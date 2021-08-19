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

/*
    agi:bitmap

    0x55A3B0 | public: __thiscall agiBitmap::agiBitmap(class agiPipeline *) | ??0agiBitmap@@QAE@PAVagiPipeline@@@Z
    0x55A3F0 | public: int __thiscall agiBitmap::Init(char *,float,float,int) | ?Init@agiBitmap@@QAEHPADMMH@Z
    0x55A600 | public: void __thiscall agiBitmap::SetTransparency(int) | ?SetTransparency@agiBitmap@@QAEXH@Z
    0x55A630 | public: virtual void __thiscall agiBitmap::UpdateFlags(void) | ?UpdateFlags@agiBitmap@@UAEXXZ
    0x55A640 | protected: virtual __thiscall agiBitmap::~agiBitmap(void) | ??1agiBitmap@@MAE@XZ
    0x55A6D0 | public: virtual char * __thiscall agiBitmap::GetName(void) | ?GetName@agiBitmap@@UAEPADXZ
    0x55A6F0 | protected: virtual void * __thiscall agiBitmap::`vector deleting destructor'(unsigned int) | ??_EagiBitmap@@MAEPAXI@Z
    0x55A6F0 | protected: virtual void * __thiscall agiBitmap::`scalar deleting destructor'(unsigned int) | ??_GagiBitmap@@MAEPAXI@Z
    0x6216F0 | const agiBitmap::`vftable' | ??_7agiBitmap@@6B@
    0x6570F0 | char * BitmapSearchPath | ?BitmapSearchPath@@3PADA
    0x903140 | class HashTable BitmapHash | ?BitmapHash@@3VHashTable@@A
*/

#include "refresh.h"

#include "surface.h"

#define BITMAP_TRANSPARENT 0x1    // Chromakey
#define BITMAP_OFFSCREEN 0x2      // Blit-able
#define BITMAP_UNLOAD_ALWAYS 0x10 // TODO: Can this be 0x4 ?

class agiBitmap : public agiRefreshable
{
public:
    // ??0agiBitmap@@QAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiBitmap(class agiPipeline* pipe);

    // ?UpdateFlags@agiBitmap@@UAEXXZ
    ARTS_EXPORT virtual void UpdateFlags();

    // ?GetName@agiBitmap@@UAEPADXZ
    ARTS_EXPORT /*const*/ char* GetName() override;

    // ?Init@agiBitmap@@QAEHPADMMH@Z
    ARTS_EXPORT i32 Init(const char* name, f32 sx, f32 sy, i32 flags);

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
    // ??_GagiBitmap@@MAEPAXI@Z
    // ??_EagiBitmap@@MAEPAXI@Z
    // ??1agiBitmap@@MAE@XZ
    ARTS_EXPORT ~agiBitmap() override;

    ConstString name_;

    Ptr<agiSurfaceDesc> surface_;

    // BITMAP_*
    u32 flags_ {0};
    i32 width_ {0};
    i32 height_ {0};
    f32 width_scale_ {0.0f};
    f32 height_scale_ {0.0f};

    b32 is_3D_ {0};
    u32 field_38 {1}; // Always 1 ?
};

check_size(agiBitmap, 0x3C);

// ?BitmapHash@@3VHashTable@@A
ARTS_IMPORT extern class HashTable BitmapHash;

// ?BitmapSearchPath@@3PADA
ARTS_IMPORT extern char* BitmapSearchPath;
