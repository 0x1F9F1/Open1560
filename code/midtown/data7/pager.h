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

class ipcMessageQueue;

struct PagerInfo_t
{
    usize Handle {};
    u32 Offset {};
    u32 Size {};

#ifdef ARTS_DEV_BUILD
    ConstString Path;
#endif

    const char* GetPath()
    {
#ifdef ARTS_DEV_BUILD
        return Path.get();
#else
        return "unknown";
#endif
    }

    // ?Read@PagerInfo_t@@QAEXPAXII@Z | stream:hfsystem
    ARTS_EXPORT void Read(void* buffer, u32 offset, u32 size);
};

check_size(PagerInfo_t, 0x10);

#define ARTS_PAGE_TEXTURES 0x1
#define ARTS_PAGE_GEOMETRY 0x2
#define ARTS_PAGE_BOUNDS 0x4

// ?EnablePaging@@3HA
ARTS_EXPORT extern i32 EnablePaging; // ARTS_PAGE_*

// ?PAGER@@3VipcMessageQueue@@A
extern ipcMessageQueue PAGER;
