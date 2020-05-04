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

#include "boat.h"

mmBoat::mmBoat()
{
    unimplemented();
}

mmBoat::~mmBoat()
{
    unimplemented();
}

void mmBoat::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmBoat*, class Bank*>>(0xC7820_Offset, this, arg1);
}

void mmBoat::AdjustPhaseOffsets()
{
    return stub<thiscall_t<void, mmBoat*>>(0xC77A0_Offset, this);
}

void mmBoat::CalculateCubics(i32 arg1)
{
    return stub<thiscall_t<void, mmBoat*, i32>>(0xC7910_Offset, this, arg1);
}

void mmBoat::ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4)
{
    return stub<thiscall_t<void, mmBoat*, class Vector3&, class Vector3&, class Vector3&, class Vector3&>>(
        0xC7C90_Offset, this, arg1, arg2, arg3, arg4);
}

class MetaClass* mmBoat::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmBoat*>>(0xC7FC0_Offset, this);
}

void mmBoat::Init(i32 arg1, char* arg2, char* arg3, class Vector3* arg4, i32 arg5, i32 arg6, f32* arg7)
{
    return stub<thiscall_t<void, mmBoat*, i32, char*, char*, class Vector3*, i32, i32, f32*>>(
        0xC7270_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmBoat::Reset()
{
    return stub<thiscall_t<void, mmBoat*>>(0xC7570_Offset, this);
}

void mmBoat::ReverseCalcPathSpeed()
{
    return stub<thiscall_t<void, mmBoat*>>(0xC76A0_Offset, this);
}

void mmBoat::SetPathSpeed()
{
    return stub<thiscall_t<void, mmBoat*>>(0xC7650_Offset, this);
}

void mmBoat::SetRock(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmBoat*, f32, f32>>(0xC7670_Offset, this, arg1, arg2);
}

void mmBoat::SolvePosition(class Vector3& arg1, f32& arg2)
{
    return stub<thiscall_t<void, mmBoat*, class Vector3&, f32&>>(0xC76C0_Offset, this, arg1, arg2);
}

void mmBoat::SolveVector(f32 arg1, class Vector3& arg2, class Vector3& arg3)
{
    return stub<thiscall_t<void, mmBoat*, f32, class Vector3&, class Vector3&>>(0xC7B20_Offset, this, arg1, arg2, arg3);
}

void mmBoat::SolveXZCurve(class Vector3& arg1, class Vector3& arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmBoat*, class Vector3&, class Vector3&, f32>>(0xC7D80_Offset, this, arg1, arg2, arg3);
}

void mmBoat::Update()
{
    return stub<thiscall_t<void, mmBoat*>>(0xC75D0_Offset, this);
}

void mmBoat::UpdatePathPosition()
{
    return stub<thiscall_t<void, mmBoat*>>(0xC7600_Offset, this);
}

void mmBoat::DeclareFields()
{
    return stub<cdecl_t<void>>(0xC7E50_Offset);
}

define_dummy_symbol(mmanim_boat);
