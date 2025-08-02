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

#include "appcamcs.h"

class mmCar;

class CarCamCS : public AppCamCS
{
public:
    // ??0CarCamCS@@QAE@XZ
    ARTS_IMPORT CarCamCS();

    // ??_ECarCamCS@@UAEPAXI@Z
    // ??1CarCamCS@@UAE@XZ
    ARTS_EXPORT ~CarCamCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@CarCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@CarCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@CarCamCS@@QAEXPAVmmCar@@PAD@Z
    ARTS_IMPORT void Init(mmCar* arg1, char* arg2);

    // ?DeclareFields@CarCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap114[0x4];
};

check_size(CarCamCS, 0x118);
