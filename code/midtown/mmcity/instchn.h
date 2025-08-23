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

class mmInstance;

class mmInstChain
{
public:
    // ??0mmInstChain@@QAE@XZ
    ARTS_EXPORT mmInstChain() = default;

    // ??1mmInstChain@@QAE@XZ
    ARTS_EXPORT ~mmInstChain() = default;

    // ?Draw@mmInstChain@@QAEXFFIHM@Z
    ARTS_IMPORT void Draw(i16 arg1, i16 arg2, u32 arg3, i32 arg4, f32 arg5);

    // ?Init@mmInstChain@@QAEXH@Z
    void Init(i32 num_rooms);

    // ?Parent@mmInstChain@@QAEXPAVmmInstance@@F@Z
    ARTS_EXPORT void Parent(mmInstance* inst, i16 room);

    // ?Reparent@mmInstChain@@QAEXPAVmmInstance@@F@Z
    ARTS_EXPORT void Reparent(mmInstance* inst, i16 room);

    // ?Unparent@mmInstChain@@QAEXPAVmmInstance@@@Z
    ARTS_EXPORT void Unparent(mmInstance* inst);

    // ?Relight@mmInstChain@@QAEXF@Z
    void Relight(i16 room);

    // ?RelightEverything@mmInstChain@@QAEXXZ
    ARTS_EXPORT void RelightEverything();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmInstChain@@QAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1);
#endif

    Ptr<mmInstance*[]> Chains {};
    Ptr<i16[]> ChainCounts {};
    i32 NumChains {};
};

check_size(mmInstChain, 0xC);

// Check if an instance's sphere is visible before any drawing.
// Can end up hiding shadows if the object itself isn't visible.
// Can also hide facade instances, since it doesn't check if the secondary meshes are visible (see the GRND sliver in room 682)
// ?EnableSphereCull@@3HA
ARTS_EXPORT extern b32 EnableSphereCull;

// ?LabelInstances@@3HA
ARTS_EXPORT extern b32 LabelInstances;

// ?NormalsOnInstances@@3HA
ARTS_EXPORT extern b32 NormalsOnInstances;

// ?WorstCount@@3HA
ARTS_EXPORT extern i32 WorstCount;

// ?WorstRoom@@3HA
ARTS_EXPORT extern i32 WorstRoom;
