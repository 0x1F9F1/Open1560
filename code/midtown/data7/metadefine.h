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

#include "metaclass.h"
#include "metatype.h"

ARTS_CLANG_DIAGNOSTIC_IGNORED("-Winvalid-offsetof");

template <typename T>
inline void* MetaNew([[maybe_unused]] isize len)
{
    if constexpr (std::is_default_constructible_v<T>)
    {
        if (len)
            return new T[len] {};
        else
            return new T {};
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
inline void MetaDelete(void* ptr, isize len)
{
    if (ptr)
    {
        if (len)
        {
            if constexpr (std::is_abstract_v<T>)
                ArAssert(false, "Cannot delete array of abstract class");
            else
                delete[] static_cast<T*>(ptr);
        }
        else
        {
            delete static_cast<T*>(ptr);
        }
    }
}

template <typename T>
inline void MetaDeclareFields()
{
    MetaClass* current = MetaClass::Current;

    // TODO: Avoid having to declare parent fields
    if (MetaClass* parent = current->GetParent())
    {
        MetaClass::Current = parent;
        parent->DeclareFields();
        MetaClass::Current = current;
    }

    T::MetaData::DeclareFields();
}

#define META_DEFINE_CLASS_STORE(NAME, TYPE, PARENT)                                             \
    struct TYPE::MetaData                                                                       \
    {                                                                                           \
        using MetaThis = TYPE;                                                                  \
        static MetaClass Class;                                                                 \
        static void DeclareFields();                                                            \
    };                                                                                          \
    MetaClass TYPE::MetaData::Class {                                                           \
        NAME, sizeof(TYPE), MetaNew<TYPE>, MetaDelete<TYPE>, &MetaDeclareFields<TYPE>, PARENT}; \
    template <>                                                                                 \
    MetaClass* GetMetaClass<TYPE>()                                                             \
    {                                                                                           \
        return &TYPE::MetaData::Class;                                                          \
    }                                                                                           \
    MetaClass* TYPE::GetClass()                                                                 \
    {                                                                                           \
        return GetMetaClass<TYPE>();                                                            \
    }

#define META_DEFINE(NAME, TYPE)                                    \
    META_DEFINE_CLASS_STORE(NAME, TYPE, &MetaClass::RootMetaClass) \
    META_DECLARE_FIELDS(TYPE)

#define META_CHECK_IS_INTERCONVIRTIBLE(BASE, DERIVED)                                                       \
    ArCheck((static_cast<DERIVED*>(reinterpret_cast<BASE*>(0x1000)) == reinterpret_cast<DERIVED*>(0x1000)), \
        #DERIVED " is not interconvertible with " #BASE)

#define META_DEFINE_CHILD(NAME, TYPE, PARENT)                                                                   \
    static_assert(std::is_base_of_v<PARENT, TYPE>, "Invalid Parent");                                           \
    META_DEFINE_CLASS_STORE(NAME, TYPE, (META_CHECK_IS_INTERCONVIRTIBLE(PARENT, TYPE), GetMetaClass<PARENT>())) \
    META_DECLARE_FIELDS(TYPE)

#define META_DECLARE_FIELDS(TYPE) void TYPE::MetaData::DeclareFields()

#define META_FIELD(NAME, MEMBER)                                                          \
    MetaClass::DeclareNamedTypedField(NAME, static_cast<u32>(offsetof(MetaThis, MEMBER)), \
        const_cast<MetaType*>(CreateMetaType<decltype(MetaThis::MEMBER)>()));
