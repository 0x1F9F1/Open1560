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

define_dummy_symbol(agid3d_d3dtexdef);

#include "d3dtexdef.h"

#include "agi/error.h"
#include "agi/rsys.h"
#include "dderror.h"
#include "pcpipe.h"
#include "pcwindis/setupdata.h"
#include "vector7/vector2.h"

i32 agiD3DTexDef::BeginGfx()
{
    if (surface_ == nullptr)
    {
        Errorf("Missing SurfaceDesc for '%s' in BeginGfx - trouble is brewing!", tex_.Name);
        return AGI_ERROR_FILE_NOT_FOUND;
    }

    if (page_state_ == 0 && cache_handle_ == 0)
        surface_->Reload(tex_.Name, TexSearchPath, tex_.LOD, mip_reduction_, 0, 0, 0);

    if (!NoMultiTexture && agiCurState.GetMaxTextures() > 1 && !std::strncmp(tex_.Name, "SHADMAP", 7))
    {
        Displayf("Fixing shadow map '%s' for multitexturing...", tex_.Name);

        ArAssert(surface_->PixelFormat.RGBBitCount == 16, "Invalid SHADMAP Format");
        ArAssert(surface_->PixelFormat.RGBAlphaBitMask == 0xF000, "Invalid SHADMAP Format");

        u16* surface = static_cast<u16*>(surface_->Surface);
        i32 surface_bytes = 0;

        for (u32 i = 0; i < surface_->MipMapCount; ++i)
        {
            i32 width = surface_->Width >> i;
            i32 height = surface_->Height >> i;

            surface_bytes += width * height;
        }

        while (surface_bytes)
        {
            --surface_bytes;
            *surface = ~((*surface >> 12) | (*surface >> 8) | (*surface >> 4));
            ++surface;
        }
    }

    surface_size_ =
        surface_->Width * surface_->Height * (surface_->PixelFormat.RGBBitCount + 7) / 8; // Only used for stats

    if (Pipe()->GetFilterCaps() != 0 && !(tex_.Flags & agiTexParameters::NoMipMaps))
        surface_size_ = (surface_size_ * 4) / 3; // Size of all mipmaps = sum 1/4^n, n=0 to infinity = 4/3

    if (tex_.SheetFlags & 0x2 && GetRendererInfo().AdditiveBlending)
        tex_.Flags &= ~agiTexParameters::Alpha;

    DDSURFACEDESC2 sd = ConvertSurfaceDesc(*surface_);
    sd.ddpfPixelFormat = (tex_.Flags & agiTexParameters::Alpha) ? Pipe()->GetAlphaFormat() : Pipe()->GetOpaqueFormat();
    sd.dwReserved = 0; // lpLut/szLut

    // TODO: Shouldn't this use the same checks as surface_size_ ?
    if (Pipe()->GetFilterCaps() == 0)
    {
        sd.dwMipMapCount = 0;
        sd.dwFlags &= ~DDSD_MIPMAPCOUNT;
        sd.ddsCaps.dwCaps &= ~(DDSCAPS_COMPLEX | DDSCAPS_MIPMAP);
    }

    sd.ddsCaps.dwCaps &=
        ~(DDSCAPS_BACKBUFFER | DDSCAPS_3DDEVICE | DDSCAPS_VIDEOMEMORY | DDSCAPS_LOCALVIDMEM | DDSCAPS_NONLOCALVIDMEM);
    sd.ddsCaps.dwCaps |= DDSCAPS_TEXTURE;

    if (DontCacheTextures)
        sd.ddsCaps.dwCaps |= DDSCAPS_VIDEOMEMORY;
    else
        sd.ddsCaps.dwCaps2 |= DDSCAPS2_TEXTUREMANAGE;

    sd.dwFlags &= ~(DDSD_BACKBUFFERCOUNT | DDSD_PITCH);

    if ((GetRendererInfo().SpecialFlags & 4) && (sd.dwFlags & DDSD_CKSRCBLT))
    {
        sd.dwFlags &= ~DDSD_CKSRCBLT;

        // TODO: Select correct alpha-based format (and set the dwBBitMask)
        sd.ddpfPixelFormat.dwRGBAlphaBitMask = 0x8000;
        sd.ddpfPixelFormat.dwRBitMask = 0x7C00;
        sd.ddpfPixelFormat.dwGBitMask = 0x3E0;

        tex_.Flags &= ~agiTexParameters::ColorKey;
        tex_.Flags |= agiTexParameters::Alpha;
    }

    if (HRESULT error = Pipe()->GetDirectDraw()->CreateSurface(&sd, &mem_tex_surf_, nullptr))
        Quitf("Can't create surface for '%s', code = 0x%08X", tex_.Name, error);

    IDirectDrawSurface4* pdds = mem_tex_surf_;
    pdds->AddRef();

    i32 mip_level = 0;

    while (true)
    {
        DDSURFACEDESC2 ddsd {sizeof(ddsd)};

        DD_TRY(pdds->Lock(nullptr, &ddsd, DDLOCK_WAIT, nullptr));

        if (ddsd.ddpfPixelFormat.dwFlags & DDPF_RGB)
        {
            agiSurfaceDesc agisd = ConvertSurfaceDesc(ddsd);
            agisd.CopyFrom(surface_, mip_level, &tex_);
            ddsd = ConvertSurfaceDesc(agisd);
            ++mip_level;
        }

        pdds->Unlock(nullptr);

        if (Pipe()->GetFilterCaps() == 0)
            break;

        ddsd.ddsCaps.dwCaps = DDSCAPS_COMPLEX | DDSCAPS_TEXTURE | DDSCAPS_MIPMAP;

        IDirectDrawSurface4* pdds_child = nullptr;

        if (pdds->GetAttachedSurface(&ddsd.ddsCaps, &pdds_child))
            break;

        pdds->Release();
        pdds = pdds_child;
    }

    pdds->Release();

    DD_TRY(mem_tex_surf_->QueryInterface(IID_IDirect3DTexture2, (void**) &mem_tex_));

    if (cache_handle_ == 0)
        surface_->Unload();

    page_state_ = 0;

    DDSCAPS2 caps {};
    caps.dwCaps = DDSCAPS_VIDEOMEMORY;

    DWORD dwTotal = 0;
    DWORD dwFree = 0;

    DD_TRY(Pipe()->GetDirectDraw()->GetAvailableVidMem(&caps, &dwTotal, &dwFree));

    agiDisplayf("Texture %s: %d bytes texture memory total, %d available", tex_.Name, dwTotal, dwFree);

    state_ = 1;

    return AGI_ERROR_SUCCESS;
}

void agiD3DTexDef::EndGfx()
{
    SafeRelease(mem_tex_);
    DD_RELEASE(mem_tex_surf_);
    DD_RELEASE(pal_);

    state_ = 0;
}

IDirect3DTexture2* agiD3DTexDef::GetHandle(i32)
{
    if (state_ == 0)
    {
        if (!LockSurfaceIfResident())
        {
            PageInSurface();

            return nullptr;
        }

        if ((surface_->PixelFormat.Flags & AGIPF_PALETTEINDEXED8) && surface_->lpLut == nullptr)
        {
            UnlockSurface();
        }
        else if (BeginGfx() == AGI_ERROR_SUCCESS)
        {
            UnlockAndFreeSurface();
        }
        else
        {
            Warningf("agiD3DTexDef::GetHandle - Texture '%s' didn't init properly", tex_.Name);
        }
    }

    return mem_tex_;
}

b32 agiD3DTexDef::IsAvailable()
{
    return true;
}

b32 agiD3DTexDef::Lock(agiTexLock& lock)
{
    if (mem_tex_surf_ == nullptr)
        return false;

    DDSURFACEDESC2 sd {sizeof(sd)};

    DD_TRY(mem_tex_surf_->Lock(nullptr, &sd, DDLOCK_NOSYSLOCK, nullptr));

    lock.ColorModel =
        (tex_.Flags & agiTexParameters::Alpha) ? Pipe()->GetAlphaColorModel() : Pipe()->GetOpaqueColorModel();

    lock.Width = sd.dwWidth;
    lock.Height = sd.dwHeight;
    lock.Pitch = sd.lPitch;
    lock.Surface = sd.lpSurface;

    return true;
}

void agiD3DTexDef::Request()
{
    GetHandle(0);
}

void agiD3DTexDef::Restore()
{
    if (mem_tex_surf_)
        mem_tex_surf_->Restore();

    if (DontCacheTextures)
    {
        EndGfx();

        if (!(EnablePaging & ARTS_PAGE_TEXTURES) || (tex_.Flags & agiTexParameters::Modified))
            BeginGfx();
    }
}

void agiD3DTexDef::Set(Vector2& arg1, Vector2& arg2)
{
    arg1 = arg2;
}

void agiD3DTexDef::Unlock(agiTexLock&)
{
    DD_TRY(mem_tex_surf_->Unlock(nullptr));
}

void agiD3DTexDef::Prober(void*)
{}
