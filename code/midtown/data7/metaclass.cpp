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

// TODO: Figure out why ClassIndex starts at index 1

MetaClass::MetaClass(const char* name, u32 size, void* (*allocate)(i32), void (*free)(void*, i32),
    void (*declare)(void), class MetaClass* parent)
    : name_(name)
    , size_(size)
    , allocate_(allocate)
    , free_(free)
    , declare_(declare)
    , parent_(parent)
{
    if (parent_)
        next_child_ = std::exchange(parent_->children_, this);

    if (NextSerial == MAX_CLASSES - 1)
        Abortf("Too many classes, raise MAX_CLASSES (data7/metaclass.cpp)");

    index_ = ++NextSerial;
    ClassIndex[NextSerial] = nullptr;
}

MetaClass::~MetaClass()
{
    if (index_ != NextSerial)
        Abortf("MetaClass destructed in wrong order, rebuild arts6 up");

    ClassIndex[NextSerial] = nullptr;
    --NextSerial;

    if (parent_)
    {
        MetaClass** i = &parent_->children_;

        for (; *i; i = &(*i)->next_child_)
        {
            if (*i == this)
            {
                *i = next_child_;

                break;
            }
        }
    }
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
