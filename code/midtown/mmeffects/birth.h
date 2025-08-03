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

struct asSparkInfo;
struct asSparkPos;

class asBirthRule final : public asNode
{
public:
    // ??0asBirthRule@@QAE@XZ
    ARTS_IMPORT asBirthRule();

    // ??1asBirthRule@@UAE@XZ | inline
    ARTS_EXPORT ~asBirthRule() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asBirthRule@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@asBirthRule@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?InitSpark@asBirthRule@@QAEXPAUasSparkInfo@@PAUasSparkPos@@@Z
    ARTS_IMPORT void InitSpark(asSparkInfo* arg1, asSparkPos* arg2);

    // ?DeclareFields@asBirthRule@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Vector3 Position;
    Vector3 PositionVar;
    Vector3 Velocity;
    Vector3 VelocityVar;
    f32 Life;
    f32 LifeVar;
    f32 Mass;
    f32 MassVar;
    f32 Radius;
    f32 RadiusVar;
    f32 DRadius;
    f32 DRadiusVar;
    f32 Drag;
    f32 DragVar;
    f32 Damp;
    f32 DampVar;
    f32 SpewRate;
    f32 SpewRateLimit;
    f32 Gravity;
    i32 DAlpha;
    i32 DAlphaVar;
    i32 DRotation;
    i32 DRotationVar;
    i32 TexFrameStart;
    i32 TexFrameEnd;
    i32 InitialBlast;

    enum BirthFlags_
    {
        kStationary = 0x1,
        kCycleFrames = 0x4,
        kSplashes = 0x8,
    };

    i32 BirthFlags;

    void (*InitCallback)(asSparkInfo*, asSparkPos*);
};

check_size(asBirthRule, 0xB0);
