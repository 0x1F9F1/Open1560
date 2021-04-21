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

class eqEventQ;
class asCamera;
class asViewCS;
class asLamp;
class asLinearCS;
class uiNavBar;
class WArray;
class MArray;
class sfPointer;
class Card2D;
class UIMenu;
class mmTextNode;
class AudSound;

class MenuManager final : public asNode
{
    // const MenuManager::`vftable' @ 0x61E338

public:
    // 0x4AED60 | ??0MenuManager@@QAE@XZ
    ARTS_IMPORT MenuManager();

    // 0x4B1C10 | ??_EMenuManager@@UAEPAXI@Z
    // 0x4B1C10 | ??_GMenuManager@@UAEPAXI@Z
    // 0x4AEF20 | ??1MenuManager@@UAE@XZ
    ARTS_IMPORT ~MenuManager() override;

    // 0x4B14E0 | ?ActionID@MenuManager@@QAEHH@Z | unused
    ARTS_IMPORT i32 ActionID(i32 arg1);

    // 0x4B1980 | ?AddBrackets@MenuManager@@QAEXPAVUIIcon@@0PAVuiWidget@@MM@Z
    ARTS_IMPORT void AddBrackets(class UIIcon* arg1, class UIIcon* arg2, class uiWidget* arg3, f32 arg4, f32 arg5);

    // 0x4B1670 | ?AddMenu2@MenuManager@@QAEHPAVUIMenu@@@Z
    ARTS_IMPORT i32 AddMenu2(class UIMenu* arg1);

    // 0x4AFB50 | ?AddPointer@MenuManager@@QAEXXZ
    ARTS_EXPORT void AddPointer();

    // 0x4B1400 | ?AddWidgets@MenuManager@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(class Bank* arg1) override;

    // 0x4B0A50 | ?AdjustPopupCard@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_IMPORT void AdjustPopupCard(class UIMenu* arg1);

    // 0x4B17D0 | ?AllocateMenuSwitchAudio@MenuManager@@QAEXXZ
    ARTS_IMPORT void AllocateMenuSwitchAudio();

    // 0x4B08E0 | ?CheckBG@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_IMPORT void CheckBG(class UIMenu* arg1);

    // 0x4B0E60 | ?CheckInput@MenuManager@@QAEXXZ
    ARTS_IMPORT void CheckInput();

    // 0x4AF230 | ?ClearAllWidgets@MenuManager@@QAEXXZ
    ARTS_IMPORT void ClearAllWidgets();

    // 0x4B0B60 | ?CloseDialog@MenuManager@@QAEXXZ
    ARTS_IMPORT void CloseDialog();

    // 0x4B1480 | ?CurrentMenuSelected@MenuManager@@QAEHXZ
    ARTS_EXPORT i32 CurrentMenuSelected();

    // 0x4B0DC0 | ?DeclareLastDrawn@MenuManager@@QAEXPAVasNode@@@Z
    ARTS_IMPORT void DeclareLastDrawn(class asNode* arg1);

    // 0x4B16D0 | ?DeleteMenu@MenuManager@@QAEXPAVUIMenu@@@Z | unused
    ARTS_IMPORT void DeleteMenu(class UIMenu* arg1);

    // 0x4B0C00 | ?Disable@MenuManager@@QAEXH@Z
    ARTS_EXPORT void Disable(i32 id);

    // 0x4B0C60 | ?DisableNavBar@MenuManager@@QAEXXZ
    ARTS_IMPORT void DisableNavBar();

    // 0x4B0AA0 | ?DisablePU@MenuManager@@QAEXXZ
    ARTS_IMPORT void DisablePU();

    // 0x4B0B90 | ?Enable@MenuManager@@QAEXH@Z
    ARTS_EXPORT void Enable(i32 id);

    // 0x4B0C40 | ?EnableNavBar@MenuManager@@QAEXXZ
    ARTS_IMPORT void EnableNavBar();

    // 0x4B09D0 | ?EnablePU@MenuManager@@QAEXXZ
    ARTS_IMPORT void EnablePU();

    // 0x4B1440 | ?FindMenu@MenuManager@@QAEHH@Z
    ARTS_IMPORT i32 FindMenu(i32 arg1);

    // 0x4B0E30 | ?Flush@MenuManager@@QAEXXZ
    ARTS_IMPORT void Flush();

    // 0x4B1520 | ?ForceCurrentFocus@MenuManager@@QAEXXZ
    ARTS_EXPORT void ForceCurrentFocus();

    // 0x4B05D0 | ?GetControllerName@MenuManager@@QAEPADH@Z
    ARTS_IMPORT char* GetControllerName(i32 arg1);

    // 0x4B1410 | ?GetCurrentMenu@MenuManager@@QAEPAVUIMenu@@XZ
    ARTS_EXPORT class UIMenu* GetCurrentMenu();

    // 0x4B0740 | ?GetFGColor@MenuManager@@QAEAAVVector4@@H@Z
    ARTS_IMPORT class Vector4& GetFGColor(i32 arg1);

    // 0x4B0670 | ?GetFont@MenuManager@@QAEPAXH@Z
    ARTS_IMPORT void* GetFont(i32 arg1);

    // 0x4B1650 | ?GetPreviousMenu@MenuManager@@QAEHXZ
    ARTS_EXPORT i32 GetPreviousMenu();

    // 0x4AF140 | ?GetScale@MenuManager@@QAEXAAM000@Z
    ARTS_EXPORT void GetScale(f32& x, f32& y, f32& width, f32& height);

    // 0x4B1A60 | ?Help@MenuManager@@QAEXXZ
    ARTS_IMPORT void Help();

    // 0x4AF270 | ?Init@MenuManager@@QAEXHHPAD@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2, char* arg3);

    // 0x4AF600 | ?Init@MenuManager@@QAEXPAVasCamera@@HHMMMM@Z
    ARTS_IMPORT void Init(class asCamera* arg1, i32 arg2, i32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);

    // 0x4AF870 | ?InitCommonStuff@MenuManager@@QAEXHH@Z
    ARTS_IMPORT void InitCommonStuff(i32 arg1, i32 arg2);

    // 0x4AFB60 | ?InitGlobalStrings@MenuManager@@QAEXXZ
    ARTS_IMPORT void InitGlobalStrings();

    // 0x4B0C70 | ?Kill@MenuManager@@QAEXXZ
    ARTS_IMPORT void Kill();

    // 0x4B02D0 | ?LoadRaceNames@MenuManager@@QAEXXZ
    ARTS_IMPORT void LoadRaceNames();

    // 0x4B14A0 | ?MenuState@MenuManager@@QAEHH@Z
    ARTS_EXPORT i32 MenuState(i32 menu);

    // 0x4AF1B0 | ?MouseAction@MenuManager@@QAEPAVuiWidget@@HMM@Z
    ARTS_IMPORT class uiWidget* MouseAction(i32 arg1, f32 arg2, f32 arg3);

    // 0x4B13C0 | ?NotifyMouseSelect@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_IMPORT void NotifyMouseSelect(class UIMenu* arg1);

    // 0x4B0AE0 | ?OpenDialog@MenuManager@@QAEXH@Z
    ARTS_IMPORT void OpenDialog(i32 arg1);

    // 0x4B1950 | ?PlayRecordsSound@MenuManager@@QAEXXZ
    ARTS_IMPORT void PlayRecordsSound();

    // 0x4B0D10 | ?PlaySound@MenuManager@@QAEXH@Z
    ARTS_IMPORT void PlaySound(i32 arg1);

    // 0x4B0F60 | ?RegisterWidgetFocus@MenuManager@@QAEXHMMMMPAVuiWidget@@@Z
    ARTS_IMPORT void RegisterWidgetFocus(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, class uiWidget* arg6);

    // 0x4B0DD0 | ?ResChange@MenuManager@@UAEXHH@Z
    ARTS_IMPORT void ResChange(i32 arg1, i32 arg2) override;

    // 0x4B0FC0 | ?ScanGlobalKeys@MenuManager@@QAEHH@Z
    ARTS_IMPORT i32 ScanGlobalKeys(i32 arg1);

    // 0x4B0960 | ?SetBackgroundImage@MenuManager@@QAEXPAD@Z
    ARTS_IMPORT void SetBackgroundImage(char* arg1);

    // 0x4B0900 | ?SetDefaultBackgroundImage@MenuManager@@QAEXPAD@Z
    ARTS_IMPORT void SetDefaultBackgroundImage(char* arg1);

    // 0x4B1550 | ?SetFocus@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_EXPORT void SetFocus(class UIMenu* menu);

    // 0x4B1620 | ?SetPreviousMenu@MenuManager@@QAEXH@Z
    ARTS_IMPORT void SetPreviousMenu(i32 arg1);

    // 0x4B1560 | ?Switch@MenuManager@@QAEHH@Z
    ARTS_EXPORT i32 Switch(i32 id);

    // 0x4B1370 | ?SwitchFocus@MenuManager@@QAEXPAVUIMenu@@@Z
    ARTS_IMPORT void SwitchFocus(class UIMenu* arg1);

    // 0x4B0EE0 | ?ToggleFocus@MenuManager@@QAEXH@Z
    ARTS_IMPORT void ToggleFocus(i32 arg1);

    // 0x4B09B0 | ?TogglePU@MenuManager@@QAEXXZ | unused
    ARTS_IMPORT void TogglePU();

    // 0x4B0E00 | ?Update@MenuManager@@UAEXXZ
    ARTS_EXPORT void Update() override;

    // 0x705960 | ?Instance@MenuManager@@2PAV1@A
    ARTS_IMPORT static class MenuManager* Instance;

    eqEventQ* GetEventQ()
    {
        return event_q_;
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
    // 0x4B1730 | ?PlayMenuSwitchSound@MenuManager@@AAEXXZ
    ARTS_IMPORT void PlayMenuSwitchSound();

    void SwitchNow(i32 id);

    eqEventQ* event_q_;
    asCamera* menu_camera_;
    asViewCS* menu_cs_;
    asLamp* lamps_;
    asLinearCS* lcss_;
    uiNavBar* nav_bar_;
    i32 field_38;
    i32 has_active_widget_;
    b32 is_3D_;
    b32 is_popup_;
    uiWidget* focused_widget_;
    uiWidget* active_widget_;
    i32 field_50;
    WArray* widget_array_;
    MArray* menu_array_;
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
    sfPointer* pointer_;
    i32 field_C8;
    i32 field_CC;
    b32 field_D0;
    f32 field_D4;
    f32 field_D8;
    UIMenu* dialog_menu_;
    UIMenu* underlay_menu_;
    asNode* last_drawn_;
    UIMenu** menus_;
    UIMenu* active_menu_;
    Card2D* popup_;
    mmTextNode* dwordF4;
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
    AudSound* move_selector_sound_;
    AudSound* selection_made_sound_;
    AudSound* switch_sound_;
    AudSound* ui_sounds_;
    char* default_background_;
};

check_size(MenuManager, 0x140);

// 0x6418B4 | ?DELAYTTIME@@3MA
ARTS_IMPORT extern f32 DELAYTTIME;
