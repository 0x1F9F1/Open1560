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

// 0x46B8F0 | ?IMPACTCB@@YAXPAVmmCarSim@@PAVasBound@@PAVmmIntersection@@PAVVector3@@M3@Z
void IMPACTCB(class mmCarSim* arg1, class asBound* arg2, class mmIntersection* arg3, class Vector3* arg4, f32 arg5,
    class Vector3* arg6);

// 0x6A7C78 | ?HitWaterTimer@@3MA
inline extern_var(0x6A7C78, f32, HitWaterTimer);

// 0x63ABC0 | ?MetricFactor@@3MA
inline extern_var(0x63ABC0, f32, MetricFactor);

// 0x6A7C40 | ?PlayerPos@@3VVector3@@A
inline extern_var(0x6A7C40, class Vector3, PlayerPos);

// 0x63ABC4 | ?WeatherFriction@@3MA
inline extern_var(0x63ABC4, f32, WeatherFriction);

// 0x6A7C50 | ?mmCarSimMetaClass@@3VMetaClass@@A
inline extern_var(0x6A7C50, class MetaClass, mmCarSimMetaClass);

class mmCarSim : public asNode
{
    // const mmCarSim::`vftable' @ 0x61BEA8

public:
    // 0x46B950 | ??0mmCarSim@@QAE@XZ
    mmCarSim();

    // 0x4703D0 | ??_EmmCarSim@@UAEPAXI@Z
    // 0x46C040 | ??1mmCarSim@@UAE@XZ
    ~mmCarSim() override;

    // 0x46C340 | ?AddPlayerSpecifics@mmCarSim@@QAEXXZ
    void AddPlayerSpecifics();

    // 0x46E840 | ?AddWidgets@mmCarSim@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x46D540 | ?AfterLoad@mmCarSim@@UAEXXZ
    void AfterLoad() override;

    // 0x46D600 | ?BeforeSave@mmCarSim@@UAEXXZ
    void BeforeSave() override;

    // 0x46D080 | ?ConfigureDrivetrain@mmCarSim@@QAEXXZ
    void ConfigureDrivetrain();

    // 0x46E080 | ?Explode@mmCarSim@@QAEXXZ
    void Explode();

    // 0x4701A0 | ?GetClass@mmCarSim@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x46C500 | ?Init@mmCarSim@@QAEXPADPAVmmCar@@H@Z
    void Init(char* arg1, class mmCar* arg2, i32 arg3);

    // 0x46F5B0 | ?InitPtx@mmCarSim@@QAEXXZ
    void InitPtx();

    // 0x46BFF0 | ?OnGround@mmCarSim@@QAEHXZ
    i32 OnGround();

    // 0x46C3C0 | ?PlayHorn@mmCarSim@@QAEXXZ
    void PlayHorn();

    // 0x46FAA0 | ?PlayImpactAudio@mmCarSim@@QAEXFPAVmmIntersection@@PAVVector3@@@Z
    void PlayImpactAudio(i16 arg1, class mmIntersection* arg2, class Vector3* arg3);

    // 0x46CB20 | ?ReInit@mmCarSim@@QAEXPAD@Z
    void ReInit(char* arg1);

    // 0x46D060 | ?ReconfigureDrivetrain@mmCarSim@@QAEXXZ
    void ReconfigureDrivetrain();

    // 0x46E830 | ?RemoveNetVehicleAudio@mmCarSim@@QAEXXZ
    void RemoveNetVehicleAudio();

    // 0x46D6B0 | ?Reset@mmCarSim@@UAEXXZ
    void Reset() override;

    // 0x46D020 | ?RestoreImpactParams@mmCarSim@@QAEXXZ
    void RestoreImpactParams();

    // 0x46D040 | ?SetHackedImpactParams@mmCarSim@@QAEXXZ
    void SetHackedImpactParams();

    // 0x46D500 | ?SetResetPos@mmCarSim@@QAEXAAVVector3@@@Z
    void SetResetPos(class Vector3& arg1);

    // 0x46E7E0 | ?ShouldSkid@mmCarSim@@QAEHXZ
    i32 ShouldSkid();

    // 0x46C4A0 | ?StartSiren@mmCarSim@@QAEXXZ
    void StartSiren();

    // 0x46C430 | ?StopHorn@mmCarSim@@QAEXXZ
    void StopHorn();

    // 0x46C4D0 | ?StopSiren@mmCarSim@@QAEXXZ
    void StopSiren();

    // 0x46D300 | ?UnconfigureDrivetrain@mmCarSim@@QAEXXZ
    void UnconfigureDrivetrain();

    // 0x46D860 | ?Update@mmCarSim@@UAEXXZ
    void Update() override;

    // 0x46E270 | ?UpdateDamage@mmCarSim@@QAEXXZ
    void UpdateDamage();

    // 0x46E160 | ?UpdateExhaust@mmCarSim@@QAEXXZ
    void UpdateExhaust();

    // 0x46E520 | ?UpdateFF@mmCarSim@@QAEXXZ
    void UpdateFF();

    // 0x46D680 | ?UpdateICSParams@mmCarSim@@QAEXXZ
    void UpdateICSParams();

    // 0x46FBC0 | ?DeclareFields@mmCarSim@@SAXXZ
    static void DeclareFields();

    // 0x46C030 | ?SetGlobalTuning@mmCarSim@@SAXMM@Z
    static void SetGlobalTuning(f32 arg1, f32 arg2);

    // 0x6A7C94 | ?DirtTex@mmCarSim@@2PAVagiTexDef@@A
    static inline extern_var(0x6A7C94, class agiTexDef*, DirtTex);

    // 0x6A7C90 | ?GrassTex@mmCarSim@@2PAVagiTexDef@@A
    static inline extern_var(0x6A7C90, class agiTexDef*, GrassTex);

    // 0x6A7C9C | ?PlayerRawSteering@mmCarSim@@2MA
    static inline extern_var(0x6A7C9C, f32, PlayerRawSteering);

    // 0x6A7C98 | ?SnowTex@mmCarSim@@2PAVagiTexDef@@A
    static inline extern_var(0x6A7C98, class agiTexDef*, SnowTex);
};

check_size(mmCarSim, 0x1FAC);
