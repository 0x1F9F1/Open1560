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
    mmcity:inst

    0x4929D0 | public: __thiscall mmInstance::mmInstance(void) | ??0mmInstance@@QAE@XZ
    0x492A00 | public: virtual __thiscall mmInstance::~mmInstance(void) | ??1mmInstance@@UAE@XZ
    0x492A10 | public: virtual void __fastcall mmInstance::Relight(void) | ?Relight@mmInstance@@UAIXXZ
    0x492A20 | public: virtual float __fastcall mmInstance::GetScale(void) | ?GetScale@mmInstance@@UAIMXZ
    0x492A30 | public: virtual int __thiscall mmInstance::ComputeLod(float,float) | ?ComputeLod@mmInstance@@UAEHMM@Z
    0x492AA0 | public: virtual void __fastcall mmInstance::Draw(int) | ?Draw@mmInstance@@UAIXH@Z
    0x492B00 | public: virtual void __fastcall mmInstance::DrawShadow(void) | ?DrawShadow@mmInstance@@UAIXXZ
    0x492B10 | public: virtual void __fastcall mmInstance::DrawGlow(void) | ?DrawGlow@mmInstance@@UAIXXZ
    0x492B20 | public: virtual int __thiscall mmInstance::Init(char *,class Vector3 &,class Vector3 &,int,char *) | ?Init@mmInstance@@UAEHPADAAVVector3@@1H0@Z
    0x492BC0 | char * __cdecl formatf(char const *,...) | ?formatf@@YAPADPBDZZ
    0x492BE0 | public: class agiMeshSet * __thiscall mmInstance::GetResidentMeshSet(int,int,int) | ?GetResidentMeshSet@mmInstance@@QAEPAVagiMeshSet@@HHH@Z
    0x492C70 | public: static int __cdecl mmInstance::GetMeshSetSet(char *,int,char *,class Vector3 *) | ?GetMeshSetSet@mmInstance@@SAHPADH0PAVVector3@@@Z
    0x4930E0 | int __cdecl GetPolyInfo(class agiMeshSet *) | ?GetPolyInfo@@YAHPAVagiMeshSet@@@Z
    0x493120 | public: virtual unsigned int __thiscall mmInstance::SizeOf(void) | ?SizeOf@mmInstance@@UAEIXZ
    0x493130 | public: virtual void __thiscall mmInstance::Reset(void) | ?Reset@mmInstance@@UAEXXZ
    0x493140 | public: static void __cdecl mmInstance::ResetAll(void) | ?ResetAll@mmInstance@@SAXXZ
    0x493250 | public: void __thiscall mmInstance::InitMeshes(char *,int,char *,class Vector3 *) | ?InitMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    0x493290 | public: void __thiscall mmInstance::AddMeshes(char *,int,char *,class Vector3 *) | ?AddMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    0x4932B0 | public: __thiscall mmYInstance::mmYInstance(void) | ??0mmYInstance@@QAE@XZ
    0x4932E0 | public: virtual __thiscall mmYInstance::~mmYInstance(void) | ??1mmYInstance@@UAE@XZ
    0x4932F0 | public: virtual void __fastcall mmYInstance::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmYInstance@@UAIXABVMatrix34@@@Z
    0x493340 | public: virtual class Matrix34 & __fastcall mmYInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@mmYInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x493390 | public: virtual class Vector3 & __fastcall mmYInstance::GetPos(void) | ?GetPos@mmYInstance@@UAIAAVVector3@@XZ
    0x4933A0 | public: virtual unsigned int __thiscall mmYInstance::SizeOf(void) | ?SizeOf@mmYInstance@@UAEIXZ
    0x4933B0 | public: virtual void __thiscall mmYInstance::AddWidgets(class Bank *) | ?AddWidgets@mmYInstance@@UAEXPAVBank@@@Z
    0x493400 | public: __thiscall mmMatrixInstance::mmMatrixInstance(void) | ??0mmMatrixInstance@@QAE@XZ
    0x493430 | public: virtual __thiscall mmMatrixInstance::~mmMatrixInstance(void) | ??1mmMatrixInstance@@UAE@XZ
    0x493440 | public: virtual void __fastcall mmMatrixInstance::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmMatrixInstance@@UAIXABVMatrix34@@@Z
    0x493460 | public: virtual class Matrix34 & __fastcall mmMatrixInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@mmMatrixInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x493470 | public: virtual class Vector3 & __fastcall mmMatrixInstance::GetPos(void) | ?GetPos@mmMatrixInstance@@UAIAAVVector3@@XZ
    0x493480 | public: int __thiscall mmMatrixInstance::Init(char *,class Vector3 &,class Vector3 &,class Vector3 &,int,char *) | ?Init@mmMatrixInstance@@QAEHPADAAVVector3@@11H0@Z
    0x4935B0 | public: virtual void __thiscall mmMatrixInstance::Hit(class mmInstance *) | ?Hit@mmMatrixInstance@@UAEXPAVmmInstance@@@Z
    0x4935C0 | public: virtual unsigned int __thiscall mmMatrixInstance::SizeOf(void) | ?SizeOf@mmMatrixInstance@@UAEIXZ
    0x4935D0 | public: virtual void __thiscall mmMatrixInstance::AddWidgets(class Bank *) | ?AddWidgets@mmMatrixInstance@@UAEXPAVBank@@@Z
    0x4935E0 | public: __thiscall mmStaticInstance::mmStaticInstance(void) | ??0mmStaticInstance@@QAE@XZ
    0x493600 | public: virtual __thiscall mmStaticInstance::~mmStaticInstance(void) | ??1mmStaticInstance@@UAE@XZ
    0x493610 | public: int __thiscall mmStaticInstance::Init(char *,class Vector3 &,class Vector3 &,float,int,char *) | ?Init@mmStaticInstance@@QAEHPADAAVVector3@@1MH0@Z
    0x493670 | void __cdecl MatrixFromPoints(class Matrix34 &,class Vector3 &,class Vector3 &,float) | ?MatrixFromPoints@@YAXAAVMatrix34@@AAVVector3@@1M@Z
    0x493790 | public: __thiscall mmFacadeInstance::mmFacadeInstance(void) | ??0mmFacadeInstance@@QAE@XZ
    0x4937B0 | public: virtual __thiscall mmFacadeInstance::~mmFacadeInstance(void) | ??1mmFacadeInstance@@UAE@XZ
    0x4937C0 | public: static float __cdecl mmFacadeQuad::DoubleArea(class agiMeshSet *) | ?DoubleArea@mmFacadeQuad@@SAMPAVagiMeshSet@@@Z
    0x493820 | public: static int __cdecl mmFacadeQuad::Valid(class agiMeshSet *) | ?Valid@mmFacadeQuad@@SAHPAVagiMeshSet@@@Z
    0x493850 | public: __thiscall mmFacadeQuad::mmFacadeQuad(class agiMeshSet *,float,float) | ??0mmFacadeQuad@@QAE@PAVagiMeshSet@@MM@Z
    0x493B70 | public: void __thiscall mmFacadeQuad::DrawLit(void (__cdecl*)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *),class agiMeshSet *) | ?DrawLit@mmFacadeQuad@@QAEXP6AXPAEPAI1PAVagiMeshSet@@@Z2@Z
    0x493CC0 | public: int __thiscall mmFacadeInstance::InitFacade(char *,class Vector3 &,class Vector3 &,float,int,class Vector3 const &) | ?InitFacade@mmFacadeInstance@@QAEHPADAAVVector3@@1MHABV2@@Z
    0x493FF0 | public: virtual float __fastcall mmFacadeInstance::GetScale(void) | ?GetScale@mmFacadeInstance@@UAIMXZ
    0x494000 | public: virtual unsigned int __thiscall mmFacadeInstance::SizeOf(void) | ?SizeOf@mmFacadeInstance@@UAEIXZ
    0x494010 | public: virtual void __fastcall mmFacadeInstance::Draw(int) | ?Draw@mmFacadeInstance@@UAIXH@Z
    0x494210 | public: virtual unsigned int __thiscall mmStaticInstance::SizeOf(void) | ?SizeOf@mmStaticInstance@@UAEIXZ
    0x494220 | public: virtual void __fastcall mmStaticInstance::Relight(void) | ?Relight@mmStaticInstance@@UAIXXZ
    0x494230 | public: virtual void __fastcall mmStaticInstance::Draw(int) | ?Draw@mmStaticInstance@@UAIXH@Z
    0x494290 | public: virtual unsigned int __thiscall mmShearInstance::SizeOf(void) | ?SizeOf@mmShearInstance@@UAEIXZ
    0x4942A0 | public: int __thiscall mmShearInstance::Init(char *,class Vector3 &,class Vector3 &,float,int,char *) | ?Init@mmShearInstance@@QAEHPADAAVVector3@@1MH0@Z
    0x494460 | public: virtual void __fastcall mmShearInstance::Draw(int) | ?Draw@mmShearInstance@@UAIXH@Z
    0x494480 | public: virtual float __fastcall mmShearInstance::GetScale(void) | ?GetScale@mmShearInstance@@UAIMXZ
    0x494490 | public: virtual unsigned int __thiscall mmBuildingInstance::SizeOf(void) | ?SizeOf@mmBuildingInstance@@UAEIXZ
    0x4944A0 | public: int __thiscall mmBuildingInstance::Init(char *,class Vector3 &,class Vector3 &,class Vector3 &) | ?Init@mmBuildingInstance@@QAEHPADAAVVector3@@11@Z
    0x4945E0 | public: virtual float __fastcall mmBuildingInstance::GetScale(void) | ?GetScale@mmBuildingInstance@@UAIMXZ
    0x4945F0 | public: virtual void __fastcall mmBuildingInstance::Draw(int) | ?Draw@mmBuildingInstance@@UAIXH@Z
    0x4946B0 | public: void __thiscall mmInstance::DrawDropShadow(int,int,class Matrix34 const &) | ?DrawDropShadow@mmInstance@@QAEXHHABVMatrix34@@@Z
    0x494960 | public: virtual void __thiscall mmStaticInstance::AddWidgets(class Bank *) | ?AddWidgets@mmStaticInstance@@UAEXPAVBank@@@Z
    0x494A10 | public: static void __cdecl mmInstance::DeclareFields(void) | ?DeclareFields@mmInstance@@SAXXZ
    0x494AB0 | public: virtual class MetaClass * __thiscall mmInstance::GetClass(void) | ?GetClass@mmInstance@@UAEPAVMetaClass@@XZ
    0x494AC0 | public: static void __cdecl mmYInstance::DeclareFields(void) | ?DeclareFields@mmYInstance@@SAXXZ
    0x494B60 | public: virtual class MetaClass * __thiscall mmYInstance::GetClass(void) | ?GetClass@mmYInstance@@UAEPAVMetaClass@@XZ
    0x494B70 | public: static void __cdecl mmMatrixInstance::DeclareFields(void) | ?DeclareFields@mmMatrixInstance@@SAXXZ
    0x494CF0 | public: virtual class MetaClass * __thiscall mmMatrixInstance::GetClass(void) | ?GetClass@mmMatrixInstance@@UAEPAVMetaClass@@XZ
    0x494D00 | public: static void __cdecl mmShearInstance::DeclareFields(void) | ?DeclareFields@mmShearInstance@@SAXXZ
    0x494E90 | public: virtual class MetaClass * __thiscall mmShearInstance::GetClass(void) | ?GetClass@mmShearInstance@@UAEPAVMetaClass@@XZ
    0x494EA0 | public: static void __cdecl mmBuildingInstance::DeclareFields(void) | ?DeclareFields@mmBuildingInstance@@SAXXZ
    0x495030 | public: virtual class MetaClass * __thiscall mmBuildingInstance::GetClass(void) | ?GetClass@mmBuildingInstance@@UAEPAVMetaClass@@XZ
    0x495040 | public: static void __cdecl mmStaticInstance::DeclareFields(void) | ?DeclareFields@mmStaticInstance@@SAXXZ
    0x4951C0 | public: virtual class MetaClass * __thiscall mmStaticInstance::GetClass(void) | ?GetClass@mmStaticInstance@@UAEPAVMetaClass@@XZ
    0x4951D0 | public: static void __cdecl mmFacadeInstance::DeclareFields(void) | ?DeclareFields@mmFacadeInstance@@SAXXZ
    0x495350 | public: virtual class MetaClass * __thiscall mmFacadeInstance::GetClass(void) | ?GetClass@mmFacadeInstance@@UAEPAVMetaClass@@XZ
    0x495360 | public: virtual void * __thiscall mmInstance::`scalar deleting destructor'(unsigned int) | ??_GmmInstance@@UAEPAXI@Z
    0x495360 | public: virtual void * __thiscall mmInstance::`vector deleting destructor'(unsigned int) | ??_EmmInstance@@UAEPAXI@Z
    0x495380 | public: virtual void * __thiscall mmYInstance::`scalar deleting destructor'(unsigned int) | ??_GmmYInstance@@UAEPAXI@Z
    0x495380 | public: virtual void * __thiscall mmYInstance::`vector deleting destructor'(unsigned int) | ??_EmmYInstance@@UAEPAXI@Z
    0x4953A0 | public: virtual void * __thiscall mmMatrixInstance::`vector deleting destructor'(unsigned int) | ??_EmmMatrixInstance@@UAEPAXI@Z
    0x495400 | public: virtual void * __thiscall mmShearInstance::`vector deleting destructor'(unsigned int) | ??_EmmShearInstance@@UAEPAXI@Z
    0x495460 | public: __thiscall mmShearInstance::mmShearInstance(void) | ??0mmShearInstance@@QAE@XZ
    0x495480 | public: virtual void * __thiscall mmBuildingInstance::`vector deleting destructor'(unsigned int) | ??_EmmBuildingInstance@@UAEPAXI@Z
    0x4954E0 | public: __thiscall mmBuildingInstance::mmBuildingInstance(void) | ??0mmBuildingInstance@@QAE@XZ
    0x495500 | public: virtual void * __thiscall mmStaticInstance::`vector deleting destructor'(unsigned int) | ??_EmmStaticInstance@@UAEPAXI@Z
    0x495560 | public: virtual void * __thiscall mmFacadeInstance::`vector deleting destructor'(unsigned int) | ??_EmmFacadeInstance@@UAEPAXI@Z
    0x61CFC8 | const mmInstance::`vftable' | ??_7mmInstance@@6B@
    0x61D058 | const mmYInstance::`vftable' | ??_7mmYInstance@@6B@
    0x61D0B8 | const mmMatrixInstance::`vftable' | ??_7mmMatrixInstance@@6B@
    0x61D118 | const mmStaticInstance::`vftable' | ??_7mmStaticInstance@@6B@
    0x61D178 | const mmFacadeInstance::`vftable' | ??_7mmFacadeInstance@@6B@
    0x63F828 | public: static float (* mmInstance::LodTable)[4][3] | ?LodTable@mmInstance@@2PAY132MA
    0x63F8B8 | int EnableFacadeSideClipping | ?EnableFacadeSideClipping@@3HA
    0x6ED4F8 | public: static char * * mmInstance::MeshSetNames | ?MeshSetNames@mmInstance@@2PAPADA
    0x6F14F8 | public: static void (__cdecl* mmInstance::DynamicLighter)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?DynamicLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    0x6F1500 | class MetaClass mmInstanceMetaClass | ?mmInstanceMetaClass@@3VMetaClass@@A
    0x6F1528 | class mmHeap<int> mmInstanceHeap | ?mmInstanceHeap@@3V?$mmHeap@H@@A
    0x6F1538 | public: static struct mmInstance::MeshSetTableEntry * mmInstance::MeshSetTable | ?MeshSetTable@mmInstance@@2PAUMeshSetTableEntry@1@A
    0x705538 | class MetaClass mmMatrixInstanceMetaClass | ?mmMatrixInstanceMetaClass@@3VMetaClass@@A
    0x705560 | public: static int mmInstance::ShowLights | ?ShowLights@mmInstance@@2HA
    0x705578 | class MetaClass mmFacadeInstanceMetaClass | ?mmFacadeInstanceMetaClass@@3VMetaClass@@A
    0x7055A0 | class MetaClass mmYInstanceMetaClass | ?mmYInstanceMetaClass@@3VMetaClass@@A
    0x7055D0 | public: static int mmInstance::LodTableIndex | ?LodTableIndex@mmInstance@@2HA
    0x7055D8 | class MetaClass mmBuildingInstanceMetaClass | ?mmBuildingInstanceMetaClass@@3VMetaClass@@A
    0x705688 | public: static void (__cdecl* mmInstance::StaticLighter)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?StaticLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    0x705690 | class MetaClass mmShearInstanceMetaClass | ?mmShearInstanceMetaClass@@3VMetaClass@@A
    0x7056C0 | class MetaClass mmStaticInstanceMetaClass | ?mmStaticInstanceMetaClass@@3VMetaClass@@A
    0x7056F8 | public: static int mmInstance::MeshSetSetCount | ?MeshSetSetCount@mmInstance@@2HA
*/

#include "data7/base.h"

#include "heap.h"
#include "vector7/matrix34.h"

class agiMeshSet;
class mmBoundTemplate;
class mmPhysEntity;

class mmInstance : public Base
{
public:
    // ??0mmInstance@@QAE@XZ
    ARTS_EXPORT mmInstance() = default;

    // ??_EmmInstance@@UAEPAXI@Z
    // ??_GmmInstance@@UAEPAXI@Z
    // ??1mmInstance@@UAE@XZ
    ARTS_IMPORT ~mmInstance() override = default;

    virtual void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) = 0;

    virtual Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) = 0;

    virtual Vector3& ARTS_FASTCALL GetPos() = 0;

    // ?GetEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_EXPORT virtual mmPhysEntity* GetEntity();

    // ?AttachEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_EXPORT virtual mmPhysEntity* AttachEntity();

    // ?GetVelocity@mmInstance@@UAE?AVVector3@@XZ | inline
    ARTS_IMPORT virtual Vector3 GetVelocity();

    // ?Impact@mmInstance@@UAEXPAV1@PAVVector3@@@Z | inline
    ARTS_EXPORT virtual void Impact(mmInstance* arg1, Vector3* arg2);

    // ?Detach@mmInstance@@UAEXXZ | inline
    ARTS_EXPORT virtual void Detach();

    // ?Draw@mmInstance@@UAIXH@Z
    ARTS_IMPORT virtual void ARTS_FASTCALL Draw(i32 arg1);

    // ?DrawShadow@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL DrawShadow();

    // ?DrawGlow@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL DrawGlow();

    // ?Relight@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL Relight();

    // ?SizeOf@mmInstance@@UAEIXZ
    ARTS_IMPORT virtual u32 SizeOf();

    // ?Reset@mmInstance@@UAEXXZ
    ARTS_EXPORT virtual void Reset();

#ifdef ARTS_DEV_BUILD
    virtual void AddWidgets(Bank* arg1) = 0;
#endif

    // ?Init@mmInstance@@UAEHPADAAVVector3@@1H0@Z
    ARTS_EXPORT virtual i32 Init(char* arg1, Vector3& arg2, Vector3& arg3, i32 arg4, char* arg5);

    // ?GetScale@mmInstance@@UAIMXZ
    ARTS_IMPORT virtual f32 ARTS_FASTCALL GetScale();

    // ?ComputeLod@mmInstance@@UAEHMM@Z
    ARTS_IMPORT virtual i32 ComputeLod(f32 arg1, f32 arg2);

    // ?AddMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    ARTS_IMPORT void AddMeshes(char* arg1, i32 arg2, char* arg3, Vector3* arg4);

    // ?DrawDropShadow@mmInstance@@QAEXHHABVMatrix34@@@Z
    ARTS_IMPORT void DrawDropShadow(i32 arg1, i32 arg2, const Matrix34& arg3);

    // ?GetClass@mmInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetResidentMeshSet@mmInstance@@QAEPAVagiMeshSet@@HHH@Z
    ARTS_EXPORT agiMeshSet* GetResidentMeshSet(i32 lod, i32 index, i32 variant = 0);

    // ?InitMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    ARTS_IMPORT void InitMeshes(char* arg1, i32 arg2, char* arg3, Vector3* arg4);

    static void* operator new(std::size_t size);

    // ??3mmInstance@@SAXPAX@Z | inline
    static void operator delete(void* ptr);

    // ?DeclareFields@mmInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?GetMeshSetSet@mmInstance@@SAHPADH0PAVVector3@@@Z
    ARTS_IMPORT static i32 GetMeshSetSet(char* arg1, i32 arg2, char* arg3, Vector3* arg4);

    // ?ResetAll@mmInstance@@SAXXZ
    ARTS_IMPORT static void ResetAll();

    // ?DynamicLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    ARTS_IMPORT static void (*DynamicLighter)(u8*, u32*, u32*, agiMeshSet*);

    // ?LodTable@mmInstance@@2PAY132MA
    ARTS_EXPORT static f32 LodTable[3][4][3];

    // ?LodTableIndex@mmInstance@@2HA
    ARTS_IMPORT static i32 LodTableIndex;

    // ?MeshSetNames@mmInstance@@2PAPADA
    ARTS_IMPORT static char* MeshSetNames[4096];

    // ?MeshSetSetCount@mmInstance@@2HA
    ARTS_IMPORT static i32 MeshSetSetCount;

#define INST_LOD_VLOW 0
#define INST_LOD_LOW 1
#define INST_LOD_MED 2
#define INST_LOD_HIGH 3

    struct MeshSetTableEntry
    {
        agiMeshSet* Meshes[4] {};
        mmBoundTemplate* Bound {nullptr};
    };

    // ?MeshSetTable@mmInstance@@2PAUMeshSetTableEntry@1@A
    ARTS_IMPORT static MeshSetTableEntry MeshSetTable[4096];

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
                    mmDofBangerInstance
                        mmDrawbridgeInstance &= ~(0x2 | 0x20), |= 0x800

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
#define INST_FLAG_BANGER 0x40 // Instance is a mmBangerInstance
#define INST_FLAG_80 0x80
#define INST_FLAG_100 0x100   // Vehicle?
#define INST_FLAG_UNHIT 0x200 // Instance is a mmUnhitBangerInstance
#define INST_FLAG_GLOW 0x400
#define INST_FLAG_800 0x800   // Terrain? Passed from mmPhysicsMGR::Update to mmPhysicsMGR::GatherCollidables
#define INST_FLAG_1000 0x1000 // mmBangerInstance::Draw - Increment lod
#define INST_FLAG_2000 0x2000
#define INST_FLAG_4000 0x4000 // Collided with Player?

    // INST_FLAG_*
    u16 Flags {INST_FLAG_ACTIVE};

    u16 MeshIndex {0};
    i16 ChainId {-1};

    /*
        mmFacadeInstance:
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
    u8 SubType {0};
    u8 Owner {0};

    mmInstance* PrevChain {nullptr};
    mmInstance* NextChain {nullptr};
};

check_size(mmInstance, 0x14);

class mmMatrixInstance : public mmInstance
{
public:
    // ??0mmMatrixInstance@@QAE@XZ
    ARTS_IMPORT mmMatrixInstance();

    // ??_EmmMatrixInstance@@UAEPAXI@Z
    // ??1mmMatrixInstance@@UAE@XZ
    ARTS_IMPORT ~mmMatrixInstance() override = default;

    // ?Hit@mmMatrixInstance@@UAEXPAVmmInstance@@@Z
    ARTS_EXPORT virtual void Hit(mmInstance* arg1);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmMatrixInstance@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?FromMatrix@mmMatrixInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetClass@mmMatrixInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetPos@mmMatrixInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?Init@mmMatrixInstance@@QAEHPADAAVVector3@@11H0@Z
    ARTS_IMPORT i32 Init(char* arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, i32 arg5, char* arg6);

    // ?SizeOf@mmMatrixInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // ?ToMatrix@mmMatrixInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

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

    // ??_EmmShearInstance@@UAEPAXI@Z
    // ??_GmmShearInstance@@UAEPAXI@Z | unused
    // ??1mmShearInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmShearInstance() override = default;

    // ?Draw@mmShearInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?GetClass@mmShearInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetScale@mmShearInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // ?Init@mmShearInstance@@QAEHPADAAVVector3@@1MH0@Z
    ARTS_IMPORT i32 Init(char* arg1, Vector3& arg2, Vector3& arg3, f32 arg4, i32 arg5, char* arg6);

    // ?SizeOf@mmShearInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // ?DeclareFields@mmShearInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap44[0x4];
};

check_size(mmShearInstance, 0x48);

class mmBuildingInstance final : public mmMatrixInstance
{
public:
    // ??0mmBuildingInstance@@QAE@XZ | inline
    ARTS_IMPORT mmBuildingInstance();

    // ??_EmmBuildingInstance@@UAEPAXI@Z
    // ??_GmmBuildingInstance@@UAEPAXI@Z | unused
    // ??1mmBuildingInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmBuildingInstance() override = default;

    // ?Draw@mmBuildingInstance@@UAIXH@Z
    ARTS_EXPORT void ARTS_FASTCALL Draw(i32 lod) override;

    // ?GetClass@mmBuildingInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetScale@mmBuildingInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // ?Init@mmBuildingInstance@@QAEHPADAAVVector3@@11@Z
    ARTS_IMPORT i32 Init(char* arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4);

    // ?SizeOf@mmBuildingInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

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

// ?mmInstanceHeap@@3V?$mmHeap@H@@A
ARTS_IMPORT extern class mmHeap<i32> mmInstanceHeap;

class mmYInstance : public mmInstance
{
public:
    // ??0mmYInstance@@QAE@XZ
    ARTS_IMPORT mmYInstance();

    // ??_EmmYInstance@@UAEPAXI@Z
    // ??_GmmYInstance@@UAEPAXI@Z
    // ??1mmYInstance@@UAE@XZ
    ARTS_IMPORT ~mmYInstance() override = default;

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
    ARTS_IMPORT u32 SizeOf() override;

    // ?ToMatrix@mmYInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    // ?DeclareFields@mmYInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap14[0x18];
};

check_size(mmYInstance, 0x2C);

class mmStaticInstance : public mmYInstance
{
public:
    // ??0mmStaticInstance@@QAE@XZ
    ARTS_IMPORT mmStaticInstance();

    // ??_EmmStaticInstance@@UAEPAXI@Z
    // ??1mmStaticInstance@@UAE@XZ
    ARTS_IMPORT ~mmStaticInstance() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmStaticInstance@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Draw@mmStaticInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?GetClass@mmStaticInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmStaticInstance@@QAEHPADAAVVector3@@1MH0@Z | unused
    ARTS_IMPORT i32 Init(char* arg1, Vector3& arg2, Vector3& arg3, f32 arg4, i32 arg5, char* arg6);

    // ?Relight@mmStaticInstance@@UAIXXZ
    ARTS_EXPORT void ARTS_FASTCALL Relight() override;

    // ?SizeOf@mmStaticInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

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

    // ??_EmmFacadeInstance@@UAEPAXI@Z
    // ??1mmFacadeInstance@@UAE@XZ
    ARTS_IMPORT ~mmFacadeInstance() override = default;

    // ?Draw@mmFacadeInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?GetClass@mmFacadeInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetScale@mmFacadeInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // ?InitFacade@mmFacadeInstance@@QAEHPADAAVVector3@@1MHABV2@@Z
    ARTS_IMPORT i32 InitFacade(char* arg1, Vector3& arg2, Vector3& arg3, f32 arg4, i32 arg5, const Vector3& arg6);

    // ?SizeOf@mmFacadeInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

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
