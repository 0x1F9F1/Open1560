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

define_dummy_symbol(mmcamcs_precamcs);

#include "precamcs.h"

#include "arts7/node.h"
#include "mmcar/car.h"
#include "mmcar/trailer.h"

#include "carcamcs.h"

PreCamCS::PreCamCS()
{
    PolarAngle = 0.0f;
    AzimuthOffset = 0.0f;
    PolarHeight = 2.0f;
    PolarDistance = 22.0f;
    PolarIncline = 1.1f;
    field_128 = 2.0f;
    BlendTime = 3.0f;
}

void PreCamCS::Init(mmCar* car)
{
    Car = car;
    CarMatrix = &car->Sim.LCS.World;
    SetName(car->Sim.GetNodeName());
}

void PreCamCS::MakeActive()
{
    Car->Model.Activate();

    if (Car->Trailer)
        Car->Trailer->Inst.Flags |= INST_FLAG_ACTIVE;

    PolarAngle = atan2(CarMatrix->m2.x, CarMatrix->m2.z) + AzimuthOffset;
}

void PreCamCS::Reset()
{
    asNode::Reset();
}

void PreCamCS::Update()
{
    camera_.PolarView(PolarDistance, PolarAngle, PolarIncline, 0.0f);

    if (CarMatrix)
        camera_.m3 += CarMatrix->m3;

    camera_.m3.y += PolarHeight;
}