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
    mmcity:heap

    0x4955C0 | void __cdecl mmHeapError(void) | ?mmHeapError@@YAXXZ
*/

// ?mmHeapError@@YAXXZ
[[noreturn]] ARTS_EXPORT void mmHeapError();

template <typename T>
class mmHeap
{
private:
    u8* HeapBase {nullptr};
    u8* HeapEnd {nullptr};
    u8* HeapHead {nullptr};
    u8* HeapTop {nullptr};

public:
    void* Allocate(usize size)
    {
        // TODO: Align size (based on alignof(T)/sizeof(T) ?)

        void* result = HeapHead;
        HeapHead += size;

        if (HeapHead > HeapTop)
            mmHeapError();

        return result;
    }

    void Free(void* ptr)
    {
        // TODO: Validate Free

        HeapHead = static_cast<u8*>(ptr);
    }
};
