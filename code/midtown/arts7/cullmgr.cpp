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

define_dummy_symbol(arts7_cullmgr);

#include "cullmgr.h"

#include "camera.h"
#include "midgets.h"
#include "pgraph.h"
#include "sim.h"

#include "agi/bitmap.h"
#include "agi/pipeline.h"
#include "agi/print.h"
#include "agi/rsys.h"
#include "data7/metadefine.h"
#include "data7/utimer.h"
#include "dyna7/gfx.h"
#include "eventq7/active.h"
#include "memory/allocator.h"
#include "memory/stack.h"
#include "midtown.h"
#include "vector7/randmath.h"

asCullManager* CULLMGR = nullptr;

static f32 CurrentFrameTime = 0.0f;
static f32 UpdateTime2D = 0.0f;
static f32 UpdateTime3D = 0.0f;
static f32 asCullManager_UpdateTime = 0.0f;
static f32 asCullManager_UpdateTime3D = 0.0f;
static i32 StatsTextOffset = 0;

#ifdef ARTS_DEV_BUILD

static void PrintMessages()
{
    for (usize i = 0; i < ARTS_SIZE(MessageFifo); ++i)
    {
        Statsf("%s", MessageFifo[(i + MessageFirst) % ARTS_SIZE(MessageFifo)]);
    }
}

static void PrintMemoryUsage()
{
    asMemStats stats;
    asMemSource sources[1024];
    usize num_sources = ARTS_SIZE(sources);
    CURHEAP->GetStats(&stats, sources, &num_sources);

    Statsf("%6zu KB Max Size", CURHEAP->GetHeapSize() >> 10);
    Statsf("%6zu KB Current Size", CURHEAP->GetHeapUsed() >> 10);

    Statsf("%6zu KB Used", stats.cbUsed >> 10);
    Statsf("%6zu KB Free", stats.cbFree >> 10);
    Statsf("%6zu KB Waste", stats.cbOverhead >> 10);

    Statsf("%6zu Nodes (%zu Used/%zu Free)", stats.nTotalBlocks, stats.nUsedBlocks, stats.nFreeBlocks);

    if (num_sources)
    {
        Statsf("Nodes, Used (KB), Waste (KB) | Source");

        for (usize i = 0; i < std::min<usize>(num_sources, 64); ++i)
        {
            asMemSource source = sources[i];

            char symbol[128];
            LookupAddress(symbol, ARTS_SIZE(symbol), source.uSource);

            Statsf("%5zu, %9zu, %10zu | %s", source.nBlocks, source.cbUsed >> 10, source.cbOverhead >> 10, symbol);
        }
    }
}

static void PrintRenderPerf()
{
    agiTraverseTimer -= agiClipTimer;

    ulong api_total = agiBeginScene + agiEndScene + agiBeginFrame + agiEndFrame + agiCopyBitmap + agiClearViewport +
        agiStateChanges + agiRasterization;

    ulong geom_total = agiTransformTimer + agiTraverseTimer + agiFirstPass + agiSecondPass + agiClipTimer +
        agiInvertTimer + agiLightTimer;

    Statsf("BeginFrame:    %5.2f", agiBeginFrame * ut2float);
    Statsf("BeginScene:    %5.2f", agiBeginScene * ut2float);
    Statsf("ClearViewport: %5.2f", agiClearViewport * ut2float);
    Statsf("Rasterization: %5.2f", agiRasterization * ut2float);
    Statsf("State Changes: %5.2f", agiStateChanges * ut2float);
    Statsf("EndScene:      %5.2f", agiEndScene * ut2float);
    Statsf("CopyBitmap:    %5.2f (%d calls/%d pixels)", agiCopyBitmap * ut2float, agiBitmapCount, agiBitmapPixels);
    Statsf("EndFrame:      %5.2f", agiEndFrame * ut2float);
    Statsf("API Total:     %5.2f", api_total * ut2float);

    Statsf("Transform:    %5.2f", agiTransformTimer * ut2float);
    Statsf("Lighting:     %5.2f", agiLightTimer * ut2float);
    Statsf("Traverse:     %5.2f", agiTraverseTimer * ut2float);
    Statsf("First Pass:   %5.2f", agiFirstPass * ut2float);
    Statsf("Second Pass:  %5.2f", agiSecondPass * ut2float);
    Statsf("Clip:         %5.2f", agiClipTimer * ut2float);
    Statsf("W Invert:     %5.2f", agiInvertTimer * ut2float);
    Statsf("Geom. Total:  %5.2f", geom_total * ut2float);

    Statsf("3D Total:  %5.2f", asCullManager_UpdateTime3D * 1000.0f);
    Statsf("2D Total:  %5.2f", (asCullManager_UpdateTime - asCullManager_UpdateTime3D) * 1000.0f);
    Statsf("Overhead:  %5.2f", (asCullManager_UpdateTime * 1000.0f) - ((api_total + geom_total) * ut2float));

    agiClearViewport = 0;
    agiEndFrame = 0;
    agiCopyBitmap = 0;
    agiEndScene = 0;
    agiStateChanges = 0;
    agiRasterization = 0;
    agiBeginScene = 0;
    agiBeginFrame = 0;
    agiInvertTimer = 0;
    agiClipTimer = 0;
    agiLightTimer = 0;
    agiTraverseTimer = 0;
    agiTransformTimer = 0;
    agiSecondPass = 0;
    agiFirstPass = 0;
    agiBitmapPixels = 0;
    agiBitmapCount = 0;
}
#endif

#ifdef ARTS_DEV_BUILD
static mem::cmd_param PARAM_showfps {"showfps"};
#endif

asCullManager::asCullManager(i32 max_cullables, i32 max_cullables_2D)
    : max_cullables_(max_cullables)
    , max_cullables_2D_(max_cullables_2D)
    , cullables_(arnewa asCullable * [max_cullables] {})
    , cullables_2D_(arnewa asCullable * [max_cullables_2D] {})
    , transforms_(arnewa Matrix34 * [max_cullables] {})
{
    Reset(); // TODO: Is this call unncessary?

    SetNodeFlag(NODE_FLAG_UPDATE_PAUSED);

#ifdef ARTS_DEV_BUILD
    AddPage([this] { PrintMiniStats(); });
    AddPage([this] { PrintStats(); });
    AddPage([] { PGRAPH->Cull(); });
    AddPage(PrintRenderPerf);
    AddPage(PrintMessages);
    AddPage(PrintMemoryUsage);

    ArAssert(!PGRAPH, "Already have a PGRAPH");
    PGRAPH = new asPerfGraph();
    PGRAPH->AddComponent("3D", &UpdateTime3D, ColGreen);
    PGRAPH->AddComponent("2D", &UpdateTime2D, ColBlue);

    current_page_ = PARAM_showfps.get_or(false) ? 1 : 0;
#endif
}

asCullManager::~asCullManager()
{
    delete PGRAPH;

    PGRAPH = nullptr;
}

void asCullManager::DeclareCamera(asCamera* camera)
{
    LockGuard lock(mutex_);

    if (num_cameras_ < ARTS_SSIZE(cameras_))
    {
        cameras_[num_cameras_++] = camera;
    }
    else
    {
        Errorf("Too many cameras declared, somthing's rotten in Denmark.");
    }
}

void asCullManager::DeclareCullable(asCullable* cullable)
{
    ArAssert(cullable, "Cullable is null");

    LockGuard lock(mutex_);

    if (Sim()->IsFullUpdate())
    {
        if (num_cullables_ >= max_cullables_)
        {
            Warningf("Increase CULLMGR::MaxCullables!. MaxCullables=%d", max_cullables_);
        }
        else
        {
            cullables_[num_cullables_] = cullable;
            transforms_[num_cullables_] = Sim()->GetCurrentMatrix();
            ++num_cullables_;
        }
    }
}

void asCullManager::DeclareCullable2D(asCullable* cullable)
{
    ArAssert(cullable, "Cullable2D is null");

    LockGuard lock(mutex_);

    if (Sim()->IsFullUpdate())
    {
        if (num_cullables_2D_ >= max_cullables_2D_)
        {
            Warningf("Increase CULLMGR::MaxCullables2D!. MaxCullables2D=%d", max_cullables_2D_);
        }
        else
        {
            cullables_2D_[num_cullables_2D_] = cullable;
            ++num_cullables_2D_;
        }
    }
}

#ifdef ARTS_DEV_BUILD
void asCullManager::AddPage(Callback callback)
{
    ArAssert(num_pages_ < ARTS_SIZE(page_callbacks_), "Too Many Pages");

    page_callbacks_[num_pages_++] = callback;
}
#endif

void asCullManager::DeclareBitmap(asCullable* cullable, agiBitmap* bitmap)
{
    ArAssert(cullable, "Bitmap Cullable is null");

    if (bitmap && bitmap->Is3D())
        DeclareCullable(cullable);
    else
        DeclareCullable2D(cullable);
}

void asCullManager::DeclarePrint(asCullable* cullable)
{
    ArAssert(cullable, "Print Cullable is null");

    if (agiPrintIs3D())
        DeclareCullable(cullable);
    else
        DeclareCullable2D(cullable);
}

void asCullManager::Reset()
{
    LockGuard lock(mutex_);

    num_cameras_ = 0;
    num_cullables_ = 0;
    num_cullables_2D_ = 0;

    current_frame_time_ = 0.0f;
    average_frame_time_ = 0.0f;
    stats_counter_ = 0;

    frame_timer_.Reset();
    stats_timer_.Reset();
}

void asCullManager::Update()
{
    if (!Sim()->IsFullUpdate())
    {
        return;
    }

    LockGuard lock(mutex_);

    auto log_random_calls = std::exchange(LogRandomCalls, nullptr);
    auto rand_seed = gRandSeed;

    if (MIDGETSPTR->IsOpen())
        MIDGETSPTR->Update();

    PGRAPH->Update();

    Timer update_timer;
    float update_3D = 0.0f;

    if (num_cameras_ && IsAppActive())
    {
        Pipe()->BeginFrame();

        if (!num_cameras_ || !cameras_[0]->GetUnderlayBitmap() || cameras_[0]->GetUnderlayBitmap()->Is3D())
            Pipe()->BeginScene();

        Matrix34* prev_matrix = Sim()->GetCurrentMatrix();

        for (i32 i = 0; i < num_cameras_; ++i)
        {
            current_camera_ = cameras_[i];
            current_camera_->DrawBegin();

            for (i32 j = 0; j < num_cullables_; ++j)
            {
                Sim()->SetCurrentMatrix(transforms_[j]);
                cullables_[j]->Cull();
            }

            current_camera_->DrawEnd();
        }

        Sim()->SetCurrentMatrix(prev_matrix);

        Timer update_3D_timer;

        StatsTextOffset = 0;
        UpdateTime3D = asCullManager_UpdateTime3D;
        UpdateTime2D = asCullManager_UpdateTime - asCullManager_UpdateTime3D;

        if (agiPrintIs3D())
        {
            if (show_version_)
            {
                DisplayVersionString();
            }
            else if (current_page_)
            {
                page_callbacks_[current_page_ - 1].Call();
            }
        }

        agiCurState.SetTexture(nullptr);
        agiCurState.SetMtl(nullptr);

        // TODO: Should this only call EndScene if BeginScene was called?
        Pipe()->EndScene();

        current_camera_ = nullptr;

        update_3D = update_3D_timer.Time();

        for (i32 i = 0; i < num_cullables_2D_; ++i)
            cullables_2D_[i]->Cull();

        if (!agiPrintIs3D())
        {
            if (show_version_)
            {
                DisplayVersionString();
            }
            else if (current_page_)
            {
                page_callbacks_[current_page_ - 1].Call();
            }
        }

        Pipe()->EndFrame();
    }

    Update3D = update_3D;
    asCullManager_UpdateTime3D = update_3D;
    asCullManager_UpdateTime = update_timer.Time();

    CurrentFrameTime = frame_timer_.Time();
    frame_timer_.Reset();

    num_cameras_ = 0;
    num_cullables_2D_ = 0;
    num_cullables_ = 0;

    LogRandomCalls = log_random_calls;
    gRandSeed = rand_seed;
}

void asCullManager::DisplayVersionString() const
{
    agiPrintf(0, 0, text_color_, VERSION_STRING);
}

void asCullManager::PrintMiniStats()
{
    current_frame_time_ = CurrentFrameTime;

    f32 frame_weight = std::clamp(current_frame_time_, 0.01f, 0.5f);
    average_frame_time_ += (current_frame_time_ - average_frame_time_) * frame_weight;

    Statsf("%4.f fps (%5.2f/%5.2f ms/f)", std::round(1.0f / average_frame_time_), current_frame_time_ * 1000.0f,
        average_frame_time_ * 1000.0f);
}

void asCullManager::PrintStats()
{
    PrintMiniStats();

    agiStats stats = STATS;

    Statsf("Sim Delta:%5.2f TSC Speed:%2.2f GHz", Sim()->GetUpdateDelta() * 1000.0f, 0.000001f / ut2float);
    Statsf("CULLMGR 3D:%4.1f/2D:%4.1f/Updt:%4.1fms", UpdateTime3D * 1000.0f, (UpdateTime2D - UpdateTime3D) * 1000.0f,
        (CurrentFrameTime - UpdateTime2D) * 1000.0f);
    Statsf("DLPs Drawn:%-3d Clipped:%-3d", stats.DlpDrawn, stats.DlpClipped);
    Statsf("Verts Xfrm:%-5d Lit:%-5d OutC:%-5d Clip:%-5d", stats.VertsXfrm, stats.VertsLit, stats.VertsOut,
        stats.VertsClip);
    Statsf("Tris:%-4d Lines:%-4d Cards:%-4d", stats.Tris, stats.Lines, stats.Cards);
    Statsf("St.Chg:%-3d TexChg:%-3d St.Call:%-3d Geom.Call:%-3d", stats.StateChanges, stats.TextureChanges,
        stats.StateChangeCalls, stats.GeomCalls);
    Statsf("TxlsXfrd:%-4d KXtraTex:%-3d", (stats.TxlsXrfd + 1023) >> 10, stats.XtraTex);
}

extern const char* PrinterPrefixes[5];

const u32 agiPrinterColors[5] {
    0xFFFFFFFF,
    0xFFFFFF00,
    0xFFFF0000,
    0xFFFF0000,
    0xFFFF0000,
};

void Statsf(ARTS_FORMAT_STRING const char* format, ...)
{
    char buffer[256];
    std::va_list va;
    va_start(va, format);
    arts_vsprintf(buffer, format, va);
    va_end(va);

    u32 color = CullMgr()->GetTextColor();
    const char* text = buffer;

    for (i32 i = 4; i > 0; --i)
    {
        if (std::size_t length = std::strlen(PrinterPrefixes[i]); std::strncmp(text, PrinterPrefixes[i], length) == 0)
        {
            color = agiPrinterColors[i];
            text += length;
            break;
        }
    }

    agiPrint(0, StatsTextOffset, color, text);

    StatsTextOffset += agiFontHeight;
}

META_DEFINE_CHILD("asCullManager", asCullManager, asNode)
{}
