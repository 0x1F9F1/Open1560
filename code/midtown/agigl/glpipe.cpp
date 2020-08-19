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
#include "agirend/rdlp.h"
#include "agirend/zbrender.h"
#include "data7/utimer.h"

#include "glbitmap.h"
#include "glerror.h"
#include "glrsys.h"
#include "gltexdef.h"
#include "glview.h"

#include <Windows.h>
#include <wingdi.h>

#include <glad/glad.h>

static mem::cmd_param PARAM_width {"width"};
static mem::cmd_param PARAM_height {"height"};
static mem::cmd_param PARAM_depth {"depth"};

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

typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC)(int interval);

PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;

i32 agiGLPipeline::BeginGfx()
{
    if (gfx_started_)
        return AGI_ERROR_ALREADY_INITIALIZED;

    valid_bit_depths_ = 0x4;
    flags_ = 0x1 | 0x4 | 0x10;

    // TODO: Use GetDesktopWindow() ?
    HDC hdc = GetDC(nullptr);
    horz_res_ = GetDeviceCaps(hdc, HORZRES);
    vert_res_ = GetDeviceCaps(hdc, VERTRES);
    ReleaseDC(nullptr, hdc);

    window_dc_ = GetDC(static_cast<HWND>(window_));

    PIXELFORMATDESCRIPTOR pfd {sizeof(pfd)};

    pfd.nVersion = 1;
    pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24; // Or 16?

    pfd.cAlphaBits = 8;
    pfd.cAlphaShift = 24;
    pfd.cRedBits = 8;
    pfd.cRedShift = 16;
    pfd.cGreenBits = 8;
    pfd.cGreenShift = 8;
    pfd.cBlueBits = 8;
    pfd.cBlueShift = 0;

    int format = ChoosePixelFormat(window_dc_, &pfd);

    SetPixelFormat(window_dc_, format, &pfd);

    int num_formats = DescribePixelFormat(window_dc_, format, 0, 0);

    Displayf("%d pixel formats... (we picked #%d)", num_formats, format);

    for (i32 i = 1; i <= num_formats; ++i)
    {
        DescribePixelFormat(window_dc_, i, sizeof(pfd), &pfd);

        Displayf("%d. Flags %x [%s] colorbits=%d depthbits=%d", i, pfd.dwFlags, PixelFormatFlagsToString(pfd.dwFlags),
            pfd.cColorBits, pfd.cDepthBits);
    }

    gl_context_ = wglCreateContext(window_dc_);

    wglMakeCurrent(window_dc_, gl_context_);

    if (gladLoadGL() != 1)
        Quitf("Failed to load GLAD");

    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) wglGetProcAddress("wglSwapIntervalEXT");

    if (wglSwapIntervalEXT)
        wglSwapIntervalEXT(0);

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

    glDisable(GL_CULL_FACE);
    glEnable(GL_COLOR_MATERIAL);

    agiCurState.SetBlendSet(agiBlendSet::SrcAlpha_InvSrcAlpha);
    agiCurState.SetTexturePerspective(true);
    agiCurState.SetMaxTextures(1);

    rasterizer_ = MakeRc<agiGLRasterizer>(this);
    renderer_ = MakeRc<agiZBufRenderer>(rasterizer_.get());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, static_cast<GLdouble>(width_), 0.0, static_cast<GLdouble>(height_), -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // glViewport(0, 0, width_, height_);
    glViewport(0, 0, horz_res_, vert_res_);

    PrintGlErrors();

    gfx_started_ = true;

    return AGI_ERROR_SUCCESS;
}

void agiGLPipeline::EndGfx()
{
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
    agiPipeline::BeginFrame();
    wglMakeCurrent(window_dc_, gl_context_);

    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    PrintGlErrors();
}

void agiGLPipeline::BeginScene()
{
    agiPipeline::BeginScene();
    in_scene_ = true;
}

void agiGLPipeline::EndScene()
{
    rasterizer_->EndGroup();
    in_scene_ = false;
    agiPipeline::EndScene();
}

void agiGLPipeline::EndFrame()
{
    ARTS_TIMED(agiEndFrame);

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
    if (src == nullptr)
        return;

    if (!width)
        width = src->GetWidth();

    if (!height)
        height = src->GetHeight();

    glBindTexture(GL_TEXTURE_2D, static_cast<agiGLBitmap*>(src)->GetHandle());

    glColor3f(1.0, 1.0, 1.0);
    glDisable(GL_CULL_FACE);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glDepthMask(false);

    if (src->IsTransparent())
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    else
    {
        glDisable(GL_BLEND);
    }

    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);

    dst_y = height_ - dst_y;

    // Texture Coords
    // 0,0 --- 1,1
    //  |       |
    //  |       |
    // 0,1 --- 1,1

    f32 fWidth = static_cast<f32>(src->GetWidth());
    f32 fHeight = static_cast<f32>(src->GetHeight());

    glTexCoord2f(src_x / fWidth, src_y / fHeight);
    glVertex2i(dst_x, dst_y);

    glTexCoord2f(src_x / fWidth, (src_y + height) / fHeight);
    glVertex2i(dst_x, dst_y - height);

    glTexCoord2f((src_x + width) / fWidth, (src_y + height) / fHeight);
    glVertex2i(dst_x + width, dst_y - height);

    glTexCoord2f((src_x + width) / fWidth, src_y / fHeight);
    glVertex2i(dst_x + width, dst_y);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_CULL_FACE);
    glDepthMask(true);

    glBindTexture(GL_TEXTURE_2D, 0);

    PrintGlErrors();
}

void agiGLPipeline::ClearAll([[maybe_unused]] i32 color)
{
    // TODO: Handle glClearColor

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void agiGLPipeline::ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color)
{
    y = height_ - y;

    glDisable(GL_CULL_FACE);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glDepthMask(false);

    glBegin(GL_QUADS);
    glColor3ub(color & 0xFF, (color >> 8) & 0xFF, (color >> 16) & 0xFF);

    glVertex2i(x, y);
    glVertex2i(x, y - height);

    glVertex2i(x + width, y - height);
    glVertex2i(x + width, y);

    glEnd();

    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_CULL_FACE);
    glDepthMask(true);
}

void agiGLPipeline::Init()
{
    width_ = PARAM_width.get_or<i32>(640);
    height_ = PARAM_height.get_or<i32>(480);
    bit_depth_ = PARAM_depth.get_or<i32>(32);

    device_flags_1_ = 0x1032; // hal, zbuffer, vram
    device_flags_3_ = 0x0;

    device_flags_2_ = device_flags_1_;

    if (device_flags_3_ == 0x0)
        device_flags_3_ = device_flags_1_;
}
