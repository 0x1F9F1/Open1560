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
    mmui:racebase

    0x4A63C0 | public: __thiscall RaceMenuBase::RaceMenuBase(int) | ??0RaceMenuBase@@QAE@H@Z
    0x4A6500 | public: void __thiscall RaceMenuBase::Init(int) | ?Init@RaceMenuBase@@QAEXH@Z
    0x4A72C0 | public: virtual __thiscall RaceMenuBase::~RaceMenuBase(void) | ??1RaceMenuBase@@UAE@XZ
    0x4A7340 | public: void __thiscall RaceMenuBase::FocusDescription(int) | ?FocusDescription@RaceMenuBase@@QAEXH@Z
    0x4A7370 | public: void __thiscall RaceMenuBase::WidgetOnOff(int,class uiWidget *) | ?WidgetOnOff@RaceMenuBase@@QAEXHPAVuiWidget@@@Z
    0x4A73A0 | public: void __thiscall RaceMenuBase::SetRW(void) | ?SetRW@RaceMenuBase@@QAEXXZ
    0x4A7670 | public: int __thiscall RaceMenuBase::IsEnvEnabled(void) | ?IsEnvEnabled@RaceMenuBase@@QAEHXZ
    0x4A7690 | public: void __thiscall RaceMenuBase::CheatCallback(void) | ?CheatCallback@RaceMenuBase@@QAEXXZ
    0x4A76A0 | public: void __thiscall RaceMenuBase::SyncRaceState(void) | ?SyncRaceState@RaceMenuBase@@QAEXXZ
    0x4A7750 | public: void __thiscall RaceMenuBase::CityChange(void) | ?CityChange@RaceMenuBase@@QAEXXZ
    0x4A78D0 | public: void __thiscall RaceMenuBase::GameCallback(void) | ?GameCallback@RaceMenuBase@@QAEXXZ
    0x4A7950 | public: void __thiscall RaceMenuBase::LapsCallback(void) | ?LapsCallback@RaceMenuBase@@QAEXXZ
    0x4A7960 | public: void __thiscall RaceMenuBase::WPCallback(void) | ?WPCallback@RaceMenuBase@@QAEXXZ
    0x4A79B0 | public: void __thiscall RaceMenuBase::AICallback(void) | ?AICallback@RaceMenuBase@@QAEXXZ
    0x4A7A00 | public: void __thiscall RaceMenuBase::WeatherCallback(void) | ?WeatherCallback@RaceMenuBase@@QAEXXZ
    0x4A7A10 | public: void __thiscall RaceMenuBase::TimeCallback(void) | ?TimeCallback@RaceMenuBase@@QAEXXZ
    0x4A7A20 | public: void __thiscall RaceMenuBase::ChangeLocalVals(void) | ?ChangeLocalVals@RaceMenuBase@@QAEXXZ
    0x4A7CB0 | public: void __thiscall RaceMenuBase::SetStateRace(void) | ?SetStateRace@RaceMenuBase@@QAEXXZ
    0x4A8050 | public: virtual void * __thiscall RaceMenuBase::`vector deleting destructor'(unsigned int) | ??_ERaceMenuBase@@UAEPAXI@Z
    0x4A8050 | public: virtual void * __thiscall RaceMenuBase::`scalar deleting destructor'(unsigned int) | ??_GRaceMenuBase@@UAEPAXI@Z
    0x61DD00 | const RaceMenuBase::`vftable' | ??_7RaceMenuBase@@6B@
    0x641198 | float GoldHPScale | ?GoldHPScale@@3MA
    0x64119C | float GoldDamageScale | ?GoldDamageScale@@3MA
*/

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
