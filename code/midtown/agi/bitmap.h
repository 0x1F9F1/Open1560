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

#pragma once

#include "refresh.h"

#include "surface.h"

#define BITMAP_TRANSPARENT 0x1    // Chromakey
#define BITMAP_OFFSCREEN 0x2      // Blit-able
#define BITMAP_UNLOAD_ALWAYS 0x10 // TODO: Can this be 0x4 ?

class agiBitmap : public agiRefreshable
{
public:
    // ??0agiBitmap@@QAE@PAVagiPipeline@@@Z
    agiBitmap(agiPipeline* pipe);

    // ?UpdateFlags@agiBitmap@@UAEXXZ
    virtual void UpdateFlags();

    // ?GetName@agiBitmap@@UAEPADXZ
    aconst char* GetName() override;

    // ?Init@agiBitmap@@QAEHPADMMH@Z
    i32 Init(const char* name, f32 sx, f32 sy, i32 flags);

    // ?SetTransparency@agiBitmap@@QAEXH@Z
    ARTS_EXPORT void SetTransparency(b32 enabled);

    agiSurfaceDesc* GetSurface() const
    {
        return surface_.get();
    }

    bool Is3D() const
    {
        return is_3D_;
    }

    i32 GetWidth() const
    {
        return width_;
    }

    i32 GetHeight() const
    {
        return height_;
    }

    bool IsTransparent() const
    {
        return flags_ & BITMAP_TRANSPARENT;
    }

    bool NeedsReload() const
    {
        return !HaveGfxStarted() && (surface_->Surface == nullptr);
    }

protected:
    // ??1agiBitmap@@MAE@XZ
    ~agiBitmap() override;

    ConstString name_;

    Ptr<agiSurfaceDesc> surface_;

    // BITMAP_*
    u32 flags_ {};
    i32 width_ {};
    i32 height_ {};
    f32 width_scale_ {};
    f32 height_scale_ {};

    b32 is_3D_ {};
    [[deprecated]] u32 field_38 {1}; // Always 1 ?
};

check_size(agiBitmap, 0x3C);

// ?BitmapHash@@3VHashTable@@A
extern HashTable BitmapHash;

// ?BitmapSearchPath@@3PADA
extern aconst char* BitmapSearchPath;
