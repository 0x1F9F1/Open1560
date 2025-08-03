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

define_dummy_symbol(mmai_aiGoalStop);

#include "aiGoalStop.h"

#include "mmcar/car.h"

aiGoalStop::aiGoalStop(mmCar* car, b16* is_stopped)
    : Car(car)
    , IsStopped(is_stopped)
{}

b32 aiGoalStop::Context()
{
    if (*IsStopped)
        return true;

    UpdateCount = 0;
    return false;
}

b32 aiGoalStop::Priority()
{
    return true;
}

void aiGoalStop::Reset()
{}

void aiGoalStop::Update()
{
    ++UpdateCount;

    Car->Sim.Steering = 0.0f;
    Car->Sim.Engine.Throttle = 0.0f;
    Car->Sim.Brakes = 1.0f;

    Car->Sim.ICS.LinearMomentum *= 0.95f;
}
