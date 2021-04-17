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
    data7:cache

    0x576FC0 | public: __thiscall DataCache::DataCache(void) | ??0DataCache@@QAE@XZ
    0x576FD0 | public: void __thiscall DataCache::Init(unsigned int,int,char *) | ?Init@DataCache@@QAEXIHPAD@Z
    0x577070 | public: void __thiscall DataCache::Shutdown(void) | ?Shutdown@DataCache@@QAEXXZ
    0x5770B0 | private: void __thiscall DataCache::Unload(int) | ?Unload@DataCache@@AAEXH@Z
    0x5771A0 | private: void __thiscall DataCache::Relocate(struct DataCacheObject *,unsigned char *) | ?Relocate@DataCache@@AAEXPAUDataCacheObject@@PAE@Z
    0x5771F0 | public: int __thiscall DataCache::Lock(int *) | ?Lock@DataCache@@QAEHPAH@Z
    0x577290 | public: void __thiscall DataCache::Unlock(int) | ?Unlock@DataCache@@QAEXH@Z
    0x577300 | public: void __thiscall DataCache::UnlockAndFree(int) | ?UnlockAndFree@DataCache@@QAEXH@Z
    0x5773A0 | private: void __thiscall DataCache::CleanEndOfHeap(void) | ?CleanEndOfHeap@DataCache@@AAEXXZ
    0x577410 | public: int __thiscall DataCache::BeginObject(int *,void (__cdecl*)(void *,int),void *,unsigned int) | ?BeginObject@DataCache@@QAEHPAHP6AXPAXH@Z1I@Z
    0x5775C0 | private: void __thiscall DataCache::InitObject(int,int *,void (__cdecl*)(void *,int),void *,unsigned char *,unsigned int) | ?InitObject@DataCache@@AAEXHPAHP6AXPAXH@Z1PAEI@Z
    0x577690 | public: void __thiscall DataCache::EndObject(int) | ?EndObject@DataCache@@QAEXH@Z
    0x5776D0 | public: void __thiscall DataCache::Flush(void) | ?Flush@DataCache@@QAEXXZ
    0x577750 | public: void __thiscall DataCache::Age(void) | ?Age@DataCache@@QAEXXZ
    0x577920 | public: void * __thiscall DataCache::Allocate(int,unsigned int) | ?Allocate@DataCache@@QAEPAXHI@Z
    0x5779D0 | public: void __thiscall DataCache::GetStatus(unsigned int &,unsigned int &,unsigned int &) | ?GetStatus@DataCache@@QAEXAAI00@Z
    0x90A9B0 | class DataCache CACHE | ?CACHE@@3VDataCache@@A
*/

#include "mutex.h"

using DataCacheCallback = void (*)(void* ctx, isize delta);

struct DataCacheObject;

class DataCache
{
public:
    // 0x576FC0 | ??0DataCache@@QAE@XZ
    ARTS_EXPORT DataCache();

    ~DataCache();

    ARTS_NON_COPYABLE(DataCache);

    // 0x577750 | ?Age@DataCache@@QAEXXZ
    ARTS_EXPORT void Age();

    // 0x577920 | ?Allocate@DataCache@@QAEPAXHI@Z
    ARTS_EXPORT void* Allocate(i32 handle, u32 size);

    // 0x577410 | ?BeginObject@DataCache@@QAEHPAHP6AXPAXH@Z1I@Z
    ARTS_EXPORT i32 BeginObject(i32* handle_ptr, DataCacheCallback relocate, void* context, u32 maxsize);

    // 0x577690 | ?EndObject@DataCache@@QAEXH@Z
    ARTS_EXPORT void EndObject(i32 handle);

    // 0x5776D0 | ?Flush@DataCache@@QAEXXZ
    ARTS_EXPORT void Flush();

    // 0x5779D0 | ?GetStatus@DataCache@@QAEXAAI00@Z
    ARTS_EXPORT void GetStatus(u32& objects, u32& bytes, u32& waste);

    // 0x576FD0 | ?Init@DataCache@@QAEXIHPAD@Z
    ARTS_EXPORT void Init(u32 heap_size, i32 handle_count, const char* name);

    // 0x5771F0 | ?Lock@DataCache@@QAEHPAH@Z
    ARTS_EXPORT b32 Lock(i32* handle);

    // 0x577070 | ?Shutdown@DataCache@@QAEXXZ | unused
    ARTS_EXPORT void Shutdown();

    // 0x577290 | ?Unlock@DataCache@@QAEXH@Z
    ARTS_EXPORT void Unlock(i32 handle);

    // 0x577300 | ?UnlockAndFree@DataCache@@QAEXH@Z
    ARTS_EXPORT void UnlockAndFree(i32 handle);

    void Free(i32 handle);

private:
    // 0x5773A0 | ?CleanEndOfHeap@DataCache@@AAEXXZ
    ARTS_EXPORT void CleanEndOfHeap();

    // 0x5775C0 | ?InitObject@DataCache@@AAEXHPAHP6AXPAXH@Z1PAEI@Z
    ARTS_EXPORT void InitObject(
        i32 handle, i32* handle_ptr, DataCacheCallback relocate, void* context, u8* data, u32 maxsize);

    // 0x5771A0 | ?Relocate@DataCache@@AAEXPAUDataCacheObject@@PAE@Z
    ARTS_EXPORT void Relocate(DataCacheObject* dco, u8* ptr);

    // 0x5770B0 | ?Unload@DataCache@@AAEXH@Z
    ARTS_EXPORT void Unload(i32 handle);

    DataCacheObject& GetObject(i32 handle);

    u32 aged_objects_ {0};
    u32 aged_bytes_ {0};

    // Must always be indexed by > 0
    DataCacheObject* objects_ {nullptr}; // pObjects

    u32 max_objects_ {0};
    u32 cur_objects_ {0}; // nMaxHandles

    u32 cur_waste_ {0};
    u32 max_waste_ {0};

    b32 fragmented_ {false};

    u8* heap_ {nullptr}; // pHeap
    u32 heap_size_ {0};
    u32 heap_used_ {0}; // nTotalAllocated

    u32 age_ {0};

    u32 object_locks_ {0};

    CriticalSection cache_lock_ {};
    CriticalSection object_lock_ {};

    const char* name_ {nullptr};
};

check_size(DataCache, 0x40);

// 0x90A9B0 | ?CACHE@@3VDataCache@@A
ARTS_IMPORT extern class DataCache CACHE;

template <typename T>
inline void PointerFixup(T*& ptr, isize delta)
{
    if (ptr)
        ptr = delta ? reinterpret_cast<T*>(reinterpret_cast<u8*>(ptr) + delta) : nullptr;
}