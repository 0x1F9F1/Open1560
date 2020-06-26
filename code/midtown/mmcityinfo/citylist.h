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
    mmcityinfo:citylist

    0x4CBC10 | public: __thiscall mmCityList::mmCityList(void) | ??0mmCityList@@QAE@XZ
    0x4CBC30 | public: virtual __thiscall mmCityList::~mmCityList(void) | ??1mmCityList@@UAE@XZ
    0x4CBC90 | public: void __thiscall mmCityList::Init(int) | ?Init@mmCityList@@QAEXH@Z
    0x4CBCA0 | public: class mmCityInfo * __thiscall mmCityList::GetCityInfo(int) | ?GetCityInfo@mmCityList@@QAEPAVmmCityInfo@@H@Z
    0x4CBCD0 | public: class mmCityInfo * __thiscall mmCityList::GetCityInfo(char *) | ?GetCityInfo@mmCityList@@QAEPAVmmCityInfo@@PAD@Z
    0x4CBD50 | public: int __thiscall mmCityList::GetCityID(char *) | ?GetCityID@mmCityList@@QAEHPAD@Z
    0x4CBDD0 | public: void __thiscall mmCityList::SetCurrentCity(char *) | ?SetCurrentCity@mmCityList@@QAEXPAD@Z
    0x4CBDF0 | public: void __thiscall mmCityList::SetCurrentCity(int) | ?SetCurrentCity@mmCityList@@QAEXH@Z
    0x4CBE20 | public: class mmCityInfo * __thiscall mmCityList::GetCurrentCity(void) | ?GetCurrentCity@mmCityList@@QAEPAVmmCityInfo@@XZ
    0x4CBE30 | public: void __thiscall mmCityList::Load(char *) | ?Load@mmCityList@@QAEXPAD@Z
    0x4CBF60 | public: void __thiscall mmCityList::Print(void) | ?Print@mmCityList@@QAEXXZ
    0x4CBFA0 | public: void __thiscall mmCityList::LoadAll(void) | ?LoadAll@mmCityList@@QAEXXZ
    0x4CC050 | public: virtual void * __thiscall mmCityList::`vector deleting destructor'(unsigned int) | ??_EmmCityList@@UAEPAXI@Z
    0x4CC050 | public: virtual void * __thiscall mmCityList::`scalar deleting destructor'(unsigned int) | ??_GmmCityList@@UAEPAXI@Z
    0x61F8AC | const mmCityList::`vftable' | ??_7mmCityList@@6B@
    0x7084E4 | class mmCityList * CityListPtr | ?CityListPtr@@3PAVmmCityList@@A
*/

class mmCityList
{
    // const mmCityList::`vftable' @ 0x61F8AC

public:
    // 0x4CBC10 | ??0mmCityList@@QAE@XZ
    ARTS_IMPORT mmCityList();

    // 0x4CC050 | ??_GmmCityList@@UAEPAXI@Z
    // 0x4CBC30 | ??1mmCityList@@UAE@XZ
    ARTS_IMPORT virtual ~mmCityList();

    // 0x4CBD50 | ?GetCityID@mmCityList@@QAEHPAD@Z
    ARTS_IMPORT i32 GetCityID(char* arg1);

    // 0x4CBCD0 | ?GetCityInfo@mmCityList@@QAEPAVmmCityInfo@@PAD@Z
    ARTS_IMPORT class mmCityInfo* GetCityInfo(char* arg1);

    // 0x4CBCA0 | ?GetCityInfo@mmCityList@@QAEPAVmmCityInfo@@H@Z
    ARTS_IMPORT class mmCityInfo* GetCityInfo(i32 arg1);

    // 0x4CBE20 | ?GetCurrentCity@mmCityList@@QAEPAVmmCityInfo@@XZ
    ARTS_IMPORT class mmCityInfo* GetCurrentCity();

    // 0x4CBC90 | ?Init@mmCityList@@QAEXH@Z | unused
    ARTS_IMPORT void Init(i32 arg1);

    // 0x4CBE30 | ?Load@mmCityList@@QAEXPAD@Z
    ARTS_IMPORT void Load(char* arg1);

    // 0x4CBFA0 | ?LoadAll@mmCityList@@QAEXXZ
    ARTS_IMPORT void LoadAll();

    // 0x4CBF60 | ?Print@mmCityList@@QAEXXZ | unused
    ARTS_IMPORT void Print();

    // 0x4CBDD0 | ?SetCurrentCity@mmCityList@@QAEXPAD@Z
    ARTS_IMPORT void SetCurrentCity(char* arg1);

    // 0x4CBDF0 | ?SetCurrentCity@mmCityList@@QAEXH@Z
    ARTS_IMPORT void SetCurrentCity(i32 arg1);

    u8 gap4[0xC];
};

check_size(mmCityList, 0x10);

// 0x7084E4 | ?CityListPtr@@3PAVmmCityList@@A
ARTS_IMPORT extern class mmCityList* CityListPtr;
