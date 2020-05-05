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

define_dummy_symbol(mmanim_bridge);

#include "bridge.h"

mmBridgeMgr::mmBridgeMgr()
{
    unimplemented();
}

mmBridgeMgr::~mmBridgeMgr()
{
    unimplemented(arg1);
}

void mmBridgeMgr::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmBridgeMgr*, class Bank*>>(0xC1CD0_Offset, this, arg1);
}

void mmBridgeMgr::Cull()
{
    return stub<thiscall_t<void, mmBridgeMgr*>>(0xC1860_Offset, this);
}

class MetaClass* mmBridgeMgr::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmBridgeMgr*>>(0xC32E0_Offset, this);
}

void mmBridgeMgr::Init(char* arg1, class mmInstance* arg2, class mmInstance** arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmBridgeMgr*, char*, class mmInstance*, class mmInstance**, i32>>(
        0xC18A0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmBridgeMgr::Save()
{
    return stub<thiscall_t<void, mmBridgeMgr*>>(0xC1CC0_Offset, this);
}

void mmBridgeMgr::ToggleDrawLabels()
{
    return stub<thiscall_t<void, mmBridgeMgr*>>(0xC1850_Offset, this);
}

void mmBridgeMgr::DeclareFields()
{
    return stub<cdecl_t<void>>(0xC3070_Offset);
}

mmBridgeSet::mmBridgeSet()
{
    unimplemented();
}

mmBridgeSet::~mmBridgeSet()
{
    unimplemented(arg1);
}

void mmBridgeSet::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmBridgeSet*, class Bank*>>(0xC27D0_Offset, this, arg1);
}

void mmBridgeSet::Cull()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2730_Offset, this);
}

class MetaClass* mmBridgeSet::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmBridgeSet*>>(0xC3060_Offset, this);
}

i32 mmBridgeSet::Init(char* arg1, class Stream* arg2)
{
    return stub<thiscall_t<i32, mmBridgeSet*, char*, class Stream*>>(0xC22C0_Offset, this, arg1, arg2);
}

void mmBridgeSet::InitTrigger()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2290_Offset, this);
}

i32 mmBridgeSet::ReadEntry(class Stream* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmBridgeSet*, class Stream*, i32>>(0xC2150_Offset, this, arg1, arg2);
}

void mmBridgeSet::Reset()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2080_Offset, this);
}

void mmBridgeSet::SetSoundPtrs(class AudSound* arg1, class AudSound* arg2)
{
    return stub<thiscall_t<void, mmBridgeSet*, class AudSound*, class AudSound*>>(0xC2E20_Offset, this, arg1, arg2);
}

void mmBridgeSet::UnAssignSounds()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2E00_Offset, this);
}

void mmBridgeSet::Update()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2380_Offset, this);
}

void mmBridgeSet::UpdateAudio()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2A40_Offset, this);
}

void mmBridgeSet::DeclareFields()
{
    return stub<cdecl_t<void>>(0xC29A0_Offset);
}

void mmBridgeSet::CalculateAudioPanning()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2D80_Offset, this);
}

void mmBridgeSet::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2CA0_Offset, this);
}

f32 mmBridgeSet::CalculateDoppler(f32 arg1)
{
    return stub<thiscall_t<f32, mmBridgeSet*, f32>>(0xC2DD0_Offset, this, arg1);
}

void mmBridgeSet::RampDownBridgeVolume()
{
    return stub<thiscall_t<void, mmBridgeSet*>>(0xC2E80_Offset, this);
}
