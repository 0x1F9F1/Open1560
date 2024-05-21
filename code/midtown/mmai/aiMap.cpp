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

define_dummy_symbol(mmai_aiMap);

#include "aiMap.h"

#include "aiIntersection.h"
#include "aiPath.h"
#include "aiVehicleAmbient.h"
#include "aiVehicleOpponent.h"
#include "aiVehiclePolice.h"

#include "arts7/camera.h"
#include "arts7/cullmgr.h"
#include "mmcity/cullcity.h"
#include "vector7/randmath.h"

#ifdef ARTS_DEV_BUILD
void aiMap::AddWidgets(Bank* bank)
{
    bank->AddButton("Always Green", [this] { AllwaysGreen(); });
    bank->AddButton("Always Red", [this] { AllwaysRed(); });

    bank->AddButton("Draw Ambient Paths", [this] {
        DrawActivePaths = (DrawActivePaths != 1) ? 1 : 0;
        DrawAllPaths = false;
    });
    bank->AddButton("Draw Ped Paths", [this] {
        DrawActivePaths = (DrawActivePaths != 2) ? 2 : 0;
        DrawAllPaths = false;
    });
    bank->AddButton("Draw All Paths", [this] {
        DrawActivePaths = 0;
        DrawAllPaths ^= true;
    });

    bank->AddButton("Draw Path Normals", [this] { DrawPathNormals ^= true; });

    bank->AddButton("Draw Path IDs", [this] { DrawPathIds ^= true; });
    bank->AddButton("Draw Intersection IDs", [this] { DrawIntersectionIds ^= true; });
    bank->AddButton("Draw Ambient IDs", [this] { DrawAmbientIds ^= true; });

    bank->AddButton("Draw Target Points", [this] { DrawTargetPoints ^= true; });
    bank->AddButton("Draw Bounding Boxes", [this] { DrawBBoxes ^= true; });

    bank->AddSlider("Vehicle Speed", &SpeedRacerCheat, 0.1f, 100.0f, 0.1f);

    bank->AddButton("Dump AI", [this] { Dump(); });
    bank->AddButton("Dump Paths", [this] { DumpPaths(); });
    bank->AddButton("Dump Intersections", [this] { DumpIntersections(); });

    bank->PushSection("Opponents", false);

    for (i32 i = 0; i < NumOpponents; ++i)
    {
        bank->PushSection(arts_formatf<128>("Opponent %i", i), false);
        Opponents[i].AddWidget(bank);
        bank->PopSection();
    }

    bank->PopSection();
}
#endif

void aiMap::Dump()
{
    Displayf("AI MAP");

    Displayf("Num Paths = %d", NumPaths);
    Displayf("Num Intersections = %d", NumIntersections);
    Displayf("Num Opponents = %d", NumOpponents);

    for (i32 i = 0; i < NumOpponents; ++i)
        Opponents[i].Dump();

    Displayf("Num Cops = %d", NumPolice);

    for (i32 i = 0; i < NumPolice; ++i)
        PoliceVehicles[i].Dump();

    Displayf("Num Ambients = %d", NumAmbients);

    for (i32 i = 0; i < NumPolice; ++i)
        Ambients[i].Dump();
}

void aiMap::DumpPaths()
{
    Displayf("Num Paths = %i", NumPaths);

    for (i32 i = 0; i < NumPaths; ++i)
        Paths[i]->Dump();
}

void aiMap::DumpIntersections()
{
    Displayf("Num NumIntersections = %i", NumIntersections);

    for (i32 i = 0; i < NumIntersections; ++i)
        Intersections[i]->Dump();
}

aiIntersection* aiMap::Intersection(i32 index)
{
    if (index >= 0 && index <= NumIntersections)
        return Intersections[index];

    Warningf("Returning a NULL Intersection. Idx: %d", index);
    return nullptr;
}

aiVehicleOpponent* aiMap::Opponent(i32 index)
{
    if (index >= 0 && index <= NumOpponents)
        return &Opponents[index];

    Warningf("Returning a NULL Opponent. Idx: %d", index);
    return nullptr;
}

aiPath* aiMap::Path(i32 index)
{
    if (index >= 0 && index <= NumPaths)
        return Paths[index];

    Warningf("Returning a NULL Path for %d.", index);
    return nullptr;
}

aiVehiclePolice* aiMap::Police(i32 index)
{
    if (index >= 0 && index <= NumPolice)
        return &PoliceVehicles[index];

    Warningf("Returning a NULL Cop. Idx: %d", index);
    return nullptr;
}

void aiMap::Stats()
{
    Statsf("AI Total Update: %.3fms", _fTotUpdate * 1000.0f);
    Statsf("Ped Update: %.3fms, Qty: %d", _fPedUpdate * 1000.0f, _nPedQty);
    Statsf("Ambient Update: %.3fms, Qty: %d", _fAmbientUpdate * 1000.0f, _nAmbientQty);
    Statsf("Opponent Update: %.3fms, Qty: %d", _fOppUpdate * 1000.0f, NumOpponents);
    Statsf("Police Update: %.3fms, Qty: %d", _fCopUpdate * 1000.0f, NumPolice);
}

void aiMap::UpdatePaused()
{}

b32 aiMap::ChooseNextLaneLink(aiRailSet* rail)
{
    aiPath* path = rail->CurLink;
    i16 lane = rail->CurLane;

    switch (path->NumLanes)
    {
        case 1: return ChooseNextRandomLink(rail);
        case 2: return lane ? ChooseNextRightStraightLink(rail) : ChooseNextLeftStraightLink(rail);
        case 3: {
            switch (lane)
            {
                case 0: return ChooseNextLeftStraightLink(rail);
                case 1: return ChooseNextStraightLink(rail);
                case 2: return ChooseNextRightStraightLink(rail);
                default: return false;
            }
        }

        case 4: return (lane == 3) ? ChooseNextRightStraightFreewayLink(rail) : ChooseNextFreewayLink(rail);

        default: return false;
    }
}

b32 aiMap::ChooseNextRandomLink(aiRailSet* rail)
{
    aiPath* path = rail->CurLink;
    i32 total_paths = path->Sink->NumSourcePaths + path->Sink->NumSinkPaths;

    aiPath* paths[16];
    usize num_paths = 0;
    i32 idx = path->EdgeIndex;

    // Check all paths, except the current one
    for (i32 i = 1; i < total_paths; ++i)
    {
        if (++idx == total_paths)
            idx = 0;

        aiIntersection* intersection = path->Sink;

        if (intersection->PathIds[idx] >= 9990)
            continue;

        aiPath* dst = intersection->Path(idx);

        // TODO: Allow following a path back to the same intersection.
        if (intersection == dst->Sink) // Avoid circular roads
            continue;

        if (dst != path->OncomingPath // Avoid doing a U-turn
            && !dst->IsBlocked        // Avoid blocked roads
            && !dst->HasBridge)       // Avoid bridges
        {
            if (dst->NumLanes == 4)
            {
                rail->NextLink = dst;
                rail->NextLane = 3;
                return true;
            }

            ArAssert(num_paths < ARTS_SIZE(paths), "Too many possible paths");
            paths[num_paths++] = dst;
        }
    }

    if (num_paths == 0)
    {
        Warningf("No eligible roads identified to turn onto from road: %d.", path->Id);

        return false;
    }

    aiPath* dst = paths[static_cast<u32>(static_cast<f32>(num_paths) * frand())];
    rail->NextLink = dst;

    if (rail->SolveTurnType(path, dst))
        rail->NextLane = 0;
    else
        rail->NextLane = dst->NumLanes - 1;

    return true;
}
