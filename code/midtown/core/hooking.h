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

#include <mem/cmd_param.h>
#include <mem/macros.h>

template <typename T>
struct type_identity
{
    using type = T;
};

template <typename T>
using type_identity_t = typename type_identity<T>::type;

#define mem_offset_field(OFFSET, TYPE, NAME)                                              \
    MEM_STRONG_INLINE typename std::add_lvalue_reference<TYPE>::type Get##NAME() noexcept \
    {                                                                                     \
        return mem::field<TYPE>(this, OFFSET);                                            \
    }                                                                                     \
    template <typename T>                                                                 \
    MEM_STRONG_INLINE typename std::add_lvalue_reference<TYPE>::type Set##NAME(T&& value) \
    {                                                                                     \
        return Get##NAME() = std::forward<T>(value);                                      \
    }                                                                                     \
    __declspec(property(get = Get##NAME, put = Set##NAME)) TYPE NAME

template <typename T>
struct unconst
{
    typedef T type;
};

template <typename T>
struct unconst<const T>
{
    typedef T type;
};

template <typename T>
struct unconst<T*>
{
    typedef typename unconst<T>::type* type;
};

template <typename T>
struct unconst<T&>
{
    typedef typename unconst<T>::type& type;
};

template <typename T>
struct unconst<T&&>
{
    typedef typename unconst<T>::type&& type;
};

#ifdef ARTS_STANDALONE
#    define check_size(TYPE, SIZE)
#    define define_dummy_symbol mem_define_dummy_symbol
#    define include_dummy_symbol mem_include_dummy_symbol
#    define hook_func(...)
#    define offset_field(OFFSET, TYPE, NAME) TYPE NAME
#    define xconst(VALUE) (VALUE)
#    define aconst const

ARTS_FORCEINLINE const char* operator""_xconst(const char* str, std::size_t)
{
    return str;
}
#else
#    define check_size mem_check_size
#    define define_dummy_symbol mem_define_dummy_symbol
#    define include_dummy_symbol mem_include_dummy_symbol
#    define hook_func mem_func
#    define offset_field mem_offset_field
#    define xconst(VALUE) const_cast<typename unconst<decltype((VALUE))>::type>((VALUE))
#    define aconst

ARTS_FORCEINLINE char* operator""_xconst(const char* str, std::size_t)
{
    return const_cast<char*>(str);
}
#endif

extern mem::static_function* INIT_main;
extern mem::static_function* FRAME_pre_update;
