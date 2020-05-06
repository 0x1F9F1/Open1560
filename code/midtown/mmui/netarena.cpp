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

define_dummy_symbol(mmui_netarena);

#include "netarena.h"

NetArena::NetArena(i32 arg1)
{
    unimplemented(arg1);
}

NetArena::~NetArena()
{
    unimplemented(arg1);
}

void NetArena::AddGameChatLine(char* arg1)
{
    return stub<thiscall_t<void, NetArena*, char*>>(0x4A1F30, this, arg1);
}

void NetArena::AddRosterName(char* arg1)
{
    return stub<thiscall_t<void, NetArena*, char*>>(0x4A2230, this, arg1);
}

void NetArena::AddRosterName(struct LocString* arg1, struct LocString* arg2, struct LocString* arg3, u32 arg4)
{
    return stub<thiscall_t<void, NetArena*, struct LocString*, struct LocString*, struct LocString*, u32>>(
        0x4A2250, this, arg1, arg2, arg3, arg4);
}

void NetArena::ChatEntry()
{
    return stub<thiscall_t<void, NetArena*>>(0x4A20B0, this);
}

void NetArena::DisablePlayButton()
{
    return stub<thiscall_t<void, NetArena*>>(0x4A1E60, this);
}

void NetArena::EnablePlayButton()
{
    return stub<thiscall_t<void, NetArena*>>(0x4A1E50, this);
}

i32 NetArena::FindRosterName(char* arg1)
{
    return stub<thiscall_t<i32, NetArena*, char*>>(0x4A21C0, this, arg1);
}

char* NetArena::GetRaceName()
{
    return stub<thiscall_t<char*, NetArena*>>(0x4A2670, this);
}

void NetArena::PostChatMessages()
{
    return stub<thiscall_t<void, NetArena*>>(0x4A1FE0, this);
}

void NetArena::PostHostSettings()
{
    return stub<thiscall_t<void, NetArena*>>(0x4A2880, this);
}

void NetArena::PostPlayerInfo(struct LocString* arg1, struct LocString* arg2, struct LocString* arg3)
{
    return stub<thiscall_t<void, NetArena*, struct LocString*, struct LocString*, struct LocString*>>(
        0x4A2A40, this, arg1, arg2, arg3);
}

void NetArena::PreSetup()
{
    return stub<thiscall_t<void, NetArena*>>(0x4A1E40, this);
}

void NetArena::RemoveRosterEntry(i32 arg1)
{
    return stub<thiscall_t<void, NetArena*, i32>>(0x4A23F0, this, arg1);
}

void NetArena::RemoveRosterName(char* arg1)
{
    return stub<thiscall_t<void, NetArena*, char*>>(0x4A25E0, this, arg1);
}

void NetArena::ResetGameChat()
{
    return stub<thiscall_t<void, NetArena*>>(0x4A1E70, this);
}

void NetArena::ResetRoster()
{
    return stub<thiscall_t<void, NetArena*>>(0x4A24C0, this);
}

i32 NetArena::RetrieveChatLine(char* arg1)
{
    return stub<thiscall_t<i32, NetArena*, char*>>(0x4A2170, this, arg1);
}

void NetArena::SetHost(i32 arg1)
{
    return stub<thiscall_t<void, NetArena*, i32>>(0x4A2AF0, this, arg1);
}

void NetArena::SetReady(u32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, NetArena*, u32, i32>>(0x4A2620, this, arg1, arg2);
}
