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

#include "vector7/matrix34.h"
#include "vector7/vector2.h"

class agiViewParameters
{
public:
    // ??0agiViewParameters@@QAE@XZ
    ARTS_IMPORT agiViewParameters();

    // ?Perspective@agiViewParameters@@QAEXMMMM@Z
    ARTS_IMPORT void Perspective(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?SetBill@agiViewParameters@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void SetBill(Vector3& arg1);

    // ?SetBillY@agiViewParameters@@QAEXAAVMatrix34@@@Z
    ARTS_IMPORT void SetBillY(Matrix34& arg1);

    // ?SphereVisible@agiViewParameters@@QAEHAAVVector3@@M@Z
    ARTS_IMPORT i32 SphereVisible(Vector3& arg1, f32 arg2);

    void SetWorld(const Matrix34& world);

    // ?MtxSerial@agiViewParameters@@2IA
    ARTS_IMPORT static u32 MtxSerial;

    // ?ViewSerial@agiViewParameters@@2IA
    ARTS_IMPORT static u32 ViewSerial;

    f32 X;
    f32 Y;
    f32 Width;
    f32 Height;
    f32 Fov;
    f32 Aspect;
    f32 Near;
    f32 Far;
    f32 DepthScale;

    f32 ProjX;
    f32 ProjY;
    f32 ProjZZ;
    f32 ProjZW;
    f32 ProjXZ;
    f32 ProjYZ;
    f32 ProjRight;
    f32 ProjBottom;

    // Position/Orientation of the camera in world space
    Matrix34 Camera;

    // Transform from world space to view space
    // Equal to `Camera.Inverse()`
    Matrix34 View;

    // Transform from model space to world space
    Matrix34 World;

    // Transform from model space to view space
    // Equal to `View * Model`
    Matrix34 ModelView;

    Vector2 LeftPlane;
    Vector2 RightPlane;

    // TODO: Are these in the right order?
    Vector2 TopPlane;
    Vector2 BottomPlane;

    f32 field_124;
    b32 Orthographic;
};

check_size(agiViewParameters, 0x12C);

#define AGI_VIEW_CLEAR_TARGET 0x00000001l  /* Clear target surface */
#define AGI_VIEW_CLEAR_ZBUFFER 0x00000002l /* Clear target z buffer */

class agiViewport : public agiRefreshable
{
public:
    virtual void Activate() = 0;

    virtual void SetBackground(aconst Vector3& color) = 0;

    virtual void Clear(i32 flags) = 0;

    // ?SetWorld@agiViewport@@UAEXAAVMatrix34@@@Z
    ARTS_EXPORT virtual void SetWorld(aconst Matrix34& world);

    // ?Aspect@agiViewport@@QAEMXZ | unused
    ARTS_EXPORT f32 Aspect();

    // ?GetName@agiViewport@@UAEPADXZ
    ARTS_EXPORT aconst char* GetName() override;

    agiViewParameters& GetParams()
    {
        return params_;
    }

protected:
    // ??0agiViewport@@IAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiViewport(agiPipeline* pipe);

    // ??_GagiViewport@@MAEPAXI@Z
    // ??_EagiViewport@@MAEPAXI@Z
    // ??1agiViewport@@MAE@XZ
    ARTS_EXPORT ~agiViewport() override;

    // ?Active@agiViewport@@1PAV1@A
    ARTS_IMPORT static agiViewport* Active;

    friend agiViewport* Viewport();

    agiViewParameters params_;
    u32 field_144_; // ViewIndex ?
    // TODO: Is clear_color_ part of agiViewport ?
};

check_size(agiViewport, 0x148);

inline agiViewport* Viewport()
{
    return agiViewport::Active;
}

inline const agiViewParameters& ViewParams()
{
    return Viewport()->GetParams();
}
