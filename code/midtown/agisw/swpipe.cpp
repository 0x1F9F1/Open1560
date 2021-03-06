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

define_dummy_symbol(agisw_swpipe);

#include "swpipe.h"
#include "agi/cmodel8.h"
#include "agi/error.h"
#include "agi/mtldef.h"
#include "agi/palette.h"
#include "agi/texdef.h"
#include "agid3d/dderror.h"
#include "agirend/bilight.h"
#include "agirend/bilmodel.h"
#include "agirend/lighter.h"
#include "agirend/rdlp.h"
#include "agirend/zbrender.h"
#include "core/minwin.h"
#include "data7/utimer.h"
#include "eventq7/winevent.h"
#include "pcwindis/dxinit.h"
#include "swddraw.h"
#include "swrend.h"
#include "swrsys.h"
#include "swtexdef.h"

class agiSWViewport final : public agiViewport
{
    // const agiSWViewport::`vftable' @ 0x621248

public:
    agiSWViewport(class agiSWPipeline* pipe)
        : agiViewport(pipe)
    {}

    // 0x534BE0 | ??_EagiSWViewport@@UAEPAXI@Z
    // 0x534BE0 | ??_GagiSWViewport@@UAEPAXI@Z
    // 0x534C10 | ??1agiSWViewport@@UAE@XZ | inline
    ARTS_EXPORT ~agiSWViewport() override = default;

    // 0x534930 | ?Activate@agiSWViewport@@UAEXXZ | inline
    ARTS_EXPORT void Activate() override
    {
        agiViewport::Active = this;
        ++agiViewParameters::ViewSerial;
        ++agiViewParameters::MtxSerial;
    }

    // 0x534BC0 | ?BeginGfx@agiSWViewport@@UAEHXZ | inline
    ARTS_EXPORT i32 BeginGfx() override
    {
        return AGI_ERROR_SUCCESS;
    }

    // 0x5349B0 | ?Clear@agiSWViewport@@UAEXH@Z | inline
    ARTS_IMPORT void Clear(i32 color) override;

    // 0x534BD0 | ?EndGfx@agiSWViewport@@UAEXXZ | inline
    ARTS_EXPORT void EndGfx() override
    {}

    // 0x534950 | ?SetBackground@agiSWViewport@@UAEXAAVVector3@@@Z | inline
    ARTS_EXPORT void SetBackground(class Vector3& color) override
    {
        clear_color_ = Pipe()->GetHiColorModel()->GetColor(color);
    }

private:
    u32 clear_color_ {0};
};

check_size(agiSWViewport, 0x14C);

static DDCOLORKEY ddk {};

// TODO: Merge with agiDDBitmap (identical code)
class agiSWBitmap final : public agiBitmap
{
    // const agiSWBitmap::`vftable' @ 0x621288

public:
    agiSWBitmap(class agiSWPipeline* pipe)
        : agiBitmap(pipe)
    {}

    agiSWPipeline* Pipe() const
    {
        return static_cast<agiSWPipeline*>(agiRefreshable::Pipe());
    }

    // 0x534DF0 | ??_GagiSWBitmap@@UAEPAXI@Z
    // 0x534DF0 | ??_EagiSWBitmap@@UAEPAXI@Z
    // 0x534E20 | ??1agiSWBitmap@@UAE@XZ | inline
    ARTS_EXPORT ~agiSWBitmap() override
    {
        EndGfx();
    }

    // 0x534C20 | ?BeginGfx@agiSWBitmap@@UAEHXZ | inline
    ARTS_EXPORT i32 BeginGfx() override
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

        DDSURFACEDESC2 ddsdDest {sizeof(ddsdDest)};

        ddsdDest.dwWidth = width_;
        ddsdDest.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
        ddsdDest.dwHeight = height_;
        ddsdDest.ddsCaps.dwCaps = (flags_ & AGI_BITMAP_OFFSCREEN) ? DDSCAPS_OFFSCREENPLAIN : DDSCAPS_SYSTEMMEMORY;

        if (Pipe()->GetDirectDraw()->CreateSurface(&ddsdDest, &d_surf_, nullptr))
        {
            Quitf("CreateSurface: '%s': %d x %d %dbpp failed.", name_.get(), ddsdDest.dwWidth, ddsdDest.dwHeight,
                ddsdDest.ddpfPixelFormat.dwRGBBitCount);
        }

        DD_TRY(d_surf_->Lock(nullptr, &ddsdDest, DDLOCK_WAIT, nullptr));

        agiSurfaceDesc surface = agiSurfaceDesc::FromDDSD2(ddsdDest);
        surface.CopyFrom(surface_.get(), 0);

        DD_TRY(d_surf_->Unlock(nullptr));

        state_ = 1;

        DDSCAPS2 caps {};
        caps.dwCaps = DDSCAPS_TEXTURE;
        DWORD dwTotal = 0;
        DWORD dwFree = 0;
        DD_TRY(Pipe()->GetDirectDraw()->GetAvailableVidMem(&caps, &dwTotal, &dwFree));

        agiDisplayf("Bitmap %s: %d bytes texture memory total, %d available", name_.get(), dwTotal, dwFree);

        if (name_[0] != '*' || (flags_ & AGI_BITMAP_UNLOAD_ALWAYS))
            surface_->Unload();

        UpdateFlags();

        return AGI_ERROR_SUCCESS;
    }

    // 0x534DC0 | ?EndGfx@agiSWBitmap@@UAEXXZ | inline
    ARTS_EXPORT void EndGfx() override
    {
        if (state_ != 0)
        {
            DD_RELEASE(d_surf_);

            state_ = 0;
        }
    }

    // 0x534DE0 | ?Restore@agiSWBitmap@@UAEXXZ | inline
    ARTS_EXPORT void Restore() override
    {
        EndGfx();
        BeginGfx();
    }

    // 0x534DA0 | ?UpdateFlags@agiSWBitmap@@UAEXXZ | inline
    ARTS_EXPORT void UpdateFlags() override
    {
        DD_TRY(d_surf_->SetColorKey(DDCKEY_SRCBLT, IsTransparent() ? &ddk : nullptr));
    }

    IDirectDrawSurface4* GetDDSurface() const
    {
        return d_surf_;
    }

private:
    IDirectDrawSurface4* d_surf_ {nullptr};
};

check_size(agiSWBitmap, 0x40);

agiSWPipeline::agiSWPipeline(i32 /*argc*/, char** /*argv*/)
{
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetDC(hwnd);
    horz_res_ = GetDeviceCaps(hdc, HORZRES);
    vert_res_ = GetDeviceCaps(hdc, VERTRES);
    ReleaseDC(hwnd, hdc);
}

agiSWPipeline::~agiSWPipeline() = default;

static mem::cmd_param PARAM_width {"width"};
static mem::cmd_param PARAM_height {"height"};
static mem::cmd_param PARAM_depth {"depth"};
static mem::cmd_param PARAM_vsync {"vsync"};

static mem::cmd_param PARAM_pack {"pack"};
static mem::cmd_param PARAM_annotate {"annotate"};

static mem::cmd_param PARAM_window {"window"};

void agiSWPipeline::Init()
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

    ddAttach(device_flags_1_, bit_depth_);
}

void agiSWPipeline::BeginFrame()
{
    agiPipeline::BeginFrame();
    swFbStartFrame();

    if (lpdsFront->IsLost() && (ActiveFlag & 1))
    {
        lpdsFront->Restore();
        RestoreAll();
    }
}

i32 agiSWPipeline::BeginGfx()
{
    gfx_started_ = true;

    dxiWidth = width_;
    dxiHeight = height_;
    dxiDepth = bit_depth_;

    dxiSetDisplayMode();
    swFbStart();

    screen_format_ = swScreenDesc;
    swInit();

    // FIXME: Leaks agiSWRasterizer
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
    valid_bit_depths_ = 0x1;
    agiCurState.SetMaxTextures(1);

    return AGI_ERROR_SUCCESS;
}

void agiSWPipeline::BeginScene()
{
    in_scene_ = true;
    swFbStartScene();
    renderer_->BeginGroup();
    agiLighter::BeginScene();
    UpdateLutQueue();
}

void agiSWPipeline::ClearAll(i32 color)
{
    DDBLTFX blt {sizeof(blt)};
    blt.dwFillColor = color;

    lpdsFront->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &blt);
    lpdsBack->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &blt);

    if (lpdsBack2)
        lpdsBack2->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &blt);

    lpdsRend->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &blt);
}

void agiSWPipeline::ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color)
{
    DDBLTFX blt {sizeof(blt)};
    blt.dwFillColor = color;

    RECT rect {x, y, x + width, y + height};

    lpdsRend->Blt(&rect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &blt);
}

void agiSWPipeline::CopyBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height)
{
    ++agiBitmapCount;
    agiBitmapPixels += width * height;

    // TODO: Implement DrawMode 3

    if (IsAppActive() && (dst_x >= 0) && (dst_x + width <= width_) && (dst_y >= 0) && (dst_y + height <= height_))
    {
        ARTS_UTIMED(agiCopyBitmap);

        if ((dst_x == 0) && (dst_y == 0) && (width == width_) && (height == height_))
            std::memset(swDepthBuffer, 0xFF, sizeof(u16) * swFbWidth * swFbHeight);

        RECT rect {src_x, src_y, src_x + width, src_y + height};

        HRESULT error = lpdsRend->BltFast(dst_x, dst_y, static_cast<agiSWBitmap*>(src)->GetDDSurface(), &rect,
            DDBLTFAST_WAIT | (src->IsTransparent() ? DDBLTFAST_SRCCOLORKEY : DDBLTFAST_NOCOLORKEY));

        if (error)
        {
            if (error != DDERR_INVALIDRECT) // FIXME: Avoid DDERR_INVALIDRECT spam
                Errorf("CopyBitmap (%s) failed: code = 0x%08X", src->GetName(), error);
        }
    }
}

RcOwner<class agiBitmap> agiSWPipeline::CreateBitmap()
{
    return AsOwner(MakeRc<agiSWBitmap>(this));
}

RcOwner<class DLP> agiSWPipeline::CreateDLP()
{
    return AsOwner(MakeRc<RDLP>(this));
}

RcOwner<class agiLight> agiSWPipeline::CreateLight()
{
    return AsOwner(MakeRc<agiBILight>(this));
}

RcOwner<class agiLightModel> agiSWPipeline::CreateLightModel()
{
    return AsOwner(MakeRc<agiBILightModel>(this));
}

RcOwner<class agiMtlDef> agiSWPipeline::CreateMtlDef()
{
    return nullptr;
}

RcOwner<class agiTexDef> agiSWPipeline::CreateTexDef()
{
    return AsOwner(MakeRc<agiSWTexDef>(this));
}

RcOwner<class agiTexLut> agiSWPipeline::CreateTexLut()
{
    return AsOwner(MakeRc<agiSWTexLut>(this));
}

RcOwner<class agiViewport> agiSWPipeline::CreateViewport()
{
    return AsOwner(MakeRc<agiSWViewport>(this));
}

void agiSWPipeline::EndFrame()
{
    swFbEndFrame();
    agiPipeline::EndFrame();
}

void agiSWPipeline::EndGfx()
{
    swKill();
    swFbEnd();
    gfx_started_ = false;
}

void agiSWPipeline::EndScene()
{
    renderer_->EndGroup();
    swFbEndScene();
    in_scene_ = false;
}

i32 agiSWPipeline::Validate()
{
    return AGI_ERROR_SUCCESS;
}

b32 agiSWPipeline::PrintIs3D()
{
    return true;
}

// 0x5342F0 | ?zmemset@@YAXPAGI@Z
ARTS_EXPORT /*static*/ void zmemset(u16* values, u32 count)
{
    std::memset(values, 0xFF, count * sizeof(u16[4]));
}

Owner<class agiPipeline> swCreatePipeline(i32 argc, char** argv)
{
    Ptr<agiSWPipeline> result = MakeUnique<agiSWPipeline>(argc, argv);
    result->Init();
    return AsOwner(result);
}
