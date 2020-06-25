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
