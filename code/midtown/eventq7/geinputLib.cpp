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

define_dummy_symbol(eventq7_geinputLib);

#include "geinputLib.h"

void geinputAcquireMouse()
{
    return stub<cdecl_t<void>>(0x564200);
}

void geinputCleanup()
{
    return stub<cdecl_t<void>>(0x564570);
}

void geinputClearCache()
{
    return stub<cdecl_t<void>>(0x564610);
}

i32 geinputGetBufferedKeyboard(char* arg1)
{
    return stub<cdecl_t<i32, char*>>(0x564220, arg1);
}

char* geinputGetKeyboard()
{
    return stub<cdecl_t<char*>>(0x5642B0);
}

void geinputGetMouse(i32* arg1, i32* arg2, char* arg3, char* arg4, i32* arg5, i32* arg6, i32* arg7, char* arg8)
{
    return stub<cdecl_t<void, i32*, i32*, char*, char*, i32*, i32*, i32*, char*>>(
        0x564320, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void geinputUnacquireMouse()
{
    return stub<cdecl_t<void>>(0x564210);
}

i32 inputSetup(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<cdecl_t<i32, i32, i32, i32, i32, i32>>(0x563DE0, arg1, arg2, arg3, arg4, arg5);
}

static char* DIError(i32 arg1)
{
    return stub<cdecl_t<char*, i32>>(0x564050, arg1);
}
