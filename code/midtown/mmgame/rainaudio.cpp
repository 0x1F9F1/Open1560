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

#include "rainaudio.h"

mmRainAudio::mmRainAudio()
{
    unimplemented();
}

mmRainAudio::~mmRainAudio()
{
    unimplemented();
}

void mmRainAudio::SetInterior(u8 arg1)
{
    return stub<thiscall_t<void, mmRainAudio*, u8>>(0x33440_Offset, this, arg1);
}

void mmRainAudio::ShelterOff()
{
    return stub<thiscall_t<void, mmRainAudio*>>(0x33540_Offset, this);
}

void mmRainAudio::ShelterOn()
{
    return stub<thiscall_t<void, mmRainAudio*>>(0x334D0_Offset, this);
}

void mmRainAudio::Update()
{
    return stub<thiscall_t<void, mmRainAudio*>>(0x335B0_Offset, this);
}

define_dummy_symbol(mmgame_rainaudio);
