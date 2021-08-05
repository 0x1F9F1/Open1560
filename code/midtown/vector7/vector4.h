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
    vector7:vector4

    0x56DBA0 | public: float __thiscall Vector4::Mag(void) const | ?Mag@Vector4@@QBEMXZ
    0x56DC70 | public: class Vector4 __thiscall Vector4::operator/(float) const | ??KVector4@@QBE?AV0@M@Z
    0x56DD00 | public: class Vector4 __thiscall Vector4::operator!(void) const | ??7Vector4@@QBE?AV0@XZ
    0x56DD80 | public: void __thiscall Vector4::Bilinear(float,float,class Vector4 const &,class Vector4 const &,class Vector4 const &,class Vector4 const &) | ?Bilinear@Vector4@@QAEXMMABV1@000@Z
    0x56DDD0 | public: void __thiscall Vector4::CalculatePlane(class Vector3 const &,class Vector3 const &,class Vector3 const &) | ?CalculatePlane@Vector4@@QAEXABVVector3@@00@Z
    0x56DED0 | public: void __thiscall Vector4::GetLookAt(class Vector3 const &,class Vector3 *,class Vector3 *) const | ?GetLookAt@Vector4@@QBEXABVVector3@@PAV2@1@Z
    0x56DF50 | public: void __thiscall Vector4::Lerp(float,class Vector4 const &,class Vector4 const &) | ?Lerp@Vector4@@QAEXMABV1@0@Z
    0x56E040 | public: void __thiscall Vector4Array::Init(int) | ?Init@Vector4Array@@QAEXH@Z
    0x56E0B0 | public: void __thiscall Vector4Array::Delete(void) | ?Delete@Vector4Array@@QAEXXZ
    0x56E100 | private: void __thiscall Vector4Array::NewTable(int) | ?NewTable@Vector4Array@@AAEXH@Z
    0x56E170 | public: class Vector4 & __thiscall Vector4Array::operator[](int) | ??AVector4Array@@QAEAAVVector4@@H@Z
    0x56E1F0 | public: void __thiscall Vector4Array::operator=(class Vector4Array &) | ??4Vector4Array@@QAEXAAV0@@Z
    0x56E2F0 | public: void __thiscall Vector4Array::BlockCopy(class Vector4Array &) | ?BlockCopy@Vector4Array@@QAEXAAV1@@Z
    0x56E3F0 | public: virtual void __thiscall Vector4Type::Save(class MiniParser *,void *) | ?Save@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    0x56E430 | public: virtual void __thiscall Vector4Type::Load(class MiniParser *,void *) | ?Load@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    0x56E470 | public: virtual unsigned int __thiscall Vector4Type::SizeOf(void) | ?SizeOf@Vector4Type@@UAEIXZ
    0x56E480 | public: virtual void * __thiscall Vector4Type::New(int) | ?New@Vector4Type@@UAEPAXH@Z
    0x56E4D0 | public: virtual void __thiscall Vector4Type::Delete(void *,int) | ?Delete@Vector4Type@@UAEXPAXH@Z
    0x621C38 | const Vector4Type::`vftable' | ??_7Vector4Type@@6B@
    0x9094EC | struct Vector4Type Vector4Inst | ?Vector4Inst@@3UVector4Type@@A
*/

#include "data7/metatype.h"

class Vector4
{
public:
    constexpr inline Vector4() noexcept = default;

    constexpr inline Vector4(f32 x, f32 y, f32 z, f32 w) noexcept
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {}

    // ??7Vector4@@QBE?AV0@XZ
    ARTS_IMPORT class Vector4 operator!() const;

    // ??KVector4@@QBE?AV0@M@Z | unused
    ARTS_IMPORT class Vector4 operator/(f32 arg1) const;

    // ??TVector4@@QBEMABV0@@Z | inline
    ARTS_IMPORT f32 operator^(class Vector4 const& arg1) const;

    // ?Bilinear@Vector4@@QAEXMMABV1@000@Z | unused
    ARTS_IMPORT void Bilinear(f32 arg1, f32 arg2, class Vector4 const& arg3, class Vector4 const& arg4,
        class Vector4 const& arg5, class Vector4 const& arg6);

    // ?CalculatePlane@Vector4@@QAEXABVVector3@@00@Z
    ARTS_IMPORT void CalculatePlane(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3);

    // ?GetLookAt@Vector4@@QBEXABVVector3@@PAV2@1@Z | unused
    ARTS_IMPORT void GetLookAt(class Vector3 const& arg1, class Vector3* arg2, class Vector3* arg3) const;

    // ?Lerp@Vector4@@QAEXMABV1@0@Z
    ARTS_IMPORT void Lerp(f32 arg1, class Vector4 const& arg2, class Vector4 const& arg3);

    // ?Mag@Vector4@@QBEMXZ | unused
    ARTS_IMPORT f32 Mag() const;

    // ?Set@Vector4@@QAEXMMMM@Z | inline
    ARTS_IMPORT void Set(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    constexpr inline bool operator==(const Vector4& other) const noexcept
    {
        return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
    }

    constexpr inline bool operator!=(const Vector4& other) const noexcept
    {
        return (x != other.x) || (y != other.y) || (z != other.z) || (w != other.w);
    }

    f32 x {};
    f32 y {};
    f32 z {};
    f32 w {};
};

check_size(Vector4, 0x10);

#if 0
class Vector4Array
{
public:
    // ??4Vector4Array@@QAEXAAV0@@Z | unused
    ARTS_IMPORT void operator=(class Vector4Array& arg1);

    // ??AVector4Array@@QAEAAVVector4@@H@Z | unused
    ARTS_IMPORT class Vector4& operator[](i32 arg1);

    // ?BlockCopy@Vector4Array@@QAEXAAV1@@Z | unused
    ARTS_IMPORT void BlockCopy(class Vector4Array& arg1);

    // ?Delete@Vector4Array@@QAEXXZ
    ARTS_IMPORT void Delete();

    // ?Init@Vector4Array@@QAEXH@Z | unused
    ARTS_IMPORT void Init(i32 arg1);

private:
    // ?NewTable@Vector4Array@@AAEXH@Z
    ARTS_IMPORT void NewTable(i32 arg1);

    u8 gap0[0x14];
};

check_size(Vector4Array, 0x14);

struct Vector4Type final : MetaType
{
    // const Vector4Type::`vftable'

public:
    // ?Delete@Vector4Type@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(class MiniParser* arg1, void* arg2) override;

    // ?New@Vector4Type@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(class MiniParser* arg1, void* arg2) override;

    // ?SizeOf@Vector4Type@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;
};

check_size(Vector4Type, 0x4);

// ?Vector4Inst@@3UVector4Type@@A
ARTS_IMPORT extern struct Vector4Type Vector4Inst;
#endif
