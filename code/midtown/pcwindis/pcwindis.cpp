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

define_dummy_symbol(pcwindis_pcwindis);

#include "pcwindis.h"

#include "eventq7/dispatchable.h"

struct MapEntry
{
    const char* Name;
    u32* Msgs;
    i32 NumMsgs;
    Dispatchable* Handler;
};

static constexpr usize MAX_MAP_ENTRIES = 16;

static MapEntry MapEntries[MAX_MAP_ENTRIES] {};
static i32 NumMapEntries = 0;

LRESULT __stdcall MasterWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    for (i32 i = NumMapEntries; i > 0; --i)
    {
        MapEntry& entry = MapEntries[i - 1];

        for (i32 j = 0; j < entry.NumMsgs; ++j)
        {
            if (entry.Msgs[j] == uMsg)
                return entry.Handler->WindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    return DefWindowProcA(hwnd, uMsg, wParam, lParam);
}

void RegisterMap(const char* name, u32* msgs, i32 num_msgs, class Dispatchable* handler)
{
    if (NumMapEntries == MAX_MAP_ENTRIES)
    {
        Errorf("Out of maps in NumMapEntries");
        return;
    }

    for (i32 i = 0; i < num_msgs; ++i)
    {
        for (i32 j = 0; j < NumMapEntries; ++j)
        {
            MapEntry& entry = MapEntries[j];

            for (i32 k = 0; k < entry.NumMsgs; ++k)
            {
                if (entry.Msgs[k] == msgs[i])
                    Warningf("'%s' message %d hides '%s' version!", name, msgs[i], entry.Name);
            }
        }
    }

    MapEntry& entry = MapEntries[NumMapEntries++];

    entry.Name = name;
    entry.Msgs = msgs;
    entry.NumMsgs = num_msgs;
    entry.Handler = handler;
}

void UnregisterMap(const char* name)
{
    for (i32 i = 0; i < NumMapEntries; ++i)
    {
        MapEntry& entry = MapEntries[i];

        if (std::strcmp(name, entry.Name))
            continue;

        --NumMapEntries;

        for (; i < NumMapEntries; ++i)
            MapEntries[i] = MapEntries[i + 1];

        MapEntries[i] = {};

        return;
    }

    Errorf("Map '%s' not found in UnregisterMap", name);
}
