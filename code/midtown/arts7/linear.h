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

class asLinearCS : public asNode
{
    // const asLinearCS::`vftable' @ 0x620B40

public:
    // 0x525AB0 | ??0asLinearCS@@QAE@XZ
    asLinearCS();

    // 0x4B1CA0 | ??_EasLinearCS@@UAEPAXI@Z
    // 0x422F00 | ??1asLinearCS@@UAE@XZ
    ~asLinearCS() override;

    // 0x525CC0 | ?AddWidgets@asLinearCS@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x525C00 | ?Cull@asLinearCS@@UAEXXZ
    void Cull() override;

    // 0x525CB0 | ?FileIO@asLinearCS@@QAEXPAVMiniParser@@@Z
    void FileIO(class MiniParser* arg1);

    // 0x525FF0 | ?GetClass@asLinearCS@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x525B20 | ?Update@asLinearCS@@UAEXXZ
    void Update() override;

    // 0x525E20 | ?DeclareFields@asLinearCS@@SAXXZ
    static void DeclareFields();
};

check_size(asLinearCS, 0x88);

// 0x7908D8 | ?asLinearCSMetaClass@@3VMetaClass@@A
inline extern_var(0x7908D8, class MetaClass, asLinearCSMetaClass);
