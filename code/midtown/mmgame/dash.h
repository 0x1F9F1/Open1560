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
    mmgame:dash

    0x4215D0 | public: __thiscall mmDashView::mmDashView(void) | ??0mmDashView@@QAE@XZ
    0x421770 | public: virtual __thiscall mmDashView::~mmDashView(void) | ??1mmDashView@@UAE@XZ
    0x421880 | public: void __thiscall mmDashView::Init(char *,class mmPlayer *) | ?Init@mmDashView@@QAEXPADPAVmmPlayer@@@Z
    0x421C10 | public: virtual void __thiscall mmDashView::Reset(void) | ?Reset@mmDashView@@UAEXXZ
    0x421C20 | public: virtual void __thiscall mmDashView::BeforeSave(void) | ?BeforeSave@mmDashView@@UAEXXZ
    0x421CC0 | public: virtual void __thiscall mmDashView::AfterLoad(void) | ?AfterLoad@mmDashView@@UAEXXZ
    0x421D60 | public: void __thiscall mmDashView::ActivateUntilTransitionIsOver(void) | ?ActivateUntilTransitionIsOver@mmDashView@@QAEXXZ
    0x421D80 | public: void __thiscall mmDashView::Activate(void) | ?Activate@mmDashView@@QAEXXZ
    0x421DA0 | public: void __thiscall mmDashView::Deactivate(void) | ?Deactivate@mmDashView@@QAEXXZ
    0x421DC0 | public: void __thiscall mmDashView::TempDeactivate(void) | ?TempDeactivate@mmDashView@@QAEXXZ
    0x421DD0 | public: virtual void __thiscall mmDashView::Update(void) | ?Update@mmDashView@@UAEXXZ
    0x421F00 | public: virtual void __thiscall mmDashView::Cull(void) | ?Cull@mmDashView@@UAEXXZ
    0x4220F0 | public: __thiscall mmExternalView::mmExternalView(void) | ??0mmExternalView@@QAE@XZ
    0x422170 | public: void __thiscall mmExternalView::Init(class mmPlayer *) | ?Init@mmExternalView@@QAEXPAVmmPlayer@@@Z
    0x4221B0 | public: virtual void __thiscall mmExternalView::ResChange(int,int) | ?ResChange@mmExternalView@@UAEXHH@Z
    0x422300 | public: virtual void __thiscall mmExternalView::Reset(void) | ?Reset@mmExternalView@@UAEXXZ
    0x422310 | public: virtual void __thiscall mmExternalView::Update(void) | ?Update@mmExternalView@@UAEXXZ
    0x422330 | public: void __thiscall mmExternalView::WideFOV(int) | ?WideFOV@mmExternalView@@QAEXH@Z
    0x422340 | public: virtual void __thiscall mmExternalView::Cull(void) | ?Cull@mmExternalView@@UAEXXZ
    0x4224E0 | public: virtual void __thiscall mmExternalView::AddWidgets(class Bank *) | ?AddWidgets@mmExternalView@@UAEXPAVBank@@@Z
    0x4227D0 | public: virtual void __thiscall mmDashView::AddWidgets(class Bank *) | ?AddWidgets@mmDashView@@UAEXPAVBank@@@Z
    0x422BD0 | public: static void __cdecl mmDashView::DeclareFields(void) | ?DeclareFields@mmDashView@@SAXXZ
    0x422EC0 | public: virtual class MetaClass * __thiscall mmDashView::GetClass(void) | ?GetClass@mmDashView@@UAEPAVMetaClass@@XZ
    0x422F00 | public: virtual __thiscall asLinearCS::~asLinearCS(void) | ??1asLinearCS@@UAE@XZ
    0x422F10 | public: virtual __thiscall RadialGauge::~RadialGauge(void) | ??1RadialGauge@@UAE@XZ
    0x422F60 | public: virtual void * __thiscall mmExternalView::`scalar deleting destructor'(unsigned int) | ??_GmmExternalView@@UAEPAXI@Z
    0x422F60 | public: virtual void * __thiscall mmExternalView::`vector deleting destructor'(unsigned int) | ??_EmmExternalView@@UAEPAXI@Z
    0x422F90 | public: virtual void * __thiscall mmDashView::`vector deleting destructor'(unsigned int) | ??_EmmDashView@@UAEPAXI@Z
    0x61AAC0 | const mmDashView::`vftable' | ??_7mmDashView@@6B@
    0x61AB00 | const mmExternalView::`vftable' | ??_7mmExternalView@@6B@
    0x636504 | float MAX_SPEED | ?MAX_SPEED@@3MA
    0x6A72B8 | class MetaClass mmDashViewMetaClass | ?mmDashViewMetaClass@@3VMetaClass@@A
*/

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
    ARTS_IMPORT void Init(char* arg1, mmPlayer* arg2);

    // ?Reset@mmDashView@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?TempDeactivate@mmDashView@@QAEXXZ | unused
    ARTS_IMPORT void TempDeactivate();

    // ?Update@mmDashView@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmDashView@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
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
    u16 NeutralTexture;
    u16 GearTextures[11];
    i32 field_864;
    f32 DashJitterAmp;
    f32 CollisionJitterAmp;
    f32 MaxSpeed;
    f32 MaxRPM;
    f32 MinSpeed;
    u16 InTransition;
    i16 Active;
};

check_size(mmDashView, 0x880);

// ?MAX_SPEED@@3MA
ARTS_IMPORT extern f32 MAX_SPEED;
