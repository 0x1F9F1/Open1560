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

define_dummy_symbol(midtown);

#include "midtown.h"

#include <mem/cmd_param-inl.h>

#include "data7/callback.h"
#include "data7/ipc.h"
#include "data7/metaclass.h"
#include "memory/allocator.h"
#include "memory/stack.h"
#include "mmcityinfo/state.h"
#include "pcwindis/dxinit.h"

#include <mem/module.h>
#include <mem/pattern.h>

#include "core/minwin.h"

// 0x402F20 | ?GameCloseCallback@@YAXXZ
ARTS_EXPORT /*static*/ void GameCloseCallback()
{
    MMSTATE.GameState = 0;
    MMSTATE.Closing = 1;
}

// 0x402E70 | ?TouchMemory@@YAXPAXH@Z
ARTS_EXPORT /*static*/ void TouchMemory(void*, i32)
{}

// 0x402EC0 | ?exeDirFile@@YAPADPAD0@Z
ARTS_EXPORT /*static*/ char* exeDirFile(char* buffer, char* file)
{
    // FIXME: Unsafe
    usize const buf_len = 0x80;

    GetModuleFileNameA(NULL, buffer, buf_len);

    if (char* folder = std::strrchr(buffer, '\\'))
        folder[1] = '\0';

    arts_strcat(buffer, buf_len, file);

    return buffer;
}

static Callback GameResetCallback_[32];
CallbackArray GameResetCallbacks {GameResetCallback_, ARTS_SIZE(GameResetCallback_)};

static char Main_ExecPath[1024] {};
static char* Main_Argv[128] {};

alignas(16) static u8 Main_InitHeap[0x10000];

static mem::cmd_param PARAM_clean_dir {"cleandir"};

ARTS_EXPORT int WINAPI MidtownMain(
    HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR lpCmdLine, int /*nShowCmd*/)
{
    asMemoryAllocator init_alloc;
    init_alloc.Init(Main_InitHeap, sizeof(Main_InitHeap), 1);

    CURHEAP = &init_alloc;

    MetaClass::FixupClasses();

    GetModuleFileNameA(0, Main_ExecPath, ARTS_SIZE32(Main_ExecPath));

    usize argc = 0;
    Main_Argv[argc++] = Main_ExecPath;

    char* current = lpCmdLine;

    while (*current)
    {
        current += std::strspn(current, " \t");

        char* cmd_start = nullptr;

        if (*current == '"')
        {
            ++current;

            cmd_start = current;

            current = std::strchr(current, '"');

            ArAssert(current != nullptr, "Unclosed CMD line string");
        }
        else if (*current != '\0')
        {
            cmd_start = current;

            current += std::strcspn(current, " \t");
        }
        else
        {
            break;
        }

        if (*current)
        {
            *current++ = '\0';
        }

        ArAssert(argc < ARTS_SIZE(Main_Argv), "Too Many CMD arguments");
        Main_Argv[argc++] = cmd_start;
    }

    ArAssert(argc < ARTS_SIZE(Main_Argv), "Too Many CMD arguments");
    Main_Argv[argc] = nullptr;

    mem::cmd_param::init(static_cast<int>(argc), Main_Argv);

    Application(static_cast<int>(argc), Main_Argv);

    Displayf("Good bye.");

    CloseLogFile();

#ifdef ARTS_FINAL
    if (PARAM_clean_dir.get_or(true))
    {
        system("del /Q *.csv last.rpl crash.rpl portals.s");
    }
#endif

    // Timer::Sleep(500);

    return 0;
}

static void CallGameResetCallbacks()
{
    // TODO: Move this to ApplicationHelper
    GameResetCallbacks.Invoke(true);
}

static mem::cmd_param PARAM_affinity {"affinity"};
static mem::cmd_param PARAM_sync {"sync"};
static mem::cmd_param PARAM_res_hack {"reshack"};

void Application(i32 argc, char** argv)
{
    ARTS_EXCEPTION_BEGIN
    {
        // Needs to be called before FileSystem destruction
        create_hook(
            "CallGameResetCallbacks", "GameResetCallbacks after ~AudManager", 0x4E829F, &CallGameResetCallbacks);

        dxiIcon = 111;

        u32 affinity = PARAM_affinity.get_or<u32>(0);

        if (affinity)
        {
            Displayf("SetProcessAffinityMask(0x%X)", affinity);

            SetProcessAffinityMask(GetCurrentProcess(), affinity);
        }

        if (affinity == 0 || (affinity & (affinity - 1)) != 0)
        {
            SynchronousMessageQueues = PARAM_sync.get_or(true);

            if (!SynchronousMessageQueues)
            {
                Warningf("For stability, recommend using -sync");
            }
        }

#ifndef ARTS_DISABLE_DDRAW
        if (PARAM_res_hack.get_or(false))
        {
            wchar_t d3dim_path[MAX_PATH];
            GetSystemDirectoryW(d3dim_path, ARTS_SIZE(d3dim_path));
            wcscat_s(d3dim_path, L"\\d3dim.dll");

            HMODULE d3dim = LoadLibraryW(d3dim_path);

            if (d3dim)
            {
                mem::pattern res_pattern("B8 00 08 00 00 39");
                mem::default_scanner res_scanner(res_pattern);

                mem::module::nt(d3dim).enum_segments([&res_scanner](mem::region segment, mem::prot_flags prot) {
                    if (prot & mem::prot_flags::X)
                    {
                        res_scanner(segment, [](mem::pointer addr) {
                            create_patch("ResHack", "Removes 2048x2048 res limit", addr + 1, "\xFF\xFF\xFF\xFF", 4);

                            return false;
                        });
                    }

                    return false;
                });
            }
            else
            {
                Displayf("ResHack - d3dim not found");
            }
        }
#endif

        ApplicationHelper(argc, argv);
    }
    ARTS_EXCEPTION_END
    {
        // AIMAP.Dump()

        Abortf("Exception caught during init.");
    }
}

i32 GameFilter(struct _EXCEPTION_POINTERS* exception)
{
    return ExceptionFilter(exception);
}
