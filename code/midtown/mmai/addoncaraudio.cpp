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

define_dummy_symbol(mmai_addoncaraudio);

#include "addoncaraudio.h"

AddOnCarAudio::AddOnCarAudio(char* arg1, i16 arg2)
{
    unimplemented(arg1, arg2);
}

AddOnCarAudio::~AddOnCarAudio()
{
    unimplemented();
}

void AddOnCarAudio::EchoOff()
{
    return stub<thiscall_t<void, AddOnCarAudio*>>(0x5C750_Offset, this);
}

void AddOnCarAudio::EchoOn(f32 arg1)
{
    return stub<thiscall_t<void, AddOnCarAudio*, f32>>(0x5C700_Offset, this, arg1);
}

class AudSound* AddOnCarAudio::GetEngineSoundPtr(i16 arg1)
{
    return stub<thiscall_t<class AudSound*, AddOnCarAudio*, i16>>(0x5C6E0_Offset, this, arg1);
}

void AddOnCarAudio::Update()
{
    return stub<thiscall_t<void, AddOnCarAudio*>>(0x5C780_Offset, this);
}
