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
    mmgame:player

    0x429FF0 | public: __thiscall mmPlayer::mmPlayer(void) | ??0mmPlayer@@QAE@XZ
    0x42A370 | public: virtual void __thiscall mmPlayer::BeforeSave(void) | ?BeforeSave@mmPlayer@@UAEXXZ
    0x42A380 | public: virtual void __thiscall mmPlayer::AfterLoad(void) | ?AfterLoad@mmPlayer@@UAEXXZ
    0x42A390 | public: void __thiscall mmPlayer::ReInit(char *) | ?ReInit@mmPlayer@@QAEXPAD@Z
    0x42A520 | public: void __thiscall mmPlayer::Init(char *,char *,class mmGame *) | ?Init@mmPlayer@@QAEXPAD0PAVmmGame@@@Z
    0x42A9A0 | public: void __thiscall mmPlayer::SetMirrorFOV(void) | ?SetMirrorFOV@mmPlayer@@QAEXXZ
    0x42A9D0 | public: void __thiscall mmPlayer::SetPreRaceCam(void) | ?SetPreRaceCam@mmPlayer@@QAEXXZ
    0x42AAF0 | public: void __thiscall mmPlayer::SetPostRaceCam(void) | ?SetPostRaceCam@mmPlayer@@QAEXXZ
    0x42AC10 | public: int __thiscall mmPlayer::IsPOV(void) | ?IsPOV@mmPlayer@@QAEHXZ
    0x42AC60 | public: void __thiscall mmPlayer::SetWideFOV(int) | ?SetWideFOV@mmPlayer@@QAEXH@Z
    0x42ADF0 | public: void __thiscall mmPlayer::ToggleWideFOV(void) | ?ToggleWideFOV@mmPlayer@@QAEXXZ
    0x42AE10 | public: void __thiscall mmPlayer::ToggleCam(void) | ?ToggleCam@mmPlayer@@QAEXXZ
    0x42AF30 | public: void __thiscall mmPlayer::ToggleExternalView(void) | ?ToggleExternalView@mmPlayer@@QAEXXZ
    0x42B0E0 | public: void __thiscall mmPlayer::ToggleDash(void) | ?ToggleDash@mmPlayer@@QAEXXZ
    0x42B310 | public: void __thiscall mmPlayer::UpdateHOG(void) | ?UpdateHOG@mmPlayer@@QAEXXZ
    0x42B440 | public: virtual void __thiscall mmPlayer::Reset(void) | ?Reset@mmPlayer@@UAEXXZ
    0x42B5F0 | public: void __thiscall mmPlayer::SetSteering(float) | ?SetSteering@mmPlayer@@QAEXM@Z
    0x42BBC0 | public: virtual void __thiscall mmPlayer::Update(void) | ?Update@mmPlayer@@UAEXXZ
    0x42C420 | public: void __thiscall mmPlayer::SetCamInterest(class asInertialCS *) | ?SetCamInterest@mmPlayer@@QAEXPAVasInertialCS@@@Z
    0x42C490 | public: int __thiscall mmPlayer::IsMaxDamaged(void) | ?IsMaxDamaged@mmPlayer@@QAEHXZ
    0x42C4C0 | public: void __thiscall mmPlayer::EnableRegen(int) | ?EnableRegen@mmPlayer@@QAEXH@Z
    0x42C4E0 | public: void __thiscall mmPlayer::ResetDamage(void) | ?ResetDamage@mmPlayer@@QAEXXZ
    0x42C4F0 | public: void __thiscall mmPlayer::UpdateRegen(void) | ?UpdateRegen@mmPlayer@@QAEXXZ
    0x42C590 | public: virtual void __thiscall mmPlayer::AddWidgets(class Bank *) | ?AddWidgets@mmPlayer@@UAEXPAVBank@@@Z
    0x42CD40 | public: static void __cdecl mmPlayer::DeclareFields(void) | ?DeclareFields@mmPlayer@@SAXXZ
    0x42D1B0 | public: virtual class MetaClass * __thiscall mmPlayer::GetClass(void) | ?GetClass@mmPlayer@@UAEPAVMetaClass@@XZ
    0x42D1F0 | public: virtual __thiscall mmCar::~mmCar(void) | ??1mmCar@@UAE@XZ
    0x42D2B0 | public: virtual __thiscall PolarCamCS::~PolarCamCS(void) | ??1PolarCamCS@@UAE@XZ
    0x42D2C0 | public: virtual __thiscall AICamCS::~AICamCS(void) | ??1AICamCS@@UAE@XZ
    0x42D2D0 | public: virtual __thiscall PointCamCS::~PointCamCS(void) | ??1PointCamCS@@UAE@XZ
    0x42D2E0 | public: virtual __thiscall PreCamCS::~PreCamCS(void) | ??1PreCamCS@@UAE@XZ
    0x42D2F0 | public: virtual __thiscall PostCamCS::~PostCamCS(void) | ??1PostCamCS@@UAE@XZ
    0x42D300 | public: virtual __thiscall asOverSample::~asOverSample(void) | ??1asOverSample@@UAE@XZ
    0x42D310 | public: virtual void * __thiscall mmPlayer::`vector deleting destructor'(unsigned int) | ??_EmmPlayer@@UAEPAXI@Z
    0x42D370 | public: virtual __thiscall mmPlayer::~mmPlayer(void) | ??1mmPlayer@@UAE@XZ
    0x42D510 | public: virtual __thiscall mmPhysEntity::~mmPhysEntity(void) | ??1mmPhysEntity@@UAE@XZ
    0x61AF00 | const mmPlayer::`vftable' | ??_7mmPlayer@@6B@
    0x6A7750 | class MetaClass mmPlayerMetaClass | ?mmPlayerMetaClass@@3VMetaClass@@A
    0x6A7778 | int RestoreCityCam | ?RestoreCityCam@@3HA
*/

#include "arts7/node.h"

#include "arts7/camera.h"
#include "hud.h"
#include "hudmap.h"
#include "mmcamcs/aicamcs.h"
#include "mmcamcs/pointcamcs.h"
#include "mmcamcs/polarcamcs.h"
#include "mmcamcs/postcamcs.h"
#include "mmcamcs/povcamcs.h"
#include "mmcamcs/precamcs.h"
#include "mmcamcs/trackcamcs.h"
#include "mmcar/car.h"

class mmGame;
class mmRainAudio;
class mmViewCS;

class mmPlayer final : public asNode
{
public:
    // ??0mmPlayer@@QAE@XZ
    ARTS_IMPORT mmPlayer();

    // ??_EmmPlayer@@UAEPAXI@Z
    // ??1mmPlayer@@UAE@XZ | inline
    ARTS_EXPORT ~mmPlayer() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmPlayer@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AfterLoad@mmPlayer@@UAEXXZ
    ARTS_EXPORT void AfterLoad() override;

    // ?BeforeSave@mmPlayer@@UAEXXZ
    ARTS_EXPORT void BeforeSave() override;

    // ?EnableRegen@mmPlayer@@QAEXH@Z
    ARTS_IMPORT void EnableRegen(i32 arg1);

    // ?GetClass@mmPlayer@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmPlayer@@QAEXPAD0PAVmmGame@@@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2, mmGame* arg3);

    // ?IsMaxDamaged@mmPlayer@@QAEHXZ
    ARTS_IMPORT i32 IsMaxDamaged();

    // ?IsPOV@mmPlayer@@QAEHXZ
    ARTS_IMPORT i32 IsPOV();

    // ?ReInit@mmPlayer@@QAEXPAD@Z
    ARTS_IMPORT void ReInit(char* arg1);

    // ?Reset@mmPlayer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetDamage@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ResetDamage();

    // ?SetCamInterest@mmPlayer@@QAEXPAVasInertialCS@@@Z
    ARTS_IMPORT void SetCamInterest(asInertialCS* arg1);

    // ?SetMirrorFOV@mmPlayer@@QAEXXZ | unused
    ARTS_IMPORT void SetMirrorFOV();

    // ?SetPostRaceCam@mmPlayer@@QAEXXZ
    ARTS_IMPORT void SetPostRaceCam();

    // ?SetPreRaceCam@mmPlayer@@QAEXXZ
    ARTS_IMPORT void SetPreRaceCam();

    // ?SetSteering@mmPlayer@@QAEXM@Z
    ARTS_IMPORT void SetSteering(f32 arg1);

    // ?SetWideFOV@mmPlayer@@QAEXH@Z
    ARTS_IMPORT void SetWideFOV(b32 arg1);

    // ?ToggleCam@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ToggleCam();

    // ?ToggleDash@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ToggleDash();

    // ?ToggleExternalView@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ToggleExternalView();

    // ?ToggleWideFOV@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ToggleWideFOV();

    // ?Update@mmPlayer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateHOG@mmPlayer@@QAEXXZ
    ARTS_IMPORT void UpdateHOG();

    // ?UpdateRegen@mmPlayer@@QAEXXZ
    ARTS_EXPORT void UpdateRegen();

    // ?DeclareFields@mmPlayer@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    b32 WideFov;
    f32 HogTimer;
    f32 HogTimerLimit;
    f32 HogSpeedLimit;
    i32 field_30;
    i32 CameraMode;
    mmCar Car;
    [[deprecated("Use Car.Sim")]] mmCarSim* CarSim;
    mmHUD Hud;
    mmHudMap HudMap;
    mmViewCS* ViewCS;
    CarCamCS* CarCams[6];
    i8 CamIndex;
    i8 XCamIndex;
    i8 XCamStart;
    i8 XCamCount;
    i8 WantPreRaceCam;
    i8 InAutoCam;
    i8 InPreRaceCam;
    f32 Speed;
    TrackCamCS NearCam;
    TrackCamCS FarCam;
    TrackCamCS IndCam;
    PovCamCS PovCam;
    PovCamCS DashCam;
    PolarCamCS PolarCam1;
    PolarCamCS PolarCam2;
    AICamCS AiCam;
    PointCamCS PointCam;
    i32 InWater;
    i32 DontResetDamage;
    f32 CamPan;
    PreCamCS PreCam;
    PostCamCS PostCam;
    asCamera Camera;
    i32 Score;
    i32 ForceStop;
    mmRainAudio* RainAudio;
    i32 RegenEnabled;
    Matrix34 MirrorMatrix;
    f32 ScoreWeight;
    f32 Steering;
    f32 PeggedTimer;
    f32 PeggedTheshold;
    f32 field_49C8;
    u8 gap49CC[12];
    f32 field_49D8;
    f32 field_49DC;
    f32 field_49E0;
    i16 field_49E4;
    i16 field_49E6;
    i32 field_49E8;
    i32 field_49EC;
    i32 SpeedSensitive;
    f32 SpeedBaseLow;
    f32 SpeedBaseHi;
    f32 DiscreteSteeringDeltaInHi;
    f32 DiscreteSteeringDeltaOutHi;
    f32 DiscreteSteeringFilterHi;
    f32 DiscreteSteeringDeltaInLo;
    f32 DiscreteSteeringDeltaOutLo;
    f32 DiscreteSteeringFilterLo;
    f32 MouseSensitivityLow;
    f32 MouseSteerFilterLow;
    f32 MouseSensitivityHi;
    f32 MouseSteerFilterHi;
    f32 MouseSteerFilterLow2;
    i16 SteerApp;
    f32 JoySteerApproachOutHi;
    f32 JoySteerApproachInHi;
    f32 JoySteerAppApp;
    f32 field_4A38;
    f32 JoySteerApproachOutLo;
    f32 JoySteerApproachInLo;
    f32 field_4A44;
    f32 JoySteerFilterLow;
    f32 JoySensitivityLow;
    f32 JoySteerFilterHi;
    f32 JoySensitivityHi;
    f32 field_4A58;
    f32 field_4A5C;
    i16 field_4A60;
    f32 WheelSteerApproachOutHi;
    f32 WheelSteerApproachInHi;
    f32 WheelSteerAppApp;
    f32 field_4A70;
    f32 WheelSteerApproachOutLo;
    f32 WheelSteerApproachInLo;
    f32 field_4A7C;
    f32 WheelSteerFilterLow;
    f32 WheelSensitivityLow;
    f32 WheelSteerFilterHi;
    f32 WheelSensitivityHi;
    f32 field_4A90;
    f32 field_4A94;
};

check_size(mmPlayer, 0x4A98);

// ?RestoreCityCam@@3HA
ARTS_IMPORT extern i32 RestoreCityCam;
