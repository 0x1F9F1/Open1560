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

#include "network.h"

asNetwork::asNetwork()
{
    unimplemented();
}

asNetwork::~asNetwork()
{
    unimplemented();
}

void asNetwork::ChatMessage(u32 arg1, char* arg2)
{
    return stub<thiscall_t<void, asNetwork*, u32, char*>>(0x8AE30_Offset, this, arg1, arg2);
}

void asNetwork::CloseSession()
{
    return stub<thiscall_t<void, asNetwork*>>(0x8A3A0_Offset, this);
}

i32 asNetwork::CreateInterface()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x89470_Offset, this);
}

i32 asNetwork::CreatePlayer(char* arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asNetwork*, char*, void*, i32>>(0x899A0_Offset, this, arg1, arg2, arg3);
}

i32 asNetwork::CreateSession(char* arg1, char* arg2, i32 arg3, struct NETSESSION_DESC* arg4)
{
    return stub<thiscall_t<i32, asNetwork*, char*, char*, i32, struct NETSESSION_DESC*>>(
        0x8A080_Offset, this, arg1, arg2, arg3, arg4);
}

void asNetwork::Deallocate()
{
    return stub<thiscall_t<void, asNetwork*>>(0x89430_Offset, this);
}

void asNetwork::DestroyPlayer()
{
    return stub<thiscall_t<void, asNetwork*>>(0x89A60_Offset, this);
}

void asNetwork::Disconnect()
{
    return stub<thiscall_t<void, asNetwork*>>(0x89910_Offset, this);
}

char* asNetwork::GetEnumModem(i32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, i32>>(0x8B2D0_Offset, this, arg1);
}

char* asNetwork::GetEnumPlayer(i32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, i32>>(0x89AD0_Offset, this, arg1);
}

i32 asNetwork::GetEnumPlayerData(i32 arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asNetwork*, i32, void*, i32>>(0x89E40_Offset, this, arg1, arg2, arg3);
}

char* asNetwork::GetEnumProtocol(i32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, i32>>(0x89960_Offset, this, arg1);
}

char* asNetwork::GetEnumSession(i32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, i32>>(0x8A3E0_Offset, this, arg1);
}

i32 asNetwork::GetEnumSessionID(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x8A410_Offset, this, arg1);
}

i32 asNetwork::GetEnumSessionLock(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x8B060_Offset, this, arg1);
}

i32 asNetwork::GetEnumSessionStatus(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x8B030_Offset, this, arg1);
}

i32 asNetwork::GetGameVersion(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x8B000_Offset, this, arg1);
}

i32 asNetwork::GetMyLogicalIndex()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x8AFC0_Offset, this);
}

i32 asNetwork::GetNetworkCaps()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x89490_Offset, this);
}

i32 asNetwork::GetNumModems()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x8B2C0_Offset, this);
}

i32 asNetwork::GetNumPlayers()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x89B40_Offset, this);
}

i32 asNetwork::GetNumProtocols()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x89990_Offset, this);
}

i32 asNetwork::GetNumSessions()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x8A440_Offset, this);
}

i32 asNetwork::GetPlayerData(u32 arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asNetwork*, u32, void*, i32>>(0x89F00_Offset, this, arg1, arg2, arg3);
}

u32 asNetwork::GetPlayerID(i32 arg1)
{
    return stub<thiscall_t<u32, asNetwork*, i32>>(0x89B00_Offset, this, arg1);
}

char* asNetwork::GetPlayerName(u32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, u32>>(0x89C00_Offset, this, arg1);
}

i32 asNetwork::GetPlayerName(u32 arg1, char* arg2)
{
    return stub<thiscall_t<i32, asNetwork*, u32, char*>>(0x89CC0_Offset, this, arg1, arg2);
}

i32 asNetwork::GetPlayers(struct _GUID* arg1)
{
    return stub<thiscall_t<i32, asNetwork*, struct _GUID*>>(0x89AA0_Offset, this, arg1);
}

void asNetwork::GetProtocols()
{
    return stub<thiscall_t<void, asNetwork*>>(0x89520_Offset, this);
}

void asNetwork::GetSessionData(struct NETSESSION_DESC* arg1)
{
    return stub<thiscall_t<void, asNetwork*, struct NETSESSION_DESC*>>(0x8A690_Offset, this, arg1);
}

void asNetwork::GetSessionsAsynch()
{
    return stub<thiscall_t<void, asNetwork*>>(0x8A940_Offset, this);
}

i32 asNetwork::GetSessionsSynch(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x8A890_Offset, this, arg1);
}

void asNetwork::HandleAppMessage(void* arg1)
{
    return stub<thiscall_t<void, asNetwork*, void*>>(0x8ABC0_Offset, this, arg1);
}

void asNetwork::HandleSysMessage(struct DPMSG_GENERIC* arg1)
{
    return stub<thiscall_t<void, asNetwork*, struct DPMSG_GENERIC*>>(0x8ABE0_Offset, this, arg1);
}

i32 asNetwork::Initialize(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asNetwork*, i32, i32, i32>>(0x89020_Offset, this, arg1, arg2, arg3);
}

i32 asNetwork::InitializeLobby(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, asNetwork*, i32, i32>>(0x89080_Offset, this, arg1, arg2);
}

i32 asNetwork::JoinLobbySession()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x89150_Offset, this);
}

i32 asNetwork::JoinSession(i32 arg1, char* arg2)
{
    return stub<thiscall_t<i32, asNetwork*, i32, char*>>(0x8B240_Offset, this, arg1, arg2);
}

i32 asNetwork::JoinSession(char* arg1, struct _GUID* arg2, char* arg3)
{
    return stub<thiscall_t<i32, asNetwork*, char*, struct _GUID*, char*>>(0x8A170_Offset, this, arg1, arg2, arg3);
}

void asNetwork::Logout()
{
    return stub<thiscall_t<void, asNetwork*>>(0x89360_Offset, this);
}

u32 asNetwork::Ping(u32 arg1)
{
    return stub<thiscall_t<u32, asNetwork*, u32>>(0x89FB0_Offset, this, arg1);
}

i32 asNetwork::PollLobby()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x8AA20_Offset, this);
}

i32 asNetwork::QueryModems()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x8B300_Offset, this);
}

void asNetwork::SealSession()
{
    return stub<thiscall_t<void, asNetwork*>>(0x8A450_Offset, this);
}

void asNetwork::Send(u32 arg1, void* arg2, u32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, asNetwork*, u32, void*, u32, i32>>(0x8AEF0_Offset, this, arg1, arg2, arg3, arg4);
}

void asNetwork::SendLobbyProperty(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, asNetwork*, void*, i32>>(0x89280_Offset, this, arg1, arg2);
}

void asNetwork::SetEnumSessionLock(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asNetwork*, i32, i32>>(0x8B090_Offset, this, arg1, arg2);
}

void asNetwork::SetPlayerData(u32 arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<void, asNetwork*, u32, void*, i32>>(0x89DA0_Offset, this, arg1, arg2, arg3);
}

i32 asNetwork::SetProtocol(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x898B0_Offset, this, arg1);
}

i32 asNetwork::SetProtocol(i32 arg1, struct NETCOMMPACK* arg2)
{
    return stub<thiscall_t<i32, asNetwork*, i32, struct NETCOMMPACK*>>(0x89550_Offset, this, arg1, arg2);
}

void asNetwork::SetSessionData(struct NETSESSION_DESC* arg1, char* arg2)
{
    return stub<thiscall_t<void, asNetwork*, struct NETSESSION_DESC*, char*>>(0x8A750_Offset, this, arg1, arg2);
}

void asNetwork::StopSessionsAsynch()
{
    return stub<thiscall_t<void, asNetwork*>>(0x8A9A0_Offset, this);
}

void asNetwork::UnSealSession()
{
    return stub<thiscall_t<void, asNetwork*>>(0x8A570_Offset, this);
}

i32 asNetwork::Update()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x8AAC0_Offset, this);
}

void asNetwork::WaitForLobbyConnection(i32 arg1)
{
    return stub<thiscall_t<void, asNetwork*, i32>>(0x890F0_Offset, this, arg1);
}

i32 __stdcall EnumConnectionsCallback(
    struct _GUID const* arg1, void* arg2, u32 arg3, struct DPNAME const* arg4, u32 arg5, void* arg6)
{
    return stub<stdcall_t<i32, struct _GUID const*, void*, u32, struct DPNAME const*, u32, void*>>(
        0x8B170_Offset, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 __stdcall EnumModemAddress(struct _GUID const& arg1, u32 arg2, void const* arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct _GUID const&, u32, void const*, void*>>(0x8B430_Offset, arg1, arg2, arg3, arg4);
}

i32 __stdcall EnumPlayersCallback(u32 arg1, u32 arg2, struct DPNAME const* arg3, u32 arg4, void* arg5)
{
    return stub<stdcall_t<i32, u32, u32, struct DPNAME const*, u32, void*>>(
        0x8B1E0_Offset, arg1, arg2, arg3, arg4, arg5);
}

i32 __stdcall EnumSessionCallback(struct DPSESSIONDESC2 const* arg1, u32* arg2, u32 arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct DPSESSIONDESC2 const*, u32*, u32, void*>>(0x8B0B0_Offset, arg1, arg2, arg3, arg4);
}

define_dummy_symbol(mmnetwork_network);
