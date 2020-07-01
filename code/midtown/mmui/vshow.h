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
    mmui:vshow

    0x4A4F70 | public: __thiscall VehShowcase::VehShowcase(int) | ??0VehShowcase@@QAE@H@Z
    0x4A50C0 | public: virtual __thiscall VehShowcase::~VehShowcase(void) | ??1VehShowcase@@UAE@XZ
    0x4A5120 | public: virtual void __thiscall VehShowcase::PreSetup(void) | ?PreSetup@VehShowcase@@UAEXXZ
    0x4A5190 | public: virtual void __thiscall VehShowcase::PostSetup(void) | ?PostSetup@VehShowcase@@UAEXXZ
    0x4A51A0 | public: virtual void * __thiscall VehShowcase::`vector deleting destructor'(unsigned int) | ??_EVehShowcase@@UAEPAXI@Z
    0x4A51A0 | public: virtual void * __thiscall VehShowcase::`scalar deleting destructor'(unsigned int) | ??_GVehShowcase@@UAEPAXI@Z
    0x61DB20 | const VehShowcase::`vftable' | ??_7VehShowcase@@6B@
*/

#include "mmwidget/menu.h"

class VehShowcase /*final*/ : public UIMenu
{
    // const VehShowcase::`vftable' @ 0x61DB20

public:
    // 0x4A4F70 | ??0VehShowcase@@QAE@H@Z
    ARTS_IMPORT VehShowcase(i32 arg1);

    // 0x4A51A0 | ??_GVehShowcase@@UAEPAXI@Z
    // 0x4A51A0 | ??_EVehShowcase@@UAEPAXI@Z
    // 0x4A50C0 | ??1VehShowcase@@UAE@XZ
    ARTS_IMPORT ~VehShowcase() override;

    // 0x4A5190 | ?PostSetup@VehShowcase@@UAEXXZ
    ARTS_EXPORT void PostSetup() override;

    // 0x4A5120 | ?PreSetup@VehShowcase@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gap90[0x8];
};

check_size(VehShowcase, 0x98);
