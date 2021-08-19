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
    mmui:netarena

    0x4A1790 | public: __thiscall NetArena::NetArena(int) | ??0NetArena@@QAE@H@Z
    0x4A1D80 | public: virtual __thiscall NetArena::~NetArena(void) | ??1NetArena@@UAE@XZ
    0x4A1E40 | public: virtual void __thiscall NetArena::PreSetup(void) | ?PreSetup@NetArena@@UAEXXZ
    0x4A1E50 | public: void __thiscall NetArena::EnablePlayButton(void) | ?EnablePlayButton@NetArena@@QAEXXZ
    0x4A1E60 | public: void __thiscall NetArena::DisablePlayButton(void) | ?DisablePlayButton@NetArena@@QAEXXZ
    0x4A1E70 | public: void __thiscall NetArena::ResetGameChat(void) | ?ResetGameChat@NetArena@@QAEXXZ
    0x4A1F30 | public: void __thiscall NetArena::AddGameChatLine(char *) | ?AddGameChatLine@NetArena@@QAEXPAD@Z
    0x4A1FE0 | public: void __thiscall NetArena::PostChatMessages(void) | ?PostChatMessages@NetArena@@QAEXXZ
    0x4A20B0 | public: void __thiscall NetArena::ChatEntry(void) | ?ChatEntry@NetArena@@QAEXXZ
    0x4A2170 | public: int __thiscall NetArena::RetrieveChatLine(char *) | ?RetrieveChatLine@NetArena@@QAEHPAD@Z
    0x4A21C0 | public: int __thiscall NetArena::FindRosterName(char *) | ?FindRosterName@NetArena@@QAEHPAD@Z
    0x4A2230 | public: void __thiscall NetArena::AddRosterName(char *) | ?AddRosterName@NetArena@@QAEXPAD@Z
    0x4A2250 | public: void __thiscall NetArena::AddRosterName(struct LocString *,struct LocString *,struct LocString *,unsigned long) | ?AddRosterName@NetArena@@QAEXPAULocString@@00K@Z
    0x4A23F0 | public: void __thiscall NetArena::RemoveRosterEntry(int) | ?RemoveRosterEntry@NetArena@@QAEXH@Z
    0x4A24C0 | public: void __thiscall NetArena::ResetRoster(void) | ?ResetRoster@NetArena@@QAEXXZ
    0x4A25E0 | public: void __thiscall NetArena::RemoveRosterName(char *) | ?RemoveRosterName@NetArena@@QAEXPAD@Z
    0x4A2620 | public: void __thiscall NetArena::SetReady(unsigned long,int) | ?SetReady@NetArena@@QAEXKH@Z
    0x4A2670 | public: char * __thiscall NetArena::GetRaceName(void) | ?GetRaceName@NetArena@@QAEPADXZ
    0x4A2880 | public: void __thiscall NetArena::PostHostSettings(void) | ?PostHostSettings@NetArena@@QAEXXZ
    0x4A2A40 | public: void __thiscall NetArena::PostPlayerInfo(struct LocString *,struct LocString *,struct LocString *) | ?PostPlayerInfo@NetArena@@QAEXPAULocString@@00@Z
    0x4A2AF0 | public: void __thiscall NetArena::SetHost(int) | ?SetHost@NetArena@@QAEXH@Z
    0x4A2B30 | public: virtual void * __thiscall NetArena::`scalar deleting destructor'(unsigned int) | ??_GNetArena@@UAEPAXI@Z
    0x4A2B30 | public: virtual void * __thiscall NetArena::`vector deleting destructor'(unsigned int) | ??_ENetArena@@UAEPAXI@Z
    0x61D8E0 | const NetArena::`vftable' | ??_7NetArena@@6B@
*/

#include "mmwidget/menu.h"

class NetArena final : public UIMenu
{
public:
    // ??0NetArena@@QAE@H@Z
    ARTS_IMPORT NetArena(i32 arg1);

    // ??_ENetArena@@UAEPAXI@Z
    // ??_GNetArena@@UAEPAXI@Z
    // ??1NetArena@@UAE@XZ
    ARTS_IMPORT ~NetArena() override;

    // ?AddGameChatLine@NetArena@@QAEXPAD@Z
    ARTS_IMPORT void AddGameChatLine(char* arg1);

    // ?AddRosterName@NetArena@@QAEXPAD@Z | unused
    ARTS_IMPORT void AddRosterName(char* arg1);

    // ?AddRosterName@NetArena@@QAEXPAULocString@@00K@Z
    ARTS_IMPORT void AddRosterName(struct LocString* arg1, struct LocString* arg2, struct LocString* arg3, ulong arg4);

    // ?ChatEntry@NetArena@@QAEXXZ
    ARTS_IMPORT void ChatEntry();

    // ?DisablePlayButton@NetArena@@QAEXXZ | unused
    ARTS_IMPORT void DisablePlayButton();

    // ?EnablePlayButton@NetArena@@QAEXXZ | unused
    ARTS_IMPORT void EnablePlayButton();

    // ?FindRosterName@NetArena@@QAEHPAD@Z
    ARTS_IMPORT i32 FindRosterName(char* arg1);

    // ?GetRaceName@NetArena@@QAEPADXZ
    ARTS_IMPORT char* GetRaceName();

    // ?PostChatMessages@NetArena@@QAEXXZ
    ARTS_IMPORT void PostChatMessages();

    // ?PostHostSettings@NetArena@@QAEXXZ
    ARTS_IMPORT void PostHostSettings();

    // ?PostPlayerInfo@NetArena@@QAEXPAULocString@@00@Z
    ARTS_IMPORT void PostPlayerInfo(struct LocString* arg1, struct LocString* arg2, struct LocString* arg3);

    // ?PreSetup@NetArena@@UAEXXZ
    ARTS_EXPORT void PreSetup() override;

    // ?RemoveRosterEntry@NetArena@@QAEXH@Z
    ARTS_IMPORT void RemoveRosterEntry(i32 arg1);

    // ?RemoveRosterName@NetArena@@QAEXPAD@Z | unused
    ARTS_IMPORT void RemoveRosterName(char* arg1);

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
