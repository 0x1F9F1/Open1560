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

define_dummy_symbol(mmcar_axle);

#include "axle.h"

mmAxle::mmAxle()
{
    unimplemented();
}

mmAxle::~mmAxle()
{
    unimplemented(arg1);
}

void mmAxle::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmAxle*, class Bank*>>(0x7D590_Offset, this, arg1);
}

class MetaClass* mmAxle::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmAxle*>>(0x7D720_Offset, this);
}

void mmAxle::Init(char* arg1, char* arg2, class mmWheel* arg3, class mmWheel* arg4)
{
    return stub<thiscall_t<void, mmAxle*, char*, char*, class mmWheel*, class mmWheel*>>(
        0x7D4A0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmAxle::Update()
{
    return stub<thiscall_t<void, mmAxle*>>(0x7D4F0_Offset, this);
}

void mmAxle::DeclareFields()
{
    return stub<cdecl_t<void>>(0x7D5B0_Offset);
}
