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

// ?ASinf@@YAMM@Z | inline
ARTS_IMPORT f32 ASinf(f32 arg1);

// ?ATan2f@@YAMMM@Z | inline
ARTS_IMPORT f32 ATan2f(f32 arg1, f32 arg2);

// ?asinf_fast@@YAMM@Z | inline
ARTS_IMPORT f32 asinf_fast(f32 arg1);

// ?atan2f_fast@@YAMMM@Z
ARTS_IMPORT f32 atan2f_fast(f32 arg1, f32 arg2);

// ?atan2f_faster@@YAMMM@Z
ARTS_IMPORT f32 atan2f_faster(f32 arg1, f32 arg2);

// ?atanf_fast@@YAMM@Z
ARTS_IMPORT f32 atanf_fast(f32 arg1);

// ?atanf_fast_large_values@@YAMM@Z
ARTS_IMPORT f32 atanf_fast_large_values(f32 arg1);

// ?atanf_faster@@YAMM@Z
ARTS_IMPORT f32 atanf_faster(f32 arg1);

// ?TRIGMATH_ATANTABLE@@3PAMA
ARTS_IMPORT extern f32 TRIGMATH_ATANTABLE[401];

// ?TRIGMATH_COSTABLE@@3PAMA
ARTS_IMPORT extern f32 TRIGMATH_COSTABLE[1034];

// ?TRIGMATH_TANTABLE@@3PAMA
ARTS_IMPORT extern f32 TRIGMATH_TANTABLE[1034];

// ?asintable@@3PAMA
ARTS_IMPORT extern f32 asintable[4300];
