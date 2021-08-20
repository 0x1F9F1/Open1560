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

#include "fsystem.h"
#include "hfsystem.h"

#include "core/endian.h"

constexpr bool IsLittleEndian = true;

b32 EnableBinaryFileMapping = false;

Stream::Stream(void* buffer, isize buffer_size, FileSystem* file_system)
    : buffer_(static_cast<u8*>(buffer))
    , buffer_capacity_(buffer_size)
    , file_system_(file_system)
    , little_endian_(IsLittleEndian)
{
    if (buffer_ == nullptr && buffer_capacity_ != 0)
    {
        buffer_ = new u8[buffer_capacity_];
        flags_ |= ARTS_STREAM_MANAGED_BUFFER;
    }

    swap_endian_ = little_endian_;

    initialized_ = true;
}

Stream::~Stream()
{
    // FIXME: If the file actually requires flushing, this will result in purecalls
    // Flush();

    if (file_system_)
        file_system_->NotifyDelete();

    if (flags_ & ARTS_STREAM_MANAGED_BUFFER)
        delete[] buffer_;

    buffer_ = nullptr;
    initialized_ = false;
}

void* Stream::GetMapping()
{
    return nullptr;
}

usize Stream::GetPagerHandle()
{
    return 0;
}

b32 Stream::GetPagingInfo(usize&, u32&, u32&)
{
    return false;
}

void Stream::Debug()
{}

void Stream::Error(const char* msg)
{
    char buffer[128];
    GetError(buffer, ARTS_SIZE(buffer));
    Errorf("%s: %s", msg, buffer);
}

isize Stream::Flush()
{
    isize count = 0;

    if (buffer_read_)
    {
        if (buffer_head_ != buffer_read_)
            count = RawSeek(position_ + buffer_head_);
    }
    else if (buffer_head_)
    {
        count = RawWrite(buffer_, buffer_head_);
    }

    position_ += buffer_head_;
    buffer_read_ = 0;
    buffer_head_ = 0;

    if (count == -1)
        Error("Stream::Flush()");

    return count;
}

isize Stream::Get(u16* values, isize count)
{
    count = Read(values, count * sizeof(*values)) / sizeof(*values);

    if (swap_endian_)
        SwapShorts(values, count);

    return count;
}

isize Stream::Get(u32* values, isize count)
{
    count = Read(values, count * sizeof(*values)) / sizeof(*values);

    if (swap_endian_)
        SwapLongs(values, count);

    return count;
}

isize Stream::GetString(char* buffer, isize buffer_len)
{
    usize len = Get<u32>();

    if (len <= static_cast<u32>(buffer_len)) // TODO: Should this be "<" to ensure a null terminator?
        return Get(reinterpret_cast<u8*>(buffer), len);

    // TODO: Check result of Get()
    Get(reinterpret_cast<u8*>(buffer), buffer_len - 1);
    buffer[buffer_len - 1] = '\0';

    len -= buffer_len - 1;

    // TODO: Use seek?
    for (; len; --len)
        GetCh();

    return buffer_len;
}

ConstString Stream::GetString()
{
    usize length = Get<u32>();

    if (length == 0)
        return nullptr;

    ConstString result {length};
    Read(result.get(), length);
    return result;
}

isize Stream::Printf(ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    isize result = Vprintf(format, va);
    va_end(va);
    return result;
}

i32 Stream::Scanf(const char* format, ...)
{
    std::va_list va;
    va_start(va, format);

    i32 result = Vscanf(format, va);

    va_end(va);
    return result;
}

i32 Stream::Vscanf(const char* format, std::va_list va)
{
    i32 ch = -1;

    do
    {
        ch = GetCh();
    } while (IsSpace(ch));

    UnGetCh(ch);

    char buffer[256];
    isize length = arts_fgets(buffer, ARTS_SIZE(buffer), this);

    if (!length)
        return 0;

    // NOTE: This can not be vsscanf_s because it has to support the game's unsafe format strings.
    //
    // mmCityInfo::Load:
    //     "LocalizedName=%[^\r]"
    //     "MapName=%s"
    //     "RaceDir=%s"
    //     "BlitzNames=%[^\r]"
    //     "CircuitNames=%[^\r]"
    //     "CheckpointNames=%[^\r]"
    //
    // mmVehInfo::Load:
    //     "BaseName=%s",
    //     "Description=%[^\r]"
    //     "Colors=%[^\r]"
    //
    // dxiReadConfigFile:
    //     "InterfaceGuid=%s"
    //     "DriverGuid=%s"
    //
    // TODO: Replace this with vsscanf_s when possible
    i32 result = std::vsscanf(static_cast<const char*>(buffer), format, va);

    if (!result)
        Errorf("scan of '%s' == '%s' failed", format, buffer);

    return result;
}

isize Stream::Gets(char* buffer, isize buffer_len)
{
    if (buffer_len == 0)
        return 0;

    buffer_len -= 1;

    isize total = 0;

    while (total < buffer_len)
    {
        i32 v = GetCh();

        if (v == -1)
            break;

        buffer[total++] = static_cast<char>(v);

        if (v == '\n')
            break;
    }

    buffer[total] = '\0';

    return total;
}

isize Stream::Put(f32 value)
{
    if (swap_endian_)
        value = ByteSwap(value);

    return Write(&value, sizeof(value)) / sizeof(value);
}

isize Stream::Put(u16 value)
{
    if (swap_endian_)
        value = ByteSwap(value);

    return Write(&value, sizeof(value)) / sizeof(value);
}

isize Stream::Put(u32 value)
{
    if (swap_endian_)
        value = ByteSwap(value);

    return Write(&value, sizeof(value)) / sizeof(value);
}

isize Stream::Put(u8 value)
{
    return Write(&value, sizeof(value)) / sizeof(value);
}

isize Stream::Put(const u16* values, isize count)
{
    if (swap_endian_)
    {
        isize result = 0;

        for (i32 i = 0; i < count; ++i)
            result += Put(values[i]);

        return result;
    }
    else
    {
        return Write(values, sizeof(*values) * count) / sizeof(*values);
    }
}

isize Stream::Put(const u32* values, isize count)
{
    if (swap_endian_)
    {
        isize result = 0;

        for (i32 i = 0; i < count; ++i)
            result += Put(values[i]);

        return result;
    }
    else
    {
        return Write(values, sizeof(*values) * count) / sizeof(*values);
    }
}

isize Stream::Put(const u8* values, isize count)
{
    return Write(values, sizeof(*values) * count) / sizeof(*values);
}

isize Stream::PutString(const char* str)
{
    usize len = std::strlen(str) + 1;
    Put(static_cast<u32>(len));
    return Put(reinterpret_cast<const u8*>(str), len);
}

isize Stream::Read(void* ptr, isize size)
{
    if ((buffer_read_ == 0) && (buffer_head_ != 0) && (Flush() < 0))
        return -1;

    isize total = 0;
    isize buffered = buffer_read_ - buffer_head_;

    if (size > buffered)
    {
        if (buffered != 0)
        {
            std::memcpy(ptr, buffer_ + buffer_head_, buffered);

            ptr = static_cast<u8*>(ptr) + buffered;
            size -= buffered;
            total += buffered;

            buffer_head_ = buffer_read_;
        }

        position_ += buffer_head_;

        if (size > static_cast<isize>(buffer_capacity_))
        {
            isize raw_read = RawRead(ptr, size);

            buffer_head_ = 0;
            buffer_read_ = 0;

            if (raw_read < 0)
                return -1;

            position_ += raw_read;
            total += raw_read;

            return total;
        }

        isize raw_read = RawRead(buffer_, buffer_capacity_);

        buffer_head_ = 0;
        buffer_read_ = raw_read;

        if (raw_read < 0)
        {
            buffer_read_ = 0;
            return -1;
        }
    }

    buffered = buffer_read_ - buffer_head_;

    if (size > buffered)
        size = buffered;

    std::memcpy(ptr, buffer_ + buffer_head_, size);
    buffer_head_ += static_cast<u32>(size);
    total += size;

    return total;
}

i32 Stream::Seek(i32 position)
{
    // TODO: Add origin param, similar to fseek

    if (buffer_read_)
    {
        if (u32 rel_offset = position - position_; rel_offset < buffer_read_)
        {
            buffer_head_ = rel_offset;
            return position;
        }
    }

    if (Flush() < 0)
        return -1;

    position_ = position;

    return RawSeek(position);
}

i32 Stream::Size()
{
    if (Flush() < 0)
        return -1;

    return RawSize();
}

isize Stream::Vprintf(const char* format, std::va_list va)
{
    char buffer[256];
    arts_vsprintf(buffer, format, va);
    return Write(buffer, std::strlen(buffer));
}

isize Stream::Write(const void* ptr, isize size)
{
    if ((buffer_read_ != 0) && (Flush() < 0))
        return -1;

    if (size >= static_cast<isize>(buffer_capacity_))
    {
        if (Flush() < 0)
            return -1;

        isize written = RawWrite(ptr, size);

        if (written < 0)
            written = -1;

        return written;
    }

    isize pending = size;

    if (isize avail = buffer_capacity_ - buffer_head_; pending >= avail)
    {
        std::memcpy(buffer_ + buffer_head_, ptr, avail);
        buffer_head_ = buffer_capacity_;

        ptr = static_cast<const u8*>(ptr) + avail;
        pending -= avail;

        if (Flush() < 0)
            return -1;
    }

    std::memcpy(buffer_ + buffer_head_, ptr, pending);
    buffer_head_ += pending;

    return size;
}

void Stream::RawDebug()
{}

i32 Stream::AlignSize()
{
    return 1;
}

i32 Stream::GetError(char* buf, isize buf_len)
{
    i32 error = errno;
    strerror_s(buf, usize(buf_len), error);
    return error;
}

void Stream::SwapLongs(u32* values, isize count)
{
    ByteSwapN(values, count);
}

void Stream::SwapShorts(u16* values, isize count)
{
    ByteSwapN(values, count);
}

isize arts_fgets(char* buffer, isize buffer_len, Stream* stream)
{
    return stream->Gets(buffer, buffer_len);
}

Stream* arts_fopen(const char* path, const char* mode)
{
    return AsRaw((mode[0] == 'r') ? FileSystem::OpenAny(path, mode[1] != '+', 0, 4096) : HFS.CreateOn(path, 0, 4096));
}

void arts_fprintf(Stream* stream, ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    stream->Vprintf(format, va);
    va_end(va);
}

i32 arts_fscanf(Stream* stream, const char* format, ...)
{
    std::va_list va;
    va_start(va, format);

    i32 result = stream->Vscanf(format, va);

    va_end(va);
    return result;
}

i32 arts_fseek(Stream* stream, i32 offset, i32 origin)
{
    switch (origin)
    {
        case 0: break;
        case 1: offset += stream->Tell(); break;
        case 2: offset += stream->Size(); break;
        default: return -1;
    }

    return stream->Seek(offset);
}
