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

define_dummy_symbol(mmui_vehicle);

#include "vehicle.h"

Vehicle::Vehicle(i32 arg1)
{
    unimplemented(arg1);
}

Vehicle::~Vehicle()
{
    unimplemented(arg1);
}

void Vehicle::PostSetup()
{
    return stub<thiscall_t<void, Vehicle*>>(0xA5310_Offset, this);
}

void Vehicle::PreSetup()
{
    return stub<thiscall_t<void, Vehicle*>>(0xA5300_Offset, this);
}

void Vehicle::SetSubMenu(i32 arg1)
{
    return stub<thiscall_t<void, Vehicle*, i32>>(0xA52C0_Offset, this, arg1);
}

void Vehicle::SetSubMenuButtons()
{
    return stub<thiscall_t<void, Vehicle*>>(0xA52E0_Offset, this);
}
