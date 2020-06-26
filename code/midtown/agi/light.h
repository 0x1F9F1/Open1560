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
    agi:light

    0x55B9E0 | public: __thiscall agiLightParameters::agiLightParameters(void) | ??0agiLightParameters@@QAE@XZ
    0x55BA60 | public: void __thiscall agiLightParameters::operator=(class agiLightParameters const &) | ??4agiLightParameters@@QAEXABV0@@Z
    0x55BA80 | public: __thiscall agiLight::agiLight(class agiPipeline *) | ??0agiLight@@QAE@PAVagiPipeline@@@Z
    0x55BAD0 | public: int __thiscall agiLight::Init(class agiLightParameters const &) | ?Init@agiLight@@QAEHABVagiLightParameters@@@Z
    0x55BB00 | public: virtual void __thiscall agiLight::Remove(void) | ?Remove@agiLight@@UAEXXZ
    0x55BB10 | public: virtual __thiscall agiLight::~agiLight(void) | ??1agiLight@@UAE@XZ
    0x55BB20 | public: virtual char * __thiscall agiLight::GetName(void) | ?GetName@agiLight@@UAEPADXZ
    0x55BB40 | public: virtual void * __thiscall agiLight::`scalar deleting destructor'(unsigned int) | ??_GagiLight@@UAEPAXI@Z
    0x55BB40 | public: virtual void * __thiscall agiLight::`vector deleting destructor'(unsigned int) | ??_EagiLight@@UAEPAXI@Z
    0x621720 | const agiLight::`vftable' | ??_7agiLight@@6B@
*/

#include "refresh.h"

class agiLightParameters
{
public:
    // 0x55B9E0 | ??0agiLightParameters@@QAE@XZ
    ARTS_IMPORT agiLightParameters();

    // 0x55BA60 | ??4agiLightParameters@@QAEXABV0@@Z
    ARTS_IMPORT void operator=(class agiLightParameters const& arg1);

    u8 gap0[0x70];
};

check_size(agiLightParameters, 0x70);

class agiLight : public agiRefreshable
{
    // const agiLight::`vftable' @ 0x621720

public:
    // 0x55BA80 | ??0agiLight@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiLight(class agiPipeline* arg1);

    // 0x55BB40 | ??_EagiLight@@UAEPAXI@Z
    // 0x55BB10 | ??1agiLight@@UAE@XZ
    ARTS_IMPORT ~agiLight() override;

    virtual i32 Update() = 0;

    // 0x55BB00 | ?Remove@agiLight@@UAEXXZ
    ARTS_IMPORT virtual void Remove();

    // 0x55BB20 | ?GetName@agiLight@@UAEPADXZ
    ARTS_IMPORT char* GetName() override;

    // 0x55BAD0 | ?Init@agiLight@@QAEHABVagiLightParameters@@@Z
    ARTS_IMPORT i32 Init(class agiLightParameters const& arg1);

    u8 gap18[0x70];
};

check_size(agiLight, 0x88);
