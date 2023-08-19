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

#include "aiData.h"
#include "aiGoalBackup.h"
#include "aiGoalFollowWayPts.h"
#include "aiGoalStop.h"

void aiVehicleOpponent::DrawDamage()
{}

void aiVehicleOpponent::Init(int opp_id, aiRaceData* race_data, char* arg3)
{
    int TextureQuality = agiRQ.TextureQuality;
    if (agiRQ.TextureQuality)
        --agiRQ.TextureQuality;

    int paint_job = opp_id & 3;
    int index = opp_id + 1;

    List* p_opponents = &race_data->Opponents;
    OpponentRaceData* oppRaceData = static_cast<OpponentRaceData*>(p_opponents->Access(index));

    Car.Init(oppRaceData->Model, CAR_TYPE_OPPONENT, paint_job);

    agiRQ.TextureQuality = TextureQuality;

    aiVehicle::Init(opp_id);
    Car.Reset();

    std::unique_ptr<aiGoalFollowWayPts> followWayPts = std::make_unique<aiGoalFollowWayPts>(
        oppRaceData->PathFile, &RailSet, this, &IsBackup, &IsFinished, &IsStopped, arg3, oppRaceData->MaxThrottle);

    WayPts = followWayPts.release();

    std::unique_ptr<aiGoalBackup> backupGoal = std::make_unique<aiGoalBackup>(&RailSet, &Car, &IsBackup);

    BackupGoal = backupGoal.release();

    std::unique_ptr<aiGoalStop> stopGoal = std::make_unique<aiGoalStop>(&Car, &IsStopped);

    StopGoal = stopGoal.release();

    IsSemi = strcmp("vpsemi", oppRaceData->Model) == 0;

    DLPTemplate* DLPTemplate = GetDLPTemplate(oppRaceData->Model);

    if (DLPTemplate)
    {
        Vector3 max, min;
        DLPTemplate->BoundBox(min, max, const_cast<char*>("BODY_H"));

        RailSet.FrontBumperDist = -min.z;
        RailSet.LSideDist = -min.x;
        RailSet.BackBumperDist = max.z;
        RailSet.RSideDist = max.x;
    }
    AudIndexNumber = 1; // original = -1
}
