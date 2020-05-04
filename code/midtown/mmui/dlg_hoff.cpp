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

#include "dlg_hoff.h"

Dialog_HallOfFame::Dialog_HallOfFame(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6)
{
    unimplemented();
}

Dialog_HallOfFame::~Dialog_HallOfFame()
{
    unimplemented();
}

void Dialog_HallOfFame::AddRaceRecord(i32 arg1, char* arg2, char* arg3, char* arg4, i32 arg5, char* arg6, char* arg7)
{
    return stub<thiscall_t<void, Dialog_HallOfFame*, i32, char*, char*, char*, i32, char*, char*>>(
        0x9E800_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void Dialog_HallOfFame::InitRaceRecord()
{
    return stub<thiscall_t<void, Dialog_HallOfFame*>>(0x9EA50_Offset, this);
}

void Dialog_HallOfFame::PreSetup()
{
    return stub<thiscall_t<void, Dialog_HallOfFame*>>(0x9E7F0_Offset, this);
}

void Dialog_HallOfFame::ResetRaceRecord()
{
    return stub<thiscall_t<void, Dialog_HallOfFame*>>(0x9E940_Offset, this);
}

void Dialog_HallOfFame::SetSortState()
{
    return stub<thiscall_t<void, Dialog_HallOfFame*>>(0x9E9D0_Offset, this);
}

define_dummy_symbol(mmui_dlg_hoff);
