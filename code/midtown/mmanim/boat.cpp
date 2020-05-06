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

define_dummy_symbol(mmanim_boat);

#include "boat.h"

mmBoat::mmBoat()
{
    unimplemented();
}

mmBoat::~mmBoat()
{
    unimplemented(arg1);
}

void mmBoat::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmBoat*, class Bank*>>(0x4C7820, this, arg1);
}

void mmBoat::AdjustPhaseOffsets()
{
    return stub<thiscall_t<void, mmBoat*>>(0x4C77A0, this);
}

void mmBoat::CalculateCubics(i32 arg1)
{
    return stub<thiscall_t<void, mmBoat*, i32>>(0x4C7910, this, arg1);
}

void mmBoat::ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4)
{
    return stub<thiscall_t<void, mmBoat*, class Vector3&, class Vector3&, class Vector3&, class Vector3&>>(
        0x4C7C90, this, arg1, arg2, arg3, arg4);
}

class MetaClass* mmBoat::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmBoat*>>(0x4C7FC0, this);
}

void mmBoat::Init(i32 arg1, char* arg2, char* arg3, class Vector3* arg4, i32 arg5, i32 arg6, f32* arg7)
{
    return stub<thiscall_t<void, mmBoat*, i32, char*, char*, class Vector3*, i32, i32, f32*>>(
        0x4C7270, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmBoat::Reset()
{
    return stub<thiscall_t<void, mmBoat*>>(0x4C7570, this);
}

void mmBoat::ReverseCalcPathSpeed()
{
    return stub<thiscall_t<void, mmBoat*>>(0x4C76A0, this);
}

void mmBoat::SetPathSpeed()
{
    return stub<thiscall_t<void, mmBoat*>>(0x4C7650, this);
}

void mmBoat::SetRock(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmBoat*, f32, f32>>(0x4C7670, this, arg1, arg2);
}

void mmBoat::SolvePosition(class Vector3& arg1, f32& arg2)
{
    return stub<thiscall_t<void, mmBoat*, class Vector3&, f32&>>(0x4C76C0, this, arg1, arg2);
}

void mmBoat::SolveVector(f32 arg1, class Vector3& arg2, class Vector3& arg3)
{
    return stub<thiscall_t<void, mmBoat*, f32, class Vector3&, class Vector3&>>(0x4C7B20, this, arg1, arg2, arg3);
}

void mmBoat::SolveXZCurve(class Vector3& arg1, class Vector3& arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmBoat*, class Vector3&, class Vector3&, f32>>(0x4C7D80, this, arg1, arg2, arg3);
}

void mmBoat::Update()
{
    return stub<thiscall_t<void, mmBoat*>>(0x4C75D0, this);
}

void mmBoat::UpdatePathPosition()
{
    return stub<thiscall_t<void, mmBoat*>>(0x4C7600, this);
}

void mmBoat::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4C7E50);
}
