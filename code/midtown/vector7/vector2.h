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
    vector7:vector2

    0x571110 | public: class Vector2 __thiscall Vector2::operator/(float) const | ??KVector2@@QBE?AV0@M@Z
    0x571170 | public: class Vector2 __thiscall Vector2::operator~(void) const | ??SVector2@@QBE?AV0@XZ
    0x5711E0 | public: float __thiscall Vector2::Mag(void) const | ?Mag@Vector2@@QBEMXZ
    0x571260 | public: float __thiscall Vector2::InvMag(void) const | ?InvMag@Vector2@@QBEMXZ
    0x5712C0 | public: void __thiscall Vector2Array::Init(int) | ?Init@Vector2Array@@QAEXH@Z
    0x571330 | public: void __thiscall Vector2Array::Delete(void) | ?Delete@Vector2Array@@QAEXXZ
    0x571380 | private: void __thiscall Vector2Array::NewTable(int) | ?NewTable@Vector2Array@@AAEXH@Z
    0x5713F0 | public: class Vector2 & __thiscall Vector2Array::operator[](int) | ??AVector2Array@@QAEAAVVector2@@H@Z
    0x571460 | public: void __thiscall Vector2Array::operator=(class Vector2Array &) | ??4Vector2Array@@QAEXAAV0@@Z
    0x571540 | public: void __thiscall Vector2Array::BlockCopy(class Vector2Array &) | ?BlockCopy@Vector2Array@@QAEXAAV1@@Z
    0x571640 | public: virtual void __thiscall Vector2Type::Save(class MiniParser *,void *) | ?Save@Vector2Type@@UAEXPAVMiniParser@@PAX@Z
    0x571670 | public: virtual void __thiscall Vector2Type::Load(class MiniParser *,void *) | ?Load@Vector2Type@@UAEXPAVMiniParser@@PAX@Z
    0x5716A0 | public: virtual unsigned int __thiscall Vector2Type::SizeOf(void) | ?SizeOf@Vector2Type@@UAEIXZ
    0x5716B0 | public: virtual void * __thiscall Vector2Type::New(int) | ?New@Vector2Type@@UAEPAXH@Z
    0x571700 | public: virtual void __thiscall Vector2Type::Delete(void *,int) | ?Delete@Vector2Type@@UAEXPAXH@Z
    0x621CD0 | const Vector2Type::`vftable' | ??_7Vector2Type@@6B@
    0x909644 | struct Vector2Type Vector2Inst | ?Vector2Inst@@3UVector2Type@@A
*/

#include "core/endian.h"
#include "data7/metatype.h"

class Vector2
{
public:
    constexpr inline Vector2() noexcept = default;

    constexpr inline Vector2(f32 x, f32 y) noexcept
        : x(x)
        , y(y)
    {}

    // ??KVector2@@QBE?AV0@M@Z | unused
    ARTS_IMPORT Vector2 operator/(f32 arg1) const;

    inline Vector2 operator*(f32 value) const
    {
        return {x * value, y * value};
    }

    // ??SVector2@@QBE?AV0@XZ | unused
    ARTS_EXPORT inline Vector2 operator~() const
    {
        return *this * InvMag();
    }

    // ?InvMag@Vector2@@QBEMXZ
    ARTS_IMPORT f32 InvMag() const;

    // ?Mag@Vector2@@QBEMXZ
    ARTS_IMPORT f32 Mag() const;

    constexpr inline bool operator==(const Vector2& other) const noexcept
    {
        return (x == other.x) && (y == other.y);
    }

    constexpr inline bool operator!=(const Vector2& other) const noexcept
    {
        return (x != other.x) || (y != other.y);
    }

    f32 x {};
    f32 y {};
};

check_size(Vector2, 0x8);

#if 0
class Vector2Array
{
public:
    // ??4Vector2Array@@QAEXAAV0@@Z | unused
    ARTS_IMPORT void operator=(Vector2Array& arg1);

    // ??AVector2Array@@QAEAAVVector2@@H@Z | unused
    ARTS_IMPORT Vector2& operator[](i32 arg1);

    // ?BlockCopy@Vector2Array@@QAEXAAV1@@Z | unused
    ARTS_IMPORT void BlockCopy(Vector2Array& arg1);

    // ?Delete@Vector2Array@@QAEXXZ
    ARTS_IMPORT void Delete();

    // ?Init@Vector2Array@@QAEXH@Z | unused
    ARTS_IMPORT void Init(i32 arg1);

private:
    // ?NewTable@Vector2Array@@AAEXH@Z
    ARTS_IMPORT void NewTable(i32 arg1);

    u8 gap0[0x14];
};

check_size(Vector2Array, 0x14);

struct Vector2Type final : MetaType
{
    public:
    // ?Delete@Vector2Type@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@Vector2Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@Vector2Type@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@Vector2Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@Vector2Type@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(Vector2Type, 0x4);

// ?Vector2Inst@@3UVector2Type@@A
ARTS_IMPORT extern Vector2Type Vector2Inst;
#endif

template <>
ARTS_FORCEINLINE Vector2 ByteSwap<Vector2>(Vector2 value) noexcept
{
    ByteSwapV(value.x, value.y);
    return value;
}
