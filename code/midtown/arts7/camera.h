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
    arts7:camera

    0x528BB0 | public: virtual __thiscall asCamera::~asCamera(void) | ??1asCamera@@UAE@XZ
    0x528C40 | public: __thiscall asCamera::asCamera(void) | ??0asCamera@@QAE@XZ
    0x528DF0 | public: virtual void __thiscall asCamera::Update(void) | ?Update@asCamera@@UAEXXZ
    0x529100 | public: void __thiscall asCamera::SetClipArea(float,float,float,float) | ?SetClipArea@asCamera@@QAEXMMMM@Z
    0x529230 | public: void __thiscall asCamera::SetLighting(int) | ?SetLighting@asCamera@@QAEXH@Z
    0x529250 | public: void __thiscall asCamera::SetWorld(class Matrix34 &) | ?SetWorld@asCamera@@QAEXAAVMatrix34@@@Z
    0x529270 | public: void __thiscall asCamera::GetNearClip(class Vector3 *,class Matrix34 &,enum asCamera::kNearClip) | ?GetNearClip@asCamera@@QAEXPAVVector3@@AAVMatrix34@@W4kNearClip@1@@Z
    0x5297D0 | public: void __thiscall asCamera::DrawBegin(void) | ?DrawBegin@asCamera@@QAEXXZ
    0x5299C0 | public: void __thiscall asCamera::DrawEnd(void) | ?DrawEnd@asCamera@@QAEXXZ
    0x529B70 | public: void __thiscall asCamera::SetViewport(float,float,float,float,int) | ?SetViewport@asCamera@@QAEXMMMMH@Z
    0x529BC0 | public: void __thiscall asCamera::SetView(float,float,float,float) | ?SetView@asCamera@@QAEXMMMM@Z
    0x529C10 | public: void __thiscall asCamera::SetFog(float,float,float,float) | ?SetFog@asCamera@@QAEXMMMM@Z
    0x529C40 | public: void __thiscall asCamera::SetUnderlay(char *) | ?SetUnderlay@asCamera@@QAEXPAD@Z
    0x529C80 | public: void __thiscall asCamera::SetUnderlayCB(class agiBitmap *,class Callback *) | ?SetUnderlayCB@asCamera@@QAEXPAVagiBitmap@@PAVCallback@@@Z
    0x529CA0 | public: int __thiscall asCamera::GetViewportWidth(void) | ?GetViewportWidth@asCamera@@QAEHXZ
    0x529CC0 | public: int __thiscall asCamera::GetViewportHeight(void) | ?GetViewportHeight@asCamera@@QAEHXZ
    0x529CE0 | public: void __thiscall asCamera::FadeOut(float,int) | ?FadeOut@asCamera@@QAEXMH@Z
    0x529D40 | public: void __thiscall asCamera::FadeIn(float,int) | ?FadeIn@asCamera@@QAEXMH@Z
    0x529DA0 | public: void __thiscall asCamera::FileIO(class MiniParser *) | ?FileIO@asCamera@@QAEXPAVMiniParser@@@Z
    0x529DB0 | public: float __thiscall asCamera::SphereVisible(class Vector3 const &,float,float *) | ?SphereVisible@asCamera@@QAEMABVVector3@@MPAM@Z
    0x529F50 | public: void __thiscall asCamera::SetAmbient(class Vector3 const &) | ?SetAmbient@asCamera@@QAEXABVVector3@@@Z
    0x529F90 | public: void __thiscall asCamera::SetMonochrome(int) | ?SetMonochrome@asCamera@@QAEXH@Z
    0x529FB0 | private: void __thiscall asCamera::Regen(void) | ?Regen@asCamera@@AAEXXZ
    0x529FD0 | void __cdecl FadeItOut(class asCamera *) | ?FadeItOut@@YAXPAVasCamera@@@Z
    0x529FF0 | void __cdecl FadeItIn(class asCamera *) | ?FadeItIn@@YAXPAVasCamera@@@Z
    0x52A010 | void __cdecl FritzIt(class asCamera *) | ?FritzIt@@YAXPAVasCamera@@@Z
    0x52A020 | void __cdecl ViewIt(class asCamera *) | ?ViewIt@@YAXPAVasCamera@@@Z
    0x52A040 | public: virtual void __thiscall asCamera::AddWidgets(class Bank *) | ?AddWidgets@asCamera@@UAEXPAVBank@@@Z
    0x52A6A0 | public: static void __cdecl asCamera::DeclareFields(void) | ?DeclareFields@asCamera@@SAXXZ
    0x52A810 | public: virtual class MetaClass * __thiscall asCamera::GetClass(void) | ?GetClass@asCamera@@UAEPAVMetaClass@@XZ
    0x52A820 | public: virtual void * __thiscall asCamera::`vector deleting destructor'(unsigned int) | ??_EasCamera@@UAEPAXI@Z
    0x620D50 | const asCamera::`vftable' | ??_7asCamera@@6B@
    0x64DF5C | float Duration | ?Duration@@3MA
    0x790958 | class MetaClass asCameraMetaClass | ?asCameraMetaClass@@3VMetaClass@@A
    0x790980 | class agiViewport * VW | ?VW@@3PAVagiViewport@@A
*/

#include "node.h"

#include "data7/callback.h"
#include "vector7/matrix34.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

class agiViewport;
class agiLightModel;
class agiLightModelParameters;
class agiBitmap;

class asCamera final : public asNode
{
    // const asCamera::`vftable' @ 0x620D50

public:
    // 0x528C40 | ??0asCamera@@QAE@XZ
    ARTS_IMPORT asCamera();

    // 0x52A820 | ??_EasCamera@@UAEPAXI@Z
    // 0x528BB0 | ??1asCamera@@UAE@XZ
    ARTS_IMPORT ~asCamera() override;

    // 0x52A040 | ?AddWidgets@asCamera@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x5297D0 | ?DrawBegin@asCamera@@QAEXXZ
    ARTS_IMPORT void DrawBegin();

    // 0x5299C0 | ?DrawEnd@asCamera@@QAEXXZ
    ARTS_IMPORT void DrawEnd();

    // 0x529D40 | ?FadeIn@asCamera@@QAEXMH@Z
    ARTS_IMPORT void FadeIn(f32 arg1, i32 arg2);

    // 0x529CE0 | ?FadeOut@asCamera@@QAEXMH@Z
    ARTS_IMPORT void FadeOut(f32 arg1, i32 arg2);

    // 0x529DA0 | ?FileIO@asCamera@@QAEXPAVMiniParser@@@Z | unused
    ARTS_IMPORT void FileIO(class MiniParser* arg1);

    // 0x52A810 | ?GetClass@asCamera@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    enum kNearClip
    {
        kNearClip0,
        kNearClip1,
        kNearClip2,
        kNearClip3,
        kNearClip4,
    };

    // 0x529270 | ?GetNearClip@asCamera@@QAEXPAVVector3@@AAVMatrix34@@W4kNearClip@1@@Z | unused
    ARTS_IMPORT void GetNearClip(class Vector3* arg1, class Matrix34& arg2, enum asCamera::kNearClip arg3);

    // 0x529CC0 | ?GetViewportHeight@asCamera@@QAEHXZ | unused
    ARTS_IMPORT i32 GetViewportHeight();

    // 0x529CA0 | ?GetViewportWidth@asCamera@@QAEHXZ | unused
    ARTS_IMPORT i32 GetViewportWidth();

    // 0x529F50 | ?SetAmbient@asCamera@@QAEXABVVector3@@@Z | unused
    ARTS_IMPORT void SetAmbient(class Vector3 const& arg1);

    // 0x529100 | ?SetClipArea@asCamera@@QAEXMMMM@Z
    ARTS_IMPORT void SetClipArea(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x529C10 | ?SetFog@asCamera@@QAEXMMMM@Z
    ARTS_IMPORT void SetFog(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x529230 | ?SetLighting@asCamera@@QAEXH@Z
    ARTS_IMPORT void SetLighting(i32 arg1);

    // 0x529F90 | ?SetMonochrome@asCamera@@QAEXH@Z | unused
    ARTS_IMPORT void SetMonochrome(i32 arg1);

    // 0x529C40 | ?SetUnderlay@asCamera@@QAEXPAD@Z
    ARTS_IMPORT void SetUnderlay(char* arg1);

    // 0x529C80 | ?SetUnderlayCB@asCamera@@QAEXPAVagiBitmap@@PAVCallback@@@Z
    ARTS_IMPORT void SetUnderlayCB(class agiBitmap* arg1, class Callback* arg2);

    // 0x529BC0 | ?SetView@asCamera@@QAEXMMMM@Z
    ARTS_EXPORT void SetView(f32 horz_fov, f32 vert_fov, f32 near_clip, f32 far_clip);

    // 0x529B70 | ?SetViewport@asCamera@@QAEXMMMMH@Z
    ARTS_IMPORT void SetViewport(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5);

    // 0x529250 | ?SetWorld@asCamera@@QAEXAAVMatrix34@@@Z
    ARTS_IMPORT void SetWorld(class Matrix34& arg1);

    // 0x529DB0 | ?SphereVisible@asCamera@@QAEMABVVector3@@MPAM@Z | unused
    ARTS_IMPORT f32 SphereVisible(class Vector3 const& arg1, f32 arg2, f32* arg3);

    // 0x528DF0 | ?Update@asCamera@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x52A6A0 | ?DeclareFields@asCamera@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x529FB0 | ?Regen@asCamera@@AAEXXZ
    ARTS_IMPORT void Regen();

    agiViewport* viewport_ {nullptr};
    agiLightModel* light_model_ {nullptr};
    agiLightModelParameters* light_params_ {nullptr};

    agiBitmap* underlay_bitmap_ {nullptr};
    Callback* underlay_callback_ {nullptr};

    f32 x_origin_ {0.0f};
    f32 y_origin_ {0.0f};

    f32 x_size_ {0.0f};
    f32 y_size_ {0.0f};

    Vector3 bg_color_ {};
    Vector4 shadow_color_ {};

    u32 dword5C;
    u32 dword60;
    u32 dword64;
    i32 clear_flags_ {0};

    f32 fov_ {0.0f};
    f32 fov_radians_ {0.0f};
    f32 aspect_ {0.0f};
    f32 near_clip_ {0.0f};
    f32 far_clip_ {0.0f};
    f32 float80;
    f32 float84;

    f32 left_clip_scale_ {0.0f};
    f32 right_clip_scale_ {0.0f};
    f32 bottom_clip_scale_ {0.0f};
    f32 top_clip_scale_ {0.0f};

    Vector2 left_clip_ {};
    Vector2 right_clip_ {};
    Vector2 bottom_clip_ {};
    Vector2 top_clip_ {};

    b32 auto_aspect_ {false};
    i32 draw_mode_ {0};
    i32 dwordC0;
    f32 floatC4;
    i32 dwordC8;
    i32 dwordCC;

    Vector3 fog_color_ {};
    f32 fog_density_ {0.0f};
    f32 floatE0;
    f32 fog_start_ {0.0f};
    f32 fog_end_ {0.0f};

    Matrix34 matrixEC {};
    Matrix34 model_ {};

    i32 dword14C;
    i32 dword150;
    i32 dword154;
    i32 dword158;
    i32 dword15C;

    i32 pause_fade_ {0};
    f32 fade_speed_ {0.0f};
    f32 fade_amount_ {0.0f};
    f32 max_fade_ {0.0f};
    Vector3 fade_color_ {};
    f32 float17C;
    i32 fade_ticks_ {0};
    i32 dword184;
};

check_size(asCamera, 0x18C);

// 0x529FF0 | ?FadeItIn@@YAXPAVasCamera@@@Z
ARTS_IMPORT void FadeItIn(class asCamera* arg1);

// 0x529FD0 | ?FadeItOut@@YAXPAVasCamera@@@Z
ARTS_IMPORT void FadeItOut(class asCamera* arg1);

// 0x52A010 | ?FritzIt@@YAXPAVasCamera@@@Z
ARTS_IMPORT void FritzIt(class asCamera* arg1);

// 0x52A020 | ?ViewIt@@YAXPAVasCamera@@@Z
ARTS_IMPORT void ViewIt(class asCamera* arg1);

// 0x64DF5C | ?Duration@@3MA
ARTS_IMPORT extern f32 Duration;

// 0x790980 | ?VW@@3PAVagiViewport@@A
ARTS_IMPORT extern class agiViewport* VW;

// 0x790958 | ?asCameraMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asCameraMetaClass;
