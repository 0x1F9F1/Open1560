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

#include "valloc.h"

asSafeHeap::asSafeHeap()
{
    unimplemented();
}

asSafeHeap::~asSafeHeap()
{
    unimplemented();
}

void asSafeHeap::Init(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asSafeHeap*, i32, i32>>(0x1213B0_Offset, this, arg1, arg2);
}

void asSafeHeap::Kill()
{
    return stub<thiscall_t<void, asSafeHeap*>>(0x121450_Offset, this);
}

void asSafeHeap::Restart()
{
    return stub<thiscall_t<void, asSafeHeap*>>(0x121420_Offset, this);
}

void asSafeHeap::Activate()
{
    return stub<thiscall_t<void, asSafeHeap*>>(0x121480_Offset, this);
}

void asSafeHeap::Deactivate()
{
    return stub<thiscall_t<void, asSafeHeap*>>(0x1214C0_Offset, this);
}

define_dummy_symbol(memory_valloc);
