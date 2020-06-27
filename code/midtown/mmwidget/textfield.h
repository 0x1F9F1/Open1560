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
    mmwidget:textfield

    0x4B2160 | public: __thiscall UITextField::UITextField(void) | ??0UITextField@@QAE@XZ
    0x4B2270 | public: virtual __thiscall UITextField::~UITextField(void) | ??1UITextField@@UAE@XZ
    0x4B22E0 | public: void __thiscall UITextField::Init(struct LocString *,char *,float,float,float,float,int,int,int,int,int,class Callback,class UIMenu *) | ?Init@UITextField@@QAEXPAULocString@@PADMMMMHHHHHVCallback@@PAVUIMenu@@@Z
    0x4B25F0 | public: void __thiscall UITextField::SetText(struct LocString *) | ?SetText@UITextField@@QAEXPAULocString@@@Z
    0x4B2610 | public: void __thiscall UITextField::SetField(char *) | ?SetField@UITextField@@QAEXPAD@Z
    0x4B2670 | public: virtual void __thiscall UITextField::CaptureAction(union eqEvent) | ?CaptureAction@UITextField@@UAEXTeqEvent@@@Z
    0x4B2680 | public: virtual void __thiscall UITextField::Action(union eqEvent) | ?Action@UITextField@@UAEXTeqEvent@@@Z
    0x4B26D0 | public: void __thiscall UITextField::ClearField(void) | ?ClearField@UITextField@@QAEXXZ
    0x4B2730 | public: void __thiscall UITextField::SetTextField(void) | ?SetTextField@UITextField@@QAEXXZ
    0x4B2780 | public: void __thiscall UITextField::ToggleField(int) | ?ToggleField@UITextField@@QAEXH@Z
    0x4B28E0 | public: virtual void __thiscall UITextField::Switch(int) | ?Switch@UITextField@@UAEXH@Z
    0x4B2980 | public: int __thiscall UITextField::IsValidChar(unsigned short) | ?IsValidChar@UITextField@@QAEHG@Z
    0x4B2A10 | public: void __thiscall UITextField::WmCharHandler(unsigned char) | ?WmCharHandler@UITextField@@QAEXE@Z
    0x4B2B80 | public: void __thiscall UITextField::KeyAction(union eqEvent *) | ?KeyAction@UITextField@@QAEXPATeqEvent@@@Z
    0x4B2C90 | public: void __thiscall UITextField::SetCompositionWindow(void) | ?SetCompositionWindow@UITextField@@QAEXXZ
    0x4B2D80 | public: virtual void * __thiscall UITextField::`vector deleting destructor'(unsigned int) | ??_EUITextField@@UAEPAXI@Z
    0x4B2D80 | public: virtual void * __thiscall UITextField::`scalar deleting destructor'(unsigned int) | ??_GUITextField@@UAEPAXI@Z
    0x4B2DB0 | public: virtual __thiscall uiWidget::~uiWidget(void) | ??1uiWidget@@UAE@XZ
    0x4B2DC0 | public: virtual void __thiscall uiWidget::Disable(void) | ?Disable@uiWidget@@UAEXXZ
    0x4B2DD0 | public: virtual void __thiscall uiWidget::Enable(void) | ?Enable@uiWidget@@UAEXXZ
    0x4B2DE0 | public: virtual void __thiscall uiWidget::TurnOn(void) | ?TurnOn@uiWidget@@UAEXXZ
    0x4B2E00 | public: virtual void __thiscall uiWidget::TurnOff(void) | ?TurnOff@uiWidget@@UAEXXZ
    0x4B2E10 | public: virtual void __thiscall uiWidget::SetReadOnly(int) | ?SetReadOnly@uiWidget@@UAEXH@Z
    0x4B2E30 | public: virtual void __thiscall uiWidget::Action(union eqEvent) | ?Action@uiWidget@@UAEXTeqEvent@@@Z
    0x4B2E40 | public: virtual void __thiscall uiWidget::CaptureAction(union eqEvent) | ?CaptureAction@uiWidget@@UAEXTeqEvent@@@Z
    0x4B2E50 | public: virtual void __thiscall uiWidget::EvalMouseX(float) | ?EvalMouseX@uiWidget@@UAEXM@Z
    0x4B2E60 | public: virtual char * __thiscall uiWidget::ReturnDescription(void) | ?ReturnDescription@uiWidget@@UAEPADXZ
    0x4B2E70 | public: virtual void __thiscall uiWidget::SetPosition(float,float) | ?SetPosition@uiWidget@@UAEXMM@Z
    0x4B2E80 | public: virtual float __thiscall uiWidget::GetScreenHeight(void) | ?GetScreenHeight@uiWidget@@UAEMXZ
    0x4B2E90 | public: virtual void * __thiscall uiWidget::`vector deleting destructor'(unsigned int) | ??_EuiWidget@@UAEPAXI@Z
    0x4B2E90 | public: virtual void * __thiscall uiWidget::`scalar deleting destructor'(unsigned int) | ??_GuiWidget@@UAEPAXI@Z
    0x4B2EC0 | public: virtual void __thiscall UITextField::Update(void) | ?Update@UITextField@@UAEXXZ
    0x61E408 | const UITextField::`vftable' | ??_7UITextField@@6B@
    0x61E478 | const uiWidget::`vftable' | ??_7uiWidget@@6B@
*/

#include "widget.h"

class UITextField : public uiWidget
{
    // const UITextField::`vftable' @ 0x61E408

public:
    // 0x4B2160 | ??0UITextField@@QAE@XZ
    ARTS_IMPORT UITextField();

    // 0x4B2D80 | ??_GUITextField@@UAEPAXI@Z
    // 0x4B2D80 | ??_EUITextField@@UAEPAXI@Z
    // 0x4B2270 | ??1UITextField@@UAE@XZ
    ARTS_IMPORT ~UITextField() override;

    // 0x4B2680 | ?Action@UITextField@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // 0x4B2670 | ?CaptureAction@UITextField@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void CaptureAction(union eqEvent arg1) override;

    // 0x4B26D0 | ?ClearField@UITextField@@QAEXXZ | unused
    ARTS_IMPORT void ClearField();

    // 0x4B22E0 | ?Init@UITextField@@QAEXPAULocString@@PADMMMMHHHHHVCallback@@PAVUIMenu@@@Z
    ARTS_IMPORT void Init(struct LocString* arg1, char* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7,
        i32 arg8, i32 arg9, i32 arg10, i32 arg11, class Callback arg12, class UIMenu* arg13);

    // 0x4B2980 | ?IsValidChar@UITextField@@QAEHG@Z
    ARTS_IMPORT i32 IsValidChar(u16 arg1);

    // 0x4B2B80 | ?KeyAction@UITextField@@QAEXPATeqEvent@@@Z
    ARTS_IMPORT void KeyAction(union eqEvent* arg1);

    // 0x4B2C90 | ?SetCompositionWindow@UITextField@@QAEXXZ
    ARTS_IMPORT void SetCompositionWindow();

    // 0x4B2610 | ?SetField@UITextField@@QAEXPAD@Z
    ARTS_IMPORT void SetField(char* arg1);

    // 0x4B25F0 | ?SetText@UITextField@@QAEXPAULocString@@@Z | unused
    ARTS_IMPORT void SetText(struct LocString* arg1);

    // 0x4B2730 | ?SetTextField@UITextField@@QAEXXZ
    ARTS_IMPORT void SetTextField();

    // 0x4B28E0 | ?Switch@UITextField@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // 0x4B2780 | ?ToggleField@UITextField@@QAEXH@Z
    ARTS_IMPORT void ToggleField(i32 arg1);

    // 0x4B2EC0 | ?Update@UITextField@@UAEXXZ | inline
    ARTS_IMPORT void Update() override;

    // 0x4B2A10 | ?WmCharHandler@UITextField@@QAEXE@Z
    ARTS_IMPORT void WmCharHandler(u8 arg1);

    u8 gap74[0xD0];
};

check_size(UITextField, 0x144);
