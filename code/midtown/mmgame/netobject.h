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
    mmgame:netobject

    0x432740 | public: __thiscall mmNetObject::mmNetObject(void) | ??0mmNetObject@@QAE@XZ
    0x4327F0 | public: virtual __thiscall mmNetObject::~mmNetObject(void) | ??1mmNetObject@@UAE@XZ
    0x432800 | public: void __thiscall mmNetObject::Clear(void) | ?Clear@mmNetObject@@QAEXXZ
    0x432850 | public: void __thiscall mmNetObject::Activate(void) | ?Activate@mmNetObject@@QAEXXZ
    0x4328A0 | public: void __thiscall mmNetObject::Deactivate(void) | ?Deactivate@mmNetObject@@QAEXXZ
    0x432900 | public: void __thiscall mmNetObject::Init(class mmCar *,char *,int,unsigned long,char *) | ?Init@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    0x432980 | public: void __thiscall mmNetObject::ReInit(class mmCar *,char *,int,unsigned long,char *) | ?ReInit@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    0x432A40 | public: void __thiscall mmNetObject::SetCar(class mmCar *) | ?SetCar@mmNetObject@@QAEXPAVmmCar@@@Z
    0x432A50 | public: void __thiscall mmNetObject::SetActive(int) | ?SetActive@mmNetObject@@QAEXH@Z
    0x432A70 | public: void __thiscall mmNetObject::SetScore(int) | ?SetScore@mmNetObject@@QAEXH@Z
    0x432A80 | public: virtual void __thiscall mmNetObject::SetLocalData(void) | ?SetLocalData@mmNetObject@@UAEXXZ
    0x432BD0 | public: void __thiscall mmNetObject::PositionUpdate(struct NETGAME_MSG *) | ?PositionUpdate@mmNetObject@@QAEXPAUNETGAME_MSG@@@Z
    0x432F80 | public: void __thiscall mmNetObject::Predict(void) | ?Predict@mmNetObject@@QAEXXZ
    0x433130 | public: virtual void __thiscall mmNetObject::Update(void) | ?Update@mmNetObject@@UAEXXZ
    0x4331D0 | public: virtual void * __thiscall mmNetObject::`vector deleting destructor'(unsigned int) | ??_EmmNetObject@@UAEPAXI@Z
    0x4331D0 | public: virtual void * __thiscall mmNetObject::`scalar deleting destructor'(unsigned int) | ??_GmmNetObject@@UAEPAXI@Z
    0x61B120 | const mmNetObject::`vftable' | ??_7mmNetObject@@6B@
    0x6A77E8 | float time_delta | ?time_delta@@3MA
*/

#include "mmnetwork/netobject.h"

class mmNetObject : public asNetObject
{
    // const mmNetObject::`vftable' @ 0x61B120

public:
    // 0x432740 | ??0mmNetObject@@QAE@XZ
    ARTS_IMPORT mmNetObject();

    // 0x4331D0 | ??_GmmNetObject@@UAEPAXI@Z
    // 0x4327F0 | ??1mmNetObject@@UAE@XZ
    ARTS_IMPORT ~mmNetObject() override;

    // 0x432850 | ?Activate@mmNetObject@@QAEXXZ
    ARTS_IMPORT void Activate();

    // 0x432800 | ?Clear@mmNetObject@@QAEXXZ
    ARTS_IMPORT void Clear();

    // 0x4328A0 | ?Deactivate@mmNetObject@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // 0x432900 | ?Init@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    ARTS_IMPORT void Init(class mmCar* arg1, char* arg2, i32 arg3, u32 arg4, char* arg5);

    // 0x432BD0 | ?PositionUpdate@mmNetObject@@QAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void PositionUpdate(struct NETGAME_MSG* arg1);

    // 0x432F80 | ?Predict@mmNetObject@@QAEXXZ
    ARTS_IMPORT void Predict();

    // 0x432980 | ?ReInit@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    ARTS_IMPORT void ReInit(class mmCar* arg1, char* arg2, i32 arg3, u32 arg4, char* arg5);

    // 0x432A50 | ?SetActive@mmNetObject@@QAEXH@Z
    ARTS_IMPORT void SetActive(i32 arg1);

    // 0x432A40 | ?SetCar@mmNetObject@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void SetCar(class mmCar* arg1);

    // 0x432A80 | ?SetLocalData@mmNetObject@@UAEXXZ
    ARTS_IMPORT void SetLocalData() override;

    // 0x432A70 | ?SetScore@mmNetObject@@QAEXH@Z | unused
    ARTS_IMPORT void SetScore(i32 arg1);

    // 0x433130 | ?Update@mmNetObject@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap28[0xCC];
};

check_size(mmNetObject, 0xF4);

// 0x6A77E8 | ?time_delta@@3MA
ARTS_IMPORT extern f32 time_delta;
