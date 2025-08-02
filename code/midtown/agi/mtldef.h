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

#include "refresh.h"

#include "vector7/vector4.h"

class agiMtlParameters
{
public:
    // ??0agiMtlParameters@@QAE@XZ
    ARTS_IMPORT agiMtlParameters();

    // ??4agiMtlParameters@@QAEXABV0@@Z
    ARTS_IMPORT void operator=(const agiMtlParameters& arg1);

    // ?Load@agiMtlParameters@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Load(Stream* arg1);

    // ?Save@agiMtlParameters@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(Stream* arg1);

    char Name[32] {};

    Vector4 Emmisive {0.0f, 0.0f, 0.0f, 1.0f};
    Vector4 Ambient {0.2f, 0.2f, 0.2f, 1.0f};
    Vector4 Diffuse {0.8f, 0.8f, 0.8f, 1.0f};
    Vector4 Specular {0.0f, 0.0f, 0.0f, 1.0f};

    f32 Power {};

    u16 Touched {true};
};

check_size(agiMtlParameters, 0x68);

class agiMtlDef : public agiRefreshable
{
public:
    // ?GetName@agiMtlDef@@UAEPADXZ
    ARTS_IMPORT aconst char* GetName() override;

    // ?Init@agiMtlDef@@QAEHABVagiMtlParameters@@@Z
    ARTS_IMPORT i32 Init(const agiMtlParameters& arg1);

    agiMtlParameters Mtl {};

protected:
    // ??0agiMtlDef@@IAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiMtlDef(agiPipeline* arg1);

    // ??_EagiMtlDef@@MAEPAXI@Z
    // ??_GagiMtlDef@@MAEPAXI@Z
    // ??1agiMtlDef@@MAE@XZ
    ARTS_IMPORT ~agiMtlDef() override;
};

check_size(agiMtlDef, 0x80);
