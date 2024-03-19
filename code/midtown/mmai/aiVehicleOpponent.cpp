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

#include "agi/dlptmpl.h"
#include "agi/getdlp.h"
#include "agiworld/quality.h"
#include "dyna7/gfx.h"
#include "mmdyna/poly.h"
#include "mmphysics/phys.h"

#include "aiData.h"
#include "aiGoalBackup.h"
#include "aiGoalFollowWayPts.h"
#include "aiGoalStop.h"

void aiVehicleOpponent::DrawDamage()
{}

void aiVehicleOpponent::DrawTargetPt()
{
    DrawColor(ColPurple);

    Vector3 base_pos = Car.Sim.ICS.Matrix.m3;

    Vector3 car_pos = base_pos;
    car_pos.y += 1.0f;

    Vector3 target_pt = WayPts->TargetPt;
    target_pt.y += 1.0f;

    mmIntersection isect;
    isect.InitSegment(car_pos, target_pt, nullptr, 2, 0);

    PHYS.Collide(&isect, PHYS_COLLIDE_ROOM);

    if (isect.HitPoly)
    {
        target_pt.y = (-isect.HitPoly->PlaneD - isect.HitPoly->PlaneN.z * target_pt.z - isect.HitPoly->PlaneN.x * target_pt.x) / isect.HitPoly->PlaneN.y - -0.5f;
    }

    DrawLine(car_pos, target_pt);

    Vector3 speed_label = base_pos;
    speed_label.y += 0.5f;

    Vector3 steering_label = base_pos;
    steering_label.y += 0.25f;

    Vector3 throttle_label = base_pos;
    throttle_label.y += 0.0f;

    Vector3 brake_label = base_pos;
    brake_label.y -= 0.25f;

    DrawLabelf(speed_label, xconst("MPH: %.2f"), Car.Sim.SpeedMPH);
    DrawLabelf(steering_label, xconst("Steering: %.2f"), Car.Sim.Steering);
    DrawLabelf(throttle_label, xconst("Throttle: %.2f"), Car.Sim.Engine.Throttle);
    DrawLabelf(brake_label, xconst("Brakes: %.2f"), Car.Sim.Brakes);

    DrawColor(ColLightCyan);

    RailSet.DrawTurn(WayPts->DistToSide);
}

void aiVehicleOpponent::Init(i32 opp_id, aiRaceData* race_data, char* race_name)
{
    i32 tex_quality = agiRQ.TextureQuality;
    if (agiRQ.TextureQuality)
        --agiRQ.TextureQuality;

    i32 paint_job = opp_id & 3;
    i32 index = opp_id + 1;

    OpponentRaceData* opp = static_cast<OpponentRaceData*>(race_data->Opponents.Access(index));

    Car.Init(opp->Model, CAR_TYPE_OPPONENT, paint_job);

    agiRQ.TextureQuality = tex_quality;

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