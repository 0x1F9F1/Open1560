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

class uiWidget;

class mmSlider final : public asNode
{
public:
    // ??0mmSlider@@QAE@XZ
    ARTS_IMPORT mmSlider();

    // ??1mmSlider@@UAE@XZ
    ARTS_IMPORT ~mmSlider() override;

    // ?Cull@mmSlider@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Dec@mmSlider@@QAEMXZ
    ARTS_IMPORT f32 Dec();

    // ?FudgeWidth@mmSlider@@QAEMXZ
    ARTS_IMPORT f32 FudgeWidth();

    // ?GetClass@mmSlider@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetScreenHeight@mmSlider@@QAEMXZ
    ARTS_IMPORT f32 GetScreenHeight();

    // ?GetSliderHotSpots@mmSlider@@QAEXAAM00000@Z
    ARTS_IMPORT void GetSliderHotSpots(f32& arg1, f32& arg2, f32& arg3, f32& arg4, f32& arg5, f32& arg6);

    // ?Inc@mmSlider@@QAEMXZ
    ARTS_IMPORT f32 Inc();

    // ?Init@mmSlider@@QAEXPADPAVuiWidget@@MMMMHMMHH@Z
    ARTS_IMPORT void Init(char* arg1, uiWidget* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, f32 arg8,
        f32 arg9, i32 arg10, i32 arg11);

    // ?IsReadWrite@mmSlider@@QAEHXZ
    ARTS_IMPORT i32 IsReadWrite();

    // ?LoadBitmap@mmSlider@@QAEXPAD@Z
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // ?SetPosition@mmSlider@@QAEXMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2);

    // ?SetRange@mmSlider@@QAEXMM@Z
    ARTS_IMPORT void SetRange(f32 arg1, f32 arg2);

    // ?SetReadWrite@mmSlider@@QAEXH@Z
    ARTS_IMPORT void SetReadWrite(i32 arg1);

    // ?SetStep@mmSlider@@QAEXM@Z
    ARTS_IMPORT void SetStep(f32 arg1);

    // ?SetValue@mmSlider@@QAEMM@Z
    ARTS_IMPORT f32 SetValue(f32 arg1);

    // ?Update@mmSlider@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdatePosition@mmSlider@@QAEXXZ
    ARTS_IMPORT void UpdatePosition();

    // ?DeclareFields@mmSlider@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x84];
};

check_size(mmSlider, 0xA4);
