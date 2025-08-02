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

#include "base.h"

#define CALLBACK_DATA_SIZE sizeof(void* [4])
#define CALLBACK_DATA_ALIGN alignof(void*)
#define CALLBACK_CC ARTS_FASTCALL

class Callback
{
public:
    using Static0 = void (*)();
    using Static1 = void (*)(void*);
    using Static2 = void (*)(void*, void*);

    using Member0 = void (Base::*)();
    using Member1 = void (Base::*)(void*);
    using Member2 = void (Base::*)(void*, void*);

    // ??0Callback@@QAE@XZ
    ARTS_EXPORT Callback() noexcept = default;

    Callback(std::nullptr_t) noexcept;

    template <typename Func>
    Callback(Func func) noexcept;

    // ??0Callback@@QAE@P6AXXZ@Z
    [[deprecated]] ARTS_EXPORT explicit Callback(Static0 func) noexcept;

    // ??0Callback@@QAE@P6AXPAX@Z0@Z
    [[deprecated]] ARTS_EXPORT explicit Callback(Static1 func, void* param) noexcept;

    // ??0Callback@@QAE@P6AXPAX0@Z0@Z
    [[deprecated]] ARTS_EXPORT explicit Callback(Static2 func, void* param) noexcept;

    // ??0Callback@@QAE@P8Base@@AEXXZPAV1@@Z
    [[deprecated]] ARTS_EXPORT explicit Callback(Member0 func, Base* this_ptr) noexcept;

    // ??0Callback@@QAE@P8Base@@AEXPAX@ZPAV1@0@Z
    [[deprecated]] ARTS_EXPORT explicit Callback(Member1 func, Base* this_ptr, void* param) noexcept;

    // ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@0@Z
    [[deprecated]] ARTS_EXPORT explicit Callback(Member2 func, Base* this_ptr, void* param) noexcept;

    // ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@00@Z | unused
    [[deprecated]] ARTS_EXPORT explicit Callback(Member2 func, Base* this_ptr, void* param1, void* param2) noexcept;

    // ?Call@Callback@@QAEXPAX@Z
    ARTS_EXPORT void Call(void* param = nullptr);

    bool operator==(const Callback& other) const;

private:
    alignas(CALLBACK_DATA_ALIGN) u8 data_[CALLBACK_DATA_SIZE] {};
    void(CALLBACK_CC* invoke_)(void* context, void* param) {};
};

check_size(Callback, 0x14);

class CallbackArray
{
public:
    CallbackArray(Callback* callbacks, usize capacity);

    void Append(Callback callback);
    void Clear();
    void Invoke(bool clear_after, void* param = nullptr);

private:
    Callback* callbacks_ {};
    u16 size_ {};
    u16 capacity_ {};
};

// ?NullCallback@@3VCallback@@A
[[deprecated]] ARTS_EXPORT extern Callback NullCallback;

inline Callback::Callback(std::nullptr_t) noexcept
    : Callback()
{}

template <typename Func, typename = void>
struct CallbackInvoker
{
    static void CALLBACK_CC Invoke(void* context, [[maybe_unused]] void* param)
    {
        (*static_cast<Func*>(context))();
    }
};

template <typename Func>
struct CallbackInvoker<Func, decltype(void(std::declval<Func&>()(std::declval<void*>())))>
{
    static void CALLBACK_CC Invoke(void* context, void* param)
    {
        (*static_cast<Func*>(context))(param);
    }
};

template <typename Func>
inline Callback::Callback(Func func) noexcept
    : invoke_(CallbackInvoker<Func>::Invoke)
{
    static_assert(sizeof(Func) <= CALLBACK_DATA_SIZE, "Function is too large");
    static_assert(alignof(Func) <= CALLBACK_DATA_ALIGN, "Function is over-aligned");
    static_assert(std::is_trivially_copyable_v<Func>, "Function is not trivially copyable");

    new (data_) Func(func);
}

inline bool Callback::operator==(const Callback& other) const
{
    return !std::memcmp(this, &other, sizeof(*this));
}
