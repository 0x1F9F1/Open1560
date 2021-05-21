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

define_dummy_symbol(memory_valloc);

#include "valloc.h"

#include "core/minwin.h"

#include "allocator.h"

asSafeHeap SAFEHEAP {};

static usize MultiHeapCount = 4;

static mem::cmd_param PARAM_multiheap {"multiheap"};

asSafeHeap::asSafeHeap()
{}

asSafeHeap::~asSafeHeap()
{
    Kill();
}

void asSafeHeap::Init(isize heap_size, b32 multi_heap)
{
    // TODO: Move param to ApplicationHelper
    MultiHeapCount = PARAM_multiheap.get_or<i32>(4);

    multi_heap = multi_heap && (MultiHeapCount != 0);

    SYSTEM_INFO sys_info;
    GetSystemInfo(&sys_info);

    heap_size = (heap_size + sys_info.dwAllocationGranularity - 1) & ~isize(sys_info.dwAllocationGranularity - 1);

    heap_size_ = heap_size;
    multi_heap_ = multi_heap;

    if (multi_heap)
        heap_size *= MultiHeapCount;

    heap_ = static_cast<u8*>(VirtualAlloc(
        nullptr, heap_size, multi_heap ? MEM_RESERVE : MEM_COMMIT, multi_heap ? PAGE_NOACCESS : PAGE_READWRITE));

    Activate();
}

void asSafeHeap::Kill()
{
    if (heap_)
    {
        Deactivate();

        if (multi_heap_)
        {
            VirtualFree(heap_, 0, MEM_RELEASE);
        }

        heap_ = nullptr;
    }
}

static mem::cmd_param PARAM_safeheap {"safeheap"};

void asSafeHeap::Restart()
{
    if (!PARAM_safeheap.get_or(true))
    {
        ALLOCATOR.DumpStats();
        return;
    }

    Deactivate();

    if (multi_heap_)
    {
        heap_index_ = (heap_index_ + 1) % MultiHeapCount;
    }

    Activate();
}

void asSafeHeap::Activate()
{
    current_heap_ = heap_ + (heap_size_ * heap_index_);

    if (multi_heap_)
    {
        VirtualAlloc(current_heap_, heap_size_, MEM_COMMIT, PAGE_READWRITE);
    }

    ALLOCATOR.Init(current_heap_, heap_size_, true);
}

void asSafeHeap::Deactivate()
{
    ALLOCATOR.Kill();

    if (multi_heap_)
    {
        // VirtualFree without the MEM_RELEASE flag may free memory but not address descriptors
        ARTS_MSVC_DIAGNOSTIC_IGNORED(6250);
        VirtualFree(current_heap_, heap_size_, MEM_DECOMMIT);
    }

    current_heap_ = 0;
}

patch_static_ctors(0x521350);
