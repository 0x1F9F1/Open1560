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

#include "optionsbase.h"

class ControlSetup final : public OptionsBase
{
public:
    // ??0ControlSetup@@QAE@H@Z
    ARTS_IMPORT ControlSetup(i32 arg1);

    // ??_EControlSetup@@UAEPAXI@Z
    // ??_GControlSetup@@UAEPAXI@Z
    // ??1ControlSetup@@UAE@XZ
    ARTS_IMPORT ~ControlSetup() override;

    // ?ActivateDeviceOptions@ControlSetup@@QAEXXZ
    ARTS_IMPORT void ActivateDeviceOptions();

    // ?BadAssignCB@ControlSetup@@QAEXXZ
    ARTS_IMPORT void BadAssignCB();

    // ?CancelAction@ControlSetup@@UAEXXZ
    ARTS_IMPORT void CancelAction() override;

    // ?CancelBadAssignment@ControlSetup@@QAEXXZ
    ARTS_IMPORT void CancelBadAssignment();

    // ?ClearBadAssignment@ControlSetup@@QAEXXZ
    ARTS_IMPORT void ClearBadAssignment();

    // ?ControlSelect@ControlSetup@@QAEXXZ
    ARTS_IMPORT void ControlSelect();

    // ?CreateDeviceOptions@ControlSetup@@QAEXXZ
    ARTS_IMPORT void CreateDeviceOptions();

    // ?DeactivateAllDeviceOptions@ControlSetup@@QAEXXZ
    ARTS_IMPORT void DeactivateAllDeviceOptions();

    // ?DoneAction@ControlSetup@@UAEXXZ
    ARTS_EXPORT void DoneAction() override;

    // ?InitCustomControls@ControlSetup@@QAEXXZ
    ARTS_IMPORT void InitCustomControls();

    // ?LaunchJoyCpl@ControlSetup@@QAEXXZ
    ARTS_IMPORT void LaunchJoyCpl();

    // ?POVCB@ControlSetup@@QAEXXZ | unused
    ARTS_EXPORT void POVCB();

    // ?PreSetup@ControlSetup@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?ResetDefaultAction@ControlSetup@@UAEXXZ
    ARTS_IMPORT void ResetDefaultAction() override;

    // ?SetControlPosition@ControlSetup@@QAEMPAVuiWidget@@MM@Z
    ARTS_IMPORT f32 SetControlPosition(uiWidget* arg1, f32 arg2, f32 arg3);

    // ?SetFFPermissions@ControlSetup@@QAEXXZ
    ARTS_IMPORT void SetFFPermissions();

    // ?SetSensitivityCB@ControlSetup@@QAEXXZ
    ARTS_IMPORT void SetSensitivityCB();

    // ?StoreCurrentSetup@ControlSetup@@UAEXXZ
    ARTS_IMPORT void StoreCurrentSetup() override;

    // ?Update@ControlSetup@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?VerifyBadAssignment@ControlSetup@@QAEXXZ
    ARTS_IMPORT void VerifyBadAssignment();

    u8 gap6EC8[0x40];
};

check_size(ControlSetup, 0x6F08);
