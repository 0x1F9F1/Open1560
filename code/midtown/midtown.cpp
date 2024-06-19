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
#include "mmai/aiMap.h"
#include "mmaudio/manager.h"
#include "mmcamtour/gamerecord.h"
#include "mmcar/carsim.h"
#include "mmcity/loader.h"
#include "mmcityinfo/state.h"
#include "mmgame/game.h"
#include "mmgame/gameman.h"
#include "mmgame/interface.h"
#include "mmgame/player.h"
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

#ifdef ARTS_DEV_BUILD
#    include "toolmgr/toolmgr.h"
#endif

#include <mem/cmd_param-inl.h>

#define SDL_MAIN_NEEDED
#include <SDL.h>

#include "core/minwin.h"

#ifdef ARTS_ENABLE_OPENGL
#    include "agigl/glpipe.h"
#endif

#ifndef CI_BUILD_STRING
#    define CI_BUILD_STRING "Dev"
#endif

const char* VERSION_STRING = "Open1560: " __DATE__ " " __TIME__ " / " CI_BUILD_STRING;
const char* DEFAULT_CITY = "chicago";

// ?GameCloseCallback@@YAXXZ
ARTS_EXPORT /*static*/ void GameCloseCallback()
{
    MMSTATE.GameState = mmGameState::Menus;
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

struct ArchiveFileList
{
    char* Files[256] {};
    usize Count {};

    void Add(const char* path)
    {
        const char* basename = std::strrchr(path, '/');
        basename = basename ? (basename + 1) : path;
        const char* ext = std::strrchr(basename, '.');

        ArAssert(Count < ARTS_SIZE(Files), "Too many files");
        Files[Count++] = arts_strdup(ext ? path : arts_formatf<256>("%s%s", path, ".ar").get());
    }

    void Sort()
    {
        std::sort(Files, Files + Count, [](const char* lhs, const char* rhs) { return std::strcmp(lhs, rhs) < 0; });
    }
};

static void AutoLoadArchives(const char* path, ArchiveFileList& files)
{
    for (FileInfo* f = HFS.FirstEntry(path); f; f = HFS.NextEntry(f))
    {
        if (const char* ext = std::strrchr(f->Path, '.');
            ext && !arts_stricmp(ext, ".AR") && arts_strnicmp(f->Path, "TEST", 4))
        {
            files.Add(f->Path);
        }
    }

    files.Sort();
}

static void LoadArchiveList(const char* path, ArchiveFileList& files)
{
    Ptr<Stream> input {arts_fopen(path, "r")};

    if (input == nullptr)
    {
        Warningf("Failed to open archive list '%s'", path);

        return;
    }

    char buffer[ARTS_MAX_PATH];

    while (input->Gets(buffer, ARTS_SSIZE(buffer)))
    {
        if (char* end = std::strpbrk(buffer, "\r\n"))
            *end = '\0';

        if (buffer[0] != '\0' && buffer[0] != '#')
            files.Add(buffer);
    }
}

static mem::cmd_param PARAM_archives {"archives"};

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

    ArchiveFileList files;

    char* archives = arts_strdup(PARAM_archives.get_or("mods.txt"));
    char* context = nullptr;

    for (const char* path = arts_strtok(archives, "|", &context); path; path = arts_strtok(nullptr, "|", &context))
    {
        if (const char* ext = std::strrchr(path, '.'); ext && !arts_stricmp(ext, ".txt"))
        {
            LoadArchiveList(arts_formatf<ARTS_MAX_PATH>("%s/%s", base_path, path), files);
        }
        else
        {
            files.Add(path);
        }
    }

    arts_free(archives);

    if (files.Count == 0)
    {
        Displayf("Searching for archives");

        AutoLoadArchives(base_path, files);
    }

    Displayf("Loading %zu archives", files.Count);

    for (usize i = 0; i < files.Count; ++i)
    {
        char* path = files.Files[i];

        if (Ptr<Stream> stream {arts_fopen(arts_formatf<ARTS_MAX_PATH>("%s/%s", base_path, path), "r")})
        {
            Displayf("Adding '%s' to autosearch...", path);
            /*FileSystem::FS[...] = */ new VirtualFileSystem(as_owner std::move(stream));
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

class PreGameUpdate final : public asNode
{
public:
    PreGameUpdate()
    {
        SetName("PreGameUpdate");

        SetNodeFlag(NODE_FLAG_UPDATE_PAUSED);
    }

    void Update() override
    {
        mem::static_function::exec(FRAME_pre_update, false);
    }
};

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

            if (MMSTATE.GameState == mmGameState::Menus)
                Quitf("Can't start UI, this should never happen.");

            MessageBoxA(NULL, LOC_STR(MM_IDS_LOW_VRAM), APPTITLE, MB_ICONERROR);
            MMSTATE.GameState = mmGameState::Menus;
            return;
        }
    }

    {
        ARTS_MEM_STAT("ARTS Init");

        /*ARTSPTR = */ new asSimulation();
        Sim()->Init("."_xconst, argc, argv);

        if (!VFS)
        {
            LoadArchives(ar_path);
            agiPhysLib.Load("mtl/physics.db");
        }
    }

    if (!GBArgs['f'])
        Sim()->SetDebug(false);

    {
        ARTS_MEM_STAT("Audio manager");

        InitAudioManager();

        if (no_audio)
            AudMgr()->Disable(-1, -1);
    }

    {
        ARTS_MEM_STAT("GameInput");

        /*GameInputPtr = */ new mmInput();
        GameInput()->AttachToPipe();
        GameInput()->Init(static_cast<i32>(MMSTATE.InputType));
    }

    Ptr<mmGameManager> game_manager;
    Ptr<mmInterface> mm_interface;

    {
        mmLoader loader;

        if (page_override == -1)
        {
            if (MMSTATE.GameState != mmGameState::Menus)
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

            PAGER.Init(128, SynchronousMessageQueues ? IPC_QUEUE_MODE_SYNC : IPC_QUEUE_MODE_ASYNC);
        }

        loader.Reset();

        switch (MMSTATE.GameState)
        {
            case mmGameState::Menus: {
                loader.Init("title_screen"_xconst, 0.0f, 0.0f);

                if (GraphicsChange)
                {
                    loader.BeginTask(LOC_STRING(MM_IDS_LOADING_GRAPHICS));
                }
                else
                {
                    if (MMSTATE.HasMidtownCD)
                        AudMgr()->PlayCDTrack(3, true);

                    loader.BeginTask(LOC_STRING(MM_IDS_LOADING_INTERFACE));
                }

                mm_interface = arnew mmInterface();
                Sim()->AddChild(mm_interface.get());

                mm_interface->Reset();
                mm_interface->ShowMain(CycleState);

                CycleState = 1;
                break;
            }

            case mmGameState::Drive: {
                if (Rc<agiBitmap> image =
                        GenerateLoadScreenName() ? as_rc Pipe()->GetBitmap(LoadScreen, 1.0f, 1.0f, 0) : nullptr)
                {
                    loader.Init(LoadScreen, 366.0f / 640.0f, 414.0f / 480.0f);
                }
                else
                {
                    arts_strcpy(LoadScreen, "title_screen");
                    loader.Init(LoadScreen, 15.0f / 640.0f, 456.0f / 480.0f);
                }

                ARTS_MEM_STAT("GameManager");

                loader.BeginTask(LOC_STRING(MM_IDS_LOADING_RACE));

                AudMgr()->AssignWaveVolume(MMSTATE.WaveVolume);
                AudMgr()->AssignCDVolume(MMSTATE.CDVolume);

                if (MMSTATE.HasMidtownCD)
                    AudMgr()->PlayCDTrack(2, true);

                Sim()->AdoptChild(arnew PreGameUpdate());

                game_manager = /*mmGameManager::Instance = */ arnew mmGameManager();
                Sim()->AddChild(game_manager.get());

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

        Sim()->ResChange(Pipe()->GetWidth(), Pipe()->GetHeight());

        loader.EndTask();
    }

    MMSTATE.GameState = mmGameState::Running;
    MMSTATE.Shutdown = false;

    ALLOCATOR.SanityCheck();
    // TouchMemory(ALLOCATOR.GetHeapStart(), ALLOCATOR.GetHeapSize());

    module_init.End();
    Displayf("********* Load time = %f seconds; %dK allocated.", LoadTimer.Time(), ALLOCATOR.GetHeapUsed() >> 10);

    GameLoop(mm_interface.get(), game_manager.get(), replay_name);

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
            game_manager->SaveReplay("last.rpl"_xconst);
    }
#endif

    PAGER.Shutdown();
    AudMgr()->Disable(-1, -1);
    ALLOCATOR.SanityCheck();

    mm_interface = nullptr;
    game_manager = nullptr;

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
static mem::cmd_param PARAM_speedrun {"speedrun"};
static mem::cmd_param PARAM_multiheap {"multiheap"};

void ApplicationHelper(i32 argc, char** argv)
{
    dxiIcon = 111;

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

            argv[argc++] = "-path"_xconst;
            argv[argc++] = "."_xconst;
            argv[argc++] = "-archive"_xconst;
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

    if (PARAM_speedrun)
    {
        mem::cmd_param::set("smoothstep", "0");
        mem::cmd_param::set("maxfps", "60");
        mem::cmd_param::set("speedycops", "1");
        // mem::cmd_param::set("vsync", "0");
        mem::cmd_param::set("showfps", "1");
    }

    if (priority >= 0 && priority < 4)
    {
        static const char* const priority_names[4] = {"idle", "normal", "high", "REALTIME"};
        Warningf("Running with %s priority class.", priority_names[priority]);

        static const u32 priority_classes[4] {
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

    SDL_SetHint(SDL_HINT_TIMER_RESOLUTION, "1");
    SDL_SetHint(SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "1");
    SDL_SetHint(SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4, "1");
    SDL_SetHint(SDL_HINT_WINDOWS_DPI_AWARENESS, "permonitorv2");
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_SetHintWithPriority(SDL_HINT_WINDOWS_INTRESOURCE_ICON, arts_formatf<16>("%i", dxiIcon), SDL_HINT_OVERRIDE);

    if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
    {
        Errorf("Unable to initialize SDL Video: %s", SDL_GetError());
        return;
    }

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
            HierAllowPath = "players\0"_xconst;
            break;

        case 2: // Allow access to tuning data (fasttune)
            HierAllowPath = "players\0race\0tune\0"_xconst;
            break;
    }

    CURHEAP = &ALLOCATOR;
    SAFEHEAP.Init(PARAM_heapsize.get_or(ALLOCATOR.IsDebug() ? 80 : 64) << 20, PARAM_multiheap.get_or<i32>(2));

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

Owner<agiPipeline> CreatePipeline(i32 argc, char** argv)
{
    dxiRendererInfo_t& info = GetRendererInfo();

    if (bHaveIME)
    {
        dxiShutdown();

        if (MMSTATE.GameState != mmGameState::Menus)
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

    if (MMSTATE.GameState != mmGameState::Menus)
    {
        i32 res_choice = info.ResChoice;
        bRenderToSystem = RenderToSystemMemory;

        switch (info.Type)
        {
            case dxiRendererType::DX6_Soft: pipe = as_ptr swCreatePipeline(argc, argv); break;
            case dxiRendererType::DX6_GDI:
            case dxiRendererType::DX6: pipe = as_ptr d3dCreatePipeline(argc, argv); break;

#ifdef ARTS_ENABLE_OPENGL
            case dxiRendererType::OpenGL: pipe = as_ptr glCreatePipeline(argc, argv); break;
            case dxiRendererType::SDL2: pipe = as_ptr sdlCreatePipeline(argc, argv); break;
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

            pipe = as_ptr swCreatePipeline(argc, argv);
            pipe->SetRes(640, 480);
        }
    }
    else
    {
        bRenderToSystem = true;

        switch (bHaveIME ? dxiRendererType::DX6_Soft : info.Type)
        {
            case dxiRendererType::DX6_Soft: pipe = as_ptr swCreatePipeline(argc, argv); break;
            case dxiRendererType::DX6_GDI:
            case dxiRendererType::DX6: pipe = as_ptr d3dCreatePipeline(argc, argv); break;

#ifdef ARTS_ENABLE_OPENGL
            case dxiRendererType::OpenGL: pipe = as_ptr glCreatePipeline(argc, argv); break;
            case dxiRendererType::SDL2: pipe = as_ptr sdlCreatePipeline(argc, argv); break;
#endif
        }

        pipe->SetRes(640, 480);

        if (pipe->Validate())
        {
            MessageBoxA(NULL, LOC_STR(MM_IDS_REDETECT_VIDEO), APPTITLE, MB_ICONERROR);
            Quit();
        }
    }

    return as_owner pipe;
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
    {
        arts_free(file_data);
        CloseHandle(handle);
        return nullptr;
    }

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

extern "C" int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE PrevInstance, LPSTR lpCmdLine, int nShowCmd);

ARTS_EXPORT int WINAPI MidtownMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    return WinMain(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}

int main(int argc, char** argv)
{
    SDL_SetHint(SDL_HINT_TIMER_RESOLUTION, "1");

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
        // NOTE: Leaks file_argv and new_argv
        if (file_argc > 1)
        {
            int new_argc = argc + file_argc;
            char** new_argv = new char*[new_argc];

            new_argv[0] = argv[0];

            for (int i = 1; i < file_argc; ++i)
                new_argv[i] = file_argv[i];

            new_argv[file_argc] = const_cast<char*>("-dummycmd=0");

            for (int i = 1; i < argc; ++i)
                new_argv[file_argc + i] = argv[i];

            argc = new_argc;
            argv = new_argv;
        }
    }

    mem::cmd_param::init(argc, argv);

    if (PARAM_console.get_or(false))
        LogToConsole();

    if (SDL_Init(SDL_INIT_TIMER) != 0)
    {
        Errorf("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    Displayf("Processed %zu Init Functions", mem::static_function::exec(INIT_main, true));

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

static mem::cmd_param PARAM_help {"help", "Show list of available command line arguments"};

static void ShowUsage()
{
    mem::cmd_param* cmds[256];
    std::size_t count = mem::cmd_param::collect(cmds, ARTS_SIZE(cmds));

    std::size_t name_width = 0;
    std::size_t desc_width = 0;

    for (std::size_t i = 0; i < count; ++i)
    {
        mem::cmd_param& cmd = *cmds[i];

        name_width = (std::max)(name_width, std::strlen(cmd.name()));

        if (const char* desc = cmd.description())
            desc_width = (std::max)(desc_width, std::strlen(desc));
    }

    for (std::size_t i = 0; i < count; ++i)
    {
        mem::cmd_param& cmd = *cmds[i];

        const char* name = cmd.name();
        const char* desc = cmd.description();
        const char* def_value = cmd.default_value();

        Printf("-%-*s | %-*s | %s", static_cast<int>(name_width), name, static_cast<int>(desc_width), desc ? desc : "",
            def_value ? def_value : "");
    }
}

static mem::cmd_param PARAM_affinity {"affinity"};
static mem::cmd_param PARAM_sync {"sync"};

static void SetThreadSafety()
{
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
}

static mem::cmd_param PARAM_tool {"tool"};

void Application(i32 argc, char** argv)
{
    ARTS_EXCEPTION_BEGIN
    {
        SetThreadSafety();

        if (PARAM_help)
        {
            ShowUsage();
            return;
        }

        if (const char* tool = PARAM_tool.value())
        {
            ProcessTool(tool);
            return;
        }

        ApplicationHelper(argc, argv);
    }
    ARTS_EXCEPTION_END
    {
        // AIMAP.Dump()

        Abortf("Exception caught during init.");
    }
}

i32 GameFilter(_EXCEPTION_POINTERS* exception)
{
    return ExceptionFilter(exception);
}

void GameLoop([[maybe_unused]] mmInterface* mm_interface, [[maybe_unused]] mmGameManager* game_manager,
    [[maybe_unused]] char* replay_name)
{
    ARTS_EXCEPTION_BEGIN
    {
        // bool lock_alloc = MMSTATE.GameState == 1;
        // if (lock_alloc)
        //     ++ ALLOCATOR.LockCount;

        while (MMSTATE.GameState == mmGameState::Running)
        {
#ifdef ARTS_DEV_BUILD
            if (CycleTest && Sim()->GetElapsed() > CycleTime)
            {
                Sim()->SetElapsed(0.0f);

                if (CycleState == 1)
                {
                    if (CycleTest <= 1)
                    {
                        MMSTATE.GameMode = mmGameMode::Cruise;
                        MMSTATE.NetworkStatus = 0;
                    }
                    else
                    {
                        mm_interface->SetupArchiveTest(CycleTest);
                    }

                    mm_interface->BeDone();
                    MMSTATE.GameState = mmGameState::Drive;
                }
                else if (CycleState == 2)
                {
                    static i32 CycleCount = 0;

                    game_manager->BeDone();
                    MMSTATE.GameState = mmGameState::Menus;
                    Displayf(">>>>>>>>>>>>>>>>>>>CYCLETEST: CYCLE # %d", ++CycleCount);
                }
            }

            if (SampleStats == 1 && game_manager)
            {
                Vector4 pos;
                game_manager->Current->Player->Hud.GetPosHdg(pos);
                SystemStatsRecord->DoScan(pos);
            }
            else
#endif
            {
                bool sampling = !!(GetAsyncKeyState(VK_CAPITAL) & 0x8000);

                if (sampling && __VtResumeSampling)
                    __VtResumeSampling();

                if (GetAsyncKeyState(VK_SCROLL) & 0x8000)
                    ALLOCATOR.SanityCheck();

                if (EnablePaging)
                {
                    CACHE.Age();
                    TEXCACHE.Age();
                }

                Sim()->Simulate();

                if (sampling && __VtPauseSampling)
                    __VtPauseSampling();
            }
        }

        // if (lock_alloc)
        //     --ALLOCATOR.LockCount;
    }
    ARTS_EXCEPTION_END
    {
        Displayf("CRASH POSITION = (%f, %f, %f)", PlayerPos.x, PlayerPos.y, PlayerPos.z);

        AIMAP.Dump();

#ifdef ARTS_DEV_BUILD
        if (game_manager && !replay_name)
        {
            game_manager->SaveReplay("crash.rpl"_xconst);

            Abortf("Exception caught during simulate loop, saving replay.");
        }
#endif

        Abortf("Exception caught during simulate loop.");
    }
}

b32 GenerateLoadScreenName()
{
    switch (MMSTATE.GameMode)
    {
        case mmGameMode::Cruise: arts_sprintf(LoadScreen, "%sro", CityName); return true;
        case mmGameMode::Checkpoint: arts_sprintf(LoadScreen, "%sch%d", CityName, MMSTATE.EventId + 1); return true;
        case mmGameMode::CnR: arts_sprintf(LoadScreen, "%scr", CityName); return true;
        case mmGameMode::Circuit: arts_sprintf(LoadScreen, "%sci%d", CityName, MMSTATE.EventId + 1); return true;
        case mmGameMode::Blitz: arts_sprintf(LoadScreen, "%sbl%d", CityName, MMSTATE.EventId + 1); return true;
    }

    return false;
}

void InitAudioManager()
{
    /*AUDMGRPTR = */ new AudManager();

    AudMgr()->SteroOn = (MMSTATE.AudFlags & AudManager::GetStereoOnMask()) != 0;

    AudMgr()->Init(150, MMSTATE.AudFlags & (AudManager::GetDSound3DMask() | AudManager::GetUsingEAXMask()),
        MMSTATE.AudDeviceName, // FIXME: This is empty the first time
        (MMSTATE.AudFlags & AudManager::GetSoundFXOnMask()) != 0,
        (MMSTATE.AudFlags & AudManager::GetCDMusicOnMask()) != 0);

    AudMgr()->NotDsound3D = !(AudManager::GetDSound3DMask() & MMSTATE.AudFlags);

    if (AudMgr()->EAXEnabled() && (MMSTATE.AudFlags & AudManager::GetUsingEAXMask()) &&
        (MMSTATE.AudFlags & AudManager::GetDSound3DMask()))
    {
        AudMgr()->AlwaysEAX(true);
        AudMgr()->SetEAXPreset(EAX_ENVIRONMENT_CITY, 0.114329f, 1.865f, 0.221129f);
    }

    MMSTATE.HasMidtownCD = AudMgr()->CheckCDFile("cdid.txt"_xconst);

    if (!MMSTATE.HasMidtownCD)
        AudMgr()->SetCDPlayMode(1);

    AudMgr()->AssignWaveVolume(0.0f);
    AudMgr()->AssignCDVolume(0.0f);
    AudMgr()->SetNumChannels(MMSTATE.AudNumChannels);
}
