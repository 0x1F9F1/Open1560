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
    mmui:dlg_drec

    0x49EC10 | public: __thiscall Dialog_DriverRec::Dialog_DriverRec(int,float,float,float,float,char *) | ??0Dialog_DriverRec@@QAE@HMMMMPAD@Z
    0x49EF70 | public: virtual __thiscall Dialog_DriverRec::~Dialog_DriverRec(void) | ??1Dialog_DriverRec@@UAE@XZ
    0x49EF80 | public: virtual void __thiscall Dialog_DriverRec::PreSetup(void) | ?PreSetup@Dialog_DriverRec@@UAEXXZ
    0x49EF90 | public: void __thiscall Dialog_DriverRec::InitDriverRecord(int) | ?InitDriverRecord@Dialog_DriverRec@@QAEXH@Z
    0x49F060 | public: int __thiscall Dialog_DriverRec::AddDriverRecord(int,char *,int,float,char *,int) | ?AddDriverRecord@Dialog_DriverRec@@QAEHHPADHM0H@Z
    0x49F1A0 | public: void __thiscall Dialog_DriverRec::ResetDriverRecord(void) | ?ResetDriverRecord@Dialog_DriverRec@@QAEXXZ
    0x49F230 | public: void __thiscall Dialog_DriverRec::SetRecordPosition(int) | ?SetRecordPosition@Dialog_DriverRec@@QAEXH@Z
    0x49F250 | public: void __thiscall Dialog_DriverRec::SetSortState(void) | ?SetSortState@Dialog_DriverRec@@QAEXXZ
    0x49F2B0 | public: virtual void * __thiscall Dialog_DriverRec::`vector deleting destructor'(unsigned int) | ??_EDialog_DriverRec@@UAEPAXI@Z
    0x49F2B0 | public: virtual void * __thiscall Dialog_DriverRec::`scalar deleting destructor'(unsigned int) | ??_GDialog_DriverRec@@UAEPAXI@Z
    0x61D668 | const Dialog_DriverRec::`vftable' | ??_7Dialog_DriverRec@@6B@
*/

#include "pu_menu.h"

class Dialog_DriverRec final : public PUMenuBase
{
    // const Dialog_DriverRec::`vftable' @ 0x61D668

public:
    // 0x49EC10 | ??0Dialog_DriverRec@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_DriverRec(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x49F2B0 | ??_GDialog_DriverRec@@UAEPAXI@Z
    // 0x49F2B0 | ??_EDialog_DriverRec@@UAEPAXI@Z
    // 0x49EF70 | ??1Dialog_DriverRec@@UAE@XZ
    ARTS_IMPORT ~Dialog_DriverRec() override = default;

    // 0x49F060 | ?AddDriverRecord@Dialog_DriverRec@@QAEHHPADHM0H@Z
    ARTS_IMPORT i32 AddDriverRecord(i32 arg1, char* arg2, i32 arg3, f32 arg4, char* arg5, i32 arg6);

    // 0x49EF90 | ?InitDriverRecord@Dialog_DriverRec@@QAEXH@Z
    ARTS_IMPORT void InitDriverRecord(i32 arg1);

    // 0x49EF80 | ?PreSetup@Dialog_DriverRec@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // 0x49F1A0 | ?ResetDriverRecord@Dialog_DriverRec@@QAEXXZ
    ARTS_IMPORT void ResetDriverRecord();

    // 0x49F230 | ?SetRecordPosition@Dialog_DriverRec@@QAEXH@Z
    ARTS_IMPORT void SetRecordPosition(i32 arg1);

    // 0x49F250 | ?SetSortState@Dialog_DriverRec@@QAEXXZ
    ARTS_IMPORT void SetSortState();

    u8 gapC0[0x24];
};

check_size(Dialog_DriverRec, 0xE4);
