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

#pragma once

struct bitread_working_state;
struct d_derived_tbl;
struct jpeg_decompress_struct;

// ?jinit_huff_decoder@@YAXPAUjpeg_decompress_struct@@@Z
ARTS_IMPORT void jinit_huff_decoder(jpeg_decompress_struct* arg1);

// ?jpeg_fill_bit_buffer@@YAEPAUbitread_working_state@@JHH@Z
ARTS_IMPORT u8 jpeg_fill_bit_buffer(bitread_working_state* arg1, i32 arg2, i32 arg3, i32 arg4);

// ?jpeg_huff_decode@@YAHPAUbitread_working_state@@JHPAUd_derived_tbl@@H@Z
ARTS_IMPORT i32 jpeg_huff_decode(bitread_working_state* arg1, i32 arg2, i32 arg3, d_derived_tbl* arg4, i32 arg5);

// ?jpeg_make_d_derived_tbl@@YAXPAUjpeg_decompress_struct@@EHPAPAUd_derived_tbl@@@Z
ARTS_IMPORT void jpeg_make_d_derived_tbl(jpeg_decompress_struct* arg1, u8 arg2, i32 arg3, d_derived_tbl** arg4);
