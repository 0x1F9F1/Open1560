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

define_dummy_symbol(agid3d_ddpipe);

#include "ddpipe.h"

#include "agi/cmodel.h"
#include "agi/cmodel8.h"
#include "agi/error.h"
#include "agi/palette.h"
#include "agi/rsys.h"
#include "agi/texdef.h"
#include "ddbitmap.h"
#include "dderror.h"
#include "pcpipe.h"
#include "pcwindis/dxinit.h"

agiDDPipeline::agiDDPipeline()
{
    // TODO: Use window_ ?
    HDC hdc = GetDC(nullptr);
    horz_res_ = GetDeviceCaps(hdc, HORZRES);
    vert_res_ = GetDeviceCaps(hdc, VERTRES);
    ReleaseDC(nullptr, hdc);
}

agiDDPipeline::~agiDDPipeline()
{
    EndGfx();
}

static mem::cmd_param PARAM_width {"width"};
static mem::cmd_param PARAM_height {"height"};
static mem::cmd_param PARAM_depth {"depth"};

static mem::cmd_param PARAM_labelf {"labelf"};
static mem::cmd_param PARAM_labelp {"labelp"};

static mem::cmd_param PARAM_pack {"pack"};
static mem::cmd_param PARAM_mip {"mip"};

static mem::cmd_param PARAM_square {"square"};
static mem::cmd_param PARAM_nfog {"nfog"};
static mem::cmd_param PARAM_multitex {"multitex"};
static mem::cmd_param PARAM_annotate {"annotate"};

void agiDDPipeline::Init()
{
    width_ = PARAM_width.get_or<i32>(640);
    height_ = PARAM_height.get_or<i32>(480);
    bit_depth_ = PARAM_depth.get_or<i32>(16);

    // TODO: Add other command options

    DrawLabelFArg = PARAM_labelf.get_or(false);
    NoBlitHack |= DrawLabelFArg;

    DrawLabelPArg = PARAM_labelp.get_or(false);
    NoBlitHack |= DrawLabelFArg;

    PackShift = PARAM_pack.get_or<i32>(0);
    NoMip = !PARAM_mip.get_or(true);
    ForceSquare = PARAM_square.get_or(false);
    NormalizedFog = PARAM_nfog.get_or(false);
    NoMultiTexture = !PARAM_multitex.get_or(true);
    AnnotateTextures = PARAM_annotate.get_or(false);

    device_flags_1_ = 0x1032; // hal, zbuffer, vram
    device_flags_3_ = 0x0;

    device_flags_2_ = device_flags_1_;

    if (device_flags_3_ == 0x0)
        device_flags_3_ = device_flags_1_;
}

void agiDDPipeline::BeginFrame()
{
    if (DDNeedRestore)
    {
        agiDisplayf("RESTORING GRAPHICS STATE");
        EndAllGfx();
        DDNeedRestore = false;
        BeginAllGfx();

        if (DDNeedRestore)
        {
            Errorf("RESTORE FAILED!");
            DDNeedRestore = false;
        }
    }
}

i32 agiDDPipeline::BeginGfx()
{
    if (gfx_started_)
        return AGI_ERROR_ALREADY_INITIALIZED;

    flags_ = 0;
    set_rend_palette_ = dxiIsFullScreen();

    dxiWidth = width_;
    dxiHeight = height_;
    dxiDepth = bit_depth_;

    dxiSetDisplayMode();

    // TODO: Use window_ ?
    HDC hdc = GetDC(nullptr);
    i32 bit_depth = GetDeviceCaps(hdc, BITSPIXEL);
    horz_res_ = GetDeviceCaps(hdc, HORZRES);
    vert_res_ = GetDeviceCaps(hdc, VERTRES);
    ReleaseDC(nullptr, hdc);

    if (bit_depth_ == 0)
        bit_depth_ = bit_depth;

    d_draw_ = lpDD4;
    d_front_ = lpdsFront;
    d_back_ = lpdsBack;
    d_rend_ = lpdsRend;
    d_clip_ = lpClip;

    d_pix_format_ = {sizeof(d_pix_format_)};
    DD_TRY(d_front_->GetPixelFormat(&d_pix_format_));

    PALETTEENTRY ddpal[256] {};

    if (!(DrawModeAnd & 0x1))
    {
        for (i32 i = 0; i < agiPal.ColorCount; ++i)
            ddpal[i] = mem::bit_cast<PALETTEENTRY>((agiPal.Colors[i] & 0xFFFFFF) | 0x40000000);
    }

    DD_TRY(d_draw_->CreatePalette(DDPCAPS_8BIT | DDPCAPS_ALLOW256, ddpal, &d_pal_, nullptr));

    if (bit_depth_ == 8)
    {
        hi_color_model_ = MakeRc<agiColorModel8>(&agiPal);

        DD_TRY(d_front_->SetPalette(d_pal_));
        DD_TRY(d_back_->SetPalette(d_pal_));

        if (set_rend_palette_)
        {
            DD_TRY(d_rend_->SetPalette(d_pal_));
        }
    }
    else
    {
        DDSURFACEDESC2 screen_desc {sizeof(screen_desc)};

        // NOTE: Originally used lpdsFront
        d_front_->GetSurfaceDesc(&screen_desc);

        screen_format_ = ConvertSurfaceDesc(screen_desc);
        d_pix_format_ = screen_desc.ddpfPixelFormat;

        hi_color_model_ = AsRc(agiColorModel::FindMatch(d_pix_format_.dwRBitMask, d_pix_format_.dwGBitMask,
            d_pix_format_.dwBBitMask, d_pix_format_.dwRGBAlphaBitMask));

        if (hi_color_model_ == nullptr)
        {
            Quitf("Unsupported hicolor model R=%x G=%x B=%x A=%x", d_pix_format_.dwRBitMask, d_pix_format_.dwGBitMask,
                d_pix_format_.dwBBitMask, d_pix_format_.dwRGBAlphaBitMask);
        }
    }

    opaque_color_model_ = hi_color_model_;
    alpha_color_model_ = hi_color_model_;
    text_color_model_ = hi_color_model_;

    gfx_started_ = 1;

    return AGI_ERROR_SUCCESS;
}

void agiDDPipeline::BeginScene()
{
    DDSURFACEDESC2 ddsd {sizeof(ddsd)};

    DD_TRY(d_rend_->Lock(nullptr, &ddsd, DDLOCK_WAIT, nullptr));
}

void agiDDPipeline::ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color)
{
    DDBLTFX fx {sizeof(fx)};
    fx.dwFillColor = color;

    RECT rect {};
    rect.left = x;
    rect.top = y;
    rect.right = x + width;
    rect.bottom = y + height;

    // NOTE: Used lpdsRend
    d_rend_->Blt(&rect, nullptr, nullptr, DDBLT_WAIT | DDBLT_COLORFILL, &fx);
}

void agiDDPipeline::CopyBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height)
{
    ++agiBitmapCount;
    agiBitmapPixels += width * height;

    // TODO: Implement DrawMode 3
    // TODO: ARTS_UTIMED(agiCopyBitmap);

    RECT rect {};
    rect.left = src_x;
    rect.top = src_y;
    rect.right = width + src_x;
    rect.bottom = height + src_y;

    if (dst_x >= 0 && dst_y >= 0 && width && height)
    {
        if (dst_x <= width_ - width && dst_y <= height_ - height)
            d_rend_->BltFast(dst_x, dst_y, static_cast<agiDDBitmap*>(src)->GetDDSurface(), &rect,
                DDBLTFAST_WAIT | (src->IsTransparent() ? DDBLTFAST_SRCCOLORKEY : DDBLTFAST_NOCOLORKEY));
    }
    else
    {
        Errorf("%s: Bad copybitmap size (%d, %d, %d, %d)", src ? src->GetName() : nullptr, dst_x, dst_y, width, height);
    }
}

RcOwner<class agiBitmap> agiDDPipeline::CreateBitmap()
{
    return AsOwner(MakeRc<agiDDBitmap>(this));
}

void agiDDPipeline::EndFrame()
{}

void agiDDPipeline::EndGfx()
{
    SafeRelease(d_pal_);
    gfx_started_ = false;

    text_color_model_ = nullptr;
    hi_color_model_ = nullptr;
    opaque_color_model_ = nullptr;
    alpha_color_model_ = nullptr;
}

void agiDDPipeline::EndScene()
{}

b32 agiDDPipeline::LockFrameBuffer(agiSurfaceDesc& surface)
{
    DDSURFACEDESC2 ddsd {sizeof(ddsd)};

    if (d_rend_->Lock(nullptr, &ddsd, DDLOCK_WAIT, nullptr))
        return false;

    surface = ConvertSurfaceDesc(ddsd);

    return true;
}

void agiDDPipeline::UnlockFrameBuffer()
{
    d_rend_->Unlock(nullptr);
}

i32 agiDDPipeline::Validate()
{
    return 0;
}
