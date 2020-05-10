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

template <typename T>
struct MetaClassStore
{
    static MetaClass I;
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

template <typename T, bool Abstract = std::is_abstract_v<T> || !std::is_default_constructible_v<T>>
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

#define META_DEFINE_STORE(TYPE, PARENT, ALLOCATOR)                                             \
    class MetaClass* TYPE::GetClass()                                                          \
    {                                                                                          \
        return &MetaClassStore<TYPE>::I;                                                       \
    }                                                                                          \
    template <>                                                                                \
    MetaClass MetaClassStore<TYPE>::I                                                          \
    {                                                                                          \
        (#TYPE), sizeof(TYPE), ALLOCATOR::New, ALLOCATOR::Delete, &TYPE::DeclareFields, PARENT \
    }

#define META_DEFINE(TYPE)                                                    \
    META_DEFINE_STORE(TYPE, &MetaClass::RootMetaClass, MetaAllocator<TYPE>); \
    void TYPE::DeclareFields()

#define META_DEFINE_CHILD(TYPE, PARENT)                                       \
    META_DEFINE_STORE(TYPE, &MetaClassStore<PARENT>::I, MetaAllocator<TYPE>); \
    static_assert(std::is_base_of_v<PARENT, TYPE>, "Invalid Parent");         \
    void TYPE::DeclareFields()
