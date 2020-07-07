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

#include <cstdarg>

#include "memory/stub.h"

#define arts_vsprintf vsprintf_s
#define arts_sprintf sprintf_s

#define arts_vsscanf vsscanf_s
#define arts_sscanf sscanf_s

#define arts_strcpy strcpy_s
#define arts_strncpy strncpy_s
#define arts_strcat strcat_s

#define arts_stricmp _stricmp

char* arts_strdup(const char* str);

class CString
{
public:
    ARTS_FORCEINLINE constexpr CString() = default;

    ARTS_FORCEINLINE constexpr CString(std::nullptr_t)
        : data_(nullptr)
    {}

    ARTS_FORCEINLINE CString(const char* value)
        : data_(arts_strdup(value))
    {}

    ARTS_FORCEINLINE CString(const CString& other)
        : CString(other.data_)
    {}

    ARTS_FORCEINLINE CString(CString&& other)
    {
        data_ = other.data_;
        other.data_ = nullptr;
    }

    ARTS_FORCEINLINE ~CString()
    {
        if (data_)
            arts_free(data_);
    }

    ARTS_FORCEINLINE CString& operator=(const char* value)
    {
        assign(value);

        return *this;
    }

    ARTS_FORCEINLINE CString& operator=(const CString& value)
    {
        assign(value.data_);

        return *this;
    }

    ARTS_FORCEINLINE CString& operator=(CString&& value)
    {
        if (data_)
            arts_free(data_);

        data_ = value.data_;
        value.data_ = nullptr;

        return *this;
    }

    ARTS_FORCEINLINE void assign(const char* value)
    {
        if (data_)
            arts_free(data_);

        data_ = value ? arts_strdup(value) : nullptr;
    }

    ARTS_FORCEINLINE void reset()
    {
        if (data_)
        {
            arts_free(data_);
            data_ = nullptr;
        }
    }

    ARTS_FORCEINLINE char* get()
    {
        return data_;
    }

    ARTS_FORCEINLINE const char* get() const
    {
        return data_;
    }

private:
    char* data_ {nullptr};
};

static_assert(sizeof(CString) == sizeof(char*));

template <usize N>
class CStringBuffer
{
public:
    static_assert(N != 0, "Cannot have an empty string buffer");

    ARTS_FORCEINLINE CStringBuffer()
    {
        buffer_[0] = '\0';
    }

    ARTS_FORCEINLINE CStringBuffer(const char* value)
    {
        assign(value);
    }

    ARTS_FORCEINLINE CStringBuffer& operator=(const char* value)
    {
        assign(value);

        return *this;
    }

    ARTS_FORCEINLINE void clear()
    {
        buffer_[0] = '\0';
    }

    ARTS_FORCEINLINE void assign(const char* value)
    {
        arts_strcpy(buffer_, value);
    }

    ARTS_FORCEINLINE void assign(const char* value, usize len)
    {
        arts_strncpy(buffer_, value, len);
    }

    ARTS_FORCEINLINE void append(const char* value)
    {
        arts_strcat(buffer_, value);
    }

    ARTS_FORCEINLINE void append(const char* value, usize len)
    {
        arts_strncat(buffer_, value, len);
    }

    inline void sprintf(const char* format, ...)
    {
        std::va_list va;
        va_start(va, format);
        arts_vsprintf(buffer_, format, va);
        va_end(va);
    }

    ARTS_FORCEINLINE void vsprintf(const char* format, std::va_list va)
    {
        arts_vsprintf(buffer_, format, va);
    }

    ARTS_FORCEINLINE char* get()
    {
        return buffer_;
    }

    ARTS_FORCEINLINE const char* get() const
    {
        return buffer_;
    }

    ARTS_FORCEINLINE operator const char*() const
    {
        return buffer_;
    }

    static ARTS_FORCEINLINE constexpr usize capacity()
    {
        return N;
    }

private:
    char buffer_[N];
};

class CStringBuilder
{
public:
    ARTS_FORCEINLINE constexpr CStringBuilder(char* buffer, usize capacity)
        : buffer_(buffer)
        , capacity_(capacity)
    {}

    ARTS_FORCEINLINE ~CStringBuilder()
    {
        buffer_[(written_ < capacity_) ? written_ : 0] = '\0';
    }

    ARTS_FORCEINLINE void operator+=(const char* str)
    {
        append(str, std::strlen(str));
    }

    ARTS_FORCEINLINE void operator+=(char c)
    {
        if (written_ < capacity_)
        {
            buffer_[written_++] = c;
        }
    }

    inline void append(const char* str, usize len)
    {
        if (written_ + len >= capacity_)
        {
            written_ = capacity_;

            return;
        }

        std::memcpy(buffer_ + written_, str, len);
        written_ += len;
    }

private:
    char* buffer_ {nullptr};
    usize capacity_ {0};
    usize written_ {0};
};

inline bool IsSpace(i32 value)
{
    return (value == '\t' || value == '\n' || value == '\r' || value == ' ');
}

inline bool IsDigit(i32 value)
{
    return (value >= '0' && value <= '9');
}

inline bool IsLetter(i32 value)
{
    return (value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z');
}
