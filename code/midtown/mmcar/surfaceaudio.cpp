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

#include "surfaceaudio.h"

mmSurfaceAudio::mmSurfaceAudio(class mmCarSim* arg1, class Vector3* arg2)
{
    unimplemented();
}

mmSurfaceAudio::~mmSurfaceAudio()
{
    unimplemented();
}

void mmSurfaceAudio::DisableSurface()
{
    return stub<thiscall_t<void, mmSurfaceAudio*>>(0x87B00_Offset, this);
}

void mmSurfaceAudio::EchoOff(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, class mmCarSim*>>(0x87740_Offset, this, arg1);
}

void mmSurfaceAudio::EchoOn(class mmCarSim* arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, class mmCarSim*, f32>>(0x87630_Offset, this, arg1, arg2);
}

i32 mmSurfaceAudio::EnableAir(class mmCarSim* arg1)
{
    return stub<thiscall_t<i32, mmSurfaceAudio*, class mmCarSim*>>(0x877F0_Offset, this, arg1);
}

i32 mmSurfaceAudio::EnableSurface(class mmCarSim* arg1)
{
    return stub<thiscall_t<i32, mmSurfaceAudio*, class mmCarSim*>>(0x87970_Offset, this, arg1);
}

i32 mmSurfaceAudio::EnableSuspension(class mmCarSim* arg1)
{
    return stub<thiscall_t<i32, mmSurfaceAudio*, class mmCarSim*>>(0x878C0_Offset, this, arg1);
}

void mmSurfaceAudio::EnableTireWobble()
{
    return stub<thiscall_t<void, mmSurfaceAudio*>>(0x87580_Offset, this);
}

i16 mmSurfaceAudio::OnTwoWheels()
{
    return stub<thiscall_t<i16, mmSurfaceAudio*>>(0x88E90_Offset, this);
}

void mmSurfaceAudio::SetWheelPointers(
    class mmWheel* arg1, class mmWheel* arg2, class mmWheel* arg3, class mmWheel* arg4)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, class mmWheel*, class mmWheel*, class mmWheel*, class mmWheel*>>(
        0x87B20_Offset, this, arg1, arg2, arg3, arg4);
}

void mmSurfaceAudio::SetWobblePitch(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32, f32>>(0x88F20_Offset, this, arg1, arg2);
}

void mmSurfaceAudio::SetWobbleVol(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32, f32>>(0x88F40_Offset, this, arg1, arg2);
}

void mmSurfaceAudio::Update(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x87B50_Offset, this, arg1);
}

void mmSurfaceAudio::UpdateSkidClear(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x882C0_Offset, this, arg1);
}

void mmSurfaceAudio::UpdateSkidRain(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x88680_Offset, this, arg1);
}

void mmSurfaceAudio::UpdateSkidSnow(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x88A50_Offset, this, arg1);
}

void mmSurfaceAudio::UpdateSurface(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x87D30_Offset, this, arg1);
}

void mmSurfaceAudio::UpdateSurfaceSnow(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x87FB0_Offset, this, arg1);
}

void mmSurfaceAudio::UpdateSuspension()
{
    return stub<thiscall_t<void, mmSurfaceAudio*>>(0x88D80_Offset, this);
}

void mmSurfaceAudio::UpdateTireWobble()
{
    return stub<thiscall_t<void, mmSurfaceAudio*>>(0x87BE0_Offset, this);
}

void mmSurfaceAudio::PlayCobble(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x88190_Offset, this, arg1);
}

define_dummy_symbol(mmcar_surfaceaudio);
