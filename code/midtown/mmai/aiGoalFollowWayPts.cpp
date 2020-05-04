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

#include "aiGoalFollowWayPts.h"

aiGoalFollowWayPts::aiGoalFollowWayPts()
{
    unimplemented();
}

aiGoalFollowWayPts::aiGoalFollowWayPts(char* arg1, class aiRailSet* arg2, class aiVehicleOpponent* arg3, i16* arg4,
    i16* arg5, i16* arg6, char* arg7, f32 arg8)
{
    unimplemented();
}

aiGoalFollowWayPts::~aiGoalFollowWayPts()
{
    unimplemented();
}

void aiGoalFollowWayPts::Init()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x664D0_Offset, this);
}

void aiGoalFollowWayPts::Reset()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x669C0_Offset, this);
}

i32 aiGoalFollowWayPts::Context()
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*>>(0x668C0_Offset, this);
}

i32 aiGoalFollowWayPts::Priority()
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*>>(0x669B0_Offset, this);
}

void aiGoalFollowWayPts::Update()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x66AB0_Offset, this);
}

class MetaClass* aiGoalFollowWayPts::GetClass()
{
    return stub<thiscall_t<class MetaClass*, aiGoalFollowWayPts*>>(0x6A2D0_Offset, this);
}

void aiGoalFollowWayPts::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*, class Bank*>>(0x6A0E0_Offset, this, arg1);
}

void aiGoalFollowWayPts::Dump()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x69E60_Offset, this);
}

void aiGoalFollowWayPts::DeclareFields()
{
    return stub<cdecl_t<void>>(0x6A140_Offset);
}

void aiGoalFollowWayPts::AddToBlockedRange(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*, f32, f32, f32>>(0x68B00_Offset, this, arg1, arg2, arg3);
}

void aiGoalFollowWayPts::AvoidCollision(i32 arg1)
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*, i32>>(0x68CA0_Offset, this, arg1);
}

void aiGoalFollowWayPts::AvoidOpponentCollision(class aiVehicleOpponent* arg1)
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*, class aiVehicleOpponent*>>(0x67040_Offset, this, arg1);
}

void aiGoalFollowWayPts::CalcSpeed()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x69170_Offset, this);
}

class aiPath* aiGoalFollowWayPts::DetRdSegBetweenInts(class aiIntersection* arg1, class aiIntersection* arg2)
{
    return stub<thiscall_t<class aiPath*, aiGoalFollowWayPts*, class aiIntersection*, class aiIntersection*>>(
        0x67E40_Offset, this, arg1, arg2);
}

i32 aiGoalFollowWayPts::DetectCollision(i32* arg1)
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*, i32*>>(0x67ED0_Offset, this, arg1);
}

class aiVehicleOpponent* aiGoalFollowWayPts::DetectOpponentCollision()
{
    return stub<thiscall_t<class aiVehicleOpponent*, aiGoalFollowWayPts*>>(0x66EA0_Offset, this);
}

i32 aiGoalFollowWayPts::LocateWayPtFromInt(class aiIntersection* arg1, class aiPath** arg2)
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*, class aiIntersection*, class aiPath**>>(
        0x67D60_Offset, this, arg1, arg2);
}

i32 aiGoalFollowWayPts::LocateWayPtFromRoad(class aiPath* arg1, class aiPath** arg2, class aiPath** arg3)
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*, class aiPath*, class aiPath**, class aiPath**>>(
        0x676E0_Offset, this, arg1, arg2, arg3);
}

void aiGoalFollowWayPts::PlanRoute()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x674B0_Offset, this);
}

void aiGoalFollowWayPts::SolveTargetPoint()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x69E10_Offset, this);
}

define_dummy_symbol(mmai_aiGoalFollowWayPts);
