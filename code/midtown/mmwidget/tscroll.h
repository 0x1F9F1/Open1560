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

class UITextScroll final : public uiWidget
{
public:
    // ??0UITextScroll@@QAE@XZ
    ARTS_IMPORT UITextScroll();

    // ??_EUITextScroll@@UAEPAXI@Z
    // ??_GUITextScroll@@UAEPAXI@Z
    // ??1UITextScroll@@UAE@XZ
    ARTS_IMPORT ~UITextScroll() override;

    // ?Action@UITextScroll@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?GetHit@UITextScroll@@QAEHMM@Z
    ARTS_IMPORT i32 GetHit(f32 arg1, f32 arg2);

    // ?Init@UITextScroll@@QAEXPAXMMMMVstring@@HPAHVCallback@@@Z
    ARTS_IMPORT void Init(
        void* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, string arg6, i32 arg7, i32* arg8, Callback arg9);

    // ?InitVScroll@UITextScroll@@QAEXMMM@Z
    ARTS_EXPORT void InitVScroll(f32 arg1, f32 arg2, f32 arg3);

    // ?Recalc@UITextScroll@@QAEXVstring@@@Z
    ARTS_IMPORT void Recalc(string arg1);

    // ?SetText@UITextScroll@@QAEXHPAULocString@@@Z
    ARTS_IMPORT void SetText(i32 arg1, LocString* arg2);

    // ?SetVScrollPos@UITextScroll@@QAEXXZ
    ARTS_IMPORT void SetVScrollPos();

    // ?SetVScrollVals@UITextScroll@@QAEXXZ
    ARTS_IMPORT void SetVScrollVals();

    // ?Switch@UITextScroll@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?VScrollCB@UITextScroll@@QAEXXZ
    ARTS_IMPORT void VScrollCB();

private:
    // ?AddTextScrollLine@UITextScroll@@AAEXPADH@Z
    ARTS_IMPORT void AddTextScrollLine(char* arg1, i32 arg2);

    // ?FillScroll@UITextScroll@@AAEXXZ
    ARTS_IMPORT void FillScroll();

    // ?InitTextScroll@UITextScroll@@AAEXVstring@@@Z
    ARTS_IMPORT void InitTextScroll(string arg1);

    // ?ResetTextScroll@UITextScroll@@AAEXXZ
    ARTS_IMPORT void ResetTextScroll();

    // ?SetTextColor@UITextScroll@@AAEXXZ
    ARTS_IMPORT void SetTextColor();

    u8 gap74[0x70];
};

check_size(UITextScroll, 0xE4);
