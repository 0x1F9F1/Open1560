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

define_dummy_symbol(agi_getdlp);

#include "getdlp.h"

void CheckLibraries()
{
    return stub<cdecl_t<void>>(0x556A30);
}

class DLPTemplate* GetDLPTemplate(char* arg1)
{
    return stub<cdecl_t<class DLPTemplate*, char*>>(0x556B60, arg1);
}

i32 GetGroupVerts(char* arg1, char* arg2, class Vector3* arg3, i32 arg4)
{
    return stub<cdecl_t<i32, char*, char*, class Vector3*, i32>>(0x556DF0, arg1, arg2, arg3, arg4);
}

i32 OutOfDate(char* arg1, char* arg2)
{
    return stub<cdecl_t<i32, char*, char*>>(0x5569D0, arg1, arg2);
}

static i32 LibOutOfDate(char* arg1, char* arg2)
{
    return stub<cdecl_t<i32, char*, char*>>(0x556AD0, arg1, arg2);
}
