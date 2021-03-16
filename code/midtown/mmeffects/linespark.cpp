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

define_dummy_symbol(mmeffects_linespark);

#include "linespark.h"

#include "arts7/sim.h"

void asLineSparks::Update()
{
    // TODO: Smoothly animate the sparks, only using fixed update for fading
    SampleFraction += ARTSPTR->GetUpdateDelta() / SampleTime;
    i32 delta = static_cast<i32>(SampleFraction);
    SampleFraction -= static_cast<f32>(delta);

    if (delta)
        Update(delta * SampleTime);
}

run_once([] {
    // Use Sparks.SampleTime instead of ARTSPTR.DeltaTime to calculate number of sparks
    // Time shouldn't actually be factored into this at all, since it isn't happening each frame
    // SampleTime was just easy to access and provides the desired scale
    create_patch("mmCar::Impact", "Spark Count", 0x474226, "\x8B\x8E\xC8\x18\x00\x00\xD9\x81\xEC\x00\x00\x00", 12);
});