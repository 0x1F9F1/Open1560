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
    mmai:aiMap

    0x433E50 | public: class aiPath * __thiscall aiMap::Path(int) | ?Path@aiMap@@QAEPAVaiPath@@H@Z
    0x433E80 | public: class aiIntersection * __thiscall aiMap::Intersection(int) | ?Intersection@aiMap@@QAEPAVaiIntersection@@H@Z
    0x433EB0 | public: class aiVehicleAmbient * __thiscall aiMap::Vehicle(int) | ?Vehicle@aiMap@@QAEPAVaiVehicleAmbient@@H@Z
    0x433EF0 | public: class aiVehiclePolice * __thiscall aiMap::Police(int) | ?Police@aiMap@@QAEPAVaiVehiclePolice@@H@Z
    0x433F30 | public: class aiVehicleOpponent * __thiscall aiMap::Opponent(int) | ?Opponent@aiMap@@QAEPAVaiVehicleOpponent@@H@Z
    0x433F70 | public: class aiPedestrian * __thiscall aiMap::Pedestrian(int) | ?Pedestrian@aiMap@@QAEPAVaiPedestrian@@H@Z
    0x433FB0 | public: class Vector3 & __thiscall aiMap::PlayerPos(void) | ?PlayerPos@aiMap@@QAEAAVVector3@@XZ
    0x433FC0 | public: __thiscall aiMap::aiMap(void) | ??0aiMap@@QAE@XZ
    0x433FE0 | public: virtual __thiscall aiMap::~aiMap(void) | ??1aiMap@@UAE@XZ
    0x433FF0 | public: void __thiscall aiMap::Clean(void) | ?Clean@aiMap@@QAEXXZ
    0x434220 | public: void __thiscall aiMap::Init(char *,char *,char *,class mmCar *) | ?Init@aiMap@@QAEXPAD00PAVmmCar@@@Z
    0x435770 | public: void __thiscall aiMap::Stats(void) | ?Stats@aiMap@@QAEXXZ
    0x435830 | private: void __thiscall aiMap::SaveBinary(char *) | ?SaveBinary@aiMap@@AAEXPAD@Z
    0x4359B0 | private: void __thiscall aiMap::ReadBinary(char *) | ?ReadBinary@aiMap@@AAEXPAD@Z
    0x435FB0 | public: virtual void __thiscall aiMap::Reset(void) | ?Reset@aiMap@@UAEXXZ
    0x4362F0 | public: virtual void __thiscall aiMap::Update(void) | ?Update@aiMap@@UAEXXZ
    0x436670 | public: virtual void __thiscall aiMap::UpdatePaused(void) | ?UpdatePaused@aiMap@@UAEXXZ
    0x436680 | public: virtual void __thiscall aiMap::Cull(void) | ?Cull@aiMap@@UAEXXZ
    0x436CD0 | public: void __thiscall aiMap::DrawNextVisibleAmbient(void) | ?DrawNextVisibleAmbient@aiMap@@QAEXXZ
    0x436CF0 | public: void __thiscall aiMap::AllwaysGreen(void) | ?AllwaysGreen@aiMap@@QAEXXZ
    0x436D30 | public: void __thiscall aiMap::AllwaysRed(void) | ?AllwaysRed@aiMap@@QAEXXZ
    0x436D70 | public: void __thiscall aiMap::DrawAppRoads(void) | ?DrawAppRoads@aiMap@@QAEXXZ
    0x436D90 | public: int __thiscall aiMap::MapComponent(class Vector3 &,short *,short *,short) | ?MapComponent@aiMap@@QAEHAAVVector3@@PAF1F@Z
    0x436F10 | public: int __thiscall aiMap::DetermineRoadPosInfo(class Matrix34 &,class aiRailSet *,short *,float *,short *,float *,int) | ?DetermineRoadPosInfo@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAFPAM23H@Z
    0x4370B0 | public: int __thiscall aiMap::DeterminePerpMapComponent(class Matrix34 &,class aiRailSet *,short *,short *,float *,float *,short *) | ?DeterminePerpMapComponent@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAF2PAM32@Z
    0x437310 | public: int __thiscall aiMap::DetermineOppMapComponent(class Matrix34 &,class aiRailSet *,short *,short *,float *,float *,short *,float *,float,short,short) | ?DetermineOppMapComponent@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAF2PAM323MFF@Z
    0x438CB0 | public: int __thiscall aiMap::DetermineOppRoadPosInfo(class Vector3 &,class Vector3 &,class aiRailSet *,short *,float *,float *,int) | ?DetermineOppRoadPosInfo@aiMap@@QAEHAAVVector3@@0PAVaiRailSet@@PAFPAM3H@Z
    0x438D90 | public: int __thiscall aiMap::FindAmbAppRoad(int) | ?FindAmbAppRoad@aiMap@@QAEHH@Z
    0x438DE0 | public: int __thiscall aiMap::FindPedAppRoad(int) | ?FindPedAppRoad@aiMap@@QAEHH@Z
    0x438E30 | public: class aiPath * __thiscall aiMap::PredictIntersectionPath(int,class Matrix34 &) | ?PredictIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    0x439010 | public: class aiPath * __thiscall aiMap::PredictAmbIntersectionPath(int,class Matrix34 &) | ?PredictAmbIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    0x4391F0 | public: class aiPath * __thiscall aiMap::PredictAmbFreewayIntersectionPath(int,class Matrix34 &) | ?PredictAmbFreewayIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    0x439400 | public: void __thiscall aiMap::Dump(void) | ?Dump@aiMap@@QAEXXZ
    0x439540 | public: void __thiscall aiMap::GetCameraPos(void) | ?GetCameraPos@aiMap@@QAEXXZ
    0x439570 | private: class aiPath * __thiscall aiMap::AddAIPath(class mmRoadSect &,int,int) | ?AddAIPath@aiMap@@AAEPAVaiPath@@AAVmmRoadSect@@HH@Z
    0x439670 | public: class aiIntersection * __thiscall aiMap::AddIntersection(class Vector3 *) | ?AddIntersection@aiMap@@QAEPAVaiIntersection@@PAVVector3@@@Z
    0x4396A0 | private: class aiIntersection * __thiscall aiMap::ScanIntersections(class Vector3 &) | ?ScanIntersections@aiMap@@AAEPAVaiIntersection@@AAVVector3@@@Z
    0x439720 | private: class aiIntersection * __thiscall aiMap::NewIntersection(class Vector3 &) | ?NewIntersection@aiMap@@AAEPAVaiIntersection@@AAVVector3@@@Z
    0x439800 | private: void __thiscall aiMap::CreateAmbAppRoadMap(void) | ?CreateAmbAppRoadMap@aiMap@@AAEXXZ
    0x439D80 | private: void __thiscall aiMap::CreatePedAppRoadMap(void) | ?CreatePedAppRoadMap@aiMap@@AAEXXZ
    0x43A300 | private: void __thiscall aiMap::AddIntToAppRoadMap(class CArrayList *,int,float,struct asPortalCell * *,int) | ?AddIntToAppRoadMap@aiMap@@AAEXPAVCArrayList@@HMPAPAUasPortalCell@@H@Z
    0x43A380 | private: float __thiscall aiMap::RoadDensity(int,float,int) | ?RoadDensity@aiMap@@AAEMHMH@Z
    0x43A3D0 | private: int __thiscall aiMap::NumCars(int,float,float) | ?NumCars@aiMap@@AAEHHMM@Z
    0x43A400 | private: int __thiscall aiMap::FindRoad(class CArrayList *,int) | ?FindRoad@aiMap@@AAEHPAVCArrayList@@H@Z
    0x43A440 | public: int __thiscall aiMap::ChooseNextRandomLink(class aiRailSet *) | ?ChooseNextRandomLink@aiMap@@QAEHPAVaiRailSet@@@Z
    0x43A5D0 | public: int __thiscall aiMap::ChooseNextLeftStraightLink(class aiRailSet *) | ?ChooseNextLeftStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    0x43A840 | public: int __thiscall aiMap::ChooseNextRightStraightLink(class aiRailSet *) | ?ChooseNextRightStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    0x43AAE0 | public: int __thiscall aiMap::ChooseNextStraightLink(class aiRailSet *) | ?ChooseNextStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    0x43ADF0 | public: int __thiscall aiMap::ChooseNextLaneLink(class aiRailSet *) | ?ChooseNextLaneLink@aiMap@@QAEHPAVaiRailSet@@@Z
    0x43AE90 | public: int __thiscall aiMap::ChooseNextFreewayLink(class aiRailSet *) | ?ChooseNextFreewayLink@aiMap@@QAEHPAVaiRailSet@@@Z
    0x43AFA0 | public: int __thiscall aiMap::ChooseNextRightStraightFreewayLink(class aiRailSet *) | ?ChooseNextRightStraightFreewayLink@aiMap@@QAEHPAVaiRailSet@@@Z
    0x43B160 | private: void __thiscall aiMap::AdjustPedestrians(int,int) | ?AdjustPedestrians@aiMap@@AAEXHH@Z
    0x43B500 | public: void __thiscall aiMap::AddPedestrian(class aiPedestrian *) | ?AddPedestrian@aiMap@@QAEXPAVaiPedestrian@@@Z
    0x43B530 | public: void __thiscall aiMap::RemovePedestrian(class aiPedestrian *) | ?RemovePedestrian@aiMap@@QAEXPAVaiPedestrian@@@Z
    0x43B5A0 | private: void __thiscall aiMap::AdjustAmbients(int,int) | ?AdjustAmbients@aiMap@@AAEXHH@Z
    0x43BA60 | public: void __thiscall aiMap::AddAmbient(class aiVehicleSpline *) | ?AddAmbient@aiMap@@QAEXPAVaiVehicleSpline@@@Z
    0x43BAA0 | public: void __thiscall aiMap::RemoveAmbient(class aiVehicleSpline *) | ?RemoveAmbient@aiMap@@QAEXPAVaiVehicleSpline@@@Z
    0x43BB10 | public: class aiPath * __thiscall aiMap::DetRdSegBetweenInts(class aiIntersection *,class aiIntersection *) | ?DetRdSegBetweenInts@aiMap@@QAEPAVaiPath@@PAVaiIntersection@@0@Z
    0x43BB90 | public: int __thiscall aiMap::GoodRoadForCopStartPos(int) | ?GoodRoadForCopStartPos@aiMap@@QAEHH@Z
    0x43BBE0 | public: virtual void __thiscall aiMap::AddWidgets(class Bank *) | ?AddWidgets@aiMap@@UAEXPAVBank@@@Z
    0x43BC20 | public: static void __cdecl aiMap::DeclareFields(void) | ?DeclareFields@aiMap@@SAXXZ
    0x43BD90 | public: virtual class MetaClass * __thiscall aiMap::GetClass(void) | ?GetClass@aiMap@@UAEPAVMetaClass@@XZ
    0x43BEF0 | public: void * __thiscall aiVehicleAmbient::`vector deleting destructor'(unsigned int) | ??_EaiVehicleAmbient@@QAEPAXI@Z
    0x43BF50 | public: void * __thiscall aiVehiclePolice::`vector deleting destructor'(unsigned int) | ??_EaiVehiclePolice@@QAEPAXI@Z
    0x43BFB0 | public: void * __thiscall aiVehicleOpponent::`vector deleting destructor'(unsigned int) | ??_EaiVehicleOpponent@@QAEPAXI@Z
    0x43C010 | public: void * __thiscall aiPedestrian::`vector deleting destructor'(unsigned int) | ??_EaiPedestrian@@QAEPAXI@Z
    0x43C070 | public: void * __thiscall CArrayList::`vector deleting destructor'(unsigned int) | ??_ECArrayList@@QAEPAXI@Z
    0x43C0D0 | float __cdecl Clamp(float,float,float) | ?Clamp@@YAMMMM@Z
    0x43C100 | public: __thiscall Vector3::Vector3(float,float,float) | ??0Vector3@@QAE@MMM@Z
    0x43C120 | public: virtual void * __thiscall aiMap::`vector deleting destructor'(unsigned int) | ??_EaiMap@@UAEPAXI@Z
    0x43C180 | public: __thiscall CArrayList::CArrayList(void) | ??0CArrayList@@QAE@XZ
    0x43C190 | public: virtual __thiscall mmRoadSide::~mmRoadSide(void) | ??1mmRoadSide@@UAE@XZ
    0x43C220 | public: virtual void * __thiscall mmRoadSide::`scalar deleting destructor'(unsigned int) | ??_GmmRoadSide@@UAEPAXI@Z
    0x43C250 | public: virtual __thiscall mmRoadSect::~mmRoadSect(void) | ??1mmRoadSect@@UAE@XZ
    0x43C360 | public: virtual void * __thiscall mmRoadSect::`scalar deleting destructor'(unsigned int) | ??_GmmRoadSect@@UAEPAXI@Z
    0x61B298 | const aiMap::`vftable' | ??_7aiMap@@6B@
    0x61B2D8 | const mmRoadSide::`vftable' | ??_7mmRoadSide@@6B@
    0x61B2F0 | const mmRoadSect::`vftable' | ??_7mmRoadSect@@6B@
    0x6A7830 | float _fPedUpdate | ?_fPedUpdate@@3MA
    0x6A7834 | float _fAmbientUpdate | ?_fAmbientUpdate@@3MA
    0x6A7838 | float _fCopUpdate | ?_fCopUpdate@@3MA
    0x6A7840 | int _nPedQty | ?_nPedQty@@3HA
    0x6A7848 | class aiMap AIMAP | ?AIMAP@@3VaiMap@@A
    0x6A7908 | class MetaClass aiMapMetaClass | ?aiMapMetaClass@@3VMetaClass@@A
    0x6A7934 | int _nRdQty | ?_nRdQty@@3HA
    0x6A7938 | float _fOppUpdate | ?_fOppUpdate@@3MA
    0x6A793C | int _nAmbientQty | ?_nAmbientQty@@3HA
    0x6A7948 | float _fTotUpdate | ?_fTotUpdate@@3MA
*/

#include "arts7/node.h"

#include "vector7/vector3.h"

class aiIntersection;
class aiPath;
class aiPedestrian;
class aiPoliceForce;
class aiRaceData;
class aiRailSet;
class aiVehicleAmbient;
class aiVehicleManager;
class aiVehicleOpponent;
class aiVehiclePolice;
class aiVehicleSpline;
class CArrayList;
class mmCar;
class mmRoadSect;
struct asPortalCell;

// https://web.archive.org/web/20120511074218/http://www.gamasutra.com/view/feature/131515/ai_madness_using_ai_to_bring_.php?print=1

class aiMap final : public asNode
{
public:
    // ??0aiMap@@QAE@XZ
    ARTS_IMPORT aiMap();

    // ??_EaiMap@@UAEPAXI@Z
    // ??1aiMap@@UAE@XZ
    ARTS_EXPORT ~aiMap() override = default;

    // ?AddAmbient@aiMap@@QAEXPAVaiVehicleSpline@@@Z
    ARTS_IMPORT void AddAmbient(aiVehicleSpline* arg1);

    // ?AddIntersection@aiMap@@QAEPAVaiIntersection@@PAVVector3@@@Z
    ARTS_IMPORT aiIntersection* AddIntersection(Vector3* arg1);

    // ?AddPedestrian@aiMap@@QAEXPAVaiPedestrian@@@Z
    ARTS_IMPORT void AddPedestrian(aiPedestrian* arg1);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiMap@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* bank) override;
#endif

    // ?AllwaysGreen@aiMap@@QAEXXZ | unused
    ARTS_IMPORT void AllwaysGreen();

    // ?AllwaysRed@aiMap@@QAEXXZ | unused
    ARTS_IMPORT void AllwaysRed();

    // ?ChooseNextFreewayLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextFreewayLink(aiRailSet* arg1);

    // ?ChooseNextLaneLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextLaneLink(aiRailSet* arg1);

    // ?ChooseNextLeftStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextLeftStraightLink(aiRailSet* arg1);

    // ?ChooseNextRandomLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextRandomLink(aiRailSet* arg1);

    // ?ChooseNextRightStraightFreewayLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextRightStraightFreewayLink(aiRailSet* arg1);

    // ?ChooseNextRightStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextRightStraightLink(aiRailSet* arg1);

    // ?ChooseNextStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextStraightLink(aiRailSet* arg1);

    // ?Clean@aiMap@@QAEXXZ
    ARTS_IMPORT void Clean();

    // ?Cull@aiMap@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?DetRdSegBetweenInts@aiMap@@QAEPAVaiPath@@PAVaiIntersection@@0@Z | unused
    ARTS_IMPORT aiPath* DetRdSegBetweenInts(aiIntersection* arg1, aiIntersection* arg2);

    // ?DetermineOppMapComponent@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAF2PAM323MFF@Z
    ARTS_IMPORT i32 DetermineOppMapComponent(Matrix34& arg1, aiRailSet* arg2, i16* arg3, i16* arg4, f32* arg5,
        f32* arg6, i16* arg7, f32* arg8, f32 arg9, i16 arg10, i16 arg11);

    // ?DetermineOppRoadPosInfo@aiMap@@QAEHAAVVector3@@0PAVaiRailSet@@PAFPAM3H@Z
    ARTS_IMPORT i32 DetermineOppRoadPosInfo(
        Vector3& arg1, Vector3& arg2, aiRailSet* arg3, i16* arg4, f32* arg5, f32* arg6, i32 arg7);

    // ?DeterminePerpMapComponent@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAF2PAM32@Z
    ARTS_IMPORT i32 DeterminePerpMapComponent(
        Matrix34& arg1, aiRailSet* arg2, i16* arg3, i16* arg4, f32* arg5, f32* arg6, i16* arg7);

    // ?DetermineRoadPosInfo@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAFPAM23H@Z
    ARTS_IMPORT i32 DetermineRoadPosInfo(
        Matrix34& arg1, aiRailSet* arg2, i16* arg3, f32* arg4, i16* arg5, f32* arg6, i32 arg7);

    // ?DrawAppRoads@aiMap@@QAEXXZ
    ARTS_IMPORT void DrawAppRoads();

    // ?DrawNextVisibleAmbient@aiMap@@QAEXXZ
    ARTS_IMPORT void DrawNextVisibleAmbient();

    // ?Dump@aiMap@@QAEXXZ
    ARTS_EXPORT void Dump();

    void DumpPaths();

    void DumpIntersections();

    // ?FindAmbAppRoad@aiMap@@QAEHH@Z
    ARTS_IMPORT i32 FindAmbAppRoad(i32 arg1);

    // ?FindPedAppRoad@aiMap@@QAEHH@Z
    ARTS_IMPORT i32 FindPedAppRoad(i32 arg1);

    // ?GetCameraPos@aiMap@@QAEXXZ | unused
    ARTS_IMPORT void GetCameraPos();

    // ?GetClass@aiMap@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GoodRoadForCopStartPos@aiMap@@QAEHH@Z
    ARTS_IMPORT i32 GoodRoadForCopStartPos(i32 arg1);

    // ?Init@aiMap@@QAEXPAD00PAVmmCar@@@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2, char* arg3, mmCar* arg4);

    // ?Intersection@aiMap@@QAEPAVaiIntersection@@H@Z
    ARTS_IMPORT aiIntersection* Intersection(i32 arg1);

    // ?MapComponent@aiMap@@QAEHAAVVector3@@PAF1F@Z
    ARTS_IMPORT i32 MapComponent(Vector3& arg1, i16* arg2, i16* arg3, i16 arg4);

    // ?Opponent@aiMap@@QAEPAVaiVehicleOpponent@@H@Z
    ARTS_IMPORT aiVehicleOpponent* Opponent(i32 arg1);

    // ?Path@aiMap@@QAEPAVaiPath@@H@Z
    ARTS_IMPORT aiPath* Path(i32 arg1);

    // ?Pedestrian@aiMap@@QAEPAVaiPedestrian@@H@Z | unused
    ARTS_IMPORT aiPedestrian* Pedestrian(i32 arg1);

    // ?PlayerPos@aiMap@@QAEAAVVector3@@XZ | unused
    ARTS_IMPORT Vector3& PlayerPos();

    // ?Police@aiMap@@QAEPAVaiVehiclePolice@@H@Z
    ARTS_IMPORT aiVehiclePolice* Police(i32 arg1);

    // ?PredictAmbFreewayIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    ARTS_IMPORT aiPath* PredictAmbFreewayIntersectionPath(i32 arg1, Matrix34& arg2);

    // ?PredictAmbIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    ARTS_IMPORT aiPath* PredictAmbIntersectionPath(i32 arg1, Matrix34& arg2);

    // ?PredictIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    ARTS_IMPORT aiPath* PredictIntersectionPath(i32 arg1, Matrix34& arg2);

    // ?RemoveAmbient@aiMap@@QAEXPAVaiVehicleSpline@@@Z
    ARTS_IMPORT void RemoveAmbient(aiVehicleSpline* arg1);

    // ?RemovePedestrian@aiMap@@QAEXPAVaiPedestrian@@@Z
    ARTS_IMPORT void RemovePedestrian(aiPedestrian* arg1);

    // ?Reset@aiMap@@UAEXXZ
    ARTS_IMPORT void Reset() override;

#ifdef ARTS_DEV_BUILD
    // ?Stats@aiMap@@QAEXXZ
    ARTS_IMPORT void Stats();
#endif

    // ?Update@aiMap@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdatePaused@aiMap@@UAEXXZ
    ARTS_EXPORT void UpdatePaused() override;

    // ?Vehicle@aiMap@@QAEPAVaiVehicleAmbient@@H@Z | unused
    ARTS_IMPORT aiVehicleAmbient* Vehicle(i32 arg1);

    // ?DeclareFields@aiMap@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    aiVehicleManager* VehicleMgr;
    aiRaceData* RaceData;
    aiIntersection** Intersections;
    i16 NumIntersections;
    aiPath** Paths;
    i16 NumPaths;
    aiVehicleAmbient* Ambients;
    i16 NumAmbients;
    aiVehicleSpline* pFirstAmbient;
    aiPoliceForce* PoliceForce;
    aiVehiclePolice* PoliceVehicles;
    i16 NumPolice;
    i16 CopCount;
    i16 CopPaths[6];
    aiVehicleOpponent* Opponents;
    i16 NumOpponents;
    aiPedestrian* Pedestrians;
    i16 NumPedestrians;
    aiPedestrian* field_6C;
    i16 UpdateGroup;
    i16 UpdateCount;
    Vector3 CameraPos;
    mmCar* PlayerCar;
    Vector3 zAxis;
    f32 InvCarSpeed;
    f32 SpeedRacerCheat;
    i16 PlayerRoom;
    CArrayList* AmbientRoads;
    CArrayList* PedRoads;

    b16 DrawAllPaths;

    b16 DrawIntersectionIds;
    b16 DrawPathIds;
    b16 DrawAmbientIds;

    b16 AlwaysGreen;
    b16 AlwaysRed;

    b16 DrawPathNormals;
    b16 DrawTargetPoints;

    // 0: Off
    // 1: Ambients
    // 2: Peds
    i16 DrawActivePaths;

    b16 DrawBBoxes;
    u16 nAmbientCount;
    u16 BackwardsCheat;

private:
    // ?AddAIPath@aiMap@@AAEPAVaiPath@@AAVmmRoadSect@@HH@Z
    ARTS_IMPORT aiPath* AddAIPath(mmRoadSect& arg1, i32 arg2, i32 arg3);

    // ?AddIntToAppRoadMap@aiMap@@AAEXPAVCArrayList@@HMPAPAUasPortalCell@@H@Z
    ARTS_IMPORT void AddIntToAppRoadMap(CArrayList* arg1, i32 arg2, f32 arg3, asPortalCell** arg4, i32 arg5);

    // ?AdjustAmbients@aiMap@@AAEXHH@Z
    ARTS_IMPORT void AdjustAmbients(i32 arg1, i32 arg2);

    // ?AdjustPedestrians@aiMap@@AAEXHH@Z
    ARTS_IMPORT void AdjustPedestrians(i32 arg1, i32 arg2);

#ifdef ARTS_DEV_BUILD
    // ?CreateAmbAppRoadMap@aiMap@@AAEXXZ
    ARTS_IMPORT void CreateAmbAppRoadMap();

    // ?CreatePedAppRoadMap@aiMap@@AAEXXZ
    ARTS_IMPORT void CreatePedAppRoadMap();
#endif

    // ?FindRoad@aiMap@@AAEHPAVCArrayList@@H@Z
    ARTS_IMPORT i32 FindRoad(CArrayList* arg1, i32 arg2);

    // ?NewIntersection@aiMap@@AAEPAVaiIntersection@@AAVVector3@@@Z
    ARTS_IMPORT aiIntersection* NewIntersection(Vector3& arg1);

    // ?NumCars@aiMap@@AAEHHMM@Z
    ARTS_IMPORT i32 NumCars(i32 arg1, f32 arg2, f32 arg3);

    // ?ReadBinary@aiMap@@AAEXPAD@Z
    ARTS_IMPORT void ReadBinary(char* arg1);

    // ?RoadDensity@aiMap@@AAEMHMH@Z | unused
    ARTS_IMPORT f32 RoadDensity(i32 arg1, f32 arg2, i32 arg3);

    // ?SaveBinary@aiMap@@AAEXPAD@Z
    ARTS_IMPORT void SaveBinary(char* arg1);

    // ?ScanIntersections@aiMap@@AAEPAVaiIntersection@@AAVVector3@@@Z
    ARTS_IMPORT aiIntersection* ScanIntersections(Vector3& arg1);
};

check_size(aiMap, 0xBC);

// ?Clamp@@YAMMMM@Z | inline
ARTS_IMPORT f32 Clamp(f32 arg1, f32 arg2, f32 arg3);

// ?AIMAP@@3VaiMap@@A
ARTS_IMPORT extern aiMap AIMAP;

// ?_fAmbientUpdate@@3MA
ARTS_IMPORT extern f32 _fAmbientUpdate;

// ?_fCopUpdate@@3MA
ARTS_IMPORT extern f32 _fCopUpdate;

// ?_fOppUpdate@@3MA
ARTS_IMPORT extern f32 _fOppUpdate;

// ?_fPedUpdate@@3MA
ARTS_IMPORT extern f32 _fPedUpdate;

// ?_fTotUpdate@@3MA
ARTS_IMPORT extern f32 _fTotUpdate;

// ?_nAmbientQty@@3HA
ARTS_IMPORT extern i32 _nAmbientQty;

// ?_nPedQty@@3HA
ARTS_IMPORT extern i32 _nPedQty;

// ?_nRdQty@@3HA
ARTS_IMPORT extern i32 _nRdQty;
