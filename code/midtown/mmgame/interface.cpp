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

#include "interface.h"

void ReportTimeAlloc(f32 arg1)
{
    return stub<cdecl_t<void, f32>>(0x6A80_Offset, arg1);
}

mmInterface::mmInterface()
{
    unimplemented();
}

mmInterface::~mmInterface()
{
    unimplemented();
}

void mmInterface::BeDone()
{
    return stub<thiscall_t<void, mmInterface*>>(0x87B0_Offset, this);
}

class MetaClass* mmInterface::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmInterface*>>(0xE7D0_Offset, this);
}

void mmInterface::InitLobby()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCD10_Offset, this);
}

void mmInterface::InitPlayerInfo()
{
    return stub<thiscall_t<void, mmInterface*>>(0x7A90_Offset, this);
}

void mmInterface::LobbySwitch(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmInterface*, i32, i32>>(0xAB70_Offset, this, arg1, arg2);
}

void mmInterface::MessageCallback(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmInterface*, void*, void*>>(0x7F70_Offset, this, arg1, arg2);
}

void mmInterface::MessageCallback2(void* arg1, void* arg2)
{
    return stub<thiscall_t<void, mmInterface*, void*, void*>>(0x8440_Offset, this, arg1, arg2);
}

void mmInterface::Reset()
{
    return stub<thiscall_t<void, mmInterface*>>(0x8660_Offset, this);
}

void mmInterface::SetupArchiveTest(i32& arg1)
{
    return stub<thiscall_t<void, mmInterface*, i32&>>(0xE3E0_Offset, this, arg1);
}

void mmInterface::ShowLockedVehicleMessage()
{
    return stub<thiscall_t<void, mmInterface*>>(0x8790_Offset, this);
}

void mmInterface::ShowMain(i32 arg1)
{
    return stub<thiscall_t<void, mmInterface*, i32>>(0x8670_Offset, this, arg1);
}

void mmInterface::Switch(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmInterface*, i32, i32>>(0xA7D0_Offset, this, arg1, arg2);
}

void mmInterface::Update()
{
    return stub<thiscall_t<void, mmInterface*>>(0x88A0_Offset, this);
}

void mmInterface::UpdateLobby()
{
    return stub<thiscall_t<void, mmInterface*>>(0xA1F0_Offset, this);
}

void mmInterface::DeclareFields()
{
    return stub<cdecl_t<void>>(0xE660_Offset);
}

void mmInterface::ChangePlayerData()
{
    return stub<thiscall_t<void, mmInterface*>>(0xD8B0_Offset, this);
}

void mmInterface::CitySetupCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0xB6D0_Offset, this);
}

void mmInterface::ClearSessions()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCFA0_Offset, this);
}

i32 mmInterface::CreatePlayer(i32 arg1)
{
    return stub<thiscall_t<i32, mmInterface*, i32>>(0xD540_Offset, this, arg1);
}

i32 mmInterface::CreateSession()
{
    return stub<thiscall_t<i32, mmInterface*>>(0xDC40_Offset, this);
}

void mmInterface::FillCRRoster()
{
    return stub<thiscall_t<void, mmInterface*>>(0xAD40_Offset, this);
}

i32 mmInterface::GetHostPlayerData(struct mmPlayerInfo& arg1)
{
    return stub<thiscall_t<i32, mmInterface*, struct mmPlayerInfo&>>(0xD760_Offset, this, arg1);
}

char* mmInterface::GetRaceName(enum mmGameMode arg1, i32 arg2)
{
    return stub<thiscall_t<char*, mmInterface*, enum mmGameMode, i32>>(0xB890_Offset, this, arg1, arg2);
}

void mmInterface::GetRaceString(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmInterface*, i32, char*>>(0xB830_Offset, this, arg1, arg2);
}

void mmInterface::GetScoreString(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmInterface*, i32, char*>>(0xB7F0_Offset, this, arg1, arg2);
}

void mmInterface::GetSessionData(struct NETSESSION_DESC arg1)
{
    return stub<thiscall_t<void, mmInterface*, struct NETSESSION_DESC>>(0xDB80_Offset, this, arg1);
}

void mmInterface::GetTimeString(f32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmInterface*, f32, char*>>(0xB790_Offset, this, arg1, arg2);
}

void mmInterface::GetUniquePlayerName()
{
    return stub<thiscall_t<void, mmInterface*>>(0xD7C0_Offset, this);
}

void mmInterface::GetUnlockedCar()
{
    return stub<thiscall_t<void, mmInterface*>>(0xAE40_Offset, this);
}

void mmInterface::InitNetwork()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCC20_Offset, this);
}

void mmInterface::InitProtocols()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCD80_Offset, this);
}

void mmInterface::JoinGame()
{
    return stub<thiscall_t<void, mmInterface*>>(0x9F90_Offset, this);
}

void mmInterface::JoinLAN()
{
    return stub<thiscall_t<void, mmInterface*>>(0xA010_Offset, this);
}

i32 mmInterface::JoinModem()
{
    return stub<thiscall_t<i32, mmInterface*>>(0xA100_Offset, this);
}

i32 mmInterface::JoinPasswordSession(i32 arg1)
{
    return stub<thiscall_t<i32, mmInterface*, i32>>(0xD200_Offset, this, arg1);
}

i32 mmInterface::JoinSerial()
{
    return stub<thiscall_t<i32, mmInterface*>>(0xA070_Offset, this);
}

i32 mmInterface::JoinSession(i32 arg1)
{
    return stub<thiscall_t<i32, mmInterface*, i32>>(0xD000_Offset, this, arg1);
}

void mmInterface::LobbyCreate()
{
    return stub<thiscall_t<void, mmInterface*>>(0xDEF0_Offset, this);
}

void mmInterface::MultiStartGame()
{
    return stub<thiscall_t<void, mmInterface*>>(0xD3B0_Offset, this);
}

void mmInterface::NetJoinCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x9F00_Offset, this);
}

void mmInterface::NetNameCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0x9F60_Offset, this);
}

i32 mmInterface::PlayerCreate(char* arg1)
{
    return stub<thiscall_t<i32, mmInterface*, char*>>(0xB200_Offset, this, arg1);
}

void mmInterface::PlayerCreateCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0xB1B0_Offset, this);
}

void mmInterface::PlayerFillStats()
{
    return stub<thiscall_t<void, mmInterface*>>(0xC2E0_Offset, this);
}

void mmInterface::PlayerGraphicsCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0xB3C0_Offset, this);
}

void mmInterface::PlayerLoad(char* arg1)
{
    return stub<thiscall_t<void, mmInterface*, char*>>(0xB430_Offset, this, arg1);
}

void mmInterface::PlayerLoadCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0xB390_Offset, this);
}

void mmInterface::PlayerReadState()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCB20_Offset, this);
}

void mmInterface::PlayerRemove(char* arg1)
{
    return stub<thiscall_t<void, mmInterface*, char*>>(0xB020_Offset, this, arg1);
}

void mmInterface::PlayerRemoveCB()
{
    return stub<thiscall_t<void, mmInterface*>>(0xAFF0_Offset, this);
}

void mmInterface::PlayerResolveCars()
{
    return stub<thiscall_t<void, mmInterface*>>(0xC950_Offset, this);
}

void mmInterface::PlayerResolveScore()
{
    return stub<thiscall_t<void, mmInterface*>>(0xC810_Offset, this);
}

void mmInterface::PlayerSetState()
{
    return stub<thiscall_t<void, mmInterface*>>(0xB4E0_Offset, this);
}

void mmInterface::RaceFillRecords()
{
    return stub<thiscall_t<void, mmInterface*>>(0xB9F0_Offset, this);
}

void mmInterface::RefreshCRPlayers()
{
    return stub<thiscall_t<void, mmInterface*>>(0xACA0_Offset, this);
}

void mmInterface::RefreshDriverList()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCB40_Offset, this);
}

void mmInterface::RefreshPlayers()
{
    return stub<thiscall_t<void, mmInterface*>>(0xD980_Offset, this);
}

void mmInterface::RefreshSessions()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCFC0_Offset, this);
}

void mmInterface::RequestProverb()
{
    return stub<thiscall_t<void, mmInterface*>>(0xAE90_Offset, this);
}

void mmInterface::SendBootMsg(u32 arg1)
{
    return stub<thiscall_t<void, mmInterface*, u32>>(0xE330_Offset, this, arg1);
}

void mmInterface::SendChatMessage(void* arg1)
{
    return stub<thiscall_t<void, mmInterface*, void*>>(0xE250_Offset, this, arg1);
}

void mmInterface::SendMsg(i32 arg1)
{
    return stub<thiscall_t<void, mmInterface*, i32>>(0xE2F0_Offset, this, arg1);
}

void mmInterface::SendReadyReq()
{
    return stub<thiscall_t<void, mmInterface*>>(0xE3B0_Offset, this);
}

void mmInterface::SendReadyStatus()
{
    return stub<thiscall_t<void, mmInterface*>>(0xE370_Offset, this);
}

void mmInterface::SetCRStateData()
{
    return stub<thiscall_t<void, mmInterface*>>(0xDE80_Offset, this);
}

void mmInterface::SetProtocol()
{
    return stub<thiscall_t<void, mmInterface*>>(0xD440_Offset, this);
}

i32 mmInterface::SetProtocol2()
{
    return stub<thiscall_t<i32, mmInterface*>>(0xD4F0_Offset, this);
}

void mmInterface::SetSessionData(struct NETSESSION_DESC* arg1)
{
    return stub<thiscall_t<void, mmInterface*, struct NETSESSION_DESC*>>(0xDDC0_Offset, this, arg1);
}

void mmInterface::SetStateDefaults()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCC00_Offset, this);
}

void mmInterface::SetStateRace(i32 arg1)
{
    return stub<thiscall_t<void, mmInterface*, i32>>(0xCBF0_Offset, this, arg1);
}

void mmInterface::ShowSessions()
{
    return stub<thiscall_t<void, mmInterface*>>(0xCDA0_Offset, this);
}

define_dummy_symbol(mmgame_interface);
