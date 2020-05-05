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
    return stub<thiscall_t<void, NetArena*, char*>>(0xA1F30_Offset, this, arg1);
}

void NetArena::AddRosterName(char* arg1)
{
    return stub<thiscall_t<void, NetArena*, char*>>(0xA2230_Offset, this, arg1);
}

void NetArena::AddRosterName(struct LocString* arg1, struct LocString* arg2, struct LocString* arg3, u32 arg4)
{
    return stub<thiscall_t<void, NetArena*, struct LocString*, struct LocString*, struct LocString*, u32>>(
        0xA2250_Offset, this, arg1, arg2, arg3, arg4);
}

void NetArena::ChatEntry()
{
    return stub<thiscall_t<void, NetArena*>>(0xA20B0_Offset, this);
}

void NetArena::DisablePlayButton()
{
    return stub<thiscall_t<void, NetArena*>>(0xA1E60_Offset, this);
}

void NetArena::EnablePlayButton()
{
    return stub<thiscall_t<void, NetArena*>>(0xA1E50_Offset, this);
}

i32 NetArena::FindRosterName(char* arg1)
{
    return stub<thiscall_t<i32, NetArena*, char*>>(0xA21C0_Offset, this, arg1);
}

char* NetArena::GetRaceName()
{
    return stub<thiscall_t<char*, NetArena*>>(0xA2670_Offset, this);
}

void NetArena::PostChatMessages()
{
    return stub<thiscall_t<void, NetArena*>>(0xA1FE0_Offset, this);
}

void NetArena::PostHostSettings()
{
    return stub<thiscall_t<void, NetArena*>>(0xA2880_Offset, this);
}

void NetArena::PostPlayerInfo(struct LocString* arg1, struct LocString* arg2, struct LocString* arg3)
{
    return stub<thiscall_t<void, NetArena*, struct LocString*, struct LocString*, struct LocString*>>(
        0xA2A40_Offset, this, arg1, arg2, arg3);
}

void NetArena::PreSetup()
{
    return stub<thiscall_t<void, NetArena*>>(0xA1E40_Offset, this);
}

void NetArena::RemoveRosterEntry(i32 arg1)
{
    return stub<thiscall_t<void, NetArena*, i32>>(0xA23F0_Offset, this, arg1);
}

void NetArena::RemoveRosterName(char* arg1)
{
    return stub<thiscall_t<void, NetArena*, char*>>(0xA25E0_Offset, this, arg1);
}

void NetArena::ResetGameChat()
{
    return stub<thiscall_t<void, NetArena*>>(0xA1E70_Offset, this);
}

void NetArena::ResetRoster()
{
    return stub<thiscall_t<void, NetArena*>>(0xA24C0_Offset, this);
}

i32 NetArena::RetrieveChatLine(char* arg1)
{
    return stub<thiscall_t<i32, NetArena*, char*>>(0xA2170_Offset, this, arg1);
}

void NetArena::SetHost(i32 arg1)
{
    return stub<thiscall_t<void, NetArena*, i32>>(0xA2AF0_Offset, this, arg1);
}

void NetArena::SetReady(u32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, NetArena*, u32, i32>>(0xA2620_Offset, this, arg1, arg2);
}
