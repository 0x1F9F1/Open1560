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
    data7:memstat

    0x578B20 | void __cdecl BeginMemStat(char const *) | ?BeginMemStat@@YAXPBD@Z
    0x578B80 | int __cdecl getMem(void) | ?getMem@@YAHXZ
    0x578BB0 | void __cdecl EndMemStat(void) | ?EndMemStat@@YAXXZ
    0x6620A8 | int EnableMemStat | ?EnableMemStat@@3HA
    0x90AEA8 | int beginStackCount | ?beginStackCount@@3HA
*/

// ?BeginMemStat@@YAXPBD@Z
ARTS_EXPORT void BeginMemStat(const char* name);

// ?EndMemStat@@YAXXZ
ARTS_EXPORT void EndMemStat();

// ?EnableMemStat@@3HA
ARTS_IMPORT extern i32 EnableMemStat;

// ?beginStackCount@@3HA
ARTS_IMPORT extern i32 beginStackCount;

struct MemStat
{
    const char* Name {};

    MemStat(const char* name)
    {
        Begin(name);
    }

    ~MemStat()
    {
        End();
    }

    void Begin(const char* name)
    {
        End();
        BeginMemStat(name);
        Name = name;
    }

    void End()
    {
        if (Name)
        {
            EndMemStat();
            Name = nullptr;
        }
    }
};

#define ARTS_MEM_STAT(NAME)                   \
    MemStat ARTS_CONCAT(mem_stat_, ARTS_LINE) \
    {                                         \
        NAME                                  \
    }
