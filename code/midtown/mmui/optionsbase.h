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

#include "mmwidget/menu.h"

class OptionsBase : public UIMenu
{
public:
    // ??0OptionsBase@@QAE@H@Z
    ARTS_IMPORT OptionsBase(i32 arg1);

    // ??_GOptionsBase@@UAEPAXI@Z
    // ??_EOptionsBase@@UAEPAXI@Z
    // ??1OptionsBase@@UAE@XZ
    ARTS_IMPORT ~OptionsBase() override;

    virtual void CancelAction() = 0;

    virtual void DoneAction() = 0;

    // ?ResetDefaultAction@OptionsBase@@UAEXXZ | inline
    ARTS_EXPORT virtual void ResetDefaultAction();

    // ?StoreCurrentSetup@OptionsBase@@UAEXXZ | inline
    ARTS_EXPORT virtual void StoreCurrentSetup();

    // ?IsAnOptionMenu@OptionsBase@@UAEHXZ | inline
    ARTS_IMPORT i32 IsAnOptionMenu() override;

    u8 gap90[0x6E38];
};

check_size(OptionsBase, 0x6EC8);
