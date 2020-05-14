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

define_dummy_symbol(mmeffects_meshform);

#include "meshform.h"

asMeshSetForm::asMeshSetForm()
{
    unimplemented();
}

asMeshSetForm::~asMeshSetForm()
{
    unimplemented();
}

void asMeshSetForm::Cull()
{
    return stub<thiscall_t<void, asMeshSetForm*>>(0x4FFF60, this);
}

void asMeshSetForm::SetShape(char* arg1, char* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<void, asMeshSetForm*, char*, char*, class Vector3*>>(0x4FFEC0, this, arg1, arg2, arg3);
}

void asMeshSetForm::SetZRead(i32 arg1)
{
    return stub<thiscall_t<void, asMeshSetForm*, i32>>(0x4FFF00, this, arg1);
}

void asMeshSetForm::SetZWrite(i32 arg1)
{
    return stub<thiscall_t<void, asMeshSetForm*, i32>>(0x4FFF20, this, arg1);
}

void asMeshSetForm::Update()
{
    return stub<thiscall_t<void, asMeshSetForm*>>(0x4FFF40, this);
}
