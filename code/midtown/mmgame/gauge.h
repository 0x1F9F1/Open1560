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

#include "arts7/linear.h"
#include "vector7/vector3.h"

class mmCarSim;
class mmExternalView;
class mmPlayer;
class agiMeshSet;

class RadialGauge final : public asNode
{
public:
    // ??0RadialGauge@@QAE@XZ
    ARTS_IMPORT RadialGauge();

    // ??_ERadialGauge@@UAEPAXI@Z
    // ??_GRadialGauge@@UAEPAXI@Z
    // ??1RadialGauge@@UAE@XZ | inline
    ARTS_IMPORT ~RadialGauge() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@RadialGauge@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@RadialGauge@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?Init@RadialGauge@@QAEXPAD0PAM1M@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2, f32* arg3, f32* arg4, f32 arg5);

    // ?Update@RadialGauge@@UAEXXZ
    ARTS_IMPORT void Update() override;

    asLinearCS LCS;
    f32* CurrentValue;
    f32* MaxValue;
    f32 RotMin;
    f32 RotMax;
    f32 MinValue;
    Vector3 Pos;
    agiMeshSet* NeedleMesh;
};

check_size(RadialGauge, 0xCC);

struct mmLinearGauge
{
public:
    // ??0mmLinearGauge@@QAE@XZ
    ARTS_IMPORT mmLinearGauge();

    // ??1mmLinearGauge@@QAE@XZ
    ARTS_IMPORT ~mmLinearGauge();

    // ?Draw@mmLinearGauge@@QAEXXZ
    ARTS_IMPORT void Draw();

    // ?Init@mmLinearGauge@@QAEXPADPAM11HPAVmmExternalView@@@Z
    ARTS_IMPORT void Init(char* arg1, f32* arg2, f32* arg3, f32* arg4, i32 arg5, mmExternalView* arg6);

    u8 gap0[0x34];
};

check_size(mmLinearGauge, 0x34);

struct mmRadGauge
{
public:
    // ?ResChange@mmRadGauge@@QAEXXZ
    ARTS_IMPORT void ResChange();

    u8 gap0[0x3C];
};

check_size(mmRadGauge, 0x3C);

struct mmGearIndicator
{
public:
    // ?Draw@mmGearIndicator@@QAEXXZ
    ARTS_IMPORT void Draw();

    // ?Init@mmGearIndicator@@QAEXPAVmmExternalView@@PAVmmPlayer@@@Z
    ARTS_IMPORT void Init(mmExternalView* arg1, mmPlayer* arg2);

    u8 gap0[0x40];
};

check_size(mmGearIndicator, 0x40);

struct mmSpeedIndicator
{
public:
    // ?Draw@mmSpeedIndicator@@QAEXXZ
    ARTS_IMPORT void Draw();

    // ?Init@mmSpeedIndicator@@QAEXPAVmmExternalView@@PAVmmCarSim@@@Z
    ARTS_IMPORT void Init(mmExternalView* arg1, mmCarSim* arg2);

    u8 gap0[0x38];
};

check_size(mmSpeedIndicator, 0x38);
