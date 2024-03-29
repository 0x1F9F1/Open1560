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
    mmui:pu_debug

    0x4AA3F0 | public: __thiscall PUDebug::PUDebug(int,float,float,float,float) | ??0PUDebug@@QAE@HMMMM@Z
    0x4AA590 | public: virtual __thiscall PUDebug::~PUDebug(void) | ??1PUDebug@@UAE@XZ
    0x4AA5A0 | public: void __thiscall PUDebug::RecordCB(void) | ?RecordCB@PUDebug@@QAEXXZ
    0x4AA5B0 | public: virtual void * __thiscall PUDebug::`scalar deleting destructor'(unsigned int) | ??_GPUDebug@@UAEPAXI@Z
    0x4AA5B0 | public: virtual void * __thiscall PUDebug::`vector deleting destructor'(unsigned int) | ??_EPUDebug@@UAEPAXI@Z
    0x61E000 | const PUDebug::`vftable' | ??_7PUDebug@@6B@
*/

#include "pu_menu.h"

class PUDebug final : public PUMenuBase
{
public:
    // ??0PUDebug@@QAE@HMMMM@Z
    ARTS_IMPORT PUDebug(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ??_EPUDebug@@UAEPAXI@Z
    // ??_GPUDebug@@UAEPAXI@Z
    // ??1PUDebug@@UAE@XZ
    ARTS_IMPORT ~PUDebug() override = default;

    // ?RecordCB@PUDebug@@QAEXXZ
    ARTS_IMPORT void RecordCB();

    u8 gapC0[0x68];
};

check_size(PUDebug, 0x128);
