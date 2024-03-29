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
    mmgame:waypoints

    0x42D540 | public: __thiscall mmWaypoints::mmWaypoints(void) | ??0mmWaypoints@@QAE@XZ
    0x42D950 | public: int __thiscall mmWaypoints::BlitzRemove(int) | ?BlitzRemove@mmWaypoints@@QAEHH@Z
    0x42D9D0 | public: int __thiscall mmWaypoints::Init(class mmPlayer *,char *,int,int,int,int) | ?Init@mmWaypoints@@QAEHPAVmmPlayer@@PADHHHH@Z
    0x42DB00 | public: float __thiscall mmWaypoints::GetStartAngle(void) | ?GetStartAngle@mmWaypoints@@QAEMXZ
    0x42DB20 | public: virtual __thiscall mmWaypoints::~mmWaypoints(void) | ??1mmWaypoints@@UAE@XZ
    0x42DC20 | public: int __thiscall mmWaypoints::LoadCSV(char *,int) | ?LoadCSV@mmWaypoints@@QAEHPADH@Z
    0x42E910 | public: virtual void __thiscall mmWaypoints::Cull(void) | ?Cull@mmWaypoints@@UAEXXZ
    0x42E920 | public: void __thiscall mmWaypoints::CalculateGatePoints(class Vector3,float,float,class Vector2 *,class Vector2 *) | ?CalculateGatePoints@mmWaypoints@@QAEXVVector3@@MMPAVVector2@@1@Z
    0x42E9A0 | public: virtual void __thiscall mmWaypoints::Update(void) | ?Update@mmWaypoints@@UAEXXZ
    0x42ED30 | public: void __thiscall mmWaypoints::DeactivateFinish(void) | ?DeactivateFinish@mmWaypoints@@QAEXXZ
    0x42ED50 | public: virtual void __thiscall mmWaypoints::Reset(void) | ?Reset@mmWaypoints@@UAEXXZ
    0x42EE40 | public: void __thiscall mmWaypoints::GetStart(class Vector3 &) | ?GetStart@mmWaypoints@@QAEXAAVVector3@@@Z
    0x42EE80 | public: void __thiscall mmWaypoints::GetWaypoint(int,class Vector3 &) | ?GetWaypoint@mmWaypoints@@QAEXHAAVVector3@@@Z
    0x42EED0 | public: float __thiscall mmWaypoints::GetHeading(int) | ?GetHeading@mmWaypoints@@QAEMH@Z
    0x42EF00 | public: void __thiscall mmWaypoints::GenerateHitRooms(void) | ?GenerateHitRooms@mmWaypoints@@QAEXXZ
    0x42EF60 | public: int __thiscall mmWaypoints::GetHitRoom(int) | ?GetHitRoom@mmWaypoints@@QAEHH@Z
    0x42EF80 | public: void __thiscall mmWaypoints::SetArrow(void) | ?SetArrow@mmWaypoints@@QAEXXZ
    0x42EFA0 | public: void __thiscall mmWaypoints::UpdateWPHUD(void) | ?UpdateWPHUD@mmWaypoints@@QAEXXZ
    0x42F010 | public: void __thiscall mmWaypoints::ResetAllTags(void) | ?ResetAllTags@mmWaypoints@@QAEXXZ
    0x42F050 | public: void __thiscall mmWaypoints::GetClosestWaypoint(void) | ?GetClosestWaypoint@mmWaypoints@@QAEXXZ
    0x42F130 | public: void __thiscall mmWaypoints::CycleCurrentWaypoint(int) | ?CycleCurrentWaypoint@mmWaypoints@@QAEXH@Z
    0x42F1A0 | public: void __thiscall mmWaypoints::GetNextWaypoint(void) | ?GetNextWaypoint@mmWaypoints@@QAEXXZ
    0x42F1B0 | public: void __thiscall mmWaypoints::GetLastWaypoint(void) | ?GetLastWaypoint@mmWaypoints@@QAEXXZ
    0x42F1C0 | public: void __thiscall mmWaypoints::SetCurrentGoals(int) | ?SetCurrentGoals@mmWaypoints@@QAEXH@Z
    0x42F200 | public: int __thiscall mmWaypoints::AIWPHit(int,int,class Matrix34,class Vector3,float) | ?AIWPHit@mmWaypoints@@QAEHHHVMatrix34@@VVector3@@M@Z
    0x42F4C0 | public: int __thiscall mmWaypoints::AnyAIWPHit(unsigned int &,int,class Matrix34,class Vector3,float) | ?AnyAIWPHit@mmWaypoints@@QAEHAAIHVMatrix34@@VVector3@@M@Z
    0x42F820 | public: int __thiscall mmWaypoints::WPHit(int,class Vector3,int,int) | ?WPHit@mmWaypoints@@QAEHHVVector3@@HH@Z
    0x42FAA0 | public: int __thiscall mmWaypoints::AnyWPHits(int) | ?AnyWPHits@mmWaypoints@@QAEHH@Z
    0x42FD50 | public: int __thiscall mmWaypoints::LineIntersect(class Vector2,class Vector2,class Vector2,class Vector2,float) | ?LineIntersect@mmWaypoints@@QAEHVVector2@@000M@Z
    0x42FF60 | public: void __thiscall mmWaypoints::ClearWaypoint(int) | ?ClearWaypoint@mmWaypoints@@QAEXH@Z
    0x430020 | public: void __thiscall mmWaypoints::DisplayHUDMessage(int,int) | ?DisplayHUDMessage@mmWaypoints@@QAEXHH@Z
    0x430170 | public: void __thiscall mmGate::Init(class Vector2,class Vector2) | ?Init@mmGate@@QAEXVVector2@@0@Z
    0x4301F0 | public: float __thiscall mmGate::LineEq(float,float) | ?LineEq@mmGate@@QAEMMM@Z
    0x430210 | public: int __thiscall mmGate::CloseEnough(float,float) | ?CloseEnough@mmGate@@QAEHMM@Z
    0x430250 | public: int __thiscall mmGate::Check(class Vector2,class Vector2) | ?Check@mmGate@@QAEHVVector2@@0@Z
    0x430320 | public: virtual void * __thiscall mmWaypoints::`scalar deleting destructor'(unsigned int) | ??_GmmWaypoints@@UAEPAXI@Z
    0x430320 | public: virtual void * __thiscall mmWaypoints::`vector deleting destructor'(unsigned int) | ??_EmmWaypoints@@UAEPAXI@Z
    0x430350 | public: __thiscall Vector2::Vector2(class Vector2 const &) | ??0Vector2@@QAE@ABV0@@Z
    0x61AF78 | const mmWaypoints::`vftable' | ??_7mmWaypoints@@6B@
    0x6A7788 | class Vector3 Size | ?Size@@3VVector3@@A
*/

#include "arts7/node.h"

class mmPlayer;

class mmWaypoints final : public asNode
{
public:
    // ??0mmWaypoints@@QAE@XZ
    ARTS_IMPORT mmWaypoints();

    // ??_EmmWaypoints@@UAEPAXI@Z
    // ??_GmmWaypoints@@UAEPAXI@Z
    // ??1mmWaypoints@@UAE@XZ
    ARTS_IMPORT ~mmWaypoints() override;

    // ?AIWPHit@mmWaypoints@@QAEHHHVMatrix34@@VVector3@@M@Z
    ARTS_IMPORT i32 AIWPHit(i32 arg1, i32 arg2, Matrix34 arg3, Vector3 arg4, f32 arg5);

    // ?AnyAIWPHit@mmWaypoints@@QAEHAAIHVMatrix34@@VVector3@@M@Z
    ARTS_IMPORT i32 AnyAIWPHit(u32& arg1, i32 arg2, Matrix34 arg3, Vector3 arg4, f32 arg5);

    // ?AnyWPHits@mmWaypoints@@QAEHH@Z
    ARTS_IMPORT i32 AnyWPHits(i32 arg1);

    // ?BlitzRemove@mmWaypoints@@QAEHH@Z
    ARTS_IMPORT i32 BlitzRemove(i32 arg1);

    // ?CalculateGatePoints@mmWaypoints@@QAEXVVector3@@MMPAVVector2@@1@Z
    ARTS_IMPORT void CalculateGatePoints(Vector3 arg1, f32 arg2, f32 arg3, Vector2* arg4, Vector2* arg5);

    // ?ClearWaypoint@mmWaypoints@@QAEXH@Z
    ARTS_IMPORT void ClearWaypoint(i32 arg1);

    // ?Cull@mmWaypoints@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?CycleCurrentWaypoint@mmWaypoints@@QAEXH@Z
    ARTS_IMPORT void CycleCurrentWaypoint(i32 arg1);

    // ?DeactivateFinish@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void DeactivateFinish();

    // ?DisplayHUDMessage@mmWaypoints@@QAEXHH@Z
    ARTS_IMPORT void DisplayHUDMessage(i32 arg1, i32 arg2);

    // ?GenerateHitRooms@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void GenerateHitRooms();

    // ?GetClosestWaypoint@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void GetClosestWaypoint();

    // ?GetHeading@mmWaypoints@@QAEMH@Z
    ARTS_IMPORT f32 GetHeading(i32 arg1);

    // ?GetHitRoom@mmWaypoints@@QAEHH@Z
    ARTS_IMPORT i32 GetHitRoom(i32 arg1);

    // ?GetLastWaypoint@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void GetLastWaypoint();

    // ?GetNextWaypoint@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void GetNextWaypoint();

    // ?GetStart@mmWaypoints@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void GetStart(Vector3& arg1);

    // ?GetStartAngle@mmWaypoints@@QAEMXZ
    ARTS_IMPORT f32 GetStartAngle();

    // ?GetWaypoint@mmWaypoints@@QAEXHAAVVector3@@@Z
    ARTS_IMPORT void GetWaypoint(i32 arg1, Vector3& arg2);

    // ?Init@mmWaypoints@@QAEHPAVmmPlayer@@PADHHHH@Z
    ARTS_IMPORT i32 Init(mmPlayer* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6);

    // ?LineIntersect@mmWaypoints@@QAEHVVector2@@000M@Z
    ARTS_IMPORT i32 LineIntersect(Vector2 arg1, Vector2 arg2, Vector2 arg3, Vector2 arg4, f32 arg5);

    // ?LoadCSV@mmWaypoints@@QAEHPADH@Z
    ARTS_IMPORT i32 LoadCSV(char* arg1, i32 arg2);

    // ?Reset@mmWaypoints@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetAllTags@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void ResetAllTags();

    // ?SetArrow@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void SetArrow();

    // ?SetCurrentGoals@mmWaypoints@@QAEXH@Z
    ARTS_IMPORT void SetCurrentGoals(i32 arg1);

    // ?Update@mmWaypoints@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateWPHUD@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void UpdateWPHUD();

    // ?WPHit@mmWaypoints@@QAEHHVVector3@@HH@Z
    ARTS_IMPORT i32 WPHit(i32 arg1, Vector3 arg2, i32 arg3, i32 arg4);

    u8 gap20[0x8C];
};

check_size(mmWaypoints, 0xAC);

struct mmGate
{
public:
    // ?Check@mmGate@@QAEHVVector2@@0@Z | unused
    ARTS_IMPORT i32 Check(Vector2 arg1, Vector2 arg2);

    // ?CloseEnough@mmGate@@QAEHMM@Z
    ARTS_IMPORT i32 CloseEnough(f32 arg1, f32 arg2);

    // ?Init@mmGate@@QAEXVVector2@@0@Z | unused
    ARTS_IMPORT void Init(Vector2 arg1, Vector2 arg2);

    // ?LineEq@mmGate@@QAEMMM@Z
    ARTS_IMPORT f32 LineEq(f32 arg1, f32 arg2);

    u8 gap0[0x18];
};

check_size(mmGate, 0x18);

// ?Size@@3VVector3@@A
ARTS_IMPORT extern Vector3 Size;
