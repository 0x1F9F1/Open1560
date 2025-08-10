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

define_dummy_symbol(arts7_sim);

#include "sim.h"

#include "agi/error.h"
#include "agi/getdlp.h"
#include "agi/light.h"
#include "agi/mtllib.h"
#include "agi/physlib.h"
#include "agi/pipeline.h"
#include "agi/print.h"
#include "agi/rsys.h"
#include "agi/texlib.h"
#include "cullmgr.h"
#include "data7/args.h"
#include "data7/ipc.h"
#include "data7/memstat.h"
#include "data7/metadefine.h"
#include "data7/mmx.h"
#include "data7/str.h"
#include "data7/utimer.h"
#include "dyna7/dyna.h"
#include "dyna7/gfx.h"
#include "eventq7/keys.h"
#include "memory/allocator.h"
#include "midgets.h"
#include "midtown.h"
#include "pcwindis/dxinit.h"
#include "pgraph.h"
#include "stream/hfsystem.h"
#include "stream/vfsystem.h"

#include <crtdbg.h>
#include <cstdlib>

static bool PipelineInitialized = false;

i32 InitPipeline(const char* title, i32 argc, char** argv)
{
    if (PipelineInitialized)
        Quitf("Tried to InitPipeline twice.");

    Argc = argc;
    Argv = argv;

    auto pipe = CreatePipeline(argc, argv);
    agiPipeline::CurrentPipe = pipe.release();

    if (!agiPipeline::CurrentPipe)
        return AGI_ERROR_NO_DEVICE;

    PipelineInitialized = true;

    if (Pipe()->Validate())
        Quit("Couldn't start renderer");

    Pipe()->SetWindow(CreatePipelineAttachableWindow(title, 0, 0, Pipe()->GetWidth(), Pipe()->GetHeight(), nullptr));

    i32 error = Pipe()->BeginAllGfx();

    if (error == 0)
    {
        agiPrintInit();

        Pipe()->ClearAll(0);
    }

    return error;
}

static agiLightParameters SunParams {};
static agiLight* SunLight = nullptr;

void ShutdownPipeline()
{
    if (!PipelineInitialized)
    {
        Errorf("ShutdownPipeline w/out InitPipeline.");
        return;
    }

    PipelineInitialized = false;

    if (SunLight)
    {
        SunLight->Release();
        SunLight = nullptr;
    }

    agiPrintShutdown();

    Pipe()->EndAllGfx();

    delete agiPipeline::CurrentPipe;
    agiPipeline::CurrentPipe = nullptr;

    DestroyPipelineAttachableWindow();

    if (eqReplay::Recording)
        eqReplay::ShutdownRecord();
}

#ifdef ARTS_DEV_BUILD
static void TogglePipelineWindow()
{
    agiPrintShutdown();
    Pipe()->EndAllGfx();
    DestroyPipelineAttachableWindow();
    dxiShutdown();

    dxiFlags ^= DXI_FLAG_FULL_SCREEN;

    dxiInit(APPTITLE, 0, nullptr);
    Pipe()->SetWindow(CreatePipelineAttachableWindow(APPTITLE, 0, 0, Pipe()->GetWidth(), Pipe()->GetHeight(), nullptr));

    i32 error = Pipe()->BeginAllGfx();

    if (error == 0)
    {
        agiPrintInit();

        Pipe()->ClearAll(0);
    }
}
#endif

static void QuietPrinter(i32 level, const char* format, std::va_list args)
{
    if (level >= 3)
        DefaultPrinter(level, format, args);
}

asSimulation::asSimulation()
    : keys_queue_(0xB, EQ_EVENT_MASK(eqEventType::Keyboard) | EQ_EVENT_MASK(eqEventType::Activate), 32)
    , widgets_queue_(0xB, EQ_EVENT_MASK(eqEventType::Keyboard), 32)
    , draw_mode_(agiDrawTextured)
{
    ArAssert(!ARTSPTR, "Already have simulation");

    frame_depth_ = 0;
    frame_stack_[0] = &root_frame_;
    current_matrix_ = &root_frame_.World;

    SetName("Root");
    RealTime(0.0f);

#ifdef ARTS_DEV_BUILD
    {
        ARTS_MEM_STAT("asSimulate::DeclareVector buffers");

        vector_capacity_ = 256;
        vector_count_ = 0;
        vector_starts_ = arnewa Vector3[vector_capacity_] {};
        vector_ends_ = arnewa Vector3[vector_capacity_] {};
        vector_colors_ = arnewa Vector3[vector_capacity_] {};
    }
#endif

    ARTSPTR = this;

#ifdef ARTS_DEV_BUILD
    MIDGETSPTR = new asMidgets();
#endif
}

asSimulation::~asSimulation()
{
    ARTSPTR = nullptr;

    if (MIDGETSPTR)
    {
        delete MIDGETSPTR;
        MIDGETSPTR = nullptr;
    }

    if (CULLMGR)
    {
        delete CULLMGR;
        CULLMGR = nullptr;
    }

    agiMtlLib.Kill();
    agiTexLib.Kill();
    agiPhysLib.Kill();

    if (VFS)
    {
        delete VFS;
        VFS = nullptr;
    }
}

void asSimulation::Init(aconst char* proj_path, i32 argc, char** argv)
{
    seconds_ = 4321.0f;

    ConstString proj_path_env = arts_getenv("ARTS_PROJ");

    if (proj_path_env)
        proj_path = proj_path_env.get();

    const char* vfs_path = nullptr;
    [[maybe_unused]] i32 dbg_flags = _CRTDBG_ALLOC_MEM_DF;

    GBArgs.ParseArgs(argc, const_cast<const char**>(argv));

#define ARG(NAME) !std::strcmp(arg, NAME)

    for (int i = 1; i < argc;)
    {
        // FIXME: Extra args may read out of bounds
        char* arg = argv[i++];

        if (ARG("-ui"))
        {
            show_ui_ = true;
        }
        else if (ARG("-path"))
        {
            proj_path = argv[i++];
        }
        else if (ARG("-fsverbose"))
        {
            fsVerbose = true;
        }
        else if (ARG("-logopen"))
        {
            LogOpenOn = true;
        }
        else if (ARG("-quiet"))
        {
            Errorf("Message output disabled.");
            Quiet();
        }
        else if (ARG("-record"))
        {
            eqReplay::InitRecord(argv[i++]);
        }
        else if (ARG("-playback"))
        {
            eqReplay::InitPlayback(argv[i++]);
        }
        else if (ARG("-archive"))
        {
            vfs_path = argv[i++];
        }
        if (ARG("-simdbg"))
        {
            DebugMemory |= ARTS_DEBUG_SIM;
        }
        else if (ARG("-updatememdbg"))
        {
            DebugMemory |= ARTS_DEBUG_UPDATEMEM;
        }
        else if (ARG("-updatedbg"))
        {
            DebugMemory |= ARTS_DEBUG_UPDATE;
        }
        else if (ARG("-heapdbg"))
        {
            dbg_flags |= _CRTDBG_CHECK_ALWAYS_DF;
        }
        else if (ARG("-leakdbg"))
        {
            dbg_flags |= _CRTDBG_LEAK_CHECK_DF;
        }
    }

#undef ARG

    _CrtSetDbgFlag(dbg_flags);

    if (fsVerbose)
        Displayf("Using '%s' for project path.", proj_path);

    char exe_path[ARTS_MAX_PATH];

    if (!vfs_path)
    {
        arts_strcpy(exe_path, argv[0]);

        if (char* ext = std::strrchr(exe_path, '.')) // Replace file extension with .ar
        {
            ++ext;
            arts_strcpy(ext, &exe_path[ARTS_SIZE(exe_path)] - ext, "AR");
            vfs_path = exe_path;
        }
    }

    if (vfs_path)
    {
        Ptr<Stream> vfs_stream {arts_fopen(vfs_path, "r")};

        if (fsVerbose)
        {
            Displayf("VFS '%s' %s found.", vfs_path, vfs_stream ? "" : "NOT");
        }

        if (vfs_stream)
        {
            DevelopmentMode = false;
            ARTS_MEM_STAT("VFS");
            VFS = new VirtualFileSystem(as_owner std::move(vfs_stream));
        }
    }

    arts_strcpy(ProjPath, proj_path);
    HierPrefix = ProjPath;

    arts_sprintf(ExecPath, "%s\\bin\\", proj_path);

    CheckLibraries();

    agiMtlLib.Init(0);
    agiTexLib.Init(0);
    agiPhysLib.Load("mtl/physics.db");

    if (!CULLMGR)
    {
        CULLMGR = new asCullManager(1024, 128);
    }

    SunParams.SetPosition({1000.0f, 1000.0f, 1000.0f});
    SunLight = as_raw Pipe()->CreateLight();

    if (SunLight)
        SunLight->Init(SunParams);
}

void asSimulation::BeginOverSample(i32 samples)
{
    seconds_ /= samples;
    inv_seconds_ *= samples;
}

void asSimulation::EndOverSample(i32 samples)
{
    seconds_ *= samples;
    inv_seconds_ /= samples;
}

void asSimulation::FixedFrame(f32 frame_rate, i32 frame_samples)
{
    ResetClock();
    sample_mode_ = 1;
    frame_samples_ = frame_samples;
    fixed_fps_ = frame_rate;
    sample_step_ = 1.0f / (frame_samples * frame_rate);
}

void asSimulation::FrameLock(i32 lock, i32)
{
    frame_lock_ = lock;
}

void asSimulation::Pause()
{
    eqEventQ events {-1, -1, 32};
    eqEvent event;

    bool done = false;

    while (!done)
    {
        eqEventHandler::SuperQ->Update(0);

        while (events.Pop(&event))
        {
            if ((event.Type == eqEventType::Keyboard) && (event.Key.Modifiers & EQ_KMOD_DOWN))
            {
                frame_step_ = 0;
                done = true;
            }
        }

        Widgets();
    }

    frame_timer_.Reset();

    while (keys_queue_.Pop(&event))
        ;
}

void asSimulation::FirstUpdate()
{
    ResetClock();
    frame_timer_.Reset();
    first_frame_ = true;
    seconds_ = 0.0f;
}

void asSimulation::Quiet()
{
    Printer = QuietPrinter;
}

void asSimulation::RealTime(f32 fps)
{
    ResetClock();
    fixed_fps_ = 30.0;
    sample_mode_ = 0;
    frame_samples_ = 1;
    sample_step_ = fps ? (1.0f / fps) : 0.0f;
}

void asSimulation::Reset()
{
    should_reset_ = true;
}

static mem::cmd_param PARAM_smoothstep {"smoothstep"};
static mem::cmd_param PARAM_maxfps {"maxfps"};

void asSimulation::ResetClock()
{
    inv_seconds_ = 1.0f;
    elapsed_ = 0.0f;
    full_updates_ = 0;
    updates_ = 0;
    frame_count_ = 0;
    bench_elapsed_ = 0.0f;

    curr_stats_.Reset();
    prev_stats_.Reset();

    smooth_ = PARAM_smoothstep.get_or(true);
    target_delta_ = 1.0f / 30.0f;
    delta_drift_ = 0.0f;
    prev_utimer_ = 0;
    toggle_pause_ = false;
    time_warp_ = 1.0f;

    f32 max_fps = PARAM_maxfps.get_or(300.0f);
    max_fps_delta_ = (max_fps > 0.0f) ? (1.0f / max_fps) : 0.0f;
}

void asSimulation::Simulate()
{
    if (eqReplay::Playback)
        eqReplay::DoPlayback();

    if (should_reset_)
    {
        asNode::Reset();
        seconds_ = 4321.0f;
        should_reset_ = false;
    }

    if (DebugMemory & ARTS_DEBUG_SIM)
    {
        ALLOCATOR.SanityCheck();

        if (const char* error = VerifyTree())
            Quitf("Node Tree Corrupt: %s", error);
    }

    Device();
    Widgets();
    Update();

    CullMgr()->Update();

    if (eqReplay::Recording)
        eqReplay::DoRecord();
}

void asSimulation::Update()
{
    if (seconds_ == 4321.0f)
        FirstUpdate();
    else if (seconds_ == 1234.0f)
        Quitf("ARTS.Init() not called");

    if (toggle_pause_)
    {
        paused_ ^= true;
        toggle_pause_ = false;
    }

#ifdef ARTS_DEV_BUILD
    if (!paused_ || frame_step_)
        vector_count_ = 0;
#endif

    Timer timer;

    f32 delta = frame_timer_.Time();

    if (max_fps_delta_ && delta < max_fps_delta_)
    {
        delta = frame_timer_.WaitUntil(max_fps_delta_);
    }

    frame_timer_.Reset();

    prev_utimer_ = adjust_utimer(delta, prev_utimer_);

    actual_elapsed_ += delta;
    bench_elapsed_ += delta;

    if (bench_elapsed_ > 1.0f)
        Benchmark();

    i32 num_samples = 1;
    ++frame_count_;

    delta = std::clamp(delta, min_frame_delta_, max_frame_delta_);

    if (smooth_)
        SmoothDelta(delta);

    delta *= time_warp_;

    if (!eqReplay::Playback)
    {
        if (frame_step_)
        {
            seconds_ = sample_step_ ? sample_step_ : 0.05f;
        }
        else if (sample_mode_)
        {
            num_samples = frame_samples_;
            seconds_ = sample_step_;
        }
        else
        {
            if (sample_step_ && delta >= sample_step_)
            {
                delta = std::min(delta, max_samples_ * sample_step_);
                num_samples = static_cast<i32>(delta / sample_step_) + 1;
                seconds_ = delta / num_samples;
            }
            else
            {
                seconds_ = delta;
            }
        }
    }

    full_update_ = false;
    ++full_updates_;
    inv_seconds_ = 1.0f / seconds_;

    for (i32 sample = 1; sample <= num_samples; ++sample)
    {
        ++updates_;

        if (sample == num_samples)
            full_update_ = true;

        elapsed_ += seconds_;

        if (!paused_ || frame_step_)
            asNode::Update();
        else
            UpdatePaused(this);

        prev_stats_.Current(&curr_stats_);

        first_frame_ = 0;
    }

#ifdef ARTS_DEV_BUILD
    if (physics_bank_open_)
    {
        if (SunLight)
        {
            SunLight->Init(SunParams);
            SunLight->Update();
        }

        CullMgr()->DeclareCullable(this);
    }
#endif

    curr_stats_.UpdateTime += timer.Time();

#ifdef ARTS_DEV_BUILD
    if (TimingCount && !--TimingCount)
    {
        Ptr<Stream> report {arts_fopen("perf.rpt", "w")};

        PerfReport(report.get(), 0);
    }
#endif
}

void asSimulation::UpdatePaused(asNode* node)
{
    for (asNode* n = node->GetChildNode(); n; n = n->GetNextNode())
    {
        if (n->IsNodeActive())
        {
            if (n->TestNodeFlag(NODE_FLAG_UPDATE_PAUSED))
            {
                n->Update();
            }
            else
            {
                n->UpdatePaused();
                UpdatePaused(n);
            }
        }
    }
}

#ifdef ARTS_DEV_BUILD
void asSimulation::Cull()
{
    if (vector_count_ == 0)
        return;

    Matrix34 world {IDENTITY};
    DrawBegin(world);

    for (i32 i = 0; i < vector_count_; ++i)
    {
        DrawColor(vector_colors_[i]);
        DrawLine(vector_starts_[i], vector_ends_[i]);
    }

    DrawEnd();
}

void asSimulation::DeclareVector(const Vector3* start, const Vector3* end, const Vector3* color)
{
    if (full_update_ && vector_count_ < vector_capacity_)
    {
        vector_starts_[vector_count_] = *start;
        vector_ends_[vector_count_] = *end;
        vector_colors_[vector_count_] = *color;

        ++vector_count_;
    }
}
#endif

void asSimulation::Device()
{
    Timer timer;

    if (!Pipe()->HaveGfxStarted())
        Pipe()->BeginAllGfx();

    eqEventHandler::SuperQ->Update(0);

    if (frame_step_)
        frame_step_ = false;

    for (eqEvent event; keys_queue_.Pop(&event);)
    {
        if ((event.Type != eqEventType::Keyboard) || !(event.Key.Modifiers & EQ_KMOD_DOWN))
            continue;

        i32 vkey = event.Key.Key;

        if (vkey == EQ_VK_ESCAPE)
            in_escape_ = true;

        i32 mods = event.Key.Modifiers & (EQ_KMOD_SHIFT | EQ_KMOD_CTRL | EQ_KMOD_ALT);

        if (!(mods & EQ_KMOD_SHIFT))
            continue;

        if (vkey == EQ_VK_PAUSE)
            Pause();

        if (vkey == EQ_VK_V && (mods & EQ_KMOD_CTRL) && CullMgr())
            CullMgr()->ToggleVersionString();

#ifdef ARTS_DEV_BUILD
        if (no_debug_)
        {
            switch (vkey)
            {
                case EQ_VK_F1: {
                    if (CullMgr()->CurrentPage())
                        CullMgr()->HidePage();
                    else
                        CullMgr()->NextPage();

                    break;
                }

                case EQ_VK_F4: {
                    if (mods == (EQ_KMOD_SHIFT | EQ_KMOD_CTRL | EQ_KMOD_ALT))
                        no_debug_ = false;

                    break;
                }

                case EQ_VK_F5: {
                    dxiScreenShot(nullptr);

                    break;
                }

                case EQ_VK_F6: {
                    switch (agiCurState.GetTexFilter())
                    {
                        case agiTexFilter::Point: agiCurState.SetTexFilter(agiTexFilter::Bilinear); break;
                        case agiTexFilter::Bilinear: agiCurState.SetTexFilter(agiTexFilter::Trilinear); break;
                        case agiTexFilter::Trilinear: agiCurState.SetTexFilter(agiTexFilter::Point); break;
                    }

                    break;
                }

                case EQ_VK_F9: {
                    if (HaveKNI)
                    {
                        UseKNI ^= true;

                        Displayf("Pentium III insns %s", UseKNI ? "ENABLED" : "DISABLED");
                    }

                    break;
                }
            }
        }
        else if (vkey == EQ_VK_F1)
        {
            if (mods & EQ_KMOD_CTRL)
                CullMgr()->PrevPage();
            else
                CullMgr()->NextPage();
        }
        else if ((vkey >= EQ_VK_F1) && (vkey <= EQ_VK_F12) && (mods & EQ_KMOD_CTRL))
        {
            PGRAPH->Key(vkey);
        }
        else
        {
            switch (vkey)
            {
                case EQ_VK_F2: {
                    physics_bank_open_ = false;
                    draw_mode_ = (draw_mode_ == agiDrawDepth) ? agiDrawTextured : agiDrawDepth;

                    break;
                }

                case EQ_VK_F3: {
                    physics_bank_open_ = false;

                    if (draw_mode_ == agiDrawWireframe)
                        draw_mode_ = agiDrawSolid;
                    else if (draw_mode_ == agiDrawSolid)
                        draw_mode_ = agiDrawTextured;
                    else
                        draw_mode_ = agiDrawWireframe;

                    break;
                }

                case EQ_VK_F4: {
                    physics_bank_open_ ^= true;
                    draw_mode_ = physics_bank_open_ ? agiDrawSolid : agiDrawTextured;

                    break;
                }

                case EQ_VK_F5: {
                    dxiScreenShot(nullptr);

                    break;
                }

                case EQ_VK_F6: {
                    agiCurState.SetDither(!agiCurState.GetDither());

                    break;
                }

                case EQ_VK_F7: {
                    switch (agiCurState.GetTexFilter())
                    {
                        case agiTexFilter::Point: agiCurState.SetTexFilter(agiTexFilter::Bilinear); break;
                        case agiTexFilter::Bilinear: agiCurState.SetTexFilter(agiTexFilter::Trilinear); break;
                        case agiTexFilter::Trilinear: agiCurState.SetTexFilter(agiTexFilter::Point); break;
                    }

                    break;
                }

                case EQ_VK_F8: {
                    if (mods & EQ_KMOD_SHIFT)
                    {
                        agiEnableZBuffer ^= true;
                        Displayf("Z buffer %s", agiEnableZBuffer ? "ENABLED" : "DISABLED");
                    }

                    break;
                }

                case EQ_VK_F9: {
                    if (HaveKNI)
                    {
                        UseKNI ^= true;
                        Displayf("Pentium III insns %s", UseKNI ? "ENABLED" : "DISABLED");
                    }

                    break;
                }

                case EQ_VK_F11: {
                    SetPause(false);

                    break;
                }

                case EQ_VK_F12: {
                    if (IsPaused())
                        frame_step_ = true;
                    else
                        SetPause(true);

                    break;
                }

                case EQ_VK_RETURN: {
                    if (mods == (EQ_KMOD_SHIFT | EQ_KMOD_CTRL | EQ_KMOD_ALT))
                        TogglePipelineWindow();

                    break;
                }
            }
        }
#endif
    }

    curr_stats_.DeviceTime += timer.Time();
}

void asSimulation::Widgets()
{
    Timer timer;

#ifdef ARTS_DEV_BUILD
    for (eqEvent event; widgets_queue_.Pop(&event);)
    {
        if ((event.Type == eqEventType::Keyboard) && (event.Key.Modifiers == (EQ_KMOD_DOWN | EQ_KMOD_CTRL)) &&
            (event.Key.Key == EQ_VK_M) && !no_debug_)
        {
            if (MIDGETSPTR->IsOpen() && MIDGETSPTR->GetVisibleLines() == 5)
            {
                MIDGETSPTR->SetVisibleLines(21);
            }
            else
            {
                MIDGETSPTR->SetVisibleLines(5);
                MIDGETSPTR->Toggle();
            }
        }
    }
#endif

    curr_stats_.WidgetsTime += timer.Time();
}

void asSimulation::SmoothDelta(f32& delta)
{
    // Ignore very large deltas
    if (delta >= 0.5f)
        return;

    f32 raw_delta = delta;

    delta += delta_drift_ * 0.2f;
    delta += (target_delta_ - delta) * 0.8f;
    delta = std::clamp(delta, raw_delta * 0.2f, raw_delta * 5.0f);

    target_delta_ += (delta - target_delta_) * 0.2f;
    delta_drift_ += raw_delta - delta;
}

static ARTS_NOINLINE bool IsValidPointer(void* address, usize size, bool access)
{
    volatile char* volatile addr = static_cast<volatile char*>(address);

    if (addr == nullptr)
        return false;

    __try
    {
        for (usize i = 0; i < size; ++i)
        {
            volatile char v = addr[i];

            if (access)
            {
                addr[i] = v;
            }
        }
    }
    __except (1)
    {
        return false;
    }

    return true;
}

const char* asNode::VerifyTree()
{
    if (!IsValidPointer(this, sizeof(*this), true))
        return "Bad 'this'";

    if (!IsValidPointer(*reinterpret_cast<void**>(this), sizeof(void* [8]), false))
        return "Bad virtual table";

    if (parent_node_ && !IsValidPointer(parent_node_, sizeof(*this), true))
        return "Bad parent";

    const char* msg = nullptr;

    i32 i = 1;
    for (asNode* n = child_node_; n; n = n->next_node_, ++i)
    {
        msg = n->VerifyTree();

        if (msg)
        {
            Errorf("Kid %d(%p) of type %s name %s: %s", i, n, GetNodeType(), node_name_.get(), msg);
            break;
        }
    }

    return msg;
}

#ifdef ARTS_DEV_BUILD
void asSimulation::OpenPhysicsBank()
{
    physics_bank_open_ ^= true;
}

void asSimulation::AddWidgets(Bank* bank)
{
    asNode::AddWidgets(bank);

    bank->AddButton("Reset Simulation", [this] { Reset(); });
    bank->AddSlider("Time Warp", &time_warp_, 0.1f, 10.0f, 0.1f);

    bank->PushSection("Physics Draw Mode", false);
    bank->AddToggle("Matrix", &DynaDrawMode, DYNA_DRAW_MATRIX);
    bank->AddToggle("Cull Spheres", &DynaDrawMode, DYNA_DRAW_CULL_SPHERES);
    bank->AddToggle("Geometry", &DynaDrawMode, DYNA_DRAW_GEOMETRY);
    bank->AddToggle("Status", &DynaDrawMode, DYNA_DRAW_STATUS);
    bank->AddToggle("Bounds", &DynaDrawMode, DYNA_DRAW_BOUNDS);
    bank->AddToggle("Tables", &DynaDrawMode, DYNA_DRAW_TABLES);
    bank->AddToggle("Intersect", &DynaDrawMode, DYNA_DRAW_INTERSECT);
    bank->AddToggle("Applied Forces", &DynaDrawMode, DYNA_DRAW_APPLIED_FORCES);
    bank->AddToggle("Applied Pushes", &DynaDrawMode, DYNA_DRAW_APPLIED_PUSHES);
    bank->AddToggle("Result Forces", &DynaDrawMode, DYNA_DRAW_RESULT_FORCES);
    bank->AddToggle("Volume Samples", &DynaDrawMode, DYNA_DRAW_VOLUME_SAMPLES);
    bank->AddToggle("Fluid Samples", &DynaDrawMode, DYNA_DRAW_FLUID_SAMPLES);
    bank->AddToggle("Springs", &DynaDrawMode, DYNA_DRAW_SPRINGS);
    bank->PopSection();

    bank->PushSection("Memory Debug", false);
    bank->AddToggle("Sim", &DebugMemory, ARTS_DEBUG_SIM);
    bank->AddToggle("Update", &DebugMemory, ARTS_DEBUG_UPDATE);
    bank->AddToggle("Update Mem", &DebugMemory, ARTS_DEBUG_UPDATEMEM);
    bank->PopSection();

    bank->PushSection("Node Timing", false);
    bank->AddSlider("Current", &TimingCount, 0, INT_MAX, 0);

    static i32 additional_timing = 100;

    bank->AddSlider("Additional", &additional_timing, 1, 1000, 1);
    bank->AddButton("Begin", [] { TimingCount += additional_timing; });
    bank->AddButton("Reset", [this] {
        TimingCount = 0;
        ResetTime();
    });

    bank->PopSection();
}

void InitBank(i32 /*argc*/, char** /*argv*/)
{}
#endif

META_DEFINE_CHILD("asSimulation", asSimulation, asNode)
{}
