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

define_dummy_symbol(mmcar_engine);

#include "engine.h"

mmEngine::mmEngine()
{
    unimplemented();
}

mmEngine::~mmEngine()
{
    unimplemented(arg1);
}

void mmEngine::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmEngine*, class Bank*>>(0x47CE70, this, arg1);
}

void mmEngine::AfterLoad()
{
    return stub<thiscall_t<void, mmEngine*>>(0x47C9D0, this);
}

f32 mmEngine::CalcTorque(f32 arg1)
{
    return stub<thiscall_t<f32, mmEngine*, f32>>(0x47CBB0, this, arg1);
}

f32 mmEngine::CalcTorqueAtFullThrottle()
{
    return stub<thiscall_t<f32, mmEngine*>>(0x47CAE0, this);
}

f32 mmEngine::CalcTorqueAtZeroThrottle()
{
    return stub<thiscall_t<f32, mmEngine*>>(0x47CB70, this);
}

void mmEngine::ComputeConstants()
{
    return stub<thiscall_t<void, mmEngine*>>(0x47CA60, this);
}

class MetaClass* mmEngine::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmEngine*>>(0x47D180, this);
}

void mmEngine::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmEngine*, class mmCarSim*>>(0x47C9A0, this, arg1);
}

void mmEngine::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, mmEngine*, class Stream*>>(0x47C9E0, this, arg1);
}

void mmEngine::Reset()
{
    return stub<thiscall_t<void, mmEngine*>>(0x47CC60, this);
}

void mmEngine::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, mmEngine*, class Stream*>>(0x47CBE0, this, arg1);
}

void mmEngine::Update()
{
    return stub<thiscall_t<void, mmEngine*>>(0x47CC90, this);
}

void mmEngine::DeclareFields()
{
    return stub<cdecl_t<void>>(0x47CFC0);
}
