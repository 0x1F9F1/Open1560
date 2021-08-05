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

#include "vector7/vector3.h"
#include "vector7/vector4.h"

class agiLightParameters
{
public:
    // ??0agiLightParameters@@QAE@XZ
    ARTS_EXPORT agiLightParameters() = default;

    // ??4agiLightParameters@@QAEXABV0@@Z
    ARTS_EXPORT void operator=(class agiLightParameters const& rhs)
    {
        std::memcpy(this, &rhs, sizeof(*this));

        Touched = true;
    }

    void Touch()
    {
        Touched = true;
    }

    void SetPosition(Vector3 position)
    {
        Position = position;
    }

    u32 Flags {0x3};
    b32 Touched {true};
    Vector3 Ambient {0.0f, 0.0f, 0.0f};
    f32 field_14 {1.0f};
    Vector3 Diffuse {1.0f, 1.0f, 1.0f};
    f32 Alpha {1.0f};
    Vector3 Specular {1.0f, 1.0f, 1.0f};
    f32 field_34 {1.0f};
    Vector4 Position {0.0f, 0.0f, 1.0f, 1.0f};
    Vector3 Direction {0.0f, 0.0f, -1.0f};
    f32 SpotExp {0.0f};
    f32 SpotAngle {180.0f};
    f32 ConstantAtten {1.0f};
    f32 LinearAtten {0.0f};
    f32 QuadraticAtten {0.0f};
    f32 SpecularExp {0.0f};
    u32 field_6C {0xFFFFFFFF};
};

check_size(agiLightParameters, 0x70);

class agiLight : public agiRefreshable
{
    // const agiLight::`vftable'

public:
    // ??0agiLight@@QAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiLight(class agiPipeline* pipe)
        : agiRefreshable(pipe)
    {}

    // ??_EagiLight@@UAEPAXI@Z
    // ??_GagiLight@@UAEPAXI@Z
    // ??1agiLight@@UAE@XZ
    ARTS_EXPORT ~agiLight() override = default;

    virtual i32 Update() = 0;

    // ?Remove@agiLight@@UAEXXZ
    ARTS_EXPORT virtual void Remove();

    // ?GetName@agiLight@@UAEPADXZ
    ARTS_EXPORT char* GetName() override;

    // ?Init@agiLight@@QAEHABVagiLightParameters@@@Z
    ARTS_EXPORT i32 Init(class agiLightParameters const& params);

    agiLightParameters Params {};
};

check_size(agiLight, 0x88);
