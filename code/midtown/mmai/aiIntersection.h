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

#include "vector7/vector3.h"

class aiPath;
class aiTrafficLightSet;

class aiIntersection
{
public:
    // ??0aiIntersection@@QAE@H@Z
    ARTS_IMPORT aiIntersection(i32 arg1);

    // ??1aiIntersection@@QAE@XZ
    ARTS_IMPORT ~aiIntersection();

    // ?AddSinkPath@aiIntersection@@QAEXPAVaiPath@@@Z
    ARTS_IMPORT void AddSinkPath(aiPath* arg1);

    // ?AddSourcePath@aiIntersection@@QAEXPAVaiPath@@@Z
    ARTS_IMPORT void AddSourcePath(aiPath* arg1);

    // ?CreateRoadMap@aiIntersection@@QAEXXZ
    ARTS_IMPORT void CreateRoadMap();

#ifdef ARTS_DEV_BUILD
    // ?DrawId@aiIntersection@@QAEXXZ
    ARTS_IMPORT void DrawId();

    // ?DrawPaths@aiIntersection@@QAEXXZ
    ARTS_IMPORT void DrawPaths();
#endif

    // ?Dump@aiIntersection@@QAEXXZ | unused
    ARTS_EXPORT void Dump();

    // ?Init@aiIntersection@@QAEXXZ
    ARTS_IMPORT void Init();

    // ?Path@aiIntersection@@QAEPAVaiPath@@H@Z
    ARTS_IMPORT aiPath* Path(i32 arg1);

    // ?ReadBinary@aiIntersection@@QAEXPAVStream@@@Z
    ARTS_IMPORT void ReadBinary(Stream* arg1);

    // ?Reset@aiIntersection@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?SaveBinary@aiIntersection@@QAEXPAVStream@@@Z
    ARTS_IMPORT void SaveBinary(Stream* arg1);

    aiPath* SinkPath(i32 index)
    {
        return (index >= 0 && index < NumSinkPaths) ? SinkPaths[index] : nullptr;
    }

    aiPath* SourcePath(i32 index)
    {
        return (index >= 0 && index < NumSourcePaths) ? SourcePaths[index] : nullptr;
    }

    aiPath** SinkPaths;
    i16 NumSinkPaths;
    aiPath** SourcePaths;
    i16 NumSourcePaths;
    i32* PathIds;
    f32* RoadDirections;
    i16 Id;
    aiTrafficLightSet* TrafficLights;
    Vector3 Pos;
};

check_size(aiIntersection, 0x2C);
