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

#include "metadeclare.h"

class MiniParser;

struct MetaType
{
    virtual void Save(MiniParser* parser, void* ptr) = 0;
    virtual void Load(MiniParser* parser, void* ptr) = 0;
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

// ?PtrTo@@YAPAUMetaType@@PAU1@@Z
ARTS_EXPORT MetaType* PtrTo(MetaType* target);

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
    public:
    // ?Delete@RefToType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?GetCount@RefToType@@QAEHPAX@Z
    ARTS_IMPORT i32 GetCount(void* arg1);

    // ?Load@RefToType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@RefToType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@RefToType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@RefToType@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(RefToType, 0x0);

struct ArrayOfType final : MetaType
{
    public:
    // ?Delete@ArrayOfType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@ArrayOfType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@ArrayOfType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@ArrayOfType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@ArrayOfType@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(ArrayOfType, 0x0);
#endif

// ?Struct@@YAPAUMetaType@@PAVMetaClass@@@Z
ARTS_EXPORT MetaType* Struct(MetaClass* target);

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
    public:
    // ?Delete@CharType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@CharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@CharType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@CharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@CharType@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(CharType, 0x0);

struct SignedCharType final : MetaType
{
    public:
    // ?Delete@SignedCharType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@SignedCharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@SignedCharType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@SignedCharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@SignedCharType@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(SignedCharType, 0x0);

struct UnsignedCharType final : MetaType
{
    public:
    // ?Delete@UnsignedCharType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@UnsignedCharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@UnsignedCharType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@UnsignedCharType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@UnsignedCharType@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(UnsignedCharType, 0x0);

struct SignedShortType final : MetaType
{
    public:
    // ?Delete@SignedShortType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@SignedShortType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@SignedShortType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@SignedShortType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@SignedShortType@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(SignedShortType, 0x0);

struct UnsignedShortType final : MetaType
{
    public:
    // ?Delete@UnsignedShortType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@UnsignedShortType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@UnsignedShortType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@UnsignedShortType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@UnsignedShortType@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(UnsignedShortType, 0x0);
#endif

template <>
const MetaType* CreateMetaType_<signed int>();

#if 0
struct SignedInt64Type final : MetaType
{
    public:
    // ?Delete@SignedInt64Type@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@SignedInt64Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@SignedInt64Type@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@SignedInt64Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@SignedInt64Type@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(SignedInt64Type, 0x0);

struct UnsignedIntType final : MetaType
{
    public:
    // ?Delete@UnsignedIntType@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@UnsignedIntType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@UnsignedIntType@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@UnsignedIntType@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@UnsignedIntType@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(UnsignedIntType, 0x0);
#endif

template <>
const MetaType* CreateMetaType_<float>();

template <>
const MetaType* CreateMetaType_<char*>();

template <>
const MetaType* CreateMetaType_<ConstString>();

// ?CharInst@@3UCharType@@A
// ARTS_IMPORT extern CharType CharInst;

// ?FloatInst@@3UFloatType@@A
// ARTS_IMPORT extern FloatType FloatInst;

// ?SignedCharInst@@3USignedCharType@@A
// ARTS_IMPORT extern SignedCharType SignedCharInst;

// ?SignedInt64Inst@@3USignedInt64Type@@A
// ARTS_IMPORT extern SignedInt64Type SignedInt64Inst;

// ?SignedIntInst@@3USignedIntType@@A
// ARTS_IMPORT extern SignedIntType SignedIntInst;

// ?SignedShortInst@@3USignedShortType@@A
// ARTS_IMPORT extern SignedShortType SignedShortInst;

// ?StringInst@@3UStringType@@A
// ARTS_IMPORT extern StringType StringInst;

// ?UnsignedCharInst@@3UUnsignedCharType@@A
// ARTS_IMPORT extern UnsignedCharType UnsignedCharInst;

// ?UnsignedIntInst@@3UUnsignedIntType@@A
// ARTS_IMPORT extern UnsignedIntType UnsignedIntInst;

// ?UnsignedShortInst@@3UUnsignedShortType@@A
// ARTS_IMPORT extern UnsignedShortType UnsignedShortInst;
