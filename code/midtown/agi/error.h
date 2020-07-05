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

/*
    agi:error

    0x55BE20 | char * __cdecl agiGetError(int) | ?agiGetError@@YAPADH@Z
    0x55BE80 | void __cdecl agiDisplayf(char const *,...) | ?agiDisplayf@@YAXPBDZZ
    0x907230 | int agiVerbose | ?agiVerbose@@3HA
*/

#define AGI_ERROR_SUCCESS 0
#define AGI_ERROR_FILE_NOT_FOUND -1
#define AGI_ERROR_OBJECT_EMPTY -2
#define AGI_ERROR_ALREADY_INITIALIZED -3
#define AGI_ERROR_BAD_FORMAT -4

// 0x55BE80 | ?agiDisplayf@@YAXPBDZZ
ARTS_EXPORT void agiDisplayf(char const* format, ...);

// 0x55BE20 | ?agiGetError@@YAPADH@Z
ARTS_EXPORT const char* agiGetError(i32 error);

// 0x907230 | ?agiVerbose@@3HA
ARTS_IMPORT extern i32 agiVerbose;
