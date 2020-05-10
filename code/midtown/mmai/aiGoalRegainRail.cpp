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

define_dummy_symbol(mmai_aiGoalRegainRail);

#include "aiGoalRegainRail.h"

aiGoalRegainRail::aiGoalRegainRail(class aiRailSet* arg1, class aiVehicleSpline* arg2)
{
    unimplemented(arg1, arg2);
}

aiGoalRegainRail::~aiGoalRegainRail()
{
    unimplemented();
}

i32 aiGoalRegainRail::Context()
{
    return stub<thiscall_t<i32, aiGoalRegainRail*>>(0x46B240, this);
}

void aiGoalRegainRail::Dump()
{
    return stub<thiscall_t<void, aiGoalRegainRail*>>(0x46B270, this);
}

void aiGoalRegainRail::Init()
{
    return stub<thiscall_t<void, aiGoalRegainRail*>>(0x46AA60, this);
}

i32 aiGoalRegainRail::Priority()
{
    return stub<thiscall_t<i32, aiGoalRegainRail*>>(0x46B260, this);
}

void aiGoalRegainRail::Reset()
{
    return stub<thiscall_t<void, aiGoalRegainRail*>>(0x46AA80, this);
}

void aiGoalRegainRail::Update()
{
    return stub<thiscall_t<void, aiGoalRegainRail*>>(0x46B130, this);
}
