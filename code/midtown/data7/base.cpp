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

define_dummy_symbol(data7_base);

#include "base.h"

Base::~Base()
{
    unimplemented(arg1);
}

class MetaClass* Base::GetClass()
{
    return stub<thiscall_t<class MetaClass*, Base*>>(0x179290_Offset, this);
}

char* Base::GetTypeNameV()
{
    return stub<thiscall_t<char*, Base*>>(0x1791A0_Offset, this);
}

void Base::BeforeSave()
{
    return stub<thiscall_t<void, Base*>>(0x1791C0_Offset, this);
}

void Base::AfterLoad()
{
    return stub<thiscall_t<void, Base*>>(0x1791D0_Offset, this);
}

char* Base::GetTypeName()
{
    return stub<thiscall_t<char*, Base*>>(0x1791B0_Offset, this);
}

void Base::DeclareFields()
{
    return stub<cdecl_t<void>>(0x1791F0_Offset);
}
