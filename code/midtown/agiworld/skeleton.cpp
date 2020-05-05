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

define_dummy_symbol(agiworld_skeleton);

#include "skeleton.h"

bnSkeleton::bnSkeleton()
{
    unimplemented();
}

bnSkeleton::~bnSkeleton()
{
    unimplemented();
}

void bnSkeleton::Attach(class Matrix34* const arg1)
{
    return stub<thiscall_t<void, bnSkeleton*, class Matrix34* const>>(0x115080_Offset, this, arg1);
}

void bnSkeleton::Draw()
{
    return stub<thiscall_t<void, bnSkeleton*>>(0x115070_Offset, this);
}

class bnBone* bnSkeleton::FindBone(char* arg1, i32 arg2, char arg3)
{
    return stub<thiscall_t<class bnBone*, bnSkeleton*, char*, i32, char>>(0x115100_Offset, this, arg1, arg2, arg3);
}

i32 bnSkeleton::HowMany(char* arg1, char arg2)
{
    return stub<thiscall_t<i32, bnSkeleton*, char*, char>>(0x115220_Offset, this, arg1, arg2);
}

i32 bnSkeleton::Load(char const* arg1)
{
    return stub<thiscall_t<i32, bnSkeleton*, char const*>>(0x114C70_Offset, this, arg1);
}

void bnSkeleton::Pose(class Vector3 const* arg1)
{
    return stub<thiscall_t<void, bnSkeleton*, class Vector3 const*>>(0x1150B0_Offset, this, arg1);
}

i32 bnSkeleton::Save(char const* arg1)
{
    return stub<thiscall_t<i32, bnSkeleton*, char const*>>(0x114FA0_Offset, this, arg1);
}

void bnSkeleton::Transform(class Matrix34* arg1)
{
    return stub<thiscall_t<void, bnSkeleton*, class Matrix34*>>(0x115050_Offset, this, arg1);
}

i32 bnAnimation::Load(char* arg1)
{
    return stub<thiscall_t<i32, bnAnimation*, char*>>(0x115260_Offset, this, arg1);
}

class bnAnimation* bnAnimation::Lookup(char* arg1)
{
    return stub<cdecl_t<class bnAnimation*, char*>>(0x1153F0_Offset, arg1);
}
