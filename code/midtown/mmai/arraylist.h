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
    mmai:arraylist

    0x446C00 | public: __thiscall CArrayList::~CArrayList(void) | ??1CArrayList@@QAE@XZ
    0x446C20 | public: void __thiscall CArrayList::Append(int) | ?Append@CArrayList@@QAEXH@Z
*/

class CArrayList /*final*/
{
public:
    // 0x43C180 | ??0CArrayList@@QAE@XZ | inline
    ARTS_IMPORT CArrayList();

    // 0x43C070 | ??_ECArrayList@@QAEPAXI@Z | unused
    // 0x446C00 | ??1CArrayList@@QAE@XZ
    ARTS_IMPORT ~CArrayList();

    // 0x446C20 | ?Append@CArrayList@@QAEXH@Z
    ARTS_IMPORT void Append(i32 arg1);

    u8 gap0[0x8];
};

check_size(CArrayList, 0x8);
