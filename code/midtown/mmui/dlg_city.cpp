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

#include "dlg_city.h"

Dialog_City::Dialog_City(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6)
{
    unimplemented();
}

Dialog_City::~Dialog_City()
{
    unimplemented();
}

void Dialog_City::DoneCB()
{
    return stub<thiscall_t<void, Dialog_City*>>(0x9DA20_Offset, this);
}

void Dialog_City::PreSetup()
{
    return stub<thiscall_t<void, Dialog_City*>>(0x9DA10_Offset, this);
}

define_dummy_symbol(mmui_dlg_city);
