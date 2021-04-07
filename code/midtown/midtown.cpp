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

void InitPatches();

ARTS_EXPORT int WINAPI MidtownMain(
    HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int /*nShowCmd*/)
{
    int argc = 0;
    char** argv = GetCommandLineUTF8(&argc);

    mem::cmd_param::init(argc, argv);

    if (PARAM_console.get_or(false))
        LogToConsole();

    InitPatches();

    Displayf("Processed %zu Init Functions", mem::init_function::ROOT().init());

    MetaClass::FixupClasses();

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

void InitPatches()
{
    patch_jmp("ApplicationHelper", "Enable HW Menu Rendering", 0x401DB4, jump_type::always);

    create_patch("ApplicationHelper", "Increase Heap Size", 0x401E11, "\x05\x00\x00\x00\x04", 5); // add eax, 0x4000000

    patch_jmp("mmCullCity::InitTimeOfDayAndWeather", "Additive Blending Check", 0x48DDD2, jump_type::always);
    patch_jmp("SetTexQualString", "Additive Blending Check", 0x49A29F, jump_type::never);

    // Checked in GetPackedTexture, only necessary if agiRQ.TextureQuality <= 2
    // create_patch("aiVehicleOpponent::Init", "agiRQ.TextureQuality", 0x44DC2A, "\xEB\x06", 2);

    create_patch("CACHE", "Capacity", 0x4029DA + 1, "\x00\x10\x00\x00", 4); //    0x800 ->   0x1000 (2x)
    create_patch("CACHE", "HeapSize", 0x4029DF + 1, "\x00\x00\x20\x00", 4); // 0x100000 -> 0x200000 (2x)
    create_hook("CACHE", "Shutdown", 0x402D98, 0x577070, hook_type::call);

    create_patch("TEXCACHE", "Capacity", 0x4029F3 + 1, "\x00\x02\x00\x00", 4); //    0x100 ->    0x200 (2x)
    create_patch("TEXCACHE", "HeapSize", 0x4029F8 + 1, "\x00\x00\x40\x00", 4); // 0x200000 -> 0x400000 (2x)
    create_hook("TEXCACHE", "Shutdown", 0x402D8E, 0x577070, hook_type::call);

    if (false) // Hack, replaces 16-bit handler with 32-bit handler
    {
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D419, "\x83\x79\x04\x04", 4);
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D439, "\x8D\x04\xBA", 3);
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D47E, "\x8B\x00\x89\x04\x93\x90\x90", 7);
    }

    // Allocates 2 extra agiTexDef slots instead of 1, in case TextureCount == 0 (Assumes new memory is zeroed out)
    // Won't avoid some crashes, but should help avoid any out of bounds reads or writes
    // This also needs to be patched in agiMeshSet::DoPageIn
    create_patch("agiMeshSet::BinaryLoad", "Avoid empty texdefs", 0x502D43, "\x8D\x14\x8D\x08\x00\x00\x00", 7);

    // Hack, avoids attempting to access freed memory (https://github.com/0x1F9F1/Open1560/issues/15)
    // Luckily the aiVehicleSpline destructor doesn't do actually do anything anyway (apart from set mmInstanceHeap.HeapHead, which we want to avoid anyway)
    patch_jmp("aiVehicleSpline::~aiVehicleSpline", "Avoid freeing aiVehicleInstance", 0x459F84, jump_type::always);

    // create_patch("sfPointer::ResChange", "Use Old Cursor", 0x641F2C, "pointer", 8);

    // create_patch("DoScan", "Stop Touching Memory", 0x4046D0, "\xC3", 1);

    // create_patch("MultiTexture", "Enable D3D MultiTexture", 0x530788 + 6, "\x02", 1);

    patch_jmp("sfPointer::Update", "Enable cursor in windowed mode", 0x4BDAA4, jump_type::never);

    patch_jmp("PolarCamCS", "No Collision", 0x4FAFF4, jump_type::always);

    create_patch("PolarCamCS", "Increase Max XCAM Distance", 0x620340, "\x00\x00\x7A\x43", 4);

    create_patch("aiVehicleOpponent::Reset", "Fix List::Clear memory leak", 0x44DE4D,
        "\x89\xF9\xE8\x3C\xE4\x12\x00\x90\x8B\xD3\x42", 11);
    create_patch(
        "aiVehiclePolice::Reset", "Fix List::Clear memory leak", 0x44511C, "\x89\xF9\xE8\x6D\x71\x13\x00\x90", 8);

    create_patch("agiSWTexDef::BeginGfx", "MipMapCount Comparison", 0x537797, "\x7E", 1);
    create_patch("agiSWTexDef::EndGfx", "MipMapCount Comparison", 0x537833, "\x7E", 1);

    create_patch("TestResolution", "Max Software Resolution", 0x575E6C + 3, "\x00\x08", 2);
    create_patch("TestResolution", "Max Software Resolution", 0x575E73 + 2, "\x00\x08", 2);

    create_patch("agiSWTexLut::BeginGfx", "Fixed Fog Calculation", 0x5379F2,
        "\xB8\x00\x01\x00\x00\x89\x45\xE4\x46\xC1\xE6\x05\x29\xF0\x90\x90\x90", 0x11);

    create_patch("swComputeIntensity", "Fixed Fog Calculation", 0x536857, "\xB8\x00\x07\x00\x00\x5D\xC3", 7);

    patch_jmp("VehShowcase::PreSetup", "Fix showcase with addon cars", 0x4A5146, jump_type::never);

    patch_jmp("mmInterface::PlayerFillStats", "Always Show Score", 0x40C414, jump_type::never);

    create_patch("DriverMenu::DisplayDriverInfo", "Fix score alignment", 0x6410E0, "%d", 3);

    create_patch("ApplicationHelper", "DevelopmentMode", 0x40278A, "\x90\x90\x90\x90\x90\x90", 6);

    patch_jmp("mmCullCity::Init", "DevelopmentMode", 0x48C851, jump_type::always);

    patch_jmp("GetMeshSet", "Pager address check", 0x512AD5, jump_type::always);
    patch_jmp("mmBoundTemplate::LockIfResident", "Pager address check", 0x519329, jump_type::always);

    // create_patch("AudManager::Disable", "Actually disable sfx/music", 0x4E9098 + 1, "\x00\x00\x00\x00", 4);

    create_patch("mmGame::Init", "Use MapName", 0x40EEDF,
        "\x89\x5D\xFC\x89\x87\xBC\x00\x00\x00\x8D\xB7\xB4\x74\x01\x00\x89\x75\xC8\x8B\x0D\xE4\x84\x70\x00\xE8\x24"
        "\xCF\x0B\x00\x83\xC0\x2C\x50\x56\xE8\x3A\x66\x18\x00\x83\xC4\x08\x0F\xB6\x00\x24\xDF\x3C\x43\x0F\x94\xD0"
        "\xA3\xE0\x84\x70\x00\x90\x90\x90\x90\x90\x90\x90\x90",
        0x41);

    create_patch("asNetwork::JoinLobbySession", "Max Lobby Players", 0x4891EC + 3, "\x08", 1);

    create_patch("mmWheel::Update", "Wheel Speed", 0x47F179, "\xDD\xD8\x90\x90\x90\x90", 6);

    f32 skid_thresh = 0.5f;
    create_patch("SkidRotationThresh", "Fix skids", 0x63C014, &skid_thresh, sizeof(skid_thresh));

    for (usize addr : {
             0x4F5B6E,
             0x4F5C15,
             0x4F5E2C,

             0x4F4CD6,
             0x4F52E2,
             0x4F533C,
             0x4F5397,
             0x4F53BA,
             0x4F53EA,
             0x4F541A,
             0x4F54D3,
         })
    {
        create_patch("StreamObj", "Disable Thread Suspend", addr, "\x58\x31\xC0\x90\x90\x90", 6);
    }

    constexpr u32 pxt_checks[][2] {
        {0x444609, 0x444642}, // ?Draw@aiTrafficLightInstance@@UAIXH@Z
        {0x451DA5, 0x451DDE}, // ?Draw@aiVehicleInstance@@UAIXH@Z
        {0x471BDA, 0x471C0D}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x471C2D, 0x471C60}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x471C80, 0x471CB3}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x471F92, 0x471FC5}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x471FE5, 0x472018}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x472035, 0x472068}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x4728D5, 0x472908}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x472925, 0x472958}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x472978, 0x4729AB}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x48D7B9, 0x48D7F2}, // ?Update@mmCullCity@@UAEXXZ
        {0x4C9DF8, 0x4C9E31}, // ?Draw@mmBangerInstance@@UAIXH@Z
        {0x4CA0B7, 0x4CA0F0}, // ?Draw@mmHitBangerInstance@@UAIXH@Z
        {0x4CBA9F, 0x4CBAD8}, // ?Draw@mmGlassBangerInstance@@EAIXH@Z
    };

    for (const auto [from, to] : pxt_checks)
    {
        create_hook("PtxCount", "Avoid particle limit crash", from, to, hook_type::jmp);
    }

    patch_jmp("aiGoalChase::Update", "No Speed Boost", 0x461004, jump_type::always);
    create_patch("aiGoalChase::CalcSpeed", "No Brake Boost", 0x462B0F, "\xEB\x2A", 2);

    // patch_jmp("aiGoalChase::Update", "No Steering boost", 0x460FB0, jump_type::always);
    // create_patch("aiGoalChase::CalcSpeed", "No Steering boost", 0x4627E6, "\xEB\x2A", 2);
    // create_patch("aiGoalChase::CalcSpeed", "No Steering boost", 0x4629F9, "\xEB\x3A", 2);

    create_patch("MenuManager::ScanGlobalKeys", "Debug Text Alignment", 0x4B11DA + 1, "\x07", 1);

    for (usize addr : {0x413BC0, 0x415D72, 0x417A90})
    {
        create_patch("LocPlayerName", "lea don't mov", addr, "\x8D", 1);
    }

    create_patch("mmMultiCR::OppStealGold", "Icon Number", 0x41D93C + 6, "\x0A\x00\x00\x00", 4);

#ifndef ARTS_FINAL
    patch_jmp("mmLoader::Update", "Enable Task String", 0x48BA2D, jump_type::never);
    patch_jmp("mmLoader::Update", "Enable Task String", 0x48BA4B, jump_type::never);

    // create_patch("ApplicationHelper", "No paging in menus", 0x4029A6, "\x00\x00\x00\x00", 4);

    {
        patch_jmp("", "", 0x4744DD, jump_type::never);

        // Ambient Vehicle Colors
        u32 new_colors[] {
            0xFFB58900, // Yellow
            0xFFCB4B16, // Orange
            0xFFDC322F, // Red
            0xFFD33682, // Magenta
            0xFF6C71C4, // Violet
            0xFF268BD2, // Blue
            0xFF2AA198, // Cyan
            0xFF859900, // Green
            0xFF073642, // Base02
            0xFFEEE8D5, // Base2
        };

        std::memcpy((u32*) 0x639888, new_colors, sizeof(new_colors));
    }

    create_patch("", "", 0x4022B7 + 6, "\x05", 1);

    {
        const char* wp_name = "pt_check";
        create_patch("", "", 0x4124A7 + 1, &wp_name, sizeof(wp_name));
    }

    patch_jmp("", "", 0x474371, jump_type::never);
    patch_jmp("", "", 0x42A8E8, jump_type::never);
#endif
}