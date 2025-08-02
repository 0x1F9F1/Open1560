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

#include "arts7/linear.h"

class mmWheel;

class mmShock final : public asLinearCS
{
public:
    // ??0mmShock@@QAE@XZ
    ARTS_IMPORT mmShock();

    // ??_EmmShock@@UAEPAXI@Z
    // ??1mmShock@@UAE@XZ | inline
    ARTS_EXPORT ~mmShock() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmShock@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@mmShock@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Update@mmShock@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmShock@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x10];
};

check_size(mmShock, 0x98);
