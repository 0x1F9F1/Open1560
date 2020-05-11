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
struct MetaClassStore
{
    static MetaClass Instance;
};

template <typename T>
struct MetaFieldStore
{
    using MetaThis = T;

    static const std::initializer_list<const StaticMetaField> Fields;
};

template <typename T>
inline void* ptrNew(i32 len)
{
    if (len)
        return new T[len];
    else
        return new T;
}

template <typename T>
inline void ptrDelete(void* ptr, i32 len)
{
    if (len)
        delete[] static_cast<T*>(ptr);
    else
        delete static_cast<T*>(ptr);
}

template <typename T>
inline void MetaDeclareStaticFields()
{
    MetaClass::DeclareStaticFields(MetaFieldStore<T>::Fields);
}

template <typename T, bool Abstract = !std::is_default_constructible_v<T>>
struct MetaAllocator;

template <typename T>
struct MetaAllocator<T, false>
{
    static constexpr auto New {ptrNew<T>};
    static constexpr auto Delete {ptrDelete<T>};
};

template <typename T>
struct MetaAllocator<T, true>
{
    static constexpr auto New {nullptr};
    static constexpr auto Delete {ptrDelete<T>};
};

#define META_DEFINE_CLASS_STORE(NAME, TYPE, PARENT, ALLOCATOR)                                        \
    class MetaClass* TYPE::GetClass()                                                                 \
    {                                                                                                 \
        return &MetaClassStore<TYPE>::Instance;                                                       \
    }                                                                                                 \
    template <>                                                                                       \
    MetaClass MetaClassStore<TYPE>::Instance                                                          \
    {                                                                                                 \
        NAME, sizeof(TYPE), ALLOCATOR::New, ALLOCATOR::Delete, &MetaDeclareStaticFields<TYPE>, PARENT \
    }

#define META_DEFINE(NAME, TYPE)                                                          \
    META_DEFINE_CLASS_STORE(NAME, TYPE, &MetaClass::RootMetaClass, MetaAllocator<TYPE>); \
    META_DECLARE_FIELDS(TYPE)

#define META_DEFINE_CHILD(NAME, TYPE, PARENT)                                                    \
    META_DEFINE_CLASS_STORE(NAME, TYPE, &MetaClassStore<PARENT>::Instance, MetaAllocator<TYPE>); \
    static_assert(std::is_base_of_v<PARENT, TYPE>, "Invalid Parent");                            \
    META_DECLARE_FIELDS(TYPE)

#define META_DECLARE_FIELDS(TYPE) \
    template <>                   \
    constexpr std::initializer_list<const StaticMetaField> MetaFieldStore<TYPE>::Fields

#define META_FIELD(NAME, MEMBER)                                                               \
    StaticMetaField                                                                            \
    {                                                                                          \
        NAME, offsetof(MetaThis, MEMBER), &MetaTypeStore<decltype(MetaThis::MEMBER)>::Instance \
    }
