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

PreCamCS::PreCamCS()
{
    CarCamCS::CarCamCS();
    dword120 = 5.0f;        // unknown
    AzimuthOffset = 0.0f;   // rotation angle
    PolarHeight = 2.0f;     // vertical height (smooth)
    PolarDistance = 22.0f;  // distance to car (smooth)
    PolarIncline = 1.1f;    // rotation (vertical based), higher will also twist the camera
    dword128 = 0.0f;        // unkown...
    BlendTime = 3.0f;       // gets buggy when changed
}
