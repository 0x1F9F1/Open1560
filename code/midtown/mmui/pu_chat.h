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
    mmui:pu_chat

    0x4A9780 | public: __thiscall PUChat::PUChat(int,float,float,float,float,char *) | ??0PUChat@@QAE@HMMMMPAD@Z
    0x4A9880 | public: virtual __thiscall PUChat::~PUChat(void) | ??1PUChat@@UAE@XZ
    0x4A9890 | public: void __thiscall PUChat::ClearChat(void) | ?ClearChat@PUChat@@QAEXXZ
    0x4A98D0 | public: void __thiscall PUChat::ChatEntry(void) | ?ChatEntry@PUChat@@QAEXXZ
    0x4A9930 | public: virtual void * __thiscall PUChat::`scalar deleting destructor'(unsigned int) | ??_GPUChat@@UAEPAXI@Z
    0x4A9930 | public: virtual void * __thiscall PUChat::`vector deleting destructor'(unsigned int) | ??_EPUChat@@UAEPAXI@Z
    0x61DED8 | const PUChat::`vftable' | ??_7PUChat@@6B@
*/

#include "pu_menu.h"

class PUChat final : public PUMenuBase
{
public:
    // ??0PUChat@@QAE@HMMMMPAD@Z
    ARTS_IMPORT PUChat(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // ??_EPUChat@@UAEPAXI@Z
    // ??_GPUChat@@UAEPAXI@Z
    // ??1PUChat@@UAE@XZ
    ARTS_IMPORT ~PUChat() override = default;

    // ?ChatEntry@PUChat@@QAEXXZ
    ARTS_IMPORT void ChatEntry();

    // ?ClearChat@PUChat@@QAEXXZ
    ARTS_IMPORT void ClearChat();

    u8 gapC0[0x68];
};

check_size(PUChat, 0x128);
