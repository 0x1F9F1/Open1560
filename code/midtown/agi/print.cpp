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

define_dummy_symbol(agi_print);

#include "print.h"

void agiPrint(i32 arg1, i32 arg2, i32 arg3, char const* arg4)
{
    return stub<cdecl_t<void, i32, i32, i32, char const*>>(0x557E70, arg1, arg2, arg3, arg4);
}

void agiPrintInit()
{
    return stub<cdecl_t<void>>(0x557F00);
}

i32 agiPrintIs3D()
{
    return stub<cdecl_t<i32>>(0x557EF0);
}

void agiPrintShutdown()
{
    return stub<cdecl_t<void>>(0x557F10);
}

void agiPrintf(i32 arg1, i32 arg2, i32 arg3, char const* arg4, ...)
{
    unimplemented(arg1, arg2, arg3, arg4);
}

static void InitBuiltin()
{
    return stub<cdecl_t<void>>(0x557FE0);
}
