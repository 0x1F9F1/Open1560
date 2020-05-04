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

class Callback
{
public:
    // 0x5792C0 | ??0Callback@@QAE@XZ
    Callback();

    // 0x5793D0 | ??0Callback@@QAE@P6AXXZ@Z
    Callback(void (*arg1)(void));

    // 0x5793F0 | ??0Callback@@QAE@P6AXPAX@Z0@Z
    Callback(void (*arg1)(void*), void* arg2);

    // 0x579420 | ??0Callback@@QAE@P6AXPAX0@Z0@Z
    Callback(void (*arg1)(void*, void*), void* arg2);

    // 0x579450 | ?Call@Callback@@QAEXPAX@Z
    void Call(void* arg1);
};

check_size(Callback, 0x0);

// 0x579390 | ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@00@Z (Skipped: void)

// 0x579350 | ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@0@Z (Skipped: void)

// 0x579310 | ??0Callback@@QAE@P8Base@@AEXPAX@ZPAV1@0@Z (Skipped: void)

// 0x5792D0 | ??0Callback@@QAE@P8Base@@AEXXZPAV1@@Z (Skipped: void)

// 0x90B128 | ?NullCallback@@3VCallback@@A
inline extern_var(0x50B128_Offset, class Callback, NullCallback);
