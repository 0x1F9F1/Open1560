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

define_dummy_symbol(mmgame_netobject);

#include "netobject.h"

#include "arts7/sim.h"
#include "mmcar/car.h"
#include "mmcityinfo/vehlist.h"

void mmNetObject::Init(mmCar* car, char* vehicle, i32 variant, ulong player_id, char* name)
{
    vehicle = VehList()->GetVehicleInfo(vehicle)->BaseName;

    car->Init(vehicle, CAR_TYPE_NETOBJECT, variant);
    ICS = car->GetICS();
    UpdateCount = 0;
    MatrixChanged = 0;
    Flags = 0;
    Score = 0;
    SetCar(car);
    PlayerID = player_id;
    SetName(name);
}

void mmNetObject::Predict()
{
    if (MatrixChanged)
    {
        constexpr f32 INSTANT_UPDATE_FLAG = 100.0f;

        if (field_BC == INSTANT_UPDATE_FLAG)
        {
            ICS->Matrix = Matrix;
            MatrixChanged = false;
        }

        else if (field_BC > 0.0f)
        {
            const f32 seconds = ARTSPTR->GetUpdateDelta();
            ICS->Matrix.Approach(Matrix, field_BC, field_C0, seconds);
            MatrixChanged = false;
        }
    }
    else
    {
        const f32 seconds = ARTSPTR->GetUpdateDelta();

        const f32 steering = std::clamp(SteeringDelta * seconds + PrevSteering, 0.0f, 2.0f);
        const f32 throttle = std::clamp(ThrottleDelta * seconds + PrevThrottle, 0.0f, 1.0f);
        const f32 brakes = std::clamp(BrakesDelta * seconds + PrevBrakes, 0.0f, 1.0f);

        Car->Sim.Steering = steering - 1.0f; // Convert [0, 2] range to [-1, 1]
        Car->Sim.Engine.Throttle = throttle;
        Car->Sim.Brakes = brakes;

        PrevSteering = steering;
        PrevThrottle = throttle;
        PrevBrakes = brakes;
    }
}

void mmNetObject::ReInit(mmCar* car, char* vehicle, i32 variant, ulong player_id, char* name)
{
    vehicle = VehList()->GetVehicleInfo(vehicle)->BaseName;

    car->ReInit(vehicle, variant);
    PrevBrakes = 0.0f;
    Brakes = 0.0f;
    PrevSteering = 0.0f;
    Steering = 0.0f;
    PrevThrottle = 0.0f;
    Throttle = 0.0f;
    field_BC = 0.0f;
    field_C0 = 0.0f;
    Matrix.Identity();
    UpdateCount = 0;
    MatrixChanged = 0;
    IsEnabled = 0;
    Flags = 0;
    Score = 0;
    ICS = car->GetICS();
    SetCar(car);
    PlayerID = player_id;
    SetName(name);
}