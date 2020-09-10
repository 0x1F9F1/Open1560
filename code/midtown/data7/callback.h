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

#define CB_TYPE_NONE 0

#define CB_TYPE_CFA 1
#define CB_TYPE_CFA1 2
#define CB_TYPE_CFA2 3

#define CB_TYPE_MFA 4
#define CB_TYPE_MFA1 5
#define CB_TYPE_MFA2 6
#define CB_TYPE_MFA3 7

class Callback
{
public:
    using Static0 = void (*)();
    using Static1 = void (*)(void*);
    using Static2 = void (*)(void*, void*);

    using Member0 = void (Base::*)();
    using Member1 = void (Base::*)(void*);
    using Member2 = void (Base::*)(void*, void*);

    // 0x5792C0 | ??0Callback@@QAE@XZ
    ARTS_EXPORT constexpr Callback() noexcept = default;

    // 0x5793D0 | ??0Callback@@QAE@P6AXXZ@Z
    ARTS_EXPORT constexpr Callback(Static0 func) noexcept;

    // 0x5793F0 | ??0Callback@@QAE@P6AXPAX@Z0@Z
    ARTS_EXPORT constexpr Callback(Static1 func, void* param) noexcept;

    // 0x579420 | ??0Callback@@QAE@P6AXPAX0@Z0@Z
    ARTS_EXPORT constexpr Callback(Static2 func, void* param) noexcept;

    // 0x5792D0 | ??0Callback@@QAE@P8Base@@AEXXZPAV1@@Z
    ARTS_EXPORT constexpr Callback(Member0 func, class Base* this_ptr) noexcept;

    // 0x579310 | ??0Callback@@QAE@P8Base@@AEXPAX@ZPAV1@0@Z
    ARTS_EXPORT constexpr Callback(Member1 func, class Base* this_ptr, void* param) noexcept;

    // 0x579350 | ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@0@Z
    ARTS_EXPORT constexpr Callback(Member2 func, class Base* this_ptr, void* param) noexcept;

    // 0x579390 | ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@00@Z
    ARTS_EXPORT constexpr Callback(Member2 func, class Base* this_ptr, void* param1, void* param2) noexcept;

    // 0x579450 | ?Call@Callback@@QAEXPAX@Z
    ARTS_EXPORT void Call(void* param = nullptr);

    bool operator==(const Callback& other) const;

private:
    i32 type_ {CB_TYPE_NONE};
    Base* this_ptr_ {nullptr};

    union
    {
        void* address;

        Static0 static0;
        Static1 static1;
        Static2 static2;

        Member0 member0;
        Member1 member1;
        Member2 member2;
    } func_ {nullptr};

    void* param_1_ {nullptr};
    void* param_2_ {nullptr};
};

class CallbackArray
{
public:
    CallbackArray(Callback* callbacks, usize capacity);

    void Append(Callback callback);
    void Clear();
    void Invoke(bool clear_after, void* param = nullptr);

private:
    Callback* callbacks_ {nullptr};
    u16 size_ {0};
    u16 capacity_ {0};
};

#define CFA(FUNC) Callback(static_cast<Callback::Static0>(FUNC))
#define CFA1(FUNC, PARAM) Callback(static_cast<Callback::Static1>(FUNC), PARAM)
#define CFA2(FUNC, PARAM) Callback(static_cast<Callback::Static2>(FUNC), PARAM)

#define MFA(FUNC, THIS) Callback(static_cast<Callback::Member0>(&FUNC), THIS)
#define MFA1(FUNC, THIS, PARAM) Callback(static_cast<Callback::Member1>(&FUNC), THIS, PARAM)
#define MFA2(FUNC, THIS, PARAM) Callback(static_cast<Callback::Member2>(&FUNC), THIS, PARAM)
#define MFA3(FUNC, THIS, PARAM1, PARAM2) Callback(static_cast<Callback::Member2>(&FUNC), THIS, PARAM1, PARAM2)

check_size(Callback, 0x14);

// 0x90B128 | ?NullCallback@@3VCallback@@A
// ARTS_IMPORT extern class Callback NullCallback;
inline constexpr const Callback NullCallback {};

inline constexpr Callback::Callback(Static0 func) noexcept
    : type_(CB_TYPE_CFA)
{
    func_.static0 = func;
}

inline constexpr Callback::Callback(Static1 func, void* param) noexcept
    : type_(CB_TYPE_CFA1)
    , param_1_(param)
{
    func_.static1 = func;
}

inline constexpr Callback::Callback(Static2 func, void* param) noexcept
    : type_(CB_TYPE_CFA2)
    , param_1_(param)
{
    func_.static2 = func;
}

inline constexpr Callback::Callback(Member0 func, Base* this_ptr) noexcept
    : type_(CB_TYPE_MFA)
    , this_ptr_(this_ptr)
{
    func_.member0 = func;

    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

inline constexpr Callback::Callback(Member1 func, Base* this_ptr, void* param) noexcept
    : type_(CB_TYPE_MFA1)
    , this_ptr_(this_ptr)
    , param_1_(param)
{
    func_.member1 = func;

    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

inline constexpr Callback::Callback(Member2 func, Base* this_ptr, void* param) noexcept
    : type_(CB_TYPE_MFA2)
    , this_ptr_(this_ptr)
    , param_1_(param)
{
    func_.member2 = func;

    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

inline constexpr Callback::Callback(Member2 func, Base* this_ptr, void* param1, void* param2) noexcept
    : type_(CB_TYPE_MFA3)
    , this_ptr_(this_ptr)
    , param_1_(param1)
    , param_2_(param2)
{
    func_.member2 = func;

    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

inline bool Callback::operator==(const Callback& other) const
{
    return !std::memcmp(this, &other, sizeof(*this));
}
