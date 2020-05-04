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

#include "dderror.h"

char* DDErrorToString(i32 arg1)
{
    return stub<cdecl_t<char*, i32>>(0x132090_Offset, arg1);
}

void __DDRelease(struct IUnknown* arg1, char const* arg2, char const* arg3, i32 arg4)
{
    return stub<cdecl_t<void, struct IUnknown*, char const*, char const*, i32>>(
        0x132890_Offset, arg1, arg2, arg3, arg4);
}

void __DDTry(i32 arg1, char const* arg2, char const* arg3, i32 arg4)
{
    return stub<cdecl_t<void, i32, char const*, char const*, i32>>(0x1327B0_Offset, arg1, arg2, arg3, arg4);
}

define_dummy_symbol(agid3d_dderror);
