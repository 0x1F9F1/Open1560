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

static mem::cmd_param PARAM_preapproach {"preapproach", "Enable dynamic TrackCamCS AppXZPos calculations"};

void TrackCamCS::AfterLoad()
{
    CameraNear = 0.5f;
}

void TrackCamCS::UpdateInput()
{}

void TrackCamCS::PreApproach()
{
    // AppXZPos is used to control how quickly the camera will attempt to adjust its X/Z coordinates to match the target position.
    // MinAppXZPos/MaxAppXZPos/MinSpeed/MaxSpeed/AppInc/AppDec can used to dynamically control AppXZPos based on the vehicle's speed.
    // This was used in MM2, but disabled in MM1.
    // Since the existing cameras are not tuned to use it, you must use the `-preapproach` command param to enable it.

    if (!Car || !PARAM_preapproach.get_or(false))
    {
        return;
    }

    f32 target_xz = MaxAppXZPos;

    if ((MinAppXZPos != 0.0f) && (MinSpeed != MaxSpeed))
    {
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

        target_xz = (MinAppXZPos - MaxAppXZPos) * speed_scale + MaxAppXZPos;
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
