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

    // ?AllwaysGreen@aiMap@@QAEXXZ
    ARTS_IMPORT void AllwaysGreen();

    // ?AllwaysRed@aiMap@@QAEXXZ
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

    // ?GetClass@aiMap@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GoodRoadForCopStartPos@aiMap@@QAEHH@Z
    ARTS_IMPORT i32 GoodRoadForCopStartPos(i32 arg1);

    // ?Init@aiMap@@QAEXPAD00PAVmmCar@@@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2, char* arg3, mmCar* arg4);

    // ?Intersection@aiMap@@QAEPAVaiIntersection@@H@Z
    ARTS_EXPORT aiIntersection* Intersection(i32 index);

    // ?MapComponent@aiMap@@QAEHAAVVector3@@PAF1F@Z
    ARTS_IMPORT i32 MapComponent(Vector3& arg1, i16* arg2, i16* arg3, i16 arg4);

    // ?Opponent@aiMap@@QAEPAVaiVehicleOpponent@@H@Z
    ARTS_EXPORT aiVehicleOpponent* Opponent(i32 index);

    // ?Path@aiMap@@QAEPAVaiPath@@H@Z
    ARTS_EXPORT aiPath* Path(i32 index);

    // ?Police@aiMap@@QAEPAVaiVehiclePolice@@H@Z
    ARTS_EXPORT aiVehiclePolice* Police(i32 index);

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
    ARTS_EXPORT void Stats();
#endif

    // ?Update@aiMap@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdatePaused@aiMap@@UAEXXZ
    ARTS_EXPORT void UpdatePaused() override;

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
