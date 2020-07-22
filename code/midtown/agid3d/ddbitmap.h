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
    agid3d:ddbitmap

    0x5339F0 | public: __thiscall agiDDBitmap::agiDDBitmap(class agiPipeline *) | ??0agiDDBitmap@@QAE@PAVagiPipeline@@@Z
    0x533A20 | public: virtual int __thiscall agiDDBitmap::BeginGfx(void) | ?BeginGfx@agiDDBitmap@@UAEHXZ
    0x533C80 | public: virtual void __thiscall agiDDBitmap::UpdateFlags(void) | ?UpdateFlags@agiDDBitmap@@UAEXXZ
    0x533CC0 | public: virtual void __thiscall agiDDBitmap::EndGfx(void) | ?EndGfx@agiDDBitmap@@UAEXXZ
    0x533CF0 | public: virtual __thiscall agiDDBitmap::~agiDDBitmap(void) | ??1agiDDBitmap@@UAE@XZ
    0x533D40 | void __cdecl breakme(void) | ?breakme@@YAXXZ
    0x533D50 | public: virtual void __thiscall agiDDBitmap::Restore(void) | ?Restore@agiDDBitmap@@UAEXXZ
    0x533D90 | public: virtual void * __thiscall agiDDBitmap::`scalar deleting destructor'(unsigned int) | ??_GagiDDBitmap@@UAEPAXI@Z
    0x533D90 | public: virtual void * __thiscall agiDDBitmap::`vector deleting destructor'(unsigned int) | ??_EagiDDBitmap@@UAEPAXI@Z
    0x6211B0 | const agiDDBitmap::`vftable' | ??_7agiDDBitmap@@6B@
*/

#include "agi/bitmap.h"

class agiDDBitmap final : public agiBitmap
{
    // const agiDDBitmap::`vftable' @ 0x6211B0

public:
    // 0x5339F0 | ??0agiDDBitmap@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiDDBitmap(class agiPipeline* arg1);

    // 0x533D90 | ??_EagiDDBitmap@@UAEPAXI@Z
    // 0x533D90 | ??_GagiDDBitmap@@UAEPAXI@Z
    // 0x533CF0 | ??1agiDDBitmap@@UAE@XZ
    ARTS_IMPORT ~agiDDBitmap() override;

    // 0x533A20 | ?BeginGfx@agiDDBitmap@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // 0x533CC0 | ?EndGfx@agiDDBitmap@@UAEXXZ
    ARTS_IMPORT void EndGfx() override;

    // 0x533D50 | ?Restore@agiDDBitmap@@UAEXXZ
    ARTS_IMPORT void Restore() override;

    // 0x533C80 | ?UpdateFlags@agiDDBitmap@@UAEXXZ
    ARTS_IMPORT void UpdateFlags() override;

    u8 gap3C[0x4];
};

check_size(agiDDBitmap, 0x40);

// 0x533D40 | ?breakme@@YAXXZ
ARTS_EXPORT void breakme();
