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
    mmwidget:compscroll

    0x4B4EF0 | public: __thiscall UICompositeScroll::UICompositeScroll(void) | ??0UICompositeScroll@@QAE@XZ
    0x4B4FD0 | public: virtual __thiscall UICompositeScroll::~UICompositeScroll(void) | ??1UICompositeScroll@@UAE@XZ
    0x4B5050 | public: void __thiscall UICompositeScroll::Init(float,float,float,float,float,int,int *,int,int,class Callback) | ?Init@UICompositeScroll@@QAEXMMMMMHPAHHHVCallback@@@Z
    0x4B5290 | public: void __thiscall UICompositeScroll::InitVScroll(float,float,float) | ?InitVScroll@UICompositeScroll@@QAEXMMM@Z
    0x4B5310 | public: void __thiscall UICompositeScroll::RemoveAllComponentChildren(void) | ?RemoveAllComponentChildren@UICompositeScroll@@QAEXXZ
    0x4B5360 | public: void __thiscall UICompositeScroll::AddComponent(class mmCompBase *) | ?AddComponent@UICompositeScroll@@QAEXPAVmmCompBase@@@Z
    0x4B5430 | public: void __thiscall UICompositeScroll::AddTitle(class mmCompBase *) | ?AddTitle@UICompositeScroll@@QAEXPAVmmCompBase@@@Z
    0x4B5450 | public: int __thiscall UICompositeScroll::GetSelectedCount(void) | ?GetSelectedCount@UICompositeScroll@@QAEHXZ
    0x4B54A0 | public: void __thiscall UICompositeScroll::Redraw(void) | ?Redraw@UICompositeScroll@@QAEXXZ
    0x4B55F0 | public: void __thiscall UICompositeScroll::VScrollCB(void) | ?VScrollCB@UICompositeScroll@@QAEXXZ
    0x4B5660 | public: void __thiscall UICompositeScroll::SetVScrollVals(void) | ?SetVScrollVals@UICompositeScroll@@QAEXXZ
    0x4B56B0 | public: void __thiscall UICompositeScroll::SetVScrollPos(void) | ?SetVScrollPos@UICompositeScroll@@QAEXXZ
    0x4B56F0 | public: virtual void __thiscall UICompositeScroll::Reset(void) | ?Reset@UICompositeScroll@@UAEXXZ
    0x4B5710 | public: virtual void __thiscall UICompositeScroll::Update(void) | ?Update@UICompositeScroll@@UAEXXZ
    0x4B5720 | public: int __thiscall UICompositeScroll::GetHit(float,float) | ?GetHit@UICompositeScroll@@QAEHMM@Z
    0x4B57A0 | public: virtual void __thiscall UICompositeScroll::Action(union eqEvent) | ?Action@UICompositeScroll@@UAEXTeqEvent@@@Z
    0x4B5920 | public: virtual void __thiscall UICompositeScroll::CaptureAction(union eqEvent) | ?CaptureAction@UICompositeScroll@@UAEXTeqEvent@@@Z
    0x4B5990 | public: virtual void __thiscall UICompositeScroll::Switch(int) | ?Switch@UICompositeScroll@@UAEXH@Z
    0x4B59D0 | public: void __thiscall UICompositeScroll::Clear(void) | ?Clear@UICompositeScroll@@QAEXXZ
    0x4B59E0 | public: void __thiscall UICompositeScroll::SetHightlight(void) | ?SetHightlight@UICompositeScroll@@QAEXXZ
    0x4B59F0 | public: float __thiscall UICompositeScroll::GetHeight(void) | ?GetHeight@UICompositeScroll@@QAEMXZ
    0x4B5A10 | public: void __thiscall UICompositeScroll::SetPosition(int) | ?SetPosition@UICompositeScroll@@QAEXH@Z
    0x4B5A50 | public: virtual void * __thiscall UICompositeScroll::`scalar deleting destructor'(unsigned int) | ??_GUICompositeScroll@@UAEPAXI@Z
    0x4B5A50 | public: virtual void * __thiscall UICompositeScroll::`vector deleting destructor'(unsigned int) | ??_EUICompositeScroll@@UAEPAXI@Z
    0x61E778 | const UICompositeScroll::`vftable' | ??_7UICompositeScroll@@6B@
*/

#include "widget.h"

class UICompositeScroll : public uiWidget
{
    // const UICompositeScroll::`vftable' @ 0x61E778

public:
    // 0x4B4EF0 | ??0UICompositeScroll@@QAE@XZ
    UICompositeScroll();

    // 0x4B5A50 | ??_EUICompositeScroll@@UAEPAXI@Z
    // 0x4B4FD0 | ??1UICompositeScroll@@UAE@XZ
    ~UICompositeScroll() override;

    // 0x4B57A0 | ?Action@UICompositeScroll@@UAEXTeqEvent@@@Z
    void Action(union eqEvent arg1) override;

    // 0x4B5360 | ?AddComponent@UICompositeScroll@@QAEXPAVmmCompBase@@@Z
    void AddComponent(class mmCompBase* arg1);

    // 0x4B5430 | ?AddTitle@UICompositeScroll@@QAEXPAVmmCompBase@@@Z | unused
    void AddTitle(class mmCompBase* arg1);

    // 0x4B5920 | ?CaptureAction@UICompositeScroll@@UAEXTeqEvent@@@Z
    void CaptureAction(union eqEvent arg1) override;

    // 0x4B59D0 | ?Clear@UICompositeScroll@@QAEXXZ
    void Clear();

    // 0x4B59F0 | ?GetHeight@UICompositeScroll@@QAEMXZ | unused
    f32 GetHeight();

    // 0x4B5720 | ?GetHit@UICompositeScroll@@QAEHMM@Z
    i32 GetHit(f32 arg1, f32 arg2);

    // 0x4B5450 | ?GetSelectedCount@UICompositeScroll@@QAEHXZ
    i32 GetSelectedCount();

    // 0x4B5050 | ?Init@UICompositeScroll@@QAEXMMMMMHPAHHHVCallback@@@Z
    void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, i32 arg6, i32* arg7, i32 arg8, i32 arg9,
        class Callback arg10);

    // 0x4B5290 | ?InitVScroll@UICompositeScroll@@QAEXMMM@Z
    void InitVScroll(f32 arg1, f32 arg2, f32 arg3);

    // 0x4B54A0 | ?Redraw@UICompositeScroll@@QAEXXZ
    void Redraw();

    // 0x4B5310 | ?RemoveAllComponentChildren@UICompositeScroll@@QAEXXZ
    void RemoveAllComponentChildren();

    // 0x4B56F0 | ?Reset@UICompositeScroll@@UAEXXZ
    void Reset() override;

    // 0x4B59E0 | ?SetHightlight@UICompositeScroll@@QAEXXZ
    void SetHightlight();

    // 0x4B5A10 | ?SetPosition@UICompositeScroll@@QAEXH@Z
    void SetPosition(i32 arg1);

    // 0x4B56B0 | ?SetVScrollPos@UICompositeScroll@@QAEXXZ
    void SetVScrollPos();

    // 0x4B5660 | ?SetVScrollVals@UICompositeScroll@@QAEXXZ
    void SetVScrollVals();

    // 0x4B5990 | ?Switch@UICompositeScroll@@UAEXH@Z
    void Switch(i32 arg1) override;

    // 0x4B5710 | ?Update@UICompositeScroll@@UAEXXZ
    void Update() override;

    // 0x4B55F0 | ?VScrollCB@UICompositeScroll@@QAEXXZ
    void VScrollCB();
};

check_size(UICompositeScroll, 0xE4);
