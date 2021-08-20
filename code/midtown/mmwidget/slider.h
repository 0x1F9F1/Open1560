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
    mmwidget:slider

    0x4B39B0 | public: __thiscall UISlider::UISlider(void) | ??0UISlider@@QAE@XZ
    0x4B3A40 | public: virtual __thiscall UISlider::~UISlider(void) | ??1UISlider@@UAE@XZ
    0x4B3AB0 | public: void __thiscall UISlider::Init(struct LocString *,float *,float,float,float,float,float,float,int,int,int,int,class Callback,class UIMenu *) | ?Init@UISlider@@QAEXPAULocString@@PAMMMMMMMHHHHVCallback@@PAVUIMenu@@@Z
    0x4B3CD0 | public: virtual void __thiscall UISlider::SetPosition(float,float) | ?SetPosition@UISlider@@UAEXMM@Z
    0x4B3E30 | public: void __thiscall UISlider::SetText(struct LocString *) | ?SetText@UISlider@@QAEXPAULocString@@@Z
    0x4B3E40 | public: virtual void __thiscall UISlider::Update(void) | ?Update@UISlider@@UAEXXZ
    0x4B3EA0 | public: virtual void __thiscall UISlider::Action(union eqEvent) | ?Action@UISlider@@UAEXTeqEvent@@@Z
    0x4B3F70 | public: virtual void __thiscall UISlider::Switch(int) | ?Switch@UISlider@@UAEXH@Z
    0x4B3FE0 | public: int __thiscall UISlider::TestHit(float,float) | ?TestHit@UISlider@@QAEHMM@Z
    0x4B3FF0 | public: void __thiscall UISlider::SetReadWrite(int) | ?SetReadWrite@UISlider@@QAEXH@Z
    0x4B4040 | public: int __thiscall UISlider::IsReadWrite(void) | ?IsReadWrite@UISlider@@QAEHXZ
    0x4B4050 | public: float __thiscall UISlider::GetValue(void) | ?GetValue@UISlider@@QAEMXZ
    0x4B4060 | public: float __thiscall UISlider::SetValue(float) | ?SetValue@UISlider@@QAEMM@Z
    0x4B4090 | public: void __thiscall UISlider::SetMouseParams(float) | ?SetMouseParams@UISlider@@QAEXM@Z
    0x4B40E0 | public: void __thiscall UISlider::EvalMouseXY(float,float) | ?EvalMouseXY@UISlider@@QAEXMM@Z
    0x4B4210 | public: void __thiscall UISlider::SetData(float) | ?SetData@UISlider@@QAEXM@Z
    0x4B4230 | public: float __thiscall UISlider::GetFudgeWidth(void) | ?GetFudgeWidth@UISlider@@QAEMXZ
    0x4B4240 | public: virtual void * __thiscall UISlider::`scalar deleting destructor'(unsigned int) | ??_GUISlider@@UAEPAXI@Z
    0x4B4240 | public: virtual void * __thiscall UISlider::`vector deleting destructor'(unsigned int) | ??_EUISlider@@UAEPAXI@Z
    0x4B4270 | public: virtual float __thiscall UISlider::GetScreenHeight(void) | ?GetScreenHeight@UISlider@@UAEMXZ
    0x61E590 | const UISlider::`vftable' | ??_7UISlider@@6B@
*/

#include "widget.h"

class UISlider final : public uiWidget
{
public:
    // ??0UISlider@@QAE@XZ
    ARTS_IMPORT UISlider();

    // ??_EUISlider@@UAEPAXI@Z
    // ??_GUISlider@@UAEPAXI@Z
    // ??1UISlider@@UAE@XZ
    ARTS_IMPORT ~UISlider() override;

    // ?Action@UISlider@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?EvalMouseXY@UISlider@@QAEXMM@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2);

    // ?GetFudgeWidth@UISlider@@QAEMXZ
    ARTS_IMPORT f32 GetFudgeWidth();

    // ?GetScreenHeight@UISlider@@UAEMXZ | inline
    ARTS_IMPORT f32 GetScreenHeight() override;

    // ?GetValue@UISlider@@QAEMXZ | unused
    ARTS_IMPORT f32 GetValue();

    // ?Init@UISlider@@QAEXPAULocString@@PAMMMMMMMHHHHVCallback@@PAVUIMenu@@@Z
    ARTS_IMPORT void Init(LocString* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
        i32 arg9, i32 arg10, i32 arg11, i32 arg12, Callback arg13, UIMenu* arg14);

    // ?IsReadWrite@UISlider@@QAEHXZ | unused
    ARTS_IMPORT i32 IsReadWrite();

    // ?SetData@UISlider@@QAEXM@Z
    ARTS_IMPORT void SetData(f32 arg1);

    // ?SetMouseParams@UISlider@@QAEXM@Z
    ARTS_IMPORT void SetMouseParams(f32 arg1);

    // ?SetPosition@UISlider@@UAEXMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2) override;

    // ?SetReadWrite@UISlider@@QAEXH@Z
    ARTS_IMPORT void SetReadWrite(i32 arg1);

    // ?SetText@UISlider@@QAEXPAULocString@@@Z | unused
    ARTS_EXPORT void SetText(LocString* arg1);

    // ?SetValue@UISlider@@QAEMM@Z
    ARTS_IMPORT f32 SetValue(f32 arg1);

    // ?Switch@UISlider@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?TestHit@UISlider@@QAEHMM@Z | unused
    ARTS_EXPORT i32 TestHit(f32 arg1, f32 arg2);

    // ?Update@UISlider@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap74[0x58];
};

check_size(UISlider, 0xCC);
