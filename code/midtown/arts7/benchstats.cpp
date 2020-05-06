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

define_dummy_symbol(arts7_benchstats);

#include "benchstats.h"

void asBenchStats::Average(class asBenchStats* arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, asBenchStats*, class asBenchStats*, f32, i32>>(0x52CEB0, this, arg1, arg2, arg3);
}

void asBenchStats::Current(class asBenchStats* arg1)
{
    return stub<thiscall_t<void, asBenchStats*, class asBenchStats*>>(0x52CFD0, this, arg1);
}

void asBenchStats::Print()
{
    return stub<thiscall_t<void, asBenchStats*>>(0x52CEA0, this);
}

void asBenchStats::Reset()
{
    return stub<thiscall_t<void, asBenchStats*>>(0x52CE60, this);
}
