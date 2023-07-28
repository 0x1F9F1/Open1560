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
    // Check if the car's maximum scaled damage is greater or equal to the current damage
    if (this->Car->Sim.MaxDamageScaled >= this->Car->Sim.CurrentDamage)
    {
        // If the car is not backing up and not finished, then return true
        return (*this->BackingUp != 1) && (*this->IsFinished == 0);
    }

    // Check if the game mode is Circuit and the opponent car is broken (1), and more than 5 seconds have passed since the timer was last reset
    else if (MMSTATE.GameMode == mmGameMode::Circuit && this->DamageState == 1 && this->Time.Time() > 5.0)
    {
        // Reset the car's damage state and clear its damage
        this->DamageState = 0;
        this->Car->ClearDamage();
        return 1;
    }

    // If the car's damage state is not 1
    else
    {
        // If the car's damage state is 0, reset the timer and set the damage state to 1
        if (!this->DamageState)
        {
            this->Time.Reset();
            this->DamageState = 1;
        }

        // Set the car's steering, throttle, and brakes to 0
        this->Car->Sim.Steering = 0.0;
        this->Car->Sim.Engine.Throttle = 0.0;
        this->Car->Sim.Brakes = 0.0;

        // Get the linear momentum of the car
        Vector3* p_LinearMomentum = &this->Car->Sim.ICS.LinearMomentum;

        // Reduce the car's linear momentum by 5%
        p_LinearMomentum->x *= 0.95;
        p_LinearMomentum->y *= 0.95;
        p_LinearMomentum->z *= 0.95;

        // Return false
        return false;
    }
}
