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

#include "allocator.h"

asMemoryAllocator::asMemoryAllocator()
{
    unimplemented();
}

asMemoryAllocator::~asMemoryAllocator()
{
    unimplemented();
}

void* asMemoryAllocator::Allocate(u32 arg1)
{
    return stub<thiscall_t<void*, asMemoryAllocator*, u32>>(0x120A20_Offset, this, arg1);
}

void asMemoryAllocator::CheckPointer(void* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*>>(0x120C40_Offset, this, arg1);
}

void asMemoryAllocator::Free(void* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*>>(0x120C90_Offset, this, arg1);
}

void asMemoryAllocator::GetStats(struct asMemStats* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, struct asMemStats*>>(0x120FC0_Offset, this, arg1);
}

void asMemoryAllocator::Init(void* arg1, u32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*, u32, i32>>(0x1209D0_Offset, this, arg1, arg2, arg3);
}

void asMemoryAllocator::Kill()
{
    return stub<thiscall_t<void, asMemoryAllocator*>>(0x120A10_Offset, this);
}

void* asMemoryAllocator::Reallocate(void* arg1, u32 arg2)
{
    return stub<thiscall_t<void*, asMemoryAllocator*, void*, u32>>(0x120EA0_Offset, this, arg1, arg2);
}

void asMemoryAllocator::SanityCheck()
{
    return stub<thiscall_t<void, asMemoryAllocator*>>(0x121090_Offset, this);
}

void asMemoryAllocator::Link(struct asMemoryAllocator::node* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, struct asMemoryAllocator::node*>>(0x120E50_Offset, this, arg1);
}

void asMemoryAllocator::Unlink(struct asMemoryAllocator::node* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, struct asMemoryAllocator::node*>>(0x120DF0_Offset, this, arg1);
}

void asMemoryAllocator::Verify(void* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*>>(0x120F00_Offset, this, arg1);
}

define_dummy_symbol(memory_allocator);
