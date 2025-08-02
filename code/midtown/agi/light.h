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

#include "vector7/vector3.h"
#include "vector7/vector4.h"

class agiLightParameters
{
public:
    // ??0agiLightParameters@@QAE@XZ
    ARTS_EXPORT agiLightParameters() = default;

    // ??4agiLightParameters@@QAEXABV0@@Z
    ARTS_EXPORT void operator=(const agiLightParameters& rhs)
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
    f32 SpotExp {};
    f32 SpotAngle {180.0f};
    f32 ConstantAtten {1.0f};
    f32 LinearAtten {};
    f32 QuadraticAtten {};
    f32 SpecularExp {};
    u32 field_6C {0xFFFFFFFF};
};

check_size(agiLightParameters, 0x70);

class agiLight : public agiRefreshable
{
public:
    // ??0agiLight@@QAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiLight(agiPipeline* pipe)
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
    ARTS_EXPORT aconst char* GetName() override;

    // ?Init@agiLight@@QAEHABVagiLightParameters@@@Z
    ARTS_EXPORT i32 Init(const agiLightParameters& params);

    agiLightParameters Params {};
};

check_size(agiLight, 0x88);
