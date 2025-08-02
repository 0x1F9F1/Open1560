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

class mmSingleCircuit final : public mmGame
{
public:
    // ??0mmSingleCircuit@@QAE@XZ
    ARTS_EXPORT mmSingleCircuit();

    // ??_EmmSingleCircuit@@UAEPAXI@Z
    // ??1mmSingleCircuit@@UAE@XZ
    ARTS_IMPORT ~mmSingleCircuit() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmSingleCircuit@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@mmSingleCircuit@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetWaypoints@mmSingleCircuit@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT mmWaypoints* GetWaypoints() override;

    // ?HitWaterHandler@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // ?Init@mmSingleCircuit@@QAEHXZ
    ARTS_EXPORT b32 Init();

    // ?InitGameObjects@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitOtherPlayers@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // ?NextRace@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void NextRace() override;

    // ?Reset@mmSingleCircuit@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDebugKeyInput@mmSingleCircuit@@UAEXH@Z | inline
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateGameInput@mmSingleCircuit@@UAEXH@Z
    ARTS_EXPORT void UpdateGameInput(i32 arg1) override;

    // ?UpdateScore@mmSingleCircuit@@QAEXXZ
    ARTS_IMPORT void UpdateScore();

    // ?DeclareFields@mmSingleCircuit@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?DisableRacers@mmSingleCircuit@@AAEXXZ
    ARTS_IMPORT void DisableRacers();

    // ?EnableRacers@mmSingleCircuit@@AAEXXZ
    ARTS_IMPORT void EnableRacers();

    // ?FinishMessage@mmSingleCircuit@@AAEXHH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1, i32 arg2);

    // ?ProgressCheck@mmSingleCircuit@@AAEHHH@Z
    ARTS_IMPORT i32 ProgressCheck(i32 arg1, i32 arg2);

    // ?RegisterFinish@mmSingleCircuit@@AAEHXZ
    ARTS_IMPORT i32 RegisterFinish();

    // ?RegisterLap@mmSingleCircuit@@AAEHXZ
    ARTS_IMPORT i32 RegisterLap();

public:
    foobar FooBar {};
    mmWaypoints* Waypoints {};

#ifdef ARTS_STANDALONE
    i16 OppFinishPositions[MaxOpponents] {};
#else
    ARTS_EXPORT static i16 OppFinishPositions[MaxOpponents];
    i16 OldOppFinishPositions[8] {};
#endif

    i16 NumFinished {};

#ifdef ARTS_STANDALONE
    i32 OppNumCheck[MaxOpponents] {};
#else
    ARTS_EXPORT static i32 OppNumCheck[MaxOpponents];
    i32 OldOppNumCheck[8] {};
#endif

    f32 StartAngle {};
    f32 BestLapTime {};
    f32 LapTimes[10] {};
    i32 LapCounter {};
    i32 field_1E5FC {};
};

check_size(mmSingleCircuit, 0x1E600);
