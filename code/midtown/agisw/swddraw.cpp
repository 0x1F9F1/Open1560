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

define_dummy_symbol(agisw_swddraw);

#include "swddraw.h"

// 0x534FA0 | ?ddEnd@@YAXXZ
ARTS_IMPORT /*static*/ void ddEnd();

// 0x535070 | ?ddEndFrame@@YAXXZ
ARTS_IMPORT /*static*/ void ddEndFrame();

// 0x535030 | ?ddEndScene@@YAXXZ
ARTS_IMPORT /*static*/ void ddEndScene();

// 0x534EA0 | ?ddStart@@YAXXZ
ARTS_IMPORT /*static*/ void ddStart();

// 0x534FC0 | ?ddStartFrame@@YAXXZ
ARTS_IMPORT /*static*/ void ddStartFrame();

// 0x534FD0 | ?ddStartScene@@YAXXZ
ARTS_IMPORT /*static*/ void ddStartScene();
