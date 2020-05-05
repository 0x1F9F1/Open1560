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

define_dummy_symbol(mmcar_wheel);

#include "wheel.h"

mmWheel::mmWheel()
{
    unimplemented();
}

mmWheel::~mmWheel()
{
    unimplemented(arg1);
}

void mmWheel::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmWheel*, class Bank*>>(0x7F6D0_Offset, this, arg1);
}

void mmWheel::AfterLoad()
{
    return stub<thiscall_t<void, mmWheel*>>(0x7DA10_Offset, this);
}

void mmWheel::ComputeConstants()
{
    return stub<thiscall_t<void, mmWheel*>>(0x7D950_Offset, this);
}

f32 mmWheel::ComputeDwtdw(f32 arg1, f32* arg2, f32* arg3, f32* arg4)
{
    return stub<thiscall_t<f32, mmWheel*, f32, f32*, f32*, f32*>>(0x7DBB0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmWheel::CopyVars(class mmWheel* arg1)
{
    return stub<thiscall_t<void, mmWheel*, class mmWheel*>>(0x7F5F0_Offset, this, arg1);
}

void mmWheel::GenerateSkidParticles()
{
    return stub<thiscall_t<void, mmWheel*>>(0x7F340_Offset, this);
}

class MetaClass* mmWheel::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmWheel*>>(0x7FDC0_Offset, this);
}

i32 mmWheel::GetSurfaceSound()
{
    return stub<thiscall_t<i32, mmWheel*>>(0x7F6B0_Offset, this);
}

void mmWheel::Init(char* arg1, char* arg2, class Vector3 arg3, class asInertialCS* arg4, i32 arg5,
    class mmBoundTemplate* arg6, i32 arg7)
{
    return stub<
        thiscall_t<void, mmWheel*, char*, char*, class Vector3, class asInertialCS*, i32, class mmBoundTemplate*, i32>>(
        0x7DA20_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmWheel::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, mmWheel*, class Stream*>>(0x7F3B0_Offset, this, arg1);
}

void mmWheel::Reset()
{
    return stub<thiscall_t<void, mmWheel*>>(0x7F2D0_Offset, this);
}

void mmWheel::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, mmWheel*, class Stream*>>(0x7F4B0_Offset, this, arg1);
}

void mmWheel::SetFricMultiplier(f32 arg1)
{
    return stub<thiscall_t<void, mmWheel*, f32>>(0x7F380_Offset, this, arg1);
}

void mmWheel::SetInputs(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmWheel*, f32, f32>>(0x7F360_Offset, this, arg1, arg2);
}

void mmWheel::SetSteerMultiplier(f32 arg1)
{
    return stub<thiscall_t<void, mmWheel*, f32>>(0x7F3A0_Offset, this, arg1);
}

void mmWheel::Update()
{
    return stub<thiscall_t<void, mmWheel*>>(0x7E3E0_Offset, this);
}

void mmWheel::DeclareFields()
{
    return stub<cdecl_t<void>>(0x7FB00_Offset);
}
