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

#include "agi/physlib.h"
#include "agi/pipeline.h"
#include "agi/texdef.h"
#include "arts7/sim.h"
#include "data7/args.h"
#include "data7/cache.h"
#include "data7/callback.h"
#include "data7/ipc.h"
#include "data7/memstat.h"
#include "data7/metaclass.h"
#include "data7/pager.h"
#include "data7/timer.h"
#include "eventq7/winevent.h"
#include "localize/localize.h"
#include "memory/allocator.h"
#include "memory/stack.h"
#include "memory/valloc.h"
#include "mmaudio/manager.h"
#include "mmcamtour/gamerecord.h"
#include "mmcity/loader.h"
#include "mmcityinfo/state.h"
#include "mmgame/gameman.h"
#include "mmgame/interface.h"
#include "mminput/input.h"
#include "mmphysics/phys.h"
#include "pcwindis/dxinit.h"
#include "pcwindis/dxsetup.h"
#include "pcwindis/setupdata.h"
#include "stream/hfsystem.h"
#include "stream/stream.h"
#include "stream/vfsystem.h"
#include "vector7/randmath.h"

#include <mem/cmd_param-inl.h>
#include <mem/module.h>
#include <mem/pattern.h>

#include "core/minwin.h"

const char* DEFAULT_CITY = "chicago";

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

void ApplicationHelper(i32 argc, char** argv)
{
    CloseCallback = GameCloseCallback;

    bool log_to_file = true;
    bool window = false;
    bool no_audio = false;
    int path_filter = 1;
    const char* ar_path = nullptr;
    DevelopmentMode = false;
    ALLOCATOR.SetDebug(true);

#define ARG(NAME) !std::strcmp(arg, NAME)
#define ARGN(NAME) !std::strncmp(arg, NAME, std::strlen(NAME))

    for (int i = 1; i < argc;)
    {
        char* arg = argv[i++];

        if (ARGN("-test"))
        {
            /*static char test_ar_path[128];
            arts_sprintf(test_ar_path, "c:\\mm\\shop\\build\\test%s.ar", arg + 5);

            argv[argc++] = const_cast<char*>("-path");
            argv[argc++] = const_cast<char*>(".");
            argv[argc++] = const_cast<char*>("-archive");
            argv[argc++] = test_ar_path;*/
        }
        else if (ARG("-window"))
        {
            window = true;
        }
        else if (ARG("-sw"))
        {
            dxiRendererChoice = 0;
        }
        else if (ARG("-noaudio"))
        {
            no_audio = true;
        }
        else if (ARG("-log"))
        {
            log_to_file = true;
        }
        else if (ARG("-path"))
        {
            DevelopmentMode = true;
            path_filter = 0;
        }
        else if (ARG("-fasttune"))
        {
            path_filter = 2;
        }
        else if (ARGN("-page"))
        {
            arg += 5;

            if (*arg)
            {
                page_override = 0;

                for (; *arg; ++arg)
                {
                    switch (*arg)
                    {
                        case 't': page_override |= ARTS_PAGE_TEXTURES; break;
                        case 'g': page_override |= ARTS_PAGE_GEOMETRY; break;
                        case 'b': page_override |= ARTS_PAGE_BOUNDS; break;
                    }
                }
            }
            else
            {
                page_override = ARTS_PAGE_TEXTURES | ARTS_PAGE_GEOMETRY | ARTS_PAGE_BOUNDS;
            }
        }
        else if (ARG("-nopage"))
        {
            page_override = 0;
        }
        else if (ARG("-sync"))
        {
            SynchronousMessageQueues = true;
        }
        else if (ARG("-adir"))
        {
            ar_path = argv[i++];
        }
        else if (ARG("-nobc"))
        {
            ALLOCATOR.SetDebug(false);
        }
        else if (ARG("-ime"))
        {
            bHaveIME = true;
        }
    }

    GBArgs.ParseArgs(argc, const_cast<const char**>(argv));

    if (GBArgs['f'] || window)
    {
        log_to_file = false;
    }
    else
    {
        // EnableNormalOutput = false;
        EnableDebugOutput = false;
    }

    if (log_to_file)
        LogToFile();

    Displayf("%s - %s", APPTITLE, VERSION_STRING);

    if (page_override == -1)
    {
        Warningf("**** PAGING: As specified in UI");
    }
    else
    {
        Warningf("**** PAGING: (%s %s %s)", (page_override & ARTS_PAGE_TEXTURES) ? "textures" : "",
            (page_override & ARTS_PAGE_BOUNDS) ? "bounds" : "", (page_override & ARTS_PAGE_GEOMETRY) ? "geom" : "");
    }

    if (HANDLE mutex = CreateMutexA(NULL, FALSE, "MidtownMadnessMutex");
        (mutex == NULL) || (WaitForSingleObject(mutex, 1) != WAIT_OBJECT_0))
    {
        MessageBoxA(NULL, LOC_STR(MM_IDS_ALREADY_RUNNING), APPTITLE, MB_ICONERROR);
        Quit();
    }

    if (MEMORYSTATUSEX memory {sizeof(memory)}; GlobalMemoryStatusEx(&memory))
    {
        Displayf("Avail Phys: %lldM  Avail Page: %lldM  Avail addr: %lldM", memory.ullAvailPhys >> 20,
            memory.ullAvailPageFile >> 20, memory.ullAvailVirtual >> 20);

        if (memory.ullAvailPageFile + memory.ullAvailPhys < (80 << 20))
        {
            MessageBoxA(NULL, LOC_STR(MM_IDS_LOW_MEMORY), APPTITLE, MB_ICONERROR);
            Quit();
        }
    }

    if (ULARGE_INTEGER free_bytes; GetDiskFreeSpaceExA(NULL, &free_bytes, NULL, NULL))
    {
        if (free_bytes.QuadPart < (128 << 10))
        {
            MessageBoxA(NULL, LOC_STR(MM_IDS_LOW_DISK), APPTITLE, 0);
        }
    }

    dxiConfig(argc, argv);
    ShowCursor(FALSE);
    bool show_cursor = true;

    dxiInit(APPTITLE, argc, argv);
    Displayf("dxiInit returned.");

    // TODO: Fix IME
    /*if (ImmGetContext(hwndMain))
    {
        bHaveIME = 1;
        hImmContext = reinterpret_cast<ulong>(ImmAssociateContext(hwndMain, 0));
    }*/

    switch (path_filter)
    {
        case 0: // Allow everything (dev)
            HierAllowPath = nullptr;
            break;

        case 1: // Only allow access to save data (default)
            HierAllowPath = const_cast<char*>("players\0");
            break;

        case 2: // Allow access to tuning data (fasttune)
            HierAllowPath = const_cast<char*>("players\0race\0tune\0");
            break;
    }

    CURHEAP = &ALLOCATOR;
    SAFEHEAP.Init((ALLOCATOR.IsDebug() ? 80 : 64) << 20, true);

    bool no_ui = false;

    MMSTATE.AudNumChannels = 32;
    MMSTATE.AudFlags = AudManager::GetHiSampleSizeMask() | AudManager::GetHiResMask() | AudManager::GetStereoOnMask() |
        AudManager::GetCommentaryOnMask() | AudManager::GetCDMusicOnMask() | AudManager::GetSoundFXOnMask();
    MMSTATE.AudDeviceName[0] = 0;
    MMSTATE.HasMidtownCD = false;
    MMSTATE.WaveVolume = 1.0f;
    MMSTATE.CDVolume = 0.5f;
    MMSTATE.AudBalance = 0.0f;
    MMSTATE.CurrentCar = 2;
    MMSTATE.AmbientDensity = 0.33f;
    MMSTATE.CopDensity = 1.0f;
    MMSTATE.MaxOpponents = 7.0f;
    MMSTATE.CopBehaviorFlag = 0;
    MMSTATE.PedDensity = 1.0f;
    MMSTATE.GameMode = mmGameMode::Cruise;
    MMSTATE.EventId = 0;
    MMSTATE.AutoTransmission = true;
    MMSTATE.EnableFF = true;
    MMSTATE.PhysicsRealism = 0.75f;
    MMSTATE.Weather = 0;
    MMSTATE.TimeOfDay = 1;
    MMSTATE.InputType = 0;
    MMSTATE.DisableDamage = false;
    MMSTATE.DisableAI = false;
    MMSTATE.TimeLimit = 0.0f;
    MMSTATE.UnlockAllRaces = false;
    MMSTATE.SuperCops = false;
    MMSTATE.AmbientCount = 100;
    MMSTATE.CameraIndex = 0;
    MMSTATE.HudmapMode = 0;
    MMSTATE.WideFov = false;
    MMSTATE.DashView = false;
    arts_strcpy(MMSTATE.IntroText, "");

    /*const*/ char* replay_name = nullptr;
    int priority = 2;

    for (int i = 1; i < argc;)
    {
        char* arg = argv[i++];

        if (ARG("-noui"))
        {
            const char* veh_name = "vpbug";

            if (asArg* veh = GBArgs['v'])
                veh_name = veh->sValues[0];

            MMSTATE.NoUI = true;
            arts_strcpy(MMSTATE.CarName, veh_name);
            MMSTATE.GameState = 1;
        }
        else if (ARG("-keyboard"))
        {
            MMSTATE.InputType = 1;
        }
        else if (ARG("-joystick"))
        {
            MMSTATE.InputType = 2;
        }
        else if (ARG("-wheel"))
        {
            MMSTATE.InputType = 4;
        }
        else if (ARG("-nodamage"))
        {
            MMSTATE.DisableDamage = true;
        }
        else if (ARG("-allrace"))
        {
            MMSTATE.UnlockAllRaces = true;
        }
        else if (ARG("-allcars"))
        {
            AllCars = true;
        }
        else if (ARG("-stoabs"))
        {
            BlitzCheatTime = 800;
            MMSTATE.DisableDamage = true;
            MMSTATE.UnlockAllRaces = true;
            AllCars = true;
        }
        else if (ARG("-supercops"))
        {
            MMSTATE.SuperCops = true;
        }
        else if (ARG("-ambient"))
        {
            MMSTATE.AmbientCount = std::atoi(argv[i++]);
        }
        else if (ARG("-noai"))
        {
            MMSTATE.AmbientDensity = 0.0f;
            MMSTATE.CopDensity = 0.0f;
            MMSTATE.MaxOpponents = 0.0f;
            MMSTATE.DisableAI = true;
        }
        else if (ARG("-nopcops"))
        {
            MMSTATE.CopDensity = 0.0f;
        }
        else if (ARG("-blitztime"))
        {
            BlitzCheatTime = std::atoi(argv[i++]);
        }
        else if (ARG("-race"))
        {
            MMSTATE.GameMode = mmGameMode::Race;
            MMSTATE.EventId = std::atoi(argv[i++]);
        }
        else if (ARG("-circuit"))
        {
            MMSTATE.GameMode = mmGameMode::Circuit;
            MMSTATE.EventId = std::atoi(argv[i++]);
        }
        else if (ARG("-blitz"))
        {
            MMSTATE.GameMode = mmGameMode::Blitz;
            MMSTATE.EventId = std::atoi(argv[i++]);
        }
        else if (ARG("-edit"))
        {
            MMSTATE.GameMode = mmGameMode::Edit;
        }
        else if (ARG("-archivecycle"))
        {
            CycleTest = 2;
        }
        else if (ARG("-sample"))
        {
            SampleStats = true;
        }
        else if (ARG("-dragtimer"))
        {
            DragTimer = true;
        }
        else if (ARG("-noopponents"))
        {
            MMSTATE.MaxOpponents = 0.0f;
        }
        else if (ARG("-prio"))
        {
            priority = std::atoi(argv[i++]);
        }
        else if (ARG("-crash"))
        {
            replay_name = argv[i++];
        }
        else if (ARG("-damagescale"))
        {
            GlobalDamageScale = static_cast<f32>(std::atof(argv[i++]));
        }
    }

#undef ARG
#undef ARGN

    if (priority >= 0 && priority < 4)
    {
        static const char* const priority_names[4] = {"idle", "normal", "high", "REALTIME"};
        Warningf("Running with %s priority class.", priority_names[priority]);

        static u32 const priority_classes[4] {
            IDLE_PRIORITY_CLASS, NORMAL_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, REALTIME_PRIORITY_CLASS};
        SetPriorityClass(GetCurrentProcess(), priority_classes[priority]);
    }

    PHYS.SetGravity(-19.8f);
    InitialCursorState = window ? 0 : -1;

    if (CycleTest == 0 && GBArgs['c'])
    {
        if (asArg* time = GBArgs['c'])
        {
            CycleTest = 1;
            CycleTime = std::clamp<f32>(time->fValues[0], 5.0f, 600.0f);
        }
    }

    if (asArg* city = GBArgs['l'])
    {
        arts_strcpy(CityName, city->sValues[0]);
        MMSTATE.GameMode = mmGameMode::Cruise;
    }
    else
    {
        arts_strcpy(CityName, DEFAULT_CITY);
    }

    char ar_path_buffer[1024];

    while (!MMSTATE.Closing)
    {
        LoadTimer.Reset();
        SAFEHEAP.Restart();

        MemStat module_init {"Module init"};
        InitEventQueue();

        {
            ARTS_MEM_STAT("AGI Startup");

            if (InitPipeline(APPTITLE, argc, argv))
            {
                ShutdownPipeline();
                DeallocateEventQueue();

                if (!MMSTATE.GameState)
                    Quitf("Can't start UI, this should never happen.");

                MessageBoxA(NULL, LOC_STR(MM_IDS_LOW_VRAM), APPTITLE, MB_ICONERROR);
                MMSTATE.GameState = 0;
                continue;
            }
        }

        {
            ARTS_MEM_STAT("ARTS Init");

            /*ARTSPTR = */ new asSimulation();
            ARTSPTR->Init(const_cast<char*>("."), argc, argv);

            if (!VFS)
            {
                if (!ar_path)
                {
                    GetModuleFileNameA(NULL, ar_path_buffer, ARTS_SIZE32(ar_path_buffer));

                    if (char* dir = std::strrchr(ar_path_buffer, '\\'))
                    {
                        *dir = '\0';
                        ar_path = ar_path_buffer;
                    }
                    else
                    {
                        ar_path = ".";
                    }
                }

                for (FileInfo* f = HFS.FirstEntry(ar_path); f; f = HFS.NextEntry(f))
                {
                    if (char* ext = std::strrchr(f->Path, '.');
                        ext && !arts_stricmp(ext, ".AR") && arts_strnicmp(f->Path, "TEST", 4))
                    {
                        char path[1024];
                        arts_sprintf(path, "%s/%s", ar_path, f->Path);

                        if (Stream* stream = arts_fopen(path, "r"))
                        {
                            Displayf("Adding '%s' in autosearch...", f->Path);
                            new VirtualFileSystem(stream);
                            // DevelopmentMode = false;
                        }
                    }
                }

                if (Stream* phys_db = arts_fopen("mtl/physics.db", "r"))
                {
                    agiPhysLib.Load(phys_db);
                    delete phys_db;
                }
            }
        }

        if (!GBArgs['f'] && !window)
            ARTSPTR->SetDebug(false);

        {
            ARTS_MEM_STAT("Audio manager");

            InitAudioManager();

            if (no_audio)
                AUDMGRPTR->Disable(-1, -1);
        }

        {
            ARTS_MEM_STAT("GameInput");

            /*GameInputPtr = */ new mmInput();
            GameInputPtr->AttachToPipe();
            GameInputPtr->Init(MMSTATE.InputType);
        }

        mmGameManager* game_manager = nullptr;
        mmInterface* mm_interface = nullptr;

        {
            mmLoader loader;

            if (page_override == -1)
            {
                if (MMSTATE.GameState)
                    EnablePaging = MMSTATE.EnablePaging ? (ARTS_PAGE_TEXTURES | ARTS_PAGE_GEOMETRY) : 0;
                else
                    EnablePaging = ARTS_PAGE_TEXTURES;
            }
            else
            {
                EnablePaging = page_override;
            }

            {
                ARTS_MEM_STAT("Cache and pager.");

                if (EnablePaging)
                {
                    CACHE.Init(2 << 20, 2048, "CACHE");
                    TEXCACHE.Init(4 << 20, 256, "TEXCACHE");
                }

                PAGER.Init(128, false);
            }

            loader.Reset();

            switch (MMSTATE.GameState)
            {
                case 0: {
                    loader.Init(const_cast<char*>("title_screen"), 0.0f, 0.0f);

                    if (GraphicsChange)
                    {
                        loader.BeginTask(LOC_STRING(MM_IDS_LOADING_GRAPHICS), 0.0f);
                    }
                    else
                    {
                        if (MMSTATE.HasMidtownCD)
                            AUDMGRPTR->PlayCDTrack(3, true);

                        loader.BeginTask(LOC_STRING(MM_IDS_LOADING_INTERFACE), 0.0f);
                    }

                    mm_interface = new mmInterface();
                    ARTSPTR->AddChild(mm_interface);

                    mm_interface->Reset();
                    mm_interface->ShowMain(CycleState);

                    CycleState = 1;
                    break;
                }

                case 1: {
                    if (GenerateLoadScreenName())
                        loader.Init(LoadScreen, 366.0f / 640.0f, 414.0f / 480.0f);
                    else
                        loader.Init(LoadScreen, 15.0f / 640.0f, 456.0f / 480.0f);

                    ARTS_MEM_STAT("GameManager");

                    loader.BeginTask(LOC_STRING(MM_IDS_LOADING_RACE), 0.0f);

                    AUDMGRPTR->AssignWaveVolume(MMSTATE.WaveVolume);
                    AUDMGRPTR->AssignCDVolume(MMSTATE.CDVolume);

                    if (MMSTATE.HasMidtownCD)
                        AUDMGRPTR->PlayCDTrack(2, true);

                    game_manager = /*mmGameManager::Instance = */ new mmGameManager();
                    ARTSPTR->AddChild(game_manager);

                    game_manager->Reset();

                    CycleState = 2;

                    if (SampleStats)
                    {
                        SystemStatsRecord = new mmGameRecord(0.1f);
                        SystemStatsRecord->Init(1000);
                    }

                    if (replay_name)
                        game_manager->LoadReplay(replay_name);

                    break;
                }

                default: Quitf("Invalid GameState %i", MMSTATE.GameState);
            }

            ARTSPTR->ResChange(Pipe()->GetWidth(), Pipe()->GetHeight());

            loader.EndTask(0.0f);
        }

        MMSTATE.GameState = -1;
        MMSTATE.Closing = 0;

        ALLOCATOR.SanityCheck();

        // TouchMemory(ALLOCATOR.GetHeapStart(), ALLOCATOR.GetHeapSize());
        module_init.End();

        Displayf("********* Load time = %f seconds; %dK allocated.", LoadTimer.Time(), ALLOCATOR.GetHeapUsed() >> 10);

        if (show_cursor)
        {
            ShowCursor(TRUE);
            show_cursor = false;
        }

        GameLoop(mm_interface, game_manager, replay_name);

        if (game_manager)
        {
            if (SampleStats)
            {
                char csv_name[80];
                arts_sprintf(csv_name, "gstat_%d_%d_%04d.csv", MMSTATE.GameMode, MMSTATE.EventId,
                    static_cast<i32>(frand() * 1000.0f));
                SystemStatsRecord->Dump(csv_name);

                delete SystemStatsRecord;
                SystemStatsRecord = nullptr;
            }

            if (!replay_name)
                game_manager->SaveReplay(const_cast<char*>("last.rpl"));
        }

        PAGER.Shutdown();
        AUDMGRPTR->Disable(-1, -1);
        ALLOCATOR.SanityCheck();

        delete mm_interface;
        delete game_manager;

        if (EnablePaging)
        {
            TEXCACHE.Shutdown();
            CACHE.Shutdown();
        }

        delete GameInputPtr;
        delete AUDMGRPTR;

        GameResetCallbacks.Invoke(true);

        if (!VFS)
        {
            while (FileSystem::FSCount > 1) // Leave the HFS
                delete FileSystem::FS[FileSystem::FSCount - 1];
        }

        delete ARTSPTR;

        ShutdownPipeline();

        // TODO: Fix IME
        /*if (bHaveIME)
        {
            dxiShutdown();
            ChangeDisplaySettingsA(0, 0);
        }*/

        DeallocateEventQueue();

        HashTable::KillAll();
        MetaClass::UndeclareAll();

        if (no_ui)
            break;
    }

    SAFEHEAP.Kill();
    dxiShutdown();
    dxiChangeDisplaySettings(0, 0, 0);
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

static mem::cmd_param PARAM_affinity {"affinity"};
static mem::cmd_param PARAM_sync {"sync"};
static mem::cmd_param PARAM_res_hack {"reshack"};

void Application(i32 argc, char** argv)
{
    ARTS_EXCEPTION_BEGIN
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
    patch_jmp("mmCullCity::InitTimeOfDayAndWeather", "Additive Blending Check", 0x48DDD2, jump_type::always);
    patch_jmp("SetTexQualString", "Additive Blending Check", 0x49A29F, jump_type::never);

    // Checked in GetPackedTexture, only necessary if agiRQ.TextureQuality <= 2
    // create_patch("aiVehicleOpponent::Init", "agiRQ.TextureQuality", 0x44DC2A, "\xEB\x06", 2);

    if (false) // Hack, replaces 16-bit handler with 32-bit handler
    {
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D419, "\x83\x79\x04\x04", 4);
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D439, "\x8D\x04\xBA", 3);
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D47E, "\x8B\x00\x89\x04\x93\x90\x90", 7);
    }

    // Allocates 2 extra agiTexDef slots instead of 1, in case TextureCount == 0 (Assumes new memory is zeroed out)
    // Won't avoid some crashes, but should help avoid any out of bounds reads or writes
    // This also needs to be patched in agiMeshSet::DoPageIn
    // lea edx,[ecx*4+0x8]
    create_patch("agiMeshSet::BinaryLoad", "Avoid empty texdefs", 0x502D43, "\x8D\x14\x8D\x08\x00\x00\x00", 7);

    // Hack, avoids attempting to access freed memory (https://github.com/0x1F9F1/Open1560/issues/15)
    // Luckily the aiVehicleSpline destructor doesn't do actually do anything anyway (apart from set mmInstanceHeap.HeapHead, which we want to avoid anyway)
    patch_jmp("aiVehicleSpline::~aiVehicleSpline", "Avoid freeing aiVehicleInstance", 0x459F84, jump_type::always);

    // create_patch("sfPointer::ResChange", "Use Old Cursor", 0x641F2C, "pointer", 8);

    // create_patch("DoScan", "Stop Touching Memory", 0x4046D0, "\xC3", 1);

    // create_patch("MultiTexture", "Enable D3D MultiTexture", 0x530788 + 6, "\x02", 1);

    patch_jmp("sfPointer::Update", "Enable cursor in windowed mode", 0x4BDAA4, jump_type::never);

    patch_jmp("PolarCamCS", "No Collision", 0x4FAFF4, jump_type::always);

    create_packed_patch<f32>("PolarCamCS", "Increase Max XCAM Distance", 0x620340, 250.0f);

    create_patch("aiVehicleOpponent::Reset", "Fix List::Clear memory leak", 0x44DE4D,
        "\x89\xF9\xE8\x3C\xE4\x12\x00\x90\x8B\xD3\x42", 11);

    create_patch(
        "aiVehiclePolice::Reset", "Fix List::Clear memory leak", 0x44511C, "\x89\xF9\xE8\x6D\x71\x13\x00\x90", 8);

    create_patch("agiSWTexDef::BeginGfx", "MipMapCount Comparison", 0x537797, "\x7E", 1);
    create_patch("agiSWTexDef::EndGfx", "MipMapCount Comparison", 0x537833, "\x7E", 1);

    // Software renderer breaks with resolutions > 2048. Is this just a DDRAW limit?
    create_packed_patch<u16>("TestResolution", "Max Software Resolution", 0x575E6C + 3, 2048);
    create_packed_patch<u16>("TestResolution", "Max Software Resolution", 0x575E73 + 2, 2048);

    create_patch("agiSWTexLut::BeginGfx", "Fixed Fog Calculation", 0x5379F2,
        "\xB8\x00\x01\x00\x00\x89\x45\xE4\x46\xC1\xE6\x05\x29\xF0\x90\x90\x90", 0x11);

    create_patch("swComputeIntensity", "Fixed Fog Calculation", 0x536857, "\xB8\x00\x07\x00\x00\x5D\xC3", 7);

    patch_jmp("VehShowcase::PreSetup", "Fix showcase with addon cars", 0x4A5146, jump_type::never);

    patch_jmp("mmInterface::PlayerFillStats", "Always Show Score", 0x40C414, jump_type::never);

    create_patch("DriverMenu::DisplayDriverInfo", "Fix score alignment", 0x6410E0, "%d", 3);

    patch_jmp("mmCullCity::Init", "DevelopmentMode", 0x48C851, jump_type::always);

    patch_jmp("GetMeshSet", "Pager address check", 0x512AD5, jump_type::always);
    patch_jmp("mmBoundTemplate::LockIfResident", "Pager address check", 0x519329, jump_type::always);

    // create_patch("AudManager::Disable", "Actually disable sfx/music", 0x4E9098 + 1, "\x00\x00\x00\x00", 4);

    create_patch("mmGame::Init", "Use MapName", 0x40EEDF,
        "\x89\x5D\xFC\x89\x87\xBC\x00\x00\x00\x8D\xB7\xB4\x74\x01\x00\x89\x75\xC8\x8B\x0D\xE4\x84\x70\x00\xE8\x24"
        "\xCF\x0B\x00\x83\xC0\x2C\x50\x56\xE8\x3A\x66\x18\x00\x83\xC4\x08\x0F\xB6\x00\x24\xDF\x3C\x43\x0F\x94\xD0"
        "\xA3\xE0\x84\x70\x00\x90\x90\x90\x90\x90\x90\x90\x90",
        0x41);

    create_packed_patch<u32>("asNetwork::JoinLobbySession", "Max Lobby Players", 0x4891EC + 3, 8);

    create_patch("mmWheel::Update", "Wheel Speed", 0x47F179, "\xDD\xD8\x90\x90\x90\x90", 6);

    create_packed_patch<f32>("SkidRotationThresh", "Fix skids", 0x63C014, 0.5f);

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

    create_packed_patch<u8>(
        "MenuManager::ScanGlobalKeys", "Debug Text Alignment", 0x4B11DA + 1, 0x7); // CENTER | VCENTER | BORDER

    for (usize addr : {0x413BC0, 0x415D72, 0x417A90})
    {
        create_patch("LocPlayerName", "lea don't mov", addr, "\x8D", 1);
    }

    create_packed_patch<u32>("mmMultiCR::OppStealGold", "Icon Number", 0x41D93C + 6, 10);

#ifndef ARTS_FINAL
    patch_jmp("mmLoader::Update", "Enable Task String", 0x48BA2D, jump_type::never);
    patch_jmp("mmLoader::Update", "Enable Task String", 0x48BA4B, jump_type::never);

    {
        for (usize addr : {
                 0x4743C9,
                 0x47441D,
                 0x474471,
                 0x4744DD,
             })
        {
            patch_jmp("mmCar::VehNameRemap", "Egg Check", addr, jump_type::never);
        }

        // Ambient Vehicle Colors
        static const u32 AmbientVehiclePalette[] {
            0xFFB58900, // Yellow
            0xFFCB4B16, // Orange
            0xFFDC322F, // Red
            0xFFD33682, // Magenta
            0xFF6C71C4, // Violet
            0xFF268BD2, // Blue
            0xFF2AA198, // Cyan
            0xFF859900, // Green
        };

        create_hook("aiVehicleAmbient::Init", "Custom Ambient Colors", 0x44EFF1,
            alloc_proxy<ARTS_SIZE(AmbientVehiclePalette) * sizeof(u32**)>, hook_type::call);

        create_packed_patch<const void*>(
            "aiVehicleAmbient::Init", "Custom Ambient Colors", 0x44EFF6 + 1, &AmbientVehiclePalette);

        create_packed_patch<u32>(
            "aiVehicleAmbient::Init", "Custom Ambient Colors", 0x44F008 + 3, ARTS_SIZE32(AmbientVehiclePalette));

        create_packed_patch<u32>(
            "aiVehicleAmbient::Init", "Custom Ambient Colors", 0x44F100 + 1, ARTS_SIZE32(AmbientVehiclePalette));
    }

    {
        const char* wp_name = "pt_check";
        create_patch(
            "mmGameEdit::InitGameObjects", "Use a valid waypoint object", 0x4124A7 + 1, &wp_name, sizeof(wp_name));
    }

    patch_jmp("mmCar::VehNameRemap", "Work in all game modes", 0x474371, jump_type::never);
    patch_jmp("mmPlayer::Init", "Enable FreeCam when not in DevelopmentMode", 0x42A8E8, jump_type::never);
#endif
}
