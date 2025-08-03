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

#include "mutex.h"

using DataCacheCallback = void (*)(void* ctx, isize delta);

struct DataCacheObject;

class DataCache
{
public:
    // ??0DataCache@@QAE@XZ
    ARTS_EXPORT DataCache();

    ~DataCache();

    ARTS_NON_COPYABLE(DataCache);

    // ?Age@DataCache@@QAEXXZ
    void Age();

    // ?Allocate@DataCache@@QAEPAXHI@Z
    ARTS_EXPORT void* Allocate(i32 handle, u32 size);

    // ?BeginObject@DataCache@@QAEHPAHP6AXPAXH@Z1I@Z
    ARTS_EXPORT i32 BeginObject(i32* handle_ptr, DataCacheCallback relocate, void* context, u32 maxsize);

    // ?EndObject@DataCache@@QAEXH@Z
    ARTS_EXPORT void EndObject(i32 handle);

    // ?Flush@DataCache@@QAEXXZ
    void Flush();

    // ?GetStatus@DataCache@@QAEXAAI00@Z
    void GetStatus(u32& objects, u32& bytes, u32& waste);

    // ?Init@DataCache@@QAEXIHPAD@Z
    void Init(u32 heap_size, i32 handle_count, const char* name);

    // ?Lock@DataCache@@QAEHPAH@Z
    ARTS_EXPORT b32 Lock(i32* handle);

    // ?Shutdown@DataCache@@QAEXXZ
    void Shutdown();

    // ?Unlock@DataCache@@QAEXH@Z
    ARTS_EXPORT void Unlock(i32 handle);

    // ?UnlockAndFree@DataCache@@QAEXH@Z
    void UnlockAndFree(i32 handle);

    void Free(i32 handle);

    u32 GetEvictedObjects() const
    {
        return evicted_objects_;
    }

    u32 GetEvictedBytes() const
    {
        return evicted_bytes_;
    }

    void ResetEvictionCounter()
    {
        evicted_objects_ = 0;
        evicted_bytes_ = 0;
    }

private:
    // ?CleanEndOfHeap@DataCache@@AAEXXZ
    void CleanEndOfHeap();

    // ?InitObject@DataCache@@AAEXHPAHP6AXPAXH@Z1PAEI@Z
    void InitObject(
        i32 handle, i32* handle_ptr, DataCacheCallback relocate, void* context, u8* data, u32 maxsize);

    // ?Relocate@DataCache@@AAEXPAUDataCacheObject@@PAE@Z
    void Relocate(DataCacheObject* dco, u8* ptr);

    // ?Unload@DataCache@@AAEXH@Z
    void Unload(i32 handle);

    DataCacheObject& GetObject(i32 handle);

    u32 evicted_objects_ {};
    u32 evicted_bytes_ {};

    // Must always be indexed by > 0
    DataCacheObject* objects_ {}; // pObjects

    u32 max_objects_ {};
    u32 cur_objects_ {}; // nMaxHandles

    u32 cur_waste_ {};
    u32 max_waste_ {};

    b32 fragmented_ {};

    u8* heap_ {}; // pHeap
    u32 heap_size_ {};
    u32 heap_used_ {}; // nTotalAllocated

    u32 age_ {};

    u32 object_locks_ {};

    Mutex cache_lock_ {};
    Mutex object_lock_ {};

    const char* name_ {};
};

check_size(DataCache, 0x40);

// ?CACHE@@3VDataCache@@A
ARTS_EXPORT extern DataCache CACHE;

template <typename T>
inline void PointerFixup(T*& ptr, isize delta)
{
    if (delta)
        ptr = ptr ? reinterpret_cast<T*>(reinterpret_cast<u8*>(ptr) + delta) : nullptr;
    else
        ptr = nullptr;
}
