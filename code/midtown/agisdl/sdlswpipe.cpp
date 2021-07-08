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

#include "sdlswpipe.h"

#include "agi/bitmap.h"
#include "agi/cmodel8.h"
#include "agi/error.h"
#include "agi/mtldef.h"
#include "agi/palette.h"
#include "agi/rgba.h"
#include "agi/texdef.h"
#include "agi/viewport.h"
#include "agirend/bilight.h"
#include "agirend/bilmodel.h"
#include "agirend/lighter.h"
#include "agirend/rdlp.h"
#include "agirend/zbrender.h"
#include "agisw/swrend.h"
#include "agisw/swrsys.h"
#include "agisw/swtexdef.h"
#include "core/minwin.h"
#include "data7/utimer.h"
#include "eventq7/winevent.h"
#include "pcwindis/dxinit.h"

#include <SDL_render.h>
#include <SDL_syswm.h>

static void zmemset(u16* values, u32 count)
{
    std::memset(values, 0xFF, count * sizeof(u16[4]));
}

class agiSDLViewport final : public agiViewport
{
public:
    agiSDLViewport(class agiSDLSWPipeline* pipe)
        : agiViewport(pipe)
    {}

    ~agiSDLViewport() override = default;

    void Activate() override
    {
        agiViewport::Active = this;
        ++agiViewParameters::ViewSerial;
        ++agiViewParameters::MtxSerial;
    }

    i32 BeginGfx() override
    {
        return AGI_ERROR_SUCCESS;
    }

    void Clear(i32 flags) override
    {
        if (!ActiveFlag)
            return;

        ARTS_UTIMED(agiClearViewport);

        i32 width = Pipe()->GetWidth();
        i32 height = Pipe()->GetHeight();

        SDL_Rect rect {
            static_cast<i32>(width * params_.X),
            static_cast<i32>(height * (1.0f - (params_.Y + params_.Height))),
            static_cast<i32>(std::ceil(width * params_.Width)),
            static_cast<i32>(std::ceil(height * params_.Height)),
        };

        if (flags & AGI_VIEW_CLEAR_TARGET)
        {
            SDL_FillRect(Pipe()->GetSurface(), &rect, swIsInterlaced ? 0 : clear_color_);
        }

        if ((flags & AGI_VIEW_CLEAR_ZBUFFER) && agiEnableZBuffer)
        {
            if (rect.x == 0 && rect.y == 0 && rect.w == width && rect.h == height)
            {
                zmemset(swDepthBuffer, (swFbWidth * swFbHeight) >> (swIsInterlaced + 2));
            }
            else
            {
                if (swIsInterlaced)
                {
                    rect.y >>= 1;
                    rect.h >>= 1;
                }

                u16* dst = &swDepthBuffer[rect.x + swFbWidth * rect.y];

                for (i32 i = 0; i < rect.h; ++i)
                {
                    zmemset(dst, rect.w / 4);

                    dst += swFbWidth;
                }
            }
        }
    }

    void EndGfx() override
    {}

    void SetBackground(class Vector3& color) override
    {
        clear_color_ = Pipe()->GetHiColorModel()->GetColor(color);
    }

    agiSDLSWPipeline* Pipe()
    {
        return static_cast<agiSDLSWPipeline*>(agiViewport::Pipe());
    }

private:
    u32 clear_color_ {0};
};

class agiSDLBitmap final : public agiBitmap
{
public:
    agiSDLBitmap(class agiSDLSWPipeline* pipe)
        : agiBitmap(pipe)
    {}

    agiSDLSWPipeline* Pipe() const
    {
        return static_cast<agiSDLSWPipeline*>(agiBitmap::Pipe());
    }

    ~agiSDLBitmap() override
    {
        EndGfx();
    }

    i32 BeginGfx() override
    {
        if (!Pipe()->HaveGfxStarted())
            return AGI_ERROR_SUCCESS;

        if (state_ != 0)
            return AGI_ERROR_ALREADY_INITIALIZED;

        if (surface_ == nullptr)
            return AGI_ERROR_OBJECT_EMPTY;

        if (width_scale_ == 0.0f || height_scale_ == 0.0f)
        {
            if (name_[0] != '*')
                surface_->Reload(name_.get(), BitmapSearchPath, 0, 0, 0, 0, 0);

            width_ = surface_->Width;
            height_ = surface_->Height;
        }
        else
        {
            width_ = static_cast<i32>(UI_Width * width_scale_ + 0.5f);
            height_ = static_cast<i32>(UI_Height * height_scale_ + 0.5f);

            if (name_[0] != '*')
                surface_->Reload(name_.get(), BitmapSearchPath, 0, 0, 0, width_, height_);
        }

        if (surface_->Surface == nullptr)
            return AGI_ERROR_OBJECT_EMPTY;

        u32 format = 0;

        switch (surface_->PixelFormat.RBitMask)
        {
            case 0xF800: format = SDL_PIXELFORMAT_RGB565; break;
            case 0xF00: format = SDL_PIXELFORMAT_RGBA4444; break;

            default: Quitf("Invalid Format");
        }

        sdl_surface_ = SDL_CreateRGBSurfaceWithFormat(0, width_, height_, 16, format);

        SDL_LockSurface(sdl_surface_);

        agiSurfaceDesc surface = *surface_;
        surface.Width = sdl_surface_->w;
        surface.Height = sdl_surface_->h;
        surface.Surface = sdl_surface_->pixels;
        surface.Pitch = sdl_surface_->pitch;
        surface.CopyFrom(surface_.get(), 0);

        SDL_UnlockSurface(sdl_surface_);

        state_ = 1;

        if (name_[0] != '*' || (flags_ & AGI_BITMAP_UNLOAD_ALWAYS))
            surface_->Unload();

        UpdateFlags();

        return AGI_ERROR_SUCCESS;
    }

    void EndGfx() override
    {
        if (state_ != 0)
        {
            if (sdl_surface_)
            {
                SDL_FreeSurface(sdl_surface_);
                sdl_surface_ = nullptr;
            }

            state_ = 0;
        }
    }

    void Restore() override
    {
        EndGfx();
        BeginGfx();
    }

    void UpdateFlags() override
    {
        SDL_SetColorKey(sdl_surface_, IsTransparent() ? SDL_TRUE : SDL_FALSE, 0x0);
    }

    SDL_Surface* GetSurface()
    {
        return sdl_surface_;
    }

private:
    SDL_Surface* sdl_surface_ {nullptr};
};

agiSDLSWPipeline::agiSDLSWPipeline() = default;
agiSDLSWPipeline::~agiSDLSWPipeline() = default;

static mem::cmd_param PARAM_width {"width"};
static mem::cmd_param PARAM_height {"height"};
static mem::cmd_param PARAM_depth {"depth"};
static mem::cmd_param PARAM_vsync {"vsync"};

static mem::cmd_param PARAM_pack {"pack"};
static mem::cmd_param PARAM_annotate {"annotate"};

static mem::cmd_param PARAM_window {"window"};

void agiSDLSWPipeline::Init()
{
    width_ = PARAM_width.get_or<i32>(640);
    height_ = PARAM_height.get_or<i32>(480);
    bit_depth_ = PARAM_depth.get_or<i32>(16);

    device_flags_1_ = 0x0;
    is_software_ = true;

    if (PARAM_window)
        bit_depth_ = 0;
    else if (PARAM_vsync.get_or(true)) // FIXME: Screen is blank when window + vsync
        device_flags_1_ |= 0x1;

    device_flags_2_ = device_flags_1_;
    device_flags_3_ = device_flags_1_;

    PackShift = PARAM_pack.get_or<i32>(0);
    AnnotateTextures = PARAM_annotate.get_or(false);
}

void agiSDLSWPipeline::BeginFrame()
{
    ARTS_UTIMED(agiBeginFrame);

    agiPipeline::BeginFrame();

    SDL_LockTextureToSurface(render_texture_, NULL, &render_surface_);
    ArAssert(!SDL_MUSTLOCK(render_surface_), "Render Surface");

    SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0);
    SDL_RenderClear(sdl_renderer_);

    debugTri = 0;
}

i32 agiSDLSWPipeline::BeginGfx()
{
    if (gfx_started_)
        return AGI_ERROR_ALREADY_INITIALIZED;

    valid_bit_depths_ = 0x1;

    agiSDLPipeline::BeginGfx();

    sdl_renderer_ = SDL_CreateRenderer(
        window_, -1, SDL_RENDERER_ACCELERATED | ((device_flags_1_ & 0x1) ? SDL_RENDERER_PRESENTVSYNC : 0));

    // FIXME: SDL_CreateRenderer can silently recreate the underlying window
    SDL_SysWMinfo wm_info {};
    SDL_VERSION(&wm_info.version);
    ArAssert(SDL_GetWindowWMInfo(window_, &wm_info), "Failed to get native window handle");
    hwndMain = wm_info.info.win.window;

    SDL_RendererInfo info;
    SDL_GetRendererInfo(sdl_renderer_, &info);
    Displayf("Software Renderer: %s", info.name);

    SDL_GetRendererOutputSize(sdl_renderer_, &horz_res_, &vert_res_);

    InitScaling();

    SDL_Rect viewport {blit_x_, blit_y_, blit_width_, blit_height_};
    SDL_RenderSetViewport(sdl_renderer_, &viewport);

    render_texture_ =
        SDL_CreateTexture(sdl_renderer_, SDL_PIXELFORMAT_RGB565, SDL_TEXTUREACCESS_STREAMING, width_, height_);

    swFbWidth = width_;
    swFbHeight = height_;

    const auto& pixel_format = PixelFormat_R5G6B5;

    screen_format_ = {sizeof(screen_format_)};
    screen_format_.Flags = AGISD_PIXELFORMAT;
    screen_format_.PixelFormat = pixel_format;

    swBytesPerPixel = pixel_format.RGBBitCount >> 3;
    swRedMask = pixel_format.RBitMask;
    swGreenMask = pixel_format.GBitMask;
    swBlueMask = pixel_format.BBitMask;

    Displayf("SCREEN MODEL: %x / %x / %x", pixel_format.RBitMask, pixel_format.GBitMask, pixel_format.BBitMask);

    swInit();

    renderer_ = MakeRc<agiZBufRenderer>(new agiSWRasterizer(this));

    if (bit_depth_ == 8)
    {
        hi_color_model_ = MakeRc<agiColorModel8>(&agiPal);
    }
    else
    {
        hi_color_model_ = AsRc(agiColorModel::FindMatch(swRedMask, swGreenMask, swBlueMask, 0));
    }

    text_color_model_ = hi_color_model_;

    opaque_color_model_ = MakeRc<agiColorModel8>(&agiPal);
    alpha_color_model_ = opaque_color_model_;

    TexSearchPath = const_cast<char*>("texp\0");

    agiCurState.SetTexturePerspective(true);
    agiCurState.SetMaxTextures(1);

    gfx_started_ = true;

    return AGI_ERROR_SUCCESS;
}

void agiSDLSWPipeline::BeginScene()
{
    ARTS_UTIMED(agiBeginScene);

    in_scene_ = true;

    void* pixels = render_surface_->pixels;
    i32 pitch = render_surface_->pitch;

    swActualScreenStride = pitch;
    swScreenStride = pitch << swIsInterlaced;

    swScreen = static_cast<u8*>(pixels) + swFrameOffset;

    renderer_->BeginGroup();
    agiLighter::BeginScene();
    UpdateLutQueue();
}

void agiSDLSWPipeline::ClearAll(i32 color)
{
    SDL_FillRect(render_surface_, NULL, color);
}

void agiSDLSWPipeline::ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color)
{
    SDL_Rect rect {x, y, width, height};

    SDL_FillRect(render_surface_, &rect, color);
}

void agiSDLSWPipeline::CopyBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height)
{
    if (!IsAppActive())
        return;

    // FIXME: https://github.com/0x1F9F1/Open1560/issues/22
    if (src_y + height > src->GetHeight())
        return;

    ++agiBitmapCount;
    agiBitmapPixels += width * height;

    // FIXME: This overlaps with the rasterizer timer
    ARTS_UTIMED(agiCopyBitmap);

    // TODO: Implement DrawMode 3

    if ((dst_x == 0) && (dst_y == 0) && (width == width_) && (height == height_))
        std::memset(swDepthBuffer, 0xFF, sizeof(u16) * swFbWidth * swFbHeight);

    SDL_Surface* src_surface = static_cast<agiSDLBitmap*>(src)->GetSurface();

    SDL_Rect src_rect {
        src_x, src_y, std::clamp(width, 1, src_surface->w - src_x), std::clamp(height, 1, src_surface->h - src_y)};

    SDL_Rect dst_rect {dst_x, dst_y, width, height};

    SDL_BlitScaled(src_surface, &src_rect, render_surface_, &dst_rect);
}

RcOwner<class agiBitmap> agiSDLSWPipeline::CreateBitmap()
{
    return AsOwner(MakeRc<agiSDLBitmap>(this));
}

RcOwner<class DLP> agiSDLSWPipeline::CreateDLP()
{
    return AsOwner(MakeRc<RDLP>(this));
}

RcOwner<class agiLight> agiSDLSWPipeline::CreateLight()
{
    return AsOwner(MakeRc<agiBILight>(this));
}

RcOwner<class agiLightModel> agiSDLSWPipeline::CreateLightModel()
{
    return AsOwner(MakeRc<agiBILightModel>(this));
}

RcOwner<class agiMtlDef> agiSDLSWPipeline::CreateMtlDef()
{
    return nullptr;
}

RcOwner<class agiTexDef> agiSDLSWPipeline::CreateTexDef()
{
    return AsOwner(MakeRc<agiSWTexDef>(reinterpret_cast<agiSWPipeline*>(this)));
}

RcOwner<class agiTexLut> agiSDLSWPipeline::CreateTexLut()
{
    return AsOwner(MakeRc<agiSWTexLut>(reinterpret_cast<agiSWPipeline*>(this)));
}

RcOwner<class agiViewport> agiSDLSWPipeline::CreateViewport()
{
    return AsOwner(MakeRc<agiSDLViewport>(this));
}

void agiSDLSWPipeline::EndFrame()
{
    ARTS_UTIMED(agiEndFrame);

    SDL_UnlockTexture(render_texture_);
    render_surface_ = nullptr;

    SDL_RenderCopy(sdl_renderer_, render_texture_, NULL, NULL);

    SDL_RenderPresent(sdl_renderer_);

    agiPipeline::EndFrame();
}

void agiSDLSWPipeline::EndGfx()
{
    swKill();

    if (render_texture_)
    {
        SDL_DestroyTexture(render_texture_);
        render_texture_ = nullptr;
    }

    if (sdl_renderer_)
    {
        SDL_DestroyRenderer(sdl_renderer_);
        sdl_renderer_ = nullptr;
    }

    gfx_started_ = false;
}

void agiSDLSWPipeline::EndScene()
{
    ARTS_UTIMED(agiEndScene);

    renderer_->EndGroup();
    in_scene_ = false;
}

i32 agiSDLSWPipeline::Validate()
{
    return AGI_ERROR_SUCCESS;
}

static void TranslatePixels(u8* data, i32 width, i32 height)
{
    // Flip vertically
    for (i32 y = 0; y < height / 2; ++y)
    {
        u32* lhs = (u32*) &data[y * width * 4];
        u32* rhs = (u32*) &data[(height - y - 1) * width * 4];

        for (i32 x = 0; x < width; ++x)
        {
            u32 temp = lhs[x];
            lhs[x] = rhs[x];
            rhs[x] = temp;
        }
    }

    // BGRA -> BGR
    u8* src = data;
    u8* dst = data;
    for (i32 i = 0, count = width * height; i < count; ++i)
    {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        src += 4;
        dst += 3;
    }
}

Ptr<u8[]> sdlScreenShot(i32& width, i32& height)
{
    SDL_Window* window = SDL_GetGrabbedWindow();

    if (window == nullptr)
        return nullptr;

    SDL_Renderer* renderer = SDL_GetRenderer(window);

    if (renderer == nullptr)
        return nullptr;

    SDL_Rect view;
    SDL_RenderGetViewport(renderer, &view);

    width = view.w;
    height = view.h;

    Ptr<u8[]> buffer = MakeUniqueUninit<u8[]>(width * height * 4);

    if (buffer == nullptr)
        return nullptr;

    if (SDL_RenderReadPixels(renderer, &view, SDL_PIXELFORMAT_ARGB8888, buffer.get(), width * 4) != 0)
        return nullptr;

    TranslatePixels(buffer.get(), width, height);

    return buffer;
}

Owner<class agiPipeline> sdlCreatePipeline([[maybe_unused]] i32 argc, [[maybe_unused]] char** argv)
{
    Ptr<agiSDLSWPipeline> result = MakeUnique<agiSDLSWPipeline>();
    result->Init();
    return AsOwner(result);
}
