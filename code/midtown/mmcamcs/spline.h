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

class Spline final : public asNode
{
public:
    // ??0Spline@@QAE@XZ
    ARTS_IMPORT Spline();

    // ??_ESpline@@UAEPAXI@Z
    // ??1Spline@@UAE@XZ | inline
    ARTS_EXPORT ~Spline() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@Spline@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?CalcCoeff@Spline@@QAEXXZ
    ARTS_IMPORT void CalcCoeff();

    // ?FixTimeStop@Spline@@QAEXXZ
    ARTS_IMPORT void FixTimeStop();

    // ?GetClass@Spline@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?InRange@Spline@@QAEHXZ
    ARTS_IMPORT i32 InRange();

    // ?SetGoal@Spline@@QAEXPAMM@Z
    ARTS_IMPORT void SetGoal(f32* arg1, f32 arg2);

    // ?SetValue@Spline@@QAEXPAM@Z
    ARTS_IMPORT void SetValue(f32* arg1);

    // ?Solve@Spline@@QAEXM@Z
    ARTS_IMPORT void Solve(f32 arg1);

    // ?Update@Spline@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@Spline@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x54];
};

check_size(Spline, 0x74);
