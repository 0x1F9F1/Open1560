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

#include "dlg_renv.h"

Dialog_RaceEnvironment::Dialog_RaceEnvironment(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6)
{
    unimplemented();
}

Dialog_RaceEnvironment::~Dialog_RaceEnvironment()
{
    unimplemented();
}

void Dialog_RaceEnvironment::CancelCallback()
{
    return stub<thiscall_t<void, Dialog_RaceEnvironment*>>(0x9E3A0_Offset, this);
}

void Dialog_RaceEnvironment::ControlPedSlider()
{
    return stub<thiscall_t<void, Dialog_RaceEnvironment*>>(0x9E2F0_Offset, this);
}

void Dialog_RaceEnvironment::DoneCallback()
{
    return stub<thiscall_t<void, Dialog_RaceEnvironment*>>(0x9E350_Offset, this);
}

void Dialog_RaceEnvironment::PreSetup()
{
    return stub<thiscall_t<void, Dialog_RaceEnvironment*>>(0x9E2A0_Offset, this);
}

void Dialog_RaceEnvironment::SetMultiRaceOptions(i32 arg1)
{
    return stub<thiscall_t<void, Dialog_RaceEnvironment*, i32>>(0x9E310_Offset, this, arg1);
}

define_dummy_symbol(mmui_dlg_renv);
