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
    mmwidget:toggle2

    0x4BFF10 | public: __thiscall mmToggle2::mmToggle2(void) | ??0mmToggle2@@QAE@XZ
    0x4BFF30 | public: virtual __thiscall mmToggle2::~mmToggle2(void) | ??1mmToggle2@@UAE@XZ
    0x4BFF90 | public: void __thiscall mmToggle2::Init(char *,float,float,int *) | ?Init@mmToggle2@@QAEXPADMMPAH@Z
    0x4BFFC0 | private: void __thiscall mmToggle2::LoadBitmap(char *) | ?LoadBitmap@mmToggle2@@AAEXPAD@Z
    0x4C0020 | public: void __thiscall mmToggle2::SetPosition(float,float) | ?SetPosition@mmToggle2@@QAEXMM@Z
    0x4C00C0 | public: virtual void __thiscall mmToggle2::Update(void) | ?Update@mmToggle2@@UAEXXZ
    0x4C00E0 | public: virtual void __thiscall mmToggle2::Cull(void) | ?Cull@mmToggle2@@UAEXXZ
    0x4C01A0 | public: static void __cdecl mmToggle2::DeclareFields(void) | ?DeclareFields@mmToggle2@@SAXXZ
    0x4C0300 | public: virtual class MetaClass * __thiscall mmToggle2::GetClass(void) | ?GetClass@mmToggle2@@UAEPAVMetaClass@@XZ
    0x4C0310 | public: virtual void * __thiscall mmToggle2::`vector deleting destructor'(unsigned int) | ??_EmmToggle2@@UAEPAXI@Z
    0x61F228 | const mmToggle2::`vftable' | ??_7mmToggle2@@6B@
    0x705CF0 | class MetaClass mmToggle2MetaClass | ?mmToggle2MetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmToggle2 : public asNode
{
    // const mmToggle2::`vftable' @ 0x61F228

public:
    // 0x4BFF10 | ??0mmToggle2@@QAE@XZ
    mmToggle2();

    // 0x4C0310 | ??_EmmToggle2@@UAEPAXI@Z
    // 0x4BFF30 | ??1mmToggle2@@UAE@XZ
    ~mmToggle2() override;

    // 0x4C00E0 | ?Cull@mmToggle2@@UAEXXZ
    void Cull() override;

    // 0x4C0300 | ?GetClass@mmToggle2@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4BFF90 | ?Init@mmToggle2@@QAEXPADMMPAH@Z
    void Init(char* arg1, f32 arg2, f32 arg3, i32* arg4);

    // 0x4C0020 | ?SetPosition@mmToggle2@@QAEXMM@Z
    void SetPosition(f32 arg1, f32 arg2);

    // 0x4C00C0 | ?Update@mmToggle2@@UAEXXZ
    void Update() override;

    // 0x4C01A0 | ?DeclareFields@mmToggle2@@SAXXZ
    static void DeclareFields();

private:
    // 0x4BFFC0 | ?LoadBitmap@mmToggle2@@AAEXPAD@Z
    void LoadBitmap(char* arg1);
};

check_size(mmToggle2, 0x40);

// 0x705CF0 | ?mmToggle2MetaClass@@3VMetaClass@@A
inline extern_var(0x305CF0_Offset, class MetaClass, mmToggle2MetaClass);
