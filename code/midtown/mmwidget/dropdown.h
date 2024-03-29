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
    mmwidget:dropdown

    0x4C0810 | public: __thiscall mmDropDown::mmDropDown(void) | ??0mmDropDown@@QAE@XZ
    0x4C0870 | public: virtual __thiscall mmDropDown::~mmDropDown(void) | ??1mmDropDown@@UAE@XZ
    0x4C08F0 | public: void __thiscall mmDropDown::Init(class asCamera *,void *,float,float,float,float,class string,int) | ?Init@mmDropDown@@QAEXPAVasCamera@@PAXMMMMVstring@@H@Z
    0x4C09F0 | public: void __thiscall mmDropDown::InitString(class string) | ?InitString@mmDropDown@@QAEXVstring@@@Z
    0x4C0C70 | private: void __thiscall mmDropDown::SetString(class string) | ?SetString@mmDropDown@@AAEXVstring@@@Z
    0x4C0D60 | public: void __thiscall mmDropDown::GetCurrentString(char *,int) | ?GetCurrentString@mmDropDown@@QAEXPADH@Z
    0x4C0DB0 | public: void __thiscall mmDropDown::SetDisabledColors(void) | ?SetDisabledColors@mmDropDown@@QAEXXZ
    0x4C0E30 | public: int __thiscall mmDropDown::FindFirstEnabled(void) | ?FindFirstEnabled@mmDropDown@@QAEHXZ
    0x4C0E60 | public: void __thiscall mmDropDown::SetHighlight(int) | ?SetHighlight@mmDropDown@@QAEXH@Z
    0x4C0EC0 | public: int __thiscall mmDropDown::GetHit(float,float) | ?GetHit@mmDropDown@@QAEHMM@Z
    0x4C0F20 | public: virtual void __thiscall mmDropDown::Update(void) | ?Update@mmDropDown@@UAEXXZ
    0x4C0F30 | public: static void __cdecl mmDropDown::DeclareFields(void) | ?DeclareFields@mmDropDown@@SAXXZ
    0x4C10A0 | public: virtual class MetaClass * __thiscall mmDropDown::GetClass(void) | ?GetClass@mmDropDown@@UAEPAVMetaClass@@XZ
    0x4C10B0 | public: virtual void * __thiscall mmDropDown::`vector deleting destructor'(unsigned int) | ??_EmmDropDown@@UAEPAXI@Z
    0x61F2B8 | const mmDropDown::`vftable' | ??_7mmDropDown@@6B@
    0x705D40 | class MetaClass mmDropDownMetaClass | ?mmDropDownMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"
#include "data7/str.h"

class asCamera;
class mmTextNode;

class mmDropDown final : public asNode
{
public:
    // ??0mmDropDown@@QAE@XZ
    ARTS_EXPORT mmDropDown();

    // ??_EmmDropDown@@UAEPAXI@Z
    // ??1mmDropDown@@UAE@XZ
    ARTS_EXPORT ~mmDropDown() override;

    // ?FindFirstEnabled@mmDropDown@@QAEHXZ
    ARTS_IMPORT i32 FindFirstEnabled();

    // ?GetCurrentString@mmDropDown@@QAEXPADH@Z
    ARTS_IMPORT void GetCurrentString(char* arg1, i32 arg2);

    // ?GetHit@mmDropDown@@QAEHMM@Z
    ARTS_IMPORT i32 GetHit(f32 arg1, f32 arg2);

    // ?Init@mmDropDown@@QAEXPAVasCamera@@PAXMMMMVstring@@H@Z
    ARTS_IMPORT void Init(asCamera* arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, string arg7, i32 arg8);

    // ?InitString@mmDropDown@@QAEXVstring@@@Z
    ARTS_EXPORT void InitString(string values);

    // ?SetDisabledColors@mmDropDown@@QAEXXZ
    ARTS_IMPORT void SetDisabledColors();

    // ?SetHighlight@mmDropDown@@QAEXH@Z
    ARTS_EXPORT void SetHighlight(i32 index);

    // ?Update@mmDropDown@@UAEXXZ
    ARTS_IMPORT void Update() override;

    VIRTUAL_META_DECLARE;

private:
    // ?SetString@mmDropDown@@AAEXVstring@@@Z
    ARTS_IMPORT void SetString(string arg1);

    Ptr<mmTextNode[]> ValueNodes;
    Ptr<u32[]> DropIndex;
    i32 Highlighted {-1};
    i32 field_2C {};
    i32 Enabled {};
    i32 DisabledMask {};
    asCamera* Camera {};
    void* Font {};
    f32 Y {};
    f32 Height {};
    f32 X {};
    f32 Width {};
    f32 DropHeight {};
    f32 Bottom {};
    i32 NumValues {};
    string ValuesString {};
    char field_64[100];
};

check_size(mmDropDown, 0xC8);
