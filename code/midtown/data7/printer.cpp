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

#include "core/platform.h"

#include "machname.h"
#include "memory/stack.h"

b32 EnableDebugOutput = true;
b32 EnableNormalOutput = true;

#ifdef ARTS_DEV_BUILD
char MessageFifo[32][256];
i32 MessageFirst = 0;
#endif

u16* MonoPointer = nullptr;

void (*Printer)(i32 level, const char* format, std::va_list args) = DefaultPrinter;

char __assertFailed[] = "Assertion failed (%s,%d): '%s'";

void Printerf(i32 level, ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(level, format, va);
    va_end(va);
}

void Displayf(ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(0, format, va);
    va_end(va);
}

void Printf(ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(0, format, va);
    va_end(va);
}

void Debugf(ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(0, format, va);
    va_end(va);
}

void Warningf(ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(1, format, va);
    va_end(va);
}

void Errorf(ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(2, format, va);
    va_end(va);
}

void PErrorf(ARTS_FORMAT_STRING const char* format, ...)
{
    char buffer[256];
    std::va_list va;
    va_start(va, format);
    arts_vsprintf(buffer, format, va);
    va_end(va);

    char error[256];
    Errorf("%s: %s", (strerror_s(error, errno) == 0) ? error : "Unknown Error", buffer);
}

void PDebug(ARTS_FORMAT_STRING const char* format, ...)
{
    char buffer[256];
    std::va_list va;
    va_start(va, format);
    arts_vsprintf(buffer, format, va);
    va_end(va);

    char error[256];
    Warningf("%s: %s", (strerror_s(error, errno) == 0) ? error : "Unknown Error", buffer);
}

[[noreturn]] void Abortf(ARTS_FORMAT_STRING const char* format, ...)
{
    std::va_list va;
    va_start(va, format);
    Printer(4, format, va);
    va_end(va);

    ArAbort();
}

static HANDLE DebugLogFile = INVALID_HANDLE_VALUE;

const char* PrinterPrefixes[5] {
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

void DefaultPrinter(i32 level, const char* format, std::va_list args)
{
    char buffer[4096];
    arts_strcpy(buffer, PrinterPrefixes[level]);

    {
        char buffer2[4096];
        arts_vsprintf(buffer2, format, args);

        arts_strcat(buffer, buffer2);
    }

#ifdef ARTS_DEV_BUILD
    arts_strncpy(MessageFifo[MessageFirst++ % ARTS_SIZE(MessageFifo)], buffer, ARTS_SIZE(MessageFifo[0]) - 1);
#endif

    arts_strcat(buffer, "\r\n");

    if (EnableNormalOutput)
    {
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(output, PrinterColors[level]);

        DWORD written = 0;

        if (!WriteConsoleA(output, buffer, static_cast<DWORD>(std::strlen(buffer)), &written, 0))
        {
            WriteFile(output, buffer, static_cast<DWORD>(std::strlen(buffer)), &written, 0);
        }

        SetConsoleTextAttribute(output, PrinterColors[0]);
    }

    if (DebugLogFile != INVALID_HANDLE_VALUE)
    {
        DWORD written = 0;

        WriteFile(DebugLogFile, buffer, static_cast<DWORD>(std::strlen(buffer)), &written, 0);

        if (level >= 3)
            FlushFileBuffers(DebugLogFile);
    }
    else if (EnableDebugOutput)
    {
        OutputDebugStringA(buffer);
    }

    if (level >= 3)
    {
        MessageBoxA(NULL, buffer, "Fatal Error", MB_OK | MB_ICONERROR | MB_SETFOREGROUND | MB_TOPMOST);

        StackTraceback(16, 2);

        if (IsDebuggerPresent())
        {
            ArDebugBreak();
        }

        std::terminate();
    }
}

void LogToFile()
{
    if (DebugLogFile != INVALID_HANDLE_VALUE)
        return;

    std::time_t time;
    std::time(&time);

    std::tm tm;

    if (localtime_s(&tm, &time) != 0)
        return LogToFile("Open1560.log");

    char machname[128];
    GetMachineName(machname, ARTS_SIZE(machname));

    const auto filename = arts_formatf<128>("%s-%04d%02d%02d-%02d%02d%02d.log", machname, tm.tm_year + 1900,
        tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    LogToFile(filename);
}

void LogToFile(const char* file)
{
    if (DebugLogFile != INVALID_HANDLE_VALUE)
        return;

    HANDLE lock_file =
        CreateFileA("MM.LOCK", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (lock_file != INVALID_HANDLE_VALUE)
    {
        if (GetFileSize(lock_file, NULL) == 15)
        {
            Warningf("Lock file detected. Saving log");

            char time_string[15];
            DWORD bytes_read = 0;
            if (ReadFile(lock_file, time_string, sizeof(time_string), &bytes_read, NULL))
            {
                CreateDirectoryA("crashes", NULL);

                if (!MoveFileA(file, arts_formatf<256>("crashes/Open1560-%.15s.log", time_string)))
                {
                    Warningf("Failed to save log file");
                }
            }
            else
            {
                Warningf("Failed to read lock file timestamp");
            }
        }

        time_t rawtime;
        time(&rawtime);

        struct tm timeinfo;
        localtime_s(&timeinfo, &rawtime);

        char open_time[16];
        strftime(open_time, ARTS_SIZE(open_time), "%G%m%d-%H%M%S", &timeinfo);

        SetFilePointer(lock_file, 0, NULL, FILE_BEGIN);
        SetEndOfFile(lock_file);

        DWORD bytes_written = 0;
        WriteFile(lock_file, open_time, 15, &bytes_written, NULL);

        FlushFileBuffers(lock_file);
        CloseHandle(lock_file);
    }
    else
    {
        Warningf("Failed to create lock file");
    }

    DebugLogFile = CreateFileA(file, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

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

void CloseLogFile()
{
    FlushFileBuffers(DebugLogFile);

    DeleteFileA("MM.LOCK");
}

void LogToConsole()
{
    if (GetConsoleWindow() == NULL)
    {
        if (!AttachConsole(ATTACH_PARENT_PROCESS))
        {
            AllocConsole();
            SetConsoleTitleA("Open1560 Console");
        }

        std::FILE* f = nullptr;
        freopen_s(&f, "CONOUT$", "w", stdout);
        freopen_s(&f, "CONOUT$", "w", stderr);
    }
}

void Quit(const char* message)
{
    if (message)
        Quitf("%s", message);
    else
        std::exit(0);
}
