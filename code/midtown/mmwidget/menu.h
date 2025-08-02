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

#include "data7/callback.h"
#include "data7/str.h"
#include "localize/localize.h"
#include "mmwidget/widget.h"

union eqEvent;
class mmIO;

class UIBMButton;
class UIBMLabel;
class UIButton;
class UICompositeScroll;
class UIControlWidget;
class UICWArray;
class UIIcon;
class UIIconW;
class UILabel;
class UIMexButton;
class UISlider;
class UITextDropdown;
class UITextField;
class UITextRoller2;
class UITextRoller;
class UITextScroll;
class UIToggleButton2;
class UIToggleButton;
class UIVScrollBar;

class UIMenu : public asNode
{
public:
    enum class eSource : i32
    {
        Keyboard,
        Mouse
    };

    // ??0UIMenu@@QAE@H@Z
    ARTS_IMPORT UIMenu(i32 menu_id);

    // ??_EUIMenu@@UAEPAXI@Z
    // ??_GUIMenu@@UAEPAXI@Z
    // ??1UIMenu@@UAE@XZ
    ARTS_IMPORT ~UIMenu() override;

    // ?PreSetup@UIMenu@@UAEXXZ
    ARTS_IMPORT virtual void PreSetup();

    // ?PostSetup@UIMenu@@UAEXXZ
    ARTS_EXPORT virtual void PostSetup();

    // ?BackUp@UIMenu@@UAEXXZ
    ARTS_IMPORT virtual void BackUp();

    // ?CheckInput@UIMenu@@UAEXXZ
    ARTS_EXPORT virtual void CheckInput();

    // ?IsAnOptionMenu@UIMenu@@UAEHXZ | inline
    ARTS_EXPORT virtual i32 IsAnOptionMenu();

    // ?AddBMButton@UIMenu@@QAEPAVUIBMButton@@HPADMMHVCallback@@PAHHH1@Z
    ARTS_IMPORT UIBMButton* AddBMButton(i32 arg1, char* arg2, f32 arg3, f32 arg4, i32 arg5, Callback arg6, i32* arg7,
        i32 arg8, i32 arg9, Callback arg10);

    // ?AddBMLabel@UIMenu@@QAEPAVUIBMLabel@@HPADPAVstring@@MMPAH@Z
    ARTS_IMPORT UIBMLabel* AddBMLabel(i32 arg1, char* arg2, string* arg3, f32 arg4, f32 arg5, i32* arg6);

    // ?AddButton@UIMenu@@QAEPAVUIButton@@HPAULocString@@MMMMHHVCallback@@@Z
    ARTS_IMPORT UIButton* AddButton(
        i32 arg1, LocString* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, i32 arg8, Callback arg9);

    // ?AddCWArray@UIMenu@@QAEPAVUICWArray@@HMMMMHVCallback@@@Z
    ARTS_IMPORT UICWArray* AddCWArray(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, i32 arg6, Callback arg7);

    // ?AddCompScroll@UIMenu@@QAEPAVUICompositeScroll@@HMMMMMHPAHHHVCallback@@@Z
    ARTS_IMPORT UICompositeScroll* AddCompScroll(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7,
        i32* arg8, i32 arg9, i32 arg10, Callback arg11);

    // ?AddHotSpot@UIMenu@@QAEPAVuiWidget@@HPADMMMMVCallback@@@Z
    ARTS_IMPORT uiWidget* AddHotSpot(i32 arg1, char* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Callback arg7);

    // ?AddIconW@UIMenu@@QAEPAVUIIconW@@HPAULocString@@PADMMMMVCallback@@@Z | unused
    ARTS_IMPORT UIIconW* AddIconW(
        i32 arg1, LocString* arg2, char* arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, Callback arg8);

    // ?AddLabel@UIMenu@@QAEPAVUILabel@@HPAULocString@@MMMMHH@Z
    ARTS_IMPORT UILabel* AddLabel(i32 id, LocString* text, f32 x, f32 y, f32 w, f32 h, i32 flags, i32 font_size);

    // ?AddMex@UIMenu@@QAEPAVUIMexButton@@HPAULocString@@PAHHMMMMHHVCallback@@@Z | unused
    ARTS_IMPORT UIMexButton* AddMex(i32 arg1, LocString* arg2, i32* arg3, i32 arg4, f32 arg5, f32 arg6, f32 arg7,
        f32 arg8, i32 arg9, i32 arg10, Callback arg11);

    // ?AddSlider@UIMenu@@QAEPAVUISlider@@HPAULocString@@PAMMMMMMMHHHHVCallback@@@Z
    ARTS_IMPORT UISlider* AddSlider(i32 arg1, LocString* arg2, f32* arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
        f32 arg8, f32 arg9, i32 arg10, i32 arg11, i32 arg12, i32 arg13, Callback arg14);

    // ?AddTextDropdown@UIMenu@@QAEPAVUITextDropdown@@HPAULocString@@PAHMMMMVstring@@HHHVCallback@@PAD@Z
    ARTS_IMPORT UITextDropdown* AddTextDropdown(i32 arg1, LocString* arg2, i32* arg3, f32 arg4, f32 arg5, f32 arg6,
        f32 arg7, string arg8, i32 arg9, i32 arg10, i32 arg11, Callback arg12, char* arg13);

    // ?AddTextField@UIMenu@@QAEPAVUITextField@@HPAULocString@@PADMMMMHHHHHVCallback@@@Z
    ARTS_IMPORT UITextField* AddTextField(i32 arg1, LocString* arg2, char* arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
        i32 arg8, i32 arg9, i32 arg10, i32 arg11, i32 arg12, Callback arg13);

    // ?AddTextRoller@UIMenu@@QAEPAVUITextRoller@@HPAULocString@@PAHMMMMVstring@@HHHHVCallback@@@Z | unused
    ARTS_IMPORT UITextRoller* AddTextRoller(i32 arg1, LocString* arg2, i32* arg3, f32 arg4, f32 arg5, f32 arg6,
        f32 arg7, string arg8, i32 arg9, i32 arg10, i32 arg11, i32 arg12, Callback arg13);

    // ?AddTextRoller2@UIMenu@@QAEPAVUITextRoller2@@HPAULocString@@PAHMMMMVstring@@HHHHVCallback@@@Z
    ARTS_IMPORT UITextRoller2* AddTextRoller2(i32 arg1, LocString* arg2, i32* arg3, f32 arg4, f32 arg5, f32 arg6,
        f32 arg7, string arg8, i32 arg9, i32 arg10, i32 arg11, i32 arg12, Callback arg13);

    // ?AddTextScroll@UIMenu@@QAEPAVUITextScroll@@HPAXMMMMVstring@@HPAHVCallback@@@Z
    ARTS_IMPORT UITextScroll* AddTextScroll(
        i32 arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, string arg7, i32 arg8, i32* arg9, Callback arg10);

    // ?AddToggle@UIMenu@@QAEPAVUIToggleButton@@HPAULocString@@PAHMMMMHHVCallback@@@Z | unused
    ARTS_IMPORT UIToggleButton* AddToggle(i32 arg1, LocString* arg2, i32* arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
        i32 arg8, i32 arg9, Callback arg10);

    // ?AddToggle2@UIMenu@@QAEPAVUIToggleButton2@@HPAULocString@@PAHMMMMHHVCallback@@@Z
    ARTS_IMPORT UIToggleButton2* AddToggle2(i32 arg1, LocString* arg2, i32* arg3, f32 arg4, f32 arg5, f32 arg6,
        f32 arg7, i32 arg8, i32 arg9, Callback arg10);

    // ?AddUIControl@UIMenu@@QAEPAVUIControlWidget@@HMMMMMPAVmmIO@@VCallback@@@Z | unused
    ARTS_IMPORT UIControlWidget* AddUIControl(
        i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, mmIO* arg7, Callback arg8);

    // ?AddVScrollBar@UIMenu@@QAEPAVUIVScrollBar@@HPAHMMMMMMHHVCallback@@@Z | unused
    ARTS_IMPORT UIVScrollBar* AddVScrollBar(i32 arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
        f32 arg8, i32 arg9, i32 arg10, Callback arg11);

    // ?AddWidget@UIMenu@@QAEXPAVuiWidget@@PADMMMMH1@Z
    ARTS_IMPORT void AddWidget(
        uiWidget* arg1, char* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, char* arg8);

    // ?AssignBackground@UIMenu@@QAEXPAD@Z
    ARTS_IMPORT void AssignBackground(char* arg1);

    // ?AssignName@UIMenu@@QAEXPAULocString@@@Z
    ARTS_IMPORT void AssignName(LocString* arg1);

    // ?CheckMouseHits@UIMenu@@QAEXXZ
    ARTS_IMPORT void CheckMouseHits();

    // ?ClearAction@UIMenu@@QAEXXZ
    ARTS_EXPORT void ClearAction();

    // ?ClearSelected@UIMenu@@QAEXXZ
    ARTS_IMPORT void ClearSelected();

    // ?ClearToolTip@UIMenu@@QAEXXZ
    ARTS_IMPORT void ClearToolTip();

    // ?ClearWidgets@UIMenu@@QAEXXZ
    ARTS_IMPORT void ClearWidgets();

    // ?Decrement@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 Decrement();

    // ?Disable@UIMenu@@QAEXXZ
    ARTS_IMPORT void Disable();

    // ?DisableIME@UIMenu@@QAEXXZ
    ARTS_IMPORT void DisableIME();

    // ?Enable@UIMenu@@QAEXXZ
    ARTS_IMPORT void Enable();

    // ?FindTheFirstFocusWidget@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 FindTheFirstFocusWidget();

    // ?GetBstate@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 GetBstate();

    // ?GetDimensions@UIMenu@@QAEXAAM000@Z
    ARTS_EXPORT void GetDimensions(f32& x, f32& y, f32& w, f32& h);

    // ?GetWidgetID@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 GetWidgetID();

    // ?Increment@UIMenu@@QAEHXZ
    ARTS_IMPORT i32 Increment();

    // ?KeyboardAction@UIMenu@@QAEXTeqEvent@@@Z
    ARTS_IMPORT void KeyboardAction(eqEvent arg1);

    // ?MouseAction@UIMenu@@QAEXTeqEvent@@@Z
    ARTS_IMPORT void MouseAction(eqEvent arg1);

    // ?MouseHitCheck@UIMenu@@QAEPAVuiWidget@@HMM@Z
    ARTS_IMPORT uiWidget* MouseHitCheck(i32 arg1, f32 arg2, f32 arg3);

    // ?ScaleWidget@UIMenu@@QAEXAAM000@Z
    ARTS_EXPORT void ScaleWidget(f32& x, f32& y, f32& w, f32& h);

    // ?ScanInput@UIMenu@@QAEHPATeqEvent@@@Z
    ARTS_EXPORT b32 ScanInput(eqEvent* event);

    // ?SetAction@UIMenu@@QAEXW4eSource@1@@Z
    ARTS_IMPORT void SetAction(UIMenu::eSource arg1);

    // ?SetBstate@UIMenu@@QAEXH@Z
    ARTS_IMPORT void SetBstate(i32 arg1);

    // ?SetFocusWidget@UIMenu@@QAEXH@Z
    ARTS_IMPORT void SetFocusWidget(i32 arg1);

    // ?SetSelected@UIMenu@@QAEXXZ
    ARTS_IMPORT void SetSelected();

    // ?Update@UIMenu@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UI_BOTTOM_MARGIN@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_BOTTOM_MARGIN;

    // ?UI_LEFT_MARGIN@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_LEFT_MARGIN;

    // ?UI_LEFT_MARGIN2@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_LEFT_MARGIN2;

    // ?UI_RIGHT_MARGIN@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_RIGHT_MARGIN;

    // ?UI_TOP_MARGIN@UIMenu@@2MA
    ARTS_IMPORT static f32 UI_TOP_MARGIN;

    // ?WIDGET_HEIGHT@UIMenu@@2MA
    ARTS_IMPORT static f32 WIDGET_HEIGHT;

    // ?WIDGET_WIDTH@UIMenu@@2MA
    ARTS_IMPORT static f32 WIDGET_WIDTH;

    i32 GetState() const
    {
        return state_;
    }

    i32 GetMenuID() const
    {
        return menu_id_;
    }

    i32 GetPreviousMenuID() const
    {
        return prev_menu_id_;
    }

    i32 GetWidgetCount() const
    {
        return widget_count_;
    }

    uiWidget* GetWidget(i32 index) const
    {
        return widgets_[index];
    }

    uiWidget* FindWidget(i32 id);

protected:
    i32 action_source_;
    i32 state_;
    i32 enabled_;
    i32 menu_id_;
    i32 field_30;
    i32 widget_count_;
    i32 field_38;
    uiWidget** widgets_;
    ConstString menu_name_;
    char* field_44;
    i32 field_48;
    f32 menu_x_;
    f32 menu_y_;
    f32 menu_width_;
    f32 menu_height_;
    f32 field_5C;
    f32 field_60;
    f32 field_64;
    i32 field_68;
    i32* p_b_state_;
    i32 b_state_;
    i32 field_74;
    i32 field_78;
    i32 prev_menu_id_;
    i32 active_widget_id_;
    f32 field_84;
    i32 field_88;
    ConstString background_name_;
};

check_size(UIMenu, 0x90);
