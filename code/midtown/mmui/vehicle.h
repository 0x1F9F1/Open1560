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

#include "vselect.h"

/*
    mmui:vehicle

    0x4A51D0 | public: __thiscall Vehicle::Vehicle(int) | ??0Vehicle@@QAE@H@Z
    0x4A52B0 | public: virtual __thiscall Vehicle::~Vehicle(void) | ??1Vehicle@@UAE@XZ
    0x4A52C0 | public: void __thiscall Vehicle::SetSubMenu(int) | ?SetSubMenu@Vehicle@@QAEXH@Z
    0x4A52E0 | public: void __thiscall Vehicle::SetSubMenuButtons(void) | ?SetSubMenuButtons@Vehicle@@QAEXXZ
    0x4A5300 | public: virtual void __thiscall Vehicle::PreSetup(void) | ?PreSetup@Vehicle@@UAEXXZ
    0x4A5310 | public: virtual void __thiscall Vehicle::PostSetup(void) | ?PostSetup@Vehicle@@UAEXXZ
    0x4A5320 | public: virtual void * __thiscall Vehicle::`scalar deleting destructor'(unsigned int) | ??_GVehicle@@UAEPAXI@Z
    0x4A5320 | public: virtual void * __thiscall Vehicle::`vector deleting destructor'(unsigned int) | ??_EVehicle@@UAEPAXI@Z
    0x61DB70 | const Vehicle::`vftable' | ??_7Vehicle@@6B@
*/

class Vehicle : public VehicleSelectBase
{
    // const Vehicle::`vftable' @ 0x61DB70

public:
    // 0x4A51D0 | ??0Vehicle@@QAE@H@Z
    Vehicle(i32 arg1);

    // 0x4A5320 | ??_EVehicle@@UAEPAXI@Z
    // 0x4A52B0 | ??1Vehicle@@UAE@XZ
    ~Vehicle() override;

    // 0x4A5310 | ?PostSetup@Vehicle@@UAEXXZ
    void PostSetup() override;

    // 0x4A5300 | ?PreSetup@Vehicle@@UAEXXZ
    void PreSetup() override;

    // 0x4A52C0 | ?SetSubMenu@Vehicle@@QAEXH@Z
    void SetSubMenu(i32 arg1);

    // 0x4A52E0 | ?SetSubMenuButtons@Vehicle@@QAEXXZ
    void SetSubMenuButtons();
};

check_size(Vehicle, 0x184);
