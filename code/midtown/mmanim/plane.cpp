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
    unimplemented();
}

void mmAnimPlane::Activate()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5330, this);
}

void mmAnimPlane::AdjustPhaseOffsets()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5630, this);
}

void mmAnimPlane::CalculateCubics(i32 arg1, class Vector4& arg2, class Vector4& arg3, class Vector4& arg4)
{
    return stub<thiscall_t<void, mmAnimPlane*, i32, class Vector4&, class Vector4&, class Vector4&>>(
        0x4C5770, this, arg1, arg2, arg3, arg4);
}

void mmAnimPlane::Deactivate()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5340, this);
}

void __fastcall mmAnimPlane::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmAnimPlane*, i32>>(0x4C5A70, this, arg1);
}

void mmAnimPlane::Init(i32 arg1, char* arg2, char* arg3, class Vector3* arg4, i32 arg5, i32 arg6, f32* arg7)
{
    return stub<thiscall_t<void, mmAnimPlane*, i32, char*, char*, class Vector3*, i32, i32, f32*>>(
        0x4C50C0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmAnimPlane::PreCalcCubics()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C56A0, this);
}

void mmAnimPlane::Reset()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C52C0, this);
}

void mmAnimPlane::ReverseCalcPathSpeed()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5550, this);
}

void mmAnimPlane::SetPathSpeed()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5540, this);
}

void mmAnimPlane::SolvePosition(class Vector3& arg1, f32& arg2)
{
    return stub<thiscall_t<void, mmAnimPlane*, class Vector3&, f32&>>(0x4C5560, this, arg1, arg2);
}

void mmAnimPlane::SolveVector(f32 arg1, class Vector3& arg2, class Vector3& arg3)
{
    return stub<thiscall_t<void, mmAnimPlane*, f32, class Vector3&, class Vector3&>>(0x4C58F0, this, arg1, arg2, arg3);
}

void mmAnimPlane::Update()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5350, this);
}

void mmAnimPlane::UpdatePathPosition()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5370, this);
}

void mmAnimPlane::CalculateAudioPanning()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5CF0, this);
}

void mmAnimPlane::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5C20, this);
}

f32 mmAnimPlane::CalculateDoppler(f32 arg1)
{
    return stub<thiscall_t<f32, mmAnimPlane*, f32>>(0x4C5D40, this, arg1);
}

void mmAnimPlane::UpdateAudio()
{
    return stub<thiscall_t<void, mmAnimPlane*>>(0x4C5AC0, this);
}
