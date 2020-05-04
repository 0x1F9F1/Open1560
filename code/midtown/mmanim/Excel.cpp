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

#include "Excel.h"

mmAnimExcel::mmAnimExcel()
{
    unimplemented();
}

mmAnimExcel::~mmAnimExcel()
{
    unimplemented();
}

void mmAnimExcel::AddFile(char* arg1, char* arg2)
{
    return stub<thiscall_t<void, mmAnimExcel*, char*, char*>>(0xC3600_Offset, this, arg1, arg2);
}

char* mmAnimExcel::GetName(i32 arg1)
{
    return stub<thiscall_t<char*, mmAnimExcel*, i32>>(0xC3770_Offset, this, arg1);
}

char* mmAnimExcel::GetNextName()
{
    return stub<thiscall_t<char*, mmAnimExcel*>>(0xC35C0_Offset, this);
}

char* mmAnimExcel::GetPriorName()
{
    return stub<thiscall_t<char*, mmAnimExcel*>>(0xC3740_Offset, this);
}

i32 mmAnimExcel::Init(char* arg1, char* arg2)
{
    return stub<thiscall_t<i32, mmAnimExcel*, char*, char*>>(0xC3530_Offset, this, arg1, arg2);
}

define_dummy_symbol(mmanim_Excel);
