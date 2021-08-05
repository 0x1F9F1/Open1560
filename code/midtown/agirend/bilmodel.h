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
    agirend:bilmodel

    0x555260 | public: __thiscall agiBILightModel::agiBILightModel(class agiPipeline *) | ??0agiBILightModel@@QAE@PAVagiPipeline@@@Z
    0x555280 | public: virtual __thiscall agiBILightModel::~agiBILightModel(void) | ??1agiBILightModel@@UAE@XZ
    0x5552E0 | public: virtual int __thiscall agiBILightModel::BeginGfx(void) | ?BeginGfx@agiBILightModel@@UAEHXZ
    0x555310 | public: virtual void __thiscall agiBILightModel::EndGfx(void) | ?EndGfx@agiBILightModel@@UAEXXZ
    0x555320 | public: virtual int __thiscall agiBILightModel::Activate(void) | ?Activate@agiBILightModel@@UAEHXZ
    0x555340 | public: virtual void * __thiscall agiBILightModel::`vector deleting destructor'(unsigned int) | ??_EagiBILightModel@@UAEPAXI@Z
    0x555340 | public: virtual void * __thiscall agiBILightModel::`scalar deleting destructor'(unsigned int) | ??_GagiBILightModel@@UAEPAXI@Z
    0x621508 | const agiBILightModel::`vftable' | ??_7agiBILightModel@@6B@
*/

#include "agi/lmodel.h"

class agiBILightModel final : public agiLightModel
{
    // const agiBILightModel::`vftable'

public:
    // ??0agiBILightModel@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiBILightModel(class agiPipeline* arg1);

    // ??_GagiBILightModel@@UAEPAXI@Z
    // ??_EagiBILightModel@@UAEPAXI@Z
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
