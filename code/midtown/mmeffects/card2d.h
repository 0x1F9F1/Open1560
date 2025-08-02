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

class Card2D final : public asNode
{
public:
    // ??0Card2D@@QAE@XZ
    ARTS_IMPORT Card2D();

    // ??_ECard2D@@UAEPAXI@Z
    // ??_GCard2D@@UAEPAXI@Z
    // ??1Card2D@@UAE@XZ | inline
    ARTS_EXPORT ~Card2D() override = default;

    // ?Init@Card2D@@QAEXPAVasCamera@@MMMMM@Z
    ARTS_IMPORT void Init(asCamera* camera, f32 x, f32 y, f32 w, f32 h, f32 alpha);

    // ?SetAlpha@Card2D@@QAEXM@Z
    ARTS_IMPORT void SetAlpha(f32 arg1);

    // ?SetColor@Card2D@@QAEXVVector4@@@Z | inline
    ARTS_IMPORT void SetColor(Vector4 arg1);

    // ?SetDimensions@Card2D@@QAEXMMMM@Z
    ARTS_IMPORT void SetDimensions(f32 x, f32 y, f32 w, f32 h);

    // ?SetPosition@Card2D@@QAEXMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2);

    // ?Update@Card2D@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@Card2D@@EAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@Card2D@@EAEXXZ
    ARTS_IMPORT void Cull() override;

    u8 gap20[0x18];
};

check_size(Card2D, 0x38);
