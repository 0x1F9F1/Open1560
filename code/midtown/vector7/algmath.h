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
    vector7:algmath

    0x570DB0 | float __cdecl Bias(float,float) | ?Bias@@YAMMM@Z
    0x570E00 | float __cdecl Gain(float,float) | ?Gain@@YAMMM@Z
    0x570E80 | float __cdecl logf_fast(float) | ?logf_fast@@YAMM@Z
    0x570F10 | float __cdecl sqrtf_faster(float) | ?sqrtf_faster@@YAMM@Z
    0x570F80 | float __cdecl invsqrtf_fast(float) | ?invsqrtf_fast@@YAMM@Z
    0x571000 | float __cdecl expf_fast(float) | ?expf_fast@@YAMM@Z
    0x571090 | float __cdecl expf_faster(float) | ?expf_faster@@YAMM@Z
*/

// ?invsqrtf_fast@@YAMM@Z
ARTS_IMPORT f32 invsqrtf_fast(f32 arg1);

// ?logf_fast@@YAMM@Z
ARTS_IMPORT f32 logf_fast(f32 arg1);

// ?sqrtf_faster@@YAMM@Z
ARTS_IMPORT f32 sqrtf_faster(f32 arg1);
