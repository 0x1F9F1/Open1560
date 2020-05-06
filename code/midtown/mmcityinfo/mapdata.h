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
    mmcityinfo:mapdata

    0x4D3270 | public: __thiscall mmMapData::mmMapData(void) | ??0mmMapData@@QAE@XZ
    0x4D3290 | public: virtual __thiscall mmMapData::~mmMapData(void) | ??1mmMapData@@UAE@XZ
    0x4D32F0 | public: void __thiscall mmMapData::NewItems(int) | ?NewItems@mmMapData@@QAEXH@Z
    0x4D3320 | public: void __thiscall mmMapData::SetItem(int,char *) | ?SetItem@mmMapData@@QAEXHPAD@Z
    0x4D3340 | public: char * __thiscall mmMapData::GetItem(int) | ?GetItem@mmMapData@@QAEPADH@Z
    0x4D3370 | public: int __thiscall mmMapData::GetNumItems(void) | ?GetNumItems@mmMapData@@QAEHXZ
    0x4D3380 | public: void __thiscall mmMapData::Append(char *) | ?Append@mmMapData@@QAEXPAD@Z
    0x4D3400 | public: static void __cdecl mmMapData::DeclareFields(void) | ?DeclareFields@mmMapData@@SAXXZ
    0x4D35B0 | public: virtual class MetaClass * __thiscall mmMapData::GetClass(void) | ?GetClass@mmMapData@@UAEPAVMetaClass@@XZ
    0x4D35C0 | public: virtual void * __thiscall mmMapData::`vector deleting destructor'(unsigned int) | ??_EmmMapData@@UAEPAXI@Z
    0x61F930 | const mmMapData::`vftable' | ??_7mmMapData@@6B@
    0x708690 | class MetaClass mmMapDataMetaClass | ?mmMapDataMetaClass@@3VMetaClass@@A
*/

#include "infobase.h"

class mmMapData : public mmInfoBase
{
    // const mmMapData::`vftable' @ 0x61F930

public:
    // 0x4D3270 | ??0mmMapData@@QAE@XZ
    mmMapData();

    // 0x4D35C0 | ??_EmmMapData@@UAEPAXI@Z
    // 0x4D3290 | ??1mmMapData@@UAE@XZ
    ~mmMapData() override;

    // 0x4D3380 | ?Append@mmMapData@@QAEXPAD@Z
    void Append(char* arg1);

    // 0x4D35B0 | ?GetClass@mmMapData@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4D3340 | ?GetItem@mmMapData@@QAEPADH@Z
    char* GetItem(i32 arg1);

    // 0x4D3370 | ?GetNumItems@mmMapData@@QAEHXZ
    i32 GetNumItems();

    // 0x4D32F0 | ?NewItems@mmMapData@@QAEXH@Z
    void NewItems(i32 arg1);

    // 0x4D3320 | ?SetItem@mmMapData@@QAEXHPAD@Z
    void SetItem(i32 arg1, char* arg2);

    // 0x4D3400 | ?DeclareFields@mmMapData@@SAXXZ
    static void DeclareFields();
};

check_size(mmMapData, 0x90);

// 0x708690 | ?mmMapDataMetaClass@@3VMetaClass@@A
inline extern_var(0x708690, class MetaClass, mmMapDataMetaClass);
