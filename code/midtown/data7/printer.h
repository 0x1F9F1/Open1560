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

void Printerf(i32 level, ARTS_FORMAT_STRING char const* format, ...);

// 0x576C70 | ?Displayf@@YAXPBDZZ
ARTS_EXPORT void Displayf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576C90 | ?Printf@@YAXPBDZZ | unused
ARTS_EXPORT void Printf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576CB0 | ?Debugf@@YAXPBDZZ
ARTS_EXPORT void Debugf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576CD0 | ?Warningf@@YAXPBDZZ
ARTS_EXPORT void Warningf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576CF0 | ?Errorf@@YAXPBDZZ
ARTS_EXPORT void Errorf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576D10 | ?PErrorf@@YAXPBDZZ | unused
ARTS_EXPORT void PErrorf(ARTS_FORMAT_STRING char const* format, ...);

// 0x576D60 | ?PDebug@@YAXPBDZZ | unused
ARTS_EXPORT void PDebug(ARTS_FORMAT_STRING char const* format, ...);

// 0x576DB0 | ?Abortf@@YAXPBDZZ
[[noreturn]] ARTS_EXPORT void Abortf(ARTS_FORMAT_STRING char const* format, ...);

// 0x5769C0 | ?DefaultPrinter@@YAXHPBDPAD@Z
ARTS_EXPORT void DefaultPrinter(i32 level, char const* format, std::va_list args);

// 0x576E00 | ?LogToCommPort@@YAHHH@Z
ARTS_IMPORT i32 LogToCommPort(i32 arg1, i32 arg2);

// 0x576F00 | ?LogToFile@@YAXXZ
ARTS_EXPORT void LogToFile();

// 0x576EA0 | ?LogToFile@@YAXPAD@Z
ARTS_EXPORT void LogToFile(const char* file);

void CloseLogFile();

void LogToConsole();

// 0x576E90 | ?LogToMonochromeMonitor@@YAXXZ
ARTS_IMPORT void LogToMonochromeMonitor();

// 0x576DD0 | ?Quit@@YAXPBD@Z
ARTS_EXPORT void Quit(char const* message = nullptr);

// 0x661AA8 | ?EnableDebugOutput@@3HA
ARTS_EXPORT extern b32 EnableDebugOutput;

// 0x661AA4 | ?EnableNormalOutput@@3HA
ARTS_EXPORT extern b32 EnableNormalOutput;

// 0x90A688 | ?MessageFifo@@3PAY0FA@DA
extern char MessageFifo[32][256];

// 0x90A680 | ?MessageFirst@@3HA
ARTS_EXPORT extern i32 MessageFirst;

// 0x90A684 | ?MonoPointer@@3PAGA
ARTS_EXPORT extern u16* MonoPointer;

// 0x661AB8 | ?Printer@@3P6AXHPBDPAD@ZA
ARTS_EXPORT extern void (*Printer)(i32 level, char const* format, std::va_list args);

// 0x661AC0 | ?__assertFailed@@3PADA
ARTS_EXPORT extern char __assertFailed[];
