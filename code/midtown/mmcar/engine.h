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

#include "arts7/node.h"

class mmCarSim;
class mmTransmission;

class mmEngine final : public asNode
{
public:
    // ??0mmEngine@@QAE@XZ
    ARTS_IMPORT mmEngine();

    // ??1mmEngine@@UAE@XZ
    ARTS_EXPORT ~mmEngine() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmEngine@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AfterLoad@mmEngine@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // ?CalcTorque@mmEngine@@QAEMM@Z
    ARTS_IMPORT f32 CalcTorque(f32 arg1);

    // ?CalcTorqueAtFullThrottle@mmEngine@@QAEMXZ
    ARTS_IMPORT f32 CalcTorqueAtFullThrottle();

    // ?CalcTorqueAtZeroThrottle@mmEngine@@QAEMXZ
    ARTS_IMPORT f32 CalcTorqueAtZeroThrottle();

    // ?ComputeConstants@mmEngine@@QAEXXZ
    ARTS_IMPORT void ComputeConstants();

    // ?GetClass@mmEngine@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmEngine@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(mmCarSim* arg1);

    // ?Reset@mmEngine@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@mmEngine@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmEngine@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    f32 MaxHorsePower;
    f32 OptRPM;
    f32 MaxRPM;
    f32 GCL;
    f32 HPScale;
    f32 EngineMass;
    f32 MaxRotationSpeed;
    f32 OptRotationSpeed;
    f32 TorqueDropoff;
    f32 MaxTorque;
    f32 PullUpModifier;
    f32 BreakDownModifier;
    f32 PrevGearRPM;
    f32 GearChangeTime;
    i32 ChangingGear;
    f32 Throttle;
    f32 field_60;
    f32 RotationSpeed;
    f32 RPM;
    f32 Horsepower;
    f32 Torque;
    mmCarSim* CarSim;
    mmTransmission* Trans;
};

check_size(mmEngine, 0x7C);
