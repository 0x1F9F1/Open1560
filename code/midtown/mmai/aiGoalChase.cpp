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