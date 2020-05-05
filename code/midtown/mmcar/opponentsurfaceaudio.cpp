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

define_dummy_symbol(mmcar_opponentsurfaceaudio);

#include "opponentsurfaceaudio.h"

mmOpponentSurfaceAudio::mmOpponentSurfaceAudio()
{
    unimplemented();
}

mmOpponentSurfaceAudio::~mmOpponentSurfaceAudio()
{
    unimplemented();
}

void mmOpponentSurfaceAudio::Disable3DMode()
{
    return stub<thiscall_t<void, mmOpponentSurfaceAudio*>>(0x863A0_Offset, this);
}

void mmOpponentSurfaceAudio::Enable3DMode(class Vector3* arg1)
{
    return stub<thiscall_t<void, mmOpponentSurfaceAudio*, class Vector3*>>(0x86380_Offset, this, arg1);
}

void mmOpponentSurfaceAudio::SetWheelPointers(
    class mmWheel* arg1, class mmWheel* arg2, class mmWheel* arg3, class mmWheel* arg4)
{
    return stub<
        thiscall_t<void, mmOpponentSurfaceAudio*, class mmWheel*, class mmWheel*, class mmWheel*, class mmWheel*>>(
        0x85E40_Offset, this, arg1, arg2, arg3, arg4);
}

void mmOpponentSurfaceAudio::Update(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentSurfaceAudio*, f32>>(0x85E60_Offset, this, arg1);
}

void mmOpponentSurfaceAudio::UpdateSkid(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentSurfaceAudio*, f32>>(0x85EA0_Offset, this, arg1);
}

void mmOpponentSurfaceAudio::UpdateSkidSnow(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentSurfaceAudio*, f32>>(0x86120_Offset, this, arg1);
}
