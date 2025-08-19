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

define_dummy_symbol(mmcity_cellrend);

#include "cellrend.h"

f32 ObjectMaxDist = 300.0f;

// ?BuildingMaxDist@@3MA
ARTS_EXPORT f32 BuildingMaxDist = 1000.0f;

f32 StaticTerrainLodTable[4][2] {
    {150.0f, 50.0f},
    {200.0f, 100.0f},
    {250.0f, 150.0f},
    {325.0f, 200.0f},
};

// ?LightDistances@@3PAMA
ARTS_EXPORT f32 LightDistances[4] {
    80.0f,
    160.0f,
    250.0f,
    350.0f,
};

void mmCellRenderer::Relight()
{}