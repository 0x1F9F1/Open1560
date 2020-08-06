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

#include "data7/ipc.h"
#include "data7/metaclass.h"
#include "memory/allocator.h"
#include "memory/stack.h"
#include "mmcityinfo/state.h"
#include "pcwindis/dxinit.h"

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

static char Main_ExecPath[1024] {};
static char* Main_Argv[128] {};

alignas(16) static u8 Main_InitHeap[0x10000];

int WINAPI MidtownMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR lpCmdLine, int /*nShowCmd*/)
{
    asMemoryAllocator init_alloc;
    init_alloc.Init(Main_InitHeap, sizeof(Main_InitHeap), 1);

    CURHEAP = &init_alloc;

    MetaClass::FixupClasses();

    GetModuleFileNameA(0, Main_ExecPath, std::size(Main_ExecPath));

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

        ArAssert(argc < std::size(Main_Argv), "Too Many CMD arguments");
        Main_Argv[argc++] = cmd_start;
    }

    ArAssert(argc < std::size(Main_Argv), "Too Many CMD arguments");
    Main_Argv[argc] = nullptr;

    mem::cmd_param::init(static_cast<int>(argc), Main_Argv);

    Application(static_cast<int>(argc), Main_Argv);

    Displayf("Good bye.");

    // Timer::Sleep(500);

    return 0;
}

static mem::cmd_param PARAM_affinity {"affinity"};
static mem::cmd_param PARAM_sync {"sync"};

void Application(i32 argc, char** argv)
{
    EXCEPTION_BEGIN
    {
        dxiIcon = 111;

        u32 affinity = PARAM_affinity.get_or<u32>(0);

        if (affinity)
        {
            Displayf("SetProcessAffinityMask(0x%X)", affinity);

            SetProcessAffinityMask(GetCurrentProcess(), affinity);
        }

        if (affinity == 0 || (affinity & (affinity - 1)) != 0)
        {
            SynchronousMessageQueues = PARAM_sync.get_or<bool>(true);

            Warningf("Running with multiple threads. Here be dragons");

            if (!SynchronousMessageQueues)
            {
                Warningf("For stability, recommend using -sync");
            }
        }

        ApplicationHelper(argc, argv);
    }
    EXCEPTION_END
    {
        // AIMAP.Dump()

        Abortf("Exception caught during init.");
    }
}

i32 GameFilter(struct _EXCEPTION_POINTERS* exception)
{
    return ExceptionFilter(exception);
}
