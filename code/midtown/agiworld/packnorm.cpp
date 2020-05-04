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

#include "packnorm.h"

u8 PackNormal(class Vector3& arg1)
{
    return stub<cdecl_t<u8, class Vector3&>>(0x1164B0_Offset, arg1);
}

u8 PackNormalSlow(class Vector3& arg1)
{
    return stub<cdecl_t<u8, class Vector3&>>(0x116400_Offset, arg1);
}

define_dummy_symbol(agiworld_packnorm);
