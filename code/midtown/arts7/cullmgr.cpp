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
#include "agi/pipeline.h"
#include "agi/print.h"
#include "data7/metadefine.h"
#include "dyna7/gfx.h"
#include "memory/allocator.h"
#include "memory/stack.h"
#include "midtown.h"
#include "pgraph.h"

static extern_var(0x790868, f32, CurrentFrameTime);

static extern_var(0x790870, f32, UpdateTime2D);
static extern_var(0x790874, f32, UpdateTime3D);

static extern_var(0x790878, i32, StatsTextOffset);

static void PrintPerfGraph()
{
    PGRAPH->Cull();
}

static void PrintRenderPerf()
{
    return stub<cdecl_t<void>>(0x5248E0);
}

static void PrintMessages()
{
    for (usize i = 0; i < std::size(MessageFifo); ++i)
    {
        Statsf("%s", MessageFifo[(i + MessageFirst) % std::size(MessageFifo)]);
    }
}

static void PrintMemoryUsage()
{
    asMemStats stats;
    asMemSource sources[1024];
    usize num_sources = std::size(sources);
    CURHEAP->GetStats(&stats, sources, &num_sources);

    Statsf("%6zu KB Max Size", CURHEAP->GetHeapSize() >> 10);
    Statsf("%6zu KB Current Size", CURHEAP->GetCurrentTotal() >> 10);

    Statsf("%6zu KB Used", stats.cbUsed >> 10);
    Statsf("%6zu KB Free", stats.cbFree >> 10);
    Statsf("%6zu KB Waste", stats.cbOverhead >> 10);

    Statsf("%6zu Nodes (%zu Used/%zu Free)", stats.nTotalNodes, stats.nUsedNodes, stats.nFreeNodes);

    Statsf("Nodes, Used (KB), Waste (KB) | Source");

    for (usize i = 0; i < std::min<usize>(num_sources, 64); ++i)
    {
        asMemSource source = sources[i];

        char symbol[128];
        LookupAddress(symbol, std::size(symbol), source.uSource);

        Statsf("%5zu, %5zu, %3zu | %s", source.nNodes, source.cbUsed >> 10, source.cbOverhead >> 10, symbol);
    }
}

asCullManager::asCullManager(i32 max_cullables, i32 max_cullables_2D)
    : max_cullables_(max_cullables)
    , max_cullables_2D_(max_cullables_2D)
    , cullables_(MakeUnique<asCullable*[]>(max_cullables))
    , cullables_2D_(MakeUnique<asCullable*[]>(max_cullables_2D))
    , transforms_(MakeUnique<Matrix34*[]>(max_cullables))
{
    Reset(); // TODO: Is this call unncessary?

    SetUpdateWhilePaused(true);

    AddPage(MFA(asCullManager::PrintMiniStats, this));
    AddPage(MFA(asCullManager::PrintStats, this));
    AddPage(CFA(PrintPerfGraph));
    AddPage(CFA(PrintRenderPerf));
    AddPage(CFA(PrintMessages));
    AddPage(CFA(PrintMemoryUsage));

    /*PGRAPH = */ new asPerfGraph();

    PGRAPH->AddComponent("3D", &UpdateTime3D, ColGreen);
    PGRAPH->AddComponent("2D", &UpdateTime2D, ColBlue);
}

asCullManager::~asCullManager()
{
    delete PGRAPH;
}

void asCullManager::DeclareCamera(asCamera* camera)
{
    MutexGuard lock(mutex_);

    if (num_cameras_ < static_cast<i32>(std::size(cameras_)))
    {
        cameras_[num_cameras_++] = camera;
    }
    else
    {
        Errorf("Too many cameras declared, somthing's rotten in Denmark.");
    }
}

void asCullManager::AddPage(Callback callback)
{
    ArAssert(num_pages_ < std::size(page_callbacks_), "Too Many Pages");

    page_callbacks_[num_pages_++] = callback;
}

void asCullManager::Reset()
{
    MutexGuard lock(mutex_);

    num_cameras_ = 0;
    num_cullables_ = 0;
    num_cullables_2D_ = 0;

    current_fps_ = 0.0f;
    average_fps_ = 0.0f;
    stats_counter_ = 0;

    frame_timer_.Reset();
    stats_timer_.Reset();
}

void asCullManager::DisplayVersionString()
{
    agiPrintf(0, 0, text_color_, VERSION_STRING);
}

void asCullManager::PrintMiniStats()
{
    current_fps_ = 1.0f / CurrentFrameTime;

    if (++stats_counter_ > std::clamp<f32>(average_fps_, 10.0f, 1000.0f))
    {
        average_fps_ = static_cast<f32>(stats_counter_) / stats_timer_.Time();
        stats_timer_.Reset();
        stats_counter_ = 0;
    }

    Statsf("%6.2f/%6.2f fps (%5.2fms/f)", current_fps_, average_fps_, CurrentFrameTime * 1000.0f);
}

void asCullManager::PrintStats()
{
    PrintMiniStats();

    agiStats stats = STATS;

    Statsf("CULLMGR 3D:%4.1f/2D:%4.1f/Updt:%4.1fms", UpdateTime3D * 1000.0f, (UpdateTime2D - UpdateTime3D) * 1000.0f,
        (CurrentFrameTime - UpdateTime2D) * 1000.0f);
    Statsf("DLPs Drawn:%-3dClipped:%-3d", stats.DlpDrawn, stats.DlpClipped);
    Statsf(
        "Verts Xfrm:%-5dLit:%-5dOutC:%-5dClip:%-5d", stats.VertsXfrm, stats.VertsLit, stats.VertsOut, stats.VertsClip);
    Statsf("Tris:%-4dLines:%-4dCards:%-4d", stats.Tris, stats.Lines, stats.Cards);
    Statsf("St.Chg:%-3dTexChg:%-3dSt.Call:%-3dGeom.Call:%-3d", stats.StateChanges, stats.TextureChanges,
        stats.StateChangeCalls, stats.GeomCalls);
    Statsf("TxlsXfrd:%-4dKXtraTex:%-3d", (stats.TxlsXrfd + 1023) >> 10, stats.XtraTex);
}

void Statsf(ARTS_FORMAT_STRING char const* format, ...)
{
    char buffer[128];
    std::va_list va;
    va_start(va, format);
    arts_vsprintf(buffer, format, va);
    va_end(va);

    agiPrint(0, StatsTextOffset, CULLMGR->GetTextColor(), buffer);

    StatsTextOffset += agiFontHeight;
}

META_DEFINE_CHILD("asCullManager", asCullManager, asNode)
{}
