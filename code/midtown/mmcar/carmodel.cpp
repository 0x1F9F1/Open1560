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

define_dummy_symbol(mmcar_carmodel);

#include "carmodel.h"

enum
{
    MESH_BODY = 0,
    MESH_SHADOW = 1,
    MESH_HLIGHT = 2,
    MESH_TLIGHT = 3,
    MESH_SLIGHT0 = 4,
    MESH_SLIGHT1 = 5,
    MESH_WHL0 = 6,
    MESH_WHL1 = 7,
    MESH_WHL2 = 8,
    MESH_WHL3 = 9,
    MESH_WHL4 = 10,
    MESH_WHL5 = 11,
    MESH_AXLE0 = 12,
    MESH_AXLE1 = 13,
    MESH_FNDR0 = 14,
    MESH_FNDR1 = 15,
    MESH_REDLIGHT = 16,
    MESH_BLUELIGHT = 17,
    MESH_REDCONE = 18,
    MESH_BLUECONE = 19,
    MESH_RLIGHT = 20,
    MESH_BLIGHT = 21,
};

mmCarModel::mmCarModel()
{
    SetFlags(INST_FLAG_SHADOW | INST_FLAG_MOVER | INST_FLAG_100 | INST_FLAG_GLOW | INST_FLAG_2000);
    CarFlags |= CAR_FLAG_ACTIVE;

    Sparks.Init(256, GetSparkLut("tune/spark.tga"_xconst));
}

i32 mmCarModel::GetCarFlags(char* /*arg1*/)
{
    return 0;
}
