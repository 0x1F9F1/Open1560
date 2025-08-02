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
    mmphysics:phys

    0x4D3DA0 | public: void __thiscall mmPhysExec::DoUpdateAll(void) | ?DoUpdateAll@mmPhysExec@@QAEXXZ
    0x4D3FF0 | public: void __thiscall mmPhysExec::DoUpdatePlayerOnly(void) | ?DoUpdatePlayerOnly@mmPhysExec@@QAEXXZ
    0x4D42A0 | public: __thiscall mmPhysicsMGR::mmPhysicsMGR(void) | ??0mmPhysicsMGR@@QAE@XZ
    0x4D43A0 | public: virtual __thiscall mmPhysicsMGR::~mmPhysicsMGR(void) | ??1mmPhysicsMGR@@UAE@XZ
    0x4D4430 | public: void __thiscall mmPhysicsMGR::Init(class asInertialCS *,class mmViewCS *) | ?Init@mmPhysicsMGR@@QAEXPAVasInertialCS@@PAVmmViewCS@@@Z
    0x4D44D0 | public: virtual void __thiscall mmPhysicsMGR::Reset(void) | ?Reset@mmPhysicsMGR@@UAEXXZ
    0x4D4520 | public: void __thiscall mmPhysicsMGR::Shutdown(void) | ?Shutdown@mmPhysicsMGR@@QAEXXZ
    0x4D4540 | public: void __thiscall mmPhysicsMGR::DeclareMover(class mmInstance *,int,int) | ?DeclareMover@mmPhysicsMGR@@QAEXPAVmmInstance@@HH@Z
    0x4D4740 | public: void __thiscall mmPhysicsMGR::NewMover(class mmInstance *,class mmInstance *) | ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@0@Z
    0x4D4840 | public: void __thiscall mmPhysicsMGR::NewMover(class mmInstance *) | ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@@Z
    0x4D48C0 | public: void __thiscall mmPhysicsMGR::NewMover(class mmInstance *,class mmInstance *,class mmInstance *) | ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@00@Z
    0x4D49E0 | public: void __thiscall mmPhysicsMGR::IgnoreMover(class mmInstance *) | ?IgnoreMover@mmPhysicsMGR@@QAEXPAVmmInstance@@@Z
    0x4D4A30 | protected: void __thiscall mmPhysicsMGR::GatherRoomCollidables(int,short,int) | ?GatherRoomCollidables@mmPhysicsMGR@@IAEXHFH@Z
    0x4D4B50 | protected: int __thiscall mmPhysicsMGR::ClosestNeighboringCullRoom(int) | ?ClosestNeighboringCullRoom@mmPhysicsMGR@@IAEHH@Z
    0x4D4CA0 | protected: void __thiscall mmPhysicsMGR::GatherCollidables(int,int) | ?GatherCollidables@mmPhysicsMGR@@IAEXHH@Z
    0x4D4D00 | public: void __thiscall mmPhysicsMGR::UpdateEverythingButPlayer(void) | ?UpdateEverythingButPlayer@mmPhysicsMGR@@QAEXXZ
    0x4D4F40 | public: virtual void __thiscall mmPhysicsMGR::Update(void) | ?Update@mmPhysicsMGR@@UAEXXZ
    0x4D52F0 | public: virtual void __thiscall mmPhysicsMGR::UpdatePaused(void) | ?UpdatePaused@mmPhysicsMGR@@UAEXXZ
    0x4D5320 | protected: void __thiscall mmPhysicsMGR::DeclareBound(class mmBoundTemplate *) | ?DeclareBound@mmPhysicsMGR@@IAEXPAVmmBoundTemplate@@@Z
    0x4D5390 | public: virtual void __thiscall mmPhysicsMGR::Cull(void) | ?Cull@mmPhysicsMGR@@UAEXXZ
    0x4D5520 | protected: void __thiscall mmPhysicsMGR::Stats(void) | ?Stats@mmPhysicsMGR@@IAEXXZ
    0x4D5730 | protected: int __thiscall mmPhysicsMGR::TrivialCollideInstances(class mmInstance *,class mmInstance *) | ?TrivialCollideInstances@mmPhysicsMGR@@IAEHPAVmmInstance@@0@Z
    0x4D5950 | protected: int __thiscall mmPhysicsMGR::CollideInstances(class mmInstance *,class mmInstance *,int,int) | ?CollideInstances@mmPhysicsMGR@@IAEHPAVmmInstance@@0HH@Z
    0x4D5DF0 | protected: void __thiscall mmPhysicsMGR::CollideTerrain(class mmInstance *) | ?CollideTerrain@mmPhysicsMGR@@IAEXPAVmmInstance@@@Z
    0x4D62D0 | protected: int __thiscall mmPhysicsMGR::CollideProbe(short,class mmIntersection *,int) | ?CollideProbe@mmPhysicsMGR@@IAEHFPAVmmIntersection@@H@Z
    0x4D6460 | public: int __thiscall mmPhysicsMGR::Collide(class mmIntersection *,int,short,short) | ?Collide@mmPhysicsMGR@@QAEHPAVmmIntersection@@HFF@Z
    0x4D6580 | public: int __thiscall mmPhysicsMGR::CollideLOS(class mmIntersection *,int,short,short) | ?CollideLOS@mmPhysicsMGR@@QAEHPAVmmIntersection@@HFF@Z
    0x4D66E0 | int __cdecl FindIntersections(class mmIntersection *,int,class asBound *,class asBound *,class mmBoundTemplate *,class mmBoundTemplate *,class mmEdgeBodyIsect *,int,class mmEdgeBodyIsect *,int) | ?FindIntersections@@YAHPAVmmIntersection@@HPAVasBound@@1PAVmmBoundTemplate@@2PAVmmEdgeBodyIsect@@H3H@Z
    0x4D7B10 | void __cdecl DoEndPtSearch(int,class Vector3 const &,class mmEdgeBodyIsect *,int,class mmIntersection * *,int *,int) | ?DoEndPtSearch@@YAXHABVVector3@@PAVmmEdgeBodyIsect@@HPAPAVmmIntersection@@PAHH@Z
    0x4D8130 | void __cdecl DoEdgeEdge(class mmEdgeBodyIsect *,class mmIntersection * *,int *,int) | ?DoEdgeEdge@@YAXPAVmmEdgeBodyIsect@@PAPAVmmIntersection@@PAHH@Z
    0x4D8210 | void __cdecl SegSegDistNorm(class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 *,class Vector3 *,class Vector3 *,float *,int *) | ?SegSegDistNorm@@YAXABVVector3@@00000PAV1@11PAMPAH@Z
    0x4D8730 | int __cdecl GetCollidePolyEdge(class Vector3 const &,class mmPolygon *,class mmBoundTemplate *,class asInertialCS *,class Vector3 const &,float,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 *,class Vector3 *,float *,int *,int *) | ?GetCollidePolyEdge@@YAHABVVector3@@PAVmmPolygon@@PAVmmBoundTemplate@@PAVasInertialCS@@0M0000PAV1@4PAMPAH6@Z
    0x4D8E00 | public: virtual void __thiscall mmPhysicsMGR::AddWidgets(class Bank *) | ?AddWidgets@mmPhysicsMGR@@UAEXPAVBank@@@Z
    0x4D8EF0 | public: static void __cdecl mmPhysicsMGR::DeclareFields(void) | ?DeclareFields@mmPhysicsMGR@@SAXXZ
    0x4D9070 | public: virtual class MetaClass * __thiscall mmPhysicsMGR::GetClass(void) | ?GetClass@mmPhysicsMGR@@UAEPAVMetaClass@@XZ
    0x4D9080 | public: class Vector3 __thiscall Vector3::operator/(float) const | ??KVector3@@QBE?AV0@M@Z
    0x4D90C0 | int __cdecl testNoOverlap(float,float) | ?testNoOverlap@@YAHMM@Z
    0x4D9130 | public: virtual void * __thiscall mmPhysicsMGR::`vector deleting destructor'(unsigned int) | ??_EmmPhysicsMGR@@UAEPAXI@Z
    0x4D9190 | public: virtual void __thiscall mmPhysExec::Update(void) | ?Update@mmPhysExec@@UAEXXZ
    0x4D91B0 | public: virtual void * __thiscall mmPhysExec::`vector deleting destructor'(unsigned int) | ??_EmmPhysExec@@UAEPAXI@Z
    0x4D91B0 | public: virtual void * __thiscall mmPhysExec::`scalar deleting destructor'(unsigned int) | ??_GmmPhysExec@@UAEPAXI@Z
    0x4D91E0 | public: virtual __thiscall mmPhysExec::~mmPhysExec(void) | ??1mmPhysExec@@UAE@XZ
    0x61F998 | const mmPhysicsMGR::`vftable' | ??_7mmPhysicsMGR@@6B@
    0x61F9D8 | const mmPhysExec::`vftable' | ??_7mmPhysExec@@6B@
    0x643E6C | int CallImpactCallbacks | ?CallImpactCallbacks@@3HA
    0x7086C0 | class mmEdgeBodyIsect * EBISECTS | ?EBISECTS@@3PAVmmEdgeBodyIsect@@A
    0x70A548 | class MetaClass mmPhysicsMGRMetaClass | ?mmPhysicsMGRMetaClass@@3VMetaClass@@A
    0x716F70 | protected: static class mmPhysicsMGR * mmPhysicsMGR::Instance | ?Instance@mmPhysicsMGR@@1PAV1@A
    0x716F80 | unsigned long ImpactTime | ?ImpactTime@@3KA
    0x716F88 | float PhysUpdate | ?PhysUpdate@@3MA
    0x716F90 | class mmIntersection * ISECTS | ?ISECTS@@3PAVmmIntersection@@A
    0x718590 | unsigned long physTerrainCollisions | ?physTerrainCollisions@@3KA
    0x718698 | class mmPhysicsMGR PHYS | ?PHYS@@3VmmPhysicsMGR@@A
    0x7188BC | unsigned long ImpactCallbackTime | ?ImpactCallbackTime@@3KA
    0x7188C0 | unsigned long physCollisions | ?physCollisions@@3KA
    0x7190D0 | unsigned long physUpdate | ?physUpdate@@3KA
*/

#include "arts7/node.h"

#include "osample.h"

class asBound;
class asInertialCS;
class mmBoundTemplate;
class mmEdgeBodyIsect;
class mmInstance;
class mmInstChain;
class mmIntersection;
class mmPolygon;
class mmViewCS;

class mmPhysExec final : public asNode
{
public:
    // ??_GmmPhysExec@@UAEPAXI@Z
    // ??_EmmPhysExec@@UAEPAXI@Z
    // ??1mmPhysExec@@UAE@XZ | inline
    ARTS_EXPORT ~mmPhysExec() override = default;

    // ?DoUpdateAll@mmPhysExec@@QAEXXZ
    ARTS_IMPORT void DoUpdateAll();

    // ?DoUpdatePlayerOnly@mmPhysExec@@QAEXXZ
    ARTS_IMPORT void DoUpdatePlayerOnly();

    // ?Update@mmPhysExec@@UAEXXZ | inline
    ARTS_EXPORT void Update() override;

    b32 OnlyPlayer {};
};

check_size(mmPhysExec, 0x24);

#define MOVER_TYPE_PERM 1 // Vehicles, plus a few broken bits
#define MOVER_TYPE_TEMP 2 // Props, Disappears if not inside an active room
#define MOVER_TYPE_10 10  // mmNetObject mmTrailerInstance

#define MOVER_FLAG_ACTIVE 0x1          // Do Update/PostUpdate
#define MOVER_FLAG_COLLIDE_TERRAIN 0x2 // Collide with terrain
#define MOVER_FLAG_COLLIDE_MOVERS 0x8  // Collide with other movers
#define MOVER_FLAG_20 0x20             // Collide with INST_FLAG_800, implies MOVER_FLAG_COLLIDE_MOVERS
#define MOVER_FLAG_PLAYER 0x40         // Is attached to player

#define PHYS_COLLIDE_ROOM 1
#define PHYS_COLLIDE_HITID 2

// https://web.archive.org/web/20131114044954/http://www.gamasutra.com/view/feature/131315/what_a_designers_should_know_about_.php?print=1

class mmPhysicsMGR final : public asNode
{
public:
    // ??0mmPhysicsMGR@@QAE@XZ
    ARTS_IMPORT mmPhysicsMGR();

    // ??_EmmPhysicsMGR@@UAEPAXI@Z
    // ??1mmPhysicsMGR@@UAE@XZ
    ARTS_IMPORT ~mmPhysicsMGR() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmPhysicsMGR@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // type = PHYS_COLLIDE_*
    // ?Collide@mmPhysicsMGR@@QAEHPAVmmIntersection@@HFF@Z
    ARTS_IMPORT i32 Collide(mmIntersection* isect, i32 type, i16 room_id = 0, i16 arg4 = 0);

    // ?CollideLOS@mmPhysicsMGR@@QAEHPAVmmIntersection@@HFF@Z
    ARTS_IMPORT i32 CollideLOS(mmIntersection* arg1, i32 arg2, i16 arg3, i16 arg4);

    // ?Cull@mmPhysicsMGR@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?DeclareMover@mmPhysicsMGR@@QAEXPAVmmInstance@@HH@Z
    ARTS_IMPORT void DeclareMover(mmInstance* arg1, i32 type, i32 flags);

    // ?GetClass@mmPhysicsMGR@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?IgnoreMover@mmPhysicsMGR@@QAEXPAVmmInstance@@@Z
    ARTS_EXPORT void IgnoreMover(mmInstance* inst);

    // ?Init@mmPhysicsMGR@@QAEXPAVasInertialCS@@PAVmmViewCS@@@Z
    ARTS_IMPORT void Init(asInertialCS* arg1, mmViewCS* arg2);

    // ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@@Z
    ARTS_IMPORT void NewMover(mmInstance* arg1);

    // ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@0@Z
    ARTS_IMPORT void NewMover(mmInstance* arg1, mmInstance* arg2);

    // ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@00@Z
    ARTS_IMPORT void NewMover(mmInstance* arg1, mmInstance* arg2, mmInstance* arg3);

    // ?Reset@mmPhysicsMGR@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Shutdown@mmPhysicsMGR@@QAEXXZ
    ARTS_IMPORT void Shutdown();

    // ?Update@mmPhysicsMGR@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateEverythingButPlayer@mmPhysicsMGR@@QAEXXZ
    ARTS_IMPORT void UpdateEverythingButPlayer();

    // ?UpdatePaused@mmPhysicsMGR@@UAEXXZ
    ARTS_IMPORT void UpdatePaused() override;

    // ?DeclareFields@mmPhysicsMGR@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    void SetGravity(f32 gravity)
    {
        Gravity = gravity;
    }

    f32 GetGravity() const
    {
        return Gravity;
    }

    asInertialCS* GetPlayerICS()
    {
        return PlayerICS;
    }

protected:
    // ?ClosestNeighboringCullRoom@mmPhysicsMGR@@IAEHH@Z
    ARTS_IMPORT i32 ClosestNeighboringCullRoom(i32 arg1);

    // ?CollideInstances@mmPhysicsMGR@@IAEHPAVmmInstance@@0HH@Z
    ARTS_IMPORT i32 CollideInstances(mmInstance* arg1, mmInstance* arg2, i32 arg3, i32 arg4);

    // ?CollideProbe@mmPhysicsMGR@@IAEHFPAVmmIntersection@@H@Z
    ARTS_EXPORT b32 CollideProbe(i16 room, mmIntersection* isect, i32 flags);

    // ?CollideTerrain@mmPhysicsMGR@@IAEXPAVmmInstance@@@Z
    ARTS_IMPORT void CollideTerrain(mmInstance* arg1);

    // ?DeclareBound@mmPhysicsMGR@@IAEXPAVmmBoundTemplate@@@Z
    ARTS_IMPORT void DeclareBound(mmBoundTemplate* arg1);

    // ?GatherCollidables@mmPhysicsMGR@@IAEXHH@Z
    ARTS_IMPORT void GatherCollidables(i32 arg1, i32 arg2);

    // ?GatherRoomCollidables@mmPhysicsMGR@@IAEXHFH@Z
    ARTS_IMPORT void GatherRoomCollidables(i32 arg1, i16 arg2, i32 arg3);

#ifdef ARTS_DEV_BUILD
    // ?Stats@mmPhysicsMGR@@IAEXXZ
    ARTS_IMPORT void Stats();
#endif

    // ?TrivialCollideInstances@mmPhysicsMGR@@IAEHPAVmmInstance@@0@Z
    ARTS_IMPORT i32 TrivialCollideInstances(mmInstance* arg1, mmInstance* arg2);

    // ?Instance@mmPhysicsMGR@@1PAV1@A
    ARTS_IMPORT static mmPhysicsMGR* Instance;

private:
    i32 field_20;
    asInertialCS* PlayerICS;
    mmInstance* PlayerInst;
    i32 ReduceOversampling;
    f32 Gravity;
    i32 field_34;

    // DeclareBound
    i32 NumBounds;
    mmBoundTemplate* Bounds[64];

    i32 CylinderCollisions;
    mmPhysExec PhysExec;
    asOverSample OverSample;
    mmViewCS* PlayerVCS;

    i16 ActiveRooms[64];
    i16 NumActiveRooms;

    i16 field_21A;
    mmBoundTemplate* HitIdBound;
    mmInstChain* ObjectsChain;
};

check_size(mmPhysicsMGR, 0x224);

// ?DoEdgeEdge@@YAXPAVmmEdgeBodyIsect@@PAPAVmmIntersection@@PAHH@Z
ARTS_IMPORT void DoEdgeEdge(mmEdgeBodyIsect* arg1, mmIntersection** arg2, i32* arg3, i32 arg4);

// ?DoEndPtSearch@@YAXHABVVector3@@PAVmmEdgeBodyIsect@@HPAPAVmmIntersection@@PAHH@Z
ARTS_IMPORT void DoEndPtSearch(
    i32 arg1, const Vector3& arg2, mmEdgeBodyIsect* arg3, i32 arg4, mmIntersection** arg5, i32* arg6, i32 arg7);

// ?FindIntersections@@YAHPAVmmIntersection@@HPAVasBound@@1PAVmmBoundTemplate@@2PAVmmEdgeBodyIsect@@H3H@Z
ARTS_IMPORT i32 FindIntersections(mmIntersection* arg1, i32 arg2, asBound* arg3, asBound* arg4, mmBoundTemplate* arg5,
    mmBoundTemplate* arg6, mmEdgeBodyIsect* arg7, i32 arg8, mmEdgeBodyIsect* arg9, i32 arg10);

// ?GetCollidePolyEdge@@YAHABVVector3@@PAVmmPolygon@@PAVmmBoundTemplate@@PAVasInertialCS@@0M0000PAV1@4PAMPAH6@Z
ARTS_IMPORT i32 GetCollidePolyEdge(const Vector3& arg1, mmPolygon* arg2, mmBoundTemplate* arg3, asInertialCS* arg4,
    const Vector3& arg5, f32 arg6, const Vector3& arg7, const Vector3& arg8, const Vector3& arg9, const Vector3& arg10,
    Vector3* arg11, Vector3* arg12, f32* arg13, i32* arg14, i32* arg15);

// ?SegSegDistNorm@@YAXABVVector3@@00000PAV1@11PAMPAH@Z
ARTS_IMPORT void SegSegDistNorm(const Vector3& arg1, const Vector3& arg2, const Vector3& arg3, const Vector3& arg4,
    const Vector3& arg5, const Vector3& arg6, Vector3* arg7, Vector3* arg8, Vector3* arg9, f32* arg10, i32* arg11);

// ?testNoOverlap@@YAHMM@Z | inline
ARTS_IMPORT i32 testNoOverlap(f32 arg1, f32 arg2);

// ?CallImpactCallbacks@@3HA
ARTS_IMPORT extern i32 CallImpactCallbacks;

// ?EBISECTS@@3PAVmmEdgeBodyIsect@@A
ARTS_IMPORT extern mmEdgeBodyIsect EBISECTS[32];

// ?ISECTS@@3PAVmmIntersection@@A
ARTS_IMPORT extern mmIntersection ISECTS[32];

#ifdef ARTS_DEV_BUILD
// ?ImpactCallbackTime@@3KA
ARTS_IMPORT extern ulong ImpactCallbackTime;

// ?ImpactTime@@3KA
ARTS_IMPORT extern ulong ImpactTime;
#endif

// ?PHYS@@3VmmPhysicsMGR@@A
ARTS_IMPORT extern mmPhysicsMGR PHYS;

// ?PhysUpdate@@3MA
ARTS_IMPORT extern f32 PhysUpdate;

#ifdef ARTS_DEV_BUILD
// ?physCollisions@@3KA
ARTS_IMPORT extern ulong physCollisions;

// ?physTerrainCollisions@@3KA
ARTS_IMPORT extern ulong physTerrainCollisions;

// ?physUpdate@@3KA
ARTS_IMPORT extern ulong physUpdate;
#endif
