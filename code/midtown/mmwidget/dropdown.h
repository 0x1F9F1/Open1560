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

#include "arts7/node.h"

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

class mmDropDown : public asNode
{
    // const mmDropDown::`vftable' @ 0x61F2B8

public:
    // 0x4C0810 | ??0mmDropDown@@QAE@XZ
    mmDropDown();

    // 0x4C10B0 | ??_EmmDropDown@@UAEPAXI@Z
    // 0x4C0870 | ??1mmDropDown@@UAE@XZ
    ~mmDropDown() override;

    // 0x4C0E30 | ?FindFirstEnabled@mmDropDown@@QAEHXZ
    i32 FindFirstEnabled();

    // 0x4C10A0 | ?GetClass@mmDropDown@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4C0D60 | ?GetCurrentString@mmDropDown@@QAEXPADH@Z
    void GetCurrentString(char* arg1, i32 arg2);

    // 0x4C0EC0 | ?GetHit@mmDropDown@@QAEHMM@Z
    i32 GetHit(f32 arg1, f32 arg2);

    // 0x4C08F0 | ?Init@mmDropDown@@QAEXPAVasCamera@@PAXMMMMVstring@@H@Z
    void Init(class asCamera* arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class string arg7, i32 arg8);

    // 0x4C09F0 | ?InitString@mmDropDown@@QAEXVstring@@@Z
    void InitString(class string arg1);

    // 0x4C0DB0 | ?SetDisabledColors@mmDropDown@@QAEXXZ
    void SetDisabledColors();

    // 0x4C0E60 | ?SetHighlight@mmDropDown@@QAEXH@Z
    void SetHighlight(i32 arg1);

    // 0x4C0F20 | ?Update@mmDropDown@@UAEXXZ
    void Update() override;

    // 0x4C0F30 | ?DeclareFields@mmDropDown@@SAXXZ
    static void DeclareFields();

private:
    // 0x4C0C70 | ?SetString@mmDropDown@@AAEXVstring@@@Z
    void SetString(class string arg1);
};

check_size(mmDropDown, 0xC8);

// 0x705D40 | ?mmDropDownMetaClass@@3VMetaClass@@A
inline extern_var(0x305D40_Offset, class MetaClass, mmDropDownMetaClass);
