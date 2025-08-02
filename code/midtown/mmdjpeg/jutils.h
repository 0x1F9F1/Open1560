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

// ?jcopy_sample_rows@@YAXPAPAEH0HHI@Z
ARTS_IMPORT void jcopy_sample_rows(u8** arg1, i32 arg2, u8** arg3, i32 arg4, i32 arg5, u32 arg6);

// ?jdiv_round_up@@YAJJJ@Z
ARTS_IMPORT i32 jdiv_round_up(i32 arg1, i32 arg2);

// ?jround_up@@YAJJJ@Z
ARTS_IMPORT i32 jround_up(i32 arg1, i32 arg2);

// ?jzero_far@@YAXPAXI@Z
ARTS_IMPORT void jzero_far(void* arg1, u32 arg2);

// ?jpeg_natural_order@@3PBHB
ARTS_IMPORT extern const i32* const jpeg_natural_order;
