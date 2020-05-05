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
    mmui:pu_main

    0x4AADA0 | public: __thiscall PUMain::PUMain(int,float,float,float,float,char *) | ??0PUMain@@QAE@HMMMMPAD@Z
    0x4AAFA0 | public: virtual __thiscall PUMain::~PUMain(void) | ??1PUMain@@UAE@XZ
    0x4AAFB0 | public: virtual void * __thiscall PUMain::`vector deleting destructor'(unsigned int) | ??_EPUMain@@UAEPAXI@Z
    0x4AAFB0 | public: virtual void * __thiscall PUMain::`scalar deleting destructor'(unsigned int) | ??_GPUMain@@UAEPAXI@Z
    0x61E198 | const PUMain::`vftable' | ??_7PUMain@@6B@
*/

#include "pu_menu.h"

class PUMain : public PUMenuBase
{
    // const PUMain::`vftable' @ 0x61E198

public:
    // 0x4AADA0 | ??0PUMain@@QAE@HMMMMPAD@Z
    PUMain(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x4AAFB0 | ??_GPUMain@@UAEPAXI@Z
    // 0x4AAFA0 | ??1PUMain@@UAE@XZ
    ~PUMain() override;
};

check_size(PUMain, 0xC0);
