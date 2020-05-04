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

#include "aero.h"

asAero::asAero()
{
    unimplemented();
}

asAero::~asAero()
{
    unimplemented();
}

void asAero::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asAero*, class Bank*>>(0xE0330_Offset, this, arg1);
}

class MetaClass* asAero::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asAero*>>(0xE0670_Offset, this);
}

void asAero::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, asAero*, class Stream*>>(0xE0130_Offset, this, arg1);
}

void asAero::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, asAero*, class Stream*>>(0xE0200_Offset, this, arg1);
}

void asAero::Update()
{
    return stub<thiscall_t<void, asAero*>>(0xDFC70_Offset, this);
}

void asAero::DeclareFields()
{
    return stub<cdecl_t<void>>(0xE0490_Offset);
}

define_dummy_symbol(mmphysics_aero);
