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
    mmwidget:manager

    0x4AED60 | public: __thiscall MenuManager::MenuManager(void) | ??0MenuManager@@QAE@XZ
    0x4AEF20 | public: virtual __thiscall MenuManager::~MenuManager(void) | ??1MenuManager@@UAE@XZ
    0x4AF140 | public: void __thiscall MenuManager::GetScale(float &,float &,float &,float &) | ?GetScale@MenuManager@@QAEXAAM000@Z
    0x4AF1B0 | public: class uiWidget * __thiscall MenuManager::MouseAction(int,float,float) | ?MouseAction@MenuManager@@QAEPAVuiWidget@@HMM@Z
    0x4AF230 | public: void __thiscall MenuManager::ClearAllWidgets(void) | ?ClearAllWidgets@MenuManager@@QAEXXZ
    0x4AF270 | public: void __thiscall MenuManager::Init(int,int,char *) | ?Init@MenuManager@@QAEXHHPAD@Z
    0x4AF600 | public: void __thiscall MenuManager::Init(class asCamera *,int,int,float,float,float,float) | ?Init@MenuManager@@QAEXPAVasCamera@@HHMMMM@Z
    0x4AF870 | public: void __thiscall MenuManager::InitCommonStuff(int,int) | ?InitCommonStuff@MenuManager@@QAEXHH@Z
    0x4AFB50 | public: void __thiscall MenuManager::AddPointer(void) | ?AddPointer@MenuManager@@QAEXXZ
    0x4AFB60 | public: void __thiscall MenuManager::InitGlobalStrings(void) | ?InitGlobalStrings@MenuManager@@QAEXXZ
    0x4B02D0 | public: void __thiscall MenuManager::LoadRaceNames(void) | ?LoadRaceNames@MenuManager@@QAEXXZ
    0x4B05D0 | public: char * __thiscall MenuManager::GetControllerName(int) | ?GetControllerName@MenuManager@@QAEPADH@Z
    0x4B0670 | public: void * __thiscall MenuManager::GetFont(int) | ?GetFont@MenuManager@@QAEPAXH@Z
    0x4B0740 | public: class Vector4 & __thiscall MenuManager::GetFGColor(int) | ?GetFGColor@MenuManager@@QAEAAVVector4@@H@Z
    0x4B08E0 | public: void __thiscall MenuManager::CheckBG(class UIMenu *) | ?CheckBG@MenuManager@@QAEXPAVUIMenu@@@Z
    0x4B0900 | public: void __thiscall MenuManager::SetDefaultBackgroundImage(char *) | ?SetDefaultBackgroundImage@MenuManager@@QAEXPAD@Z
    0x4B0960 | public: void __thiscall MenuManager::SetBackgroundImage(char *) | ?SetBackgroundImage@MenuManager@@QAEXPAD@Z
    0x4B09B0 | public: void __thiscall MenuManager::TogglePU(void) | ?TogglePU@MenuManager@@QAEXXZ
    0x4B09D0 | public: void __thiscall MenuManager::EnablePU(void) | ?EnablePU@MenuManager@@QAEXXZ
    0x4B0A50 | public: void __thiscall MenuManager::AdjustPopupCard(class UIMenu *) | ?AdjustPopupCard@MenuManager@@QAEXPAVUIMenu@@@Z
    0x4B0AA0 | public: void __thiscall MenuManager::DisablePU(void) | ?DisablePU@MenuManager@@QAEXXZ
    0x4B0AE0 | public: void __thiscall MenuManager::OpenDialog(int) | ?OpenDialog@MenuManager@@QAEXH@Z
    0x4B0B60 | public: void __thiscall MenuManager::CloseDialog(void) | ?CloseDialog@MenuManager@@QAEXXZ
    0x4B0B90 | public: void __thiscall MenuManager::Enable(int) | ?Enable@MenuManager@@QAEXH@Z
    0x4B0C00 | public: void __thiscall MenuManager::Disable(int) | ?Disable@MenuManager@@QAEXH@Z
    0x4B0C40 | public: void __thiscall MenuManager::EnableNavBar(void) | ?EnableNavBar@MenuManager@@QAEXXZ
    0x4B0C60 | public: void __thiscall MenuManager::DisableNavBar(void) | ?DisableNavBar@MenuManager@@QAEXXZ
    0x4B0C70 | public: void __thiscall MenuManager::Kill(void) | ?Kill@MenuManager@@QAEXXZ
    0x4B0D10 | public: void __thiscall MenuManager::PlaySound(int) | ?PlaySound@MenuManager@@QAEXH@Z
    0x4B0DC0 | public: void __thiscall MenuManager::DeclareLastDrawn(class asNode *) | ?DeclareLastDrawn@MenuManager@@QAEXPAVasNode@@@Z
    0x4B0DD0 | public: virtual void __thiscall MenuManager::ResChange(int,int) | ?ResChange@MenuManager@@UAEXHH@Z
    0x4B0E00 | public: virtual void __thiscall MenuManager::Update(void) | ?Update@MenuManager@@UAEXXZ
    0x4B0E30 | public: void __thiscall MenuManager::Flush(void) | ?Flush@MenuManager@@QAEXXZ
    0x4B0E60 | public: void __thiscall MenuManager::CheckInput(void) | ?CheckInput@MenuManager@@QAEXXZ
    0x4B0EE0 | public: void __thiscall MenuManager::ToggleFocus(int) | ?ToggleFocus@MenuManager@@QAEXH@Z
    0x4B0F60 | public: void __thiscall MenuManager::RegisterWidgetFocus(int,float,float,float,float,class uiWidget *) | ?RegisterWidgetFocus@MenuManager@@QAEXHMMMMPAVuiWidget@@@Z
    0x4B0FC0 | public: int __thiscall MenuManager::ScanGlobalKeys(int) | ?ScanGlobalKeys@MenuManager@@QAEHH@Z
    0x4B1370 | public: void __thiscall MenuManager::SwitchFocus(class UIMenu *) | ?SwitchFocus@MenuManager@@QAEXPAVUIMenu@@@Z
    0x4B13C0 | public: void __thiscall MenuManager::NotifyMouseSelect(class UIMenu *) | ?NotifyMouseSelect@MenuManager@@QAEXPAVUIMenu@@@Z
    0x4B1400 | public: virtual void __thiscall MenuManager::AddWidgets(class Bank *) | ?AddWidgets@MenuManager@@UAEXPAVBank@@@Z
    0x4B1410 | public: class UIMenu * __thiscall MenuManager::GetCurrentMenu(void) | ?GetCurrentMenu@MenuManager@@QAEPAVUIMenu@@XZ
    0x4B1440 | public: int __thiscall MenuManager::FindMenu(int) | ?FindMenu@MenuManager@@QAEHH@Z
    0x4B1480 | public: int __thiscall MenuManager::CurrentMenuSelected(void) | ?CurrentMenuSelected@MenuManager@@QAEHXZ
    0x4B14A0 | public: int __thiscall MenuManager::MenuState(int) | ?MenuState@MenuManager@@QAEHH@Z
    0x4B14E0 | public: int __thiscall MenuManager::ActionID(int) | ?ActionID@MenuManager@@QAEHH@Z
    0x4B1520 | public: void __thiscall MenuManager::ForceCurrentFocus(void) | ?ForceCurrentFocus@MenuManager@@QAEXXZ
    0x4B1550 | public: void __thiscall MenuManager::SetFocus(class UIMenu *) | ?SetFocus@MenuManager@@QAEXPAVUIMenu@@@Z
    0x4B1560 | public: int __thiscall MenuManager::Switch(int) | ?Switch@MenuManager@@QAEHH@Z
    0x4B1620 | public: void __thiscall MenuManager::SetPreviousMenu(int) | ?SetPreviousMenu@MenuManager@@QAEXH@Z
    0x4B1650 | public: int __thiscall MenuManager::GetPreviousMenu(void) | ?GetPreviousMenu@MenuManager@@QAEHXZ
    0x4B1670 | public: int __thiscall MenuManager::AddMenu2(class UIMenu *) | ?AddMenu2@MenuManager@@QAEHPAVUIMenu@@@Z
    0x4B16D0 | public: void __thiscall MenuManager::DeleteMenu(class UIMenu *) | ?DeleteMenu@MenuManager@@QAEXPAVUIMenu@@@Z
    0x4B1730 | private: void __thiscall MenuManager::PlayMenuSwitchSound(void) | ?PlayMenuSwitchSound@MenuManager@@AAEXXZ
    0x4B17D0 | public: void __thiscall MenuManager::AllocateMenuSwitchAudio(void) | ?AllocateMenuSwitchAudio@MenuManager@@QAEXXZ
    0x4B1950 | public: void __thiscall MenuManager::PlayRecordsSound(void) | ?PlayRecordsSound@MenuManager@@QAEXXZ
    0x4B1980 | public: void __thiscall MenuManager::AddBrackets(class UIIcon *,class UIIcon *,class uiWidget *,float,float) | ?AddBrackets@MenuManager@@QAEXPAVUIIcon@@0PAVuiWidget@@MM@Z
    0x4B1A60 | public: void __thiscall MenuManager::Help(void) | ?Help@MenuManager@@QAEXXZ
    0x4B1B30 | unsigned long __stdcall HelpWatcher(void *) | ?HelpWatcher@@YGKPAX@Z
    0x4B1C10 | public: virtual void * __thiscall MenuManager::`scalar deleting destructor'(unsigned int) | ??_GMenuManager@@UAEPAXI@Z
    0x4B1C10 | public: virtual void * __thiscall MenuManager::`vector deleting destructor'(unsigned int) | ??_EMenuManager@@UAEPAXI@Z
    0x4B1C40 | public: virtual void * __thiscall asLamp::`vector deleting destructor'(unsigned int) | ??_EasLamp@@UAEPAXI@Z
    0x4B1CA0 | public: virtual void * __thiscall asLinearCS::`vector deleting destructor'(unsigned int) | ??_EasLinearCS@@UAEPAXI@Z
    0x61E338 | const MenuManager::`vftable' | ??_7MenuManager@@6B@
    0x6418B4 | float DELAYTTIME | ?DELAYTTIME@@3MA
    0x705960 | public: static class MenuManager * MenuManager::Instance | ?Instance@MenuManager@@2PAV1@A
*/

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

    // ?ActionID@MenuManager@@QAEHH@Z | unused
    ARTS_IMPORT i32 ActionID(i32 arg1);

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
    ARTS_IMPORT void AdjustPopupCard(UIMenu* arg1);

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

    // ?DeleteMenu@MenuManager@@QAEXPAVUIMenu@@@Z | unused
    ARTS_IMPORT void DeleteMenu(UIMenu* arg1);

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

    // ?TogglePU@MenuManager@@QAEXXZ | unused
    ARTS_IMPORT void TogglePU();

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
    b32 is_popup_;
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

inline MenuManager* Menus()
{
    return MenuManager::Instance;
}

// ?DELAYTTIME@@3MA
ARTS_IMPORT extern f32 DELAYTTIME;
