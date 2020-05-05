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

#include "textfield.h"

class UISlider : public uiWidget
{
    // const UISlider::`vftable' @ 0x61E590

public:
    // 0x4B39B0 | ??0UISlider@@QAE@XZ
    UISlider();

    // 0x4B4240 | ??_EUISlider@@UAEPAXI@Z
    // 0x4B3A40 | ??1UISlider@@UAE@XZ
    ~UISlider() override;

    // 0x4B3EA0 | ?Action@UISlider@@UAEXTeqEvent@@@Z
    void Action(union eqEvent arg1) override;

    // 0x4B40E0 | ?EvalMouseXY@UISlider@@QAEXMM@Z
    void EvalMouseXY(f32 arg1, f32 arg2);

    // 0x4B4230 | ?GetFudgeWidth@UISlider@@QAEMXZ
    f32 GetFudgeWidth();

    // 0x4B4270 | ?GetScreenHeight@UISlider@@UAEMXZ
    f32 GetScreenHeight() override;

    // 0x4B4050 | ?GetValue@UISlider@@QAEMXZ
    f32 GetValue();

    // 0x4B3AB0 | ?Init@UISlider@@QAEXPAULocString@@PAMMMMMMMHHHHVCallback@@PAVUIMenu@@@Z
    void Init(struct LocString* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, i32 arg9,
        i32 arg10, i32 arg11, i32 arg12, class Callback arg13, class UIMenu* arg14);

    // 0x4B4040 | ?IsReadWrite@UISlider@@QAEHXZ
    i32 IsReadWrite();

    // 0x4B4210 | ?SetData@UISlider@@QAEXM@Z
    void SetData(f32 arg1);

    // 0x4B4090 | ?SetMouseParams@UISlider@@QAEXM@Z
    void SetMouseParams(f32 arg1);

    // 0x4B3CD0 | ?SetPosition@UISlider@@UAEXMM@Z
    void SetPosition(f32 arg1, f32 arg2) override;

    // 0x4B3FF0 | ?SetReadWrite@UISlider@@QAEXH@Z
    void SetReadWrite(i32 arg1);

    // 0x4B3E30 | ?SetText@UISlider@@QAEXPAULocString@@@Z
    void SetText(struct LocString* arg1);

    // 0x4B4060 | ?SetValue@UISlider@@QAEMM@Z
    f32 SetValue(f32 arg1);

    // 0x4B3F70 | ?Switch@UISlider@@UAEXH@Z
    void Switch(i32 arg1) override;

    // 0x4B3FE0 | ?TestHit@UISlider@@QAEHMM@Z
    i32 TestHit(f32 arg1, f32 arg2);

    // 0x4B3E40 | ?Update@UISlider@@UAEXXZ
    void Update() override;
};

check_size(UISlider, 0xCC);
