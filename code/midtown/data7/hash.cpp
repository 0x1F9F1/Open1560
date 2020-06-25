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

define_dummy_symbol(data7_hash);

#include "hash.h"

HashTable::~HashTable()
{
    Kill();
    RemoveMe();
}

void HashTable::operator=(class HashTable& other)
{
    Init(bucket_count_ - 1);

    for (i32 i = 0; i < other.bucket_count_; ++i)
    {
        for (HashEntry* j = other.buckets_[i]; j; j = j->Next)
            Insert(j->Key.get(), j->Value);
    }
}

void* HashTable::Access(const char* key)
{
    if (buckets_ == nullptr && bucket_count_ != 0)
        Init(bucket_count_);

    for (HashEntry* i = buckets_[Hash(key)]; i; i = i->Next)
    {
        if (!std::strcmp(i->Key.get(), key))
            return i->Value;
    }

    return nullptr;
}

b32 HashTable::Change(const char* old_key, const char* new_key)
{
    // TODO: Reuse existing entry

    void* value = Access(old_key);

    b32 result = Delete((char*) old_key);

    if (result)
        result = Insert((char*) new_key, value);

    return result;
}

i32 HashTable::Delete(const char* key)
{
    if (buckets_ == nullptr)
        return false;

    for (HashEntry** i = &buckets_[Hash(key)]; *i; i = &(*i)->Next)
    {
        HashEntry* v = *i;

        if (!std::strcmp(v->Key.get(), key))
        {
            *i = v->Next;
            delete v;
            --value_count_;
            return true;
        }
    }

    return false;
}

void HashTable::Init(i32 bucket_count)
{
    Kill();
    bucket_count_ = ComputePrime(std::max(bucket_count, 100));
    buckets_ = MakeUnique<HashEntry*[]>(bucket_count_);
}

u32 HashTable::Hash(const char* key)
{
    u32 hash = 0;

    for (char c; (c = *key) != '\0'; ++key)
    {
        hash = (hash << 4) + c;

        if (u32 upper = hash & 0xF0000000)
            hash ^= upper ^ (upper >> 24);
    }

    return hash % u32(bucket_count_);
}
