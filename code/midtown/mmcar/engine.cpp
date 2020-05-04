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

#include "engine.h"

mmEngine::mmEngine()
{
    unimplemented();
}

mmEngine::~mmEngine()
{
    unimplemented();
}

void mmEngine::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmEngine*, class Bank*>>(0x7CE70_Offset, this, arg1);
}

void mmEngine::AfterLoad()
{
    return stub<thiscall_t<void, mmEngine*>>(0x7C9D0_Offset, this);
}

f32 mmEngine::CalcTorque(f32 arg1)
{
    return stub<thiscall_t<f32, mmEngine*, f32>>(0x7CBB0_Offset, this, arg1);
}

f32 mmEngine::CalcTorqueAtFullThrottle()
{
    return stub<thiscall_t<f32, mmEngine*>>(0x7CAE0_Offset, this);
}

f32 mmEngine::CalcTorqueAtZeroThrottle()
{
    return stub<thiscall_t<f32, mmEngine*>>(0x7CB70_Offset, this);
}

void mmEngine::ComputeConstants()
{
    return stub<thiscall_t<void, mmEngine*>>(0x7CA60_Offset, this);
}

class MetaClass* mmEngine::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmEngine*>>(0x7D180_Offset, this);
}

void mmEngine::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmEngine*, class mmCarSim*>>(0x7C9A0_Offset, this, arg1);
}

void mmEngine::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, mmEngine*, class Stream*>>(0x7C9E0_Offset, this, arg1);
}

void mmEngine::Reset()
{
    return stub<thiscall_t<void, mmEngine*>>(0x7CC60_Offset, this);
}

void mmEngine::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, mmEngine*, class Stream*>>(0x7CBE0_Offset, this, arg1);
}

void mmEngine::Update()
{
    return stub<thiscall_t<void, mmEngine*>>(0x7CC90_Offset, this);
}

void mmEngine::DeclareFields()
{
    return stub<cdecl_t<void>>(0x7CFC0_Offset);
}

define_dummy_symbol(mmcar_engine);
