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

#include "widget.h"

class UISlider final : public uiWidget
{
public:
    // ??0UISlider@@QAE@XZ
    ARTS_IMPORT UISlider();

    // ??_EUISlider@@UAEPAXI@Z
    // ??_GUISlider@@UAEPAXI@Z
    // ??1UISlider@@UAE@XZ
    ARTS_IMPORT ~UISlider() override;

    // ?Action@UISlider@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?EvalMouseXY@UISlider@@QAEXMM@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2);

    // ?GetFudgeWidth@UISlider@@QAEMXZ
    ARTS_IMPORT f32 GetFudgeWidth();

    // ?GetScreenHeight@UISlider@@UAEMXZ | inline
    ARTS_IMPORT f32 GetScreenHeight() override;

    // ?Init@UISlider@@QAEXPAULocString@@PAMMMMMMMHHHHVCallback@@PAVUIMenu@@@Z
    ARTS_IMPORT void Init(LocString* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
        i32 arg9, i32 arg10, i32 arg11, i32 arg12, Callback arg13, UIMenu* arg14);

    // ?SetData@UISlider@@QAEXM@Z
    ARTS_IMPORT void SetData(f32 arg1);

    // ?SetMouseParams@UISlider@@QAEXM@Z
    ARTS_IMPORT void SetMouseParams(f32 arg1);

    // ?SetPosition@UISlider@@UAEXMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2) override;

    // ?SetReadWrite@UISlider@@QAEXH@Z
    ARTS_IMPORT void SetReadWrite(i32 arg1);

    // ?SetText@UISlider@@QAEXPAULocString@@@Z | unused
    ARTS_EXPORT void SetText(LocString* arg1);

    // ?SetValue@UISlider@@QAEMM@Z
    ARTS_IMPORT f32 SetValue(f32 arg1);

    // ?Switch@UISlider@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?TestHit@UISlider@@QAEHMM@Z | unused
    ARTS_EXPORT i32 TestHit(f32 arg1, f32 arg2);

    // ?Update@UISlider@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap74[0x58];
};

check_size(UISlider, 0xCC);
