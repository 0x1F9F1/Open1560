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

#pragma once

#include "agi/lmodel.h"

class agiBILightModel final : public agiLightModel
{
public:
    // ??0agiBILightModel@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiBILightModel(agiPipeline* arg1);

    // ??1agiBILightModel@@UAE@XZ
    ARTS_IMPORT ~agiBILightModel() override;

    // ?Activate@agiBILightModel@@UAEHXZ
    ARTS_IMPORT i32 Activate() override;

    // ?BeginGfx@agiBILightModel@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // ?EndGfx@agiBILightModel@@UAEXXZ
    ARTS_IMPORT void EndGfx() override;
};

check_size(agiBILightModel, 0x40);
