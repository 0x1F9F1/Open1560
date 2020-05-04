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

#include "mapdata.h"

mmMapData::mmMapData()
{
    unimplemented();
}

mmMapData::~mmMapData()
{
    unimplemented();
}

void mmMapData::Append(char* arg1)
{
    return stub<thiscall_t<void, mmMapData*, char*>>(0xD3380_Offset, this, arg1);
}

class MetaClass* mmMapData::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMapData*>>(0xD35B0_Offset, this);
}

char* mmMapData::GetItem(i32 arg1)
{
    return stub<thiscall_t<char*, mmMapData*, i32>>(0xD3340_Offset, this, arg1);
}

i32 mmMapData::GetNumItems()
{
    return stub<thiscall_t<i32, mmMapData*>>(0xD3370_Offset, this);
}

void mmMapData::NewItems(i32 arg1)
{
    return stub<thiscall_t<void, mmMapData*, i32>>(0xD32F0_Offset, this, arg1);
}

void mmMapData::SetItem(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmMapData*, i32, char*>>(0xD3320_Offset, this, arg1, arg2);
}

void mmMapData::DeclareFields()
{
    return stub<cdecl_t<void>>(0xD3400_Offset);
}

define_dummy_symbol(mmcityinfo_mapdata);
