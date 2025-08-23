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

define_dummy_symbol(mmcity_instchn);

#include "instchn.h"

#include "inst.h"

b32 EnableSphereCull = true;
b32 LabelInstances = false;
b32 NormalsOnInstances = false;
i32 WorstCount = 0;
i32 WorstRoom = 0;

void mmInstChain::Init(i32 num_rooms)
{
    Chains = arnewa mmInstance * [num_rooms] {};
    ChainCounts = arnewa i16[num_rooms] {};
    NumChains = num_rooms;
}

void mmInstChain::Parent(mmInstance* inst, i16 room)
{
    ArAssert(inst->ChainId == -1, "Instance is already parented");
    ArAssert(room >= 0 && room < NumChains, "Invalid room");

    inst->ChainPrev = nullptr;

    mmInstance* next = Chains[room];
    inst->ChainNext = next;
    if (next)
        next->ChainPrev = inst;

    Chains[room] = inst;
    ++ChainCounts[room];
    inst->ChainId = room;
}

void mmInstChain::Reparent(mmInstance* inst, i16 room)
{
    Unparent(inst);
    Parent(inst, room);
}

void mmInstChain::Unparent(mmInstance* inst)
{
    ArAssert(inst->ChainId != -1, "Instance is not parented");
    ArAssert(inst->ChainId >= 0 && inst->ChainId < NumChains, "Invalid inst room");

    if (mmInstance* prev = inst->ChainPrev)
        prev->ChainNext = inst->ChainNext;
    else
        Chains[inst->ChainId] = inst->ChainNext;

    if (mmInstance* next = inst->ChainNext)
        next->ChainPrev = inst->ChainPrev;

    --ChainCounts[inst->ChainId];
    inst->ChainId = -1;
}

void mmInstChain::Relight(i16 room)
{
    for (mmInstance* i = Chains[room]; i; i = i->ChainNext)
        i->Relight();
}

void mmInstChain::RelightEverything()
{
    for (i16 i = 0; i < NumChains; ++i)
        Relight(i);
}

#ifdef ARTS_DEV_BUILD
void mmInstChain::AddWidgets(Bank* /*arg1*/)
{}
#endif
