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
    mmai:aiRailSet

    0x453BF0 | public: __thiscall aiRailSet::aiRailSet(void) | ??0aiRailSet@@QAE@XZ
    0x453CF0 | public: __thiscall aiRailSet::~aiRailSet(void) | ??1aiRailSet@@QAE@XZ
    0x453D00 | public: void __thiscall aiRailSet::CalcRailPosition(class Vector3 &,float) | ?CalcRailPosition@aiRailSet@@QAEXAAVVector3@@M@Z
    0x454710 | public: int __thiscall aiRailSet::CalcCopRailPosition(class Vector3 &,class Vector3 &,float,float) | ?CalcCopRailPosition@aiRailSet@@QAEHAAVVector3@@0MM@Z
    0x456B60 | public: int __thiscall aiRailSet::CalcRailState(float) | ?CalcRailState@aiRailSet@@QAEHM@Z
    0x457170 | public: float __thiscall aiRailSet::CalcRailLength(void) | ?CalcRailLength@aiRailSet@@QAEMXZ
    0x457660 | public: void __thiscall aiRailSet::CalcTurnIntersection(class Vector3 &,int,class aiPath *,class aiPath *) | ?CalcTurnIntersection@aiRailSet@@QAEXAAVVector3@@HPAVaiPath@@1@Z
    0x457A70 | public: void __thiscall aiRailSet::DrawTurn(float) | ?DrawTurn@aiRailSet@@QAEXM@Z
    0x458850 | public: void __thiscall aiRailSet::CalcRailPosOrient(class Vector3 &,class Vector3 &,float) | ?CalcRailPosOrient@aiRailSet@@QAEXAAVVector3@@0M@Z
    0x4593F0 | public: void __thiscall aiRailSet::SolveNextLane(void) | ?SolveNextLane@aiRailSet@@QAEXXZ
    0x459470 | public: int __thiscall aiRailSet::SolveTurnType(class aiPath *,class aiPath *) | ?SolveTurnType@aiRailSet@@QAEHPAVaiPath@@0@Z
    0x459630 | public: void __thiscall aiRailSet::CalcXZPosition(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,float) | ?CalcXZPosition@aiRailSet@@QAEXAAVVector3@@0000M@Z
    0x459740 | public: void __thiscall aiRailSet::CalcXZDirection(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,float) | ?CalcXZDirection@aiRailSet@@QAEXAAVVector3@@0000M@Z
    0x459860 | public: void __thiscall aiRailSet::CalcXZPosOrient(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,float) | ?CalcXZPosOrient@aiRailSet@@QAEXAAVVector3@@00000M@Z
    0x4599A0 | public: void __thiscall aiRailSet::ComputeXZCurve(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &) | ?ComputeXZCurve@aiRailSet@@QAEXAAVVector3@@000@Z
    0x459A50 | public: void __thiscall aiRailSet::ComputeXZCurve(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,class Vector4 &,class Vector4 &) | ?ComputeXZCurve@aiRailSet@@QAEXAAVVector3@@000AAVVector4@@1@Z
    0x459AF0 | public: void __thiscall aiRailSet::SolveXZCurve(class Vector3 &,class Vector3 &,float) | ?SolveXZCurve@aiRailSet@@QAEXAAVVector3@@0M@Z
    0x459B80 | public: void __thiscall aiRailSet::SolveXZPosition(class Vector3 &,float) | ?SolveXZPosition@aiRailSet@@QAEXAAVVector3@@M@Z
    0x459BC0 | public: void __thiscall aiRailSet::Dump(void) | ?Dump@aiRailSet@@QAEXXZ
    0x459E00 | class Vector3 __cdecl operator*(float,class Vector3 const &) | ??D@YA?AVVector3@@MABV0@@Z
    0x459E40 | public: float __thiscall Vector3::operator^(class Vector3 const &) const | ??TVector3@@QBEMABV0@@Z
    0x459E70 | public: class Vector3 __thiscall Vector3::operator-(void) const | ??GVector3@@QBE?AV0@XZ
    0x459E90 | public: class Vector3 * __thiscall aiPath::LBoundary(int) | ?LBoundary@aiPath@@QAEPAVVector3@@H@Z
*/

class aiRailSet
{
public:
    // 0x453BF0 | ??0aiRailSet@@QAE@XZ
    aiRailSet();

    // 0x453CF0 | ??1aiRailSet@@QAE@XZ
    ~aiRailSet();

    // 0x454710 | ?CalcCopRailPosition@aiRailSet@@QAEHAAVVector3@@0MM@Z
    i32 CalcCopRailPosition(class Vector3& arg1, class Vector3& arg2, f32 arg3, f32 arg4);

    // 0x457170 | ?CalcRailLength@aiRailSet@@QAEMXZ
    f32 CalcRailLength();

    // 0x458850 | ?CalcRailPosOrient@aiRailSet@@QAEXAAVVector3@@0M@Z
    void CalcRailPosOrient(class Vector3& arg1, class Vector3& arg2, f32 arg3);

    // 0x453D00 | ?CalcRailPosition@aiRailSet@@QAEXAAVVector3@@M@Z
    void CalcRailPosition(class Vector3& arg1, f32 arg2);

    // 0x456B60 | ?CalcRailState@aiRailSet@@QAEHM@Z
    i32 CalcRailState(f32 arg1);

    // 0x457660 | ?CalcTurnIntersection@aiRailSet@@QAEXAAVVector3@@HPAVaiPath@@1@Z
    void CalcTurnIntersection(class Vector3& arg1, i32 arg2, class aiPath* arg3, class aiPath* arg4);

    // 0x459740 | ?CalcXZDirection@aiRailSet@@QAEXAAVVector3@@0000M@Z | unused
    void CalcXZDirection(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
        class Vector3& arg5, f32 arg6);

    // 0x459860 | ?CalcXZPosOrient@aiRailSet@@QAEXAAVVector3@@00000M@Z
    void CalcXZPosOrient(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
        class Vector3& arg5, class Vector3& arg6, f32 arg7);

    // 0x459630 | ?CalcXZPosition@aiRailSet@@QAEXAAVVector3@@0000M@Z
    void CalcXZPosition(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
        class Vector3& arg5, f32 arg6);

    // 0x4599A0 | ?ComputeXZCurve@aiRailSet@@QAEXAAVVector3@@000@Z
    void ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4);

    // 0x459A50 | ?ComputeXZCurve@aiRailSet@@QAEXAAVVector3@@000AAVVector4@@1@Z
    void ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
        class Vector4& arg5, class Vector4& arg6);

    // 0x457A70 | ?DrawTurn@aiRailSet@@QAEXM@Z
    void DrawTurn(f32 arg1);

    // 0x459BC0 | ?Dump@aiRailSet@@QAEXXZ
    void Dump();

    // 0x4593F0 | ?SolveNextLane@aiRailSet@@QAEXXZ | unused
    void SolveNextLane();

    // 0x459470 | ?SolveTurnType@aiRailSet@@QAEHPAVaiPath@@0@Z
    i32 SolveTurnType(class aiPath* arg1, class aiPath* arg2);

    // 0x459AF0 | ?SolveXZCurve@aiRailSet@@QAEXAAVVector3@@0M@Z
    void SolveXZCurve(class Vector3& arg1, class Vector3& arg2, f32 arg3);

    // 0x459B80 | ?SolveXZPosition@aiRailSet@@QAEXAAVVector3@@M@Z | unused
    void SolveXZPosition(class Vector3& arg1, f32 arg2);
};

check_size(aiRailSet, 0x0);

// 0x459E00 | ??D@YA?AVVector3@@MABV0@@Z | inline
class Vector3 operator*(f32 arg1, class Vector3 const& arg2);
