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

define_dummy_symbol(arts7_cullable);

#include "cullable.h"

asCullable::asCullable()
{
    unimplemented();
}

asCullable::~asCullable()
{
    unimplemented(arg1);
}

void asCullable::Cull()
{
    return stub<thiscall_t<void, asCullable*>>(0x1258C0_Offset, this);
}

void asCullable::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asCullable*, class Bank*>>(0x1258D0_Offset, this, arg1);
}

class MetaClass* asCullable::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asCullable*>>(0x125A30_Offset, this);
}

void asCullable::DeclareFields()
{
    return stub<cdecl_t<void>>(0x1258E0_Offset);
}
