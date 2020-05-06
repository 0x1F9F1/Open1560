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

define_dummy_symbol(data7_metaclass);

#include "metaclass.h"

MetaClass::MetaClass(
    char* arg1, u32 arg2, void* (*arg3)(i32), void (*arg4)(void*, i32), void (*arg5)(void), class MetaClass* arg6)
{
    unimplemented(arg1, arg2, arg3, arg4, arg5, arg6);
}

MetaClass::~MetaClass()
{
    unimplemented();
}

void MetaClass::InitFields()
{
    return stub<thiscall_t<void, MetaClass*>>(0x577C70, this);
}

i32 MetaClass::IsSubclassOf(class MetaClass* arg1)
{
    return stub<thiscall_t<i32, MetaClass*, class MetaClass*>>(0x577BB0, this, arg1);
}

void MetaClass::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, MetaClass*, class MiniParser*, void*>>(0x577E90, this, arg1, arg2);
}

void MetaClass::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, MetaClass*, class MiniParser*, void*>>(0x577C90, this, arg1, arg2);
}

void MetaClass::SkipBlock(class MiniParser* arg1)
{
    return stub<thiscall_t<void, MetaClass*, class MiniParser*>>(0x577DE0, this, arg1);
}

void MetaClass::DeclareNamedTypedField(char* arg1, u32 arg2, struct MetaType* arg3)
{
    return stub<cdecl_t<void, char*, u32, struct MetaType*>>(0x578000, arg1, arg2, arg3);
}

class MetaClass* MetaClass::FindByName(char* arg1, class MetaClass* arg2)
{
    return stub<cdecl_t<class MetaClass*, char*, class MetaClass*>>(0x577BE0, arg1, arg2);
}

void MetaClass::UndeclareAll()
{
    return stub<cdecl_t<void>>(0x577B80);
}

void __BadSafeCall(char* arg1, class Base* arg2)
{
    return stub<cdecl_t<void, char*, class Base*>>(0x577C50, arg1, arg2);
}
