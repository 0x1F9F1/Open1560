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
#include "mmcar/trailer.h"
#include "mmcityinfo/vehlist.h"
#include "mmphysics/phys.h"

#include "mmnetwork/network.h"

mmNetObject::mmNetObject()
    : asNetObject()
    , field_28(0)
    , Flags(0)
    , Score(0)
    , Time(0.0f)
    , LocalData {}
    , Car(nullptr)
    , IsEnabled(false)
    , Active(0)
    , UpdateCount(0)
    , MatrixChanged(false)
    , ActivateTime(0.0f)
    , Steering(0.0f)
    , PrevSteering(0.0f)
    , SteeringDelta(0.0f)
    , Throttle(0.0f)
    , PrevThrottle(0.0f)
    , ThrottleDelta(0.0f)
    , Brakes(0.0f)
    , PrevBrakes(0.0f)
    , BrakesDelta(0.0f)
    , field_BC(0.0f)
    , field_C0(0.0f)
    , Matrix(IDENTITY)
{
    time_delta = 10.0f;
}

void mmNetObject::Activate()
{
    if (Car)
    {
        Car->Model.Activate();
        Car->Sim.ActivateNode();

        if (Car->Model.HasTrailer())
        {
            Car->Trailer->Activate();
        }
    }

    ActivateNode();
}

void mmNetObject::Clear()
{
    field_BC = 0.0f;
    field_C0 = 0.0f;
    ActivateTime = 0.0f;
    Flags = 0;
    Score = 0;

    if (Car)
    {
        Car->RemoveVehicleAudio();
    }

    SetCar(nullptr);
    PlayerID = 0;
    IsEnabled = false;
    SetActive(false);
}

void mmNetObject::Deactivate()
{
    if (Car)
    {
        Car->Model.Deactivate();
        Car->Sim.DeactivateNode();

        if (Car->Model.HasTrailer())
        {
            Car->Trailer->Deactivate();
        }

        IsEnabled = false;
    }

    DeactivateNode();
}

void mmNetObject::Init(mmCar* car, char* vehicle, i32 variant, ulong player_id, char* name)
{
    vehicle = VehList()->GetVehicleInfo(vehicle)->BaseName;

    car->Init(vehicle, CAR_TYPE_NETOBJECT, variant);
    ICS = car->GetICS();
    UpdateCount = 0;
    MatrixChanged = false;
    Flags = 0;
    Score = 0;
    SetCar(car);
    PlayerID = player_id;
    SetName(name);
}

void mmNetObject::PositionUpdate(NETGAME_MSG* msg)
{
    MatrixChanged = true;

    if ((msg->LastUpdateIdx < 0) || (static_cast<u32>(msg->LastUpdateIdx) < UpdateCount))
        return;

    UpdateCount = msg->LastUpdateIdx;

    Car->Sim.Steering = msg->Steering;
    Car->Sim.Brakes = static_cast<u8>(msg->Brakes) / 255.0f;
    Car->Sim.Engine.Throttle = static_cast<u8>(msg->Throttle) / 255.0f;

    Car->Sim.CurrentDamage = msg->Damage;
    ICS->LinearMomentum = msg->Velocity;

    Matrix.m3 = msg->Position;
    Matrix.FromEulers(msg->Rotation);

    if (UpdateCount == 0)
    {
        ICS->Matrix = Matrix;
        Activate();
        ActivateTime = msg->Time;
    }

    const f32 dist_sq = ICS->Matrix.m3.Dist2(Matrix.m3);

    if (dist_sq > 25.0f)
    {
        field_BC = 100.0f;
        field_C0 = 100.0f;
    }
    else if (dist_sq > 16.0f)
    {
        field_BC = 5.0f;
        field_C0 = 0.5f;
    }
    else if (dist_sq > 9.0f)
    {
        field_BC = 2.5f;
        field_C0 = 1.0f;
    }
    else if (dist_sq > 4.0f)
    {
        field_BC = 1.75f;
        field_C0 = 2.0f;
    }
    else if (dist_sq > 1.0f)
    {
        field_BC = 0.875f;
        field_C0 = 3.0f;
    }
    else
    {
        field_BC = 0.0f;
        field_C0 = 0.0f;
    }

    Score = msg->Score;
    Flags = msg->Flags;

    if (msg->Flags & NET_FLAG_HORN)
        Car->Sim.PlayHorn();
    else
        Car->Sim.StopHorn();

    if (msg->Flags & NET_FLAG_SIREN)
    {
        Car->Sim.StartSiren();
        Car->Model.CarFlags |= CAR_FLAG_SIREN_ON;
    }
    else
    {
        Car->Sim.StopSiren();
        Car->Model.CarFlags &= ~CAR_FLAG_SIREN_ON;
    }

    if (msg->Flags & NET_FLAG_REVERSE)
    {
        if (!Car->Sim.Trans.IsReverse())
            Car->Sim.Trans.SetCurrentGear(0);
    }
    else
    {
        if (Car->Sim.Trans.IsReverse())
            Car->Sim.Trans.SetCurrentGear(2);
    }

    SteeringDelta = (Car->Sim.Steering + 1.0f - Steering) * time_delta;
    ThrottleDelta = (Car->Sim.Engine.Throttle - Throttle) * time_delta;
    BrakesDelta = (Car->Sim.Brakes - Brakes) * time_delta;

    PrevSteering = Steering = Car->Sim.Steering + 1.0f; // Convert [-1, 1] to [0, 2]
    PrevThrottle = Throttle = Car->Sim.Engine.Throttle;
    PrevBrakes = Brakes = Car->Sim.Brakes;

    Time = msg->Time;
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

void mmNetObject::SetActive(b32 active)
{
    Active = active;
}

void mmNetObject::SetCar(mmCar* car)
{
    Car = car;
}

void mmNetObject::SetLocalData()
{
    if (!NETMGR.InSession())
        return;

    LocalData.SenderId = PlayerID;
    LocalData.MessageId = 501;

    LocalData.Steering = Car->Sim.Steering;
    LocalData.Throttle = static_cast<u8>(Car->Sim.Engine.Throttle * 255.0f);
    LocalData.Brakes = static_cast<u8>(Car->Sim.Brakes * 255.0f);

    LocalData.Rotation = Car->Sim.ICS.Matrix.GetEulers();
    LocalData.Position = Car->Sim.ICS.Matrix.m3;
    LocalData.Velocity = Car->Sim.ICS.LinearMomentum;
    LocalData.Damage = Car->Sim.CurrentDamage;

    LocalData.LastUpdateIdx = ++UpdateCount;

    LocalData.Time = Time;
    LocalData.Score = static_cast<u16>(Score);
    LocalData.StringValue[1] = 0;

    LocalData.Flags = 0;

    if (Car->Sim.HornPlaying)
        LocalData.Flags |= NET_FLAG_HORN;

    if (Car->Model.CarFlags & CAR_FLAG_SIREN_ON)
        LocalData.Flags |= NET_FLAG_SIREN;

    if (Car->Sim.Trans.IsReverse())
        LocalData.Flags |= NET_FLAG_REVERSE;

    LocalData.Flags |= static_cast<u16>(Flags);

    NETMGR.Send(0, &LocalData, sizeof(NETGAME_MSG), 0);
}

void mmNetObject::Update()
{
    Predict();

    ActivateTime += ARTSPTR->GetUpdateDelta();

    if (Car->Model.HasTrailer())
    {
        PHYS.DeclareMover(&Car->Trailer->Inst, MOVER_TYPE_10,
            MOVER_FLAG_ACTIVE | MOVER_FLAG_COLLIDE_TERRAIN | MOVER_FLAG_COLLIDE_MOVERS);
    }

    PHYS.DeclareMover(
        &Car->Model, MOVER_TYPE_PERM, MOVER_FLAG_ACTIVE | MOVER_FLAG_COLLIDE_TERRAIN | MOVER_FLAG_COLLIDE_MOVERS);

    asNetObject::Update();
}