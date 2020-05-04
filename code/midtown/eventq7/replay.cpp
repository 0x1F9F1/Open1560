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

#include "replay.h"

eqReplayChannel::~eqReplayChannel()
{
    unimplemented();
}

void eqReplayChannel::InitRecord()
{
    return stub<thiscall_t<void, eqReplayChannel*>>(0x164680_Offset, this);
}

void eqReplayChannel::InitPlayback()
{
    return stub<thiscall_t<void, eqReplayChannel*>>(0x164690_Offset, this);
}

void eqReplayChannel::DoRecord(class Stream* arg1)
{
    return stub<thiscall_t<void, eqReplayChannel*, class Stream*>>(0x - 400000_Offset, this, arg1);
}

void eqReplayChannel::DoPlayback(class Stream* arg1)
{
    return stub<thiscall_t<void, eqReplayChannel*, class Stream*>>(0x - 400000_Offset, this, arg1);
}

void eqReplayChannel::ShutdownRecord()
{
    return stub<thiscall_t<void, eqReplayChannel*>>(0x1646A0_Offset, this);
}

void eqReplayChannel::ShutdownPlayback()
{
    return stub<thiscall_t<void, eqReplayChannel*>>(0x1646B0_Offset, this);
}

eqReplayChannel::eqReplayChannel(u32 arg1)
{
    unimplemented();
}

void eqReplay::DoPlayback()
{
    return stub<cdecl_t<void>>(0x164920_Offset);
}

void eqReplay::DoRecord()
{
    return stub<cdecl_t<void>>(0x1648C0_Offset);
}

void eqReplay::InitPlayback(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0x164750_Offset, arg1);
}

void eqReplay::InitRecord(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0x1646C0_Offset, arg1);
}

void eqReplay::ShutdownPlayback()
{
    return stub<cdecl_t<void>>(0x164860_Offset);
}

void eqReplay::ShutdownRecord()
{
    return stub<cdecl_t<void>>(0x164800_Offset);
}

define_dummy_symbol(eventq7_replay);
