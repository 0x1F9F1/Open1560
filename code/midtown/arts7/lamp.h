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
    arts7:lamp

    0x526000 | public: __thiscall asLamp::asLamp(void) | ??0asLamp@@QAE@XZ
    0x5260C0 | public: virtual __thiscall asLamp::~asLamp(void) | ??1asLamp@@UAE@XZ
    0x526130 | public: void __thiscall asLamp::SetColor(class Vector3 const &,float) | ?SetColor@asLamp@@QAEXABVVector3@@M@Z
    0x526170 | public: void __thiscall asLamp::SetDistant(void) | ?SetDistant@asLamp@@QAEXXZ
    0x526180 | public: void __thiscall asLamp::SetPoint(void) | ?SetPoint@asLamp@@QAEXXZ
    0x526190 | public: virtual void __thiscall asLamp::Update(void) | ?Update@asLamp@@UAEXXZ
    0x526290 | public: virtual void __thiscall asLamp::Cull(void) | ?Cull@asLamp@@UAEXXZ
    0x5262E0 | public: void __thiscall asLamp::FileIO(class MiniParser *) | ?FileIO@asLamp@@QAEXPAVMiniParser@@@Z
    0x5262F0 | private: void __thiscall asLamp::Regen(void) | ?Regen@asLamp@@AAEXXZ
    0x526310 | public: virtual void __thiscall asLamp::AddWidgets(class Bank *) | ?AddWidgets@asLamp@@UAEXPAVBank@@@Z
    0x526680 | public: static void __cdecl asLamp::DeclareFields(void) | ?DeclareFields@asLamp@@SAXXZ
    0x5267E0 | public: virtual class MetaClass * __thiscall asLamp::GetClass(void) | ?GetClass@asLamp@@UAEPAVMetaClass@@XZ
    0x620B80 | const asLamp::`vftable' | ??_7asLamp@@6B@
    0x790900 | class MetaClass asLampMetaClass | ?asLampMetaClass@@3VMetaClass@@A
*/

#include "node.h"

class asLamp final : public asNode
{
public:
    // ??0asLamp@@QAE@XZ
    ARTS_IMPORT asLamp();

    // ??_EasLamp@@UAEPAXI@Z
    // ??1asLamp@@UAE@XZ
    ARTS_IMPORT ~asLamp() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asLamp@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?Cull@asLamp@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?FileIO@asLamp@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(class MiniParser* arg1);

    // ?GetClass@asLamp@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?SetColor@asLamp@@QAEXABVVector3@@M@Z
    ARTS_IMPORT void SetColor(class Vector3 const& arg1, f32 arg2);

    // ?SetDistant@asLamp@@QAEXXZ
    ARTS_IMPORT void SetDistant();

    // ?SetPoint@asLamp@@QAEXXZ | unused
    ARTS_IMPORT void SetPoint();

    // ?Update@asLamp@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@asLamp@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?Regen@asLamp@@AAEXXZ
    ARTS_IMPORT void Regen();

    u8 gap20[0x10];
};

check_size(asLamp, 0x30);

// ?asLampMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asLampMetaClass;
