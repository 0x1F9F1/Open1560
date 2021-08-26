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

#define RC_USE_SWAP 1

template <typename T>
class Rc final
{
public:
    ARTS_FORCEINLINE constexpr Rc() noexcept = default;

    ARTS_FORCEINLINE constexpr Rc(std::nullptr_t) noexcept
        : ptr_(nullptr)
    {}

    ARTS_FORCEINLINE explicit Rc(T* ptr) noexcept
        : ptr_(ptr)
    {}

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    ARTS_FORCEINLINE Rc(Ptr<U>&& ptr) noexcept
        : ptr_(ptr.release())
    {}

    ARTS_FORCEINLINE Rc(Rc&& other) noexcept
        : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    ARTS_FORCEINLINE Rc(Rc<U>&& other) noexcept
        : ptr_(other.release())
    {}

    ARTS_FORCEINLINE Rc(const Rc& other) noexcept
        : ptr_(other.get())
    {
        if (ptr_)
            ptr_->AddRef();
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    ARTS_FORCEINLINE Rc(const Rc<U>& other) noexcept
        : ptr_(other.get())
    {
        if (ptr_)
            ptr_->AddRef();
    }

    ARTS_FORCEINLINE ~Rc()
    {
        if (ptr_)
            ptr_->Release();
    }

    ARTS_FORCEINLINE Rc& operator=(std::nullptr_t)
    {
#if RC_USE_SWAP
        Rc().swap(*this);
#else
        T* old = ptr_;
        ptr_ = nullptr;

        if (old)
            old->Release();
#endif

        return *this;
    }

    ARTS_FORCEINLINE Rc& operator=(Rc&& other) noexcept
    {
        if (this != &other)
        {
#if RC_USE_SWAP
            Rc(std::move(other)).swap(*this);
#else
            T* old = ptr_;
            ptr_ = other.release();

            if (old)
                old->Release();
#endif
        }

        return *this;
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    ARTS_FORCEINLINE Rc& operator=(Rc<U>&& other)
    {
#if RC_USE_SWAP
        Rc(std::move(other)).swap(*this);
#else
        T* old = ptr_;
        ptr_ = other.release();

        if (old)
            old->Release();
#endif

        return *this;
    }

    ARTS_FORCEINLINE Rc& operator=(const Rc& other)
    {
#if RC_USE_SWAP
        if (this != &other)
        {
            Rc(other).swap(*this);
        }
#else
        T* old = ptr_;
        ptr_ = other.get();

        if (old != ptr_)
        {
            if (ptr_)
                ptr_->AddRef();

            if (old)
                old->Release();
        }
#endif

        return *this;
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    ARTS_FORCEINLINE Rc& operator=(const Rc<U>& other)
    {
#if RC_USE_SWAP
        if (this != &other)
        {
            Rc(other).swap(*this);
        }
#else
        T* old = ptr_;
        ptr_ = other.get();

        if (old != ptr_)
        {
            if (ptr_)
                ptr_->AddRef();

            if (old)
                old->Release();
        }
#endif

        return *this;
    }

    ARTS_FORCEINLINE void reset(T* ptr = nullptr)
    {
#if RC_USE_SWAP
        Rc(ptr).swap(*this);
#else
        T* old = ptr_;
        ptr_ = ptr;

        if (old)
            old->Release();
#endif
    }

    ARTS_FORCEINLINE T& operator*() const noexcept
    {
        return *ptr_;
    }

    ARTS_FORCEINLINE T* operator->() const noexcept
    {
        return ptr_;
    }

    ARTS_FORCEINLINE T* get() const noexcept
    {
        return ptr_;
    }

    [[nodiscard]] ARTS_FORCEINLINE T* release() noexcept
    {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    ARTS_FORCEINLINE void swap(Rc& other) noexcept
    {
        T* ptr = ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = ptr;
    }

    ARTS_FORCEINLINE explicit operator bool() const noexcept
    {
        return ptr_ != nullptr;
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    ARTS_FORCEINLINE bool operator==(const Rc<U>& other) const noexcept
    {
        return ptr_ == other.ptr_;
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    ARTS_FORCEINLINE bool operator!=(const Rc<U>& other) const noexcept
    {
        return ptr_ != other.ptr_;
    }

    ARTS_FORCEINLINE bool operator==(std::nullptr_t other) const noexcept
    {
        return ptr_ == other;
    }

    ARTS_FORCEINLINE bool operator!=(std::nullptr_t other) const noexcept
    {
        return ptr_ != other;
    }

private:
    T* ptr_ {};
};

template <typename T, typename... Args>
[[nodiscard]] inline std::enable_if_t<!std::is_array_v<T>, Rc<T>> MakeRc(Args&&... args)
{
    return Rc<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
[[nodiscard]] inline std::enable_if_t<!std::is_array_v<T>, Rc<T>> AddRc(T* ptr) noexcept
{
    if (ptr)
        ptr->AddRef();

    return Rc<T>(ptr);
}

#ifdef ARTS_STANDALONE
template <typename T>
using RcOwner = Rc<T>;

#    define AsRc(PTR) (PTR)
#else
template <typename T>
using RcOwner = T*;

#    define AsRc(PTR) (Rc<std::remove_pointer_t<decltype(PTR)>>((PTR)))
#endif
