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

define_dummy_symbol(mmgame_waypoints);

#include "waypoints.h"

mmWaypoints::mmWaypoints()
{
    unimplemented();
}

mmWaypoints::~mmWaypoints()
{
    unimplemented(arg1);
}

i32 mmWaypoints::AIWPHit(i32 arg1, i32 arg2, class Matrix34 arg3, class Vector3 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32, i32, class Matrix34, class Vector3, f32>>(
        0x42F200, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmWaypoints::AnyAIWPHit(u32& arg1, i32 arg2, class Matrix34 arg3, class Vector3 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, mmWaypoints*, u32&, i32, class Matrix34, class Vector3, f32>>(
        0x42F4C0, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmWaypoints::AnyWPHits(i32 arg1)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32>>(0x42FAA0, this, arg1);
}

i32 mmWaypoints::BlitzRemove(i32 arg1)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32>>(0x42D950, this, arg1);
}

void mmWaypoints::CalculateGatePoints(class Vector3 arg1, f32 arg2, f32 arg3, class Vector2* arg4, class Vector2* arg5)
{
    return stub<thiscall_t<void, mmWaypoints*, class Vector3, f32, f32, class Vector2*, class Vector2*>>(
        0x42E920, this, arg1, arg2, arg3, arg4, arg5);
}

void mmWaypoints::ClearWaypoint(i32 arg1)
{
    return stub<thiscall_t<void, mmWaypoints*, i32>>(0x42FF60, this, arg1);
}

void mmWaypoints::Cull()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42E910, this);
}

void mmWaypoints::CycleCurrentWaypoint(i32 arg1)
{
    return stub<thiscall_t<void, mmWaypoints*, i32>>(0x42F130, this, arg1);
}

void mmWaypoints::DeactivateFinish()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42ED30, this);
}

void mmWaypoints::DisplayHUDMessage(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmWaypoints*, i32, i32>>(0x430020, this, arg1, arg2);
}

void mmWaypoints::GenerateHitRooms()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42EF00, this);
}

void mmWaypoints::GetClosestWaypoint()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42F050, this);
}

f32 mmWaypoints::GetHeading(i32 arg1)
{
    return stub<thiscall_t<f32, mmWaypoints*, i32>>(0x42EED0, this, arg1);
}

i32 mmWaypoints::GetHitRoom(i32 arg1)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32>>(0x42EF60, this, arg1);
}

void mmWaypoints::GetLastWaypoint()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42F1B0, this);
}

void mmWaypoints::GetNextWaypoint()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42F1A0, this);
}

void mmWaypoints::GetStart(class Vector3& arg1)
{
    return stub<thiscall_t<void, mmWaypoints*, class Vector3&>>(0x42EE40, this, arg1);
}

f32 mmWaypoints::GetStartAngle()
{
    return stub<thiscall_t<f32, mmWaypoints*>>(0x42DB00, this);
}

void mmWaypoints::GetWaypoint(i32 arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, mmWaypoints*, i32, class Vector3&>>(0x42EE80, this, arg1, arg2);
}

i32 mmWaypoints::Init(class mmPlayer* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6)
{
    return stub<thiscall_t<i32, mmWaypoints*, class mmPlayer*, char*, i32, i32, i32, i32>>(
        0x42D9D0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 mmWaypoints::LineIntersect(class Vector2 arg1, class Vector2 arg2, class Vector2 arg3, class Vector2 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, mmWaypoints*, class Vector2, class Vector2, class Vector2, class Vector2, f32>>(
        0x42FD50, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmWaypoints::LoadCSV(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmWaypoints*, char*, i32>>(0x42DC20, this, arg1, arg2);
}

void mmWaypoints::Reset()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42ED50, this);
}

void mmWaypoints::ResetAllTags()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42F010, this);
}

void mmWaypoints::SetArrow()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42EF80, this);
}

void mmWaypoints::SetCurrentGoals(i32 arg1)
{
    return stub<thiscall_t<void, mmWaypoints*, i32>>(0x42F1C0, this, arg1);
}

void mmWaypoints::Update()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42E9A0, this);
}

void mmWaypoints::UpdateWPHUD()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x42EFA0, this);
}

i32 mmWaypoints::WPHit(i32 arg1, class Vector3 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32, class Vector3, i32, i32>>(0x42F820, this, arg1, arg2, arg3, arg4);
}

i32 mmGate::Check(class Vector2 arg1, class Vector2 arg2)
{
    return stub<thiscall_t<i32, mmGate*, class Vector2, class Vector2>>(0x430250, this, arg1, arg2);
}

i32 mmGate::CloseEnough(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmGate*, f32, f32>>(0x430210, this, arg1, arg2);
}

void mmGate::Init(class Vector2 arg1, class Vector2 arg2)
{
    return stub<thiscall_t<void, mmGate*, class Vector2, class Vector2>>(0x430170, this, arg1, arg2);
}

f32 mmGate::LineEq(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<f32, mmGate*, f32, f32>>(0x4301F0, this, arg1, arg2);
}
