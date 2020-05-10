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

define_dummy_symbol(mmai_aiGoalCollision);

#include "aiGoalCollision.h"

aiGoalCollision::aiGoalCollision(class aiRailSet* arg1, class aiVehicleSpline* arg2)
{
    unimplemented(arg1, arg2);
}

aiGoalCollision::~aiGoalCollision()
{
    unimplemented();
}

i32 aiGoalCollision::Context()
{
    return stub<thiscall_t<i32, aiGoalCollision*>>(0x46B3D0, this);
}

void aiGoalCollision::Init()
{
    return stub<thiscall_t<void, aiGoalCollision*>>(0x46B330, this);
}

i32 aiGoalCollision::Priority()
{
    return stub<thiscall_t<i32, aiGoalCollision*>>(0x46B3F0, this);
}

void aiGoalCollision::Reset()
{
    return stub<thiscall_t<void, aiGoalCollision*>>(0x46B340, this);
}

void aiGoalCollision::Update()
{
    return stub<thiscall_t<void, aiGoalCollision*>>(0x46B350, this);
}
