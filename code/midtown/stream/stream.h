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
    stream:stream

    0x55E8B0 | public: __thiscall Stream::Stream(void *,int,class FileSystem *) | ??0Stream@@QAE@PAXHPAVFileSystem@@@Z
    0x55E940 | public: virtual __thiscall Stream::~Stream(void) | ??1Stream@@UAE@XZ
    0x55E9C0 | public: int __thiscall Stream::Read(void *,int) | ?Read@Stream@@QAEHPAXH@Z
    0x55EB00 | public: int __thiscall Stream::Write(void *,int) | ?Write@Stream@@QAEHPAXH@Z
    0x55EC00 | public: int __thiscall Stream::GetCh(void) | ?GetCh@Stream@@QAEHXZ
    0x55EC30 | public: int __thiscall Stream::PutCh(unsigned char) | ?PutCh@Stream@@QAEHE@Z
    0x55EC60 | public: int __thiscall Stream::Seek(int) | ?Seek@Stream@@QAEHH@Z
    0x55EC90 | public: int __thiscall Stream::Tell(void) | ?Tell@Stream@@QAEHXZ
    0x55ECA0 | public: int __thiscall Stream::Size(void) | ?Size@Stream@@QAEHXZ
    0x55ECC0 | public: int __thiscall Stream::Flush(void) | ?Flush@Stream@@QAEHXZ
    0x55ED30 | protected: virtual int __thiscall Stream::AlignSize(void) | ?AlignSize@Stream@@MAEHXZ
    0x55ED40 | protected: virtual int __thiscall Stream::GetError(char *,int) | ?GetError@Stream@@MAEHPADH@Z
    0x55ED80 | public: virtual void * __thiscall Stream::GetMapping(void) | ?GetMapping@Stream@@UAEPAXXZ
    0x55ED90 | public: virtual unsigned int __thiscall Stream::GetPagerHandle(void) | ?GetPagerHandle@Stream@@UAEIXZ
    0x55EDA0 | public: virtual int __thiscall Stream::GetPagingInfo(unsigned int &,unsigned int &,unsigned int &) | ?GetPagingInfo@Stream@@UAEHAAI00@Z
    0x55EDB0 | public: void __thiscall Stream::Error(char *) | ?Error@Stream@@QAEXPAD@Z
    0x55EDF0 | public: int __cdecl Stream::Printf(char const *,...) | ?Printf@Stream@@QAAHPBDZZ
    0x55EE40 | public: int __thiscall Stream::Vprintf(char const *,char *) | ?Vprintf@Stream@@QAEHPBDPAD@Z
    0x55EE90 | protected: virtual void __thiscall Stream::RawDebug(void) | ?RawDebug@Stream@@MAEXXZ
    0x55EEA0 | public: void __thiscall Stream::Debug(void) | ?Debug@Stream@@QAEXXZ
    0x55EEB0 | public: int __thiscall Stream::PutString(char *) | ?PutString@Stream@@QAEHPAD@Z
    0x55EEF0 | public: int __thiscall Stream::GetString(char *,int) | ?GetString@Stream@@QAEHPADH@Z
    0x55EF80 | public: int __thiscall Stream::Put(unsigned char) | ?Put@Stream@@QAEHE@Z
    0x55EFA0 | public: int __thiscall Stream::Put(unsigned short) | ?Put@Stream@@QAEHG@Z
    0x55EFD0 | public: int __thiscall Stream::Put(unsigned long) | ?Put@Stream@@QAEHK@Z
    0x55F020 | public: int __thiscall Stream::Put(float) | ?Put@Stream@@QAEHM@Z
    0x55F080 | public: int __thiscall Stream::Put(unsigned char *,int) | ?Put@Stream@@QAEHPAEH@Z
    0x55F0A0 | public: int __thiscall Stream::Put(unsigned short *,int) | ?Put@Stream@@QAEHPAGH@Z
    0x55F100 | public: int __thiscall Stream::Put(unsigned long *,int) | ?Put@Stream@@QAEHPAKH@Z
    0x55F170 | public: int __thiscall Stream::Get(unsigned char *,int) | ?Get@Stream@@QAEHPAEH@Z
    0x55F190 | public: int __thiscall Stream::Get(unsigned short *,int) | ?Get@Stream@@QAEHPAGH@Z
    0x55F1D0 | public: int __thiscall Stream::Get(unsigned long *,int) | ?Get@Stream@@QAEHPAKH@Z
    0x55F210 | private: static void __cdecl Stream::SwapShorts(unsigned short *,int) | ?SwapShorts@Stream@@CAXPAGH@Z
    0x55F240 | private: static void __cdecl Stream::SwapLongs(unsigned long *,int) | ?SwapLongs@Stream@@CAXPAKH@Z
    0x55F290 | public: unsigned short __thiscall Stream::GetShort(void) | ?GetShort@Stream@@QAEGXZ
    0x55F2B0 | public: unsigned long __thiscall Stream::GetLong(void) | ?GetLong@Stream@@QAEKXZ
    0x55F2D0 | void __cdecl fprintf(class Stream *,char const *,...) | ?fprintf@@YAXPAVStream@@PBDZZ
    0x55F2F0 | class Stream * __cdecl fopen(char *,char *) | ?fopen@@YAPAVStream@@PAD0@Z
    0x55F330 | int __cdecl fseek(class Stream *,int,int) | ?fseek@@YAHPAVStream@@HH@Z
    0x55F390 | _vprintf
    0x55F3B0 | _printf
    0x55F3E0 | int __cdecl fgets(char *,int,class Stream *) | ?fgets@@YAHPADHPAVStream@@@Z
    0x55F450 | int __cdecl fscanf(class Stream *,char const *,...) | ?fscanf@@YAHPAVStream@@PBDZZ
    0x55F500 | public: virtual void * __thiscall Stream::`vector deleting destructor'(unsigned int) | ??_EStream@@UAEPAXI@Z
    0x55F500 | public: virtual void * __thiscall Stream::`scalar deleting destructor'(unsigned int) | ??_GStream@@UAEPAXI@Z
    0x6218E8 | const Stream::`vftable' | ??_7Stream@@6B@
    0x907960 | int EnableBinaryFileMapping | ?EnableBinaryFileMapping@@3HA
*/

#include "data7/base.h"

class Stream : public Base
{
    // const Stream::`vftable' @ 0x6218E8

public:
    // 0x55E8B0 | ??0Stream@@QAE@PAXHPAVFileSystem@@@Z
    Stream(void* buffer, i32 buffer_size, class FileSystem* file_system);

    // 0x55F500 | ??_GStream@@UAEPAXI@Z
    // 0x55E940 | ??1Stream@@UAE@XZ
    ~Stream() override;

    // 0x55ED80 | ?GetMapping@Stream@@UAEPAXXZ
    virtual void* GetMapping();

    // 0x55ED90 | ?GetPagerHandle@Stream@@UAEIXZ
    virtual u32 GetPagerHandle();

    // 0x55EDA0 | ?GetPagingInfo@Stream@@UAEHAAI00@Z
    virtual i32 GetPagingInfo(u32& handle, u32& offset, u32& size);

    virtual i32 RawRead(void* arg1, i32 arg2) = 0;

    virtual i32 RawWrite(void* arg1, i32 arg2) = 0;

    virtual i32 RawSeek(i32 arg1) = 0;

    virtual i32 RawTell() = 0;

    virtual i32 RawSize() = 0;

protected:
    // 0x55EE90 | ?RawDebug@Stream@@MAEXXZ
    virtual void RawDebug();

    // 0x55ED30 | ?AlignSize@Stream@@MAEHXZ
    virtual i32 AlignSize();

    // 0x55ED40 | ?GetError@Stream@@MAEHPADH@Z
    virtual i32 GetError(char* buf, i32 buf_len);

    u8* buffer_ {nullptr};

    // TODO: Use u64
    u32 position_ {0};

    i32 buffer_head_ {0};
    i32 buffer_read_ {0};
    i32 buffer_capacity_ {0};

    FileSystem* file_system_ {nullptr};

    // 0x1 | Allocated Buffer
    u8 flags_ {0};

    u8 swap_endian_ {false};
    u8 little_endian_ {false};
    u8 initialized_ {false};

public:
    // 0x55EEA0 | ?Debug@Stream@@QAEXXZ
    void Debug();

    // 0x55EDB0 | ?Error@Stream@@QAEXPAD@Z
    void Error(const char* msg);

    // 0x55ECC0 | ?Flush@Stream@@QAEHXZ
    i32 Flush();

    // 0x55F190 | ?Get@Stream@@QAEHPAGH@Z
    i32 Get(u16* arg1, i32 arg2);

    // 0x55F1D0 | ?Get@Stream@@QAEHPAKH@Z
    i32 Get(u32* arg1, i32 arg2);

    // 0x55F170 | ?Get@Stream@@QAEHPAEH@Z
    i32 Get(u8* arg1, i32 arg2);

    // 0x55EC00 | ?GetCh@Stream@@QAEHXZ
    i32 GetCh();

    i32 UnGetCh(i32 ch);

    // 0x55F2B0 | ?GetLong@Stream@@QAEKXZ
    u32 GetLong();

    // 0x55F290 | ?GetShort@Stream@@QAEGXZ
    u16 GetShort();

    // 0x55EEF0 | ?GetString@Stream@@QAEHPADH@Z
    i32 GetString(char* arg1, i32 arg2);

    // 0x55EDF0 | ?Printf@Stream@@QAAHPBDZZ
    i32 Printf(char const* format, ...);

    // 0x55F020 | ?Put@Stream@@QAEHM@Z
    i32 Put(f32 arg1);

    // 0x55EFA0 | ?Put@Stream@@QAEHG@Z
    i32 Put(u16 arg1);

    // 0x55EFD0 | ?Put@Stream@@QAEHK@Z
    i32 Put(u32 arg1);

    // 0x55EF80 | ?Put@Stream@@QAEHE@Z
    i32 Put(u8 arg1);

    // 0x55F0A0 | ?Put@Stream@@QAEHPAGH@Z
    i32 Put(u16* arg1, i32 arg2);

    // 0x55F100 | ?Put@Stream@@QAEHPAKH@Z
    i32 Put(u32* arg1, i32 arg2);

    // 0x55F080 | ?Put@Stream@@QAEHPAEH@Z
    i32 Put(u8* arg1, i32 arg2);

    // 0x55EC30 | ?PutCh@Stream@@QAEHE@Z
    i32 PutCh(u8 arg1);

    // 0x55EEB0 | ?PutString@Stream@@QAEHPAD@Z
    i32 PutString(char* arg1);

    // 0x55E9C0 | ?Read@Stream@@QAEHPAXH@Z
    i32 Read(void* arg1, i32 arg2);

    // 0x55EC60 | ?Seek@Stream@@QAEHH@Z
    i32 Seek(i32 arg1);

    // 0x55ECA0 | ?Size@Stream@@QAEHXZ
    i32 Size();

    // 0x55EC90 | ?Tell@Stream@@QAEHXZ
    i32 Tell();

    // 0x55EE40 | ?Vprintf@Stream@@QAEHPBDPAD@Z
    i32 Vprintf(char const* format, std::va_list va);

    // 0x55EB00 | ?Write@Stream@@QAEHPAXH@Z
    i32 Write(void* arg1, i32 arg2);

private:
    // 0x55F240 | ?SwapLongs@Stream@@CAXPAKH@Z
    static void SwapLongs(u32* arg1, i32 arg2);

    // 0x55F210 | ?SwapShorts@Stream@@CAXPAGH@Z
    static void SwapShorts(u16* arg1, i32 arg2);
};

check_size(Stream, 0x20);

// 0x55F3E0 | ?fgets@@YAHPADHPAVStream@@@Z
i32 arts_fgets(char* arg1, i32 arg2, class Stream* arg3);

// 0x55F2F0 | ?fopen@@YAPAVStream@@PAD0@Z
class Stream* arts_fopen(char* arg1, char* arg2);

// 0x55F2D0 | ?fprintf@@YAXPAVStream@@PBDZZ
void arts_fprintf(class Stream* stream, char const* format, ...);

// 0x55F450 | ?fscanf@@YAHPAVStream@@PBDZZ
i32 arts_fscanf(class Stream* stream, char const* format, ...);

// 0x55F330 | ?fseek@@YAHPAVStream@@HH@Z
i32 arts_fseek(class Stream* arg1, i32 arg2, i32 arg3);

// 0x907960 | ?EnableBinaryFileMapping@@3HA
inline extern_var(0x907960, i32, EnableBinaryFileMapping);

// 0x55F3B0 | _printf (Skipped: void)

// 0x55F390 | _vprintf (Skipped: void)
