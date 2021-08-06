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
#include "agirend/rdlp.h"
#include "agirend/zbrender.h"
#include "data7/utimer.h"
#include "eventq7/winevent.h"
#include "mmcityinfo/state.h"
#include "pcwindis/dxinit.h"
#include "pcwindis/setupdata.h"

#include "glbitmap.h"
#include "glcontext.h"
#include "glrsys.h"
#include "gltexdef.h"
#include "glview.h"

#include <glad/glad.h>

static mem::cmd_param PARAM_gldebug {"gldebug"};
static mem::cmd_param PARAM_msaa {"msaa"};
static mem::cmd_param PARAM_native_res {"nativeres"};

agiGLPipeline::agiGLPipeline() = default;
agiGLPipeline::~agiGLPipeline() = default;

i32 agiGLPipeline::BeginGfx()
{
    if (gfx_started_)
        return AGI_ERROR_ALREADY_INITIALIZED;

    valid_bit_depths_ = 0x4;
    flags_ = 0x1 | 0x4 | 0x10;

    agiSDLPipeline::BeginGfx();

    i32 debug_level = PARAM_gldebug.get_or(
#ifdef ARTS_DEBUG
        1
#else
        -1
#endif
    );

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, (debug_level > 0) ? SDL_GL_CONTEXT_DEBUG_FLAG : 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_NO_ERROR, (debug_level < 0) ? 1 : 0);

    SDL_GLContext context = SDL_GL_CreateContext(window_);

    if (context == nullptr)
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        context = SDL_GL_CreateContext(window_);
    }

    if (context == nullptr)
        Quitf("Failed to create OpenGL context: %s", SDL_GetError());

    gl_context_ = MakeUnique<agiGLContext>(window_, context, debug_level);

    SDL_GL_GetDrawableSize(window_, &horz_res_, &vert_res_);

    dxiWidth = horz_res_;
    dxiHeight = vert_res_;

    Displayf("Window Resolution: %u x %u", horz_res_, vert_res_);

    if (device_flags_1_ & 0x1)
    {
        if (SDL_GL_SetSwapInterval(-1) == -1)
            SDL_GL_SetSwapInterval(1);
    }
    else
    {
        SDL_GL_SetSwapInterval(0);
    }

    // TODO: Should this have alpha?
    screen_format_ = agiSurfaceDesc::FromFormat(PixelFormat_A8R8G8B8);
    opaque_format_ = agiSurfaceDesc::FromFormat(PixelFormat_X8R8G8B8);
    alpha_format_ = agiSurfaceDesc::FromFormat(PixelFormat_A8R8G8B8);

    screen_color_model_ = AsRc(agiColorModel::FindMatch(&screen_format_));
    opaque_color_model_ = AsRc(agiColorModel::FindMatch(&opaque_format_));
    alpha_color_model_ = AsRc(agiColorModel::FindMatch(&alpha_format_));
    text_color_model_ = alpha_color_model_;

    TexSearchPath = const_cast<char*>("tex16a\0tex16o\0tex16\0");

    agiCurState.SetCullMode(agiCullMode::None);
    agiCurState.SetBlendSet(agiBlendSet::SrcAlpha_InvSrcAlpha);
    agiCurState.SetTexturePerspective(true);
    agiCurState.SetMaxTextures(1);
    agiCurState.SetSmoothShading(true);

    rasterizer_ = MakeRc<agiGLRasterizer>(this);
    renderer_ = MakeRc<agiZBufRenderer>(rasterizer_.get());

    InitScaling();

    bool builtin_fb = !gl_context_->HasExtension(300, "GL_ARB_framebuffer_object");

    i32 msaa_level = 0;

    if (!builtin_fb && gl_context_->HasExtension(320, "GL_ARB_texture_multisample"))
    {
        GLint max_samples = 0;
        glGetIntegerv(GL_MAX_SAMPLES, &max_samples);
        msaa_level = std::clamp(PARAM_msaa.get_or<i32>(0), 0, max_samples);
    }

    bool native_res = builtin_fb || PARAM_native_res.get_or(true);

    if (msaa_level != 0 && !gl_context_->HasExtension("GL_EXT_framebuffer_multisample_blit_scaled"))
    {
        Errorf("Multisample scaling not supported");

        native_res = true;
    }

    if (native_res)
    {
        render_width_ = blit_width_;
        render_height_ = blit_height_;
    }
    else
    {
        render_width_ = width_;
        render_height_ = height_;
    }

    // Don't bother using a custom framebuffer if there would be no difference
    if (render_width_ == blit_width_ && render_height_ == blit_height_ && msaa_level == 0)
        builtin_fb = true;

    render_x_ = 0;
    render_y_ = 0;

    gl_context_->CheckErrors();

    Displayf("Using %s framebuffer (msaa=%i)", builtin_fb ? "builtin" : "custom", msaa_level);

    // Clear the builtin frame buffer (avoid ugly remains/ghost image)
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    // SDL_GL_SwapWindow(window_);

    if (!builtin_fb)
    {
        glGenFramebuffers(1, &fbo_);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
        glGenRenderbuffers(2, rbo_);

        if (render_width_ > blit_width_ || render_height_ > blit_height_)
            blit_filter_ = GL_LINEAR;
        else
            blit_filter_ = GL_NEAREST;

        if (msaa_level)
        {
            glBindRenderbuffer(GL_RENDERBUFFER, rbo_[0]);
            glRenderbufferStorageMultisample(GL_RENDERBUFFER, msaa_level, GL_RGBA8, render_width_, render_height_);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, rbo_[0]);

            glBindRenderbuffer(GL_RENDERBUFFER, rbo_[1]);
            glRenderbufferStorageMultisample(
                GL_RENDERBUFFER, msaa_level, GL_DEPTH_COMPONENT, render_width_, render_height_);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rbo_[1]);

            if (render_width_ != blit_width_ || render_height_ != blit_height_)
                blit_filter_ = GL_SCALED_RESOLVE_NICEST_EXT;
        }
        else
        {
            glBindRenderbuffer(GL_RENDERBUFFER, rbo_[0]);
            glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, render_width_, render_height_);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, rbo_[0]);

            glBindRenderbuffer(GL_RENDERBUFFER, rbo_[1]);
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, render_width_, render_height_);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rbo_[1]);
        }

        if (GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER); status != GL_FRAMEBUFFER_COMPLETE)
            Quitf("Failed to create framebuffer: 0x%08X", status);
    }
    else
    {
        std::swap(render_x_, blit_x_);
        std::swap(render_y_, blit_y_);
    }

    gl_context_->CheckErrors();

    glViewport(render_x_, render_y_, render_width_, render_height_);

    gfx_started_ = true;

    return AGI_ERROR_SUCCESS;
}

void agiGLPipeline::EndGfx()
{
    if (fbo_ != 0)
    {
        glDeleteFramebuffers(1, &fbo_);
        glDeleteRenderbuffers(2, rbo_);

        fbo_ = 0;
        rbo_[0] = 0;
        rbo_[1] = 0;
    }

    text_color_model_ = nullptr;
    screen_color_model_ = nullptr;
    opaque_color_model_ = nullptr;
    alpha_color_model_ = nullptr;

    renderer_ = nullptr;
    rasterizer_ = nullptr;

    gl_context_ = nullptr;

    gfx_started_ = false;
}

static mem::cmd_param PARAM_frameclear {"frameclear"};

void agiGLPipeline::BeginFrame()
{
    ARTS_UTIMED(agiBeginFrame);

    agiPipeline::BeginFrame();

    gl_context_->MakeCurrent();

    if (PARAM_frameclear.get_or(true))
    {
        agiGL->EnableDisable(GL_SCISSOR_TEST, false);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    if (fbo_ != 0)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
    }
}

void agiGLPipeline::BeginScene()
{
    ARTS_UTIMED(agiBeginScene);

    UpdateZTrick();

    agiPipeline::BeginScene();
    agiLighter::BeginScene();

    in_scene_ = true;

    renderer_->BeginGroup();
}

void agiGLPipeline::EndScene()
{
    ARTS_UTIMED(agiEndScene);

    rasterizer_->EndGroup();
    in_scene_ = false;

    agiPipeline::EndScene();
}

void agiGLPipeline::EndFrame()
{
    ARTS_UTIMED(agiEndFrame);

    if (fbo_ != 0)
    {
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
        glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo_);
        glBlitFramebuffer(render_x_, render_y_, render_x_ + render_width_, render_y_ + render_height_, blit_x_, blit_y_,
            blit_x_ + blit_width_, blit_y_ + blit_height_, GL_COLOR_BUFFER_BIT, blit_filter_);
    }

    SDL_GL_SwapWindow(window_);

    if (!dxiDoubleBuffer())
        glFinish();

    gl_context_->CheckErrors();

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
    if (!IsAppActive())
        return;

    // FIXME: https://github.com/0x1F9F1/Open1560/issues/22
    if (src_y + height > src->GetHeight())
        return;

#ifdef ARTS_DEV_BUILD
    ++agiBitmapCount;
    agiBitmapPixels += width * height;
#endif

    // FIXME: This overlaps with the rasterizer timer
    // ARTS_UTIMED(agiCopyBitmap);

    // rasterizer_->BeginGroup();

    agiTexDef* texture = static_cast<agiGLBitmap*>(src)->GetHandle();

    bool debug_draw = agiCurState.GetDrawMode() == agiDrawDepth;

    auto old_tex = agiCurState.SetTexture(debug_draw ? nullptr : texture);
    auto old_draw_mode = agiCurState.SetDrawMode(agiDrawTextured);
    auto old_depth = agiCurState.SetZEnable(false);
    auto old_zwrite = agiCurState.SetZWrite(false);
    auto old_alpha = agiCurState.SetAlphaEnable(debug_draw ? true : false);
    auto old_filter = agiCurState.SetTexFilter(agiTexFilter::Point);
    auto old_fog_mode = agiCurState.SetFogMode(agiFogMode::None);
    auto old_fog_color = agiCurState.SetFogColor(0x00000000);
    auto old_blend_set = agiCurState.SetBlendSet(debug_draw ? agiBlendSet::One_One : agiBlendSet::SrcAlpha_InvSrcAlpha);

    agiScreenVtx blank {0.0f, 0.0f, 0.0f, 1.0f, debug_draw ? 0xFF000044 : 0xFFFFFFFF, 0xFFFFFFFF, 0.0f, 0.0f};
    agiScreenVtx verts[4] {blank, blank, blank, blank};
    u16 indices[6] {0, 1, 2, 0, 2, 3};

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

    rasterizer_->Mesh(agiVtxType::Screen, (agiVtx*) verts, 4, indices, 6);

    // rasterizer_->EndGroup();

    agiCurState.SetTexture(old_tex);
    agiCurState.SetDrawMode(old_draw_mode);
    agiCurState.SetZEnable(old_depth);
    agiCurState.SetZWrite(old_zwrite);
    agiCurState.SetAlphaEnable(old_alpha);
    agiCurState.SetTexFilter(old_filter);
    agiCurState.SetFogMode(old_fog_mode);
    agiCurState.SetFogColor(old_fog_color);
    agiCurState.SetBlendSet(old_blend_set);
}

void agiGLPipeline::ClearAll(i32 color)
{
    glClearColor((color & 0xFF) / 255.0f, ((color >> 8) & 0xFF) / 255.0f, ((color >> 16) & 0xFF) / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void agiGLPipeline::ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color)
{
    // rasterizer_->BeginGroup();

    auto tex = agiCurState.SetTexture(nullptr);
    auto draw_mode = agiCurState.SetDrawMode(agiDrawTextured);
    auto depth = agiCurState.SetZEnable(false);
    auto zwrite = agiCurState.SetZWrite(false);
    auto alpha = agiCurState.SetAlphaEnable(false);
    auto filter = agiCurState.SetTexFilter(agiTexFilter::Point);
    auto fog_mode = agiCurState.SetFogMode(agiFogMode::None);
    auto fog_color = agiCurState.SetFogColor(0x00000000);

    agiScreenVtx blank {0.0f, 0.0f, 0.0f, 1.0f, color | 0xFF000000, 0xFFFFFFFF, 0.0f, 0.0f};
    agiScreenVtx verts[4] {blank, blank, blank, blank};
    u16 indices[6] {0, 1, 2, 0, 2, 3};

    verts[3].x = verts[0].x = static_cast<f32>(x);
    verts[1].y = verts[0].y = static_cast<f32>(y);

    verts[1].x = verts[2].x = static_cast<f32>(x + width);
    verts[3].y = verts[2].y = static_cast<f32>(y + height);

    rasterizer_->Mesh(agiVtxType::Screen, (agiVtx*) verts, 4, indices, 6);

    // rasterizer_->EndGroup();

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
static mem::cmd_param PARAM_pack {"pack"};
static mem::cmd_param PARAM_annotate {"annotate"};

void agiGLPipeline::Init()
{
    // TODO: Properly use width/height/depth
    width_ = PARAM_width.get_or<i32>(640);
    height_ = PARAM_height.get_or<i32>(480);
    bit_depth_ = PARAM_depth.get_or<i32>(32);

    device_flags_1_ = 0x1032; // hal, zbuffer, vram

    if (PARAM_vsync.get_or(true))
        device_flags_1_ |= 0x1;

    device_flags_2_ = device_flags_1_;
    device_flags_3_ = device_flags_1_;

    PackShift = PARAM_pack.get_or<i32>(0);
    AnnotateTextures = PARAM_annotate.get_or(false);
}

Ptr<u8[]> glScreenShot(i32& width, i32& height)
{
    if (agiGL == nullptr)
        return nullptr;

    GLint viewport[4] {};
    glGetIntegerv(GL_VIEWPORT, viewport);

    i32 x = viewport[0];
    i32 y = viewport[1];

    width = viewport[2];
    height = viewport[3];

    Ptr<u8[]> buffer = MakeUniqueUninit<u8[]>(width * height * 3);

    if (buffer)
    {
        glPixelStorei(GL_PACK_ALIGNMENT, 1);

        // FIXME: Does not work with MSAA (FBO anti-alias method is not valid for read pixels.)
        glReadPixels(x, y, width, height, GL_BGR, GL_UNSIGNED_BYTE, buffer.get());
    }

    return buffer;
}

Owner<agiPipeline> glCreatePipeline([[maybe_unused]] i32 argc, [[maybe_unused]] char** argv)
{
    Ptr<agiGLPipeline> result = MakeUnique<agiGLPipeline>();
    result->Init();
    return AsOwner(result);
}
