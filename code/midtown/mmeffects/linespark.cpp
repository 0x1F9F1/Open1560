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

const f32 SparkLength = 1.0f / 30.0f;

void asLineSparks::Update()
{
    const f32 delta = ARTSPTR->GetUpdateDelta();

    FadeFraction += delta * FadeRate;
    const i32 fade = static_cast<i32>(FadeFraction);
    FadeFraction -= static_cast<f32>(fade);

    const f32 gravity = Gravity * delta;
    const f32 trail = TrailLength * delta;

    for (i32 i = 0; i < NumActive;)
    {
        if (fade)
        {
            i32 column = SparkColumns[i] + fade;

            if (column < 0)
            {
                --NumActive;
                SparkStarts[i] = SparkStarts[NumActive];
                SparkColumns[i] = SparkColumns[NumActive];
                SparkRows[i] = SparkRows[NumActive];
                SparkVelocities[i] = SparkVelocities[NumActive];
                continue;
            }

            SparkColumns[i] = static_cast<u8>(column);
            SparkColors[i] = Lut->Colors[SparkRows[i] + (SparkColumns[i] >> Lut->RowShift)];
        }

        SparkVelocities[i].y += gravity;
        SparkStarts[i] += SparkVelocities[i] * delta;
        SparkEnds[i] = SparkStarts[i] + SparkVelocities[i] * SparkLength;

        if ((SparkStarts[i].y < GroundY) && (SparkVelocities[i].y < 0.0f))
            SparkVelocities[i].y = SparkVelocities[i].y * -0.8f;

        ++i;
    }
}

run_once([] {
    // Use Sparks.SampleTime instead of ARTSPTR.DeltaTime to calculate number of sparks
    // Time shouldn't actually be factored into this at all, since it isn't happening each frame
    // SampleTime was just easy to access and provides the desired scale
    create_patch("mmCar::Impact", "Spark Count", 0x474226, "\x8B\x8E\xC8\x18\x00\x00\xD9\x81\xEC\x00\x00\x00", 12);
});