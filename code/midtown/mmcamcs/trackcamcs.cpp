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

define_dummy_symbol(mmcamcs_trackcamcs);

#include "trackcamcs.h"

#include "arts7/sim.h"
#include "mmcar/car.h"

static mem::cmd_param PARAM_preapproach {"preapproach", "Enable dynamic TrackCamCS AppXZPos calculations"};

void TrackCamCS::AfterLoad()
{
    CameraNear = 0.5f;

    if (bool enabled = false; PARAM_preapproach.get(enabled))
    {
        if (!enabled)
        {
            // preapproach is explicitly disabled
            MinAppXZPos = 0.0f;
        }
    }
    else
    {
        // preapproach is not specified, disable it for vanilla cameras (these values are the same for every MM1 TrackCamCS).
        // If you want to use these values, change AppXZPos to something slightly different.
        if ((MaxAppXZPos == 30.0f) && (MinSpeed == 5.0f) && (MaxSpeed == 35.0f) && (AppXZPos == 5.0f))
        {
            if (((MinAppXZPos == 1.0f) && (AppInc == 8.0f) && (AppDec == 5.0f)) ||
                ((MinAppXZPos == 1.8f) && (AppInc == 15.0f) && (AppDec == 10.0f)))
            {
                MinAppXZPos = 0.0f;
            }
        }
    }
}

void TrackCamCS::UpdateInput()
{}

void TrackCamCS::PreApproach()
{
    // AppXZPos is used to control how quickly the camera will attempt to adjust its X/Z coordinates to match the target position.
    // MinAppXZPos/MaxAppXZPos/MinSpeed/MaxSpeed/AppInc/AppDec can used to dynamically control AppXZPos based on the vehicle's speed.

    if (!Car)
    {
        return;
    }

    // Don't touch AppXZPos at all, unless we have valid parameters.
    if ((MinAppXZPos == 0.0f) || (MinSpeed == MaxSpeed))
    {
        return;
    }

    // As speed increases from MinSpeed to MaxSpeed, we interpolate from MaxAppXZPos to MinAppXZPos
    f32 speed_scale = 0.0f;

    if (CarVelocity <= MinSpeed)
    {
        speed_scale = 0.0f;
    }
    else if (CarVelocity >= MaxSpeed)
    {
        speed_scale = 1.0f;
    }
    else
    {
        speed_scale = (CarVelocity - MinSpeed) / (MaxSpeed - MinSpeed);
    }

    f32 target_xz = (MinAppXZPos - MaxAppXZPos) * speed_scale + MaxAppXZPos;

    if (Car->Sim.Trans.IsReverse())
    {
        target_xz = 20.0f;
    }

    f32 seconds = Sim()->GetUpdateDelta();

    if (target_xz < AppXZPos)
    {
        AppXZPos = std::max(target_xz, AppXZPos - (AppDec * seconds));
    }
    else if (target_xz > AppXZPos)
    {
        AppXZPos = std::min(target_xz, AppXZPos + (AppInc * seconds));
    }
}

void TrackCamCS::UpdateHill()
{}
