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

class Dialog_DriverRec final : public PUMenuBase
{
public:
    // ??0Dialog_DriverRec@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_DriverRec(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // ??1Dialog_DriverRec@@UAE@XZ
    ARTS_EXPORT ~Dialog_DriverRec() override = default;

    // ?AddDriverRecord@Dialog_DriverRec@@QAEHHPADHM0H@Z
    ARTS_IMPORT i32 AddDriverRecord(i32 arg1, char* arg2, i32 arg3, f32 arg4, char* arg5, i32 arg6);

    // ?InitDriverRecord@Dialog_DriverRec@@QAEXH@Z
    ARTS_IMPORT void InitDriverRecord(i32 arg1);

    // ?PreSetup@Dialog_DriverRec@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?ResetDriverRecord@Dialog_DriverRec@@QAEXXZ
    ARTS_IMPORT void ResetDriverRecord();

    // ?SetRecordPosition@Dialog_DriverRec@@QAEXH@Z
    ARTS_IMPORT void SetRecordPosition(i32 arg1);

    // ?SetSortState@Dialog_DriverRec@@QAEXXZ
    ARTS_IMPORT void SetSortState();

    u8 gapC0[0x24];
};

check_size(Dialog_DriverRec, 0xE4);
