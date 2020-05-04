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
    return stub<thiscall_t<void, asLamp*, class Bank*>>(0x126310_Offset, this, arg1);
}

void asLamp::Cull()
{
    return stub<thiscall_t<void, asLamp*>>(0x126290_Offset, this);
}

void asLamp::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asLamp*, class MiniParser*>>(0x1262E0_Offset, this, arg1);
}

class MetaClass* asLamp::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asLamp*>>(0x1267E0_Offset, this);
}

void asLamp::SetColor(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, asLamp*, class Vector3 const&, f32>>(0x126130_Offset, this, arg1, arg2);
}

void asLamp::SetDistant()
{
    return stub<thiscall_t<void, asLamp*>>(0x126170_Offset, this);
}

void asLamp::SetPoint()
{
    return stub<thiscall_t<void, asLamp*>>(0x126180_Offset, this);
}

void asLamp::Update()
{
    return stub<thiscall_t<void, asLamp*>>(0x126190_Offset, this);
}

void asLamp::DeclareFields()
{
    return stub<cdecl_t<void>>(0x126680_Offset);
}

void asLamp::Regen()
{
    return stub<thiscall_t<void, asLamp*>>(0x1262F0_Offset, this);
}

define_dummy_symbol(arts7_lamp);
