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

#include "waypoints.h"

mmWaypoints::mmWaypoints()
{
    unimplemented();
}

mmWaypoints::~mmWaypoints()
{
    unimplemented();
}

i32 mmWaypoints::AIWPHit(i32 arg1, i32 arg2, class Matrix34 arg3, class Vector3 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32, i32, class Matrix34, class Vector3, f32>>(
        0x2F200_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmWaypoints::AnyAIWPHit(u32& arg1, i32 arg2, class Matrix34 arg3, class Vector3 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, mmWaypoints*, u32&, i32, class Matrix34, class Vector3, f32>>(
        0x2F4C0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmWaypoints::AnyWPHits(i32 arg1)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32>>(0x2FAA0_Offset, this, arg1);
}

i32 mmWaypoints::BlitzRemove(i32 arg1)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32>>(0x2D950_Offset, this, arg1);
}

void mmWaypoints::CalculateGatePoints(class Vector3 arg1, f32 arg2, f32 arg3, class Vector2* arg4, class Vector2* arg5)
{
    return stub<thiscall_t<void, mmWaypoints*, class Vector3, f32, f32, class Vector2*, class Vector2*>>(
        0x2E920_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmWaypoints::ClearWaypoint(i32 arg1)
{
    return stub<thiscall_t<void, mmWaypoints*, i32>>(0x2FF60_Offset, this, arg1);
}

void mmWaypoints::Cull()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2E910_Offset, this);
}

void mmWaypoints::CycleCurrentWaypoint(i32 arg1)
{
    return stub<thiscall_t<void, mmWaypoints*, i32>>(0x2F130_Offset, this, arg1);
}

void mmWaypoints::DeactivateFinish()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2ED30_Offset, this);
}

void mmWaypoints::DisplayHUDMessage(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmWaypoints*, i32, i32>>(0x30020_Offset, this, arg1, arg2);
}

void mmWaypoints::GenerateHitRooms()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2EF00_Offset, this);
}

void mmWaypoints::GetClosestWaypoint()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2F050_Offset, this);
}

f32 mmWaypoints::GetHeading(i32 arg1)
{
    return stub<thiscall_t<f32, mmWaypoints*, i32>>(0x2EED0_Offset, this, arg1);
}

i32 mmWaypoints::GetHitRoom(i32 arg1)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32>>(0x2EF60_Offset, this, arg1);
}

void mmWaypoints::GetLastWaypoint()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2F1B0_Offset, this);
}

void mmWaypoints::GetNextWaypoint()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2F1A0_Offset, this);
}

void mmWaypoints::GetStart(class Vector3& arg1)
{
    return stub<thiscall_t<void, mmWaypoints*, class Vector3&>>(0x2EE40_Offset, this, arg1);
}

f32 mmWaypoints::GetStartAngle()
{
    return stub<thiscall_t<f32, mmWaypoints*>>(0x2DB00_Offset, this);
}

void mmWaypoints::GetWaypoint(i32 arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, mmWaypoints*, i32, class Vector3&>>(0x2EE80_Offset, this, arg1, arg2);
}

i32 mmWaypoints::Init(class mmPlayer* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6)
{
    return stub<thiscall_t<i32, mmWaypoints*, class mmPlayer*, char*, i32, i32, i32, i32>>(
        0x2D9D0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 mmWaypoints::LineIntersect(class Vector2 arg1, class Vector2 arg2, class Vector2 arg3, class Vector2 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, mmWaypoints*, class Vector2, class Vector2, class Vector2, class Vector2, f32>>(
        0x2FD50_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 mmWaypoints::LoadCSV(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmWaypoints*, char*, i32>>(0x2DC20_Offset, this, arg1, arg2);
}

void mmWaypoints::Reset()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2ED50_Offset, this);
}

void mmWaypoints::ResetAllTags()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2F010_Offset, this);
}

void mmWaypoints::SetArrow()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2EF80_Offset, this);
}

void mmWaypoints::SetCurrentGoals(i32 arg1)
{
    return stub<thiscall_t<void, mmWaypoints*, i32>>(0x2F1C0_Offset, this, arg1);
}

void mmWaypoints::Update()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2E9A0_Offset, this);
}

void mmWaypoints::UpdateWPHUD()
{
    return stub<thiscall_t<void, mmWaypoints*>>(0x2EFA0_Offset, this);
}

i32 mmWaypoints::WPHit(i32 arg1, class Vector3 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, mmWaypoints*, i32, class Vector3, i32, i32>>(
        0x2F820_Offset, this, arg1, arg2, arg3, arg4);
}

i32 mmGate::Check(class Vector2 arg1, class Vector2 arg2)
{
    return stub<thiscall_t<i32, mmGate*, class Vector2, class Vector2>>(0x30250_Offset, this, arg1, arg2);
}

i32 mmGate::CloseEnough(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmGate*, f32, f32>>(0x30210_Offset, this, arg1, arg2);
}

void mmGate::Init(class Vector2 arg1, class Vector2 arg2)
{
    return stub<thiscall_t<void, mmGate*, class Vector2, class Vector2>>(0x30170_Offset, this, arg1, arg2);
}

f32 mmGate::LineEq(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<f32, mmGate*, f32, f32>>(0x301F0_Offset, this, arg1, arg2);
}

define_dummy_symbol(mmgame_waypoints);
