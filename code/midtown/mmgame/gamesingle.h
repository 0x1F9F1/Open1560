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

class mmGameSingle final : public mmGame
{
public:
    // ??0mmGameSingle@@QAE@XZ
    ARTS_IMPORT mmGameSingle();

    // ??1mmGameSingle@@UAE@XZ
    ARTS_IMPORT ~mmGameSingle() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmGameSingle@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@mmGameSingle@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetWaypoints@mmGameSingle@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT mmWaypoints* GetWaypoints() override;

    // ?HitWaterHandler@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // ?Init@mmGameSingle@@QAEHXZ
    ARTS_EXPORT b32 Init();

    // ?InitGameObjects@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitOtherPlayers@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // ?NextRace@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void NextRace() override;

    // ?Reset@mmGameSingle@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDebugKeyInput@mmGameSingle@@UAEXH@Z | inline
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateGameInput@mmGameSingle@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // ?UpdateScore@mmGameSingle@@QAEXXZ
    ARTS_IMPORT void UpdateScore();

    // ?DeclareFields@mmGameSingle@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?DisableRacers@mmGameSingle@@AAEXXZ
    ARTS_IMPORT void DisableRacers();

    // ?EnableRacers@mmGameSingle@@AAEXXZ
    ARTS_IMPORT void EnableRacers();

    // ?FinishMessage@mmGameSingle@@AAEXHH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1, i32 arg2);

    // ?ProgressCheck@mmGameSingle@@AAEHHH@Z
    ARTS_IMPORT i32 ProgressCheck(i32 arg1, i32 arg2);

    // ?RegisterFinish@mmGameSingle@@AAEHXZ
    ARTS_IMPORT i32 RegisterFinish();

public:
    b32 InWater {};
    foobar FooBar {};

#ifdef ARTS_STANDALONE
    i32 OppNumCheck[MaxOpponents] {};
#else
    static i32 OppNumCheck[MaxOpponents];
    i32 OldOppNumCheck[8] {};

    [[deprecated]] i32 field_1E5B4[8] {};
#endif

    mmWaypoints* Waypoints {};

#ifdef ARTS_STANDALONE
    i16 OppFinishPositions[MaxOpponents] {};
#else
    static i16 OppFinishPositions[MaxOpponents];
    i16 OldOppFinishPositions[8] {};
#endif

    i16 NumFinished {};
    f32 RespawnPosition {};
};

check_size(mmGameSingle, 0x1E5F0);
