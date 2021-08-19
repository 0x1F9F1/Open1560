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
    mmcamcs:pointcamcs

    0x4F9E20 | public: __thiscall PointCamCS::PointCamCS(void) | ??0PointCamCS@@QAE@XZ
    0x4F9E50 | public: void __thiscall PointCamCS::Init(class mmCar *) | ?Init@PointCamCS@@QAEXPAVmmCar@@@Z
    0x4F9E80 | public: virtual void __thiscall PointCamCS::Reset(void) | ?Reset@PointCamCS@@UAEXXZ
    0x4F9E90 | public: virtual void __thiscall PointCamCS::MakeActive(void) | ?MakeActive@PointCamCS@@UAEXXZ
    0x4F9EC0 | public: void __thiscall PointCamCS::SetPos(class Vector3 &) | ?SetPos@PointCamCS@@QAEXAAVVector3@@@Z
    0x4F9F00 | public: void __thiscall PointCamCS::SetMaxDist(float) | ?SetMaxDist@PointCamCS@@QAEXM@Z
    0x4F9F20 | public: void __thiscall PointCamCS::SetMinDist(float) | ?SetMinDist@PointCamCS@@QAEXM@Z
    0x4F9F40 | public: void __thiscall PointCamCS::SetAppRate(float) | ?SetAppRate@PointCamCS@@QAEXM@Z
    0x4F9F50 | public: void __thiscall PointCamCS::SetVel(class Vector3 &) | ?SetVel@PointCamCS@@QAEXAAVVector3@@@Z
    0x4F9F70 | public: class Vector3 __thiscall PointCamCS::GetPos(void) | ?GetPos@PointCamCS@@QAE?AVVector3@@XZ
    0x4F9FA0 | public: virtual void __thiscall PointCamCS::Update(void) | ?Update@PointCamCS@@UAEXXZ
    0x4FA280 | public: static void __cdecl PointCamCS::DeclareFields(void) | ?DeclareFields@PointCamCS@@SAXXZ
    0x4FA3F0 | public: virtual class MetaClass * __thiscall PointCamCS::GetClass(void) | ?GetClass@PointCamCS@@UAEPAVMetaClass@@XZ
    0x4FA430 | public: virtual void * __thiscall PointCamCS::`vector deleting destructor'(unsigned int) | ??_EPointCamCS@@UAEPAXI@Z
    0x620248 | const PointCamCS::`vftable' | ??_7PointCamCS@@6B@
    0x719438 | class MetaClass PointCamCSMetaClass | ?PointCamCSMetaClass@@3VMetaClass@@A
*/

#include "carcamcs.h"

class PointCamCS final : public CarCamCS
{
public:
    // ??0PointCamCS@@QAE@XZ
    ARTS_IMPORT PointCamCS();

    // ??_EPointCamCS@@UAEPAXI@Z
    // ??1PointCamCS@@UAE@XZ | inline
    ARTS_IMPORT ~PointCamCS() override = default;

    // ?GetClass@PointCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetPos@PointCamCS@@QAE?AVVector3@@XZ | unused
    ARTS_IMPORT class Vector3 GetPos();

    // ?Init@PointCamCS@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void Init(class mmCar* arg1);

    // ?MakeActive@PointCamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // ?Reset@PointCamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetAppRate@PointCamCS@@QAEXM@Z
    ARTS_IMPORT void SetAppRate(f32 arg1);

    // ?SetMaxDist@PointCamCS@@QAEXM@Z
    ARTS_IMPORT void SetMaxDist(f32 arg1);

    // ?SetMinDist@PointCamCS@@QAEXM@Z
    ARTS_IMPORT void SetMinDist(f32 arg1);

    // ?SetPos@PointCamCS@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void SetPos(class Vector3& arg1);

    // ?SetVel@PointCamCS@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void SetVel(class Vector3& arg1);

    // ?Update@PointCamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@PointCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap118[0x2C];
};

check_size(PointCamCS, 0x144);

// ?PointCamCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass PointCamCSMetaClass;
