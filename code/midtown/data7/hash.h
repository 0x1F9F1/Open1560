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
    data7:hash

    0x578040 | public: void __thiscall HashIterator::Begin(void) | ?Begin@HashIterator@@QAEXXZ
    0x578050 | public: int __thiscall HashIterator::Next(void) | ?Next@HashIterator@@QAEHXZ
    0x5780A0 | public: void __thiscall HashTable::Init(int) | ?Init@HashTable@@QAEXH@Z
    0x578110 | public: void __thiscall HashTable::Kill(void) | ?Kill@HashTable@@QAEXXZ
    0x578180 | public: void __thiscall HashTable::operator=(class HashTable &) | ??4HashTable@@QAEXAAV0@@Z
    0x5781D0 | public: int __thiscall HashTable::Insert(char *,void *) | ?Insert@HashTable@@QAEHPADPAX@Z
    0x5782B0 | public: int __thiscall HashTable::Delete(char *) | ?Delete@HashTable@@QAEHPAD@Z
    0x5783F0 | public: int __thiscall HashTable::Change(char *,char *) | ?Change@HashTable@@QAEHPAD0@Z
    0x578430 | public: void * __thiscall HashTable::Access(char *) | ?Access@HashTable@@QAEPAXPAD@Z
    0x5784C0 | private: int __thiscall HashTable::Hash(char *) | ?Hash@HashTable@@AAEHPAD@Z
    0x578500 | private: int __thiscall HashTable::ComputePrime(int) | ?ComputePrime@HashTable@@AAEHH@Z
    0x578550 | private: void __thiscall HashTable::Recompute(int) | ?Recompute@HashTable@@AAEXH@Z
    0x578610 | public: static void __cdecl HashTable::KillAll(void) | ?KillAll@HashTable@@SAXXZ
    0x578630 | private: void __thiscall HashTable::RemoveMe(void) | ?RemoveMe@HashTable@@AAEXXZ
    0x90AE5C | private: static class HashTable * HashTable::First | ?First@HashTable@@0PAV1@A
*/

struct HashEntry
{
    CString Key {nullptr};
    void* Value {nullptr};
    HashEntry* Next {nullptr};
};

check_size(HashEntry, 0xC);

class HashTable
{
public:
    // 0x498950 | ??1HashTable@@QAE@XZ | inline
    ARTS_EXPORT ~HashTable();

    // 0x578180 | ??4HashTable@@QAEXAAV0@@Z | unused
    ARTS_EXPORT void operator=(class HashTable& other);

    // 0x578430 | ?Access@HashTable@@QAEPAXPAD@Z
    ARTS_EXPORT void* Access(const char* key);

    // 0x5783F0 | ?Change@HashTable@@QAEHPAD0@Z | unused
    ARTS_EXPORT b32 Change(const char* old_key, const char* new_key);

    // 0x5782B0 | ?Delete@HashTable@@QAEHPAD@Z
    ARTS_EXPORT i32 Delete(const char* key);

    // 0x5780A0 | ?Init@HashTable@@QAEXH@Z
    ARTS_EXPORT void Init(i32 bucket_count);

    // 0x5781D0 | ?Insert@HashTable@@QAEHPADPAX@Z
    i32 Insert(char* arg1, void* arg2);

    // 0x578110 | ?Kill@HashTable@@QAEXXZ
    void Kill();

    // 0x578610 | ?KillAll@HashTable@@SAXXZ
    static void KillAll();

private:
    // 0x578500 | ?ComputePrime@HashTable@@AAEHH@Z
    i32 ComputePrime(i32 arg1);

    // 0x5784C0 | ?Hash@HashTable@@AAEHPAD@Z
    ARTS_EXPORT u32 Hash(const char* key);

    // 0x578550 | ?Recompute@HashTable@@AAEXH@Z
    void Recompute(i32 arg1);

    // 0x578630 | ?RemoveMe@HashTable@@AAEXXZ
    void RemoveMe();

    // 0x90AE5C | ?First@HashTable@@0PAV1@A
    static inline extern_var(0x90AE5C, class HashTable*, First);

    i32 bucket_count_ {0};
    i32 value_count_ {0};
    Ptr<HashEntry* []> buckets_ { nullptr };
    HashTable* next_table_ {nullptr};
};

check_size(HashTable, 0x10);

struct HashIterator
{
public:
    // 0x578040 | ?Begin@HashIterator@@QAEXXZ
    void Begin();

    // 0x578050 | ?Next@HashIterator@@QAEHXZ
    i32 Next();

    HashTable* Table {nullptr};
    i32 Index {0};
    HashEntry* Current {nullptr};
};

check_size(HashIterator, 0xC);
