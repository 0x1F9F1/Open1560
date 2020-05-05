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

define_dummy_symbol(mmdjpeg_jdapimin);

#include "jdapimin.h"

void jpeg_CreateDecompress(struct jpeg_decompress_struct* arg1, i32 arg2, u32 arg3)
{
    return stub<cdecl_t<void, struct jpeg_decompress_struct*, i32, u32>>(0x17D000_Offset, arg1, arg2, arg3);
}

void jpeg_abort_decompress(struct jpeg_decompress_struct* arg1)
{
    return stub<cdecl_t<void, struct jpeg_decompress_struct*>>(0x17D100_Offset, arg1);
}

i32 jpeg_consume_input(struct jpeg_decompress_struct* arg1)
{
    return stub<cdecl_t<i32, struct jpeg_decompress_struct*>>(0x17D1A0_Offset, arg1);
}

void jpeg_destroy_decompress(struct jpeg_decompress_struct* arg1)
{
    return stub<cdecl_t<void, struct jpeg_decompress_struct*>>(0x17D0E0_Offset, arg1);
}

u8 jpeg_finish_decompress(struct jpeg_decompress_struct* arg1)
{
    return stub<cdecl_t<u8, struct jpeg_decompress_struct*>>(0x17D4A0_Offset, arg1);
}

u8 jpeg_has_multiple_scans(struct jpeg_decompress_struct* arg1)
{
    return stub<cdecl_t<u8, struct jpeg_decompress_struct*>>(0x17D460_Offset, arg1);
}

u8 jpeg_input_complete(struct jpeg_decompress_struct* arg1)
{
    return stub<cdecl_t<u8, struct jpeg_decompress_struct*>>(0x17D420_Offset, arg1);
}

i32 jpeg_read_header(struct jpeg_decompress_struct* arg1, u8 arg2)
{
    return stub<cdecl_t<i32, struct jpeg_decompress_struct*, u8>>(0x17D120_Offset, arg1, arg2);
}
