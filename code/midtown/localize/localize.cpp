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

#include "localize.h"

struct LocString* AngelReadString(u32 arg1)
{
    return stub<cdecl_t<struct LocString*, u32>>(0x1200D0_Offset, arg1);
}

char* GetLocTime(f32 arg1)
{
    return stub<cdecl_t<char*, f32>>(0x120010_Offset, arg1);
}

define_dummy_symbol(localize_localize);
