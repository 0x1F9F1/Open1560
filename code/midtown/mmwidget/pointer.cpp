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

#include "pointer.h"

sfPointer::sfPointer()
{
    unimplemented();
}

sfPointer::~sfPointer()
{
    unimplemented();
}

void sfPointer::Cull()
{
    return stub<thiscall_t<void, sfPointer*>>(0xBDD30_Offset, this);
}

class MetaClass* sfPointer::GetClass()
{
    return stub<thiscall_t<class MetaClass*, sfPointer*>>(0xBDF20_Offset, this);
}

f32 sfPointer::GetPointerHeight()
{
    return stub<thiscall_t<f32, sfPointer*>>(0xBDA80_Offset, this);
}

void sfPointer::Init()
{
    return stub<thiscall_t<void, sfPointer*>>(0xBDA00_Offset, this);
}

void sfPointer::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, sfPointer*, i32, i32>>(0xBDA20_Offset, this, arg1, arg2);
}

void sfPointer::Update()
{
    return stub<thiscall_t<void, sfPointer*>>(0xBDA90_Offset, this);
}

void sfPointer::WaitForRelease()
{
    return stub<thiscall_t<void, sfPointer*>>(0xBDD20_Offset, this);
}

void sfPointer::DeclareFields()
{
    return stub<cdecl_t<void>>(0xBDDB0_Offset);
}

void sfPointer::UpdateAttached()
{
    return stub<thiscall_t<void, sfPointer*>>(0xBDD10_Offset, this);
}

define_dummy_symbol(mmwidget_pointer);
