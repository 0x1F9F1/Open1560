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
    data7:printer

    0x5769C0 | void __cdecl DefaultPrinter(int,char const *,char *) | ?DefaultPrinter@@YAXHPBDPAD@Z
    0x576C70 | void __cdecl Displayf(char const *,...) | ?Displayf@@YAXPBDZZ
    0x576C90 | void __cdecl Printf(char const *,...) | ?Printf@@YAXPBDZZ
    0x576CB0 | void __cdecl Debugf(char const *,...) | ?Debugf@@YAXPBDZZ
    0x576CD0 | void __cdecl Warningf(char const *,...) | ?Warningf@@YAXPBDZZ
    0x576CF0 | void __cdecl Errorf(char const *,...) | ?Errorf@@YAXPBDZZ
    0x576D10 | void __cdecl PErrorf(char const *,...) | ?PErrorf@@YAXPBDZZ
    0x576D60 | void __cdecl PDebug(char const *,...) | ?PDebug@@YAXPBDZZ
    0x576DB0 | void __cdecl Abortf(char const *,...) | ?Abortf@@YAXPBDZZ
    0x576DD0 | void __cdecl Quit(char const *) | ?Quit@@YAXPBD@Z
    0x576E00 | int __cdecl LogToCommPort(int,int) | ?LogToCommPort@@YAHHH@Z
    0x576E90 | void __cdecl LogToMonochromeMonitor(void) | ?LogToMonochromeMonitor@@YAXXZ
    0x576EA0 | void __cdecl LogToFile(char *) | ?LogToFile@@YAXPAD@Z
    0x576F00 | void __cdecl LogToFile(void) | ?LogToFile@@YAXXZ
    0x661AA4 | int EnableNormalOutput | ?EnableNormalOutput@@3HA
    0x661AA8 | int EnableDebugOutput | ?EnableDebugOutput@@3HA
    0x661AB8 | void (__cdecl* Printer)(int,char const *,char *) | ?Printer@@3P6AXHPBDPAD@ZA
    0x661AC0 | char * __assertFailed | ?__assertFailed@@3PADA
    0x90A680 | int MessageFirst | ?MessageFirst@@3HA
    0x90A684 | unsigned short * MonoPointer | ?MonoPointer@@3PAGA
    0x90A688 | char (* MessageFifo)[80] | ?MessageFifo@@3PAY0FA@DA
*/

#include <cstdarg>

// 0x576C70 | ?Displayf@@YAXPBDZZ
void Displayf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576C90 | ?Printf@@YAXPBDZZ | unused
void Printf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576CB0 | ?Debugf@@YAXPBDZZ
void Debugf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576CD0 | ?Warningf@@YAXPBDZZ
void Warningf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576CF0 | ?Errorf@@YAXPBDZZ
void Errorf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576D10 | ?PErrorf@@YAXPBDZZ | unused
void PErrorf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576D60 | ?PDebug@@YAXPBDZZ | unused
void PDebug(ARTS_FORMAT_STRING char const* format, ...);

// 0x576DB0 | ?Abortf@@YAXPBDZZ
[[noreturn]] void Abortf(ARTS_FORMAT_STRING char const* format, ...);

// 0x5769C0 | ?DefaultPrinter@@YAXHPBDPAD@Z
void DefaultPrinter(i32 level, char const* format, std::va_list args);

// 0x576E00 | ?LogToCommPort@@YAHHH@Z
i32 LogToCommPort(i32 arg1, i32 arg2);

// 0x576F00 | ?LogToFile@@YAXXZ
void LogToFile();

// 0x576EA0 | ?LogToFile@@YAXPAD@Z
void LogToFile(const char* file);

// 0x576E90 | ?LogToMonochromeMonitor@@YAXXZ
void LogToMonochromeMonitor();

// 0x576DD0 | ?Quit@@YAXPBD@Z
void Quit(char const* message);

// 0x661AA8 | ?EnableDebugOutput@@3HA
inline extern_var(0x661AA8, i32, EnableDebugOutput);

// 0x661AA4 | ?EnableNormalOutput@@3HA
inline extern_var(0x661AA4, i32, EnableNormalOutput);

// 0x90A688 | ?MessageFifo@@3PAY0FA@DA
inline extern_var(0x90A688, char[10][80], MessageFifo);

// 0x90A680 | ?MessageFirst@@3HA
inline extern_var(0x90A680, i32, MessageFirst);

// 0x90A684 | ?MonoPointer@@3PAGA
inline extern_var(0x90A684, u16*, MonoPointer);

// 0x661AB8 | ?Printer@@3P6AXHPBDPAD@ZA
inline extern_var(0x661AB8, void (*)(i32, char const*, std::va_list), Printer);

// 0x661AC0 | ?__assertFailed@@3PADA
inline extern_var(0x661AC0, char[], __assertFailed);
