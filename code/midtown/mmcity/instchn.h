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
    mmcity:instchn

    0x492280 | public: __thiscall mmInstChain::mmInstChain(void) | ??0mmInstChain@@QAE@XZ
    0x492290 | public: __thiscall mmInstChain::~mmInstChain(void) | ??1mmInstChain@@QAE@XZ
    0x4922B0 | public: void __thiscall mmInstChain::Init(int) | ?Init@mmInstChain@@QAEXH@Z
    0x492310 | public: void __thiscall mmInstChain::Parent(class mmInstance *,short) | ?Parent@mmInstChain@@QAEXPAVmmInstance@@F@Z
    0x4923A0 | public: void __thiscall mmInstChain::Unparent(class mmInstance *) | ?Unparent@mmInstChain@@QAEXPAVmmInstance@@@Z
    0x492440 | public: void __thiscall mmInstChain::Reparent(class mmInstance *,short) | ?Reparent@mmInstChain@@QAEXPAVmmInstance@@F@Z
    0x492470 | public: void __thiscall mmInstChain::RelightEverything(void) | ?RelightEverything@mmInstChain@@QAEXXZ
    0x492490 | public: void __thiscall mmInstChain::Relight(short) | ?Relight@mmInstChain@@QAEXF@Z
    0x4924C0 | public: void __thiscall mmInstChain::Draw(short,short,unsigned int,int,float) | ?Draw@mmInstChain@@QAEXFFIHM@Z
    0x492980 | public: void __thiscall mmInstChain::AddWidgets(class Bank *) | ?AddWidgets@mmInstChain@@QAEXPAVBank@@@Z
    0x63F6B4 | int EnableSphereCull | ?EnableSphereCull@@3HA
    0x6ED4E4 | int WorstRoom | ?WorstRoom@@3HA
    0x6ED4E8 | int LabelInstances | ?LabelInstances@@3HA
    0x6ED4EC | int WorstCount | ?WorstCount@@3HA
    0x6ED4F0 | int NormalsOnInstances | ?NormalsOnInstances@@3HA
*/

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
    ARTS_IMPORT void Parent(mmInstance* arg1, i16 arg2);

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
