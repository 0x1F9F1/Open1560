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

#include <memory>
#include <type_traits>

template <typename T>
using Ptr = std::unique_ptr<T>;

#ifdef ARTS_STANDALONE
template <typename T>
using Owner = Ptr<T>;

#    define AsPtr(PTR) (PTR)
#    define AsOwner(PTR) (std::move((PTR)))
#    define AsRaw(PTR) ((PTR).release())
#else
template <typename T>
using Owner = T*;

#    define AsPtr(PTR) (Ptr<std::remove_pointer_t<decltype(PTR)>>((PTR)))
#    define AsOwner(PTR) ((PTR).release())
#    define AsRaw(PTR) (PTR)
#endif

template <typename T, typename... Args>
[[nodiscard]] inline std::enable_if_t<!std::is_array_v<T>, Ptr<T>> MakeUnique(Args&&... args)
{
    return Ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
[[nodiscard]] inline std::enable_if_t<std::is_array_v<T>, Ptr<T>> MakeUnique(usize size)
{
    static_assert(std::extent_v<T> == 0, "Cannot MakeUnique with non-zero array extent");

    return Ptr<T>(new std::remove_extent_t<T>[size] {});
}

template <typename T>
[[nodiscard]] inline std::enable_if_t<!std::is_array_v<T>, Ptr<T>> MakeUniqueUninit()
{
    return Ptr<T>(new T);
}

template <typename T>
[[nodiscard]] inline std::enable_if_t<std::is_array_v<T>, Ptr<T>> MakeUniqueUninit(usize size)
{
    static_assert(std::extent_v<T> == 0, "Cannot MakeUnique with non-zero array extent");

    return Ptr<T>(new std::remove_extent_t<T>[size]);
}
