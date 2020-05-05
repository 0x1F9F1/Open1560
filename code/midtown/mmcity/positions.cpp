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

define_dummy_symbol(mmcity_positions);

#include "positions.h"

void DumpPositions(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0x91B40_Offset, arg1);
}

i32 GetPositionCount()
{
    return stub<cdecl_t<i32>>(0x91B00_Offset);
}

class Vector4& GetPositionVector4(i32 arg1)
{
    return stub<cdecl_t<class Vector4&, i32>>(0x91B10_Offset, arg1);
}

void InitPositions()
{
    return stub<cdecl_t<void>>(0x91900_Offset);
}

void LoadPositions(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0x91940_Offset, arg1);
}

i32 RecallPosition(i32 arg1, class Matrix34* arg2, i32* arg3, char* arg4)
{
    return stub<cdecl_t<i32, i32, class Matrix34*, i32*, char*>>(0x91C00_Offset, arg1, arg2, arg3, arg4);
}

i32 RegisterPosition(class Vector4& arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, char* arg6)
{
    return stub<cdecl_t<i32, class Vector4&, i32, i32, i32, i32, char*>>(
        0x91C90_Offset, arg1, arg2, arg3, arg4, arg5, arg6);
}

position_t::~position_t()
{
    unimplemented();
}
