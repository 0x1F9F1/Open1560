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

define_dummy_symbol(mmai_aiVehicleMGR);

#include "aiVehicleMGR.h"

#include "aiVehicleSpline.h"
#include "mmcity/cullcity.h"
#include "mmdyna/isect.h"
#include "mmphysics/phys.h"

f32 EggMass = 1.0f;

void aiVehicleInstance::Detach()
{
    if (mmPhysEntity* entity = GetEntity())
        entity->DetachMe();

    if (ChainId != -1)
        CullCity()->ObjectsChain.Unparent(this);
}

void aiVehicleActive::Attach(aiVehicleInstance* inst)
{
    aiVehicleData* data = inst->GetData();

    inst->Flags &= ~INST_FLAG_COLLIDER;
    inst->Owner = static_cast<u8>(VehicleIndex + 1);

    ICS.Zero();
    ICS.Matrix = inst->ToMatrix(ICS.Matrix);
    ICS.World = inst->ToMatrix(ICS.World);
    ICS.State = ICS_STATE_AWAKE;
    Inst = inst;

    ICS.SetMass(data->Size.x, data->Size.y, data->Size.z, data->Mass * EggMass);
    ICS.Friction = data->Friction;
    ICS.Elasticity = data->Elasticity;

    MaxDamage = data->MaxDamage;
    ICS.State = ICS_STATE_AWAKE;
    Bound.AudioId = data->SoundId;

    ICS.LinearVelocity = inst->Spline->Matrix->m2 * -inst->Spline->CurSpeed;
    ICS.LinearMomentum = ICS.LinearVelocity * ICS.Mass;

    WheelFL.Init(&data->FLOff, data, &ICS);
    WheelFR.Init(&data->FROff, data, &ICS);
    WheelBL.Init(&data->BLOff, data, &ICS);
    WheelBR.Init(&data->BROff, data, &ICS);

    ICS.Update();
}

void aiVehicleActive::Detach()
{
    if (Inst == nullptr)
        return;

    bool return_to_rail = Damage <= MaxDamage;

    mmIntersection isect;
    isect.InitSegment(ICS.Matrix.m3 + ICS.Matrix.m1 * 0.5f, ICS.Matrix.m3 - ICS.Matrix.m1 * 3.0f, nullptr, 2, 0);

    if (!PHYS.Collide(&isect, PHYS_COLLIDE_ROOM) || (ICS.Matrix.m1 ^ isect.Normal) < 0.9f)
        return_to_rail = false;

    if (Inst->Flags & INST_FLAG_40)
        return_to_rail = false;

    if (return_to_rail)
        Inst->Spline->Impact(0);
    else
        Inst->Flags |= INST_FLAG_40;

    Inst->Flags |= INST_FLAG_COLLIDER;
    Inst->Owner = 0;

    PHYS.IgnoreMover(Inst);

    Inst = nullptr;
    Damage = 0.0f;
}

void aiVehicleActive::DetachMe()
{
    Detach();
    AiVehicleManager()->Detach(this);
}

#ifdef ARTS_DEV_BUILD
void aiVehicleInstance::AddWidgets(Bank* /*arg1*/)
{}
#endif
