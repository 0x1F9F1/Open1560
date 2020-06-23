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
    eventq7:geinputLib

    0x563DE0 | int __cdecl inputSetup(int,int,int,int,int) | ?inputSetup@@YAHHHHHH@Z
    0x564050 | char * __cdecl DIError(int) | ?DIError@@YAPADH@Z
    0x564200 | void __cdecl geinputAcquireMouse(void) | ?geinputAcquireMouse@@YAXXZ
    0x564210 | void __cdecl geinputUnacquireMouse(void) | ?geinputUnacquireMouse@@YAXXZ
    0x564220 | int __cdecl geinputGetBufferedKeyboard(char *) | ?geinputGetBufferedKeyboard@@YAHPAD@Z
    0x5642B0 | char * __cdecl geinputGetKeyboard(void) | ?geinputGetKeyboard@@YAPADXZ
    0x564320 | void __cdecl geinputGetMouse(long *,long *,char *,char *,long *,long *,long *,char *) | ?geinputGetMouse@@YAXPAJ0PAD10001@Z
    0x564570 | void __cdecl geinputCleanup(void) | ?geinputCleanup@@YAXXZ
    0x564610 | void __cdecl geinputClearCache(void) | ?geinputClearCache@@YAXXZ
    0x9092C0 | struct _DIMOUSESTATE MOUSESTATE | ?MOUSESTATE@@3U_DIMOUSESTATE@@A
*/

// 0x564200 | ?geinputAcquireMouse@@YAXXZ | unused
void geinputAcquireMouse();

// 0x564570 | ?geinputCleanup@@YAXXZ
void geinputCleanup();

// 0x564610 | ?geinputClearCache@@YAXXZ | unused
void geinputClearCache();

// 0x564220 | ?geinputGetBufferedKeyboard@@YAHPAD@Z
i32 geinputGetBufferedKeyboard(char* arg1);

// 0x5642B0 | ?geinputGetKeyboard@@YAPADXZ
char* geinputGetKeyboard();

// 0x564320 | ?geinputGetMouse@@YAXPAJ0PAD10001@Z
void geinputGetMouse(i32* arg1, i32* arg2, char* arg3, char* arg4, i32* arg5, i32* arg6, i32* arg7, char* arg8);

// 0x564210 | ?geinputUnacquireMouse@@YAXXZ | unused
void geinputUnacquireMouse();

// 0x563DE0 | ?inputSetup@@YAHHHHHH@Z
i32 inputSetup(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

// 0x9092C0 | ?MOUSESTATE@@3U_DIMOUSESTATE@@A
inline extern_var(0x9092C0, struct _DIMOUSESTATE, MOUSESTATE);
