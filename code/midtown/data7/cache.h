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

class DataCache
{
public:
    // 0x576FC0 | ??0DataCache@@QAE@XZ
    DataCache();

    // 0x577750 | ?Age@DataCache@@QAEXXZ
    void Age();

    // 0x577920 | ?Allocate@DataCache@@QAEPAXHI@Z
    void* Allocate(i32 arg1, u32 arg2);

    // 0x577410 | ?BeginObject@DataCache@@QAEHPAHP6AXPAXH@Z1I@Z
    i32 BeginObject(i32* arg1, void (*arg2)(void*, i32), void* arg3, u32 arg4);

    // 0x577690 | ?EndObject@DataCache@@QAEXH@Z
    void EndObject(i32 arg1);

    // 0x5776D0 | ?Flush@DataCache@@QAEXXZ
    void Flush();

    // 0x5779D0 | ?GetStatus@DataCache@@QAEXAAI00@Z
    void GetStatus(u32& arg1, u32& arg2, u32& arg3);

    // 0x576FD0 | ?Init@DataCache@@QAEXIHPAD@Z
    void Init(u32 arg1, i32 arg2, char* arg3);

    // 0x5771F0 | ?Lock@DataCache@@QAEHPAH@Z
    i32 Lock(i32* arg1);

    // 0x577070 | ?Shutdown@DataCache@@QAEXXZ
    void Shutdown();

    // 0x577290 | ?Unlock@DataCache@@QAEXH@Z
    void Unlock(i32 arg1);

    // 0x577300 | ?UnlockAndFree@DataCache@@QAEXH@Z
    void UnlockAndFree(i32 arg1);

private:
    // 0x5773A0 | ?CleanEndOfHeap@DataCache@@AAEXXZ
    void CleanEndOfHeap();

    // 0x5775C0 | ?InitObject@DataCache@@AAEXHPAHP6AXPAXH@Z1PAEI@Z
    void InitObject(i32 arg1, i32* arg2, void (*arg3)(void*, i32), void* arg4, u8* arg5, u32 arg6);

    // 0x5771A0 | ?Relocate@DataCache@@AAEXPAUDataCacheObject@@PAE@Z
    void Relocate(struct DataCacheObject* arg1, u8* arg2);

    // 0x5770B0 | ?Unload@DataCache@@AAEXH@Z
    void Unload(i32 arg1);
};

check_size(DataCache, 0x0);

// 0x90A9B0 | ?CACHE@@3VDataCache@@A
inline extern_var(0x90A9B0, class DataCache, CACHE);
