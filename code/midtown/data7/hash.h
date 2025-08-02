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

struct HashEntry
{
    ConstString Key;
    void* Value {};
    HashEntry* Next {};
};

check_size(HashEntry, 0xC);

class HashTable
{
public:
    HashTable(const char* name)
        : HashTable(0, name)
    {}

    // TODO: Store name
    HashTable(i32 max_entries, [[maybe_unused]] const char* name)
        : bucket_count_(max_entries)
    {
        next_table_ = First;
        First = this;
    }

    // ??1HashTable@@QAE@XZ | inline
    ARTS_EXPORT ~HashTable()
    {
        Kill();
        RemoveMe();
    }

    // ??4HashTable@@QAEXAAV0@@Z | unused
    ARTS_EXPORT void operator=(HashTable& other);

    // ?Access@HashTable@@QAEPAXPAD@Z
    ARTS_EXPORT void* Access(const char* key);

    // ?Change@HashTable@@QAEHPAD0@Z | unused
    ARTS_EXPORT b32 Change(const char* old_key, const char* new_key);

    // ?Delete@HashTable@@QAEHPAD@Z
    ARTS_EXPORT b32 Delete(const char* key);

    // ?Init@HashTable@@QAEXH@Z
    ARTS_EXPORT void Init(i32 bucket_count);

    // ?Insert@HashTable@@QAEHPADPAX@Z
    ARTS_EXPORT b32 Insert(const char* key, void* value);

    // ?Kill@HashTable@@QAEXXZ
    ARTS_EXPORT void Kill();

    void Kill(void* context, void (*callback)(void* context, const char* key, void* value));

    // ?KillAll@HashTable@@SAXXZ
    ARTS_EXPORT static void KillAll();

    i32 Size() const
    {
        return value_count_;
    }

private:
    // ?ComputePrime@HashTable@@AAEHH@Z
    ARTS_EXPORT i32 ComputePrime(i32 value);

    // ?Hash@HashTable@@AAEHPAD@Z
    ARTS_EXPORT u32 Hash(const char* key);

    // ?Recompute@HashTable@@AAEXH@Z
    ARTS_EXPORT void Recompute(i32 capacity);

    // ?RemoveMe@HashTable@@AAEXXZ
    ARTS_EXPORT void RemoveMe();

    // ?First@HashTable@@0PAV1@A
    ARTS_EXPORT static HashTable* First;

    i32 bucket_count_ {};
    i32 value_count_ {};
    Ptr<HashEntry*[]> buckets_;
    HashTable* next_table_ {};

    friend struct HashIterator;
};

check_size(HashTable, 0x10);

struct HashIterator
{
public:
    HashIterator(HashTable& table)
        : Table(&table)
    {}

    // ?Begin@HashIterator@@QAEXXZ
    ARTS_EXPORT void Begin();

    // ?Next@HashIterator@@QAEHXZ
    ARTS_EXPORT b32 Next();

    HashEntry* operator->() const
    {
        return Current;
    }

    HashTable* Table {};
    i32 Index {};
    HashEntry* Current {};
};

check_size(HashIterator, 0xC);
