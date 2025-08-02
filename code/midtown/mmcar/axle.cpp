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

define_dummy_symbol(mmcar_axle);

#include "axle.h"

#include "agi/dlptmpl.h"
#include "agi/getdlp.h"
#include "data7/metadefine.h"
#include "wheel.h"

void mmAxle::Init(char* veh_name, [[maybe_unused]] char* axle_name, mmWheel* left_wheel, mmWheel* right_wheel)
{
    WheelL = left_wheel;
    WheelR = right_wheel;

    if ([[maybe_unused]] DLPTemplate* dlp = GetDLPTemplate(veh_name))
    {
        // dlp->GetCentroid(Center, arts_formatf<128>("%s_H", axle_name));

        Center = (WheelL->Center + WheelR->Center) * 0.5f;
    }
    else
    {
        DeactivateNode();
    }
}

void mmAxle::Update()
{
    Matrix.m3 = (WheelL->Matrix.m3 + WheelR->Matrix.m3) * 0.5f;
    Matrix.RotateAbs(ZAXIS, asin((WheelL->Matrix.m3.y - WheelR->Matrix.m3.y) / WheelL->Center.x));
    asLinearCS::Update();
}

#ifdef ARTS_DEV_BUILD
void mmAxle::AddWidgets(Bank* bank)
{
    asNode::AddWidgets(bank);
}
#endif

META_DEFINE_CHILD("mmAxle", mmAxle, asLinearCS)
{}
