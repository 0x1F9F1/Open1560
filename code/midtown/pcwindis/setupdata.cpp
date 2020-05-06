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

define_dummy_symbol(pcwindis_setupdata);

#include "setupdata.h"

i32 dxiReadConfigFile()
{
    return stub<cdecl_t<i32>>(0x574B00);
}

i32 dxiResClosestMatch(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<cdecl_t<i32, i32, i32, i32>>(0x5749B0, arg1, arg2, arg3);
}

i32 dxiResGetRecommended(i32 arg1, i32 arg2)
{
    return stub<cdecl_t<i32, i32, i32>>(0x574A60, arg1, arg2);
}

void dxiWriteConfigFile()
{
    return stub<cdecl_t<void>>(0x574E90);
}
