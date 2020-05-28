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

define_dummy_symbol(data7_pager);

#include "pager.h"

#include "core/minwin.h"

void PagerInfo_t::Read(void* buffer, u32 offset, u32 size)
{
    export_hook(0x5605D0);

    if (size == 0)
        size = Size - offset;

    offset += Offset;

    OVERLAPPED overlapped {};
    overlapped.Offset = offset;
    overlapped.OffsetHigh = 0;

    DWORD bytes_read = 0;

    if (!ReadFile(static_cast<HANDLE>(Handle), buffer, size, &bytes_read, &overlapped) || (bytes_read != size))
        Errorf("PagerInfo_t(%s)::Read - Failed to read 0x%X bytes @ 0x%X: 0x%08X", Name, size, offset, GetLastError());
}
