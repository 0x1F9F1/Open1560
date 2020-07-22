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
    mmui:pu_quit

    0x4AAC20 | public: __thiscall PUQuit::PUQuit(int,float,float,float,float,char *) | ??0PUQuit@@QAE@HMMMMPAD@Z
    0x4AAD60 | public: virtual __thiscall PUQuit::~PUQuit(void) | ??1PUQuit@@UAE@XZ
    0x4AAD70 | public: virtual void * __thiscall PUQuit::`vector deleting destructor'(unsigned int) | ??_EPUQuit@@UAEPAXI@Z
    0x4AAD70 | public: virtual void * __thiscall PUQuit::`scalar deleting destructor'(unsigned int) | ??_GPUQuit@@UAEPAXI@Z
    0x61E148 | const PUQuit::`vftable' | ??_7PUQuit@@6B@
*/

#include "pu_menu.h"

class PUQuit final : public PUMenuBase
{
    // const PUQuit::`vftable' @ 0x61E148

public:
    // 0x4AAC20 | ??0PUQuit@@QAE@HMMMMPAD@Z
    ARTS_IMPORT PUQuit(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x4AAD70 | ??_GPUQuit@@UAEPAXI@Z
    // 0x4AAD70 | ??_EPUQuit@@UAEPAXI@Z
    // 0x4AAD60 | ??1PUQuit@@UAE@XZ
    ARTS_IMPORT ~PUQuit() override = default;
};

check_size(PUQuit, 0xC0);
