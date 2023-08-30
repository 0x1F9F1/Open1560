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
    mmai:aiData

    0x446630 | public: __thiscall aiRaceData::aiRaceData(char *,char *) | ??0aiRaceData@@QAE@PAD0@Z
    0x446B10 | public: __thiscall aiRaceData::~aiRaceData(void) | ??1aiRaceData@@QAE@XZ
*/

#include "data7/list.h"
#include "vector7/vector3.h"

class aiRaceData
{
public:
    // ??0aiRaceData@@QAE@PAD0@Z
    ARTS_IMPORT aiRaceData(char* arg1, char* arg2);

    // ??1aiRaceData@@QAE@XZ
    ARTS_IMPORT ~aiRaceData();

    f32 Density;
    f32 SpeedLimit;
    List Exceptions;
    List Police;
    List Opponents;
};

check_size(aiRaceData, 0x2C);

class PoliceRaceData
{
public:
    char Model[32];
    Vector3 Position;
    f32 Rotation;
    i32 Type;
    i32 BehaviourFlags;
};

check_size(PoliceRaceData, 0x38);

class OpponentRaceData
{
public:
    char Model[32];
    char PathFile[32];
    f32 MaxThrottle;
};

check_size(OpponentRaceData, 0x44);
