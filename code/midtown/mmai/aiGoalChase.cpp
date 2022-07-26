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

static f32 CopSpeedBoost = 1.0f;
static f32 CopBrakeBoost = 1.0f;

static f32 CopSteerBoost1 = 1.0f;
static f32 CopSteerBoost2 = 1.0f;

hook_func(INIT_main, [] {
    if (PARAM_speedycops.get_or(true))
    {
        for (u32 addr : {0x461022 + 2, 0x461034 + 2, 0x461042 + 2})
            create_hook("Cop Speed Boost", "Fix cop speed boost", addr, &CopSpeedBoost, hook_type::pointer);

        for (u32 addr : {0x462B19 + 2, 0x462B21 + 2, 0x462B29 + 2})
            create_hook("Cop Brake Boost", "Fix cop brake boost", addr, &CopBrakeBoost, hook_type::pointer);

        for (u32 addr : {0x460FBC + 2, 0x460FC8 + 2, 0x460FD2 + 2})
            create_hook("Cop Steer Boost 1", "Fix steer brake boost", addr, &CopSteerBoost1, hook_type::pointer);

        for (u32 addr : {0x4627F0 + 2, 0x4627F8 + 2, 0x462800 + 2, 0x462A0D + 2, 0x462A15 + 2, 0x462A1D + 2})
            create_hook("Cop Steer Boost 2", "Fix steer brake boost", addr, &CopSteerBoost2, hook_type::pointer);
    }
    else
    {
        patch_jmp("aiGoalChase::Update", "No Speed Boost", 0x461004, jump_type::always);
        create_patch("aiGoalChase::CalcSpeed", "No Brake Boost", 0x462B0F, "\xEB\x2A", 2);

        // patch_jmp("aiGoalChase::Update", "No Steering boost", 0x460FB0, jump_type::always);
        // create_patch("aiGoalChase::CalcSpeed", "No Steering boost", 0x4627E6, "\xEB\x2A", 2);
        // create_patch("aiGoalChase::CalcSpeed", "No Steering boost", 0x4629F9, "\xEB\x3A", 2);
    }
});

hook_func(FRAME_pre_update, [] {
    f32 exp = std::clamp(60.0f * Sim()->GetUpdateDelta(), 0.01f, 2.0f);

    CopSpeedBoost = std::pow(1.01f, exp);
    CopBrakeBoost = std::pow(0.95f, exp);

    CopSteerBoost1 = std::pow(0.5f, exp);
    CopSteerBoost2 = std::pow(0.85f, exp);
});