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

union eqEvent;

class VSWidget final : public asNode
{
public:
    // ??0VSWidget@@QAE@XZ
    ARTS_IMPORT VSWidget();

    // ??1VSWidget@@UAE@XZ
    ARTS_IMPORT ~VSWidget() override;

    // ?Action@VSWidget@@QAEHTeqEvent@@MMH@Z
    ARTS_IMPORT i32 Action(eqEvent arg1, f32 arg2, f32 arg3, i32 arg4);

    // ?CalcTroughRatio@VSWidget@@QAEXM@Z
    ARTS_IMPORT void CalcTroughRatio(f32 arg1);

    // ?Cull@VSWidget@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Dec@VSWidget@@QAEMXZ
    ARTS_IMPORT f32 Dec();

    // ?EvalMouseXY@VSWidget@@QAEXMMH@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2, i32 arg3);

    // ?GetClass@VSWidget@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Inc@VSWidget@@QAEMXZ
    ARTS_IMPORT f32 Inc();

    // ?Init@VSWidget@@QAEXMMMMPAHVCallback@@H@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32* arg5, Callback arg6, i32 arg7);

    // ?LoadBitmap@VSWidget@@QAEXXZ
    ARTS_IMPORT void LoadBitmap();

    // ?SetHotSpots@VSWidget@@QAEXXZ
    ARTS_IMPORT void SetHotSpots();

    // ?SetStep@VSWidget@@QAEXHM@Z
    ARTS_IMPORT void SetStep(i32 arg1, f32 arg2);

    // ?SetTrough@VSWidget@@QAEXM@Z
    ARTS_IMPORT void SetTrough(f32 arg1);

    // ?Switch@VSWidget@@QAEXHMM@Z
    ARTS_IMPORT void Switch(i32 arg1, f32 arg2, f32 arg3);

    // ?SyncData@VSWidget@@QAEXXZ
    ARTS_IMPORT void SyncData();

    // ?Update@VSWidget@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@VSWidget@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xB0];
};

check_size(VSWidget, 0xD0);
