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

#include <DbgHelp.h>

struct MapSymbol
{
    char* Name {nullptr};
    usize Address {0};
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
        GetModuleFileNameA(NULL, map_name, std::size(map_name));

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
        MapSymbolCount = 0;

        for (char* line_end = nullptr;; map_data = line_end + 1)
        {
            line_end = static_cast<char*>(std::memchr(map_data, '\n', map_data_end - map_data));

            if (line_end == nullptr)
                break;

            char line_buffer[256];
            arts_strncpy(line_buffer, map_data, line_end - map_data);

            if (std::strstr(line_buffer, "Publics by Value"))
                in_publics = true;

            if (!in_publics)
                continue;

            char sym_name[256];
            u32 sym_addr = 0;

            if (!std::strncmp(line_buffer, " 0001:", 6) &&
                arts_sscanf(line_buffer, "%*s %s %x", sym_name, std::size(sym_name), &sym_addr))
            {
                usize sym_len = std::strlen(sym_name);

                if (state == 2)
                {
                    char* symbol = &symbol_data[symbols_size];
                    std::memcpy(symbol, sym_name, sym_len + 1);

                    MapSymbols[MapSymbolCount].Name = symbol;
                    MapSymbols[MapSymbolCount].Address = sym_addr;
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

void DebugLog(i32 arg1, void* arg2, i32 arg3)
{
    return stub<cdecl_t<void, i32, void*, i32>>(0x520720, arg1, arg2, arg3);
}

void DebugLogInit(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x5206C0, arg1);
}

void DebugLogShutdown()
{
    return stub<cdecl_t<void>>(0x520700);
}

void DoStackTraceback(i32 arg1, i32* arg2)
{
    return stub<cdecl_t<void, i32, i32*>>(0x5204C0, arg1, arg2);
}

void DumpStackTraceback(i32* arg1, i32 arg2)
{
    return stub<cdecl_t<void, i32*, i32>>(0x520670, arg1, arg2);
}

i32 LogStackTraceback(i32* arg1, i32 arg2)
{
    return stub<cdecl_t<i32, i32*, i32>>(0x5205B0, arg1, arg2);
}

static bool DbgHelpLoaded = false;

void LookupAddress(char* buffer, usize buflen, usize address)
{
    if (!MapSymbolsLoaded)
    {
        InitMap();

        SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
        DbgHelpLoaded = SymInitialize(GetCurrentProcess(), NULL, TRUE);

        MapSymbolsLoaded = true;
    }

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
            if (!arts_stricmp(module.ModuleName, "dinput"))
                arts_strcpy(module.ModuleName, "Open1560");

            if (pSymbol->NameLen > 64)
                arts_strcpy(pSymbol->Name + 61, 4, "...");

            arts_sprintf(buffer, buflen, "0x%X (%s.%s + 0x%X)", address, module.ModuleName, pSymbol->Name,
                static_cast<u32>(dwDisplacement));

            return;
        }
    }

    if (const MapSymbol* entry = LookupMapSymbol(address))
    {
        char undec_name[256];

        const char* function_name =
            UnDecorateSymbolName(entry->Name, undec_name, 128, UNDNAME_NAME_ONLY) ? undec_name : entry->Name;

        arts_sprintf(buffer, buflen, "0x%X (%s + 0x%X)", address, function_name, address - entry->Address);

        return;
    }

    arts_sprintf(buffer, buflen, "0x%X (Unknown)", address);
}

void LookupAddress(char* buffer, i32 addr)
{
    export_hook(0x520130);

    LookupAddress(buffer, 128, usize(addr));
}

void StackTraceback(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x520590, arg1);
}
