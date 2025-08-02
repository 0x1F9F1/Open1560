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

#include "arts7/node.h"

#include "agiworld/texsort.h"
#include "mmcityinfo/miscdata.h"
#include "mmcityinfo/playercfg.h"
#include "mmcityinfo/playerdir.h"

struct mmPlayerInfo;
struct NETSESSION_DESC;

class AboutMenu;
class AudioOptions;
class ControlSetup;
class CRSettings;
class Dialog_City;
class Dialog_ControlAssign;
class Dialog_DriverRec;
class Dialog_HallOfFame;
class Dialog_Message;
class Dialog_NewPlayer;
class Dialog_Password;
class Dialog_RaceEnvironment;
class Dialog_Serial;
class Dialog_TCPIP;
class DriverMenu;
class GraphicsOptions;
class HostRaceMenu;
class MainMenu;
class NetArena;
class NetSelectMenu;
class OptionsMenu;
class RaceMenu;
class Vehicle;
class VehShowcase;

enum class mmGameMode : i32;

// ?ReportTimeAlloc@@YAXM@Z
ARTS_EXPORT void ReportTimeAlloc(f32 time);

// ?defcarname@@3PADA
ARTS_IMPORT extern char defcarname[80];

// ?szSearchPath@@3PADA
ARTS_IMPORT extern char szSearchPath[128];

class mmInterface final : public asNode
{
public:
    // ??0mmInterface@@QAE@XZ
    ARTS_IMPORT mmInterface();

    // ??_EmmInterface@@UAEPAXI@Z
    // ??1mmInterface@@UAE@XZ
    ARTS_EXPORT ~mmInterface() override;

    // ?BeDone@mmInterface@@QAEXXZ
    ARTS_IMPORT void BeDone();

    // ?GetClass@mmInterface@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?InitLobby@mmInterface@@QAEXXZ
    ARTS_EXPORT void InitLobby();

    // ?InitPlayerInfo@mmInterface@@QAEXXZ
    ARTS_IMPORT void InitPlayerInfo();

    // ?LobbySwitch@mmInterface@@QAEXHH@Z
    ARTS_IMPORT void LobbySwitch(i32 arg1, i32 arg2);

    // ?MessageCallback@mmInterface@@QAEXPAX0@Z
    ARTS_IMPORT void MessageCallback(void* arg1, void* arg2);

    // ?MessageCallback2@mmInterface@@QAEXPAX0@Z
    ARTS_IMPORT void MessageCallback2(void* arg1, void* arg2);

    // ?Reset@mmInterface@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetupArchiveTest@mmInterface@@QAEXAAH@Z
    ARTS_IMPORT void SetupArchiveTest(i32& arg1);

    // ?ShowLockedVehicleMessage@mmInterface@@QAEXXZ
    ARTS_IMPORT void ShowLockedVehicleMessage();

    // ?ShowMain@mmInterface@@QAEXH@Z
    ARTS_IMPORT void ShowMain(i32 arg1);

    // ?Switch@mmInterface@@QAEXHH@Z
    ARTS_IMPORT void Switch(i32 arg1, i32 arg2);

    // ?Update@mmInterface@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateLobby@mmInterface@@QAEXXZ
    ARTS_IMPORT void UpdateLobby();

    // ?DeclareFields@mmInterface@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    MainMenu* MenuMain;
    DriverMenu* MenuDriver;
    RaceMenu* MenuRace;
    Dialog_City* DlgCity;
    Vehicle* MenuVehicle;
    VehShowcase* MenuVehShowcase;
    NetSelectMenu* MenuNetSelect;
    AboutMenu* MenuAbout;
    OptionsMenu* MenuOptions;
    GraphicsOptions* MenuGraphicsOptions;
    AudioOptions* MenuAudioOptions;
    ControlSetup* MenuControlSetup;
    HostRaceMenu* MenuHostRace;
    NetArena* MenuNetArena;
    CRSettings* MenuCRSettings;
    u32 PlayerIDs[8];
    i32 LobbyStatus;
    Dialog_TCPIP* DlgTCPIP;
    Dialog_ControlAssign* DlgControlAssign;
    Dialog_Serial* DlgSerial;
    Dialog_NewPlayer* DlgNewPlayer;
    Dialog_DriverRec* DlgDriverRec;
    Dialog_HallOfFame* DlgHallOfFame;
    Dialog_RaceEnvironment* DlgRaceEnvironment;
    Dialog_Password* DlgPassword;
    Dialog_Message* DlgLocked;
    Dialog_Message* DlgBadPass;
    Dialog_Message* DlgQuit;
    Dialog_Message* DlgDelete;
    Dialog_Message* DlgRetreive;
    Dialog_Message* DlgAlreadyExists;
    Dialog_Message* DlgLastPlayer;
    Dialog_Message* DlgOriginalSettings;
    Dialog_Message* DlgZone;
    Dialog_Message* DlgCannotAssign;
    Dialog_Message* DlgPlayerLimit;
    mmPlayerDirectory PlayerDir;
    mmPlayerConfig PlayerCfg;
    mmMiscData AmateurData;
    mmMiscData ProData;
    i32 CheckpointScore;
    i32 CircuitScore;
    i32 BlitzScore;
    i32 CheckpointsWon;
    i32 CircuitsWon;
    i32 BlitzWon;
    i32 field_35788;
    i32 field_3578C;
    u8 gap35790[4];
    i32 NeedsRefresh;
    u8 gap35798[16];
    agiTexSorter TexSorter;
    char JoinOrHostGame[128];

private:
    // ?ChangePlayerData@mmInterface@@AAEXXZ
    ARTS_IMPORT void ChangePlayerData();

    // ?CitySetupCB@mmInterface@@AAEXXZ
    ARTS_IMPORT void CitySetupCB();

    // ?ClearSessions@mmInterface@@AAEXXZ
    ARTS_IMPORT void ClearSessions();

    // ?CreatePlayer@mmInterface@@AAEHH@Z
    ARTS_IMPORT i32 CreatePlayer(i32 arg1);

    // ?CreateSession@mmInterface@@AAEHXZ
    ARTS_IMPORT i32 CreateSession();

    // ?FillCRRoster@mmInterface@@AAEXXZ
    ARTS_IMPORT void FillCRRoster();

    // ?GetHostPlayerData@mmInterface@@AAEHAAUmmPlayerInfo@@@Z
    ARTS_IMPORT i32 GetHostPlayerData(mmPlayerInfo& arg1);

    // ?GetRaceName@mmInterface@@AAEPADW4mmGameMode@@H@Z
    ARTS_IMPORT char* GetRaceName(mmGameMode arg1, i32 arg2);

    // ?GetRaceString@mmInterface@@AAEXHPAD@Z
    ARTS_IMPORT void GetRaceString(i32 arg1, char* arg2);

    // ?GetScoreString@mmInterface@@AAEXHPAD@Z
    ARTS_IMPORT void GetScoreString(i32 arg1, char* arg2);

    // ?GetSessionData@mmInterface@@AAEXUNETSESSION_DESC@@@Z
    ARTS_IMPORT void GetSessionData(NETSESSION_DESC arg1);

    // ?GetTimeString@mmInterface@@AAEXMPAD@Z
    ARTS_IMPORT void GetTimeString(f32 arg1, char* arg2);

    // ?GetUniquePlayerName@mmInterface@@AAEXXZ
    ARTS_IMPORT void GetUniquePlayerName();

    // ?GetUnlockedCar@mmInterface@@AAEXXZ
    ARTS_IMPORT void GetUnlockedCar();

    // ?InitNetwork@mmInterface@@AAEXXZ
    ARTS_IMPORT void InitNetwork();

    // ?InitProtocols@mmInterface@@AAEXXZ
    ARTS_IMPORT void InitProtocols();

    // ?JoinGame@mmInterface@@AAEXXZ
    ARTS_IMPORT void JoinGame();

    // ?JoinLAN@mmInterface@@AAEXXZ
    ARTS_IMPORT void JoinLAN();

    // ?JoinModem@mmInterface@@AAEHXZ
    ARTS_IMPORT i32 JoinModem();

    // ?JoinPasswordSession@mmInterface@@AAEHH@Z
    ARTS_IMPORT i32 JoinPasswordSession(i32 arg1);

    // ?JoinSerial@mmInterface@@AAEHXZ
    ARTS_IMPORT i32 JoinSerial();

    // ?JoinSession@mmInterface@@AAEHH@Z
    ARTS_IMPORT i32 JoinSession(i32 arg1);

    // ?LobbyCreate@mmInterface@@AAEXXZ
    ARTS_IMPORT void LobbyCreate();

    // ?MultiStartGame@mmInterface@@AAEXXZ
    ARTS_IMPORT void MultiStartGame();

    // ?NetJoinCB@mmInterface@@AAEXXZ
    ARTS_IMPORT void NetJoinCB();

    // ?NetNameCB@mmInterface@@AAEXXZ
    ARTS_IMPORT void NetNameCB();

    // ?PlayerCreate@mmInterface@@AAEHPAD@Z
    ARTS_IMPORT i32 PlayerCreate(char* arg1);

    // ?PlayerCreateCB@mmInterface@@AAEXXZ
    ARTS_IMPORT void PlayerCreateCB();

    // ?PlayerFillStats@mmInterface@@AAEXXZ
    ARTS_IMPORT void PlayerFillStats();

    // ?PlayerGraphicsCB@mmInterface@@AAEXXZ
    ARTS_IMPORT void PlayerGraphicsCB();

    // ?PlayerLoad@mmInterface@@AAEXPAD@Z
    ARTS_IMPORT void PlayerLoad(char* arg1);

    // ?PlayerLoadCB@mmInterface@@AAEXXZ
    ARTS_IMPORT void PlayerLoadCB();

    // ?PlayerReadState@mmInterface@@AAEXXZ
    ARTS_IMPORT void PlayerReadState();

    // ?PlayerRemove@mmInterface@@AAEXPAD@Z
    ARTS_IMPORT void PlayerRemove(char* arg1);

    // ?PlayerRemoveCB@mmInterface@@AAEXXZ
    ARTS_IMPORT void PlayerRemoveCB();

    // ?PlayerResolveCars@mmInterface@@AAEXXZ
    ARTS_EXPORT void PlayerResolveCars();

    // ?PlayerResolveScore@mmInterface@@AAEXXZ
    ARTS_IMPORT void PlayerResolveScore();

    // ?PlayerSetState@mmInterface@@AAEXXZ
    ARTS_IMPORT void PlayerSetState();

    // ?RaceFillRecords@mmInterface@@AAEXXZ
    ARTS_IMPORT void RaceFillRecords();

    // ?RefreshCRPlayers@mmInterface@@AAEXXZ
    ARTS_IMPORT void RefreshCRPlayers();

    // ?RefreshDriverList@mmInterface@@AAEXXZ
    ARTS_IMPORT void RefreshDriverList();

    // ?RefreshPlayers@mmInterface@@AAEXXZ
    ARTS_IMPORT void RefreshPlayers();

    // ?RefreshSessions@mmInterface@@AAEXXZ
    ARTS_IMPORT void RefreshSessions();

    // ?RequestProverb@mmInterface@@AAEXXZ
    ARTS_IMPORT void RequestProverb();

    // ?SendChatMessage@mmInterface@@AAEXPAX@Z
    ARTS_IMPORT void SendChatMessage(void* arg1);

    // ?SendMsg@mmInterface@@AAEXH@Z
    ARTS_IMPORT void SendMsg(i32 arg1);

    // ?SendReadyReq@mmInterface@@AAEXXZ
    ARTS_IMPORT void SendReadyReq();

    // ?SendReadyStatus@mmInterface@@AAEXXZ
    ARTS_IMPORT void SendReadyStatus();

    // ?SetCRStateData@mmInterface@@AAEXXZ
    ARTS_IMPORT void SetCRStateData();

    // ?SetProtocol@mmInterface@@AAEXXZ
    ARTS_IMPORT void SetProtocol();

    // ?SetProtocol2@mmInterface@@AAEHXZ
    ARTS_IMPORT i32 SetProtocol2();

    // ?SetSessionData@mmInterface@@AAEXPAUNETSESSION_DESC@@@Z
    ARTS_IMPORT void SetSessionData(NETSESSION_DESC* arg1);

    // ?SetStateDefaults@mmInterface@@AAEXXZ | unused
    ARTS_EXPORT void SetStateDefaults();

    // ?SetStateRace@mmInterface@@AAEXH@Z | unused
    ARTS_EXPORT void SetStateRace(i32 arg1);

    // ?ShowSessions@mmInterface@@AAEXXZ
    ARTS_IMPORT void ShowSessions();
};

check_size(mmInterface, 0x35830);
