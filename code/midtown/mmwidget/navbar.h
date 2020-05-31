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
    mmwidget:navbar

    0x4B1D00 | public: __thiscall uiNavBar::uiNavBar(int) | ??0uiNavBar@@QAE@H@Z
    0x4B1F10 | public: void __thiscall uiNavBar::Help(void) | ?Help@uiNavBar@@QAEXXZ
    0x4B1F20 | public: void __thiscall uiNavBar::Minimize(void) | ?Minimize@uiNavBar@@QAEXXZ
    0x4B1F70 | public: virtual __thiscall uiNavBar::~uiNavBar(void) | ??1uiNavBar@@UAE@XZ
    0x4B1F80 | public: void __thiscall uiNavBar::ResetState(void) | ?ResetState@uiNavBar@@QAEXXZ
    0x4B1F90 | public: void __thiscall uiNavBar::OptionActive(void) | ?OptionActive@uiNavBar@@QAEXXZ
    0x4B1FB0 | public: void __thiscall uiNavBar::OptionInActive(void) | ?OptionInActive@uiNavBar@@QAEXXZ
    0x4B1FD0 | public: virtual void __thiscall uiNavBar::Update(void) | ?Update@uiNavBar@@UAEXXZ
    0x4B2070 | public: void __thiscall uiNavBar::SetPrevPos(float,float) | ?SetPrevPos@uiNavBar@@QAEXMM@Z
    0x4B20C0 | public: void __thiscall uiNavBar::TurnOnPrev(void) | ?TurnOnPrev@uiNavBar@@QAEXXZ
    0x4B20E0 | public: void __thiscall uiNavBar::TurnOffPrev(void) | ?TurnOffPrev@uiNavBar@@QAEXXZ
    0x4B2100 | public: void __thiscall uiNavBar::SetPrevBitmap(char *) | ?SetPrevBitmap@uiNavBar@@QAEXPAD@Z
    0x4B2120 | public: virtual void * __thiscall uiNavBar::`scalar deleting destructor'(unsigned int) | ??_GuiNavBar@@UAEPAXI@Z
    0x4B2120 | public: virtual void * __thiscall uiNavBar::`vector deleting destructor'(unsigned int) | ??_EuiNavBar@@UAEPAXI@Z
    0x4B2150 | public: virtual void __thiscall uiNavBar::BackUp(void) | ?BackUp@uiNavBar@@UAEXXZ
    0x61E3B8 | const uiNavBar::`vftable' | ??_7uiNavBar@@6B@
*/

#include "menu.h"

class uiNavBar : public UIMenu
{
    // const uiNavBar::`vftable' @ 0x61E3B8

public:
    // 0x4B1D00 | ??0uiNavBar@@QAE@H@Z
    uiNavBar(i32 arg1);

    // 0x4B2120 | ??_EuiNavBar@@UAEPAXI@Z
    // 0x4B1F70 | ??1uiNavBar@@UAE@XZ
    ~uiNavBar() override;

    // 0x4B2150 | ?BackUp@uiNavBar@@UAEXXZ | inline
    void BackUp() override;

    // 0x4B1F10 | ?Help@uiNavBar@@QAEXXZ
    void Help();

    // 0x4B1F20 | ?Minimize@uiNavBar@@QAEXXZ
    void Minimize();

    // 0x4B1F90 | ?OptionActive@uiNavBar@@QAEXXZ
    void OptionActive();

    // 0x4B1FB0 | ?OptionInActive@uiNavBar@@QAEXXZ
    void OptionInActive();

    // 0x4B1F80 | ?ResetState@uiNavBar@@QAEXXZ | unused
    void ResetState();

    // 0x4B2100 | ?SetPrevBitmap@uiNavBar@@QAEXPAD@Z | unused
    void SetPrevBitmap(char* arg1);

    // 0x4B2070 | ?SetPrevPos@uiNavBar@@QAEXMM@Z
    void SetPrevPos(f32 arg1, f32 arg2);

    // 0x4B20E0 | ?TurnOffPrev@uiNavBar@@QAEXXZ
    void TurnOffPrev();

    // 0x4B20C0 | ?TurnOnPrev@uiNavBar@@QAEXXZ
    void TurnOnPrev();

    // 0x4B1FD0 | ?Update@uiNavBar@@UAEXXZ
    void Update() override;
};

check_size(uiNavBar, 0xC0);
