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
    mmui:pu_options

    0x4AA5E0 | public: __thiscall PUOptions::PUOptions(int,float,float,float,float) | ??0PUOptions@@QAE@HMMMM@Z
    0x4AA750 | public: virtual __thiscall PUOptions::~PUOptions(void) | ??1PUOptions@@UAE@XZ
    0x4AA760 | public: virtual void * __thiscall PUOptions::`vector deleting destructor'(unsigned int) | ??_EPUOptions@@UAEPAXI@Z
    0x4AA760 | public: virtual void * __thiscall PUOptions::`scalar deleting destructor'(unsigned int) | ??_GPUOptions@@UAEPAXI@Z
    0x61E050 | const PUOptions::`vftable' | ??_7PUOptions@@6B@
*/

#include "pu_menu.h"

class PUOptions /*final*/ : public PUMenuBase
{
    // const PUOptions::`vftable' @ 0x61E050

public:
    // 0x4AA5E0 | ??0PUOptions@@QAE@HMMMM@Z
    ARTS_IMPORT PUOptions(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x4AA760 | ??_GPUOptions@@UAEPAXI@Z
    // 0x4AA760 | ??_EPUOptions@@UAEPAXI@Z
    // 0x4AA750 | ??1PUOptions@@UAE@XZ
    ARTS_IMPORT ~PUOptions() override = default;
};

check_size(PUOptions, 0xC0);
