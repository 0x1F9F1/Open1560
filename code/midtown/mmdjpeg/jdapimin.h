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

/*
    mmdjpeg:jdapimin

    0x57D000 | void __cdecl jpeg_CreateDecompress(struct jpeg_decompress_struct *,int,unsigned int) | ?jpeg_CreateDecompress@@YAXPAUjpeg_decompress_struct@@HI@Z
    0x57D0E0 | void __cdecl jpeg_destroy_decompress(struct jpeg_decompress_struct *) | ?jpeg_destroy_decompress@@YAXPAUjpeg_decompress_struct@@@Z
    0x57D100 | void __cdecl jpeg_abort_decompress(struct jpeg_decompress_struct *) | ?jpeg_abort_decompress@@YAXPAUjpeg_decompress_struct@@@Z
    0x57D120 | int __cdecl jpeg_read_header(struct jpeg_decompress_struct *,unsigned char) | ?jpeg_read_header@@YAHPAUjpeg_decompress_struct@@E@Z
    0x57D1A0 | int __cdecl jpeg_consume_input(struct jpeg_decompress_struct *) | ?jpeg_consume_input@@YAHPAUjpeg_decompress_struct@@@Z
    0x57D420 | unsigned char __cdecl jpeg_input_complete(struct jpeg_decompress_struct *) | ?jpeg_input_complete@@YAEPAUjpeg_decompress_struct@@@Z
    0x57D460 | unsigned char __cdecl jpeg_has_multiple_scans(struct jpeg_decompress_struct *) | ?jpeg_has_multiple_scans@@YAEPAUjpeg_decompress_struct@@@Z
    0x57D4A0 | unsigned char __cdecl jpeg_finish_decompress(struct jpeg_decompress_struct *) | ?jpeg_finish_decompress@@YAEPAUjpeg_decompress_struct@@@Z
*/

// 0x57D000 | ?jpeg_CreateDecompress@@YAXPAUjpeg_decompress_struct@@HI@Z
void jpeg_CreateDecompress(struct jpeg_decompress_struct* arg1, i32 arg2, u32 arg3);

// 0x57D100 | ?jpeg_abort_decompress@@YAXPAUjpeg_decompress_struct@@@Z
void jpeg_abort_decompress(struct jpeg_decompress_struct* arg1);

// 0x57D1A0 | ?jpeg_consume_input@@YAHPAUjpeg_decompress_struct@@@Z
i32 jpeg_consume_input(struct jpeg_decompress_struct* arg1);

// 0x57D0E0 | ?jpeg_destroy_decompress@@YAXPAUjpeg_decompress_struct@@@Z
void jpeg_destroy_decompress(struct jpeg_decompress_struct* arg1);

// 0x57D4A0 | ?jpeg_finish_decompress@@YAEPAUjpeg_decompress_struct@@@Z
u8 jpeg_finish_decompress(struct jpeg_decompress_struct* arg1);

// 0x57D460 | ?jpeg_has_multiple_scans@@YAEPAUjpeg_decompress_struct@@@Z
u8 jpeg_has_multiple_scans(struct jpeg_decompress_struct* arg1);

// 0x57D420 | ?jpeg_input_complete@@YAEPAUjpeg_decompress_struct@@@Z
u8 jpeg_input_complete(struct jpeg_decompress_struct* arg1);

// 0x57D120 | ?jpeg_read_header@@YAHPAUjpeg_decompress_struct@@E@Z
i32 jpeg_read_header(struct jpeg_decompress_struct* arg1, u8 arg2);
