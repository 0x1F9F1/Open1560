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
    mmanim:AnimSpline

    0x4C37D0 | public: __thiscall mmAnimSpline::mmAnimSpline(void) | ??0mmAnimSpline@@QAE@XZ
    0x4C37F0 | public: virtual __thiscall mmAnimSpline::~mmAnimSpline(void) | ??1mmAnimSpline@@UAE@XZ
    0x4C3850 | public: int __thiscall mmAnimSpline::Init(char *,int) | ?Init@mmAnimSpline@@QAEHPADH@Z
    0x4C38F0 | public: int __thiscall mmAnimSpline::LoadFile(char *) | ?LoadFile@mmAnimSpline@@QAEHPAD@Z
    0x4C39D0 | public: void __thiscall mmAnimSpline::ClearVectors(void) | ?ClearVectors@mmAnimSpline@@QAEXXZ
    0x4C39F0 | public: void __thiscall mmAnimSpline::AddVector(class Vector3 &) | ?AddVector@mmAnimSpline@@QAEXAAVVector3@@@Z
    0x4C3A90 | public: int __thiscall mmAnimSpline::InitBoat(void) | ?InitBoat@mmAnimSpline@@QAEHXZ
    0x4C3AA0 | public: int __thiscall mmAnimSpline::InitPlane(void) | ?InitPlane@mmAnimSpline@@QAEHXZ
    0x4C3B40 | public: int __thiscall mmAnimSpline::InitTrain(void) | ?InitTrain@mmAnimSpline@@QAEHXZ
    0x4C3BC0 | public: virtual void __thiscall mmAnimSpline::Update(void) | ?Update@mmAnimSpline@@UAEXXZ
    0x4C3BF0 | public: virtual void __thiscall mmAnimSpline::Reset(void) | ?Reset@mmAnimSpline@@UAEXXZ
    0x4C3C10 | public: void __thiscall mmAnimSpline::AirlinerSwap(void) | ?AirlinerSwap@mmAnimSpline@@QAEXXZ
    0x4C3CC0 | public: void __thiscall mmAnimSpline::UFOSwap(void) | ?UFOSwap@mmAnimSpline@@QAEXXZ
    0x4C3CE0 | public: virtual void * __thiscall mmAnimSpline::`scalar deleting destructor'(unsigned int) | ??_GmmAnimSpline@@UAEPAXI@Z
    0x61F3F0 | const mmAnimSpline::`vftable' | ??_7mmAnimSpline@@6B@
*/

#include "arts7/node.h"

class mmAnimSpline /*final*/ : public asNode
{
    // const mmAnimSpline::`vftable' @ 0x61F3F0

public:
    // 0x4C37D0 | ??0mmAnimSpline@@QAE@XZ
    ARTS_IMPORT mmAnimSpline();

    // 0x4C15C0 | ??_EmmAnimSpline@@UAEPAXI@Z
    // 0x4C3CE0 | ??_GmmAnimSpline@@UAEPAXI@Z | unused
    // 0x4C37F0 | ??1mmAnimSpline@@UAE@XZ
    ARTS_IMPORT ~mmAnimSpline() override;

    // 0x4C39F0 | ?AddVector@mmAnimSpline@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void AddVector(class Vector3& arg1);

    // 0x4C3C10 | ?AirlinerSwap@mmAnimSpline@@QAEXXZ
    ARTS_IMPORT void AirlinerSwap();

    // 0x4C39D0 | ?ClearVectors@mmAnimSpline@@QAEXXZ
    ARTS_IMPORT void ClearVectors();

    // 0x4C3850 | ?Init@mmAnimSpline@@QAEHPADH@Z
    ARTS_IMPORT i32 Init(char* arg1, i32 arg2);

    // 0x4C3A90 | ?InitBoat@mmAnimSpline@@QAEHXZ
    ARTS_EXPORT i32 InitBoat();

    // 0x4C3AA0 | ?InitPlane@mmAnimSpline@@QAEHXZ
    ARTS_IMPORT i32 InitPlane();

    // 0x4C3B40 | ?InitTrain@mmAnimSpline@@QAEHXZ
    ARTS_IMPORT i32 InitTrain();

    // 0x4C38F0 | ?LoadFile@mmAnimSpline@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadFile(char* arg1);

    // 0x4C3BF0 | ?Reset@mmAnimSpline@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4C3CC0 | ?UFOSwap@mmAnimSpline@@QAEXXZ
    ARTS_IMPORT void UFOSwap();

    // 0x4C3BC0 | ?Update@mmAnimSpline@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x14];
};

check_size(mmAnimSpline, 0x34);
