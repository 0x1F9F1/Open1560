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

#include <shellapi.h>

static char** GetCommandLineUTF8(int* pNumArgs)
{
    int argc = 0;
    LPWSTR* wargv = CommandLineToArgvW(GetCommandLineW(), &argc);

    int size = 0;
    size += sizeof(char*) * (argc + 1);

    for (int i = 0; i < argc; ++i)
        size += WideCharToMultiByte(CP_UTF8, 0, wargv[i], -1, NULL, 0, NULL, NULL);

    void* result = arts_malloc(size);

    size = 0;
    size += sizeof(char*) * (argc + 1);

    for (int i = 0; i < argc; ++i)
    {
        char* arg = static_cast<char*>(result) + size;
        size += WideCharToMultiByte(CP_UTF8, 0, wargv[i], -1, arg, INT_MAX, NULL, NULL);
        static_cast<char**>(result)[i] = arg;
    }

    static_cast<char**>(result)[argc] = nullptr;

    LocalFree(wargv);

    *pNumArgs = argc;
    return static_cast<char**>(result);
}

static mem::cmd_param PARAM_clean_dir {"cleandir"};
static mem::cmd_param PARAM_console {"console"};

ARTS_EXPORT int WINAPI MidtownMain(
    HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/)
{
    MetaClass::FixupClasses();

    int argc = 0;
    char** argv = GetCommandLineUTF8(&argc);

    mem::cmd_param::init(argc, argv);

    if (PARAM_console.get_or(false))
        LogToConsole();

    Application(argc, argv);

    Displayf("Good bye.");

    CloseLogFile();

#ifdef ARTS_FINAL
    if (PARAM_clean_dir.get_or(true))
    {
        DeleteFileA("last.rpl");
        DeleteFileA("crash.rpl");
        DeleteFileA("portals.s");

        WIN32_FIND_DATAA find_data;

        if (HANDLE find_handle = FindFirstFileA("*.csv", &find_data); find_handle != INVALID_HANDLE_VALUE)
        {
            do
            {
                DeleteFileA(find_data.cFileName);
            } while (FindNextFileA(find_handle, &find_data));

            FindClose(find_handle);
        }
    }
#endif

    return 0;
}

static Callback GameResetCallback_[32];
CallbackArray GameResetCallbacks {GameResetCallback_, ARTS_SIZE(GameResetCallback_)};

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
