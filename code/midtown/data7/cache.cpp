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
static constexpr u32 MaxObjectAge = 300;

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

static inline constexpr u32 AlignSize(u32 value) noexcept
{
    return (value + 7) & 0xFFFFFFF8;
}

DataCache::DataCache()
{
    export_hook(0x576FC0);
}

void DataCache::Age()
{
    export_hook(0x577750);

    ipcWaitSingle(write_mutex_);

    ++age_;

    if (lock_count_ != 0)
    {
        for (i32 i = 1; i <= cur_objects_; ++i)
        {
            if (DataCacheObject& dco = objects_[i]; dco.nLockCount != 0)
                Quitf("DataCache::Age - Object still locked: %s", dco.GetName());
        }
    }

    for (i32 i = 1; i <= cur_objects_; ++i)
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
        i32 i = 1;
        i32 j = 0;
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

            Relocate(dco, heap);
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
        heap_used_ = heap - heap_;
    }

    ipcReleaseMutex(write_mutex_);
}

void* DataCache::Allocate(i32 handle, u32 size)
{
    export_hook(0x577920);

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
    export_hook(0x577410);

    ipcWaitSingle(write_mutex_);

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

        for (i32 j = 1; j <= max_objects_; ++j)
        {
            DataCacheObject& dco = objects_[i];

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

        ipcReleaseMutex(write_mutex_);

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
    export_hook(0x577690);

    DataCacheObject& dco = GetObject(handle);

    dco.nLockCount = 0;

    if (--lock_count_ == 0)
        ipcReleaseMutex(read_mutex_);

    ipcReleaseMutex(write_mutex_);
}

void DataCache::Flush()
{
    export_hook(0x5776D0);

    ipcWaitSingle(write_mutex_);
    ipcWaitSingle(read_mutex_);

    for (i32 i = 1; i <= cur_objects_; ++i)
    {
        DataCacheObject& dco = objects_[i];

        if (dco.bUsed)
            Unload(i);

        dco.pBase = nullptr;
    }

    heap_used_ = 0;

    ipcReleaseMutex(read_mutex_);
    ipcReleaseMutex(write_mutex_);
}

void DataCache::GetStatus(u32& objects, u32& bytes, u32& waste)
{
    export_hook(0x5779D0);

    objects = 100 * cur_objects_ / max_objects_;
    bytes = 100 * heap_used_ / heap_size_;
    waste = 100 * cur_waste_ / max_waste_;
}

void DataCache::Init(u32 heap_size, i32 handle_count, const char* name)
{
    export_hook(0x576FD0);

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
    lock_count_ = 0;

    write_mutex_ = ipcCreateMutex(0);
    read_mutex_ = ipcCreateMutex(0);

    name_ = name;
}

b32 DataCache::Lock(i32* handle)
{
    export_hook(0x5771F0);

    ArAssert(*handle != 0, "Invalid Handle");

    ipcWaitSingle(write_mutex_);

    if (*handle == -1)
    {
        ipcReleaseMutex(write_mutex_);
        return false;
    }

    DataCacheObject& dco = GetObject(*handle);

    ++dco.nLockCount;

    if (lock_count_++ == 0)
        ipcWaitSingle(read_mutex_);

    dco.nAge = age_;

    ipcReleaseMutex(write_mutex_);

    return true;
}

void DataCache::Shutdown()
{
    export_hook(0x577070);

    ipcWaitSingle(write_mutex_);
    ipcWaitSingle(read_mutex_);

    Flush();

    ipcCloseHandle(write_mutex_);
    ipcCloseHandle(read_mutex_);
}

void DataCache::Unlock(i32 handle)
{
    export_hook(0x577290);

    ipcWaitSingle(write_mutex_);

    DataCacheObject& dco = GetObject(handle);

    --dco.nLockCount;

    if (--lock_count_ == 0)
        ipcReleaseMutex(read_mutex_);

    ipcReleaseMutex(write_mutex_);
}

void DataCache::UnlockAndFree(i32 handle)
{
    export_hook(0x577300);

    ipcWaitSingle(write_mutex_);

    DataCacheObject& dco = GetObject(handle);

    --dco.nLockCount;

    if (--lock_count_ == 0)
        ipcReleaseMutex(read_mutex_);

    cur_waste_ += dco.nMaxSize;

    Unload(handle);
    CleanEndOfHeap();
    ipcReleaseMutex(write_mutex_);
}

void DataCache::CleanEndOfHeap()
{
    export_hook(0x5773A0);

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
    export_hook(0x5775C0);

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

    if (lock_count_++ == 0)
        ipcWaitSingle(read_mutex_);
}

void DataCache::Relocate(DataCacheObject& dco, u8* ptr)
{
    export_hook(0x5771A0);

    if (i32 delta = ptr - dco.pBase)
    {
        dco.Relocate(dco.Context, delta);
        std::memcpy(ptr, dco.pBase, dco.nTotalSize);
        dco.pBase = ptr;
    }
}

void DataCache::Unload(i32 handle)
{
    export_hook(0x5770B0);

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
