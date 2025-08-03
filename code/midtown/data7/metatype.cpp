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

define_dummy_symbol(data7_metatype);

#include "metatype.h"

#include <cinttypes>

#include "metaclass.h"
#include "metadefine.h"
#include "miniparser.h"

struct PtrToType final : MetaType
{
    PtrToType(MetaType* target)
        : TargetType(target)
    {}

    MetaType* TargetType {};

    // ?Delete@PtrToType@@UAEXPAXH@Z
    void Delete(void*, isize) override
    {}

    // ?Load@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    void Load(MiniParser* parser, void*) override
    {
        parser->Match(MiniParser::LabelRefToken);
    }

    // ?New@PtrToType@@UAEPAXH@Z
    void* New(isize) override
    {
        return nullptr;
    }

    // ?Save@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    void Save(MiniParser* parser, void* ptr) override
    {
        parser->PlaceLabelRef(*static_cast<void**>(ptr));
    }

    // ?SizeOf@PtrToType@@UAEIXZ
    usize SizeOf() override
    {
        return sizeof(void*);
    }
};

check_size(PtrToType, 0x8);

ARTS_NOINLINE MetaType* PtrTo(MetaType* target)
{
    return new PtrToType(target);
}

struct StructType final : MetaType
{
    StructType(MetaClass* target)
        : TargetClass(target)
    {}

    MetaClass* TargetClass {};

    // ?Delete@StructType@@UAEXPAXH@Z
    void Delete(void* ptr, isize count) override
    {
        TargetClass->Free(ptr, count);
    }

    // ?Load@StructType@@UAEXPAVMiniParser@@PAX@Z
    void Load(MiniParser* parser, void* ptr) override
    {
        TargetClass->Load(parser, ptr);
    }

    // ?New@StructType@@UAEPAXH@Z
    void* New(isize count) override
    {
        return TargetClass->Allocate(count);
    }

    // ?Save@StructType@@UAEXPAVMiniParser@@PAX@Z
    void Save(MiniParser* parser, void* ptr) override
    {
        TargetClass->Save(parser, ptr);
    }

    // ?SizeOf@StructType@@UAEIXZ
    usize SizeOf() override
    {
        return TargetClass->GetSize();
    }
};

check_size(StructType, 0x8);

ARTS_NOINLINE MetaType* Struct(MetaClass* target)
{
    return new StructType(target);
}

struct SignedIntType final : MetaType
{
public:
    // ?Delete@SignedIntType@@UAEXPAXH@Z
    ARTS_EXPORT void Delete(void* ptr, isize len) override
    {
        MetaDelete<i32>(ptr, len);
    }

    // ?Load@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(MiniParser* parser, void* ptr) override
    {
        *static_cast<i32*>(ptr) = parser->IntVal();
    }

    // ?New@SignedIntType@@UAEPAXH@Z
    ARTS_EXPORT void* New(isize count) override
    {
        return MetaNew<i32>(count);
    }

    // ?Save@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(MiniParser* parser, void* ptr) override
    {
        parser->Printf("%" PRIi32 " ", *static_cast<i32*>(ptr));
    }

    // ?SizeOf@SignedIntType@@UAEIXZ
    ARTS_EXPORT usize SizeOf() override
    {
        return sizeof(i32);
    }
};

check_size(SignedIntType, 0x4);

static const SignedIntType SignedIntInst;

template <>
const MetaType* CreateMetaType_<signed int>()
{
    return &SignedIntInst;
}

struct FloatType final : MetaType
{
public:
    // ?Delete@FloatType@@UAEXPAXH@Z
    ARTS_EXPORT void Delete(void* ptr, i32 len) override
    {
        MetaDelete<f32>(ptr, len);
    }

    // ?Load@FloatType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(MiniParser* parser, void* ptr) override
    {
        *static_cast<f32*>(ptr) = parser->FloatVal();
    }

    // ?New@FloatType@@UAEPAXH@Z
    ARTS_EXPORT void* New(i32 count) override
    {
        return MetaNew<f32>(count);
    }

    // ?Save@FloatType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(MiniParser* parser, void* ptr) override
    {
        parser->Printf("%g ", *static_cast<f32*>(ptr));
    }

    // ?SizeOf@FloatType@@UAEIXZ
    ARTS_EXPORT usize SizeOf() override
    {
        return sizeof(f32);
    }
};

check_size(FloatType, 0x4);

static const FloatType FloatInst;

template <>
const MetaType* CreateMetaType_<float>()
{
    return &FloatInst;
}

struct StringType final : MetaType
{
public:
    // ?Delete@StringType@@UAEXPAXH@Z
    ARTS_EXPORT void Delete(void*, isize) override
    {
        // TODO: Implement this?
    }

    // ?Load@StringType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(MiniParser* parser, void* ptr) override
    {
        char*& str = *static_cast<char**>(ptr);

        if (str)
            arts_free(str);

        if (parser->NextToken() != MiniParser::LabelRefToken) // TODO: Are all other tokens really valid?
            str = arts_strdup(parser->GetBuffer());
        else
            str = nullptr;
    }

    // ?New@StringType@@UAEPAXH@Z
    ARTS_EXPORT void* New(isize count) override
    {
        if (count)
            return new char* [count] {};
        else
            return new char*();
    }

    // ?Save@StringType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(MiniParser* parser, void* ptr) override
    {
        if (char* str = *static_cast<char**>(ptr))
            parser->PrintString(str, 1024);
        else
            parser->Printf("$0");
    }

    // ?SizeOf@StringType@@UAEIXZ
    ARTS_EXPORT usize SizeOf() override
    {
        return sizeof(char*);
    }
};

check_size(StringType, 0x4);

static const StringType StringInst;

template <>
const MetaType* CreateMetaType_<char*>()
{
    return &StringInst;
}

struct ConstStringType final : MetaType
{
public:
    void Delete(void*, isize) override
    {
        // TODO: Implement this?
    }

    void Load(MiniParser* parser, void* ptr) override
    {
        ConstString& str = *static_cast<ConstString*>(ptr);

        if (parser->NextToken() != MiniParser::LabelRefToken) // TODO: Are all other tokens really valid?
            str = parser->GetBuffer();
        else
            str = nullptr;
    }

    void* New(isize count) override
    {
        if (count)
            return new ConstString[count] {};
        else
            return new ConstString();
    }

    void Save(MiniParser* parser, void* ptr) override
    {
        if (ConstString& str = *static_cast<ConstString*>(ptr))
            parser->PrintString(str.get(), 1024);
        else
            parser->Printf("$0");
    }

    usize SizeOf() override
    {
        return sizeof(ConstString);
    }
};

static const ConstStringType ConstStringInst;

template <>
const MetaType* CreateMetaType_<ConstString>()
{
    return &ConstStringInst;
}
