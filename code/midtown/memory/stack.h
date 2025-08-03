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

// #define ARTS_NO_EXCEPTION_CATCHING

// ?DebugLog@@YAXHPAXH@Z
ARTS_EXPORT void DebugLog(i32 tag, void* data, i32 size);

// ?DebugLogInit@@YAXH@Z | unused
void DebugLogInit(b32 reading);

// ?DebugLogShutdown@@YAXXZ
ARTS_EXPORT void DebugLogShutdown();

// ?DumpStackTraceback@@YAXPAHH@Z
void DumpStackTraceback(isize* frames, i32 count);

void LookupAddress(char* buffer, usize buflen, usize address);

i32 StackTraceback(i32 depth, isize* frames, i32 skipped);

// ?StackTraceback@@YAXH@Z
void StackTraceback(i32 depth);

void StackTraceback(i32 depth, i32 skipped);

i32 ExceptionFilter(_EXCEPTION_POINTERS* exception);

#ifndef ARTS_NO_EXCEPTION_CATCHING
#    define ARTS_EXCEPTION_BEGIN \
        __try                    \
        {
#    define ARTS_EXCEPTION_END \
        }                      \
        __except (ExceptionFilter(GetExceptionInformation()))
#else
#    define ARTS_EXCEPTION_BEGIN \
        if constexpr (true)      \
        {
#    define ARTS_EXCEPTION_END \
        }                      \
        else if constexpr (false)
#endif
