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

#include "node.h"

#include "data7/callback.h"
#include "vector7/matrix34.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

class agiBitmap;
class agiLightModel;
class agiLightModelParameters;
class agiViewport;

class asCamera final : public asNode
{
public:
    // ??0asCamera@@QAE@XZ
    ARTS_IMPORT asCamera();

    // ??1asCamera@@UAE@XZ
    ARTS_IMPORT ~asCamera() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asCamera@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?DrawBegin@asCamera@@QAEXXZ
    ARTS_EXPORT void DrawBegin();

    // ?DrawEnd@asCamera@@QAEXXZ
    ARTS_IMPORT void DrawEnd();

    // ?FadeIn@asCamera@@QAEXMH@Z
    ARTS_IMPORT void FadeIn(f32 arg1, i32 arg2);

    // ?FadeOut@asCamera@@QAEXMH@Z
    ARTS_IMPORT void FadeOut(f32 arg1, i32 arg2);

    // ?GetClass@asCamera@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    enum kNearClip
    {
        kNearClip0,
        kNearClip1,
        kNearClip2,
        kNearClip3,
        kNearClip4,
    };

    // ?SetClipArea@asCamera@@QAEXMMMM@Z
    ARTS_IMPORT void SetClipArea(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?SetFog@asCamera@@QAEXMMMM@Z
    ARTS_IMPORT void SetFog(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?SetLighting@asCamera@@QAEXH@Z
    ARTS_IMPORT void SetLighting(i32 arg1);

    // ?SetUnderlay@asCamera@@QAEXPAD@Z
    ARTS_IMPORT void SetUnderlay(aconst char* arg1);

    // ?SetUnderlayCB@asCamera@@QAEXPAVagiBitmap@@PAVCallback@@@Z
    ARTS_IMPORT void SetUnderlayCB(agiBitmap* arg1, Callback* arg2);

    // ?SetView@asCamera@@QAEXMMMM@Z
    ARTS_EXPORT void SetView(f32 horz_fov, f32 aspect, f32 near_clip, f32 far_clip);

    // ?SetViewport@asCamera@@QAEXMMMMH@Z
    ARTS_IMPORT void SetViewport(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5);

    // ?SetWorld@asCamera@@QAEXAAVMatrix34@@@Z
    ARTS_IMPORT void SetWorld(Matrix34& arg1);

    // ?Update@asCamera@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@asCamera@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Matrix34* GetCameraMatrix()
    {
        return &camera_;
    }

private:
    // ?Regen@asCamera@@AAEXXZ
    ARTS_IMPORT void Regen();

    agiViewport* viewport_ {};
    agiLightModel* light_model_ {};
    agiLightModelParameters* light_params_ {};

    agiBitmap* underlay_bitmap_ {};
    Callback* underlay_callback_ {};

    f32 x_origin_ {};
    f32 y_origin_ {};

    f32 x_size_ {};
    f32 y_size_ {};

    Vector3 bg_color_ {};
    Vector4 shadow_color_ {};

    u32 field_5C;
    u32 field_60;
    u32 field_64;
    i32 clear_flags_ {};

    f32 fov_ {};
    f32 fov_radians_ {};
    f32 aspect_ {};
    f32 near_clip_ {};
    f32 far_clip_ {};
    f32 float_80;
    f32 float_84;

    f32 left_clip_scale_ {};
    f32 right_clip_scale_ {};
    f32 bottom_clip_scale_ {};
    f32 top_clip_scale_ {};

    Vector2 left_clip_ {};
    Vector2 right_clip_ {};
    Vector2 bottom_clip_ {};
    Vector2 top_clip_ {};

    b32 auto_aspect_ {};
    i32 draw_mode_ {};
    i32 field_C0;
    f32 float_C4;
    i32 field_C8;
    i32 field_CC;

    Vector3 fog_color_ {};
    f32 fog_density_ {};
    f32 float_E0;
    f32 fog_start_ {};
    f32 fog_end_ {};

    Matrix34 camera_ {};
    Matrix34 view_ {};

    i32 field_14C;
    i32 field_150;
    i32 field_154;
    i32 field_158;
    i32 field_15C;

    i32 pause_fade_ {};
    f32 fade_amount_ {};
    f32 fade_speed_ {};
    f32 max_fade_ {};
    Vector3 fade_color_ {};
    f32 float_17C;
    i32 fade_ticks_ {};
    i32 field_184;
};

check_size(asCamera, 0x18C);

#ifdef ARTS_DEV_BUILD
// ?FadeItIn@@YAXPAVasCamera@@@Z
ARTS_IMPORT void FadeItIn(asCamera* arg1);

// ?FadeItOut@@YAXPAVasCamera@@@Z
ARTS_IMPORT void FadeItOut(asCamera* arg1);

// ?FritzIt@@YAXPAVasCamera@@@Z
ARTS_IMPORT void FritzIt(asCamera* arg1);

// ?ViewIt@@YAXPAVasCamera@@@Z
ARTS_IMPORT void ViewIt(asCamera* arg1);

// ?Duration@@3MA
ARTS_IMPORT extern f32 Duration;
#endif

// ?VW@@3PAVagiViewport@@A
ARTS_IMPORT extern agiViewport* VW;
