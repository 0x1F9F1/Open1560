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

define_dummy_symbol(arts7_lamp);

#include "lamp.h"

asLamp::asLamp()
{
    unimplemented();
}

asLamp::~asLamp()
{
    unimplemented();
}

void asLamp::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asLamp*, class Bank*>>(0x526310, this, arg1);
}

void asLamp::Cull()
{
    return stub<thiscall_t<void, asLamp*>>(0x526290, this);
}

void asLamp::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asLamp*, class MiniParser*>>(0x5262E0, this, arg1);
}

class MetaClass* asLamp::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asLamp*>>(0x5267E0, this);
}

void asLamp::SetColor(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, asLamp*, class Vector3 const&, f32>>(0x526130, this, arg1, arg2);
}

void asLamp::SetDistant()
{
    return stub<thiscall_t<void, asLamp*>>(0x526170, this);
}

void asLamp::SetPoint()
{
    return stub<thiscall_t<void, asLamp*>>(0x526180, this);
}

void asLamp::Update()
{
    return stub<thiscall_t<void, asLamp*>>(0x526190, this);
}

void asLamp::DeclareFields()
{
    return stub<cdecl_t<void>>(0x526680);
}

void asLamp::Regen()
{
    return stub<thiscall_t<void, asLamp*>>(0x5262F0, this);
}
