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
    ARTS_EXPORT ~aiVehicleInstance() override = default;

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

inline aiVehicleManager* AiVehicleMgr()
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
    ARTS_EXPORT ~aiVehicleData() override = default;

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
