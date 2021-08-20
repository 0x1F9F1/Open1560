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
    mmphysics:osample

    0x4DED20 | public: __thiscall asOverSample::asOverSample(void) | ??0asOverSample@@QAE@XZ
    0x4DED50 | public: void __thiscall asOverSample::RealTime(float) | ?RealTime@asOverSample@@QAEXM@Z
    0x4DED70 | public: virtual void __thiscall asOverSample::Update(void) | ?Update@asOverSample@@UAEXXZ
    0x4DEE30 | public: virtual void __thiscall asOverSample::AddWidgets(class Bank *) | ?AddWidgets@asOverSample@@UAEXPAVBank@@@Z
    0x4DEEE0 | public: static void __cdecl asOverSample::DeclareFields(void) | ?DeclareFields@asOverSample@@SAXXZ
    0x4DF060 | public: virtual class MetaClass * __thiscall asOverSample::GetClass(void) | ?GetClass@asOverSample@@UAEPAVMetaClass@@XZ
    0x4DF070 | public: virtual void * __thiscall asOverSample::`vector deleting destructor'(unsigned int) | ??_EasOverSample@@UAEPAXI@Z
    0x61FB28 | const asOverSample::`vftable' | ??_7asOverSample@@6B@
    0x719160 | class MetaClass asOverSampleMetaClass | ?asOverSampleMetaClass@@3VMetaClass@@A
    0x719188 | int BenchOSample | ?BenchOSample@@3HA
*/

#include "arts7/node.h"

class asOverSample final : public asNode
{
public:
    // ??0asOverSample@@QAE@XZ
    ARTS_EXPORT asOverSample() = default;

    // ??_EasOverSample@@UAEPAXI@Z
    // ??1asOverSample@@UAE@XZ | inline
    ARTS_EXPORT ~asOverSample() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asOverSample@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@asOverSample@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?RealTime@asOverSample@@QAEXM@Z
    ARTS_EXPORT void RealTime(f32 fps);

    // ?Update@asOverSample@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@asOverSample@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    f32 SampleStep {1.0f / 25.0f};
    i32 MaxSamples {20};
    i32 NumSamples {0};
    i32 field_2C {1};
};

check_size(asOverSample, 0x30);

// ?BenchOSample@@3HA
ARTS_IMPORT extern i32 BenchOSample;
