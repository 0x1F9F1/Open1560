/*
    Copyright 2018 Brick

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software
    and associated documentation files (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge, publish, distribute,
    sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or
    substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
    BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef MEM_MACROS_BRICK_H
#define MEM_MACROS_BRICK_H

#include "mem.h"

#include "static_function.h"

#define mem_decl_extern(TYPE, NAME) typename std::add_lvalue_reference<TYPE>::type NAME
#define mem_defn_extern(ADDRESS, NAME) decltype(NAME) NAME = mem::pointer(ADDRESS).as<decltype(NAME)>()

#ifdef __INTELLISENSE__
#    define mem_extern_var(ADDRESS, TYPE, NAME)               \
        typename std::add_lvalue_reference<TYPE>::type NAME = \
            *static_cast<typename std::add_pointer<TYPE>::type>(nullptr)
#else
#    define mem_extern_var(ADDRESS, TYPE, NAME)               \
        typename std::add_lvalue_reference<TYPE>::type NAME = \
            mem::pointer(ADDRESS).as<typename std::add_lvalue_reference<TYPE>::type>()
#endif

#define mem_check_size(TYPE, SIZE)                                                         \
    static_assert(sizeof(TYPE) >= (SIZE), #TYPE " too small: sizeof(" #TYPE ") < " #SIZE); \
    static_assert(sizeof(TYPE) <= (SIZE), #TYPE " too large: sizeof(" #TYPE ") > " #SIZE)

#define mem_paste_(LHS, RHS) LHS##RHS
#define mem_paste(LHS, RHS) mem_paste_(LHS, RHS)

#define mem_str_(VALUE) #VALUE
#define mem_str(VALUE) mem_str_(VALUE)

#define mem_func static mem::static_function mem_paste(mem_func_, __LINE__)

#define mem_define_dummy_symbol(NAME)     \
    void mem_paste(dummy_symbol_, NAME)() \
    {}

#define mem_include_dummy_symbol(NAME)            \
    extern void mem_paste(dummy_symbol_, NAME)(); \
    auto mem_paste(dummy_include_, NAME) = &mem_paste(dummy_symbol_, NAME)

#endif // MEM_MACROS_BRICK_H
