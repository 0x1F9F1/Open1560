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

define_dummy_symbol(mmcar_wheel);

#include "wheel.h"

#include "arts7/sim.h"
#include "mmbangers/active.h"

// TODO: This also needs to factor in the wheel rotation delta
void mmWheel::GenerateSkidParticles()
{
    ParticleCount += std::min(ParticleMultiplier * PtxMaxSkidCount * Sim()->GetUpdateDelta(), 1.0f);
}

static const f32 PtxFrameRate = 60.0f;

static mem::cmd_param PARAM_maxskid {"maxskid"};

hook_func(INIT_main, [] {
    mmWheel::PtxMaxSkidCount = PtxFrameRate * PARAM_maxskid.get_or(1.0f);

    patch_jmp("mmWheel::ComputeDwtdw", "Avoid Probe Poly Caching", 0x47DCAA, jump_type::always);
});