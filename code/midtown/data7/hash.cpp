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
    unimplemented();
}

void HashTable::operator=(class HashTable& arg1)
{
    return stub<thiscall_t<void, HashTable*, class HashTable&>>(0x178180_Offset, this, arg1);
}

void* HashTable::Access(char* arg1)
{
    return stub<thiscall_t<void*, HashTable*, char*>>(0x178430_Offset, this, arg1);
}

i32 HashTable::Change(char* arg1, char* arg2)
{
    return stub<thiscall_t<i32, HashTable*, char*, char*>>(0x1783F0_Offset, this, arg1, arg2);
}

i32 HashTable::Delete(char* arg1)
{
    return stub<thiscall_t<i32, HashTable*, char*>>(0x1782B0_Offset, this, arg1);
}

void HashTable::Init(i32 arg1)
{
    return stub<thiscall_t<void, HashTable*, i32>>(0x1780A0_Offset, this, arg1);
}

i32 HashTable::Insert(char* arg1, void* arg2)
{
    return stub<thiscall_t<i32, HashTable*, char*, void*>>(0x1781D0_Offset, this, arg1, arg2);
}

void HashTable::Kill()
{
    return stub<thiscall_t<void, HashTable*>>(0x178110_Offset, this);
}

void HashTable::KillAll()
{
    return stub<cdecl_t<void>>(0x178610_Offset);
}

i32 HashTable::ComputePrime(i32 arg1)
{
    return stub<thiscall_t<i32, HashTable*, i32>>(0x178500_Offset, this, arg1);
}

i32 HashTable::Hash(char* arg1)
{
    return stub<thiscall_t<i32, HashTable*, char*>>(0x1784C0_Offset, this, arg1);
}

void HashTable::Recompute(i32 arg1)
{
    return stub<thiscall_t<void, HashTable*, i32>>(0x178550_Offset, this, arg1);
}

void HashTable::RemoveMe()
{
    return stub<thiscall_t<void, HashTable*>>(0x178630_Offset, this);
}

void HashIterator::Begin()
{
    return stub<thiscall_t<void, HashIterator*>>(0x178040_Offset, this);
}

i32 HashIterator::Next()
{
    return stub<thiscall_t<i32, HashIterator*>>(0x178050_Offset, this);
}
