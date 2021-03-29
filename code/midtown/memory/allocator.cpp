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

#include "core/minwin.h"
#include "stack.h"

#ifndef STATIC_HEAP_SIZE
#    define STATIC_HEAP_SIZE 0x10000
#endif

// Upper Guard  : 0x55
// Lower Guard  : 0xAA
// Uninitialized: 0xCD
// Deleted      : 0xDD

struct asMemoryAllocator::Node
{
    // Requires 4-byte alignment

    // 0x1 - In Use
    // 0x2 - Sanity Check Pending
    // 0xFFFFFFFC - Next
    u32 Status;

    // Aligned size of data
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
#if SIZE_MAX <= UINT32_MAX
        return reinterpret_cast<Node*>(Status & 0xFFFFFFFC);
#else
        const u32 dist = Status & 0xFFFFFFFC;

        if (dist)
        {
            return reinterpret_cast<Node*>(reinterpret_cast<usize>(this) - dist);
        }

        return nullptr;
#endif
    }

    ARTS_FORCEINLINE void SetPrev(Node* n) noexcept
    {
#if SIZE_MAX <= UINT32_MAX
        ArDebugAssert((reinterpret_cast<u32>(n) & 0x3) == 0, "");

        Status = reinterpret_cast<u32>(n) | (Status & 0x3);
#else
        Status &= 0x3;

        if (n)
        {
            const usize dist = reinterpret_cast<usize>(this) - reinterpret_cast<usize>(n);
            ArDebugAssert((dist & 0x3) == 0, "");
            Status |= static_cast<u32>(dist);
        }
#endif
    }

    ARTS_FORCEINLINE u8* GetData() const noexcept
    {
        return reinterpret_cast<u8*>(const_cast<Node*>(this)) + sizeof(Node);
    }

    ARTS_FORCEINLINE Node* GetNext() const noexcept
    {
        return reinterpret_cast<Node*>(GetData() + Size);
    }

    ARTS_FORCEINLINE void SetAllocated(bool allocated) noexcept
    {
        Status &= 0xFFFFFFFC;

        if (allocated)
            Status |= 1;
    }

    ARTS_FORCEINLINE bool IsAllocated() const noexcept
    {
        return (Status & 0x1) == 0x1;
    }

    ARTS_FORCEINLINE void SetPendingSanity(bool array) noexcept
    {
        Status &= 0xFFFFFFFD;

        if (array)
            Status |= 0x2;
    }

    ARTS_FORCEINLINE bool IsPendingSanity() const noexcept
    {
        return (Status & 0x2) == 0x2;
    }

    // Only valid for debug allocators
    ARTS_FORCEINLINE u32 GetUserSize() const noexcept
    {
        u8* const data = GetData();
        u32 size = 0;
        std::memcpy(&size, data + 0, sizeof(size));
        return size;
    }

    // Only valid for debug allocators
    ARTS_FORCEINLINE u32 GetAllocSource() const noexcept
    {
        u8* const data = GetData();
        u32 source = 0;
        std::memcpy(&source, data + 4, sizeof(source));
        return source;
    }

    // Only valid for debug allocators
    ARTS_FORCEINLINE bool CheckLowerGuard() const noexcept
    {
        u8* const data = GetData();
        u32 lower = 0;
        std::memcpy(&lower, data + 8, sizeof(lower));
        return lower == LOWER_GUARD;
    }

    // Only valid for debug allocators
    ARTS_FORCEINLINE bool CheckUpperGuard() const noexcept
    {
        u8* const data = GetData();
        u32 upper = 0;
        std::memcpy(&upper, data + 12 + GetUserSize(), sizeof(upper));
        return upper == UPPER_GUARD;
    }

    static constexpr usize DebugLowerGuardSize = sizeof(u32) * 3;
    static constexpr usize DebugUpperGuardSize = sizeof(u32) * 1;

    ARTS_FORCEINLINE void SetDebugGuards(u32 real_size, u32 source) noexcept
    {
        u8* const data = GetData();
        std::memcpy(data + 0, &real_size, sizeof(real_size));
        std::memcpy(data + 4, &source, sizeof(source));
        std::memcpy(data + 8, &LOWER_GUARD, sizeof(LOWER_GUARD));
        std::memcpy(data + 12 + real_size, &UPPER_GUARD, sizeof(UPPER_GUARD));
    }

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
};

static ARTS_FORCEINLINE u32 GetBucketIndex(u32 size) noexcept
{
    unsigned long index;
    _BitScanReverse(&index, size);
    return index;
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

    LookupAddress(address_string, ARTS_SIZE(address_string), usize(source));
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

void* asMemoryAllocator::Allocate(usize size)
{
    return Allocate(size, DefaultNewAlignment, nullptr);
}

void* asMemoryAllocator::Allocate(usize size, usize align, void* caller)
{
    static constexpr usize MinAllocSize = sizeof(FreeNode) - sizeof(Node);
    static constexpr usize MinAllocAlign =
        std::max<usize>(4, alignof(FreeNode)); // Node uses the lower 2 bits for other stuff
    static constexpr usize SplitNodeThresh = sizeof(FreeNode);

    static_assert(SplitNodeThresh >= sizeof(FreeNode));

    check_size(Node, 0x8);
    check_size(FreeNode, 0x10);

    if (size == 0)
        return nullptr;

    usize real_size = size;

    usize align_offset = 0;

    if (debug_)
    {
        size += Node::DebugGuardOverhead;
        align_offset += Node::DebugLowerGuardSize;

#ifndef ARTS_FINAL
        last_allocs_[alloc_id_++ % ARTS_SIZE(last_allocs_)] = reinterpret_cast<usize>(caller);
#endif
    }

    if (size <= MinAllocSize)
        size = MinAllocSize;

    size = (size + MinAllocAlign - 1) & ~(MinAllocAlign - 1);

    if (align < MinAllocAlign)
        align = MinAllocAlign;

    Lock();

    Verify(nullptr);

    FreeNode* n = FindFirstFit(size, align, align_offset);

    if (n == nullptr)
    {
        DumpStats();

        Abortf("Heap overrun allocating 0x%X bytes", size);
    }

    ArAssert(!n->IsAllocated(), "Node not free");

    Unlink(n);

    Node* next = n->GetNext();

    if (usize extra = reinterpret_cast<usize>(n->GetData() + align_offset) & (align - 1); extra != 0)
    {
        extra = align - extra;

        Node* prev = n;

        n = reinterpret_cast<FreeNode*>(reinterpret_cast<usize>(n) + extra);
        n->Clear();

        if (extra > SplitNodeThresh)
        {
            prev->Size = extra - sizeof(Node);
            n->SetPrev(prev);

            ArDebugAssert(prev->GetNext() == n, "");

            Link(static_cast<FreeNode*>(prev));
        }
        else
        {
            prev = prev->GetPrev();

            ArDebugAssert(prev, "");
            ArDebugAssert(prev->IsAllocated(), "");

            prev->Size = reinterpret_cast<usize>(n) - reinterpret_cast<usize>(prev) - sizeof(Node);
            n->SetPrev(prev);

            ArDebugAssert(prev->GetNext() == n, "");
        }
    }

    usize next_gap = reinterpret_cast<usize>(next) - reinterpret_cast<usize>(n) - sizeof(Node);

    ArDebugAssert(next_gap >= size, "Node Too Small");

    if (usize extra = next_gap - size; extra > SplitNodeThresh)
    {
        n->Size = size;

        Node* new_next = n->GetNext();

        new_next->Clear();
        new_next->Size = extra - sizeof(Node);
        new_next->SetPrev(n);

        if (next < GetHeapEnd())
            next->SetPrev(new_next);

        Link(static_cast<FreeNode*>(new_next));

        next = new_next;
    }
    else
    {
        n->Size = next_gap;

        if (next < GetHeapEnd())
            next->SetPrev(n);
    }

    ArDebugAssert(n->GetNext() == next, "");

    if (n != GetHeapStart())
        ArDebugAssert(n->GetPrev()->GetNext() == n, "");

    ArDebugAssert((next == GetHeapEnd()) || (next->GetPrev() == n), "");

    n->SetAllocated(true);

    u8* result = n->GetData();

    if (debug_)
    {
        std::memset(result, 0xCD, size);
        n->SetDebugGuards(real_size, static_cast<u32>(reinterpret_cast<usize>(caller))); // FIXME: 64-bit incompatible
        result += Node::DebugLowerGuardSize;
    }

    Unlock();

    return result;
}

void asMemoryAllocator::CheckPointer(void* ptr)
{
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
    if (!ptr || !initialized_)
        return;

    Lock();

    Verify(ptr);

    FreeNode* n = static_cast<FreeNode*>(Node::From(ptr, debug_));

    if (debug_)
        std::memset(n->GetData(), 0xDD, n->Size);

    n->SetAllocated(false);

    Node* prev = n->GetPrev();
    Node* next = n->GetNext();

    if (prev && !prev->IsAllocated()) // Merge previous node, if free
    {
        Unlink(static_cast<FreeNode*>(prev));
        prev->Size = reinterpret_cast<usize>(next) - reinterpret_cast<usize>(prev) - sizeof(Node);
        n = static_cast<FreeNode*>(prev);

        if (next < GetHeapEnd())
            next->SetPrev(n);
    }

    if (next < GetHeapEnd() && !next->IsAllocated()) // Merge next node, if free
    {
        Unlink(static_cast<FreeNode*>(next));
        next = next->GetNext();
        n->Size = reinterpret_cast<usize>(next) - reinterpret_cast<usize>(n) - sizeof(Node);

        if (next < GetHeapEnd())
            next->SetPrev(n);
    }

    Link(n);

    Unlock();
}

void asMemoryAllocator::GetStats(asMemStats* stats)
{
    GetStats(stats, nullptr, nullptr);
}

void asMemoryAllocator::GetStats(struct asMemStats* stats, struct asMemSource* sources, usize* num_sources)
{
    Lock();

    usize max_sources = (debug_ && sources && num_sources) ? *num_sources : 0;
    usize cur_sources = 0;

    std::memset(stats, 0, sizeof(*stats));

    if (max_sources)
        std::memset(sources, 0, max_sources * sizeof(*sources));

    for (Node* n = GetFirstNode(); n != GetHeapEnd(); n = n->GetNext())
    {
        ++stats->nTotalNodes;

        u32 size = n->Size;
        u32 overhead = sizeof(Node);

        stats->cbOverhead += overhead;

        if (n->IsAllocated())
        {
            ++stats->nUsedNodes;
            stats->cbUsed += size;

            if (max_sources)
            {
                u32 source = n->GetAllocSource();

                asMemSource* sources_end = sources + cur_sources;

                asMemSource* find = std::lower_bound(sources, sources_end, source,
                    [](const asMemSource& source, u32 address) { return source.uSource < address; });

                if ((find == sources_end) || (find->uSource != source))
                {
                    if (cur_sources < max_sources)
                    {
                        std::memmove(find + 1, find, (sources_end - find) * sizeof(*find));
                        *find = {source};
                        ++cur_sources;
                    }
                    else
                    {
                        find = nullptr;
                    }
                }

                if (find)
                {
                    find->nNodes++;
                    find->cbUsed += size;
                    find->cbOverhead += overhead;
                }
            }
        }
        else
        {
            ++stats->nFreeNodes;
            stats->cbFree += size;
        }
    }

    ArAssert(stats->cbFree + stats->cbUsed + stats->cbOverhead == heap_size_, "Invalid Node Sizes");

    if (num_sources)
    {
        std::sort(sources, sources + cur_sources, [](const asMemSource& lhs, const asMemSource& rhs) {
            return (lhs.cbUsed + lhs.cbOverhead) > (rhs.cbUsed + rhs.cbOverhead);
        });

        *num_sources = cur_sources;
    }

    Unlock();
}

void asMemoryAllocator::Init(void* heap, usize heap_size, b32 use_nodes)
{
    ArAssert(!initialized_, "Allocator already initialized");
    ArAssert(use_nodes, "Linear allocator not supported");

    heap_ = heap;
    heap_size_ = heap_size;
    heap_used_ = heap_size;
    use_nodes_ = use_nodes;

#ifndef ARTS_FINAL
    alloc_id_ = 0;
#endif

    initialized_ = true;

    if (use_nodes)
    {
        std::memset(buckets_, 0, sizeof(buckets_));

        FreeNode* start = static_cast<FreeNode*>(heap_);
        start->Clear();
        start->Size = heap_size - sizeof(Node);
        start->SetPrev(nullptr);
        Link(start);

        Allocate(1, 1, nullptr);

        SanityCheck();
    }
}

void asMemoryAllocator::Kill()
{
    if (initialized_ && debug_)
        SanityCheck();

    heap_ = nullptr;
    initialized_ = false;
}

void* asMemoryAllocator::Reallocate(void* ptr, usize size)
{
    return Reallocate(ptr, size, nullptr);
}

void* asMemoryAllocator::Reallocate(void* ptr, usize size, void* caller)
{
    usize old_size = 0;

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

    void* new_ptr = Allocate(size, DefaultNewAlignment, caller);

    if (ptr && new_ptr)
    {
        std::memcpy(new_ptr, ptr, old_size);
        Free(ptr);
    }

    return new_ptr;
}

void asMemoryAllocator::SanityCheck()
{
    if (!initialized_)
        return;

    Lock();

    bool is_invalid = false;

    ARTS_EXCEPTION_BEGIN
    {
        is_invalid = DoSanityCheck();
    }
    ARTS_EXCEPTION_END
    {
        is_invalid = true;
    }

    if (is_invalid)
    {
#ifndef ARTS_FINAL
        usize alloc_id = alloc_id_;

        if (debug_)
        {
            Displayf("Last %zu allocations:", ARTS_SIZE(last_allocs_));

            for (usize i = 0; i < ARTS_SIZE(last_allocs_); ++i)
            {
                char address[128];
                LookupAddress(address, ARTS_SIZE(address), last_allocs_[(alloc_id - i - 1) % ARTS_SIZE(last_allocs_)]);
                Displayf("  %2zu: %s", i, address);
            }
        }

        Abortf("Memory Allocator Corrupted (allocid = %u)", alloc_id);
#else
        Abortf("Memory Allocator Corrupted");
#endif
    }

    Unlock();
}

void asMemoryAllocator::DumpStats()
{
    Lock();

    SanityCheck();

    asMemStats stats;
    asMemSource sources[1024];
    usize num_sources = ARTS_SIZE(sources);

    GetStats(&stats, sources, &num_sources);

    Warningf("** Allocator Stats **");

    Warningf("Heap Size: 0x%08X KB", GetHeapSize() >> 10);
    Warningf("Heap Used: 0x%08X KB", GetHeapUsed() >> 10);

    Warningf(" Alloc Used: 0x%08X KB", stats.cbUsed >> 10);
    Warningf(" Alloc Free: 0x%08X KB", stats.cbFree >> 10);
    Warningf("Alloc Waste: 0x%08X KB", stats.cbOverhead >> 10);

    Warningf("Total Nodes: %10u", stats.nTotalNodes);
    Warningf(" Used Nodes: %10u", stats.nUsedNodes);
    Warningf(" Free Nodes: %10u", stats.nFreeNodes);

    if (num_sources)
    {
        Warningf("** %u Alloc Sources **", num_sources);

        for (usize i = 0; i < num_sources; ++i)
        {
            const asMemSource& source = sources[i];

            char address_string[128];
            LookupAddress(address_string, ARTS_SIZE(address_string), source.uSource);

            Warningf("%-80s: Used: 0x%08X KB, Waste: 0x%08X KB", address_string, source.cbUsed, source.cbOverhead);
        }
    }

    Unlock();
}

usize asMemoryAllocator::SizeOf(void* ptr) const
{
    Node* n = Node::From(ptr, debug_);

    return debug_ ? n->GetUserSize() : n->Size;
}

void asMemoryAllocator::Link(FreeNode* n)
{
    heap_used_ -= n->Size + sizeof(Node);

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
    heap_used_ += n->Size + sizeof(Node);

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
    ArAssert(heap_ && heap_size_, "Heap not initialized");

    if (usize const lock_count = lock_count_)
    {
        lock_count_ = 0;
        Warningf("Memory allocated or freed while locked!");
        StackTraceback(16);
        lock_count_ = lock_count;
    }

    if (ptr)
    {
        ArAssert(ptr >= GetHeapStart(), "Pointer below heap");
        ArAssert(ptr < GetHeapEnd(), "Pointer above heap");

        if (use_nodes_)
        {
            Node* const n = Node::From(ptr, debug_);

            ArAssert(n->IsAllocated(), "Node not allocated");

            b32 is_invalid = false;

            u32 source = 0;

            if (debug_)
            {
                source = n->GetAllocSource();

                if (!n->CheckLowerGuard())
                    is_invalid |= HeapAssert(n->GetData(), "Lower Guard Word", source);

                if (!n->CheckUpperGuard())
                    is_invalid |= HeapAssert(n->GetData(), "Upper Guard Word", source);
            }

            if (Node* prev = n->GetPrev())
            {
                if (prev->GetNext() != n)
                    is_invalid |= HeapAssert(n, "Node->Prev->Next != Node", source);
            }
            else
            {
                if (n != GetHeapStart())
                    is_invalid |= HeapAssert(n, "Node->Prev == NULL, but Node != HeapBase", source);
            }

            if (Node* next = n->GetNext(); next != GetHeapEnd())
            {
                if (next->GetPrev() != n)
                    is_invalid |= HeapAssert(n, "Node->Next->Prev != Node", source);
            }

            if (is_invalid)
            {
                SanityCheck();

                Abortf("Memory Allocator Node Corrupt");
            }
        }
    }
}

asMemoryAllocator::FreeNode* asMemoryAllocator::FindFirstFit(usize size, usize align, usize offset)
{
    align -= 1;
    offset = -isize(offset + sizeof(Node));

    for (u32 i = GetBucketIndex(size); i < ARTS_SIZE32(buckets_); ++i)
    {
        for (FreeNode* n = buckets_[i]; n; n = n->NextFree)
        {
            if (n->Size >= size + ((offset - reinterpret_cast<usize>(n)) & align))
                return n;
        }
    }

    return nullptr;
}

asMemoryAllocator::Node* asMemoryAllocator::GetFirstNode() const
{
    return static_cast<Node*>(GetHeapStart());
}

void asMemoryAllocator::Lock() const
{
    lock_.lock();
}

void asMemoryAllocator::Unlock() const
{
    lock_.unlock();
}

bool asMemoryAllocator::DoSanityCheck() const
{
    Node* last = nullptr;
    usize total = 0;
    usize total_used = 0;
    usize errors = 0;

    for (Node *n = GetFirstNode(), *next = nullptr; n != GetHeapEnd(); last = n, n = next)
    {
        u32 source = (debug_ && n->IsAllocated()) ? n->GetAllocSource() : 0;

        next = n->GetNext();

        if (next <= n)
            errors += HeapAssert(n, "Node Direction", source);

        if (next > GetHeapEnd())
            errors += HeapAssert(n, "Node Size", source);

        if (n->GetPrev() != last)
            errors += HeapAssert(n, "Linked List", source);

        if (n->IsPendingSanity())
            errors += HeapAssert(n, "Pending Sanity Check", source);

        if (debug_ && n->IsAllocated())
        {
            if (!n->CheckLowerGuard())
                errors += HeapAssert(n, "Lower Guard Word", source);

            if (!n->CheckUpperGuard())
                errors += HeapAssert(n, "Upper Guard Word", source);
        }

        if (n->IsAllocated())
            ++total_used;
        else
            n->SetPendingSanity(true);

        ++total;

        if (errors > 20)
            return true;
    }

    if (last && (last->GetNext() != GetHeapEnd()))
        return true;

    usize total_free = 0;

    for (usize i = 0; i < ARTS_SIZE(buckets_); ++i)
    {
        for (FreeNode *n = buckets_[i], *prev = nullptr; n; prev = n, n = n->NextFree)
        {
            if (n->PrevFree != prev)
                errors += HeapAssert(n, "Invalid Prev Node");

            if (!n->IsPendingSanity())
                errors += HeapAssert(n, "Missing Sanity Check");

            n->SetPendingSanity(false);

            ++total_free;

            if (errors > 20)
                return true;
        }
    }

    for (Node* n = GetFirstNode(); n != GetHeapEnd(); n = n->GetNext())
    {
        if (n->IsPendingSanity())
            errors += HeapAssert(n, "Pending Sanity Check");

        if (errors > 20)
            return true;
    }

    if (total_used + total_free != total)
        return true;

    // Displayf("Sanity Checked %u nodes (%u used, %u free)", total, total_used, total_free);

    return errors != 0;
}

asMemoryAllocator ALLOCATOR;

asMemoryAllocator* StaticAllocator()
{
    static asMemoryAllocator* allocator = nullptr;

    if (allocator == nullptr)
    {
        alignas(asMemoryAllocator) static unsigned char storage[sizeof(asMemoryAllocator)];
        allocator = new (storage) asMemoryAllocator();

        alignas(64) static unsigned char heap[STATIC_HEAP_SIZE];
        allocator->Init(heap, sizeof(heap), true);
    }

    return allocator;
}

asMemoryAllocator* CURHEAP = StaticAllocator();

run_once([] {
    create_patch("CRTALLOCATOR", "Fix CRTALLOCATOR", 0x520970, "\xC3", 1);
    create_patch("CRTALLOCATOR", "Fix CRTALLOCATOR", 0x40185D, "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90", 10);
});
