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

define_dummy_symbol(mmcity_anim);

#include "anim.h"

void mmAnimation::Load(char* arg1, class Stream* arg2)
{
    return stub<thiscall_t<void, mmAnimation*, char*, class Stream*>>(0x497EB0, this, arg1, arg2);
}

i32 mmAnimation::LookupSequence(char* arg1)
{
    return stub<thiscall_t<i32, mmAnimation*, char*>>(0x497E50, this, arg1);
}

class mmAnimation* GetAnimation(char* arg1)
{
    return stub<cdecl_t<class mmAnimation*, char*>>(0x498700, arg1);
}

void mmAnimInstState::Update()
{
    return stub<thiscall_t<void, mmAnimInstState*>>(0x498880, this);
}

void mmAnimInstState::PreUpdate(f32 arg1)
{
    return stub<cdecl_t<void, f32>>(0x498830, arg1);
}
