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
    data7:list

    0x57C280 | public: __thiscall List::~List(void) | ??1List@@QAE@XZ
    0x57C290 | public: void __thiscall List::Kill(void) | ?Kill@List@@QAEXXZ
    0x57C2B0 | public: int __thiscall List::Insert(int,void *) | ?Insert@List@@QAEHHPAX@Z
    0x57C330 | public: void * __thiscall List::Access(int) | ?Access@List@@QAEPAXH@Z
    0x57C360 | public: int __thiscall List::Delete(int) | ?Delete@List@@QAEHH@Z
*/

struct List
{
public:
    // 0x57C280 | ??1List@@QAE@XZ
    ~List();

    // 0x57C330 | ?Access@List@@QAEPAXH@Z
    void* Access(i32 arg1);

    // 0x57C360 | ?Delete@List@@QAEHH@Z
    i32 Delete(i32 arg1);

    // 0x57C2B0 | ?Insert@List@@QAEHHPAX@Z
    i32 Insert(i32 arg1, void* arg2);

    // 0x57C290 | ?Kill@List@@QAEXXZ
    void Kill();
};

check_size(List, 0x0);
