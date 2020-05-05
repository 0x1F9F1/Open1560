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

define_dummy_symbol(mmcamcs_spline);

#include "spline.h"

Spline::Spline()
{
    unimplemented();
}

Spline::~Spline()
{
    unimplemented(arg1);
}

void Spline::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, Spline*, class Bank*>>(0xFDB80_Offset, this, arg1);
}

void Spline::CalcCoeff()
{
    return stub<thiscall_t<void, Spline*>>(0xFD5B0_Offset, this);
}

void Spline::FixTimeStop()
{
    return stub<thiscall_t<void, Spline*>>(0xFDAF0_Offset, this);
}

class MetaClass* Spline::GetClass()
{
    return stub<thiscall_t<class MetaClass*, Spline*>>(0xFDD00_Offset, this);
}

i32 Spline::InRange()
{
    return stub<thiscall_t<i32, Spline*>>(0xFD550_Offset, this);
}

void Spline::Init(f32* arg1, i32 arg2)
{
    return stub<thiscall_t<void, Spline*, f32*, i32>>(0xFD420_Offset, this, arg1, arg2);
}

void Spline::Print(i32 arg1)
{
    return stub<thiscall_t<void, Spline*, i32>>(0xFD9F0_Offset, this, arg1);
}

void Spline::SetGoal(f32* arg1, f32 arg2)
{
    return stub<thiscall_t<void, Spline*, f32*, f32>>(0xFD790_Offset, this, arg1, arg2);
}

void Spline::SetValue(f32* arg1)
{
    return stub<thiscall_t<void, Spline*, f32*>>(0xFD710_Offset, this, arg1);
}

void Spline::Solve(f32 arg1)
{
    return stub<thiscall_t<void, Spline*, f32>>(0xFD880_Offset, this, arg1);
}

void Spline::Update()
{
    return stub<thiscall_t<void, Spline*>>(0xFDB30_Offset, this);
}

void Spline::DeclareFields()
{
    return stub<cdecl_t<void>>(0xFDB90_Offset);
}
