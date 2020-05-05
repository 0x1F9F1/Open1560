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
    unimplemented(arg1);
}

i32 MenuManager::ActionID(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0xB14E0_Offset, this, arg1);
}

void MenuManager::AddBrackets(class UIIcon* arg1, class UIIcon* arg2, class uiWidget* arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, MenuManager*, class UIIcon*, class UIIcon*, class uiWidget*, f32, f32>>(
        0xB1980_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

i32 MenuManager::AddMenu2(class UIMenu* arg1)
{
    return stub<thiscall_t<i32, MenuManager*, class UIMenu*>>(0xB1670_Offset, this, arg1);
}

void MenuManager::AddPointer()
{
    return stub<thiscall_t<void, MenuManager*>>(0xAFB50_Offset, this);
}

void MenuManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class Bank*>>(0xB1400_Offset, this, arg1);
}

void MenuManager::AdjustPopupCard(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0xB0A50_Offset, this, arg1);
}

void MenuManager::AllocateMenuSwitchAudio()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB17D0_Offset, this);
}

void MenuManager::CheckBG(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0xB08E0_Offset, this, arg1);
}

void MenuManager::CheckInput()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB0E60_Offset, this);
}

void MenuManager::ClearAllWidgets()
{
    return stub<thiscall_t<void, MenuManager*>>(0xAF230_Offset, this);
}

void MenuManager::CloseDialog()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB0B60_Offset, this);
}

i32 MenuManager::CurrentMenuSelected()
{
    return stub<thiscall_t<i32, MenuManager*>>(0xB1480_Offset, this);
}

void MenuManager::DeclareLastDrawn(class asNode* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class asNode*>>(0xB0DC0_Offset, this, arg1);
}

void MenuManager::DeleteMenu(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0xB16D0_Offset, this, arg1);
}

void MenuManager::Disable(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0xB0C00_Offset, this, arg1);
}

void MenuManager::DisableNavBar()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB0C60_Offset, this);
}

void MenuManager::DisablePU()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB0AA0_Offset, this);
}

void MenuManager::Enable(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0xB0B90_Offset, this, arg1);
}

void MenuManager::EnableNavBar()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB0C40_Offset, this);
}

void MenuManager::EnablePU()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB09D0_Offset, this);
}

i32 MenuManager::FindMenu(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0xB1440_Offset, this, arg1);
}

void MenuManager::Flush()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB0E30_Offset, this);
}

void MenuManager::ForceCurrentFocus()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB1520_Offset, this);
}

char* MenuManager::GetControllerName(i32 arg1)
{
    return stub<thiscall_t<char*, MenuManager*, i32>>(0xB05D0_Offset, this, arg1);
}

class UIMenu* MenuManager::GetCurrentMenu()
{
    return stub<thiscall_t<class UIMenu*, MenuManager*>>(0xB1410_Offset, this);
}

class Vector4& MenuManager::GetFGColor(i32 arg1)
{
    return stub<thiscall_t<class Vector4&, MenuManager*, i32>>(0xB0740_Offset, this, arg1);
}

void* MenuManager::GetFont(i32 arg1)
{
    return stub<thiscall_t<void*, MenuManager*, i32>>(0xB0670_Offset, this, arg1);
}

i32 MenuManager::GetPreviousMenu()
{
    return stub<thiscall_t<i32, MenuManager*>>(0xB1650_Offset, this);
}

void MenuManager::GetScale(f32& arg1, f32& arg2, f32& arg3, f32& arg4)
{
    return stub<thiscall_t<void, MenuManager*, f32&, f32&, f32&, f32&>>(0xAF140_Offset, this, arg1, arg2, arg3, arg4);
}

void MenuManager::Help()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB1A60_Offset, this);
}

void MenuManager::Init(i32 arg1, i32 arg2, char* arg3)
{
    return stub<thiscall_t<void, MenuManager*, i32, i32, char*>>(0xAF270_Offset, this, arg1, arg2, arg3);
}

void MenuManager::Init(class asCamera* arg1, i32 arg2, i32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7)
{
    return stub<thiscall_t<void, MenuManager*, class asCamera*, i32, i32, f32, f32, f32, f32>>(
        0xAF600_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void MenuManager::InitCommonStuff(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, MenuManager*, i32, i32>>(0xAF870_Offset, this, arg1, arg2);
}

void MenuManager::InitGlobalStrings()
{
    return stub<thiscall_t<void, MenuManager*>>(0xAFB60_Offset, this);
}

void MenuManager::Kill()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB0C70_Offset, this);
}

void MenuManager::LoadRaceNames()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB02D0_Offset, this);
}

i32 MenuManager::MenuState(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0xB14A0_Offset, this, arg1);
}

class uiWidget* MenuManager::MouseAction(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<class uiWidget*, MenuManager*, i32, f32, f32>>(0xAF1B0_Offset, this, arg1, arg2, arg3);
}

void MenuManager::NotifyMouseSelect(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0xB13C0_Offset, this, arg1);
}

void MenuManager::OpenDialog(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0xB0AE0_Offset, this, arg1);
}

void MenuManager::PlayRecordsSound()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB1950_Offset, this);
}

void MenuManager::PlaySound(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0xB0D10_Offset, this, arg1);
}

void MenuManager::RegisterWidgetFocus(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, class uiWidget* arg6)
{
    return stub<thiscall_t<void, MenuManager*, i32, f32, f32, f32, f32, class uiWidget*>>(
        0xB0F60_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void MenuManager::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, MenuManager*, i32, i32>>(0xB0DD0_Offset, this, arg1, arg2);
}

i32 MenuManager::ScanGlobalKeys(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0xB0FC0_Offset, this, arg1);
}

void MenuManager::SetBackgroundImage(char* arg1)
{
    return stub<thiscall_t<void, MenuManager*, char*>>(0xB0960_Offset, this, arg1);
}

void MenuManager::SetDefaultBackgroundImage(char* arg1)
{
    return stub<thiscall_t<void, MenuManager*, char*>>(0xB0900_Offset, this, arg1);
}

void MenuManager::SetFocus(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0xB1550_Offset, this, arg1);
}

void MenuManager::SetPreviousMenu(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0xB1620_Offset, this, arg1);
}

i32 MenuManager::Switch(i32 arg1)
{
    return stub<thiscall_t<i32, MenuManager*, i32>>(0xB1560_Offset, this, arg1);
}

void MenuManager::SwitchFocus(class UIMenu* arg1)
{
    return stub<thiscall_t<void, MenuManager*, class UIMenu*>>(0xB1370_Offset, this, arg1);
}

void MenuManager::ToggleFocus(i32 arg1)
{
    return stub<thiscall_t<void, MenuManager*, i32>>(0xB0EE0_Offset, this, arg1);
}

void MenuManager::TogglePU()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB09B0_Offset, this);
}

void MenuManager::Update()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB0E00_Offset, this);
}

void MenuManager::PlayMenuSwitchSound()
{
    return stub<thiscall_t<void, MenuManager*>>(0xB1730_Offset, this);
}
