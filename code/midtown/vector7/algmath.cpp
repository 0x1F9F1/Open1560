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

define_dummy_symbol(vector7_algmath);

#include "algmath.h"

f32 Bias(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<f32, f32, f32>>(0x570DB0, arg1, arg2);
}

f32 Gain(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<f32, f32, f32>>(0x570E00, arg1, arg2);
}

f32 expf_fast(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x571000, arg1);
}

f32 expf_faster(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x571090, arg1);
}

f32 invsqrtf_fast(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x570F80, arg1);
}

f32 logf_fast(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x570E80, arg1);
}

f32 sqrtf_faster(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x570F10, arg1);
}
