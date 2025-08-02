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

#include "widget.h"

class mmCompBase;

class UICompositeScroll final : public uiWidget
{
public:
    // ??0UICompositeScroll@@QAE@XZ
    ARTS_IMPORT UICompositeScroll();

    // ??_EUICompositeScroll@@UAEPAXI@Z
    // ??_GUICompositeScroll@@UAEPAXI@Z
    // ??1UICompositeScroll@@UAE@XZ
    ARTS_IMPORT ~UICompositeScroll() override;

    // ?Action@UICompositeScroll@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?AddComponent@UICompositeScroll@@QAEXPAVmmCompBase@@@Z
    ARTS_IMPORT void AddComponent(mmCompBase* arg1);

    // ?CaptureAction@UICompositeScroll@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void CaptureAction(eqEvent arg1) override;

    // ?Clear@UICompositeScroll@@QAEXXZ
    ARTS_IMPORT void Clear();

    // ?GetHit@UICompositeScroll@@QAEHMM@Z
    ARTS_IMPORT i32 GetHit(f32 arg1, f32 arg2);

    // ?GetSelectedCount@UICompositeScroll@@QAEHXZ
    ARTS_IMPORT i32 GetSelectedCount();

    // ?Init@UICompositeScroll@@QAEXMMMMMHPAHHHVCallback@@@Z
    ARTS_IMPORT void Init(
        f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, i32 arg6, i32* arg7, i32 arg8, i32 arg9, Callback arg10);

    // ?InitVScroll@UICompositeScroll@@QAEXMMM@Z
    ARTS_IMPORT void InitVScroll(f32 arg1, f32 arg2, f32 arg3);

    // ?Redraw@UICompositeScroll@@QAEXXZ
    ARTS_IMPORT void Redraw();

    // ?RemoveAllComponentChildren@UICompositeScroll@@QAEXXZ
    ARTS_IMPORT void RemoveAllComponentChildren();

    // ?Reset@UICompositeScroll@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetHightlight@UICompositeScroll@@QAEXXZ
    ARTS_EXPORT void SetHightlight();

    // ?SetPosition@UICompositeScroll@@QAEXH@Z
    ARTS_IMPORT void SetPosition(i32 arg1);

    // ?SetVScrollPos@UICompositeScroll@@QAEXXZ
    ARTS_IMPORT void SetVScrollPos();

    // ?SetVScrollVals@UICompositeScroll@@QAEXXZ
    ARTS_IMPORT void SetVScrollVals();

    // ?Switch@UICompositeScroll@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Update@UICompositeScroll@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?VScrollCB@UICompositeScroll@@QAEXXZ
    ARTS_IMPORT void VScrollCB();

    u8 gap74[0x70];
};

check_size(UICompositeScroll, 0xE4);
