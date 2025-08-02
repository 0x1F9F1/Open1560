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

class agiBitmap;
class mmTextNode;

class PUMenuBase : public UIMenu
{
public:
    // ??0PUMenuBase@@QAE@HMMMMPAD@Z
    ARTS_EXPORT PUMenuBase(i32 menu_id, f32 x, f32 y, f32 width, f32 height, char* background);

    // ??_EPUMenuBase@@UAEPAXI@Z
    // ??_GPUMenuBase@@UAEPAXI@Z
    // ??1PUMenuBase@@UAE@XZ
    ARTS_IMPORT ~PUMenuBase() override;

    // ?AddExit@PUMenuBase@@QAEMMMMM@Z
    ARTS_IMPORT f32 AddExit(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?AddOKCancel@PUMenuBase@@QAEXVCallback@@0@Z
    ARTS_IMPORT void AddOKCancel(Callback arg1, Callback arg2);

    // ?AddPrevious@PUMenuBase@@QAEMMMMM@Z
    ARTS_IMPORT f32 AddPrevious(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?CreateDummyBitmap@PUMenuBase@@QAEPAVagiBitmap@@XZ
    ARTS_IMPORT RcOwner<agiBitmap> CreateDummyBitmap();

    // ?CreateTitle@PUMenuBase@@QAEMXZ
    ARTS_IMPORT f32 CreateTitle();

    // ?Cull@PUMenuBase@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?DisableExit@PUMenuBase@@QAEXXZ
    ARTS_IMPORT void DisableExit();

    // ?EnableExit@PUMenuBase@@QAEXXZ
    ARTS_IMPORT void EnableExit();

    // ?Update@PUMenuBase@@UAEXXZ
    ARTS_IMPORT void Update() override;

    Ptr<mmTextNode> CreateTextNode(f32 x, f32 y, f32 width, f32 height, i32 lines, i32 flags);
    i32 AddText(mmTextNode* node, void* font, LocString* text, i32 effects, f32 x, f32 y);

protected:
    i32 field_90 {};
    Rc<agiBitmap> bg_bitmap_;
    UIButton* exit_button_ {};
    i32 bg_x_ {};
    i32 bg_y_ {};
    i32 widget_font_size_ {};
    f32 widget_height_ {};
    f32 field_AC {};
    f32 field_B0 {};
    f32 field_B4 {};
    f32 field_B8 {};
    f32 field_BC {};
};

check_size(PUMenuBase, 0xC0);
