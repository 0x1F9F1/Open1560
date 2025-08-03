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

class mmSingleBlitz final : public mmGame
{
public:
    // ??0mmSingleBlitz@@QAE@XZ
    ARTS_IMPORT mmSingleBlitz();

    // ??1mmSingleBlitz@@UAE@XZ
    ARTS_IMPORT ~mmSingleBlitz() override;

    // ?GetClass@mmSingleBlitz@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetWaypoints@mmSingleBlitz@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT mmWaypoints* GetWaypoints() override;

    // ?HitWaterHandler@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // ?Init@mmSingleBlitz@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?InitGameObjects@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitOtherPlayers@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // ?NextRace@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void NextRace() override;

    // ?PlayTimerWarning@mmSingleBlitz@@QAEXM@Z
    ARTS_IMPORT void PlayTimerWarning(f32 arg1);

    // ?Reset@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDebugKeyInput@mmSingleBlitz@@UAEXH@Z | inline
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmSingleBlitz@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateGameInput@mmSingleBlitz@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // ?DeclareFields@mmSingleBlitz@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?DisableRacers@mmSingleBlitz@@AAEXXZ
    ARTS_IMPORT void DisableRacers();

    // ?EnableRacers@mmSingleBlitz@@AAEXXZ
    ARTS_IMPORT void EnableRacers();

    // ?FinishMessage@mmSingleBlitz@@AAEXH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1);

    // ?ProgressCheck@mmSingleBlitz@@AAEHHH@Z
    ARTS_IMPORT i32 ProgressCheck(i32 arg1, i32 arg2);

    // ?RegisterFinish@mmSingleBlitz@@AAEHXZ
    ARTS_IMPORT i32 RegisterFinish();

    u8 gap1E570[0x48];
};

check_size(mmSingleBlitz, 0x1E5B8);
