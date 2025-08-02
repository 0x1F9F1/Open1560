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
#include "inst.h"

class mmPed final : public mmYInstance
{
public:
    // ??0mmPed@@QAE@XZ
    ARTS_IMPORT mmPed();

    // ??_EmmPed@@UAEPAXI@Z
    // ??1mmPed@@UAE@XZ
    ARTS_EXPORT ~mmPed() override = default;

    // ?Draw@mmPed@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?GetClass@mmPed@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmPed@@QAEXPADAAVVector3@@@Z
    ARTS_IMPORT void Init(char* arg1, Vector3& arg2);

    // ?ToMatrix@mmPed@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    // ?Update@mmPed@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?DeclareFields@mmPed@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap2C[0x8];
};

check_size(mmPed, 0x34);

class mmPedManager final : public asNode
{
public:
    // ??0mmPedManager@@QAE@XZ
    ARTS_IMPORT mmPedManager();

    // ??_EmmPedManager@@UAEPAXI@Z
    // ??1mmPedManager@@UAE@XZ
    ARTS_EXPORT ~mmPedManager() override = default;

    // ?GetClass@mmPedManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Update@mmPedManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmPedManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xC];
};

check_size(mmPedManager, 0x2C);
