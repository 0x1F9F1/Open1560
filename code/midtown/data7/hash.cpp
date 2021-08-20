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

HashTable* HashTable::First = nullptr;

void HashTable::operator=(HashTable& other)
{
    // TODO: Why is this bucket_count_ - 1?
    Init(bucket_count_ - 1);

    for (i32 i = 0; i < other.bucket_count_; ++i)
    {
        for (HashEntry* j = other.buckets_[i]; j; j = j->Next)
            Insert(j->Key.get(), j->Value);
    }
}

void* HashTable::Access(const char* key)
{
    if (buckets_ == nullptr)
        return nullptr;

    for (HashEntry* i = buckets_[Hash(key)]; i; i = i->Next)
    {
        if (i->Key == key)
            return i->Value;
    }

    return nullptr;
}

b32 HashTable::Change(const char* old_key, const char* new_key)
{
    // TODO: Reuse existing entry

    void* value = Access(old_key);

    if (!Delete(old_key))
        return false;

    return Insert(new_key, value);
}

b32 HashTable::Delete(const char* key)
{
    if (buckets_ == nullptr)
        return false;

    for (HashEntry** i = &buckets_[Hash(key)]; *i; i = &(*i)->Next)
    {
        if (HashEntry* v = *i; v->Key == key)
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

    value_count_ = 0;
    bucket_count_ = ComputePrime(std::max(bucket_count, 100));
    buckets_ = MakeUnique<HashEntry*[]>(bucket_count_);
}

b32 HashTable::Insert(const char* key, void* value)
{
    if (buckets_ == nullptr)
    {
        if (bucket_count_ == 0)
            return false;

        Init(bucket_count_);
    }

    u32 bucket = Hash(key);

    for (HashEntry* i = buckets_[bucket]; i; i = i->Next)
    {
        if (i->Key == key)
            return false;
    }

    buckets_[bucket] = new HashEntry {ConstString(key), value, buckets_[bucket]};

    // TODO: Check before inserting
    if (++value_count_ > bucket_count_) // TODO: Reduce load factor
        Recompute(bucket_count_ * 4);   // TODO: Reduce growth factor

    return true;
}

void HashTable::Kill()
{
    if (buckets_ == nullptr)
        return;

    for (i32 i = 0; i < bucket_count_; ++i)
    {
        for (HashEntry *j = buckets_[i], *next = nullptr; j; j = next)
        {
            next = j->Next;

            delete j;
        }
    }

    value_count_ = 0;
    buckets_ = nullptr;
}

void HashTable::Kill(void* context, void (*callback)(void* context, const char* key, void* value))
{
    if (buckets_ == nullptr)
        return;

    Ptr<HashEntry*[]> buckets = std::move(buckets_);
    i32 bucket_count = bucket_count_;
    value_count_ = 0;

    for (i32 i = 0; i < bucket_count; ++i)
    {
        for (HashEntry *j = buckets[i], *next = nullptr; j; j = next)
        {
            next = j->Next;
            callback(context, j->Key.get(), j->Value);
            delete j;
        }
    }
}

void HashTable::KillAll()
{
    for (HashTable* i = First; i; i = i->next_table_)
        i->Kill();
}

// TODO: Make static
// TODO: Make unsigned
// TODO: Maybe use powers of 2 instead of primes
i32 HashTable::ComputePrime(i32 value)
{
    u32 prime = static_cast<u32>(value);

    if (!(prime % 2))
        ++prime;

    for (;; prime += 2)
    {
        for (u32 n = 3, upper = prime / 2;; n += 2)
        {
            if (n > upper)
                return static_cast<i32>(prime);

            if ((prime % n) == 0)
                break;
        }
    }
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

    ArDebugAssert(bucket_count_ != 0, "Cannot hash on an empty table");

    return hash % bucket_count_;
}

void HashTable::Recompute(i32 capacity)
{
    capacity = ComputePrime(capacity);

    i32 old_bucket_count = bucket_count_;
    Ptr<HashEntry*[]> old_buckets = MakeUnique<HashEntry*[]>(capacity);

    buckets_.swap(old_buckets);
    bucket_count_ = capacity;

    for (i32 i = 0; i < old_bucket_count; ++i)
    {
        for (HashEntry *j = old_buckets[i], *next = nullptr; j; j = next)
        {
            next = j->Next;

            u32 bucket = Hash(j->Key.get());

            j->Next = buckets_[bucket];
            buckets_[bucket] = j;
        }
    }
}

void HashTable::RemoveMe()
{
    for (HashTable** i = &First; *i; i = &(*i)->next_table_)
    {
        if (*i == this)
        {
            *i = (*i)->next_table_;
            break;
        }
    }
}

void HashIterator::Begin()
{
    Current = nullptr;
    Index = -1;
}

b32 HashIterator::Next()
{
    if (Table->buckets_ == nullptr)
        return false;

    if (Current)
    {
        Current = Current->Next;

        if (Current)
            return true;
    }

    while (true)
    {
        if (Index == Table->bucket_count_ - 1)
            break;

        Current = Table->buckets_[++Index];

        if (Current)
            return true;
    }

    return false;
}
