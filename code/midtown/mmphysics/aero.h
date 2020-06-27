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
    mmphysics:aero

    0x4DFC10 | public: __thiscall asAero::asAero(void) | ??0asAero@@QAE@XZ
    0x4DFC70 | public: virtual void __thiscall asAero::Update(void) | ?Update@asAero@@UAEXXZ
    0x4E0130 | public: void __thiscall asAero::Load(class Stream *) | ?Load@asAero@@QAEXPAVStream@@@Z
    0x4E0200 | public: void __thiscall asAero::Save(class Stream *) | ?Save@asAero@@QAEXPAVStream@@@Z
    0x4E0330 | public: virtual void __thiscall asAero::AddWidgets(class Bank *) | ?AddWidgets@asAero@@UAEXPAVBank@@@Z
    0x4E0490 | public: static void __cdecl asAero::DeclareFields(void) | ?DeclareFields@asAero@@SAXXZ
    0x4E0670 | public: virtual class MetaClass * __thiscall asAero::GetClass(void) | ?GetClass@asAero@@UAEPAVMetaClass@@XZ
    0x4E0680 | public: virtual void * __thiscall asAero::`vector deleting destructor'(unsigned int) | ??_EasAero@@UAEPAXI@Z
    0x61FBF8 | const asAero::`vftable' | ??_7asAero@@6B@
    0x7191F8 | class MetaClass asAeroMetaClass | ?asAeroMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class asAero : public asNode
{
    // const asAero::`vftable' @ 0x61FBF8

public:
    // 0x4DFC10 | ??0asAero@@QAE@XZ
    ARTS_IMPORT asAero();

    // 0x4E0680 | ??_EasAero@@UAEPAXI@Z
    // 0x470320 | ??1asAero@@UAE@XZ | inline
    ARTS_IMPORT ~asAero() override = default;

    // 0x4E0330 | ?AddWidgets@asAero@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4E0670 | ?GetClass@asAero@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4E0130 | ?Load@asAero@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Load(class Stream* arg1);

    // 0x4E0200 | ?Save@asAero@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Save(class Stream* arg1);

    // 0x4DFC70 | ?Update@asAero@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4E0490 | ?DeclareFields@asAero@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x54];
};

check_size(asAero, 0x74);

// 0x7191F8 | ?asAeroMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asAeroMetaClass;
