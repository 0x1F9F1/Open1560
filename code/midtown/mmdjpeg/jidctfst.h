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
    mmdjpeg:jidctfst

    0x583D40 | void __cdecl jpeg_idct_ifast(struct jpeg_decompress_struct *,struct jpeg_component_info *,short *,unsigned char * *,unsigned int) | ?jpeg_idct_ifast@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
*/

// 0x583D40 | ?jpeg_idct_ifast@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
void jpeg_idct_ifast(
    struct jpeg_decompress_struct* arg1, struct jpeg_component_info* arg2, i16* arg3, u8** arg4, u32 arg5);
