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
    mmdjpeg:jdapistd

    0x57D570 | unsigned char __cdecl jpeg_start_decompress(struct jpeg_decompress_struct *) | ?jpeg_start_decompress@@YAEPAUjpeg_decompress_struct@@@Z
    0x57D680 | unsigned int __cdecl jpeg_read_scanlines(struct jpeg_decompress_struct *,unsigned char * *,unsigned int) | ?jpeg_read_scanlines@@YAIPAUjpeg_decompress_struct@@PAPAEI@Z
    0x57D720 | unsigned int __cdecl jpeg_read_raw_data(struct jpeg_decompress_struct *,unsigned char * * *,unsigned int) | ?jpeg_read_raw_data@@YAIPAUjpeg_decompress_struct@@PAPAPAEI@Z
*/

struct jpeg_decompress_struct;

// ?jpeg_read_scanlines@@YAIPAUjpeg_decompress_struct@@PAPAEI@Z
ARTS_IMPORT u32 jpeg_read_scanlines(jpeg_decompress_struct* arg1, u8** arg2, u32 arg3);

// ?jpeg_start_decompress@@YAEPAUjpeg_decompress_struct@@@Z
ARTS_IMPORT u8 jpeg_start_decompress(jpeg_decompress_struct* arg1);
