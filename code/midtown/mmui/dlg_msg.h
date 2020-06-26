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
    mmui:dlg_msg

    0x49F2E0 | public: __thiscall Dialog_Message::Dialog_Message(int,float,float,float,float,char *) | ??0Dialog_Message@@QAE@HMMMMPAD@Z
    0x49F3F0 | public: void __thiscall Dialog_Message::Init(int,char *,char *) | ?Init@Dialog_Message@@QAEXHPAD0@Z
    0x49F460 | public: virtual __thiscall Dialog_Message::~Dialog_Message(void) | ??1Dialog_Message@@UAE@XZ
    0x49F470 | public: virtual void __thiscall Dialog_Message::PreSetup(void) | ?PreSetup@Dialog_Message@@UAEXXZ
    0x49F480 | public: virtual void * __thiscall Dialog_Message::`vector deleting destructor'(unsigned int) | ??_EDialog_Message@@UAEPAXI@Z
    0x49F480 | public: virtual void * __thiscall Dialog_Message::`scalar deleting destructor'(unsigned int) | ??_GDialog_Message@@UAEPAXI@Z
    0x61D6B8 | const Dialog_Message::`vftable' | ??_7Dialog_Message@@6B@
*/

#include "pu_menu.h"

class Dialog_Message : public PUMenuBase
{
    // const Dialog_Message::`vftable' @ 0x61D6B8

public:
    // 0x49F2E0 | ??0Dialog_Message@@QAE@HMMMMPAD@Z
    ARTS_IMPORT Dialog_Message(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x49F480 | ??_GDialog_Message@@UAEPAXI@Z
    // 0x49F460 | ??1Dialog_Message@@UAE@XZ
    ARTS_IMPORT ~Dialog_Message() override;

    // 0x49F3F0 | ?Init@Dialog_Message@@QAEXHPAD0@Z
    ARTS_IMPORT void Init(i32 arg1, char* arg2, char* arg3);

    // 0x49F470 | ?PreSetup@Dialog_Message@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gapC0[0x10];
};

check_size(Dialog_Message, 0xD0);
