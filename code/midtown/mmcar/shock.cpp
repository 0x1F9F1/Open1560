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

define_dummy_symbol(mmcar_shock);

#include "shock.h"

mmShock::mmShock()
{
    unimplemented();
}

mmShock::~mmShock()
{
    unimplemented(arg1);
}

void mmShock::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmShock*, class Bank*>>(0x7D280_Offset, this, arg1);
}

class MetaClass* mmShock::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmShock*>>(0x7D410_Offset, this);
}

void mmShock::Init(char* arg1, char* arg2, class mmWheel* arg3)
{
    return stub<thiscall_t<void, mmShock*, char*, char*, class mmWheel*>>(0x7D210_Offset, this, arg1, arg2, arg3);
}

void mmShock::Update()
{
    return stub<thiscall_t<void, mmShock*>>(0x7D270_Offset, this);
}

void mmShock::DeclareFields()
{
    return stub<cdecl_t<void>>(0x7D2A0_Offset);
}
