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

define_dummy_symbol(arts7_dof);

#include "dof.h"

asDofCS::asDofCS()
{
    unimplemented();
}

asDofCS::~asDofCS()
{
    unimplemented(arg1);
}

void asDofCS::operator=(class asDofCS const& arg1)
{
    return stub<thiscall_t<void, asDofCS*, class asDofCS const&>>(0x52ADE0, this, arg1);
}

void asDofCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asDofCS*, class Bank*>>(0x52B600, this, arg1);
}

void asDofCS::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asDofCS*, class MiniParser*>>(0x52B5D0, this, arg1);
}

class MetaClass* asDofCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asDofCS*>>(0x52BB60, this);
}

void asDofCS::Reset()
{
    return stub<thiscall_t<void, asDofCS*>>(0x52AF20, this);
}

void asDofCS::SetTime(f32 arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, asDofCS*, f32, f32, i32>>(0x52AF50, this, arg1, arg2, arg3);
}

void asDofCS::Update()
{
    return stub<thiscall_t<void, asDofCS*>>(0x52AFC0, this);
}

void asDofCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x52B9F0);
}

void asDofCS::ModeCB()
{
    return stub<thiscall_t<void, asDofCS*>>(0x52B5E0, this);
}
