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

#include "carcamcs.h"

class mmCar;

class AICamCS final : public CarCamCS
{
public:
    // ??0AICamCS@@QAE@XZ
    ARTS_IMPORT AICamCS();

    // ??1AICamCS@@UAE@XZ | inline
    ARTS_EXPORT ~AICamCS() override = default;

    // ?GetClass@AICamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@AICamCS@@QAEXPAVmmCar@@@Z
    ARTS_IMPORT void Init(mmCar* arg1);

    // ?MakeActive@AICamCS@@UAEXXZ
    ARTS_IMPORT void MakeActive() override;

    // ?Reset@AICamCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@AICamCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@AICamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap118[0x8];
};

check_size(AICamCS, 0x120);
