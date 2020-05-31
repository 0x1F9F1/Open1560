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

define_dummy_symbol(agiworld_meshset);

#include "meshset.h"

agiMeshSet::agiMeshSet()
{
    unimplemented();
}

agiMeshSet::~agiMeshSet()
{
    unimplemented();
}

void agiMeshSet::ComputePlaneEquations()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x5148D0, this);
}

i32 agiMeshSet::IsFullyResident(i32 arg1)
{
    return stub<thiscall_t<i32, agiMeshSet*, i32>>(0x514BC0, this, arg1);
}

i32 agiMeshSet::LockIfResident()
{
    return stub<thiscall_t<i32, agiMeshSet*>>(0x514B20, this);
}

void agiMeshSet::MakeResident()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x514B90, this);
}

void agiMeshSet::Offset(class Vector3 arg1)
{
    return stub<thiscall_t<void, agiMeshSet*, class Vector3>>(0x514880, this, arg1);
}

void agiMeshSet::PageIn()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x514B00, this);
}

void agiMeshSet::Unlock()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x514B50, this);
}

void agiMeshSet::UnlockAndFree()
{
    return stub<thiscall_t<void, agiMeshSet*>>(0x514B70, this);
}

void agiMeshSet::PageInCallback(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x514AF0, arg1);
}
