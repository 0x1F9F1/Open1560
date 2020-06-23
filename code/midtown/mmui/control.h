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
    mmui:control

    0x4A2CA0 | public: __thiscall ControlSetup::ControlSetup(int) | ??0ControlSetup@@QAE@H@Z
    0x4A2E90 | public: virtual __thiscall ControlSetup::~ControlSetup(void) | ??1ControlSetup@@UAE@XZ
    0x4A2EF0 | public: void __thiscall ControlSetup::CreateDeviceOptions(void) | ?CreateDeviceOptions@ControlSetup@@QAEXXZ
    0x4A31B0 | public: void __thiscall ControlSetup::DeactivateAllDeviceOptions(void) | ?DeactivateAllDeviceOptions@ControlSetup@@QAEXXZ
    0x4A3210 | public: void __thiscall ControlSetup::ActivateDeviceOptions(void) | ?ActivateDeviceOptions@ControlSetup@@QAEXXZ
    0x4A34F0 | public: float __thiscall ControlSetup::SetControlPosition(class uiWidget *,float,float) | ?SetControlPosition@ControlSetup@@QAEMPAVuiWidget@@MM@Z
    0x4A3510 | public: void __thiscall ControlSetup::POVCB(void) | ?POVCB@ControlSetup@@QAEXXZ
    0x4A3520 | public: void __thiscall ControlSetup::SetSensitivityCB(void) | ?SetSensitivityCB@ControlSetup@@QAEXXZ
    0x4A3530 | public: void __thiscall ControlSetup::ControlSelect(void) | ?ControlSelect@ControlSetup@@QAEXXZ
    0x4A3580 | public: virtual void __thiscall ControlSetup::PreSetup(void) | ?PreSetup@ControlSetup@@UAEXXZ
    0x4A35B0 | public: void __thiscall ControlSetup::SetFFPermissions(void) | ?SetFFPermissions@ControlSetup@@QAEXXZ
    0x4A35F0 | public: void __thiscall ControlSetup::InitCustomControls(void) | ?InitCustomControls@ControlSetup@@QAEXXZ
    0x4A3680 | public: virtual void __thiscall ControlSetup::Update(void) | ?Update@ControlSetup@@UAEXXZ
    0x4A36A0 | public: virtual void __thiscall ControlSetup::StoreCurrentSetup(void) | ?StoreCurrentSetup@ControlSetup@@UAEXXZ
    0x4A36B0 | public: virtual void __thiscall ControlSetup::ResetDefaultAction(void) | ?ResetDefaultAction@ControlSetup@@UAEXXZ
    0x4A36F0 | public: void __thiscall ControlSetup::LaunchJoyCpl(void) | ?LaunchJoyCpl@ControlSetup@@QAEXXZ
    0x4A37A0 | unsigned long __stdcall CalibrateWatcher(void *) | ?CalibrateWatcher@@YGKPAX@Z
    0x4A3880 | public: virtual void __thiscall ControlSetup::CancelAction(void) | ?CancelAction@ControlSetup@@UAEXXZ
    0x4A3890 | public: virtual void __thiscall ControlSetup::DoneAction(void) | ?DoneAction@ControlSetup@@UAEXXZ
    0x4A38A0 | public: void __thiscall ControlSetup::BadAssignCB(void) | ?BadAssignCB@ControlSetup@@QAEXXZ
    0x4A38D0 | public: void __thiscall ControlSetup::ClearBadAssignment(void) | ?ClearBadAssignment@ControlSetup@@QAEXXZ
    0x4A38E0 | public: void __thiscall ControlSetup::CancelBadAssignment(void) | ?CancelBadAssignment@ControlSetup@@QAEXXZ
    0x4A3900 | public: void __thiscall ControlSetup::VerifyBadAssignment(void) | ?VerifyBadAssignment@ControlSetup@@QAEXXZ
    0x4A3920 | public: virtual void * __thiscall ControlSetup::`scalar deleting destructor'(unsigned int) | ??_GControlSetup@@UAEPAXI@Z
    0x4A3920 | public: virtual void * __thiscall ControlSetup::`vector deleting destructor'(unsigned int) | ??_EControlSetup@@UAEPAXI@Z
    0x61D9A0 | const ControlSetup::`vftable' | ??_7ControlSetup@@6B@
*/

#include "optionsbase.h"

class ControlSetup : public OptionsBase
{
    // const ControlSetup::`vftable' @ 0x61D9A0

public:
    // 0x4A2CA0 | ??0ControlSetup@@QAE@H@Z
    ControlSetup(i32 arg1);

    // 0x4A3920 | ??_EControlSetup@@UAEPAXI@Z
    // 0x4A2E90 | ??1ControlSetup@@UAE@XZ
    ~ControlSetup() override;

    // 0x4A3210 | ?ActivateDeviceOptions@ControlSetup@@QAEXXZ
    void ActivateDeviceOptions();

    // 0x4A38A0 | ?BadAssignCB@ControlSetup@@QAEXXZ
    void BadAssignCB();

    // 0x4A3880 | ?CancelAction@ControlSetup@@UAEXXZ
    void CancelAction() override;

    // 0x4A38E0 | ?CancelBadAssignment@ControlSetup@@QAEXXZ
    void CancelBadAssignment();

    // 0x4A38D0 | ?ClearBadAssignment@ControlSetup@@QAEXXZ
    void ClearBadAssignment();

    // 0x4A3530 | ?ControlSelect@ControlSetup@@QAEXXZ
    void ControlSelect();

    // 0x4A2EF0 | ?CreateDeviceOptions@ControlSetup@@QAEXXZ
    void CreateDeviceOptions();

    // 0x4A31B0 | ?DeactivateAllDeviceOptions@ControlSetup@@QAEXXZ
    void DeactivateAllDeviceOptions();

    // 0x4A3890 | ?DoneAction@ControlSetup@@UAEXXZ
    void DoneAction() override;

    // 0x4A35F0 | ?InitCustomControls@ControlSetup@@QAEXXZ
    void InitCustomControls();

    // 0x4A36F0 | ?LaunchJoyCpl@ControlSetup@@QAEXXZ
    void LaunchJoyCpl();

    // 0x4A3510 | ?POVCB@ControlSetup@@QAEXXZ | unused
    void POVCB();

    // 0x4A3580 | ?PreSetup@ControlSetup@@UAEXXZ
    void PreSetup() override;

    // 0x4A36B0 | ?ResetDefaultAction@ControlSetup@@UAEXXZ
    void ResetDefaultAction() override;

    // 0x4A34F0 | ?SetControlPosition@ControlSetup@@QAEMPAVuiWidget@@MM@Z
    f32 SetControlPosition(class uiWidget* arg1, f32 arg2, f32 arg3);

    // 0x4A35B0 | ?SetFFPermissions@ControlSetup@@QAEXXZ
    void SetFFPermissions();

    // 0x4A3520 | ?SetSensitivityCB@ControlSetup@@QAEXXZ
    void SetSensitivityCB();

    // 0x4A36A0 | ?StoreCurrentSetup@ControlSetup@@UAEXXZ
    void StoreCurrentSetup() override;

    // 0x4A3680 | ?Update@ControlSetup@@UAEXXZ
    void Update() override;

    // 0x4A3900 | ?VerifyBadAssignment@ControlSetup@@QAEXXZ
    void VerifyBadAssignment();
};

check_size(ControlSetup, 0x6F08);
