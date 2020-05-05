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

class mmWheel : public asLinearCS
{
    // const mmWheel::`vftable' @ 0x61C740

public:
    // 0x47D790 | ??0mmWheel@@QAE@XZ
    mmWheel();

    // 0x47FE00 | ??_EmmWheel@@UAEPAXI@Z
    // 0x470360 | ??1mmWheel@@UAE@XZ
    ~mmWheel() override;

    // 0x47F6D0 | ?AddWidgets@mmWheel@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x47DA10 | ?AfterLoad@mmWheel@@UAEXXZ
    void AfterLoad() override;

    // 0x47D950 | ?ComputeConstants@mmWheel@@QAEXXZ
    void ComputeConstants();

    // 0x47DBB0 | ?ComputeDwtdw@mmWheel@@QAEMMPAM00@Z
    f32 ComputeDwtdw(f32 arg1, f32* arg2, f32* arg3, f32* arg4);

    // 0x47F5F0 | ?CopyVars@mmWheel@@QAEXPAV1@@Z
    void CopyVars(class mmWheel* arg1);

    // 0x47F340 | ?GenerateSkidParticles@mmWheel@@QAEXXZ
    void GenerateSkidParticles();

    // 0x47FDC0 | ?GetClass@mmWheel@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x47F6B0 | ?GetSurfaceSound@mmWheel@@QAEHXZ
    i32 GetSurfaceSound();

    // 0x47DA20 | ?Init@mmWheel@@QAEXPAD0VVector3@@PAVasInertialCS@@HPAVmmBoundTemplate@@H@Z
    void Init(char* arg1, char* arg2, class Vector3 arg3, class asInertialCS* arg4, i32 arg5,
        class mmBoundTemplate* arg6, i32 arg7);

    // 0x47F3B0 | ?Load@mmWheel@@QAEXPAVStream@@@Z
    void Load(class Stream* arg1);

    // 0x47F2D0 | ?Reset@mmWheel@@UAEXXZ
    void Reset() override;

    // 0x47F4B0 | ?Save@mmWheel@@QAEXPAVStream@@@Z
    void Save(class Stream* arg1);

    // 0x47F380 | ?SetFricMultiplier@mmWheel@@QAEXM@Z
    void SetFricMultiplier(f32 arg1);

    // 0x47F360 | ?SetInputs@mmWheel@@QAEXMM@Z
    void SetInputs(f32 arg1, f32 arg2);

    // 0x47F3A0 | ?SetSteerMultiplier@mmWheel@@QAEXM@Z
    void SetSteerMultiplier(f32 arg1);

    // 0x47E3E0 | ?Update@mmWheel@@UAEXXZ
    void Update() override;

    // 0x47FB00 | ?DeclareFields@mmWheel@@SAXXZ
    static void DeclareFields();

    // 0x63C490 | ?PtxMaxSkidCount@mmWheel@@2MA
    static inline extern_var(0x23C490_Offset, f32, PtxMaxSkidCount);
};

check_size(mmWheel, 0x268);

// 0x6A80F4 | ?DispLatZeroThresh@@3MA
inline extern_var(0x2A80F4_Offset, f32, DispLatZeroThresh);

// 0x6A80B8 | ?mmWheelMetaClass@@3VMetaClass@@A
inline extern_var(0x2A80B8_Offset, class MetaClass, mmWheelMetaClass);
