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

b32 aiGoalFollowWayPts::Context()
{
    if (Car->Sim.MaxDamageScaled >= Car->Sim.CurrentDamage)
    {
        return (*BackingUp != 1) && (*IsFinished == 0);
    }
    else if (MMSTATE.GameMode == mmGameMode::Circuit && DamageState == 1 && Time.Time() > 5.0f)
    {
        DamageState = 0;
        Car->ClearDamage();
        return 1;
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

        Vector3* p_LinearMomentum = &Car->Sim.ICS.LinearMomentum;
        *p_LinearMomentum *= 0.95f;

        return false;
    }
}