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

#include "opponentimpactaudio.h"

mmOpponentImpactAudio::mmOpponentImpactAudio()
{
    unimplemented();
}

mmOpponentImpactAudio::~mmOpponentImpactAudio()
{
    unimplemented();
}

void mmOpponentImpactAudio::Disable3DMode()
{
    return stub<thiscall_t<void, mmOpponentImpactAudio*>>(0x7A7E0_Offset, this);
}

void mmOpponentImpactAudio::Enable3DMode(class Vector3* arg1)
{
    return stub<thiscall_t<void, mmOpponentImpactAudio*, class Vector3*>>(0x7A770_Offset, this, arg1);
}

void mmOpponentImpactAudio::Play(f32 arg1, i16 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmOpponentImpactAudio*, f32, i16, f32, f32>>(
        0x7A5A0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmOpponentImpactAudio::Update()
{
    return stub<thiscall_t<void, mmOpponentImpactAudio*>>(0x7A710_Offset, this);
}

f32 mmOpponentImpactAudio::GetSecondsElapsed()
{
    return stub<cdecl_t<f32>>(0x7A7D0_Offset);
}

void mmOpponentImpactAudio::SetSecondsElapsed(f32 arg1)
{
    return stub<cdecl_t<void, f32>>(0x7A7C0_Offset, arg1);
}

define_dummy_symbol(mmcar_opponentimpactaudio);
