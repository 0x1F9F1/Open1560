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

#include "gamemulti.h"

class mmCar;
class mmWaypointObject;

class mmMultiCR final : public mmGameMulti
{
public:
    // ??0mmMultiCR@@QAE@XZ
    ARTS_IMPORT mmMultiCR();

    // ??_EmmMultiCR@@UAEPAXI@Z
    // ??1mmMultiCR@@UAE@XZ
    ARTS_IMPORT ~mmMultiCR() override;

    // ?ChangePlayerData@mmMultiCR@@QAEXXZ
    ARTS_IMPORT void ChangePlayerData();

    // ?DropThruCityHandler@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void DropThruCityHandler() override;

    // ?FondleCarMass@mmMultiCR@@QAEXPAVmmCar@@M@Z
    ARTS_IMPORT void FondleCarMass(mmCar* arg1, f32 arg2);

    // ?GameMessage@mmMultiCR@@UAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void GameMessage(NETGAME_MSG* arg1) override;

    // ?GetClass@mmMultiCR@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetWaypoints@mmMultiCR@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_EXPORT mmWaypoints* GetWaypoints() override;

    // ?HitWaterHandler@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // ?ImpactCallback@mmMultiCR@@QAEXXZ
    ARTS_IMPORT void ImpactCallback();

    // ?Init@mmMultiCR@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?InitGameObjects@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitNetworkPlayers@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void InitNetworkPlayers() override;

    // ?LoadCSV@mmMultiCR@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadCSV(char* arg1);

    // ?LoadSets@mmMultiCR@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadSets(char* arg1);

    // ?Reset@mmMultiCR@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetPositions@mmMultiCR@@QAEXH@Z
    ARTS_IMPORT void ResetPositions(i32 arg1);

    // ?SystemMessage@mmMultiCR@@UAEXPAUNETSYS_MSG@@@Z
    ARTS_IMPORT void SystemMessage(NETSYS_MSG* arg1) override;

    // ?UpdateDebugKeyInput@mmMultiCR@@UAEXH@Z
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmMultiCR@@UAEXXZ
    ARTS_EXPORT void UpdateGame() override;

    // ?UpdateGameInput@mmMultiCR@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // ?DeclareFields@mmMultiCR@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?DisplayTimeWarning@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void DisplayTimeWarning(i32 arg1);

    // ?DropGold@mmMultiCR@@AAEXVVector3@@H@Z
    ARTS_IMPORT void DropGold(Vector3 arg1, i32 arg2);

    // ?FillResults@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void FillResults();

    // ?FindGround@mmMultiCR@@AAEXVVector3@@AAV2@@Z
    ARTS_IMPORT void FindGround(Vector3 arg1, Vector3& arg2);

    // ?GetRandomIndex@mmMultiCR@@AAEHXZ
    ARTS_IMPORT i32 GetRandomIndex();

    // ?OppStealGold@mmMultiCR@@AAEXH@Z
    ARTS_EXPORT void OppStealGold(i32 player);

    // ?Score@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void Score(i32 arg1);

    // ?SelectTeams@mmMultiCR@@AAEHXZ | unused
    ARTS_EXPORT i32 SelectTeams();

    // ?SendGameState@mmMultiCR@@AAEXK@Z
    ARTS_IMPORT void SendGameState(ulong arg1);

    // ?SendGoldAck@mmMultiCR@@AAEXK@Z
    ARTS_IMPORT void SendGoldAck(ulong arg1);

    // ?SendGoldDeliver@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void SendGoldDeliver();

    // ?SendGoldDrop@mmMultiCR@@AAEXVVector3@@@Z
    ARTS_IMPORT void SendGoldDrop(Vector3 arg1);

    // ?SendLimitReached@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void SendLimitReached(i32 arg1);

    // ?SendSetup@mmMultiCR@@AAEXK@Z | unused
    ARTS_EXPORT void SendSetup(ulong arg1);

    // ?SendTimeWarning@mmMultiCR@@AAEXH@Z
    ARTS_IMPORT void SendTimeWarning(i32 arg1);

    // ?StealGold@mmMultiCR@@AAEXPAVmmCar@@@Z
    ARTS_EXPORT void StealGold(mmCar* car);

    // ?UpdateBank@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateBank();

    // ?UpdateGold@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateGold();

    // ?UpdateHUD@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateHUD();

    // ?UpdateHideout@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateHideout();

    // ?UpdateLimit@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateLimit();

    // ?UpdateTimeWarning@mmMultiCR@@AAEXXZ
    ARTS_IMPORT void UpdateTimeWarning();

public:
    mmWaypointObject* field_1EEA8;
    mmWaypointObject* field_1EEAC;
    mmWaypointObject* field_1EEB0;
    Vector4* GoldPositions;
    mmCar* GoldCarrier;
    i32 BlueScore;
    i32 RedScore;
    i16 field_1EEC4[16];
    i32 field_1EEE4;
    i32 NumGoldPositions;
    i32 GoldIndex;
    i32 field_1EEF0;
    i32 TimesGoldStolen;
    f32 field_1EEF8;
    mmTimer field_1EEFC;
};

check_size(mmMultiCR, 0x1EF30);

// ?TwoPlayers@@3HA
ARTS_IMPORT extern i32 TwoPlayers;
