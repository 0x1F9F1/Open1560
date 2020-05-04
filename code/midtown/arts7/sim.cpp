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

#include "sim.h"

asSimulation::asSimulation()
{
    unimplemented();
}

asSimulation::~asSimulation()
{
    unimplemented();
}

void asSimulation::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asSimulation*, class Bank*>>(0x122FD0_Offset, this, arg1);
}

void asSimulation::BeginOverSample(i32 arg1)
{
    return stub<thiscall_t<void, asSimulation*, i32>>(0x122CF0_Offset, this, arg1);
}

void asSimulation::Benchmark()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122E40_Offset, this);
}

void asSimulation::Cull()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122C20_Offset, this);
}

void asSimulation::DeclareVector(class Vector3 const* arg1, class Vector3 const* arg2, class Vector3 const* arg3)
{
    return stub<thiscall_t<void, asSimulation*, class Vector3 const*, class Vector3 const*, class Vector3 const*>>(
        0x122B80_Offset, this, arg1, arg2, arg3);
}

void asSimulation::Device()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122600_Offset, this);
}

void asSimulation::EndOverSample()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122D30_Offset, this);
}

void asSimulation::EndOverSample(i32 arg1)
{
    return stub<thiscall_t<void, asSimulation*, i32>>(0x122D60_Offset, this, arg1);
}

void asSimulation::FirstUpdate()
{
    return stub<thiscall_t<void, asSimulation*>>(0x1222A0_Offset, this);
}

void asSimulation::FixedFrame(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asSimulation*, f32, i32>>(0x122DF0_Offset, this, arg1, arg2);
}

void asSimulation::FrameLock(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asSimulation*, i32, i32>>(0x122E30_Offset, this, arg1, arg2);
}

class MetaClass* asSimulation::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asSimulation*>>(0x1236A0_Offset, this);
}

void asSimulation::Init(char* arg1, i32 arg2, char** arg3)
{
    return stub<thiscall_t<void, asSimulation*, char*, i32, char**>>(0x121C40_Offset, this, arg1, arg2, arg3);
}

void asSimulation::OpenPhysicsBank()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122FA0_Offset, this);
}

void asSimulation::Pause()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122EC0_Offset, this);
}

void asSimulation::Quiet()
{
    return stub<thiscall_t<void, asSimulation*>>(0x121C10_Offset, this);
}

void asSimulation::RealTime(f32 arg1)
{
    return stub<thiscall_t<void, asSimulation*, f32>>(0x122D90_Offset, this, arg1);
}

void asSimulation::Reset()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122290_Offset, this);
}

void asSimulation::ResetClock()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122CA0_Offset, this);
}

void asSimulation::Simulate()
{
    return stub<thiscall_t<void, asSimulation*>>(0x122A60_Offset, this);
}

void asSimulation::Update()
{
    return stub<thiscall_t<void, asSimulation*>>(0x1222C0_Offset, this);
}

void asSimulation::UpdatePaused(class asNode* arg1)
{
    return stub<thiscall_t<void, asSimulation*, class asNode*>>(0x122B10_Offset, this, arg1);
}

void asSimulation::Widgets()
{
    return stub<thiscall_t<void, asSimulation*>>(0x1229C0_Offset, this);
}

void asSimulation::DeclareFields()
{
    return stub<cdecl_t<void>>(0x123530_Offset);
}

void InitBank(i32 arg1, char** arg2)
{
    return stub<cdecl_t<void, i32, char**>>(0x122FC0_Offset, arg1, arg2);
}

i32 InitPipeline(char* arg1, i32 arg2, char** arg3)
{
    return stub<cdecl_t<i32, char*, i32, char**>>(0x123210_Offset, arg1, arg2, arg3);
}

i32 RestartPipeline(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<cdecl_t<i32, i32, i32, i32, i32, i32>>(0x123340_Offset, arg1, arg2, arg3, arg4, arg5);
}

void ShutdownPipeline()
{
    return stub<cdecl_t<void>>(0x1232D0_Offset);
}

f64 invert(f64 arg1)
{
    return stub<cdecl_t<f64, f64>>(0x1225F0_Offset, arg1);
}

artsReplayChannel::artsReplayChannel()
{
    unimplemented();
}

artsReplayChannel::~artsReplayChannel()
{
    unimplemented();
}

void artsReplayChannel::DoPlayback(class Stream* arg1)
{
    return stub<thiscall_t<void, artsReplayChannel*, class Stream*>>(0x123710_Offset, this, arg1);
}

void artsReplayChannel::DoRecord(class Stream* arg1)
{
    return stub<thiscall_t<void, artsReplayChannel*, class Stream*>>(0x1236D0_Offset, this, arg1);
}

define_dummy_symbol(arts7_sim);
