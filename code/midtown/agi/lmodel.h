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

/*
    agi:lmodel

    0x55BCA0 | public: __thiscall agiLightModelParameters::agiLightModelParameters(void) | ??0agiLightModelParameters@@QAE@XZ
    0x55BCD0 | public: void __thiscall agiLightModelParameters::operator=(class agiLightModelParameters const &) | ??4agiLightModelParameters@@QAEXABV0@@Z
    0x55BCF0 | public: __thiscall agiLightModelParameters::~agiLightModelParameters(void) | ??1agiLightModelParameters@@QAE@XZ
    0x55BD00 | protected: __thiscall agiLightModel::agiLightModel(class agiPipeline *) | ??0agiLightModel@@IAE@PAVagiPipeline@@@Z
    0x55BD50 | public: int __thiscall agiLightModel::Init(class agiLightModelParameters const &) | ?Init@agiLightModel@@QAEHABVagiLightModelParameters@@@Z
    0x55BD80 | public: virtual __thiscall agiLightModel::~agiLightModel(void) | ??1agiLightModel@@UAE@XZ
    0x55BDD0 | public: virtual char * __thiscall agiLightModel::GetName(void) | ?GetName@agiLightModel@@UAEPADXZ
    0x55BDF0 | public: virtual void * __thiscall agiLightModel::`scalar deleting destructor'(unsigned int) | ??_GagiLightModel@@UAEPAXI@Z
    0x55BDF0 | public: virtual void * __thiscall agiLightModel::`vector deleting destructor'(unsigned int) | ??_EagiLightModel@@UAEPAXI@Z
    0x621760 | const agiLightModel::`vftable' | ??_7agiLightModel@@6B@
*/

#include "refresh.h"

#include "vector7/vector4.h"

class agiLightModelParameters
{
public:
    // ??0agiLightModelParameters@@QAE@XZ
    ARTS_IMPORT agiLightModelParameters();

    // ??1agiLightModelParameters@@QAE@XZ
    ARTS_IMPORT ~agiLightModelParameters() = default;

    // ??4agiLightModelParameters@@QAEXABV0@@Z
    ARTS_IMPORT void operator=(class agiLightModelParameters const& arg1);

    Vector4 Ambient;
    b32 LocalViewer;
    u32 dword14;
    u32 dword18;
    b32 Enabled;
    b32 Monochromatic;
    b32 Changed;
};

check_size(agiLightModelParameters, 0x28);

class agiLightModel : public agiRefreshable
{
    // const agiLightModel::`vftable'

public:
    // ??_EagiLightModel@@UAEPAXI@Z
    // ??_GagiLightModel@@UAEPAXI@Z
    // ??1agiLightModel@@UAE@XZ
    ARTS_IMPORT ~agiLightModel() override;

    virtual i32 Activate() = 0;

    // ?GetName@agiLightModel@@UAEPADXZ
    ARTS_IMPORT char* GetName() override;

    // ?Init@agiLightModel@@QAEHABVagiLightModelParameters@@@Z
    ARTS_IMPORT i32 Init(class agiLightModelParameters const& arg1);

    agiLightModelParameters Params;

protected:
    // ??0agiLightModel@@IAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiLightModel(class agiPipeline* arg1);
};

check_size(agiLightModel, 0x40);
