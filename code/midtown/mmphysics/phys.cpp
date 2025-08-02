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

define_dummy_symbol(mmphysics_phys);

#include "phys.h"

#include "entity.h"
#include "memory/alloca.h"
#include "mmcity/inst.h"
#include "mmcity/instchn.h"
#include "mmdyna/bndtmpl.h"
#include "mmdyna/isect.h"

static constexpr i32 MAX_MOVERS = 128;
static constexpr i32 MAX_COLLIDABLES_PER_ENTRY = 32;
static constexpr i32 MAX_MOVERS_PER_ENTRY = 32;

struct mmPhysMover
{
    mmInstance* Instance;
    mmPhysEntity* Entity;
    i32 NumColliders;
    i32 NumMovers;
    b32 DisabledColliders[MAX_COLLIDABLES_PER_ENTRY];
    mmInstance* Colliders[MAX_COLLIDABLES_PER_ENTRY];
    mmPhysMover* Movers[MAX_MOVERS_PER_ENTRY];
    i32 Flags;
};

check_size(mmPhysMover, 0x194);

ARTS_IMPORT i32 MoverCount;
ARTS_IMPORT mmPhysMover Movers[MAX_MOVERS];

void mmPhysExec::Update()
{
    if (OnlyPlayer)
        DoUpdatePlayerOnly();
    else
        DoUpdateAll();
}

void mmPhysicsMGR::IgnoreMover(mmInstance* inst)
{
    for (i32 i = 0; i < MoverCount; ++i)
    {
        if (mmPhysMover* mover = &Movers[i]; mover->Instance == inst)
        {
            // TODO: Set mover->[Instance/Entity] = nullptr;
            mover->Flags = 0;
        }
    }
}

b32 mmPhysicsMGR::CollideProbe(i16 room, mmIntersection* isect, i32 flags)
{
    for (mmInstance* inst = ObjectsChain->Chains[room]; inst; inst = inst->ChainNext)
    {
        if (!(inst->Flags & flags))
            continue;

        mmBoundTemplate* bound = inst->GetBound();

        if (bound == nullptr)
        {
            Errorf("Attemptimg to collide probe against instance with no bound template");
            continue;
        }

        Matrix34 world = inst->ToMatrix(world);
        Matrix34 inv_world = world.FastInverse();
        isect->Transform(&inv_world);

        // FIXME: This assumes the first collision is the "best" one
        if (bound->Collide(isect))
        {
            isect->Position.Dot(isect->Position, world);
            isect->Normal.Dot3x3(isect->Normal, world);
            return true;
        }
    }

    return false;
}