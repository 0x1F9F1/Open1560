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

define_dummy_symbol(stream_stream);

#include "stream.h"

Stream::Stream(void* arg1, i32 arg2, class FileSystem* arg3)
{
    unimplemented(arg1, arg2, arg3);
}

Stream::~Stream()
{
    unimplemented(arg1);
}

void* Stream::GetMapping()
{
    return stub<thiscall_t<void*, Stream*>>(0x55ED80, this);
}

u32 Stream::GetPagerHandle()
{
    return stub<thiscall_t<u32, Stream*>>(0x55ED90, this);
}

i32 Stream::GetPagingInfo(u32& arg1, u32& arg2, u32& arg3)
{
    return stub<thiscall_t<i32, Stream*, u32&, u32&, u32&>>(0x55EDA0, this, arg1, arg2, arg3);
}

void Stream::RawDebug()
{
    return stub<thiscall_t<void, Stream*>>(0x55EE90, this);
}

i32 Stream::AlignSize()
{
    return stub<thiscall_t<i32, Stream*>>(0x55ED30, this);
}

i32 Stream::GetError(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, char*, i32>>(0x55ED40, this, arg1, arg2);
}

void Stream::Debug()
{
    return stub<thiscall_t<void, Stream*>>(0x55EEA0, this);
}

void Stream::Error(char* arg1)
{
    return stub<thiscall_t<void, Stream*, char*>>(0x55EDB0, this, arg1);
}

i32 Stream::Flush()
{
    return stub<thiscall_t<i32, Stream*>>(0x55ECC0, this);
}

i32 Stream::Get(u16* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u16*, i32>>(0x55F190, this, arg1, arg2);
}

i32 Stream::Get(u32* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u32*, i32>>(0x55F1D0, this, arg1, arg2);
}

i32 Stream::Get(u8* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u8*, i32>>(0x55F170, this, arg1, arg2);
}

i32 Stream::GetCh()
{
    return stub<thiscall_t<i32, Stream*>>(0x55EC00, this);
}

u32 Stream::GetLong()
{
    return stub<thiscall_t<u32, Stream*>>(0x55F2B0, this);
}

u16 Stream::GetShort()
{
    return stub<thiscall_t<u16, Stream*>>(0x55F290, this);
}

i32 Stream::GetString(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, char*, i32>>(0x55EEF0, this, arg1, arg2);
}

i32 Stream::Printf(char const* arg1, ...)
{
    unimplemented(arg1);
}

i32 Stream::Put(f32 arg1)
{
    return stub<thiscall_t<i32, Stream*, f32>>(0x55F020, this, arg1);
}

i32 Stream::Put(u16 arg1)
{
    return stub<thiscall_t<i32, Stream*, u16>>(0x55EFA0, this, arg1);
}

i32 Stream::Put(u32 arg1)
{
    return stub<thiscall_t<i32, Stream*, u32>>(0x55EFD0, this, arg1);
}

i32 Stream::Put(u8 arg1)
{
    return stub<thiscall_t<i32, Stream*, u8>>(0x55EF80, this, arg1);
}

i32 Stream::Put(u16* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u16*, i32>>(0x55F0A0, this, arg1, arg2);
}

i32 Stream::Put(u32* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u32*, i32>>(0x55F100, this, arg1, arg2);
}

i32 Stream::Put(u8* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u8*, i32>>(0x55F080, this, arg1, arg2);
}

i32 Stream::PutCh(u8 arg1)
{
    return stub<thiscall_t<i32, Stream*, u8>>(0x55EC30, this, arg1);
}

i32 Stream::PutString(char* arg1)
{
    return stub<thiscall_t<i32, Stream*, char*>>(0x55EEB0, this, arg1);
}

i32 Stream::Read(void* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, void*, i32>>(0x55E9C0, this, arg1, arg2);
}

i32 Stream::Seek(i32 arg1)
{
    return stub<thiscall_t<i32, Stream*, i32>>(0x55EC60, this, arg1);
}

i32 Stream::Size()
{
    return stub<thiscall_t<i32, Stream*>>(0x55ECA0, this);
}

i32 Stream::Tell()
{
    return stub<thiscall_t<i32, Stream*>>(0x55EC90, this);
}

i32 Stream::Vprintf(char const* arg1, char* arg2)
{
    return stub<thiscall_t<i32, Stream*, char const*, char*>>(0x55EE40, this, arg1, arg2);
}

i32 Stream::Write(void* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, void*, i32>>(0x55EB00, this, arg1, arg2);
}

void Stream::SwapLongs(u32* arg1, i32 arg2)
{
    return stub<cdecl_t<void, u32*, i32>>(0x55F240, arg1, arg2);
}

void Stream::SwapShorts(u16* arg1, i32 arg2)
{
    return stub<cdecl_t<void, u16*, i32>>(0x55F210, arg1, arg2);
}

i32 fgets(char* arg1, i32 arg2, class Stream* arg3)
{
    return stub<cdecl_t<i32, char*, i32, class Stream*>>(0x55F3E0, arg1, arg2, arg3);
}

class Stream* fopen(char* arg1, char* arg2)
{
    return stub<cdecl_t<class Stream*, char*, char*>>(0x55F2F0, arg1, arg2);
}

void fprintf(class Stream* arg1, char const* arg2, ...)
{
    unimplemented(arg1, arg2);
}

i32 fscanf(class Stream* arg1, char const* arg2, ...)
{
    unimplemented(arg1, arg2);
}

i32 fseek(class Stream* arg1, i32 arg2, i32 arg3)
{
    return stub<cdecl_t<i32, class Stream*, i32, i32>>(0x55F330, arg1, arg2, arg3);
}
