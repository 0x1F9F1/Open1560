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

void Application(i32 argc, char** argv)
{
    dxiIcon = 111;

    SetProcessAffinityMask(GetCurrentProcess(), 1);

    __try
    {
        ApplicationHelper(argc, argv);
    }
    __except (GameFilter(GetExceptionInformation()))
    {
        // AIMAP.Dump()

        Abortf("Exception caught during init.");
    }
}

static const char* GetExceptionCodeString(DWORD code)
{
    switch (code)
    {
        case EXCEPTION_ACCESS_VIOLATION: return "ACCESS_VIOLATION";
        case EXCEPTION_ARRAY_BOUNDS_EXCEEDED: return "ARRAY_BOUNDS_EXCEEDED";
        case EXCEPTION_BREAKPOINT: return "BREAKPOINT";
        case EXCEPTION_DATATYPE_MISALIGNMENT: return "DATATYPE_MISALIGNMENT";
        case EXCEPTION_FLT_DENORMAL_OPERAND: return "FLT_DENORMAL_OPERAND";
        case EXCEPTION_FLT_DIVIDE_BY_ZERO: return "FLT_DIVIDE_BY_ZERO";
        case EXCEPTION_FLT_INEXACT_RESULT: return "FLT_INEXACT_RESULT";
        case EXCEPTION_FLT_INVALID_OPERATION: return "FLT_INVALID_OPERATION";
        case EXCEPTION_FLT_OVERFLOW: return "FLT_OVERFLOW";
        case EXCEPTION_FLT_STACK_CHECK: return "FLT_STACK_CHECK";
        case EXCEPTION_FLT_UNDERFLOW: return "FLT_UNDERFLOW";
        case EXCEPTION_GUARD_PAGE: return "GUARD_PAGE";
        case EXCEPTION_ILLEGAL_INSTRUCTION: return "ILLEGAL_INSTRUCTION";
        case EXCEPTION_IN_PAGE_ERROR: return "IN_PAGE_ERROR";
        case EXCEPTION_INT_DIVIDE_BY_ZERO: return "INT_DIVIDE_BY_ZERO";
        case EXCEPTION_INT_OVERFLOW: return "INT_OVERFLOW";
        case EXCEPTION_INVALID_DISPOSITION: return "INVALID_DISPOSITION";
        case EXCEPTION_INVALID_HANDLE: return "INVALID_HANDLE";
        case EXCEPTION_NONCONTINUABLE_EXCEPTION: return "NONCONTINUABLE_EXCEPTION";
        case EXCEPTION_PRIV_INSTRUCTION: return "PRIV_INSTRUCTION";
        case EXCEPTION_SINGLE_STEP: return "SINGLE_STEP";
        case EXCEPTION_STACK_OVERFLOW: return "STACK_OVERFLOW";
    };

    return nullptr;
}

i32 GameFilter(struct _EXCEPTION_POINTERS* exception)
{
    CONTEXT* context = exception->ContextRecord;
    EXCEPTION_RECORD* record = exception->ExceptionRecord;

    char source[128];
    LookupAddress(source, std::size(source), context->Eip);

    const char* error_code_string = GetExceptionCodeString(record->ExceptionCode);

    Displayf("%s (0x%08X) at EIP=%s", error_code_string ? error_code_string : "UNKNOWN", record->ExceptionCode, source);

    Displayf("EAX=%08X EBX=%08X ECX=%08X EDX=%08X", context->Eax, context->Ebx, context->Ecx, context->Edx);
    Displayf("ESI=%08X EDI=%08X EBP=%08X ESP=%08X", context->Esi, context->Edi, context->Ebp, context->Esp);

    DoStackTraceback(16, reinterpret_cast<i32*>(context->Ebp));

    return EXCEPTION_EXECUTE_HANDLER;
}
