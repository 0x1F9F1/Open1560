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

define_dummy_symbol(mmai_aiGoalFollowWayPts);

#include "aiGoalFollowWayPts.h"

aiGoalFollowWayPts::aiGoalFollowWayPts()
{
    unimplemented();
}

aiGoalFollowWayPts::aiGoalFollowWayPts(char* arg1, class aiRailSet* arg2, class aiVehicleOpponent* arg3, i16* arg4,
    i16* arg5, i16* arg6, char* arg7, f32 arg8)
{
    unimplemented(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

aiGoalFollowWayPts::~aiGoalFollowWayPts()
{
    unimplemented();
}

class MetaClass* aiGoalFollowWayPts::GetClass()
{
    return stub<thiscall_t<class MetaClass*, aiGoalFollowWayPts*>>(0x46A2D0, this);
}

void aiGoalFollowWayPts::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*, class Bank*>>(0x46A0E0, this, arg1);
}

i32 aiGoalFollowWayPts::Context()
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*>>(0x4668C0, this);
}

void aiGoalFollowWayPts::Dump()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x469E60, this);
}

void aiGoalFollowWayPts::Init()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x4664D0, this);
}

i32 aiGoalFollowWayPts::Priority()
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*>>(0x4669B0, this);
}

void aiGoalFollowWayPts::Reset()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x4669C0, this);
}

void aiGoalFollowWayPts::Update()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x466AB0, this);
}

void aiGoalFollowWayPts::DeclareFields()
{
    return stub<cdecl_t<void>>(0x46A140);
}

void aiGoalFollowWayPts::AddToBlockedRange(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*, f32, f32, f32>>(0x468B00, this, arg1, arg2, arg3);
}

void aiGoalFollowWayPts::AvoidCollision(i32 arg1)
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*, i32>>(0x468CA0, this, arg1);
}

void aiGoalFollowWayPts::AvoidOpponentCollision(class aiVehicleOpponent* arg1)
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*, class aiVehicleOpponent*>>(0x467040, this, arg1);
}

void aiGoalFollowWayPts::CalcSpeed()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x469170, this);
}

class aiPath* aiGoalFollowWayPts::DetRdSegBetweenInts(class aiIntersection* arg1, class aiIntersection* arg2)
{
    return stub<thiscall_t<class aiPath*, aiGoalFollowWayPts*, class aiIntersection*, class aiIntersection*>>(
        0x467E40, this, arg1, arg2);
}

i32 aiGoalFollowWayPts::DetectCollision(i32* arg1)
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*, i32*>>(0x467ED0, this, arg1);
}

class aiVehicleOpponent* aiGoalFollowWayPts::DetectOpponentCollision()
{
    return stub<thiscall_t<class aiVehicleOpponent*, aiGoalFollowWayPts*>>(0x466EA0, this);
}

i32 aiGoalFollowWayPts::LocateWayPtFromInt(class aiIntersection* arg1, class aiPath** arg2)
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*, class aiIntersection*, class aiPath**>>(
        0x467D60, this, arg1, arg2);
}

i32 aiGoalFollowWayPts::LocateWayPtFromRoad(class aiPath* arg1, class aiPath** arg2, class aiPath** arg3)
{
    return stub<thiscall_t<i32, aiGoalFollowWayPts*, class aiPath*, class aiPath**, class aiPath**>>(
        0x4676E0, this, arg1, arg2, arg3);
}

void aiGoalFollowWayPts::PlanRoute()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x4674B0, this);
}

void aiGoalFollowWayPts::SolveTargetPoint()
{
    return stub<thiscall_t<void, aiGoalFollowWayPts*>>(0x469E10, this);
}
