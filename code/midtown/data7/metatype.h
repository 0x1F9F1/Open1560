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

#pragma once

/*
    data7:metatype

    0x57B590 | public: virtual void __thiscall PtrToType::Save(class MiniParser *,void *) | ?Save@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    0x57B5B0 | public: virtual void __thiscall PtrToType::Load(class MiniParser *,void *) | ?Load@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    0x57B5D0 | public: virtual void * __thiscall PtrToType::New(int) | ?New@PtrToType@@UAEPAXH@Z
    0x57B5E0 | public: virtual void __thiscall PtrToType::Delete(void *,int) | ?Delete@PtrToType@@UAEXPAXH@Z
    0x57B5F0 | public: virtual unsigned int __thiscall PtrToType::SizeOf(void) | ?SizeOf@PtrToType@@UAEIXZ
    0x57B600 | public: int __thiscall RefToType::GetCount(void *) | ?GetCount@RefToType@@QAEHPAX@Z
    0x57B640 | public: virtual void __thiscall RefToType::Save(class MiniParser *,void *) | ?Save@RefToType@@UAEXPAVMiniParser@@PAX@Z
    0x57B6F0 | public: virtual void __thiscall RefToType::Load(class MiniParser *,void *) | ?Load@RefToType@@UAEXPAVMiniParser@@PAX@Z
    0x57B7A0 | public: virtual void * __thiscall RefToType::New(int) | ?New@RefToType@@UAEPAXH@Z
    0x57B7B0 | public: virtual void __thiscall RefToType::Delete(void *,int) | ?Delete@RefToType@@UAEXPAXH@Z
    0x57B7C0 | public: virtual unsigned int __thiscall RefToType::SizeOf(void) | ?SizeOf@RefToType@@UAEIXZ
    0x57B7D0 | public: virtual void __thiscall ArrayOfType::Save(class MiniParser *,void *) | ?Save@ArrayOfType@@UAEXPAVMiniParser@@PAX@Z
    0x57B870 | public: virtual void __thiscall ArrayOfType::Load(class MiniParser *,void *) | ?Load@ArrayOfType@@UAEXPAVMiniParser@@PAX@Z
    0x57B900 | public: virtual unsigned int __thiscall ArrayOfType::SizeOf(void) | ?SizeOf@ArrayOfType@@UAEIXZ
    0x57B920 | public: virtual void * __thiscall ArrayOfType::New(int) | ?New@ArrayOfType@@UAEPAXH@Z
    0x57B940 | public: virtual void __thiscall ArrayOfType::Delete(void *,int) | ?Delete@ArrayOfType@@UAEXPAXH@Z
    0x57B960 | public: virtual void __thiscall StructType::Save(class MiniParser *,void *) | ?Save@StructType@@UAEXPAVMiniParser@@PAX@Z
    0x57B980 | public: virtual void __thiscall StructType::Load(class MiniParser *,void *) | ?Load@StructType@@UAEXPAVMiniParser@@PAX@Z
    0x57B9A0 | public: virtual unsigned int __thiscall StructType::SizeOf(void) | ?SizeOf@StructType@@UAEIXZ
    0x57B9B0 | public: virtual void * __thiscall StructType::New(int) | ?New@StructType@@UAEPAXH@Z
    0x57B9D0 | public: virtual void __thiscall StructType::Delete(void *,int) | ?Delete@StructType@@UAEXPAXH@Z
    0x57B9F0 | public: virtual void __thiscall CharType::Save(class MiniParser *,void *) | ?Save@CharType@@UAEXPAVMiniParser@@PAX@Z
    0x57BA10 | public: virtual void __thiscall CharType::Load(class MiniParser *,void *) | ?Load@CharType@@UAEXPAVMiniParser@@PAX@Z
    0x57BA30 | public: virtual unsigned int __thiscall CharType::SizeOf(void) | ?SizeOf@CharType@@UAEIXZ
    0x57BA40 | public: virtual void * __thiscall CharType::New(int) | ?New@CharType@@UAEPAXH@Z
    0x57BA70 | public: virtual void __thiscall CharType::Delete(void *,int) | ?Delete@CharType@@UAEXPAXH@Z
    0x57BAC0 | public: virtual void __thiscall SignedCharType::Save(class MiniParser *,void *) | ?Save@SignedCharType@@UAEXPAVMiniParser@@PAX@Z
    0x57BAE0 | public: virtual void __thiscall SignedCharType::Load(class MiniParser *,void *) | ?Load@SignedCharType@@UAEXPAVMiniParser@@PAX@Z
    0x57BB00 | public: virtual unsigned int __thiscall SignedCharType::SizeOf(void) | ?SizeOf@SignedCharType@@UAEIXZ
    0x57BB10 | public: virtual void * __thiscall SignedCharType::New(int) | ?New@SignedCharType@@UAEPAXH@Z
    0x57BB40 | public: virtual void __thiscall SignedCharType::Delete(void *,int) | ?Delete@SignedCharType@@UAEXPAXH@Z
    0x57BB90 | public: virtual void __thiscall UnsignedCharType::Save(class MiniParser *,void *) | ?Save@UnsignedCharType@@UAEXPAVMiniParser@@PAX@Z
    0x57BBB0 | public: virtual void __thiscall UnsignedCharType::Load(class MiniParser *,void *) | ?Load@UnsignedCharType@@UAEXPAVMiniParser@@PAX@Z
    0x57BBD0 | public: virtual unsigned int __thiscall UnsignedCharType::SizeOf(void) | ?SizeOf@UnsignedCharType@@UAEIXZ
    0x57BBE0 | public: virtual void * __thiscall UnsignedCharType::New(int) | ?New@UnsignedCharType@@UAEPAXH@Z
    0x57BC10 | public: virtual void __thiscall UnsignedCharType::Delete(void *,int) | ?Delete@UnsignedCharType@@UAEXPAXH@Z
    0x57BC60 | public: virtual void __thiscall SignedShortType::Save(class MiniParser *,void *) | ?Save@SignedShortType@@UAEXPAVMiniParser@@PAX@Z
    0x57BC80 | public: virtual void __thiscall SignedShortType::Load(class MiniParser *,void *) | ?Load@SignedShortType@@UAEXPAVMiniParser@@PAX@Z
    0x57BCA0 | public: virtual unsigned int __thiscall SignedShortType::SizeOf(void) | ?SizeOf@SignedShortType@@UAEIXZ
    0x57BCB0 | public: virtual void * __thiscall SignedShortType::New(int) | ?New@SignedShortType@@UAEPAXH@Z
    0x57BCE0 | public: virtual void __thiscall SignedShortType::Delete(void *,int) | ?Delete@SignedShortType@@UAEXPAXH@Z
    0x57BD30 | public: virtual void __thiscall UnsignedShortType::Save(class MiniParser *,void *) | ?Save@UnsignedShortType@@UAEXPAVMiniParser@@PAX@Z
    0x57BD60 | public: virtual void __thiscall UnsignedShortType::Load(class MiniParser *,void *) | ?Load@UnsignedShortType@@UAEXPAVMiniParser@@PAX@Z
    0x57BD80 | public: virtual unsigned int __thiscall UnsignedShortType::SizeOf(void) | ?SizeOf@UnsignedShortType@@UAEIXZ
    0x57BD90 | public: virtual void * __thiscall UnsignedShortType::New(int) | ?New@UnsignedShortType@@UAEPAXH@Z
    0x57BDC0 | public: virtual void __thiscall UnsignedShortType::Delete(void *,int) | ?Delete@UnsignedShortType@@UAEXPAXH@Z
    0x57BE10 | public: virtual void __thiscall SignedIntType::Save(class MiniParser *,void *) | ?Save@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    0x57BE30 | public: virtual void __thiscall SignedIntType::Load(class MiniParser *,void *) | ?Load@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    0x57BE50 | public: virtual unsigned int __thiscall SignedIntType::SizeOf(void) | ?SizeOf@SignedIntType@@UAEIXZ
    0x57BE60 | public: virtual void * __thiscall SignedIntType::New(int) | ?New@SignedIntType@@UAEPAXH@Z
    0x57BE90 | public: virtual void __thiscall SignedIntType::Delete(void *,int) | ?Delete@SignedIntType@@UAEXPAXH@Z
    0x57BEE0 | public: virtual void __thiscall SignedInt64Type::Save(class MiniParser *,void *) | ?Save@SignedInt64Type@@UAEXPAVMiniParser@@PAX@Z
    0x57BF10 | public: virtual void __thiscall SignedInt64Type::Load(class MiniParser *,void *) | ?Load@SignedInt64Type@@UAEXPAVMiniParser@@PAX@Z
    0x57BF30 | public: virtual unsigned int __thiscall SignedInt64Type::SizeOf(void) | ?SizeOf@SignedInt64Type@@UAEIXZ
    0x57BF40 | public: virtual void * __thiscall SignedInt64Type::New(int) | ?New@SignedInt64Type@@UAEPAXH@Z
    0x57BF70 | public: virtual void __thiscall SignedInt64Type::Delete(void *,int) | ?Delete@SignedInt64Type@@UAEXPAXH@Z
    0x57BFC0 | public: virtual void __thiscall UnsignedIntType::Save(class MiniParser *,void *) | ?Save@UnsignedIntType@@UAEXPAVMiniParser@@PAX@Z
    0x57BFE0 | public: virtual void __thiscall UnsignedIntType::Load(class MiniParser *,void *) | ?Load@UnsignedIntType@@UAEXPAVMiniParser@@PAX@Z
    0x57C000 | public: virtual unsigned int __thiscall UnsignedIntType::SizeOf(void) | ?SizeOf@UnsignedIntType@@UAEIXZ
    0x57C010 | public: virtual void * __thiscall UnsignedIntType::New(int) | ?New@UnsignedIntType@@UAEPAXH@Z
    0x57C040 | public: virtual void __thiscall UnsignedIntType::Delete(void *,int) | ?Delete@UnsignedIntType@@UAEXPAXH@Z
    0x57C090 | public: virtual void __thiscall FloatType::Save(class MiniParser *,void *) | ?Save@FloatType@@UAEXPAVMiniParser@@PAX@Z
    0x57C0C0 | public: virtual void __thiscall FloatType::Load(class MiniParser *,void *) | ?Load@FloatType@@UAEXPAVMiniParser@@PAX@Z
    0x57C0E0 | public: virtual unsigned int __thiscall FloatType::SizeOf(void) | ?SizeOf@FloatType@@UAEIXZ
    0x57C0F0 | public: virtual void * __thiscall FloatType::New(int) | ?New@FloatType@@UAEPAXH@Z
    0x57C120 | public: virtual void __thiscall FloatType::Delete(void *,int) | ?Delete@FloatType@@UAEXPAXH@Z
    0x57C190 | public: virtual void __thiscall StringType::Save(class MiniParser *,void *) | ?Save@StringType@@UAEXPAVMiniParser@@PAX@Z
    0x57C1D0 | public: virtual void __thiscall StringType::Load(class MiniParser *,void *) | ?Load@StringType@@UAEXPAVMiniParser@@PAX@Z
    0x57C220 | public: virtual void * __thiscall StringType::New(int) | ?New@StringType@@UAEPAXH@Z
    0x57C260 | public: virtual void __thiscall StringType::Delete(void *,int) | ?Delete@StringType@@UAEXPAXH@Z
    0x57C270 | public: virtual unsigned int __thiscall StringType::SizeOf(void) | ?SizeOf@StringType@@UAEIXZ
    0x621DB0 | const CharType::`vftable' | ??_7CharType@@6B@
    0x621DC8 | const SignedCharType::`vftable' | ??_7SignedCharType@@6B@
    0x621DE0 | const UnsignedCharType::`vftable' | ??_7UnsignedCharType@@6B@
    0x621DF8 | const SignedShortType::`vftable' | ??_7SignedShortType@@6B@
    0x621E10 | const UnsignedShortType::`vftable' | ??_7UnsignedShortType@@6B@
    0x621E28 | const SignedIntType::`vftable' | ??_7SignedIntType@@6B@
    0x621E40 | const SignedInt64Type::`vftable' | ??_7SignedInt64Type@@6B@
    0x621E58 | const UnsignedIntType::`vftable' | ??_7UnsignedIntType@@6B@
    0x621E70 | const FloatType::`vftable' | ??_7FloatType@@6B@
    0x621E88 | const StringType::`vftable' | ??_7StringType@@6B@
    0x90B474 | struct UnsignedCharType UnsignedCharInst | ?UnsignedCharInst@@3UUnsignedCharType@@A
    0x90B478 | struct CharType CharInst | ?CharInst@@3UCharType@@A
    0x90B47C | struct SignedIntType SignedIntInst | ?SignedIntInst@@3USignedIntType@@A
    0x90B480 | struct FloatType FloatInst | ?FloatInst@@3UFloatType@@A
    0x90B484 | struct SignedShortType SignedShortInst | ?SignedShortInst@@3USignedShortType@@A
    0x90B488 | struct StringType StringInst | ?StringInst@@3UStringType@@A
    0x90B48C | struct SignedCharType SignedCharInst | ?SignedCharInst@@3USignedCharType@@A
    0x90B490 | struct UnsignedIntType UnsignedIntInst | ?UnsignedIntInst@@3UUnsignedIntType@@A
    0x90B494 | struct UnsignedShortType UnsignedShortInst | ?UnsignedShortInst@@3UUnsignedShortType@@A
    0x90B498 | struct SignedInt64Type SignedInt64Inst | ?SignedInt64Inst@@3USignedInt64Type@@A
*/

struct MetaType
{
    virtual void Save(class MiniParser* parser, void* ptr) = 0;
    virtual void Load(class MiniParser* parser, void* ptr) = 0;
    virtual usize SizeOf() = 0;
    virtual void* New(isize count) = 0;
    virtual void Delete(void* ptr, isize count) = 0;
};

check_size(MetaType, 0x4);

template <typename T, typename = void>
struct MetaTypeFactory;

template <typename T>
const MetaType* CreateMetaType_()
{
    return MetaTypeFactory<T>::Create();
}

template <typename T>
inline const MetaType* CreateMetaType()
{
    return CreateMetaType_<typename std::remove_cv<T>::type>();
}

template <>
const MetaType* CreateMetaType<void>() = delete;

// 0x524610 | ?PtrTo@@YAPAUMetaType@@PAU1@@Z
ARTS_EXPORT struct MetaType* PtrTo(struct MetaType* target);

template <typename T>
struct MetaTypeFactory<T*>
{
    static inline MetaType* Create()
    {
        return PtrTo(const_cast<MetaType*>(CreateMetaType<T>()));
    }
};

#if 0
struct RefToType final : MetaType
{
    // const RefToType::`vftable' @ 0x61F720

public:
    // 0x57B7B0 | ?Delete@RefToType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57B600 | ?GetCount@RefToType@@QAEHPAX@Z
    ARTS_IMPORT i32 GetCount(void* arg1);

    // 0x57B6F0 | ?Load@RefToType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57B7A0 | ?New@RefToType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57B640 | ?Save@RefToType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57B7C0 | ?SizeOf@RefToType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(RefToType, 0x0);

struct ArrayOfType final : MetaType
{
    // const ArrayOfType::`vftable' @ 0x61BF58

public:
    // 0x57B940 | ?Delete@ArrayOfType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57B870 | ?Load@ArrayOfType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57B920 | ?New@ArrayOfType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57B7D0 | ?Save@ArrayOfType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57B900 | ?SizeOf@ArrayOfType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(ArrayOfType, 0x0);
#endif

// 0x4703A0 | ?Struct@@YAPAUMetaType@@PAVMetaClass@@@Z
ARTS_EXPORT struct MetaType* Struct(class MetaClass* target);

template <typename T>
struct MetaTypeFactory<T, std::enable_if_t<std::is_class_v<T>>>
{
    static inline MetaType* Create()
    {
        return Struct(GetMetaClass<T>());
    }
};

#if 0
struct CharType final : MetaType
{
    // const CharType::`vftable' @ 0x621DB0

public:
    // 0x57BA70 | ?Delete@CharType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57BA10 | ?Load@CharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57BA40 | ?New@CharType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57B9F0 | ?Save@CharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57BA30 | ?SizeOf@CharType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(CharType, 0x0);

struct SignedCharType final : MetaType
{
    // const SignedCharType::`vftable' @ 0x621DC8

public:
    // 0x57BB40 | ?Delete@SignedCharType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57BAE0 | ?Load@SignedCharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57BB10 | ?New@SignedCharType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57BAC0 | ?Save@SignedCharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57BB00 | ?SizeOf@SignedCharType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(SignedCharType, 0x0);

struct UnsignedCharType final : MetaType
{
    // const UnsignedCharType::`vftable' @ 0x621DE0

public:
    // 0x57BC10 | ?Delete@UnsignedCharType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57BBB0 | ?Load@UnsignedCharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57BBE0 | ?New@UnsignedCharType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57BB90 | ?Save@UnsignedCharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57BBD0 | ?SizeOf@UnsignedCharType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(UnsignedCharType, 0x0);

struct SignedShortType final : MetaType
{
    // const SignedShortType::`vftable' @ 0x621DF8

public:
    // 0x57BCE0 | ?Delete@SignedShortType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57BC80 | ?Load@SignedShortType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57BCB0 | ?New@SignedShortType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57BC60 | ?Save@SignedShortType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57BCA0 | ?SizeOf@SignedShortType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(SignedShortType, 0x0);

struct UnsignedShortType final : MetaType
{
    // const UnsignedShortType::`vftable' @ 0x621E10

public:
    // 0x57BDC0 | ?Delete@UnsignedShortType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57BD60 | ?Load@UnsignedShortType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57BD90 | ?New@UnsignedShortType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57BD30 | ?Save@UnsignedShortType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57BD80 | ?SizeOf@UnsignedShortType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(UnsignedShortType, 0x0);
#endif

template <>
const MetaType* CreateMetaType_<signed int>();

#if 0
struct SignedInt64Type final : MetaType
{
    // const SignedInt64Type::`vftable' @ 0x621E40

public:
    // 0x57BF70 | ?Delete@SignedInt64Type@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57BF10 | ?Load@SignedInt64Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57BF40 | ?New@SignedInt64Type@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57BEE0 | ?Save@SignedInt64Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57BF30 | ?SizeOf@SignedInt64Type@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(SignedInt64Type, 0x0);

struct UnsignedIntType final : MetaType
{
    // const UnsignedIntType::`vftable' @ 0x621E58

public:
    // 0x57C040 | ?Delete@UnsignedIntType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57BFE0 | ?Load@UnsignedIntType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57C010 | ?New@UnsignedIntType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57BFC0 | ?Save@UnsignedIntType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57C000 | ?SizeOf@UnsignedIntType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(UnsignedIntType, 0x0);

struct FloatType final : MetaType
{
    // const FloatType::`vftable' @ 0x621E70

public:
    // 0x57C120 | ?Delete@FloatType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // 0x57C0C0 | ?Load@FloatType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // 0x57C0F0 | ?New@FloatType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // 0x57C090 | ?Save@FloatType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // 0x57C0E0 | ?SizeOf@FloatType@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(FloatType, 0x0);
#endif

template <>
const MetaType* CreateMetaType_<char*>();

template <>
const MetaType* CreateMetaType_<ConstString>();

// 0x90B478 | ?CharInst@@3UCharType@@A
// ARTS_IMPORT extern struct CharType CharInst;

// 0x90B480 | ?FloatInst@@3UFloatType@@A
// ARTS_IMPORT extern struct FloatType FloatInst;

// 0x90B48C | ?SignedCharInst@@3USignedCharType@@A
// ARTS_IMPORT extern struct SignedCharType SignedCharInst;

// 0x90B498 | ?SignedInt64Inst@@3USignedInt64Type@@A
// ARTS_IMPORT extern struct SignedInt64Type SignedInt64Inst;

// 0x90B47C | ?SignedIntInst@@3USignedIntType@@A
// ARTS_IMPORT extern struct SignedIntType SignedIntInst;

// 0x90B484 | ?SignedShortInst@@3USignedShortType@@A
// ARTS_IMPORT extern struct SignedShortType SignedShortInst;

// 0x90B488 | ?StringInst@@3UStringType@@A
// ARTS_IMPORT extern struct StringType StringInst;

// 0x90B474 | ?UnsignedCharInst@@3UUnsignedCharType@@A
// ARTS_IMPORT extern struct UnsignedCharType UnsignedCharInst;

// 0x90B490 | ?UnsignedIntInst@@3UUnsignedIntType@@A
// ARTS_IMPORT extern struct UnsignedIntType UnsignedIntInst;

// 0x90B494 | ?UnsignedShortInst@@3UUnsignedShortType@@A
// ARTS_IMPORT extern struct UnsignedShortType UnsignedShortInst;
