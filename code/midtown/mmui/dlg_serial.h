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
    mmui:dlg_serial

    0x49F850 | public: __thiscall Dialog_Serial::Dialog_Serial(int,float,float,float,float,char *) | ??0Dialog_Serial@@QAE@HMMMMPAD@Z
    0x4A00B0 | public: virtual __thiscall Dialog_Serial::~Dialog_Serial(void) | ??1Dialog_Serial@@UAE@XZ
    0x4A0110 | public: virtual void __thiscall Dialog_Serial::PreSetup(void) | ?PreSetup@Dialog_Serial@@UAEXXZ
    0x4A0120 | public: void __thiscall Dialog_Serial::IPAddressCallback(void) | ?IPAddressCallback@Dialog_Serial@@QAEXXZ
    0x4A0130 | public: void __thiscall Dialog_Serial::BuildComs(void) | ?BuildComs@Dialog_Serial@@QAEXXZ
    0x4A01F0 | public: struct NETCOMMPACK * __thiscall Dialog_Serial::GetCommPack(void) | ?GetCommPack@Dialog_Serial@@QAEPAUNETCOMMPACK@@XZ
    0x4A0200 | public: virtual void * __thiscall Dialog_Serial::`vector deleting destructor'(unsigned int) | ??_EDialog_Serial@@UAEPAXI@Z
    0x4A0200 | public: virtual void * __thiscall Dialog_Serial::`scalar deleting destructor'(unsigned int) | ??_GDialog_Serial@@UAEPAXI@Z
    0x61D768 | const Dialog_Serial::`vftable' | ??_7Dialog_Serial@@6B@
*/

#include "pu_menu.h"

class Dialog_Serial /*final*/ : public PUMenuBase
{
    // const Dialog_Serial::`vftable' @ 0x61D768

public:
    // 0x49F850 | ??0Dialog_Serial@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_Serial(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x4A0200 | ??_GDialog_Serial@@UAEPAXI@Z
    // 0x4A0200 | ??_EDialog_Serial@@UAEPAXI@Z
    // 0x4A00B0 | ??1Dialog_Serial@@UAE@XZ
    ARTS_IMPORT ~Dialog_Serial() override;

    // 0x4A0130 | ?BuildComs@Dialog_Serial@@QAEXXZ
    ARTS_IMPORT void BuildComs();

    // 0x4A01F0 | ?GetCommPack@Dialog_Serial@@QAEPAUNETCOMMPACK@@XZ
    ARTS_IMPORT struct NETCOMMPACK* GetCommPack();

    // 0x4A0120 | ?IPAddressCallback@Dialog_Serial@@QAEXXZ | unused
    ARTS_IMPORT void IPAddressCallback();

    // 0x4A0110 | ?PreSetup@Dialog_Serial@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gapC0[0x88];
};

check_size(Dialog_Serial, 0x148);
