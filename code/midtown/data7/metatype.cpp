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
    // const PtrToType::`vftable' @ 0x620AB8

    PtrToType(MetaType* target)
        : TargetType(target)
    {}

    MetaType* TargetType {nullptr};

    // 0x57B5E0 | ?Delete@PtrToType@@UAEXPAXH@Z
    ARTS_EXPORT void Delete(void*, i32) override
    {}

    // 0x57B5B0 | ?Load@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(class MiniParser* parser, void*) override
    {
        parser->Match(MiniParser::LabelRefToken);
    }

    // 0x57B5D0 | ?New@PtrToType@@UAEPAXH@Z
    ARTS_EXPORT void* New(i32) override
    {
        return nullptr;
    }

    // 0x57B590 | ?Save@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(class MiniParser* parser, void* ptr) override
    {
        parser->PlaceLabelRef(*static_cast<void**>(ptr));
    }

    // 0x57B5F0 | ?SizeOf@PtrToType@@UAEIXZ
    ARTS_EXPORT u32 SizeOf() override
    {
        return sizeof(void*);
    }
};

check_size(PtrToType, 0x8);

ARTS_NOINLINE struct MetaType* PtrTo(struct MetaType* target)
{
    return new PtrToType(target);
}

struct StructType final : MetaType
{
    // const StructType::`vftable' @ 0x61BEE8

    StructType(MetaClass* target)
        : TargetClass(target)
    {}

    MetaClass* TargetClass {nullptr};

    // 0x57B9D0 | ?Delete@StructType@@UAEXPAXH@Z
    ARTS_EXPORT void Delete(void* ptr, i32 count) override
    {
        TargetClass->Free(ptr, count);
    }

    // 0x57B980 | ?Load@StructType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(class MiniParser* parser, void* ptr) override
    {
        TargetClass->Load(parser, ptr);
    }

    // 0x57B9B0 | ?New@StructType@@UAEPAXH@Z
    ARTS_EXPORT void* New(i32 count) override
    {
        return TargetClass->Allocate(count);
    }

    // 0x57B960 | ?Save@StructType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(class MiniParser* parser, void* ptr) override
    {
        TargetClass->Save(parser, ptr);
    }

    // 0x57B9A0 | ?SizeOf@StructType@@UAEIXZ
    ARTS_EXPORT u32 SizeOf() override
    {
        return TargetClass->GetSize();
    }
};

check_size(StructType, 0x8);

ARTS_NOINLINE struct MetaType* Struct(class MetaClass* target)
{
    return new StructType(target);
}

struct SignedIntType final : MetaType
{
    // const SignedIntType::`vftable' @ 0x621E28

public:
    // 0x57BE90 | ?Delete@SignedIntType@@UAEXPAXH@Z
    ARTS_EXPORT void Delete(void* ptr, i32 len) override
    {
        MetaDelete<i32>(ptr, len);
    }

    // 0x57BE30 | ?Load@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(class MiniParser* parser, void* ptr) override
    {
        *static_cast<i32*>(ptr) = parser->IntVal();
    }

    // 0x57BE60 | ?New@SignedIntType@@UAEPAXH@Z
    ARTS_EXPORT void* New(i32 count) override
    {
        return MetaNew<i32>(count);
    }

    // 0x57BE10 | ?Save@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(class MiniParser* parser, void* ptr) override
    {
        parser->Printf("%" PRIi32 " ", *static_cast<i32*>(ptr));
    }

    // 0x57BE50 | ?SizeOf@SignedIntType@@UAEIXZ
    ARTS_EXPORT u32 SizeOf() override
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

struct StringType final : MetaType
{
    // const StringType::`vftable' @ 0x621E88

public:
    // 0x57C260 | ?Delete@StringType@@UAEXPAXH@Z
    ARTS_EXPORT void Delete(void*, i32) override
    {
        // TODO: Implement this?
    }

    // 0x57C1D0 | ?Load@StringType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(class MiniParser* parser, void* ptr) override
    {
        char*& str = *static_cast<char**>(ptr);

        if (str)
            arts_free(str);

        if (parser->NextToken() != MiniParser::LabelRefToken) // TODO: Are all other tokens really valid?
            str = arts_strdup(parser->GetBuffer());
        else
            str = nullptr;
    }

    // 0x57C220 | ?New@StringType@@UAEPAXH@Z
    ARTS_EXPORT void* New(i32 count) override
    {
        if (count)
            return new char* [count] {};
        else
            return new char*();
    }

    // 0x57C190 | ?Save@StringType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(class MiniParser* parser, void* ptr) override
    {
        if (char* str = *static_cast<char**>(ptr))
            parser->PrintString(str, 1024);
        else
            parser->Printf("$0");
    }

    // 0x57C270 | ?SizeOf@StringType@@UAEIXZ
    ARTS_EXPORT u32 SizeOf() override
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

template <>
const MetaType* CreateMetaType_<CString>()
{
    return &StringInst;
}
