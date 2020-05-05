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

define_dummy_symbol(mmanim_plane);

#include "plane.h"

mmAnimPlane::mmAnimPlane()
{
    unimplemented();
}

mmAnimPlane::~mmAnimPlane()
{
    unimplemented(arg1);
}

void mmAnimPlane::Activate()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5330_Offset, this);
}

void mmAnimPlane::AdjustPhaseOffsets()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5630_Offset, this);
}

void mmAnimPlane::CalculateCubics(i32 arg1, class Vector4& arg2, class Vector4& arg3, class Vector4& arg4)
{
    return stub<thiscall_t<void, mmAnimPlane*, i32, class Vector4&, class Vector4&, class Vector4&>>(
        0xC5770_Offset, this, arg1, arg2, arg3, arg4);
}

void mmAnimPlane::Deactivate()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5340_Offset, this);
}

void __fastcall mmAnimPlane::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmAnimPlane*, i32>>(0xC5A70_Offset, this, arg1);
}

void mmAnimPlane::Init(i32 arg1, char* arg2, char* arg3, class Vector3* arg4, i32 arg5, i32 arg6, f32* arg7)
{
    return stub<thiscall_t<void, mmAnimPlane*, i32, char*, char*, class Vector3*, i32, i32, f32*>>(
        0xC50C0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmAnimPlane::PreCalcCubics()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC56A0_Offset, this);
}

void mmAnimPlane::Reset()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC52C0_Offset, this);
}

void mmAnimPlane::ReverseCalcPathSpeed()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5550_Offset, this);
}

void mmAnimPlane::SetPathSpeed()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5540_Offset, this);
}

void mmAnimPlane::SolvePosition(class Vector3& arg1, f32& arg2)
{
    return stub<thiscall_t<void, mmAnimPlane*, class Vector3&, f32&>>(0xC5560_Offset, this, arg1, arg2);
}

void mmAnimPlane::SolveVector(f32 arg1, class Vector3& arg2, class Vector3& arg3)
{
    return stub<thiscall_t<void, mmAnimPlane*, f32, class Vector3&, class Vector3&>>(
        0xC58F0_Offset, this, arg1, arg2, arg3);
}

void mmAnimPlane::Update()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5350_Offset, this);
}

void mmAnimPlane::UpdatePathPosition()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5370_Offset, this);
}

void mmAnimPlane::CalculateAudioPanning()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5CF0_Offset, this);
}

void mmAnimPlane::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5C20_Offset, this);
}

f32 mmAnimPlane::CalculateDoppler(f32 arg1)
{
    return stub<thiscall_t<f32, mmAnimPlane*, f32>>(0xC5D40_Offset, this, arg1);
}

void mmAnimPlane::UpdateAudio()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0xC5AC0_Offset, this);
}
