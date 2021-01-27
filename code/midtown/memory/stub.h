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

/*
    memory:stub

    0x5214F0 | _malloc
    0x521510 | _realloc
    0x521530 | _calloc
    0x521570 | _free
    0x521590 | __msize
    0x5215A0 | void * __cdecl operator new(unsigned int) | ??2@YAPAXI@Z
    0x5215C0 | void __cdecl operator delete(void *) | ??3@YAXPAX@Z
    0x5215E0 | __realloc_dbg
    0x521630 | __malloc_dbg
    0x521670 | __free_dbg
    0x5216B0 | __calloc_dbg
    0x521710 | __msize_dbg
    0x521730 | __CrtCheckMemory
    0x521740 | __CrtSetDbgFlag
    0x521750 | __CrtIsValidPointer
    0x521790 | __CrtMemCheckpoint
    0x5217D0 | __CrtDumpMemoryLeaks
*/

#include <intrin.h>

#ifdef _MSC_VER
#    define ArReturnAddress() _ReturnAddress()
#else
#    define ArReturnAddress() __builtin_return_address()
#endif

// 0x5215C0 | ??3@YAXPAX@Z

// 0x5215A0 | ??2@YAPAXI@Z

// 0x521730 | __CrtCheckMemory | void

// 0x5217D0 | __CrtDumpMemoryLeaks | void

// 0x521750 | __CrtIsValidPointer | void

// 0x521790 | __CrtMemCheckpoint | void

// 0x521740 | __CrtSetDbgFlag | void

// 0x5216B0 | __calloc_dbg | void

// 0x521670 | __free_dbg | void

// 0x521630 | __malloc_dbg | void

// 0x521710 | __msize_dbg | void

// 0x5215E0 | __realloc_dbg | void

// 0x521530 | _calloc
ARTS_EXPORT void* arts_calloc(std::size_t num, std::size_t size);

// 0x521570 | _free
ARTS_EXPORT void arts_free(void* ptr);

// 0x5214F0 | _malloc
ARTS_EXPORT void* arts_malloc(std::size_t size);

// 0x521590 | __msize | void
ARTS_EXPORT std::size_t arts_msize(void* ptr);

// 0x521510 | _realloc
ARTS_EXPORT void* arts_realloc(void* ptr, std::size_t size);

void* arts_aligned_alloc(std::size_t size, std::size_t align);

void arts_aligned_free(void* ptr, std::size_t align);
