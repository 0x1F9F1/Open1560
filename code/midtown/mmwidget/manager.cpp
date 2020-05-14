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

define_dummy_symbol(mmwidget_manager);

#include "manager.h"

MenuManager::MenuManager()
{
    unimplemented();
}

MenuManager::~MenuManager()
{
    unimplemented();
}

i32 MenuManager::ActionID(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0x4B14E0, this, arg1);
}

void MenuManager::AddBrackets(class UIIcon* arg1, class UIIcon* arg2, class uiWidget* arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, MenuManager*, class UIIcon*, class UIIcon*, class uiWidget*, f32, f32>>(
        0x4B1980, this, arg1, arg2, arg3, arg4, arg5);
}

i32 MenuManager::AddMenu2(class UIMenu* arg1)
{
    return stub<thiscall_t<i32, MenuManager*, class UIMenu*>>(0x4B1670, this, arg1);
}

void MenuManager::AddPointer()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4AFB50, this);
}

void MenuManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class Bank*>>(0x4B1400, this, arg1);
}

void MenuManager::AdjustPopupCard(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0x4B0A50, this, arg1);
}

void MenuManager::AllocateMenuSwitchAudio()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B17D0, this);
}

void MenuManager::CheckBG(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0x4B08E0, this, arg1);
}

void MenuManager::CheckInput()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B0E60, this);
}

void MenuManager::ClearAllWidgets()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4AF230, this);
}

void MenuManager::CloseDialog()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B0B60, this);
}

i32 MenuManager::CurrentMenuSelected()
{
    return stub<thiscall_t<i32, MenuManager*>>(0x4B1480, this);
}

void MenuManager::DeclareLastDrawn(class asNode* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class asNode*>>(0x4B0DC0, this, arg1);
}

void MenuManager::DeleteMenu(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0x4B16D0, this, arg1);
}

void MenuManager::Disable(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0x4B0C00, this, arg1);
}

void MenuManager::DisableNavBar()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B0C60, this);
}

void MenuManager::DisablePU()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B0AA0, this);
}

void MenuManager::Enable(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0x4B0B90, this, arg1);
}

void MenuManager::EnableNavBar()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B0C40, this);
}

void MenuManager::EnablePU()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B09D0, this);
}

i32 MenuManager::FindMenu(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0x4B1440, this, arg1);
}

void MenuManager::Flush()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B0E30, this);
}

void MenuManager::ForceCurrentFocus()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B1520, this);
}

char* MenuManager::GetControllerName(i32 arg1)
{
    return stub<thiscall_t<char*, MenuManager*, i32>>(0x4B05D0, this, arg1);
}

class UIMenu* MenuManager::GetCurrentMenu()
{
    return stub<thiscall_t<class UIMenu*, MenuManager*>>(0x4B1410, this);
}

class Vector4& MenuManager::GetFGColor(i32 arg1)
{
    return stub<thiscall_t<class Vector4&, MenuManager*, i32>>(0x4B0740, this, arg1);
}

void* MenuManager::GetFont(i32 arg1)
{
    return stub<thiscall_t<void*, MenuManager*, i32>>(0x4B0670, this, arg1);
}

i32 MenuManager::GetPreviousMenu()
{
    return stub<thiscall_t<i32, MenuManager*>>(0x4B1650, this);
}

void MenuManager::GetScale(f32& arg1, f32& arg2, f32& arg3, f32& arg4)
{
    return stub<thiscall_t<void, MenuManager*, f32&, f32&, f32&, f32&>>(0x4AF140, this, arg1, arg2, arg3, arg4);
}

void MenuManager::Help()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B1A60, this);
}

void MenuManager::Init(i32 arg1, i32 arg2, char* arg3)
{
    return stub<thiscall_t<void, MenuManager*, i32, i32, char*>>(0x4AF270, this, arg1, arg2, arg3);
}

void MenuManager::Init(class asCamera* arg1, i32 arg2, i32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7)
{
    return stub<thiscall_t<void, MenuManager*, class asCamera*, i32, i32, f32, f32, f32, f32>>(
        0x4AF600, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void MenuManager::InitCommonStuff(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, MenuManager*, i32, i32>>(0x4AF870, this, arg1, arg2);
}

void MenuManager::InitGlobalStrings()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4AFB60, this);
}

void MenuManager::Kill()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B0C70, this);
}

void MenuManager::LoadRaceNames()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B02D0, this);
}

i32 MenuManager::MenuState(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0x4B14A0, this, arg1);
}

class uiWidget* MenuManager::MouseAction(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<class uiWidget*, MenuManager*, i32, f32, f32>>(0x4AF1B0, this, arg1, arg2, arg3);
}

void MenuManager::NotifyMouseSelect(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0x4B13C0, this, arg1);
}

void MenuManager::OpenDialog(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0x4B0AE0, this, arg1);
}

void MenuManager::PlayRecordsSound()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B1950, this);
}

void MenuManager::PlaySound(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0x4B0D10, this, arg1);
}

void MenuManager::RegisterWidgetFocus(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, class uiWidget* arg6)
{
    return stub<thiscall_t<void, MenuManager*, i32, f32, f32, f32, f32, class uiWidget*>>(
        0x4B0F60, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void MenuManager::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, MenuManager*, i32, i32>>(0x4B0DD0, this, arg1, arg2);
}

i32 MenuManager::ScanGlobalKeys(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0x4B0FC0, this, arg1);
}

void MenuManager::SetBackgroundImage(char* arg1)
{
    return stub<thiscall_t<void, MenuManager*, char*>>(0x4B0960, this, arg1);
}

void MenuManager::SetDefaultBackgroundImage(char* arg1)
{
    return stub<thiscall_t<void, MenuManager*, char*>>(0x4B0900, this, arg1);
}

void MenuManager::SetFocus(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0x4B1550, this, arg1);
}

void MenuManager::SetPreviousMenu(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0x4B1620, this, arg1);
}

i32 MenuManager::Switch(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0x4B1560, this, arg1);
}

void MenuManager::SwitchFocus(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0x4B1370, this, arg1);
}

void MenuManager::ToggleFocus(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0x4B0EE0, this, arg1);
}

void MenuManager::TogglePU()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B09B0, this);
}

void MenuManager::Update()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B0E00, this);
}

void MenuManager::PlayMenuSwitchSound()
{
    return stub<thiscall_t<void, MenuManager*>>(0x4B1730, this);
}

static u32 __stdcall HelpWatcher(void* arg1)
{
    return stub<stdcall_t<u32, void*>>(0x4B1B30, arg1);
}
