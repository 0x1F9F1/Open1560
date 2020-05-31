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
    mmwidget:bm_button

    0x4B60A0 | public: __thiscall UIBMButton::UIBMButton(void) | ??0UIBMButton@@QAE@XZ
    0x4B6140 | public: virtual __thiscall UIBMButton::~UIBMButton(void) | ??1UIBMButton@@UAE@XZ
    0x4B61C0 | public: void __thiscall UIBMButton::Init(char *,float,float,int,int,int *,int,int,struct LocString *,class Callback,class Callback) | ?Init@UIBMButton@@QAEXPADMMHHPAHHHPAULocString@@VCallback@@3@Z
    0x4B6450 | public: void __thiscall UIBMButton::LoadBitmap(char *) | ?LoadBitmap@UIBMButton@@QAEXPAD@Z
    0x4B64C0 | public: int __thiscall UIBMButton::GetDiv(void) | ?GetDiv@UIBMButton@@QAEHXZ
    0x4B64F0 | public: class agiBitmap * __thiscall UIBMButton::CreateDummyBitmap(void) | ?CreateDummyBitmap@UIBMButton@@QAEPAVagiBitmap@@XZ
    0x4B6550 | private: void __thiscall UIBMButton::GetSize(void) | ?GetSize@UIBMButton@@AAEXXZ
    0x4B6580 | public: virtual void __thiscall UIBMButton::SetPosition(float,float) | ?SetPosition@UIBMButton@@UAEXMM@Z
    0x4B66F0 | public: void __thiscall UIBMButton::GetHitArea(float &,float &) | ?GetHitArea@UIBMButton@@QAEXAAM0@Z
    0x4B6750 | public: void __thiscall UIBMButton::DoToggle(void) | ?DoToggle@UIBMButton@@QAEXXZ
    0x4B6810 | public: void __thiscall UIBMButton::Kill(void) | ?Kill@UIBMButton@@QAEXXZ
    0x4B6830 | public: void __thiscall UIBMButton::Unkill(void) | ?Unkill@UIBMButton@@QAEXXZ
    0x4B6870 | public: virtual void __thiscall UIBMButton::Switch(int) | ?Switch@UIBMButton@@UAEXH@Z
    0x4B69A0 | public: virtual void __thiscall UIBMButton::Action(union eqEvent) | ?Action@UIBMButton@@UAEXTeqEvent@@@Z
    0x4B6A50 | public: void __thiscall UIBMButton::MexOff(void) | ?MexOff@UIBMButton@@QAEXXZ
    0x4B6A60 | public: void __thiscall UIBMButton::MexOn(void) | ?MexOn@UIBMButton@@QAEXXZ
    0x4B6AA0 | public: void __thiscall UIBMButton::MexToggle(void) | ?MexToggle@UIBMButton@@QAEXXZ
    0x4B6AD0 | public: virtual void __thiscall UIBMButton::Update(void) | ?Update@UIBMButton@@UAEXXZ
    0x4B6C60 | public: virtual char * __thiscall UIBMButton::ReturnDescription(void) | ?ReturnDescription@UIBMButton@@UAEPADXZ
    0x4B6D10 | public: virtual float __thiscall UIBMButton::GetScreenHeight(void) | ?GetScreenHeight@UIBMButton@@UAEMXZ
    0x4B6D20 | public: virtual void __thiscall UIBMButton::Cull(void) | ?Cull@UIBMButton@@UAEXXZ
    0x4B6ED0 | private: static void __cdecl UIBMButton::AllocateSounds(void) | ?AllocateSounds@UIBMButton@@CAXXZ
    0x4B70C0 | private: void __thiscall UIBMButton::PlaySound(void) | ?PlaySound@UIBMButton@@AAEXXZ
    0x4B70F0 | public: static void __cdecl UIBMButton::DeclareFields(void) | ?DeclareFields@UIBMButton@@SAXXZ
    0x4B7260 | public: virtual class MetaClass * __thiscall UIBMButton::GetClass(void) | ?GetClass@UIBMButton@@UAEPAVMetaClass@@XZ
    0x4B7270 | public: virtual void __thiscall UIBMButton::Enable(void) | ?Enable@UIBMButton@@UAEXXZ
    0x4B7290 | public: virtual void __thiscall UIBMButton::Disable(void) | ?Disable@UIBMButton@@UAEXXZ
    0x4B72B0 | public: virtual void * __thiscall UIBMButton::`vector deleting destructor'(unsigned int) | ??_EUIBMButton@@UAEPAXI@Z
    0x61E878 | const UIBMButton::`vftable' | ??_7UIBMButton@@6B@
    0x7059D0 | class MetaClass UIBMButtonMetaClass | ?UIBMButtonMetaClass@@3VMetaClass@@A
    0x705A08 | private: static class AudSound * UIBMButton::s_pSound | ?s_pSound@UIBMButton@@0PAVAudSound@@A
*/

#include "widget.h"

class UIBMButton : public uiWidget
{
    // const UIBMButton::`vftable' @ 0x61E878

public:
    // 0x4B60A0 | ??0UIBMButton@@QAE@XZ
    UIBMButton();

    // 0x4B72B0 | ??_EUIBMButton@@UAEPAXI@Z
    // 0x4B6140 | ??1UIBMButton@@UAE@XZ
    ~UIBMButton() override;

    // 0x4B69A0 | ?Action@UIBMButton@@UAEXTeqEvent@@@Z
    void Action(union eqEvent arg1) override;

    // 0x4B64F0 | ?CreateDummyBitmap@UIBMButton@@QAEPAVagiBitmap@@XZ
    class agiBitmap* CreateDummyBitmap();

    // 0x4B6D20 | ?Cull@UIBMButton@@UAEXXZ
    void Cull() override;

    // 0x4B7290 | ?Disable@UIBMButton@@UAEXXZ | inline
    void Disable() override;

    // 0x4B6750 | ?DoToggle@UIBMButton@@QAEXXZ
    void DoToggle();

    // 0x4B7270 | ?Enable@UIBMButton@@UAEXXZ | inline
    void Enable() override;

    // 0x4B7260 | ?GetClass@UIBMButton@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4B64C0 | ?GetDiv@UIBMButton@@QAEHXZ
    i32 GetDiv();

    // 0x4B66F0 | ?GetHitArea@UIBMButton@@QAEXAAM0@Z
    void GetHitArea(f32& arg1, f32& arg2);

    // 0x4B6D10 | ?GetScreenHeight@UIBMButton@@UAEMXZ
    f32 GetScreenHeight() override;

    // 0x4B61C0 | ?Init@UIBMButton@@QAEXPADMMHHPAHHHPAULocString@@VCallback@@3@Z
    void Init(char* arg1, f32 arg2, f32 arg3, i32 arg4, i32 arg5, i32* arg6, i32 arg7, i32 arg8, struct LocString* arg9,
        class Callback arg10, class Callback arg11);

    // 0x4B6810 | ?Kill@UIBMButton@@QAEXXZ
    void Kill();

    // 0x4B6450 | ?LoadBitmap@UIBMButton@@QAEXPAD@Z
    void LoadBitmap(char* arg1);

    // 0x4B6A50 | ?MexOff@UIBMButton@@QAEXXZ
    void MexOff();

    // 0x4B6A60 | ?MexOn@UIBMButton@@QAEXXZ
    void MexOn();

    // 0x4B6AA0 | ?MexToggle@UIBMButton@@QAEXXZ | unused
    void MexToggle();

    // 0x4B6C60 | ?ReturnDescription@UIBMButton@@UAEPADXZ
    char* ReturnDescription() override;

    // 0x4B6580 | ?SetPosition@UIBMButton@@UAEXMM@Z
    void SetPosition(f32 arg1, f32 arg2) override;

    // 0x4B6870 | ?Switch@UIBMButton@@UAEXH@Z
    void Switch(i32 arg1) override;

    // 0x4B6830 | ?Unkill@UIBMButton@@QAEXXZ
    void Unkill();

    // 0x4B6AD0 | ?Update@UIBMButton@@UAEXXZ
    void Update() override;

    // 0x4B70F0 | ?DeclareFields@UIBMButton@@SAXXZ
    static void DeclareFields();

private:
    // 0x4B6550 | ?GetSize@UIBMButton@@AAEXXZ
    void GetSize();

    // 0x4B70C0 | ?PlaySound@UIBMButton@@AAEXXZ
    void PlaySound();

    // 0x4B6ED0 | ?AllocateSounds@UIBMButton@@CAXXZ
    static void AllocateSounds();

    // 0x705A08 | ?s_pSound@UIBMButton@@0PAVAudSound@@A
    static inline extern_var(0x705A08, class AudSound*, s_pSound);
};

check_size(UIBMButton, 0xF0);

// 0x7059D0 | ?UIBMButtonMetaClass@@3VMetaClass@@A
inline extern_var(0x7059D0, class MetaClass, UIBMButtonMetaClass);
