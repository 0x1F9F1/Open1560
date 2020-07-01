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
    mmdjpeg:jmemnobs

    0x580FA0 | void * __cdecl jpeg_get_small(struct jpeg_common_struct *,unsigned int) | ?jpeg_get_small@@YAPAXPAUjpeg_common_struct@@I@Z
    0x580FC0 | void __cdecl jpeg_free_small(struct jpeg_common_struct *,void *,unsigned int) | ?jpeg_free_small@@YAXPAUjpeg_common_struct@@PAXI@Z
    0x580FE0 | void * __cdecl jpeg_get_large(struct jpeg_common_struct *,unsigned int) | ?jpeg_get_large@@YAPAXPAUjpeg_common_struct@@I@Z
    0x581000 | void __cdecl jpeg_free_large(struct jpeg_common_struct *,void *,unsigned int) | ?jpeg_free_large@@YAXPAUjpeg_common_struct@@PAXI@Z
    0x581020 | long __cdecl jpeg_mem_available(struct jpeg_common_struct *,long,long,long) | ?jpeg_mem_available@@YAJPAUjpeg_common_struct@@JJJ@Z
    0x581030 | void __cdecl jpeg_open_backing_store(struct jpeg_common_struct *,struct backing_store_struct *,long) | ?jpeg_open_backing_store@@YAXPAUjpeg_common_struct@@PAUbacking_store_struct@@J@Z
    0x581050 | long __cdecl jpeg_mem_init(struct jpeg_common_struct *) | ?jpeg_mem_init@@YAJPAUjpeg_common_struct@@@Z
    0x581060 | void __cdecl jpeg_mem_term(struct jpeg_common_struct *) | ?jpeg_mem_term@@YAXPAUjpeg_common_struct@@@Z
    0x90B4C0 | int jpeg_allocated | ?jpeg_allocated@@3HA
*/

// 0x581000 | ?jpeg_free_large@@YAXPAUjpeg_common_struct@@PAXI@Z
ARTS_IMPORT void jpeg_free_large(struct jpeg_common_struct* arg1, void* arg2, u32 arg3);

// 0x580FC0 | ?jpeg_free_small@@YAXPAUjpeg_common_struct@@PAXI@Z
ARTS_IMPORT void jpeg_free_small(struct jpeg_common_struct* arg1, void* arg2, u32 arg3);

// 0x580FE0 | ?jpeg_get_large@@YAPAXPAUjpeg_common_struct@@I@Z
ARTS_IMPORT void* jpeg_get_large(struct jpeg_common_struct* arg1, u32 arg2);

// 0x580FA0 | ?jpeg_get_small@@YAPAXPAUjpeg_common_struct@@I@Z
ARTS_IMPORT void* jpeg_get_small(struct jpeg_common_struct* arg1, u32 arg2);

// 0x581020 | ?jpeg_mem_available@@YAJPAUjpeg_common_struct@@JJJ@Z
ARTS_IMPORT i32 jpeg_mem_available(struct jpeg_common_struct* arg1, i32 arg2, i32 arg3, i32 arg4);

// 0x581050 | ?jpeg_mem_init@@YAJPAUjpeg_common_struct@@@Z
ARTS_EXPORT i32 jpeg_mem_init(struct jpeg_common_struct* arg1);

// 0x581060 | ?jpeg_mem_term@@YAXPAUjpeg_common_struct@@@Z
ARTS_EXPORT void jpeg_mem_term(struct jpeg_common_struct* arg1);

// 0x581030 | ?jpeg_open_backing_store@@YAXPAUjpeg_common_struct@@PAUbacking_store_struct@@J@Z
ARTS_IMPORT void jpeg_open_backing_store(struct jpeg_common_struct* arg1, struct backing_store_struct* arg2, i32 arg3);

// 0x90B4C0 | ?jpeg_allocated@@3HA
ARTS_IMPORT extern i32 jpeg_allocated;
