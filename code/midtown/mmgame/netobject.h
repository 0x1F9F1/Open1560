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

class mmCar;
struct NETGAME_MSG;

class mmNetObject final : public asNetObject
{
public:
    // ??0mmNetObject@@QAE@XZ
    ARTS_IMPORT mmNetObject();

    // ??_GmmNetObject@@UAEPAXI@Z
    // ??_EmmNetObject@@UAEPAXI@Z
    // ??1mmNetObject@@UAE@XZ
    ARTS_IMPORT ~mmNetObject() override = default;

    // ?Activate@mmNetObject@@QAEXXZ
    ARTS_IMPORT void Activate();

    // ?Clear@mmNetObject@@QAEXXZ
    ARTS_IMPORT void Clear();

    // ?Deactivate@mmNetObject@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // ?Init@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    ARTS_IMPORT void Init(mmCar* arg1, char* arg2, i32 arg3, ulong arg4, char* arg5);

    // ?PositionUpdate@mmNetObject@@QAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void PositionUpdate(NETGAME_MSG* arg1);

    // ?Predict@mmNetObject@@QAEXXZ
    ARTS_IMPORT void Predict();

    // ?ReInit@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    ARTS_IMPORT void ReInit(mmCar* arg1, char* arg2, i32 arg3, ulong arg4, char* arg5);

    // ?SetActive@mmNetObject@@QAEXH@Z
    ARTS_IMPORT void SetActive(i32 arg1);

    // ?SetCar@mmNetObject@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void SetCar(mmCar* arg1);

    // ?SetLocalData@mmNetObject@@UAEXXZ
    ARTS_IMPORT void SetLocalData() override;

    // ?SetScore@mmNetObject@@QAEXH@Z | unused
    ARTS_IMPORT void SetScore(i32 arg1);

    // ?Update@mmNetObject@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap28[0xCC];
};

check_size(mmNetObject, 0xF4);

// ?time_delta@@3MA
ARTS_IMPORT extern f32 time_delta;
