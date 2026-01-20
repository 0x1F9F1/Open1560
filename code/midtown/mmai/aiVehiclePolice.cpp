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

define_dummy_symbol(mmai_aiVehiclePolice);

#include "aiVehiclePolice.h"

#include "aiData.h"
#include "aiGoalBackup.h"
#include "aiGoalChase.h"
#include "aiGoalRandomDrive.h"
#include "aiGoalStop.h"

#include "data7/str.h"
#include "mmcityinfo/vehlist.h"

static mem::cmd_param PARAM_maxcopcolors {"maxcopcolors"};

void aiVehiclePolice::Init(i32 cop_id, aiRaceData* race_data)
{
    RaceData = race_data;

    PoliceRaceData* cop = static_cast<PoliceRaceData*>(RaceData->Police.Access(cop_id + 1));

    mmVehInfo* veh_info = VehList()->GetVehicleInfo(cop->Model);
    i32 num_paint_jobs = string(veh_info->Colors).NumSubStrings();
    i32 paint_job = (PARAM_maxcopcolors.value() != nullptr) ? (cop_id % num_paint_jobs) : 0;
    Car.Init(cop->Model, CAR_TYPE_POLICE, paint_job);

    aiVehicleSpline::Init(cop->Model, cop_id);

    Matrix = &Car.Sim.ICS.Matrix;

    Car.Sim.ICS.Gravity.y = -40.0f;
    Car.Reset();

    ChaseGoal = arnew aiGoalChase(this, &RailSet, &TargetCar, &StopId, &TargetPt, &BackupId);
    BackupGoal = arnew aiGoalBackup(&RailSet, &Car, &BackupId);
    StopGoal = arnew aiGoalStop(&Car, &StopId);
    RandomDriveGoal = arnew aiGoalRandomDrive(&RailSet, this);

    AudioIndexNumber = -1;
}
