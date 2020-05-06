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

define_dummy_symbol(mmanim_train);

#include "train.h"

mmAnimTrain::mmAnimTrain()
{
    unimplemented();
}

mmAnimTrain::~mmAnimTrain()
{
    unimplemented();
}

void mmAnimTrain::AdjustPhaseOffsets()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C66D0, this);
}

void mmAnimTrain::CalculateCubics(i32 arg1, class Vector4& arg2, class Vector4& arg3, class Vector4& arg4)
{
    return stub<thiscall_t<void, mmAnimTrain*, i32, class Vector4&, class Vector4&, class Vector4&>>(
        0x4C6890, this, arg1, arg2, arg3, arg4);
}

void mmAnimTrain::ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
    class Vector4& arg5, class Vector4& arg6, class Vector4& arg7)
{
    return stub<thiscall_t<void, mmAnimTrain*, class Vector3&, class Vector3&, class Vector3&, class Vector3&,
        class Vector4&, class Vector4&, class Vector4&>>(0x4C6A90, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmAnimTrain::GetStart(f32 arg1, i32& arg2, f32& arg3)
{
    return stub<thiscall_t<void, mmAnimTrain*, f32, i32&, f32&>>(0x4C6740, this, arg1, arg2, arg3);
}

void mmAnimTrain::Init(i32 arg1, char* arg2, char* arg3, class Vector3* arg4, i32 arg5, i32 arg6, f32* arg7)
{
    return stub<thiscall_t<void, mmAnimTrain*, i32, char*, char*, class Vector3*, i32, i32, f32*>>(
        0x4C6080, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmAnimTrain::PreCalcCubics()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C67C0, this);
}

void mmAnimTrain::Reset()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C6350, this);
}

void mmAnimTrain::ReverseCalcPathSpeed()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C65C0, this);
}

void mmAnimTrain::SetPathSpeed()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C65B0, this);
}

void mmAnimTrain::SolvePosition(class Vector3& arg1, f32& arg2)
{
    return stub<thiscall_t<void, mmAnimTrain*, class Vector3&, f32&>>(0x4C65D0, this, arg1, arg2);
}

void mmAnimTrain::SolveXZCurve(class Vector3& arg1, class Vector3& arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmAnimTrain*, class Vector3&, class Vector3&, f32>>(0x4C6B70, this, arg1, arg2, arg3);
}

void mmAnimTrain::Update()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C63C0, this);
}

void mmAnimTrain::UpdatePathPosition()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C6460, this);
}

void mmAnimTrain::CalculateAudioPanning()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C6ED0, this);
}

void mmAnimTrain::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C6E00, this);
}

f32 mmAnimTrain::CalculateDoppler(f32 arg1)
{
    return stub<thiscall_t<f32, mmAnimTrain*, f32>>(0x4C6F20, this, arg1);
}

void mmAnimTrain::UpdateAudio()
{
    return stub<thiscall_t<void, mmAnimTrain*>>(0x4C6CA0, this);
}
