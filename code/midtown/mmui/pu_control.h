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
    mmui:pu_control

    0x4A9F50 | public: __thiscall PUControl::PUControl(int,float,float,float,float) | ??0PUControl@@QAE@HMMMM@Z
    0x4AA250 | public: virtual __thiscall PUControl::~PUControl(void) | ??1PUControl@@UAE@XZ
    0x4AA2B0 | public: virtual void __thiscall PUControl::PreSetup(void) | ?PreSetup@PUControl@@UAEXXZ
    0x4AA2D0 | public: void __thiscall PUControl::CancelAction(void) | ?CancelAction@PUControl@@QAEXXZ
    0x4AA2F0 | public: void __thiscall PUControl::SetRWStates(void) | ?SetRWStates@PUControl@@QAEXXZ
    0x4AA380 | public: void __thiscall PUControl::ControlSelect(void) | ?ControlSelect@PUControl@@QAEXXZ
    0x4AA3B0 | public: void __thiscall PUControl::SetSensitivityCB(void) | ?SetSensitivityCB@PUControl@@QAEXXZ
    0x4AA3C0 | public: virtual void * __thiscall PUControl::`scalar deleting destructor'(unsigned int) | ??_GPUControl@@UAEPAXI@Z
    0x4AA3C0 | public: virtual void * __thiscall PUControl::`vector deleting destructor'(unsigned int) | ??_EPUControl@@UAEPAXI@Z
    0x61DFA8 | const PUControl::`vftable' | ??_7PUControl@@6B@
*/

#include "pu_menu.h"

class PUControl /*final*/ : public PUMenuBase
{
    // const PUControl::`vftable' @ 0x61DFA8

public:
    // 0x4A9F50 | ??0PUControl@@QAE@HMMMM@Z
    ARTS_IMPORT PUControl(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x4AA3C0 | ??_EPUControl@@UAEPAXI@Z
    // 0x4AA3C0 | ??_GPUControl@@UAEPAXI@Z
    // 0x4AA250 | ??1PUControl@@UAE@XZ
    ARTS_IMPORT ~PUControl() override;

    // 0x4AA2D0 | ?CancelAction@PUControl@@QAEXXZ
    ARTS_IMPORT void CancelAction();

    // 0x4AA380 | ?ControlSelect@PUControl@@QAEXXZ
    ARTS_IMPORT void ControlSelect();

    // 0x4AA2B0 | ?PreSetup@PUControl@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // 0x4AA2F0 | ?SetRWStates@PUControl@@QAEXXZ
    ARTS_IMPORT void SetRWStates();

    // 0x4AA3B0 | ?SetSensitivityCB@PUControl@@QAEXXZ
    ARTS_IMPORT void SetSensitivityCB();

    u8 gapC0[0x18];
};

check_size(PUControl, 0xD8);
