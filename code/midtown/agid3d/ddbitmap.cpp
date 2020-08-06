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

define_dummy_symbol(agid3d_ddbitmap);

#include "ddbitmap.h"
#include "agi/error.h"
#include "dderror.h"

void breakme()
{}

agiDDBitmap::~agiDDBitmap()
{
    EndGfx();
}

i32 agiDDBitmap::BeginGfx()
{
    if (!Pipe()->HaveGfxStarted())
        return AGI_ERROR_SUCCESS;

    if (state_ != 0)
        return AGI_ERROR_ALREADY_INITIALIZED;

    if (surface_ == nullptr)
        return AGI_ERROR_OBJECT_EMPTY;

    if (width_scale_ == 0.0f || height_scale_ == 0.0f)
    {
        if (*name_.get() != '*')
            surface_->Reload(const_cast<char*>(name_.get()), BitmapSearchPath, 0, 0, 0, 0, 0);

        width_ = surface_->Width;
        height_ = surface_->Height;
    }
    else
    {
        width_ = static_cast<i32>(Pipe()->GetWidth() * width_scale_ - -0.5f);
        height_ = static_cast<i32>(Pipe()->GetHeight() * height_scale_ - -0.5f);

        if (*name_.get() != '*')
            surface_->Reload(const_cast<char*>(name_.get()), BitmapSearchPath, 0, 0, 0, width_, height_);
    }

    DDSURFACEDESC2 ddsdDest {sizeof(ddsdDest)};

    ddsdDest.dwWidth = width_;
    ddsdDest.dwFlags = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
    ddsdDest.dwHeight = height_;
    ddsdDest.ddsCaps.dwCaps = (flags_ & AGI_BITMAP_OFFSCREEN) != 0 ? DDSCAPS_OFFSCREENPLAIN : DDSCAPS_SYSTEMMEMORY;

    if (Pipe()->GetDirectDraw()->CreateSurface(&ddsdDest, &d_surf_, nullptr))
    {
        Quitf("CreateSurface: '%s': %d x %d %dbpp failed.", name_.get(), ddsdDest.dwWidth, ddsdDest.dwHeight,
            ddsdDest.ddpfPixelFormat.dwRGBBitCount);
    }

    DD_TRY(d_surf_->Lock(nullptr, &ddsdDest, DDLOCK_WAIT, nullptr));

    agiSurfaceDesc surface = ConvertSurfaceDesc(ddsdDest);
    surface.CopyFrom(surface_, 0);

    DD_TRY(d_surf_->Unlock(nullptr));

    state_ = 1;

    DDSCAPS2 caps {};
    caps.dwCaps = DDSCAPS_TEXTURE;
    DWORD dwTotal = 0;
    DWORD dwFree = 0;
    DD_TRY(Pipe()->GetDirectDraw()->GetAvailableVidMem(&caps, &dwTotal, &dwFree));

    agiDisplayf("Bitmap %s: %d bytes texture memory total, %d available", name_.get(), dwTotal, dwFree);

    if (*name_.get() != '*')
        surface_->Unload();

    UpdateFlags();

    return AGI_ERROR_SUCCESS;
}

void agiDDBitmap::EndGfx()
{
    if (state_ != 0)
    {
        DD_RELEASE(d_surf_);

        state_ = 0;
    }
}

void agiDDBitmap::Restore()
{
    EndGfx();

    BeginGfx();
}

static DDCOLORKEY ddk {};

void agiDDBitmap::UpdateFlags()
{
    DD_TRY(d_surf_->SetColorKey(DDCKEY_SRCBLT, IsTransparent() ? &ddk : nullptr));
}
