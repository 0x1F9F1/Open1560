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
    agi:physdef

    0x556F90 | public: void __thiscall agiPhysParameters::Load(class Stream *) | ?Load@agiPhysParameters@@QAEXPAVStream@@@Z
    0x557040 | public: void __thiscall agiPhysParameters::Save(class Stream *) | ?Save@agiPhysParameters@@QAEXPAVStream@@@Z
*/

#include "vector7/vector2.h"
#include "vector7/vector3.h"

class agiPhysParameters
{
public:
    // ?Load@agiPhysParameters@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Load(Stream* arg1);

    // ?Save@agiPhysParameters@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(Stream* arg1);

    char Name[32] {};

    f32 Friction {};
    f32 Elasticity {};
    f32 Drag {};

    f32 BumpHeight {};
    f32 BumpWidth {};
    f32 BumpDepth {};

    f32 SinkDepth {};

    u32 Type {};
    u32 Sound {};

    Vector2 Velocity {};
    Vector3 PtxColor {};
};

check_size(agiPhysParameters, 0x58);

class agiPhysDef
{
public:
    agiPhysDef() = delete;

    void Release()
    {}
};
