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

define_dummy_symbol(agiworld_texsheet);

#include "texsheet.h"

char* mystrtok(char* arg1, char const* arg2)
{
    return stub<cdecl_t<char*, char*, char const*>>(0x511B30, arg1, arg2);
}

void agiTexSheet::Add(char* arg1)
{
    return stub<thiscall_t<void, agiTexSheet*, char*>>(0x5124A0, this, arg1);
}

i32 agiTexSheet::GetVariationCount(char* arg1)
{
    return stub<thiscall_t<i32, agiTexSheet*, char*>>(0x512410, this, arg1);
}

void agiTexSheet::Kill()
{
    return stub<thiscall_t<void, agiTexSheet*>>(0x5120A0, this);
}

void agiTexSheet::Load(char* arg1)
{
    return stub<thiscall_t<void, agiTexSheet*, char*>>(0x511B90, this, arg1);
}

struct agiTexProp* agiTexSheet::Lookup(char* arg1, i32 arg2)
{
    return stub<thiscall_t<struct agiTexProp*, agiTexSheet*, char*, i32>>(0x512340, this, arg1, arg2);
}

struct agiTexProp* agiTexSheet::LookupAlternate(char* arg1)
{
    return stub<thiscall_t<struct agiTexProp*, agiTexSheet*, char*>>(0x5123A0, this, arg1);
}

char* agiTexSheet::RemapName(char* arg1, i32 arg2)
{
    return stub<thiscall_t<char*, agiTexSheet*, char*, i32>>(0x512460, this, arg1, arg2);
}

void agiTexSheet::Save(char* arg1)
{
    return stub<thiscall_t<void, agiTexSheet*, char*>>(0x5120D0, this, arg1);
}
