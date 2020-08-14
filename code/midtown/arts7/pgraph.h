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
    arts7:pgraph

    0x52A8A0 | public: __thiscall asPerfGraph::asPerfGraph(void) | ??0asPerfGraph@@QAE@XZ
    0x52A930 | public: __thiscall asPerfGraph::~asPerfGraph(void) | ??1asPerfGraph@@QAE@XZ
    0x52A960 | public: void __thiscall asPerfGraph::AddComponent(char *,float *,class Vector3 &) | ?AddComponent@asPerfGraph@@QAEXPADPAMAAVVector3@@@Z
    0x52A9E0 | public: void __thiscall asPerfGraph::Key(int) | ?Key@asPerfGraph@@QAEXH@Z
    0x52AA30 | public: void __thiscall asPerfGraph::Update(void) | ?Update@asPerfGraph@@QAEXXZ
    0x52AB30 | public: void __thiscall asPerfGraph::Cull(void) | ?Cull@asPerfGraph@@QAEXXZ
    0x790984 | class asPerfGraph * PGRAPH | ?PGRAPH@@3PAVasPerfGraph@@A
*/

class Vector3;

#include "agi/rgba.h"

class asPerfGraph
{
public:
    // 0x52A8A0 | ??0asPerfGraph@@QAE@XZ
    ARTS_EXPORT asPerfGraph();

    // 0x52A930 | ??1asPerfGraph@@QAE@XZ
    ARTS_EXPORT ~asPerfGraph();

    // 0x52A960 | ?AddComponent@asPerfGraph@@QAEXPADPAMAAVVector3@@@Z
    ARTS_EXPORT void AddComponent(const char* name, f32* value, const Vector3& color);

    // 0x52AB30 | ?Cull@asPerfGraph@@QAEXXZ
    ARTS_EXPORT void Cull();

    // 0x52A9E0 | ?Key@asPerfGraph@@QAEXH@Z
    ARTS_EXPORT void Key(i32 vkey);

    // 0x52AA30 | ?Update@asPerfGraph@@QAEXXZ
    ARTS_EXPORT void Update();

private:
    static constexpr i32 MaxComponents = 8;

    i32 num_components_ {0};
    i32 maim_component_ {0};
    f32* component_history_[MaxComponents] {};
    const char* component_name_[MaxComponents] {};
    f32* component_value_[MaxComponents] {};
    agiRgba component_color_[MaxComponents] {};
    f32 graph_scale_ {1.0f};
    i32 write_index_ {0};
    i32 read_index_ {0};

    f32 auto_scale_ {0.0f};
    i32 num_samples_ {0};
    bool scroll_ {true};
};

// check_size(asPerfGraph, 0x94);

// 0x790984 | ?PGRAPH@@3PAVasPerfGraph@@A
ARTS_IMPORT extern class asPerfGraph* PGRAPH;
