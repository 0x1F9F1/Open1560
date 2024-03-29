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
    mmcar:force

    0x480BE0 | public: __thiscall mmForce::mmForce(void) | ??0mmForce@@QAE@XZ
    0x480C00 | public: virtual void __thiscall mmForce::Update(void) | ?Update@mmForce@@UAEXXZ
    0x480E10 | public: virtual void __thiscall mmForce::AddWidgets(class Bank *) | ?AddWidgets@mmForce@@UAEXPAVBank@@@Z
    0x480E20 | public: static void __cdecl mmForce::DeclareFields(void) | ?DeclareFields@mmForce@@SAXXZ
    0x480F80 | public: virtual class MetaClass * __thiscall mmForce::GetClass(void) | ?GetClass@mmForce@@UAEPAVMetaClass@@XZ
    0x480F90 | public: virtual void * __thiscall mmForce::`vector deleting destructor'(unsigned int) | ??_EmmForce@@UAEPAXI@Z
    0x61C850 | const mmForce::`vftable' | ??_7mmForce@@6B@
    0x63C9EC | float YDownForceMinHeight | ?YDownForceMinHeight@@3MA
    0x63C9F0 | float YDownForceMaxHeight | ?YDownForceMaxHeight@@3MA
    0x63C9F4 | float YDownForceMin | ?YDownForceMin@@3MA
    0x63C9F8 | float YDownForceMax | ?YDownForceMax@@3MA
    0x6A8148 | class MetaClass mmForceMetaClass | ?mmForceMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmForce final : public asNode
{
public:
    // ??0mmForce@@QAE@XZ
    ARTS_IMPORT mmForce();

    // ??_EmmForce@@UAEPAXI@Z
    // ??1mmForce@@UAE@XZ | inline
    ARTS_IMPORT ~mmForce() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmForce@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@mmForce@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Update@mmForce@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmForce@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xC];
};

check_size(mmForce, 0x2C);

// ?YDownForceMax@@3MA
ARTS_IMPORT extern f32 YDownForceMax;

// ?YDownForceMaxHeight@@3MA
ARTS_IMPORT extern f32 YDownForceMaxHeight;

// ?YDownForceMin@@3MA
ARTS_IMPORT extern f32 YDownForceMin;

// ?YDownForceMinHeight@@3MA
ARTS_IMPORT extern f32 YDownForceMinHeight;
