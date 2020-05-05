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

define_dummy_symbol(mminput_spring);

#include "spring.h"

i32 mmSpringFF::Assign(i32 arg1)
{
    return stub<thiscall_t<i32, mmSpringFF*, i32>>(0xE7E80_Offset, this, arg1);
}

i32 mmSpringFF::Init(struct IDirectInputDevice2A* arg1)
{
    return stub<thiscall_t<i32, mmSpringFF*, struct IDirectInputDevice2A*>>(0xE7D50_Offset, this, arg1);
}

i32 mmSpringFF::Play()
{
    return stub<thiscall_t<i32, mmSpringFF*>>(0xE7F70_Offset, this);
}

i32 mmSpringFF::SetValues(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmSpringFF*, f32, f32>>(0xE7E50_Offset, this, arg1, arg2);
}

i32 mmSpringFF::Stop()
{
    return stub<thiscall_t<i32, mmSpringFF*>>(0xE7FE0_Offset, this);
}
