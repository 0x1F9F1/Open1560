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

define_dummy_symbol(data7_str);

#include "str.h"

string::string()
{
    capacity_ = 51;
    data_ = new char[capacity_];
    data_[0] = '\0';
}

string::string(char const* str)
{
    i32 len = static_cast<i32>(std::strlen(str));
    capacity_ = len + 50;
    data_ = new char[capacity_];
    std::memcpy(data_, str, len + 1);
}

string::string(class string const& other)
    : string(other.data_)
{}

string::string(string&& other)
    : data_(other.data_)
    , capacity_(other.capacity_)
{
    other.data_ = nullptr;
    other.capacity_ = 0;
}

string::~string()
{
    if (data_)
        delete[] data_;
}

void string::operator=(char const* arg1)
{
    return stub<thiscall_t<void, string*, char const*>>(0x57B320, this, arg1);
}

class string string::operator+(char const* arg1)
{
    return stub<thiscall_t<class string, string*, char const*>>(0x579510, this, arg1);
}

class string string::operator+(class string const& arg1)
{
    return stub<thiscall_t<class string, string*, class string const&>>(0x57B380, this, arg1);
}

void string::operator+=(char arg1)
{
    return stub<thiscall_t<void, string*, char>>(0x579860, this, arg1);
}

void string::operator+=(char const* arg1)
{
    return stub<thiscall_t<void, string*, char const*>>(0x579770, this, arg1);
}

class string string::operator-(char const* arg1)
{
    return stub<thiscall_t<class string, string*, char const*>>(0x579900, this, arg1);
}

void string::operator-=(char const* arg1)
{
    return stub<thiscall_t<void, string*, char const*>>(0x579A60, this, arg1);
}

void string::ChangeExtension(class string const& arg1)
{
    return stub<thiscall_t<void, string*, class string const&>>(0x57A950, this, arg1);
}

i32 string::CommaFile()
{
    return stub<thiscall_t<i32, string*>>(0x57A4A0, this);
}

i32 string::Contains(class string& arg1)
{
    return stub<thiscall_t<i32, string*, class string&>>(0x579C60, this, arg1);
}

void string::DirFileExt(class string& arg1, class string& arg2, class string& arg3)
{
    return stub<thiscall_t<void, string*, class string&, class string&, class string&>>(
        0x57A290, this, arg1, arg2, arg3);
}

void string::ExpandEnvs()
{
    return stub<thiscall_t<void, string*>>(0x57AB10, this);
}

class string string::Extension()
{
    return stub<thiscall_t<class string, string*>>(0x57A800, this);
}

i32 string::FileExists()
{
    return stub<thiscall_t<i32, string*>>(0x57A260, this);
}

class string string::FileName()
{
    return stub<thiscall_t<class string, string*>>(0x57A6A0, this);
}

i32 string::FindFile(class string const& arg1, i32 arg2, class string const& arg3, class string const& arg4)
{
    return stub<thiscall_t<i32, string*, class string const&, i32, class string const&, class string const&>>(
        0x579ED0, this, arg1, arg2, arg3, arg4);
}

void string::Init(i32 arg1)
{
    return stub<thiscall_t<void, string*, i32>>(0x49A6F0, this, arg1);
}

i32 string::IsNumeric()
{
    return stub<thiscall_t<i32, string*>>(0x57AE10, this);
}

void string::MinusEqual(char arg1)
{
    return stub<thiscall_t<void, string*, char>>(0x579B10, this, arg1);
}

i32 string::NumSubStrings()
{
    return stub<thiscall_t<i32, string*>>(0x57ADC0, this);
}

void string::RemoveExtension()
{
    return stub<thiscall_t<void, string*>>(0x57AAD0, this);
}

void string::SaveName(class string const& arg1, i32 arg2, class string const& arg3, class string const& arg4)
{
    return stub<thiscall_t<void, string*, class string const&, i32, class string const&, class string const&>>(
        0x579D00, this, arg1, arg2, arg3, arg4);
}

class string string::SubString(i32 arg1)
{
    return stub<thiscall_t<class string, string*, i32>>(0x57ACB0, this, arg1);
}

class string operator+(char const* arg1, class string const& arg2)
{
    return stub<cdecl_t<class string, char const*, class string const&>>(0x579640, arg1, arg2);
}

#if 0
void StringArray::operator=(class StringArray& arg1)
{
    return stub<thiscall_t<void, StringArray*, class StringArray&>>(0x57B050, this, arg1);
}

class string& StringArray::operator[](i32 arg1)
{
    return stub<thiscall_t<class string&, StringArray*, i32>>(0x57AFA0, this, arg1);
}

void StringArray::BlockCopy(class StringArray& arg1)
{
    return stub<thiscall_t<void, StringArray*, class StringArray&>>(0x57B1F0, this, arg1);
}

void StringArray::Delete()
{
    return stub<thiscall_t<void, StringArray*>>(0x57AED0, this);
}

void StringArray::Init(i32 arg1)
{
    return stub<thiscall_t<void, StringArray*, i32>>(0x57AE60, this, arg1);
}

void StringArray::NewTable(i32 arg1)
{
    return stub<thiscall_t<void, StringArray*, i32>>(0x57AF30, this, arg1);
}
#endif
