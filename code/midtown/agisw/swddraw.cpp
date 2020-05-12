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

define_dummy_symbol(agisw_swddraw);

#include "swddraw.h"

void ddAttach(i32 arg1, i32 arg2)
{
    return stub<cdecl_t<void, i32, i32>>(0x534E30, arg1, arg2);
}

static void ddEnd()
{
    return stub<cdecl_t<void>>(0x534FA0);
}

static void ddEndFrame()
{
    return stub<cdecl_t<void>>(0x535070);
}

static void ddEndScene()
{
    return stub<cdecl_t<void>>(0x535030);
}

static void ddStart()
{
    return stub<cdecl_t<void>>(0x534EA0);
}

static void ddStartFrame()
{
    return stub<cdecl_t<void>>(0x534FC0);
}

static void ddStartScene()
{
    return stub<cdecl_t<void>>(0x534FD0);
}
