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
    agiSDLViewport(agiSDLSWPipeline* pipe)
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

        i32 pipe_width = Pipe()->GetWidth();
        i32 pipe_height = Pipe()->GetHeight();

        i32 x = static_cast<i32>(std::round(pipe_width * params_.X));
        i32 y = static_cast<i32>(std::round(pipe_height * params_.Y));
        i32 w = static_cast<i32>(std::round(pipe_width * (params_.X + params_.Width))) - x;
        i32 h = static_cast<i32>(std::round(pipe_height * (params_.Y + params_.Height))) - y;
        y = pipe_height - (y + h);

        SDL_Rect rect {x, y, w, h};

        if (flags & AGI_VIEW_CLEAR_TARGET)
        {
            SDL_FillRect(Pipe()->GetSurface(), &rect, swIsInterlaced ? 0 : clear_color_);
        }

        if ((flags & AGI_VIEW_CLEAR_ZBUFFER) && agiEnableZBuffer)
        {
            if (rect.x == 0 && rect.y == 0 && rect.w == pipe_width && rect.h == pipe_height)
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

    void SetBackground(aconst Vector3& color) override
    {
        clear_color_ = Pipe()->GetScreenColorModel()->GetColor(color);
    }

    agiSDLSWPipeline* Pipe()
    {
        return static_cast<agiSDLSWPipeline*>(agiViewport::Pipe());
    }

private:
    u32 clear_color_ {};
};

static u32 GetSDLPixelFormat(const agiPixelFormat& format)
{
    switch (format.RBitMask)
    {
        case 0xF800: return SDL_PIXELFORMAT_RGB565;
        case 0xF00: return (format.RGBAlphaBitMask == 0xF000) ? SDL_PIXELFORMAT_ARGB4444 : SDL_PIXELFORMAT_XRGB4444;
        case 0x7C00: return (format.RGBAlphaBitMask == 0x8000) ? SDL_PIXELFORMAT_ARGB1555 : SDL_PIXELFORMAT_XRGB1555;

        default:
            Quitf("Invalid Format %x / %x / %x / %s", format.RBitMask, format.GBitMask, format.BBitMask,
                format.RGBAlphaBitMask);
    }
}

class agiSDLBitmap final : public agiBitmap
{
public:
    agiSDLBitmap(agiSDLSWPipeline* pipe)
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

        // FIXME: Some RV3 bitmaps (ICON_*) have incorrect pitch.
        surface_->FixPitch();

        sdl_surface_ = SDL_CreateRGBSurfaceWithFormat(
            0, width_, height_, 16, GetSDLPixelFormat(Pipe()->GetScreenFormat().PixelFormat));

        SDL_Surface* source = SDL_CreateRGBSurfaceWithFormatFrom(surface_->Surface, surface_->Width, surface_->Height,
            16, surface_->Pitch, GetSDLPixelFormat(surface_->PixelFormat));

        SDL_BlitScaled(source, NULL, sdl_surface_, NULL);
        SDL_FreeSurface(source);

        state_ = 1;

        if (name_[0] != '*' || (flags_ & BITMAP_UNLOAD_ALWAYS))
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
    SDL_Surface* sdl_surface_ {};
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

    SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0);
    SDL_RenderClear(sdl_renderer_);

    debugTri = 0;
}

static mem::cmd_param PARAM_use555 {"use555"};

i32 agiSDLSWPipeline::BeginGfx()
{
    if (gfx_started_)
        return AGI_ERROR_ALREADY_INITIALIZED;

    bit_depth_ = 16;
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

    const auto& screen_format = PARAM_use555 ? PixelFormat_X1R5G5B5 : PixelFormat_R5G6B5;

    render_surface_ = SDL_CreateRGBSurfaceWithFormat(0, width_, height_, 16, GetSDLPixelFormat(screen_format));

    render_texture_ = SDL_CreateTexture(
        sdl_renderer_, GetSDLPixelFormat(screen_format), SDL_TEXTUREACCESS_STREAMING, width_, height_);

    swFbWidth = width_;
    swFbHeight = height_;

    screen_format_ = agiSurfaceDesc::FromFormat(screen_format);
    opaque_format_ = agiSurfaceDesc::FromFormat(PixelFormat_P8);
    alpha_format_ = opaque_format_;

    swBytesPerPixel = screen_format.RGBBitCount >> 3;
    swRedMask = screen_format.RBitMask;
    swGreenMask = screen_format.GBitMask;
    swBlueMask = screen_format.BBitMask;

    Displayf("SCREEN MODEL: %x / %x / %x", screen_format.RBitMask, screen_format.GBitMask, screen_format.BBitMask);

    swInit();

    renderer_ = MakeRc<agiZBufRenderer>(new agiSWRasterizer(this));

    if (bit_depth_ == 8)
    {
        screen_color_model_ = MakeRc<agiColorModel8>(&agiPal);
    }
    else
    {
        screen_color_model_ = AsRc(agiColorModel::FindMatch(swRedMask, swGreenMask, swBlueMask, 0));
    }

    text_color_model_ = screen_color_model_;

    opaque_color_model_ = MakeRc<agiColorModel8>(&agiPal);
    alpha_color_model_ = opaque_color_model_;

    TexSearchPath = xconst("texp\0");

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

#ifdef ARTS_DEV_BUILD
    ++agiBitmapCount;
    agiBitmapPixels += width * height;
#endif

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

RcOwner<agiBitmap> agiSDLSWPipeline::CreateBitmap()
{
    return AsOwner(MakeRc<agiSDLBitmap>(this));
}

RcOwner<DLP> agiSDLSWPipeline::CreateDLP()
{
    return AsOwner(MakeRc<RDLP>(this));
}

RcOwner<agiLight> agiSDLSWPipeline::CreateLight()
{
    return AsOwner(MakeRc<agiBILight>(this));
}

RcOwner<agiLightModel> agiSDLSWPipeline::CreateLightModel()
{
    return AsOwner(MakeRc<agiBILightModel>(this));
}

RcOwner<agiMtlDef> agiSDLSWPipeline::CreateMtlDef()
{
    return nullptr;
}

RcOwner<agiTexDef> agiSDLSWPipeline::CreateTexDef()
{
    return AsOwner(MakeRc<agiSWTexDef>(reinterpret_cast<agiSWPipeline*>(this)));
}

RcOwner<agiTexLut> agiSDLSWPipeline::CreateTexLut()
{
    return AsOwner(MakeRc<agiSWTexLut>(reinterpret_cast<agiSWPipeline*>(this)));
}

RcOwner<agiViewport> agiSDLSWPipeline::CreateViewport()
{
    return AsOwner(MakeRc<agiSDLViewport>(this));
}

void agiSDLSWPipeline::EndFrame()
{
    ARTS_UTIMED(agiEndFrame);

    if (ScreenShotRequested())
        SaveScreenShot(CaptureScreen());

    SDL_UpdateTexture(render_texture_, NULL, render_surface_->pixels, render_surface_->pitch);

    SDL_Rect dest {blit_x_, blit_y_, blit_width_, blit_height_};
    SDL_RenderCopy(sdl_renderer_, render_texture_, NULL, &dest);

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

    if (render_surface_)
    {
        SDL_FreeSurface(render_surface_);
        render_surface_ = nullptr;
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

Ptr<agiSurfaceDesc> agiSDLSWPipeline::CaptureScreen()
{
    i32 width = render_surface_->w;
    i32 height = render_surface_->h;

    Ptr<agiSurfaceDesc> surface =
        AsPtr(agiSurfaceDesc::Init(width, height, agiSurfaceDesc::FromFormat(PixelFormat_B8G8R8)));

    SDL_ConvertPixels(width, height, render_surface_->format->format, render_surface_->pixels, render_surface_->pitch,
        SDL_PIXELFORMAT_BGR24, static_cast<u8*>(surface->Surface) + surface->Pitch * (height - 1), -surface->Pitch);

    return surface;
}

Owner<agiPipeline> sdlCreatePipeline([[maybe_unused]] i32 argc, [[maybe_unused]] char** argv)
{
    Ptr<agiSDLSWPipeline> result = MakeUnique<agiSDLSWPipeline>();
    result->Init();
    return AsOwner(result);
}
