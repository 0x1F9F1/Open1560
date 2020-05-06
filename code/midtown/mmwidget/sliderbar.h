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
    mmwidget:sliderbar

    0x4BE6A0 | public: __thiscall mmSlider::mmSlider(void) | ??0mmSlider@@QAE@XZ
    0x4BE730 | public: virtual __thiscall mmSlider::~mmSlider(void) | ??1mmSlider@@UAE@XZ
    0x4BE7D0 | public: void __thiscall mmSlider::Init(char *,class uiWidget *,float,float,float,float,int,float,float,int,int) | ?Init@mmSlider@@QAEXPADPAVuiWidget@@MMMMHMMHH@Z
    0x4BE830 | public: void __thiscall mmSlider::LoadBitmap(char *) | ?LoadBitmap@mmSlider@@QAEXPAD@Z
    0x4BE9E0 | public: void __thiscall mmSlider::SetReadWrite(int) | ?SetReadWrite@mmSlider@@QAEXH@Z
    0x4BEA00 | public: int __thiscall mmSlider::IsReadWrite(void) | ?IsReadWrite@mmSlider@@QAEHXZ
    0x4BEA10 | public: float __thiscall mmSlider::SetValue(float) | ?SetValue@mmSlider@@QAEMM@Z
    0x4BEA70 | public: float __thiscall mmSlider::GetScreenHeight(void) | ?GetScreenHeight@mmSlider@@QAEMXZ
    0x4BEAA0 | public: float __thiscall mmSlider::FudgeWidth(void) | ?FudgeWidth@mmSlider@@QAEMXZ
    0x4BEAD0 | public: void __thiscall mmSlider::SetPosition(float,float) | ?SetPosition@mmSlider@@QAEXMM@Z
    0x4BEAF0 | public: void __thiscall mmSlider::GetSliderHotSpots(float &,float &,float &,float &,float &,float &) | ?GetSliderHotSpots@mmSlider@@QAEXAAM00000@Z
    0x4BEBC0 | public: void __thiscall mmSlider::UpdatePosition(void) | ?UpdatePosition@mmSlider@@QAEXXZ
    0x4BEBF0 | public: float __thiscall mmSlider::Inc(void) | ?Inc@mmSlider@@QAEMXZ
    0x4BEC10 | public: float __thiscall mmSlider::Dec(void) | ?Dec@mmSlider@@QAEMXZ
    0x4BEC30 | public: void __thiscall mmSlider::SetStep(float) | ?SetStep@mmSlider@@QAEXM@Z
    0x4BECB0 | public: void __thiscall mmSlider::SetRange(float,float) | ?SetRange@mmSlider@@QAEXMM@Z
    0x4BED20 | public: virtual void __thiscall mmSlider::Update(void) | ?Update@mmSlider@@UAEXXZ
    0x4BED40 | public: virtual void __thiscall mmSlider::Cull(void) | ?Cull@mmSlider@@UAEXXZ
    0x4BEF00 | public: static void __cdecl mmSlider::DeclareFields(void) | ?DeclareFields@mmSlider@@SAXXZ
    0x4BF070 | public: virtual class MetaClass * __thiscall mmSlider::GetClass(void) | ?GetClass@mmSlider@@UAEPAVMetaClass@@XZ
    0x4BF080 | public: virtual void * __thiscall mmSlider::`vector deleting destructor'(unsigned int) | ??_EmmSlider@@UAEPAXI@Z
    0x61F140 | const mmSlider::`vftable' | ??_7mmSlider@@6B@
    0x705CA0 | class MetaClass mmSliderMetaClass | ?mmSliderMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmSlider : public asNode
{
    // const mmSlider::`vftable' @ 0x61F140

public:
    // 0x4BE6A0 | ??0mmSlider@@QAE@XZ
    mmSlider();

    // 0x4BF080 | ??_EmmSlider@@UAEPAXI@Z
    // 0x4BE730 | ??1mmSlider@@UAE@XZ
    ~mmSlider() override;

    // 0x4BED40 | ?Cull@mmSlider@@UAEXXZ
    void Cull() override;

    // 0x4BEC10 | ?Dec@mmSlider@@QAEMXZ
    f32 Dec();

    // 0x4BEAA0 | ?FudgeWidth@mmSlider@@QAEMXZ
    f32 FudgeWidth();

    // 0x4BF070 | ?GetClass@mmSlider@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4BEA70 | ?GetScreenHeight@mmSlider@@QAEMXZ
    f32 GetScreenHeight();

    // 0x4BEAF0 | ?GetSliderHotSpots@mmSlider@@QAEXAAM00000@Z
    void GetSliderHotSpots(f32& arg1, f32& arg2, f32& arg3, f32& arg4, f32& arg5, f32& arg6);

    // 0x4BEBF0 | ?Inc@mmSlider@@QAEMXZ
    f32 Inc();

    // 0x4BE7D0 | ?Init@mmSlider@@QAEXPADPAVuiWidget@@MMMMHMMHH@Z
    void Init(char* arg1, class uiWidget* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, f32 arg8, f32 arg9,
        i32 arg10, i32 arg11);

    // 0x4BEA00 | ?IsReadWrite@mmSlider@@QAEHXZ
    i32 IsReadWrite();

    // 0x4BE830 | ?LoadBitmap@mmSlider@@QAEXPAD@Z
    void LoadBitmap(char* arg1);

    // 0x4BEAD0 | ?SetPosition@mmSlider@@QAEXMM@Z
    void SetPosition(f32 arg1, f32 arg2);

    // 0x4BECB0 | ?SetRange@mmSlider@@QAEXMM@Z
    void SetRange(f32 arg1, f32 arg2);

    // 0x4BE9E0 | ?SetReadWrite@mmSlider@@QAEXH@Z
    void SetReadWrite(i32 arg1);

    // 0x4BEC30 | ?SetStep@mmSlider@@QAEXM@Z
    void SetStep(f32 arg1);

    // 0x4BEA10 | ?SetValue@mmSlider@@QAEMM@Z
    f32 SetValue(f32 arg1);

    // 0x4BED20 | ?Update@mmSlider@@UAEXXZ
    void Update() override;

    // 0x4BEBC0 | ?UpdatePosition@mmSlider@@QAEXXZ
    void UpdatePosition();

    // 0x4BEF00 | ?DeclareFields@mmSlider@@SAXXZ
    static void DeclareFields();
};

check_size(mmSlider, 0xA4);

// 0x705CA0 | ?mmSliderMetaClass@@3VMetaClass@@A
inline extern_var(0x705CA0, class MetaClass, mmSliderMetaClass);
