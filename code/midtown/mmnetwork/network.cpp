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

define_dummy_symbol(mmnetwork_network);

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
    return stub<thiscall_t<void, asNetwork*, u32, char*>>(0x48AE30, this, arg1, arg2);
}

void asNetwork::CloseSession()
{
    return stub<thiscall_t<void, asNetwork*>>(0x48A3A0, this);
}

i32 asNetwork::CreateInterface()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x489470, this);
}

i32 asNetwork::CreatePlayer(char* arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asNetwork*, char*, void*, i32>>(0x4899A0, this, arg1, arg2, arg3);
}

i32 asNetwork::CreateSession(char* arg1, char* arg2, i32 arg3, struct NETSESSION_DESC* arg4)
{
    return stub<thiscall_t<i32, asNetwork*, char*, char*, i32, struct NETSESSION_DESC*>>(
        0x48A080, this, arg1, arg2, arg3, arg4);
}

void asNetwork::Deallocate()
{
    return stub<thiscall_t<void, asNetwork*>>(0x489430, this);
}

void asNetwork::DestroyPlayer()
{
    return stub<thiscall_t<void, asNetwork*>>(0x489A60, this);
}

void asNetwork::Disconnect()
{
    return stub<thiscall_t<void, asNetwork*>>(0x489910, this);
}

char* asNetwork::GetEnumModem(i32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, i32>>(0x48B2D0, this, arg1);
}

char* asNetwork::GetEnumPlayer(i32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, i32>>(0x489AD0, this, arg1);
}

i32 asNetwork::GetEnumPlayerData(i32 arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asNetwork*, i32, void*, i32>>(0x489E40, this, arg1, arg2, arg3);
}

char* asNetwork::GetEnumProtocol(i32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, i32>>(0x489960, this, arg1);
}

char* asNetwork::GetEnumSession(i32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, i32>>(0x48A3E0, this, arg1);
}

i32 asNetwork::GetEnumSessionID(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x48A410, this, arg1);
}

i32 asNetwork::GetEnumSessionLock(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x48B060, this, arg1);
}

i32 asNetwork::GetEnumSessionStatus(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x48B030, this, arg1);
}

i32 asNetwork::GetGameVersion(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x48B000, this, arg1);
}

i32 asNetwork::GetMyLogicalIndex()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x48AFC0, this);
}

i32 asNetwork::GetNetworkCaps()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x489490, this);
}

i32 asNetwork::GetNumModems()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x48B2C0, this);
}

i32 asNetwork::GetNumPlayers()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x489B40, this);
}

i32 asNetwork::GetNumProtocols()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x489990, this);
}

i32 asNetwork::GetNumSessions()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x48A440, this);
}

i32 asNetwork::GetPlayerData(u32 arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asNetwork*, u32, void*, i32>>(0x489F00, this, arg1, arg2, arg3);
}

u32 asNetwork::GetPlayerID(i32 arg1)
{
    return stub<thiscall_t<u32, asNetwork*, i32>>(0x489B00, this, arg1);
}

char* asNetwork::GetPlayerName(u32 arg1)
{
    return stub<thiscall_t<char*, asNetwork*, u32>>(0x489C00, this, arg1);
}

i32 asNetwork::GetPlayerName(u32 arg1, char* arg2)
{
    return stub<thiscall_t<i32, asNetwork*, u32, char*>>(0x489CC0, this, arg1, arg2);
}

i32 asNetwork::GetPlayers(struct _GUID* arg1)
{
    return stub<thiscall_t<i32, asNetwork*, struct _GUID*>>(0x489AA0, this, arg1);
}

void asNetwork::GetProtocols()
{
    return stub<thiscall_t<void, asNetwork*>>(0x489520, this);
}

void asNetwork::GetSessionData(struct NETSESSION_DESC* arg1)
{
    return stub<thiscall_t<void, asNetwork*, struct NETSESSION_DESC*>>(0x48A690, this, arg1);
}

void asNetwork::GetSessionsAsynch()
{
    return stub<thiscall_t<void, asNetwork*>>(0x48A940, this);
}

i32 asNetwork::GetSessionsSynch(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x48A890, this, arg1);
}

void asNetwork::HandleAppMessage(void* arg1)
{
    return stub<thiscall_t<void, asNetwork*, void*>>(0x48ABC0, this, arg1);
}

void asNetwork::HandleSysMessage(struct DPMSG_GENERIC* arg1)
{
    return stub<thiscall_t<void, asNetwork*, struct DPMSG_GENERIC*>>(0x48ABE0, this, arg1);
}

i32 asNetwork::Initialize(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asNetwork*, i32, i32, i32>>(0x489020, this, arg1, arg2, arg3);
}

i32 asNetwork::InitializeLobby(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, asNetwork*, i32, i32>>(0x489080, this, arg1, arg2);
}

i32 asNetwork::JoinLobbySession()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x489150, this);
}

i32 asNetwork::JoinSession(i32 arg1, char* arg2)
{
    return stub<thiscall_t<i32, asNetwork*, i32, char*>>(0x48B240, this, arg1, arg2);
}

i32 asNetwork::JoinSession(char* arg1, struct _GUID* arg2, char* arg3)
{
    return stub<thiscall_t<i32, asNetwork*, char*, struct _GUID*, char*>>(0x48A170, this, arg1, arg2, arg3);
}

void asNetwork::Logout()
{
    return stub<thiscall_t<void, asNetwork*>>(0x489360, this);
}

u32 asNetwork::Ping(u32 arg1)
{
    return stub<thiscall_t<u32, asNetwork*, u32>>(0x489FB0, this, arg1);
}

i32 asNetwork::PollLobby()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x48AA20, this);
}

i32 asNetwork::QueryModems()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x48B300, this);
}

void asNetwork::SealSession()
{
    return stub<thiscall_t<void, asNetwork*>>(0x48A450, this);
}

void asNetwork::Send(u32 arg1, void* arg2, u32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, asNetwork*, u32, void*, u32, i32>>(0x48AEF0, this, arg1, arg2, arg3, arg4);
}

void asNetwork::SendLobbyProperty(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, asNetwork*, void*, i32>>(0x489280, this, arg1, arg2);
}

void asNetwork::SetEnumSessionLock(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asNetwork*, i32, i32>>(0x48B090, this, arg1, arg2);
}

void asNetwork::SetPlayerData(u32 arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<void, asNetwork*, u32, void*, i32>>(0x489DA0, this, arg1, arg2, arg3);
}

i32 asNetwork::SetProtocol(i32 arg1)
{
    return stub<thiscall_t<i32, asNetwork*, i32>>(0x4898B0, this, arg1);
}

i32 asNetwork::SetProtocol(i32 arg1, struct NETCOMMPACK* arg2)
{
    return stub<thiscall_t<i32, asNetwork*, i32, struct NETCOMMPACK*>>(0x489550, this, arg1, arg2);
}

void asNetwork::SetSessionData(struct NETSESSION_DESC* arg1, char* arg2)
{
    return stub<thiscall_t<void, asNetwork*, struct NETSESSION_DESC*, char*>>(0x48A750, this, arg1, arg2);
}

void asNetwork::StopSessionsAsynch()
{
    return stub<thiscall_t<void, asNetwork*>>(0x48A9A0, this);
}

void asNetwork::UnSealSession()
{
    return stub<thiscall_t<void, asNetwork*>>(0x48A570, this);
}

i32 asNetwork::Update()
{
    return stub<thiscall_t<i32, asNetwork*>>(0x48AAC0, this);
}

void asNetwork::WaitForLobbyConnection(i32 arg1)
{
    return stub<thiscall_t<void, asNetwork*, i32>>(0x4890F0, this, arg1);
}

i32 __stdcall EnumConnectionsCallback(
    struct _GUID const* arg1, void* arg2, u32 arg3, struct DPNAME const* arg4, u32 arg5, void* arg6)
{
    return stub<stdcall_t<i32, struct _GUID const*, void*, u32, struct DPNAME const*, u32, void*>>(
        0x48B170, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 __stdcall EnumModemAddress(struct _GUID const& arg1, u32 arg2, void const* arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct _GUID const&, u32, void const*, void*>>(0x48B430, arg1, arg2, arg3, arg4);
}

i32 __stdcall EnumPlayersCallback(u32 arg1, u32 arg2, struct DPNAME const* arg3, u32 arg4, void* arg5)
{
    return stub<stdcall_t<i32, u32, u32, struct DPNAME const*, u32, void*>>(0x48B1E0, arg1, arg2, arg3, arg4, arg5);
}

i32 __stdcall EnumSessionCallback(struct DPSESSIONDESC2 const* arg1, u32* arg2, u32 arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct DPSESSIONDESC2 const*, u32*, u32, void*>>(0x48B0B0, arg1, arg2, arg3, arg4);
}
