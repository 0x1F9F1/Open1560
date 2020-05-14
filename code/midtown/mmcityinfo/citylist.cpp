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

define_dummy_symbol(mmcityinfo_citylist);

#include "citylist.h"

mmCityList::mmCityList()
{
    unimplemented();
}

mmCityList::~mmCityList()
{
    unimplemented();
}

i32 mmCityList::GetCityID(char* arg1)
{
    return stub<thiscall_t<i32, mmCityList*, char*>>(0x4CBD50, this, arg1);
}

class mmCityInfo* mmCityList::GetCityInfo(char* arg1)
{
    return stub<thiscall_t<class mmCityInfo*, mmCityList*, char*>>(0x4CBCD0, this, arg1);
}

class mmCityInfo* mmCityList::GetCityInfo(i32 arg1)
{
    return stub<thiscall_t<class mmCityInfo*, mmCityList*, i32>>(0x4CBCA0, this, arg1);
}

class mmCityInfo* mmCityList::GetCurrentCity()
{
    return stub<thiscall_t<class mmCityInfo*, mmCityList*>>(0x4CBE20, this);
}

void mmCityList::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmCityList*, i32>>(0x4CBC90, this, arg1);
}

void mmCityList::Load(char* arg1)
{
    return stub<thiscall_t<void, mmCityList*, char*>>(0x4CBE30, this, arg1);
}

void mmCityList::LoadAll()
{
    return stub<thiscall_t<void, mmCityList*>>(0x4CBFA0, this);
}

void mmCityList::Print()
{
    return stub<thiscall_t<void, mmCityList*>>(0x4CBF60, this);
}

void mmCityList::SetCurrentCity(char* arg1)
{
    return stub<thiscall_t<void, mmCityList*, char*>>(0x4CBDD0, this, arg1);
}

void mmCityList::SetCurrentCity(i32 arg1)
{
    return stub<thiscall_t<void, mmCityList*, i32>>(0x4CBDF0, this, arg1);
}
