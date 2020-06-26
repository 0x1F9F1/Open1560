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
    mmnetwork:network

    0x488FA0 | public: __thiscall asNetwork::asNetwork(void) | ??0asNetwork@@QAE@XZ
    0x489010 | public: __thiscall asNetwork::~asNetwork(void) | ??1asNetwork@@QAE@XZ
    0x489020 | public: int __thiscall asNetwork::Initialize(int,int,int) | ?Initialize@asNetwork@@QAEHHHH@Z
    0x489080 | public: int __thiscall asNetwork::InitializeLobby(int,int) | ?InitializeLobby@asNetwork@@QAEHHH@Z
    0x4890F0 | public: void __thiscall asNetwork::WaitForLobbyConnection(int) | ?WaitForLobbyConnection@asNetwork@@QAEXH@Z
    0x489150 | public: int __thiscall asNetwork::JoinLobbySession(void) | ?JoinLobbySession@asNetwork@@QAEHXZ
    0x489280 | public: void __thiscall asNetwork::SendLobbyProperty(void *,int) | ?SendLobbyProperty@asNetwork@@QAEXPAXH@Z
    0x489360 | public: void __thiscall asNetwork::Logout(void) | ?Logout@asNetwork@@QAEXXZ
    0x489430 | public: void __thiscall asNetwork::Deallocate(void) | ?Deallocate@asNetwork@@QAEXXZ
    0x489470 | public: int __thiscall asNetwork::CreateInterface(void) | ?CreateInterface@asNetwork@@QAEHXZ
    0x489490 | public: int __thiscall asNetwork::GetNetworkCaps(void) | ?GetNetworkCaps@asNetwork@@QAEHXZ
    0x489520 | public: void __thiscall asNetwork::GetProtocols(void) | ?GetProtocols@asNetwork@@QAEXXZ
    0x489550 | public: int __thiscall asNetwork::SetProtocol(int,struct NETCOMMPACK *) | ?SetProtocol@asNetwork@@QAEHHPAUNETCOMMPACK@@@Z
    0x4898B0 | public: int __thiscall asNetwork::SetProtocol(int) | ?SetProtocol@asNetwork@@QAEHH@Z
    0x489910 | public: void __thiscall asNetwork::Disconnect(void) | ?Disconnect@asNetwork@@QAEXXZ
    0x489960 | public: char * __thiscall asNetwork::GetEnumProtocol(int) | ?GetEnumProtocol@asNetwork@@QAEPADH@Z
    0x489990 | public: int __thiscall asNetwork::GetNumProtocols(void) | ?GetNumProtocols@asNetwork@@QAEHXZ
    0x4899A0 | public: int __thiscall asNetwork::CreatePlayer(char *,void *,int) | ?CreatePlayer@asNetwork@@QAEHPADPAXH@Z
    0x489A60 | public: void __thiscall asNetwork::DestroyPlayer(void) | ?DestroyPlayer@asNetwork@@QAEXXZ
    0x489AA0 | public: int __thiscall asNetwork::GetPlayers(struct _GUID *) | ?GetPlayers@asNetwork@@QAEHPAU_GUID@@@Z
    0x489AD0 | public: char * __thiscall asNetwork::GetEnumPlayer(int) | ?GetEnumPlayer@asNetwork@@QAEPADH@Z
    0x489B00 | public: unsigned long __thiscall asNetwork::GetPlayerID(int) | ?GetPlayerID@asNetwork@@QAEKH@Z
    0x489B40 | public: int __thiscall asNetwork::GetNumPlayers(void) | ?GetNumPlayers@asNetwork@@QAEHXZ
    0x489C00 | public: char * __thiscall asNetwork::GetPlayerName(unsigned long) | ?GetPlayerName@asNetwork@@QAEPADK@Z
    0x489CC0 | public: int __thiscall asNetwork::GetPlayerName(unsigned long,char *) | ?GetPlayerName@asNetwork@@QAEHKPAD@Z
    0x489DA0 | public: void __thiscall asNetwork::SetPlayerData(unsigned long,void *,int) | ?SetPlayerData@asNetwork@@QAEXKPAXH@Z
    0x489E40 | public: int __thiscall asNetwork::GetEnumPlayerData(int,void *,int) | ?GetEnumPlayerData@asNetwork@@QAEHHPAXH@Z
    0x489F00 | public: int __thiscall asNetwork::GetPlayerData(unsigned long,void *,int) | ?GetPlayerData@asNetwork@@QAEHKPAXH@Z
    0x489FB0 | public: unsigned long __thiscall asNetwork::Ping(unsigned long) | ?Ping@asNetwork@@QAEKK@Z
    0x48A080 | public: int __thiscall asNetwork::CreateSession(char *,char *,int,struct NETSESSION_DESC *) | ?CreateSession@asNetwork@@QAEHPAD0HPAUNETSESSION_DESC@@@Z
    0x48A170 | public: int __thiscall asNetwork::JoinSession(char *,struct _GUID *,char *) | ?JoinSession@asNetwork@@QAEHPADPAU_GUID@@0@Z
    0x48A3A0 | public: void __thiscall asNetwork::CloseSession(void) | ?CloseSession@asNetwork@@QAEXXZ
    0x48A3E0 | public: char * __thiscall asNetwork::GetEnumSession(int) | ?GetEnumSession@asNetwork@@QAEPADH@Z
    0x48A410 | public: int __thiscall asNetwork::GetEnumSessionID(int) | ?GetEnumSessionID@asNetwork@@QAEHH@Z
    0x48A440 | public: int __thiscall asNetwork::GetNumSessions(void) | ?GetNumSessions@asNetwork@@QAEHXZ
    0x48A450 | public: void __thiscall asNetwork::SealSession(void) | ?SealSession@asNetwork@@QAEXXZ
    0x48A570 | public: void __thiscall asNetwork::UnSealSession(void) | ?UnSealSession@asNetwork@@QAEXXZ
    0x48A690 | public: void __thiscall asNetwork::GetSessionData(struct NETSESSION_DESC *) | ?GetSessionData@asNetwork@@QAEXPAUNETSESSION_DESC@@@Z
    0x48A750 | public: void __thiscall asNetwork::SetSessionData(struct NETSESSION_DESC *,char *) | ?SetSessionData@asNetwork@@QAEXPAUNETSESSION_DESC@@PAD@Z
    0x48A890 | public: int __thiscall asNetwork::GetSessionsSynch(int) | ?GetSessionsSynch@asNetwork@@QAEHH@Z
    0x48A940 | public: void __thiscall asNetwork::GetSessionsAsynch(void) | ?GetSessionsAsynch@asNetwork@@QAEXXZ
    0x48A9A0 | public: void __thiscall asNetwork::StopSessionsAsynch(void) | ?StopSessionsAsynch@asNetwork@@QAEXXZ
    0x48AA20 | public: int __thiscall asNetwork::PollLobby(void) | ?PollLobby@asNetwork@@QAEHXZ
    0x48AAC0 | public: int __thiscall asNetwork::Update(void) | ?Update@asNetwork@@QAEHXZ
    0x48ABC0 | public: void __thiscall asNetwork::HandleAppMessage(void *) | ?HandleAppMessage@asNetwork@@QAEXPAX@Z
    0x48ABE0 | public: void __thiscall asNetwork::HandleSysMessage(struct DPMSG_GENERIC *) | ?HandleSysMessage@asNetwork@@QAEXPAUDPMSG_GENERIC@@@Z
    0x48AE30 | public: void __thiscall asNetwork::ChatMessage(unsigned long,char *) | ?ChatMessage@asNetwork@@QAEXKPAD@Z
    0x48AEF0 | public: void __thiscall asNetwork::Send(unsigned long,void *,unsigned long,int) | ?Send@asNetwork@@QAEXKPAXKH@Z
    0x48AFC0 | public: int __thiscall asNetwork::GetMyLogicalIndex(void) | ?GetMyLogicalIndex@asNetwork@@QAEHXZ
    0x48B000 | public: int __thiscall asNetwork::GetGameVersion(int) | ?GetGameVersion@asNetwork@@QAEHH@Z
    0x48B030 | public: int __thiscall asNetwork::GetEnumSessionStatus(int) | ?GetEnumSessionStatus@asNetwork@@QAEHH@Z
    0x48B060 | public: int __thiscall asNetwork::GetEnumSessionLock(int) | ?GetEnumSessionLock@asNetwork@@QAEHH@Z
    0x48B090 | public: void __thiscall asNetwork::SetEnumSessionLock(int,int) | ?SetEnumSessionLock@asNetwork@@QAEXHH@Z
    0x48B0B0 | int __stdcall EnumSessionCallback(struct DPSESSIONDESC2 const *,unsigned long *,unsigned long,void *) | ?EnumSessionCallback@@YGHPBUDPSESSIONDESC2@@PAKKPAX@Z
    0x48B170 | int __stdcall EnumConnectionsCallback(struct _GUID const *,void *,unsigned long,struct DPNAME const *,unsigned long,void *) | ?EnumConnectionsCallback@@YGHPBU_GUID@@PAXKPBUDPNAME@@K1@Z
    0x48B1E0 | int __stdcall EnumPlayersCallback(unsigned long,unsigned long,struct DPNAME const *,unsigned long,void *) | ?EnumPlayersCallback@@YGHKKPBUDPNAME@@KPAX@Z
    0x48B240 | public: int __thiscall asNetwork::JoinSession(int,char *) | ?JoinSession@asNetwork@@QAEHHPAD@Z
    0x48B2C0 | public: int __thiscall asNetwork::GetNumModems(void) | ?GetNumModems@asNetwork@@QAEHXZ
    0x48B2D0 | public: char * __thiscall asNetwork::GetEnumModem(int) | ?GetEnumModem@asNetwork@@QAEPADH@Z
    0x48B300 | public: int __thiscall asNetwork::QueryModems(void) | ?QueryModems@asNetwork@@QAEHXZ
    0x48B430 | int __stdcall EnumModemAddress(struct _GUID const &,unsigned long,void const *,void *) | ?EnumModemAddress@@YGHABU_GUID@@KPBXPAX@Z
    0x61CB70 | _MM_GUID
    0x6A8918 | class asNetwork NETMGR | ?NETMGR@@3VasNetwork@@A
*/

class asNetwork
{
public:
    // 0x488FA0 | ??0asNetwork@@QAE@XZ
    ARTS_IMPORT asNetwork();

    // 0x489010 | ??1asNetwork@@QAE@XZ
    ARTS_IMPORT ~asNetwork();

    // 0x48AE30 | ?ChatMessage@asNetwork@@QAEXKPAD@Z | unused
    ARTS_IMPORT void ChatMessage(u32 arg1, char* arg2);

    // 0x48A3A0 | ?CloseSession@asNetwork@@QAEXXZ
    ARTS_IMPORT void CloseSession();

    // 0x489470 | ?CreateInterface@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 CreateInterface();

    // 0x4899A0 | ?CreatePlayer@asNetwork@@QAEHPADPAXH@Z
    ARTS_IMPORT i32 CreatePlayer(char* arg1, void* arg2, i32 arg3);

    // 0x48A080 | ?CreateSession@asNetwork@@QAEHPAD0HPAUNETSESSION_DESC@@@Z
    ARTS_IMPORT i32 CreateSession(char* arg1, char* arg2, i32 arg3, struct NETSESSION_DESC* arg4);

    // 0x489430 | ?Deallocate@asNetwork@@QAEXXZ
    ARTS_IMPORT void Deallocate();

    // 0x489A60 | ?DestroyPlayer@asNetwork@@QAEXXZ
    ARTS_IMPORT void DestroyPlayer();

    // 0x489910 | ?Disconnect@asNetwork@@QAEXXZ
    ARTS_IMPORT void Disconnect();

    // 0x48B2D0 | ?GetEnumModem@asNetwork@@QAEPADH@Z | unused
    ARTS_IMPORT char* GetEnumModem(i32 arg1);

    // 0x489AD0 | ?GetEnumPlayer@asNetwork@@QAEPADH@Z
    ARTS_IMPORT char* GetEnumPlayer(i32 arg1);

    // 0x489E40 | ?GetEnumPlayerData@asNetwork@@QAEHHPAXH@Z
    ARTS_IMPORT i32 GetEnumPlayerData(i32 arg1, void* arg2, i32 arg3);

    // 0x489960 | ?GetEnumProtocol@asNetwork@@QAEPADH@Z | unused
    ARTS_IMPORT char* GetEnumProtocol(i32 arg1);

    // 0x48A3E0 | ?GetEnumSession@asNetwork@@QAEPADH@Z
    ARTS_IMPORT char* GetEnumSession(i32 arg1);

    // 0x48A410 | ?GetEnumSessionID@asNetwork@@QAEHH@Z | unused
    ARTS_IMPORT i32 GetEnumSessionID(i32 arg1);

    // 0x48B060 | ?GetEnumSessionLock@asNetwork@@QAEHH@Z
    ARTS_IMPORT i32 GetEnumSessionLock(i32 arg1);

    // 0x48B030 | ?GetEnumSessionStatus@asNetwork@@QAEHH@Z | unused
    ARTS_IMPORT i32 GetEnumSessionStatus(i32 arg1);

    // 0x48B000 | ?GetGameVersion@asNetwork@@QAEHH@Z
    ARTS_IMPORT i32 GetGameVersion(i32 arg1);

    // 0x48AFC0 | ?GetMyLogicalIndex@asNetwork@@QAEHXZ | unused
    ARTS_IMPORT i32 GetMyLogicalIndex();

    // 0x489490 | ?GetNetworkCaps@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 GetNetworkCaps();

    // 0x48B2C0 | ?GetNumModems@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 GetNumModems();

    // 0x489B40 | ?GetNumPlayers@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 GetNumPlayers();

    // 0x489990 | ?GetNumProtocols@asNetwork@@QAEHXZ | unused
    ARTS_IMPORT i32 GetNumProtocols();

    // 0x48A440 | ?GetNumSessions@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 GetNumSessions();

    // 0x489F00 | ?GetPlayerData@asNetwork@@QAEHKPAXH@Z
    ARTS_IMPORT i32 GetPlayerData(u32 arg1, void* arg2, i32 arg3);

    // 0x489B00 | ?GetPlayerID@asNetwork@@QAEKH@Z
    ARTS_IMPORT u32 GetPlayerID(i32 arg1);

    // 0x489C00 | ?GetPlayerName@asNetwork@@QAEPADK@Z
    ARTS_IMPORT char* GetPlayerName(u32 arg1);

    // 0x489CC0 | ?GetPlayerName@asNetwork@@QAEHKPAD@Z
    ARTS_IMPORT i32 GetPlayerName(u32 arg1, char* arg2);

    // 0x489AA0 | ?GetPlayers@asNetwork@@QAEHPAU_GUID@@@Z
    ARTS_IMPORT i32 GetPlayers(struct _GUID* arg1);

    // 0x489520 | ?GetProtocols@asNetwork@@QAEXXZ
    ARTS_IMPORT void GetProtocols();

    // 0x48A690 | ?GetSessionData@asNetwork@@QAEXPAUNETSESSION_DESC@@@Z
    ARTS_IMPORT void GetSessionData(struct NETSESSION_DESC* arg1);

    // 0x48A940 | ?GetSessionsAsynch@asNetwork@@QAEXXZ
    ARTS_IMPORT void GetSessionsAsynch();

    // 0x48A890 | ?GetSessionsSynch@asNetwork@@QAEHH@Z
    ARTS_IMPORT i32 GetSessionsSynch(i32 arg1);

    // 0x48ABC0 | ?HandleAppMessage@asNetwork@@QAEXPAX@Z
    ARTS_IMPORT void HandleAppMessage(void* arg1);

    // 0x48ABE0 | ?HandleSysMessage@asNetwork@@QAEXPAUDPMSG_GENERIC@@@Z
    ARTS_IMPORT void HandleSysMessage(struct DPMSG_GENERIC* arg1);

    // 0x489020 | ?Initialize@asNetwork@@QAEHHHH@Z
    ARTS_IMPORT i32 Initialize(i32 arg1, i32 arg2, i32 arg3);

    // 0x489080 | ?InitializeLobby@asNetwork@@QAEHHH@Z
    ARTS_IMPORT i32 InitializeLobby(i32 arg1, i32 arg2);

    // 0x489150 | ?JoinLobbySession@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 JoinLobbySession();

    // 0x48B240 | ?JoinSession@asNetwork@@QAEHHPAD@Z
    ARTS_IMPORT i32 JoinSession(i32 arg1, char* arg2);

    // 0x48A170 | ?JoinSession@asNetwork@@QAEHPADPAU_GUID@@0@Z
    ARTS_IMPORT i32 JoinSession(char* arg1, struct _GUID* arg2, char* arg3);

    // 0x489360 | ?Logout@asNetwork@@QAEXXZ
    ARTS_IMPORT void Logout();

    // 0x489FB0 | ?Ping@asNetwork@@QAEKK@Z | unused
    ARTS_IMPORT u32 Ping(u32 arg1);

    // 0x48AA20 | ?PollLobby@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 PollLobby();

    // 0x48B300 | ?QueryModems@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 QueryModems();

    // 0x48A450 | ?SealSession@asNetwork@@QAEXXZ
    ARTS_IMPORT void SealSession();

    // 0x48AEF0 | ?Send@asNetwork@@QAEXKPAXKH@Z
    ARTS_IMPORT void Send(u32 arg1, void* arg2, u32 arg3, i32 arg4);

    // 0x489280 | ?SendLobbyProperty@asNetwork@@QAEXPAXH@Z | unused
    ARTS_IMPORT void SendLobbyProperty(void* arg1, i32 arg2);

    // 0x48B090 | ?SetEnumSessionLock@asNetwork@@QAEXHH@Z
    ARTS_IMPORT void SetEnumSessionLock(i32 arg1, i32 arg2);

    // 0x489DA0 | ?SetPlayerData@asNetwork@@QAEXKPAXH@Z
    ARTS_IMPORT void SetPlayerData(u32 arg1, void* arg2, i32 arg3);

    // 0x4898B0 | ?SetProtocol@asNetwork@@QAEHH@Z
    ARTS_IMPORT i32 SetProtocol(i32 arg1);

    // 0x489550 | ?SetProtocol@asNetwork@@QAEHHPAUNETCOMMPACK@@@Z
    ARTS_IMPORT i32 SetProtocol(i32 arg1, struct NETCOMMPACK* arg2);

    // 0x48A750 | ?SetSessionData@asNetwork@@QAEXPAUNETSESSION_DESC@@PAD@Z
    ARTS_IMPORT void SetSessionData(struct NETSESSION_DESC* arg1, char* arg2);

    // 0x48A9A0 | ?StopSessionsAsynch@asNetwork@@QAEXXZ
    ARTS_IMPORT void StopSessionsAsynch();

    // 0x48A570 | ?UnSealSession@asNetwork@@QAEXXZ
    ARTS_IMPORT void UnSealSession();

    // 0x48AAC0 | ?Update@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 Update();

    // 0x4890F0 | ?WaitForLobbyConnection@asNetwork@@QAEXH@Z
    ARTS_IMPORT void WaitForLobbyConnection(i32 arg1);
};

check_size(asNetwork, 0x64);

// 0x48B170 | ?EnumConnectionsCallback@@YGHPBU_GUID@@PAXKPBUDPNAME@@K1@Z
ARTS_IMPORT i32 ARTS_STDCALL EnumConnectionsCallback(
    struct _GUID const* arg1, void* arg2, u32 arg3, struct DPNAME const* arg4, u32 arg5, void* arg6);

// 0x48B430 | ?EnumModemAddress@@YGHABU_GUID@@KPBXPAX@Z
ARTS_IMPORT i32 ARTS_STDCALL EnumModemAddress(struct _GUID const& arg1, u32 arg2, void const* arg3, void* arg4);

// 0x48B1E0 | ?EnumPlayersCallback@@YGHKKPBUDPNAME@@KPAX@Z
ARTS_IMPORT i32 ARTS_STDCALL EnumPlayersCallback(u32 arg1, u32 arg2, struct DPNAME const* arg3, u32 arg4, void* arg5);

// 0x48B0B0 | ?EnumSessionCallback@@YGHPBUDPSESSIONDESC2@@PAKKPAX@Z
ARTS_IMPORT i32 ARTS_STDCALL EnumSessionCallback(struct DPSESSIONDESC2 const* arg1, u32* arg2, u32 arg3, void* arg4);

// 0x6A8918 | ?NETMGR@@3VasNetwork@@A
ARTS_IMPORT extern class asNetwork NETMGR;

// 0x61CB70 | _MM_GUID (Skipped: void)
