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

class asPerfGraph
{
public:
    // 0x52A8A0 | ??0asPerfGraph@@QAE@XZ
    asPerfGraph();

    // 0x52A930 | ??1asPerfGraph@@QAE@XZ
    ~asPerfGraph();

    // 0x52A960 | ?AddComponent@asPerfGraph@@QAEXPADPAMAAVVector3@@@Z
    void AddComponent(char* arg1, f32* arg2, class Vector3& arg3);

    // 0x52AB30 | ?Cull@asPerfGraph@@QAEXXZ
    void Cull();

    // 0x52A9E0 | ?Key@asPerfGraph@@QAEXH@Z
    void Key(i32 arg1);

    // 0x52AA30 | ?Update@asPerfGraph@@QAEXXZ
    void Update();
};

check_size(asPerfGraph, 0x94);

// 0x790984 | ?PGRAPH@@3PAVasPerfGraph@@A
inline extern_var(0x390984_Offset, class asPerfGraph*, PGRAPH);
