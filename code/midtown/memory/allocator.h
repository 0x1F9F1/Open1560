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
    memory:allocator

    0x5209B0 | public: __thiscall asMemoryAllocator::asMemoryAllocator(void) | ??0asMemoryAllocator@@QAE@XZ
    0x5209C0 | public: __thiscall asMemoryAllocator::~asMemoryAllocator(void) | ??1asMemoryAllocator@@QAE@XZ
    0x5209D0 | public: void __thiscall asMemoryAllocator::Init(void *,unsigned int,int) | ?Init@asMemoryAllocator@@QAEXPAXIH@Z
    0x520A10 | public: void __thiscall asMemoryAllocator::Kill(void) | ?Kill@asMemoryAllocator@@QAEXXZ
    0x520A20 | public: void * __thiscall asMemoryAllocator::Allocate(unsigned int) | ?Allocate@asMemoryAllocator@@QAEPAXI@Z
    0x520C40 | public: void __thiscall asMemoryAllocator::CheckPointer(void *) | ?CheckPointer@asMemoryAllocator@@QAEXPAX@Z
    0x520C90 | public: void __thiscall asMemoryAllocator::Free(void *) | ?Free@asMemoryAllocator@@QAEXPAX@Z
    0x520DF0 | private: void __thiscall asMemoryAllocator::Unlink(struct asMemoryAllocator::node *) | ?Unlink@asMemoryAllocator@@AAEXPAUnode@1@@Z
    0x520E50 | private: void __thiscall asMemoryAllocator::Link(struct asMemoryAllocator::node *) | ?Link@asMemoryAllocator@@AAEXPAUnode@1@@Z
    0x520EA0 | public: void * __thiscall asMemoryAllocator::Reallocate(void *,unsigned int) | ?Reallocate@asMemoryAllocator@@QAEPAXPAXI@Z
    0x520F00 | private: void __thiscall asMemoryAllocator::Verify(void *) | ?Verify@asMemoryAllocator@@AAEXPAX@Z
    0x520FC0 | public: void __thiscall asMemoryAllocator::GetStats(struct asMemStats *) | ?GetStats@asMemoryAllocator@@QAEXPAUasMemStats@@@Z
    0x521090 | public: void __thiscall asMemoryAllocator::SanityCheck(void) | ?SanityCheck@asMemoryAllocator@@QAEXXZ
    0x521250 | int __cdecl HeapAssert(void *,int,char *,int) | ?HeapAssert@@YAHPAXHPADH@Z
    0x7805E8 | class asMemoryAllocator ALLOCATOR | ?ALLOCATOR@@3VasMemoryAllocator@@A
    0x780688 | class asMemoryAllocator * CURHEAP | ?CURHEAP@@3PAVasMemoryAllocator@@A
    0x780690 | class asMemoryAllocator CRTALLOCATOR | ?CRTALLOCATOR@@3VasMemoryAllocator@@A
    0x780730 | unsigned char * CRTHEAP | ?CRTHEAP@@3PAEA
*/

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

    // ??1asMemoryAllocator@@QAE@XZ

    // ?Allocate@asMemoryAllocator@@QAEPAXI@Z
    ARTS_EXPORT void* Allocate(usize size);

    void* Allocate(usize size, usize align, void* caller);

    // ?CheckPointer@asMemoryAllocator@@QAEXPAX@Z
    ARTS_EXPORT void CheckPointer(void* ptr);

    // ?Free@asMemoryAllocator@@QAEXPAX@Z
    ARTS_EXPORT void Free(void* ptr);

    void Free(void* ptr, usize size);

    // ?GetStats@asMemoryAllocator@@QAEXPAUasMemStats@@@Z
    ARTS_EXPORT void GetStats(asMemStats* stats);

    void GetStats(asMemStats* stats, asMemSource* sources, usize* num_sources);

    // ?Init@asMemoryAllocator@@QAEXPAXIH@Z
    ARTS_EXPORT void Init(void* heap, usize heap_size, b32 use_nodes);

    // ?Kill@asMemoryAllocator@@QAEXXZ
    ARTS_EXPORT void Kill();

    // ?Reallocate@asMemoryAllocator@@QAEPAXPAXI@Z
    ARTS_EXPORT void* Reallocate(void* ptr, usize size);

    void* Reallocate(void* ptr, usize size, void* caller);

    // ?SanityCheck@asMemoryAllocator@@QAEXXZ
    ARTS_EXPORT void SanityCheck() const;

    void DumpStats();

    usize SizeOf(void* ptr) const;

    void SetDebug(bool enabled)
    {
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

    // ?Link@asMemoryAllocator@@AAEXPAUnode@1@@Z
    ARTS_EXPORT void Link(FreeNode* n);

    // ?Unlink@asMemoryAllocator@@AAEXPAUnode@1@@Z
    ARTS_EXPORT void Unlink(FreeNode* n);

    // ?Verify@asMemoryAllocator@@AAEXPAX@Z
    ARTS_EXPORT void Verify(void* ptr) const;

    FreeNode* FindFirstFit(usize size, usize align, usize offset);

    Node* GetFirstNode() const;

    void Lock() const;
    void Unlock() const;

    bool DoSanityCheck() const;

    b32 initialized_ {};
    b32 debug_ {};
    void* heap_ {};
    usize heap_size_ {};
    std::atomic<usize> heap_used_ {};
    mutable usize lock_count_ {};
    b32 use_nodes_ {};
    FreeNode* buckets_[32] {};

#ifndef ARTS_STANDALONE
    Node* last_ {};
#endif

    // New Fields
    mutable RecursiveTicketLock lock_ {};

#ifndef ARTS_FINAL
    std::atomic<usize> alloc_id_ {};
    usize last_allocs_[16] {};
#endif
};

// check_size(asMemoryAllocator, 0xA0);

// ?ALLOCATOR@@3VasMemoryAllocator@@A
ARTS_EXPORT extern asMemoryAllocator ALLOCATOR;

// ?CRTALLOCATOR@@3VasMemoryAllocator@@A

// ?CRTHEAP@@3PAEA

// ?CURHEAP@@3PAVasMemoryAllocator@@A
ARTS_EXPORT extern asMemoryAllocator* CURHEAP;

asMemoryAllocator* StaticAllocator();
