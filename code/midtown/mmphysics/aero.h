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

class asAero final : public asNode
{
public:
    // ??0asAero@@QAE@XZ
    ARTS_IMPORT asAero();

    // ??_EasAero@@UAEPAXI@Z
    // ??1asAero@@UAE@XZ | inline
    ARTS_EXPORT ~asAero() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asAero@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@asAero@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Update@asAero@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@asAero@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x54];
};

check_size(asAero, 0x74);
