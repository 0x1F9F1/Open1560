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

#include <cstdarg>

void Printerf(i32 level, ARTS_FORMAT_STRING const char* format, ...);

// ?Displayf@@YAXPBDZZ
ARTS_EXPORT void Displayf(ARTS_FORMAT_STRING const char* format, ...);

// ?Printf@@YAXPBDZZ | unused
void Printf(ARTS_FORMAT_STRING const char* format, ...);

// ?Debugf@@YAXPBDZZ
ARTS_EXPORT void Debugf(ARTS_FORMAT_STRING const char* format, ...);

// ?Warningf@@YAXPBDZZ
ARTS_EXPORT void Warningf(ARTS_FORMAT_STRING const char* format, ...);

// ?Errorf@@YAXPBDZZ
ARTS_EXPORT void Errorf(ARTS_FORMAT_STRING const char* format, ...);

// ?PErrorf@@YAXPBDZZ | unused
void PErrorf(ARTS_FORMAT_STRING const char* format, ...);

// ?PDebug@@YAXPBDZZ | unused
void PDebug(ARTS_FORMAT_STRING const char* format, ...);

// ?Abortf@@YAXPBDZZ
[[noreturn]] ARTS_EXPORT void Abortf(ARTS_FORMAT_STRING const char* format, ...);

// ?DefaultPrinter@@YAXHPBDPAD@Z
void DefaultPrinter(i32 level, const char* format, std::va_list args);

// ?LogToFile@@YAXXZ
void LogToFile();

// ?LogToFile@@YAXPAD@Z
void LogToFile(const char* file);

void CloseLogFile();

void LogToConsole();

// ?Quit@@YAXPBD@Z
void Quit(const char* message = nullptr);

// ?EnableDebugOutput@@3HA
extern b32 EnableDebugOutput;

// ?EnableNormalOutput@@3HA
extern b32 EnableNormalOutput;

#ifdef ARTS_DEV_BUILD
// ?MessageFifo@@3PAY0FA@DA
extern char MessageFifo[32][256];

// ?MessageFirst@@3HA
extern i32 MessageFirst;
#endif

// ?Printer@@3P6AXHPBDPAD@ZA
extern void (*Printer)(i32 level, const char* format, std::va_list args);

// ?__assertFailed@@3PADA
ARTS_EXPORT extern char __assertFailed[];
