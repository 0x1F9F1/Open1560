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
    mmcar:wheel

    0x47D790 | public: __thiscall mmWheel::mmWheel(void) | ??0mmWheel@@QAE@XZ
    0x47D950 | public: void __thiscall mmWheel::ComputeConstants(void) | ?ComputeConstants@mmWheel@@QAEXXZ
    0x47DA10 | public: virtual void __thiscall mmWheel::AfterLoad(void) | ?AfterLoad@mmWheel@@UAEXXZ
    0x47DA20 | public: void __thiscall mmWheel::Init(char *,char *,class Vector3,class asInertialCS *,int,class mmBoundTemplate *,int) | ?Init@mmWheel@@QAEXPAD0VVector3@@PAVasInertialCS@@HPAVmmBoundTemplate@@H@Z
    0x47DBB0 | public: float __thiscall mmWheel::ComputeDwtdw(float,float *,float *,float *) | ?ComputeDwtdw@mmWheel@@QAEMMPAM00@Z
    0x47E3E0 | public: virtual void __thiscall mmWheel::Update(void) | ?Update@mmWheel@@UAEXXZ
    0x47F2D0 | public: virtual void __thiscall mmWheel::Reset(void) | ?Reset@mmWheel@@UAEXXZ
    0x47F340 | public: void __thiscall mmWheel::GenerateSkidParticles(void) | ?GenerateSkidParticles@mmWheel@@QAEXXZ
    0x47F360 | public: void __thiscall mmWheel::SetInputs(float,float) | ?SetInputs@mmWheel@@QAEXMM@Z
    0x47F380 | public: void __thiscall mmWheel::SetFricMultiplier(float) | ?SetFricMultiplier@mmWheel@@QAEXM@Z
    0x47F3A0 | public: void __thiscall mmWheel::SetSteerMultiplier(float) | ?SetSteerMultiplier@mmWheel@@QAEXM@Z
    0x47F3B0 | public: void __thiscall mmWheel::Load(class Stream *) | ?Load@mmWheel@@QAEXPAVStream@@@Z
    0x47F4B0 | public: void __thiscall mmWheel::Save(class Stream *) | ?Save@mmWheel@@QAEXPAVStream@@@Z
    0x47F5F0 | public: void __thiscall mmWheel::CopyVars(class mmWheel *) | ?CopyVars@mmWheel@@QAEXPAV1@@Z
    0x47F6B0 | public: int __thiscall mmWheel::GetSurfaceSound(void) | ?GetSurfaceSound@mmWheel@@QAEHXZ
    0x47F6D0 | public: virtual void __thiscall mmWheel::AddWidgets(class Bank *) | ?AddWidgets@mmWheel@@UAEXPAVBank@@@Z
    0x47FB00 | public: static void __cdecl mmWheel::DeclareFields(void) | ?DeclareFields@mmWheel@@SAXXZ
    0x47FDC0 | public: virtual class MetaClass * __thiscall mmWheel::GetClass(void) | ?GetClass@mmWheel@@UAEPAVMetaClass@@XZ
    0x47FE00 | public: virtual void * __thiscall mmWheel::`vector deleting destructor'(unsigned int) | ??_EmmWheel@@UAEPAXI@Z
    0x61C740 | const mmWheel::`vftable' | ??_7mmWheel@@6B@
    0x63C490 | public: static float mmWheel::PtxMaxSkidCount | ?PtxMaxSkidCount@mmWheel@@2MA
    0x6A80B8 | class MetaClass mmWheelMetaClass | ?mmWheelMetaClass@@3VMetaClass@@A
    0x6A80F4 | float DispLatZeroThresh | ?DispLatZeroThresh@@3MA
*/

#include "arts7/linear.h"
#include "mmdyna/isect.h"

class agiPhysParameters;
class asInertialCS;
class mmBoundTemplate;
class mmCarSim;
class mmPolygon;

class mmWheel final : public asLinearCS
{
public:
    // ??0mmWheel@@QAE@XZ
    ARTS_IMPORT mmWheel();

    // ??_EmmWheel@@UAEPAXI@Z
    // ??1mmWheel@@UAE@XZ | inline
    ARTS_EXPORT ~mmWheel() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmWheel@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AfterLoad@mmWheel@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // ?ComputeConstants@mmWheel@@QAEXXZ
    ARTS_IMPORT void ComputeConstants();

    // ?ComputeDwtdw@mmWheel@@QAEMMPAM00@Z
    ARTS_IMPORT f32 ComputeDwtdw(f32 arg1, f32* arg2, f32* arg3, f32* arg4);

    // ?CopyVars@mmWheel@@QAEXPAV1@@Z
    ARTS_IMPORT void CopyVars(mmWheel* arg1);

    // ?GenerateSkidParticles@mmWheel@@QAEXXZ
    ARTS_EXPORT void GenerateSkidParticles();

    // ?GetClass@mmWheel@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetSurfaceSound@mmWheel@@QAEHXZ
    ARTS_IMPORT i32 GetSurfaceSound();

    // ?Init@mmWheel@@QAEXPAD0VVector3@@PAVasInertialCS@@HPAVmmBoundTemplate@@H@Z
    ARTS_IMPORT void Init(
        char* arg1, char* arg2, Vector3 arg3, asInertialCS* arg4, i32 arg5, mmBoundTemplate* arg6, i32 arg7);

    // ?Load@mmWheel@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Load(Stream* arg1);

    // ?Reset@mmWheel@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Save@mmWheel@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Save(Stream* arg1);

    // ?SetFricMultiplier@mmWheel@@QAEXM@Z
    ARTS_IMPORT void SetFricMultiplier(f32 arg1);

    // ?SetInputs@mmWheel@@QAEXMM@Z
    ARTS_IMPORT void SetInputs(f32 arg1, f32 arg2);

    // ?SetSteerMultiplier@mmWheel@@QAEXM@Z
    ARTS_IMPORT void SetSteerMultiplier(f32 arg1);

    // ?Update@mmWheel@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmWheel@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?PtxMaxSkidCount@mmWheel@@2MA
    ARTS_IMPORT static f32 PtxMaxSkidCount;

    mmCarSim* CarSim;
    asInertialCS* ICS;
    i32 Flags;
    f32 Spring;
    f32 Damping;
    f32 SteeringRatio;
    f32 BrakeRatio;
    f32 StaticFriction;
    f32 SuspensionLimit;
    f32 SuspensionBlend;
    f32 RenderableSuspensionLimit;
    i32 NumWheels;
    mmIntersection Intersection;
    i32 dword168;
    Vector3 field_16C;
    Vector3 field_178;
    Vector3 field_184;
    Vector3 Center;
    Vector3 Position;
    f32 Radius;
    f32 Width;
    f32 NormalLoad;
    f32 BumpHeight;
    f32 BumpWidth;
    f32 BumpDepth;
    i32 dword1C0;
    i32 gap1C4;
    f32 Wobble;
    f32 Rotation;
    f32 MaybeGrip;
    f32 Steering;
    f32 Suspension;
    f32 CurrentLoad;
    f32 BlendedLoad;
    f32 dword1E4;
    f32 OtherNormalLoad;
    i32 FullUpdated;
    b32 OnGround;
    f32 Friction;
    f32 CurrentTireDispLat;
    f32 CurrentTireDispLong;
    f32 TireGripLat;
    f32 TireGripLong;
    f32 TireResistance;
    f32 RotationSpeed;
    f32 LatSlipPercent;
    f32 LongSlipPercent;
    f32 RubberSpring;
    f32 RubberDamp;
    f32 OptimumSlipPercent;
    f32 StaticFric;
    f32 SlidingFric;
    f32 RubberSpringLat;
    f32 RubberDampLat;
    f32 FricMultiplier;
    f32 SteerMultiplier;
    f32 UnkFriction1;
    f32 UnkFriction2;
    i32 dword244;
    f32 SteeringInput;
    f32 BrakingInput;
    mmBoundTemplate* Bound;
    mmPolygon* HitPoly;
    agiPhysParameters* Phys;
    f32 PtxCount;
    f32 ParticleCount;
    i32 field_264;
};

check_size(mmWheel, 0x268);

// ?DispLatZeroThresh@@3MA
ARTS_IMPORT extern f32 DispLatZeroThresh;
