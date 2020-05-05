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

define_dummy_symbol(vector7_trigmath);

#include "trigmath.h"

f32 atan2f_fast(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<f32, f32, f32>>(0x1733D0_Offset, arg1, arg2);
}

f32 atan2f_faster(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<f32, f32, f32>>(0x173450_Offset, arg1, arg2);
}

f32 atanf_fast(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x1732F0_Offset, arg1);
}

f32 atanf_fast_large_values(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x1732C0_Offset, arg1);
}

f32 atanf_faster(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x173370_Offset, arg1);
}

f32 tanf_fast(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x173250_Offset, arg1);
}
