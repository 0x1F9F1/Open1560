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

#include "eventq.h"

eqEventQ::eqEventQ(i32 arg1, i32 arg2, i32 arg3)
{
    unimplemented();
}

eqEventQ::~eqEventQ()
{
    unimplemented();
}

void eqEventQ::Activate(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, eqEventQ*, void*, i32>>(0x163CC0_Offset, this, arg1, arg2);
}

void eqEventQ::Destroy(void* arg1)
{
    return stub<thiscall_t<void, eqEventQ*, void*>>(0x163C80_Offset, this, arg1);
}

void eqEventQ::Keyboard(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, eqEventQ*, void*, i32, i32, i32, i32>>(
        0x163C20_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void eqEventQ::Mouse(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8)
{
    return stub<thiscall_t<void, eqEventQ*, void*, i32, i32, i32, i32, i32, i32, i32>>(
        0x163B90_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

i32 eqEventQ::Pop(union eqEvent* arg1)
{
    return stub<thiscall_t<i32, eqEventQ*, union eqEvent*>>(0x163D40_Offset, this, arg1);
}

void eqEventQ::Redraw(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, eqEventQ*, void*, i32, i32, i32, i32>>(
        0x163AF0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void eqEventQ::Refocus(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, eqEventQ*, void*, i32>>(0x163B50_Offset, this, arg1, arg2);
}

void eqEventQ::Queue(union eqEvent& arg1)
{
    return stub<thiscall_t<void, eqEventQ*, union eqEvent&>>(0x163D00_Offset, this, arg1);
}

define_dummy_symbol(eventq7_eventq);
