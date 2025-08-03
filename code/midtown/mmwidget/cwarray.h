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

class UICWArray final : public uiWidget
{
public:
    // ??0UICWArray@@QAE@XZ
    ARTS_IMPORT UICWArray();

    // ??1UICWArray@@UAE@XZ
    ARTS_EXPORT ~UICWArray() override = default;

    // ?AcceptCapture@UICWArray@@QAEXXZ
    ARTS_IMPORT void AcceptCapture();

    // ?Action@UICWArray@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?CaptureAction@UICWArray@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void CaptureAction(eqEvent arg1) override;

    // ?CheckCapture@UICWArray@@QAEXXZ
    ARTS_IMPORT void CheckCapture();

    // ?DefaultCFG@UICWArray@@QAEXXZ
    ARTS_EXPORT void DefaultCFG();

    // ?EnterCapture@UICWArray@@QAEXH@Z
    ARTS_IMPORT void EnterCapture(i32 arg1);

    // ?ForceCapture@UICWArray@@QAEXXZ
    ARTS_IMPORT void ForceCapture();

    // ?Init@UICWArray@@QAEXMMMMHVCallback@@@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5, Callback arg6);

    // ?Redraw@UICWArray@@QAEXXZ
    ARTS_IMPORT void Redraw();

    // ?Reset@UICWArray@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetCapture@UICWArray@@QAEXXZ
    ARTS_IMPORT void ResetCapture();

    // ?SetVScrollPos@UICWArray@@QAEXXZ
    ARTS_IMPORT void SetVScrollPos();

    // ?SetVScrollVals@UICWArray@@QAEXXZ
    ARTS_IMPORT void SetVScrollVals();

    // ?Switch@UICWArray@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Update@UICWArray@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?VScrollCB@UICWArray@@QAEXXZ
    ARTS_IMPORT void VScrollCB();

    u8 gap74[0x68];
};

check_size(UICWArray, 0xDC);
