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

#define arts_vsprintf vsprintf_s
#define arts_sprintf sprintf_s
#define arts_strcpy strcpy_s
#define arts_strncpy strncpy_s
#define arts_strcat strcat_s
#define arts_sscanf sscanf_s

#define arts_stricmp _stricmp

class CString
{
public:
    CString()
        : data_(nullptr)
    {}

    CString(std::nullptr_t)
        : data_(nullptr)
    {}

    CString(const char* value)
    {
        assign(value);
    }

    CString(const CString& other)
        : CString(other.data_)
    {}

    CString(CString&& other)
    {
        data_ = other.data_;
        other.data_ = nullptr;
    }

    ~CString()
    {
        delete[] data_;
    }

    CString& operator=(const char* value)
    {
        assign(value);

        return *this;
    }

    CString& operator=(const CString& value)
    {
        assign(value.data_);

        return *this;
    }

    CString& operator=(CString&& value)
    {
        delete[] data_;
        data_ = value.data_;
        value.data_ = nullptr;

        return *this;
    }

    void assign(const char* value)
    {
        delete[] data_;
        data_ = CString::StrDup(value);
    }

    char* get()
    {
        return data_;
    }

    const char* get() const
    {
        return data_;
    }

    static char* StrDup(const char* value);

private:
    char* data_ {nullptr};
};

static_assert(sizeof(CString) == sizeof(char*));

template <usize N>
class CStringBuffer
{
public:
    static_assert(N != 0, "Cannot have an empty string buffer");

    CStringBuffer()
        : buffer_ {}
    {}

    CStringBuffer(const char* value)
    {
        assign(value);
    }

    CStringBuffer& operator=(const char* value)
    {
        assign(value);

        return *this;
    }

    void assign(const char* value)
    {
        arts_strcpy(buffer_, value);
    }

    void append(const char* value)
    {
        arts_strcat(buffer_, value);
    }

    void formatf(const char* format, ...)
    {
        std::va_list va;
        va_start(va, format);
        arts_vsprintf(buffer_, format, va);
        va_end(va);
    }

    char* get()
    {
        return buffer_;
    }

    const char* get() const
    {
        return buffer_;
    }

private:
    char buffer_[N] {};
};
