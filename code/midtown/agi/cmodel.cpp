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

define_dummy_symbol(agi_cmodel);

#include "cmodel.h"

#include "rgba.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

u32 agiColorModel::FindColor(i32 r, i32 g, i32 b, i32 a)
{
    return FindColor(agiRgba {static_cast<u8>(r), static_cast<u8>(g), static_cast<u8>(b), static_cast<u8>(a)});
}

u32 agiColorModel::GetColor(Vector3 const& color)
{
    return GetColor(agiRgba {
        static_cast<u8>(color.x * 255.0f), static_cast<u8>(color.y * 255.0f), static_cast<u8>(color.z * 255.0f), 0xFF});
}

u32 agiColorModel::GetColor(Vector4 const& color)
{
    return GetColor(agiRgba {static_cast<u8>(color.x * 255.0f), static_cast<u8>(color.y * 255.0f),
        static_cast<u8>(color.z * 255.0f), static_cast<u8>(color.w * 255.0f)});
}

u32 agiColorModel::GetColor(i32 r, i32 g, i32 b, i32 a)
{
    return GetColor(agiRgba {static_cast<u8>(r), static_cast<u8>(g), static_cast<u8>(b), static_cast<u8>(a)});
}
