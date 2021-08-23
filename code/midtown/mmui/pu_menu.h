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

/*
    mmui:pu_menu

    0x4AAFE0 | public: __thiscall PUMenuBase::PUMenuBase(int,float,float,float,float,char *) | ??0PUMenuBase@@QAE@HMMMMPAD@Z
    0x4AB1B0 | public: virtual __thiscall PUMenuBase::~PUMenuBase(void) | ??1PUMenuBase@@UAE@XZ
    0x4AB210 | public: class agiBitmap * __thiscall PUMenuBase::CreateDummyBitmap(void) | ?CreateDummyBitmap@PUMenuBase@@QAEPAVagiBitmap@@XZ
    0x4AB270 | public: float __thiscall PUMenuBase::CreateTitle(void) | ?CreateTitle@PUMenuBase@@QAEMXZ
    0x4AB280 | public: float __thiscall PUMenuBase::AddPrevious(float,float,float,float) | ?AddPrevious@PUMenuBase@@QAEMMMMM@Z
    0x4AB2F0 | public: void __thiscall PUMenuBase::AddOKCancel(class Callback,class Callback) | ?AddOKCancel@PUMenuBase@@QAEXVCallback@@0@Z
    0x4AB390 | public: float __thiscall PUMenuBase::AddExit(float,float,float,float) | ?AddExit@PUMenuBase@@QAEMMMMM@Z
    0x4AB400 | public: virtual void __thiscall PUMenuBase::Update(void) | ?Update@PUMenuBase@@UAEXXZ
    0x4AB430 | public: virtual void __thiscall PUMenuBase::Cull(void) | ?Cull@PUMenuBase@@UAEXXZ
    0x4AB470 | public: void __thiscall PUMenuBase::DisableExit(void) | ?DisableExit@PUMenuBase@@QAEXXZ
    0x4AB480 | public: void __thiscall PUMenuBase::EnableExit(void) | ?EnableExit@PUMenuBase@@QAEXXZ
    0x4AB490 | public: virtual void * __thiscall PUMenuBase::`scalar deleting destructor'(unsigned int) | ??_GPUMenuBase@@UAEPAXI@Z
    0x4AB490 | public: virtual void * __thiscall PUMenuBase::`vector deleting destructor'(unsigned int) | ??_EPUMenuBase@@UAEPAXI@Z
    0x61E200 | const PUMenuBase::`vftable' | ??_7PUMenuBase@@6B@
*/

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
    i32 field_90 {0};
    Rc<agiBitmap> bg_bitmap_;
    UIButton* exit_button_ {nullptr};
    i32 bg_x_ {0};
    i32 bg_y_ {0};
    i32 widget_font_size_ {0};
    f32 widget_height_ {0.0f};
    f32 field_AC {0.0f};
    f32 field_B0 {0.0f};
    f32 field_B4 {0.0f};
    f32 field_B8 {0.0f};
    f32 field_BC {0.0f};
};

check_size(PUMenuBase, 0xC0);
