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
#include <mem/stub.h>

#define Ty(...) __VA_ARGS__

enum class hook_type
{
    jmp,
    call,
    push,
    pointer,

    count
};

enum class jump_type
{
    always,
    never,
};

template <typename T>
struct type_identity
{
    using type = T;
};

template <typename T>
using type_identity_t = typename type_identity<T>::type;

extern std::size_t HookCount;
extern std::size_t PatchCount;

extern bool LogHooks;

void write_protected(mem::pointer dest, mem::pointer src, std::size_t length);

void create_hook(const char* name, const char* description, mem::pointer target, mem::pointer detour,
    hook_type type = hook_type::jmp);
void create_patch(const char* name, const char* description, mem::pointer dest, mem::pointer src, std::size_t size);

void patch_jmp(const char* name, const char* description, mem::pointer target, jump_type mode);

template <typename... Args>
inline void create_packed_patch(
    const char* name, const char* description, mem::pointer dest, type_identity_t<const Args&>... args)
{
    unsigned char buffer[(sizeof(Args) + ...)];
    unsigned char* here = buffer;
    ((std::memcpy(here, &args, sizeof(args)), here += sizeof(args)), ...);
    create_patch(name, description, dest, buffer, sizeof(buffer));
}

#define auto_hook(ADDRESS, FUNC) create_hook(#FUNC, "", ADDRESS, &FUNC)
#define auto_hook_typed(ADDRESS, FUNC, TYPE) create_hook(#FUNC, "", ADDRESS, static_cast<TYPE>(&FUNC))

template <typename Class>
struct class_proxy
{
    template <typename... Args>
    Class* ctor(Args... args)
    {
        return new (this) Class(std::forward<Args>(args)...);
    }

    void dtor()
    {
        reinterpret_cast<Class*>(this)->~Class();
    }

    template <typename... Args, typename F>
    static constexpr auto func(F) -> std::invoke_result_t<F, Args...> (F::*)(Args...)
    {
        return &F::operator();
    }
};

template <typename T>
inline void* alloc_proxy(std::size_t /*size*/)
{
    return operator new(sizeof(T));
}

template <std::size_t N>
inline void* alloc_proxy(std::size_t /*size*/)
{
    return operator new(N);
}

#define auto_hook_ctor(ADDRESS, TYPE, ...) \
    create_hook(#TYPE "::" #TYPE, "", ADDRESS, &class_proxy<TYPE>::ctor<__VA_ARGS__>)

#define auto_hook_dtor(ADDRESS, TYPE) create_hook(#TYPE "::~" #TYPE, "", ADDRESS, &class_proxy<TYPE>::dtor)

#define auto_hook_mfunc(ADDRESS, TYPE, NAME, ...)                                                      \
    create_hook(#TYPE "::" #NAME, "", ADDRESS,                                                         \
        class_proxy<TYPE>::func<__VA_ARGS__>([self = char()](auto... args) mutable -> decltype(auto) { \
            return reinterpret_cast<TYPE*>(&self)->TYPE::NAME(std::forward<decltype(args)>(args)...);  \
        }))

#define patch_static_ctors(...)                                                                \
    run_once(INIT_early, [] {                                                                  \
        for (usize addr : {__VA_ARGS__})                                                       \
            create_patch("Static Constructor", "Disable static constructor", addr, "\xC3", 1); \
    });

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
#    define run_once(...)
#    define offset_field(OFFSET, TYPE, NAME) TYPE NAME
#    define xconst(VALUE) (VALUE)
#    define aconst const
#else
#    define check_size mem_check_size
#    define define_dummy_symbol mem_define_dummy_symbol
#    define include_dummy_symbol mem_include_dummy_symbol
#    define run_once mem_run_once
#    define offset_field mem_offset_field
#    define xconst(VALUE) const_cast<typename unconst<decltype((VALUE))>::type>((VALUE))
#    define aconst
#endif

extern mem::init_function* INIT_early;
