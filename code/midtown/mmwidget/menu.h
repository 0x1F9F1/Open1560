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
    ARTS_EXPORT void DisableIME();

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
    b32 ScanInput(eqEvent* event);

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
