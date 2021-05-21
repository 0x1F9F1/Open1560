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
    memory:stack

    0x520130 | void __cdecl LookupAddress(char *,int) | ?LookupAddress@@YAXPADH@Z
    0x5201C0 | void __cdecl InitMap(void) | ?InitMap@@YAXXZ
    0x5204C0 | void __cdecl DoStackTraceback(int,int *) | ?DoStackTraceback@@YAXHPAH@Z
    0x520590 | void __cdecl StackTraceback(int) | ?StackTraceback@@YAXH@Z
    0x5205B0 | int __cdecl LogStackTraceback(int *,int) | ?LogStackTraceback@@YAHPAHH@Z
    0x520670 | void __cdecl DumpStackTraceback(int *,int) | ?DumpStackTraceback@@YAXPAHH@Z
    0x5206C0 | void __cdecl DebugLogInit(int) | ?DebugLogInit@@YAXH@Z
    0x520700 | void __cdecl DebugLogShutdown(void) | ?DebugLogShutdown@@YAXXZ
    0x520720 | void __cdecl DebugLog(int,void *,int) | ?DebugLog@@YAXHPAXH@Z
*/

// #define ARTS_NO_EXCEPTION_CATCHING

// 0x520720 | ?DebugLog@@YAXHPAXH@Z
ARTS_EXPORT void DebugLog(i32 tag, void* data, i32 size);

// 0x5206C0 | ?DebugLogInit@@YAXH@Z | unused
ARTS_EXPORT void DebugLogInit(b32 reading);

// 0x520700 | ?DebugLogShutdown@@YAXXZ
ARTS_EXPORT void DebugLogShutdown();

// 0x5204C0 | ?DoStackTraceback@@YAXHPAH@Z
ARTS_EXPORT void DoStackTraceback(i32 depth, isize* frame);

// 0x520670 | ?DumpStackTraceback@@YAXPAHH@Z
ARTS_EXPORT void DumpStackTraceback(isize* frames, i32 count);

// 0x5205B0 | ?LogStackTraceback@@YAHPAHH@Z
[[deprecated]] ARTS_EXPORT i32 LogStackTraceback(isize* frames, i32 count);

void LookupAddress(char* buffer, usize buflen, usize address);

// 0x520130 | ?LookupAddress@@YAXPADH@Z
// void LookupAddress(char* buffer, i32 address);

i32 StackTraceback(i32 depth, isize* frames, i32 skipped);

// 0x520590 | ?StackTraceback@@YAXH@Z
ARTS_EXPORT void StackTraceback(i32 depth);

void StackTraceback(i32 depth, i32 skipped);

i32 ExceptionFilter(struct _EXCEPTION_POINTERS* exception);

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
