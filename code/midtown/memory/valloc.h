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

class asSafeHeap
{
public:
    // ??0asSafeHeap@@QAE@XZ
    ARTS_EXPORT asSafeHeap();

    // ??1asSafeHeap@@QAE@XZ
    ARTS_EXPORT ~asSafeHeap();

    // ?Init@asSafeHeap@@QAEXHH@Z
    ARTS_EXPORT void Init(isize heap_size, i32 num_heaps);

    // ?Kill@asSafeHeap@@QAEXXZ
    ARTS_EXPORT void Kill();

    // ?Restart@asSafeHeap@@QAEXXZ
    ARTS_EXPORT void Restart();

protected:
    // ?Activate@asSafeHeap@@IAEXXZ
    ARTS_EXPORT void Activate();

    // ?Deactivate@asSafeHeap@@IAEXXZ
    ARTS_EXPORT void Deactivate();

private:
    u8* current_heap_ {};
    u8* heap_ {};
    u32 heap_index_ {};
    usize heap_size_ {};
    i32 num_heaps_ {};
};

check_size(asSafeHeap, 0x14);

// ?SAFEHEAP@@3VasSafeHeap@@A
ARTS_EXPORT extern asSafeHeap SAFEHEAP;
