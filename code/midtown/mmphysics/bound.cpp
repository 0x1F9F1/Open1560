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

#include "bound.h"

asBound::asBound()
{
    unimplemented();
}

asBound::~asBound()
{
    unimplemented();
}

class agiPhysParameters& asBound::GetPhysMtl(class mmPolygon const& arg1)
{
    return stub<thiscall_t<class agiPhysParameters&, asBound*, class mmPolygon const&>>(0xDFAF0_Offset, this, arg1);
}

i32 asBound::Impact(class mmIntersection* arg1, class asBound* arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<i32, asBound*, class mmIntersection*, class asBound*, i32, i32, i32>>(
        0xDF110_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

define_dummy_symbol(mmphysics_bound);
