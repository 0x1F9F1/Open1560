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

define_dummy_symbol(mmbangers_banger);

#include "banger.h"

#include "active.h"
#include "data.h"
#include "dof.h"

#include "mmcity/cullcity.h"
#include "mmphysics/phys.h"
#include "vector7/matrix34.h"

mmBangerInstance::mmBangerInstance()
{
    SetFlags(INST_FLAG_COLLIDER | INST_FLAG_40);
}

mmPhysEntity* mmBangerInstance::AttachEntity()
{
    if (mmBangerActive* entity = BangerActiveMgr()->GetActive(this))
        return entity;

    if (mmBangerActive* entity = BangerActiveMgr()->Attach(this))
        return entity;

    Errorf("mmBangerInstance::AttachEntity - Unable to attach an entity");

    return nullptr;
}

mmBangerData* mmBangerInstance::GetData()
{
    return BangerDataMgr()->GetBangerData(BangerIndex);
}

mmPhysEntity* mmBangerInstance::GetEntity()
{
    return BangerActiveMgr()->GetActive(this);
}

Vector3 mmBangerInstance::GetVelocity()
{
    if (mmBangerActive* entity = BangerActiveMgr()->GetActive(this))
        return entity->ICS.LinearVelocity;

    return Vector3(0.0f, 0.0f, 0.0f);
}

mmUnhitBangerInstance::mmUnhitBangerInstance()
{
    SetFlags(INST_FLAG_UNHIT_BANGER);
}

void mmUnhitBangerInstance::FromMatrix(const Matrix34& matrix)
{
    Position = matrix.m3;
    Angle = Vector2(matrix.m0.x, matrix.m0.z);
}

Vector3& mmUnhitBangerInstance::GetPos()
{
    return Position;
}

b32 mmUnhitBangerInstance::Init(aconst char* name, Vector3& pos1, Vector3& pos2, i32 init_flags, aconst char* part)
{
    BangerIndex = static_cast<i16>(BangerDataMgr()->AddBangerDataEntry(name, part));
    mmBangerData* bng_data = GetData();

    Vector3 cg {};
    Vector3 glow_offset {};

    if (bng_data)
    {
        cg = bng_data->CG;
        glow_offset = bng_data->CG + bng_data->GlowOffset;
    }

    bool is_valid = false;

    InitMeshes(name, MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV, part, &cg);
    InitBreakables(name, part, bng_data);

    if (MeshIndex)
    {
        if (bng_data)
            bng_data->MeshIndex = MeshIndex;

        Matrix34 matrix;

        matrix.m0 = ~Vector3(pos2.x - pos1.x, 0.0f, pos2.z - pos1.z);
        matrix.m1 = Vector3(0.0f, 1.0f, 0.0f);
        matrix.m2 = Vector3(-matrix.m0.z, 0.0f, matrix.m0.x);
        matrix.m3 = pos1;

        matrix.m3 = cg ^ matrix;

        FromMatrix(matrix);

        is_valid = true;
    }

    if ((init_flags & INST_INIT_FLAG_GLOW) && bng_data && (bng_data->BillFlags & BANGER_BILL_FLAG_GLOW))
    {
        AddMeshes(name, MESH_SET_UV | MESH_SET_CPV | MESH_SET_NO_BOUND, "GLOW"_xconst, &glow_offset);

        SetFlags(INST_FLAG_GLOW);
    }

    if (init_flags & INST_INIT_FLAG_TERRAIN)
    {
        SetFlags(INST_FLAG_TERRAIN);
    }

    if (is_valid)
    {
        // TODO: Implement MultiRoomInstance

        CullCity()->ReparentObject(this);

        if (bng_data && bng_data->HasShadows())
            SetFlags(INST_FLAG_SHADOW);
    }

    return is_valid;
}

void mmUnhitBangerInstance::Impact(mmInstance* other, Vector3* position)
{
    // Apply an impact to an unhit banger, converting it into one or more hit bangers.
    // Once this happens, the unhit banger is effectively dead.
    // Since hit bangers are allocated using a circular buffer, old ones will eventually be removed.

    // A banger cannot be impacted until it has an active entity.
    mmBangerActive* old_active = BangerActiveMgr()->GetActive(this);
    ArAssert(old_active, "Banger impacted without active entity");
    ArAssert(this == old_active->Target, "Active entity has incorrect target");

    Matrix34 mat = ToMatrix(mat);
    mmBangerData* data = GetData();

    i16 chain_id = ChainId;
    CullCity()->ObjectsChain.Unparent(this);
    ChainId = chain_id;
    ClearFlags(INST_FLAG_UNHIT_BANGER);

    if (data->NumParts == 0)
    {
        // Convert our active entity directly into a hit banger.
        mmBangerActive* active = old_active;

        mmHitBangerInstance* hit = BangerMgr()->GetBanger();
        CullCity()->ObjectsChain.Parent(hit, ChainId);

        hit->BangerIndex = BangerIndex;
        hit->MeshIndex = MeshIndex;
        hit->SetFlags(GetFlags(INST_FLAG_SHADOW | INST_FLAG_TERRAIN));

        hit->FromMatrix(mat);

        // Transfer ownership of the mmBangerActive
        hit->Owner = std::exchange(Owner, 0_u8);
        active->Target = hit;

        active->ICS.State = ICS_STATE_AWAKE;

        // Replaces our unhit inst with the hit inst, and attaches it to other.
        PHYS.NewMover(hit, this, other);
    }
    else
    {
        // Split into multiple parts, and destroy our current entity.

        Vector3 cg;
        cg.Dot3x3(data->CG, mat);
        mat.m3 -= cg;

        for (i16 i = 0; i < data->NumParts; ++i)
        {
            // Convert our active entity directly into a hit banger.
            mmHitBangerInstance* hit = BangerMgr()->GetBanger();
            CullCity()->ObjectsChain.Parent(hit, ChainId);

            // Set our data to the sub-part
            hit->BangerIndex = BangerIndex + i + 1;
            hit->MeshIndex = MeshIndex + i + 1;

            mmBangerData* part = hit->GetData();

            // Add shadows, only if both parts have shadows
            if (TestFlags(INST_FLAG_SHADOW) && part->HasShadows())
                hit->SetFlags(INST_FLAG_SHADOW);

            cg.Dot3x3(part->CG, mat);
            mat.m3 += cg;
            hit->FromMatrix(mat);
            mat.m3 -= cg;

            mmBangerActive* active = static_cast<mmBangerActive*>(hit->AttachEntity());
            Vector3 impulse = old_active->ICS.LinearImpulse * (active->ICS.Mass / old_active->ICS.Mass);
            active->ICS.ApplyImpulse(impulse, position ? *position : GetPos());
            active->ICS.State = ICS_STATE_AWAKE;

            PHYS.NewMover(hit, (i == 0) ? this : nullptr, other);
        }

        old_active->DetachMe();
    }
}

u32 mmUnhitBangerInstance::SizeOf()
{
    return sizeof(*this);
}

Matrix34& mmUnhitBangerInstance::ToMatrix(Matrix34& matrix)
{
    matrix.m0 = Vector3(Angle.x, 0.0f, Angle.y);
    matrix.m1 = Vector3(0.0f, 1.0f, 0.0f);
    matrix.m2 = Vector3(-Angle.y, 0.0f, Angle.x);
    matrix.m3 = Position;

    return matrix;
}

#ifdef ARTS_DEV_BUILD
void mmBangerInstance::AddWidgets(Bank* /*arg1*/)
{}
#endif

mmHitBangerInstance::mmHitBangerInstance()
{
    SetFlags(INST_FLAG_COLLIDER | INST_FLAG_40);
}

void mmHitBangerInstance::Detach()
{
    if (mmPhysEntity* entity = GetEntity())
        entity->DetachMe();

    if (ChainId != -1)
        CullCity()->ObjectsChain.Unparent(this);
}

void mmHitBangerInstance::FromMatrix(const Matrix34& matrix)
{
    Matrix = matrix;
}

Vector3& mmHitBangerInstance::GetPos()
{
    return Matrix.m3;
}

u32 mmHitBangerInstance::SizeOf()
{
    return sizeof(*this);
}

Matrix34& mmHitBangerInstance::ToMatrix([[maybe_unused]] Matrix34& matrix)
{
    return Matrix;
}

mmHitBangerInstance* mmBangerManager::GetBanger()
{
    mmHitBangerInstance* banger = &Bangers[NextBanger++];

    if (NextBanger == MaxBangers)
        NextBanger = 0;

    if (mmBangerActive* active = BangerActiveMgr()->GetActive(banger))
        active->DetachMe();

    if (banger->ChainId != -1)
        CullCity()->ObjectsChain.Unparent(banger);

    // Clear any flags which may be changed between bangers
    banger->ClearFlags(INST_FLAG_100 | INST_FLAG_SHADOW | INST_FLAG_TERRAIN);

    return banger;
}
