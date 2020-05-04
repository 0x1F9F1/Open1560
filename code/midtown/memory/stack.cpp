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

#include "stack.h"

void DebugLog(i32 arg1, void* arg2, i32 arg3)
{
    return stub<cdecl_t<void, i32, void*, i32>>(0x120720_Offset, arg1, arg2, arg3);
}

void DebugLogInit(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x1206C0_Offset, arg1);
}

void DebugLogShutdown()
{
    return stub<cdecl_t<void>>(0x120700_Offset);
}

void DoStackTraceback(i32 arg1, i32* arg2)
{
    return stub<cdecl_t<void, i32, i32*>>(0x1204C0_Offset, arg1, arg2);
}

void DumpStackTraceback(i32* arg1, i32 arg2)
{
    return stub<cdecl_t<void, i32*, i32>>(0x120670_Offset, arg1, arg2);
}

i32 LogStackTraceback(i32* arg1, i32 arg2)
{
    return stub<cdecl_t<i32, i32*, i32>>(0x1205B0_Offset, arg1, arg2);
}

void LookupAddress(char* arg1, i32 arg2)
{
    return stub<cdecl_t<void, char*, i32>>(0x120130_Offset, arg1, arg2);
}

void StackTraceback(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x120590_Offset, arg1);
}

define_dummy_symbol(memory_stack);
