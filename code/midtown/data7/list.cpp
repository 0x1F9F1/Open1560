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

#include "list.h"

List::~List()
{
    unimplemented();
}

void* List::Access(i32 arg1)
{
    return stub<thiscall_t<void*, List*, i32>>(0x17C330_Offset, this, arg1);
}

i32 List::Delete(i32 arg1)
{
    return stub<thiscall_t<i32, List*, i32>>(0x17C360_Offset, this, arg1);
}

i32 List::Insert(i32 arg1, void* arg2)
{
    return stub<thiscall_t<i32, List*, i32, void*>>(0x17C2B0_Offset, this, arg1, arg2);
}

void List::Kill()
{
    return stub<thiscall_t<void, List*>>(0x17C290_Offset, this);
}

define_dummy_symbol(data7_list);
