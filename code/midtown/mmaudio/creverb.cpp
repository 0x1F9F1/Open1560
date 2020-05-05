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

define_dummy_symbol(mmaudio_creverb);

#include "creverb.h"

CReverb::CReverb(struct IDirectSound3DBuffer* arg1)
{
    unimplemented(arg1);
}

CReverb::~CReverb()
{
    unimplemented();
}

void CReverb::GetAll(struct EAX_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<void, CReverb*, struct EAX_REVERBPROPERTIES*>>(0xF4A70_Offset, this, arg1);
}

f32 CReverb::GetDamping()
{
    return stub<thiscall_t<f32, CReverb*>>(0xF4A30_Offset, this);
}

f32 CReverb::GetDecayTime()
{
    return stub<thiscall_t<f32, CReverb*>>(0xF49F0_Offset, this);
}

u32 CReverb::GetEnvironment()
{
    return stub<thiscall_t<u32, CReverb*>>(0xF4970_Offset, this);
}

f32 CReverb::GetVolume()
{
    return stub<thiscall_t<f32, CReverb*>>(0xF49B0_Offset, this);
}

i32 CReverb::PropertySetOk()
{
    return stub<thiscall_t<i32, CReverb*>>(0xF4810_Offset, this);
}

void CReverb::SetAll(struct EAX_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<void, CReverb*, struct EAX_REVERBPROPERTIES*>>(0xF48F0_Offset, this, arg1);
}

void CReverb::SetDamping(f32 arg1)
{
    return stub<thiscall_t<void, CReverb*, f32>>(0xF48D0_Offset, this, arg1);
}

void CReverb::SetDecayTime(f32 arg1)
{
    return stub<thiscall_t<void, CReverb*, f32>>(0xF48B0_Offset, this, arg1);
}

void CReverb::SetEnvironment(u32 arg1)
{
    return stub<thiscall_t<void, CReverb*, u32>>(0xF4870_Offset, this, arg1);
}

void CReverb::SetPreset(struct EAX_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<void, CReverb*, struct EAX_REVERBPROPERTIES*>>(0xF4950_Offset, this, arg1);
}

void CReverb::SetPreset(u32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, CReverb*, u32, f32, f32, f32>>(0xF4910_Offset, this, arg1, arg2, arg3, arg4);
}

void CReverb::SetVolume(f32 arg1)
{
    return stub<thiscall_t<void, CReverb*, f32>>(0xF4890_Offset, this, arg1);
}

i32 CReverb::QueryProperty(u32 arg1)
{
    return stub<thiscall_t<i32, CReverb*, u32>>(0xF4820_Offset, this, arg1);
}
