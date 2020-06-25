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
    mmui:pu_roster

    0x4A8CA0 | public: __thiscall PURoster::PURoster(int,float,float,float,float) | ??0PURoster@@QAE@HMMMM@Z
    0x4A8E10 | public: virtual __thiscall PURoster::~PURoster(void) | ??1PURoster@@UAE@XZ
    0x4A8E20 | public: virtual void __thiscall PURoster::Reset(void) | ?Reset@PURoster@@UAEXXZ
    0x4A8E30 | public: void __thiscall PURoster::BootButtonCB(void) | ?BootButtonCB@PURoster@@QAEXXZ
    0x4A8E90 | public: void __thiscall PURoster::SetHost(int) | ?SetHost@PURoster@@QAEXH@Z
    0x4A8F00 | public: void __thiscall PURoster::AddName(char *,unsigned long,int) | ?AddName@PURoster@@QAEXPADKH@Z
    0x4A8FD0 | public: void __thiscall PURoster::RemoveName(char *,unsigned long) | ?RemoveName@PURoster@@QAEXPADK@Z
    0x4A9110 | public: void __thiscall PURoster::RemoveName(unsigned long) | ?RemoveName@PURoster@@QAEXK@Z
    0x4A9240 | public: void __thiscall PURoster::ClearNames(void) | ?ClearNames@PURoster@@QAEXXZ
    0x4A92A0 | public: void __thiscall PURoster::PostNames(void) | ?PostNames@PURoster@@QAEXXZ
    0x4A92D0 | public: void __thiscall PURoster::SetBootCB(class Callback) | ?SetBootCB@PURoster@@QAEXVCallback@@@Z
    0x4A92F0 | public: int __thiscall PURoster::FindRosterName(char *) | ?FindRosterName@PURoster@@QAEHPAD@Z
    0x4A9360 | public: int __thiscall PURoster::FindRosterName(unsigned long) | ?FindRosterName@PURoster@@QAEHK@Z
    0x4A9390 | public: virtual void * __thiscall PURoster::`vector deleting destructor'(unsigned int) | ??_EPURoster@@UAEPAXI@Z
    0x4A9390 | public: virtual void * __thiscall PURoster::`scalar deleting destructor'(unsigned int) | ??_GPURoster@@UAEPAXI@Z
    0x61DE08 | const PURoster::`vftable' | ??_7PURoster@@6B@
*/

#include "pu_menu.h"

class PURoster : public PUMenuBase
{
    // const PURoster::`vftable' @ 0x61DE08

public:
    // 0x4A8CA0 | ??0PURoster@@QAE@HMMMM@Z
    ARTS_IMPORT PURoster(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x4A9390 | ??_GPURoster@@UAEPAXI@Z
    // 0x4A8E10 | ??1PURoster@@UAE@XZ
    ARTS_IMPORT ~PURoster() override;

    // 0x4A8F00 | ?AddName@PURoster@@QAEXPADKH@Z
    ARTS_IMPORT void AddName(char* arg1, u32 arg2, i32 arg3);

    // 0x4A8E30 | ?BootButtonCB@PURoster@@QAEXXZ
    ARTS_IMPORT void BootButtonCB();

    // 0x4A9240 | ?ClearNames@PURoster@@QAEXXZ
    ARTS_IMPORT void ClearNames();

    // 0x4A92F0 | ?FindRosterName@PURoster@@QAEHPAD@Z | unused
    ARTS_IMPORT i32 FindRosterName(char* arg1);

    // 0x4A9360 | ?FindRosterName@PURoster@@QAEHK@Z
    ARTS_IMPORT i32 FindRosterName(u32 arg1);

    // 0x4A92A0 | ?PostNames@PURoster@@QAEXXZ
    ARTS_IMPORT void PostNames();

    // 0x4A9110 | ?RemoveName@PURoster@@QAEXK@Z
    ARTS_IMPORT void RemoveName(u32 arg1);

    // 0x4A8FD0 | ?RemoveName@PURoster@@QAEXPADK@Z
    ARTS_IMPORT void RemoveName(char* arg1, u32 arg2);

    // 0x4A8E20 | ?Reset@PURoster@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4A92D0 | ?SetBootCB@PURoster@@QAEXVCallback@@@Z
    ARTS_IMPORT void SetBootCB(class Callback arg1);

    // 0x4A8E90 | ?SetHost@PURoster@@QAEXH@Z | unused
    ARTS_IMPORT void SetHost(i32 arg1);
};

check_size(PURoster, 0x240);
