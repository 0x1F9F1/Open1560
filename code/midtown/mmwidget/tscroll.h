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
    mmwidget:tscroll

    0x4B87F0 | public: __thiscall UITextScroll::UITextScroll(void) | ??0UITextScroll@@QAE@XZ
    0x4B8900 | public: virtual __thiscall UITextScroll::~UITextScroll(void) | ??1UITextScroll@@UAE@XZ
    0x4B8980 | public: void __thiscall UITextScroll::Init(void *,float,float,float,float,class string,int,int *,class Callback) | ?Init@UITextScroll@@QAEXPAXMMMMVstring@@HPAHVCallback@@@Z
    0x4B8CF0 | public: void __thiscall UITextScroll::InitVScroll(float,float,float) | ?InitVScroll@UITextScroll@@QAEXMMM@Z
    0x4B8D00 | public: void __thiscall UITextScroll::VScrollCB(void) | ?VScrollCB@UITextScroll@@QAEXXZ
    0x4B8D40 | public: void __thiscall UITextScroll::SetVScrollVals(void) | ?SetVScrollVals@UITextScroll@@QAEXXZ
    0x4B8D60 | public: void __thiscall UITextScroll::SetVScrollPos(void) | ?SetVScrollPos@UITextScroll@@QAEXXZ
    0x4B8D90 | public: void __thiscall UITextScroll::Recalc(class string) | ?Recalc@UITextScroll@@QAEXVstring@@@Z
    0x4B8F00 | private: void __thiscall UITextScroll::FillScroll(void) | ?FillScroll@UITextScroll@@AAEXXZ
    0x4B8FE0 | public: void __thiscall UITextScroll::GetCurrentString(char *,int) | ?GetCurrentString@UITextScroll@@QAEXPADH@Z
    0x4B9030 | public: void __thiscall UITextScroll::SetHighlight(int) | ?SetHighlight@UITextScroll@@QAEXH@Z
    0x4B9080 | public: int __thiscall UITextScroll::GetHit(float,float) | ?GetHit@UITextScroll@@QAEHMM@Z
    0x4B9100 | private: void __thiscall UITextScroll::KeyAction(void) | ?KeyAction@UITextScroll@@AAEXXZ
    0x4B9160 | public: virtual void __thiscall UITextScroll::Action(union eqEvent) | ?Action@UITextScroll@@UAEXTeqEvent@@@Z
    0x4B9210 | public: virtual void __thiscall UITextScroll::Switch(int) | ?Switch@UITextScroll@@UAEXH@Z
    0x4B9250 | private: void __thiscall UITextScroll::SetTextColor(void) | ?SetTextColor@UITextScroll@@AAEXXZ
    0x4B92B0 | public: void __thiscall UITextScroll::SetText(int,struct LocString *) | ?SetText@UITextScroll@@QAEXHPAULocString@@@Z
    0x4B92F0 | private: void __thiscall UITextScroll::ResetTextScroll(void) | ?ResetTextScroll@UITextScroll@@AAEXXZ
    0x4B9370 | private: void __thiscall UITextScroll::InitTextScroll(class string) | ?InitTextScroll@UITextScroll@@AAEXVstring@@@Z
    0x4B94A0 | private: void __thiscall UITextScroll::AddTextScrollLine(char *,int) | ?AddTextScrollLine@UITextScroll@@AAEXPADH@Z
    0x4B9530 | private: void __thiscall UITextScroll::AddTextScrollLine(char *) | ?AddTextScrollLine@UITextScroll@@AAEXPAD@Z
    0x4B95D0 | public: virtual void * __thiscall UITextScroll::`scalar deleting destructor'(unsigned int) | ??_GUITextScroll@@UAEPAXI@Z
    0x4B95D0 | public: virtual void * __thiscall UITextScroll::`vector deleting destructor'(unsigned int) | ??_EUITextScroll@@UAEPAXI@Z
    0x61EA98 | const UITextScroll::`vftable' | ??_7UITextScroll@@6B@
*/

#include "widget.h"

class UITextScroll : public uiWidget
{
    // const UITextScroll::`vftable' @ 0x61EA98

public:
    // 0x4B87F0 | ??0UITextScroll@@QAE@XZ
    ARTS_IMPORT UITextScroll();

    // 0x4B95D0 | ??_EUITextScroll@@UAEPAXI@Z
    // 0x4B95D0 | ??_GUITextScroll@@UAEPAXI@Z
    // 0x4B8900 | ??1UITextScroll@@UAE@XZ
    ARTS_IMPORT ~UITextScroll() override;

    // 0x4B9160 | ?Action@UITextScroll@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // 0x4B8FE0 | ?GetCurrentString@UITextScroll@@QAEXPADH@Z | unused
    ARTS_IMPORT void GetCurrentString(char* arg1, i32 arg2);

    // 0x4B9080 | ?GetHit@UITextScroll@@QAEHMM@Z
    ARTS_IMPORT i32 GetHit(f32 arg1, f32 arg2);

    // 0x4B8980 | ?Init@UITextScroll@@QAEXPAXMMMMVstring@@HPAHVCallback@@@Z
    ARTS_IMPORT void Init(void* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, class string arg6, i32 arg7, i32* arg8,
        class Callback arg9);

    // 0x4B8CF0 | ?InitVScroll@UITextScroll@@QAEXMMM@Z
    ARTS_EXPORT void InitVScroll(f32 arg1, f32 arg2, f32 arg3);

    // 0x4B8D90 | ?Recalc@UITextScroll@@QAEXVstring@@@Z
    ARTS_IMPORT void Recalc(class string arg1);

    // 0x4B9030 | ?SetHighlight@UITextScroll@@QAEXH@Z | unused
    ARTS_IMPORT void SetHighlight(i32 arg1);

    // 0x4B92B0 | ?SetText@UITextScroll@@QAEXHPAULocString@@@Z
    ARTS_IMPORT void SetText(i32 arg1, struct LocString* arg2);

    // 0x4B8D60 | ?SetVScrollPos@UITextScroll@@QAEXXZ
    ARTS_IMPORT void SetVScrollPos();

    // 0x4B8D40 | ?SetVScrollVals@UITextScroll@@QAEXXZ
    ARTS_IMPORT void SetVScrollVals();

    // 0x4B9210 | ?Switch@UITextScroll@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // 0x4B8D00 | ?VScrollCB@UITextScroll@@QAEXXZ
    ARTS_IMPORT void VScrollCB();

private:
    // 0x4B9530 | ?AddTextScrollLine@UITextScroll@@AAEXPAD@Z | unused
    ARTS_IMPORT void AddTextScrollLine(char* arg1);

    // 0x4B94A0 | ?AddTextScrollLine@UITextScroll@@AAEXPADH@Z
    ARTS_IMPORT void AddTextScrollLine(char* arg1, i32 arg2);

    // 0x4B8F00 | ?FillScroll@UITextScroll@@AAEXXZ
    ARTS_IMPORT void FillScroll();

    // 0x4B9370 | ?InitTextScroll@UITextScroll@@AAEXVstring@@@Z
    ARTS_IMPORT void InitTextScroll(class string arg1);

    // 0x4B9100 | ?KeyAction@UITextScroll@@AAEXXZ | unused
    ARTS_IMPORT void KeyAction();

    // 0x4B92F0 | ?ResetTextScroll@UITextScroll@@AAEXXZ
    ARTS_IMPORT void ResetTextScroll();

    // 0x4B9250 | ?SetTextColor@UITextScroll@@AAEXXZ
    ARTS_IMPORT void SetTextColor();

    u8 gap74[0x70];
};

check_size(UITextScroll, 0xE4);
