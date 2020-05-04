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

#include "jutils.h"

void jcopy_block_row(i16 (*arg1)[64], i16 (*arg2)[64], u32 arg3)
{
    return stub<cdecl_t<void, i16(*)[64], i16(*)[64], u32>>(0x180F50_Offset, arg1, arg2, arg3);
}

void jcopy_sample_rows(u8** arg1, i32 arg2, u8** arg3, i32 arg4, i32 arg5, u32 arg6)
{
    return stub<cdecl_t<void, u8**, i32, u8**, i32, i32, u32>>(0x180F00_Offset, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 jdiv_round_up(i32 arg1, i32 arg2)
{
    return stub<cdecl_t<i32, i32, i32>>(0x180EC0_Offset, arg1, arg2);
}

i32 jround_up(i32 arg1, i32 arg2)
{
    return stub<cdecl_t<i32, i32, i32>>(0x180EE0_Offset, arg1, arg2);
}

void jzero_far(void* arg1, u32 arg2)
{
    return stub<cdecl_t<void, void*, u32>>(0x180F80_Offset, arg1, arg2);
}

define_dummy_symbol(mmdjpeg_jutils);
