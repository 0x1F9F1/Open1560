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
    mmui:race

    0x4A4C30 | public: __thiscall RaceMenu::RaceMenu(int) | ??0RaceMenu@@QAE@H@Z
    0x4A4CF0 | public: virtual __thiscall RaceMenu::~RaceMenu(void) | ??1RaceMenu@@UAE@XZ
    0x4A4D00 | public: int __thiscall RaceMenu::GetRaceID(void) | ?GetRaceID@RaceMenu@@QAEHXZ
    0x4A4D90 | public: void __thiscall RaceMenu::SetProgressMask(int) | ?SetProgressMask@RaceMenu@@QAEXH@Z
    0x4A4DB0 | public: void __thiscall RaceMenu::SetBlitzMask(int) | ?SetBlitzMask@RaceMenu@@QAEXH@Z
    0x4A4DD0 | public: void __thiscall RaceMenu::SetCheckpointMask(int) | ?SetCheckpointMask@RaceMenu@@QAEXH@Z
    0x4A4DF0 | public: void __thiscall RaceMenu::SetCircuitMask(int) | ?SetCircuitMask@RaceMenu@@QAEXH@Z
    0x4A4E10 | public: char * __thiscall RaceMenu::GetRaceName(enum mmGameMode,int) | ?GetRaceName@RaceMenu@@QAEPADW4mmGameMode@@H@Z
    0x4A4F30 | public: virtual void * __thiscall RaceMenu::`scalar deleting destructor'(unsigned int) | ??_GRaceMenu@@UAEPAXI@Z
    0x4A4F30 | public: virtual void * __thiscall RaceMenu::`vector deleting destructor'(unsigned int) | ??_ERaceMenu@@UAEPAXI@Z
    0x4A4F60 | public: virtual void __thiscall RaceMenuBase::UsesLobby(int) | ?UsesLobby@RaceMenuBase@@UAEXH@Z
    0x61DAC8 | const RaceMenu::`vftable' | ??_7RaceMenu@@6B@
*/

#include "racebase.h"

class RaceMenu : public RaceMenuBase
{
    // const RaceMenu::`vftable' @ 0x61DAC8

public:
    // 0x4A4C30 | ??0RaceMenu@@QAE@H@Z
    RaceMenu(i32 arg1);

    // 0x4A4F30 | ??_ERaceMenu@@UAEPAXI@Z
    // 0x4A4CF0 | ??1RaceMenu@@UAE@XZ
    ~RaceMenu() override;

    // 0x4A4D00 | ?GetRaceID@RaceMenu@@QAEHXZ | unused
    i32 GetRaceID();

    // 0x4A4E10 | ?GetRaceName@RaceMenu@@QAEPADW4mmGameMode@@H@Z | unused
    char* GetRaceName(enum mmGameMode arg1, i32 arg2);

    // 0x4A4DB0 | ?SetBlitzMask@RaceMenu@@QAEXH@Z
    void SetBlitzMask(i32 arg1);

    // 0x4A4DD0 | ?SetCheckpointMask@RaceMenu@@QAEXH@Z
    void SetCheckpointMask(i32 arg1);

    // 0x4A4DF0 | ?SetCircuitMask@RaceMenu@@QAEXH@Z
    void SetCircuitMask(i32 arg1);

    // 0x4A4D90 | ?SetProgressMask@RaceMenu@@QAEXH@Z
    void SetProgressMask(i32 arg1);
};

check_size(RaceMenu, 0xF94);
