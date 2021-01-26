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

define_dummy_symbol(data7_cache);

#include "cache.h"

#include "ipc.h"
#include "pager.h"

// Max age before an object is automatically unloaded
static u32 MaxObjectAge = 1000;

struct DataCacheObject
{
    u32 nAge {0};

    u8* pBase {nullptr};

    // Handle must be stored directly after a PagerInfo_t
    i32* pHandle {nullptr};

    u8 bUsed {0};
    u8 nLockCount {0};

    u32 nTotalSize {0};
    u32 nMaxSize {0};

    DataCacheCallback Relocate {nullptr};
    void* Context {nullptr};

    const char* GetName()
    {
        // return "unknown";

        return reinterpret_cast<PagerInfo_t*>(pHandle)[-1].Name;
    }
};

check_size(DataCacheObject, 0x20);

static inline constexpr usize AlignSize(usize value) noexcept
{
    return (value + 7) & ~usize(7); // FIXME: 64-bit requires 16-byte alignment
}

DataCache::DataCache() = default;

DataCache::~DataCache()
{
    Shutdown();
}

void DataCache::Age()
{
    cache_lock_.lock();
    object_lock_.lock();

    ++age_;

    if (object_locks_ != 0)
    {
        for (u32 i = 1; i <= cur_objects_; ++i)
        {
            if (DataCacheObject& dco = objects_[i]; dco.nLockCount != 0)
                Quitf("DataCache::Age - %s object still locked: %s", name_, dco.GetName());
        }

        Quitf("DataCache::Age - %s lock count is %u", name_, object_locks_);
    }

    for (u32 i = 1; i <= cur_objects_; ++i)
    {
        if (DataCacheObject& dco = objects_[i]; dco.bUsed && dco.nAge + MaxObjectAge < age_)
        {
            Unload(i);

            cur_waste_ += dco.nMaxSize;
            aged_bytes_ += dco.nMaxSize;
            ++aged_objects_;
        }
    }

    CleanEndOfHeap();

    if (fragmented_ || (cur_waste_ > max_waste_))
    {
        u32 i = 1;
        u32 j = 0;
        u8* heap = heap_;

        for (; i <= cur_objects_; ++i)
        {
            if (!objects_[i].bUsed)
                continue;

            DataCacheObject& dco = objects_[++j];

            if (i != j)
            {
                dco = objects_[i];
                *dco.pHandle = j;
            }

            Relocate(&dco, heap);
            heap += dco.nTotalSize;

            dco.nMaxSize = dco.nTotalSize;
        }

        cur_objects_ = j;

        while (++j < i)
        {
            DataCacheObject& dco = objects_[j];

            dco.bUsed = 0;
            dco.nTotalSize = 0;
            dco.pBase = 0;
        }

        fragmented_ = 0;
        cur_waste_ = 0;
        heap_used_ = static_cast<u32>(heap - heap_);
    }

    object_lock_.unlock();
    cache_lock_.unlock();
}

void* DataCache::Allocate(i32 handle, u32 size)
{
    if (size == 0)
        return nullptr;

    DataCacheObject& dco = GetObject(handle);

    ArAssert(dco.nLockCount, "Object Not Locked");

    size = AlignSize(size);

    ArAssert(dco.nTotalSize + size <= dco.nMaxSize, "Object Too Small");

    u8* ptr = dco.pBase + dco.nTotalSize;
    dco.nTotalSize += size;

    return ptr;
}

i32 DataCache::BeginObject(i32* handle_ptr, DataCacheCallback relocate, void* context, u32 maxsize)
{
    cache_lock_.lock();

    maxsize = AlignSize(maxsize);

    if ((cur_objects_ < max_objects_) && (maxsize + heap_used_ <= heap_size_))
    {
        ++cur_objects_;
        InitObject(cur_objects_, handle_ptr, relocate, context, heap_ + heap_used_, maxsize);
        heap_used_ += maxsize;
        return true;
    }

    i32 handle = 0;

    for (i32 i = 3; i >= 0; --i)
    {
        u32 max_age = age_;
        u32 max_size = AlignSize(maxsize + (maxsize >> i));

        for (u32 j = 1; j <= max_objects_; ++j)
        {
            DataCacheObject& dco = objects_[j];

            if ((dco.nLockCount == 0) && (dco.nMaxSize >= maxsize) && (dco.nMaxSize <= max_size) &&
                (dco.nAge < max_age))
            {
                handle = j;
                max_age = dco.nAge;
            }
        }

        if (handle)
            break;
    }

    if (handle == 0)
    {
        u32 objects = 0, bytes = 0, waste = 0;
        GetStatus(objects, bytes, waste);

        Errorf("DataCache::BeginObject - %s probably too fragmented: OBJ:%d MEM:%d WASTE:%d", name_, objects, bytes,
            waste);
        fragmented_ = true;

        cache_lock_.unlock();

        return false;
    }

    DataCacheObject& dco = objects_[handle];

    cur_waste_ += dco.nMaxSize - maxsize;

    if (dco.bUsed)
        Unload(handle);

    InitObject(handle, handle_ptr, relocate, context, dco.pBase, dco.nMaxSize);

    return true;
}

void DataCache::EndObject(i32 handle)
{
    DataCacheObject& dco = GetObject(handle);

    dco.nLockCount = 0;

    if (--object_locks_ == 0)
        object_lock_.unlock();

    cache_lock_.unlock();
}

void DataCache::Flush()
{
    cache_lock_.lock();
    object_lock_.lock();

    for (u32 i = 1; i <= cur_objects_; ++i)
    {
        DataCacheObject& dco = objects_[i];

        if (dco.bUsed)
            Unload(i);

        dco.pBase = nullptr;
    }

    heap_used_ = 0;

    object_lock_.unlock();
    cache_lock_.unlock();
}

void DataCache::GetStatus(u32& objects, u32& bytes, u32& waste)
{
    objects = 100 * cur_objects_ / max_objects_;
    bytes = 100 * heap_used_ / heap_size_;
    waste = 100 * cur_waste_ / max_waste_;
}

static mem::cmd_param PARAM_cacheage {"cacheage"};

void DataCache::Init(u32 heap_size, i32 handle_count, const char* name)
{
    MaxObjectAge = PARAM_cacheage.get_or<u32>(1000);

    aged_objects_ = 0;
    aged_bytes_ = 0;

    objects_ = new DataCacheObject[handle_count];
    --objects_;

    max_objects_ = handle_count;
    cur_objects_ = 0;

    cur_waste_ = 0;
    max_waste_ = heap_size >> 2;

    fragmented_ = false;

    heap_ = new u8[heap_size];
    heap_size_ = heap_size;
    heap_used_ = 0;

    age_ = 0;
    object_locks_ = 0;

    cache_lock_.init();
    object_lock_.init();

    name_ = name;
}

b32 DataCache::Lock(i32* handle)
{
    ArAssert(*handle != 0, "Invalid Handle");

    if (*handle == -1)
    {
        return false;
    }

    cache_lock_.lock();

    DataCacheObject& dco = GetObject(*handle);

    if (object_locks_++ == 0)
        object_lock_.lock();

    ++dco.nLockCount;
    dco.nAge = age_;

    cache_lock_.unlock();

    return true;
}

void DataCache::Shutdown()
{
    Flush();

    ++objects_;
    delete[] objects_;
    objects_ = nullptr;

    delete[] heap_;
    heap_ = nullptr;

    cache_lock_.close();
    object_lock_.close();
}

void DataCache::Unlock(i32 handle)
{
    cache_lock_.lock();

    DataCacheObject& dco = GetObject(handle);

    --dco.nLockCount;

    if (--object_locks_ == 0)
        object_lock_.unlock();

    cache_lock_.unlock();
}

void DataCache::UnlockAndFree(i32 handle)
{
    cache_lock_.lock();

    DataCacheObject& dco = GetObject(handle);

    --dco.nLockCount;

    if (--object_locks_ == 0)
        object_lock_.unlock();

    cur_waste_ += dco.nMaxSize;

    Unload(handle);
    CleanEndOfHeap();

    cache_lock_.unlock();
}

void DataCache::Free(i32 handle)
{
    cache_lock_.lock();

    Unload(handle);

    cache_lock_.unlock();
}

void DataCache::CleanEndOfHeap()
{
    for (; cur_objects_; --cur_objects_)
    {
        DataCacheObject& dco = objects_[cur_objects_];

        if (dco.bUsed)
            break;

        u32 size = dco.nMaxSize;

        ArAssert(dco.pBase + size == heap_ + heap_used_, "Object Corrupt");

        cur_waste_ -= size;
        heap_used_ -= size;
    }
}

void DataCache::InitObject(
    i32 handle, i32* handle_ptr, DataCacheCallback relocate, void* context, u8* data, u32 maxsize)
{
    DataCacheObject& dco = GetObject(handle);

    dco.nLockCount = 1;
    dco.pBase = data;
    *handle_ptr = handle;

    ArAssert(!dco.bUsed, "Object In Use");
    ArAssert(dco.nTotalSize == 0, "Object Not Empty");

    dco.pHandle = handle_ptr;
    dco.bUsed = 1;

    dco.Relocate = relocate;
    dco.Context = context;
    dco.nAge = age_;

    ArAssert(maxsize, "Object Cannot Be Empty");

    dco.nMaxSize = maxsize;

    if (object_locks_++ == 0)
        object_lock_.lock();
}

void DataCache::Relocate(DataCacheObject* dco, u8* ptr)
{
    if (isize delta = ptr - dco->pBase)
    {
        dco->Relocate(dco->Context, delta);
        std::memmove(ptr, dco->pBase, dco->nTotalSize);
        dco->pBase = ptr;
    }
}

void DataCache::Unload(i32 handle)
{
    DataCacheObject& dco = GetObject(handle);

    if (dco.nLockCount)
        Quitf("DataCache(%s)::Unload - locked object '%s'", name_, dco.GetName());

    if (dco.pHandle == nullptr)
        Quitf("DataCache(%s)::Unload - Already unloaded handle %d", name_, handle);

    ArAssert(dco.nLockCount == 0, "Object Locked");
    ArAssert(dco.bUsed, "Object Unused");

    if (dco.Relocate)
    {
        dco.Relocate(dco.Context, 0);
        dco.Relocate = nullptr;
    }

    dco.bUsed = false;
    dco.nAge = 0;
    dco.nTotalSize = 0;
    *dco.pHandle = 0;
    dco.pHandle = nullptr;
}

inline DataCacheObject& DataCache::GetObject(i32 handle)
{
    ArAssert(handle > 0, "Invalid Handle");

    return objects_[handle];
}
