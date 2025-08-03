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

    // ??1mmAnimMgr@@UAE@XZ
    ARTS_IMPORT ~mmAnimMgr() override;

    // ?AirlinerSwap@mmAnimMgr@@QAEXXZ
    ARTS_IMPORT void AirlinerSwap();

    // ?GetClass@mmAnimMgr@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmAnimMgr@@QAEHPADPAVmmInstance@@PAPAV2@H@Z
    ARTS_IMPORT i32 Init(char* arg1, mmInstance* arg2, mmInstance** arg3, i32 arg4);

    // ?TestDOFAct@mmAnimMgr@@QAEXH@Z
    void TestDOFAct(i32 arg1);

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
