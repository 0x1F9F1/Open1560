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

define_dummy_symbol(memory_allocator);

#include "allocator.h"

struct asMemoryAllocator::node
{
    u32 Status;
    u32 Size;

    static node* from(void* ptr, b32 debug) noexcept
    {
        return reinterpret_cast<node*>(static_cast<u8*>(ptr) - (sizeof(node) + (debug ? 8 : 0)));
    }
};

asMemoryAllocator::asMemoryAllocator()
{}

asMemoryAllocator::~asMemoryAllocator()
{}

void* asMemoryAllocator::Allocate(u32 arg1)
{
    return stub<thiscall_t<void*, asMemoryAllocator*, u32>>(0x520A20, this, arg1);
}

void asMemoryAllocator::CheckPointer(void* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*>>(0x520C40, this, arg1);
}

void asMemoryAllocator::Free(void* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*>>(0x520C90, this, arg1);
}

void asMemoryAllocator::GetStats(struct asMemStats* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, struct asMemStats*>>(0x520FC0, this, arg1);
}

void asMemoryAllocator::Init(void* arg1, u32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*, u32, i32>>(0x5209D0, this, arg1, arg2, arg3);
}

void asMemoryAllocator::Kill()
{
    return stub<thiscall_t<void, asMemoryAllocator*>>(0x520A10, this);
}

void* asMemoryAllocator::Reallocate(void* arg1, u32 arg2)
{
    return stub<thiscall_t<void*, asMemoryAllocator*, void*, u32>>(0x520EA0, this, arg1, arg2);
}

void asMemoryAllocator::SanityCheck()
{
    return stub<thiscall_t<void, asMemoryAllocator*>>(0x521090, this);
}

usize asMemoryAllocator::SizeOf(void* ptr)
{
    return asMemoryAllocator::node::from(ptr, debug_)->Size - (debug_ ? 12 : 0);
}

void asMemoryAllocator::Link(struct asMemoryAllocator::node* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, struct asMemoryAllocator::node*>>(0x520E50, this, arg1);
}

void asMemoryAllocator::Unlink(struct asMemoryAllocator::node* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, struct asMemoryAllocator::node*>>(0x520DF0, this, arg1);
}

void asMemoryAllocator::Verify(void* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*>>(0x520F00, this, arg1);
}

static i32 HeapAssert(void* arg1, i32 arg2, char* arg3, i32 arg4)
{
    return stub<cdecl_t<i32, void*, i32, char*, i32>>(0x521250, arg1, arg2, arg3, arg4);
}
