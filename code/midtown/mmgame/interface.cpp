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

define_dummy_symbol(mmgame_interface);

#include "interface.h"

void ReportTimeAlloc(f32 arg1)
{
    return stub<cdecl_t<void, f32>>(0x406A80, arg1);
}

mmInterface::mmInterface()
{
    unimplemented();
}

mmInterface::~mmInterface()
{
    unimplemented(arg1);
}

void mmInterface::BeDone()
{
    return stub<thiscall_t<void, mmInterface*>>(0x4087B0, this);
}

class MetaClass* mmInterface::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmInterface*>>(0x40E7D0, this);
}

void mmInterface::InitLobby()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CD10, this);
}

void mmInterface::InitPlayerInfo()
{
    return stub<thiscall_t<void, mmInterface*>>(0x407A90, this);
}

void mmInterface::LobbySwitch(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmInterface*, i32, i32>>(0x40AB70, this, arg1, arg2);
}

void mmInterface::MessageCallback(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmInterface*, void*, void*>>(0x407F70, this, arg1, arg2);
}

void mmInterface::MessageCallback2(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmInterface*, void*, void*>>(0x408440, this, arg1, arg2);
}

void mmInterface::Reset()
{
    return stub<thiscall_t<void, mmInterface*>>(0x408660, this);
}

void mmInterface::SetupArchiveTest(i32& arg1)
{
    return stub<thiscall_t<void, mmInterface*, i32&>>(0x40E3E0, this, arg1);
}

void mmInterface::ShowLockedVehicleMessage()
{
    return stub<thiscall_t<void, mmInterface*>>(0x408790, this);
}

void mmInterface::ShowMain(i32 arg1)
{
    return stub<thiscall_t<void, mmInterface*, i32>>(0x408670, this, arg1);
}

void mmInterface::Switch(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmInterface*, i32, i32>>(0x40A7D0, this, arg1, arg2);
}

void mmInterface::Update()
{
    return stub<thiscall_t<void, mmInterface*>>(0x4088A0, this);
}

void mmInterface::UpdateLobby()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40A1F0, this);
}

void mmInterface::DeclareFields()
{
    return stub<cdecl_t<void>>(0x40E660);
}

void mmInterface::ChangePlayerData()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40D8B0, this);
}

void mmInterface::CitySetupCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40B6D0, this);
}

void mmInterface::ClearSessions()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CFA0, this);
}

i32 mmInterface::CreatePlayer(i32 arg1)
{
    return stub<thiscall_t<i32, mmInterface*, i32>>(0x40D540, this, arg1);
}

i32 mmInterface::CreateSession()
{
    return stub<thiscall_t<i32, mmInterface*>>(0x40DC40, this);
}

void mmInterface::FillCRRoster()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40AD40, this);
}

i32 mmInterface::GetHostPlayerData(struct mmPlayerInfo& arg1)
{
    return stub<thiscall_t<i32, mmInterface*, struct mmPlayerInfo&>>(0x40D760, this, arg1);
}

char* mmInterface::GetRaceName(enum mmGameMode arg1, i32 arg2)
{
    return stub<thiscall_t<char*, mmInterface*, enum mmGameMode, i32>>(0x40B890, this, arg1, arg2);
}

void mmInterface::GetRaceString(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmInterface*, i32, char*>>(0x40B830, this, arg1, arg2);
}

void mmInterface::GetScoreString(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmInterface*, i32, char*>>(0x40B7F0, this, arg1, arg2);
}

void mmInterface::GetSessionData(struct NETSESSION_DESC arg1)
{
    return stub<thiscall_t<void, mmInterface*, struct NETSESSION_DESC>>(0x40DB80, this, arg1);
}

void mmInterface::GetTimeString(f32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmInterface*, f32, char*>>(0x40B790, this, arg1, arg2);
}

void mmInterface::GetUniquePlayerName()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40D7C0, this);
}

void mmInterface::GetUnlockedCar()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40AE40, this);
}

void mmInterface::InitNetwork()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CC20, this);
}

void mmInterface::InitProtocols()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CD80, this);
}

void mmInterface::JoinGame()
{
    return stub<thiscall_t<void, mmInterface*>>(0x409F90, this);
}

void mmInterface::JoinLAN()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40A010, this);
}

i32 mmInterface::JoinModem()
{
    return stub<thiscall_t<i32, mmInterface*>>(0x40A100, this);
}

i32 mmInterface::JoinPasswordSession(i32 arg1)
{
    return stub<thiscall_t<i32, mmInterface*, i32>>(0x40D200, this, arg1);
}

i32 mmInterface::JoinSerial()
{
    return stub<thiscall_t<i32, mmInterface*>>(0x40A070, this);
}

i32 mmInterface::JoinSession(i32 arg1)
{
    return stub<thiscall_t<i32, mmInterface*, i32>>(0x40D000, this, arg1);
}

void mmInterface::LobbyCreate()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40DEF0, this);
}

void mmInterface::MultiStartGame()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40D3B0, this);
}

void mmInterface::NetJoinCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x409F00, this);
}

void mmInterface::NetNameCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x409F60, this);
}

i32 mmInterface::PlayerCreate(char* arg1)
{
    return stub<thiscall_t<i32, mmInterface*, char*>>(0x40B200, this, arg1);
}

void mmInterface::PlayerCreateCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40B1B0, this);
}

void mmInterface::PlayerFillStats()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40C2E0, this);
}

void mmInterface::PlayerGraphicsCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40B3C0, this);
}

void mmInterface::PlayerLoad(char* arg1)
{
    return stub<thiscall_t<void, mmInterface*, char*>>(0x40B430, this, arg1);
}

void mmInterface::PlayerLoadCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40B390, this);
}

void mmInterface::PlayerReadState()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CB20, this);
}

void mmInterface::PlayerRemove(char* arg1)
{
    return stub<thiscall_t<void, mmInterface*, char*>>(0x40B020, this, arg1);
}

void mmInterface::PlayerRemoveCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40AFF0, this);
}

void mmInterface::PlayerResolveCars()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40C950, this);
}

void mmInterface::PlayerResolveScore()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40C810, this);
}

void mmInterface::PlayerSetState()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40B4E0, this);
}

void mmInterface::RaceFillRecords()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40B9F0, this);
}

void mmInterface::RefreshCRPlayers()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40ACA0, this);
}

void mmInterface::RefreshDriverList()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CB40, this);
}

void mmInterface::RefreshPlayers()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40D980, this);
}

void mmInterface::RefreshSessions()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CFC0, this);
}

void mmInterface::RequestProverb()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40AE90, this);
}

void mmInterface::SendBootMsg(u32 arg1)
{
    return stub<thiscall_t<void, mmInterface*, u32>>(0x40E330, this, arg1);
}

void mmInterface::SendChatMessage(void* arg1)
{
    return stub<thiscall_t<void, mmInterface*, void*>>(0x40E250, this, arg1);
}

void mmInterface::SendMsg(i32 arg1)
{
    return stub<thiscall_t<void, mmInterface*, i32>>(0x40E2F0, this, arg1);
}

void mmInterface::SendReadyReq()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40E3B0, this);
}

void mmInterface::SendReadyStatus()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40E370, this);
}

void mmInterface::SetCRStateData()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40DE80, this);
}

void mmInterface::SetProtocol()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40D440, this);
}

i32 mmInterface::SetProtocol2()
{
    return stub<thiscall_t<i32, mmInterface*>>(0x40D4F0, this);
}

void mmInterface::SetSessionData(struct NETSESSION_DESC* arg1)
{
    return stub<thiscall_t<void, mmInterface*, struct NETSESSION_DESC*>>(0x40DDC0, this, arg1);
}

void mmInterface::SetStateDefaults()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CC00, this);
}

void mmInterface::SetStateRace(i32 arg1)
{
    return stub<thiscall_t<void, mmInterface*, i32>>(0x40CBF0, this, arg1);
}

void mmInterface::ShowSessions()
{
    return stub<thiscall_t<void, mmInterface*>>(0x40CDA0, this);
}
