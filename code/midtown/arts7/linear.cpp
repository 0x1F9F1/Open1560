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

define_dummy_symbol(arts7_linear);

#include "linear.h"

asLinearCS::asLinearCS()
{
    unimplemented();
}

asLinearCS::~asLinearCS()
{
    unimplemented(arg1);
}

void asLinearCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asLinearCS*, class Bank*>>(0x125CC0_Offset, this, arg1);
}

void asLinearCS::Cull()
{
    return stub<thiscall_t<void, asLinearCS*>>(0x125C00_Offset, this);
}

void asLinearCS::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asLinearCS*, class MiniParser*>>(0x125CB0_Offset, this, arg1);
}

class MetaClass* asLinearCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asLinearCS*>>(0x125FF0_Offset, this);
}

void asLinearCS::Update()
{
    return stub<thiscall_t<void, asLinearCS*>>(0x125B20_Offset, this);
}

void asLinearCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x125E20_Offset);
}
