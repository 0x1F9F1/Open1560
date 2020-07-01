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
    mmui:optionsbase

    0x4AB4C0 | public: __thiscall OptionsBase::OptionsBase(int) | ??0OptionsBase@@QAE@H@Z
    0x4AB620 | public: void __thiscall OptionsBase::CreateTitle(struct LocString *) | ?CreateTitle@OptionsBase@@QAEXPAULocString@@@Z
    0x4AB650 | public: virtual __thiscall OptionsBase::~OptionsBase(void) | ??1OptionsBase@@UAE@XZ
    0x4AB6A0 | public: virtual void * __thiscall OptionsBase::`vector deleting destructor'(unsigned int) | ??_EOptionsBase@@UAEPAXI@Z
    0x4AB6A0 | public: virtual void * __thiscall OptionsBase::`scalar deleting destructor'(unsigned int) | ??_GOptionsBase@@UAEPAXI@Z
    0x4AB6F0 | public: virtual void __thiscall OptionsBase::ResetDefaultAction(void) | ?ResetDefaultAction@OptionsBase@@UAEXXZ
    0x61E250 | const OptionsBase::`vftable' | ??_7OptionsBase@@6B@
*/

#include "mmwidget/menu.h"

class OptionsBase : public UIMenu
{
    // const OptionsBase::`vftable' @ 0x61E250

public:
    // 0x4AB4C0 | ??0OptionsBase@@QAE@H@Z
    ARTS_IMPORT OptionsBase(i32 arg1);

    // 0x4AB6A0 | ??_GOptionsBase@@UAEPAXI@Z
    // 0x4AB6A0 | ??_EOptionsBase@@UAEPAXI@Z
    // 0x4AB650 | ??1OptionsBase@@UAE@XZ
    ARTS_IMPORT ~OptionsBase() override;

    virtual void CancelAction() = 0;

    virtual void DoneAction() = 0;

    // 0x4AB6F0 | ?ResetDefaultAction@OptionsBase@@UAEXXZ | inline
    ARTS_EXPORT virtual void ResetDefaultAction();

    // 0x49A6D0 | ?StoreCurrentSetup@OptionsBase@@UAEXXZ | inline
    ARTS_EXPORT virtual void StoreCurrentSetup();

    // 0x4AB620 | ?CreateTitle@OptionsBase@@QAEXPAULocString@@@Z | unused
    ARTS_IMPORT void CreateTitle(struct LocString* arg1);

    // 0x49A6E0 | ?IsAnOptionMenu@OptionsBase@@UAEHXZ | inline
    ARTS_IMPORT i32 IsAnOptionMenu() override;

    u8 gap90[0x6E38];
};

check_size(OptionsBase, 0x6EC8);
