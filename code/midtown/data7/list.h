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

struct List
{
public:
    List() = default;

    // ??1List@@QAE@XZ
    ARTS_EXPORT ~List();

    ARTS_NON_COPYABLE(List);

    // ?Access@List@@QAEPAXH@Z
    ARTS_EXPORT void* Access(i32 index);

    // ?Delete@List@@QAEHH@Z
    b32 Delete(i32 index);

    // ?Insert@List@@QAEHHPAX@Z
    ARTS_EXPORT b32 Insert(i32 index, void* value);

    // ?Kill@List@@QAEXXZ
    ARTS_EXPORT void Kill();

    void Append(void* value)
    {
        Insert(size_ + 1, value);
    }

private:
    struct Entry;

    i32 size_ {};
    Entry* first_ {};

    // See aiVehicle::Update
    Entry* iter_current_ {};
};

check_size(List, 0xC);
