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
    mmcamcs:postcamcs

    0x4F9570 | public: __thiscall PostCamCS::PostCamCS(void) | ??0PostCamCS@@QAE@XZ
    0x4F95C0 | public: void __thiscall PostCamCS::Init(class mmCar *) | ?Init@PostCamCS@@QAEXPAVmmCar@@@Z
    0x4F95E0 | public: virtual void __thiscall PostCamCS::Reset(void) | ?Reset@PostCamCS@@UAEXXZ
    0x4F95F0 | public: virtual void __thiscall PostCamCS::MakeActive(void) | ?MakeActive@PostCamCS@@UAEXXZ
    0x4F9670 | public: virtual void __thiscall PostCamCS::Update(void) | ?Update@PostCamCS@@UAEXXZ
    0x4F97A0 | public: virtual void __thiscall PostCamCS::AddWidgets(class Bank *) | ?AddWidgets@PostCamCS@@UAEXPAVBank@@@Z
    0x4F97C0 | public: static void __cdecl PostCamCS::DeclareFields(void) | ?DeclareFields@PostCamCS@@SAXXZ
    0x4F9930 | public: virtual class MetaClass * __thiscall PostCamCS::GetClass(void) | ?GetClass@PostCamCS@@UAEPAVMetaClass@@XZ
    0x4F9970 | public: virtual void * __thiscall PostCamCS::`vector deleting destructor'(unsigned int) | ??_EPostCamCS@@UAEPAXI@Z
    0x4F99D0 | public: virtual void __thiscall BaseCamCS::UpdateInput(void) | ?UpdateInput@BaseCamCS@@UAEXXZ
    0x620190 | const PostCamCS::`vftable' | ??_7PostCamCS@@6B@
    0x7193D8 | class MetaClass PostCamCSMetaClass | ?PostCamCSMetaClass@@3VMetaClass@@A
*/

#include "carcamcs.h"

class PostCamCS final : public CarCamCS
{
    // const PostCamCS::`vftable' @ 0x620190

public:
    // 0x4F9570 | ??0PostCamCS@@QAE@XZ
    ARTS_IMPORT PostCamCS();

    // 0x4F9970 | ??_EPostCamCS@@UAEPAXI@Z
    // 0x42D2F0 | ??1PostCamCS@@UAE@XZ | inline
    ARTS_IMPORT ~PostCamCS() override = default;

    // 0x4F97A0 | ?AddWidgets@PostCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4F9930 | ?GetClass@PostCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4F95C0 | ?Init@PostCamCS@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void Init(class mmCar* arg1);

    // 0x4F95F0 | ?MakeActive@PostCamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // 0x4F95E0 | ?Reset@PostCamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4F9670 | ?Update@PostCamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4F97C0 | ?DeclareFields@PostCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap118[0x14];
};

check_size(PostCamCS, 0x12C);

// 0x7193D8 | ?PostCamCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass PostCamCSMetaClass;
