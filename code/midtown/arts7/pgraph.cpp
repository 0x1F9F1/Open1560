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

#include "pgraph.h"

asPerfGraph::asPerfGraph()
{
    unimplemented();
}

asPerfGraph::~asPerfGraph()
{
    unimplemented();
}

void asPerfGraph::AddComponent(char* arg1, f32* arg2, class Vector3& arg3)
{
    return stub<thiscall_t<void, asPerfGraph*, char*, f32*, class Vector3&>>(0x12A960_Offset, this, arg1, arg2, arg3);
}

void asPerfGraph::Cull()
{
    return stub<thiscall_t<void, asPerfGraph*>>(0x12AB30_Offset, this);
}

void asPerfGraph::Key(i32 arg1)
{
    return stub<thiscall_t<void, asPerfGraph*, i32>>(0x12A9E0_Offset, this, arg1);
}

void asPerfGraph::Update()
{
    return stub<thiscall_t<void, asPerfGraph*>>(0x12AA30_Offset, this);
}

define_dummy_symbol(arts7_pgraph);
