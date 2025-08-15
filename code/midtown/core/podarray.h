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

#include <type_traits>

// A simple wrapper to avoid default constructing elements
template <typename T, std::size_t N>
struct PodArray
{
    static_assert(std::is_trivially_copy_assignable_v<T>);

    alignas(T) unsigned char Data[N][sizeof(T)];

    ARTS_FORCEINLINE operator T*()
    {
        return reinterpret_cast<T*>(Data);
    }

    ARTS_FORCEINLINE operator const T*() const
    {
        return reinterpret_cast<const T*>(Data);
    }
};
