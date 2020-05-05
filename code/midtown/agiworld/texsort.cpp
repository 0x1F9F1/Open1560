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

#include "texsort.h"

agiTexSorter::agiTexSorter()
{
    unimplemented();
}

agiTexSorter::~agiTexSorter()
{
    Instance = nullptr;
}

void agiTexSorter::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, agiTexSorter*, class Bank*>>(0x104620_Offset, this, arg1);
}

void agiTexSorter::Cull(i32 arg1)
{
    return stub<thiscall_t<void, agiTexSorter*, i32>>(0x104090_Offset, this, arg1);
}

class agiPolySet* agiTexSorter::BeginVerts(class agiTexDef* arg1, i32 arg2, i32 arg3)
{
    return stub<cdecl_t<class agiPolySet*, class agiTexDef*, i32, i32>>(0x103B20_Offset, arg1, arg2, arg3);
}

class agiPolySet* agiTexSorter::BeginVerts2(class agiTexDef* arg1, class agiTexDef* arg2, i32 arg3, i32 arg4)
{
    return stub<cdecl_t<class agiPolySet*, class agiTexDef*, class agiTexDef*, i32, i32>>(
        0x103D70_Offset, arg1, arg2, arg3, arg4);
}

void agiTexSorter::DoTexture(class agiPolySet* arg1)
{
    return stub<cdecl_t<void, class agiPolySet*>>(0x104150_Offset, arg1);
}

void agiTexSorter::EndVerts()
{
    return stub<cdecl_t<void>>(0x103FF0_Offset);
}

void agiTexSorter::EndVerts2()
{
    return stub<cdecl_t<void>>(0x104040_Offset);
}

class agiPolySet* agiTexSorter::GetEnv(class agiTexDef* arg1, i32 arg2, i32 arg3)
{
    return stub<cdecl_t<class agiPolySet*, class agiTexDef*, i32, i32>>(0x103A60_Offset, arg1, arg2, arg3);
}

class agiTexDef* GetPackedTexture(char* arg1, i32 arg2)
{
    return stub<cdecl_t<class agiTexDef*, char*, i32>>(0x1043E0_Offset, arg1, arg2);
}

define_dummy_symbol(agiworld_texsort);
