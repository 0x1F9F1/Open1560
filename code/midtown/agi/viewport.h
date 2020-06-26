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
    agi:viewport

    0x5571D0 | public: __thiscall agiViewParameters::agiViewParameters(void) | ??0agiViewParameters@@QAE@XZ
    0x557240 | public: void __thiscall agiViewParameters::Perspective(float,float,float,float) | ?Perspective@agiViewParameters@@QAEXMMMM@Z
    0x557310 | public: void __thiscall agiViewParameters::Ortho(float,float,float,float) | ?Ortho@agiViewParameters@@QAEXMMMM@Z
    0x5573B0 | public: void __thiscall agiViewParameters::Frustum(float,float,float,float,float,float) | ?Frustum@agiViewParameters@@QAEXMMMMMM@Z
    0x557490 | public: int __thiscall agiViewParameters::SphereVisible(class Vector3 &,float) | ?SphereVisible@agiViewParameters@@QAEHAAVVector3@@M@Z
    0x557590 | public: void __thiscall agiViewParameters::SetBill(class Vector3 &) | ?SetBill@agiViewParameters@@QAEXAAVVector3@@@Z
    0x5576D0 | public: void __thiscall agiViewParameters::SetBillY(class Matrix34 &) | ?SetBillY@agiViewParameters@@QAEXAAVMatrix34@@@Z
    0x557870 | public: float __thiscall agiViewport::Aspect(void) | ?Aspect@agiViewport@@QAEMXZ
    0x5578A0 | public: virtual void __thiscall agiViewport::SetWorld(class Matrix34 &) | ?SetWorld@agiViewport@@UAEXAAVMatrix34@@@Z
    0x5578E0 | protected: __thiscall agiViewport::agiViewport(class agiPipeline *) | ??0agiViewport@@IAE@PAVagiPipeline@@@Z
    0x557940 | protected: virtual __thiscall agiViewport::~agiViewport(void) | ??1agiViewport@@MAE@XZ
    0x557960 | public: void __thiscall agiViewParameters::Project(class Vector3 &,class Vector3 &) | ?Project@agiViewParameters@@QAEXAAVVector3@@0@Z
    0x5579D0 | public: virtual char * __thiscall agiViewport::GetName(void) | ?GetName@agiViewport@@UAEPADXZ
    0x5579F0 | protected: virtual void * __thiscall agiViewport::`vector deleting destructor'(unsigned int) | ??_EagiViewport@@MAEPAXI@Z
    0x5579F0 | protected: virtual void * __thiscall agiViewport::`scalar deleting destructor'(unsigned int) | ??_GagiViewport@@MAEPAXI@Z
    0x621620 | const agiViewport::`vftable' | ??_7agiViewport@@6B@
    0x8FF040 | public: static unsigned int agiViewParameters::ViewSerial | ?ViewSerial@agiViewParameters@@2IA
    0x8FF044 | public: static unsigned int agiViewParameters::MtxSerial | ?MtxSerial@agiViewParameters@@2IA
    0x8FF048 | protected: static class agiViewport * agiViewport::Active | ?Active@agiViewport@@1PAV1@A
*/

#include "refresh.h"

class agiViewParameters
{
public:
    // 0x5571D0 | ??0agiViewParameters@@QAE@XZ
    ARTS_IMPORT agiViewParameters();

    // 0x5573B0 | ?Frustum@agiViewParameters@@QAEXMMMMMM@Z | unused
    ARTS_IMPORT void Frustum(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

    // 0x557310 | ?Ortho@agiViewParameters@@QAEXMMMM@Z | unused
    ARTS_IMPORT void Ortho(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x557240 | ?Perspective@agiViewParameters@@QAEXMMMM@Z
    ARTS_IMPORT void Perspective(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x557960 | ?Project@agiViewParameters@@QAEXAAVVector3@@0@Z | unused
    ARTS_IMPORT void Project(class Vector3& arg1, class Vector3& arg2);

    // 0x557590 | ?SetBill@agiViewParameters@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void SetBill(class Vector3& arg1);

    // 0x5576D0 | ?SetBillY@agiViewParameters@@QAEXAAVMatrix34@@@Z
    ARTS_IMPORT void SetBillY(class Matrix34& arg1);

    // 0x557490 | ?SphereVisible@agiViewParameters@@QAEHAAVVector3@@M@Z
    ARTS_IMPORT i32 SphereVisible(class Vector3& arg1, f32 arg2);

    // 0x8FF044 | ?MtxSerial@agiViewParameters@@2IA
    ARTS_IMPORT static u32 MtxSerial;

    // 0x8FF040 | ?ViewSerial@agiViewParameters@@2IA
    ARTS_IMPORT static u32 ViewSerial;
};

check_size(agiViewParameters, 0x12C);

class agiViewport : public agiRefreshable
{
    // const agiViewport::`vftable' @ 0x621620

public:
    virtual void Activate() = 0;

    virtual void SetBackground(class Vector3& arg1) = 0;

    virtual void Clear(i32 arg1) = 0;

    // 0x5578A0 | ?SetWorld@agiViewport@@UAEXAAVMatrix34@@@Z
    ARTS_IMPORT virtual void SetWorld(class Matrix34& arg1);

    // 0x557870 | ?Aspect@agiViewport@@QAEMXZ | unused
    ARTS_IMPORT f32 Aspect();

    // 0x5579D0 | ?GetName@agiViewport@@UAEPADXZ
    ARTS_IMPORT char* GetName() override;

protected:
    // 0x5578E0 | ??0agiViewport@@IAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiViewport(class agiPipeline* arg1);

    // 0x5579F0 | ??_GagiViewport@@MAEPAXI@Z
    // 0x557940 | ??1agiViewport@@MAE@XZ
    ARTS_IMPORT ~agiViewport() override;

    // 0x8FF048 | ?Active@agiViewport@@1PAV1@A
    ARTS_IMPORT static class agiViewport* Active;
};

check_size(agiViewport, 0x14C);
