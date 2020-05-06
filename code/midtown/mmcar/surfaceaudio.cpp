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

define_dummy_symbol(mmcar_surfaceaudio);

#include "surfaceaudio.h"

mmSurfaceAudio::mmSurfaceAudio(class mmCarSim* arg1, class Vector3* arg2)
{
    unimplemented(arg1, arg2);
}

mmSurfaceAudio::~mmSurfaceAudio()
{
    unimplemented();
}

void mmSurfaceAudio::DisableSurface()
{
    return stub<thiscall_t<void, mmSurfaceAudio*>>(0x487B00, this);
}

void mmSurfaceAudio::EchoOff(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, class mmCarSim*>>(0x487740, this, arg1);
}

void mmSurfaceAudio::EchoOn(class mmCarSim* arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, class mmCarSim*, f32>>(0x487630, this, arg1, arg2);
}

i32 mmSurfaceAudio::EnableAir(class mmCarSim* arg1)
{
    return stub<thiscall_t<i32, mmSurfaceAudio*, class mmCarSim*>>(0x4877F0, this, arg1);
}

i32 mmSurfaceAudio::EnableSurface(class mmCarSim* arg1)
{
    return stub<thiscall_t<i32, mmSurfaceAudio*, class mmCarSim*>>(0x487970, this, arg1);
}

i32 mmSurfaceAudio::EnableSuspension(class mmCarSim* arg1)
{
    return stub<thiscall_t<i32, mmSurfaceAudio*, class mmCarSim*>>(0x4878C0, this, arg1);
}

void mmSurfaceAudio::EnableTireWobble()
{
    return stub<thiscall_t<void, mmSurfaceAudio*>>(0x487580, this);
}

i16 mmSurfaceAudio::OnTwoWheels()
{
    return stub<thiscall_t<i16, mmSurfaceAudio*>>(0x488E90, this);
}

void mmSurfaceAudio::SetWheelPointers(
    class mmWheel* arg1, class mmWheel* arg2, class mmWheel* arg3, class mmWheel* arg4)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, class mmWheel*, class mmWheel*, class mmWheel*, class mmWheel*>>(
        0x487B20, this, arg1, arg2, arg3, arg4);
}

void mmSurfaceAudio::SetWobblePitch(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32, f32>>(0x488F20, this, arg1, arg2);
}

void mmSurfaceAudio::SetWobbleVol(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32, f32>>(0x488F40, this, arg1, arg2);
}

void mmSurfaceAudio::Update(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x487B50, this, arg1);
}

void mmSurfaceAudio::UpdateSkidClear(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x4882C0, this, arg1);
}

void mmSurfaceAudio::UpdateSkidRain(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x488680, this, arg1);
}

void mmSurfaceAudio::UpdateSkidSnow(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x488A50, this, arg1);
}

void mmSurfaceAudio::UpdateSurface(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x487D30, this, arg1);
}

void mmSurfaceAudio::UpdateSurfaceSnow(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x487FB0, this, arg1);
}

void mmSurfaceAudio::UpdateSuspension()
{
    return stub<thiscall_t<void, mmSurfaceAudio*>>(0x488D80, this);
}

void mmSurfaceAudio::UpdateTireWobble()
{
    return stub<thiscall_t<void, mmSurfaceAudio*>>(0x487BE0, this);
}

void mmSurfaceAudio::PlayCobble(f32 arg1)
{
    return stub<thiscall_t<void, mmSurfaceAudio*, f32>>(0x488190, this, arg1);
}
