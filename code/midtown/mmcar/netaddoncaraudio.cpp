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

#include "netaddoncaraudio.h"

NetAddOnCarAudio::NetAddOnCarAudio(char* arg1, i16 arg2)
{
    unimplemented();
}

NetAddOnCarAudio::~NetAddOnCarAudio()
{
    unimplemented();
}

i32 NetAddOnCarAudio::AssignSounds(class mmNetworkCarAudio* arg1, i16 arg2)
{
    return stub<thiscall_t<i32, NetAddOnCarAudio*, class mmNetworkCarAudio*, i16>>(0x856B0_Offset, this, arg1, arg2);
}

void NetAddOnCarAudio::EchoOff()
{
    return stub<thiscall_t<void, NetAddOnCarAudio*>>(0x857A0_Offset, this);
}

void NetAddOnCarAudio::EchoOn(f32 arg1)
{
    return stub<thiscall_t<void, NetAddOnCarAudio*, f32>>(0x85740_Offset, this, arg1);
}

void NetAddOnCarAudio::Update()
{
    return stub<thiscall_t<void, NetAddOnCarAudio*>>(0x857D0_Offset, this);
}

define_dummy_symbol(mmcar_netaddoncaraudio);
