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
    mmui:racehost

    0x4A2B60 | public: __thiscall HostRaceMenu::HostRaceMenu(int) | ??0HostRaceMenu@@QAE@H@Z
    0x4A2C30 | public: virtual __thiscall HostRaceMenu::~HostRaceMenu(void) | ??1HostRaceMenu@@UAE@XZ
    0x4A2C40 | public: void __thiscall HostRaceMenu::EnableStart(void) | ?EnableStart@HostRaceMenu@@QAEXXZ
    0x4A2C50 | public: void __thiscall HostRaceMenu::DisableStart(void) | ?DisableStart@HostRaceMenu@@QAEXXZ
    0x4A2C60 | public: virtual void __thiscall HostRaceMenu::UsesLobby(int) | ?UsesLobby@HostRaceMenu@@UAEXH@Z
    0x4A2C70 | public: virtual void * __thiscall HostRaceMenu::`scalar deleting destructor'(unsigned int) | ??_GHostRaceMenu@@UAEPAXI@Z
    0x4A2C70 | public: virtual void * __thiscall HostRaceMenu::`vector deleting destructor'(unsigned int) | ??_EHostRaceMenu@@UAEPAXI@Z
    0x61D930 | const HostRaceMenu::`vftable' | ??_7HostRaceMenu@@6B@
*/

#include "racebase.h"

class HostRaceMenu : public RaceMenuBase
{
    // const HostRaceMenu::`vftable' @ 0x61D930

public:
    // 0x4A2B60 | ??0HostRaceMenu@@QAE@H@Z
    ARTS_IMPORT HostRaceMenu(i32 arg1);

    // 0x4A2C70 | ??_EHostRaceMenu@@UAEPAXI@Z
    // 0x4A2C70 | ??_GHostRaceMenu@@UAEPAXI@Z
    // 0x4A2C30 | ??1HostRaceMenu@@UAE@XZ
    ARTS_IMPORT ~HostRaceMenu() override = default;

    // 0x4A2C50 | ?DisableStart@HostRaceMenu@@QAEXXZ | unused
    ARTS_IMPORT void DisableStart();

    // 0x4A2C40 | ?EnableStart@HostRaceMenu@@QAEXXZ | unused
    ARTS_IMPORT void EnableStart();

    // 0x4A2C60 | ?UsesLobby@HostRaceMenu@@UAEXH@Z
    ARTS_IMPORT void UsesLobby(i32 arg1) override;

    u8 gapF90[0x8];
};

check_size(HostRaceMenu, 0xF98);
