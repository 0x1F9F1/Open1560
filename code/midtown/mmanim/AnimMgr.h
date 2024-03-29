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
    mmanim:AnimMgr

    0x4C1110 | public: __thiscall mmAnimMgr::mmAnimMgr(void) | ??0mmAnimMgr@@QAE@XZ
    0x4C1190 | public: virtual __thiscall mmAnimMgr::~mmAnimMgr(void) | ??1mmAnimMgr@@UAE@XZ
    0x4C11F0 | public: int __thiscall mmAnimMgr::Init(char *,class mmInstance *,class mmInstance * *,int) | ?Init@mmAnimMgr@@QAEHPADPAVmmInstance@@PAPAV2@H@Z
    0x4C13A0 | public: virtual void __thiscall mmAnimMgr::Update(void) | ?Update@mmAnimMgr@@UAEXXZ
    0x4C13B0 | public: void __thiscall mmAnimMgr::TestDOFAct(int) | ?TestDOFAct@mmAnimMgr@@QAEXH@Z
    0x4C13C0 | public: void __thiscall mmAnimMgr::AirlinerSwap(void) | ?AirlinerSwap@mmAnimMgr@@QAEXXZ
    0x4C1400 | public: void __thiscall mmAnimMgr::UFOSwap(void) | ?UFOSwap@mmAnimMgr@@QAEXXZ
    0x4C1440 | public: static void __cdecl mmAnimMgr::DeclareFields(void) | ?DeclareFields@mmAnimMgr@@SAXXZ
    0x4C15B0 | public: virtual class MetaClass * __thiscall mmAnimMgr::GetClass(void) | ?GetClass@mmAnimMgr@@UAEPAVMetaClass@@XZ
    0x4C15C0 | public: virtual void * __thiscall mmAnimSpline::`vector deleting destructor'(unsigned int) | ??_EmmAnimSpline@@UAEPAXI@Z
    0x4C1620 | public: virtual void * __thiscall mmAnimMgr::`vector deleting destructor'(unsigned int) | ??_EmmAnimMgr@@UAEPAXI@Z
    0x61F308 | const mmAnimMgr::`vftable' | ??_7mmAnimMgr@@6B@
    0x705D68 | class MetaClass mmAnimMgrMetaClass | ?mmAnimMgrMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

#include "Excel.h"
#include "bridge.h"

class mmAnimSpline;
class mmInstance;

class mmAnimMgr final : public asNode
{
public:
    // ??0mmAnimMgr@@QAE@XZ
    ARTS_IMPORT mmAnimMgr();

    // ??_EmmAnimMgr@@UAEPAXI@Z
    // ??1mmAnimMgr@@UAE@XZ
    ARTS_IMPORT ~mmAnimMgr() override;

    // ?AirlinerSwap@mmAnimMgr@@QAEXXZ
    ARTS_IMPORT void AirlinerSwap();

    // ?GetClass@mmAnimMgr@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmAnimMgr@@QAEHPADPAVmmInstance@@PAPAV2@H@Z
    ARTS_IMPORT i32 Init(char* arg1, mmInstance* arg2, mmInstance** arg3, i32 arg4);

    // ?TestDOFAct@mmAnimMgr@@QAEXH@Z
    ARTS_EXPORT void TestDOFAct(i32 arg1);

    // ?UFOSwap@mmAnimMgr@@QAEXXZ
    ARTS_IMPORT void UFOSwap();

    // ?Update@mmAnimMgr@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmAnimMgr@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    ARTS_ZEROED;

    mmAnimExcel AnimExcel;
    i32 field_30;
    mmAnimSpline* Splines;
    mmBridgeMgr BridgeMgr;
    i32 SplineCount;
};

check_size(mmAnimMgr, 0x26B0);
