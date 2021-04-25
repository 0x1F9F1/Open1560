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
    vector7:trigmath

    0x573250 | float __cdecl tanf_fast(float) | ?tanf_fast@@YAMM@Z
    0x5732C0 | float __cdecl atanf_fast_large_values(float) | ?atanf_fast_large_values@@YAMM@Z
    0x5732F0 | float __cdecl atanf_fast(float) | ?atanf_fast@@YAMM@Z
    0x573370 | float __cdecl atanf_faster(float) | ?atanf_faster@@YAMM@Z
    0x5733D0 | float __cdecl atan2f_fast(float,float) | ?atan2f_fast@@YAMMM@Z
    0x573450 | float __cdecl atan2f_faster(float,float) | ?atan2f_faster@@YAMMM@Z
    0x65A548 | float * asintable | ?asintable@@3PAMA
    0x65E878 | float * TRIGMATH_COSTABLE | ?TRIGMATH_COSTABLE@@3PAMA
    0x65F8A0 | float * TRIGMATH_TANTABLE | ?TRIGMATH_TANTABLE@@3PAMA
    0x6608C8 | float * TRIGMATH_ATANTABLE | ?TRIGMATH_ATANTABLE@@3PAMA
*/

// 0x56D8B0 | ?ASinf@@YAMM@Z | inline
ARTS_IMPORT f32 ASinf(f32 arg1);

// 0x56D980 | ?ATan2f@@YAMMM@Z | inline
ARTS_IMPORT f32 ATan2f(f32 arg1, f32 arg2);

// 0x56D950 | ?asinf_fast@@YAMM@Z | inline
ARTS_IMPORT f32 asinf_fast(f32 arg1);

// 0x5733D0 | ?atan2f_fast@@YAMMM@Z
ARTS_IMPORT f32 atan2f_fast(f32 arg1, f32 arg2);

// 0x573450 | ?atan2f_faster@@YAMMM@Z
ARTS_IMPORT f32 atan2f_faster(f32 arg1, f32 arg2);

// 0x5732F0 | ?atanf_fast@@YAMM@Z
ARTS_IMPORT f32 atanf_fast(f32 arg1);

// 0x5732C0 | ?atanf_fast_large_values@@YAMM@Z
ARTS_IMPORT f32 atanf_fast_large_values(f32 arg1);

// 0x573370 | ?atanf_faster@@YAMM@Z
ARTS_IMPORT f32 atanf_faster(f32 arg1);

// 0x573250 | ?tanf_fast@@YAMM@Z | unused
ARTS_IMPORT f32 tanf_fast(f32 arg1);

// 0x6608C8 | ?TRIGMATH_ATANTABLE@@3PAMA
ARTS_IMPORT extern f32 TRIGMATH_ATANTABLE[401];

// 0x65E878 | ?TRIGMATH_COSTABLE@@3PAMA
ARTS_IMPORT extern f32 TRIGMATH_COSTABLE[1034];

// 0x65F8A0 | ?TRIGMATH_TANTABLE@@3PAMA
ARTS_IMPORT extern f32 TRIGMATH_TANTABLE[1034];

// 0x65A548 | ?asintable@@3PAMA
ARTS_IMPORT extern f32 asintable[4300];
