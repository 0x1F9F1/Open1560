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

class Vehicle final : public VehicleSelectBase
{
public:
    // ??0Vehicle@@QAE@H@Z
    ARTS_IMPORT Vehicle(i32 arg1);

    // ??1Vehicle@@UAE@XZ
    ARTS_EXPORT ~Vehicle() override = default;

    // ?PostSetup@Vehicle@@UAEXXZ
    ARTS_IMPORT void PostSetup() override;

    // ?PreSetup@Vehicle@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?SetSubMenu@Vehicle@@QAEXH@Z
    ARTS_IMPORT void SetSubMenu(i32 arg1);

    // ?SetSubMenuButtons@Vehicle@@QAEXXZ
    ARTS_IMPORT void SetSubMenuButtons();

    u8 gap168[0x1C];
};

check_size(Vehicle, 0x184);
