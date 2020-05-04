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

#include "engineaudioopponent.h"

EngineAudioOpponent::EngineAudioOpponent()
{
    unimplemented();
}

EngineAudioOpponent::~EngineAudioOpponent()
{
    unimplemented();
}

void EngineAudioOpponent::ClearName()
{
    return stub<thiscall_t<void, EngineAudioOpponent*>>(0x85A10_Offset, this);
}

void EngineAudioOpponent::Disable3DMode()
{
    return stub<thiscall_t<void, EngineAudioOpponent*>>(0x85A50_Offset, this);
}

void EngineAudioOpponent::Enable3DMode(class Vector3* arg1)
{
    return stub<thiscall_t<void, EngineAudioOpponent*, class Vector3*>>(0x85A30_Offset, this, arg1);
}

class MetaClass* EngineAudioOpponent::GetClass()
{
    return stub<thiscall_t<class MetaClass*, EngineAudioOpponent*>>(0x85C70_Offset, this);
}

void EngineAudioOpponent::Init()
{
    return stub<thiscall_t<void, EngineAudioOpponent*>>(0x85890_Offset, this);
}

void EngineAudioOpponent::Init(i16 arg1)
{
    return stub<thiscall_t<void, EngineAudioOpponent*, i16>>(0x85900_Offset, this, arg1);
}

void EngineAudioOpponent::SetSoundPtr(class AudSound* arg1)
{
    return stub<thiscall_t<void, EngineAudioOpponent*, class AudSound*>>(0x77810_Offset, this, arg1);
}

void EngineAudioOpponent::UpdateRPM(f32 arg1)
{
    return stub<thiscall_t<void, EngineAudioOpponent*, f32>>(0x85940_Offset, this, arg1);
}

void EngineAudioOpponent::DeclareFields()
{
    return stub<cdecl_t<void>>(0x85A60_Offset);
}

define_dummy_symbol(mmcar_engineaudioopponent);
