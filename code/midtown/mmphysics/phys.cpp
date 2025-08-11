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

#include "data7/metadefine.h"
#include "memory/alloca.h"
#include "mmbangers/banger.h"
#include "mmcity/cullcity.h"
#include "mmcity/inst.h"
#include "mmcity/instchn.h"
#include "mmdyna/bndtmpl.h"
#include "mmdyna/isect.h"

static constexpr i32 MAX_EBISECTS = 32;
static constexpr i32 MAX_ISECTS = 32;
static constexpr i32 MAX_MOVERS = 256; // Increased from 128
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
    i32 Flags; // MOVER_FLAG_*

    void SetInstance(mmInstance* inst)
    {
        Instance = inst;
        Entity = inst->GetEntity();
    }

    void AddCollider(mmInstance* inst)
    {
        if (NumColliders == MAX_COLLIDABLES_PER_ENTRY)
        {
            Errorf("Reached MAX_COLLIDABLES_PER_ENTRY");
        }
        else if (inst == Instance)
        {
            Errorf("Colliding object against itself");
        }
        else
        {
            Colliders[NumColliders++] = inst;
        }
    }

    void IgnoreCollider(mmInstance* inst)
    {
        for (i32 i = 0; i < NumColliders; ++i)
        {
            if (inst == Colliders[i])
            {
                DisabledColliders[i] = true;
                break;
            }
        }
    }

    void AddMover(mmPhysMover* mover)
    {
        for (i32 i = 0; i < NumMovers; ++i)
        {
            if (Movers[i] == mover)
                return;
        }

        if (NumMovers == MAX_MOVERS_PER_ENTRY)
        {
            Errorf("Reached MAX_MOVERS_PER_ENTRY");
        }
        else
        {
            Movers[NumMovers++] = mover;
        }
    }
};

check_size(mmPhysMover, 0x194);

mmEdgeBodyIsect EBISECTS[MAX_EBISECTS] {};
mmIntersection ISECTS[MAX_ISECTS] {};
mmPhysicsMGR PHYS {};
f32 PhysUpdate = 0.0f;

#ifdef ARTS_DEV_BUILD
ulong ImpactCallbackTime = 0;
ulong ImpactTime = 0;
ulong physCollisions = 0;
ulong physTerrainCollisions = 0;
ulong physUpdate = 0;
#endif

// ?MoverCount@@3HA
ARTS_EXPORT i32 MoverCount = 0;

// ?Movers@@3PAUmmPhysMover@@A
ARTS_EXPORT mmPhysMover Movers[MAX_MOVERS] {};

// ?MoverNeighbours@@3PAFA
ARTS_EXPORT i16 MoverNeighbours[MAX_MOVERS] {};

// ?MoverPositions@@3PAVVector3@@A
ARTS_EXPORT Vector3 MoverPositions[MAX_MOVERS] {};

// ?MoverRadiuses@@3PAMA
ARTS_EXPORT f32 MoverRadiuses[MAX_MOVERS] {};

static mmPhysMover* GetInstMover(mmInstance* inst)
{
    for (i32 i = 0; i < MoverCount; ++i)
    {
        mmPhysMover* mover = &Movers[i];

        if (inst == mover->Instance)
        {
            return mover;
        }
    }

    return nullptr;
}

void mmPhysExec::Update()
{
    if (OnlyPlayer)
        DoUpdatePlayerOnly();
    else
        DoUpdateAll();
}

mmPhysicsMGR::mmPhysicsMGR()
{
    if (Instance)
        Quitf("Can only have one physmgr at a time");

    Instance = this;

    AddChild(&OverSample);
    OverSample.AddChild(&PhysExec);
    OverSample.RealTime(35.0f);

    DrawBounds = true;

    // The original code relied on CylinderCollisions to properly detect collisions,
    // but now that's been fixed, it shouldn't be necessary.
    CylinderCollisions = false;

    EnableCachedPoly = true;

    Reset();
}

mmPhysicsMGR::~mmPhysicsMGR()
{
    Instance = nullptr;
}

void mmPhysicsMGR::DeclareMover(mmInstance* inst, i32 type, i32 flags)
{
    i16 room = inst->ChainId;

    if (room == -1)
    {
        Errorf("PHYS.DeclareMover: An unparented instance is being declared to the PhysMGR - ignoring it.");
        inst->Detach();
        return;
    }

    if (type == MOVER_TYPE_PERM)
    {
        AddActiveRoom(room);

        asPortalCell* cells[20];
        i32 count = CullCity()->RenderWeb.GetCellNeighbors(room, cells, ARTS_SSIZE32(cells));

        for (i32 i = 0; i < count; ++i)
        {
            AddActiveRoom(cells[i]->CellIndex);
        }
    }
    else if (type == MOVER_TYPE_TEMP)
    {
        // Temporary movers disappear once their room is inactive.
        if (!IsRoomActive(room))
        {
            inst->Detach();
            return;
        }
    }

    if (mmPhysMover* mover = GetInstMover(inst))
    {
        mover->Flags |= flags;
    }
    else if (MoverCount < MAX_MOVERS)
    {
        mover = &Movers[MoverCount++];
        mover->SetInstance(inst);
        mover->Flags = flags;
    }
    else
    {
        Errorf("PHYS.DeclareMover: raise MAX_MOVERS past %d", MoverCount);
    }

    // FIXME: Banger projectiles can be spawned before the player's mover is declared.
    // if (inst == PHYS.PlayerInst)
    // {
    //     ArAssert(GetInstMover(inst) == &Movers[0], "First mover is not the player!");
    // }
}

void mmPhysicsMGR::IgnoreMover(mmInstance* inst)
{
    if (mmPhysMover* mover = GetInstMover(inst))
    {
        mover->Flags = 0;
        mover->NumMovers = 0;
        mover->NumColliders = 0;
        // mover->Instance = nullptr;
        // mover->Entity = nullptr;
    }
}

void mmPhysicsMGR::NewMover(mmInstance* inst)
{
    mmPhysMover* mover = GetInstMover(inst);

    if (!mover)
    {
        if (MoverCount >= MAX_MOVERS)
        {
            Errorf("PHYS.NewMover(1): raise MAX_MOVERS past %d", MoverCount);
            return;
        }

        mover = &Movers[MoverCount++];
    }

    mover->SetInstance(inst);
}

void mmPhysicsMGR::NewMover(mmInstance* inst, mmInstance* other)
{
    // This is called by CollideInstances after two instances have collided, and at least one of them did not have an entity.

    mmPhysMover* mover = GetInstMover(inst);

    if (!mover)
    {
        Errorf("PHYS.NewMover(2): not a mover");
        return;
    }

    mover->SetInstance(inst);

    mmPhysMover* other_mover = GetInstMover(other);

    if (!other_mover)
    {
        if (MoverCount >= MAX_MOVERS)
        {
            Errorf("PHYS.NewMover(2): raise MAX_MOVERS past %d", MoverCount);
            return;
        }

        other_mover = &Movers[MoverCount++];
    }

    other_mover->SetInstance(other);

    // Each mover is first collided with other movers, then with other instances.
    // If we've collided with this instance, make sure we don't collide with it again.
    other_mover->IgnoreCollider(inst);

    // I'm not really sure when we should link movers to each other.
    // They are usually gathered at the start of each frame.
    other_mover->AddMover(mover);
}

void mmPhysicsMGR::NewMover(mmInstance* new_inst, mmInstance* old_inst, mmInstance* other)
{
    if (old_inst)
    {
        for (i32 i = 0; i < MoverCount; ++i)
        {
            mmPhysMover* mover = &Movers[i];
            mover->IgnoreCollider(old_inst);
        }
    }

    mmPhysMover* other_mover = GetInstMover(other);

    if (!other_mover)
    {
        Errorf("PHYS.NewMover(3): not able to find other's entry");
        return;
    }

    if (MoverCount >= MAX_MOVERS)
    {
        Errorf("PHYS.NewMover(3): raise MAX_MOVERS past %d", MoverCount);
        return;
    }

    mmPhysMover* mover = &Movers[MoverCount++];
    mover->SetInstance(new_inst);
    other_mover->AddMover(mover);
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

void mmPhysicsMGR::GatherCollidables(i32 mover_id, i32 inst_flags)
{
    mmPhysMover* mover = &Movers[mover_id];
    mover->NumColliders = 0;

    if (i32 room = mover->Instance->ChainId; room != -1)
        GatherRoomCollidables(mover_id, mover->Instance->ChainId, inst_flags);

    if (i16 room = MoverNeighbours[mover_id]; room != -1)
        GatherRoomCollidables(mover_id, room, inst_flags);
}

void mmPhysicsMGR::GatherRoomCollidables(i32 mover_id, i16 room, i32 inst_flags)
{
    ArAssert(room != -1, "Invalid room");

    mmPhysMover* mover = &Movers[mover_id];
    u16 test_flags = static_cast<u16>(inst_flags ? inst_flags : INST_FLAG_COLLIDER);

    for (mmInstance* inst = ObjectsChain->Chains[room]; inst; inst = inst->ChainNext)
    {
        if (inst->TestFlags(test_flags) && (inst != mover->Instance) && TrivialCollideInstances(inst, mover->Instance))
        {
            mover->AddCollider(inst);
        }
    }
}

bool mmPhysicsMGR::IsRoomActive(i16 room) const
{
    for (i32 i = 0; i < NumActiveRooms; ++i)
    {
        if (room == ActiveRooms[i])
            return true;
    }

    return false;
}

void mmPhysicsMGR::AddActiveRoom(i16 room)
{
    if (!IsRoomActive(room) && (NumActiveRooms < MAX_ACTIVE_ROOMS))
    {
        ActiveRooms[NumActiveRooms++] = room;
    }
}

b32 mmPhysicsMGR::TrivialCollideInstances(mmInstance* inst_1, mmInstance* inst_2)
{
    mmBoundTemplate* bound_1 = inst_1->GetBound();
    mmBoundTemplate* bound_2 = inst_2->GetBound();

    // The original code did not use the bound's Center, even though the Radius is based off that point.
    Vector3 center_1 = bound_1->Center;
    Vector3 center_2 = bound_2->Center;

    f32 radius_1 = bound_1->Radius;
    f32 radius_2 = bound_2->Radius;

    bool ignore_y = false;

    // TODO: Remove CylinderCollisions if no issues are found without it.
    if (CylinderCollisions)
    {
        if (inst_1->TestFlags(INST_FLAG_UNHIT_BANGER))
        {
            if (mmBangerData* data = static_cast<mmBangerInstance*>(inst_1)->GetData(); data && (data->YRadius != 0.0f))
            {
                radius_1 = data->YRadius;
                center_1 = -data->CG;
                ignore_y = true;
            }
        }

        if (inst_2->TestFlags(INST_FLAG_UNHIT_BANGER))
        {
            if (mmBangerData* data = static_cast<mmBangerInstance*>(inst_2)->GetData(); data && (data->YRadius != 0.0f))
            {
                radius_2 = data->YRadius;
                center_2 = -data->CG;
                ignore_y = true;
            }
        }
    }

    Matrix34 mat;
    Vector3 pos_1 = center_1 ^ inst_1->ToMatrix(mat);
    Vector3 pos_2 = center_2 ^ inst_2->ToMatrix(mat);

    if (ignore_y)
    {
        pos_2.y = pos_1.y;
    }

    f32 max_dist = radius_1 + radius_2;

    return pos_1.Dist2(pos_2) < (max_dist * max_dist);
}

META_DEFINE_CHILD("mmPhysicsMGR", mmPhysicsMGR, asNode)
{
    META_FIELD("Gravity", Gravity);
}