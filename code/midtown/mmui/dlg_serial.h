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

struct NETCOMMPACK;

class Dialog_Serial final : public PUMenuBase
{
public:
    // ??0Dialog_Serial@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_Serial(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // ??1Dialog_Serial@@UAE@XZ
    ARTS_IMPORT ~Dialog_Serial() override;

    // ?BuildComs@Dialog_Serial@@QAEXXZ
    ARTS_IMPORT void BuildComs();

    // ?GetCommPack@Dialog_Serial@@QAEPAUNETCOMMPACK@@XZ
    ARTS_IMPORT NETCOMMPACK* GetCommPack();

    // ?PreSetup@Dialog_Serial@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gapC0[0x88];
};

check_size(Dialog_Serial, 0x148);
