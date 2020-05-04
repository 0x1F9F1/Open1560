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

#include "aiGoalRandomDrive.h"

aiGoalRandomDrive::aiGoalRandomDrive(class aiRailSet* arg1, class aiVehicleSpline* arg2)
{
    unimplemented();
}

aiGoalRandomDrive::~aiGoalRandomDrive()
{
    unimplemented();
}

void aiGoalRandomDrive::Init()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x5C8B0_Offset, this);
}

void aiGoalRandomDrive::Reset()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x5C8D0_Offset, this);
}

i32 aiGoalRandomDrive::Context()
{
    return stub<thiscall_t<i32, aiGoalRandomDrive*>>(0x5D440_Offset, this);
}

i32 aiGoalRandomDrive::Priority()
{
    return stub<thiscall_t<i32, aiGoalRandomDrive*>>(0x5D460_Offset, this);
}

void aiGoalRandomDrive::Update()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x5D320_Offset, this);
}

void aiGoalRandomDrive::Dump()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x5F690_Offset, this);
}

void aiGoalRandomDrive::SolvePosition(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiGoalRandomDrive*, class Vector3&, f32>>(0x5E250_Offset, this, arg1, arg2);
}

i32 aiGoalRandomDrive::AnyVehiclesComingThisWay()
{
    return stub<thiscall_t<i32, aiGoalRandomDrive*>>(0x5DE10_Offset, this);
}

void aiGoalRandomDrive::AvoidCollision(class aiVehicleSpline* arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiGoalRandomDrive*, class aiVehicleSpline*, f32>>(0x5E020_Offset, this, arg1, arg2);
}

void aiGoalRandomDrive::ChangeLanes()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x5F1A0_Offset, this);
}

i32 aiGoalRandomDrive::OkayToEnterIntersection()
{
    return stub<thiscall_t<i32, aiGoalRandomDrive*>>(0x5DC00_Offset, this);
}

void aiGoalRandomDrive::SolveLane()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x5F0B0_Offset, this);
}

void aiGoalRandomDrive::SolveRailType()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x5E2A0_Offset, this);
}

void aiGoalRandomDrive::SolveVelocity()
{
    return stub<thiscall_t<void, aiGoalRandomDrive*>>(0x5D470_Offset, this);
}

aiGoal::~aiGoal()
{
    unimplemented();
}

void aiGoal::Update()
{
    return stub<thiscall_t<void, aiGoal*>>(0x5F700_Offset, this);
}

define_dummy_symbol(mmai_aiGoalRandomDrive);
