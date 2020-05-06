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

define_dummy_symbol(data7_printer);

#include "printer.h"

#include <cstring>
#include <ctime>

#include "core/minwin.h"

#include "machname.h"

void Displayf(char const* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(0, format, va);
    va_end(va);
}

void Printf(char const* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(0, format, va);
    va_end(va);
}

void Debugf(char const* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(0, format, va);
    va_end(va);
}

void Warningf(char const* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(1, format, va);
    va_end(va);
}

void Errorf(char const* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(2, format, va);
    va_end(va);
}

void PErrorf(char const* format, ...)
{
    char buffer[256];
    std::va_list va;
    va_start(va, format);
    vsprintf_s(buffer, format, va);
    va_end(va);

    char error[256];
    Errorf("%s: %s", (strerror_s(error, errno) == 0) ? error : "Unknown Error", buffer);
}

void PDebug(char const* format, ...)
{
    char buffer[256];
    std::va_list va;
    va_start(va, format);
    vsprintf_s(buffer, format, va);
    va_end(va);

    char error[256];
    Warningf("%s: %s", (strerror_s(error, errno) == 0) ? error : "Unknown Error", buffer);
}

void Abortf(char const* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(4, format, va);
    va_end(va);
}

static extern_var(0x661AA0, HANDLE, DebugLogFile);

static constexpr const char* PrinterPrefixes[5] {
    "",
    "WARNING: ",
    "ERROR: ",
    "FATAL ERROR: ",
    "ABORT: ",
};

static constexpr u8 PrinterColors[5] {
    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    FOREGROUND_RED | FOREGROUND_INTENSITY,
    FOREGROUND_RED | FOREGROUND_INTENSITY,
    FOREGROUND_RED | FOREGROUND_INTENSITY,
};

void DefaultPrinter(i32 level, char const* format, std::va_list args)
{
    char buffer[512];
    strcpy_s(buffer, PrinterPrefixes[level]);

    {
        char buffer2[512];
        vsprintf_s(buffer2, format, args);

        if (!strcmp(buffer2, "DirectInput problem, code = -2147024884(8007000c) [not acquired]"))
            return;

        strcat_s(buffer, buffer2);
    }

    strcat_s(buffer, "\n");

    if (EnableNormalOutput || true)
    {
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(output, PrinterColors[level]);

        DWORD written = 0;

        if (!WriteConsoleA(output, buffer, std::strlen(buffer), &written, 0))
        {
            WriteFile(output, buffer, std::strlen(buffer), &written, 0);
        }

        SetConsoleTextAttribute(output, PrinterColors[0]);
    }

    if (DebugLogFile != INVALID_HANDLE_VALUE)
    {
        DWORD written = 0;

        WriteFile(DebugLogFile, buffer, std::strlen(buffer), &written, 0);

        if (level >= 3)
        {
            CloseHandle(DebugLogFile);
        }
    }
    else if (EnableDebugOutput)
    {
        OutputDebugStringA(buffer);
    }

    if (level >= 3)
    {
        if (IsDebuggerPresent())
        {
            DebugBreak();
        }

        MessageBoxA(NULL, buffer, "Fatal Error", MB_OK);

        if (level == 3)
        {
            _exit(1);
        }

        if (level == 4)
        {
            *static_cast<volatile i32*>(0) = 0xDEADBEEF;
        }
    }
}

i32 LogToCommPort(i32 arg1, i32 arg2)
{
    return stub<cdecl_t<i32, i32, i32>>(0x576E00, arg1, arg2);
}

void LogToFile()
{
    export_hook(0x576F00);

    std::time_t time;
    std::time(&time);

    std::tm tm;

    if (localtime_s(&tm, &time) != 0)
        return LogToFile("Open1560.log");

    char machname[128];

    GetMachineName(machname, 128);

    char filename[128];

    sprintf_s(filename, "%s-%04d%02d%02d-%02d%02d%02d.log", machname, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec);

    LogToFile(filename);
}

void LogToFile(char* file)
{
    export_hook(0x576EA0);

    DebugLogFile = CreateFileA(file, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (DebugLogFile == INVALID_HANDLE_VALUE)
    {
        OutputDebugStringA("OUTPUT LOG FILE CREATE FAILED.\n");
    }
    else
    {
        OutputDebugStringA("Logging output to file '");
        OutputDebugStringA(file);
        OutputDebugStringA("'.\n");
    }
}

void LogToMonochromeMonitor()
{
    return stub<cdecl_t<void>>(0x576E90);
}

void Quit(char const* arg1)
{
    return stub<cdecl_t<void, char const*>>(0x576DD0, arg1);
}
