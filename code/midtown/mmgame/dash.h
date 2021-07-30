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

#include "arts7/linear.h"
#include "arts7/node.h"

class mmExternalView final : public asNode
{
    // const mmExternalView::`vftable' @ 0x61AB00

public:
    // 0x4220F0 | ??0mmExternalView@@QAE@XZ
    ARTS_IMPORT mmExternalView();

    // 0x422F60 | ??_EmmExternalView@@UAEPAXI@Z
    // 0x422F60 | ??_GmmExternalView@@UAEPAXI@Z
    // 0x406910 | ??1mmExternalView@@UAE@XZ | inline
    ARTS_IMPORT ~mmExternalView() override;

#ifdef ARTS_DEV_BUILD
    // 0x4224E0 | ?AddWidgets@mmExternalView@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // 0x422340 | ?Cull@mmExternalView@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x422170 | ?Init@mmExternalView@@QAEXPAVmmPlayer@@@Z
    ARTS_IMPORT void Init(class mmPlayer* arg1);

    // 0x4221B0 | ?ResChange@mmExternalView@@UAEXHH@Z
    ARTS_IMPORT void ResChange(i32 arg1, i32 arg2) override;

    // 0x422300 | ?Reset@mmExternalView@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // 0x422310 | ?Update@mmExternalView@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x422330 | ?WideFOV@mmExternalView@@QAEXH@Z
    ARTS_EXPORT void WideFOV(i32 arg1);

    u8 gap20[0xEC];
};

check_size(mmExternalView, 0x10C);

class mmDashView final : public asLinearCS
{
    // const mmDashView::`vftable' @ 0x61AAC0

public:
    // 0x4215D0 | ??0mmDashView@@QAE@XZ
    ARTS_IMPORT mmDashView();

    // 0x422F90 | ??_EmmDashView@@UAEPAXI@Z
    // 0x421770 | ??1mmDashView@@UAE@XZ
    ARTS_IMPORT ~mmDashView() override;

    // 0x421D80 | ?Activate@mmDashView@@QAEXXZ
    ARTS_IMPORT void Activate();

    // 0x421D60 | ?ActivateUntilTransitionIsOver@mmDashView@@QAEXXZ
    ARTS_IMPORT void ActivateUntilTransitionIsOver();

#ifdef ARTS_DEV_BUILD
    // 0x4227D0 | ?AddWidgets@mmDashView@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // 0x421CC0 | ?AfterLoad@mmDashView@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // 0x421C20 | ?BeforeSave@mmDashView@@UAEXXZ
    ARTS_IMPORT void BeforeSave() override;

    // 0x421F00 | ?Cull@mmDashView@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x421DA0 | ?Deactivate@mmDashView@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // 0x422EC0 | ?GetClass@mmDashView@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x421880 | ?Init@mmDashView@@QAEXPADPAVmmPlayer@@@Z
    ARTS_IMPORT void Init(char* arg1, class mmPlayer* arg2);

    // 0x421C10 | ?Reset@mmDashView@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x421DC0 | ?TempDeactivate@mmDashView@@QAEXXZ | unused
    ARTS_IMPORT void TempDeactivate();

    // 0x421DD0 | ?Update@mmDashView@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x422BD0 | ?DeclareFields@mmDashView@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x7F8];
};

check_size(mmDashView, 0x880);

// 0x636504 | ?MAX_SPEED@@3MA
ARTS_IMPORT extern f32 MAX_SPEED;

// 0x6A72B8 | ?mmDashViewMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmDashViewMetaClass;
