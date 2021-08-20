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

#include "widget.h"

class agiBitmap;

class UIBMLabel final : public uiWidget
{
public:
    // ??0UIBMLabel@@QAE@XZ
    ARTS_IMPORT UIBMLabel();

    // ??_EUIBMLabel@@UAEPAXI@Z
    // ??1UIBMLabel@@UAE@XZ
    ARTS_IMPORT ~UIBMLabel() override;

    // ?CreateDummyBitmap@UIBMLabel@@QAEPAVagiBitmap@@XZ
    ARTS_IMPORT agiBitmap* CreateDummyBitmap();

    // ?Cull@UIBMLabel@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@UIBMLabel@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@UIBMLabel@@QAEXPAVstring@@MMPAH@Z
    ARTS_IMPORT void Init(string* arg1, f32 arg2, f32 arg3, i32* arg4);

    // ?SetBitmapName@UIBMLabel@@QAEXPAVstring@@@Z
    ARTS_IMPORT void SetBitmapName(string* arg1);

    // ?Update@UIBMLabel@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@UIBMLabel@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?LoadBitmap@UIBMLabel@@AAEXXZ
    ARTS_IMPORT void LoadBitmap();

    u8 gap74[0x2C];
};

check_size(UIBMLabel, 0xA0);
