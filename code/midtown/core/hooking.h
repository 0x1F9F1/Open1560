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

using namespace mem::conventions;
using mem::stub;

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

extern size_t HookCount;
extern size_t PatchCount;

void write_protected(mem::pointer dest, mem::pointer src, size_t length);

void create_hook(const char* name, const char* description, mem::pointer target, mem::pointer detour,
    hook_type type = hook_type::jmp);
void create_patch(const char* name, const char* description, mem::pointer dest, mem::pointer src, size_t size);

void patch_jmp(const char* name, const char* description, mem::pointer target, jump_type mode);

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

    template <typename F, typename... Args>
    struct function_proxy : F
    {
        inline decltype(auto) invoke(Args... args)
        {
            return F::operator()(reinterpret_cast<Class*>(this), std::forward<Args>(args)...);
        }
    };

    template <typename... Args, typename F>
    static constexpr auto func(F) -> decltype(&function_proxy<F, Args...>::invoke)
    {
        return &function_proxy<F, Args...>::invoke;
    }
};

#define auto_hook_ctor(ADDRESS, TYPE, ...) \
    create_hook(#TYPE "::" #TYPE, "", ADDRESS, &class_proxy<TYPE>::ctor<__VA_ARGS__>)

#define auto_hook_dtor(ADDRESS, TYPE) create_hook(#TYPE "::~" #TYPE, "", ADDRESS, &class_proxy<TYPE>::dtor)

#define auto_hook_mfunc(ADDRESS, TYPE, NAME, ...)                                            \
    create_hook(#TYPE "::" #NAME, "", ADDRESS,                                               \
        class_proxy<TYPE>::func<__VA_ARGS__>([](auto* ptr, auto... args) -> decltype(auto) { \
            return ptr->TYPE::NAME(std::forward<decltype(args)>(args)...);                   \
        }))

#define check_size mem_check_size
#define define_dummy_symbol mem_define_dummy_symbol
#define include_dummy_symbol mem_include_dummy_symbol
#define run_once mem_run_once

// Custom extern_var to force MSVC to mark the references as constant
#if defined(_MSC_VER) && !defined(__INTELLISENSE__) && !defined(__clang__)
#    pragma const_seg(".rdata")
#    undef extern_var
#    define extern_var(ADDRESS, TYPE, NAME)                                                  \
        __declspec(allocate(".rdata")) typename std::add_lvalue_reference<TYPE>::type NAME = \
            *reinterpret_cast<typename std::add_pointer<TYPE>::type>(usize(ADDRESS));
#    define export_hook(ADDRESS) __pragma(comment(linker, "/EXPORT:" __FUNCDNAME__ ":Hook_" #    ADDRESS "=" __FUNCDNAME__))
#else
#    define export_hook(ADDRESS)
#    define extern_var mem_extern_var
#endif

#pragma warning(disable : 4505) // unreferenced local function has been removed
#pragma warning(disable : 4722) // destructor never returns, potential memory leak
#pragma warning(disable : 4702) // unreachable code
