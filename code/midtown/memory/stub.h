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

#include <intrin.h>

#ifdef _MSC_VER
#    define ArReturnAddress() _ReturnAddress()
#else
#    define ArReturnAddress() __builtin_return_address()
#endif

// ??3@YAXPAX@Z

// ??2@YAPAXI@Z

// __CrtCheckMemory | void

// __CrtDumpMemoryLeaks | void

// __CrtIsValidPointer | void

// __CrtMemCheckpoint | void

// __CrtSetDbgFlag | void

// __calloc_dbg | void

// __free_dbg | void

// __malloc_dbg | void

// __msize_dbg | void

// __realloc_dbg | void

// _calloc
ARTS_EXPORT void* arts_calloc(std::size_t num, std::size_t size);

// _free
ARTS_EXPORT void arts_free(void* ptr);

// _malloc
ARTS_EXPORT void* arts_malloc(std::size_t size);

// __msize | void
ARTS_EXPORT std::size_t arts_msize(void* ptr);

// _realloc
ARTS_EXPORT void* arts_realloc(void* ptr, std::size_t size);

void* arts_aligned_alloc(std::size_t size, std::size_t align);

void arts_aligned_free(void* ptr, std::size_t align);

struct ArWithStaticHeap
{
    ArWithStaticHeap();

    ~ArWithStaticHeap();
};

#define ARTS_ZEROED                               \
    static void* operator new(std::size_t size)   \
    {                                             \
        return arts_calloc(1, size);              \
    }                                             \
    static void* operator new[](std::size_t size) \
    {                                             \
        return arts_calloc(1, size);              \
    }