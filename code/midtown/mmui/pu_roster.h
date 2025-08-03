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

class PURoster final : public PUMenuBase
{
public:
    // ??0PURoster@@QAE@HMMMM@Z
    ARTS_IMPORT PURoster(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ??1PURoster@@UAE@XZ
    ARTS_EXPORT ~PURoster() override = default;

    // ?AddName@PURoster@@QAEXPADKH@Z
    ARTS_IMPORT void AddName(char* arg1, ulong arg2, i32 arg3);

    // ?BootButtonCB@PURoster@@QAEXXZ
    ARTS_IMPORT void BootButtonCB();

    // ?ClearNames@PURoster@@QAEXXZ
    ARTS_IMPORT void ClearNames();

    // ?FindRosterName@PURoster@@QAEHK@Z
    ARTS_IMPORT i32 FindRosterName(ulong arg1);

    // ?PostNames@PURoster@@QAEXXZ
    ARTS_IMPORT void PostNames();

    // ?RemoveName@PURoster@@QAEXK@Z
    ARTS_IMPORT void RemoveName(ulong arg1);

    // ?RemoveName@PURoster@@QAEXPADK@Z
    ARTS_IMPORT void RemoveName(char* arg1, ulong arg2);

    // ?Reset@PURoster@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetBootCB@PURoster@@QAEXVCallback@@@Z
    ARTS_IMPORT void SetBootCB(Callback arg1);

    u8 gapC0[0x180];
};

check_size(PURoster, 0x240);
