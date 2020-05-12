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

extern size_t HookCount;
extern size_t PatchCount;

void write_protected(mem::pointer dest, mem::pointer src, size_t length);

void create_hook(const char* name, const char* description, mem::pointer target, mem::pointer detour,
    hook_type type = hook_type::jmp);
void create_patch(const char* name, const char* description, mem::pointer dest, mem::pointer src, size_t size);

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
};

#define auto_hook_ctor(ADDRESS, TYPE, ...) \
    create_hook(#TYPE "::" #TYPE, "", ADDRESS, &class_proxy<TYPE>::ctor<__VA_ARGS__>)

#define auto_hook_dtor(ADDRESS, TYPE) create_hook(#TYPE "::~" #TYPE, "", ADDRESS, &class_proxy<TYPE>::dtor)

#ifndef __FUNCDNAME__ // Just to shut up IntelliSense
#    define __FUNCDNAME__ "INVALID_FUNCTION"
#endif

#define export_hook(ADDRESS) __pragma(comment(linker, "/EXPORT:" __FUNCDNAME__ ":Hook_" #ADDRESS "=" __FUNCDNAME__))

#pragma const_seg(".rdata")

// Custom extern_var to force MSVC to mark the references as constant
#undef extern_var
#define extern_var(ADDRESS, TYPE, NAME)                                                  \
    __declspec(allocate(".rdata")) typename std::add_lvalue_reference<TYPE>::type NAME = \
        *reinterpret_cast<typename std::add_pointer<TYPE>::type>(usize(ADDRESS));

#pragma warning(disable: 4505) // unreferenced local function has been removed
