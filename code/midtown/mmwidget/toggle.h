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

class mmToggle final : public asNode
{
public:
    // ??0mmToggle@@QAE@XZ
    ARTS_IMPORT mmToggle();

    // ??_EmmToggle@@UAEPAXI@Z
    // ??1mmToggle@@UAE@XZ
    ARTS_IMPORT ~mmToggle() override;

    // ?Cull@mmToggle@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@mmToggle@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmToggle@@QAEXPADMMMM@Z
    ARTS_IMPORT void Init(char* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?Update@mmToggle@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmToggle@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?LoadBitmap@mmToggle@@AAEXPAD@Z
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // ?SetSize@mmToggle@@AAEXMM@Z
    ARTS_IMPORT void SetSize(f32 arg1, f32 arg2);

    u8 gap20[0x18];
};

check_size(mmToggle, 0x38);
