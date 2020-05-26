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

#include "metadefine.h"

#include <mem/module.h>

#include <unordered_map>

MetaClass* MetaClass::ClassIndex[MAX_CLASSES] {};
i32 MetaClass::NextSerial {0};

MetaClass* MetaClass::Current {nullptr};
MetaField** MetaClass::ppField {nullptr};

MetaClass MetaClass::RootMetaClass {"Root", 0, nullptr, nullptr, nullptr, nullptr};

MetaClass::MetaClass(const char* name, u32 size, void* (*allocate)(i32), void (*free)(void*, i32),
    void (*declare)(void), class MetaClass* parent)
    : name_(name)
    , size_(size)
    , allocate_(allocate)
    , free_(free)
    , declare_(declare)
    , parent_(parent)
{
    export_hook(0x577AA0);

    Register();
}

MetaClass::~MetaClass()
{
    export_hook(0x577B20);

    Unregister();
}

ARTS_NOINLINE void MetaClass::Register()
{
    ArAssert(NextSerial < i32(MAX_CLASSES), "Too many classes, raise MAX_CLASSES");

    ClassIndex[NextSerial] = this;
    index_ = NextSerial;
    ++NextSerial;
}

ARTS_NOINLINE void MetaClass::Unregister()
{
    if (index_ != -1)
    {
        ArAssert(index_ + 1 == NextSerial, "MetaClass destructed in wrong order");

        --NextSerial;
        ClassIndex[NextSerial] = nullptr;

        for (MetaClass* i = children_; i; i = std::exchange(i->next_child_, nullptr))
            i->parent_ = nullptr;

        if (parent_)
        {
            ArAssert(parent_->children_ == this, "MetaClass destructed in wrong order");

            parent_->children_ = next_child_;
        }
    }
}

void MetaClass::InitFields()
{
    export_hook(0x577C70);

    ArAssert(Current == nullptr, "Cannot declare nested fields");

    Current = this;
    ppField = &fields_;

    declare_();

    ppField = nullptr;
    Current = nullptr;
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

void MetaClass::FixupClasses()
{
    create_hook(
        "MetaClass::Load Base", "Point to correct BaseMetaclass", 0x577FD2, GetMetaClass<Base>(), hook_type::push);

    create_hook("MetaClass::Load Root", "Point to correct RootMetaClass", 0x577EBA, &RootMetaClass, hook_type::push);

    create_hook(
        "MetaClass::Save Base", "Point to correct BaseMetaclass", 0x577CAA, GetMetaClass<Base>(), hook_type::push);

    mem::module main_module = mem::module::main();

    std::unordered_map<std::string, MetaClass*> fixups;

    // Find classes registered by Open1560
    for (i32 i = 0; i < NextSerial; ++i)
    {
        MetaClass* cls = ClassIndex[i];

        if (!main_module.contains(cls))
            fixups.emplace(cls->name_, cls);
    }

    // Replace original parent pointers with our new ones
    for (i32 i = 0; i < NextSerial; ++i)
    {
        MetaClass* cls = ClassIndex[i];

        cls->next_child_ = nullptr;

        if (cls->parent_ == nullptr)
            continue;

        if (auto find = fixups.find(cls->parent_->name_); find != fixups.end())
            cls->parent_ = find->second;
    }

    // Remove replaced classes from ClassIndex
    i32 total = 0;

    for (i32 i = 0; i < NextSerial; ++i)
    {
        MetaClass* cls = std::exchange(ClassIndex[i], nullptr);

        cls->index_ = -1;

        if (auto find = fixups.find(cls->name_); find != fixups.end() && find->second != cls)
        {
            if (cls->declare_ && find->second->declare_)
                create_hook("DeclareFields", cls->name_, cls->declare_, find->second->declare_, hook_type::jmp);

            ArAssert(cls->size_ == find->second->size_, "Class Size Mismatch");

            cls->allocate_ = find->second->allocate_;
            cls->free_ = find->second->free_;
            cls->declare_ = find->second->declare_;

            continue;
        }

        cls->index_ = total;
        ClassIndex[total] = cls;
        ++total;
    }

    NextSerial = total;

    // Link up children list
    for (i32 i = 0; i < NextSerial; ++i)
    {
        MetaClass* cls = ClassIndex[i];

        if (cls->parent_ == nullptr)
            continue;

        cls->next_child_ = std::exchange(cls->parent_->children_, cls);
    }
}

void MetaClass::DeclareNamedTypedField(const char* name, u32 offset, struct MetaType* type)
{
    export_hook(0x578000);

    MetaField* field = new MetaField {nullptr, name, offset, type};
    *ppField = field;
    ppField = &field->Next;
}

ARTS_NOINLINE void ARTS_FASTCALL MetaClass::DeclareStaticFields(
    const std::initializer_list<const StaticMetaField>& fields)
{
    for (const StaticMetaField& field : fields)
    {
        DeclareNamedTypedField(field.Name, static_cast<u32>(field.Offset), const_cast<MetaType*>(field.Getter()));
    }
}

class MetaClass* MetaClass::FindByName(char* arg1, class MetaClass* arg2)
{
    return stub<cdecl_t<class MetaClass*, char*, class MetaClass*>>(0x577BE0, arg1, arg2);
}

void MetaClass::UndeclareAll()
{
    export_hook(0x577B80);

    for (i32 i = 0; i < NextSerial; ++i)
    {
        MetaClass* cls = ClassIndex[i];

        // All fields/types should be "freed" as part of asSafeHeap restarting
        cls->fields_ = nullptr;
    }
}

void __BadSafeCall(char* arg1, class Base* arg2)
{
    return stub<cdecl_t<void, char*, class Base*>>(0x577C50, arg1, arg2);
}
