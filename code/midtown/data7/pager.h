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
    data7:pager

    0x90A9F0 | class ipcMessageQueue PAGER | ?PAGER@@3VipcMessageQueue@@A
    0x90AA18 | int EnablePaging | ?EnablePaging@@3HA
*/

struct PagerInfo_t
{
    usize Handle {0};
    u32 Offset {0};
    u32 Size {0};
    char* Name {nullptr};

    ~PagerInfo_t();

    // 0x5605D0 | ?Read@PagerInfo_t@@QAEXPAXII@Z | stream:hfsystem
    ARTS_EXPORT void Read(void* buffer, u32 offset, u32 size);
};

check_size(PagerInfo_t, 0x10);

#define ARTS_PAGE_TEXTURES 0x1
#define ARTS_PAGE_GEOMETRY 0x2
#define ARTS_PAGE_BOUNDS 0x4

// 0x90AA18 | ?EnablePaging@@3HA
ARTS_IMPORT extern i32 EnablePaging; // ARTS_PAGE_*

// 0x90A9F0 | ?PAGER@@3VipcMessageQueue@@A
ARTS_IMPORT extern class ipcMessageQueue PAGER;
