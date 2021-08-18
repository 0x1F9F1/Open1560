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

#include "agi/rsys.h"
#include "agi/viewport.h"
#include "agiworld/meshset.h"
#include "arts7/sim.h"

void asLineSparks::Draw()
{
    Viewport()->SetWorld(const_cast<Matrix34&>(IDENTITY));
    agiMeshSet::Init(false);

    auto alpha = agiCurState.SetAlphaEnable(true);
    auto texture = agiCurState.SetTexture(nullptr);

    agiMeshSet::DrawLines(SparkStarts.get(), SparkEnds.get(), SparkColors.get(), NumActive);

    agiCurState.SetAlphaEnable(alpha);
    agiCurState.SetTexture(texture);
}

void asLineSparks::Init(i32 num_sparks, asSparkLut* lut)
{
    // FIXME: asLineSparks has no constructor (or destructor).
    // If the memory is not zeroed before, they will contain garbage. (See mmGameMulti::BootStrapCars)
    SparkColors.release();
    SparkVelocities.release();
    SparkStarts.release();
    SparkEnds.release();
    SparkRows.release();
    SparkColumns.release();

    NumSparks = num_sparks;
    SparkColors = MakeUniqueUninit<u32[]>(num_sparks);
    SparkVelocities = MakeUniqueUninit<Vector3[]>(num_sparks);
    SparkStarts = MakeUniqueUninit<Vector3[]>(num_sparks);
    SparkEnds = MakeUniqueUninit<Vector3[]>(num_sparks);
    SparkRows = MakeUniqueUninit<u8[]>(num_sparks);
    SparkColumns = MakeUniqueUninit<u8[]>(num_sparks);
    NumActive = 0;
    field_0 = 0;
    GroundY = 0.0f;
    Gravity = -10.0f;
    VelXZMin = 6.0f;
    VelXZMax = 7.0f;
    VelYMin = 4.0f;
    VelYMax = 5.0f;
    TrailLength = -0.036f;
    SampleRate = 1.0f / 30.0f;

    // Note: The software renderer does not alpha blend (so sparks are fully bright while visible)
    FadeRate = -256.0f / 0.5f; // 0.5 seconds (was ~0.4 seconds)
    FadeFraction = 0.0f;
    PosVary = {0.1f, 0.1f, 0.1f};
    Lut = lut;
}

void asLineSparks::Update()
{
    Update(ARTSPTR->GetUpdateDelta());
}

void asLineSparks::Update(f32 delta)
{
    FadeFraction += delta * FadeRate;
    const i32 fade = static_cast<i32>(FadeFraction);
    FadeFraction -= static_cast<f32>(fade);

    const f32 gravity = Gravity * delta;
    const f32 trail = SampleRate * (TrailLength - 1.0f);

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
        SparkEnds[i] = SparkStarts[i] + SparkVelocities[i] * trail;

        if ((SparkStarts[i].y < GroundY) && (SparkVelocities[i].y < 0.0f))
            SparkVelocities[i].y = SparkVelocities[i].y * -0.8f;

        ++i;
    }
}