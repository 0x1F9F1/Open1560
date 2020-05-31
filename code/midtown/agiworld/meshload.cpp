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

define_dummy_symbol(agiworld_meshload);

#include "meshload.h"

#include "meshset.h"

void agiMeshSet::BinaryLoad(class Stream* arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Stream*>>(0x502BD0, this, arg1);
}

void agiMeshSet::DoPageIn()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x5032A0, this);
}

void agiMeshSet::PageOutCallback(void* arg1, i32 arg2)
{
    return stub<cdecl_t<void, void*, i32>>(0x503180, arg1, arg2);
}
