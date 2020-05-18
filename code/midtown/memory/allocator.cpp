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

static inline constexpr u32 AlignSize(u32 value) noexcept
{
    return (value + 7) & 0xFFFFFFF8;
}

struct asMemoryAllocator::Node
{
private:
    // Requires 8-byte alignment

    // 0:1 - In Use
    // 0x2 - Is Array
    // 0x4 - Sanity Check Pending
    // 0xFFFFFFF8 - Next
    u32 uStatus;

    // Unaligned size of Data
    u32 nSize;

    static constexpr u32 LOWER_GUARD = 0x55555555;
    static constexpr u32 UPPER_GUARD = 0xAAAAAAAA;

public:
    inline void Clear() noexcept
    {
        uStatus = 0;
        nSize = 0;
    }

    // Only aligned when free
    inline u32 GetSize() const noexcept
    {
        return nSize;
    }

    inline void SetSize(u32 size) noexcept
    {
        nSize = size;
    }

    inline Node* GetPrev() const noexcept
    {
#if 1
        return reinterpret_cast<Node*>(uStatus & 0xFFFFFFF8);
#else
        const u32 dist = uStatus & 0xFFFFFFF8;

        if (dist)
        {
            return reinterpret_cast<Node*>(reinterpret_cast<u8*>(const_cast<Node*>(this)) - dist);
        }

        return nullptr;
#endif
    }

    inline void SetPrev(Node* n) noexcept
    {
#if 1
        uStatus = reinterpret_cast<u32>(n) | (uStatus & 0x7);
#else
        uStatus &= 0x7;

        if (n)
        {
            const u32 dist = reinterpret_cast<u8*>(this) - reinterpret_cast<u8*>(n);
            DebugAssert((dist & 0x7) == 0);
            uStatus |= dist;
        }
#endif
    }

    inline u8* GetData() const noexcept
    {
        return reinterpret_cast<u8*>(const_cast<Node*>(this)) + sizeof(Node);
    }

    inline Node* GetNext() const noexcept
    {
        return reinterpret_cast<Node*>(GetData() + AlignSize(nSize));
    }

    inline void SetAllocated(bool allocated) noexcept
    {
        uStatus &= 0xFFFFFFF8;

        if (allocated)
            uStatus |= 1;
    }

    inline bool IsAllocated() const noexcept
    {
        return (uStatus & 0x1) == 0x1;
    }

    inline void SetIsArray(bool array) noexcept
    {
        uStatus &= 0xFFFFFFFD;

        if (array)
            uStatus |= 0x2;
    }

    inline bool IsArray() const noexcept
    {
        return (uStatus & 0x2) == 0x2;
    }

    // Used in SanityCheck
    inline void SetPendingSanity(bool pending) noexcept
    {
        uStatus &= 0xFFFFFFFB;

        if (pending)
            uStatus |= 0x4;
    }

    // Used in SanityCheck
    inline bool IsPendingSanity() const noexcept
    {
        return (uStatus & 0x4) == 0x4;
    }

    // Only valid for debug allocators
    inline i32 GetAllocSource() const noexcept
    {
        u8* const data = GetData();
        u32 source = 0;
        std::memcpy(&source, data, 4);
        return source;
    }

    // Only valid for debug allocators
    inline bool CheckLowerGuard() const noexcept
    {
        u8* const data = GetData();
        u32 lower = 0;
        std::memcpy(&lower, data + 4, 4);
        return lower == LOWER_GUARD;
    }

    // Only valid for debug allocators
    inline bool CheckUpperGuard() const noexcept
    {
        u8* const data = GetData();
        u32 upper = 0;
        std::memcpy(&upper, data + nSize - 4, 4);
        return upper == UPPER_GUARD;
    }

    inline void SetDebugGuards(u32 source) noexcept
    {
        u8* const data = GetData();
        std::memcpy(data, &source, 4);
        std::memcpy(data + 4, &LOWER_GUARD, 4);
        std::memcpy(data + nSize - 4, &UPPER_GUARD, 4);
    }

    static inline Node* From(void* ptr, bool debug) noexcept
    {
        return reinterpret_cast<Node*>(static_cast<u8*>(ptr) - (debug ? (sizeof(Node) + 8) : sizeof(Node)));
    }
};

struct asMemoryAllocator::FreeNode : asMemoryAllocator::Node
{
    FreeNode* PrevFree; // Prev free node in bucket
    FreeNode* NextFree; // Next free node in bucket

    inline FreeNode* GetPrevFree() const noexcept
    {
        return PrevFree;
    }

    inline FreeNode* GetNextFree() const noexcept
    {
        return NextFree;
    }

    inline void SetPrevFree(FreeNode* n) noexcept
    {
        PrevFree = n;
    }

    inline void SetNextFree(FreeNode* n) noexcept
    {
        NextFree = n;
    }

    inline void MergeNext()
    {
        Node* const next = GetNext();
        SetSize(next->GetSize() + reinterpret_cast<u8*>(next) - reinterpret_cast<u8*>(this));
        GetNext()->SetPrev(this);
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

static i32 HeapAssert(void* arg1, i32 arg2, const char* arg3, i32 arg4)
{
    return stub<cdecl_t<i32, void*, i32, const char*, i32>>(0x521250, arg1, arg2, arg3, arg4);
}

void asMemoryAllocator::SanityCheck()
{
    export_hook(0x521090);

    if (!initialized_)
        return;

    u8* const heap = heap_;

    if (!heap)
        return;

    u8* const heap_end = heap + heap_offset_;

    i32 is_invalid = 0;

    Node* last = nullptr;
    usize total = 0;
    usize total_used = 0;

    for (Node* n = reinterpret_cast<Node*>(heap); n->GetData() < heap_end; last = n, n = n->GetNext())
    {
        if (debug_ && n->IsAllocated())
        {
            is_invalid |= HeapAssert(n, n->CheckLowerGuard(), "Lower guard word", n->GetAllocSource());
            is_invalid |= HeapAssert(n, n->CheckUpperGuard(), "Upper guard word", n->GetAllocSource());
        }

        is_invalid |= HeapAssert(n, n->GetPrev() == last, "Linked list", 0);
        is_invalid |= HeapAssert(n, !n->IsPendingSanity(), "Pendig sanity", 0);

        if (n->IsAllocated())
        {
            ++total_used;
        }
        else
        {
            n->SetPendingSanity(true);
        }

        ++total;
    }

    if (is_invalid)
        Abortf("Memory Allocator Corrupted");

    is_invalid |= HeapAssert(last, last == last_, "Last Node", 0);

    if (last)
        is_invalid |= HeapAssert(last, reinterpret_cast<u8*>(last->GetNext()) == heap_end, "Heap End", 0);

    if (is_invalid)
        Abortf("Memory Allocator Corrupted");

    usize total_free = 0;

    for (usize i = 3; i < 32; ++i)
    {
        for (FreeNode *n = buckets_[i], *prev = nullptr; n; prev = n, n = n->GetNextFree())
        {
            ArAssert(n->GetPrevFree() == prev, "Invalid Prev Node");
            ArAssert(n->IsPendingSanity(), "Missing Sanity Check");

            n->SetPendingSanity(false);

            ++total_free;
        }
    }

    for (Node* n = reinterpret_cast<Node*>(heap); n->GetData() < heap_end; n = n->GetNext())
    {
        ArAssert(!n->IsPendingSanity(), "Pending Sanity Check");
    }

    ArAssert(total_used + total_free == total, "Mismatched Node Count");

    // Displayf("Sanity Checked %u nodes (%u used, %u free)", total, total_used, total_free);
}

usize asMemoryAllocator::SizeOf(void* ptr)
{
    return Node::From(ptr, debug_)->GetSize() - (debug_ ? 12 : 0);
}

void asMemoryAllocator::Link(FreeNode* n)
{
    return stub<thiscall_t<void, asMemoryAllocator*, struct asMemoryAllocator::Node*>>(0x520E50, this, n);
}

void asMemoryAllocator::Unlink(FreeNode* n)
{
    return stub<thiscall_t<void, asMemoryAllocator*, struct asMemoryAllocator::Node*>>(0x520DF0, this, n);
}

void asMemoryAllocator::Verify(void* arg1)
{
    return stub<thiscall_t<void, asMemoryAllocator*, void*>>(0x520F00, this, arg1);
}