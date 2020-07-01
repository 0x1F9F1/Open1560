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
    arts7:dof

    0x52ACF0 | public: __thiscall asDofCS::asDofCS(void) | ??0asDofCS@@QAE@XZ
    0x52ADE0 | public: void __thiscall asDofCS::operator=(class asDofCS const &) | ??4asDofCS@@QAEXABV0@@Z
    0x52AF20 | public: virtual void __thiscall asDofCS::Reset(void) | ?Reset@asDofCS@@UAEXXZ
    0x52AF50 | public: void __thiscall asDofCS::SetTime(float,float,int) | ?SetTime@asDofCS@@QAEXMMH@Z
    0x52AFC0 | public: virtual void __thiscall asDofCS::Update(void) | ?Update@asDofCS@@UAEXXZ
    0x52B5D0 | public: void __thiscall asDofCS::FileIO(class MiniParser *) | ?FileIO@asDofCS@@QAEXPAVMiniParser@@@Z
    0x52B5E0 | protected: void __thiscall asDofCS::ModeCB(void) | ?ModeCB@asDofCS@@IAEXXZ
    0x52B600 | public: virtual void __thiscall asDofCS::AddWidgets(class Bank *) | ?AddWidgets@asDofCS@@UAEXPAVBank@@@Z
    0x52B9F0 | public: static void __cdecl asDofCS::DeclareFields(void) | ?DeclareFields@asDofCS@@SAXXZ
    0x52BB60 | public: virtual class MetaClass * __thiscall asDofCS::GetClass(void) | ?GetClass@asDofCS@@UAEPAVMetaClass@@XZ
    0x52BB70 | public: void __thiscall Vector3::Add(class Vector3 const &,class Vector3 const &) | ?Add@Vector3@@QAEXABV1@0@Z
    0x620DF8 | const asDofCS::`vftable' | ??_7asDofCS@@6B@
    0x790990 | class MetaClass asDofCSMetaClass | ?asDofCSMetaClass@@3VMetaClass@@A
*/

#include "linear.h"

class asDofCS /*final*/ : public asLinearCS
{
    // const asDofCS::`vftable' @ 0x620DF8

public:
    // 0x52ACF0 | ??0asDofCS@@QAE@XZ
    ARTS_IMPORT asDofCS();

    // 0x49C3D0 | ??_EasDofCS@@UAEPAXI@Z
    // 0x49C430 | ??1asDofCS@@UAE@XZ | inline
    ARTS_IMPORT ~asDofCS() override = default;

    // 0x52ADE0 | ??4asDofCS@@QAEXABV0@@Z | unused
    ARTS_IMPORT void operator=(class asDofCS const& arg1);

    // 0x52B600 | ?AddWidgets@asDofCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x52B5D0 | ?FileIO@asDofCS@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(class MiniParser* arg1);

    // 0x52BB60 | ?GetClass@asDofCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x52AF20 | ?Reset@asDofCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x52AF50 | ?SetTime@asDofCS@@QAEXMMH@Z | unused
    ARTS_IMPORT void SetTime(f32 arg1, f32 arg2, i32 arg3);

    // 0x52AFC0 | ?Update@asDofCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x52B9F0 | ?DeclareFields@asDofCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

protected:
    // 0x52B5E0 | ?ModeCB@asDofCS@@IAEXXZ
    ARTS_IMPORT void ModeCB();

    u8 gap88[0x70];
};

check_size(asDofCS, 0xF8);

// 0x790990 | ?asDofCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asDofCSMetaClass;
