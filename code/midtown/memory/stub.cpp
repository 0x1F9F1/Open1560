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

void* operator new(std::size_t size)
{
    export_hook(0x5215A0);

    return CURHEAP->Allocate(size);
}

void* operator new[](std::size_t size)
{
    return CURHEAP->Allocate(size);
}

void operator delete(void* ptr) noexcept
{
    export_hook(0x5215C0);

    CURHEAP->Free(ptr);
}

void operator delete[](void* ptr) noexcept
{
    CURHEAP->Free(ptr);
}

void operator delete(void* ptr, std::size_t sz) noexcept
{
    ArDebugAssert(CURHEAP->SizeOf(ptr) == sz, "Allocation Size Mismatch");

    CURHEAP->Free(ptr);
}

void operator delete[](void* ptr, std::size_t sz) noexcept
{
    ArDebugAssert(CURHEAP->SizeOf(ptr) == sz, "Allocation Size Mismatch");

    CURHEAP->Free(ptr);
}