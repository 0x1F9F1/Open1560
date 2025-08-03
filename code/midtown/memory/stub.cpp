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

define_dummy_symbol(memory_stub);

#include "stub.h"

#include "allocator.h"

ARTS_MSVC_DIAGNOSTIC_IGNORED(28251);

ARTS_NOINLINE void* operator new(std::size_t size)
{
    return CURHEAP->Allocate(size, DefaultNewAlignment, ArReturnAddress());
}

ARTS_NOINLINE void* operator new[](std::size_t size)
{
    return CURHEAP->Allocate(size, DefaultNewAlignment, ArReturnAddress());
}

ARTS_NOINLINE void operator delete(void* ptr) noexcept
{
    CURHEAP->Free(ptr);
}

ARTS_NOINLINE void operator delete[](void* ptr) noexcept
{
    CURHEAP->Free(ptr);
}

ARTS_NOINLINE void operator delete(void* ptr, std::size_t sz) noexcept
{
    CURHEAP->Free(ptr, sz);
}

ARTS_NOINLINE void operator delete[](void* ptr, std::size_t sz) noexcept
{
    CURHEAP->Free(ptr, sz);
}

ARTS_NOINLINE void* arts_calloc(std::size_t num, std::size_t size)
{
    std::size_t len = num * size;

    void* ptr = CURHEAP->Allocate(len, DefaultNewAlignment, ArReturnAddress());

    if (ptr)
        std::memset(ptr, 0, len);

    return ptr;
}

ARTS_NOINLINE void arts_free(void* ptr)
{
    CURHEAP->Free(ptr);
}

ARTS_NOINLINE void* arts_malloc(std::size_t size)
{
    return CURHEAP->Allocate(size, DefaultNewAlignment, ArReturnAddress());
}

ARTS_NOINLINE std::size_t arts_msize(void* ptr)
{
    return CURHEAP->SizeOf(ptr);
}

ARTS_NOINLINE void* arts_realloc(void* ptr, std::size_t size)
{
    return CURHEAP->Reallocate(ptr, size, ArReturnAddress());
}

// ?arts_operator_new@@YAPAXI@Z
ARTS_EXPORT ARTS_NOINLINE void* arts_operator_new(std::size_t size)
{
    void* result = CURHEAP->Allocate(size, DefaultNewAlignment, ArReturnAddress());

    // The game expects memory to be zeroed

    if (result)
        std::memset(result, 0x00, size);

    return result;
}

// ?arts_operator_delete@@YAXPAX@Z
ARTS_EXPORT ARTS_NOINLINE void arts_operator_delete(void* ptr)
{
    CURHEAP->Free(ptr);
}

ARTS_NOINLINE void* arts_aligned_alloc(std::size_t size, std::size_t align)
{
    return CURHEAP->Allocate(size, align, ArReturnAddress());
}

ARTS_NOINLINE void arts_aligned_free(void* ptr, [[maybe_unused]] std::size_t align)
{
    CURHEAP->Free(ptr);
}

// FIXME: Not thread-safe
static asMemoryAllocator* SAVEDHEAP = nullptr;

ArWithStaticHeap::ArWithStaticHeap()
{
    ArAssert(SAVEDHEAP == nullptr, "Already allocator statically");
    SAVEDHEAP = std::exchange(CURHEAP, StaticAllocator());
}

ArWithStaticHeap::~ArWithStaticHeap()
{
    ArAssert(SAVEDHEAP != nullptr, "Not allocating statically");
    CURHEAP = std::exchange(SAVEDHEAP, nullptr);
}
