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

asSafeHeap::asSafeHeap()
{}

asSafeHeap::~asSafeHeap()
{
    Kill();
}

void asSafeHeap::Init(isize heap_size, i32 num_heaps)
{
    SYSTEM_INFO sys_info;
    GetSystemInfo(&sys_info);

    heap_size = (heap_size + sys_info.dwAllocationGranularity - 1) & -isize(sys_info.dwAllocationGranularity);

    heap_size_ = heap_size;
    num_heaps_ = (num_heaps > 1) ? num_heaps : 0;

    heap_ = static_cast<u8*>(VirtualAlloc(nullptr, heap_size * (num_heaps_ ? num_heaps_ : 1),
        num_heaps_ ? MEM_RESERVE : MEM_COMMIT, num_heaps_ ? PAGE_NOACCESS : PAGE_READWRITE));

    Activate();
}

void asSafeHeap::Kill()
{
    if (heap_)
    {
        Deactivate();

        if (num_heaps_)
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

    if (num_heaps_)
    {
        heap_index_ = (heap_index_ + 1) % num_heaps_;
    }

    Activate();
}

void asSafeHeap::Activate()
{
    current_heap_ = heap_ + (heap_size_ * heap_index_);

    if (num_heaps_)
    {
        VirtualAlloc(current_heap_, heap_size_, MEM_COMMIT, PAGE_READWRITE);
    }

    ALLOCATOR.Init(current_heap_, heap_size_, true);
}

void asSafeHeap::Deactivate()
{
    ALLOCATOR.Kill();

    if (num_heaps_)
    {
        // VirtualFree without the MEM_RELEASE flag may free memory but not address descriptors
        ARTS_MSVC_DIAGNOSTIC_IGNORED(6250);
        VirtualFree(current_heap_, heap_size_, MEM_DECOMMIT);
    }

    current_heap_ = 0;
}

patch_static_ctors(0x521350);
