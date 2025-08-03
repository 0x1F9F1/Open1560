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
    virtual void SetWorld(aconst Matrix34& world);

    // ?Aspect@agiViewport@@QAEMXZ | unused
    f32 Aspect();

    // ?GetName@agiViewport@@UAEPADXZ
    aconst char* GetName() override;

    agiViewParameters& GetParams()
    {
        return params_;
    }

protected:
    // ??0agiViewport@@IAE@PAVagiPipeline@@@Z
    agiViewport(agiPipeline* pipe);

    // ??1agiViewport@@MAE@XZ
    ~agiViewport() override;

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
