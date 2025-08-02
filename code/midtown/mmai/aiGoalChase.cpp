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

define_dummy_symbol(mmai_aiGoalChase);

#include "aiGoalChase.h"

#include "arts7/sim.h"

#include "aiMap.h"
#include "aiPath.h"
#include "aiVehiclePolice.h"

static mem::cmd_param PARAM_speedycops {"speedycops"};
static bool EnableCopSpeedBoost = false;
static const f32 CopFrameRate = 30.0f;

f32 CopSpeedBoost = 1.0f;
f32 CopBrakeBoost = 1.0f;
f32 CopSteerBoost1 = 0.5f;
f32 CopSteerBoost2 = 0.85f;

hook_func(INIT_main, [] { EnableCopSpeedBoost = PARAM_speedycops.get_or(true); });

hook_func(FRAME_pre_update, [] {
    if (EnableCopSpeedBoost)
    {
        f32 exp = std::clamp(CopFrameRate * Sim()->GetUpdateDelta(), 0.01f, 2.0f);

        CopSpeedBoost = std::pow(1.01f, exp);
        CopBrakeBoost = std::pow(0.95f, exp);

        CopSteerBoost1 = std::pow(0.5f, exp);
        CopSteerBoost2 = std::pow(0.85f, exp);
    }
});

b32 aiGoalChase::Collision(mmCar* perp)
{
    return perp->Sim.HasCollided;
}

void aiGoalChase::Dump()
{
    Displayf("PerpMapCompIdx: %d", PerpMapCompIdx);
    Displayf("PerpMapCompType: %d", PerpMapCompType);
    Displayf("PerpRdVertIdx: %d", PerpRdVertIdx);
    Displayf("PerpCullRoom: %d", PerpCullRoom);
    Displayf("PerpRoadDist: %f", PerpRoadDist);
    Displayf("PerpDistToSide: %f", PerpDistToSide);
    Displayf("CurMapCompIdx: %d", CurMapCompIdx);
    Displayf("PrevMapCompIdx: %d", PrevMapCompIdx);
    Displayf("CurMapCompType: %d", CurMapCompType);
    Displayf("PrevMapCompType: %d", PrevMapCompType);
    Displayf("CurRdVertIdx: %d", CurRdVertIdx);
    Displayf("CurCullRoom: %d", CurCullRoom);
    Displayf("ForwardDist: %f", ForwardDist);
    Displayf("SideDist: %f", SideDist);
    Displayf("TargetOffset: %f", TargetOffset);
    Displayf("ApprehendState: %d", ApprehendState);
    Displayf("State: %d", State);
    Displayf("LastState: %d", LastState);
    Displayf("StartedChase: %d", StartedChase);
    Displayf("Angle: %f", Angle);
    Displayf("SteerVal: %f", SteerVal);
    Displayf("SeparationDist: %f", SeparationDist);
    Displayf("RotAngle: %f", RotAngle);
    Displayf("Throttle: %f", Throttle);
    Displayf("Brake: %f", Brake);
    Displayf("Dist2Perp: %f", Dist2Perp);
    Displayf("DistToSide: %f", DistToSide);
    Displayf("WaitTime: %f", WaitTime);
    Displayf("Offset: %f", Offset);
    Displayf("NumBehaviors: %d", NumBehaviors);
    Displayf("NumCloseObs: %d", NumCloseObs);
    Displayf("NumFarObs: %d", NumFarObs);
}

void aiGoalChase::Follow()
{
    if (Dist2Perp <= 20.0f)
    {
        CalcSpeed(AIMAP.PlayerCar->Sim.Speed);
    }
    else
    {
        CalcSpeed(AIMAP.PlayerCar->Sim.Speed + 10.0f);
    }

    f32 path_center_length = RailSet->CurLink->CenterLength(1, RailSet->CurLink->VertexCount - 2);

    if ((CurMapCompIdx != PerpMapCompIdx) || (CurMapCompType != 1) || ((path_center_length - 30.0f) <= PerpRoadDist))
    {
        Offset = DistToSide;
    }
    else
    {
        f32 line_length =
            RailSet->CurLink->LaneLengths[2 * (RailSet->CurLink->NumLanes - 1) + 1] - RailSet->RSideDist - 1.5f;

        if (PerpDistToSide <= -line_length)
        {
            Offset = -line_length;
        }
        else if (PerpDistToSide < line_length)
        {
            Offset = PerpDistToSide;
        }
        else
        {
            Offset = line_length;
        }
    }

    RailSet->CalcCopRailPosition(*TargetPos, PoliceCar->Sim.ICS.Matrix.m3, TargetOffset + RailSet->RoadDist, Offset);
    TargetPos->y = PoliceCar->Sim.ICS.Matrix.m3.y;
}

b32 aiGoalChase::Priority()
{
    return true;
}

b32 aiGoalChase::Speeding(mmCar* perp)
{
    f32 speed_limit = (RailSet->CurLink->NumLanes == 4) ? 70.0f : 40.0f;

    return perp->Sim.SpeedMPH > speed_limit;
}

b32 aiGoalChase::Stopped(mmCar* perp)
{
    return perp->Sim.Speed < 1.0f;
}
