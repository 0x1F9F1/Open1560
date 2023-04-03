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

define_dummy_symbol(mmphysics_osample);

#include "osample.h"

#include "arts7/sim.h"
#include "data7/metadefine.h"

void asOverSample::RealTime(f32 fps)
{
    SampleStep = 1.0f / fps;
}

void asOverSample::Update()
{
    f32 delta = Sim()->GetUpdateDelta();
    bool full_update = Sim()->IsFullUpdate();

    if (delta >= SampleStep)
        NumSamples = std::min<i32>(static_cast<i32>(delta / SampleStep) + 1, MaxSamples);
    else
        NumSamples = 1;

    BenchOSample = NumSamples;

    Sim()->BeginOverSample(NumSamples);

    for (i32 i = 1; i <= NumSamples; ++i)
    {
        Sim()->SetIsFullUpdate(i == NumSamples);

        asNode::Update();
    }

    Sim()->EndOverSample(NumSamples);
    Sim()->SetIsFullUpdate(full_update);
}

META_DEFINE_CHILD("asOverSample", asOverSample, asNode)
{
    META_FIELD("SampleStep", SampleStep);
    META_FIELD("MaxSamples", MaxSamples);
}
