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

#include "mmbangers/dof.h"

class mmAnimTrigger;

class mmDrawbridgeInstance final : public mmDofBangerInstance
{
public:
    // ??1mmDrawbridgeInstance@@UAE@XZ | inline
    ARTS_EXPORT ~mmDrawbridgeInstance() override = default;

    // ?Draw@mmDrawbridgeInstance@@UAIXH@Z
    ARTS_EXPORT void ARTS_FASTCALL Draw(i32 lod) override;

    // ?InitBridge@mmDrawbridgeInstance@@QAEHPAD0HPAVMatrix34@@PAVVector3@@@Z
    ARTS_IMPORT i32 InitBridge(char* name, char* part, i32 flags, Matrix34* matrix, Vector3* offset);
};

check_size(mmDrawbridgeInstance, 0x34);

class mmAnimDOF final
{
public:
    // ??0mmAnimDOF@@QAE@XZ
    ARTS_IMPORT mmAnimDOF();

    // ??1mmAnimDOF@@QAE@XZ
    ARTS_EXPORT ~mmAnimDOF();

    // ?GetClass@mmAnimDOF@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT virtual MetaClass* GetClass();

    // ?Init@mmAnimDOF@@QAEHPAVmmAnimTrigger@@PADAAVVector3@@2HPAH@Z
    ARTS_IMPORT i32 Init(mmAnimTrigger* arg1, char* arg2, Vector3& arg3, Vector3& arg4, i32 arg5, i32* arg6);

    // ?Reset@mmAnimDOF@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?SetState@mmAnimDOF@@QAEXH@Z
    ARTS_IMPORT void SetState(i32 arg1);

    // ?SetSwitch@mmAnimDOF@@QAEXH@Z
    ARTS_IMPORT void SetSwitch(i32 arg1);

    // ?Update@mmAnimDOF@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?DeclareFields@mmAnimDOF@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Vector3 field_4;
    mmUnhitBangerInstance* UnhitBanger;
    mmDofBangerInstance* DofBanger;
    Matrix34 field_18;
    Matrix34 field_48;
    Vector3 RotationAxis;
    i32 field_84;
    i32 field_88;
    i32 field_8C;
    i32 Opposite;
    mmAnimTrigger* Trigger;
};

check_size(mmAnimDOF, 0x98);

inline mmAnimDOF::~mmAnimDOF() = default;
