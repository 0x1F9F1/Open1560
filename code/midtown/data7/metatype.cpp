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

struct PtrToType : MetaType
{
    // const PtrToType::`vftable' @ 0x620AB8

    PtrToType(MetaType* target)
        : TargetType(target)
    {}

    MetaType* TargetType {nullptr};

    // 0x57B5E0 | ?Delete@PtrToType@@UAEXPAXH@Z
    void Delete(void* arg1, i32 arg2) override
    {
        return stub<thiscall_t<void, PtrToType*, void*, i32>>(0x57B5E0, this, arg1, arg2);
    }

    // 0x57B5B0 | ?Load@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    void Load(class MiniParser* arg1, void* arg2) override
    {
        return stub<thiscall_t<void, PtrToType*, class MiniParser*, void*>>(0x57B5B0, this, arg1, arg2);
    }

    // 0x57B5D0 | ?New@PtrToType@@UAEPAXH@Z
    void* New(i32 arg1) override
    {
        return stub<thiscall_t<void*, PtrToType*, i32>>(0x57B5D0, this, arg1);
    }

    // 0x57B590 | ?Save@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    void Save(class MiniParser* arg1, void* arg2) override
    {
        return stub<thiscall_t<void, PtrToType*, class MiniParser*, void*>>(0x57B590, this, arg1, arg2);
    }

    // 0x57B5F0 | ?SizeOf@PtrToType@@UAEIXZ
    u32 SizeOf() override
    {
        return stub<thiscall_t<u32, PtrToType*>>(0x57B5F0, this);
    }
};

check_size(PtrToType, 0x8);

struct MetaType* PtrTo(struct MetaType* target)
{
    export_hook(0x524610);

    return new PtrToType {target};
}

/*
void RefToType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, RefToType*, void*, i32>>(0x57B7B0, this, arg1, arg2);
}

i32 RefToType::GetCount(void* arg1)
{
    return stub<thiscall_t<i32, RefToType*, void*>>(0x57B600, this, arg1);
}

void RefToType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, RefToType*, class MiniParser*, void*>>(0x57B6F0, this, arg1, arg2);
}

void* RefToType::New(i32 arg1)
{
    return stub<thiscall_t<void*, RefToType*, i32>>(0x57B7A0, this, arg1);
}

void RefToType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, RefToType*, class MiniParser*, void*>>(0x57B640, this, arg1, arg2);
}

u32 RefToType::SizeOf()
{
    return stub<thiscall_t<u32, RefToType*>>(0x57B7C0, this);
}

void ArrayOfType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, ArrayOfType*, void*, i32>>(0x57B940, this, arg1, arg2);
}

void ArrayOfType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, ArrayOfType*, class MiniParser*, void*>>(0x57B870, this, arg1, arg2);
}

void* ArrayOfType::New(i32 arg1)
{
    return stub<thiscall_t<void*, ArrayOfType*, i32>>(0x57B920, this, arg1);
}

void ArrayOfType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, ArrayOfType*, class MiniParser*, void*>>(0x57B7D0, this, arg1, arg2);
}

u32 ArrayOfType::SizeOf()
{
    return stub<thiscall_t<u32, ArrayOfType*>>(0x57B900, this);
}
*/

struct StructType : MetaType
{
    // const StructType::`vftable' @ 0x61BEE8

    StructType(MetaClass* target)
        : TargetClass(target)
    {}

    MetaClass* TargetClass {nullptr};

    // 0x57B9D0 | ?Delete@StructType@@UAEXPAXH@Z
    void Delete(void* arg1, i32 arg2) override
    {
        return stub<thiscall_t<void, StructType*, void*, i32>>(0x57B9D0, this, arg1, arg2);
    }

    // 0x57B980 | ?Load@StructType@@UAEXPAVMiniParser@@PAX@Z
    void Load(class MiniParser* arg1, void* arg2) override
    {
        return stub<thiscall_t<void, StructType*, class MiniParser*, void*>>(0x57B980, this, arg1, arg2);
    }

    // 0x57B9B0 | ?New@StructType@@UAEPAXH@Z
    void* New(i32 arg1) override
    {
        return stub<thiscall_t<void*, StructType*, i32>>(0x57B9B0, this, arg1);
    }

    // 0x57B960 | ?Save@StructType@@UAEXPAVMiniParser@@PAX@Z
    void Save(class MiniParser* arg1, void* arg2) override
    {
        return stub<thiscall_t<void, StructType*, class MiniParser*, void*>>(0x57B960, this, arg1, arg2);
    }

    // 0x57B9A0 | ?SizeOf@StructType@@UAEIXZ
    u32 SizeOf() override
    {
        return stub<thiscall_t<u32, StructType*>>(0x57B9A0, this);
    }
};

check_size(StructType, 0x8);

struct MetaType* Struct(class MetaClass* target)
{
    export_hook(0x4703A0);

    return new StructType {target};
}

/*
void CharType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, CharType*, void*, i32>>(0x57BA70, this, arg1, arg2);
}

void CharType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, CharType*, class MiniParser*, void*>>(0x57BA10, this, arg1, arg2);
}

void* CharType::New(i32 arg1)
{
    return stub<thiscall_t<void*, CharType*, i32>>(0x57BA40, this, arg1);
}

void CharType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, CharType*, class MiniParser*, void*>>(0x57B9F0, this, arg1, arg2);
}

u32 CharType::SizeOf()
{
    return stub<thiscall_t<u32, CharType*>>(0x57BA30, this);
}

void SignedCharType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, SignedCharType*, void*, i32>>(0x57BB40, this, arg1, arg2);
}

void SignedCharType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedCharType*, class MiniParser*, void*>>(0x57BAE0, this, arg1, arg2);
}

void* SignedCharType::New(i32 arg1)
{
    return stub<thiscall_t<void*, SignedCharType*, i32>>(0x57BB10, this, arg1);
}

void SignedCharType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedCharType*, class MiniParser*, void*>>(0x57BAC0, this, arg1, arg2);
}

u32 SignedCharType::SizeOf()
{
    return stub<thiscall_t<u32, SignedCharType*>>(0x57BB00, this);
}

void UnsignedCharType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, UnsignedCharType*, void*, i32>>(0x57BC10, this, arg1, arg2);
}

void UnsignedCharType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedCharType*, class MiniParser*, void*>>(0x57BBB0, this, arg1, arg2);
}

void* UnsignedCharType::New(i32 arg1)
{
    return stub<thiscall_t<void*, UnsignedCharType*, i32>>(0x57BBE0, this, arg1);
}

void UnsignedCharType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedCharType*, class MiniParser*, void*>>(0x57BB90, this, arg1, arg2);
}

u32 UnsignedCharType::SizeOf()
{
    return stub<thiscall_t<u32, UnsignedCharType*>>(0x57BBD0, this);
}

void SignedShortType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, SignedShortType*, void*, i32>>(0x57BCE0, this, arg1, arg2);
}

void SignedShortType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedShortType*, class MiniParser*, void*>>(0x57BC80, this, arg1, arg2);
}

void* SignedShortType::New(i32 arg1)
{
    return stub<thiscall_t<void*, SignedShortType*, i32>>(0x57BCB0, this, arg1);
}

void SignedShortType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedShortType*, class MiniParser*, void*>>(0x57BC60, this, arg1, arg2);
}

u32 SignedShortType::SizeOf()
{
    return stub<thiscall_t<u32, SignedShortType*>>(0x57BCA0, this);
}

void UnsignedShortType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, UnsignedShortType*, void*, i32>>(0x57BDC0, this, arg1, arg2);
}

void UnsignedShortType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedShortType*, class MiniParser*, void*>>(0x57BD60, this, arg1, arg2);
}

void* UnsignedShortType::New(i32 arg1)
{
    return stub<thiscall_t<void*, UnsignedShortType*, i32>>(0x57BD90, this, arg1);
}

void UnsignedShortType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedShortType*, class MiniParser*, void*>>(0x57BD30, this, arg1, arg2);
}

u32 UnsignedShortType::SizeOf()
{
    return stub<thiscall_t<u32, UnsignedShortType*>>(0x57BD80, this);
}
*/

struct SignedIntType : MetaType
{
    // const SignedIntType::`vftable' @ 0x621E28

public:
    // 0x57BE90 | ?Delete@SignedIntType@@UAEXPAXH@Z
    void Delete(void* arg1, i32 arg2) override
    {
        return stub<thiscall_t<void, SignedIntType*, void*, i32>>(0x57BE90, this, arg1, arg2);
    }

    // 0x57BE30 | ?Load@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    void Load(class MiniParser* arg1, void* arg2) override
    {
        return stub<thiscall_t<void, SignedIntType*, class MiniParser*, void*>>(0x57BE30, this, arg1, arg2);
    }

    // 0x57BE60 | ?New@SignedIntType@@UAEPAXH@Z
    void* New(i32 arg1) override
    {
        return stub<thiscall_t<void*, SignedIntType*, i32>>(0x57BE60, this, arg1);
    }

    // 0x57BE10 | ?Save@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    void Save(class MiniParser* arg1, void* arg2) override
    {
        return stub<thiscall_t<void, SignedIntType*, class MiniParser*, void*>>(0x57BE10, this, arg1, arg2);
    }

    // 0x57BE50 | ?SizeOf@SignedIntType@@UAEIXZ
    u32 SizeOf() override
    {
        return stub<thiscall_t<u32, SignedIntType*>>(0x57BE50, this);
    }
};

check_size(SignedIntType, 0x4);

static const SignedIntType SignedIntInst;

const MetaType* MetaTypeStore_<signed int>::Instance()
{
    return &SignedIntInst;
}

/*
void SignedInt64Type::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, SignedInt64Type*, void*, i32>>(0x57BF70, this, arg1, arg2);
}

void SignedInt64Type::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedInt64Type*, class MiniParser*, void*>>(0x57BF10, this, arg1, arg2);
}

void* SignedInt64Type::New(i32 arg1)
{
    return stub<thiscall_t<void*, SignedInt64Type*, i32>>(0x57BF40, this, arg1);
}

void SignedInt64Type::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedInt64Type*, class MiniParser*, void*>>(0x57BEE0, this, arg1, arg2);
}

u32 SignedInt64Type::SizeOf()
{
    return stub<thiscall_t<u32, SignedInt64Type*>>(0x57BF30, this);
}

void UnsignedIntType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, UnsignedIntType*, void*, i32>>(0x57C040, this, arg1, arg2);
}

void UnsignedIntType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedIntType*, class MiniParser*, void*>>(0x57BFE0, this, arg1, arg2);
}

void* UnsignedIntType::New(i32 arg1)
{
    return stub<thiscall_t<void*, UnsignedIntType*, i32>>(0x57C010, this, arg1);
}

void UnsignedIntType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedIntType*, class MiniParser*, void*>>(0x57BFC0, this, arg1, arg2);
}

u32 UnsignedIntType::SizeOf()
{
    return stub<thiscall_t<u32, UnsignedIntType*>>(0x57C000, this);
}

void FloatType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, FloatType*, void*, i32>>(0x57C120, this, arg1, arg2);
}

void FloatType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, FloatType*, class MiniParser*, void*>>(0x57C0C0, this, arg1, arg2);
}

void* FloatType::New(i32 arg1)
{
    return stub<thiscall_t<void*, FloatType*, i32>>(0x57C0F0, this, arg1);
}

void FloatType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, FloatType*, class MiniParser*, void*>>(0x57C090, this, arg1, arg2);
}

u32 FloatType::SizeOf()
{
    return stub<thiscall_t<u32, FloatType*>>(0x57C0E0, this);
}
*/

struct StringType : MetaType
{
    // const StringType::`vftable' @ 0x621E88

public:
    // 0x57C260 | ?Delete@StringType@@UAEXPAXH@Z
    void Delete(void* arg1, i32 arg2) override
    {
        return stub<thiscall_t<void, StringType*, void*, i32>>(0x57C260, this, arg1, arg2);
    }

    // 0x57C1D0 | ?Load@StringType@@UAEXPAVMiniParser@@PAX@Z
    void Load(class MiniParser* arg1, void* arg2) override
    {
        return stub<thiscall_t<void, StringType*, class MiniParser*, void*>>(0x57C1D0, this, arg1, arg2);
    }

    // 0x57C220 | ?New@StringType@@UAEPAXH@Z
    void* New(i32 arg1) override
    {
        return stub<thiscall_t<void*, StringType*, i32>>(0x57C220, this, arg1);
    }

    // 0x57C190 | ?Save@StringType@@UAEXPAVMiniParser@@PAX@Z
    void Save(class MiniParser* arg1, void* arg2) override
    {
        return stub<thiscall_t<void, StringType*, class MiniParser*, void*>>(0x57C190, this, arg1, arg2);
    }

    // 0x57C270 | ?SizeOf@StringType@@UAEIXZ
    u32 SizeOf() override
    {
        return stub<thiscall_t<u32, StringType*>>(0x57C270, this);
    }
};

check_size(StringType, 0x4);

static const StringType StringInst;

const MetaType* MetaTypeStore_<char*>::Instance()
{
    return &StringInst;
}

const MetaType* MetaTypeStore_<CString>::Instance()
{
    return &StringInst;
}