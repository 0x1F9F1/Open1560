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
#include "mmcity/inst.h"

class agiPhysParameters;
class mmWheel;

class mmSkid final : public mmInstance
{
public:
    // ??0mmSkid@@QAE@XZ
    ARTS_IMPORT mmSkid();

    // ??_EmmSkid@@UAEPAXI@Z
    // ??1mmSkid@@UAE@XZ
    ARTS_EXPORT ~mmSkid() override = default;

    // ?AddSkid@mmSkid@@QAEXAAVMatrix34@@PAVVector3@@PAVagiPhysParameters@@M@Z
    ARTS_IMPORT void AddSkid(Matrix34& arg1, Vector3* arg2, agiPhysParameters* arg3, f32 arg4);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmSkid@@UAEXPAVBank@@@Z | inline
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Draw@mmSkid@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?DrawShadow@mmSkid@@UAIXXZ
    ARTS_EXPORT void ARTS_FASTCALL DrawShadow() override;

    // ?FromMatrix@mmSkid@@UAIXABVMatrix34@@@Z
    ARTS_EXPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetClass@mmSkid@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetPos@mmSkid@@UAIAAVVector3@@XZ
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?Init@mmSkid@@QAEXPAD@Z
    ARTS_IMPORT void Init(char* arg1);

    // ?ToMatrix@mmSkid@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    // ?Update@mmSkid@@QAEXXZ | unused
    ARTS_EXPORT void Update();

    // ?DeclareFields@mmSkid@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap14[0x34];
};

check_size(mmSkid, 0x48);

class mmSkidManager final : public asNode
{
public:
    // ??0mmSkidManager@@QAE@XZ
    ARTS_IMPORT mmSkidManager();

    // ??_EmmSkidManager@@UAEPAXI@Z
    // ??1mmSkidManager@@UAE@XZ
    ARTS_IMPORT ~mmSkidManager() override;

    // ?GetClass@mmSkidManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmSkidManager@@QAEXPADHPAVmmWheel@@@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, mmWheel* arg3);

    // ?LayTrack@mmSkidManager@@QAEXXZ
    ARTS_IMPORT void LayTrack();

    // ?ReInit@mmSkidManager@@QAEXPAVmmWheel@@@Z
    ARTS_IMPORT void ReInit(mmWheel* arg1);

    // ?Reset@mmSkidManager@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@mmSkidManager@@UAEXXZ
    ARTS_EXPORT void Update() override;

    // ?DeclareFields@mmSkidManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    mmWheel* Wheel {};
    mmSkid* Skids {};
    i32 MaxSkids {};
    i32 field_2C {};
    f32 TimeSinceLastTrack {};
    f32 FourWheelRadius2 {};
    i32 SkidIndex {};
    i32 NotSkidding {};
    Vector3 field_40 {};
    Vector3 field_4C {};
    i32 field_58 {};
    i32 field_5C {};
    i32 field_60 {};
    i32 field_64 {};
};

check_size(mmSkidManager, 0x68);
