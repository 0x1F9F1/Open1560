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

#include "arts7/linear.h"
#include "arts7/node.h"

#include "arts7/form.h"
#include "gauge.h"

class agiMeshSet;
class mmPlayer;

class mmExternalView final : public asNode
{
public:
    // ??0mmExternalView@@QAE@XZ
    ARTS_IMPORT mmExternalView();

    // ??_EmmExternalView@@UAEPAXI@Z
    // ??_GmmExternalView@@UAEPAXI@Z
    // ??1mmExternalView@@UAE@XZ | inline
    ARTS_IMPORT ~mmExternalView() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmExternalView@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmExternalView@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Init@mmExternalView@@QAEXPAVmmPlayer@@@Z
    ARTS_IMPORT void Init(mmPlayer* arg1);

    // ?ResChange@mmExternalView@@UAEXHH@Z
    ARTS_IMPORT void ResChange(i32 arg1, i32 arg2) override;

    // ?Reset@mmExternalView@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@mmExternalView@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?WideFOV@mmExternalView@@QAEXH@Z
    ARTS_EXPORT void WideFOV(i32 arg1);

    u8 gap20[0xEC];
};

check_size(mmExternalView, 0x10C);

class mmDashView final : public asLinearCS
{
public:
    // ??0mmDashView@@QAE@XZ
    ARTS_IMPORT mmDashView();

    // ??_EmmDashView@@UAEPAXI@Z
    // ??1mmDashView@@UAE@XZ
    ARTS_IMPORT ~mmDashView() override;

    // ?Activate@mmDashView@@QAEXXZ
    ARTS_IMPORT void Activate();

    // ?ActivateUntilTransitionIsOver@mmDashView@@QAEXXZ
    ARTS_IMPORT void ActivateUntilTransitionIsOver();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmDashView@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AfterLoad@mmDashView@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // ?BeforeSave@mmDashView@@UAEXXZ
    ARTS_IMPORT void BeforeSave() override;

    // ?Cull@mmDashView@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?Deactivate@mmDashView@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // ?GetClass@mmDashView@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmDashView@@QAEXPADPAVmmPlayer@@@Z
    ARTS_EXPORT void Init(char* name, mmPlayer* player);

    // ?Reset@mmDashView@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@mmDashView@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmDashView@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

public:
    mmPlayer* Player;
    u8 gap_8C[12];
    RadialGauge RPMGuage;
    RadialGauge SpeedGuage;
    RadialGauge DamageGuage;
    Vector3 SpeedPos;
    Vector3 RPMPos;
    Vector3 DamagePos;
    f32 SpeedMinRot;
    f32 SpeedMaxRot;
    f32 RPMMinRot;
    f32 RPMMaxRot;
    f32 DamageMinRot;
    f32 DamgeMaxRot;
    f32 WheelFact;
    f32 field_33C;
    asLinearCS DashLCS;
    asLinearCS WheelLCS;
    asLinearCS RoofLCS;
    asForm field_4D8;
    asForm field_5A0;
    asForm field_668;
    asForm field_730;
    agiMeshSet* DashMesh;
    agiMeshSet* WheelMesh;
    agiMeshSet* GearMesh;
    agiMeshSet* RoofMesh;
    Vector3 WheelOffset;
    Vector3 DashPos;
    Vector3 RoofPos;
    Vector3 DashCamOffset;
    i32 field_838;
    i32 field_83C;
    i32 field_840;
    i32 field_844;
    i32 field_848;
    [[deprecated]] u16 GearTextures[12]; // Unused, see DASH_GEAR_* for indices
    i32 field_864;
    f32 DashJitterAmp;
    f32 CollisionJitterAmp;
    f32 MaxSpeed;
    f32 MaxRPM;
    f32 MinSpeed;
    u16 InTransition;
    b16 Active;
};

check_size(mmDashView, 0x880);

// ?MAX_SPEED@@3MA
ARTS_IMPORT extern f32 MAX_SPEED;
