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
    mmwidget:menu

    0x4AC7F0 | public: __thiscall UIMenu::UIMenu(int) | ??0UIMenu@@QAE@H@Z
    0x4AC8F0 | public: virtual __thiscall UIMenu::~UIMenu(void) | ??1UIMenu@@UAE@XZ
    0x4AC990 | public: void __thiscall UIMenu::AssignName(struct LocString *) | ?AssignName@UIMenu@@QAEXPAULocString@@@Z
    0x4AC9E0 | public: void __thiscall UIMenu::AssignBackground(char *) | ?AssignBackground@UIMenu@@QAEXPAD@Z
    0x4ACA30 | public: void __thiscall UIMenu::Enable(void) | ?Enable@UIMenu@@QAEXXZ
    0x4ACAB0 | public: void __thiscall UIMenu::Disable(void) | ?Disable@UIMenu@@QAEXXZ
    0x4ACAD0 | public: virtual void __thiscall UIMenu::PreSetup(void) | ?PreSetup@UIMenu@@UAEXXZ
    0x4ACB00 | public: virtual void __thiscall UIMenu::PostSetup(void) | ?PostSetup@UIMenu@@UAEXXZ
    0x4ACB10 | public: virtual void __thiscall UIMenu::Update(void) | ?Update@UIMenu@@UAEXXZ
    0x4ACB20 | public: void __thiscall UIMenu::SetAction(enum UIMenu::eSource) | ?SetAction@UIMenu@@QAEXW4eSource@1@@Z
    0x4ACB40 | public: void __thiscall UIMenu::ForceWidgetAction(int) | ?ForceWidgetAction@UIMenu@@QAEXH@Z
    0x4ACB60 | public: void __thiscall UIMenu::ClearAction(void) | ?ClearAction@UIMenu@@QAEXXZ
    0x4ACB70 | public: void __thiscall UIMenu::ClearToolTip(void) | ?ClearToolTip@UIMenu@@QAEXXZ
    0x4ACBA0 | public: virtual void __thiscall UIMenu::BackUp(void) | ?BackUp@UIMenu@@UAEXXZ
    0x4ACBB0 | public: void __thiscall UIMenu::SetBstate(int) | ?SetBstate@UIMenu@@QAEXH@Z
    0x4ACBE0 | public: void __thiscall UIMenu::SetFocusWidget(int) | ?SetFocusWidget@UIMenu@@QAEXH@Z
    0x4ACC20 | public: int __thiscall UIMenu::GetWidgetID(void) | ?GetWidgetID@UIMenu@@QAEHXZ
    0x4ACC30 | public: int __thiscall UIMenu::GetBstate(void) | ?GetBstate@UIMenu@@QAEHXZ
    0x4ACC40 | public: void __thiscall UIMenu::GetDimensions(float &,float &,float &,float &) | ?GetDimensions@UIMenu@@QAEXAAM000@Z
    0x4ACC70 | public: void __thiscall UIMenu::DisableIME(void) | ?DisableIME@UIMenu@@QAEXXZ
    0x4ACC90 | public: int __thiscall UIMenu::FindTheFirstFocusWidget(void) | ?FindTheFirstFocusWidget@UIMenu@@QAEHXZ
    0x4ACCD0 | public: int __thiscall UIMenu::Increment(void) | ?Increment@UIMenu@@QAEHXZ
    0x4ACD90 | public: int __thiscall UIMenu::Decrement(void) | ?Decrement@UIMenu@@QAEHXZ
    0x4ACE40 | public: int __thiscall UIMenu::ScanInput(union eqEvent *) | ?ScanInput@UIMenu@@QAEHPATeqEvent@@@Z
    0x4ACE80 | public: virtual void __thiscall UIMenu::CheckInput(void) | ?CheckInput@UIMenu@@UAEXXZ
    0x4ACF20 | public: void __thiscall UIMenu::ScaleWidget(float &,float &,float &,float &) | ?ScaleWidget@UIMenu@@QAEXAAM000@Z
    0x4ACF60 | public: class uiWidget * __thiscall UIMenu::AddHotSpot(int,char *,float,float,float,float,class Callback) | ?AddHotSpot@UIMenu@@QAEPAVuiWidget@@HPADMMMMVCallback@@@Z
    0x4AD040 | public: class UITextDropdown * __thiscall UIMenu::AddTextDropdown(int,struct LocString *,int *,float,float,float,float,class string,int,int,int,class Callback,char *) | ?AddTextDropdown@UIMenu@@QAEPAVUITextDropdown@@HPAULocString@@PAHMMMMVstring@@HHHVCallback@@PAD@Z
    0x4AD1C0 | public: class UITextRoller * __thiscall UIMenu::AddTextRoller(int,struct LocString *,int *,float,float,float,float,class string,int,int,int,int,class Callback) | ?AddTextRoller@UIMenu@@QAEPAVUITextRoller@@HPAULocString@@PAHMMMMVstring@@HHHHVCallback@@@Z
    0x4AD310 | public: class UITextRoller2 * __thiscall UIMenu::AddTextRoller2(int,struct LocString *,int *,float,float,float,float,class string,int,int,int,int,class Callback) | ?AddTextRoller2@UIMenu@@QAEPAVUITextRoller2@@HPAULocString@@PAHMMMMVstring@@HHHHVCallback@@@Z
    0x4AD490 | public: class UITextScroll * __thiscall UIMenu::AddTextScroll(int,void *,float,float,float,float,class string,int,int *,class Callback) | ?AddTextScroll@UIMenu@@QAEPAVUITextScroll@@HPAXMMMMVstring@@HPAHVCallback@@@Z
    0x4AD630 | public: class UICompositeScroll * __thiscall UIMenu::AddCompScroll(int,float,float,float,float,float,int,int *,int,int,class Callback) | ?AddCompScroll@UIMenu@@QAEPAVUICompositeScroll@@HMMMMMHPAHHHVCallback@@@Z
    0x4AD7B0 | public: class UITextField * __thiscall UIMenu::AddTextField(int,struct LocString *,char *,float,float,float,float,int,int,int,int,int,class Callback) | ?AddTextField@UIMenu@@QAEPAVUITextField@@HPAULocString@@PADMMMMHHHHHVCallback@@@Z
    0x4AD920 | public: class UIControlWidget * __thiscall UIMenu::AddUIControl(int,float,float,float,float,float,class mmIO *,class Callback) | ?AddUIControl@UIMenu@@QAEPAVUIControlWidget@@HMMMMMPAVmmIO@@VCallback@@@Z
    0x4AD9F0 | public: class UISlider * __thiscall UIMenu::AddSlider(int,struct LocString *,float *,float,float,float,float,float,float,int,int,int,int,class Callback) | ?AddSlider@UIMenu@@QAEPAVUISlider@@HPAULocString@@PAMMMMMMMHHHHVCallback@@@Z
    0x4ADB30 | public: class UIButton * __thiscall UIMenu::AddButton(int,struct LocString *,float,float,float,float,int,int,class Callback) | ?AddButton@UIMenu@@QAEPAVUIButton@@HPAULocString@@MMMMHHVCallback@@@Z
    0x4ADC50 | public: class UILabel * __thiscall UIMenu::AddLabel(int,struct LocString *,float,float,float,float,int,int) | ?AddLabel@UIMenu@@QAEPAVUILabel@@HPAULocString@@MMMMHH@Z
    0x4ADD60 | public: class UIBMLabel * __thiscall UIMenu::AddBMLabel(int,char *,class string *,float,float,int *) | ?AddBMLabel@UIMenu@@QAEPAVUIBMLabel@@HPADPAVstring@@MMPAH@Z
    0x4ADE70 | public: class UIIcon * __thiscall UIMenu::AddIcon(int,char *,float,float) | ?AddIcon@UIMenu@@QAEPAVUIIcon@@HPADMM@Z
    0x4ADF80 | public: class UIIconW * __thiscall UIMenu::AddIconW(int,struct LocString *,char *,float,float,float,float,class Callback) | ?AddIconW@UIMenu@@QAEPAVUIIconW@@HPAULocString@@PADMMMMVCallback@@@Z
    0x4AE090 | public: class UIToggleButton * __thiscall UIMenu::AddToggle(int,struct LocString *,int *,float,float,float,float,int,int,class Callback) | ?AddToggle@UIMenu@@QAEPAVUIToggleButton@@HPAULocString@@PAHMMMMHHVCallback@@@Z
    0x4AE1B0 | public: class UIToggleButton2 * __thiscall UIMenu::AddToggle2(int,struct LocString *,int *,float,float,float,float,int,int,class Callback) | ?AddToggle2@UIMenu@@QAEPAVUIToggleButton2@@HPAULocString@@PAHMMMMHHVCallback@@@Z
    0x4AE2D0 | public: class UIMexButton * __thiscall UIMenu::AddMex(int,struct LocString *,int *,int,float,float,float,float,int,int,class Callback) | ?AddMex@UIMenu@@QAEPAVUIMexButton@@HPAULocString@@PAHHMMMMHHVCallback@@@Z
    0x4AE3F0 | public: class UIBMButton * __thiscall UIMenu::AddBMButton(int,char *,float,float,int,class Callback,int *,int,int,class Callback) | ?AddBMButton@UIMenu@@QAEPAVUIBMButton@@HPADMMHVCallback@@PAHHH1@Z
    0x4AE580 | public: class UICWArray * __thiscall UIMenu::AddCWArray(int,float,float,float,float,int,class Callback) | ?AddCWArray@UIMenu@@QAEPAVUICWArray@@HMMMMHVCallback@@@Z
    0x4AE6C0 | public: class UIVScrollBar * __thiscall UIMenu::AddVScrollBar(int,int *,float,float,float,float,float,float,int,int,class Callback) | ?AddVScrollBar@UIMenu@@QAEPAVUIVScrollBar@@HPAHMMMMMMHHVCallback@@@Z
    0x4AE810 | public: void __thiscall UIMenu::MouseAction(union eqEvent) | ?MouseAction@UIMenu@@QAEXTeqEvent@@@Z
    0x4AE880 | public: void __thiscall UIMenu::KeyboardAction(union eqEvent) | ?KeyboardAction@UIMenu@@QAEXTeqEvent@@@Z
    0x4AE910 | public: class uiWidget * __thiscall UIMenu::MouseHitCheck(int,float,float) | ?MouseHitCheck@UIMenu@@QAEPAVuiWidget@@HMM@Z
    0x4AEA40 | public: void __thiscall UIMenu::SetSelected(void) | ?SetSelected@UIMenu@@QAEXXZ
    0x4AEA70 | public: void __thiscall UIMenu::ClearSelected(void) | ?ClearSelected@UIMenu@@QAEXXZ
    0x4AEAA0 | public: void __thiscall UIMenu::ClearWidgets(void) | ?ClearWidgets@UIMenu@@QAEXXZ
    0x4AEAD0 | public: void __thiscall UIMenu::CheckMouseHits(void) | ?CheckMouseHits@UIMenu@@QAEXXZ
    0x4AEC40 | public: void __thiscall UIMenu::AddWidget(class uiWidget *,char *,float,float,float,float,int,char *) | ?AddWidget@UIMenu@@QAEXPAVuiWidget@@PADMMMMH1@Z
    0x4AED30 | public: virtual void * __thiscall UIMenu::`scalar deleting destructor'(unsigned int) | ??_GUIMenu@@UAEPAXI@Z
    0x4AED30 | public: virtual void * __thiscall UIMenu::`vector deleting destructor'(unsigned int) | ??_EUIMenu@@UAEPAXI@Z
    0x61E2E8 | const UIMenu::`vftable' | ??_7UIMenu@@6B@
    0x641848 | public: static float UIMenu::UI_LEFT_MARGIN | ?UI_LEFT_MARGIN@UIMenu@@2MA
    0x64184C | public: static float UIMenu::UI_LEFT_MARGIN2 | ?UI_LEFT_MARGIN2@UIMenu@@2MA
    0x641850 | public: static float UIMenu::UI_TOP_MARGIN | ?UI_TOP_MARGIN@UIMenu@@2MA
    0x641854 | public: static float UIMenu::UI_BOTTOM_MARGIN | ?UI_BOTTOM_MARGIN@UIMenu@@2MA
    0x641858 | public: static float UIMenu::WIDGET_WIDTH | ?WIDGET_WIDTH@UIMenu@@2MA
    0x64185C | public: static float UIMenu::WIDGET_HEIGHT | ?WIDGET_HEIGHT@UIMenu@@2MA
    0x70595C | public: static float UIMenu::UI_RIGHT_MARGIN | ?UI_RIGHT_MARGIN@UIMenu@@2MA
*/

#include "arts7/node.h"

class UIMenu : public asNode
{
    // const UIMenu::`vftable' @ 0x61E2E8

public:
    // 0x4AC7F0 | ??0UIMenu@@QAE@H@Z
    ARTS_IMPORT UIMenu(i32 arg1);

    // 0x4AED30 | ??_EUIMenu@@UAEPAXI@Z
    // 0x4AC8F0 | ??1UIMenu@@UAE@XZ
    ARTS_IMPORT ~UIMenu() override;

    // 0x4ACAD0 | ?PreSetup@UIMenu@@UAEXXZ
    ARTS_IMPORT virtual void PreSetup();

    // 0x4ACB00 | ?PostSetup@UIMenu@@UAEXXZ
    ARTS_IMPORT virtual void PostSetup();

    // 0x4ACBA0 | ?BackUp@UIMenu@@UAEXXZ
    ARTS_IMPORT virtual void BackUp();

    // 0x4ACE80 | ?CheckInput@UIMenu@@UAEXXZ
    ARTS_IMPORT virtual void CheckInput();

    // 0x49C4F0 | ?IsAnOptionMenu@UIMenu@@UAEHXZ | inline
    ARTS_IMPORT virtual i32 IsAnOptionMenu();

    // 0x4AE3F0 | ?AddBMButton@UIMenu@@QAEPAVUIBMButton@@HPADMMHVCallback@@PAHHH1@Z
    ARTS_IMPORT class UIBMButton* AddBMButton(i32 arg1, char* arg2, f32 arg3, f32 arg4, i32 arg5, class Callback arg6,
        i32* arg7, i32 arg8, i32 arg9, class Callback arg10);

    // 0x4ADD60 | ?AddBMLabel@UIMenu@@QAEPAVUIBMLabel@@HPADPAVstring@@MMPAH@Z
    ARTS_IMPORT class UIBMLabel* AddBMLabel(i32 arg1, char* arg2, class string* arg3, f32 arg4, f32 arg5, i32* arg6);

    // 0x4ADB30 | ?AddButton@UIMenu@@QAEPAVUIButton@@HPAULocString@@MMMMHHVCallback@@@Z
    ARTS_IMPORT class UIButton* AddButton(i32 arg1, struct LocString* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
        i32 arg7, i32 arg8, class Callback arg9);

    // 0x4AE580 | ?AddCWArray@UIMenu@@QAEPAVUICWArray@@HMMMMHVCallback@@@Z
    ARTS_IMPORT class UICWArray* AddCWArray(
        i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, i32 arg6, class Callback arg7);

    // 0x4AD630 | ?AddCompScroll@UIMenu@@QAEPAVUICompositeScroll@@HMMMMMHPAHHHVCallback@@@Z
    ARTS_IMPORT class UICompositeScroll* AddCompScroll(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
        i32 arg7, i32* arg8, i32 arg9, i32 arg10, class Callback arg11);

    // 0x4ACF60 | ?AddHotSpot@UIMenu@@QAEPAVuiWidget@@HPADMMMMVCallback@@@Z
    ARTS_IMPORT class uiWidget* AddHotSpot(
        i32 arg1, char* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class Callback arg7);

    // 0x4ADE70 | ?AddIcon@UIMenu@@QAEPAVUIIcon@@HPADMM@Z | unused
    ARTS_IMPORT class UIIcon* AddIcon(i32 arg1, char* arg2, f32 arg3, f32 arg4);

    // 0x4ADF80 | ?AddIconW@UIMenu@@QAEPAVUIIconW@@HPAULocString@@PADMMMMVCallback@@@Z | unused
    ARTS_IMPORT class UIIconW* AddIconW(
        i32 arg1, struct LocString* arg2, char* arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, class Callback arg8);

    // 0x4ADC50 | ?AddLabel@UIMenu@@QAEPAVUILabel@@HPAULocString@@MMMMHH@Z
    ARTS_IMPORT class UILabel* AddLabel(
        i32 arg1, struct LocString* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, i32 arg8);

    // 0x4AE2D0 | ?AddMex@UIMenu@@QAEPAVUIMexButton@@HPAULocString@@PAHHMMMMHHVCallback@@@Z | unused
    ARTS_IMPORT class UIMexButton* AddMex(i32 arg1, struct LocString* arg2, i32* arg3, i32 arg4, f32 arg5, f32 arg6,
        f32 arg7, f32 arg8, i32 arg9, i32 arg10, class Callback arg11);

    // 0x4AD9F0 | ?AddSlider@UIMenu@@QAEPAVUISlider@@HPAULocString@@PAMMMMMMMHHHHVCallback@@@Z
    ARTS_IMPORT class UISlider* AddSlider(i32 arg1, struct LocString* arg2, f32* arg3, f32 arg4, f32 arg5, f32 arg6,
        f32 arg7, f32 arg8, f32 arg9, i32 arg10, i32 arg11, i32 arg12, i32 arg13, class Callback arg14);

    // 0x4AD040 | ?AddTextDropdown@UIMenu@@QAEPAVUITextDropdown@@HPAULocString@@PAHMMMMVstring@@HHHVCallback@@PAD@Z
    ARTS_IMPORT class UITextDropdown* AddTextDropdown(i32 arg1, struct LocString* arg2, i32* arg3, f32 arg4, f32 arg5,
        f32 arg6, f32 arg7, class string arg8, i32 arg9, i32 arg10, i32 arg11, class Callback arg12, char* arg13);

    // 0x4AD7B0 | ?AddTextField@UIMenu@@QAEPAVUITextField@@HPAULocString@@PADMMMMHHHHHVCallback@@@Z
    ARTS_IMPORT class UITextField* AddTextField(i32 arg1, struct LocString* arg2, char* arg3, f32 arg4, f32 arg5,
        f32 arg6, f32 arg7, i32 arg8, i32 arg9, i32 arg10, i32 arg11, i32 arg12, class Callback arg13);

    // 0x4AD1C0 | ?AddTextRoller@UIMenu@@QAEPAVUITextRoller@@HPAULocString@@PAHMMMMVstring@@HHHHVCallback@@@Z | unused
    ARTS_IMPORT class UITextRoller* AddTextRoller(i32 arg1, struct LocString* arg2, i32* arg3, f32 arg4, f32 arg5,
        f32 arg6, f32 arg7, class string arg8, i32 arg9, i32 arg10, i32 arg11, i32 arg12, class Callback arg13);

    // 0x4AD310 | ?AddTextRoller2@UIMenu@@QAEPAVUITextRoller2@@HPAULocString@@PAHMMMMVstring@@HHHHVCallback@@@Z
    ARTS_IMPORT class UITextRoller2* AddTextRoller2(i32 arg1, struct LocString* arg2, i32* arg3, f32 arg4, f32 arg5,
        f32 arg6, f32 arg7, class string arg8, i32 arg9, i32 arg10, i32 arg11, i32 arg12, class Callback arg13);

    // 0x4AD490 | ?AddTextScroll@UIMenu@@QAEPAVUITextScroll@@HPAXMMMMVstring@@HPAHVCallback@@@Z
    ARTS_IMPORT class UITextScroll* AddTextScroll(i32 arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
        class string arg7, i32 arg8, i32* arg9, class Callback arg10);

    // 0x4AE090 | ?AddToggle@UIMenu@@QAEPAVUIToggleButton@@HPAULocString@@PAHMMMMHHVCallback@@@Z | unused
    ARTS_IMPORT class UIToggleButton* AddToggle(i32 arg1, struct LocString* arg2, i32* arg3, f32 arg4, f32 arg5,
        f32 arg6, f32 arg7, i32 arg8, i32 arg9, class Callback arg10);

    // 0x4AE1B0 | ?AddToggle2@UIMenu@@QAEPAVUIToggleButton2@@HPAULocString@@PAHMMMMHHVCallback@@@Z
    ARTS_IMPORT class UIToggleButton2* AddToggle2(i32 arg1, struct LocString* arg2, i32* arg3, f32 arg4, f32 arg5,
        f32 arg6, f32 arg7, i32 arg8, i32 arg9, class Callback arg10);

    // 0x4AD920 | ?AddUIControl@UIMenu@@QAEPAVUIControlWidget@@HMMMMMPAVmmIO@@VCallback@@@Z | unused
    ARTS_IMPORT class UIControlWidget* AddUIControl(
        i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class mmIO* arg7, class Callback arg8);

    // 0x4AE6C0 | ?AddVScrollBar@UIMenu@@QAEPAVUIVScrollBar@@HPAHMMMMMMHHVCallback@@@Z | unused
    ARTS_IMPORT class UIVScrollBar* AddVScrollBar(i32 arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
        f32 arg8, i32 arg9, i32 arg10, class Callback arg11);

    // 0x4AEC40 | ?AddWidget@UIMenu@@QAEXPAVuiWidget@@PADMMMMH1@Z
    ARTS_IMPORT void AddWidget(
        class uiWidget* arg1, char* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, char* arg8);

    // 0x4AC9E0 | ?AssignBackground@UIMenu@@QAEXPAD@Z
    ARTS_IMPORT void AssignBackground(char* arg1);

    // 0x4AC990 | ?AssignName@UIMenu@@QAEXPAULocString@@@Z
    ARTS_IMPORT void AssignName(struct LocString* arg1);

    // 0x4AEAD0 | ?CheckMouseHits@UIMenu@@QAEXXZ
    ARTS_IMPORT void CheckMouseHits();

    // 0x4ACB60 | ?ClearAction@UIMenu@@QAEXXZ
    ARTS_IMPORT void ClearAction();

    // 0x4AEA70 | ?ClearSelected@UIMenu@@QAEXXZ
    ARTS_IMPORT void ClearSelected();

    // 0x4ACB70 | ?ClearToolTip@UIMenu@@QAEXXZ
    ARTS_IMPORT void ClearToolTip();

    // 0x4AEAA0 | ?ClearWidgets@UIMenu@@QAEXXZ
    ARTS_IMPORT void ClearWidgets();

    // 0x4ACD90 | ?Decrement@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 Decrement();

    // 0x4ACAB0 | ?Disable@UIMenu@@QAEXXZ
    ARTS_IMPORT void Disable();

    // 0x4ACC70 | ?DisableIME@UIMenu@@QAEXXZ
    ARTS_IMPORT void DisableIME();

    // 0x4ACA30 | ?Enable@UIMenu@@QAEXXZ
    ARTS_IMPORT void Enable();

    // 0x4ACC90 | ?FindTheFirstFocusWidget@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 FindTheFirstFocusWidget();

    // 0x4ACB40 | ?ForceWidgetAction@UIMenu@@QAEXH@Z | unused
    ARTS_IMPORT void ForceWidgetAction(i32 arg1);

    // 0x4ACC30 | ?GetBstate@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 GetBstate();

    // 0x4ACC40 | ?GetDimensions@UIMenu@@QAEXAAM000@Z
    ARTS_IMPORT void GetDimensions(f32& arg1, f32& arg2, f32& arg3, f32& arg4);

    // 0x4ACC20 | ?GetWidgetID@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 GetWidgetID();

    // 0x4ACCD0 | ?Increment@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 Increment();

    // 0x4AE880 | ?KeyboardAction@UIMenu@@QAEXTeqEvent@@@Z
    ARTS_IMPORT void KeyboardAction(union eqEvent arg1);

    // 0x4AE810 | ?MouseAction@UIMenu@@QAEXTeqEvent@@@Z
    ARTS_IMPORT void MouseAction(union eqEvent arg1);

    // 0x4AE910 | ?MouseHitCheck@UIMenu@@QAEPAVuiWidget@@HMM@Z
    ARTS_IMPORT class uiWidget* MouseHitCheck(i32 arg1, f32 arg2, f32 arg3);

    // 0x4ACF20 | ?ScaleWidget@UIMenu@@QAEXAAM000@Z
    ARTS_IMPORT void ScaleWidget(f32& arg1, f32& arg2, f32& arg3, f32& arg4);

    // 0x4ACE40 | ?ScanInput@UIMenu@@QAEHPATeqEvent@@@Z
    ARTS_IMPORT i32 ScanInput(union eqEvent* arg1);

    // 0x4ACB20 | ?SetAction@UIMenu@@QAEXW4eSource@1@@Z
    ARTS_IMPORT void SetAction(enum UIMenu::eSource arg1);

    // 0x4ACBB0 | ?SetBstate@UIMenu@@QAEXH@Z
    ARTS_IMPORT void SetBstate(i32 arg1);

    // 0x4ACBE0 | ?SetFocusWidget@UIMenu@@QAEXH@Z
    ARTS_IMPORT void SetFocusWidget(i32 arg1);

    // 0x4AEA40 | ?SetSelected@UIMenu@@QAEXXZ
    ARTS_IMPORT void SetSelected();

    // 0x4ACB10 | ?Update@UIMenu@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x641854 | ?UI_BOTTOM_MARGIN@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_BOTTOM_MARGIN;

    // 0x641848 | ?UI_LEFT_MARGIN@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_LEFT_MARGIN;

    // 0x64184C | ?UI_LEFT_MARGIN2@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_LEFT_MARGIN2;

    // 0x70595C | ?UI_RIGHT_MARGIN@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_RIGHT_MARGIN;

    // 0x641850 | ?UI_TOP_MARGIN@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_TOP_MARGIN;

    // 0x64185C | ?WIDGET_HEIGHT@UIMenu@@2MA
    ARTS_IMPORT static f32 WIDGET_HEIGHT;

    // 0x641858 | ?WIDGET_WIDTH@UIMenu@@2MA
    ARTS_IMPORT static f32 WIDGET_WIDTH;

    u8 gap20[0x70];
};

check_size(UIMenu, 0x90);
