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

define_dummy_symbol(mmai_aiGoalBackup);

#include "aiGoalBackup.h"

#include "mmai/aiPath.h"
#include "mmai/aiRailSet.h"
#include "mmcar/car.h"

aiGoalBackup::aiGoalBackup(aiRailSet* rail, mmCar* car, b16* backing_up)
    : Rail(rail)
    , Car(car)
    , BackingUp(backing_up)
{}

void aiGoalBackup::Init()
{
    *BackingUp = false;
    UpdateCount = 0;
}

b32 aiGoalBackup::Context()
{
    return *BackingUp;
}

i32 aiGoalBackup::Priority()
{
    return 1;
}

void aiGoalBackup::Reset()
{
    if (!Car->Sim.Trans.IsReverse())
        Car->Sim.Trans.SetReverse();
}

void aiGoalBackup::Update()
{
    aiGoal::Update();

    mmCarSim& sim = Car->Sim;
    Matrix34& matrix = sim.ICS.Matrix;
    aiPath* path = Rail->NextLink;

    i32 vert_index = path->Index(matrix.m3);
    Vector3 vert_center = *path->CenterVertice(vert_index);
    Vector3 vert_xdir = *path->VertXDir(vert_index);

    Vector3 target_offset = vert_center + vert_xdir * (vert_xdir ^ (matrix.m3 - vert_center)) - matrix.m3;

    f32 target_angle = std::atan2(target_offset ^ matrix.m0, target_offset ^ -matrix.m2);

    if (target_angle < -0.1f || target_angle > 0.1f)
    {
        sim.Steering = std::clamp(target_angle * -(20.0f / 7.0f), -1.0f, 1.0f);

        // TODO: Improve the decision of when to stop backing up
        if ((sim.Trans.TimeInGear < 3.0f) || !Car->Sim.Stuck.Impacted)
        {
            sim.Engine.Throttle = 0.85f;
            sim.Brakes = 0.0f;
        }
        else
        {
            FinishedBackingUp();
        }
    }
    else
    {
        sim.Steering = 0.0f;
        // matrix.Rotate(matrix.m1, target_angle);
        FinishedBackingUp();
    }
}

void aiGoalBackup::FinishedBackingUp()
{
    *BackingUp = false;
    UpdateCount = 0;

    Car->Sim.Stuck.Impacted = false;

    // Car->Sim.ICS.LinearMomentum *= 0.25f;
    // Car->Sim.ICS.AngularMomentum *= 0.25f;

    Car->Sim.Engine.Throttle = 0.0f;
    Car->Sim.Brakes = 1.0f;
}