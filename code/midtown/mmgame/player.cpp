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

define_dummy_symbol(mmgame_player);

#include "player.h"

#include "arts7/sim.h"

void mmPlayer::AfterLoad()
{}

void mmPlayer::BeforeSave()
{}

static const f32 RegenFrameRate = 30.0f;
static const f32 PlayerRegenRate = RegenFrameRate * 0.0005f;

void mmPlayer::UpdateRegen()
{
    if (Car.Sim.ICS.GetVelocity().Mag2() > 25.0f)
    {
        if (f32 damage = Car.Sim.CurrentDamage; damage > 0.0f)
        {
            Car.Sim.CurrentDamage =
                std::max<f32>(0.0f, damage - (Car.Sim.MaxDamageScaled * PlayerRegenRate * Sim()->GetUpdateDelta()));
        }
    }
}
