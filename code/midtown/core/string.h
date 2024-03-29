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

#define ARTS_TRUNCATE _TRUNCATE

#define arts_sprintf sprintf_s
#define arts_snprintf _snprintf_s

#define arts_vsprintf vsprintf_s
#define arts_vsnprintf _vsnprintf_s

#define arts_vsscanf vsscanf_s
#define arts_sscanf sscanf_s

#define arts_strcpy strcpy_s
#define arts_strncpy strncpy_s

#define arts_strcat strcat_s
#define arts_strncat strncat_s

#define arts_stricmp _stricmp
#define arts_strnicmp _strnicmp
#define arts_strupr _strupr_s

#define arts_strtok strtok_s

char* arts_strdup(const char* str); // StringDuplicate
char* arts_getenv(const char* name);

class Stream;

class ConstString
{
public:
    constexpr ConstString() noexcept = default;

    constexpr ConstString(std::nullptr_t) noexcept
        : data_(nullptr)
    {}

    explicit ConstString(const char* value)
        : data_(arts_strdup(value))
    {}

    explicit ConstString(usize capacity)
        : data_(static_cast<char*>(arts_malloc(capacity)))
    {}

    ConstString(const ConstString& other)
        : ConstString(other.data_)
    {}

    ConstString(ConstString&& other) noexcept
    {
        data_ = other.data_;
        other.data_ = nullptr;
    }

    ~ConstString() noexcept
    {
        if (data_)
            arts_free(data_);
    }

    ConstString& operator=(const char* value)
    {
        assign(value);

        return *this;
    }

    ConstString& operator=(const ConstString& value)
    {
        assign(value.data_);

        return *this;
    }

    ConstString& operator=(ConstString&& value) noexcept
    {
        if (data_)
            arts_free(data_);

        data_ = value.data_;
        value.data_ = nullptr;

        return *this;
    }

    void assign(const char* value)
    {
        if (data_)
            arts_free(data_);

        data_ = value ? arts_strdup(value) : nullptr;
    }

    void reset()
    {
        if (data_)
        {
            arts_free(data_);
            data_ = nullptr;
        }
    }

    char* get() noexcept
    {
        return data_;
    }

    const char* get() const noexcept
    {
        return data_;
    }

    char& operator[](usize index) noexcept
    {
        return data_[index];
    }

    const char& operator[](usize index) const noexcept
    {
        return data_[index];
    }

    explicit operator bool() const noexcept
    {
        return data_ != nullptr;
    }

private:
    char* data_ {};
};

static_assert(sizeof(ConstString) == sizeof(char*));

class arts_format_t
{};

class arts_vformat_t
{};

template <usize N>
class CStringBuffer
{
public:
    static_assert(N != 0, "Cannot have an empty string buffer");

    CStringBuffer()
    {
        buffer_[0] = '\0';
    }

    CStringBuffer(const char* value)
    {
        assign(value);
    }

    CStringBuffer(arts_vformat_t, ARTS_FORMAT_STRING const char* format, std::va_list va)
    {
        arts_vsprintf(buffer_, format, va);
    }

    CStringBuffer(arts_format_t, ARTS_FORMAT_STRING const char* format, ...)
    {
        std::va_list va;
        va_start(va, format);
        arts_vsprintf(buffer_, format, va);
        va_end(va);
    }

    void clear()
    {
        buffer_[0] = '\0';
    }

    void assign(const char* value)
    {
        arts_strcpy(buffer_, value);
    }

    void assign(const char* value, usize len)
    {
        arts_strncpy(buffer_, value, len);
    }

    void append(const char* value)
    {
        arts_strcat(buffer_, value);
    }

    void append(const char* value, usize len)
    {
        arts_strncat(buffer_, value, len);
    }

    char* get()
    {
        return buffer_;
    }

    const char* get() const
    {
        return buffer_;
    }

    operator char*()
    {
        return buffer_;
    }

    operator const char*() const
    {
        return buffer_;
    }

    static constexpr usize capacity()
    {
        return N;
    }

private:
    char buffer_[N];
};

class CStringBuilder
{
public:
    constexpr CStringBuilder(char* buffer, usize capacity)
        : buffer_(buffer)
        , capacity_(capacity)
    {}

    ~CStringBuilder()
    {
        buffer_[(written_ < capacity_) ? written_ : 0] = '\0';
    }

    void operator+=(const char* str)
    {
        append(str, std::strlen(str));
    }

    void operator+=(char c)
    {
        if (written_ < capacity_)
        {
            buffer_[written_++] = c;
        }
    }

    void append(const char* str, usize len)
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
    char* buffer_ {};
    usize capacity_ {};
    usize written_ {};
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

inline bool operator==(const ConstString& lhs, const ConstString& rhs)
{
    return std::strcmp(lhs.get(), rhs.get()) == 0;
}

inline bool operator==(const ConstString& lhs, const char* rhs)
{
    return std::strcmp(lhs.get(), rhs) == 0;
}

inline bool operator==(const char* lhs, const ConstString& rhs)
{
    return std::strcmp(lhs, rhs.get()) == 0;
}

inline bool operator!=(const ConstString& lhs, const ConstString& rhs)
{
    return std::strcmp(lhs.get(), rhs.get()) != 0;
}

inline bool operator!=(const ConstString& lhs, const char* rhs)
{
    return std::strcmp(lhs.get(), rhs) != 0;
}

inline bool operator!=(const char* lhs, const ConstString& rhs)
{
    return std::strcmp(lhs, rhs.get()) != 0;
}

template <usize N, typename... Args>
ARTS_FORCEINLINE CStringBuffer<N> arts_formatf(const char* format, const Args&... args)
{
    return CStringBuffer<N> {arts_format_t {}, format, args...};
}

template <usize N>
ARTS_FORCEINLINE CStringBuffer<N> arts_vformatf(const char* format, std::va_list va)
{
    return CStringBuffer<N> {arts_vformat_t {}, format, va};
}
