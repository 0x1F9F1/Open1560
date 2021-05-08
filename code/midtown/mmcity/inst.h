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

class mmBoundTemplate;

class mmInstance : public Base
{
    // const mmInstance::`vftable' @ 0x61CFC8

public:
    // 0x4929D0 | ??0mmInstance@@QAE@XZ
    ARTS_IMPORT mmInstance();

    // 0x495360 | ??_EmmInstance@@UAEPAXI@Z
    // 0x495360 | ??_GmmInstance@@UAEPAXI@Z
    // 0x492A00 | ??1mmInstance@@UAE@XZ
    ARTS_IMPORT ~mmInstance() override = default;

    virtual void ARTS_FASTCALL FromMatrix(class Matrix34 const& arg1) = 0;

    virtual class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) = 0;

    virtual class Vector3& ARTS_FASTCALL GetPos() = 0;

    // 0x433DB0 | ?GetEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_EXPORT virtual class mmPhysEntity* GetEntity();

    // 0x433DC0 | ?AttachEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_EXPORT virtual class mmPhysEntity* AttachEntity();

    // 0x433DD0 | ?GetVelocity@mmInstance@@UAE?AVVector3@@XZ | inline
    ARTS_IMPORT virtual class Vector3 GetVelocity();

    // 0x433DF0 | ?Impact@mmInstance@@UAEXPAV1@PAVVector3@@@Z | inline
    ARTS_EXPORT virtual void Impact(class mmInstance* arg1, class Vector3* arg2);

    // 0x433E00 | ?Detach@mmInstance@@UAEXXZ | inline
    ARTS_EXPORT virtual void Detach();

    // 0x492AA0 | ?Draw@mmInstance@@UAIXH@Z
    ARTS_IMPORT virtual void ARTS_FASTCALL Draw(i32 arg1);

    // 0x492B00 | ?DrawShadow@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL DrawShadow();

    // 0x492B10 | ?DrawGlow@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL DrawGlow();

    // 0x492A10 | ?Relight@mmInstance@@UAIXXZ
    ARTS_EXPORT virtual void ARTS_FASTCALL Relight();

    // 0x493120 | ?SizeOf@mmInstance@@UAEIXZ
    ARTS_IMPORT virtual u32 SizeOf();

    // 0x493130 | ?Reset@mmInstance@@UAEXXZ
    ARTS_EXPORT virtual void Reset();

    virtual void AddWidgets(class Bank* arg1) = 0;

    // 0x492B20 | ?Init@mmInstance@@UAEHPADAAVVector3@@1H0@Z
    ARTS_EXPORT virtual i32 Init(char* arg1, class Vector3& arg2, class Vector3& arg3, i32 arg4, char* arg5);

    // 0x492A20 | ?GetScale@mmInstance@@UAIMXZ
    ARTS_IMPORT virtual f32 ARTS_FASTCALL GetScale();

    // 0x492A30 | ?ComputeLod@mmInstance@@UAEHMM@Z
    ARTS_IMPORT virtual i32 ComputeLod(f32 arg1, f32 arg2);

    // 0x493290 | ?AddMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    ARTS_IMPORT void AddMeshes(char* arg1, i32 arg2, char* arg3, class Vector3* arg4);

    // 0x4946B0 | ?DrawDropShadow@mmInstance@@QAEXHHABVMatrix34@@@Z
    ARTS_IMPORT void DrawDropShadow(i32 arg1, i32 arg2, class Matrix34 const& arg3);

    // 0x494AB0 | ?GetClass@mmInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x492BE0 | ?GetResidentMeshSet@mmInstance@@QAEPAVagiMeshSet@@HHH@Z
    ARTS_IMPORT class agiMeshSet* GetResidentMeshSet(i32 arg1, i32 arg2, i32 arg3);

    // 0x493250 | ?InitMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    ARTS_IMPORT void InitMeshes(char* arg1, i32 arg2, char* arg3, class Vector3* arg4);

    static void* operator new(std::size_t size);

    // 0x430690 | ??3mmInstance@@SAXPAX@Z | inline
    static void operator delete(void* ptr);

    // 0x494A10 | ?DeclareFields@mmInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // 0x492C70 | ?GetMeshSetSet@mmInstance@@SAHPADH0PAVVector3@@@Z
    ARTS_IMPORT static i32 GetMeshSetSet(char* arg1, i32 arg2, char* arg3, class Vector3* arg4);

    // 0x493140 | ?ResetAll@mmInstance@@SAXXZ
    ARTS_IMPORT static void ResetAll();

    // 0x6F14F8 | ?DynamicLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    ARTS_IMPORT static void (*DynamicLighter)(u8*, u32*, u32*, class agiMeshSet*);

    // 0x63F828 | ?LodTable@mmInstance@@2PAY132MA
    ARTS_IMPORT static f32 LodTable[3][4][3];

    // 0x7055D0 | ?LodTableIndex@mmInstance@@2HA
    ARTS_IMPORT static i32 LodTableIndex;

    // 0x6ED4F8 | ?MeshSetNames@mmInstance@@2PAPADA
    ARTS_IMPORT static char* MeshSetNames[4096];

    // 0x7056F8 | ?MeshSetSetCount@mmInstance@@2HA
    ARTS_IMPORT static i32 MeshSetSetCount;

    struct MeshSetTableEntry
    {
        agiMeshSet* VLow {nullptr};
        agiMeshSet* Low {nullptr};
        agiMeshSet* Medium {nullptr};
        agiMeshSet* High {nullptr};
        mmBoundTemplate* Bound {nullptr};
    };

    // 0x6F1538 | ?MeshSetTable@mmInstance@@2PAUMeshSetTableEntry@1@A
    ARTS_IMPORT static struct MeshSetTableEntry MeshSetTable[4096];

    // 0x705560 | ?ShowLights@mmInstance@@2HA
    ARTS_IMPORT static i32 ShowLights;

    // 0x705688 | ?StaticLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    ARTS_IMPORT static void (*StaticLighter)(u8*, u32*, u32*, class agiMeshSet*);

    u8 gap4[0x10];
};

check_size(mmInstance, 0x14);

class mmMatrixInstance : public mmInstance
{
    // const mmMatrixInstance::`vftable' @ 0x61D0B8

public:
    // 0x493400 | ??0mmMatrixInstance@@QAE@XZ
    ARTS_IMPORT mmMatrixInstance();

    // 0x4953A0 | ??_EmmMatrixInstance@@UAEPAXI@Z
    // 0x493430 | ??1mmMatrixInstance@@UAE@XZ
    ARTS_IMPORT ~mmMatrixInstance() override = default;

    // 0x4935B0 | ?Hit@mmMatrixInstance@@UAEXPAVmmInstance@@@Z
    ARTS_EXPORT virtual void Hit(class mmInstance* arg1);

    // 0x4935D0 | ?AddWidgets@mmMatrixInstance@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(class Bank* arg1) override;

    // 0x493440 | ?FromMatrix@mmMatrixInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(class Matrix34 const& arg1) override;

    // 0x494CF0 | ?GetClass@mmMatrixInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x493470 | ?GetPos@mmMatrixInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT class Vector3& ARTS_FASTCALL GetPos() override;

    // 0x493480 | ?Init@mmMatrixInstance@@QAEHPADAAVVector3@@11H0@Z
    ARTS_IMPORT i32 Init(
        char* arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4, i32 arg5, char* arg6);

    // 0x4935C0 | ?SizeOf@mmMatrixInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // 0x493460 | ?ToMatrix@mmMatrixInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) override;

    // 0x494B70 | ?DeclareFields@mmMatrixInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap14[0x30];
};

check_size(mmMatrixInstance, 0x44);

class mmShearInstance final : public mmMatrixInstance
{
    // const mmShearInstance::`vftable' @ 0x61CE78

public:
    // 0x495460 | ??0mmShearInstance@@QAE@XZ | inline
    ARTS_IMPORT mmShearInstance();

    // 0x495400 | ??_EmmShearInstance@@UAEPAXI@Z
    // 0x48FBF0 | ??_GmmShearInstance@@UAEPAXI@Z | unused
    // 0x48FC10 | ??1mmShearInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmShearInstance() override = default;

    // 0x494460 | ?Draw@mmShearInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x494E90 | ?GetClass@mmShearInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x494480 | ?GetScale@mmShearInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // 0x4942A0 | ?Init@mmShearInstance@@QAEHPADAAVVector3@@1MH0@Z
    ARTS_IMPORT i32 Init(char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, char* arg6);

    // 0x494290 | ?SizeOf@mmShearInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // 0x494D00 | ?DeclareFields@mmShearInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap44[0x4];
};

check_size(mmShearInstance, 0x48);

class mmBuildingInstance final : public mmMatrixInstance
{
    // const mmBuildingInstance::`vftable' @ 0x61CE18

public:
    // 0x4954E0 | ??0mmBuildingInstance@@QAE@XZ | inline
    ARTS_IMPORT mmBuildingInstance();

    // 0x495480 | ??_EmmBuildingInstance@@UAEPAXI@Z
    // 0x48FC20 | ??_GmmBuildingInstance@@UAEPAXI@Z | unused
    // 0x48FC40 | ??1mmBuildingInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmBuildingInstance() override = default;

    // 0x4945F0 | ?Draw@mmBuildingInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x495030 | ?GetClass@mmBuildingInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4945E0 | ?GetScale@mmBuildingInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // 0x4944A0 | ?Init@mmBuildingInstance@@QAEHPADAAVVector3@@11@Z
    ARTS_IMPORT i32 Init(char* arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4);

    // 0x494490 | ?SizeOf@mmBuildingInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // 0x494EA0 | ?DeclareFields@mmBuildingInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap44[0x4];
};

check_size(mmBuildingInstance, 0x48);

// 0x4930E0 | ?GetPolyInfo@@YAHPAVagiMeshSet@@@Z
ARTS_IMPORT i32 GetPolyInfo(class agiMeshSet* arg1);

// 0x492BC0 | ?formatf@@YAPADPBDZZ
ARTS_IMPORT char* formatf(char const* arg1, ...);

// 0x63F8B8 | ?EnableFacadeSideClipping@@3HA
ARTS_IMPORT extern i32 EnableFacadeSideClipping;

// 0x7055D8 | ?mmBuildingInstanceMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmBuildingInstanceMetaClass;

// 0x705578 | ?mmFacadeInstanceMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmFacadeInstanceMetaClass;

// 0x6F1528 | ?mmInstanceHeap@@3V?$mmHeap@H@@A
ARTS_IMPORT extern class mmHeap<i32> mmInstanceHeap;

// 0x6F1500 | ?mmInstanceMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmInstanceMetaClass;

// 0x705538 | ?mmMatrixInstanceMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmMatrixInstanceMetaClass;

// 0x705690 | ?mmShearInstanceMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmShearInstanceMetaClass;

// 0x7056C0 | ?mmStaticInstanceMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmStaticInstanceMetaClass;

// 0x7055A0 | ?mmYInstanceMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmYInstanceMetaClass;

class mmYInstance : public mmInstance
{
    // const mmYInstance::`vftable' @ 0x61D058

public:
    // 0x4932B0 | ??0mmYInstance@@QAE@XZ
    ARTS_IMPORT mmYInstance();

    // 0x495380 | ??_EmmYInstance@@UAEPAXI@Z
    // 0x495380 | ??_GmmYInstance@@UAEPAXI@Z
    // 0x4932E0 | ??1mmYInstance@@UAE@XZ
    ARTS_IMPORT ~mmYInstance() override = default;

    // 0x4933B0 | ?AddWidgets@mmYInstance@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4932F0 | ?FromMatrix@mmYInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(class Matrix34 const& arg1) override;

    // 0x494B60 | ?GetClass@mmYInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x493390 | ?GetPos@mmYInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT class Vector3& ARTS_FASTCALL GetPos() override;

    // 0x4933A0 | ?SizeOf@mmYInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // 0x493340 | ?ToMatrix@mmYInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) override;

    // 0x494AC0 | ?DeclareFields@mmYInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap14[0x18];
};

check_size(mmYInstance, 0x2C);

class mmStaticInstance : public mmYInstance
{
    // const mmStaticInstance::`vftable' @ 0x61D118

public:
    // 0x4935E0 | ??0mmStaticInstance@@QAE@XZ
    ARTS_IMPORT mmStaticInstance();

    // 0x495500 | ??_EmmStaticInstance@@UAEPAXI@Z
    // 0x493600 | ??1mmStaticInstance@@UAE@XZ
    ARTS_IMPORT ~mmStaticInstance() override = default;

    // 0x494960 | ?AddWidgets@mmStaticInstance@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x494230 | ?Draw@mmStaticInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x4951C0 | ?GetClass@mmStaticInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x493610 | ?Init@mmStaticInstance@@QAEHPADAAVVector3@@1MH0@Z | unused
    ARTS_IMPORT i32 Init(char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, char* arg6);

    // 0x494220 | ?Relight@mmStaticInstance@@UAIXXZ
    ARTS_EXPORT void ARTS_FASTCALL Relight() override;

    // 0x494210 | ?SizeOf@mmStaticInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // 0x495040 | ?DeclareFields@mmStaticInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap2C[0xC];
};

check_size(mmStaticInstance, 0x38);

class mmFacadeInstance final : public mmStaticInstance
{
    // const mmFacadeInstance::`vftable' @ 0x61D178

public:
    // 0x493790 | ??0mmFacadeInstance@@QAE@XZ
    ARTS_IMPORT mmFacadeInstance();

    // 0x495560 | ??_EmmFacadeInstance@@UAEPAXI@Z
    // 0x4937B0 | ??1mmFacadeInstance@@UAE@XZ
    ARTS_IMPORT ~mmFacadeInstance() override = default;

    // 0x494010 | ?Draw@mmFacadeInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x495350 | ?GetClass@mmFacadeInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x493FF0 | ?GetScale@mmFacadeInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // 0x493CC0 | ?InitFacade@mmFacadeInstance@@QAEHPADAAVVector3@@1MHABV2@@Z
    ARTS_IMPORT i32 InitFacade(
        char* arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, i32 arg5, class Vector3 const& arg6);

    // 0x494000 | ?SizeOf@mmFacadeInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // 0x4951D0 | ?DeclareFields@mmFacadeInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap38[0xC];
};

check_size(mmFacadeInstance, 0x44);

struct mmFacadeQuad
{
public:
    // 0x493850 | ??0mmFacadeQuad@@QAE@PAVagiMeshSet@@MM@Z
    ARTS_IMPORT mmFacadeQuad(class agiMeshSet* arg1, f32 arg2, f32 arg3);

    // 0x493B70 | ?DrawLit@mmFacadeQuad@@QAEXP6AXPAEPAI1PAVagiMeshSet@@@Z2@Z
    ARTS_IMPORT void DrawLit(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiMeshSet* arg2);

    // 0x4937C0 | ?DoubleArea@mmFacadeQuad@@SAMPAVagiMeshSet@@@Z
    ARTS_IMPORT static f32 DoubleArea(class agiMeshSet* arg1);

    // 0x493820 | ?Valid@mmFacadeQuad@@SAHPAVagiMeshSet@@@Z
    ARTS_IMPORT static i32 Valid(class agiMeshSet* arg1);

    u8 gap0[0x18];
};

check_size(mmFacadeQuad, 0x18);
