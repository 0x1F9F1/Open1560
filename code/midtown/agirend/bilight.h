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
    agirend:bilight

    0x555370 | public: __thiscall agiBILight::agiBILight(class agiPipeline *) | ??0agiBILight@@QAE@PAVagiPipeline@@@Z
    0x555390 | public: virtual __thiscall agiBILight::~agiBILight(void) | ??1agiBILight@@UAE@XZ
    0x5553E0 | public: virtual int __thiscall agiBILight::BeginGfx(void) | ?BeginGfx@agiBILight@@UAEHXZ
    0x555400 | public: virtual void __thiscall agiBILight::EndGfx(void) | ?EndGfx@agiBILight@@UAEXXZ
    0x555410 | public: virtual int __thiscall agiBILight::Update(void) | ?Update@agiBILight@@UAEHXZ
    0x555420 | public: virtual void __thiscall agiBILight::Remove(void) | ?Remove@agiBILight@@UAEXXZ
    0x555430 | public: virtual void * __thiscall agiBILight::`scalar deleting destructor'(unsigned int) | ??_GagiBILight@@UAEPAXI@Z
    0x555430 | public: virtual void * __thiscall agiBILight::`vector deleting destructor'(unsigned int) | ??_EagiBILight@@UAEPAXI@Z
    0x621528 | const agiBILight::`vftable' | ??_7agiBILight@@6B@
*/

#include "agi/light.h"

class agiBILight final : public agiLight
{
    // const agiBILight::`vftable'

public:
    // ??0agiBILight@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiBILight(class agiPipeline* arg1);

    // ??_EagiBILight@@UAEPAXI@Z
    // ??_GagiBILight@@UAEPAXI@Z
    // ??1agiBILight@@UAE@XZ
    ARTS_IMPORT ~agiBILight() override;

    // ?BeginGfx@agiBILight@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // ?EndGfx@agiBILight@@UAEXXZ
    ARTS_IMPORT void EndGfx() override;

    // ?Remove@agiBILight@@UAEXXZ
    ARTS_IMPORT void Remove() override;

    // ?Update@agiBILight@@UAEHXZ
    ARTS_IMPORT i32 Update() override;
};

check_size(agiBILight, 0x88);
