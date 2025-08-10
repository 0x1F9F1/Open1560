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
    ARTS_IMPORT mmInstChain();

    // ??1mmInstChain@@QAE@XZ
    ARTS_IMPORT ~mmInstChain();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmInstChain@@QAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1);
#endif

    // ?Draw@mmInstChain@@QAEXFFIHM@Z
    ARTS_IMPORT void Draw(i16 arg1, i16 arg2, u32 arg3, i32 arg4, f32 arg5);

    // ?Init@mmInstChain@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // ?Parent@mmInstChain@@QAEXPAVmmInstance@@F@Z
    ARTS_IMPORT void Parent(mmInstance* inst, i16 room);

    // ?Relight@mmInstChain@@QAEXF@Z
    ARTS_IMPORT void Relight(i16 arg1);

    // ?RelightEverything@mmInstChain@@QAEXXZ
    ARTS_IMPORT void RelightEverything();

    // ?Reparent@mmInstChain@@QAEXPAVmmInstance@@F@Z
    ARTS_IMPORT void Reparent(mmInstance* arg1, i16 arg2);

    // ?Unparent@mmInstChain@@QAEXPAVmmInstance@@@Z
    ARTS_IMPORT void Unparent(mmInstance* arg1);

    mmInstance** Chains {};
    i16* ChainCounts {};
    i32 NumChain {};
};

check_size(mmInstChain, 0xC);

// ?EnableSphereCull@@3HA
ARTS_IMPORT extern i32 EnableSphereCull;

// ?LabelInstances@@3HA
ARTS_IMPORT extern i32 LabelInstances;

// ?NormalsOnInstances@@3HA
ARTS_IMPORT extern i32 NormalsOnInstances;

// ?WorstCount@@3HA
ARTS_IMPORT extern i32 WorstCount;

// ?WorstRoom@@3HA
ARTS_IMPORT extern i32 WorstRoom;
