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

define_dummy_symbol(agiworld_meshlight);

#include "meshlight.h"

// 0x5116B0 | ?agiInitCones@@YAXAAVMatrix34@@M@Z
ARTS_IMPORT /*static*/ void agiInitCones(class Matrix34& arg1, f32 arg2);

// 0x510EE0 | ?mmxTriple@@YAXPAI0HPAEH@Z
ARTS_IMPORT /*static*/ void mmxTriple(u32* arg1, u32* arg2, i32 arg3, u8* arg4, i32 arg5);
