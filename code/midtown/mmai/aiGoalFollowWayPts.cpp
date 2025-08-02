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

define_dummy_symbol(mmai_aiGoalFollowWayPts);

#include "aiGoalFollowWayPts.h"

#include "mmcar/car.h"
#include "mmcityinfo/state.h"

#include "aiData.h"
#include "aiMap.h"
#include "aiPath.h"
#include "aiVehicleOpponent.h"

b32 aiGoalFollowWayPts::Context()
{
    if (Car->Sim.CurrentDamage <= Car->Sim.MaxDamageScaled)
    {
        return (*BackingUp != 1) && (*IsFinished == 0);
    }
    else if (MMSTATE.GameMode == mmGameMode::Circuit && DamageState == 1 && Time.Time() > 5.0f)
    {
        DamageState = 0;
        Car->ClearDamage();
        return true;
    }
    else
    {
        if (!DamageState)
        {
            Time.Reset();
            DamageState = 1;
        }

        Car->Sim.Steering = 0.0f;
        Car->Sim.Engine.Throttle = 0.0f;
        Car->Sim.Brakes = 0.0f;

        Car->Sim.ICS.LinearMomentum *= 0.95f;

        return false;
    }
}

i32 aiGoalFollowWayPts::GetWayPtId(i16 index)
{
    if (index < 0 || index > NumWayPts)
    {
        Warningf("Check Point Index: %d, is outside of the array bounds.", index);
        Warningf("Requested by: Opp %d.", Vehicle->OppId);
        index = NumWayPts;
    }

    return WayPtIds[index];
}

void aiGoalFollowWayPts::Update()
{
    ++UpdateCount;

    if (Car->Sim.ICS.Constraints & (ICS_CONSTRAIN_TX | ICS_CONSTRAIN_TZ))
    {
        if (Car->Sim.FrontLeft.OnGround)
        {
            Car->Sim.Steering = 0.0f;
            Car->Sim.Brakes = 0.0f;
            Car->Sim.Engine.Throttle = 1.0f;
        }

        return;
    }

    Stuck.Update();

    if (Car->Sim.Stuck.State == CAR_STUCK)
    {
        PlanRoute();
        *BackingUp = true;
        Car->Sim.ICS.LinearMomentum = {};
        Car->Sim.ICS.AngularMomentum = {};
        UpdateCount = 0;
        return;
    }

    if (Stuck.State == CAR_STUCK)
    {
        Car->Sim.Steering = 1.0f;
        Car->Sim.Brakes = 0.0f;
        Car->Sim.Engine.Throttle = 1.0f;
        Car->Sim.Stuck.State = CAR_NOT_STUCK;
        return;
    }

    i16 path_id = -1;

    if (WayPtIdx > 1 && WayPtIdx < NumWayPts - 1)
    {
        aiIntersection* prev_isect = AIMAP.Intersection(GetWayPtId(WayPtIdx - 1));
        aiIntersection* next_isect = AIMAP.Intersection(GetWayPtId(WayPtIdx));
        aiPath* path = DetRdSegBetweenInts(prev_isect, next_isect);
        path_id = path->Id;
    }

    i16 out_index = 0;

    CurMapCompIdx =
        static_cast<i16>(AIMAP.DetermineOppMapComponent(Car->Sim.ICS.Matrix, Rail, &CurMapCompType, &CurRdVertIdx,
            &Rail->RoadDist, &DistToSide, &out_index, &TargetPtOffset, Car->Sim.Speed, LastMapCompType, path_id));

    PlanRoute();

    if (Rail->NextLink)
    {
        Rail->NextLink->StopDestinationSources(true);
    }

    if (i32 dist_to_side = 0; !Vehicle->IsSemi && DetectCollision(&dist_to_side))
    {
        AvoidCollision(dist_to_side);
    }
    else if (aiVehicleOpponent* opp = DetectOpponentCollision())
    {
        AvoidOpponentCollision(opp);
    }
    else
    {
        SolveTargetPoint();
    }

    Vector3 target_dir = TargetPt - Car->Sim.ICS.Matrix.m3;
    f32 angle = std::atan2(target_dir ^ Car->Sim.ICS.Matrix.m0, target_dir ^ -Car->Sim.ICS.Matrix.m2);

    Steering = std::clamp(angle, -1.0f, 1.0f);

    if (Car->Model.Flags & INST_FLAG_COLLIDED_PLAYER)
    {
        *Car->Sim.Realism = 1.0f;
    }
    else
    {
        *Car->Sim.Realism = 0.0f;

        if (angle < 0.1f && angle > -0.1f)
        {
            Car->Sim.ICS.AngularMomentum *= 0.1f;
        }
    }

    Car->Sim.Steering = Steering;
    Car->Sim.Brakes = Brakes;
    Car->Sim.Engine.Throttle = Throttle;

    LastMapCompType = CurMapCompType;
}
