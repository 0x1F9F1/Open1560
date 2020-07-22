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
    mmwidget:vscrollbar

    0x4BCD60 | public: __thiscall UIVScrollBar::UIVScrollBar(void) | ??0UIVScrollBar@@QAE@XZ
    0x4BCE00 | public: virtual __thiscall UIVScrollBar::~UIVScrollBar(void) | ??1UIVScrollBar@@UAE@XZ
    0x4BCE90 | public: void __thiscall UIVScrollBar::Init(float,float,float,float,int,float,float,int *,class Callback,int) | ?Init@UIVScrollBar@@QAEXMMMMHMMPAHVCallback@@H@Z
    0x4BCF00 | public: void __thiscall UIVScrollBar::LoadBitmap(void) | ?LoadBitmap@UIVScrollBar@@QAEXXZ
    0x4BD030 | public: void __thiscall UIVScrollBar::SetHotSpots(void) | ?SetHotSpots@UIVScrollBar@@QAEXXZ
    0x4BD0F0 | public: float __thiscall UIVScrollBar::Inc(void) | ?Inc@UIVScrollBar@@QAEMXZ
    0x4BD150 | public: float __thiscall UIVScrollBar::Dec(void) | ?Dec@UIVScrollBar@@QAEMXZ
    0x4BD1B0 | public: void __thiscall UIVScrollBar::SetStep(int,float) | ?SetStep@UIVScrollBar@@QAEXHM@Z
    0x4BD210 | public: void __thiscall UIVScrollBar::SetRange(float,float) | ?SetRange@UIVScrollBar@@QAEXMM@Z
    0x4BD280 | public: void __thiscall UIVScrollBar::SetTrough(float,float) | ?SetTrough@UIVScrollBar@@QAEXMM@Z
    0x4BD300 | public: virtual void __thiscall UIVScrollBar::Update(void) | ?Update@UIVScrollBar@@UAEXXZ
    0x4BD320 | public: virtual void __thiscall UIVScrollBar::Switch(int) | ?Switch@UIVScrollBar@@UAEXH@Z
    0x4BD370 | public: virtual void __thiscall UIVScrollBar::Action(union eqEvent) | ?Action@UIVScrollBar@@UAEXTeqEvent@@@Z
    0x4BD430 | public: void __thiscall UIVScrollBar::EvalMouseXY(float,float) | ?EvalMouseXY@UIVScrollBar@@QAEXMM@Z
    0x4BD5B0 | public: virtual void __thiscall UIVScrollBar::Cull(void) | ?Cull@UIVScrollBar@@UAEXXZ
    0x4BD730 | public: static void __cdecl UIVScrollBar::DeclareFields(void) | ?DeclareFields@UIVScrollBar@@SAXXZ
    0x4BD8A0 | public: virtual class MetaClass * __thiscall UIVScrollBar::GetClass(void) | ?GetClass@UIVScrollBar@@UAEPAVMetaClass@@XZ
    0x4BD8B0 | public: virtual void * __thiscall UIVScrollBar::`vector deleting destructor'(unsigned int) | ??_EUIVScrollBar@@UAEPAXI@Z
    0x4BD910 | public: virtual void __thiscall UIVScrollBar::SetPosition(float,float) | ?SetPosition@UIVScrollBar@@UAEXMM@Z
    0x4BD930 | public: virtual void __thiscall UIVScrollBar::Enable(void) | ?Enable@UIVScrollBar@@UAEXXZ
    0x4BD950 | public: virtual void __thiscall UIVScrollBar::Disable(void) | ?Disable@UIVScrollBar@@UAEXXZ
    0x61F030 | const UIVScrollBar::`vftable' | ??_7UIVScrollBar@@6B@
    0x705C28 | class MetaClass UIVScrollBarMetaClass | ?UIVScrollBarMetaClass@@3VMetaClass@@A
*/

#include "widget.h"

class UIVScrollBar final : public uiWidget
{
    // const UIVScrollBar::`vftable' @ 0x61F030

public:
    // 0x4BCD60 | ??0UIVScrollBar@@QAE@XZ
    ARTS_IMPORT UIVScrollBar();

    // 0x4BD8B0 | ??_EUIVScrollBar@@UAEPAXI@Z
    // 0x4BCE00 | ??1UIVScrollBar@@UAE@XZ
    ARTS_IMPORT ~UIVScrollBar() override;

    // 0x4BD370 | ?Action@UIVScrollBar@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // 0x4BD5B0 | ?Cull@UIVScrollBar@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x4BD150 | ?Dec@UIVScrollBar@@QAEMXZ
    ARTS_IMPORT f32 Dec();

    // 0x4BD950 | ?Disable@UIVScrollBar@@UAEXXZ | inline
    ARTS_IMPORT void Disable() override;

    // 0x4BD930 | ?Enable@UIVScrollBar@@UAEXXZ | inline
    ARTS_IMPORT void Enable() override;

    // 0x4BD430 | ?EvalMouseXY@UIVScrollBar@@QAEXMM@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2);

    // 0x4BD8A0 | ?GetClass@UIVScrollBar@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4BD0F0 | ?Inc@UIVScrollBar@@QAEMXZ
    ARTS_IMPORT f32 Inc();

    // 0x4BCE90 | ?Init@UIVScrollBar@@QAEXMMMMHMMPAHVCallback@@H@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5, f32 arg6, f32 arg7, i32* arg8,
        class Callback arg9, i32 arg10);

    // 0x4BCF00 | ?LoadBitmap@UIVScrollBar@@QAEXXZ
    ARTS_IMPORT void LoadBitmap();

    // 0x4BD030 | ?SetHotSpots@UIVScrollBar@@QAEXXZ
    ARTS_IMPORT void SetHotSpots();

    // 0x4BD910 | ?SetPosition@UIVScrollBar@@UAEXMM@Z | inline
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2) override;

    // 0x4BD210 | ?SetRange@UIVScrollBar@@QAEXMM@Z
    ARTS_IMPORT void SetRange(f32 arg1, f32 arg2);

    // 0x4BD1B0 | ?SetStep@UIVScrollBar@@QAEXHM@Z
    ARTS_IMPORT void SetStep(i32 arg1, f32 arg2);

    // 0x4BD280 | ?SetTrough@UIVScrollBar@@QAEXMM@Z
    ARTS_IMPORT void SetTrough(f32 arg1, f32 arg2);

    // 0x4BD320 | ?Switch@UIVScrollBar@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // 0x4BD300 | ?Update@UIVScrollBar@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4BD730 | ?DeclareFields@UIVScrollBar@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap74[0x98];
};

check_size(UIVScrollBar, 0x10C);

// 0x705C28 | ?UIVScrollBarMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass UIVScrollBarMetaClass;
