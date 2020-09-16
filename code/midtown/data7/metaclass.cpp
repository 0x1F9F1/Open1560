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
#include "miniparser.h"

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
    Register();
}

MetaClass::~MetaClass()
{
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
    ArAssert(Current == nullptr, "Cannot declare nested fields");

    Current = this;
    ppField = &fields_;

    declare_();

    ppField = nullptr;
    Current = nullptr;
}

b32 MetaClass::IsSubclassOf(class MetaClass* parent)
{
    for (MetaClass* cls = this; cls; cls = cls->parent_)
    {
        if (cls == parent)
            return true;
    }

    return false;
}

void MetaClass::Load(class MiniParser* parser, void* ptr)
{
    if (fields_ == nullptr)
        InitFields();

    parser->Match(MiniParser::IdentToken);

    MetaClass* cls = FindByName(parser->GetBuffer(), &RootMetaClass);

    if (cls == nullptr)
    {
        parser->Errorf("Unknown metaclass name '%s', skipping block", parser->GetBuffer());
        SkipBlock(parser);
        return;
    }

    if (!cls->IsSubclassOf(this))
    {
        parser->Errorf("Expected subclass of '%s', got '%s' instead, skipping block", GetName(), parser->GetBuffer());
        SkipBlock(parser);
        return;
    }

    parser->Match(MiniParser::LabelToken);
    parser->Match('{');

    while (true)
    {
        i32 token = parser->NextToken();

        if (token == '\0')
            break; // TODO: Handle unexpected EOF

        if (token == '}')
            break;

        if (token != MiniParser::IdentToken)
        {
            parser->Errorf("Expected field name here.");
            continue;
        }

        MetaField* field = fields_;

        for (; field; field = field->Next)
        {
            if (!std::strcmp(field->Name, parser->GetBuffer()))
                break;
        }

        if (field != nullptr)
            field->Type->Load(parser, static_cast<u8*>(ptr) + field->Offset);
        else
            SkipBlock(parser);
    }

    if (IsSubclassOf(GetMetaClass<Base>()))
        static_cast<Base*>(ptr)->AfterLoad();
}

void MetaClass::Save(class MiniParser* parser, void* ptr)
{
    if (fields_ == nullptr)
        InitFields();

    if (IsSubclassOf(GetMetaClass<Base>()))
        static_cast<Base*>(ptr)->BeforeSave();

    void* default_ptr = nullptr;

    if (!NoDefault)
        default_ptr = Allocate(0);

    parser->Printf("%s ", GetName());
    parser->PlaceLabel(ptr);
    parser->Printf(" {\n");
    parser->Indent(4);

    for (MetaField* field = fields_; field; field = field->Next)
    {
        void* member = static_cast<u8*>(ptr) + field->Offset;

        if (NoDefault || std::memcmp(member, static_cast<u8*>(default_ptr) + field->Offset, field->Type->SizeOf()))
        {
            parser->Printf("%s ", field->Name);
            parser->Indent(4);
            field->Type->Save(parser, member);
            parser->Indent(-4);
            parser->Printf("\n");
        }
    }

    parser->Indent(-4);
    parser->Printf("}");

    if (!NoDefault)
        Free(default_ptr, 0);
}

void MetaClass::SkipBlock(class MiniParser* parser)
{
    parser->Errorf("'%s' is not a valid field name in %s.", parser->GetBuffer(), GetName());

    bool has_values = false;
    i32 depth = 0;

    i32 token = 0;

    while ((token = parser->NextToken()) != '\0')
    {
        if (token == '{' || token == '[')
        {
            ++depth;
        }
        else if (token == '}' || token == ']')
        {
            if (depth == 0)
                break;

            --depth;
        }
        else if (token == MiniParser::IdentToken && has_values && depth == 0)
        {
            break;
        }
        else if (token == MiniParser::IntegerToken || token == MiniParser::StringToken ||
            token == MiniParser::FloatToken)
        {
            has_values = true;
        }
    }

    if (token)
        parser->PutBack(token);

    parser->Errorf("Resuming parsing here.");
}

void MetaClass::FixupClasses()
{
    mem::module main_module = mem::module::main();

    std::unordered_map<std::string_view, MetaClass*> fixups;

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

class MetaClass* MetaClass::FindByName(const char* name, class MetaClass* root)
{
    for (MetaClass* cls = root; cls; cls = cls->next_child_)
    {
        // NOTE: Original implementation also checks `cls->GetName() != nullptr`, but that seems unncessary.
        if (!std::strcmp(cls->GetName(), name))
            return cls;

        if (MetaClass* result = FindByName(name, cls->children_))
            return result;
    }

    return nullptr;
}

void MetaClass::UndeclareAll()
{
    for (i32 i = 0; i < NextSerial; ++i)
    {
        MetaClass* cls = ClassIndex[i];

        // FIXME: Need to free dynamically allocated types
        for (MetaField *j = cls->fields_, *next = nullptr; j; j = next)
        {
            next = j->Next;
            delete j;
        }

        cls->fields_ = nullptr;
    }
}

void __BadSafeCall(const char* name, class Base* ptr)
{
    Quitf("SafeCall failed: '%s' is not a '%s'.", ptr->GetTypeName(), name);
}
