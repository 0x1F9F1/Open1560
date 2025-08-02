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

#include "mmwidget/menu.h"

class RaceMenuBase : public UIMenu
{
public:
    // ??0RaceMenuBase@@QAE@H@Z
    ARTS_IMPORT RaceMenuBase(i32 arg1);

    // ??_GRaceMenuBase@@UAEPAXI@Z
    // ??_ERaceMenuBase@@UAEPAXI@Z
    // ??1RaceMenuBase@@UAE@XZ
    ARTS_IMPORT ~RaceMenuBase() override;

    // ?UsesLobby@RaceMenuBase@@UAEXH@Z | inline
    ARTS_EXPORT virtual void UsesLobby(i32 arg1);

    // ?AICallback@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void AICallback();

    // ?ChangeLocalVals@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void ChangeLocalVals();

    // ?CityChange@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void CityChange();

    // ?FocusDescription@RaceMenuBase@@QAEXH@Z
    ARTS_IMPORT void FocusDescription(i32 arg1);

    // ?GameCallback@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void GameCallback();

    // ?Init@RaceMenuBase@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // ?IsEnvEnabled@RaceMenuBase@@QAEHXZ
    ARTS_IMPORT i32 IsEnvEnabled();

    // ?LapsCallback@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void LapsCallback();

    // ?SetRW@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void SetRW();

    // ?SetStateRace@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void SetStateRace();

    // ?SyncRaceState@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void SyncRaceState();

    // ?WPCallback@RaceMenuBase@@QAEXXZ
    ARTS_IMPORT void WPCallback();

    // ?WidgetOnOff@RaceMenuBase@@QAEXHPAVuiWidget@@@Z
    ARTS_IMPORT void WidgetOnOff(i32 arg1, uiWidget* arg2);

    u8 gap90[0xF00];
};

check_size(RaceMenuBase, 0xF90);

// ?GoldDamageScale@@3MA
ARTS_IMPORT extern f32 GoldDamageScale;

// ?GoldHPScale@@3MA
ARTS_IMPORT extern f32 GoldHPScale;
