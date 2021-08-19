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
    mmwidget:vswidget

    0x4BF2F0 | public: __thiscall VSWidget::VSWidget(void) | ??0VSWidget@@QAE@XZ
    0x4BF370 | public: virtual __thiscall VSWidget::~VSWidget(void) | ??1VSWidget@@UAE@XZ
    0x4BF3F0 | public: void __thiscall VSWidget::Init(float,float,float,float,int *,class Callback,int) | ?Init@VSWidget@@QAEXMMMMPAHVCallback@@H@Z
    0x4BF450 | public: void __thiscall VSWidget::LoadBitmap(void) | ?LoadBitmap@VSWidget@@QAEXXZ
    0x4BF5A0 | public: void __thiscall VSWidget::CalcTroughRatio(float) | ?CalcTroughRatio@VSWidget@@QAEXM@Z
    0x4BF620 | public: void __thiscall VSWidget::SetHotSpots(void) | ?SetHotSpots@VSWidget@@QAEXXZ
    0x4BF6D0 | public: void __thiscall VSWidget::SyncData(void) | ?SyncData@VSWidget@@QAEXXZ
    0x4BF710 | public: float __thiscall VSWidget::Inc(void) | ?Inc@VSWidget@@QAEMXZ
    0x4BF770 | public: float __thiscall VSWidget::Dec(void) | ?Dec@VSWidget@@QAEMXZ
    0x4BF7D0 | public: void __thiscall VSWidget::SetStep(int,float) | ?SetStep@VSWidget@@QAEXHM@Z
    0x4BF840 | public: void __thiscall VSWidget::SetTrough(float) | ?SetTrough@VSWidget@@QAEXM@Z
    0x4BF8D0 | public: virtual void __thiscall VSWidget::Update(void) | ?Update@VSWidget@@UAEXXZ
    0x4BF900 | public: void __thiscall VSWidget::Switch(int,float,float) | ?Switch@VSWidget@@QAEXHMM@Z
    0x4BF950 | public: int __thiscall VSWidget::Action(union eqEvent,float,float,int) | ?Action@VSWidget@@QAEHTeqEvent@@MMH@Z
    0x4BFA00 | public: void __thiscall VSWidget::EvalMouseXY(float,float,int) | ?EvalMouseXY@VSWidget@@QAEXMMH@Z
    0x4BFBB0 | public: virtual void __thiscall VSWidget::Cull(void) | ?Cull@VSWidget@@UAEXXZ
    0x4BFD30 | public: static void __cdecl VSWidget::DeclareFields(void) | ?DeclareFields@VSWidget@@SAXXZ
    0x4BFEA0 | public: virtual class MetaClass * __thiscall VSWidget::GetClass(void) | ?GetClass@VSWidget@@UAEPAVMetaClass@@XZ
    0x4BFEB0 | public: virtual void * __thiscall VSWidget::`vector deleting destructor'(unsigned int) | ??_EVSWidget@@UAEPAXI@Z
    0x61F1E0 | const VSWidget::`vftable' | ??_7VSWidget@@6B@
    0x705CC8 | class MetaClass VSWidgetMetaClass | ?VSWidgetMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class VSWidget final : public asNode
{
public:
    // ??0VSWidget@@QAE@XZ
    ARTS_IMPORT VSWidget();

    // ??_EVSWidget@@UAEPAXI@Z
    // ??1VSWidget@@UAE@XZ
    ARTS_IMPORT ~VSWidget() override;

    // ?Action@VSWidget@@QAEHTeqEvent@@MMH@Z
    ARTS_IMPORT i32 Action(union eqEvent arg1, f32 arg2, f32 arg3, i32 arg4);

    // ?CalcTroughRatio@VSWidget@@QAEXM@Z
    ARTS_IMPORT void CalcTroughRatio(f32 arg1);

    // ?Cull@VSWidget@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Dec@VSWidget@@QAEMXZ
    ARTS_IMPORT f32 Dec();

    // ?EvalMouseXY@VSWidget@@QAEXMMH@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2, i32 arg3);

    // ?GetClass@VSWidget@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Inc@VSWidget@@QAEMXZ
    ARTS_IMPORT f32 Inc();

    // ?Init@VSWidget@@QAEXMMMMPAHVCallback@@H@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32* arg5, class Callback arg6, i32 arg7);

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

// ?VSWidgetMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass VSWidgetMetaClass;
