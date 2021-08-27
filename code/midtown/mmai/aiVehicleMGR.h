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
    mmai:aiVehicleMGR

    0x451450 | void __cdecl AMBIENTCB(class aiVehicleActive *,class asBound *,class mmIntersection *,class Vector3 *,float) | ?AMBIENTCB@@YAXPAVaiVehicleActive@@PAVasBound@@PAVmmIntersection@@PAVVector3@@M@Z
    0x4515E0 | public: virtual void __fastcall aiVehicleInstance::Draw(int) | ?Draw@aiVehicleInstance@@UAIXH@Z
    0x451E20 | public: virtual void __fastcall aiVehicleInstance::DrawGlow(void) | ?DrawGlow@aiVehicleInstance@@UAIXXZ
    0x451E70 | public: virtual void __fastcall aiVehicleInstance::DrawShadow(void) | ?DrawShadow@aiVehicleInstance@@UAIXXZ
    0x451F10 | public: virtual class mmPhysEntity * __thiscall aiVehicleInstance::GetEntity(void) | ?GetEntity@aiVehicleInstance@@UAEPAVmmPhysEntity@@XZ
    0x451F40 | public: virtual void __thiscall aiVehicleInstance::Detach(void) | ?Detach@aiVehicleInstance@@UAEXXZ
    0x451F70 | public: virtual class mmPhysEntity * __thiscall aiVehicleInstance::AttachEntity(void) | ?AttachEntity@aiVehicleInstance@@UAEPAVmmPhysEntity@@XZ
    0x451FD0 | public: virtual class Vector3 __thiscall aiVehicleInstance::GetVelocity(void) | ?GetVelocity@aiVehicleInstance@@UAE?AVVector3@@XZ
    0x452080 | public: virtual void __fastcall aiVehicleInstance::FromMatrix(class Matrix34 const &) | ?FromMatrix@aiVehicleInstance@@UAIXABVMatrix34@@@Z
    0x452090 | public: virtual class Matrix34 & __fastcall aiVehicleInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@aiVehicleInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x4520A0 | public: virtual class Vector3 & __fastcall aiVehicleInstance::GetPos(void) | ?GetPos@aiVehicleInstance@@UAIAAVVector3@@XZ
    0x4520B0 | public: __thiscall aiVehicleActive::aiVehicleActive(void) | ??0aiVehicleActive@@QAE@XZ
    0x4521A0 | public: void __thiscall aiVehicleActive::Init(char *) | ?Init@aiVehicleActive@@QAEXPAD@Z
    0x452450 | public: virtual __thiscall aiVehicleActive::~aiVehicleActive(void) | ??1aiVehicleActive@@UAE@XZ
    0x452540 | public: void __thiscall aiVehicleActive::Attach(class aiVehicleInstance *) | ?Attach@aiVehicleActive@@QAEXPAVaiVehicleInstance@@@Z
    0x4526F0 | public: virtual void __thiscall aiVehicleActive::DetachMe(void) | ?DetachMe@aiVehicleActive@@UAEXXZ
    0x452710 | public: void __thiscall aiVehicleActive::Detach(void) | ?Detach@aiVehicleActive@@QAEXXZ
    0x4528E0 | public: virtual void __thiscall aiVehicleActive::Update(void) | ?Update@aiVehicleActive@@UAEXXZ
    0x452950 | public: virtual void __thiscall aiVehicleActive::PostUpdate(void) | ?PostUpdate@aiVehicleActive@@UAEXXZ
    0x4529D0 | public: void __thiscall aiVehicleActive::UpdateDamage(void) | ?UpdateDamage@aiVehicleActive@@QAEXXZ
    0x452A30 | public: __thiscall aiVehicleManager::aiVehicleManager(void) | ??0aiVehicleManager@@QAE@XZ
    0x452B10 | public: virtual __thiscall aiVehicleManager::~aiVehicleManager(void) | ??1aiVehicleManager@@UAE@XZ
    0x452BB0 | public: void __thiscall aiVehicleManager::Init(char *) | ?Init@aiVehicleManager@@QAEXPAD@Z
    0x452BE0 | public: virtual void __thiscall aiVehicleManager::Reset(void) | ?Reset@aiVehicleManager@@UAEXXZ
    0x452C20 | public: class aiVehicleActive * __thiscall aiVehicleManager::Attach(class aiVehicleInstance *) | ?Attach@aiVehicleManager@@QAEPAVaiVehicleActive@@PAVaiVehicleInstance@@@Z
    0x452CE0 | public: void __thiscall aiVehicleManager::Detach(class aiVehicleActive *) | ?Detach@aiVehicleManager@@QAEXPAVaiVehicleActive@@@Z
    0x452D70 | public: virtual void __thiscall aiVehicleManager::Update(void) | ?Update@aiVehicleManager@@UAEXXZ
    0x452E60 | public: int __thiscall aiVehicleData::LoadEntry(char *) | ?LoadEntry@aiVehicleData@@QAEHPAD@Z
    0x453020 | public: class aiVehicleData * __thiscall aiVehicleInstance::GetData(void) | ?GetData@aiVehicleInstance@@QAEPAVaiVehicleData@@XZ
    0x453040 | public: int __thiscall aiVehicleManager::AddVehicleDataEntry(char *) | ?AddVehicleDataEntry@aiVehicleManager@@QAEHPAD@Z
    0x453350 | public: virtual void __thiscall aiVehicleManager::Save(void) | ?Save@aiVehicleManager@@UAEXXZ
    0x453380 | public: virtual void __thiscall aiVehicleManager::AddWidgets(class Bank *) | ?AddWidgets@aiVehicleManager@@UAEXPAVBank@@@Z
    0x453390 | public: virtual void __thiscall aiVehicleData::AddWidgets(class Bank *) | ?AddWidgets@aiVehicleData@@UAEXPAVBank@@@Z
    0x453610 | public: static void __cdecl aiVehicleInstance::DeclareFields(void) | ?DeclareFields@aiVehicleInstance@@SAXXZ
    0x4536B0 | public: virtual class MetaClass * __thiscall aiVehicleInstance::GetClass(void) | ?GetClass@aiVehicleInstance@@UAEPAVMetaClass@@XZ
    0x4536C0 | public: static void __cdecl aiVehicleData::DeclareFields(void) | ?DeclareFields@aiVehicleData@@SAXXZ
    0x4539F0 | public: virtual class MetaClass * __thiscall aiVehicleData::GetClass(void) | ?GetClass@aiVehicleData@@UAEPAVMetaClass@@XZ
    0x453A00 | public: virtual void * __thiscall aiVehicleActive::`vector deleting destructor'(unsigned int) | ??_EaiVehicleActive@@UAEPAXI@Z
    0x453A00 | public: virtual void * __thiscall aiVehicleActive::`scalar deleting destructor'(unsigned int) | ??_GaiVehicleActive@@UAEPAXI@Z
    0x453A30 | public: virtual __thiscall asInertialCS::~asInertialCS(void) | ??1asInertialCS@@UAE@XZ
    0x453A40 | public: virtual __thiscall asBound::~asBound(void) | ??1asBound@@UAE@XZ
    0x453A50 | public: virtual __thiscall mmWheelCheap::~mmWheelCheap(void) | ??1mmWheelCheap@@UAE@XZ
    0x453A60 | public: virtual void * __thiscall aiVehicleManager::`scalar deleting destructor'(unsigned int) | ??_GaiVehicleManager@@UAEPAXI@Z
    0x453A60 | public: virtual void * __thiscall aiVehicleManager::`vector deleting destructor'(unsigned int) | ??_EaiVehicleManager@@UAEPAXI@Z
    0x453A90 | public: virtual void * __thiscall aiVehicleData::`vector deleting destructor'(unsigned int) | ??_EaiVehicleData@@UAEPAXI@Z
    0x453AF0 | public: virtual void __thiscall mmPhysEntity::Update(void) | ?Update@mmPhysEntity@@UAEXXZ
    0x453B00 | public: virtual void __thiscall mmPhysEntity::PostUpdate(void) | ?PostUpdate@mmPhysEntity@@UAEXXZ
    0x453B10 | public: virtual class asBound * __thiscall mmPhysEntity::GetBound(void) | ?GetBound@mmPhysEntity@@UAEPAVasBound@@XZ
    0x453B20 | public: virtual class asInertialCS * __thiscall mmPhysEntity::GetICS(void) | ?GetICS@mmPhysEntity@@UAEPAVasInertialCS@@XZ
    0x453B30 | public: virtual void __thiscall mmPhysEntity::DetachMe(void) | ?DetachMe@mmPhysEntity@@UAEXXZ
    0x453B40 | public: virtual void * __thiscall mmPhysEntity::`vector deleting destructor'(unsigned int) | ??_EmmPhysEntity@@UAEPAXI@Z
    0x453B40 | public: virtual void * __thiscall mmPhysEntity::`scalar deleting destructor'(unsigned int) | ??_GmmPhysEntity@@UAEPAXI@Z
    0x453B70 | public: __thiscall aiVehicleData::aiVehicleData(void) | ??0aiVehicleData@@QAE@XZ
    0x453B90 | public: virtual __thiscall aiVehicleData::~aiVehicleData(void) | ??1aiVehicleData@@UAE@XZ
    0x453BA0 | public: virtual class asBound * __thiscall aiVehicleActive::GetBound(void) | ?GetBound@aiVehicleActive@@UAEPAVasBound@@XZ
    0x453BB0 | public: virtual class asInertialCS * __thiscall aiVehicleActive::GetICS(void) | ?GetICS@aiVehicleActive@@UAEPAVasInertialCS@@XZ
    0x453BC0 | public: virtual __thiscall asBirthRule::~asBirthRule(void) | ??1asBirthRule@@UAE@XZ
    0x61B850 | const aiVehicleActive::`vftable' | ??_7aiVehicleActive@@6B@
    0x61B8A0 | const mmPhysEntity::`vftable' | ??_7mmPhysEntity@@6B@
    0x61B8F0 | const aiVehicleManager::`vftable' | ??_7aiVehicleManager@@6B@
    0x61B930 | const aiVehicleData::`vftable' | ??_7aiVehicleData@@6B@
    0x6A7AD8 | public: static class aiVehicleManager * aiVehicleManager::Instance | ?Instance@aiVehicleManager@@2PAV1@A
    0x6A7AE0 | class HashTable VehicleDataHash | ?VehicleDataHash@@3VHashTable@@A
    0x6A7AF0 | class MetaClass aiVehicleDataMetaClass | ?aiVehicleDataMetaClass@@3VMetaClass@@A
    0x6A7B18 | class MetaClass aiVehicleInstanceMetaClass | ?aiVehicleInstanceMetaClass@@3VMetaClass@@A
    0x6A7B40 | class HashTable NoDataWhined | ?NoDataWhined@@3VHashTable@@A
    0x6A7B50 | public: static float aiVehicleManager::FloatClock | ?FloatClock@aiVehicleManager@@2MA
    0x6A7B54 | public: static int aiVehicleManager::SignalClock | ?SignalClock@aiVehicleManager@@2HA
*/

#include "arts7/node.h"

#include "mmcar/carsimcheap.h"
#include "mmcity/inst.h"
#include "mmeffects/birth.h"
#include "mmeffects/ptx.h"
#include "mmphysics/bound.h"
#include "mmphysics/entity.h"
#include "mmphysics/inertia.h"
#include "mmphysics/osample.h"

class aiVehicleActive;
class aiVehicleData;
class mmIntersection;
class aiVehicleSpline;

// ?AMBIENTCB@@YAXPAVaiVehicleActive@@PAVasBound@@PAVmmIntersection@@PAVVector3@@M@Z
ARTS_IMPORT void AMBIENTCB(aiVehicleActive* arg1, asBound* arg2, mmIntersection* arg3, Vector3* arg4, f32 arg5);

// ?NoDataWhined@@3VHashTable@@A
ARTS_IMPORT extern HashTable NoDataWhined;

// ?VehicleDataHash@@3VHashTable@@A
ARTS_IMPORT extern HashTable VehicleDataHash;

class aiVehicleInstance final : public mmInstance
{
public:
    // ??_GaiVehicleInstance@@UAEPAXI@Z
    // ??_EaiVehicleInstance@@UAEPAXI@Z
    // ??1aiVehicleInstance@@UAE@XZ | inline
    ARTS_IMPORT ~aiVehicleInstance() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiVehicleInstance@@UAEXPAVBank@@@Z | inline
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AttachEntity@aiVehicleInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_IMPORT mmPhysEntity* AttachEntity() override;

    // ?Detach@aiVehicleInstance@@UAEXXZ
    ARTS_EXPORT void Detach() override;

    // ?Draw@aiVehicleInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?DrawGlow@aiVehicleInstance@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawGlow() override;

    // ?DrawShadow@aiVehicleInstance@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawShadow() override;

    // ?FromMatrix@aiVehicleInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetClass@aiVehicleInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetData@aiVehicleInstance@@QAEPAVaiVehicleData@@XZ
    ARTS_IMPORT aiVehicleData* GetData();

    // ?GetEntity@aiVehicleInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_IMPORT mmPhysEntity* GetEntity() override;

    // ?GetPos@aiVehicleInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?GetVelocity@aiVehicleInstance@@UAE?AVVector3@@XZ
    ARTS_IMPORT Vector3 GetVelocity() override;

    // ?ToMatrix@aiVehicleInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    // ?DeclareFields@aiVehicleInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    aiVehicleSpline* Spline;
    u32** Variants;
    i16 Random;
    i16 Indicators;
    i16 field_20;
    i16 field_22;
};

check_size(aiVehicleInstance, 0x24);

class aiVehicleActive final : public mmPhysEntity
{
public:
    // ??0aiVehicleActive@@QAE@XZ
    ARTS_IMPORT aiVehicleActive();

    // ??_GaiVehicleActive@@UAEPAXI@Z
    // ??_EaiVehicleActive@@UAEPAXI@Z
    // ??1aiVehicleActive@@UAE@XZ
    ARTS_IMPORT ~aiVehicleActive() override;

    // ?Attach@aiVehicleActive@@QAEXPAVaiVehicleInstance@@@Z
    ARTS_EXPORT void Attach(aiVehicleInstance* inst);

    // ?Detach@aiVehicleActive@@QAEXXZ
    ARTS_EXPORT void Detach();

    // ?DetachMe@aiVehicleActive@@UAEXXZ
    ARTS_EXPORT void DetachMe() override;

    // ?GetBound@aiVehicleActive@@UAEPAVasBound@@XZ | inline
    ARTS_IMPORT asBound* GetBound() override;

    // ?GetICS@aiVehicleActive@@UAEPAVasInertialCS@@XZ | inline
    ARTS_IMPORT asInertialCS* GetICS() override;

    // ?Init@aiVehicleActive@@QAEXPAD@Z
    ARTS_IMPORT void Init(char* arg1);

    // ?PostUpdate@aiVehicleActive@@UAEXXZ
    ARTS_IMPORT void PostUpdate() override;

    // ?Update@aiVehicleActive@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDamage@aiVehicleActive@@QAEXXZ
    ARTS_IMPORT void UpdateDamage();

    asParticles Ptx;
    asParticles ExplosionPtx;
    asBirthRule PtxRule;
    asBirthRule ExplosionRule;
    f32 Damage;
    f32 MaxDamage;
    i32 VehicleIndex;
    aiVehicleInstance* Inst;
    asInertialCS ICS;
    asBound Bound;
    asOverSample OverSample;
    mmWheelCheap WheelFL;
    mmWheelCheap WheelFR;
    mmWheelCheap WheelBL;
    mmWheelCheap WheelBR;
};

check_size(aiVehicleActive, 0xA6C);

class aiVehicleManager final : public asNode
{
public:
    // ??0aiVehicleManager@@QAE@XZ
    ARTS_IMPORT aiVehicleManager();

    // ??_EaiVehicleManager@@UAEPAXI@Z
    // ??_GaiVehicleManager@@UAEPAXI@Z
    // ??1aiVehicleManager@@UAE@XZ
    ARTS_IMPORT ~aiVehicleManager() override;

    // ?AddVehicleDataEntry@aiVehicleManager@@QAEHPAD@Z
    ARTS_IMPORT i32 AddVehicleDataEntry(char* arg1);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiVehicleManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Attach@aiVehicleManager@@QAEPAVaiVehicleActive@@PAVaiVehicleInstance@@@Z
    ARTS_IMPORT aiVehicleActive* Attach(aiVehicleInstance* arg1);

    // ?Detach@aiVehicleManager@@QAEXPAVaiVehicleActive@@@Z
    ARTS_IMPORT void Detach(aiVehicleActive* arg1);

    // ?Init@aiVehicleManager@@QAEXPAD@Z
    ARTS_IMPORT void Init(char* arg1);

    // ?Reset@aiVehicleManager@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Save@aiVehicleManager@@UAEXXZ
    ARTS_IMPORT void Save() override;

    // ?Update@aiVehicleManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?FloatClock@aiVehicleManager@@2MA
    ARTS_IMPORT static f32 FloatClock;

    // ?Instance@aiVehicleManager@@2PAV1@A
    ARTS_IMPORT static aiVehicleManager* Instance;

    // ?SignalClock@aiVehicleManager@@2HA
    ARTS_IMPORT static i32 SignalClock;

    u8 gap20[0x16608];
};

inline aiVehicleManager* AiVehicleManager()
{
    return aiVehicleManager::Instance;
}

check_size(aiVehicleManager, 0x16628);

class aiVehicleData final : public asNode
{
public:
    // ??0aiVehicleData@@QAE@XZ | inline
    ARTS_IMPORT aiVehicleData();

    // ??_EaiVehicleData@@UAEPAXI@Z
    // ??1aiVehicleData@@UAE@XZ | inline
    ARTS_IMPORT ~aiVehicleData() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiVehicleData@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@aiVehicleData@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?LoadEntry@aiVehicleData@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadEntry(char* arg1);

    // ?DeclareFields@aiVehicleData@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Vector3 Size;
    Vector3 MaxAngClamp;
    Vector3 BodyOff;
    Vector3 FLOff;
    Vector3 FROff;
    Vector3 BLOff;
    Vector3 BROff;
    Vector3 BBLOff;
    Vector3 BBROff;
    f32 Mass;
    f32 Friction;
    f32 Elasticity;
    f32 MaxDamage;
    f32 PtxThresh;
    f32 Spring;
    f32 Damping;
    f32 RubberSpring;
    f32 RubberDamp;
    f32 SuspensionLimit;
    f32 TireRadius;
    i32 SoundId;
    i32 ManagerIdx;
};

check_size(aiVehicleData, 0xC0);

extern f32 EggMass;
