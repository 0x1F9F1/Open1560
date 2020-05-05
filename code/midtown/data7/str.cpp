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
    unimplemented();
}

string::string(char const* arg1)
{
    unimplemented(arg1);
}

string::string(class string const& arg1)
{
    unimplemented(arg1);
}

string::~string()
{
    unimplemented();
}

void string::operator=(char const* arg1)
{
    return stub<thiscall_t<void, string*, char const*>>(0x17B320_Offset, this, arg1);
}

class string string::operator+(char const* arg1)
{
    return stub<thiscall_t<class string, string*, char const*>>(0x179510_Offset, this, arg1);
}

class string string::operator+(class string const& arg1)
{
    return stub<thiscall_t<class string, string*, class string const&>>(0x17B380_Offset, this, arg1);
}

void string::operator+=(char arg1)
{
    return stub<thiscall_t<void, string*, char>>(0x179860_Offset, this, arg1);
}

void string::operator+=(char const* arg1)
{
    return stub<thiscall_t<void, string*, char const*>>(0x179770_Offset, this, arg1);
}

class string string::operator-(char const* arg1)
{
    return stub<thiscall_t<class string, string*, char const*>>(0x179900_Offset, this, arg1);
}

void string::operator-=(char const* arg1)
{
    return stub<thiscall_t<void, string*, char const*>>(0x179A60_Offset, this, arg1);
}

void string::ChangeExtension(class string const& arg1)
{
    return stub<thiscall_t<void, string*, class string const&>>(0x17A950_Offset, this, arg1);
}

i32 string::CommaFile()
{
    return stub<thiscall_t<i32, string*>>(0x17A4A0_Offset, this);
}

i32 string::Contains(class string& arg1)
{
    return stub<thiscall_t<i32, string*, class string&>>(0x179C60_Offset, this, arg1);
}

void string::DirFileExt(class string& arg1, class string& arg2, class string& arg3)
{
    return stub<thiscall_t<void, string*, class string&, class string&, class string&>>(
        0x17A290_Offset, this, arg1, arg2, arg3);
}

void string::ExpandEnvs()
{
    return stub<thiscall_t<void, string*>>(0x17AB10_Offset, this);
}

class string string::Extension()
{
    return stub<thiscall_t<class string, string*>>(0x17A800_Offset, this);
}

i32 string::FileExists()
{
    return stub<thiscall_t<i32, string*>>(0x17A260_Offset, this);
}

class string string::FileName()
{
    return stub<thiscall_t<class string, string*>>(0x17A6A0_Offset, this);
}

i32 string::FindFile(class string const& arg1, i32 arg2, class string const& arg3, class string const& arg4)
{
    return stub<thiscall_t<i32, string*, class string const&, i32, class string const&, class string const&>>(
        0x179ED0_Offset, this, arg1, arg2, arg3, arg4);
}

void string::Init(i32 arg1)
{
    return stub<thiscall_t<void, string*, i32>>(0x9A6F0_Offset, this, arg1);
}

i32 string::IsNumeric()
{
    return stub<thiscall_t<i32, string*>>(0x17AE10_Offset, this);
}

void string::MinusEqual(char arg1)
{
    return stub<thiscall_t<void, string*, char>>(0x179B10_Offset, this, arg1);
}

i32 string::NumSubStrings()
{
    return stub<thiscall_t<i32, string*>>(0x17ADC0_Offset, this);
}

void string::RemoveExtension()
{
    return stub<thiscall_t<void, string*>>(0x17AAD0_Offset, this);
}

void string::SaveName(class string const& arg1, i32 arg2, class string const& arg3, class string const& arg4)
{
    return stub<thiscall_t<void, string*, class string const&, i32, class string const&, class string const&>>(
        0x179D00_Offset, this, arg1, arg2, arg3, arg4);
}

class string string::SubString(i32 arg1)
{
    return stub<thiscall_t<class string, string*, i32>>(0x17ACB0_Offset, this, arg1);
}

class string operator+(char const* arg1, class string const& arg2)
{
    return stub<cdecl_t<class string, char const*, class string const&>>(0x179640_Offset, arg1, arg2);
}

void StringArray::operator=(class StringArray& arg1)
{
    return stub<thiscall_t<void, StringArray*, class StringArray&>>(0x17B050_Offset, this, arg1);
}

class string& StringArray::operator[](i32 arg1)
{
    return stub<thiscall_t<class string&, StringArray*, i32>>(0x17AFA0_Offset, this, arg1);
}

void StringArray::BlockCopy(class StringArray& arg1)
{
    return stub<thiscall_t<void, StringArray*, class StringArray&>>(0x17B1F0_Offset, this, arg1);
}

void StringArray::Delete()
{
    return stub<thiscall_t<void, StringArray*>>(0x17AED0_Offset, this);
}

void StringArray::Init(i32 arg1)
{
    return stub<thiscall_t<void, StringArray*, i32>>(0x17AE60_Offset, this, arg1);
}

void StringArray::NewTable(i32 arg1)
{
    return stub<thiscall_t<void, StringArray*, i32>>(0x17AF30_Offset, this, arg1);
}
