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
    mmgame:interface

    0x406A80 | void __cdecl ReportTimeAlloc(float) | ?ReportTimeAlloc@@YAXM@Z
    0x406AC0 | public: __thiscall mmInterface::mmInterface(void) | ??0mmInterface@@QAE@XZ
    0x407A90 | public: void __thiscall mmInterface::InitPlayerInfo(void) | ?InitPlayerInfo@mmInterface@@QAEXXZ
    0x407E00 | public: virtual __thiscall mmInterface::~mmInterface(void) | ??1mmInterface@@UAE@XZ
    0x407F70 | public: void __thiscall mmInterface::MessageCallback(void *,void *) | ?MessageCallback@mmInterface@@QAEXPAX0@Z
    0x408440 | public: void __thiscall mmInterface::MessageCallback2(void *,void *) | ?MessageCallback2@mmInterface@@QAEXPAX0@Z
    0x408660 | public: virtual void __thiscall mmInterface::Reset(void) | ?Reset@mmInterface@@UAEXXZ
    0x408670 | public: void __thiscall mmInterface::ShowMain(int) | ?ShowMain@mmInterface@@QAEXH@Z
    0x408790 | public: void __thiscall mmInterface::ShowLockedVehicleMessage(void) | ?ShowLockedVehicleMessage@mmInterface@@QAEXXZ
    0x4087B0 | public: void __thiscall mmInterface::BeDone(void) | ?BeDone@mmInterface@@QAEXXZ
    0x4088A0 | public: virtual void __thiscall mmInterface::Update(void) | ?Update@mmInterface@@UAEXXZ
    0x409F00 | private: void __thiscall mmInterface::NetJoinCB(void) | ?NetJoinCB@mmInterface@@AAEXXZ
    0x409F60 | private: void __thiscall mmInterface::NetNameCB(void) | ?NetNameCB@mmInterface@@AAEXXZ
    0x409F90 | private: void __thiscall mmInterface::JoinGame(void) | ?JoinGame@mmInterface@@AAEXXZ
    0x40A010 | private: void __thiscall mmInterface::JoinLAN(void) | ?JoinLAN@mmInterface@@AAEXXZ
    0x40A070 | private: int __thiscall mmInterface::JoinSerial(void) | ?JoinSerial@mmInterface@@AAEHXZ
    0x40A100 | private: int __thiscall mmInterface::JoinModem(void) | ?JoinModem@mmInterface@@AAEHXZ
    0x40A1F0 | public: void __thiscall mmInterface::UpdateLobby(void) | ?UpdateLobby@mmInterface@@QAEXXZ
    0x40A7D0 | public: void __thiscall mmInterface::Switch(int,int) | ?Switch@mmInterface@@QAEXHH@Z
    0x40AB70 | public: void __thiscall mmInterface::LobbySwitch(int,int) | ?LobbySwitch@mmInterface@@QAEXHH@Z
    0x40ACA0 | private: void __thiscall mmInterface::RefreshCRPlayers(void) | ?RefreshCRPlayers@mmInterface@@AAEXXZ
    0x40AD40 | private: void __thiscall mmInterface::FillCRRoster(void) | ?FillCRRoster@mmInterface@@AAEXXZ
    0x40AE40 | private: void __thiscall mmInterface::GetUnlockedCar(void) | ?GetUnlockedCar@mmInterface@@AAEXXZ
    0x40AE90 | private: void __thiscall mmInterface::RequestProverb(void) | ?RequestProverb@mmInterface@@AAEXXZ
    0x40AFF0 | private: void __thiscall mmInterface::PlayerRemoveCB(void) | ?PlayerRemoveCB@mmInterface@@AAEXXZ
    0x40B020 | private: void __thiscall mmInterface::PlayerRemove(char *) | ?PlayerRemove@mmInterface@@AAEXPAD@Z
    0x40B1B0 | private: void __thiscall mmInterface::PlayerCreateCB(void) | ?PlayerCreateCB@mmInterface@@AAEXXZ
    0x40B200 | private: int __thiscall mmInterface::PlayerCreate(char *) | ?PlayerCreate@mmInterface@@AAEHPAD@Z
    0x40B390 | private: void __thiscall mmInterface::PlayerLoadCB(void) | ?PlayerLoadCB@mmInterface@@AAEXXZ
    0x40B3C0 | private: void __thiscall mmInterface::PlayerGraphicsCB(void) | ?PlayerGraphicsCB@mmInterface@@AAEXXZ
    0x40B430 | private: void __thiscall mmInterface::PlayerLoad(char *) | ?PlayerLoad@mmInterface@@AAEXPAD@Z
    0x40B4E0 | private: void __thiscall mmInterface::PlayerSetState(void) | ?PlayerSetState@mmInterface@@AAEXXZ
    0x40B6D0 | private: void __thiscall mmInterface::CitySetupCB(void) | ?CitySetupCB@mmInterface@@AAEXXZ
    0x40B790 | private: void __thiscall mmInterface::GetTimeString(float,char *) | ?GetTimeString@mmInterface@@AAEXMPAD@Z
    0x40B7F0 | private: void __thiscall mmInterface::GetScoreString(int,char *) | ?GetScoreString@mmInterface@@AAEXHPAD@Z
    0x40B830 | private: void __thiscall mmInterface::GetRaceString(int,char *) | ?GetRaceString@mmInterface@@AAEXHPAD@Z
    0x40B890 | private: char * __thiscall mmInterface::GetRaceName(enum mmGameMode,int) | ?GetRaceName@mmInterface@@AAEPADW4mmGameMode@@H@Z
    0x40B9F0 | private: void __thiscall mmInterface::RaceFillRecords(void) | ?RaceFillRecords@mmInterface@@AAEXXZ
    0x40C2E0 | private: void __thiscall mmInterface::PlayerFillStats(void) | ?PlayerFillStats@mmInterface@@AAEXXZ
    0x40C810 | private: void __thiscall mmInterface::PlayerResolveScore(void) | ?PlayerResolveScore@mmInterface@@AAEXXZ
    0x40C950 | private: void __thiscall mmInterface::PlayerResolveCars(void) | ?PlayerResolveCars@mmInterface@@AAEXXZ
    0x40CB20 | private: void __thiscall mmInterface::PlayerReadState(void) | ?PlayerReadState@mmInterface@@AAEXXZ
    0x40CB40 | private: void __thiscall mmInterface::RefreshDriverList(void) | ?RefreshDriverList@mmInterface@@AAEXXZ
    0x40CBF0 | private: void __thiscall mmInterface::SetStateRace(int) | ?SetStateRace@mmInterface@@AAEXH@Z
    0x40CC00 | private: void __thiscall mmInterface::SetStateDefaults(void) | ?SetStateDefaults@mmInterface@@AAEXXZ
    0x40CC20 | private: void __thiscall mmInterface::InitNetwork(void) | ?InitNetwork@mmInterface@@AAEXXZ
    0x40CD10 | public: void __thiscall mmInterface::InitLobby(void) | ?InitLobby@mmInterface@@QAEXXZ
    0x40CD80 | private: void __thiscall mmInterface::InitProtocols(void) | ?InitProtocols@mmInterface@@AAEXXZ
    0x40CDA0 | private: void __thiscall mmInterface::ShowSessions(void) | ?ShowSessions@mmInterface@@AAEXXZ
    0x40CFA0 | private: void __thiscall mmInterface::ClearSessions(void) | ?ClearSessions@mmInterface@@AAEXXZ
    0x40CFC0 | private: void __thiscall mmInterface::RefreshSessions(void) | ?RefreshSessions@mmInterface@@AAEXXZ
    0x40D000 | private: int __thiscall mmInterface::JoinSession(int) | ?JoinSession@mmInterface@@AAEHH@Z
    0x40D200 | private: int __thiscall mmInterface::JoinPasswordSession(int) | ?JoinPasswordSession@mmInterface@@AAEHH@Z
    0x40D3B0 | private: void __thiscall mmInterface::MultiStartGame(void) | ?MultiStartGame@mmInterface@@AAEXXZ
    0x40D440 | private: void __thiscall mmInterface::SetProtocol(void) | ?SetProtocol@mmInterface@@AAEXXZ
    0x40D4F0 | private: int __thiscall mmInterface::SetProtocol2(void) | ?SetProtocol2@mmInterface@@AAEHXZ
    0x40D540 | private: int __thiscall mmInterface::CreatePlayer(int) | ?CreatePlayer@mmInterface@@AAEHH@Z
    0x40D760 | private: int __thiscall mmInterface::GetHostPlayerData(struct mmPlayerInfo &) | ?GetHostPlayerData@mmInterface@@AAEHAAUmmPlayerInfo@@@Z
    0x40D7C0 | private: void __thiscall mmInterface::GetUniquePlayerName(void) | ?GetUniquePlayerName@mmInterface@@AAEXXZ
    0x40D8B0 | private: void __thiscall mmInterface::ChangePlayerData(void) | ?ChangePlayerData@mmInterface@@AAEXXZ
    0x40D980 | private: void __thiscall mmInterface::RefreshPlayers(void) | ?RefreshPlayers@mmInterface@@AAEXXZ
    0x40DB80 | private: void __thiscall mmInterface::GetSessionData(struct NETSESSION_DESC) | ?GetSessionData@mmInterface@@AAEXUNETSESSION_DESC@@@Z
    0x40DC40 | private: int __thiscall mmInterface::CreateSession(void) | ?CreateSession@mmInterface@@AAEHXZ
    0x40DDC0 | private: void __thiscall mmInterface::SetSessionData(struct NETSESSION_DESC *) | ?SetSessionData@mmInterface@@AAEXPAUNETSESSION_DESC@@@Z
    0x40DE80 | private: void __thiscall mmInterface::SetCRStateData(void) | ?SetCRStateData@mmInterface@@AAEXXZ
    0x40DEF0 | private: void __thiscall mmInterface::LobbyCreate(void) | ?LobbyCreate@mmInterface@@AAEXXZ
    0x40E250 | private: void __thiscall mmInterface::SendChatMessage(void *) | ?SendChatMessage@mmInterface@@AAEXPAX@Z
    0x40E2F0 | private: void __thiscall mmInterface::SendMsg(int) | ?SendMsg@mmInterface@@AAEXH@Z
    0x40E330 | private: void __thiscall mmInterface::SendBootMsg(unsigned long) | ?SendBootMsg@mmInterface@@AAEXK@Z
    0x40E370 | private: void __thiscall mmInterface::SendReadyStatus(void) | ?SendReadyStatus@mmInterface@@AAEXXZ
    0x40E3B0 | private: void __thiscall mmInterface::SendReadyReq(void) | ?SendReadyReq@mmInterface@@AAEXXZ
    0x40E3E0 | public: void __thiscall mmInterface::SetupArchiveTest(int &) | ?SetupArchiveTest@mmInterface@@QAEXAAH@Z
    0x40E660 | public: static void __cdecl mmInterface::DeclareFields(void) | ?DeclareFields@mmInterface@@SAXXZ
    0x40E7D0 | public: virtual class MetaClass * __thiscall mmInterface::GetClass(void) | ?GetClass@mmInterface@@UAEPAVMetaClass@@XZ
    0x40E7E0 | public: __thiscall string::~string(void) | ??1string@@QAE@XZ
    0x40E7F0 | public: virtual void * __thiscall mmInterface::`vector deleting destructor'(unsigned int) | ??_EmmInterface@@UAEPAXI@Z
    0x61A2C8 | const mmInterface::`vftable' | ??_7mmInterface@@6B@
    0x6A6E18 | class MetaClass mmInterfaceMetaClass | ?mmInterfaceMetaClass@@3VMetaClass@@A
    0x6A6E40 | char * szSearchPath | ?szSearchPath@@3PADA
    0x6A6EC8 | char * defcarname | ?defcarname@@3PADA
*/

#include "arts7/node.h"

// 0x406A80 | ?ReportTimeAlloc@@YAXM@Z
void ReportTimeAlloc(f32 arg1);

// 0x6A6EC8 | ?defcarname@@3PADA
inline extern_var(0x6A6EC8, char*, defcarname);

// 0x6A6E18 | ?mmInterfaceMetaClass@@3VMetaClass@@A
inline extern_var(0x6A6E18, class MetaClass, mmInterfaceMetaClass);

// 0x6A6E40 | ?szSearchPath@@3PADA
inline extern_var(0x6A6E40, char*, szSearchPath);

class mmInterface : public asNode
{
    // const mmInterface::`vftable' @ 0x61A2C8

public:
    // 0x406AC0 | ??0mmInterface@@QAE@XZ
    mmInterface();

    // 0x40E7F0 | ??_EmmInterface@@UAEPAXI@Z
    // 0x407E00 | ??1mmInterface@@UAE@XZ
    ~mmInterface() override;

    // 0x4087B0 | ?BeDone@mmInterface@@QAEXXZ
    void BeDone();

    // 0x40E7D0 | ?GetClass@mmInterface@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x40CD10 | ?InitLobby@mmInterface@@QAEXXZ
    void InitLobby();

    // 0x407A90 | ?InitPlayerInfo@mmInterface@@QAEXXZ
    void InitPlayerInfo();

    // 0x40AB70 | ?LobbySwitch@mmInterface@@QAEXHH@Z
    void LobbySwitch(i32 arg1, i32 arg2);

    // 0x407F70 | ?MessageCallback@mmInterface@@QAEXPAX0@Z
    void MessageCallback(void* arg1, void* arg2);

    // 0x408440 | ?MessageCallback2@mmInterface@@QAEXPAX0@Z
    void MessageCallback2(void* arg1, void* arg2);

    // 0x408660 | ?Reset@mmInterface@@UAEXXZ
    void Reset() override;

    // 0x40E3E0 | ?SetupArchiveTest@mmInterface@@QAEXAAH@Z
    void SetupArchiveTest(i32& arg1);

    // 0x408790 | ?ShowLockedVehicleMessage@mmInterface@@QAEXXZ
    void ShowLockedVehicleMessage();

    // 0x408670 | ?ShowMain@mmInterface@@QAEXH@Z
    void ShowMain(i32 arg1);

    // 0x40A7D0 | ?Switch@mmInterface@@QAEXHH@Z
    void Switch(i32 arg1, i32 arg2);

    // 0x4088A0 | ?Update@mmInterface@@UAEXXZ
    void Update() override;

    // 0x40A1F0 | ?UpdateLobby@mmInterface@@QAEXXZ
    void UpdateLobby();

    // 0x40E660 | ?DeclareFields@mmInterface@@SAXXZ
    static void DeclareFields();

private:
    // 0x40D8B0 | ?ChangePlayerData@mmInterface@@AAEXXZ
    void ChangePlayerData();

    // 0x40B6D0 | ?CitySetupCB@mmInterface@@AAEXXZ
    void CitySetupCB();

    // 0x40CFA0 | ?ClearSessions@mmInterface@@AAEXXZ
    void ClearSessions();

    // 0x40D540 | ?CreatePlayer@mmInterface@@AAEHH@Z
    i32 CreatePlayer(i32 arg1);

    // 0x40DC40 | ?CreateSession@mmInterface@@AAEHXZ
    i32 CreateSession();

    // 0x40AD40 | ?FillCRRoster@mmInterface@@AAEXXZ
    void FillCRRoster();

    // 0x40D760 | ?GetHostPlayerData@mmInterface@@AAEHAAUmmPlayerInfo@@@Z
    i32 GetHostPlayerData(struct mmPlayerInfo& arg1);

    // 0x40B890 | ?GetRaceName@mmInterface@@AAEPADW4mmGameMode@@H@Z
    char* GetRaceName(enum mmGameMode arg1, i32 arg2);

    // 0x40B830 | ?GetRaceString@mmInterface@@AAEXHPAD@Z
    void GetRaceString(i32 arg1, char* arg2);

    // 0x40B7F0 | ?GetScoreString@mmInterface@@AAEXHPAD@Z
    void GetScoreString(i32 arg1, char* arg2);

    // 0x40DB80 | ?GetSessionData@mmInterface@@AAEXUNETSESSION_DESC@@@Z
    void GetSessionData(struct NETSESSION_DESC arg1);

    // 0x40B790 | ?GetTimeString@mmInterface@@AAEXMPAD@Z
    void GetTimeString(f32 arg1, char* arg2);

    // 0x40D7C0 | ?GetUniquePlayerName@mmInterface@@AAEXXZ
    void GetUniquePlayerName();

    // 0x40AE40 | ?GetUnlockedCar@mmInterface@@AAEXXZ
    void GetUnlockedCar();

    // 0x40CC20 | ?InitNetwork@mmInterface@@AAEXXZ
    void InitNetwork();

    // 0x40CD80 | ?InitProtocols@mmInterface@@AAEXXZ
    void InitProtocols();

    // 0x409F90 | ?JoinGame@mmInterface@@AAEXXZ
    void JoinGame();

    // 0x40A010 | ?JoinLAN@mmInterface@@AAEXXZ
    void JoinLAN();

    // 0x40A100 | ?JoinModem@mmInterface@@AAEHXZ
    i32 JoinModem();

    // 0x40D200 | ?JoinPasswordSession@mmInterface@@AAEHH@Z
    i32 JoinPasswordSession(i32 arg1);

    // 0x40A070 | ?JoinSerial@mmInterface@@AAEHXZ
    i32 JoinSerial();

    // 0x40D000 | ?JoinSession@mmInterface@@AAEHH@Z
    i32 JoinSession(i32 arg1);

    // 0x40DEF0 | ?LobbyCreate@mmInterface@@AAEXXZ
    void LobbyCreate();

    // 0x40D3B0 | ?MultiStartGame@mmInterface@@AAEXXZ
    void MultiStartGame();

    // 0x409F00 | ?NetJoinCB@mmInterface@@AAEXXZ
    void NetJoinCB();

    // 0x409F60 | ?NetNameCB@mmInterface@@AAEXXZ
    void NetNameCB();

    // 0x40B200 | ?PlayerCreate@mmInterface@@AAEHPAD@Z
    i32 PlayerCreate(char* arg1);

    // 0x40B1B0 | ?PlayerCreateCB@mmInterface@@AAEXXZ
    void PlayerCreateCB();

    // 0x40C2E0 | ?PlayerFillStats@mmInterface@@AAEXXZ
    void PlayerFillStats();

    // 0x40B3C0 | ?PlayerGraphicsCB@mmInterface@@AAEXXZ
    void PlayerGraphicsCB();

    // 0x40B430 | ?PlayerLoad@mmInterface@@AAEXPAD@Z
    void PlayerLoad(char* arg1);

    // 0x40B390 | ?PlayerLoadCB@mmInterface@@AAEXXZ
    void PlayerLoadCB();

    // 0x40CB20 | ?PlayerReadState@mmInterface@@AAEXXZ
    void PlayerReadState();

    // 0x40B020 | ?PlayerRemove@mmInterface@@AAEXPAD@Z
    void PlayerRemove(char* arg1);

    // 0x40AFF0 | ?PlayerRemoveCB@mmInterface@@AAEXXZ
    void PlayerRemoveCB();

    // 0x40C950 | ?PlayerResolveCars@mmInterface@@AAEXXZ
    void PlayerResolveCars();

    // 0x40C810 | ?PlayerResolveScore@mmInterface@@AAEXXZ
    void PlayerResolveScore();

    // 0x40B4E0 | ?PlayerSetState@mmInterface@@AAEXXZ
    void PlayerSetState();

    // 0x40B9F0 | ?RaceFillRecords@mmInterface@@AAEXXZ
    void RaceFillRecords();

    // 0x40ACA0 | ?RefreshCRPlayers@mmInterface@@AAEXXZ
    void RefreshCRPlayers();

    // 0x40CB40 | ?RefreshDriverList@mmInterface@@AAEXXZ
    void RefreshDriverList();

    // 0x40D980 | ?RefreshPlayers@mmInterface@@AAEXXZ
    void RefreshPlayers();

    // 0x40CFC0 | ?RefreshSessions@mmInterface@@AAEXXZ
    void RefreshSessions();

    // 0x40AE90 | ?RequestProverb@mmInterface@@AAEXXZ
    void RequestProverb();

    // 0x40E330 | ?SendBootMsg@mmInterface@@AAEXK@Z
    void SendBootMsg(u32 arg1);

    // 0x40E250 | ?SendChatMessage@mmInterface@@AAEXPAX@Z
    void SendChatMessage(void* arg1);

    // 0x40E2F0 | ?SendMsg@mmInterface@@AAEXH@Z
    void SendMsg(i32 arg1);

    // 0x40E3B0 | ?SendReadyReq@mmInterface@@AAEXXZ
    void SendReadyReq();

    // 0x40E370 | ?SendReadyStatus@mmInterface@@AAEXXZ
    void SendReadyStatus();

    // 0x40DE80 | ?SetCRStateData@mmInterface@@AAEXXZ
    void SetCRStateData();

    // 0x40D440 | ?SetProtocol@mmInterface@@AAEXXZ
    void SetProtocol();

    // 0x40D4F0 | ?SetProtocol2@mmInterface@@AAEHXZ
    i32 SetProtocol2();

    // 0x40DDC0 | ?SetSessionData@mmInterface@@AAEXPAUNETSESSION_DESC@@@Z
    void SetSessionData(struct NETSESSION_DESC* arg1);

    // 0x40CC00 | ?SetStateDefaults@mmInterface@@AAEXXZ
    void SetStateDefaults();

    // 0x40CBF0 | ?SetStateRace@mmInterface@@AAEXH@Z
    void SetStateRace(i32 arg1);

    // 0x40CDA0 | ?ShowSessions@mmInterface@@AAEXXZ
    void ShowSessions();
};

check_size(mmInterface, 0x35830);
