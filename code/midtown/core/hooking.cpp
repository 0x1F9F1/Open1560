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

#include "hooking.h"

#include "data7/printer.h"

#include <mem/protect.h>

void write_protected(mem::pointer dest, mem::pointer src, size_t length)
{
    mem::protect({dest, length}).copy(src);
}

const char* const HookTypeNames[static_cast<size_t>(hook_type::count)] = {
    "jmp",
    "call",
    "push",
    "pointer",
};

size_t HookCount = 0;
size_t PatchCount = 0;

void create_hook(const char* name, const char* description, mem::pointer pHook, mem::pointer pDetour, hook_type type)
{
    intptr_t rva = pDetour.as<intptr_t>() - pHook.add(5).as<intptr_t>();

    switch (type)
    {
        case hook_type::jmp: {
            std::uint8_t buffer[5] = {0xE9};

            reinterpret_cast<int&>(buffer[1]) = rva;

            write_protected(pHook, buffer, sizeof(buffer));

            break;
        }

        case hook_type::call: {
            std::uint8_t buffer[5] = {0xE8};
            reinterpret_cast<int&>(buffer[1]) = rva;

            write_protected(pHook, buffer, sizeof(buffer));

            break;
        }

        case hook_type::push: {
            std::uint8_t buffer[5] = {0x68};
            reinterpret_cast<int&>(buffer[1]) = pDetour.as<int>();

            write_protected(pHook, buffer, sizeof(buffer));

            break;
        }

        case hook_type::pointer: {
            write_protected(pHook, &pDetour, sizeof(pDetour));

            break;
        }
    }

    Displayf("Created %s hook '%s' from 0x%zX to 0x%zX: %s", HookTypeNames[static_cast<size_t>(type)], name,
        pHook.as<uintptr_t>(), pDetour.as<uintptr_t>(), description);

    ++HookCount;
}

void create_patch(const char* name, const char* description, mem::pointer dest, mem::pointer src, size_t size)
{
    write_protected(dest, src, size);

    Displayf("Created patch '%s' at 0x%zX of size %zu: %s", name, dest.as<uintptr_t>(), size, description);

    ++PatchCount;
}

void patch_jmp(const char* name, const char* description, mem::pointer target, jump_type mode)
{
    const void* patch = nullptr;
    usize len = 0;

    u8 op = target.as<u8&>();

    if (op == 0x0F)
    {
        op = target.add(1).as<u8&>();

        if (op >= 0x80 && op <= 0x8F)
        {
            switch (mode)
            {
                case jump_type::always:
                    patch = "\x90\xE9";
                    len = 2;
                    break;

                case jump_type::never:
                    patch = "\x90\x90\x90\x90\x90\x90";
                    len = 6;
                    break;
            }
        }
    }
    else if (op >= 0x70 && op <= 0x7F)
    {
        switch (mode)
        {
            case jump_type::always:
                patch = "\xEB";
                len = 1;
                break;

            case jump_type::never:
                patch = "\x90\x90";
                len = 2;
                break;
        }
    }

    if (patch)
        create_patch(name, description, target, patch, len);
    else
        Errorf("Unrecognized jmp at 0x%zX", target.as<uintptr_t>());
}
