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

class UIVScrollBar final : public uiWidget
{
public:
    // ??0UIVScrollBar@@QAE@XZ
    ARTS_IMPORT UIVScrollBar();

    // ??_EUIVScrollBar@@UAEPAXI@Z
    // ??1UIVScrollBar@@UAE@XZ
    ARTS_IMPORT ~UIVScrollBar() override;

    // ?Action@UIVScrollBar@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?Cull@UIVScrollBar@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Dec@UIVScrollBar@@QAEMXZ
    ARTS_IMPORT f32 Dec();

    // ?Disable@UIVScrollBar@@UAEXXZ | inline
    ARTS_IMPORT void Disable() override;

    // ?Enable@UIVScrollBar@@UAEXXZ | inline
    ARTS_IMPORT void Enable() override;

    // ?EvalMouseXY@UIVScrollBar@@QAEXMM@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2);

    // ?GetClass@UIVScrollBar@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Inc@UIVScrollBar@@QAEMXZ
    ARTS_IMPORT f32 Inc();

    // ?Init@UIVScrollBar@@QAEXMMMMHMMPAHVCallback@@H@Z
    ARTS_IMPORT void Init(
        f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5, f32 arg6, f32 arg7, i32* arg8, Callback arg9, i32 arg10);

    // ?LoadBitmap@UIVScrollBar@@QAEXXZ
    ARTS_IMPORT void LoadBitmap();

    // ?SetHotSpots@UIVScrollBar@@QAEXXZ
    ARTS_IMPORT void SetHotSpots();

    // ?SetPosition@UIVScrollBar@@UAEXMM@Z | inline
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2) override;

    // ?SetRange@UIVScrollBar@@QAEXMM@Z
    ARTS_IMPORT void SetRange(f32 arg1, f32 arg2);

    // ?SetStep@UIVScrollBar@@QAEXHM@Z
    ARTS_IMPORT void SetStep(i32 arg1, f32 arg2);

    // ?SetTrough@UIVScrollBar@@QAEXMM@Z
    ARTS_IMPORT void SetTrough(f32 arg1, f32 arg2);

    // ?Switch@UIVScrollBar@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Update@UIVScrollBar@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@UIVScrollBar@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap74[0x98];
};

check_size(UIVScrollBar, 0x10C);
