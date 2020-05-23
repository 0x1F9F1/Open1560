#pragma once

#include <memory>
#include <type_traits>

template <typename T>
using Ptr = std::unique_ptr<T>;

template <typename T, typename... Args>
[[nodiscard]] ARTS_FORCEINLINE std::enable_if_t<!std::is_array_v<T>, Ptr<T>> MakeUnique(Args&&... args)
{
    return Ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
[[nodiscard]] ARTS_FORCEINLINE std::enable_if_t<std::is_array_v<T>, Ptr<T>> MakeUnique(usize size)
{
    static_assert(std::extent_v<T> == 0, "Cannot MakeUnique with non-zero array extent");

    return Ptr<T>(new std::remove_extent_t<T>[size]());
}
