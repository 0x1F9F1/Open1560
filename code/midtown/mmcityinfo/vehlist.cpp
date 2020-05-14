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

define_dummy_symbol(mmcityinfo_vehlist);

#include "vehlist.h"

mmVehList::mmVehList()
{
    unimplemented();
}

mmVehList::~mmVehList()
{
    unimplemented();
}

i32 mmVehList::GetVehicleID(char* arg1)
{
    return stub<thiscall_t<i32, mmVehList*, char*>>(0x4CC1C0, this, arg1);
}

class mmVehInfo* mmVehList::GetVehicleInfo(char* arg1)
{
    return stub<thiscall_t<class mmVehInfo*, mmVehList*, char*>>(0x4CC140, this, arg1);
}

class mmVehInfo* mmVehList::GetVehicleInfo(i32 arg1)
{
    return stub<thiscall_t<class mmVehInfo*, mmVehList*, i32>>(0x4CC110, this, arg1);
}

void mmVehList::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmVehList*, i32>>(0x4CC100, this, arg1);
}

void mmVehList::Load(char* arg1)
{
    return stub<thiscall_t<void, mmVehList*, char*>>(0x4CC240, this, arg1);
}

void mmVehList::LoadAll()
{
    return stub<thiscall_t<void, mmVehList*>>(0x4CC3C0, this);
}

void mmVehList::Print()
{
    return stub<thiscall_t<void, mmVehList*>>(0x4CC370, this);
}
