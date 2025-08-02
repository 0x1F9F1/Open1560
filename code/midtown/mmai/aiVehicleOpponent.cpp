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

define_dummy_symbol(mmai_aiVehicleOpponent);

#include "aiVehicleOpponent.h"

#include "aiData.h"
#include "aiGoalBackup.h"
#include "aiGoalFollowWayPts.h"
#include "aiGoalStop.h"

#include "agi/dlptmpl.h"
#include "agi/getdlp.h"
#include "agiworld/quality.h"
#include "dyna7/gfx.h"
#include "mmai/aiaudiomanager.h"
#include "mmdyna/poly.h"
#include "mmphysics/joint3dof.h"
#include "mmphysics/phys.h"

void aiVehicleOpponent::DrawDamage()
{}

void aiVehicleOpponent::DrawTargetPt()
{
    DrawColor(ColPurple);

    Vector3 car_pos = Car.Sim.ICS.Matrix.m3;
    Vector3 target_pt = WayPts->TargetPt;
    target_pt.y = car_pos.y;

    mmIntersection isect;
    isect.InitSegment(target_pt + Vector3(0.0f, 5.0f, 0.0f), target_pt - Vector3(0.0f, 5.0f, 0.0f), nullptr, 2, 0);
    PHYS.Collide(&isect, PHYS_COLLIDE_ROOM);

    if (isect.HitPoly)
    {
        target_pt.y = isect.HitPoly->GetPlaneY(target_pt.x, target_pt.z) + 0.5f;
    }

    Vector3 line_pos = car_pos + Vector3(0.0f, 0.5f, 0.0f);
    DrawLine(line_pos, target_pt);

    Vector3 label_pos = car_pos + Vector3(0.0f, 0.5f, 0.0f);
    DrawLabelf(label_pos,
        "MPH:      %.2f\n"
        "Steering: %.2f\n"
        "Throttle: %.2f\n"
        "Brakes:   %.2f"_xconst,
        Car.Sim.SpeedMPH, Car.Sim.Steering, Car.Sim.Engine.Throttle, Car.Sim.Brakes);

    DrawColor(ColLightCyan);

    RailSet.DrawTurn(WayPts->DistToSide);
}

void aiVehicleOpponent::Init(i32 opp_id, aiRaceData* race_data, char* race_name)
{
    // TODO: Use all paint jobs
    i32 paint_job = opp_id & 3;
    i32 index = opp_id + 1;

    OpponentRaceData* opp = static_cast<OpponentRaceData*>(race_data->Opponents.Access(index));

    Car.Init(opp->Model, CAR_TYPE_OPPONENT, paint_job);

    aiVehicle::Init(opp_id);
    Car.Reset();

    WayPts = arnew aiGoalFollowWayPts(
        opp->PathFile, &RailSet, this, &IsBackup, &IsFinished, &IsStopped, xconst(race_name), opp->MaxThrottle);

    BackupGoal = arnew aiGoalBackup(&RailSet, &Car, &IsBackup);

    StopGoal = arnew aiGoalStop(&Car, &IsStopped);

    IsSemi = !std::strcmp("vpsemi", opp->Model);

    DLPTemplate* dlp = GetDLPTemplate(opp->Model);

    if (dlp)
    {
        Vector3 min, max;
        dlp->BoundBox(min, max, "BODY_H"_xconst);

        RailSet.FrontBumperDist = -min.z;
        RailSet.LSideDist = -min.x;
        RailSet.BackBumperDist = max.z;
        RailSet.RSideDist = max.x;
    }

    AudIndexNumber = -1;
}

void aiVehicleOpponent::Reset()
{
    IsBackup = false;
    IsStopped = false;
    IsFinished = false;

    WayPts->Init();
    BackupGoal->Init();
    StopGoal->Init();

    Goals.Kill();
    Goals.Append(WayPts.get());
    Goals.Append(StopGoal.get());
    Goals.Append(BackupGoal.get());

    if (AudIndexNumber != -1)
    {
        AiAudMgr()->RemoveVehicle(this, AudIndexNumber);
        AudIndexNumber = -1;
    }

    if (Car.Model.HasTrailer())
        Car.TrailerJoint->UnbreakJoint();

    Car.Reset();

    aiVehicle::Reset();
}
