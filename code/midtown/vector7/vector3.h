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
    vector7:vector3

    0x564AE0 | public: void __fastcall Vector3::Dot(class Vector3 const &,class Matrix34 const &) | ?Dot@Vector3@@QAIXABV1@ABVMatrix34@@@Z
    0x564B50 | public: void __fastcall Vector3::Dot3x3(class Vector3 const &,class Matrix34 const &) | ?Dot3x3@Vector3@@QAIXABV1@ABVMatrix34@@@Z
    0x564BB0 | public: float __thiscall Vector3::Cos(class Vector3 const &) const | ?Cos@Vector3@@QBEMABV1@@Z
    0x564CF0 | public: float __thiscall Vector3::Angle(class Vector3 const &) const | ?Angle@Vector3@@QBEMABV1@@Z
    0x564EC0 | public: float __thiscall Vector3::Area(class Vector3 const &,class Vector3 const &) const | ?Area@Vector3@@QBEMABV1@0@Z
    0x564F60 | public: class Vector3 __thiscall Vector3::Project(class Vector3 &) | ?Project@Vector3@@QAE?AV1@AAV1@@Z
    0x565000 | public: float __thiscall Vector3::Atan3(char,char) const | ?Atan3@Vector3@@QBEMDD@Z
    0x5651C0 | public: class Vector3 __thiscall Vector3::Reflect(class Vector3 const &) const | ?Reflect@Vector3@@QBE?AV1@ABV1@@Z
    0x5652C0 | public: void __thiscall Vector3::Rotate(float,int) | ?Rotate@Vector3@@QAEXMH@Z
    0x565490 | public: int __thiscall Vector3::HalfSpace(class Vector4 const &) const | ?HalfSpace@Vector3@@QBEHABVVector4@@@Z
    0x565540 | public: int __thiscall Vector3::RayIntersectPlane(class Vector3 const &,class Vector3 const &,class Vector4 const &,float) | ?RayIntersectPlane@Vector3@@QAEHABV1@0ABVVector4@@M@Z
    0x5656A0 | public: int __thiscall Vector3::Approach(class Vector3 const &,float,float,float *) | ?Approach@Vector3@@QAEHABV1@MMPAM@Z
    0x5657E0 | public: void __thiscall Vector3::CatmullRom(float,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &) | ?CatmullRom@Vector3@@QAEXMABV1@000@Z
    0x565990 | public: void __thiscall Vector3::Slerp(float,class Vector3 const &,class Vector3 const &) | ?Slerp@Vector3@@QAEXMABV1@0@Z
    0x565B50 | public: void __thiscall Vector3::Hermite(float,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &,float) | ?Hermite@Vector3@@QAEXMABV1@000M@Z
    0x565D00 | public: void __thiscall Vector3::Bilinear(float,float,class Vector3 const &,class Vector3 const &,class Vector3 const &,class Vector3 const &) | ?Bilinear@Vector3@@QAEXMMABV1@000@Z
    0x565DD0 | public: float __thiscall Vector3::PointToLine(class Vector3 const &,class Vector3 const &) const | ?PointToLine@Vector3@@QBEMABV1@0@Z
    0x565EB0 | public: float __thiscall Vector3::PointToSegment(class Vector3 const &,class Vector3 const &,class Vector3 &,int &,float *) const | ?PointToSegment@Vector3@@QBEMABV1@0AAV1@AAHPAM@Z
    0x566080 | public: float __thiscall Vector3::PointToSegment2(class Vector3 const &,class Vector3 const &,class Vector3 &,int &,float *) const | ?PointToSegment2@Vector3@@QBEMABV1@0AAV1@AAHPAM@Z
    0x5662A0 | public: unsigned int __thiscall Vector3::Equal(class Vector3 const &,float) const | ?Equal@Vector3@@QBEIABV1@M@Z
    0x566300 | public: void __thiscall Vector3::rgbtohsv(void) | ?rgbtohsv@Vector3@@QAEXXZ
    0x566420 | public: void __thiscall Vector3::hsvtorgb(void) | ?hsvtorgb@Vector3@@QAEXXZ
    0x566550 | public: void __thiscall Vector3::Clamp(float,float) | ?Clamp@Vector3@@QAEXMM@Z
    0x5665E0 | public: void __thiscall Vector3::Clamp(class Vector3 const &,class Vector3 const &) | ?Clamp@Vector3@@QAEXABV1@0@Z
    0x566680 | public: void __thiscall Vector3::GetPolar(class Vector3 const &,class Vector4 *,class Vector3 *) const | ?GetPolar@Vector3@@QBEXABV1@PAVVector4@@PAV1@@Z
    0x5667C0 | public: void __thiscall Vector3::Rebound(class Vector3 const &,float) | ?Rebound@Vector3@@QAEXABV1@M@Z
    0x566820 | public: void __thiscall Vector3::Bounce(class Vector3 const &,float) | ?Bounce@Vector3@@QAEXABV1@M@Z
    0x5668A0 | public: float __thiscall Vector3::Mag(void) const | ?Mag@Vector3@@QBEMXZ
    0x566960 | public: float __thiscall Vector3::InvMag(void) const | ?InvMag@Vector3@@QBEMXZ
    0x5669C0 | public: float __thiscall Vector3::Dist(class Vector3 const &) const | ?Dist@Vector3@@QBEMABV1@@Z
    0x566A80 | void __cdecl TransformVertNorm(class Vector3 &,class Vector3 &,class Vector3 const &,class Vector3 &,class Matrix34 const &) | ?TransformVertNorm@@YAXAAVVector3@@0ABV1@0ABVMatrix34@@@Z
    0x566B70 | void __cdecl TransformVertList(class Vector3 *,class Vector3 const *,int,class Matrix34 const &) | ?TransformVertList@@YAXPAVVector3@@PBV1@HABVMatrix34@@@Z
    0x566C30 | void __cdecl TransformVertList(class Vector3 * *,class Vector3 const * *,int,class Matrix34 const &) | ?TransformVertList@@YAXPAPAVVector3@@PAPBV1@HABVMatrix34@@@Z
    0x566D00 | void __cdecl TransformNormalList(class Vector3 *,class Vector3 const *,int,class Matrix34 const &) | ?TransformNormalList@@YAXPAVVector3@@PBV1@HABVMatrix34@@@Z
    0x566DD0 | void __cdecl TransformNormalList(class Vector3 * *,class Vector3 const * *,int,class Matrix34 const &) | ?TransformNormalList@@YAXPAPAVVector3@@PAPBV1@HABVMatrix34@@@Z
    0x566E80 | public: void __thiscall Vector3Array::Init(int) | ?Init@Vector3Array@@QAEXH@Z
    0x566EF0 | public: void __thiscall Vector3Array::Delete(void) | ?Delete@Vector3Array@@QAEXXZ
    0x566F40 | private: void __thiscall Vector3Array::NewTable(int) | ?NewTable@Vector3Array@@AAEXH@Z
    0x566FB0 | public: class Vector3 & __thiscall Vector3Array::operator[](int) | ??AVector3Array@@QAEAAVVector3@@H@Z
    0x567030 | public: void __thiscall Vector3Array::operator=(class Vector3Array &) | ??4Vector3Array@@QAEXAAV0@@Z
    0x567120 | public: void __thiscall Vector3Array::BlockCopy(class Vector3Array &) | ?BlockCopy@Vector3Array@@QAEXAAV1@@Z
    0x567320 | public: virtual void __thiscall Vector3Type::Save(class MiniParser *,void *) | ?Save@Vector3Type@@UAEXPAVMiniParser@@PAX@Z
    0x567360 | public: virtual void __thiscall Vector3Type::Load(class MiniParser *,void *) | ?Load@Vector3Type@@UAEXPAVMiniParser@@PAX@Z
    0x567390 | public: virtual unsigned int __thiscall Vector3Type::SizeOf(void) | ?SizeOf@Vector3Type@@UAEIXZ
    0x5673A0 | public: virtual void * __thiscall Vector3Type::New(int) | ?New@Vector3Type@@UAEPAXH@Z
    0x5673F0 | public: virtual void __thiscall Vector3Type::Delete(void *,int) | ?Delete@Vector3Type@@UAEXPAXH@Z
    0x621BA0 | const Vector3Type::`vftable' | ??_7Vector3Type@@6B@
    0x909450 | class Vector3 ORIGIN | ?ORIGIN@@3VVector3@@A
    0x909460 | class Vector3 XAXIS | ?XAXIS@@3VVector3@@A
    0x90946C | struct Vector3Type Vector3Inst | ?Vector3Inst@@3UVector3Type@@A
    0x909470 | class Vector3 YAXIS | ?YAXIS@@3VVector3@@A
    0x909480 | class Vector3 ZAXIS | ?ZAXIS@@3VVector3@@A
*/

#include "core/endian.h"
#include "data7/metatype.h"

class Vector3
{
public:
    constexpr inline Vector3() noexcept = default;

    // 0x43C100 | ??0Vector3@@QAE@MMM@Z | inline
    constexpr inline Vector3(f32 x, f32 y, f32 z) noexcept
        : x(x)
        , y(y)
        , z(z)
    {}

    // 0x45C420 | ??LVector3@@QBE?AV0@ABV0@@Z | inline
    ARTS_IMPORT class Vector3 operator%(class Vector3 const& arg1) const;

    // 0x451320 | ??DVector3@@QBE?AV0@M@Z | inline
    ARTS_EXPORT class Vector3 operator*(f32 value) const
    {
        return {x * value, y * value, z * value};
    }

    // 0x4DEBD0 | ??XVector3@@QAEXM@Z | inline
    ARTS_EXPORT void operator*=(f32 value)
    {
        *this = {x * value, y * value, z * value};
    }

    // 0x4512F0 | ??HVector3@@QBE?AV0@ABV0@@Z | inline
    ARTS_EXPORT class Vector3 operator+(class Vector3 const& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    // 0x4DBB50 | ??YVector3@@QAEXABV0@@Z | inline
    ARTS_EXPORT void operator+=(class Vector3 const& other)
    {
        *this = {x + other.x, y + other.y, z + other.z};
    }

    // 0x459E70 | ??GVector3@@QBE?AV0@XZ | inline
    ARTS_EXPORT class Vector3 operator-() const
    {
        return {-x, -y, -z};
    }

    // 0x43FFA0 | ??GVector3@@QBE?AV0@ABV0@@Z | inline
    ARTS_EXPORT class Vector3 operator-(class Vector3 const& other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    // 0x4DEBA0 | ??ZVector3@@QAEXABV0@@Z | inline
    ARTS_EXPORT void operator-=(class Vector3 const& other)
    {
        *this = {x - other.x, y - other.y, z - other.z};
    }

    // 0x4D9080 | ??KVector3@@QBE?AV0@M@Z | inline
    ARTS_IMPORT class Vector3 operator/(f32 arg1) const;

    // 0x4DEB70 | ??TVector3@@QBE?AV0@ABVMatrix34@@@Z | inline
    ARTS_IMPORT class Vector3 operator^(class Matrix34 const& arg1) const;

    // 0x459E40 | ??TVector3@@QBEMABV0@@Z | inline
    ARTS_IMPORT f32 operator^(class Vector3 const& arg1) const;

    // 0x570D00 | ??SVector3@@QBE?AV0@XZ | inline
    ARTS_IMPORT class Vector3 operator~() const;

    // 0x52BB70 | ?Add@Vector3@@QAEXABV1@0@Z | inline
    ARTS_IMPORT void Add(class Vector3 const& arg1, class Vector3 const& arg2);

    // 0x564CF0 | ?Angle@Vector3@@QBEMABV1@@Z
    ARTS_IMPORT f32 Angle(class Vector3 const& arg1) const;

    // 0x5656A0 | ?Approach@Vector3@@QAEHABV1@MMPAM@Z
    ARTS_IMPORT i32 Approach(class Vector3 const& arg1, f32 arg2, f32 arg3, f32* arg4);

    // 0x564EC0 | ?Area@Vector3@@QBEMABV1@0@Z
    ARTS_IMPORT f32 Area(class Vector3 const& arg1, class Vector3 const& arg2) const;

    // 0x565000 | ?Atan3@Vector3@@QBEMDD@Z | unused
    ARTS_IMPORT f32 Atan3(char arg1, char arg2) const;

    // 0x565D00 | ?Bilinear@Vector3@@QAEXMMABV1@000@Z | unused
    ARTS_IMPORT void Bilinear(f32 arg1, f32 arg2, class Vector3 const& arg3, class Vector3 const& arg4,
        class Vector3 const& arg5, class Vector3 const& arg6);

    // 0x566820 | ?Bounce@Vector3@@QAEXABV1@M@Z | unused
    ARTS_IMPORT void Bounce(class Vector3 const& arg1, f32 arg2);

    // 0x5657E0 | ?CatmullRom@Vector3@@QAEXMABV1@000@Z | unused
    ARTS_IMPORT void CatmullRom(f32 arg1, class Vector3 const& arg2, class Vector3 const& arg3,
        class Vector3 const& arg4, class Vector3 const& arg5);

    // 0x5665E0 | ?Clamp@Vector3@@QAEXABV1@0@Z | unused
    ARTS_IMPORT void Clamp(class Vector3 const& arg1, class Vector3 const& arg2);

    // 0x566550 | ?Clamp@Vector3@@QAEXMM@Z | unused
    ARTS_IMPORT void Clamp(f32 arg1, f32 arg2);

    // 0x564BB0 | ?Cos@Vector3@@QBEMABV1@@Z | unused
    ARTS_IMPORT f32 Cos(class Vector3 const& arg1) const;

    // 0x5724F0 | ?Cross@Vector3@@QAEXABV1@0@Z | inline
    ARTS_IMPORT void Cross(class Vector3 const& arg1, class Vector3 const& arg2);

    // 0x5669C0 | ?Dist@Vector3@@QBEMABV1@@Z
    ARTS_IMPORT f32 Dist(class Vector3 const& arg1) const;

    // 0x564AE0 | ?Dot@Vector3@@QAIXABV1@ABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL Dot(class Vector3 const& arg1, class Matrix34 const& arg2);

    // 0x564B50 | ?Dot3x3@Vector3@@QAIXABV1@ABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL Dot3x3(class Vector3 const& arg1, class Matrix34 const& arg2);

    // 0x5662A0 | ?Equal@Vector3@@QBEIABV1@M@Z
    ARTS_IMPORT u32 Equal(class Vector3 const& arg1, f32 arg2) const;

    // 0x566680 | ?GetPolar@Vector3@@QBEXABV1@PAVVector4@@PAV1@@Z
    ARTS_IMPORT void GetPolar(class Vector3 const& arg1, class Vector4* arg2, class Vector3* arg3) const;

    // 0x565490 | ?HalfSpace@Vector3@@QBEHABVVector4@@@Z | unused
    ARTS_IMPORT i32 HalfSpace(class Vector4 const& arg1) const;

    // 0x565B50 | ?Hermite@Vector3@@QAEXMABV1@000M@Z | unused
    ARTS_IMPORT void Hermite(f32 arg1, class Vector3 const& arg2, class Vector3 const& arg3, class Vector3 const& arg4,
        class Vector3 const& arg5, f32 arg6);

    // 0x566960 | ?InvMag@Vector3@@QBEMXZ
    ARTS_IMPORT f32 InvMag() const;

    // 0x5668A0 | ?Mag@Vector3@@QBEMXZ
    ARTS_IMPORT f32 Mag() const;

    // 0x5724D0 | ?Neg@Vector3@@QAEXABV1@@Z | inline
    ARTS_IMPORT void Neg(class Vector3 const& arg1);

    // 0x565DD0 | ?PointToLine@Vector3@@QBEMABV1@0@Z | unused
    ARTS_IMPORT f32 PointToLine(class Vector3 const& arg1, class Vector3 const& arg2) const;

    // 0x565EB0 | ?PointToSegment@Vector3@@QBEMABV1@0AAV1@AAHPAM@Z | unused
    ARTS_IMPORT f32 PointToSegment(
        class Vector3 const& arg1, class Vector3 const& arg2, class Vector3& arg3, i32& arg4, f32* arg5) const;

    // 0x566080 | ?PointToSegment2@Vector3@@QBEMABV1@0AAV1@AAHPAM@Z | unused
    ARTS_IMPORT f32 PointToSegment2(
        class Vector3 const& arg1, class Vector3 const& arg2, class Vector3& arg3, i32& arg4, f32* arg5) const;

    // 0x564F60 | ?Project@Vector3@@QAE?AV1@AAV1@@Z | unused
    ARTS_IMPORT class Vector3 Project(class Vector3& arg1);

    // 0x565540 | ?RayIntersectPlane@Vector3@@QAEHABV1@0ABVVector4@@M@Z | unused
    ARTS_IMPORT i32 RayIntersectPlane(
        class Vector3 const& arg1, class Vector3 const& arg2, class Vector4 const& arg3, f32 arg4);

    // 0x5667C0 | ?Rebound@Vector3@@QAEXABV1@M@Z | unused
    ARTS_IMPORT void Rebound(class Vector3 const& arg1, f32 arg2);

    // 0x5651C0 | ?Reflect@Vector3@@QBE?AV1@ABV1@@Z | unused
    ARTS_IMPORT class Vector3 Reflect(class Vector3 const& arg1) const;

    // 0x5652C0 | ?Rotate@Vector3@@QAEXMH@Z
    ARTS_IMPORT void Rotate(f32 arg1, i32 arg2);

    // 0x45C470 | ?Scale@Vector3@@QAEXABV1@M@Z | inline
    ARTS_IMPORT void Scale(class Vector3 const& arg1, f32 arg2);

    // 0x4DBB30 | ?Set@Vector3@@QAEXMMM@Z | inline
    ARTS_IMPORT void Set(f32 arg1, f32 arg2, f32 arg3);

    // 0x565990 | ?Slerp@Vector3@@QAEXMABV1@0@Z | unused
    ARTS_IMPORT void Slerp(f32 arg1, class Vector3 const& arg2, class Vector3 const& arg3);

    // 0x566420 | ?hsvtorgb@Vector3@@QAEXXZ | unused
    ARTS_IMPORT void hsvtorgb();

    // 0x566300 | ?rgbtohsv@Vector3@@QAEXXZ | unused
    ARTS_IMPORT void rgbtohsv();

    f32 Dist2(const Vector3& other) const
    {
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

    f32 x {};
    f32 y {};
    f32 z {};
};

check_size(Vector3, 0xC);

// 0x566D00 | ?TransformNormalList@@YAXPAVVector3@@PBV1@HABVMatrix34@@@Z | unused
ARTS_IMPORT void TransformNormalList(
    class Vector3* arg1, class Vector3 const* arg2, i32 arg3, class Matrix34 const& arg4);

// 0x566DD0 | ?TransformNormalList@@YAXPAPAVVector3@@PAPBV1@HABVMatrix34@@@Z | unused
ARTS_IMPORT void TransformNormalList(
    class Vector3** arg1, class Vector3 const** arg2, i32 arg3, class Matrix34 const& arg4);

// 0x566B70 | ?TransformVertList@@YAXPAVVector3@@PBV1@HABVMatrix34@@@Z
ARTS_IMPORT void TransformVertList(
    class Vector3* arg1, class Vector3 const* arg2, i32 arg3, class Matrix34 const& arg4);

// 0x566C30 | ?TransformVertList@@YAXPAPAVVector3@@PAPBV1@HABVMatrix34@@@Z | unused
ARTS_IMPORT void TransformVertList(
    class Vector3** arg1, class Vector3 const** arg2, i32 arg3, class Matrix34 const& arg4);

// 0x566A80 | ?TransformVertNorm@@YAXAAVVector3@@0ABV1@0ABVMatrix34@@@Z | unused
ARTS_IMPORT void TransformVertNorm(class Vector3& arg1, class Vector3& arg2, class Vector3 const& arg3,
    class Vector3& arg4, class Matrix34 const& arg5);

// 0x909450 | ?ORIGIN@@3VVector3@@A
ARTS_IMPORT extern class Vector3 ORIGIN;

// 0x90946C | ?Vector3Inst@@3UVector3Type@@A
// ARTS_IMPORT struct Vector3Type Vector3Inst;

// 0x909460 | ?XAXIS@@3VVector3@@A
ARTS_IMPORT extern class Vector3 XAXIS;

// 0x909470 | ?YAXIS@@3VVector3@@A
ARTS_IMPORT extern class Vector3 YAXIS;

// 0x909480 | ?ZAXIS@@3VVector3@@A
ARTS_IMPORT extern class Vector3 ZAXIS;

#if 0
class Vector3Array
{
public:
    // 0x567030 | ??4Vector3Array@@QAEXAAV0@@Z | unused
    ARTS_IMPORT void operator=(class Vector3Array& arg1);

    // 0x566FB0 | ??AVector3Array@@QAEAAVVector3@@H@Z | unused
    ARTS_IMPORT class Vector3& operator[](i32 arg1);

    // 0x567120 | ?BlockCopy@Vector3Array@@QAEXAAV1@@Z | unused
    ARTS_IMPORT void BlockCopy(class Vector3Array& arg1);

    // 0x566EF0 | ?Delete@Vector3Array@@QAEXXZ
    ARTS_IMPORT void Delete();

    // 0x566E80 | ?Init@Vector3Array@@QAEXH@Z | unused
    ARTS_IMPORT void Init(i32 arg1);

private:
    // 0x566F40 | ?NewTable@Vector3Array@@AAEXH@Z
    ARTS_IMPORT void NewTable(i32 arg1);
};

check_size(Vector3Array, 0x14);
#endif

template <>
const MetaType* CreateMetaType_<Vector3>();

template <>
ARTS_FORCEINLINE void ByteSwap<Vector3>(Vector3& value) noexcept
{
    ByteSwap(value.x);
    ByteSwap(value.y);
    ByteSwap(value.z);
}
