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
    0x7805E8 | class asMemoryAllocator ALLOCATOR | ?ALLOCATOR@@3VasMemoryAllocator@@A
    0x780688 | class asMemoryAllocator * CURHEAP | ?CURHEAP@@3PAVasMemoryAllocator@@A
    0x780690 | class asMemoryAllocator CRTALLOCATOR | ?CRTALLOCATOR@@3VasMemoryAllocator@@A
    0x780730 | unsigned char * CRTHEAP | ?CRTHEAP@@3PAEA
    0x521250 | int __cdecl HeapAssert(void *,int,char *,int) | ?HeapAssert@@YAHPAXHPADH@Z
*/

struct asMemStats
{
    u32 nTotalNodes {0};
    u32 nFreeNodes {0};
    u32 nUsedNodes {0};

    u32 cbOverhead {0};
    u32 cbFree {0};
    u32 cbUsed {0};
};

check_size(asMemStats, 0x18);

class asMemoryAllocator
{
public:
    // 0x5209B0 | ??0asMemoryAllocator@@QAE@XZ
    asMemoryAllocator();

    // 0x5209C0 | ??1asMemoryAllocator@@QAE@XZ
    ~asMemoryAllocator();

    // 0x520A20 | ?Allocate@asMemoryAllocator@@QAEPAXI@Z
    void* Allocate(u32 arg1);

    // 0x520C40 | ?CheckPointer@asMemoryAllocator@@QAEXPAX@Z
    void CheckPointer(void* ptr);

    // 0x520C90 | ?Free@asMemoryAllocator@@QAEXPAX@Z
    void Free(void* ptr);

    // 0x520FC0 | ?GetStats@asMemoryAllocator@@QAEXPAUasMemStats@@@Z
    void GetStats(struct asMemStats* stats);

    // 0x5209D0 | ?Init@asMemoryAllocator@@QAEXPAXIH@Z
    void Init(void* heap, u32 heap_size, b32 use_nodes);

    // 0x520A10 | ?Kill@asMemoryAllocator@@QAEXXZ
    void Kill();

    // 0x520EA0 | ?Reallocate@asMemoryAllocator@@QAEPAXPAXI@Z
    void* Reallocate(void* ptr, u32 size);

    // 0x521090 | ?SanityCheck@asMemoryAllocator@@QAEXXZ
    void SanityCheck();

    usize SizeOf(void* ptr);

private:
    struct Node;
    struct FreeNode;

    // 0x520E50 | ?Link@asMemoryAllocator@@AAEXPAUnode@1@@Z
    void Link(FreeNode* n);

    // 0x520DF0 | ?Unlink@asMemoryAllocator@@AAEXPAUnode@1@@Z
    void Unlink(FreeNode* n);

    // 0x520F00 | ?Verify@asMemoryAllocator@@AAEXPAX@Z
    void Verify(void* ptr);

    b32 initialized_ {false};
    b32 debug_ {false};
    u8* heap_ {nullptr};
    u32 heap_size_ {0};
    u32 heap_offset_ {0};
    u32 lock_count_ {0};
    b32 use_nodes_ {false};
    FreeNode* buckets_[32] {};
    Node* last_ {nullptr};
};

check_size(asMemoryAllocator, 0xA0);

// 0x7805E8 | ?ALLOCATOR@@3VasMemoryAllocator@@A
inline extern_var(0x7805E8, class asMemoryAllocator, ALLOCATOR);

// 0x780690 | ?CRTALLOCATOR@@3VasMemoryAllocator@@A
inline extern_var(0x780690, class asMemoryAllocator, CRTALLOCATOR);

// 0x780730 | ?CRTHEAP@@3PAEA
inline extern_var(0x780730, u8*, CRTHEAP);

// 0x780688 | ?CURHEAP@@3PAVasMemoryAllocator@@A
inline extern_var(0x780688, class asMemoryAllocator*, CURHEAP);
