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

#include "arts7/camera.h"
#include "arts7/cullmgr.h"
#include "mmcity/cullcity.h"

#include "aiIntersection.h"
#include "aiPath.h"
#include "aiVehicleAmbient.h"
#include "aiVehicleOpponent.h"
#include "aiVehiclePolice.h"

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