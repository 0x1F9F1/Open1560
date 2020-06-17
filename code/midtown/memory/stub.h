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
    memory:stub

    0x5214F0 | _malloc
    0x521510 | _realloc
    0x521530 | _calloc
    0x521570 | _free
    0x5215A0 | void * __cdecl operator new(unsigned int) | ??2@YAPAXI@Z
    0x5215C0 | void __cdecl operator delete(void *) | ??3@YAXPAX@Z
*/

// 0x5215C0 | ??3@YAXPAX@Z

// 0x5215A0 | ??2@YAPAXI@Z

// 0x521530 | _calloc
ARTS_EXPORT void* arts_calloc(std::size_t num, std::size_t size);

// 0x521570 | _free
ARTS_EXPORT void arts_free(void* ptr);

// 0x5214F0 | _malloc
ARTS_EXPORT void* arts_malloc(std::size_t size);

// 0x521510 | _realloc
ARTS_EXPORT void* arts_realloc(void* ptr, std::size_t size);
