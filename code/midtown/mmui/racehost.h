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

class HostRaceMenu final : public RaceMenuBase
{
public:
    // ??0HostRaceMenu@@QAE@H@Z
    ARTS_IMPORT HostRaceMenu(i32 arg1);

    // ??_EHostRaceMenu@@UAEPAXI@Z
    // ??_GHostRaceMenu@@UAEPAXI@Z
    // ??1HostRaceMenu@@UAE@XZ
    ARTS_IMPORT ~HostRaceMenu() override = default;

    // ?DisableStart@HostRaceMenu@@QAEXXZ | unused
    ARTS_IMPORT void DisableStart();

    // ?EnableStart@HostRaceMenu@@QAEXXZ | unused
    ARTS_IMPORT void EnableStart();

    // ?UsesLobby@HostRaceMenu@@UAEXH@Z
    ARTS_EXPORT void UsesLobby(i32 arg1) override;

    u8 gapF90[0x8];
};

check_size(HostRaceMenu, 0xF98);
