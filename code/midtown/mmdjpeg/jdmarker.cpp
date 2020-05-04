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

#include "jdmarker.h"

void jinit_marker_reader(struct jpeg_decompress_struct* arg1)
{
    return stub<cdecl_t<void, struct jpeg_decompress_struct*>>(0x17E380_Offset, arg1);
}

u8 jpeg_resync_to_restart(struct jpeg_decompress_struct* arg1, i32 arg2)
{
    return stub<cdecl_t<u8, struct jpeg_decompress_struct*, i32>>(0x17E150_Offset, arg1, arg2);
}

void jpeg_set_marker_processor(
    struct jpeg_decompress_struct* arg1, i32 arg2, u8 (*arg3)(struct jpeg_decompress_struct*))
{
    return stub<cdecl_t<void, struct jpeg_decompress_struct*, i32, u8 (*)(struct jpeg_decompress_struct*)>>(
        0x17FCB0_Offset, arg1, arg2, arg3);
}

define_dummy_symbol(mmdjpeg_jdmarker);
