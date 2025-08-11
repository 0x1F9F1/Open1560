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

#include "data7/base.h"
#include "vector7/matrix34.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"

#include "heap.h"

class agiMeshSet;
class mmBoundTemplate;
class mmPhysEntity;

// ?mmInstanceHeap@@3V?$mmHeap@H@@A
ARTS_IMPORT extern mmHeap<i32> mmInstanceHeap;

// Flags for .bng files
// INST_INIT_FLAG_FCD_* only apply to mmFacadeInstance (STATIC && !SHEAR && !BUILDING)
#define INST_INIT_FLAG_STATIC 0x1     // Is static, part of BuildingChain, otherwise it is a mmUnhitBangerInstance
#define INST_INIT_FLAG_SHEAR 0x2      // Inst is a mmShearInstance (requires BNG_FLAG_STATIC)
#define INST_INIT_FLAG_BUILDING 0x4   // Inst is a mmBuildingInstance (requires BNG_FLAG_STATIC && !BNG_FLAG_SHEAR)
#define INST_INIT_FLAG_FCD_LEFT 0x8   // Draw "LEFT" facade
#define INST_INIT_FLAG_FCD_RIGHT 0x10 // Draw "RIGHT" facade
#define INST_INIT_FLAG_FCD_TOP 0x20   // Draw "TOP" facade
#define INST_INIT_FLAG_GLOW 0x40      // Inst has a glow mesh (for mmUnhitBangerInstance)
#define INST_INIT_FLAG_UPPER 0x200 // Inst also has a mmUpperInstance, part of ObjectsChain, requires BNG_FLAG_BUILDING
#define INST_INIT_FLAG_FCD_BACK 0x400 // Draw "BACK" facade
#define INST_INIT_FLAG_TERRAIN 0x800  // NEW. Can collide with wheels

class mmInstance : public Base
{
public:
    // ??0mmInstance@@QAE@XZ
    ARTS_EXPORT mmInstance() = default;

    // ??1mmInstance@@UAE@XZ
    ARTS_EXPORT ~mmInstance() override = default;

    virtual void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) = 0;

    virtual Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) = 0;

    virtual Vector3& ARTS_FASTCALL GetPos() = 0;

    // ?GetEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_EXPORT virtual mmPhysEntity* GetEntity();

    // ?AttachEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_EXPORT virtual mmPhysEntity* AttachEntity();

    // ?GetVelocity@mmInstance@@UAE?AVVector3@@XZ | inline
    ARTS_EXPORT virtual Vector3 GetVelocity();

    // ?Impact@mmInstance@@UAEXPAV1@PAVVector3@@@Z | inline
    ARTS_EXPORT virtual void Impact(mmInstance* arg1, Vector3* arg2);

    // ?Detach@mmInstance@@UAEXXZ | inline
    ARTS_EXPORT virtual void Detach();

    // ?Draw@mmInstance@@UAIXH@Z
    ARTS_EXPORT virtual void ARTS_FASTCALL Draw(i32 lod);

    // ?DrawShadow@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL DrawShadow();

    // ?DrawGlow@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL DrawGlow();

    // ?Relight@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL Relight();

    // ?SizeOf@mmInstance@@UAEIXZ
    ARTS_EXPORT virtual usize SizeOf();

    // ?Reset@mmInstance@@UAEXXZ
    ARTS_EXPORT virtual void Reset();

#ifdef ARTS_DEV_BUILD
    virtual void AddWidgets(Bank* arg1) = 0;
#endif

    // ?Init@mmInstance@@UAEHPADAAVVector3@@1H0@Z
    ARTS_EXPORT virtual b32 Init(aconst char* name, Vector3& pos1, Vector3& pos2, i32 init_flags, aconst char* part);

    // ?GetScale@mmInstance@@UAIMXZ
    ARTS_EXPORT virtual f32 ARTS_FASTCALL GetScale();

    // ?ComputeLod@mmInstance@@UAEHMM@Z
    ARTS_EXPORT virtual i32 ComputeLod(f32 dist, f32 scale);

    // ?AddMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    ARTS_EXPORT void AddMeshes(aconst char* name, i32 mesh_flags, aconst char* part, Vector3* offset);

    // ?DrawDropShadow@mmInstance@@QAEXHHABVMatrix34@@@Z
    ARTS_IMPORT void DrawDropShadow(i32 arg1, i32 arg2, const Matrix34& arg3);

    // ?GetClass@mmInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetResidentMeshSet@mmInstance@@QAEPAVagiMeshSet@@HHH@Z
    ARTS_EXPORT agiMeshSet* GetResidentMeshSet(i32 lod, i32 index, i32 variant = 0);

    // ?InitMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    ARTS_EXPORT void InitMeshes(aconst char* name, i32 mesh_flags, aconst char* part, Vector3* offset);

    static void* operator new(std::size_t size);

    // ??3mmInstance@@SAXPAX@Z | inline
    static void operator delete(void* ptr);

    // ?DeclareFields@mmInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?GetMeshSetSet@mmInstance@@SAHPADH0PAVVector3@@@Z
    ARTS_IMPORT static i32 GetMeshSetSet(aconst char* name, i32 mesh_flags, aconst char* part, Vector3* offset);

    // ?ResetAll@mmInstance@@SAXXZ
    ARTS_IMPORT static void ResetAll();

    // ?DynamicLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    ARTS_IMPORT static void (*DynamicLighter)(u8*, u32*, u32*, agiMeshSet*);

    // ?LodTable@mmInstance@@2PAY132MA
    ARTS_EXPORT static f32 LodTable[3][4][3];

    // ?LodTableIndex@mmInstance@@2HA
    ARTS_IMPORT static i32 LodTableIndex;

    static constexpr i32 MaxMeshSetSets = 4096;

    // ?MeshSetNames@mmInstance@@2PAPADA
    ARTS_IMPORT static char* MeshSetNames[MaxMeshSetSets];

    // ?MeshSetSetCount@mmInstance@@2HA
    ARTS_IMPORT static i32 MeshSetSetCount;

#define INST_LOD_VLOW 0
#define INST_LOD_LOW 1
#define INST_LOD_MED 2
#define INST_LOD_HIGH 3

    struct MeshSetTableEntry
    {
        agiMeshSet* Meshes[4] {};
        mmBoundTemplate* Bound {};
    };

    // ?MeshSetTable@mmInstance@@2PAUMeshSetTableEntry@1@A
    ARTS_IMPORT static MeshSetTableEntry MeshSetTable[MaxMeshSetSets];

    // ?ShowLights@mmInstance@@2HA
    ARTS_IMPORT static i32 ShowLights;

    // ?StaticLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    ARTS_IMPORT static void (*StaticLighter)(u8*, u32*, u32*, agiMeshSet*);

    // TODO: When to use GetMeshSet vs GetResidentMeshSet?

    MeshSetTableEntry* GetMeshBase(i32 index)
    {
        return MeshIndex ? &MeshSetTable[MeshIndex - 1 + index] : nullptr;
    }

    agiMeshSet* GetMeshSet(i32 lod, i32 index)
    {
        return MeshIndex ? MeshSetTable[MeshIndex - 1 + index].Meshes[lod] : nullptr;
    }

    mmBoundTemplate* GetBound()
    {
        return MeshIndex ? MeshSetTable[MeshIndex - 1].Bound : nullptr;
    }

    /*
        mmInstance |= 0x20
            aiPedestrianInstance |= 0x2 | 0x2000
            aiVehicleInstance |= 0x2 | 0x4 | 0x100 | 0x400 | 0x2000
            mmCarModel |= 0x2 | 0x8 | 0x100 | 0x400 | 0x2000
            mmRunwayLight |= 0x2 | 0x2000
            mmSkid &= ~(0x4 | 0x8)
            mmTrailerInstance |= 0x2 | 0x8 | 0x100 | 0x2000

            mmBangerInstance |= 0x4 | 0x40
                mmFacadeBangerInstance - Unused
                mmGlassBangerInstance - Unused
                mmHitBangerInstance
                mmUnhitBangerInstance |= 0x200
                    aiTrafficLightInstance
                    mmDofBangerInstance |= 0x2 (if MeshIndex), 0x400
                        mmDrawbridgeInstance &= ~(0x2 | 0x20), |= 0x800
                    tp_trailer |= 0x800

            mmMatrixInstance |= 0x4
                mmAnimPlane
                mmAnimTrainCar
                mmBuildingInstance &= ~0x4
                mmShard &= ~(0x4 | 0x8)
                mmShearInstance &= ~0x4
                mmUpperInstance

            mmYInstance
                mmPed
                mmStaticInstance
                    mmFacadeInstance
                    mmWaypointInstance
    */
#define INST_FLAG_1 0x1
#define INST_FLAG_SHADOW 0x2

#define INST_FLAG_COLLIDER 0x4
#define INST_FLAG_MOVER 0x8
#define INST_FLAG_ACTIVE 0x20

    // Checked in aiPedestrian::DetectBanger[Collision/Obstacle], aiVehicleActive::Detach, aiGoalCollision::Update, mmCullCity::Reset
#define INST_FLAG_40 0x40 // Is an obstacle?

#define INST_FLAG_80 0x80
#define INST_FLAG_100 0x100          // Has Velocity? Checked in mmPhysExec::DoUpdateAll.
#define INST_FLAG_UNHIT_BANGER 0x200 // Breakable? Is Banger/Has Banger Data?
#define INST_FLAG_GLOW 0x400

    // Passed from mmPhysicsMGR::Update to mmPhysicsMGR::GatherCollidables, and mmPhysicsMGR::Collide to mmPhysicsMGR::CollideProbe
#define INST_FLAG_TERRAIN 0x800
#define INST_FLAG_1000 0x1000 // mmBangerInstance::Draw, mmHitBangerInstance::Draw - Increment lod
#define INST_FLAG_2000 0x2000 // Important shadows
#define INST_FLAG_COLLIDED_PLAYER 0x4000

    // INST_FLAG_*
    u16 Flags {INST_FLAG_ACTIVE};

    u16 GetFlags(u16 flags) const
    {
        return Flags & flags;
    }

    bool TestFlags(u16 flags) const
    {
        return (Flags & flags) != 0;
    }

    void SetFlags(u16 flags)
    {
        Flags |= flags;
    }

    void EnableFlags(u16 flags, bool enabled)
    {
        Flags = (Flags & ~flags) | (enabled ? flags : 0);
    }

    void ClearFlags(u16 flags)
    {
        Flags &= ~flags;
    }

    u16 MeshIndex {};
    i16 ChainId {-1};

    bool IsParented() const
    {
        return ChainId != -1;
    }

    /*
        mmFacadeInstance:
            ; Actually INST_INIT_FLAGs used in Draw
            SubType = flags & 0xFF;
            Owner = (flags >> 8) & 0xFF;

        aiVehicleInstance:
            aiVehicleManager::VehicleData[SubType]
            aiVehicleManager::ActiveVehicles[Owner] ; aiVehicleInstance::GetEntity

        mmBangerInstance:
            mmBangerActiveManager::Bangers[Owner] ; mmBangerActiveManager::GetActive

        mmShard:
            mmShardManager::Instances[SubType] ; mmShardManager::GetInstance
    */
    u8 SubType {};
    u8 Owner {};

    mmInstance* ChainPrev {};
    mmInstance* ChainNext {};
};

check_size(mmInstance, 0x14);

class mmMatrixInstance : public mmInstance
{
public:
    // ??0mmMatrixInstance@@QAE@XZ
    ARTS_EXPORT mmMatrixInstance();

    // ??1mmMatrixInstance@@UAE@XZ
    ARTS_EXPORT ~mmMatrixInstance() override = default;

    // ?Hit@mmMatrixInstance@@UAEXPAVmmInstance@@@Z
    ARTS_EXPORT virtual void Hit(mmInstance* arg1);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmMatrixInstance@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?FromMatrix@mmMatrixInstance@@UAIXABVMatrix34@@@Z
    ARTS_EXPORT void ARTS_FASTCALL FromMatrix(const Matrix34& matrix) override;

    // ?GetClass@mmMatrixInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetPos@mmMatrixInstance@@UAIAAVVector3@@XZ
    ARTS_EXPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?Init@mmMatrixInstance@@QAEHPADAAVVector3@@11H0@Z
    ARTS_IMPORT i32 Init(char* arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, i32 arg5, char* arg6);

    // ?SizeOf@mmMatrixInstance@@UAEIXZ
    ARTS_EXPORT usize SizeOf() override;

    // ?ToMatrix@mmMatrixInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_EXPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& matrix) override;

    // ?DeclareFields@mmMatrixInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Matrix34 Matrix {};
};

check_size(mmMatrixInstance, 0x44);

class mmShearInstance final : public mmMatrixInstance
{
public:
    // ??0mmShearInstance@@QAE@XZ | inline
    ARTS_IMPORT mmShearInstance();

    // ??1mmShearInstance@@UAE@XZ | inline
    ARTS_EXPORT ~mmShearInstance() override = default;

    // ?Draw@mmShearInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?GetClass@mmShearInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetScale@mmShearInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // ?Init@mmShearInstance@@QAEHPADAAVVector3@@1MH0@Z
    ARTS_IMPORT i32 Init(char* arg1, Vector3& arg2, Vector3& arg3, f32 arg4, i32 arg5, char* arg6);

    // ?SizeOf@mmShearInstance@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;

    // ?DeclareFields@mmShearInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    f32 Scale;
};

check_size(mmShearInstance, 0x48);

class mmBuildingInstance final : public mmMatrixInstance
{
public:
    // ??0mmBuildingInstance@@QAE@XZ | inline
    ARTS_IMPORT mmBuildingInstance();

    // ??1mmBuildingInstance@@UAE@XZ | inline
    ARTS_EXPORT ~mmBuildingInstance() override = default;

    // ?Draw@mmBuildingInstance@@UAIXH@Z
    ARTS_EXPORT void ARTS_FASTCALL Draw(i32 lod) override;

    // ?GetClass@mmBuildingInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetScale@mmBuildingInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // ?Init@mmBuildingInstance@@QAEHPADAAVVector3@@11@Z
    ARTS_IMPORT i32 Init(char* arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4);

    // ?SizeOf@mmBuildingInstance@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;

    // ?DeclareFields@mmBuildingInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    f32 Scale {1.0f};
};

check_size(mmBuildingInstance, 0x48);

// ?GetPolyInfo@@YAHPAVagiMeshSet@@@Z
ARTS_IMPORT i32 GetPolyInfo(agiMeshSet* arg1);

// ?formatf@@YAPADPBDZZ
ARTS_IMPORT char* formatf(const char* arg1, ...);

#ifdef ARTS_DEV_BUILD
// ?EnableFacadeSideClipping@@3HA
ARTS_IMPORT extern i32 EnableFacadeSideClipping;
#endif

class mmYInstance : public mmInstance
{
public:
    // ??0mmYInstance@@QAE@XZ
    ARTS_IMPORT mmYInstance();

    // ??1mmYInstance@@UAE@XZ
    ARTS_EXPORT ~mmYInstance() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmYInstance@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?FromMatrix@mmYInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetClass@mmYInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetPos@mmYInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?SizeOf@mmYInstance@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;

    // ?ToMatrix@mmYInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    // ?DeclareFields@mmYInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Vector3 Position;
    Vector2 Rotation;
    f32 Scale;
};

check_size(mmYInstance, 0x2C);

class mmStaticInstance : public mmYInstance
{
public:
    // ??0mmStaticInstance@@QAE@XZ
    ARTS_IMPORT mmStaticInstance();

    // ??1mmStaticInstance@@UAE@XZ
    ARTS_EXPORT ~mmStaticInstance() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmStaticInstance@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Draw@mmStaticInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?GetClass@mmStaticInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Relight@mmStaticInstance@@UAIXXZ
    ARTS_EXPORT void ARTS_FASTCALL Relight() override;

    // ?SizeOf@mmStaticInstance@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;

    // ?DeclareFields@mmStaticInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap2C[0xC];
};

check_size(mmStaticInstance, 0x38);

class mmFacadeInstance final : public mmStaticInstance
{
public:
    // ??0mmFacadeInstance@@QAE@XZ
    ARTS_IMPORT mmFacadeInstance();

    // ??1mmFacadeInstance@@UAE@XZ
    ARTS_EXPORT ~mmFacadeInstance() override = default;

    // ?Draw@mmFacadeInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?GetClass@mmFacadeInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetScale@mmFacadeInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // ?InitFacade@mmFacadeInstance@@QAEHPADAAVVector3@@1MHABV2@@Z
    ARTS_IMPORT i32 InitFacade(char* arg1, Vector3& arg2, Vector3& arg3, f32 arg4, i32 arg5, const Vector3& arg6);

    // ?SizeOf@mmFacadeInstance@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;

    // ?DeclareFields@mmFacadeInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap38[0xC];
};

check_size(mmFacadeInstance, 0x44);

struct mmFacadeQuad
{
public:
    // ??0mmFacadeQuad@@QAE@PAVagiMeshSet@@MM@Z
    ARTS_IMPORT mmFacadeQuad(agiMeshSet* arg1, f32 arg2, f32 arg3);

    // ?DrawLit@mmFacadeQuad@@QAEXP6AXPAEPAI1PAVagiMeshSet@@@Z2@Z
    ARTS_IMPORT void DrawLit(void (*arg1)(u8*, u32*, u32*, agiMeshSet*), agiMeshSet* arg2);

    // ?DoubleArea@mmFacadeQuad@@SAMPAVagiMeshSet@@@Z
    ARTS_IMPORT static f32 DoubleArea(agiMeshSet* arg1);

    // ?Valid@mmFacadeQuad@@SAHPAVagiMeshSet@@@Z
    ARTS_IMPORT static i32 Valid(agiMeshSet* arg1);

    u8 gap0[0x18];
};

check_size(mmFacadeQuad, 0x18);
