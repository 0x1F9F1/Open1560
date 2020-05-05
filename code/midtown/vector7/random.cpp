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

define_dummy_symbol(vector7_random);

#include "random.h"

f32 Random::Normal(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<f32, Random*, f32, f32>>(0x16DB10_Offset, this, arg1, arg2);
}

f32 Random::Number()
{
    return stub<thiscall_t<f32, Random*>>(0x16DAB0_Offset, this);
}

void Random::Seed(i32 arg1)
{
    return stub<thiscall_t<void, Random*, i32>>(0x16D9F0_Offset, this, arg1);
}
