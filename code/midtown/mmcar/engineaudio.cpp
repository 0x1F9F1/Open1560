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

define_dummy_symbol(mmcar_engineaudio);

#include "engineaudio.h"

EngineAudio::EngineAudio()
{
    unimplemented();
}

EngineAudio::~EngineAudio()
{
    unimplemented();
}

void EngineAudio::UpdateRPM(f32 arg1)
{
    return stub<thiscall_t<void, EngineAudio*, f32>>(0x486B30, this, arg1);
}

void EngineAudio::EchoOff()
{
    return stub<thiscall_t<void, EngineAudio*>>(0x486A40, this);
}

void EngineAudio::EchoOn(f32 arg1)
{
    return stub<thiscall_t<void, EngineAudio*, f32>>(0x4869F0, this, arg1);
}

void EngineAudio::EnableClutch(char* arg1, f32 arg2)
{
    return stub<thiscall_t<void, EngineAudio*, char*, f32>>(0x486A70, this, arg1, arg2);
}

class MetaClass* EngineAudio::GetClass()
{
    return stub<thiscall_t<class MetaClass*, EngineAudio*>>(0x4870A0, this);
}

void EngineAudio::Init(class Vector3* arg1)
{
    return stub<thiscall_t<void, EngineAudio*, class Vector3*>>(0x486550, this, arg1);
}

void EngineAudio::Init(char* arg1, char* arg2)
{
    return stub<thiscall_t<void, EngineAudio*, char*, char*>>(0x4867A0, this, arg1, arg2);
}

void EngineAudio::ResetVolume()
{
    return stub<thiscall_t<void, EngineAudio*>>(0x486D90, this);
}

void EngineAudio::Stop()
{
    return stub<thiscall_t<void, EngineAudio*>>(0x486DB0, this);
}

void EngineAudio::DeclareFields()
{
    return stub<cdecl_t<void>>(0x486DF0);
}
