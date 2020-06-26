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
    mmcar:engine

    0x47C930 | public: __thiscall mmEngine::mmEngine(void) | ??0mmEngine@@QAE@XZ
    0x47C990 | public: virtual __thiscall mmEngine::~mmEngine(void) | ??1mmEngine@@UAE@XZ
    0x47C9A0 | public: void __thiscall mmEngine::Init(class mmCarSim *) | ?Init@mmEngine@@QAEXPAVmmCarSim@@@Z
    0x47C9D0 | public: virtual void __thiscall mmEngine::AfterLoad(void) | ?AfterLoad@mmEngine@@UAEXXZ
    0x47C9E0 | public: void __thiscall mmEngine::Load(class Stream *) | ?Load@mmEngine@@QAEXPAVStream@@@Z
    0x47CA60 | public: void __thiscall mmEngine::ComputeConstants(void) | ?ComputeConstants@mmEngine@@QAEXXZ
    0x47CAE0 | public: float __thiscall mmEngine::CalcTorqueAtFullThrottle(void) | ?CalcTorqueAtFullThrottle@mmEngine@@QAEMXZ
    0x47CB70 | public: float __thiscall mmEngine::CalcTorqueAtZeroThrottle(void) | ?CalcTorqueAtZeroThrottle@mmEngine@@QAEMXZ
    0x47CBB0 | public: float __thiscall mmEngine::CalcTorque(float) | ?CalcTorque@mmEngine@@QAEMM@Z
    0x47CBE0 | public: void __thiscall mmEngine::Save(class Stream *) | ?Save@mmEngine@@QAEXPAVStream@@@Z
    0x47CC60 | public: virtual void __thiscall mmEngine::Reset(void) | ?Reset@mmEngine@@UAEXXZ
    0x47CC90 | public: virtual void __thiscall mmEngine::Update(void) | ?Update@mmEngine@@UAEXXZ
    0x47CE70 | public: virtual void __thiscall mmEngine::AddWidgets(class Bank *) | ?AddWidgets@mmEngine@@UAEXPAVBank@@@Z
    0x47CFC0 | public: static void __cdecl mmEngine::DeclareFields(void) | ?DeclareFields@mmEngine@@SAXXZ
    0x47D180 | public: virtual class MetaClass * __thiscall mmEngine::GetClass(void) | ?GetClass@mmEngine@@UAEPAVMetaClass@@XZ
    0x47D190 | public: virtual void * __thiscall mmEngine::`vector deleting destructor'(unsigned int) | ??_EmmEngine@@UAEPAXI@Z
    0x61C600 | const mmEngine::`vftable' | ??_7mmEngine@@6B@
    0x6A8030 | class MetaClass mmEngineMetaClass | ?mmEngineMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmEngine : public asNode
{
    // const mmEngine::`vftable' @ 0x61C600

public:
    // 0x47C930 | ??0mmEngine@@QAE@XZ
    ARTS_IMPORT mmEngine();

    // 0x47D190 | ??_EmmEngine@@UAEPAXI@Z
    // 0x47C990 | ??1mmEngine@@UAE@XZ
    ARTS_IMPORT ~mmEngine() override;

    // 0x47CE70 | ?AddWidgets@mmEngine@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x47C9D0 | ?AfterLoad@mmEngine@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // 0x47CBB0 | ?CalcTorque@mmEngine@@QAEMM@Z
    ARTS_IMPORT f32 CalcTorque(f32 arg1);

    // 0x47CAE0 | ?CalcTorqueAtFullThrottle@mmEngine@@QAEMXZ
    ARTS_IMPORT f32 CalcTorqueAtFullThrottle();

    // 0x47CB70 | ?CalcTorqueAtZeroThrottle@mmEngine@@QAEMXZ
    ARTS_IMPORT f32 CalcTorqueAtZeroThrottle();

    // 0x47CA60 | ?ComputeConstants@mmEngine@@QAEXXZ
    ARTS_IMPORT void ComputeConstants();

    // 0x47D180 | ?GetClass@mmEngine@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x47C9A0 | ?Init@mmEngine@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(class mmCarSim* arg1);

    // 0x47C9E0 | ?Load@mmEngine@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Load(class Stream* arg1);

    // 0x47CC60 | ?Reset@mmEngine@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x47CBE0 | ?Save@mmEngine@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Save(class Stream* arg1);

    // 0x47CC90 | ?Update@mmEngine@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x47CFC0 | ?DeclareFields@mmEngine@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x5C];
};

check_size(mmEngine, 0x7C);

// 0x6A8030 | ?mmEngineMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmEngineMetaClass;
