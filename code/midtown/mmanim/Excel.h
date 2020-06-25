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
    mmanim:Excel

    0x4C34D0 | public: __thiscall mmAnimExcel::mmAnimExcel(void) | ??0mmAnimExcel@@QAE@XZ
    0x4C34F0 | public: virtual __thiscall mmAnimExcel::~mmAnimExcel(void) | ??1mmAnimExcel@@UAE@XZ
    0x4C3530 | public: int __thiscall mmAnimExcel::Init(char *,char *) | ?Init@mmAnimExcel@@QAEHPAD0@Z
    0x4C35C0 | public: char * __thiscall mmAnimExcel::GetNextName(void) | ?GetNextName@mmAnimExcel@@QAEPADXZ
    0x4C3600 | public: void __thiscall mmAnimExcel::AddFile(char *,char *) | ?AddFile@mmAnimExcel@@QAEXPAD0@Z
    0x4C3740 | public: char * __thiscall mmAnimExcel::GetPriorName(void) | ?GetPriorName@mmAnimExcel@@QAEPADXZ
    0x4C3770 | public: char * __thiscall mmAnimExcel::GetName(int) | ?GetName@mmAnimExcel@@QAEPADH@Z
    0x4C37A0 | public: virtual void * __thiscall mmAnimExcel::`scalar deleting destructor'(unsigned int) | ??_GmmAnimExcel@@UAEPAXI@Z
    0x4C37A0 | public: virtual void * __thiscall mmAnimExcel::`vector deleting destructor'(unsigned int) | ??_EmmAnimExcel@@UAEPAXI@Z
    0x61F3EC | const mmAnimExcel::`vftable' | ??_7mmAnimExcel@@6B@
*/

struct mmAnimExcel
{
    // const mmAnimExcel::`vftable' @ 0x61F3EC

public:
    // 0x4C34D0 | ??0mmAnimExcel@@QAE@XZ
    ARTS_IMPORT mmAnimExcel();

    // 0x4C37A0 | ??_EmmAnimExcel@@UAEPAXI@Z
    // 0x4C34F0 | ??1mmAnimExcel@@UAE@XZ
    ARTS_IMPORT virtual ~mmAnimExcel();

    // 0x4C3600 | ?AddFile@mmAnimExcel@@QAEXPAD0@Z
    ARTS_IMPORT void AddFile(char* arg1, char* arg2);

    // 0x4C3770 | ?GetName@mmAnimExcel@@QAEPADH@Z
    ARTS_IMPORT char* GetName(i32 arg1);

    // 0x4C35C0 | ?GetNextName@mmAnimExcel@@QAEPADXZ | unused
    ARTS_IMPORT char* GetNextName();

    // 0x4C3740 | ?GetPriorName@mmAnimExcel@@QAEPADXZ | unused
    ARTS_IMPORT char* GetPriorName();

    // 0x4C3530 | ?Init@mmAnimExcel@@QAEHPAD0@Z
    ARTS_IMPORT i32 Init(char* arg1, char* arg2);
};

check_size(mmAnimExcel, 0x0);
