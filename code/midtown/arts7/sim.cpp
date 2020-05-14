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

define_dummy_symbol(arts7_sim);

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
    return stub<thiscall_t<void, asSimulation*, class Bank*>>(0x522FD0, this, arg1);
}

void asSimulation::BeginOverSample(i32 arg1)
{
    return stub<thiscall_t<void, asSimulation*, i32>>(0x522CF0, this, arg1);
}

void asSimulation::Benchmark()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522E40, this);
}

void asSimulation::Cull()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522C20, this);
}

void asSimulation::DeclareVector(class Vector3 const* arg1, class Vector3 const* arg2, class Vector3 const* arg3)
{
    return stub<thiscall_t<void, asSimulation*, class Vector3 const*, class Vector3 const*, class Vector3 const*>>(
        0x522B80, this, arg1, arg2, arg3);
}

void asSimulation::Device()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522600, this);
}

void asSimulation::EndOverSample()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522D30, this);
}

void asSimulation::EndOverSample(i32 arg1)
{
    return stub<thiscall_t<void, asSimulation*, i32>>(0x522D60, this, arg1);
}

void asSimulation::FirstUpdate()
{
    return stub<thiscall_t<void, asSimulation*>>(0x5222A0, this);
}

void asSimulation::FixedFrame(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asSimulation*, f32, i32>>(0x522DF0, this, arg1, arg2);
}

void asSimulation::FrameLock(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asSimulation*, i32, i32>>(0x522E30, this, arg1, arg2);
}

class MetaClass* asSimulation::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asSimulation*>>(0x5236A0, this);
}

void asSimulation::Init(char* arg1, i32 arg2, char** arg3)
{
    return stub<thiscall_t<void, asSimulation*, char*, i32, char**>>(0x521C40, this, arg1, arg2, arg3);
}

void asSimulation::OpenPhysicsBank()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522FA0, this);
}

void asSimulation::Pause()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522EC0, this);
}

void asSimulation::Quiet()
{
    return stub<thiscall_t<void, asSimulation*>>(0x521C10, this);
}

void asSimulation::RealTime(f32 arg1)
{
    return stub<thiscall_t<void, asSimulation*, f32>>(0x522D90, this, arg1);
}

void asSimulation::Reset()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522290, this);
}

void asSimulation::ResetClock()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522CA0, this);
}

void asSimulation::Simulate()
{
    return stub<thiscall_t<void, asSimulation*>>(0x522A60, this);
}

void asSimulation::Update()
{
    return stub<thiscall_t<void, asSimulation*>>(0x5222C0, this);
}

void asSimulation::UpdatePaused(class asNode* arg1)
{
    return stub<thiscall_t<void, asSimulation*, class asNode*>>(0x522B10, this, arg1);
}

void asSimulation::Widgets()
{
    return stub<thiscall_t<void, asSimulation*>>(0x5229C0, this);
}

void asSimulation::DeclareFields()
{
    return stub<cdecl_t<void>>(0x523530);
}

void InitBank(i32 arg1, char** arg2)
{
    return stub<cdecl_t<void, i32, char**>>(0x522FC0, arg1, arg2);
}

i32 InitPipeline(char* arg1, i32 arg2, char** arg3)
{
    return stub<cdecl_t<i32, char*, i32, char**>>(0x523210, arg1, arg2, arg3);
}

i32 RestartPipeline(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<cdecl_t<i32, i32, i32, i32, i32, i32>>(0x523340, arg1, arg2, arg3, arg4, arg5);
}

void ShutdownPipeline()
{
    return stub<cdecl_t<void>>(0x5232D0);
}

f64 invert(f64 arg1)
{
    return stub<cdecl_t<f64, f64>>(0x5225F0, arg1);
}

static i32 IsValidPointer(void* arg1, u32 arg2, i32 arg3)
{
    return stub<cdecl_t<i32, void*, u32, i32>>(0x523510, arg1, arg2, arg3);
}

static void QuietPrinter(i32 arg1, char const* arg2, char* arg3)
{
    return stub<cdecl_t<void, i32, char const*, char*>>(0x521C20, arg1, arg2, arg3);
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
    return stub<thiscall_t<void, artsReplayChannel*, class Stream*>>(0x523710, this, arg1);
}

void artsReplayChannel::DoRecord(class Stream* arg1)
{
    return stub<thiscall_t<void, artsReplayChannel*, class Stream*>>(0x5236D0, this, arg1);
}
