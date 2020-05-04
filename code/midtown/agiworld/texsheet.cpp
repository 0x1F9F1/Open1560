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

#include "texsheet.h"

char* mystrtok(char* arg1, char const* arg2)
{
    return stub<cdecl_t<char*, char*, char const*>>(0x111B30_Offset, arg1, arg2);
}

void agiTexSheet::Add(char* arg1)
{
    return stub<thiscall_t<void, agiTexSheet*, char*>>(0x1124A0_Offset, this, arg1);
}

i32 agiTexSheet::GetVariationCount(char* arg1)
{
    return stub<thiscall_t<i32, agiTexSheet*, char*>>(0x112410_Offset, this, arg1);
}

void agiTexSheet::Kill()
{
    return stub<thiscall_t<void, agiTexSheet*>>(0x1120A0_Offset, this);
}

void agiTexSheet::Load(char* arg1)
{
    return stub<thiscall_t<void, agiTexSheet*, char*>>(0x111B90_Offset, this, arg1);
}

struct agiTexProp* agiTexSheet::Lookup(char* arg1, i32 arg2)
{
    return stub<thiscall_t<struct agiTexProp*, agiTexSheet*, char*, i32>>(0x112340_Offset, this, arg1, arg2);
}

struct agiTexProp* agiTexSheet::LookupAlternate(char* arg1)
{
    return stub<thiscall_t<struct agiTexProp*, agiTexSheet*, char*>>(0x1123A0_Offset, this, arg1);
}

char* agiTexSheet::RemapName(char* arg1, i32 arg2)
{
    return stub<thiscall_t<char*, agiTexSheet*, char*, i32>>(0x112460_Offset, this, arg1, arg2);
}

void agiTexSheet::Save(char* arg1)
{
    return stub<thiscall_t<void, agiTexSheet*, char*>>(0x1120D0_Offset, this, arg1);
}

define_dummy_symbol(agiworld_texsheet);
