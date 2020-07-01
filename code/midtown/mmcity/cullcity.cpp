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

define_dummy_symbol(mmcity_cullcity);

#include "cullcity.h"

void mmRunwayLight::AddWidgets(class Bank* /*arg1*/)
{}

void ARTS_FASTCALL mmRunwayLight::FromMatrix(class Matrix34 const& /*arg1*/)
{}

// 0x48E220 | ?fix_fill1@@YAXXZ
ARTS_IMPORT /*static*/ void fix_fill1();

// 0x48E290 | ?fix_fill2@@YAXXZ
ARTS_IMPORT /*static*/ void fix_fill2();

// 0x48E1B0 | ?fix_sun@@YAXXZ
ARTS_IMPORT /*static*/ void fix_sun();

// 0x48E3D0 | ?parseARGB@@YAXAAI@Z
ARTS_IMPORT /*static*/ void parseARGB(u32& arg1);

// 0x48E300 | ?parseFloat@@YAXAAM@Z
ARTS_IMPORT /*static*/ void parseFloat(f32& arg1);

// 0x48E360 | ?parseRGB@@YAXAAI@Z
ARTS_IMPORT /*static*/ void parseRGB(u32& arg1);

// 0x48E330 | ?parseVector3@@YAXAAVVector3@@@Z
ARTS_IMPORT /*static*/ void parseVector3(class Vector3& arg1);
