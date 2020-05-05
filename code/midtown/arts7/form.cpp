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

define_dummy_symbol(arts7_form);

#include "form.h"

asForm::asForm()
{
    unimplemented();
}

asForm::~asForm()
{
    unimplemented(arg1);
}

void asForm::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asForm*, class Bank*>>(0x1288E0_Offset, this, arg1);
}

void asForm::Cull()
{
    return stub<thiscall_t<void, asForm*>>(0x128520_Offset, this);
}

void asForm::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asForm*, class MiniParser*>>(0x1288D0_Offset, this, arg1);
}

class Vector3 asForm::GetBoundMax()
{
    return stub<thiscall_t<class Vector3, asForm*>>(0x128820_Offset, this);
}

class Vector3 asForm::GetBoundMin()
{
    return stub<thiscall_t<class Vector3, asForm*>>(0x1287D0_Offset, this);
}

class Vector4 asForm::GetBoundSphere()
{
    return stub<thiscall_t<class Vector4, asForm*>>(0x128870_Offset, this);
}

class MetaClass* asForm::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asForm*>>(0x128B40_Offset, this);
}

void asForm::SetCull(i32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, asForm*, i32, f32>>(0x1284D0_Offset, this, arg1, arg2);
}

void asForm::SetDLP(class DLP* arg1)
{
    return stub<thiscall_t<void, asForm*, class DLP*>>(0x128420_Offset, this, arg1);
}

void asForm::SetShape(char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, asForm*, char*, char*, class Vector3*, i32, i32>>(
        0x128450_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void asForm::Update()
{
    return stub<thiscall_t<void, asForm*>>(0x1284F0_Offset, this);
}

i32 asForm::Visible(class asCamera* arg1, class Matrix34 const& arg2)
{
    return stub<thiscall_t<i32, asForm*, class asCamera*, class Matrix34 const&>>(0x128600_Offset, this, arg1, arg2);
}

void asForm::DeclareFields()
{
    return stub<cdecl_t<void>>(0x1289D0_Offset);
}
