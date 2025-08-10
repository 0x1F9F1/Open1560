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

#include "data7/base.h"

#include "core/endian.h"

class FileSystem;

#define ARTS_STREAM_MANAGED_BUFFER 0x1
#define ARTS_STREAM_SUPPORTS_MAPPING 0x2

class Stream : public Base
{
public:
    // ??0Stream@@QAE@PAXHPAVFileSystem@@@Z
    Stream(void* buffer, isize buffer_size, FileSystem* file_system);

    // ??1Stream@@UAE@XZ
    ~Stream() override;

    // ?GetMapping@Stream@@UAEPAXXZ
    virtual void* GetMapping();

    // ?GetPagerHandle@Stream@@UAEIXZ
    virtual usize GetPagerHandle();

    // ?GetPagingInfo@Stream@@UAEHAAI00@Z
    virtual b32 GetPagingInfo(usize& handle, u32& offset, u32& size);

    virtual isize RawRead(void* arg1, isize arg2) = 0;

    virtual isize RawWrite(const void* arg1, isize arg2) = 0;

    virtual i32 RawSeek(i32 arg1) = 0;

    virtual i32 RawTell() = 0;

    virtual i32 RawSize() = 0;

    // ?Debug@Stream@@QAEXXZ | unused
    void Debug();

    // ?Error@Stream@@QAEXPAD@Z
    void Error(const char* msg);

    // ?Flush@Stream@@QAEHXZ
    isize Flush();

    // ?Get@Stream@@QAEHPAGH@Z
    ARTS_EXPORT isize Get(u16* values, isize count);

    // ?Get@Stream@@QAEHPAKH@Z
    isize Get(u32* values, isize count);

    // ?Get@Stream@@QAEHPAEH@Z
    ARTS_EXPORT isize Get(u8* values, isize count)
    {
        return Read(values, count);
    }

    // ?GetCh@Stream@@QAEHXZ
    ARTS_EXPORT i32 GetCh()
    {
        if (buffer_head_ < buffer_read_)
            return buffer_[buffer_head_++];

        u8 result = 0;

        if (Read(&result, 1) == 1)
            return result;

        return -1;
    }

    i32 UnGetCh(i32 ch)
    {
        if (buffer_read_ != 0 && buffer_head_ != 0)
        {
            buffer_[--buffer_head_] = static_cast<u8>(ch);

            return ch;
        }

        return -1;
    }

    ConstString GetString();

    // ?Printf@Stream@@QAAHPBDZZ | unused
    isize Printf(ARTS_FORMAT_STRING const char* format, ...);

    i32 Scanf(const char* format, ...);

    i32 Vscanf(const char* format, std::va_list va);

    isize Gets(char* buffer, isize buffer_len);

    // ?Put@Stream@@QAEHM@Z
    ARTS_EXPORT isize Put(f32 value);

    // ?Put@Stream@@QAEHG@Z
    ARTS_EXPORT isize Put(u16 value);

    // ?Put@Stream@@QAEHK@Z
    isize Put(u32 value);

    // ?Put@Stream@@QAEHE@Z
    ARTS_EXPORT isize Put(u8 value);

    // ?Put@Stream@@QAEHPAGH@Z
    isize Put(const u16* values, isize count);

    // ?Put@Stream@@QAEHPAKH@Z
    isize Put(const u32* values, isize count);

    // ?Put@Stream@@QAEHPAEH@Z
    isize Put(const u8* values, isize count);

    // ?PutCh@Stream@@QAEHE@Z
    i32 PutCh(u8 value)
    {
        if ((buffer_read_ == 0) && (buffer_head_ < buffer_capacity_))
        {
            buffer_[buffer_head_++] = value;

            return value;
        }

        if (Write(&value, 1) == 1)
            return value;

        return -1;
    }

    // ?PutString@Stream@@QAEHPAD@Z
    isize PutString(const char* str);

    // ?Read@Stream@@QAEHPAXH@Z
    ARTS_EXPORT isize Read(void* ptr, isize size);

    // ?Seek@Stream@@QAEHH@Z
    ARTS_EXPORT i32 Seek(i32 position);

    // ?Size@Stream@@QAEHXZ
    ARTS_EXPORT i32 Size();

    // ?Tell@Stream@@QAEHXZ
    ARTS_EXPORT i32 Tell()
    {
        return position_ + buffer_head_;
    }

    // ?Vprintf@Stream@@QAEHPBDPAD@Z
    isize Vprintf(const char* format, std::va_list va);

    // ?Write@Stream@@QAEHPAXH@Z
    isize Write(const void* ptr, isize size);

    template <typename T>
    T Get();

    template <typename T>
    void GetN(T* values, isize count);

    // Returns file mapping if available, otherwise allocates a buffer and reads
    template <typename T>
    /*const */ T* ReadMapped(isize count);

    bool SupportsMapping() const
    {
        return flags_ & ARTS_STREAM_SUPPORTS_MAPPING;
    }

protected:
    // ?RawDebug@Stream@@MAEXXZ
    virtual void RawDebug();

    // ?AlignSize@Stream@@MAEHXZ
    virtual i32 AlignSize();

    // ?GetError@Stream@@MAEHPADH@Z
    virtual i32 GetError(char* buf, isize buf_len);

    u8* buffer_ {};

    // TODO: Use u64
    u32 position_ {};

    u32 buffer_head_ {};
    u32 buffer_read_ {};
    u32 buffer_capacity_ {};

    FileSystem* file_system_ {};

    // ARTS_STREAM_*
    u8 flags_ {};

    u8 swap_endian_ {};
    u8 little_endian_ {};
    u8 initialized_ {};

private:
    // ?SwapLongs@Stream@@CAXPAKH@Z
    static void SwapLongs(u32* values, isize count);

    // ?SwapShorts@Stream@@CAXPAGH@Z
    static void SwapShorts(u16* values, isize count);
};

check_size(Stream, 0x20);

// ?fgets@@YAHPADHPAVStream@@@Z
[[deprecated("Use stream->Gets()")]] isize arts_fgets(char* buffer, isize buffer_len, Stream* stream);

// ?fopen@@YAPAVStream@@PAD0@Z
Owner<Stream> arts_fopen(const char* path, const char* mode);

// ?fprintf@@YAXPAVStream@@PBDZZ
void arts_fprintf(Stream* stream, ARTS_FORMAT_STRING const char* format, ...);

// ?fscanf@@YAHPAVStream@@PBDZZ
i32 arts_fscanf(Stream* stream, const char* format, ...);

// ?fseek@@YAHPAVStream@@HH@Z
i32 arts_fseek(Stream* stream, i32 offset, i32 origin);

// ?EnableBinaryFileMapping@@3HA
ARTS_EXPORT extern b32 EnableBinaryFileMapping;

template <typename T>
ARTS_NOINLINE inline T Stream::Get()
{
    T value {};

    // TODO: Handle incomplete read
    Read(&value, sizeof(value));

    if (swap_endian_)
        value = ByteSwap<T>(value);

    return value;
}

template <typename T>
ARTS_NOINLINE inline void Stream::GetN(T* values, isize count)
{
    // TODO: Handle incomplete read
    Read(values, sizeof(T) * count);

    if (swap_endian_)
        ByteSwapN(values, count);
}

template <typename T>
inline T* Stream::ReadMapped(isize count)
{
    T* result = nullptr;

    if (EnableBinaryFileMapping && SupportsMapping())
    {
        result = reinterpret_cast<T*>(static_cast<u8*>(GetMapping()) + Tell());
        Seek(Tell() + count * sizeof(T));
    }
    else
    {
        result = new T[count];
        Read(result, count * sizeof(T));
    }

    return result;
}
