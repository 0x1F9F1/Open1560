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
    mmwidget:toggle

    0x4C0370 | public: __thiscall mmToggle::mmToggle(void) | ??0mmToggle@@QAE@XZ
    0x4C0390 | public: virtual __thiscall mmToggle::~mmToggle(void) | ??1mmToggle@@UAE@XZ
    0x4C03F0 | public: void __thiscall mmToggle::Init(char *,float,float,float,float) | ?Init@mmToggle@@QAEXPADMMMM@Z
    0x4C0490 | private: void __thiscall mmToggle::LoadBitmap(char *) | ?LoadBitmap@mmToggle@@AAEXPAD@Z
    0x4C04E0 | private: void __thiscall mmToggle::SetSize(float,float) | ?SetSize@mmToggle@@AAEXMM@Z
    0x4C0590 | public: virtual void __thiscall mmToggle::Update(void) | ?Update@mmToggle@@UAEXXZ
    0x4C05B0 | public: virtual void __thiscall mmToggle::Cull(void) | ?Cull@mmToggle@@UAEXXZ
    0x4C0630 | public: static void __cdecl mmToggle::DeclareFields(void) | ?DeclareFields@mmToggle@@SAXXZ
    0x4C07A0 | public: virtual class MetaClass * __thiscall mmToggle::GetClass(void) | ?GetClass@mmToggle@@UAEPAVMetaClass@@XZ
    0x4C07B0 | public: virtual void * __thiscall mmToggle::`vector deleting destructor'(unsigned int) | ??_EmmToggle@@UAEPAXI@Z
    0x61F270 | const mmToggle::`vftable' | ??_7mmToggle@@6B@
    0x705D18 | class MetaClass mmToggleMetaClass | ?mmToggleMetaClass@@3VMetaClass@@A
*/

class mmToggle : public asNode
{
    // const mmToggle::`vftable' @ 0x61F270

public:
    // 0x4C0370 | ??0mmToggle@@QAE@XZ
    mmToggle();

    // 0x4C07B0 | ??_EmmToggle@@UAEPAXI@Z
    // 0x4C0390 | ??1mmToggle@@UAE@XZ
    ~mmToggle() override;

    // 0x4C05B0 | ?Cull@mmToggle@@UAEXXZ
    void Cull() override;

    // 0x4C07A0 | ?GetClass@mmToggle@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4C03F0 | ?Init@mmToggle@@QAEXPADMMMM@Z
    void Init(char* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x4C0590 | ?Update@mmToggle@@UAEXXZ
    void Update() override;

    // 0x4C0630 | ?DeclareFields@mmToggle@@SAXXZ
    static void DeclareFields();

private:
    // 0x4C0490 | ?LoadBitmap@mmToggle@@AAEXPAD@Z
    void LoadBitmap(char* arg1);

    // 0x4C04E0 | ?SetSize@mmToggle@@AAEXMM@Z
    void SetSize(f32 arg1, f32 arg2);
};

check_size(mmToggle, 0x38);

// 0x705D18 | ?mmToggleMetaClass@@3VMetaClass@@A
inline extern_var(0x305D18_Offset, class MetaClass, mmToggleMetaClass);
