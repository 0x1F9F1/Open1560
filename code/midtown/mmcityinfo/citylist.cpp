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
    return stub<thiscall_t<i32, mmCityList*, char*>>(0xCBD50_Offset, this, arg1);
}

class mmCityInfo* mmCityList::GetCityInfo(char* arg1)
{
    return stub<thiscall_t<class mmCityInfo*, mmCityList*, char*>>(0xCBCD0_Offset, this, arg1);
}

class mmCityInfo* mmCityList::GetCityInfo(i32 arg1)
{
    return stub<thiscall_t<class mmCityInfo*, mmCityList*, i32>>(0xCBCA0_Offset, this, arg1);
}

class mmCityInfo* mmCityList::GetCurrentCity()
{
    return stub<thiscall_t<class mmCityInfo*, mmCityList*>>(0xCBE20_Offset, this);
}

void mmCityList::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmCityList*, i32>>(0xCBC90_Offset, this, arg1);
}

void mmCityList::Load(char* arg1)
{
    return stub<thiscall_t<void, mmCityList*, char*>>(0xCBE30_Offset, this, arg1);
}

void mmCityList::LoadAll()
{
    return stub<thiscall_t<void, mmCityList*>>(0xCBFA0_Offset, this);
}

void mmCityList::Print()
{
    return stub<thiscall_t<void, mmCityList*>>(0xCBF60_Offset, this);
}

void mmCityList::SetCurrentCity(char* arg1)
{
    return stub<thiscall_t<void, mmCityList*, char*>>(0xCBDD0_Offset, this, arg1);
}

void mmCityList::SetCurrentCity(i32 arg1)
{
    return stub<thiscall_t<void, mmCityList*, i32>>(0xCBDF0_Offset, this, arg1);
}

define_dummy_symbol(mmcityinfo_citylist);
