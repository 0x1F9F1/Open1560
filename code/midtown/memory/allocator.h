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

#include "data7/ticketlock.h"

constexpr usize DefaultNewAlignment = __STDCPP_DEFAULT_NEW_ALIGNMENT__;

struct asMemStats
{
    usize nTotalBlocks {};
    usize nFreeBlocks {};
    usize nUsedBlocks {};

    usize cbOverhead {};
    usize cbFree {};
    usize cbUsed {};
};

struct asMemSource
{
    usize uSource {};
    usize cbUsed {};
    usize cbOverhead {};
    usize nBlocks {};
};

check_size(asMemStats, 0x18);

class asMemoryAllocator
{
public:
    // ??0asMemoryAllocator@@QAE@XZ
    asMemoryAllocator() = default;

    // ??1asMemoryAllocator@@QAE@XZ
    ~asMemoryAllocator() = default;

    void* Allocate(usize size, usize align, void* caller);

    // ?CheckPointer@asMemoryAllocator@@QAEXPAX@Z
    void CheckPointer(void* ptr);

    // ?Free@asMemoryAllocator@@QAEXPAX@Z
    void Free(void* ptr);

    void Free(void* ptr, usize size);

    void GetStats(asMemStats* stats, asMemSource* sources, usize* num_sources);

    void Init(void* heap, usize heap_size);

    // ?Kill@asMemoryAllocator@@QAEXXZ
    void Kill();

    void* Reallocate(void* ptr, usize size, void* caller);

    // ?SanityCheck@asMemoryAllocator@@QBEXXZ
    ARTS_EXPORT void SanityCheck() const;

    void DumpStats();

    usize SizeOf(void* ptr) const;

    void SetDebug(bool enabled)
    {
        ArAssert(!IsInitialized(), "Cannot change debug mode of initialized allocator");

        debug_ = enabled;
    }

    bool IsInitialized() const
    {
        return initialized_;
    }

    bool IsDebug() const
    {
        return debug_;
    }

    usize GetHeapSize() const
    {
        return heap_size_;
    }

    void* GetHeapStart() const
    {
        return heap_;
    }

    void* GetHeapEnd() const
    {
        return static_cast<u8*>(heap_) + heap_size_;
    }

    usize GetHeapUsed() const
    {
        return heap_used_;
    }

private:
    struct Node;
    struct FreeNode;

    u32 GetBucketIndex(u32 size) noexcept;

    // ?Link@asMemoryAllocator@@AAEXPAUnode@1@@Z
    void Link(FreeNode* n);

    // ?Unlink@asMemoryAllocator@@AAEXPAUnode@1@@Z
    void Unlink(FreeNode* n);

    // ?Verify@asMemoryAllocator@@AAEXPAX@Z
    void Verify(void* ptr) const;

    FreeNode* FindFreeNode(usize size, usize align, usize offset);

    Node* GetFirstNode() const;

    void Lock() const;
    void Unlock() const;

    bool DoSanityCheck() const;

    b32 initialized_ {};
    b32 debug_ {};
    void* heap_ {};
    usize heap_size_ {};
    std::atomic<usize> heap_used_ {};

    static constexpr usize SmallBucketBits = 7;
    static constexpr usize SmallBucketStep = 8;
    static constexpr usize SmallBucketLimit = 1 << SmallBucketBits;
    static constexpr usize SmallBucketCount = SmallBucketLimit / SmallBucketStep;
    static constexpr usize LargeBucketCount = 32 - SmallBucketBits;
    static constexpr usize NumBuckets = SmallBucketCount + LargeBucketCount;

    FreeNode* buckets_[NumBuckets] {};
    u32 live_buckets_[(NumBuckets + 31) / 32] {};

    mutable RecursiveTicketLock lock_ {};

#ifndef ARTS_FINAL
    usize alloc_id_ {};
    usize last_allocs_[16] {};
    usize num_calls_ {};
    usize num_tests_ {};
#endif
};

// ?ALLOCATOR@@3VasMemoryAllocator@@A
ARTS_EXPORT extern asMemoryAllocator ALLOCATOR;

// ?CURHEAP@@3PAVasMemoryAllocator@@A
extern asMemoryAllocator* CURHEAP;

asMemoryAllocator* StaticAllocator();
