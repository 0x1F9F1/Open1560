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

define_dummy_symbol(mmdyna_bndtmpl2);

#include "bndtmpl2.h"

b32 EdgeInList(i32 v1, i32 v2, ilong count, i32* edge_1s, i32* edge_2s)
{
    for (i32 i = 0; i < count; ++i)
    {
        if ((v1 == edge_1s[i] && v2 == edge_2s[i]) || (v1 == edge_2s[i] && v2 == edge_1s[i]))
        {
            return true;
        }
    }

    return false;
}