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
#include "agid3d/pcpipe.h"
#include "agisdl/sdlswpipe.h"
#include "agisw/swddraw.h"
#include "agisw/swpipe.h"
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
#include "mmui/graphics.h"
#include "pcwindis/dxinit.h"
#include "pcwindis/dxsetup.h"
#include "pcwindis/pcwindis.h"
#include "pcwindis/setupdata.h"
#include "stream/hfsystem.h"
#include "stream/stream.h"
#include "stream/vfsystem.h"
#include "vector7/randmath.h"

#include <mem/cmd_param-inl.h>
#include <mem/module.h>
#include <mem/pattern.h>

#define SDL_MAIN_NEEDED
#include <SDL.h>

#include "core/minwin.h"

#ifdef ARTS_ENABLE_OPENGL
#    include "agigl/glpipe.h"
#endif

const char* DEFAULT_CITY = "chicago";

// ?GameCloseCallback@@YAXXZ
ARTS_EXPORT /*static*/ void GameCloseCallback()
{
    MMSTATE.GameState = 0;
    MMSTATE.Shutdown = true;
}

// ?TouchMemory@@YAXPAXH@Z
ARTS_EXPORT /*static*/ void TouchMemory(void*, i32)
{}

// ?exeDirFile@@YAPADPAD0@Z
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

static Callback GameResetCallbacks[32];
CallbackArray OnGameReset {GameResetCallbacks, ARTS_SIZE(GameResetCallbacks)};

static void CheckSystem()
{
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
            MessageBoxA(NULL, LOC_STR(MM_IDS_LOW_DISK), APPTITLE, MB_OK);
        }
    }
}

static void LoadArchives(const char* base_path)
{
    char module_path[ARTS_MAX_PATH];

    if (!base_path)
    {
        GetModuleFileNameA(NULL, module_path, ARTS_SIZE32(module_path));

        if (char* dir = std::strrchr(module_path, '\\'))
        {
            *dir = '\0';
            base_path = module_path;
        }
        else
        {
            base_path = ".";
        }
    }

    char* files[256];
    usize file_count = 0;

    if (Ptr<Stream> input {arts_fopen(arts_formatf<ARTS_MAX_PATH>("%s/mods.txt", base_path), "r")})
    {
        char path[ARTS_MAX_PATH];

        while (input->Gets(path, ARTS_SSIZE(path)))
        {
            if (char* end = std::strpbrk(path, "\r\n"))
                *end = '\0';

            if (path[0] != '\0' && path[0] != '#')
            {
                if (file_count < ARTS_SIZE(files))
                    files[file_count++] = arts_strdup(path);
            }
        }
    }
    else
    {
        for (FileInfo* f = HFS.FirstEntry(base_path); f; f = HFS.NextEntry(f))
        {
            if (const char* ext = std::strrchr(f->Path, '.');
                ext && !arts_stricmp(ext, ".AR") && arts_strnicmp(f->Path, "TEST", 4))
            {
                if (file_count < ARTS_SIZE(files))
                    files[file_count++] = arts_strdup(f->Path);
            }
        }

        std::sort(files, files + file_count, [](const char* lhs, const char* rhs) {
            const auto get_priority = [](const char* name) -> i32 {
                if (!arts_stricmp(name, "1560.ar"))
                    return 1;

                return 0;
            };

            if (i32 prio = get_priority(rhs) - get_priority(lhs); prio)
                return prio < 0;

            return std::strcmp(lhs, rhs) < 0;
        });
    }

    for (usize i = 0; i < file_count; ++i)
    {
        char* path = files[i];

        if (Ptr<Stream> stream {arts_fopen(arts_formatf<ARTS_MAX_PATH>("%s/%s", base_path, path), "r")})
        {
            Displayf("Adding '%s' in autosearch...", path);
            /*FileSystem::FS[...] = */ new VirtualFileSystem(AsOwner(stream));
            // DevelopmentMode = false;
        }

        arts_free(path);
    }
}

static void UnloadArchives()
{
    while (FileSystem::FSCount > 1) // Leave HFS
    {
        delete FileSystem::FS[FileSystem::FSCount - 1];
    }
}

#define ARG(NAME) !std::strcmp(arg, NAME)
#define ARGN(NAME) !std::strncmp(arg, NAME, std::strlen(NAME))

static void MainPhase(i32 argc, char** argv)
{
    LoadTimer.Reset();

    char* replay_name = nullptr;
    char* ar_path = nullptr;
    bool no_audio = false;

    for (int i = 1; i < argc;)
    {
        // FIXME: Extra args may read out of bounds
        char* arg = argv[i++];

        if (ARG("-crash"))
        {
            replay_name = argv[i++];
        }
        else if (ARG("-adir"))
        {
            ar_path = argv[i++];
        }
        else if (ARG("-noaudio"))
        {
            no_audio = true;
        }
    }

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
            return;
        }
    }

    {
        ARTS_MEM_STAT("ARTS Init");

        /*ARTSPTR = */ new asSimulation();
        ARTSPTR->Init(const_cast<char*>("."), argc, argv);

        if (!VFS)
        {
            LoadArchives(ar_path);
            agiPhysLib.Load("mtl/physics.db");
        }
    }

    if (!GBArgs['f'])
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
        GameInputPtr->Init(static_cast<i32>(MMSTATE.InputType));
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

#ifdef ARTS_DEV_BUILD
                if (SampleStats)
                {
                    SystemStatsRecord = new mmGameRecord(0.1f);
                    SystemStatsRecord->Init(1000);
                }
#endif

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
    MMSTATE.Shutdown = false;

    ALLOCATOR.SanityCheck();
    // TouchMemory(ALLOCATOR.GetHeapStart(), ALLOCATOR.GetHeapSize());

    module_init.End();
    Displayf("********* Load time = %f seconds; %dK allocated.", LoadTimer.Time(), ALLOCATOR.GetHeapUsed() >> 10);

    GameLoop(mm_interface, game_manager, replay_name);

#ifdef ARTS_DEV_BUILD
    if (game_manager)
    {
        if (SampleStats)
        {
            SystemStatsRecord->Dump(arts_formatf<80>(
                "gstat_%d_%d_%04d.csv", MMSTATE.GameMode, MMSTATE.EventId, static_cast<i32>(frand() * 1000.0f)));

            delete SystemStatsRecord;
            SystemStatsRecord = nullptr;
        }

        if (!replay_name)
            game_manager->SaveReplay(const_cast<char*>("last.rpl"));
    }
#endif

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

    OnGameReset.Invoke(true);

    if (!VFS)
    {
        UnloadArchives();
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
}

static mem::cmd_param PARAM_heapsize {"heapsize"};

void ApplicationHelper(i32 argc, char** argv)
{
    CloseCallback = GameCloseCallback;

    int path_filter = 1;
    int priority = 2;
    DevelopmentMode = false;
    ALLOCATOR.SetDebug(true);

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
        else if (ARG("-sw"))
        {
            dxiRendererChoice = 0;
        }
        else if (ARG("-log"))
        {
            LogToFile();
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
        else if (ARG("-nobc"))
        {
            ALLOCATOR.SetDebug(false);
        }
        else if (ARG("-ime"))
        {
            // TODO: Fix IME
            // bHaveIME = true;
        }
        else if (ARG("-prio"))
        {
            priority = std::atoi(argv[i++]);
        }
    }

    if (priority >= 0 && priority < 4)
    {
        static const char* const priority_names[4] = {"idle", "normal", "high", "REALTIME"};
        Warningf("Running with %s priority class.", priority_names[priority]);

        static u32 const priority_classes[4] {
            IDLE_PRIORITY_CLASS, NORMAL_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, REALTIME_PRIORITY_CLASS};
        SetPriorityClass(GetCurrentProcess(), priority_classes[priority]);
    }

    GBArgs.ParseArgs(argc, const_cast<const char**>(argv));

    if (!GBArgs['f'])
        EnableDebugOutput = false;

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

    CheckSystem();

    dxiConfig(argc, argv);
    SDL_ShowCursor(0);
    InitialCursorState = 0;

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
    SAFEHEAP.Init((PARAM_heapsize.get_or(64) + (ALLOCATOR.IsDebug() ? 16 : 0)) << 20, true);

    MMSTATE.SetDefaults();
    bool no_ui = MMSTATE.ParseStateArgs(argc, argv);

    PHYS.SetGravity(-19.8f);

#ifdef ARTS_DEV_BUILD
    if (CycleTest == 0 && GBArgs['c'])
    {
        if (asArg* time = GBArgs['c'])
        {
            CycleTest = 1;
            CycleTime = std::clamp<f32>(time->fValues[0], 5.0f, 600.0f);
        }
    }
#endif

    if (asArg* city = GBArgs['l'])
    {
        arts_strcpy(CityName, city->sValues[0]);
        MMSTATE.GameMode = mmGameMode::Cruise;
    }
    else
    {
        arts_strcpy(CityName, DEFAULT_CITY);
    }

    while (!MMSTATE.Shutdown)
    {
        SAFEHEAP.Restart();
        MainPhase(argc, argv);

        if (no_ui)
            break;
    }

    SAFEHEAP.Kill();
    dxiShutdown();
    dxiChangeDisplaySettings(0, 0, 0);
}

#undef ARG
#undef ARGN

static mem::cmd_param PARAM_width {"width"};
static mem::cmd_param PARAM_height {"height"};

Owner<agiPipeline> CreatePipeline(i32 argc, char** argv)
{
    dxiRendererInfo_t& info = GetRendererInfo();

    if (bHaveIME)
    {
        dxiShutdown();

        if (MMSTATE.GameState)
        {
            dxiFlags = (dxiFlags & ~DXI_FLAG_SYSTEM_MEMORY) | DXI_FLAG_FULL_SCREEN | DXI_FLAG_DOUBLE_BUFFER;
            InitialCursorState = -1;
        }
        else
        {
            dxiFlags = (dxiFlags & ~(DXI_FLAG_FULL_SCREEN | DXI_FLAG_DOUBLE_BUFFER)) | DXI_FLAG_SYSTEM_MEMORY;

            if (dxiChangeDisplaySettings(640, 480, 16))
            {
                MessageBoxA(NULL, LOC_STR(MM_IDS_USE_HIGH_COLOR), APPTITLE, MB_ICONERROR);
                Quit();
            }

            InitialCursorState = 0;
        }

        dxiInit(APPTITLE, 0, 0);
    }

    Ptr<agiPipeline> pipe;

    if (MMSTATE.GameState)
    {
        i32 res_choice = info.ResChoice;
        bRenderToSystem = RenderToSystemMemory;

        switch (info.Type)
        {
            case dxiRendererType::DX6_Soft: pipe = AsPtr(swCreatePipeline(argc, argv)); break;
            case dxiRendererType::DX6_GDI:
            case dxiRendererType::DX6: pipe = AsPtr(d3dCreatePipeline(argc, argv)); break;

#ifdef ARTS_ENABLE_OPENGL
            case dxiRendererType::OpenGL: pipe = AsPtr(glCreatePipeline(argc, argv)); break;
            case dxiRendererType::SDL2: pipe = AsPtr(sdlCreatePipeline(argc, argv)); break;
#endif
        }

        i32 width = pipe->GetWidth();
        i32 height = pipe->GetHeight();

        if (info.ResCount)
        {
            dxiResolution& res = info.Resolutions[res_choice];
            width = res.uWidth;
            height = res.uHeight;
        }

        pipe->SetRes(PARAM_width.get_or(width), PARAM_height.get_or(height));

        if (pipe->Validate())
        {
            pipe->EndAllGfx();
            pipe = nullptr;

            MessageBoxA(NULL, LOC_STR(MM_IDS_GRAPHICS_ERROR), APPTITLE, MB_ICONERROR);

            pipe = AsPtr(swCreatePipeline(argc, argv));
            pipe->SetRes(640, 480);
        }
    }
    else
    {
        bRenderToSystem = true;

        switch (bHaveIME ? dxiRendererType::DX6_Soft : info.Type)
        {
            case dxiRendererType::DX6_Soft: pipe = AsPtr(swCreatePipeline(argc, argv)); break;
            case dxiRendererType::DX6_GDI:
            case dxiRendererType::DX6: pipe = AsPtr(d3dCreatePipeline(argc, argv)); break;

#ifdef ARTS_ENABLE_OPENGL
            case dxiRendererType::OpenGL: pipe = AsPtr(glCreatePipeline(argc, argv)); break;
            case dxiRendererType::SDL2: pipe = AsPtr(sdlCreatePipeline(argc, argv)); break;
#endif
        }

        pipe->SetRes(640, 480);

        if (pipe->Validate())
        {
            MessageBoxA(NULL, LOC_STR(MM_IDS_REDETECT_VIDEO), APPTITLE, MB_ICONERROR);
            Quit();
        }
    }

    return AsOwner(pipe);
}

#include <shellapi.h>

static char** GetCommandLineUTF8(const wchar_t* wCmdLine, int* pNumArgs)
{
    int argc = 0;
    LPWSTR* wargv = CommandLineToArgvW(wCmdLine, &argc);

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

static char** GetCommandFileUTF8(int* pNumArgs)
{
    HANDLE handle =
        CreateFileA("commandline.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (handle == INVALID_HANDLE_VALUE)
        return nullptr;

    DWORD file_size = GetFileSize(handle, NULL);
    LPCH file_data = (LPCH) arts_malloc(file_size);

    if (!ReadFile(handle, file_data, file_size, &file_size, NULL))
        return nullptr;

    CloseHandle(handle);

    for (DWORD i = 0; i < file_size; ++i)
    {
        if (file_data[i] < 0x20)
            file_data[i] = ' ';
    }

    int wide_size = MultiByteToWideChar(CP_UTF8, 0, file_data, (int) file_size, NULL, 0);
    wchar_t* wide_data = (wchar_t*) arts_malloc((wide_size + 4) * sizeof(wchar_t));

    std::wmemcpy(wide_data, L"\"\" ", 3);
    MultiByteToWideChar(CP_UTF8, 0, file_data, (int) file_size, wide_data + 3, wide_size);
    wide_data[wide_size + 3] = L'\0';
    arts_free(file_data);

    char** result = GetCommandLineUTF8(wide_data, pNumArgs);
    arts_free(wide_data);

    return result;
}

static mem::cmd_param PARAM_clean_dir {"cleandir"};
static mem::cmd_param PARAM_console {"console"};
static mem::cmd_param PARAM_period {"period"};

static mem::cmd_param PARAM_speedrun {"speedrun"};

void InitPatches();

extern "C" int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE PrevInstance, LPSTR lpCmdLine, int nShowCmd);

ARTS_EXPORT int WINAPI MidtownMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    return WinMain(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());

        return 1;
    }

    SDL_SetHintWithPriority(
        SDL_HINT_TIMER_RESOLUTION, arts_formatf<16>("%u", PARAM_period.get_or<u32>(1)), SDL_HINT_OVERRIDE);

    SDL_LogSetOutputFunction(
        [](void* /*userdata*/, int /*category*/, SDL_LogPriority priority, const char* message) {
            i32 level = 0;

            switch (priority)
            {
                case SDL_LOG_PRIORITY_VERBOSE: level = 0; break;
                case SDL_LOG_PRIORITY_DEBUG: level = 0; break;
                case SDL_LOG_PRIORITY_INFO: level = 0; break;
                case SDL_LOG_PRIORITY_WARN: level = 1; break;
                case SDL_LOG_PRIORITY_ERROR: level = 2; break;
                case SDL_LOG_PRIORITY_CRITICAL: level = 2; break; // TODO: Make fatal?
            }

            Printerf(level, "%s", message);
        },
        nullptr);

    SDL_SetWindowsMessageHook(
        [](void* /*userdata*/, void* hWnd, unsigned int message, u64 wParam, i64 lParam) {
            SDLWindowProc(static_cast<HWND>(hWnd), message, static_cast<WPARAM>(wParam), static_cast<LPARAM>(lParam));
        },
        nullptr);

    if (int file_argc = 0; char** file_argv = GetCommandFileUTF8(&file_argc))
    {
        mem::cmd_param::init(file_argc, file_argv);
        arts_free(file_argv);
    }

    mem::cmd_param::init(argc, argv);

    if (PARAM_speedrun)
    {
        const char* const args[] {"", "-nosmoothstep", "-maxfps=60", "-speedycops"};

        mem::cmd_param::init(ARTS_SSIZE32(args), args);
    }

    if (PARAM_console.get_or(false))
        LogToConsole();

    InitPatches();

    Displayf("Processed %zu Init Functions", mem::init_function::init());

    MetaClass::FixupClasses();

    Application(argc, argv);

    SDL_Quit();

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

b32 GenerateLoadScreenName()
{
    arts_strcpy(LoadScreen, "title_screen");

    // TODO: Handle other cities
    // TODO: Use mmCityInfo.MapName
    if (std::strcmp(CityName, "chicago"))
        return false;

    char name[40];
    arts_strcpy(name, CityName);

    switch (MMSTATE.GameMode)
    {
        case mmGameMode::Cruise:
            arts_strcat(name, "ro");
            arts_sprintf(LoadScreen, "%s", name);
            return true;
        case mmGameMode::Checkpoint:
            arts_strcat(name, "ch");
            arts_sprintf(LoadScreen, "%s%d", name, MMSTATE.EventId + 1);
            return true;
        case mmGameMode::CnR:
            arts_strcat(name, "cr");
            arts_sprintf(LoadScreen, "%s", name);
            return true;
        case mmGameMode::Circuit:
            arts_strcat(name, "ci");
            arts_sprintf(LoadScreen, "%s%d", name, MMSTATE.EventId + 1);
            return true;
        case mmGameMode::Blitz:
            arts_strcat(name, "bl");
            arts_sprintf(LoadScreen, "%s%d", name, MMSTATE.EventId + 1);
            return true;
        default: return false;
    }
}

void InitAudioManager()
{
    /*AUDMGRPTR = */ new AudManager();

    AUDMGRPTR->SteroOn = (MMSTATE.AudFlags & AudManager::GetStereoOnMask()) != 0;

    AUDMGRPTR->Init(150, MMSTATE.AudFlags & (AudManager::GetDSound3DMask() | AudManager::GetUsingEAXMask()),
        MMSTATE.AudDeviceName, // FIXME: This is empty the first time
        (MMSTATE.AudFlags & AudManager::GetSoundFXOnMask()) != 0,
        (MMSTATE.AudFlags & AudManager::GetCDMusicOnMask()) != 0);

    AUDMGRPTR->NotDsound3D = !(AudManager::GetDSound3DMask() & MMSTATE.AudFlags);

    if (AUDMGRPTR->EAXEnabled() && (MMSTATE.AudFlags & AudManager::GetUsingEAXMask()) &&
        (MMSTATE.AudFlags & AudManager::GetDSound3DMask()))
    {
        AUDMGRPTR->AlwaysEAX(true);
        AUDMGRPTR->SetEAXPreset(EAX_ENVIRONMENT_CITY, 0.114329f, 1.865f, 0.221129f);
    }

    MMSTATE.HasMidtownCD = AUDMGRPTR->CheckCDFile(const_cast<char*>("cdid.txt"));

    if (!MMSTATE.HasMidtownCD)
        AUDMGRPTR->SetCDPlayMode(1);

    AUDMGRPTR->AssignWaveVolume(0.0f);
    AUDMGRPTR->AssignCDVolume(0.0f);
    AUDMGRPTR->SetNumChannels(MMSTATE.AudNumChannels);
}

static mem::cmd_param PARAM_speedycops {"speedycops"};

void InitPatches()
{
    // Checked in GetPackedTexture, only necessary if agiRQ.TextureQuality <= 2
    // create_patch("aiVehicleOpponent::Init", "agiRQ.TextureQuality", 0x44DC2A, "\xEB\x06", 2);

    if (false) // Hack, replaces 16-bit handler with 32-bit handler
    {
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D419, "\x83\x79\x04\x04", 4);
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D439, "\x8D\x04\xBA", 3);
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D47E, "\x8B\x00\x89\x04\x93\x90\x90", 7);
    }

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
             0x4F5B6E, // ?SetupNotifications@StreamObj@@QAEHXZ
             0x4F5C15, // ?HandleNotifications@@YAKPAX@Z
             0x4F5E2C, // ?HandleNotifications@@YAKPAX@Z
             0x4F4CD6, // ??1StreamObj@@QAE@XZ
             0x4F52E2, // ?Play@StreamObj@@QAEHXZ
             0x4F533C, // ?SetPlayOneShotEvent@StreamObj@@QAEXPAD@Z
             0x4F5397, // ?SetStopEvent@StreamObj@@QAEXXZ
             0x4F53BA, // ?SetVolumeEvent@StreamObj@@QAEXM@Z
             0x4F53EA, // ?SetFrequencyEvent@StreamObj@@QAEXM@Z
             0x4F541A, // ?SetPanEvent@StreamObj@@QAEXM@Z
             0x4F54D3, // ?Play@StreamObj@@QAEHPAD@Z
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

    if (!PARAM_speedycops.get_or(false))
    {
        patch_jmp("aiGoalChase::Update", "No Speed Boost", 0x461004, jump_type::always);
        create_patch("aiGoalChase::CalcSpeed", "No Brake Boost", 0x462B0F, "\xEB\x2A", 2);

        // patch_jmp("aiGoalChase::Update", "No Steering boost", 0x460FB0, jump_type::always);
        // create_patch("aiGoalChase::CalcSpeed", "No Steering boost", 0x4627E6, "\xEB\x2A", 2);
        // create_patch("aiGoalChase::CalcSpeed", "No Steering boost", 0x4629F9, "\xEB\x3A", 2);
    }

    create_packed_patch<u8>(
        "MenuManager::ScanGlobalKeys", "Debug Text Alignment", 0x4B11DA + 1, 0x7); // CENTER | VCENTER | BORDER

    for (usize addr : {0x413BC0, 0x415D72, 0x417A90})
    {
        create_patch("LocPlayerName", "lea don't mov", addr, "\x8D", 1);
    }

    create_packed_patch<u32>("mmMultiCR::OppStealGold", "Icon Number", 0x41D93C + 6, 10);
    create_packed_patch<u32>("mmGame::Init", "Icon Number", 0x40F21E + 1, 11);

    patch_jmp("mmPlayer::Init", "Enable FreeCam when not in DevelopmentMode", 0x42A8E8, jump_type::never);

    create_packed_patch<u8, f32, u8, u8, u8>(
        "mmGameEdit::InitGameObjects", "Use a valid waypoint object", 0x412495, 0x68, 7.5f, 0x6A, 0x03, 0x90);

    create_packed_patch<const char*>(
        "mmGameEdit::InitGameObjects", "Use a valid waypoint object", 0x4124A7 + 1, "pt_check");

    create_packed_patch<f32>("Vehicle::Vehicle", "Camera Viewport X", 0x4A522E + 1, 34.0f / 640.0f);
    create_packed_patch<f32>("Vehicle::Vehicle", "Camera Viewport Y", 0x4A5229 + 1, 175.0f / 480.0f);
    create_packed_patch<f32>("Vehicle::Vehicle", "Camera Viewport W", 0x4A5224 + 1, 290.0f / 640.0f);
    create_packed_patch<f32>("Vehicle::Vehicle", "Camera Viewport H", 0x4A521F + 1, 216.0f / 480.0f);
    create_packed_patch<f32>("VehicleSelectBase::InitCarSelection", "Camera Viewport Offset", 0x49B043 + 3, 2.3f);

    {
        // sw[Tri/Quad/Poly] uses Q12.10 for casting vertices to integers

        // This currently does not change anything apart from the mask, which can actually fit 1 more bit (increasing the res limit to 4096x4096)
        const u32 whole_bits = 12; // TODO: Why not just use 22?

        for (usize addr : {
                 0x53697B, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     esi, 0Ah
                 0x536999, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     eax, 0Ah
                 0x5369BC, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     eax, 0Ah
                 0x5369DA, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     ecx, 0Ah
                 0x536A00, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     edx, 0Ah
                 0x536A20, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     edi, 0Ah

                 0x536B75, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536B93, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536BB9, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536BD7, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536C00, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536C21, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536C4D, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536C6E, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah

                 0x536F98, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    shr     ecx, 0Ah
                 0x536FB6, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    shr     ecx, 0Ah
                 0x537005, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    shr     eax, 0Ah
                 0x537022, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    shr     ecx, 0Ah
             })
        {
            create_packed_patch<u8>("Software Renderer", "Max Software Resolution", addr + 2,
                static_cast<u8>(22 - whole_bits)); // shr x, 10
        }

        for (usize addr : {
                 0x53697E, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     esi, 7FFh
                 0x53699C, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     eax, 7FFh
                 0x5369BF, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     eax, 7FFh
                 0x5369DD, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     ecx, 7FFh
                 0x536A03, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     edx, 7FFh
                 0x536A23, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     edi, 7FFh

                 0x536B78, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536B96, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536BBC, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536BDA, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536C03, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536C24, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536C50, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536C71, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh

                 0x536F9B, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    and     ecx, 7FFh
                 0x536FB9, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    and     ecx, 7FFh
                 0x537008, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    and     eax, 7FFh
                 0x537025, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    and     ecx, 7FFh
             })
        {
            switch (*(const u8*) (addr))
            {
                case 0x25: addr += 1; break;
                case 0x81: addr += 2; break;
            }

            create_packed_patch<u32>(
                "Software Renderer", "Max Software Resolution", addr, (1 << whole_bits) - 1); // and x, 7FF
        }

        create_packed_patch<f32>(
            "Software Renderer", "Max Software Resolution", 0x6212D4, -static_cast<f32>(3 << whole_bits)); // -12288.0
        create_packed_patch<f32>(
            "Software Renderer", "Max Software Resolution", 0x652258, static_cast<f32>(3 << whole_bits)); // 12288.0
        create_packed_patch<u8>("Software Renderer", "Max Software Resolution", 0x537450 + 2,
            static_cast<u8>(whole_bits)); // lea     ecx, [eax+0Ch]

        create_packed_patch<u16>(
            "TestResolution", "Max Software Resolution", 0x575E6C + 3, static_cast<u16>(1 << whole_bits));
        create_packed_patch<u16>(
            "TestResolution", "Max Software Resolution", 0x575E73 + 2, static_cast<u16>(1 << whole_bits));
    }

    create_patch("mmPlayer::Update", "DeclareMover Order", 0x42C096,
        "\x8D\xB3\x34\x20\x00\x00\x6A\x0B\x6A\x01\x56\xB9\x98\x86\x71\x00\xE8\x95\x84\x0A\x00\xF6\x83\x50\x20\x00\x00"
        "\x80\x74\x18\x8B\x8B\x40\x23\x00\x00\x6A\x0A\x83\xC1\x24\x6A\x01\x51\xB9\x98\x86\x71\x00\xE8\x74\x84\x0A\x00",
        0x36);

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

    patch_jmp("mmCar::VehNameRemap", "Work in all game modes", 0x474371, jump_type::never);
#endif
}
