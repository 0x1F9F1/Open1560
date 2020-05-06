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

define_dummy_symbol(mmcar_force);

#include "force.h"

mmForce::mmForce()
{
    unimplemented();
}

mmForce::~mmForce()
{
    unimplemented(arg1);
}

void mmForce::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmForce*, class Bank*>>(0x480E10, this, arg1);
}

class MetaClass* mmForce::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmForce*>>(0x480F80, this);
}

void mmForce::Update()
{
    return stub<thiscall_t<void, mmForce*>>(0x480C00, this);
}

void mmForce::DeclareFields()
{
    return stub<cdecl_t<void>>(0x480E20);
}
