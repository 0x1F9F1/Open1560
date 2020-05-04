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

#include "node.h"

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

class asLamp : public asNode
{
    // const asLamp::`vftable' @ 0x620B80

public:
    // 0x526000 | ??0asLamp@@QAE@XZ
    asLamp();

    // 0x4B1C40 | ??_EasLamp@@UAEPAXI@Z
    // 0x5260C0 | ??1asLamp@@UAE@XZ
    ~asLamp() override;

    // 0x526310 | ?AddWidgets@asLamp@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x526290 | ?Cull@asLamp@@UAEXXZ
    void Cull() override;

    // 0x5262E0 | ?FileIO@asLamp@@QAEXPAVMiniParser@@@Z
    void FileIO(class MiniParser* arg1);

    // 0x5267E0 | ?GetClass@asLamp@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x526130 | ?SetColor@asLamp@@QAEXABVVector3@@M@Z
    void SetColor(class Vector3 const& arg1, f32 arg2);

    // 0x526170 | ?SetDistant@asLamp@@QAEXXZ
    void SetDistant();

    // 0x526180 | ?SetPoint@asLamp@@QAEXXZ
    void SetPoint();

    // 0x526190 | ?Update@asLamp@@UAEXXZ
    void Update() override;

    // 0x526680 | ?DeclareFields@asLamp@@SAXXZ
    static void DeclareFields();

private:
    // 0x5262F0 | ?Regen@asLamp@@AAEXXZ
    void Regen();
};

check_size(asLamp, 0x30);

// 0x790900 | ?asLampMetaClass@@3VMetaClass@@A
inline extern_var(0x390900_Offset, class MetaClass, asLampMetaClass);
