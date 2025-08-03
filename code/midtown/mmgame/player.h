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
