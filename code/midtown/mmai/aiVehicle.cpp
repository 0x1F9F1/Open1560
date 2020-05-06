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

define_dummy_symbol(mmai_aiVehicle);

#include "aiVehicle.h"

aiVehicle::aiVehicle()
{
    unimplemented();
}

aiVehicle::~aiVehicle()
{
    unimplemented();
}

void aiVehicle::Update()
{
    return stub<thiscall_t<void, aiVehicle*>>(0x465940, this);
}

void aiVehicle::Reset()
{
    return stub<thiscall_t<void, aiVehicle*>>(0x465930, this);
}

i32 aiVehicle::Type()
{
    return stub<thiscall_t<i32, aiVehicle*>>(0x - 400000_Offset, this);
}

void aiVehicle::DrawId()
{
    return stub<thiscall_t<void, aiVehicle*>>(0x - 400000_Offset, this);
}

void aiVehicle::Init(i32 arg1)
{
    return stub<thiscall_t<void, aiVehicle*, i32>>(0x465920, this, arg1);
}
