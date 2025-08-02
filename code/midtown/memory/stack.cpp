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

define_dummy_symbol(memory_stack);

#include "stack.h"

#include "core/minwin.h"
#include "memory/allocator.h"
#include "stream/stream.h"

#include <DbgHelp.h>
#include <intrin.h>

struct MapSymbol
{
    char* Name {};
    usize Address {};
};

static bool MapSymbolsLoaded = false;
static MapSymbol* MapSymbols = nullptr;
static i32 MapSymbolCount = 0;

static const MapSymbol* LookupMapSymbol(usize address)
{
    const MapSymbol* first = MapSymbols;
    const MapSymbol* last = first + MapSymbolCount;

    const MapSymbol* find = std::upper_bound(
        first, last, address, [](usize address, const MapSymbol& entry) { return entry.Address >= address; });

    if (find == first || find == last)
    {
        return nullptr;
    }

    return find - 1;
}

static void InitMap()
{
    HANDLE map_file = INVALID_HANDLE_VALUE;

    {
        char map_name[256];
        GetModuleFileNameA(NULL, map_name, ARTS_SSIZE32(map_name));

        if (char* map_ext = std::strrchr(map_name, '.'))
            *map_ext = '\0';

        arts_strcat(map_name, ".MAP");

        map_file =
            CreateFileA(map_name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_RANDOM_ACCESS, NULL);

        if (map_file == INVALID_HANDLE_VALUE)
        {
            Errorf("Map file '%s' not found.", map_name);
            return;
        }
    }

    DWORD file_size = GetFileSize(map_file, NULL);
    HANDLE map_file_mapping = CreateFileMappingA(map_file, NULL, PAGE_READONLY, 0, 0, NULL);

    CloseHandle(map_file);
    map_file = INVALID_HANDLE_VALUE;

    if (map_file_mapping == NULL)
    {
        Errorf("CreateFileMapping failed.");
        return;
    }

    void* map_file_view = MapViewOfFile(map_file_mapping, FILE_MAP_READ, 0, 0, 0);

    CloseHandle(map_file_mapping);
    map_file_mapping = NULL;

    if (map_file_view == NULL)
    {
        Errorf("MapViewOfFile failed.");
        return;
    }

    char* map_data_end = static_cast<char*>(map_file_view) + file_size;
    char* symbol_data = nullptr;

    for (i32 state = 1; state <= 2; ++state)
    {
        char* map_data = static_cast<char*>(map_file_view);

        bool in_publics = false;
        usize symbols_size = 0;
        usize addr_delta = 0;
        MapSymbolCount = 0;

        for (char* line_end = nullptr;; map_data = line_end + 1)
        {
            line_end = static_cast<char*>(std::memchr(map_data, '\n', map_data_end - map_data));

            if (line_end == nullptr)
                break;

            char line_buffer[1024];
            arts_strncpy(line_buffer, map_data, line_end - map_data);

            if (std::strstr(line_buffer, "Publics by Value"))
                in_publics = true;

            if (!in_publics)
            {
                if (auto base = std::strstr(line_buffer, "Preferred load address is "))
                {
                    if (usize base_addr = 0; arts_sscanf(base + 26, "%zx", &base_addr))
                    {
                        addr_delta = reinterpret_cast<usize>(GetModuleHandleA(NULL)) - base_addr;
                    }
                }

                continue;
            }

            char sym_name[1024];
            usize sym_addr = 0;

            if (!std::strncmp(line_buffer, " 0001:", 6) &&
                arts_sscanf(line_buffer, "%*s %s %zx", sym_name, ARTS_SIZE32(sym_name), &sym_addr))
            {
                usize sym_len = std::strlen(sym_name);

                if (state == 2)
                {
                    char* symbol = &symbol_data[symbols_size];
                    std::memcpy(symbol, sym_name, sym_len + 1);

                    MapSymbols[MapSymbolCount].Name = symbol;
                    MapSymbols[MapSymbolCount].Address = sym_addr + addr_delta;
                }

                symbols_size += sym_len + 1;
                ++MapSymbolCount;
            }
            else if (!std::strncmp(line_buffer, " 0002:", 6))
            {
                break;
            }
        }

        if (state == 1)
        {
            MapSymbols = static_cast<MapSymbol*>(GlobalAlloc(GMEM_ZEROINIT, MapSymbolCount * sizeof(MapSymbol)));
            symbol_data = static_cast<char*>(GlobalAlloc(GMEM_ZEROINIT, symbols_size));
            Errorf("%d symbols parsed from map file.", MapSymbolCount);
        }
    }

    UnmapViewOfFile(map_file_view);
    map_file_view = NULL;
}

static bool DbgHelpLoaded = false;

static void InitDebugSymbols()
{
    if (!MapSymbolsLoaded)
    {
        InitMap();

        SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
        DbgHelpLoaded = SymInitialize(GetCurrentProcess(), NULL, TRUE);

        if (!DbgHelpLoaded)
            Errorf("Failed to load debug symbols, error: 0x%08X", GetLastError());

        MapSymbolsLoaded = true;
    }
}

void DumpStackTraceback(i32* frames, i32 count)
{
    for (i32 i = 0; i < count; ++i)
    {
        char symbol[256];
        LookupAddress(symbol, ARTS_SIZE(symbol), usize(frames[i]));
        Displayf("%d. %s", count - i - 1, symbol);
    }
}

void LookupAddress(char* buffer, usize buflen, usize address)
{
    InitDebugSymbols();

    if (DbgHelpLoaded)
    {
        DWORD64 dwDisplacement = 0;

        alignas(SYMBOL_INFO) char symbol_buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
        PSYMBOL_INFO pSymbol = (PSYMBOL_INFO) symbol_buffer;

        pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        pSymbol->MaxNameLen = MAX_SYM_NAME;

        IMAGEHLP_MODULE module {};
        module.SizeOfStruct = sizeof(IMAGEHLP_MODULE);

        if (SymFromAddr(GetCurrentProcess(), address, &dwDisplacement, pSymbol) &&
            SymGetModuleInfo(GetCurrentProcess(), address, &module))
        {
            if (pSymbol->NameLen > 64)
                arts_strcpy(pSymbol->Name + 61, 4, "...");

            if (!arts_stricmp(module.ModuleName, "Open1560"))
            {
                arts_sprintf(
                    buffer, buflen, "0x%08zX (%s + 0x%X)", address, pSymbol->Name, static_cast<u32>(dwDisplacement));
            }
            else
            {
                arts_sprintf(buffer, buflen, "0x%08zX (%s.%s + 0x%X)", address, module.ModuleName, pSymbol->Name,
                    static_cast<u32>(dwDisplacement));
            }

            return;
        }
    }

    if (const MapSymbol* entry = LookupMapSymbol(address))
    {
        char undec_name[256];

        const char* function_name =
            UnDecorateSymbolName(entry->Name, undec_name, ARTS_SSIZE32(undec_name), UNDNAME_NAME_ONLY) ? undec_name
                                                                                                       : entry->Name;

        if (std::strlen(undec_name) > 64)
            arts_strcpy(undec_name + 61, 4, "...");

        arts_sprintf(buffer, buflen, "0x%08zX (%s + 0x%zX)", address, function_name, address - entry->Address);

        return;
    }

    arts_sprintf(buffer, buflen, "0x%08zX (Unknown)", address);
}

ARTS_NOINLINE i32 StackTraceback(i32 depth, isize* frames, i32 skipped, _CONTEXT* context_record)
{
    InitDebugSymbols();

    STACKFRAME stack_frame {};

    stack_frame.AddrPC.Offset = context_record->Eip;
    stack_frame.AddrPC.Mode = AddrModeFlat;
    stack_frame.AddrStack.Offset = context_record->Esp;
    stack_frame.AddrStack.Mode = AddrModeFlat;
    stack_frame.AddrFrame.Offset = context_record->Ebp;
    stack_frame.AddrFrame.Mode = AddrModeFlat;

    i32 num_frames = 0;

    while (num_frames < depth)
    {
        if (!StackWalk(IMAGE_FILE_MACHINE_I386, GetCurrentProcess(), GetCurrentThread(), &stack_frame, context_record,
                NULL, NULL, NULL, NULL))
            break;

        if (skipped)
            --skipped;
        else
            frames[num_frames++] = stack_frame.AddrPC.Offset;
    }

    return num_frames;
}

ARTS_NOINLINE i32 StackTraceback(i32 depth, isize* frames, i32 skipped)
{
    CONTEXT context {};
    context.ContextFlags = CONTEXT_FULL;
    RtlCaptureContext(&context);

    return StackTraceback(depth, frames, skipped, &context);
}

ARTS_NOINLINE void StackTraceback(i32 depth)
{
    StackTraceback(depth, 1);
}

ARTS_NOINLINE void StackTraceback(i32 depth, i32 skipped)
{
    isize frames[32];
    i32 num_frames = StackTraceback(std::min(depth, ARTS_SSIZE32(frames)), frames, skipped + 1);
    DumpStackTraceback(frames, num_frames);
}

static const char* GetExceptionCodeString(DWORD code)
{
    switch (code)
    {
        case EXCEPTION_ACCESS_VIOLATION: return "ACCESS_VIOLATION";
        case EXCEPTION_ARRAY_BOUNDS_EXCEEDED: return "ARRAY_BOUNDS_EXCEEDED";
        case EXCEPTION_BREAKPOINT: return "BREAKPOINT";
        case EXCEPTION_DATATYPE_MISALIGNMENT: return "DATATYPE_MISALIGNMENT";
        case EXCEPTION_FLT_DENORMAL_OPERAND: return "FLT_DENORMAL_OPERAND";
        case EXCEPTION_FLT_DIVIDE_BY_ZERO: return "FLT_DIVIDE_BY_ZERO";
        case EXCEPTION_FLT_INEXACT_RESULT: return "FLT_INEXACT_RESULT";
        case EXCEPTION_FLT_INVALID_OPERATION: return "FLT_INVALID_OPERATION";
        case EXCEPTION_FLT_OVERFLOW: return "FLT_OVERFLOW";
        case EXCEPTION_FLT_STACK_CHECK: return "FLT_STACK_CHECK";
        case EXCEPTION_FLT_UNDERFLOW: return "FLT_UNDERFLOW";
        case EXCEPTION_GUARD_PAGE: return "GUARD_PAGE";
        case EXCEPTION_ILLEGAL_INSTRUCTION: return "ILLEGAL_INSTRUCTION";
        case EXCEPTION_IN_PAGE_ERROR: return "IN_PAGE_ERROR";
        case EXCEPTION_INT_DIVIDE_BY_ZERO: return "INT_DIVIDE_BY_ZERO";
        case EXCEPTION_INT_OVERFLOW: return "INT_OVERFLOW";
        case EXCEPTION_INVALID_DISPOSITION: return "INVALID_DISPOSITION";
        case EXCEPTION_INVALID_HANDLE: return "INVALID_HANDLE";
        case EXCEPTION_NONCONTINUABLE_EXCEPTION: return "NONCONTINUABLE_EXCEPTION";
        case EXCEPTION_PRIV_INSTRUCTION: return "PRIV_INSTRUCTION";
        case EXCEPTION_SINGLE_STEP: return "SINGLE_STEP";
        case EXCEPTION_STACK_OVERFLOW: return "STACK_OVERFLOW";
    };

    return nullptr;
}

thread_local bool InException {};

i32 ExceptionFilter(_EXCEPTION_POINTERS* exception)
{
    if (InException)
        Abortf("Exception occured during handler");

    InException = true;

    CONTEXT* context = exception->ContextRecord;
    EXCEPTION_RECORD* record = exception->ExceptionRecord;

    char source[128];
    LookupAddress(source, ARTS_SIZE(source), context->Eip);

    const char* error_code_string = GetExceptionCodeString(record->ExceptionCode);

    Displayf("%s (0x%08X) at EIP=%s", error_code_string ? error_code_string : "UNKNOWN", record->ExceptionCode, source);

    Displayf("EAX=%08X EBX=%08X ECX=%08X EDX=%08X", context->Eax, context->Ebx, context->Ecx, context->Edx);
    Displayf("ESI=%08X EDI=%08X EBP=%08X ESP=%08X", context->Esi, context->Edi, context->Ebp, context->Esp);

    STACKFRAME stack_frame {};
    stack_frame.AddrPC.Offset = context->Eip;
    stack_frame.AddrPC.Mode = AddrModeFlat;
    stack_frame.AddrStack.Offset = context->Esp;
    stack_frame.AddrStack.Mode = AddrModeFlat;
    stack_frame.AddrFrame.Offset = context->Ebp;
    stack_frame.AddrFrame.Mode = AddrModeFlat;

    i32 frames[32];
    i32 num_frames = StackTraceback(ARTS_SSIZE32(frames), frames, 0, context);
    DumpStackTraceback(frames, num_frames);

    if (CURHEAP)
        CURHEAP->SanityCheck();

    InException = false;

#ifndef ARTS_FINAL
    if (IsDebuggerPresent())
    {
        return EXCEPTION_CONTINUE_SEARCH;
    }
#endif

    return EXCEPTION_EXECUTE_HANDLER;
}

// ?DebugLogStream@@3PAVStream@@A
ARTS_IMPORT extern Stream* DebugLogStream;

// ?DebugLogReading@@3HA
ARTS_IMPORT extern b32 DebugLogReading;

void DebugLogInit(b32 reading)
{
    if (DebugLogStream)
        return;

    DebugLogReading = reading;
    DebugLogStream = arts_fopen("c:\\debug.log", reading ? "r" : "w");
}

void DebugLogShutdown()
{
    delete DebugLogStream;
}

void DebugLog(i32 tag, void* data, i32 size)
{
    if (DebugLogStream == nullptr)
        return;

    isize addrs[8] {};
    StackTraceback(8, addrs, 1);

    if (DebugLogReading)
    {
        i32 ftag = 0;
        i32 fsize = 0;

        DebugLogStream->Read(&ftag, sizeof(ftag));
        DebugLogStream->Read(&fsize, sizeof(fsize));

        u8 fbuffer[256];
        ArAssert(fsize <= ARTS_SSIZE32(fbuffer), "Invalid Input Size");
        DebugLogStream->Read(fbuffer, fsize);

        isize faddrs[8] {};
        DebugLogStream->Read(faddrs, sizeof(faddrs));

        bool invalid = false;

        if (tag != ftag)
        {
            Errorf("DebugLog: Current tag %x != stored %x", tag, ftag);
            invalid = true;
        }

        if (size != fsize)
        {
            Errorf("DebugLog: Current size %d != stored %d", size, fsize);
            invalid = true;
        }

        if (std::memcmp(data, fbuffer, size))
        {
            Errorf("DebugLog: Current data != stored data");
            Displayf("CURRENT:");
            HexDump(data, size);
            Displayf("STORED:");
            HexDump(fbuffer, fsize);
            invalid = true;
        }

        // FIXME: This won't work properly with ASLR
        if (std::memcmp(addrs, faddrs, sizeof(faddrs)))
        {
            Errorf("DebugLog: Stack backtrace mismatch");
            Displayf("CURRENT:");
            DumpStackTraceback(addrs, ARTS_SSIZE32(addrs));
            Displayf("STORED:");
            DumpStackTraceback(faddrs, ARTS_SSIZE32(faddrs));
            invalid = true;
        }

        if (invalid)
            Quitf("DebugLog mismatch, aborting.");
    }
    else
    {
        DebugLogStream->Write(&tag, sizeof(tag));
        DebugLogStream->Write(&size, sizeof(size));
        DebugLogStream->Write(data, size);
        DebugLogStream->Write(addrs, sizeof(addrs));
    }
}
