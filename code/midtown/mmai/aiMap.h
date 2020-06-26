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

class aiMap : public asNode
{
    // const aiMap::`vftable' @ 0x61B298

public:
    // 0x433FC0 | ??0aiMap@@QAE@XZ
    ARTS_IMPORT aiMap();

    // 0x43C120 | ??_EaiMap@@UAEPAXI@Z
    // 0x433FE0 | ??1aiMap@@UAE@XZ
    ARTS_IMPORT ~aiMap() override;

    // 0x43BA60 | ?AddAmbient@aiMap@@QAEXPAVaiVehicleSpline@@@Z
    ARTS_IMPORT void AddAmbient(class aiVehicleSpline* arg1);

    // 0x439670 | ?AddIntersection@aiMap@@QAEPAVaiIntersection@@PAVVector3@@@Z
    ARTS_IMPORT class aiIntersection* AddIntersection(class Vector3* arg1);

    // 0x43B500 | ?AddPedestrian@aiMap@@QAEXPAVaiPedestrian@@@Z
    ARTS_IMPORT void AddPedestrian(class aiPedestrian* arg1);

    // 0x43BBE0 | ?AddWidgets@aiMap@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x436CF0 | ?AllwaysGreen@aiMap@@QAEXXZ | unused
    ARTS_IMPORT void AllwaysGreen();

    // 0x436D30 | ?AllwaysRed@aiMap@@QAEXXZ | unused
    ARTS_IMPORT void AllwaysRed();

    // 0x43AE90 | ?ChooseNextFreewayLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextFreewayLink(class aiRailSet* arg1);

    // 0x43ADF0 | ?ChooseNextLaneLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextLaneLink(class aiRailSet* arg1);

    // 0x43A5D0 | ?ChooseNextLeftStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextLeftStraightLink(class aiRailSet* arg1);

    // 0x43A440 | ?ChooseNextRandomLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextRandomLink(class aiRailSet* arg1);

    // 0x43AFA0 | ?ChooseNextRightStraightFreewayLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextRightStraightFreewayLink(class aiRailSet* arg1);

    // 0x43A840 | ?ChooseNextRightStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextRightStraightLink(class aiRailSet* arg1);

    // 0x43AAE0 | ?ChooseNextStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    ARTS_IMPORT i32 ChooseNextStraightLink(class aiRailSet* arg1);

    // 0x433FF0 | ?Clean@aiMap@@QAEXXZ
    ARTS_IMPORT void Clean();

    // 0x436680 | ?Cull@aiMap@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x43BB10 | ?DetRdSegBetweenInts@aiMap@@QAEPAVaiPath@@PAVaiIntersection@@0@Z | unused
    ARTS_IMPORT class aiPath* DetRdSegBetweenInts(class aiIntersection* arg1, class aiIntersection* arg2);

    // 0x437310 | ?DetermineOppMapComponent@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAF2PAM323MFF@Z
    ARTS_IMPORT i32 DetermineOppMapComponent(class Matrix34& arg1, class aiRailSet* arg2, i16* arg3, i16* arg4,
        f32* arg5, f32* arg6, i16* arg7, f32* arg8, f32 arg9, i16 arg10, i16 arg11);

    // 0x438CB0 | ?DetermineOppRoadPosInfo@aiMap@@QAEHAAVVector3@@0PAVaiRailSet@@PAFPAM3H@Z
    ARTS_IMPORT i32 DetermineOppRoadPosInfo(
        class Vector3& arg1, class Vector3& arg2, class aiRailSet* arg3, i16* arg4, f32* arg5, f32* arg6, i32 arg7);

    // 0x4370B0 | ?DeterminePerpMapComponent@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAF2PAM32@Z
    ARTS_IMPORT i32 DeterminePerpMapComponent(
        class Matrix34& arg1, class aiRailSet* arg2, i16* arg3, i16* arg4, f32* arg5, f32* arg6, i16* arg7);

    // 0x436F10 | ?DetermineRoadPosInfo@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAFPAM23H@Z
    ARTS_IMPORT i32 DetermineRoadPosInfo(
        class Matrix34& arg1, class aiRailSet* arg2, i16* arg3, f32* arg4, i16* arg5, f32* arg6, i32 arg7);

    // 0x436D70 | ?DrawAppRoads@aiMap@@QAEXXZ
    ARTS_IMPORT void DrawAppRoads();

    // 0x436CD0 | ?DrawNextVisibleAmbient@aiMap@@QAEXXZ
    ARTS_IMPORT void DrawNextVisibleAmbient();

    // 0x439400 | ?Dump@aiMap@@QAEXXZ
    ARTS_IMPORT void Dump();

    // 0x438D90 | ?FindAmbAppRoad@aiMap@@QAEHH@Z
    ARTS_IMPORT i32 FindAmbAppRoad(i32 arg1);

    // 0x438DE0 | ?FindPedAppRoad@aiMap@@QAEHH@Z
    ARTS_IMPORT i32 FindPedAppRoad(i32 arg1);

    // 0x439540 | ?GetCameraPos@aiMap@@QAEXXZ | unused
    ARTS_IMPORT void GetCameraPos();

    // 0x43BD90 | ?GetClass@aiMap@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x43BB90 | ?GoodRoadForCopStartPos@aiMap@@QAEHH@Z
    ARTS_IMPORT i32 GoodRoadForCopStartPos(i32 arg1);

    // 0x434220 | ?Init@aiMap@@QAEXPAD00PAVmmCar@@@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2, char* arg3, class mmCar* arg4);

    // 0x433E80 | ?Intersection@aiMap@@QAEPAVaiIntersection@@H@Z
    ARTS_IMPORT class aiIntersection* Intersection(i32 arg1);

    // 0x436D90 | ?MapComponent@aiMap@@QAEHAAVVector3@@PAF1F@Z
    ARTS_IMPORT i32 MapComponent(class Vector3& arg1, i16* arg2, i16* arg3, i16 arg4);

    // 0x433F30 | ?Opponent@aiMap@@QAEPAVaiVehicleOpponent@@H@Z
    ARTS_IMPORT class aiVehicleOpponent* Opponent(i32 arg1);

    // 0x433E50 | ?Path@aiMap@@QAEPAVaiPath@@H@Z
    ARTS_IMPORT class aiPath* Path(i32 arg1);

    // 0x433F70 | ?Pedestrian@aiMap@@QAEPAVaiPedestrian@@H@Z | unused
    ARTS_IMPORT class aiPedestrian* Pedestrian(i32 arg1);

    // 0x433FB0 | ?PlayerPos@aiMap@@QAEAAVVector3@@XZ | unused
    ARTS_IMPORT class Vector3& PlayerPos();

    // 0x433EF0 | ?Police@aiMap@@QAEPAVaiVehiclePolice@@H@Z
    ARTS_IMPORT class aiVehiclePolice* Police(i32 arg1);

    // 0x4391F0 | ?PredictAmbFreewayIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    ARTS_IMPORT class aiPath* PredictAmbFreewayIntersectionPath(i32 arg1, class Matrix34& arg2);

    // 0x439010 | ?PredictAmbIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    ARTS_IMPORT class aiPath* PredictAmbIntersectionPath(i32 arg1, class Matrix34& arg2);

    // 0x438E30 | ?PredictIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    ARTS_IMPORT class aiPath* PredictIntersectionPath(i32 arg1, class Matrix34& arg2);

    // 0x43BAA0 | ?RemoveAmbient@aiMap@@QAEXPAVaiVehicleSpline@@@Z
    ARTS_IMPORT void RemoveAmbient(class aiVehicleSpline* arg1);

    // 0x43B530 | ?RemovePedestrian@aiMap@@QAEXPAVaiPedestrian@@@Z
    ARTS_IMPORT void RemovePedestrian(class aiPedestrian* arg1);

    // 0x435FB0 | ?Reset@aiMap@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x435770 | ?Stats@aiMap@@QAEXXZ
    ARTS_IMPORT void Stats();

    // 0x4362F0 | ?Update@aiMap@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x436670 | ?UpdatePaused@aiMap@@UAEXXZ
    ARTS_IMPORT void UpdatePaused() override;

    // 0x433EB0 | ?Vehicle@aiMap@@QAEPAVaiVehicleAmbient@@H@Z | unused
    ARTS_IMPORT class aiVehicleAmbient* Vehicle(i32 arg1);

    // 0x43BC20 | ?DeclareFields@aiMap@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x439570 | ?AddAIPath@aiMap@@AAEPAVaiPath@@AAVmmRoadSect@@HH@Z
    ARTS_IMPORT class aiPath* AddAIPath(class mmRoadSect& arg1, i32 arg2, i32 arg3);

    // 0x43A300 | ?AddIntToAppRoadMap@aiMap@@AAEXPAVCArrayList@@HMPAPAUasPortalCell@@H@Z
    ARTS_IMPORT void AddIntToAppRoadMap(
        class CArrayList* arg1, i32 arg2, f32 arg3, struct asPortalCell** arg4, i32 arg5);

    // 0x43B5A0 | ?AdjustAmbients@aiMap@@AAEXHH@Z
    ARTS_IMPORT void AdjustAmbients(i32 arg1, i32 arg2);

    // 0x43B160 | ?AdjustPedestrians@aiMap@@AAEXHH@Z
    ARTS_IMPORT void AdjustPedestrians(i32 arg1, i32 arg2);

    // 0x439800 | ?CreateAmbAppRoadMap@aiMap@@AAEXXZ
    ARTS_IMPORT void CreateAmbAppRoadMap();

    // 0x439D80 | ?CreatePedAppRoadMap@aiMap@@AAEXXZ
    ARTS_IMPORT void CreatePedAppRoadMap();

    // 0x43A400 | ?FindRoad@aiMap@@AAEHPAVCArrayList@@H@Z
    ARTS_IMPORT i32 FindRoad(class CArrayList* arg1, i32 arg2);

    // 0x439720 | ?NewIntersection@aiMap@@AAEPAVaiIntersection@@AAVVector3@@@Z
    ARTS_IMPORT class aiIntersection* NewIntersection(class Vector3& arg1);

    // 0x43A3D0 | ?NumCars@aiMap@@AAEHHMM@Z
    ARTS_IMPORT i32 NumCars(i32 arg1, f32 arg2, f32 arg3);

    // 0x4359B0 | ?ReadBinary@aiMap@@AAEXPAD@Z
    ARTS_IMPORT void ReadBinary(char* arg1);

    // 0x43A380 | ?RoadDensity@aiMap@@AAEMHMH@Z | unused
    ARTS_IMPORT f32 RoadDensity(i32 arg1, f32 arg2, i32 arg3);

    // 0x435830 | ?SaveBinary@aiMap@@AAEXPAD@Z
    ARTS_IMPORT void SaveBinary(char* arg1);

    // 0x4396A0 | ?ScanIntersections@aiMap@@AAEPAVaiIntersection@@AAVVector3@@@Z
    ARTS_IMPORT class aiIntersection* ScanIntersections(class Vector3& arg1);

    u8 gap20[0x9C];
};

check_size(aiMap, 0xBC);

// 0x43C0D0 | ?Clamp@@YAMMMM@Z | inline
ARTS_IMPORT f32 Clamp(f32 arg1, f32 arg2, f32 arg3);

// 0x6A7848 | ?AIMAP@@3VaiMap@@A
ARTS_IMPORT extern class aiMap AIMAP;

// 0x6A7834 | ?_fAmbientUpdate@@3MA
ARTS_IMPORT extern f32 _fAmbientUpdate;

// 0x6A7838 | ?_fCopUpdate@@3MA
ARTS_IMPORT extern f32 _fCopUpdate;

// 0x6A7938 | ?_fOppUpdate@@3MA
ARTS_IMPORT extern f32 _fOppUpdate;

// 0x6A7830 | ?_fPedUpdate@@3MA
ARTS_IMPORT extern f32 _fPedUpdate;

// 0x6A7948 | ?_fTotUpdate@@3MA
ARTS_IMPORT extern f32 _fTotUpdate;

// 0x6A793C | ?_nAmbientQty@@3HA
ARTS_IMPORT extern i32 _nAmbientQty;

// 0x6A7840 | ?_nPedQty@@3HA
ARTS_IMPORT extern i32 _nPedQty;

// 0x6A7934 | ?_nRdQty@@3HA
ARTS_IMPORT extern i32 _nRdQty;

// 0x6A7908 | ?aiMapMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass aiMapMetaClass;
