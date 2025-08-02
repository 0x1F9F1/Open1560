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

#include "data7/callback.h"

#include <dplobby.h>

struct NETSESSION_DESC
{
    i32 GameVersion; // = 5

    // TimeOfDay: 4
    // Weather: 4
    // EventId: 4
    // GameMode: 4
    i32 dword4;

    // DisableDamage: 1
    // Unused: 1
    // Difficulty: 2
    // NumLaps: 4
    //
    // if (EventId == 2)
    //   Limit: 2
    //   LimitMode: 2
    //   GoldMass: 2
    //   GameClass: 2
    // else
    //   TimeLimit: 8
    i32 dword8;

    // PedDensity: 8
    i32 dwordC;
};

struct NETCOMMPACK
{
    i32 dword0;
    i32 dword4;
    i32 dword8;
    i32 dwordC;
    i32 dword10;
    i32 dword14;
    char char18[40];
    char char40[40];
};

class asNetwork
{
public:
    // ??0asNetwork@@QAE@XZ
    ARTS_IMPORT asNetwork();

    // ??1asNetwork@@QAE@XZ
    ARTS_IMPORT ~asNetwork();

    // ?CloseSession@asNetwork@@QAEXXZ
    ARTS_IMPORT void CloseSession();

    // ?CreateInterface@asNetwork@@QAEHXZ
    ARTS_EXPORT i32 CreateInterface();

    // ?CreatePlayer@asNetwork@@QAEHPADPAXH@Z
    ARTS_IMPORT i32 CreatePlayer(char* arg1, void* arg2, i32 arg3);

    // ?CreateSession@asNetwork@@QAEHPAD0HPAUNETSESSION_DESC@@@Z
    ARTS_IMPORT i32 CreateSession(char* arg1, char* arg2, i32 arg3, NETSESSION_DESC* arg4);

    // ?Deallocate@asNetwork@@QAEXXZ
    ARTS_EXPORT void Deallocate();

    // ?DestroyPlayer@asNetwork@@QAEXXZ
    ARTS_EXPORT void DestroyPlayer();

    // ?Disconnect@asNetwork@@QAEXXZ
    ARTS_EXPORT void Disconnect();

    // ?GetEnumPlayer@asNetwork@@QAEPADH@Z
    ARTS_IMPORT char* GetEnumPlayer(i32 arg1);

    // ?GetEnumPlayerData@asNetwork@@QAEHHPAXH@Z
    ARTS_IMPORT i32 GetEnumPlayerData(i32 arg1, void* arg2, i32 arg3);

    // ?GetEnumSession@asNetwork@@QAEPADH@Z
    ARTS_IMPORT char* GetEnumSession(i32 arg1);

    // ?GetEnumSessionLock@asNetwork@@QAEHH@Z
    ARTS_IMPORT i32 GetEnumSessionLock(i32 arg1);

    // ?GetGameVersion@asNetwork@@QAEHH@Z
    ARTS_IMPORT i32 GetGameVersion(i32 arg1);

    // ?GetNetworkCaps@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 GetNetworkCaps();

    // ?GetNumModems@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 GetNumModems();

    // ?GetNumPlayers@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 GetNumPlayers();

    // ?GetNumSessions@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 GetNumSessions();

    // ?GetPlayerData@asNetwork@@QAEHKPAXH@Z
    ARTS_IMPORT i32 GetPlayerData(ulong arg1, void* arg2, i32 arg3);

    // ?GetPlayerID@asNetwork@@QAEKH@Z
    ARTS_IMPORT ulong GetPlayerID(i32 arg1);

    // ?GetPlayerName@asNetwork@@QAEPADK@Z
    ARTS_IMPORT char* GetPlayerName(ulong arg1);

    // ?GetPlayerName@asNetwork@@QAEHKPAD@Z
    ARTS_IMPORT i32 GetPlayerName(ulong arg1, char* arg2);

    // ?GetPlayers@asNetwork@@QAEHPAU_GUID@@@Z
    ARTS_IMPORT i32 GetPlayers(_GUID* arg1);

    // ?GetProtocols@asNetwork@@QAEXXZ
    ARTS_IMPORT void GetProtocols();

    // ?GetSessionData@asNetwork@@QAEXPAUNETSESSION_DESC@@@Z
    ARTS_IMPORT void GetSessionData(NETSESSION_DESC* arg1);

    // ?GetSessionsAsynch@asNetwork@@QAEXXZ
    ARTS_IMPORT void GetSessionsAsynch();

    // ?GetSessionsSynch@asNetwork@@QAEHH@Z
    ARTS_IMPORT i32 GetSessionsSynch(i32 arg1);

    // ?HandleAppMessage@asNetwork@@QAEXPAX@Z
    ARTS_IMPORT void HandleAppMessage(void* arg1);

    // ?HandleSysMessage@asNetwork@@QAEXPAUDPMSG_GENERIC@@@Z
    ARTS_IMPORT void HandleSysMessage(DPMSG_GENERIC* arg1);

    // ?Initialize@asNetwork@@QAEHHHH@Z
    ARTS_EXPORT b32 Initialize(i32 max_players, b32 secure, i32 game_version);

    // ?InitializeLobby@asNetwork@@QAEHHH@Z
    ARTS_EXPORT b32 InitializeLobby(i32 max_players, b32 secure);

    // ?JoinLobbySession@asNetwork@@QAEHXZ
    ARTS_EXPORT b32 JoinLobbySession();

    // ?JoinSession@asNetwork@@QAEHHPAD@Z
    ARTS_IMPORT i32 JoinSession(i32 arg1, char* arg2);

    // ?JoinSession@asNetwork@@QAEHPADPAU_GUID@@0@Z
    ARTS_IMPORT i32 JoinSession(char* arg1, _GUID* arg2, char* arg3);

    // ?Logout@asNetwork@@QAEXXZ
    ARTS_EXPORT void Logout();

    // ?PollLobby@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 PollLobby();

    // ?QueryModems@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 QueryModems();

    // ?SealSession@asNetwork@@QAEXXZ
    ARTS_IMPORT void SealSession();

    // ?Send@asNetwork@@QAEXKPAXKH@Z
    ARTS_IMPORT void Send(ulong arg1, void* arg2, ulong arg3, i32 arg4);

    // ?SetEnumSessionLock@asNetwork@@QAEXHH@Z
    ARTS_IMPORT void SetEnumSessionLock(i32 arg1, i32 arg2);

    // ?SetPlayerData@asNetwork@@QAEXKPAXH@Z
    ARTS_IMPORT void SetPlayerData(ulong arg1, void* arg2, i32 arg3);

    // ?SetProtocol@asNetwork@@QAEHH@Z
    ARTS_IMPORT i32 SetProtocol(i32 arg1);

    // ?SetProtocol@asNetwork@@QAEHHPAUNETCOMMPACK@@@Z
    ARTS_IMPORT i32 SetProtocol(i32 arg1, NETCOMMPACK* arg2);

    // ?SetSessionData@asNetwork@@QAEXPAUNETSESSION_DESC@@PAD@Z
    ARTS_EXPORT void SetSessionData(NETSESSION_DESC* desc, char* name);

    // ?StopSessionsAsynch@asNetwork@@QAEXXZ
    ARTS_IMPORT void StopSessionsAsynch();

    // ?UnSealSession@asNetwork@@QAEXXZ
    ARTS_IMPORT void UnSealSession();

    // ?Update@asNetwork@@QAEHXZ
    ARTS_IMPORT i32 Update();

    // ?WaitForLobbyConnection@asNetwork@@QAEXH@Z
    ARTS_IMPORT void WaitForLobbyConnection(i32 arg1);

    bool InSession() const
    {
        return in_session_;
    }

    bool InLobby() const
    {
        return in_lobby_;
    }

    bool IsHost() const
    {
        return is_host_;
    }

    void SetSysCallback(Callback cb)
    {
        sys_message_cb_ = cb;
    }

    void SetAppCallback(Callback cb)
    {
        app_message_cb_ = cb;
    }

private:
    i32 state_;
    Callback sys_message_cb_;
    Callback app_message_cb_;
    IDirectPlay4A* dplay_;
    IDirectPlayLobby3A* dp_lobby_;
    DPID player_id_;
    DPLCONNECTION* dp_connection_;
    GUID* app_guid_;
    DPMSG_GENERIC* recv_buffer_;
    i32 recv_buffer_size_;

    // 1549: 4
    // 1560: 5
    // 1588: 5
    // 1532 NET: 6
    // 1532 VW: 7
    // 1589: 10
    f32 game_version_;
    i32 max_players_;
    b32 in_session_;
    b32 in_lobby_;
    i32 secure_;
    i32 caps_;
    bool is_host_;
};

check_size(asNetwork, 0x64);

// ?EnumConnectionsCallback@@YGHPBU_GUID@@PAXKPBUDPNAME@@K1@Z
ARTS_IMPORT i32 ARTS_STDCALL EnumConnectionsCallback(
    const _GUID* arg1, void* arg2, ulong arg3, const DPNAME* arg4, ulong arg5, void* arg6);

// ?EnumModemAddress@@YGHABU_GUID@@KPBXPAX@Z
ARTS_IMPORT i32 ARTS_STDCALL EnumModemAddress(const _GUID& arg1, ulong arg2, const void* arg3, void* arg4);

// ?EnumPlayersCallback@@YGHKKPBUDPNAME@@KPAX@Z
ARTS_IMPORT i32 ARTS_STDCALL EnumPlayersCallback(ulong arg1, ulong arg2, const DPNAME* arg3, ulong arg4, void* arg5);

// ?EnumSessionCallback@@YGHPBUDPSESSIONDESC2@@PAKKPAX@Z
ARTS_IMPORT i32 ARTS_STDCALL EnumSessionCallback(const DPSESSIONDESC2* arg1, ulong* arg2, ulong arg3, void* arg4);

// ?NETMGR@@3VasNetwork@@A
ARTS_IMPORT extern asNetwork NETMGR;

// _MM_GUID | void
