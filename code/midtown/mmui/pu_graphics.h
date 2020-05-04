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

#include "pu_menu.h"

/*
    mmui:pu_graphics

    0x4A9960 | public: __thiscall PUGraphics::PUGraphics(int,float,float,float,float) | ??0PUGraphics@@QAE@HMMMM@Z
    0x4A9EE0 | public: virtual __thiscall PUGraphics::~PUGraphics(void) | ??1PUGraphics@@UAE@XZ
    0x4A9EF0 | public: virtual void __thiscall PUGraphics::PreSetup(void) | ?PreSetup@PUGraphics@@UAEXXZ
    0x4A9F00 | public: void __thiscall PUGraphics::CancelAction(void) | ?CancelAction@PUGraphics@@QAEXXZ
    0x4A9F10 | public: virtual void * __thiscall PUGraphics::`vector deleting destructor'(unsigned int) | ??_EPUGraphics@@UAEPAXI@Z
    0x4A9F10 | public: virtual void * __thiscall PUGraphics::`scalar deleting destructor'(unsigned int) | ??_GPUGraphics@@UAEPAXI@Z
    0x4A9F40 | public: static class mmCullCity * __cdecl mmCullCity::GetInstance(void) | ?GetInstance@mmCullCity@@SAPAV1@XZ
    0x61DF48 | const PUGraphics::`vftable' | ??_7PUGraphics@@6B@
*/

class PUGraphics : public PUMenuBase
{
    // const PUGraphics::`vftable' @ 0x61DF48

public:
    // 0x4A9960 | ??0PUGraphics@@QAE@HMMMM@Z
    PUGraphics(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x4A9F10 | ??_GPUGraphics@@UAEPAXI@Z
    // 0x4A9EE0 | ??1PUGraphics@@UAE@XZ
    ~PUGraphics() override;

    // 0x4A9F00 | ?CancelAction@PUGraphics@@QAEXXZ
    void CancelAction();

    // 0x4A9EF0 | ?PreSetup@PUGraphics@@UAEXXZ
    void PreSetup() override;
};

check_size(PUGraphics, 0xC0);
