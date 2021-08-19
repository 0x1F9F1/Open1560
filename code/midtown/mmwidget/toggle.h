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

#include "arts7/node.h"

class mmToggle final : public asNode
{
public:
    // ??0mmToggle@@QAE@XZ
    ARTS_IMPORT mmToggle();

    // ??_EmmToggle@@UAEPAXI@Z
    // ??1mmToggle@@UAE@XZ
    ARTS_IMPORT ~mmToggle() override;

    // ?Cull@mmToggle@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@mmToggle@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Init@mmToggle@@QAEXPADMMMM@Z
    ARTS_IMPORT void Init(char* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?Update@mmToggle@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmToggle@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?LoadBitmap@mmToggle@@AAEXPAD@Z
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // ?SetSize@mmToggle@@AAEXMM@Z
    ARTS_IMPORT void SetSize(f32 arg1, f32 arg2);

    u8 gap20[0x18];
};

check_size(mmToggle, 0x38);
