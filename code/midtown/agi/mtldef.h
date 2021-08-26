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
    agi:mtldef

    0x55DAB0 | public: __thiscall agiMtlParameters::agiMtlParameters(void) | ??0agiMtlParameters@@QAE@XZ
    0x55DB00 | public: void __thiscall agiMtlParameters::Load(class Stream *) | ?Load@agiMtlParameters@@QAEXPAVStream@@@Z
    0x55DB70 | public: void __thiscall agiMtlParameters::Save(class Stream *) | ?Save@agiMtlParameters@@QAEXPAVStream@@@Z
    0x55DBE0 | public: void __thiscall agiMtlParameters::operator=(class agiMtlParameters const &) | ??4agiMtlParameters@@QAEXABV0@@Z
    0x55DC00 | protected: __thiscall agiMtlDef::agiMtlDef(class agiPipeline *) | ??0agiMtlDef@@IAE@PAVagiPipeline@@@Z
    0x55DC50 | public: int __thiscall agiMtlDef::Init(class agiMtlParameters const &) | ?Init@agiMtlDef@@QAEHABVagiMtlParameters@@@Z
    0x55DC80 | protected: virtual __thiscall agiMtlDef::~agiMtlDef(void) | ??1agiMtlDef@@MAE@XZ
    0x55DD30 | public: virtual char * __thiscall agiMtlDef::GetName(void) | ?GetName@agiMtlDef@@UAEPADXZ
    0x55DD50 | protected: virtual void * __thiscall agiMtlDef::`scalar deleting destructor'(unsigned int) | ??_GagiMtlDef@@MAEPAXI@Z
    0x55DD50 | protected: virtual void * __thiscall agiMtlDef::`vector deleting destructor'(unsigned int) | ??_EagiMtlDef@@MAEPAXI@Z
    0x621888 | const agiMtlDef::`vftable' | ??_7agiMtlDef@@6B@
*/

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
    ARTS_IMPORT char* GetName() override;

    // ?Init@agiMtlDef@@QAEHABVagiMtlParameters@@@Z
    ARTS_IMPORT i32 Init(const agiMtlParameters& arg1);

protected:
    // ??0agiMtlDef@@IAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiMtlDef(agiPipeline* arg1);

    // ??_EagiMtlDef@@MAEPAXI@Z
    // ??_GagiMtlDef@@MAEPAXI@Z
    // ??1agiMtlDef@@MAE@XZ
    ARTS_IMPORT ~agiMtlDef() override;

    u8 gap18[0x68];
};

check_size(agiMtlDef, 0x80);
