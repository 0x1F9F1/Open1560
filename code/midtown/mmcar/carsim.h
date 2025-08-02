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

#include "data7/callback.h"
#include "mmeffects/birth.h"
#include "mmeffects/ptx.h"
#include "mmphysics/aero.h"
#include "mmphysics/bound.h"
#include "mmphysics/inertia.h"
#include "mmphysics/osample.h"

#include "axle.h"
#include "drivetrain.h"
#include "engine.h"
#include "force.h"
#include "gyro.h"
#include "shock.h"
#include "splash.h"
#include "stuck.h"
#include "transmission.h"
#include "wheel.h"

class mmCar;
class mmCarModel;
class mmCarRoadFF;
class mmNetworkCarAudio;
class mmOpponentCarAudio;
class mmPlayerCarAudio;
class mmPoliceCarAudio;

// ?IMPACTCB@@YAXPAVmmCarSim@@PAVasBound@@PAVmmIntersection@@PAVVector3@@M3@Z
ARTS_IMPORT void IMPACTCB(mmCarSim* arg1, asBound* arg2, mmIntersection* arg3, Vector3* arg4, f32 arg5, Vector3* arg6);

// ?HitWaterTimer@@3MA
ARTS_IMPORT extern f32 HitWaterTimer;

// ?MetricFactor@@3MA
ARTS_IMPORT extern f32 MetricFactor;

// ?PlayerPos@@3VVector3@@A
ARTS_IMPORT extern Vector3 PlayerPos;

// ?WeatherFriction@@3MA
ARTS_IMPORT extern f32 WeatherFriction;

// ?EnableSmoke@@3HA
extern b32 EnableSmoke;

// ?ForceSmoke@@3HA
extern b32 ForceSmoke;

class mmCarSim final : public asNode
{
public:
    // ??0mmCarSim@@QAE@XZ
    ARTS_IMPORT mmCarSim();

    // ??_EmmCarSim@@UAEPAXI@Z
    // ??1mmCarSim@@UAE@XZ
    ARTS_IMPORT ~mmCarSim() override;

    // ?AddPlayerSpecifics@mmCarSim@@QAEXXZ
    ARTS_IMPORT void AddPlayerSpecifics();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmCarSim@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AfterLoad@mmCarSim@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // ?BeforeSave@mmCarSim@@UAEXXZ
    ARTS_IMPORT void BeforeSave() override;

    // ?ConfigureDrivetrain@mmCarSim@@QAEXXZ
    ARTS_IMPORT void ConfigureDrivetrain();

    // ?Explode@mmCarSim@@QAEXXZ
    ARTS_IMPORT void Explode();

    // ?GetClass@mmCarSim@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmCarSim@@QAEXPADPAVmmCar@@H@Z
    ARTS_IMPORT void Init(char* arg1, mmCar* arg2, i32 arg3);

    // ?InitPtx@mmCarSim@@QAEXXZ
    ARTS_IMPORT void InitPtx();

    // ?OnGround@mmCarSim@@QAEHXZ
    ARTS_IMPORT i32 OnGround();

    // ?PlayHorn@mmCarSim@@QAEXXZ
    ARTS_IMPORT void PlayHorn();

    // ?PlayImpactAudio@mmCarSim@@QAEXFPAVmmIntersection@@PAVVector3@@@Z
    ARTS_IMPORT void PlayImpactAudio(i16 arg1, mmIntersection* arg2, Vector3* arg3);

    // ?ReInit@mmCarSim@@QAEXPAD@Z
    ARTS_IMPORT void ReInit(char* arg1);

    // ?ReconfigureDrivetrain@mmCarSim@@QAEXXZ
    ARTS_IMPORT void ReconfigureDrivetrain();

    // ?RemoveNetVehicleAudio@mmCarSim@@QAEXXZ
    ARTS_IMPORT void RemoveNetVehicleAudio();

    // ?Reset@mmCarSim@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?RestoreImpactParams@mmCarSim@@QAEXXZ
    ARTS_EXPORT void RestoreImpactParams();

    // ?SetHackedImpactParams@mmCarSim@@QAEXXZ
    ARTS_EXPORT void SetHackedImpactParams();

    // ?SetResetPos@mmCarSim@@QAEXAAVVector3@@@Z
    ARTS_EXPORT void SetResetPos(Vector3& pos);

    // ?ShouldSkid@mmCarSim@@QAEHXZ
    ARTS_EXPORT b32 ShouldSkid();

    // ?StartSiren@mmCarSim@@QAEXXZ
    ARTS_IMPORT void StartSiren();

    // ?StopHorn@mmCarSim@@QAEXXZ
    ARTS_IMPORT void StopHorn();

    // ?StopSiren@mmCarSim@@QAEXXZ
    ARTS_IMPORT void StopSiren();

    // ?UnconfigureDrivetrain@mmCarSim@@QAEXXZ
    ARTS_IMPORT void UnconfigureDrivetrain();

    // ?Update@mmCarSim@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDamage@mmCarSim@@QAEXXZ
    ARTS_IMPORT void UpdateDamage();

    // ?UpdateExhaust@mmCarSim@@QAEXXZ
    ARTS_IMPORT void UpdateExhaust();

    // ?UpdateFF@mmCarSim@@QAEXXZ
    ARTS_IMPORT void UpdateFF();

    // ?UpdateICSParams@mmCarSim@@QAEXXZ
    ARTS_IMPORT void UpdateICSParams();

    // ?DeclareFields@mmCarSim@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?SetGlobalTuning@mmCarSim@@SAXMM@Z
    ARTS_EXPORT static void SetGlobalTuning(f32 arg1, f32 arg2);

    // ?DirtTex@mmCarSim@@2PAVagiTexDef@@A
    ARTS_IMPORT static agiTexDef* DirtTex;

    // ?GrassTex@mmCarSim@@2PAVagiTexDef@@A
    ARTS_IMPORT static agiTexDef* GrassTex;

    // ?PlayerRawSteering@mmCarSim@@2MA
    ARTS_IMPORT static f32 PlayerRawSteering;

    // ?SnowTex@mmCarSim@@2PAVagiTexDef@@A
    ARTS_IMPORT static agiTexDef* SnowTex;

    asOverSample OverSample;
    asInertialCS ICS;
    asLinearCS LCS;
    asLinearCS field_280;
    Vector3 BodyCG;
    Vector3 ResetPosition;
    Vector3 Dimensions;
    f32 ResetRotation;
    asBound Bound;
    asBound field_36C;
    asBound field_3A8;
    mmStuck Stuck;
    mmSplash Splash;
    asAero AeroCollide;
    mmForce Force;
    VehGyro Gyro;
    f32 field_840;
    f32 field_844;
    f32 field_848;
    f32 field_84C;
    f32 field_850;
    f32 field_854;
    f32 field_858;
    f32 field_85C;
    f32 RedistHeight;
    f32 RedistLongRatio;
    i32 DrivetrainType;
    i32 RealDrivetrainType;
    mmDrivetrain DriveTrain1;
    mmDrivetrain DriveTrain2;
    mmDrivetrain DriveTrain3;
    mmWheel FrontLeft;
    mmWheel FrontRight;
    mmWheel BackLeft;
    mmWheel BackRight;
    mmAxle FrontAxle;
    mmAxle BackAxle;
    mmShock Shock0;
    mmShock Shock1;
    mmShock Shock2;
    mmShock Shock3;
    mmEngine Engine;
    mmTransmission Trans;
    Vector3 WHL2_Pos;
    Vector3 WHL3_Pos;
    i32 field_17E8;
    i32 HasCollided;
    f32* Realism;
    Vector3 InertiaBox;
    i32 field_1800;
    f32 Brakes;
    f32 HandBrake;
    f32 Steering;
    i32 NumWheels;
    f32 Drag;
    f32 Downforce;
    f32 BoundFriction;
    f32 BoundElasticity;
    f32 DriftTorque;
    i32 field_1828;
    f32 Mass;
    f32 Speed; // Meters per second
    f32 SpeedMPH;
    f32 TBWidth;
    f32 TBHeight;
    i32 field_1840;
    f32 TB_Freq;
    f32 Gain;
    f32 field_184C;
    f32 field_1850;
    f32 field_1854;
    i32 DriverType;
    i16 CurrentLOD;
    i16 EnableDamage;
    f32 field_1860;
    i32 field_1864;
    i32 field_1868;
    i32 field_186C;
    i32 field_1870;
    i32 field_1874;
    mmCarModel* Model;
    mmCar* Car;
    f32 CurrentDamage;
    f32 SmokePtx;
    f32 SmokeParticleFraction;
    f32 MaxDamage;
    f32 MedDamage;
    f32 MaxDamageScaled;
    f32 MedDamageScaled;
    Vector3 DamageSmokeOffset;
    Vector3 field_18A8;
    f32 Damage;
    f32 CarFrictionHandling;
    f32 LongSlideMultiplier;
    f32 ExhaustParticleMultiplier;
    f32 ExhaustParticles;
    i32 EnableExhaust;
    Vector3 ExhaustSmokeOffset;
    f32 SlipPercentThresh;
    Callback OnPlayerImpact;
    asParticles GrassPtx;
    asParticles ExhaustPtx;
    asBirthRule AsphaltRule;
    asBirthRule OffroadRule;
    asBirthRule ExhaustRule;
    asBirthRule SnowRule;
    asBirthRule WaterRule;
    asBirthRule SmokeRule;
    asParticles ExplosionPtx;
    asBirthRule ExplosionRule;
    i32 Exploded;
    i32 field_1F08;
    i32 HornPlaying;
    i32 EnableFF;
    mmPlayerCarAudio* PlayerCarAudio;
    mmOpponentCarAudio* OpponentCarAudio;
    mmPoliceCarAudio* PoliceCarAudio;
    mmNetworkCarAudio* NetworkCarAudio;
    mmCarRoadFF* CarRoadFF;
    f32 field_1F28;
    f32 field_1F2C;
    f32 field_1F30;
    i32 SpinState;
    f32 SpinStartTimer;
    f32 SpinSight;
    f32 SpinEndTimer;
    f32 SpinStartTime;
    f32 SpinEndTime;
    f32 SpinStart;
    f32 SpinStop;
    f32 SpinFromMax;
    f32 SpinFromMin;
    f32 SpinToMin;
    f32 SpinToMax;
    f32 DriftThreshold;
    f32 SpinThreshold;
    f32 FrontDriftFricMultiplier;
    f32 BackDriftFricMultiplier;
    f32 FrontSpinFricMultiplier;
    f32 BackSpinFricMultiplier;
    f32 BrakeFrontFricMultiplier;
    f32 BrakeBackFricMultiplier;
    f32 SteerMultiplier;
    f32 FrontFriction;
    f32 BackFriction;
    f32 field_1F90;
    Vector3 DashCamHeadlightOffset;
    Vector3 POVCamHeadlightOffset;
};

check_size(mmCarSim, 0x1FAC);
