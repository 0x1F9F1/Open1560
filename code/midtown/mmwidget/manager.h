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
#include "data7/str.h"

class asCamera;
class asLamp;
class asLinearCS;
class asViewCS;
class AudSound;
class Card2D;
class eqEventQ;
class MArray;
class mmTextNode;
class sfPointer;
class UIIcon;
class UIMenu;
class uiNavBar;
class uiWidget;
class WArray;

class MenuManager final : public asNode
{
public:
    // ??0MenuManager@@QAE@XZ
    ARTS_IMPORT MenuManager();

    // ??_EMenuManager@@UAEPAXI@Z
    // ??_GMenuManager@@UAEPAXI@Z
    // ??1MenuManager@@UAE@XZ
    ARTS_IMPORT ~MenuManager() override;

    // ?AddBrackets@MenuManager@@QAEXPAVUIIcon@@0PAVuiWidget@@MM@Z
    ARTS_IMPORT void AddBrackets(UIIcon* arg1, UIIcon* arg2, uiWidget* arg3, f32 arg4, f32 arg5);

    // ?AddMenu2@MenuManager@@QAEHPAVUIMenu@@@Z
    ARTS_IMPORT i32 AddMenu2(UIMenu* arg1);

    // ?AddPointer@MenuManager@@QAEXXZ
    ARTS_EXPORT void AddPointer();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@MenuManager@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AdjustPopupCard@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_EXPORT void AdjustPopupCard(UIMenu* menu);

    // ?AllocateMenuSwitchAudio@MenuManager@@QAEXXZ
    ARTS_IMPORT void AllocateMenuSwitchAudio();

    // ?CheckBG@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_IMPORT void CheckBG(UIMenu* arg1);

    // ?CheckInput@MenuManager@@QAEXXZ
    ARTS_IMPORT void CheckInput();

    // ?ClearAllWidgets@MenuManager@@QAEXXZ
    ARTS_IMPORT void ClearAllWidgets();

    // ?CloseDialog@MenuManager@@QAEXXZ
    ARTS_IMPORT void CloseDialog();

    // ?CurrentMenuSelected@MenuManager@@QAEHXZ
    ARTS_EXPORT i32 CurrentMenuSelected();

    // ?DeclareLastDrawn@MenuManager@@QAEXPAVasNode@@@Z
    ARTS_IMPORT void DeclareLastDrawn(asNode* arg1);

    // ?Disable@MenuManager@@QAEXH@Z
    ARTS_EXPORT void Disable(i32 id);

    // ?DisableNavBar@MenuManager@@QAEXXZ
    ARTS_IMPORT void DisableNavBar();

    // ?DisablePU@MenuManager@@QAEXXZ
    ARTS_IMPORT void DisablePU();

    // ?Enable@MenuManager@@QAEXH@Z
    ARTS_EXPORT void Enable(i32 id);

    // ?EnableNavBar@MenuManager@@QAEXXZ
    ARTS_IMPORT void EnableNavBar();

    // ?EnablePU@MenuManager@@QAEXXZ
    ARTS_IMPORT void EnablePU();

    // ?FindMenu@MenuManager@@QAEHH@Z
    ARTS_IMPORT i32 FindMenu(i32 arg1);

    // ?Flush@MenuManager@@QAEXXZ
    ARTS_IMPORT void Flush();

    // ?ForceCurrentFocus@MenuManager@@QAEXXZ
    ARTS_EXPORT void ForceCurrentFocus();

    // ?GetControllerName@MenuManager@@QAEPADH@Z
    ARTS_IMPORT char* GetControllerName(i32 arg1);

    // ?GetCurrentMenu@MenuManager@@QAEPAVUIMenu@@XZ
    ARTS_EXPORT UIMenu* GetCurrentMenu();

    // ?GetFGColor@MenuManager@@QAEAAVVector4@@H@Z
    ARTS_IMPORT Vector4& GetFGColor(i32 arg1);

    // ?GetFont@MenuManager@@QAEPAXH@Z
    ARTS_IMPORT void* GetFont(i32 arg1);

    // ?GetPreviousMenu@MenuManager@@QAEHXZ
    ARTS_EXPORT i32 GetPreviousMenu();

    // ?GetScale@MenuManager@@QAEXAAM000@Z
    ARTS_EXPORT void GetScale(f32& x, f32& y, f32& width, f32& height);

    // ?Help@MenuManager@@QAEXXZ
    ARTS_IMPORT void Help();

    // ?Init@MenuManager@@QAEXHHPAD@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2, char* arg3);

    // ?Init@MenuManager@@QAEXPAVasCamera@@HHMMMM@Z
    ARTS_IMPORT void Init(asCamera* arg1, i32 arg2, i32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);

    // ?InitCommonStuff@MenuManager@@QAEXHH@Z
    ARTS_IMPORT void InitCommonStuff(i32 arg1, i32 arg2);

    // ?InitGlobalStrings@MenuManager@@QAEXXZ
    ARTS_IMPORT void InitGlobalStrings();

    // ?Kill@MenuManager@@QAEXXZ
    ARTS_EXPORT void Kill();

    // ?LoadRaceNames@MenuManager@@QAEXXZ
    ARTS_IMPORT void LoadRaceNames();

    // ?MenuState@MenuManager@@QAEHH@Z
    ARTS_EXPORT i32 MenuState(i32 menu);

    // ?MouseAction@MenuManager@@QAEPAVuiWidget@@HMM@Z
    ARTS_IMPORT uiWidget* MouseAction(i32 arg1, f32 arg2, f32 arg3);

    // ?NotifyMouseSelect@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_IMPORT void NotifyMouseSelect(UIMenu* arg1);

    // ?OpenDialog@MenuManager@@QAEXH@Z
    ARTS_IMPORT void OpenDialog(i32 arg1);

    // ?PlayRecordsSound@MenuManager@@QAEXXZ
    ARTS_IMPORT void PlayRecordsSound();

    // ?PlaySound@MenuManager@@QAEXH@Z
    ARTS_IMPORT void PlaySound(i32 arg1);

    // ?RegisterWidgetFocus@MenuManager@@QAEXHMMMMPAVuiWidget@@@Z
    ARTS_IMPORT void RegisterWidgetFocus(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, uiWidget* arg6);

    // ?ResChange@MenuManager@@UAEXHH@Z
    ARTS_IMPORT void ResChange(i32 arg1, i32 arg2) override;

    // ?ScanGlobalKeys@MenuManager@@QAEHH@Z
    ARTS_IMPORT i32 ScanGlobalKeys(i32 arg1);

    // ?SetBackgroundImage@MenuManager@@QAEXPAD@Z
    ARTS_IMPORT void SetBackgroundImage(char* arg1);

    // ?SetDefaultBackgroundImage@MenuManager@@QAEXPAD@Z
    ARTS_IMPORT void SetDefaultBackgroundImage(char* arg1);

    // ?SetFocus@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_EXPORT void SetFocus(UIMenu* menu);

    // ?SetPreviousMenu@MenuManager@@QAEXH@Z
    ARTS_IMPORT void SetPreviousMenu(i32 arg1);

    // ?Switch@MenuManager@@QAEHH@Z
    ARTS_EXPORT i32 Switch(i32 id);

    // ?SwitchFocus@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_IMPORT void SwitchFocus(UIMenu* arg1);

    // ?ToggleFocus@MenuManager@@QAEXH@Z
    ARTS_IMPORT void ToggleFocus(i32 arg1);

    // ?Update@MenuManager@@UAEXXZ
    ARTS_EXPORT void Update() override;

    // ?Instance@MenuManager@@2PAV1@A
    ARTS_IMPORT static MenuManager* Instance;

    eqEventQ* GetEventQ()
    {
        return event_q_.get();
    }

    bool Is3D() const
    {
        return is_3D_;
    }

    bool IsPopupOpen() const
    {
        return is_popup_open_;
    }

    bool GetFieldD0() const
    {
        return field_D0;
    }

private:
    // ?PlayMenuSwitchSound@MenuManager@@AAEXXZ
    ARTS_IMPORT void PlayMenuSwitchSound();

    void SwitchNow(i32 id);

    Ptr<eqEventQ> event_q_;
    Ptr<asCamera> menu_camera_;
    Ptr<asViewCS> menu_cs_;
    Ptr<asLamp[]> lamps_;
    Ptr<asLinearCS[]> lcss_;
    Ptr<uiNavBar> nav_bar_;
    i32 field_38;
    i32 has_active_widget_;
    b32 is_3D_;
    b32 is_popup_open_;
    uiWidget* focused_widget_;
    uiWidget* active_widget_;
    i32 field_50;
    Ptr<WArray> widget_array_;
    Ptr<MArray> menu_array_;
    string controller_names_;
    string string64;
    string string6C;
    string string74;
    string string7C;
    string string84;
    string string8C;
    string string94;
    string string9C;
    string stringA4;
    string stringAC;
    f32 start_x_;
    f32 start_y_;
    f32 scale_x_;
    f32 scale_y_;
    Ptr<sfPointer> pointer_;
    i32 field_C8;
    i32 field_CC;
    b32 field_D0;
    f32 field_D4;
    f32 field_D8;
    UIMenu* dialog_menu_;
    UIMenu* underlay_menu_;
    asNode* last_drawn_;
    Ptr<UIMenu*[]> menus_;
    UIMenu* active_menu_;
    Ptr<Card2D> popup_;
    Ptr<mmTextNode> debug_text_;
    i32 max_menus_;
    i32 num_menus_;
    i32 field_100;
    i32 next_active_menu_id_; // Slightly Repurposed
    void* font_size_12_;
    void* font_size_24_;
    void* font_size_16_;
    void* font_size_20_;
    void* font_size_32_;
    void* font_size_48_;
    void* font_size_64_;
    void* font_size_14_;
    i32 active_menu_id_;
    Ptr<AudSound> move_selector_sound_;
    Ptr<AudSound> selection_made_sound_;
    Ptr<AudSound> switch_sound_;
    Ptr<AudSound> ui_sounds_;
    char* default_background_;
};

check_size(MenuManager, 0x140);

inline MenuManager* MenuMgr()
{
    return MenuManager::Instance;
}

// ?DELAYTTIME@@3MA
ARTS_IMPORT extern f32 DELAYTTIME;
