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

define_dummy_symbol(mmui_pu_results);

#include "pu_results.h"

PUResults::PUResults(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6)
{
    unimplemented(arg1, arg2, arg3, arg4, arg5, arg6);
}

PUResults::~PUResults()
{
    unimplemented(arg1);
}

void PUResults::AddName(i32 arg1, char* arg2, f32 arg3)
{
    return stub<thiscall_t<void, PUResults*, i32, char*, f32>>(0x4A8A50, this, arg1, arg2, arg3);
}

void PUResults::AddName(i32 arg1, char* arg2, i32 arg3)
{
    return stub<thiscall_t<void, PUResults*, i32, char*, i32>>(0x4A8B00, this, arg1, arg2, arg3);
}

void PUResults::AddTitle(struct LocString* arg1, struct LocString* arg2)
{
    return stub<thiscall_t<void, PUResults*, struct LocString*, struct LocString*>>(0x4A89D0, this, arg1, arg2);
}

void PUResults::ClearNames()
{
    return stub<thiscall_t<void, PUResults*>>(0x4A8BC0, this);
}

void PUResults::DisableNextRace()
{
    return stub<thiscall_t<void, PUResults*>>(0x4A8C30, this);
}

void PUResults::EnableNextRace()
{
    return stub<thiscall_t<void, PUResults*>>(0x4A8C40, this);
}

void PUResults::Init320()
{
    return stub<thiscall_t<void, PUResults*>>(0x4A81B0, this);
}

void PUResults::Init640()
{
    return stub<thiscall_t<void, PUResults*>>(0x4A8590, this);
}

void PUResults::Reset()
{
    return stub<thiscall_t<void, PUResults*>>(0x4A8A00, this);
}

void PUResults::RestartRO(i32 arg1)
{
    return stub<thiscall_t<void, PUResults*, i32>>(0x4A8A30, this, arg1);
}

void PUResults::RosterRO(i32 arg1)
{
    return stub<thiscall_t<void, PUResults*, i32>>(0x4A8A10, this, arg1);
}

void PUResults::SetMessage(struct LocString* arg1)
{
    return stub<thiscall_t<void, PUResults*, struct LocString*>>(0x4A8C50, this, arg1);
}
