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

define_dummy_symbol(mmcar_car);

#include "car.h"

#include "data7/timer.h"
#include "mmcity/cullcity.h"
#include "mmphysics/joint3dof.h"

#include "trailer.h"

void mmCar::PostUpdate()
{
#ifdef ARTS_DEV_BUILD
    Timer t;
#endif

    if (Model.CarFlags & CAR_MODEL_FLAG_TRAILER)
    {
        Trailer->PostUpdate();

        if (TrailerJoint->IsActive())
            TrailerJoint->MoveICS();
    }
    else
    {
        Sim.ICS.MoveICS();
    }

    FLSkid.Update();
    FRSkid.Update();
    BLSkid.Update();
    BRSkid.Update();

    Shards.Update();

    Sim.ExhaustPtx.Update();
    Sim.GrassPtx.Update();
    Sim.ExplosionPtx.Update();

#ifdef ARTS_DEV_BUILD
    f32 elapsed = t.Time();
    mmCar::PostUpdateTime += elapsed;
    mmCar::TotalUpdateTime += elapsed;
#endif

    CullCity()->ReparentObject(&Model);
}

void mmCar::ReleaseTrailer()
{
    if (Model.CarFlags & CAR_MODEL_FLAG_TRAILER)
    {
        TrailerJoint->BreakJoint();
        Trailer->SetHackedImpactParams();
    }
}

run_once([] {
    static const f32 spark_multiplier = 16.0f / 30.0f;
    create_patch("mmCar::Impact", "Spark Count", 0x47422C, "\xD9\xE8\x90\x90\x90\x90", 6);
    create_packed_patch<const void*>("mmCar::Impact", "Spark Count", 0x474235 + 2, &spark_multiplier);
});
