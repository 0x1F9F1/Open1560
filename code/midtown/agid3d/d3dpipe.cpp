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

define_dummy_symbol(agid3d_d3dpipe);

#include "d3dpipe.h"

#include "agi/cmodel.h"
#include "agi/cmodel8.h"
#include "agi/error.h"
#include "agi/palette.h"
#include "agi/render.h"
#include "agi/rsys.h"
#include "d3dlight.h"
#include "d3dmtldef.h"
#include "d3drsys.h"
#include "d3dtexdef.h"
#include "d3dview.h"
#include "data7/utimer.h"
#include "ddbitmap.h"
#include "dderror.h"
#include "eventq7/winevent.h"
#include "pcpipe.h"
#include "pcwindis/dxinit.h"
#include "stream/stream.h"

// 0x5307B0 | ?EnumCallback@@YGJPAU_GUID@@PAD1PAU_D3DDeviceDesc@@2PAX@Z
ARTS_IMPORT /*static*/ long ARTS_STDCALL EnumCallback(
    struct _GUID* arg1, char* arg2, char* arg3, struct _D3DDeviceDesc* arg4, struct _D3DDeviceDesc* arg5, void* arg6);

// 0x5308B0 | ?EnumTextureCallback@@YGJPAU_DDPIXELFORMAT@@PAX@Z
ARTS_IMPORT /*static*/ long ARTS_STDCALL EnumTextureCallback(struct _DDPIXELFORMAT* arg1, void* arg2);

agiD3DPipeline::agiD3DPipeline()
{
    PROBER = agiD3DTexDef::Prober;
}

agiD3DPipeline::~agiD3DPipeline()
{
    EndGfx();
}

void agiD3DPipeline::BeginFrame()
{
    ARTS_UTIMED(agiBeginFrame);

    if (d_front_->IsLost() && (ActiveFlag & 0x1))
    {
        d_draw_->RestoreAllSurfaces();
        Displayf("Trying to restore stuff...");
        d_front_->Restore();
        Displayf("Did FB");
        d_zbuffer_->Restore();
        Displayf("Did ZB");
        RestoreAll();
        Displayf("Did RestoreAll");
    }

    // TODO: Should this call agiDDPipeline::BeginFrame ?
    agiPipeline::BeginFrame();
}

static extern_var(0x795BDC, const char*, WantedDeviceName);

static DDPIXELFORMAT ZBufferFormat;

// 0x530980 | ?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z
static long ARTS_STDCALL EnumZ(struct _DDPIXELFORMAT* format, void* context)
{
    agiDisplayf("Z bit depth = %d", format->dwRGBBitCount);

    if ((ZBufferFormat.dwSize == 0) ||
        (static_cast<agiPipeline*>(context)->GetDepth() == static_cast<i32>(format->dwRGBBitCount)))
        ZBufferFormat = *format;

    return 1;
}

static extern_var(0x7957D8, DDPIXELFORMAT[32], TextureFormats);
static extern_var(0x795BE0, i32, TextureFormatCount);

static mem::cmd_param PARAM_afilter {"afilter"};

i32 agiD3DPipeline::BeginGfx()
{
    if (gfx_started_)
        return AGI_ERROR_ALREADY_INITIALIZED;

    if (i32 error = agiDDPipeline::BeginGfx())
        return error;

    text_color_model_ = AsRc(agiColorModel::FindMatch(0xFF0000, 0xFF00, 0xFF, 0xFF000000));

    if (u32 black = text_color_model_->GetColor(0, 0, 0, 0))
        Quitf("black isn't zero -- %d", black);

    filter_caps_ = 0;

    IDirect3D* d3d_temp = nullptr;
    DD_TRY(d_draw_->QueryInterface(IID_IDirect3D, (void**) &d3d_temp));
    DD_TRY(d3d_temp->QueryInterface(IID_IDirect3D3, (void**) &d3d_));
    d3d_temp->Release();

    if (device_flags_1_ & 0x400)
        WantedDeviceName = "Ramp Emulation";
    else if (device_flags_1_ & 0x800)
        WantedDeviceName = "RGB Emulation";
    else if (device_flags_1_ & 0x1000)
        WantedDeviceName = "Direct3D HAL";
    else if (device_flags_1_ & 0x2000)
        WantedDeviceName = "MMX Emulation";
    else
        WantedDeviceName = nullptr;

    device_name_ = nullptr;
    DD_TRY(d3d_->EnumDevices(EnumCallback, this));

    if (device_name_ == nullptr)
        return AGI_ERROR_NO_DEVICE;

    agiDisplayf("Using device '%s' (%sware)", device_name_, is_hardware_ ? "Hard" : "Soft");

    agiCurState.SetTexturePerspective(true);
    agiCurState.SetDither(true);
    agiCurState.SetSmoothShading(true);

    if (is_hardware_)
        flags_ |= 0x4;

    if (device_flags_1_ & 0x10)
    {
        flags_ |= 0x1;

        ZBufferFormat = {};
        DD_TRY(d3d_->EnumZBufferFormats(d3d_guid_, EnumZ, this));

        DDSURFACEDESC2 zsd {sizeof(zsd)};
        zsd.dwWidth = width_;
        zsd.dwHeight = height_;
        zsd.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT;
        zsd.ddsCaps.dwCaps = DDSCAPS_ZBUFFER | (is_hardware_ ? DDSCAPS_VIDEOMEMORY : DDSCAPS_SYSTEMMEMORY);
        zsd.ddpfPixelFormat = ZBufferFormat;

        if (d_draw_->CreateSurface(&zsd, &d_zbuffer_, nullptr))
            return AGI_ERROR_UNSUPPORTED;

        DD_TRY(d_rend_->AddAttachedSurface(d_zbuffer_));
        DD_TRY(d_zbuffer_->GetCaps(&zsd.ddsCaps));

        if (is_hardware_ && !(zsd.ddsCaps.dwCaps & DDSCAPS_VIDEOMEMORY))
            Quitf("Couldn't fit zbuffer in video memory.");
    }
    else
    {
        d_zbuffer_ = nullptr;
    }

    DD_TRY(d3d_->CreateDevice(d3d_guid_, d_rend_, &d3d_device_, nullptr));

    if (d3d_device_ == nullptr)
        Quitf("Failed to create D3D Device.\n"
              "If you are using native DDRAW and a resolution larger than 2048, try using the -reshack command "
              "parameter.");

    d3ddev = d3d_device_;
    d3d_state_init();

    if ((MaxTexMem < 0) || ((MaxTexMem == 0) && (device_desc_.dwDevCaps & D3DDEVCAPS_TEXTURENONLOCALVIDMEM)))
    {
        agiDisplayf("AGP %s, will use non-local video memory for tex cache", MaxTexMem >= 0 ? "detected" : "FORCED");
    }
    else
    {
        agiDisplayf("AGP not detected, local video memory ONLY for tex cache");

        if (MaxTexMem != 0)
            agiDisplayf("Max tex memory usage is %d Kbytes.", MaxTexMem >> 10);
    }

    i32 wanted_depth = 0;
    i32 valid_depths = device_desc_.dwDeviceRenderBitDepth;

    // NOTE: Removed 8-bit, added 24-bit
    if ((bit_depth_ == 16) && !(valid_depths & DDBD_16))
        wanted_depth = 16;
    else if ((bit_depth_ == 24) && !(valid_depths & DDBD_24))
        wanted_depth = 24;
    else if ((bit_depth_ == 32) && !(valid_depths & DDBD_32))
        wanted_depth = 32;

    valid_bit_depths_ = 0;

    if (valid_depths & DDBD_16)
        valid_bit_depths_ |= 0x1;

    if (valid_depths & DDBD_24)
        valid_bit_depths_ |= 0x2;

    if (valid_depths & DDBD_32)
        valid_bit_depths_ |= 0x4;

    if (wanted_depth)
        Quitf("Can't render to this bitdepth, please rerun with '-depth %d' option.", wanted_depth);

    agiDisplayf("Z cmp caps = %x", device_desc_.dpcTriCaps.dwZCmpCaps);
    agiDisplayf("Alpha cmp caps = %x", device_desc_.dpcTriCaps.dwAlphaCmpCaps);
    agiDisplayf("Texture alpha: %s", (device_desc_.dpcTriCaps.dwTextureCaps & D3DPTEXTURECAPS_ALPHA) ? "yes" : "no");

    texture_filter_ = 0;

    i32 filter_caps = device_desc_.dpcTriCaps.dwTextureFilterCaps;

    if (is_hardware_ && !NoMip &&
        (filter_caps &
            (D3DPTFILTERCAPS_MIPNEAREST | D3DPTFILTERCAPS_MIPLINEAR | D3DPTFILTERCAPS_LINEARMIPNEAREST |
                D3DPTFILTERCAPS_LINEARMIPLINEAR)))
    {
        agiDisplayf("Can do mipmaps");

        filter_caps_ = filter_caps;

        if (filter_caps & (D3DPTFILTERCAPS_LINEARMIPNEAREST | D3DPTFILTERCAPS_LINEARMIPLINEAR))
            texture_filter_ |= 0x3;
        else if (filter_caps & (D3DPTFILTERCAPS_MIPNEAREST | D3DPTFILTERCAPS_MIPLINEAR))
            texture_filter_ |= 0x1;

        if (u32 filter_level = PARAM_afilter.get_or<u32>(16);
            (filter_level > 1) && (device_desc_.dpcTriCaps.dwRasterCaps & D3DPRASTERCAPS_ANISOTROPY))
        {
            if (filter_level > device_desc_.dwMaxAnisotropy)
                filter_level = device_desc_.dwMaxAnisotropy;

            agiDisplayf("Can do anisotropic %ux", filter_level);

            DD_TRY(d3d_device_->SetRenderState(D3DRENDERSTATE_ANISOTROPY, filter_level));

            texture_filter_ |= 0x4;
        }
    }

    Displayf("Texture mip filter quality: %s %s %s", (texture_filter_ & 0x4) ? "ANISOTROPIC" : "",
        (texture_filter_ & 0x2) ? "TRILINEAR" : "", (texture_filter_ & 0x1) ? "POINT" : "");

    if ((device_desc_.dpcTriCaps.dwTextureCaps & D3DPTEXTURECAPS_SQUAREONLY) || ForceSquare)
    {
        agiDisplayf("Textures must be square!");
        flags_ |= 0x20;
    }

    if (!(device_desc_.dpcTriCaps.dwTextureAddressCaps & D3DPTADDRESSCAPS_INDEPENDENTUV))
    {
        agiDisplayf("Textures DO NOT clamp/wrap independently");
        NotIndependentUV = 1;
    }

    TextureFormatCount = 0;
    DD_TRY(d3d_device_->EnumTextureFormats(EnumTextureCallback, this));
    TexSearchPath = const_cast<char*>("tex16a\0tex16o\0tex16\0");

    DDSCAPS2 vmcaps {};
    vmcaps.dwCaps = DDSCAPS_TEXTURE;
    DWORD dwTotal = 0;
    DWORD dwFree = 0;
    DD_TRY(d_draw_->GetAvailableVidMem(&vmcaps, &dwTotal, &dwFree));

    agiDisplayf("%u bytes texture memory total, %u available", dwTotal, dwFree);

    i32 opaque_format = 0;
    i32 alpha_format = 0;

    if (device_flags_1_ & 0x100)
    {
        for (i32 i = 1; i <= TextureFormatCount; ++i)
        {
            if (TextureFormats[i].dwFlags & DDPF_PALETTEINDEXED8)
            {
                opaque_format = i;
                TexSearchPath = const_cast<char*>("tex16a\0texp\0");
            }
        }
    }

    if (alpha_format == 0)
    {
        for (i32 i = 1; i <= TextureFormatCount; ++i)
        {
            if ((bit_depth_ == 32) && (TextureFormats[i].dwRGBAlphaBitMask == 0xFF000000)) // 8888
                alpha_format = i;
        }
    }

    if (alpha_format == 0)
    {
        for (i32 i = 1; i <= TextureFormatCount; ++i)
        {
            if (TextureFormats[i].dwRGBAlphaBitMask == 0xF000) // 4444
                alpha_format = i;
        }
    }

    if (alpha_format == 0)
    {
        for (i32 i = 1; i <= TextureFormatCount; ++i)
        {
            if (TextureFormats[i].dwRGBAlphaBitMask == 0x8000) // 5551
                alpha_format = i;
        }
    }

    if (opaque_format == 0)
    {
        u32 bit_count = (bit_depth_ == 32) ? 32 : 16;
        u32 rbit_mask = (bit_depth_ == 32) ? 0xFF0000 : 0xF800;

        for (i32 i = 1; i <= TextureFormatCount; ++i)
        {
            if ((TextureFormats[i].dwRGBBitCount == bit_count) && (TextureFormats[i].dwRBitMask == rbit_mask))
            {
                opaque_format = i;
                break;
            }
        }
    }

    if (opaque_format == 0)
    {
        for (i32 i = 1; i <= TextureFormatCount; ++i)
        {
            if ((TextureFormats[i].dwRGBBitCount == 16) && (TextureFormats[i].dwRBitMask == 0x7E00))
            {
                opaque_format = i;
                break;
            }
        }
    }

    if (opaque_format == 0)
    {
        for (i32 i = 1; i <= TextureFormatCount; ++i)
        {
            if ((TextureFormats[i].dwFlags & DDPF_ALPHAPIXELS) && (TextureFormats[i].dwRBitMask > 4))
            {
                opaque_format = i;
                if (alpha_format == 0)
                    alpha_format = i;
                break;
            }
        }
    }

    if (opaque_format == 0)
    {
        Warningf("punting on primary texture format!");
        opaque_format = 1;
    }

    if (alpha_format == 0)
        alpha_format = opaque_format;

    agiDisplayf("Texture Format: %d; Alpha Texture Format: %d", opaque_format, alpha_format);

    opaque_format_ = TextureFormats[opaque_format];
    alpha_format_ = TextureFormats[alpha_format];

    if (opaque_format_.dwRBitMask)
    {
        opaque_color_model_ = AsRc(agiColorModel::FindMatch(opaque_format_.dwRBitMask, opaque_format_.dwGBitMask,
            opaque_format_.dwBBitMask, opaque_format_.dwRGBAlphaBitMask));
    }
    else
    {
        opaque_color_model_ = MakeRc<agiColorModel8>(&agiPal);
    }

    if (alpha_format_.dwRBitMask)
    {
        alpha_color_model_ = AsRc(agiColorModel::FindMatch(alpha_format_.dwRBitMask, alpha_format_.dwGBitMask,
            alpha_format_.dwBBitMask, alpha_format_.dwRGBAlphaBitMask));
    }
    else
    {
        alpha_color_model_ = MakeRc<agiColorModel8>(&agiPal);
    }

    if (alpha_color_model_->BitCountA)
        flags_ |= 0x10;

    DD_TRY(d3d_->CreateViewport(&d3d_view_, nullptr));
    DD_TRY(d3d_device_->AddViewport(d3d_view_));
    DD_TRY(d3d_device_->SetCurrentViewport(d3d_view_));

    DD_TRY(d3d_device_->SetRenderState(D3DRENDERSTATE_ALPHAFUNC, D3DCMP_GREATER));

    DWORD num_codes = 0;
    d_draw_->GetFourCCCodes(&num_codes, nullptr);

    if (num_codes)
    {
        DWORD* codes = new DWORD[num_codes];
        d_draw_->GetFourCCCodes(&num_codes, codes);

        // TODO: Is S3TC actually valid/ever used?
#define FOURCC_S3TC (MAKEFOURCC('S', '3', 'T', 'C'))

        for (DWORD i = 0; i < num_codes; ++i)
        {
            if (codes[i] == FOURCC_S3TC)
                agiFOURCC = FOURCC_S3TC;
        }

        for (DWORD i = 0; i < num_codes; ++i)
        {
            if (codes[i] == FOURCC_DXT1)
                agiFOURCC = FOURCC_DXT1;
        }

#undef FOURCC_S3TC

        delete[] codes;

        if (agiFOURCC && !NoTextureCompression)
        {
            opaque_format_.dwFlags = DDPF_FOURCC;
            opaque_format_.dwFourCC = agiFOURCC;

            alpha_format_.dwFlags = DDPF_PALETTEINDEXED8;
            AlphaPalette = true;

            flags_ |= 0x10;

            TexSearchPath = const_cast<char*>("texs3\0tex16a\0tex16o\0");
        }
    }

    agiDisplayf("FOURCC (compression code) = %x", agiFOURCC);

    D3DDEVICEDESC hwcaps {sizeof(hwcaps)};
    D3DDEVICEDESC swcaps {sizeof(swcaps)};
    DD_TRY(d3d_device_->GetCaps(&hwcaps, &swcaps));

    max_tex_width_ = hwcaps.dwMaxTextureWidth ? hwcaps.dwMaxTextureWidth : 256;
    max_tex_height_ = hwcaps.dwMaxTextureHeight ? hwcaps.dwMaxTextureHeight : 256;

    agiDisplayf("Max texture size is %d by %d", max_tex_width_, max_tex_height_);

#ifndef ARTS_MULTI_TEXTURE
    NoMultiTexture = true;
#endif

    if (hwcaps.dwDevCaps & D3DDEVCAPS_SEPARATETEXTUREMEMORIES)
    {
        agiDisplayf("Separate texture memories (probably a voodoo!)");
        SeparateTextureMemories = false;
        NoMultiTexture = true;
    }

    agiCurState.SetMaxTextures(NoMultiTexture ? 1 : static_cast<i8>(hwcaps.wMaxSimultaneousTextures));

    if (agiCurState.GetMaxTextures() <= 1)
    {
        SeparateTextureMemories = false;
    }
    else
    {
        DD_TRY(d3d_device_->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 1));
    }

    return AGI_ERROR_SUCCESS;
}

void agiD3DPipeline::BeginScene()
{
    ARTS_UTIMED(agiBeginScene);

    agiPipeline::BeginScene();
    in_scene_ = true;

    if (ActiveFlag & 0x1)
    {
        DD_TRY(d3d_device_->BeginScene());
    }

    renderer_->BeginGroup();
}

void agiD3DPipeline::ClearAll(i32 color)
{
    DDBLTFX ddbltfx {sizeof(ddbltfx)};
    ddbltfx.dwFillColor = color;

    DD_TRY(d_rend_->Blt(nullptr, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx));
    DD_TRY(d_back_->Blt(nullptr, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx));
    DD_TRY(d_front_->Blt(nullptr, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx));
}

void agiD3DPipeline::CopyBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height)
{
    if (ActiveFlag & 0x1)
    {
        ARTS_UTIMED(agiCopyBitmap);

        agiDDPipeline::CopyBitmap(dst_x, dst_y, src, src_x, src_y, width, height);
    }
}

RcOwner<agiBitmap> agiD3DPipeline::CreateBitmap()
{
    return AsOwner(MakeRc<agiDDBitmap>(this));
}

RcOwner<agiLight> agiD3DPipeline::CreateLight()
{
    return AsOwner(MakeRc<agiD3DLight>(this));
}

RcOwner<agiMtlDef> agiD3DPipeline::CreateMtlDef()
{
    return AsOwner(MakeRc<agiD3DMtlDef>(this));
}

RcOwner<agiTexDef> agiD3DPipeline::CreateTexDef()
{
    return AsOwner(MakeRc<agiD3DTexDef>(this));
}

RcOwner<agiTexLut> agiD3DPipeline::CreateTexLut()
{
    if (!(device_flags_1_ & 0x100))
        return nullptr;

    return AsOwner(MakeRc<agiD3DTexLut>(this));
}

RcOwner<agiViewport> agiD3DPipeline::CreateViewport()
{
    return AsOwner(MakeRc<agiD3DViewport>(this));
}

void agiD3DPipeline::Defragment()
{
    d3d_->EvictManagedTextures();
}

static extern_var(0x795C1C, Stream*, SurfaceDumpStream);
static extern_var(0x795C08, i32, TotalTextureMem);

void agiD3DPipeline::DumpStatus(agiMemStatus& status)
{
    Displayf("BEGIN SURFACE DUMP");

    SurfaceDumpStream = arts_fopen("c:/surf.dump", "w");
    TotalTextureMem = 0;
    status = {};

    if (d_draw_)
        d_draw_->EnumSurfaces(DDENUMSURFACES_DOESEXIST | DDENUMSURFACES_ALL, nullptr, &status, callb);

    Displayf("END SURFACE DUMP: %d bytes (%dK) total.", TotalTextureMem, (TotalTextureMem + 1023) >> 10);

    arts_fprintf(SurfaceDumpStream, "TEXTURE: SYS: %d, AGP: %d LOCALVID: %d VID: %d\n", status.Texture[0],
        status.Texture[1], status.Texture[2], status.Texture[3]);

    arts_fprintf(SurfaceDumpStream, "BUFFER: SYS: %d, AGP: %d LOCALVID: %d VID: %d\n", status.Buffer[0],
        status.Buffer[1], status.Buffer[2], status.Buffer[3]);

    arts_fprintf(SurfaceDumpStream, "BITMAP: SYS: %d, AGP: %d LOCALVID: %d VID: %d\n", status.Bitmap[0],
        status.Bitmap[1], status.Bitmap[2], status.Bitmap[3]);

    arts_fprintf(SurfaceDumpStream, "TOTAL MEM: %d\n", TotalTextureMem);

    delete SurfaceDumpStream;
}

void agiD3DPipeline::EndFrame()
{
    ARTS_UTIMED(agiEndFrame);

    RECT r {};
    r.left = 0;
    r.top = 0;
    r.right = width_;
    r.bottom = height_;

    if (!dxiIsFullScreen())
    {
        RECT dr {};
        dr.left = x_;
        dr.top = y_;
        dr.right = dr.left + width_;
        dr.bottom = dr.top + height_;

        if (scale_ != 1.0f)
        {
            f32 scale = (1.0f - scale_) * 0.5f;

            // NOTE: Used CurrentPipe
            r.left = static_cast<LONG>(width_ * scale);
            r.top = static_cast<LONG>(height_ * scale);
            r.right = width_ - r.left;
            r.bottom = height_ - r.top;
        }

        DD_TRY(d_front_->Blt(&dr, d_back_, &r, DDBLT_WAIT, nullptr));
    }
    else if (dxiDoubleBuffer())
    {
        if (dxiUseSystemMemory())
        {
            DD_TRY(d_back_->BltFast(0, 0, d_rend_, &r, DDBLTFAST_NOCOLORKEY | DDBLTFAST_WAIT));
        }

        DD_TRY(d_front_->Flip(nullptr, DDFLIP_WAIT));
    }

    agiPipeline::EndFrame();
}

void agiD3DPipeline::EndGfx()
{
    if (d_zbuffer_)
    {
        DD_TRY(d_rend_->DeleteAttachedSurface(0, d_zbuffer_));
        DD_RELEASE(d_zbuffer_);
    }

    if (d3d_view_)
    {
        DD_TRY(d3d_device_->DeleteViewport(d3d_view_));
        SafeRelease(d3d_view_);
    }

    DD_RELEASE(d3d_device_);
    SafeRelease(d3d_);

    agiDDPipeline::EndGfx();
}

void agiD3DPipeline::EndScene()
{
    ARTS_UTIMED(agiEndScene);

    in_scene_ = false;
    renderer_->EndGroup();

    if (ActiveFlag & 0x1)
    {
        DD_TRY(d3d_device_->EndScene());
    }

    agiPipeline::EndScene();
}
