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
    mmcar:carsim

    0x46B8F0 | void __cdecl IMPACTCB(class mmCarSim *,class asBound *,class mmIntersection *,class Vector3 *,float,class Vector3 *) | ?IMPACTCB@@YAXPAVmmCarSim@@PAVasBound@@PAVmmIntersection@@PAVVector3@@M3@Z
    0x46B950 | public: __thiscall mmCarSim::mmCarSim(void) | ??0mmCarSim@@QAE@XZ
    0x46BFF0 | public: int __thiscall mmCarSim::OnGround(void) | ?OnGround@mmCarSim@@QAEHXZ
    0x46C030 | public: static void __cdecl mmCarSim::SetGlobalTuning(float,float) | ?SetGlobalTuning@mmCarSim@@SAXMM@Z
    0x46C040 | public: virtual __thiscall mmCarSim::~mmCarSim(void) | ??1mmCarSim@@UAE@XZ
    0x46C340 | public: void __thiscall mmCarSim::AddPlayerSpecifics(void) | ?AddPlayerSpecifics@mmCarSim@@QAEXXZ
    0x46C3C0 | public: void __thiscall mmCarSim::PlayHorn(void) | ?PlayHorn@mmCarSim@@QAEXXZ
    0x46C430 | public: void __thiscall mmCarSim::StopHorn(void) | ?StopHorn@mmCarSim@@QAEXXZ
    0x46C4A0 | public: void __thiscall mmCarSim::StartSiren(void) | ?StartSiren@mmCarSim@@QAEXXZ
    0x46C4D0 | public: void __thiscall mmCarSim::StopSiren(void) | ?StopSiren@mmCarSim@@QAEXXZ
    0x46C500 | public: void __thiscall mmCarSim::Init(char *,class mmCar *,int) | ?Init@mmCarSim@@QAEXPADPAVmmCar@@H@Z
    0x46CB20 | public: void __thiscall mmCarSim::ReInit(char *) | ?ReInit@mmCarSim@@QAEXPAD@Z
    0x46D020 | public: void __thiscall mmCarSim::RestoreImpactParams(void) | ?RestoreImpactParams@mmCarSim@@QAEXXZ
    0x46D040 | public: void __thiscall mmCarSim::SetHackedImpactParams(void) | ?SetHackedImpactParams@mmCarSim@@QAEXXZ
    0x46D060 | public: void __thiscall mmCarSim::ReconfigureDrivetrain(void) | ?ReconfigureDrivetrain@mmCarSim@@QAEXXZ
    0x46D080 | public: void __thiscall mmCarSim::ConfigureDrivetrain(void) | ?ConfigureDrivetrain@mmCarSim@@QAEXXZ
    0x46D300 | public: void __thiscall mmCarSim::UnconfigureDrivetrain(void) | ?UnconfigureDrivetrain@mmCarSim@@QAEXXZ
    0x46D500 | public: void __thiscall mmCarSim::SetResetPos(class Vector3 &) | ?SetResetPos@mmCarSim@@QAEXAAVVector3@@@Z
    0x46D540 | public: virtual void __thiscall mmCarSim::AfterLoad(void) | ?AfterLoad@mmCarSim@@UAEXXZ
    0x46D600 | public: virtual void __thiscall mmCarSim::BeforeSave(void) | ?BeforeSave@mmCarSim@@UAEXXZ
    0x46D680 | public: void __thiscall mmCarSim::UpdateICSParams(void) | ?UpdateICSParams@mmCarSim@@QAEXXZ
    0x46D6B0 | public: virtual void __thiscall mmCarSim::Reset(void) | ?Reset@mmCarSim@@UAEXXZ
    0x46D860 | public: virtual void __thiscall mmCarSim::Update(void) | ?Update@mmCarSim@@UAEXXZ
    0x46E080 | public: void __thiscall mmCarSim::Explode(void) | ?Explode@mmCarSim@@QAEXXZ
    0x46E160 | public: void __thiscall mmCarSim::UpdateExhaust(void) | ?UpdateExhaust@mmCarSim@@QAEXXZ
    0x46E270 | public: void __thiscall mmCarSim::UpdateDamage(void) | ?UpdateDamage@mmCarSim@@QAEXXZ
    0x46E520 | public: void __thiscall mmCarSim::UpdateFF(void) | ?UpdateFF@mmCarSim@@QAEXXZ
    0x46E7E0 | public: int __thiscall mmCarSim::ShouldSkid(void) | ?ShouldSkid@mmCarSim@@QAEHXZ
    0x46E830 | public: void __thiscall mmCarSim::RemoveNetVehicleAudio(void) | ?RemoveNetVehicleAudio@mmCarSim@@QAEXXZ
    0x46E840 | public: virtual void __thiscall mmCarSim::AddWidgets(class Bank *) | ?AddWidgets@mmCarSim@@UAEXPAVBank@@@Z
    0x46F5B0 | public: void __thiscall mmCarSim::InitPtx(void) | ?InitPtx@mmCarSim@@QAEXXZ
    0x46FAA0 | public: void __thiscall mmCarSim::PlayImpactAudio(short,class mmIntersection *,class Vector3 *) | ?PlayImpactAudio@mmCarSim@@QAEXFPAVmmIntersection@@PAVVector3@@@Z
    0x46FBC0 | public: static void __cdecl mmCarSim::DeclareFields(void) | ?DeclareFields@mmCarSim@@SAXXZ
    0x4701A0 | public: virtual class MetaClass * __thiscall mmCarSim::GetClass(void) | ?GetClass@mmCarSim@@UAEPAVMetaClass@@XZ
    0x470300 | public: virtual __thiscall mmStuck::~mmStuck(void) | ??1mmStuck@@UAE@XZ
    0x470310 | public: virtual __thiscall mmSplash::~mmSplash(void) | ??1mmSplash@@UAE@XZ
    0x470320 | public: virtual __thiscall asAero::~asAero(void) | ??1asAero@@UAE@XZ
    0x470330 | public: virtual __thiscall mmForce::~mmForce(void) | ??1mmForce@@UAE@XZ
    0x470340 | public: virtual __thiscall VehGyro::~VehGyro(void) | ??1VehGyro@@UAE@XZ
    0x470350 | public: virtual __thiscall mmDrivetrain::~mmDrivetrain(void) | ??1mmDrivetrain@@UAE@XZ
    0x470360 | public: virtual __thiscall mmWheel::~mmWheel(void) | ??1mmWheel@@UAE@XZ
    0x470370 | public: virtual __thiscall mmAxle::~mmAxle(void) | ??1mmAxle@@UAE@XZ
    0x470380 | public: virtual __thiscall mmShock::~mmShock(void) | ??1mmShock@@UAE@XZ
    0x470390 | public: virtual __thiscall mmTransmission::~mmTransmission(void) | ??1mmTransmission@@UAE@XZ
    0x4703A0 | struct MetaType * __cdecl Struct(class MetaClass *) | ?Struct@@YAPAUMetaType@@PAVMetaClass@@@Z
    0x4703D0 | public: virtual void * __thiscall mmCarSim::`vector deleting destructor'(unsigned int) | ??_EmmCarSim@@UAEPAXI@Z
    0x61BEA8 | const mmCarSim::`vftable' | ??_7mmCarSim@@6B@
    0x61BEE8 | const StructType::`vftable' | ??_7StructType@@6B@
    0x63ABC0 | float MetricFactor | ?MetricFactor@@3MA
    0x63ABC4 | float WeatherFriction | ?WeatherFriction@@3MA
    0x6A7C40 | class Vector3 PlayerPos | ?PlayerPos@@3VVector3@@A
    0x6A7C50 | class MetaClass mmCarSimMetaClass | ?mmCarSimMetaClass@@3VMetaClass@@A
    0x6A7C78 | float HitWaterTimer | ?HitWaterTimer@@3MA
    0x6A7C90 | public: static class agiTexDef * mmCarSim::GrassTex | ?GrassTex@mmCarSim@@2PAVagiTexDef@@A
    0x6A7C94 | public: static class agiTexDef * mmCarSim::DirtTex | ?DirtTex@mmCarSim@@2PAVagiTexDef@@A
    0x6A7C98 | public: static class agiTexDef * mmCarSim::SnowTex | ?SnowTex@mmCarSim@@2PAVagiTexDef@@A
    0x6A7C9C | public: static float mmCarSim::PlayerRawSteering | ?PlayerRawSteering@mmCarSim@@2MA
*/

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

class mmPlayerCarAudio;
class mmOpponentCarAudio;
class mmPoliceCarAudio;
class mmNetworkCarAudio;
class mmCarModel;
class mmCarRoadFF;

// ?IMPACTCB@@YAXPAVmmCarSim@@PAVasBound@@PAVmmIntersection@@PAVVector3@@M3@Z
ARTS_IMPORT void IMPACTCB(class mmCarSim* arg1, class asBound* arg2, class mmIntersection* arg3, class Vector3* arg4,
    f32 arg5, class Vector3* arg6);

// ?HitWaterTimer@@3MA
ARTS_IMPORT extern f32 HitWaterTimer;

// ?MetricFactor@@3MA
ARTS_IMPORT extern f32 MetricFactor;

// ?PlayerPos@@3VVector3@@A
ARTS_IMPORT extern class Vector3 PlayerPos;

// ?WeatherFriction@@3MA
ARTS_IMPORT extern f32 WeatherFriction;

// ?mmCarSimMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmCarSimMetaClass;

class mmCarSim final : public asNode
{
    // const mmCarSim::`vftable'

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
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
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
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Init@mmCarSim@@QAEXPADPAVmmCar@@H@Z
    ARTS_IMPORT void Init(char* arg1, class mmCar* arg2, i32 arg3);

    // ?InitPtx@mmCarSim@@QAEXXZ
    ARTS_IMPORT void InitPtx();

    // ?OnGround@mmCarSim@@QAEHXZ
    ARTS_IMPORT i32 OnGround();

    // ?PlayHorn@mmCarSim@@QAEXXZ
    ARTS_IMPORT void PlayHorn();

    // ?PlayImpactAudio@mmCarSim@@QAEXFPAVmmIntersection@@PAVVector3@@@Z
    ARTS_IMPORT void PlayImpactAudio(i16 arg1, class mmIntersection* arg2, class Vector3* arg3);

    // ?ReInit@mmCarSim@@QAEXPAD@Z
    ARTS_IMPORT void ReInit(char* arg1);

    // ?ReconfigureDrivetrain@mmCarSim@@QAEXXZ
    ARTS_IMPORT void ReconfigureDrivetrain();

    // ?RemoveNetVehicleAudio@mmCarSim@@QAEXXZ
    ARTS_IMPORT void RemoveNetVehicleAudio();

    // ?Reset@mmCarSim@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?RestoreImpactParams@mmCarSim@@QAEXXZ
    ARTS_IMPORT void RestoreImpactParams();

    // ?SetHackedImpactParams@mmCarSim@@QAEXXZ
    ARTS_IMPORT void SetHackedImpactParams();

    // ?SetResetPos@mmCarSim@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void SetResetPos(class Vector3& arg1);

    // ?ShouldSkid@mmCarSim@@QAEHXZ
    ARTS_IMPORT i32 ShouldSkid();

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
    ARTS_IMPORT static class agiTexDef* DirtTex;

    // ?GrassTex@mmCarSim@@2PAVagiTexDef@@A
    ARTS_IMPORT static class agiTexDef* GrassTex;

    // ?PlayerRawSteering@mmCarSim@@2MA
    ARTS_IMPORT static f32 PlayerRawSteering;

    // ?SnowTex@mmCarSim@@2PAVagiTexDef@@A
    ARTS_IMPORT static class agiTexDef* SnowTex;

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
    f32 Speed;
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
    Callback OnExplosion;
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
