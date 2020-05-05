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

define_dummy_symbol(agiworld_bone);

#include "bone.h"

bnBone::bnBone()
{
    unimplemented();
}

void bnBone::AddChild(class bnBone* arg1)
{
    return stub<thiscall_t<void, bnBone*, class bnBone*>>(0x116E40_Offset, this, arg1);
}

void bnBone::Attach(class Matrix34* const arg1, i32& arg2)
{
    return stub<thiscall_t<void, bnBone*, class Matrix34* const, i32&>>(0x116FD0_Offset, this, arg1, arg2);
}

void bnBone::Draw()
{
    return stub<thiscall_t<void, bnBone*>>(0x116FC0_Offset, this);
}

i32 bnBone::Load(class Tokenizer* arg1, class bnBone** arg2)
{
    return stub<thiscall_t<i32, bnBone*, class Tokenizer*, class bnBone**>>(0x116E80_Offset, this, arg1, arg2);
}

void bnBone::Pose(class Vector3 const* arg1, i32& arg2)
{
    return stub<thiscall_t<void, bnBone*, class Vector3 const*, i32&>>(0x117030_Offset, this, arg1, arg2);
}

void bnBone::Transform(class Matrix34* arg1)
{
    return stub<thiscall_t<void, bnBone*, class Matrix34*>>(0x116F70_Offset, this, arg1);
}
