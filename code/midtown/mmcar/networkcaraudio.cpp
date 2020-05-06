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

define_dummy_symbol(mmcar_networkcaraudio);

#include "networkcaraudio.h"

mmNetworkCarAudio::mmNetworkCarAudio()
{
    unimplemented();
}

mmNetworkCarAudio::mmNetworkCarAudio(class mmCarSim* arg1)
{
    unimplemented(arg1);
}

mmNetworkCarAudio::~mmNetworkCarAudio()
{
    unimplemented(arg1);
}

void mmNetworkCarAudio::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x483EC0, this);
}

void mmNetworkCarAudio::CalculateDoppler()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x483F80, this);
}

void mmNetworkCarAudio::DeactivateAudio()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x483E10, this);
}

void mmNetworkCarAudio::FluctuateFastSiren()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x483A60, this);
}

void mmNetworkCarAudio::FluctuateSlowSiren()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x483810, this);
}

class MetaClass* mmNetworkCarAudio::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmNetworkCarAudio*>>(0x484570, this);
}

void mmNetworkCarAudio::Init(class mmCarSim* arg1, u16 arg2)
{
    return stub<thiscall_t<void, mmNetworkCarAudio*, class mmCarSim*, u16>>(0x4834A0, this, arg1, arg2);
}

void mmNetworkCarAudio::LoadSucessful(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmNetworkCarAudio*, class mmCarSim*>>(0x484320, this, arg1);
}

void mmNetworkCarAudio::RemoveFromManager()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x484300, this);
}

void mmNetworkCarAudio::Reset()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x4842E0, this);
}

void mmNetworkCarAudio::StartSiren()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x484290, this);
}

void mmNetworkCarAudio::StopSiren()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x484250, this);
}

void mmNetworkCarAudio::Update()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x4836A0, this);
}

void mmNetworkCarAudio::UpdateAudio()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x4836E0, this);
}

void mmNetworkCarAudio::UpdateDoppler()
{
    return stub<thiscall_t<void, mmNetworkCarAudio*>>(0x483FA0, this);
}

void mmNetworkCarAudio::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4843A0);
}
