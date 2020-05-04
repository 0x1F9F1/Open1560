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

#include "jidctfst.h"

void jpeg_idct_ifast(
    struct jpeg_decompress_struct* arg1, struct jpeg_component_info* arg2, i16* arg3, u8** arg4, u32 arg5)
{
    return stub<cdecl_t<void, struct jpeg_decompress_struct*, struct jpeg_component_info*, i16*, u8**, u32>>(
        0x183D40_Offset, arg1, arg2, arg3, arg4, arg5);
}

define_dummy_symbol(mmdjpeg_jidctfst);
