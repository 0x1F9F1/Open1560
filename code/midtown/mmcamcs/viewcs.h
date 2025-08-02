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

#include "arts7/linear.h"

class asCamera;
class CarCamCS;

class mmViewCS final : public asLinearCS
{
public:
    // ??0mmViewCS@@QAE@XZ
    ARTS_IMPORT mmViewCS();

    // ??_EmmViewCS@@UAEPAXI@Z
    // ??1mmViewCS@@UAE@XZ
    ARTS_EXPORT ~mmViewCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmViewCS@@UAEXPAVBank@@@Z | inline
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@mmViewCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmViewCS@@QAEXXZ
    ARTS_EXPORT void Init();

    // ?NewCam@mmViewCS@@QAEHPAVCarCamCS@@HMVCallback@@@Z
    ARTS_IMPORT i32 NewCam(CarCamCS* arg1, i32 arg2, f32 arg3, Callback arg4);

    // ?Reset@mmViewCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetCamera@mmViewCS@@QAEXPAVasCamera@@@Z
    ARTS_IMPORT void SetCamera(asCamera* arg1);

    // ?SetCurrentCam@mmViewCS@@QAEXPAVCarCamCS@@@Z
    ARTS_IMPORT void SetCurrentCam(CarCamCS* arg1);

    // ?Update@mmViewCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmViewCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?Instance@mmViewCS@@SAPAV1@PAVasCamera@@@Z
    ARTS_IMPORT static mmViewCS* Instance(asCamera* arg1);

    u8 gap88[0x38];
};

check_size(mmViewCS, 0xC0);
