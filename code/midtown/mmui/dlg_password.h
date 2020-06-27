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
    mmui:dlg_password

    0x49DAB0 | public: __thiscall Dialog_Password::Dialog_Password(int,float,float,float,float,char *) | ??0Dialog_Password@@QAE@HMMMMPAD@Z
    0x49DC20 | public: virtual __thiscall Dialog_Password::~Dialog_Password(void) | ??1Dialog_Password@@UAE@XZ
    0x49DC30 | public: virtual void __thiscall Dialog_Password::PreSetup(void) | ?PreSetup@Dialog_Password@@UAEXXZ
    0x49DC40 | public: void __thiscall Dialog_Password::PasswordCallback(void) | ?PasswordCallback@Dialog_Password@@QAEXXZ
    0x49DC50 | public: virtual void * __thiscall Dialog_Password::`vector deleting destructor'(unsigned int) | ??_EDialog_Password@@UAEPAXI@Z
    0x49DC50 | public: virtual void * __thiscall Dialog_Password::`scalar deleting destructor'(unsigned int) | ??_GDialog_Password@@UAEPAXI@Z
    0x61D538 | const Dialog_Password::`vftable' | ??_7Dialog_Password@@6B@
*/

#include "pu_menu.h"

class Dialog_Password : public PUMenuBase
{
    // const Dialog_Password::`vftable' @ 0x61D538

public:
    // 0x49DAB0 | ??0Dialog_Password@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_Password(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x49DC50 | ??_GDialog_Password@@UAEPAXI@Z
    // 0x49DC50 | ??_EDialog_Password@@UAEPAXI@Z
    // 0x49DC20 | ??1Dialog_Password@@UAE@XZ
    ARTS_IMPORT ~Dialog_Password() override;

    // 0x49DC40 | ?PasswordCallback@Dialog_Password@@QAEXXZ
    ARTS_IMPORT void PasswordCallback();

    // 0x49DC30 | ?PreSetup@Dialog_Password@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gapC0[0x2C];
};

check_size(Dialog_Password, 0xEC);
