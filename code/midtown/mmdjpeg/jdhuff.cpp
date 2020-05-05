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

define_dummy_symbol(mmdjpeg_jdhuff);

#include "jdhuff.h"

void jinit_huff_decoder(struct jpeg_decompress_struct* arg1)
{
    return stub<cdecl_t<void, struct jpeg_decompress_struct*>>(0x181F80_Offset, arg1);
}

u8 jpeg_fill_bit_buffer(struct bitread_working_state* arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<cdecl_t<u8, struct bitread_working_state*, i32, i32, i32>>(0x181D60_Offset, arg1, arg2, arg3, arg4);
}

i32 jpeg_huff_decode(struct bitread_working_state* arg1, i32 arg2, i32 arg3, struct d_derived_tbl* arg4, i32 arg5)
{
    return stub<cdecl_t<i32, struct bitread_working_state*, i32, i32, struct d_derived_tbl*, i32>>(
        0x181E80_Offset, arg1, arg2, arg3, arg4, arg5);
}

void jpeg_make_d_derived_tbl(struct jpeg_decompress_struct* arg1, u8 arg2, i32 arg3, struct d_derived_tbl** arg4)
{
    return stub<cdecl_t<void, struct jpeg_decompress_struct*, u8, i32, struct d_derived_tbl**>>(
        0x181AA0_Offset, arg1, arg2, arg3, arg4);
}
