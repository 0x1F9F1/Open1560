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
    0x5204C0 | void __cdecl DoStackTraceback(int,int *) | ?DoStackTraceback@@YAXHPAH@Z
    0x520590 | void __cdecl StackTraceback(int) | ?StackTraceback@@YAXH@Z
    0x5205B0 | int __cdecl LogStackTraceback(int *,int) | ?LogStackTraceback@@YAHPAHH@Z
    0x520670 | void __cdecl DumpStackTraceback(int *,int) | ?DumpStackTraceback@@YAXPAHH@Z
    0x5206C0 | void __cdecl DebugLogInit(int) | ?DebugLogInit@@YAXH@Z
    0x520700 | void __cdecl DebugLogShutdown(void) | ?DebugLogShutdown@@YAXXZ
    0x520720 | void __cdecl DebugLog(int,void *,int) | ?DebugLog@@YAXHPAXH@Z
*/

// 0x520720 | ?DebugLog@@YAXHPAXH@Z
void DebugLog(i32 arg1, void* arg2, i32 arg3);

// 0x5206C0 | ?DebugLogInit@@YAXH@Z
void DebugLogInit(i32 arg1);

// 0x520700 | ?DebugLogShutdown@@YAXXZ
void DebugLogShutdown();

// 0x5204C0 | ?DoStackTraceback@@YAXHPAH@Z
void DoStackTraceback(i32 arg1, i32* arg2);

// 0x520670 | ?DumpStackTraceback@@YAXPAHH@Z
void DumpStackTraceback(i32* arg1, i32 arg2);

// 0x5205B0 | ?LogStackTraceback@@YAHPAHH@Z
i32 LogStackTraceback(i32* arg1, i32 arg2);

void LookupAddress(char* buffer, usize buflen, usize address);

// 0x520130 | ?LookupAddress@@YAXPADH@Z
void LookupAddress(char* buffer, i32 address);

// 0x520590 | ?StackTraceback@@YAXH@Z
void StackTraceback(i32 arg1);
