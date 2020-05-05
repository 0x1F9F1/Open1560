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

define_dummy_symbol(mmaudio_mixer);

#include "mixer.h"

VolumeDW::~VolumeDW()
{
    unimplemented();
}

void VolumeDW::Set(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, VolumeDW*, f32, f32>>(0xEE040_Offset, this, arg1, arg2);
}

u32 VolumeDW::Value()
{
    return stub<thiscall_t<u32, VolumeDW*>>(0xEE110_Offset, this);
}

MixerCTL::~MixerCTL()
{
    unimplemented(arg1);
}

void MixerCTL::AssignCDBalance(f32 arg1)
{
    return stub<thiscall_t<void, MixerCTL*, f32>>(0xEE240_Offset, this, arg1);
}

void MixerCTL::AssignCDVolume(f32 arg1)
{
    return stub<thiscall_t<void, MixerCTL*, f32>>(0xEE2E0_Offset, this, arg1);
}

u32 MixerCTL::AssignMixerBalance(f32 arg1, u32 arg2)
{
    return stub<thiscall_t<u32, MixerCTL*, f32, u32>>(0xEE580_Offset, this, arg1, arg2);
}

u32 MixerCTL::AssignMixerVolume(f32 arg1, u32 arg2)
{
    return stub<thiscall_t<u32, MixerCTL*, f32, u32>>(0xEE320_Offset, this, arg1, arg2);
}

void MixerCTL::AssignWaveBalance(f32 arg1)
{
    return stub<thiscall_t<void, MixerCTL*, f32>>(0xEE1F0_Offset, this, arg1);
}

void MixerCTL::AssignWaveVolume(f32 arg1)
{
    return stub<thiscall_t<void, MixerCTL*, f32>>(0xEE2C0_Offset, this, arg1);
}

f32 MixerCTL::GetCDBalance()
{
    return stub<thiscall_t<f32, MixerCTL*>>(0xEE300_Offset, this);
}

f32 MixerCTL::GetCDVolume()
{
    return stub<thiscall_t<f32, MixerCTL*>>(0xEE310_Offset, this);
}

f32 MixerCTL::GetMixerBalance(u32 arg1)
{
    return stub<thiscall_t<f32, MixerCTL*, u32>>(0xEE830_Offset, this, arg1);
}

f32 MixerCTL::GetWaveBalance()
{
    return stub<thiscall_t<f32, MixerCTL*>>(0xEE2A0_Offset, this);
}

f32 MixerCTL::GetWaveVolume()
{
    return stub<thiscall_t<f32, MixerCTL*>>(0xEE2B0_Offset, this);
}

u32 MixerCTL::Init()
{
    return stub<thiscall_t<u32, MixerCTL*>>(0xEE140_Offset, this);
}

void MixerCTL::RefreshAll(u32 arg1)
{
    return stub<thiscall_t<void, MixerCTL*, u32>>(0xEE290_Offset, this, arg1);
}

void MixerCTL::SetDeviceNum(u32 arg1)
{
    return stub<thiscall_t<void, MixerCTL*, u32>>(0xEEAB0_Offset, this, arg1);
}

char* MixerCTL::GetErrorMessage(u32 arg1)
{
    return stub<thiscall_t<char*, MixerCTL*, u32>>(0xEEAD0_Offset, this, arg1);
}

i32 MixerCTL::WindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, MixerCTL*, struct HWND__*, u32, u32, i32>>(
        0xEEB70_Offset, this, arg1, arg2, arg3, arg4);
}
