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
    mmcamcs:spline

    0x4FD3F0 | public: __thiscall Spline::Spline(void) | ??0Spline@@QAE@XZ
    0x4FD420 | public: void __thiscall Spline::Init(float *,int) | ?Init@Spline@@QAEXPAMH@Z
    0x4FD550 | public: int __thiscall Spline::InRange(void) | ?InRange@Spline@@QAEHXZ
    0x4FD5B0 | public: void __thiscall Spline::CalcCoeff(void) | ?CalcCoeff@Spline@@QAEXXZ
    0x4FD710 | public: void __thiscall Spline::SetValue(float *) | ?SetValue@Spline@@QAEXPAM@Z
    0x4FD790 | public: void __thiscall Spline::SetGoal(float *,float) | ?SetGoal@Spline@@QAEXPAMM@Z
    0x4FD880 | public: void __thiscall Spline::Solve(float) | ?Solve@Spline@@QAEXM@Z
    0x4FD9F0 | public: void __thiscall Spline::Print(int) | ?Print@Spline@@QAEXH@Z
    0x4FDAF0 | public: void __thiscall Spline::FixTimeStop(void) | ?FixTimeStop@Spline@@QAEXXZ
    0x4FDB30 | public: virtual void __thiscall Spline::Update(void) | ?Update@Spline@@UAEXXZ
    0x4FDB80 | public: virtual void __thiscall Spline::AddWidgets(class Bank *) | ?AddWidgets@Spline@@UAEXPAVBank@@@Z
    0x4FDB90 | public: static void __cdecl Spline::DeclareFields(void) | ?DeclareFields@Spline@@SAXXZ
    0x4FDD00 | public: virtual class MetaClass * __thiscall Spline::GetClass(void) | ?GetClass@Spline@@UAEPAVMetaClass@@XZ
    0x4FDD10 | public: virtual void * __thiscall Spline::`vector deleting destructor'(unsigned int) | ??_ESpline@@UAEPAXI@Z
    0x620540 | const Spline::`vftable' | ??_7Spline@@6B@
    0x719548 | class MetaClass SplineMetaClass | ?SplineMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class Spline final : public asNode
{
public:
    // ??0Spline@@QAE@XZ
    ARTS_IMPORT Spline();

    // ??_ESpline@@UAEPAXI@Z
    // ??1Spline@@UAE@XZ | inline
    ARTS_IMPORT ~Spline() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@Spline@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?CalcCoeff@Spline@@QAEXXZ
    ARTS_IMPORT void CalcCoeff();

    // ?FixTimeStop@Spline@@QAEXXZ
    ARTS_IMPORT void FixTimeStop();

    // ?GetClass@Spline@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?InRange@Spline@@QAEHXZ
    ARTS_IMPORT i32 InRange();

    // ?Init@Spline@@QAEXPAMH@Z | unused
    ARTS_IMPORT void Init(f32* arg1, i32 arg2);

    // ?Print@Spline@@QAEXH@Z | unused
    ARTS_IMPORT void Print(i32 arg1);

    // ?SetGoal@Spline@@QAEXPAMM@Z
    ARTS_IMPORT void SetGoal(f32* arg1, f32 arg2);

    // ?SetValue@Spline@@QAEXPAM@Z
    ARTS_IMPORT void SetValue(f32* arg1);

    // ?Solve@Spline@@QAEXM@Z
    ARTS_IMPORT void Solve(f32 arg1);

    // ?Update@Spline@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@Spline@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x54];
};

check_size(Spline, 0x74);
