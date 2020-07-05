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

define_dummy_symbol(agi_error);

#include "error.h"

void agiDisplayf(char const* format, ...)
{
    if (agiVerbose)
    {
        std::va_list va;
        va_start(va, format);
        Printer(0, format, va);
        va_end(va);
    }
}

const char* agiGetError(i32 error)
{
    switch (error)
    {
        case AGI_ERROR_SUCCESS: return "No error";

        case AGI_ERROR_FILE_NOT_FOUND: return "File not found";
        case AGI_ERROR_OBJECT_EMPTY: return "Object is empty";
        case AGI_ERROR_ALREADY_INITIALIZED: return "Object is already realized";
        case AGI_ERROR_BAD_FORMAT: return "File has bad or unknown format";

        default: return "Unknown error";
    }
}
