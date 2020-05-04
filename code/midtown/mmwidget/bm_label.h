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

#include "textfield.h"

/*
    mmwidget:bm_label

    0x4B4280 | public: __thiscall UIBMLabel::UIBMLabel(void) | ??0UIBMLabel@@QAE@XZ
    0x4B42F0 | public: virtual __thiscall UIBMLabel::~UIBMLabel(void) | ??1UIBMLabel@@UAE@XZ
    0x4B4360 | public: void __thiscall UIBMLabel::Init(class string *,float,float,int *) | ?Init@UIBMLabel@@QAEXPAVstring@@MMPAH@Z
    0x4B4440 | public: void __thiscall UIBMLabel::SetBitmapName(class string *) | ?SetBitmapName@UIBMLabel@@QAEXPAVstring@@@Z
    0x4B44E0 | private: void __thiscall UIBMLabel::LoadBitmap(void) | ?LoadBitmap@UIBMLabel@@AAEXXZ
    0x4B45C0 | public: class agiBitmap * __thiscall UIBMLabel::CreateDummyBitmap(void) | ?CreateDummyBitmap@UIBMLabel@@QAEPAVagiBitmap@@XZ
    0x4B4610 | public: virtual void __thiscall UIBMLabel::Update(void) | ?Update@UIBMLabel@@UAEXXZ
    0x4B4640 | public: virtual void __thiscall UIBMLabel::Cull(void) | ?Cull@UIBMLabel@@UAEXXZ
    0x4B4680 | public: static void __cdecl UIBMLabel::DeclareFields(void) | ?DeclareFields@UIBMLabel@@SAXXZ
    0x4B47F0 | public: virtual class MetaClass * __thiscall UIBMLabel::GetClass(void) | ?GetClass@UIBMLabel@@UAEPAVMetaClass@@XZ
    0x4B4800 | public: virtual void * __thiscall UIBMLabel::`vector deleting destructor'(unsigned int) | ??_EUIBMLabel@@UAEPAXI@Z
    0x61E608 | const UIBMLabel::`vftable' | ??_7UIBMLabel@@6B@
    0x7059A0 | class MetaClass UIBMLabelMetaClass | ?UIBMLabelMetaClass@@3VMetaClass@@A
*/

class UIBMLabel : public uiWidget
{
    // const UIBMLabel::`vftable' @ 0x61E608

public:
    // 0x4B4280 | ??0UIBMLabel@@QAE@XZ
    UIBMLabel();

    // 0x4B4800 | ??_EUIBMLabel@@UAEPAXI@Z
    // 0x4B42F0 | ??1UIBMLabel@@UAE@XZ
    ~UIBMLabel() override;

    // 0x4B45C0 | ?CreateDummyBitmap@UIBMLabel@@QAEPAVagiBitmap@@XZ
    class agiBitmap* CreateDummyBitmap();

    // 0x4B4640 | ?Cull@UIBMLabel@@UAEXXZ
    void Cull() override;

    // 0x4B47F0 | ?GetClass@UIBMLabel@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4B4360 | ?Init@UIBMLabel@@QAEXPAVstring@@MMPAH@Z
    void Init(class string* arg1, f32 arg2, f32 arg3, i32* arg4);

    // 0x4B4440 | ?SetBitmapName@UIBMLabel@@QAEXPAVstring@@@Z
    void SetBitmapName(class string* arg1);

    // 0x4B4610 | ?Update@UIBMLabel@@UAEXXZ
    void Update() override;

    // 0x4B4680 | ?DeclareFields@UIBMLabel@@SAXXZ
    static void DeclareFields();

private:
    // 0x4B44E0 | ?LoadBitmap@UIBMLabel@@AAEXXZ
    void LoadBitmap();
};

check_size(UIBMLabel, 0xA0);

// 0x7059A0 | ?UIBMLabelMetaClass@@3VMetaClass@@A
inline extern_var(0x3059A0_Offset, class MetaClass, UIBMLabelMetaClass);
