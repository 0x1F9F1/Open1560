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

class Dialog_TCPIP final : public PUMenuBase
{
public:
    // ??0Dialog_TCPIP@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_TCPIP(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // ??1Dialog_TCPIP@@UAE@XZ
    ARTS_EXPORT ~Dialog_TCPIP() override = default;

    // ?IPAddressCallback@Dialog_TCPIP@@QAEXXZ
    ARTS_IMPORT void IPAddressCallback();

    // ?PreSetup@Dialog_TCPIP@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gapC0[0x2C];
};

check_size(Dialog_TCPIP, 0xEC);
