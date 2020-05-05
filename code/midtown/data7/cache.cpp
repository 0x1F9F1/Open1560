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

DataCache::DataCache()
{
    unimplemented();
}

void DataCache::Age()
{
    return stub<thiscall_t<void, DataCache*>>(0x177750_Offset, this);
}

void* DataCache::Allocate(i32 arg1, u32 arg2)
{
    return stub<thiscall_t<void*, DataCache*, i32, u32>>(0x177920_Offset, this, arg1, arg2);
}

i32 DataCache::BeginObject(i32* arg1, void (*arg2)(void*, i32), void* arg3, u32 arg4)
{
    return stub<thiscall_t<i32, DataCache*, i32*, void (*)(void*, i32), void*, u32>>(
        0x177410_Offset, this, arg1, arg2, arg3, arg4);
}

void DataCache::EndObject(i32 arg1)
{
    return stub<thiscall_t<void, DataCache*, i32>>(0x177690_Offset, this, arg1);
}

void DataCache::Flush()
{
    return stub<thiscall_t<void, DataCache*>>(0x1776D0_Offset, this);
}

void DataCache::GetStatus(u32& arg1, u32& arg2, u32& arg3)
{
    return stub<thiscall_t<void, DataCache*, u32&, u32&, u32&>>(0x1779D0_Offset, this, arg1, arg2, arg3);
}

void DataCache::Init(u32 arg1, i32 arg2, char* arg3)
{
    return stub<thiscall_t<void, DataCache*, u32, i32, char*>>(0x176FD0_Offset, this, arg1, arg2, arg3);
}

i32 DataCache::Lock(i32* arg1)
{
    return stub<thiscall_t<i32, DataCache*, i32*>>(0x1771F0_Offset, this, arg1);
}

void DataCache::Shutdown()
{
    return stub<thiscall_t<void, DataCache*>>(0x177070_Offset, this);
}

void DataCache::Unlock(i32 arg1)
{
    return stub<thiscall_t<void, DataCache*, i32>>(0x177290_Offset, this, arg1);
}

void DataCache::UnlockAndFree(i32 arg1)
{
    return stub<thiscall_t<void, DataCache*, i32>>(0x177300_Offset, this, arg1);
}

void DataCache::CleanEndOfHeap()
{
    return stub<thiscall_t<void, DataCache*>>(0x1773A0_Offset, this);
}

void DataCache::InitObject(i32 arg1, i32* arg2, void (*arg3)(void*, i32), void* arg4, u8* arg5, u32 arg6)
{
    return stub<thiscall_t<void, DataCache*, i32, i32*, void (*)(void*, i32), void*, u8*, u32>>(
        0x1775C0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void DataCache::Relocate(struct DataCacheObject* arg1, u8* arg2)
{
    return stub<thiscall_t<void, DataCache*, struct DataCacheObject*, u8*>>(0x1771A0_Offset, this, arg1, arg2);
}

void DataCache::Unload(i32 arg1)
{
    return stub<thiscall_t<void, DataCache*, i32>>(0x1770B0_Offset, this, arg1);
}
