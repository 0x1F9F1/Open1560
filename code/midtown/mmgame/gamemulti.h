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

#include "game.h"
#include "hud.h"
#include "netobject.h"

struct NETGAME_MSG;
struct NETSYS_MSG;

class mmGameMulti : public mmGame
{
public:
    // ??0mmGameMulti@@QAE@XZ
    ARTS_IMPORT mmGameMulti();

    // ??1mmGameMulti@@UAE@XZ
    ARTS_IMPORT ~mmGameMulti() override;

    virtual void InitNetworkPlayers() = 0;

    // ?InitRoster@mmGameMulti@@UAEXXZ
    ARTS_IMPORT virtual void InitRoster();

    virtual void SystemMessage(NETSYS_MSG* arg1) = 0;

    virtual void GameMessage(NETGAME_MSG* arg1) = 0;

    // ?ActivateMapNetObject@mmGameMulti@@QAEXH@Z
    ARTS_EXPORT void ActivateMapNetObject(i32 player);

    // ?BootPlayerCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void BootPlayerCB(void* arg1, void* arg2);

    // ?BootStrapCars@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void BootStrapCars();

    // ?ClearNetObjects@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void ClearNetObjects();

    // ?DeactivateMapNetObject@mmGameMulti@@QAEXH@Z
    ARTS_EXPORT void DeactivateMapNetObject(i32 player);

    // ?DropThruCityHandler@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void DropThruCityHandler() override;

    // ?FinishMessage@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1);

    // ?GameMessageCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void GameMessageCB(void* arg1, void* arg2);

    // ?GetClass@mmGameMulti@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?HitWaterHandler@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // ?Init@mmGameMulti@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?InitGameStrings@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void InitGameStrings() override;

    // ?InitOtherPlayers@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // ?NextRace@mmGameMulti@@UAEXXZ | inline
    ARTS_EXPORT void NextRace() override;

    // ?ParseChatMessage@mmGameMulti@@QAEHPADH@Z
    ARTS_IMPORT i32 ParseChatMessage(char* arg1, i32 arg2);

    // ?QuitNetwork@mmGameMulti@@QAEXXZ
    ARTS_EXPORT void QuitNetwork();

    // ?RegisterMapNetObjects@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void RegisterMapNetObjects(i32 arg1);

    // ?Reset@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SendBootMsg@mmGameMulti@@QAEXK@Z
    ARTS_IMPORT void SendBootMsg(ulong arg1);

    // ?SendChatMessage@mmGameMulti@@UAEXPAD@Z
    ARTS_IMPORT void SendChatMessage(char* arg1) override;

    // ?SendMsg@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void SendMsg(i32 arg1);

    // ?SendToChatMessage@mmGameMulti@@QAEXPADK@Z
    ARTS_IMPORT void SendToChatMessage(char* arg1, ulong arg2);

    // ?SystemMessageCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void SystemMessageCB(void* arg1, void* arg2);

    // ?Update@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDebugKeyInput@mmGameMulti@@UAEXH@Z
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateNetWorkAudio@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void UpdateNetWorkAudio();

    // ?UpdateScore@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void UpdateScore();

    // ?DeclareFields@mmGameMulti@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

protected:
    // ?DisableRacers@mmGameMulti@@IAEXXZ
    ARTS_IMPORT void DisableRacers();

    // ?EnableRacers@mmGameMulti@@IAEXXZ
    ARTS_IMPORT void EnableRacers();

    // ?StartXYZ@mmGameMulti@@IAEXHAAVVector3@@0MM@Z
    ARTS_EXPORT void StartXYZ(i32 index, Vector3& out_result, Vector3& start_position, f32 rotation, f32 length);

public:
    f32 ResetRotation;
    f32 Time;
    mmWaypoints* Waypoints;
    string field_1E57C;
    string field_1E584;
    i32 field_1E58C;
    i32 field_1E590;
    f32 field_1E594;
    mmNetObject PlayerObject;
    mmNetObject NetObjects[8];
    mmCar* Cars[8];
    void* field_1EE4C[8];
    mmTimer TimeLimit;
    i32 field_1EE9C;
    b32 NoKicking;
    i32 field_1EEA4;
};

check_size(mmGameMulti, 0x1EEA8);
