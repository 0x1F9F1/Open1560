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
    mmdjpeg:jutils

    0x580EC0 | long __cdecl jdiv_round_up(long,long) | ?jdiv_round_up@@YAJJJ@Z
    0x580EE0 | long __cdecl jround_up(long,long) | ?jround_up@@YAJJJ@Z
    0x580F00 | void __cdecl jcopy_sample_rows(unsigned char * *,int,unsigned char * *,int,int,unsigned int) | ?jcopy_sample_rows@@YAXPAPAEH0HHI@Z
    0x580F50 | void __cdecl jcopy_block_row(short (*)[64],short (*)[64],unsigned int) | ?jcopy_block_row@@YAXPAY0EA@F0I@Z
    0x580F80 | void __cdecl jzero_far(void *,unsigned int) | ?jzero_far@@YAXPAXI@Z
    0x6220E8 | int const * const jpeg_natural_order | ?jpeg_natural_order@@3PBHB
*/

// 0x580F50 | ?jcopy_block_row@@YAXPAY0EA@F0I@Z
void jcopy_block_row(i16 (*arg1)[64], i16 (*arg2)[64], u32 arg3);

// 0x580F00 | ?jcopy_sample_rows@@YAXPAPAEH0HHI@Z
void jcopy_sample_rows(u8** arg1, i32 arg2, u8** arg3, i32 arg4, i32 arg5, u32 arg6);

// 0x580EC0 | ?jdiv_round_up@@YAJJJ@Z
i32 jdiv_round_up(i32 arg1, i32 arg2);

// 0x580EE0 | ?jround_up@@YAJJJ@Z
i32 jround_up(i32 arg1, i32 arg2);

// 0x580F80 | ?jzero_far@@YAXPAXI@Z
void jzero_far(void* arg1, u32 arg2);

// 0x6220E8 | ?jpeg_natural_order@@3PBHB
inline extern_var(0x2220E8_Offset, i32 const* const, jpeg_natural_order);
