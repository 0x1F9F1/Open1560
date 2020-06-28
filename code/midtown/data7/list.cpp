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

define_dummy_symbol(data7_list);

#include "list.h"

struct List::Entry
{
    void* Value {nullptr};
    Entry* Next {nullptr};
};

List::~List()
{
    Kill();
}

void* List::Access(i32 index)
{
    if (index < 1 || index > size_)
        return nullptr;

    Entry* entry = first_;

    for (; index > 1; --index)
        entry = entry->Next;

    return entry->Value;
}

b32 List::Delete(i32 index)
{
    if (index < 1 || index > size_)
        return false;

    Entry** here = &first_;

    for (; index > 1; --index)
        here = &(*here)->Next;

    Entry* entry = *here;

    *here = entry->Next;
    --size_;

    delete entry;

    return true;
}

b32 List::Insert(i32 index, void* value)
{
    if (index < 1 || index > size_ + 1)
        return false;

    Entry* entry = new Entry {value};

    Entry** here = &first_;

    for (; index > 1; --index)
        here = &(*here)->Next;

    entry->Next = *here;
    *here = entry;
    ++size_;

    return true;
}

void List::Kill()
{
    while (size_)
        Delete(1);
}
