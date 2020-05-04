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

#include "agi/light.h"

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

class agiBILight : public agiLight
{
    // const agiBILight::`vftable' @ 0x621528

public:
    // 0x555370 | ??0agiBILight@@QAE@PAVagiPipeline@@@Z
    agiBILight(class agiPipeline* arg1);

    // 0x555430 | ??_EagiBILight@@UAEPAXI@Z
    // 0x555390 | ??1agiBILight@@UAE@XZ
    ~agiBILight() override;

    // 0x5553E0 | ?BeginGfx@agiBILight@@UAEHXZ
    i32 BeginGfx() override;

    // 0x555400 | ?EndGfx@agiBILight@@UAEXXZ
    void EndGfx() override;

    // 0x555420 | ?Remove@agiBILight@@UAEXXZ
    void Remove() override;

    // 0x555410 | ?Update@agiBILight@@UAEHXZ
    i32 Update() override;
};

check_size(agiBILight, 0x88);
