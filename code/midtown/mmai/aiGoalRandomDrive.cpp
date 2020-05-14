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

define_dummy_symbol(mmai_aiGoalRandomDrive);

#include "aiGoalRandomDrive.h"

aiGoalRandomDrive::aiGoalRandomDrive(class aiRailSet* arg1, class aiVehicleSpline* arg2)
{
    unimplemented(arg1, arg2);
}

aiGoalRandomDrive::~aiGoalRandomDrive()
{
    unimplemented();
}

i32 aiGoalRandomDrive::Context()
{
    return stub<thiscall_t<i32, aiGoalRandomDrive*>>(0x45D440, this);
}

void aiGoalRandomDrive::Dump()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x45F690, this);
}

void aiGoalRandomDrive::Init()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x45C8B0, this);
}

i32 aiGoalRandomDrive::Priority()
{
    return stub<thiscall_t<i32, aiGoalRandomDrive*>>(0x45D460, this);
}

void aiGoalRandomDrive::Reset()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x45C8D0, this);
}

void aiGoalRandomDrive::SolvePosition(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiGoalRandomDrive*, class Vector3&, f32>>(0x45E250, this, arg1, arg2);
}

void aiGoalRandomDrive::Update()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x45D320, this);
}

i32 aiGoalRandomDrive::AnyVehiclesComingThisWay()
{
    return stub<thiscall_t<i32, aiGoalRandomDrive*>>(0x45DE10, this);
}

void aiGoalRandomDrive::AvoidCollision(class aiVehicleSpline* arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiGoalRandomDrive*, class aiVehicleSpline*, f32>>(0x45E020, this, arg1, arg2);
}

void aiGoalRandomDrive::ChangeLanes()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x45F1A0, this);
}

i32 aiGoalRandomDrive::OkayToEnterIntersection()
{
    return stub<thiscall_t<i32, aiGoalRandomDrive*>>(0x45DC00, this);
}

void aiGoalRandomDrive::SolveLane()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x45F0B0, this);
}

void aiGoalRandomDrive::SolveRailType()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x45E2A0, this);
}

void aiGoalRandomDrive::SolveVelocity()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x45D470, this);
}

aiGoal::~aiGoal()
{
    unimplemented();
}

void aiGoal::Update()
{
    return stub<thiscall_t<void, aiGoal*>>(0x45F700, this);
}
