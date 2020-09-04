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

#include <mem/module.h>
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

bool LogHooks = true;

void create_hook(const char* name, const char* description, mem::pointer pHook, mem::pointer pDetour, hook_type type)
{
    intptr_t rva = pDetour.as<intptr_t>() - pHook.add(5).as<intptr_t>();

    unsigned char buffer[16];

    switch (type)
    {
        case hook_type::jmp: {
            buffer[0] = 0xE9;
            std::memcpy(&buffer[1], &rva, sizeof(rva));
            write_protected(pHook, buffer, 5);
            break;
        }

        case hook_type::call: {
            buffer[0] = 0xE8;
            std::memcpy(&buffer[1], &rva, sizeof(rva));
            write_protected(pHook, buffer, 5);
            break;
        }

        case hook_type::push: {
            buffer[0] = 0xE9;
            std::memcpy(&buffer[1], &pDetour, sizeof(pDetour));
            write_protected(pHook, buffer, 5);
            break;
        }

        case hook_type::pointer: {
            write_protected(pHook, &pDetour, sizeof(pDetour));
            break;
        }

        default: return;
    }

    if (LogHooks)
    {
        Displayf("Created %s hook '%s' from 0x%zX to 0x%zX: %s", HookTypeNames[static_cast<size_t>(type)], name,
            pHook.as<size_t>(), pDetour.as<size_t>(), description);
    }

    ++HookCount;
}

void create_patch(const char* name, const char* description, mem::pointer dest, mem::pointer src, size_t size)
{
    write_protected(dest, src, size);

    Displayf("Created patch '%s' at 0x%zX of size %zu: %s", name, dest.as<size_t>(), size, description);

    ++PatchCount;
}

void patch_jmp(const char* name, const char* description, mem::pointer target, jump_type mode)
{
    const void* patch = nullptr;
    size_t len = 0;

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
        Errorf("Unrecognized jmp at 0x%zX", target.as<size_t>());
}

struct RelocEntry
{
    size_t Target;
    size_t Source;
};

static RelocEntry game_relocations[60000];
static size_t game_relocation_count = 0;

static void load_relocs()
{
    Displayf("Loading relocs");

    mem::module main_module = mem::module::main();

    const IMAGE_DATA_DIRECTORY& reloc_dir =
        main_module.nt_headers().OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];

    IMAGE_BASE_RELOCATION* relocs = main_module.start.add(reloc_dir.VirtualAddress).as<IMAGE_BASE_RELOCATION*>();
    DWORD relocs_size = reloc_dir.Size;

    DWORD total_size = 0;
    size_t total = 0;

    while (total_size < relocs_size)
    {
        DWORD block_va = relocs->VirtualAddress;
        size_t entry_count = entry_count = (relocs->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);

        if (total + entry_count > 60000)
            Abortf("Too many relocations");

        u16* entries = (u16*) (relocs + 1);

        for (size_t i = 0; i < entry_count; ++i, ++entries)
        {
            if ((*entries >> 12) != IMAGE_REL_BASED_HIGHLOW)
                continue;

            size_t va = block_va + (*entries & 0xFFF);
            game_relocations[total] = {main_module.start.add(va).as<size_t&>(), 0x400000 + va};
            ++total;
        }

        total_size += relocs->SizeOfBlock;
        relocs = (IMAGE_BASE_RELOCATION*) entries;
    }

    game_relocation_count = total;

    std::sort(
        game_relocations, game_relocations + game_relocation_count, [](const RelocEntry& lhs, const RelocEntry& rhs) {
            if (lhs.Target != rhs.Target)
                return lhs.Target < rhs.Target;

            return lhs.Source < rhs.Source;
        });

    Displayf("Parsed %zu relocations", total);
}

void patch_xrefs(const char* name, const char* description, mem::pointer from, mem::pointer to, size_t length)
{
    if (game_relocation_count == 0)
        load_relocs();

    auto find = std::lower_bound(game_relocations, game_relocations + game_relocation_count, from.as<size_t>(),
        [](const RelocEntry& lhs, size_t address) { return lhs.Target < address; });

    size_t total = 0;

    for (; find < game_relocations + game_relocation_count; ++find, ++total)
    {
        if (find->Target >= (from + length).as<size_t>())
            break;

        mem::pointer target = to + (find->Target - from.as<size_t>());

        write_protected(find->Source, &target, sizeof(target));
    }

    Displayf("Patches %zu '%s' xrefs: %s", total, name, description);
}
