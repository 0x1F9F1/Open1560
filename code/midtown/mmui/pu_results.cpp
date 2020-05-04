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

#include "pu_results.h"

PUResults::PUResults(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6)
{
    unimplemented();
}

PUResults::~PUResults()
{
    unimplemented();
}

void PUResults::AddName(i32 arg1, char* arg2, f32 arg3)
{
    return stub<thiscall_t<void, PUResults*, i32, char*, f32>>(0xA8A50_Offset, this, arg1, arg2, arg3);
}

void PUResults::AddName(i32 arg1, char* arg2, i32 arg3)
{
    return stub<thiscall_t<void, PUResults*, i32, char*, i32>>(0xA8B00_Offset, this, arg1, arg2, arg3);
}

void PUResults::AddTitle(struct LocString* arg1, struct LocString* arg2)
{
    return stub<thiscall_t<void, PUResults*, struct LocString*, struct LocString*>>(0xA89D0_Offset, this, arg1, arg2);
}

void PUResults::ClearNames()
{
    return stub<thiscall_t<void, PUResults*>>(0xA8BC0_Offset, this);
}

void PUResults::DisableNextRace()
{
    return stub<thiscall_t<void, PUResults*>>(0xA8C30_Offset, this);
}

void PUResults::EnableNextRace()
{
    return stub<thiscall_t<void, PUResults*>>(0xA8C40_Offset, this);
}

void PUResults::Init320()
{
    return stub<thiscall_t<void, PUResults*>>(0xA81B0_Offset, this);
}

void PUResults::Init640()
{
    return stub<thiscall_t<void, PUResults*>>(0xA8590_Offset, this);
}

void PUResults::Reset()
{
    return stub<thiscall_t<void, PUResults*>>(0xA8A00_Offset, this);
}

void PUResults::RestartRO(i32 arg1)
{
    return stub<thiscall_t<void, PUResults*, i32>>(0xA8A30_Offset, this, arg1);
}

void PUResults::RosterRO(i32 arg1)
{
    return stub<thiscall_t<void, PUResults*, i32>>(0xA8A10_Offset, this, arg1);
}

void PUResults::SetMessage(struct LocString* arg1)
{
    return stub<thiscall_t<void, PUResults*, struct LocString*>>(0xA8C50_Offset, this, arg1);
}

define_dummy_symbol(mmui_pu_results);
