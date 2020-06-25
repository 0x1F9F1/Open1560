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
    agid3d:d3dlight

    0x5337A0 | public: __thiscall agiD3DLight::agiD3DLight(class agiPipeline *) | ??0agiD3DLight@@QAE@PAVagiPipeline@@@Z
    0x5337E0 | public: virtual __thiscall agiD3DLight::~agiD3DLight(void) | ??1agiD3DLight@@UAE@XZ
    0x533840 | public: virtual int __thiscall agiD3DLight::BeginGfx(void) | ?BeginGfx@agiD3DLight@@UAEHXZ
    0x5338C0 | public: virtual void __thiscall agiD3DLight::EndGfx(void) | ?EndGfx@agiD3DLight@@UAEXXZ
    0x533910 | public: virtual int __thiscall agiD3DLight::Update(void) | ?Update@agiD3DLight@@UAEHXZ
    0x5339C0 | public: virtual void * __thiscall agiD3DLight::`vector deleting destructor'(unsigned int) | ??_EagiD3DLight@@UAEPAXI@Z
    0x5339C0 | public: virtual void * __thiscall agiD3DLight::`scalar deleting destructor'(unsigned int) | ??_GagiD3DLight@@UAEPAXI@Z
    0x621188 | const agiD3DLight::`vftable' | ??_7agiD3DLight@@6B@
*/

#include "agi/light.h"

class agiD3DLight : public agiLight
{
    // const agiD3DLight::`vftable' @ 0x621188

public:
    // 0x5337A0 | ??0agiD3DLight@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiD3DLight(class agiPipeline* arg1);

    // 0x5339C0 | ??_GagiD3DLight@@UAEPAXI@Z
    // 0x5337E0 | ??1agiD3DLight@@UAE@XZ
    ARTS_IMPORT ~agiD3DLight() override;

    // 0x533840 | ?BeginGfx@agiD3DLight@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // 0x5338C0 | ?EndGfx@agiD3DLight@@UAEXXZ
    ARTS_IMPORT void EndGfx() override;

    // 0x533910 | ?Update@agiD3DLight@@UAEHXZ
    ARTS_IMPORT i32 Update() override;
};

check_size(agiD3DLight, 0x8C);
