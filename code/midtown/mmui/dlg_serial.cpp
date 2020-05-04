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

#include "dlg_serial.h"

Dialog_Serial::Dialog_Serial(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6)
{
    unimplemented();
}

Dialog_Serial::~Dialog_Serial()
{
    unimplemented();
}

void Dialog_Serial::BuildComs()
{
    return stub<thiscall_t<void, Dialog_Serial*>>(0xA0130_Offset, this);
}

struct NETCOMMPACK* Dialog_Serial::GetCommPack()
{
    return stub<thiscall_t<struct NETCOMMPACK*, Dialog_Serial*>>(0xA01F0_Offset, this);
}

void Dialog_Serial::IPAddressCallback()
{
    return stub<thiscall_t<void, Dialog_Serial*>>(0xA0120_Offset, this);
}

void Dialog_Serial::PreSetup()
{
    return stub<thiscall_t<void, Dialog_Serial*>>(0xA0110_Offset, this);
}

define_dummy_symbol(mmui_dlg_serial);
