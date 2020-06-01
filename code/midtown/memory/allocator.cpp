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

#include "stack.h"

#include "core/minwin.h"

#include <intrin.h>

static ARTS_FORCEINLINE constexpr u32 AlignSize(u32 value) noexcept
{
    return (value + 7) & 0xFFFFFFF8;
}

struct asMemoryAllocator::Node
{
    // Requires 8-byte alignment

    // 0:1 - In Use
    // 0x2 - Is Array
    // 0x4 - Sanity Check Pending
    // 0xFFFFFFF8 - Next
    u32 Status;

    // Size of data, only aligned when free
    u32 Size;

    static constexpr u32 LOWER_GUARD = 0x55555555;
    static constexpr u32 UPPER_GUARD = 0xAAAAAAAA;

    ARTS_FORCEINLINE void Clear() noexcept
    {
        Status = 0;
        Size = 0;
    }

    ARTS_FORCEINLINE Node* GetPrev() const noexcept
    {
        return reinterpret_cast<Node*>(Status & 0xFFFFFFF8);
    }

    ARTS_FORCEINLINE void SetPrev(Node* n) noexcept
    {
        Status = reinterpret_cast<u32>(n) | (Status & 0x7);
    }

    ARTS_FORCEINLINE u8* GetData() const noexcept
    {
        return reinterpret_cast<u8*>(const_cast<Node*>(this)) + sizeof(Node);
    }

    ARTS_FORCEINLINE Node* GetNext() const noexcept
    {
        return reinterpret_cast<Node*>(GetData() + AlignSize(Size));
    }

    ARTS_FORCEINLINE void SetAllocated(bool allocated) noexcept
    {
        Status &= 0xFFFFFFF8;

        if (allocated)
            Status |= 1;
    }

    ARTS_FORCEINLINE bool IsAllocated() const noexcept
    {
        return (Status & 0x1) == 0x1;
    }

    ARTS_FORCEINLINE void SetIsArray(bool array) noexcept
    {
        Status &= 0xFFFFFFFD;

        if (array)
            Status |= 0x2;
    }

    ARTS_FORCEINLINE bool IsArray() const noexcept
    {
        return (Status & 0x2) == 0x2;
    }

    // Used in SanityCheck
    ARTS_FORCEINLINE void SetPendingSanity(bool pending) noexcept
    {
        Status &= 0xFFFFFFFB;

        if (pending)
            Status |= 0x4;
    }

    // Used in SanityCheck
    ARTS_FORCEINLINE bool IsPendingSanity() const noexcept
    {
        return (Status & 0x4) == 0x4;
    }

    // Only valid for debug allocators
    ARTS_FORCEINLINE i32 GetAllocSource() const noexcept
    {
        u8* const data = GetData();
        u32 source = 0;
        std::memcpy(&source, data, sizeof(source));
        return source;
    }

    // Only valid for debug allocators
    ARTS_FORCEINLINE bool CheckLowerGuard() const noexcept
    {
        u8* const data = GetData();
        u32 lower = 0;
        std::memcpy(&lower, data + 4, sizeof(lower));
        return lower == LOWER_GUARD;
    }

    // Only valid for debug allocators
    ARTS_FORCEINLINE bool CheckUpperGuard() const noexcept
    {
        u8* const data = GetData();
        u32 upper = 0;
        std::memcpy(&upper, data + Size - 4, sizeof(upper));
        return upper == UPPER_GUARD;
    }

    ARTS_FORCEINLINE void SetDebugGuards(u32 source) noexcept
    {
        u8* const data = GetData();
        std::memcpy(data, &source, sizeof(source));
        std::memcpy(data + 4, &LOWER_GUARD, sizeof(LOWER_GUARD));
        std::memcpy(data + Size - 4, &UPPER_GUARD, sizeof(UPPER_GUARD));
    }

    static constexpr usize DebugLowerGuardSize = sizeof(u32) * 2;
    static constexpr usize DebugUpperGuardSize = sizeof(u32) * 1;

    static constexpr usize DebugGuardOverhead = DebugLowerGuardSize + DebugUpperGuardSize;

    static ARTS_FORCEINLINE Node* From(void* ptr, bool debug) noexcept
    {
        return reinterpret_cast<Node*>(
            static_cast<u8*>(ptr) - (debug ? (sizeof(Node) + DebugLowerGuardSize) : sizeof(Node)));
    }
};

struct asMemoryAllocator::FreeNode : asMemoryAllocator::Node
{
    FreeNode* PrevFree; // Prev free node in bucket
    FreeNode* NextFree; // Next free node in bucket

    ARTS_FORCEINLINE void MergeNext()
    {
        Node* const next = GetNext();
        Size = next->Size + reinterpret_cast<u8*>(next) - reinterpret_cast<u8*>(this);
        GetNext()->SetPrev(this);
    }
};

static ARTS_FORCEINLINE u32 GetBucketIndex(u32 size) noexcept
{
#if 1
    unsigned long index;
    _BitScanReverse(&index, size + 7);
    return index;
#else
    u32 bucket = 3;

    for (u32 i = (size + 7) >> 4; i; i >>= 1)
        ++bucket;

    return bucket;
#endif
}

asMemoryAllocator::asMemoryAllocator() = default;

asMemoryAllocator::~asMemoryAllocator() = default;

void* asMemoryAllocator::Allocate(u32 size)
{
    export_hook(0x520A20);

    if (size == 0)
        return nullptr;

    if (debug_)
        size += Node::DebugGuardOverhead;

    Verify(nullptr);

    u32 asize = AlignSize(size);

    FreeNode* n = nullptr;

    for (u32 i = GetBucketIndex(size); i < std::size(buckets_); ++i)
    {
        for (n = buckets_[i]; n; n = n->NextFree)
        {
            if ((n->Size == asize) || (n->Size > asize + sizeof(Node)))
                break;
        }

        if (n)
            break;
    }

    if (n)
    {
        ArAssert(!n->IsAllocated(), "Node not free");

        u32 split_size = n->Size - asize;

        ArDebugAssert(split_size == 0 || split_size > sizeof(Node), "Invalid node split");

        Unlink(n);

        n->SetAllocated(true);
        n->Size = size;

        if (split_size > sizeof(Node))
        {
            Node* next = n->GetNext();

            next->Clear();
            next->SetPrev(n);
            next->Size = split_size - sizeof(Node);

            if (Node* after = next->GetNext(); reinterpret_cast<u8*>(after) < (heap_ + heap_offset_))
                after->SetPrev(next);

            Link(static_cast<FreeNode*>(next));

            if (last_ == n)
                last_ = next;
        }
    }
    else
    {
        n = reinterpret_cast<FreeNode*>(heap_ + heap_offset_);
        heap_offset_ += sizeof(Node) + asize;

        if (heap_offset_ > heap_size_)
            Quitf("Heap overrun");

        n->Clear();
        n->SetPrev(last_);
        n->Size = size;
        n->SetAllocated(true);

        last_ = n;
    }

    u8* result = n->GetData();

    std::memset(result, 0, size);

    if (debug_)
    {
        void** ebp = static_cast<void***>(_AddressOfReturnAddress())[-1];
        ebp = static_cast<void**>(*ebp);
        n->SetDebugGuards(reinterpret_cast<u32>(ebp[1]));

        result += Node::DebugLowerGuardSize;
    }

    return result;
}

void asMemoryAllocator::CheckPointer(void* ptr)
{
    export_hook(0x520C40);

    if (initialized_ && debug_ && ptr)
    {
        Node* n = Node::From(ptr, debug_);

        if (!n->CheckLowerGuard() || !n->CheckUpperGuard())
        {
            Errorf("CheckPointer failed!");

            SanityCheck();
        }
    }
}

void asMemoryAllocator::Free(void* ptr)
{
    export_hook(0x520C90);

    if (!ptr || !initialized_)
        return;

    Verify(ptr);

    FreeNode* n = static_cast<FreeNode*>(Node::From(ptr, debug_));

    if (debug_)
        std::memset(n->GetData(), 0xDD, n->Size);

    n->SetAllocated(false);
    n->Size = AlignSize(n->Size);

    if (FreeNode* prev = static_cast<FreeNode*>(n->GetPrev()); prev && !prev->IsAllocated())
    {
        Unlink(prev);

        if (last_ == n)
            last_ = prev;

        prev->MergeNext();

        n = prev;
    }

    if (last_ == n)
    {
        last_ = n->GetPrev();
        heap_offset_ = reinterpret_cast<u8*>(n) - heap_;
    }
    else
    {
        if (FreeNode* const next = static_cast<FreeNode*>(n->GetNext()); !next->IsAllocated())
        {
            Unlink(next);

            if (last_ == next)
                last_ = n;

            n->MergeNext();
        }

        Link(n);
    }
}

void asMemoryAllocator::GetStats(struct asMemStats* stats)
{
    export_hook(0x520FC0);

    *stats = {};

    u8* const heap = heap_;
    u8* const heap_end = heap_ + heap_offset_;

    for (Node* n = reinterpret_cast<Node*>(heap); n->GetData() < heap_end; n = n->GetNext())
    {
        ++stats->nTotalNodes;

        u32 size = n->Size;

        stats->cbOverhead += (AlignSize(size) - size) + sizeof(Node);

        if (n->IsAllocated())
        {
            ++stats->nUsedNodes;
            stats->cbUsed += size;
        }
        else
        {
            ++stats->nFreeNodes;
            stats->cbFree += size;
        }
    }

    ArAssert(stats->cbFree + stats->cbUsed + stats->cbOverhead == heap_offset_, "Invalid Node Sizes");
}

void asMemoryAllocator::Init(void* heap, u32 heap_size, b32 use_nodes)
{
    export_hook(0x5209D0);

    ArAssert(!initialized_, "Allocator already initialized");
    ArAssert(use_nodes, "Linear allocator not supported");

    heap_ = static_cast<u8*>(heap);
    heap_size_ = heap_size;
    heap_offset_ = 0;
    use_nodes_ = use_nodes;
    last_ = nullptr;

    if (use_nodes)
        std::memset(buckets_, 0, sizeof(buckets_));

    initialized_ = true;
}

void asMemoryAllocator::Kill()
{
    export_hook(0x520A10);

    heap_ = nullptr;
    initialized_ = false;
}

void* asMemoryAllocator::Reallocate(void* ptr, u32 size)
{
    export_hook(0x520EA0);

    if (initialized_)
        Verify(ptr);

    u32 old_size = 0;

    if (ptr)
    {
        if (size == 0)
        {
            Free(ptr);
            return nullptr;
        }

        old_size = SizeOf(ptr);

        if (size > old_size)
        {
            size = std::max(size, old_size + (old_size >> 1));
        }
        else
        {
            if (size > (old_size >> 1))
                return ptr;

            old_size = size;
        }
    }

    void* new_ptr = Allocate(size);

    if (ptr && new_ptr)
    {
        std::memcpy(new_ptr, ptr, old_size);
        Free(ptr);
    }

    return new_ptr;
}

static inline void ARTS_FASTCALL HexDump16(char (&buffer)[65], const u8* data)
{
    static constexpr const char HexCharTable[16 + 1] = "0123456789ABCDEF";

    for (u32 i = 0; i < 16; ++i)
    {
        u8 v;

        __try
        {
            v = data[i];
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            v = 0;
        }

        u32 const j = (i * 3);

        buffer[j + 0] = HexCharTable[v >> 4];
        buffer[j + 1] = HexCharTable[v & 0xF];
        buffer[j + 2] = ' ';

        buffer[i + 48] = (v >= 0x20 && v < 0x7F) ? v : '.';
    }

    buffer[64] = '\0';
}

static ARTS_NOINLINE b32 ARTS_FASTCALL HeapAssert(void* address, const char* message, i32 source = 0)
{
    char address_string[128];

    LookupAddress(address_string, std::size(address_string), usize(source));
    Errorf("Heap node @ 0x%08X: %s (allocated by %s).", reinterpret_cast<usize>(address), message, address_string);

    char hex_string[65];
    const u8* current = reinterpret_cast<const u8*>(address) - 64;

    for (u32 pending = 144; pending != 0; pending -= 16, current += 16)
    {
        HexDump16(hex_string, current);
        Displayf((pending != 80) ? " %08X : %s" : "[%08X]: %s", reinterpret_cast<usize>(current), hex_string);
    }

    return true;
}

void asMemoryAllocator::SanityCheck()
{
    export_hook(0x521090);

    if (!initialized_)
        return;

    u8* const heap = heap_;

    if (!heap)
        return;

    u8* const heap_end = heap_ + heap_offset_;

    b32 is_invalid = 0;

    Node* last = nullptr;
    usize total = 0;
    usize total_used = 0;

    for (Node* n = reinterpret_cast<Node*>(heap); n->GetData() < heap_end; last = n, n = n->GetNext())
    {
        u32 source = 0;

        if (debug_ && n->IsAllocated())
        {
            source = n->GetAllocSource();

            if (!n->CheckLowerGuard())
                is_invalid |= HeapAssert(n->GetData(), "Lower Guard Word", source);

            if (!n->CheckUpperGuard())
                is_invalid |= HeapAssert(n->GetData(), "Upper Guard Word", source);
        }

        if (n->GetPrev() != last)
            is_invalid |= HeapAssert(n, "Linked List", source);

        if (n->IsPendingSanity())
            is_invalid |= HeapAssert(n, "Pending Sanity Check", source);

        if (n->IsAllocated())
            ++total_used;
        else
            n->SetPendingSanity(true);

        ++total;
    }

    if (is_invalid)
        Abortf("Memory Allocator Corrupted");

    ArAssert(last == last_, "Memory Allocator Corrupted");

    if (last)
        ArAssert(reinterpret_cast<u8*>(last->GetNext()) == heap_end, "Memory Allocator Corrupted");

    usize total_free = 0;

    for (usize i = 3; i < 32; ++i)
    {
        for (FreeNode *n = buckets_[i], *prev_free = nullptr; n; prev_free = n, n = n->NextFree)
        {
            if (n->PrevFree != prev_free)
                is_invalid |= HeapAssert(n, "Invalid Prev Node");

            if (!n->IsPendingSanity())
                is_invalid |= HeapAssert(n, "Missing Sanity Check");

            n->SetPendingSanity(false);

            ++total_free;
        }
    }

    for (Node* n = reinterpret_cast<Node*>(heap); n->GetData() < heap_end; n = n->GetNext())
        ArAssert(!n->IsPendingSanity(), "Pending Sanity Check");

    ArAssert(total_used + total_free == total, "Mismatched Node Count");

    // Displayf("Sanity Checked %u nodes (%u used, %u free)", total, total_used, total_free);
}

usize asMemoryAllocator::SizeOf(void* ptr)
{
    return Node::From(ptr, debug_)->Size - (debug_ ? Node::DebugGuardOverhead : 0);
}

void asMemoryAllocator::Link(FreeNode* n)
{
    export_hook(0x520E50);

    u32 const bucket = GetBucketIndex(n->Size);

    FreeNode* const next = buckets_[bucket];

    n->PrevFree = nullptr;
    n->NextFree = next;

    if (next)
        next->PrevFree = n;

    buckets_[bucket] = n;
}

void asMemoryAllocator::Unlink(FreeNode* n)
{
    export_hook(0x520DF0);

    FreeNode* const prev = n->PrevFree;
    FreeNode* const next = n->NextFree;

    if (prev)
        prev->NextFree = next;
    else
        buckets_[GetBucketIndex(n->Size)] = next;

    if (next)
        next->PrevFree = prev;

    n->PrevFree = nullptr;
    n->NextFree = nullptr;
}

void asMemoryAllocator::Verify(void* ptr)
{
    export_hook(0x520F00);

    ArAssert(heap_ && heap_size_, "Heap not initialized");

    if (u32 const lock_count = lock_count_)
    {
        lock_count_ = 0;
        Warningf("Memory allocated or freed while locked!");
        StackTraceback(16);
        lock_count_ = lock_count;
    }

    if (ptr)
    {
        ArAssert(static_cast<u8*>(ptr) >= heap_, "Pointer below heap");
        ArAssert(static_cast<u8*>(ptr) < (heap_ + heap_size_), "Pointer above heap");

        if (use_nodes_)
        {
            Node* const n = Node::From(ptr, debug_);

            ArAssert(n->IsAllocated(), "Pointer not allocated");

            if (debug_)
            {
                ArAssert(n->CheckLowerGuard(), "Lower guard corrupted");
                ArAssert(n->CheckUpperGuard(), "Upper guard corrupted");
            }
        }
    }
}
