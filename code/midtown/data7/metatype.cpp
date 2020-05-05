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

define_dummy_symbol(data7_metatype);

#include "metatype.h"

void PtrToType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, PtrToType*, void*, i32>>(0x17B5E0_Offset, this, arg1, arg2);
}

void PtrToType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, PtrToType*, class MiniParser*, void*>>(0x17B5B0_Offset, this, arg1, arg2);
}

void* PtrToType::New(i32 arg1)
{
    return stub<thiscall_t<void*, PtrToType*, i32>>(0x17B5D0_Offset, this, arg1);
}

void PtrToType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, PtrToType*, class MiniParser*, void*>>(0x17B590_Offset, this, arg1, arg2);
}

u32 PtrToType::SizeOf()
{
    return stub<thiscall_t<u32, PtrToType*>>(0x17B5F0_Offset, this);
}

void RefToType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, RefToType*, void*, i32>>(0x17B7B0_Offset, this, arg1, arg2);
}

i32 RefToType::GetCount(void* arg1)
{
    return stub<thiscall_t<i32, RefToType*, void*>>(0x17B600_Offset, this, arg1);
}

void RefToType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, RefToType*, class MiniParser*, void*>>(0x17B6F0_Offset, this, arg1, arg2);
}

void* RefToType::New(i32 arg1)
{
    return stub<thiscall_t<void*, RefToType*, i32>>(0x17B7A0_Offset, this, arg1);
}

void RefToType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, RefToType*, class MiniParser*, void*>>(0x17B640_Offset, this, arg1, arg2);
}

u32 RefToType::SizeOf()
{
    return stub<thiscall_t<u32, RefToType*>>(0x17B7C0_Offset, this);
}

void ArrayOfType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, ArrayOfType*, void*, i32>>(0x17B940_Offset, this, arg1, arg2);
}

void ArrayOfType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, ArrayOfType*, class MiniParser*, void*>>(0x17B870_Offset, this, arg1, arg2);
}

void* ArrayOfType::New(i32 arg1)
{
    return stub<thiscall_t<void*, ArrayOfType*, i32>>(0x17B920_Offset, this, arg1);
}

void ArrayOfType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, ArrayOfType*, class MiniParser*, void*>>(0x17B7D0_Offset, this, arg1, arg2);
}

u32 ArrayOfType::SizeOf()
{
    return stub<thiscall_t<u32, ArrayOfType*>>(0x17B900_Offset, this);
}

void StructType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, StructType*, void*, i32>>(0x17B9D0_Offset, this, arg1, arg2);
}

void StructType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, StructType*, class MiniParser*, void*>>(0x17B980_Offset, this, arg1, arg2);
}

void* StructType::New(i32 arg1)
{
    return stub<thiscall_t<void*, StructType*, i32>>(0x17B9B0_Offset, this, arg1);
}

void StructType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, StructType*, class MiniParser*, void*>>(0x17B960_Offset, this, arg1, arg2);
}

u32 StructType::SizeOf()
{
    return stub<thiscall_t<u32, StructType*>>(0x17B9A0_Offset, this);
}

void CharType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, CharType*, void*, i32>>(0x17BA70_Offset, this, arg1, arg2);
}

void CharType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, CharType*, class MiniParser*, void*>>(0x17BA10_Offset, this, arg1, arg2);
}

void* CharType::New(i32 arg1)
{
    return stub<thiscall_t<void*, CharType*, i32>>(0x17BA40_Offset, this, arg1);
}

void CharType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, CharType*, class MiniParser*, void*>>(0x17B9F0_Offset, this, arg1, arg2);
}

u32 CharType::SizeOf()
{
    return stub<thiscall_t<u32, CharType*>>(0x17BA30_Offset, this);
}

void SignedCharType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, SignedCharType*, void*, i32>>(0x17BB40_Offset, this, arg1, arg2);
}

void SignedCharType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedCharType*, class MiniParser*, void*>>(0x17BAE0_Offset, this, arg1, arg2);
}

void* SignedCharType::New(i32 arg1)
{
    return stub<thiscall_t<void*, SignedCharType*, i32>>(0x17BB10_Offset, this, arg1);
}

void SignedCharType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedCharType*, class MiniParser*, void*>>(0x17BAC0_Offset, this, arg1, arg2);
}

u32 SignedCharType::SizeOf()
{
    return stub<thiscall_t<u32, SignedCharType*>>(0x17BB00_Offset, this);
}

void UnsignedCharType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, UnsignedCharType*, void*, i32>>(0x17BC10_Offset, this, arg1, arg2);
}

void UnsignedCharType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedCharType*, class MiniParser*, void*>>(0x17BBB0_Offset, this, arg1, arg2);
}

void* UnsignedCharType::New(i32 arg1)
{
    return stub<thiscall_t<void*, UnsignedCharType*, i32>>(0x17BBE0_Offset, this, arg1);
}

void UnsignedCharType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedCharType*, class MiniParser*, void*>>(0x17BB90_Offset, this, arg1, arg2);
}

u32 UnsignedCharType::SizeOf()
{
    return stub<thiscall_t<u32, UnsignedCharType*>>(0x17BBD0_Offset, this);
}

void SignedShortType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, SignedShortType*, void*, i32>>(0x17BCE0_Offset, this, arg1, arg2);
}

void SignedShortType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedShortType*, class MiniParser*, void*>>(0x17BC80_Offset, this, arg1, arg2);
}

void* SignedShortType::New(i32 arg1)
{
    return stub<thiscall_t<void*, SignedShortType*, i32>>(0x17BCB0_Offset, this, arg1);
}

void SignedShortType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedShortType*, class MiniParser*, void*>>(0x17BC60_Offset, this, arg1, arg2);
}

u32 SignedShortType::SizeOf()
{
    return stub<thiscall_t<u32, SignedShortType*>>(0x17BCA0_Offset, this);
}

void UnsignedShortType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, UnsignedShortType*, void*, i32>>(0x17BDC0_Offset, this, arg1, arg2);
}

void UnsignedShortType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedShortType*, class MiniParser*, void*>>(0x17BD60_Offset, this, arg1, arg2);
}

void* UnsignedShortType::New(i32 arg1)
{
    return stub<thiscall_t<void*, UnsignedShortType*, i32>>(0x17BD90_Offset, this, arg1);
}

void UnsignedShortType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedShortType*, class MiniParser*, void*>>(0x17BD30_Offset, this, arg1, arg2);
}

u32 UnsignedShortType::SizeOf()
{
    return stub<thiscall_t<u32, UnsignedShortType*>>(0x17BD80_Offset, this);
}

void SignedIntType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, SignedIntType*, void*, i32>>(0x17BE90_Offset, this, arg1, arg2);
}

void SignedIntType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedIntType*, class MiniParser*, void*>>(0x17BE30_Offset, this, arg1, arg2);
}

void* SignedIntType::New(i32 arg1)
{
    return stub<thiscall_t<void*, SignedIntType*, i32>>(0x17BE60_Offset, this, arg1);
}

void SignedIntType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedIntType*, class MiniParser*, void*>>(0x17BE10_Offset, this, arg1, arg2);
}

u32 SignedIntType::SizeOf()
{
    return stub<thiscall_t<u32, SignedIntType*>>(0x17BE50_Offset, this);
}

void SignedInt64Type::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, SignedInt64Type*, void*, i32>>(0x17BF70_Offset, this, arg1, arg2);
}

void SignedInt64Type::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedInt64Type*, class MiniParser*, void*>>(0x17BF10_Offset, this, arg1, arg2);
}

void* SignedInt64Type::New(i32 arg1)
{
    return stub<thiscall_t<void*, SignedInt64Type*, i32>>(0x17BF40_Offset, this, arg1);
}

void SignedInt64Type::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, SignedInt64Type*, class MiniParser*, void*>>(0x17BEE0_Offset, this, arg1, arg2);
}

u32 SignedInt64Type::SizeOf()
{
    return stub<thiscall_t<u32, SignedInt64Type*>>(0x17BF30_Offset, this);
}

void UnsignedIntType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, UnsignedIntType*, void*, i32>>(0x17C040_Offset, this, arg1, arg2);
}

void UnsignedIntType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedIntType*, class MiniParser*, void*>>(0x17BFE0_Offset, this, arg1, arg2);
}

void* UnsignedIntType::New(i32 arg1)
{
    return stub<thiscall_t<void*, UnsignedIntType*, i32>>(0x17C010_Offset, this, arg1);
}

void UnsignedIntType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, UnsignedIntType*, class MiniParser*, void*>>(0x17BFC0_Offset, this, arg1, arg2);
}

u32 UnsignedIntType::SizeOf()
{
    return stub<thiscall_t<u32, UnsignedIntType*>>(0x17C000_Offset, this);
}

void FloatType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, FloatType*, void*, i32>>(0x17C120_Offset, this, arg1, arg2);
}

void FloatType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, FloatType*, class MiniParser*, void*>>(0x17C0C0_Offset, this, arg1, arg2);
}

void* FloatType::New(i32 arg1)
{
    return stub<thiscall_t<void*, FloatType*, i32>>(0x17C0F0_Offset, this, arg1);
}

void FloatType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, FloatType*, class MiniParser*, void*>>(0x17C090_Offset, this, arg1, arg2);
}

u32 FloatType::SizeOf()
{
    return stub<thiscall_t<u32, FloatType*>>(0x17C0E0_Offset, this);
}

void StringType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, StringType*, void*, i32>>(0x17C260_Offset, this, arg1, arg2);
}

void StringType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, StringType*, class MiniParser*, void*>>(0x17C1D0_Offset, this, arg1, arg2);
}

void* StringType::New(i32 arg1)
{
    return stub<thiscall_t<void*, StringType*, i32>>(0x17C220_Offset, this, arg1);
}

void StringType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, StringType*, class MiniParser*, void*>>(0x17C190_Offset, this, arg1, arg2);
}

u32 StringType::SizeOf()
{
    return stub<thiscall_t<u32, StringType*>>(0x17C270_Offset, this);
}

void MetaType::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, MetaType*, class MiniParser*, void*>>(0x - 400000_Offset, this, arg1, arg2);
}

void MetaType::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, MetaType*, class MiniParser*, void*>>(0x - 400000_Offset, this, arg1, arg2);
}

u32 MetaType::SizeOf()
{
    return stub<thiscall_t<u32, MetaType*>>(0x - 400000_Offset, this);
}

void* MetaType::New(i32 arg1)
{
    return stub<thiscall_t<void*, MetaType*, i32>>(0x - 400000_Offset, this, arg1);
}

void MetaType::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, MetaType*, void*, i32>>(0x - 400000_Offset, this, arg1, arg2);
}
