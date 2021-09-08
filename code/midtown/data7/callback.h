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
    data7:callback

    0x5792C0 | public: __thiscall Callback::Callback(void) | ??0Callback@@QAE@XZ
    0x5792D0 | public: __thiscall Callback::Callback(void (__thiscall Base::*)(void),class Base *) | ??0Callback@@QAE@P8Base@@AEXXZPAV1@@Z
    0x579310 | public: __thiscall Callback::Callback(void (__thiscall Base::*)(void *),class Base *,void *) | ??0Callback@@QAE@P8Base@@AEXPAX@ZPAV1@0@Z
    0x579350 | public: __thiscall Callback::Callback(void (__thiscall Base::*)(void *,void *),class Base *,void *) | ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@0@Z
    0x579390 | public: __thiscall Callback::Callback(void (__thiscall Base::*)(void *,void *),class Base *,void *,void *) | ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@00@Z
    0x5793D0 | public: __thiscall Callback::Callback(void (__cdecl*)(void)) | ??0Callback@@QAE@P6AXXZ@Z
    0x5793F0 | public: __thiscall Callback::Callback(void (__cdecl*)(void *),void *) | ??0Callback@@QAE@P6AXPAX@Z0@Z
    0x579420 | public: __thiscall Callback::Callback(void (__cdecl*)(void *,void *),void *) | ??0Callback@@QAE@P6AXPAX0@Z0@Z
    0x579450 | public: void __thiscall Callback::Call(void *) | ?Call@Callback@@QAEXPAX@Z
    0x90B128 | class Callback NullCallback | ?NullCallback@@3VCallback@@A
*/

#include "base.h"

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
    ARTS_EXPORT explicit Callback(Static0 func) noexcept;

    // ??0Callback@@QAE@P6AXPAX@Z0@Z
    ARTS_EXPORT explicit Callback(Static1 func, void* param) noexcept;

    // ??0Callback@@QAE@P6AXPAX0@Z0@Z
    ARTS_EXPORT explicit Callback(Static2 func, void* param) noexcept;

    // ??0Callback@@QAE@P8Base@@AEXXZPAV1@@Z
    ARTS_EXPORT explicit Callback(Member0 func, Base* this_ptr) noexcept;

    // ??0Callback@@QAE@P8Base@@AEXPAX@ZPAV1@0@Z
    ARTS_EXPORT explicit Callback(Member1 func, Base* this_ptr, void* param) noexcept;

    // ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@0@Z
    ARTS_EXPORT explicit Callback(Member2 func, Base* this_ptr, void* param) noexcept;

    // ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@00@Z
    ARTS_EXPORT explicit Callback(Member2 func, Base* this_ptr, void* param1, void* param2) noexcept;

    // ?Call@Callback@@QAEXPAX@Z
    ARTS_EXPORT void Call(void* param = nullptr);

    bool operator==(const Callback& other) const;

private:
    void(ARTS_FASTCALL* invoke_)(void* context, void* param) {};
    u8 data_[16];
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

#define CFA(FUNC) Callback(static_cast<Callback::Static0>(FUNC))
#define CFA1(FUNC, PARAM) Callback(static_cast<Callback::Static1>(FUNC), PARAM)
#define CFA2(FUNC, PARAM) Callback(static_cast<Callback::Static2>(FUNC), PARAM)

#define MFA(FUNC, THIS) Callback(static_cast<Callback::Member0>(&FUNC), THIS)
#define MFA1(FUNC, THIS, PARAM) Callback(static_cast<Callback::Member1>(&FUNC), THIS, PARAM)
#define MFA2(FUNC, THIS, PARAM) Callback(static_cast<Callback::Member2>(&FUNC), THIS, PARAM)
#define MFA3(FUNC, THIS, PARAM1, PARAM2) Callback(static_cast<Callback::Member2>(&FUNC), THIS, PARAM1, PARAM2)

// ?NullCallback@@3VCallback@@A
// ARTS_IMPORT extern Callback NullCallback;
[[deprecated]] ARTS_EXPORT extern Callback NullCallback;

inline Callback::Callback(std::nullptr_t) noexcept
    : Callback()
{}

template <typename Func, typename = void>
struct CallbackInvoker
{
    static void ARTS_FASTCALL Invoke(void* context, [[maybe_unused]] void* param)
    {
        (*static_cast<Func*>(context))();
    }
};

template <typename Func>
struct CallbackInvoker<Func, decltype(void(std::declval<Func>()(std::declval<void*>())))>
{
    static void ARTS_FASTCALL Invoke(void* context, void* param)
    {
        (*static_cast<Func*>(context))(param);
    }
};

template <typename Func>
inline Callback::Callback(Func func) noexcept
    : invoke_(CallbackInvoker<Func>::Invoke)
{
    new (data_) Func(func);
    static_assert(sizeof(func) <= sizeof(data_));
    static_assert(std::is_trivially_copyable_v<Func>);
}

inline Callback::Callback(Static0 func) noexcept
    : Callback([func] { func(); })
{}

inline Callback::Callback(Static1 func, void* param) noexcept
    : Callback([func, param] { func(param); })
{}

inline Callback::Callback(Static2 func, void* param) noexcept
    : Callback([func, param](void* arg) { func(param, arg); })
{}

inline Callback::Callback(Member0 func, Base* this_ptr) noexcept
    : Callback([func, this_ptr] { (this_ptr->*func)(); })
{
    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

inline Callback::Callback(Member1 func, Base* this_ptr, void* param) noexcept
    : Callback([func, this_ptr, param] { (this_ptr->*func)(param); })
{
    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

inline Callback::Callback(Member2 func, Base* this_ptr, void* param) noexcept
    : Callback([func, this_ptr, param](void* arg) { (this_ptr->*func)(param, arg); })
{
    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

inline Callback::Callback(Member2 func, Base* this_ptr, void* param1, void* param2) noexcept
    : Callback([func, this_ptr, param1, param2] { (this_ptr->*func)(param1, param2); })
{
    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

inline void Callback::Call(void* param)
{
    if (invoke_)
        invoke_(data_, param);
}

inline bool Callback::operator==(const Callback& other) const
{
    return !std::memcmp(this, &other, sizeof(*this));
}
