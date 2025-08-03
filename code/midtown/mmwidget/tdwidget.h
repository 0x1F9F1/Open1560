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

class asCamera;

class TextDropWidget final : public asNode
{
public:
    // ??0TextDropWidget@@QAE@XZ
    ARTS_IMPORT TextDropWidget();

    // ??1TextDropWidget@@UAE@XZ
    ARTS_IMPORT ~TextDropWidget() override;

    // ?Capture@TextDropWidget@@QAEHMM@Z
    ARTS_IMPORT i32 Capture(f32 arg1, f32 arg2);

    // ?DecDrop@TextDropWidget@@QAEHXZ
    ARTS_IMPORT i32 DecDrop();

    // ?GetClass@TextDropWidget@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetDisabledMask@TextDropWidget@@QAEJXZ
    ARTS_IMPORT ilong GetDisabledMask();

    // ?IncDrop@TextDropWidget@@QAEHXZ
    ARTS_IMPORT i32 IncDrop();

    // ?Init@TextDropWidget@@QAEXPAVasCamera@@PAXMMMMMVstring@@H@Z
    ARTS_IMPORT void Init(
        asCamera* arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, string arg8, i32 arg9);

    // ?IsActive@TextDropWidget@@QAEHXZ
    ARTS_IMPORT i32 IsActive();

    // ?SetActive@TextDropWidget@@QAEXH@Z
    ARTS_IMPORT void SetActive(i32 arg1);

    // ?SetDisabledMask@TextDropWidget@@QAEXJ@Z
    ARTS_IMPORT void SetDisabledMask(ilong arg1);

    // ?SetHighlight@TextDropWidget@@QAEHH@Z
    ARTS_IMPORT i32 SetHighlight(i32 arg1);

    // ?SetString@TextDropWidget@@QAEXVstring@@@Z
    ARTS_IMPORT void SetString(string arg1);

    // ?SetValue@TextDropWidget@@QAEHH@Z
    ARTS_IMPORT i32 SetValue(i32 arg1);

    // ?Switch@TextDropWidget@@QAEXHAAVVector4@@@Z
    ARTS_IMPORT void Switch(i32 arg1, Vector4& arg2);

    // ?Update@TextDropWidget@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@TextDropWidget@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x18];
};

check_size(TextDropWidget, 0x38);
