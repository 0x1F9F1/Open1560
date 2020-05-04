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

#include "quat.h"

class Quaternion Quaternion::operator~()
{
    return stub<thiscall_t<class Quaternion, Quaternion*>>(0x1727F0_Offset, this);
}

f32 Quaternion::Angle(class Quaternion const& arg1)
{
    return stub<thiscall_t<f32, Quaternion*, class Quaternion const&>>(0x1729C0_Offset, this, arg1);
}

i32 Quaternion::Approach(class Quaternion const& arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<i32, Quaternion*, class Quaternion const&, f32, f32>>(
        0x173120_Offset, this, arg1, arg2, arg3);
}

void Quaternion::CatmullRom(f32 arg1, class Quaternion const& arg2, class Quaternion const& arg3,
    class Quaternion const& arg4, class Quaternion const& arg5)
{
    return stub<thiscall_t<void, Quaternion*, f32, class Quaternion const&, class Quaternion const&,
        class Quaternion const&, class Quaternion const&>>(0x1731A0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void Quaternion::FromMatrix(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Quaternion*, class Matrix34 const&>>(0x1726A0_Offset, this, arg1);
}

void Quaternion::Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, Quaternion*, f32, f32, f32, f32>>(0x172550_Offset, this, arg1, arg2, arg3, arg4);
}

void Quaternion::Lerp(f32 arg1, class Quaternion const& arg2, class Quaternion const& arg3)
{
    return stub<thiscall_t<void, Quaternion*, f32, class Quaternion const&, class Quaternion const&>>(
        0x172CE0_Offset, this, arg1, arg2, arg3);
}

f32 Quaternion::Mag()
{
    return stub<thiscall_t<f32, Quaternion*>>(0x172890_Offset, this);
}

void Quaternion::Normalize()
{
    return stub<thiscall_t<void, Quaternion*>>(0x172960_Offset, this);
}

void Quaternion::Slerp(f32 arg1, class Quaternion const& arg2, class Quaternion const& arg3)
{
    return stub<thiscall_t<void, Quaternion*, f32, class Quaternion const&, class Quaternion const&>>(
        0x172F60_Offset, this, arg1, arg2, arg3);
}

void Quaternion::TrackBall(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, Quaternion*, f32, f32, f32, f32, f32>>(
        0x172A30_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

define_dummy_symbol(vector7_quat);
