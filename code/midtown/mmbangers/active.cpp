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

define_dummy_symbol(mmbangers_active);

#include "active.h"

#include "arts7/sim.h"
#include "banger.h"
#include "data.h"
#include "mmcity/cullcity.h"
#include "mmphysics/phys.h"

mmBangerActiveManager* mmBangerActiveManager::Instance = nullptr;

mmBangerActive::mmBangerActive()
{
    AddChild(&ICS);
    ICS.AddChild(&Bound);

    ICS.LimitAngVelocity = true;
    ICS.State = ICS_STATE_AWAKE;
    ICS.Vel2 = 0.5f;
    ICS.AngVel2 = 0.5f;
    ICS.Time = 0.5f;

    Bound.ICS = &ICS;

    Particles.Init(64, 2, 2, 4, agiMeshSet::DefaultQuad);
}

mmBangerActive::~mmBangerActive() = default;

void mmBangerActive::Attach(mmBangerInstance* inst)
{
    inst->ClearFlags(INST_FLAG_COLLIDER);
    inst->SetFlags(INST_FLAG_MOVER);
    inst->Owner = static_cast<u8>(Index + 1);

    mmBangerData* banger = inst->GetData();

    ICS.Zero();
    ICS.Matrix = inst->ToMatrix(ICS.Matrix);
    ICS.World = inst->ToMatrix(ICS.World);

    Target = inst;

    ICS.SetMass(banger->Size.x, banger->Size.y, banger->Size.z, banger->Mass);
    ICS.Elasticity = banger->Elasticity;
    ICS.Friction = banger->Friction;
    ICS.State = ICS_STATE_AWAKE;
    ICS.ImpulseLimit2 = banger->ImpulseLimit2;
    Bound.AudioId = banger->AudioId;

    Particles.Reset();

    if (banger->TexNumber)
    {
        Particles.SetTexture(BangerDataMgr()->GetParticleTexture(banger->TexNumber - 1));

        Vector3 old_velocity = banger->BirthRule.Velocity;

        if (banger->BirthRule.BirthFlags & asBirthRule::kStationary)
        {
            if (!inst->TestFlags(INST_FLAG_UNHIT_BANGER))
                return;

            banger->BirthRule.Position = ICS.World.m3;
        }
        else
        {
            Particles.SetMatrix(&ICS.World);

            // FIXME: This should really use the banger velocity, but that is only set after attaching
            if (asInertialCS* player = PHYS.GetPlayerICS())
                banger->BirthRule.Velocity += player->LinearVelocity;
        }

        Particles.SetBirthRule(&banger->BirthRule);
        Particles.Blast(static_cast<i32>(banger->BirthRule.InitialBlast * ParticleMultiplier), nullptr);

        banger->BirthRule.Velocity = old_velocity;
    }
}

void mmBangerActive::Detach()
{
    if (Target == nullptr)
        return;

    PHYS.IgnoreMover(Target);

    ICS.State = ICS_STATE_AWAKE;

    Target->SetFlags(INST_FLAG_COLLIDER);
    Target->ClearFlags(INST_FLAG_MOVER);
    Target->Owner = 0;

    Target = nullptr;
}

void mmBangerActive::DetachMe()
{
    Detach();
    BangerActiveMgr()->Detach(this);
}

void mmBangerActive::PostUpdate()
{
    if (ICS.State != ICS_STATE_ASLEEP && ICS.Matrix.m3.y >= -100.0f)
    {
        ICS.MoveICS();

        Target->FromMatrix(ICS.Matrix);
        CullCity()->ReparentObject(Target);

        ICS.State = (CullCity()->GetRoomFlags(Target->ChainId) & ROOM_FLAG_10) ? ICS_STATE_OFF : ICS_STATE_AWAKE;
    }
    else
    {
        DetachMe();
    }
}

void mmBangerActive::Update()
{
    asNode::Update();

    Target->FromMatrix(ICS.Matrix);
    CullCity()->ReparentObject(Target);

    if (Sim()->IsFullUpdate() && Particles.GetNumActive())
    {
        // TODO: Use Particles.GetBirthRule() instead?
        Vector3& ptx_velocity = Target->GetData()->BirthRule.Velocity;
        Vector3 old_velocity = std::exchange(ptx_velocity, ICS.LinearVelocity);
        Particles.Update();
        ptx_velocity = old_velocity;
    }
}

mmBangerActiveManager::mmBangerActiveManager()
{
    ArAssert(Instance == nullptr, "Already have mmBangerActiveManager");
    Instance = this;

    for (i32 i = 0; i < MAX_ACTIVE_BANGERS; ++i)
    {
        mmBangerActive* active = &Bangers[i];
        active->Index = i;
        Active[i] = active;
    }
}

mmBangerActiveManager::~mmBangerActiveManager()
{
    ArAssert(Instance == this, "Invalid mmBangerActiveManager");
    Instance = nullptr;
}

mmBangerActive* mmBangerActiveManager::Attach(mmBangerInstance* inst)
{
    // Check if the banger is already attached
    // TODO: Check inst->Owner instead?
    for (i32 i = 0; i < NumActive; ++i)
    {
        if (Active[i]->Target == inst)
        {
            Errorf("Banger's already attached");
            return nullptr;
        }
    }

    if (NumActive < MAX_ACTIVE_BANGERS)
    {
        mmBangerActive* active = Active[NumActive++];
        active->Attach(inst);
        return active;
    }

    // Find and replace the oldest active banger
    i32 best_index = 0;
    f32 best_count = Active[0]->ICS.Counter;

    for (i32 i = 1; i < MAX_ACTIVE_BANGERS; ++i)
    {
        if (f32 count = Active[i]->ICS.Counter; count >= best_count)
        {
            best_count = count;
            best_index = i;
        }
    }

    mmBangerActive* active = Active[best_index];
    active->Detach();
    active->Attach(inst);

    return active;
}

void mmBangerActiveManager::Detach(mmBangerActive* active)
{
    for (i32 i = 0; i < NumActive; ++i)
    {
        if (Active[i] == active)
        {
            --NumActive;
            Active[i] = Active[NumActive];
            Active[NumActive] = active;
            break;
        }
    }
}

mmBangerActive* mmBangerActiveManager::GetActive(mmBangerInstance* inst)
{
    return inst->Owner ? &Bangers[inst->Owner - 1] : nullptr;
}

void mmBangerActiveManager::Reset()
{
    while (NumActive)
    {
        --NumActive;

        Active[NumActive]->Detach();
    }
}

void mmBangerActiveManager::Update()
{
    // TODO: Is there a better way to avoid updating while paused?
    if (Sim()->IsPaused())
        return;

    for (i32 i = 0; i < NumActive; ++i)
    {
        mmBangerActive* active = Active[i];
        mmBangerInstance* target = active->Target;
        ArAssert(target->SizeOf() == sizeof(mmHitBangerInstance), "Invalid Banger");

        i16 banger_type = target->GetData()->CollisionType;

        if (banger_type == BANGER_COLLISION_TYPE_1)
        {
            active->Update();
            active->PostUpdate();
        }
        else
        {
            i32 mover_type = (banger_type == BANGER_COLLISION_TYPE_6) ? MOVER_TYPE_PERM : MOVER_TYPE_TEMP;
            i32 mover_flags = MOVER_FLAG_ACTIVE;

            if (banger_type != BANGER_COLLISION_TYPE_2)
                mover_flags |= MOVER_FLAG_COLLIDE_TERRAIN | MOVER_FLAG_COLLIDE_MOVERS;

            PHYS.DeclareMover(target, mover_type, mover_flags);
        }
    }
}
