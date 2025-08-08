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

#include "string.h"

#include <stdlib.h>

ARTS_NOINLINE char* arts_strdup(const char* str)
{
    char* ptr = nullptr;

    if (str)
    {
        usize length = std::strlen(str) + 1;

        ptr = static_cast<char*>(arts_malloc(length));

        if (ptr)
            std::memcpy(ptr, str, length);
    }

    return ptr;
}

ConstString arts_getenv(const char* name)
{
    char* buffer;

    if (_dupenv_s(&buffer, nullptr, name))
        return nullptr;

    ConstString result {buffer};
    free(buffer);
    return result;
}