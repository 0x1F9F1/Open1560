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
    mmui:pu_exit

    0x4AAAA0 | public: __thiscall PUExit::PUExit(int,float,float,float,float,char *) | ??0PUExit@@QAE@HMMMMPAD@Z
    0x4AABE0 | public: virtual __thiscall PUExit::~PUExit(void) | ??1PUExit@@UAE@XZ
    0x4AABF0 | public: virtual void * __thiscall PUExit::`vector deleting destructor'(unsigned int) | ??_EPUExit@@UAEPAXI@Z
    0x4AABF0 | public: virtual void * __thiscall PUExit::`scalar deleting destructor'(unsigned int) | ??_GPUExit@@UAEPAXI@Z
    0x61E0F8 | const PUExit::`vftable' | ??_7PUExit@@6B@
*/

#include "pu_menu.h"

class PUExit final : public PUMenuBase
{
    // const PUExit::`vftable'

public:
    // ??0PUExit@@QAE@HMMMMPAD@Z
    ARTS_IMPORT PUExit(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // ??_GPUExit@@UAEPAXI@Z
    // ??_EPUExit@@UAEPAXI@Z
    // ??1PUExit@@UAE@XZ
    ARTS_IMPORT ~PUExit() override = default;
};

check_size(PUExit, 0xC0);
