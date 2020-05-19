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

template <typename T>
inline void* MetaNew([[maybe_unused]] i32 len)
{
    if constexpr (std::is_default_constructible_v<T>)
    {
        if (len)
            return new T[len];
        else
            return new T;
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
inline void MetaDelete(void* ptr, i32 len)
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
inline void MetaDeclareStaticFields()
{
    MetaClass* current = MetaClass::Current;

    // TODO: Avoid having to declare parent fields
    if (MetaClass* parent = current->GetParent())
    {
        MetaClass::Current = parent;
        parent->DeclareFields();
        MetaClass::Current = current;
    }

    MetaClass::DeclareStaticFields(T::MetaData::Fields);
}

#define META_DEFINE_CLASS_STORE(NAME, TYPE, PARENT, ALLOCATOR)                                        \
    struct TYPE::MetaData                                                                             \
    {                                                                                                 \
        using MetaThis = TYPE;                                                                        \
        static MetaClass Class;                                                                       \
        static const std::initializer_list<const StaticMetaField> Fields;                             \
    };                                                                                                \
    MetaClass TYPE::MetaData::Class {                                                                 \
        NAME, sizeof(TYPE), MetaNew<TYPE>, MetaDelete<TYPE>, &MetaDeclareStaticFields<TYPE>, PARENT}; \
    template <>                                                                                       \
    MetaClass* GetMetaClass<TYPE>()                                                                   \
    {                                                                                                 \
        return &TYPE::MetaData::Class;                                                                \
    }                                                                                                 \
    MetaClass* TYPE::GetClass()                                                                       \
    {                                                                                                 \
        return GetMetaClass<TYPE>();                                                                  \
    }

#define META_DEFINE(NAME, TYPE)                                                         \
    META_DEFINE_CLASS_STORE(NAME, TYPE, &MetaClass::RootMetaClass, MetaAllocator<TYPE>) \
    META_DECLARE_FIELDS(TYPE)

#define META_DEFINE_CHILD(NAME, TYPE, PARENT)                                        \
    static_assert(std::is_base_of_v<PARENT, TYPE>, "Invalid Parent");                \
    META_DEFINE_CLASS_STORE(NAME, TYPE, GetMetaClass<PARENT>(), MetaAllocator<TYPE>) \
    META_DECLARE_FIELDS(TYPE)

#define META_DECLARE_FIELDS(TYPE) constexpr std::initializer_list<const StaticMetaField> TYPE::MetaData::Fields

#define META_FIELD(NAME, MEMBER)                                                     \
    StaticMetaField                                                                  \
    {                                                                                \
        NAME, offsetof(MetaThis, MEMBER), CreateMetaType<decltype(MetaThis::MEMBER)> \
    }
