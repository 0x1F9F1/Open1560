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

#include "mmwidget/menu.h"

class NetArena final : public UIMenu
{
public:
    // ??0NetArena@@QAE@H@Z
    ARTS_IMPORT NetArena(i32 arg1);

    // ??1NetArena@@UAE@XZ
    ARTS_IMPORT ~NetArena() override;

    // ?AddGameChatLine@NetArena@@QAEXPAD@Z
    ARTS_IMPORT void AddGameChatLine(char* arg1);

    // ?AddRosterName@NetArena@@QAEXPAULocString@@00K@Z
    ARTS_IMPORT void AddRosterName(LocString* arg1, LocString* arg2, LocString* arg3, ulong arg4);

    // ?ChatEntry@NetArena@@QAEXXZ
    ARTS_IMPORT void ChatEntry();

    // ?FindRosterName@NetArena@@QAEHPAD@Z
    ARTS_IMPORT i32 FindRosterName(char* arg1);

    // ?GetRaceName@NetArena@@QAEPADXZ
    ARTS_IMPORT char* GetRaceName();

    // ?PostChatMessages@NetArena@@QAEXXZ
    ARTS_IMPORT void PostChatMessages();

    // ?PostHostSettings@NetArena@@QAEXXZ
    ARTS_IMPORT void PostHostSettings();

    // ?PostPlayerInfo@NetArena@@QAEXPAULocString@@00@Z
    ARTS_IMPORT void PostPlayerInfo(LocString* arg1, LocString* arg2, LocString* arg3);

    // ?PreSetup@NetArena@@UAEXXZ
    ARTS_EXPORT void PreSetup() override;

    // ?RemoveRosterEntry@NetArena@@QAEXH@Z
    ARTS_IMPORT void RemoveRosterEntry(i32 arg1);

    // ?ResetGameChat@NetArena@@QAEXXZ
    ARTS_IMPORT void ResetGameChat();

    // ?ResetRoster@NetArena@@QAEXXZ
    ARTS_IMPORT void ResetRoster();

    // ?RetrieveChatLine@NetArena@@QAEHPAD@Z
    ARTS_IMPORT i32 RetrieveChatLine(char* arg1);

    // ?SetHost@NetArena@@QAEXH@Z
    ARTS_IMPORT void SetHost(i32 arg1);

    // ?SetReady@NetArena@@QAEXKH@Z
    ARTS_IMPORT void SetReady(ulong arg1, i32 arg2);

    u8 gap90[0xA0];
};

check_size(NetArena, 0x130);
