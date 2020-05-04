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

#include "collide.h"

i32 mmCollideFF::Assign(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmCollideFF*, i32, i32>>(0xE7660_Offset, this, arg1, arg2);
}

i32 mmCollideFF::Init(struct IDirectInputDevice2A* arg1)
{
    return stub<thiscall_t<i32, mmCollideFF*, struct IDirectInputDevice2A*>>(0xE7470_Offset, this, arg1);
}

i32 mmCollideFF::Play()
{
    return stub<thiscall_t<i32, mmCollideFF*>>(0xE7760_Offset, this);
}

i32 mmCollideFF::SetValues(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmCollideFF*, f32, f32>>(0xE7630_Offset, this, arg1, arg2);
}

i32 mmCollideFF::Stop()
{
    return stub<thiscall_t<i32, mmCollideFF*>>(0xE77B0_Offset, this);
}

define_dummy_symbol(mminput_collide);
