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

class string
{
public:
    // ??0string@@QAE@XZ
    ARTS_EXPORT string()
    {
        capacity_ = 51;
        data_ = new char[capacity_];
        data_[0] = '\0';
    }

    // ??0string@@QAE@PBD@Z | inline
    ARTS_EXPORT string(const char* str)
    {
        i32 len = static_cast<i32>(std::strlen(str));
        capacity_ = len + 50;
        data_ = new char[capacity_];
        std::memcpy(data_, str, len + 1);
    }

    // ??0string@@QAE@ABV0@@Z | inline
    ARTS_EXPORT string(const string& other)
        : string(other.data_)
    {}

    string(string&& other) noexcept
        : data_(other.data_)
        , capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.capacity_ = 0;
    }

    // ??_Estring@@QAEPAXI@Z | unused
    // ??1string@@QAE@XZ | inline
    ARTS_EXPORT ~string()
    {
        if (data_)
            delete[] data_;
    }

    // ??4string@@QAEXPBD@Z | inline
    ARTS_IMPORT void operator=(const char* arg1);

    // ??Hstring@@QBE?AV0@PBD@Z
    ARTS_IMPORT string operator+(const char* arg1) const;

    // ??Hstring@@QBE?AV0@ABV0@@Z | inline
    ARTS_IMPORT string operator+(const string& arg1) const;

    // ??Ystring@@QAEXD@Z
    ARTS_IMPORT void operator+=(char arg1);

    // ??Ystring@@QAEXPBD@Z
    ARTS_IMPORT void operator+=(const char* arg1);

    // ??Gstring@@QBE?AV0@PBD@Z
    ARTS_IMPORT string operator-(const char* arg1) const;

    // ?Contains@string@@QBEHAAV1@@Z
    ARTS_IMPORT i32 Contains(string& arg1) const;

    // ?DirFileExt@string@@QBEXAAV1@00@Z
    ARTS_IMPORT void DirFileExt(string& arg1, string& arg2, string& arg3) const;

    // ?ExpandEnvs@string@@QAEXXZ
    ARTS_IMPORT void ExpandEnvs();

    // ?FileExists@string@@QBEHXZ
    ARTS_IMPORT i32 FileExists() const;

    // ?Init@string@@QAEXH@Z | inline
    ARTS_IMPORT void Init(i32 arg1);

    // ?NumSubStrings@string@@QBEHXZ
    ARTS_IMPORT i32 NumSubStrings() const;

    // ?SaveName@string@@QAEXABV1@H00@Z
    ARTS_IMPORT void SaveName(const string& arg1, i32 arg2, const string& arg3, const string& arg4);

    // ?SubString@string@@QBE?AV1@H@Z
    ARTS_IMPORT string SubString(i32 arg1) const;

    char* get()
    {
        return data_;
    }

    const char* get() const
    {
        return data_;
    }

    LocString* get_loc() const
    {
        return reinterpret_cast<LocString*>(data_);
    }

private:
    char* data_ {};
    i32 capacity_ {};
};

check_size(string, 0x8);

// ?ExecPath@@3PADA
ARTS_IMPORT extern char ExecPath[128];

// ?ImageExts@@3PADA
ARTS_IMPORT extern char ImageExts[128];

// ?ProjPath@@3PADA
ARTS_IMPORT extern char ProjPath[128];
