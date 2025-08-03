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

#include "arts7/node.h"

class asOverSample final : public asNode
{
public:
    // ??0asOverSample@@QAE@XZ
    ARTS_EXPORT asOverSample() = default;

    // ??1asOverSample@@UAE@XZ | inline
    ARTS_EXPORT ~asOverSample() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asOverSample@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?RealTime@asOverSample@@QAEXM@Z
    ARTS_EXPORT void RealTime(f32 fps);

    // ?Update@asOverSample@@UAEXXZ
    void Update() override;

    VIRTUAL_META_DECLARE;

private:
    f32 SampleStep {1.0f / 25.0f};
    i32 MaxSamples {20};
    i32 NumSamples {};
    i32 field_2C {1};
};

check_size(asOverSample, 0x30);

// ?BenchOSample@@3HA
ARTS_IMPORT extern i32 BenchOSample;
