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

#include "arts7/linear.h"
#include "arts7/node.h"

/*
    mmgame:dash

    0x4215D0 | public: __thiscall mmDashView::mmDashView(void) | ??0mmDashView@@QAE@XZ
    0x421770 | public: virtual __thiscall mmDashView::~mmDashView(void) | ??1mmDashView@@UAE@XZ
    0x421880 | public: void __thiscall mmDashView::Init(char *,class mmPlayer *) | ?Init@mmDashView@@QAEXPADPAVmmPlayer@@@Z
    0x421C10 | public: virtual void __thiscall mmDashView::Reset(void) | ?Reset@mmDashView@@UAEXXZ
    0x421C20 | public: virtual void __thiscall mmDashView::BeforeSave(void) | ?BeforeSave@mmDashView@@UAEXXZ
    0x421CC0 | public: virtual void __thiscall mmDashView::AfterLoad(void) | ?AfterLoad@mmDashView@@UAEXXZ
    0x421D60 | public: void __thiscall mmDashView::ActivateUntilTransitionIsOver(void) | ?ActivateUntilTransitionIsOver@mmDashView@@QAEXXZ
    0x421D80 | public: void __thiscall mmDashView::Activate(void) | ?Activate@mmDashView@@QAEXXZ
    0x421DA0 | public: void __thiscall mmDashView::Deactivate(void) | ?Deactivate@mmDashView@@QAEXXZ
    0x421DC0 | public: void __thiscall mmDashView::TempDeactivate(void) | ?TempDeactivate@mmDashView@@QAEXXZ
    0x421DD0 | public: virtual void __thiscall mmDashView::Update(void) | ?Update@mmDashView@@UAEXXZ
    0x421F00 | public: virtual void __thiscall mmDashView::Cull(void) | ?Cull@mmDashView@@UAEXXZ
    0x4220F0 | public: __thiscall mmExternalView::mmExternalView(void) | ??0mmExternalView@@QAE@XZ
    0x422170 | public: void __thiscall mmExternalView::Init(class mmPlayer *) | ?Init@mmExternalView@@QAEXPAVmmPlayer@@@Z
    0x4221B0 | public: virtual void __thiscall mmExternalView::ResChange(int,int) | ?ResChange@mmExternalView@@UAEXHH@Z
    0x422300 | public: virtual void __thiscall mmExternalView::Reset(void) | ?Reset@mmExternalView@@UAEXXZ
    0x422310 | public: virtual void __thiscall mmExternalView::Update(void) | ?Update@mmExternalView@@UAEXXZ
    0x422330 | public: void __thiscall mmExternalView::WideFOV(int) | ?WideFOV@mmExternalView@@QAEXH@Z
    0x422340 | public: virtual void __thiscall mmExternalView::Cull(void) | ?Cull@mmExternalView@@UAEXXZ
    0x4224E0 | public: virtual void __thiscall mmExternalView::AddWidgets(class Bank *) | ?AddWidgets@mmExternalView@@UAEXPAVBank@@@Z
    0x4227D0 | public: virtual void __thiscall mmDashView::AddWidgets(class Bank *) | ?AddWidgets@mmDashView@@UAEXPAVBank@@@Z
    0x422BD0 | public: static void __cdecl mmDashView::DeclareFields(void) | ?DeclareFields@mmDashView@@SAXXZ
    0x422EC0 | public: virtual class MetaClass * __thiscall mmDashView::GetClass(void) | ?GetClass@mmDashView@@UAEPAVMetaClass@@XZ
    0x422F00 | public: virtual __thiscall asLinearCS::~asLinearCS(void) | ??1asLinearCS@@UAE@XZ
    0x422F10 | public: virtual __thiscall RadialGauge::~RadialGauge(void) | ??1RadialGauge@@UAE@XZ
    0x422F60 | public: virtual void * __thiscall mmExternalView::`scalar deleting destructor'(unsigned int) | ??_GmmExternalView@@UAEPAXI@Z
    0x422F60 | public: virtual void * __thiscall mmExternalView::`vector deleting destructor'(unsigned int) | ??_EmmExternalView@@UAEPAXI@Z
    0x422F90 | public: virtual void * __thiscall mmDashView::`vector deleting destructor'(unsigned int) | ??_EmmDashView@@UAEPAXI@Z
    0x61AAC0 | const mmDashView::`vftable' | ??_7mmDashView@@6B@
    0x61AB00 | const mmExternalView::`vftable' | ??_7mmExternalView@@6B@
    0x636504 | float MAX_SPEED | ?MAX_SPEED@@3MA
    0x6A72B8 | class MetaClass mmDashViewMetaClass | ?mmDashViewMetaClass@@3VMetaClass@@A
*/

class mmExternalView : public asNode
{
    // const mmExternalView::`vftable' @ 0x61AB00

public:
    // 0x4220F0 | ??0mmExternalView@@QAE@XZ
    mmExternalView();

    // 0x422F60 | ??_EmmExternalView@@UAEPAXI@Z
    // 0x406910 | ??1mmExternalView@@UAE@XZ
    ~mmExternalView() override;

    // 0x4224E0 | ?AddWidgets@mmExternalView@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x422340 | ?Cull@mmExternalView@@UAEXXZ
    void Cull() override;

    // 0x422170 | ?Init@mmExternalView@@QAEXPAVmmPlayer@@@Z
    void Init(class mmPlayer* arg1);

    // 0x4221B0 | ?ResChange@mmExternalView@@UAEXHH@Z
    void ResChange(i32 arg1, i32 arg2) override;

    // 0x422300 | ?Reset@mmExternalView@@UAEXXZ
    void Reset() override;

    // 0x422310 | ?Update@mmExternalView@@UAEXXZ
    void Update() override;

    // 0x422330 | ?WideFOV@mmExternalView@@QAEXH@Z
    void WideFOV(i32 arg1);
};

check_size(mmExternalView, 0x0);

class mmDashView : public asLinearCS
{
    // const mmDashView::`vftable' @ 0x61AAC0

public:
    // 0x4215D0 | ??0mmDashView@@QAE@XZ
    mmDashView();

    // 0x422F90 | ??_EmmDashView@@UAEPAXI@Z
    // 0x421770 | ??1mmDashView@@UAE@XZ
    ~mmDashView() override;

    // 0x421D80 | ?Activate@mmDashView@@QAEXXZ
    void Activate();

    // 0x421D60 | ?ActivateUntilTransitionIsOver@mmDashView@@QAEXXZ
    void ActivateUntilTransitionIsOver();

    // 0x4227D0 | ?AddWidgets@mmDashView@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x421CC0 | ?AfterLoad@mmDashView@@UAEXXZ
    void AfterLoad() override;

    // 0x421C20 | ?BeforeSave@mmDashView@@UAEXXZ
    void BeforeSave() override;

    // 0x421F00 | ?Cull@mmDashView@@UAEXXZ
    void Cull() override;

    // 0x421DA0 | ?Deactivate@mmDashView@@QAEXXZ
    void Deactivate();

    // 0x422EC0 | ?GetClass@mmDashView@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x421880 | ?Init@mmDashView@@QAEXPADPAVmmPlayer@@@Z
    void Init(char* arg1, class mmPlayer* arg2);

    // 0x421C10 | ?Reset@mmDashView@@UAEXXZ
    void Reset() override;

    // 0x421DC0 | ?TempDeactivate@mmDashView@@QAEXXZ
    void TempDeactivate();

    // 0x421DD0 | ?Update@mmDashView@@UAEXXZ
    void Update() override;

    // 0x422BD0 | ?DeclareFields@mmDashView@@SAXXZ
    static void DeclareFields();
};

check_size(mmDashView, 0x880);

// 0x636504 | ?MAX_SPEED@@3MA
inline extern_var(0x236504_Offset, f32, MAX_SPEED);

// 0x6A72B8 | ?mmDashViewMetaClass@@3VMetaClass@@A
inline extern_var(0x2A72B8_Offset, class MetaClass, mmDashViewMetaClass);
