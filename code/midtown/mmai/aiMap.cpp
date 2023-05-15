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

void aiMap::UpdatePaused()
{}

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