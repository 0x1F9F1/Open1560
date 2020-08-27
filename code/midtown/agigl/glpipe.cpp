/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "glpipe.h"

#include "agi/cmodel.h"
#include "agi/error.h"
#include "agi/rsys.h"
#include "agirend/bilight.h"
#include "agirend/bilmodel.h"
#include "agirend/lighter.h"
#include "agirend/projvtx.h"
#include "agirend/rdlp.h"
#include "agirend/zbrender.h"
#include "data7/utimer.h"
#include "eventq7/winevent.h"
#include "pcwindis/dxinit.h"

#include "glbitmap.h"
#include "glerror.h"
#include "glrsys.h"
#include "gltexdef.h"
#include "glview.h"

#include <Windows.h>
#include <wingdi.h>

#include <glad/glad.h>

#include <wglext.h>

const char* PixelFormatFlagsToString(DWORD flags)
{
    // FIXME: Static buffer
    static char buffer[256];

    buffer[0] = 0;

    if (flags & PFD_DRAW_TO_WINDOW)
        arts_strcat(buffer, "PFD_DRAW_TO_WINDOW ");
    if (flags & PFD_DRAW_TO_BITMAP)
        arts_strcat(buffer, "PFD_DRAW_TO_BITMAP ");
    if (flags & PFD_SUPPORT_GDI)
        arts_strcat(buffer, "PFD_SUPPORT_GDI ");
    if (flags & PFD_SUPPORT_OPENGL)
        arts_strcat(buffer, "PFD_SUPPORT_OPENGL ");
    if (flags & PFD_GENERIC_ACCELERATED)
        arts_strcat(buffer, "PFD_GENERIC_ACCELERATED ");
    if (flags & PFD_GENERIC_FORMAT)
        arts_strcat(buffer, "PFD_GENERIC_FORMAT ");
    if (flags & PFD_NEED_PALETTE)
        arts_strcat(buffer, "PFD_NEED_PALETTE ");
    if (flags & PFD_NEED_SYSTEM_PALETTE)
        arts_strcat(buffer, "PFD_NEED_SYSTEM_PALETTE ");
    if (flags & PFD_DOUBLEBUFFER)
        arts_strcat(buffer, "PFD_DOUBLEBUFFER ");
    if (flags & PFD_STEREO)
        arts_strcat(buffer, "PFD_STEREO ");
    if (flags & PFD_SWAP_LAYER_BUFFERS)
        arts_strcat(buffer, "PFD_SWAP_LAYER_BUFFERS ");

    return buffer;
}

static PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;
static PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
static PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = NULL;

static const char* GetDebugTypeString(GLenum value)
{
    switch (value)
    {
        case GL_DEBUG_TYPE_ERROR: return "Error";
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "Deprecated Behaviour";
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "Undefined Behaviour";
        case GL_DEBUG_TYPE_PORTABILITY: return "Portability";
        case GL_DEBUG_TYPE_PERFORMANCE: return "Performance";
        case GL_DEBUG_TYPE_OTHER: return "Other";
        case GL_DEBUG_TYPE_MARKER: return "Marker";
        case GL_DEBUG_TYPE_PUSH_GROUP: return "Push Group";
        case GL_DEBUG_TYPE_POP_GROUP: return "Pop Group";

        default: return "Invalid";
    }
}

static i32 GetDebugSeverityPriority(GLenum value)
{
    switch (value)
    {
        case GL_DEBUG_SEVERITY_HIGH: return 2;
        case GL_DEBUG_SEVERITY_MEDIUM: return 1;
        case GL_DEBUG_SEVERITY_LOW: return 0;
        case GL_DEBUG_SEVERITY_NOTIFICATION: return 0;

        default: return 2;
    }
}

static void GLAPIENTRY DebugMessageCallback([[maybe_unused]] GLenum source, GLenum type, [[maybe_unused]] GLuint id,
    GLenum severity, [[maybe_unused]] GLsizei length, const GLchar* message, [[maybe_unused]] const void* userParam)
{
    if (agiVerbose)
    {
        Printerf(
            GetDebugSeverityPriority(severity), "GL Message: %X %s: %s", severity, GetDebugTypeString(type), message);
    }
}

static mem::cmd_param PARAM_gldebug {"gldebug"};
static mem::cmd_param PARAM_msaa {"msaa"};

i32 agiGLPipeline::BeginGfx()
{
    if (gfx_started_)
        return AGI_ERROR_ALREADY_INITIALIZED;

    valid_bit_depths_ = 0x4;
    flags_ = 0x1 | 0x4 | 0x10;

    // TODO: Get monitor position from dxiInfo

    MONITORINFO info {sizeof(MONITORINFO)};
    GetMonitorInfo(MonitorFromWindow(static_cast<HWND>(window_), MONITOR_DEFAULTTONEAREST), &info);

    i32 horz_res = info.rcMonitor.right - info.rcMonitor.left;
    i32 vert_res = info.rcMonitor.bottom - info.rcMonitor.top;

    if (dxiIsFullScreen())
    {
        horz_res_ = horz_res;
        vert_res_ = vert_res;
    }
    else
    {
        horz_res_ = width_;
        vert_res_ = height_;
    }

    SetWindowPos(static_cast<HWND>(window_), HWND_TOP, info.rcMonitor.left + (horz_res - horz_res_) / 2,
        info.rcMonitor.top + (vert_res - vert_res_) / 2, horz_res_, vert_res_, SWP_NOZORDER);

    window_dc_ = GetDC(static_cast<HWND>(window_));

    dxiWidth = horz_res;
    dxiHeight = horz_res;

    PIXELFORMATDESCRIPTOR pfd {sizeof(pfd)};

    pfd.nVersion = 1;
    pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int format = ChoosePixelFormat(window_dc_, &pfd);

    SetPixelFormat(window_dc_, format, &pfd);

    HGLRC temp_context = wglCreateContext(window_dc_);

    if (temp_context == NULL)
        Quitf("Failed to create temporary opengl context");

    wglMakeCurrent(window_dc_, temp_context);

    wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) wglGetProcAddress("wglChoosePixelFormatARB");
    wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress("wglCreateContextAttribsARB");
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) wglGetProcAddress("wglSwapIntervalEXT");

    // TODO: Check wglGetExtensionsStringARB extensions
    if (wglChoosePixelFormatARB && wglCreateContextAttribsARB)
    {
        Displayf("Using modern OpenGL context");

        const int pixel_attribs[] {
            // clang-format off
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
            WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
            WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
            WGL_COLOR_BITS_ARB, 32,
            WGL_DEPTH_BITS_ARB, 24,
            WGL_STENCIL_BITS_ARB, 8,
            0,
            // clang-format on
        };

        UINT num_formats = 0;
        wglChoosePixelFormatARB(window_dc_, pixel_attribs, NULL, 1, &format, &num_formats);

        if (num_formats == 0)
            Quitf("Failed to choose pixel format");

        const int context_attribs[] {
            // clang-format off
            WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
            WGL_CONTEXT_MINOR_VERSION_ARB, 2,
            WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
            WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            0
            // clang-format on
        };

        gl_context_ = wglCreateContextAttribsARB(window_dc_, 0, context_attribs);

        if (gl_context_ == NULL)
            Quitf("Failed to create opengl context");

        wglDeleteContext(temp_context);
        wglMakeCurrent(window_dc_, gl_context_);
    }
    else
    {
        Displayf("Using legacy OpenGL context");

        gl_context_ = temp_context;
    }

    if (gladLoadGL() != 1)
        Quitf("Failed to load GLAD");

    if (PARAM_gldebug.get_or(false) && glDebugMessageCallback)
    {
        Displayf("Using glDebugMessageCallback");

        glEnable(GL_DEBUG_OUTPUT);

        glDebugMessageCallback(DebugMessageCallback, 0);
    }

    if (wglSwapIntervalEXT)
    {
        wglSwapIntervalEXT((device_flags_1_ & 0x1) ? 1 : 0);
    }

    // FIXME: Check pixel format masks

    screen_format_ = {sizeof(screen_format_)};

    // TODO: Should this have alpha?
    screen_format_.Flags = AGISD_PIXELFORMAT;
    screen_format_.PixelFormat = {sizeof(screen_format_.PixelFormat)};
    screen_format_.PixelFormat.Flags = AGIPF_RGB | AGIPF_ALPHAPIXELS;

    screen_format_.PixelFormat.RGBBitCount = 32;
    screen_format_.PixelFormat.RBitMask = 0x00FF0000;
    screen_format_.PixelFormat.GBitMask = 0x0000FF00;
    screen_format_.PixelFormat.BBitMask = 0x000000FF;
    screen_format_.PixelFormat.RGBAlphaBitMask = 0xFF000000;

    alpha_color_model_ = AsRc(agiColorModel::FindMatch(0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000));
    opaque_color_model_ = alpha_color_model_;
    hi_color_model_ = alpha_color_model_;
    text_color_model_ = alpha_color_model_;

    agiCurState.SetCullMode(agiCullMode::None);
    agiCurState.SetBlendSet(agiBlendSet::SrcAlpha_InvSrcAlpha);
    agiCurState.SetTexturePerspective(true);
    agiCurState.SetMaxTextures(1);

    rasterizer_ = MakeRc<agiGLRasterizer>(this);
    renderer_ = MakeRc<agiZBufRenderer>(rasterizer_.get());

    // glViewport(0, 0, width_, height_);
    glViewport(0, 0, horz_res_, vert_res_);

    msaa_level_ = PARAM_msaa.get_or<i32>(0);

    if (msaa_level_ != 0)
    {
        glGenFramebuffers(1, &fbo_);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo_);

        glGenRenderbuffers(1, &rbo_);
        glBindRenderbuffer(GL_RENDERBUFFER, rbo_);
        glRenderbufferStorageMultisample(GL_RENDERBUFFER, msaa_level_, GL_DEPTH24_STENCIL8, horz_res_, vert_res_);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo_);

        glGenTextures(1, &msaa_tex_);
        glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, msaa_tex_);
        glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, msaa_level_, GL_RGB, horz_res_, vert_res_, GL_TRUE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE, msaa_tex_, 0);

        if (GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER); status != GL_FRAMEBUFFER_COMPLETE)
            Quitf("Failed to create framebuffer: 0x%08X", status);

        PrintGlErrors();
    }

    PrintGlErrors();

    gfx_started_ = true;

    return AGI_ERROR_SUCCESS;
}

void agiGLPipeline::EndGfx()
{
    if (msaa_level_ != 0)
    {
        glDeleteFramebuffers(1, &fbo_);
        glDeleteFramebuffers(1, &rbo_);
        glDeleteTextures(1, &msaa_tex_);
    }

    wglDeleteContext(gl_context_);

    ReleaseDC(static_cast<HWND>(window_), window_dc_);

    text_color_model_ = nullptr;
    hi_color_model_ = nullptr;
    opaque_color_model_ = nullptr;
    alpha_color_model_ = nullptr;

    renderer_ = nullptr;
    rasterizer_ = nullptr;

    gfx_started_ = false;
}

void agiGLPipeline::BeginFrame()
{
    ARTS_TIMED(agiBeginFrame);

    agiPipeline::BeginFrame();

    // TODO: Does this really need to be called each frame?
    wglMakeCurrent(window_dc_, gl_context_);

    if (msaa_level_ != 0)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
    }

    PrintGlErrors();
}

void agiGLPipeline::BeginScene()
{
    ARTS_TIMED(agiBeginScene);

    if (ZTrick)
    {
        if (agiCurState.GetZFunc() == agiCmpFunc::LessEqual)
        {
            agiCurState.SetZFunc(agiCmpFunc::GreaterEqual);
            DepthScale = -0.24f;
            DepthOffset = 0.75f;
        }
        else
        {
            agiCurState.SetZFunc(agiCmpFunc::LessEqual);
            DepthScale = 0.24f;
            DepthOffset = 0.25f;
        }
    }
    else
    {
        agiCurState.SetZFunc(agiCmpFunc::LessEqual);
        DepthScale = 0.5f;
        DepthOffset = 0.5f;
    }

    agiPipeline::BeginScene();
    agiLighter::BeginScene();

    in_scene_ = true;

    renderer_->BeginGroup();
}

void agiGLPipeline::EndScene()
{
    ARTS_TIMED(agiEndScene);

    rasterizer_->EndGroup();
    in_scene_ = false;

    agiPipeline::EndScene();
}

void agiGLPipeline::EndFrame()
{
    ARTS_TIMED(agiEndFrame);

    if (msaa_level_ != 0)
    {
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);    // Make sure no FBO is set as the draw framebuffer
        glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo_); // Make sure your multisampled FBO is the read framebuffer
        glDrawBuffer(GL_BACK);                        // Set the back buffer as the draw buffer
        glBlitFramebuffer(0, 0, horz_res_, vert_res_, 0, 0, horz_res_, vert_res_, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    }

    PrintGlErrors();

    SwapBuffers(window_dc_);
    agiPipeline::EndFrame();
}

RcOwner<class agiTexDef> agiGLPipeline::CreateTexDef()
{
    return AsOwner(MakeRc<agiGLTexDef>(this));
}

RcOwner<class agiTexLut> agiGLPipeline::CreateTexLut()
{
    return nullptr;
}

RcOwner<class DLP> agiGLPipeline::CreateDLP()
{
    return AsOwner(MakeRc<RDLP>(this));
}

RcOwner<agiLight> agiGLPipeline::CreateLight()
{
    return AsOwner(MakeRc<agiBILight>(this));
}

RcOwner<agiLightModel> agiGLPipeline::CreateLightModel()
{
    return AsOwner(MakeRc<agiBILightModel>(this));
}

RcOwner<class agiViewport> agiGLPipeline::CreateViewport()
{
    return AsOwner(MakeRc<agiGLViewport>(this));
}

RcOwner<class agiBitmap> agiGLPipeline::CreateBitmap()
{
    return AsOwner(MakeRc<agiGLBitmap>(this));
}

void agiGLPipeline::CopyBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height)
{
    if (!(ActiveFlag & 0x1))
        return;

    ++agiBitmapCount;
    agiBitmapPixels += width * height;

    ARTS_TIMED(agiCopyBitmap);

    RAST->BeginGroup();

    agiTexDef* texture = static_cast<agiGLBitmap*>(src)->GetHandle();

    auto old_tex = agiCurState.SetTexture(texture);
    auto old_draw_mode = agiCurState.SetDrawMode(0xF);
    auto old_depth = agiCurState.SetZEnable(false);
    auto old_zwrite = agiCurState.SetZWrite(false);
    auto old_alpha = agiCurState.SetAlphaEnable(false);
    auto old_filter = agiCurState.SetTexFilter(agiTexFilter::Point);
    auto old_fog_mode = agiCurState.SetFogMode(agiFogMode::None);
    auto old_fog_color = agiCurState.SetFogColor(0x00000000);

    agiScreenVtx blank;
    blank.x = 0.0f;
    blank.y = 0.0f;
    blank.z = 0.0f;
    blank.w = 1.0f;
    blank.color = 0xFFFFFFFF;
    blank.specular = 0xFFFFFFFF;
    blank.tu = 0.0f;
    blank.tv = 0.0f;

    agiScreenVtx verts[4];

    verts[0] = blank;
    verts[1] = blank;
    verts[2] = blank;
    verts[3] = blank;

    f32 const inv_tex_w = 1.0f / src->GetWidth();
    f32 const inv_tex_h = 1.0f / src->GetHeight();

    verts[3].x = verts[0].x = static_cast<f32>(dst_x);
    verts[1].y = verts[0].y = static_cast<f32>(dst_y);
    verts[3].tu = verts[0].tu = src_x * inv_tex_w;
    verts[1].tv = verts[0].tv = src_y * inv_tex_h;

    verts[1].x = verts[2].x = static_cast<f32>(dst_x + width);
    verts[3].y = verts[2].y = static_cast<f32>(dst_y + height);
    verts[1].tu = verts[2].tu = (src_x + width) * inv_tex_w;
    verts[3].tv = verts[2].tv = (src_y + height) * inv_tex_h;

    u16 indices[6];

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    indices[3] = 0;
    indices[4] = 2;
    indices[5] = 3;

    RAST->Mesh(agiVtxType::Screen, (agiVtx*) verts, 4, indices, 6);

    RAST->EndGroup();

    agiCurState.SetTexture(old_tex);
    agiCurState.SetDrawMode(old_draw_mode);
    agiCurState.SetZEnable(old_depth);
    agiCurState.SetZWrite(old_zwrite);
    agiCurState.SetAlphaEnable(old_alpha);
    agiCurState.SetTexFilter(old_filter);
    agiCurState.SetFogMode(old_fog_mode);
    agiCurState.SetFogColor(old_fog_color);

    PrintGlErrors();
}

void agiGLPipeline::ClearAll(i32 color)
{
    glClearColor((color & 0xFF) / 255.0f, ((color >> 8) & 0xFF) / 255.0f, ((color >> 16) & 0xFF) / 255.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);
}

void agiGLPipeline::ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color)
{
    RAST->BeginGroup();

    auto tex = agiCurState.SetTexture(nullptr);
    auto draw_mode = agiCurState.SetDrawMode(0xF);
    auto depth = agiCurState.SetZEnable(false);
    auto zwrite = agiCurState.SetZWrite(false);
    auto alpha = agiCurState.SetAlphaEnable(false);
    auto filter = agiCurState.SetTexFilter(agiTexFilter::Point);
    auto fog_mode = agiCurState.SetFogMode(agiFogMode::None);
    auto fog_color = agiCurState.SetFogColor(0x00000000);

    agiScreenVtx blank;
    blank.x = 0.0f;
    blank.y = 0.0f;
    blank.z = 0.0f;
    blank.w = 1.0f;
    blank.color = color | 0xFF000000;
    blank.specular = 0xFFFFFFFF;
    blank.tu = 0.0f;
    blank.tv = 0.0f;

    agiScreenVtx verts[4];

    verts[0] = blank;
    verts[1] = blank;
    verts[2] = blank;
    verts[3] = blank;

    verts[3].x = verts[0].x = static_cast<f32>(x);
    verts[1].y = verts[0].y = static_cast<f32>(y);

    verts[1].x = verts[2].x = static_cast<f32>(x + width);
    verts[3].y = verts[2].y = static_cast<f32>(y + height);

    u16 indices[6];
    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    indices[3] = 0;
    indices[4] = 2;
    indices[5] = 3;

    RAST->Mesh(agiVtxType::Screen, (agiVtx*) verts, 4, indices, 6);

    RAST->EndGroup();

    agiCurState.SetTexture(tex);
    agiCurState.SetDrawMode(draw_mode);
    agiCurState.SetZEnable(depth);
    agiCurState.SetZWrite(zwrite);
    agiCurState.SetAlphaEnable(alpha);
    agiCurState.SetTexFilter(filter);
    agiCurState.SetFogMode(fog_mode);
    agiCurState.SetFogColor(fog_color);
}

static mem::cmd_param PARAM_width {"width"};
static mem::cmd_param PARAM_height {"height"};
static mem::cmd_param PARAM_depth {"depth"};
static mem::cmd_param PARAM_vsync {"vsync"};

void agiGLPipeline::Init()
{
    width_ = PARAM_width.get_or<i32>(640);
    height_ = PARAM_height.get_or<i32>(480);
    bit_depth_ = PARAM_depth.get_or<i32>(32);

    device_flags_1_ = 0x1032; // hal, zbuffer, vram, vsync

    if (PARAM_vsync.get_or(true))
        device_flags_1_ |= 0x1;

    device_flags_2_ = device_flags_1_;
    device_flags_3_ = device_flags_1_;
}
