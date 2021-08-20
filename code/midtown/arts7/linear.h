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
    arts7:linear

    0x525AB0 | public: __thiscall asLinearCS::asLinearCS(void) | ??0asLinearCS@@QAE@XZ
    0x525B20 | public: virtual void __thiscall asLinearCS::Update(void) | ?Update@asLinearCS@@UAEXXZ
    0x525C00 | public: virtual void __thiscall asLinearCS::Cull(void) | ?Cull@asLinearCS@@UAEXXZ
    0x525CB0 | public: void __thiscall asLinearCS::FileIO(class MiniParser *) | ?FileIO@asLinearCS@@QAEXPAVMiniParser@@@Z
    0x525CC0 | public: virtual void __thiscall asLinearCS::AddWidgets(class Bank *) | ?AddWidgets@asLinearCS@@UAEXPAVBank@@@Z
    0x525E20 | public: static void __cdecl asLinearCS::DeclareFields(void) | ?DeclareFields@asLinearCS@@SAXXZ
    0x525FF0 | public: virtual class MetaClass * __thiscall asLinearCS::GetClass(void) | ?GetClass@asLinearCS@@UAEPAVMetaClass@@XZ
    0x620B40 | const asLinearCS::`vftable' | ??_7asLinearCS@@6B@
    0x7908D8 | class MetaClass asLinearCSMetaClass | ?asLinearCSMetaClass@@3VMetaClass@@A
*/

#include "node.h"

#include "vector7/matrix34.h"

class asLinearCS : public asNode
{
public:
    // ??0asLinearCS@@QAE@XZ
    ARTS_EXPORT asLinearCS();

    // ??_EasLinearCS@@UAEPAXI@Z
    // ??1asLinearCS@@UAE@XZ | inline
    ARTS_EXPORT ~asLinearCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asLinearCS@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* bank) override;
#endif

    // ?Cull@asLinearCS@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?FileIO@asLinearCS@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(MiniParser* arg1);

    // ?Update@asLinearCS@@UAEXXZ
    ARTS_EXPORT void Update() override;

    Vector3& GetPosition()
    {
        return World.m3;
    }

    VIRTUAL_META_DECLARE;

    Matrix34 Matrix {};
    Matrix34 World {};
    i32 Global {false};
    asLinearCS* Inherit {nullptr};
};

check_size(asLinearCS, 0x88);
