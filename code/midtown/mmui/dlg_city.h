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
    mmui:dlg_city

    0x49D730 | public: __thiscall Dialog_City::Dialog_City(int,float,float,float,float,char *) | ??0Dialog_City@@QAE@HMMMMPAD@Z
    0x49D9B0 | public: virtual __thiscall Dialog_City::~Dialog_City(void) | ??1Dialog_City@@UAE@XZ
    0x49DA10 | public: virtual void __thiscall Dialog_City::PreSetup(void) | ?PreSetup@Dialog_City@@UAEXXZ
    0x49DA20 | public: void __thiscall Dialog_City::DoneCB(void) | ?DoneCB@Dialog_City@@QAEXXZ
    0x49DA80 | public: virtual void * __thiscall Dialog_City::`vector deleting destructor'(unsigned int) | ??_EDialog_City@@UAEPAXI@Z
    0x49DA80 | public: virtual void * __thiscall Dialog_City::`scalar deleting destructor'(unsigned int) | ??_GDialog_City@@UAEPAXI@Z
    0x61D4E8 | const Dialog_City::`vftable' | ??_7Dialog_City@@6B@
*/

#include "pu_menu.h"

class Dialog_City : public PUMenuBase
{
    // const Dialog_City::`vftable' @ 0x61D4E8

public:
    // 0x49D730 | ??0Dialog_City@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_City(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x49DA80 | ??_GDialog_City@@UAEPAXI@Z
    // 0x49D9B0 | ??1Dialog_City@@UAE@XZ
    ARTS_IMPORT ~Dialog_City() override;

    // 0x49DA20 | ?DoneCB@Dialog_City@@QAEXXZ
    ARTS_IMPORT void DoneCB();

    // 0x49DA10 | ?PreSetup@Dialog_City@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gapC0[0xC];
};

check_size(Dialog_City, 0xCC);
