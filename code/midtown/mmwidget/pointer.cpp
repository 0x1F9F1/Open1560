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

define_dummy_symbol(mmwidget_pointer);

#include "pointer.h"

sfPointer::sfPointer()
{
    unimplemented();
}

sfPointer::~sfPointer()
{
    unimplemented(arg1);
}

void sfPointer::Cull()
{
    return stub<thiscall_t<void, sfPointer*>>(0x4BDD30, this);
}

class MetaClass* sfPointer::GetClass()
{
    return stub<thiscall_t<class MetaClass*, sfPointer*>>(0x4BDF20, this);
}

f32 sfPointer::GetPointerHeight()
{
    return stub<thiscall_t<f32, sfPointer*>>(0x4BDA80, this);
}

void sfPointer::Init()
{
    return stub<thiscall_t<void, sfPointer*>>(0x4BDA00, this);
}

void sfPointer::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, sfPointer*, i32, i32>>(0x4BDA20, this, arg1, arg2);
}

void sfPointer::Update()
{
    return stub<thiscall_t<void, sfPointer*>>(0x4BDA90, this);
}

void sfPointer::WaitForRelease()
{
    return stub<thiscall_t<void, sfPointer*>>(0x4BDD20, this);
}

void sfPointer::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4BDDB0);
}

void sfPointer::UpdateAttached()
{
    return stub<thiscall_t<void, sfPointer*>>(0x4BDD10, this);
}
