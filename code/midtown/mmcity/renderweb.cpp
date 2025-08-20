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

define_dummy_symbol(mmcity_renderweb);

#include "renderweb.h"

#include "cellrend.h"
#include "loader.h"

#include "agi/dlptmpl.h"
#include "agi/getdlp.h"
#include "agi/pipeline.h"
#include "agi/viewport.h"
#include "data7/memstat.h"
#include "data7/metadefine.h"
#include "localize/localize.h"
#include "mmcityinfo/state.h"
#include "mmdyna/bndtmpl.h"
#include "mmdyna/bndtmpl2.h"
#include "stream/fsystem.h"
#include "stream/problems.h"
#include "stream/stream.h"

static mem::cmd_param PARAM_mirrordist {"mirrordist"};
static mem::cmd_param PARAM_invlodfactor {"invlodfactor"};

f32 asRenderWeb::InvLodFactor = 0.65f;
i32 asRenderWeb::PassMask = 0;

// ?MirrorDist@@3MA
ARTS_EXPORT f32 MirrorDist = 200.0f;

hook_func(INIT_main, [] {
    asRenderWeb::InvLodFactor = PARAM_invlodfactor.get_or(0.65f);
    MirrorDist = PARAM_mirrordist.get_or(200.0f);
});

enum
{
    CHICAGO_CELL_CONSTRUCTION = 60,
    CHICAGO_CELL_WRIGLEY_OUTER = 24,
    CHICAGO_CELL_AQUARIUM = 31,
    CHICAGO_CELL_PLANETARIUM = 32,
    CHICAGO_CELL_MCCORMICK = 39,
    CHICAGO_CELL_WRIGLEY_INNER = 174,

    CITY_MESH_START = 200,
};

asRenderWeb::asRenderWeb()
{
    SetNodeFlag(NODE_FLAG_UPDATE_PAUSED);

    Viewport = as_rc Pipe()->CreateViewport();
}

asRenderWeb::~asRenderWeb() = default;

i32 asRenderWeb::GetCellNeighbors(i32 cell_id, asPortalCell** cells, i32 capacity)
{
    i32 count = 0;

    if (asPortalCell* cell = GetCell(cell_id))
    {
        for (PortalLink* link = cell->Edges; link; link = link->Next)
        {
            asPortalEdge* edge = link->Edge;

            cells[count] = (edge->Cell1 != cell) ? edge->Cell1 : edge->Cell2;

            if (++count == capacity)
                break;
        }
    }

    return count;
}

b32 asRenderWeb::Load(aconst char* city_name, b32 enable_lm)
{
    CellArray.reset();

    MemStat load("asRenderWeb::Load");

    {
        ARTS_LOADER_TASK(MM_IDS_LOADING_STATIC_TERRAIN, 0.16f);
        ARTS_MEM_STAT("asRenderWeb CELLS");
        LoadCells(city_name, enable_lm);
    }

    {
        ARTS_LOADER_TASK(MM_IDS_LOADING_COLLISION_DATABASE, 0.16f);

        {
            ARTS_MEM_STAT("asRenderWeb hitid bound");
            LoadHitId(city_name);
        }

        {
            ARTS_MEM_STAT("asRenderWeb per-room bound");
            LoadRoomBounds(city_name, enable_lm);
        }
    }

    {
        ARTS_LOADER_TASK(MM_IDS_LOADING_PORTAL_INFO, 0.16f);
        ARTS_MEM_STAT("asRenderWeb PORTALS");
        LoadPortals(city_name);
    }

    if (MakeTableStats)
    {
        delete MakeTableStats;
        MakeTableStats = nullptr;
    }

    return true;
}

void asRenderWeb::LoadCells(const char* city_name, bool enable_lm)
{
    Ptr<Stream> stream = as_ptr OpenFile(city_name, "city", ".cells", 0, nullptr, 0, "Cell info file");

    if (!stream)
        Quitf("Missing .cells file for '%s'", city_name);

    auto city_mesh = arts_formatf<128>("%scity", city_name);
    auto lm_mesh = arts_formatf<128>("%slm", city_name);

    char buffer[256];
    stream->Gets(buffer, ARTS_SIZE(buffer));
    i32 num_cells = std::atoi(buffer);

    stream->Gets(buffer, ARTS_SIZE(buffer));
    MaxCells = std::atoi(buffer) + 1;

    CellArray = arnewa asPortalCell * [MaxCells] {};

    for (i32 i = 0; i < num_cells; ++i)
    {
        stream->Gets(buffer, sizeof(buffer));
        char* here = buffer;

        i32 cell_index = std::atoi(here);
        here = std::strchr(here, ',') + 1;

        i32 cull_flags = std::atoi(here);
        here = std::strchr(here, ',');

        i32 room_flags = 0;
        i32 tag_count = 0;
        i32 tags[100];

        if (here)
        {
            char* context = nullptr;
            here = arts_strtok(here, ", \n", &context);

            if (here)
                room_flags = std::atoi(here);

            here = arts_strtok(nullptr, ", \n", &context);

            if (here)
                tag_count = std::atoi(here);

            ArAssert(tag_count < ARTS_SSIZE32(tags), "Too many visit tags");

            for (i32 j = 0; j < tag_count; ++j)
            {
                here = arts_strtok(nullptr, ", \n", &context);
                tags[j] = std::atoi(here);
            }
        }

        if (cell_index < 1 || cell_index >= MaxCells)
            Quitf("Bad cell index CULL%02d", cell_index);

        const char* mesh_name = (cell_index >= CITY_MESH_START || !enable_lm) ? city_mesh : lm_mesh;

        mmCellRenderer* renderer = new mmCellRenderer();
        renderer->Init(xconst(mesh_name), cell_index, cull_flags, room_flags, tag_count, tags);

        asPortalCell* cell = AddCell(xconst(mesh_name), renderer, cell_index);
        CellArray[cell_index] = cell;

        if (CHICAGO)
        {
            switch (cell_index)
            {
                case CHICAGO_CELL_WRIGLEY_OUTER:
                case CHICAGO_CELL_WRIGLEY_INNER:
                case CHICAGO_CELL_AQUARIUM:
                case CHICAGO_CELL_PLANETARIUM:
                case CHICAGO_CELL_MCCORMICK: cell->Flags = PORTAL_CELL_EDGE_SORTING; break;
            }
        }
    }
}

struct PtlPortal
{
    u8 Flags;
    i8 EdgeCount;
    i16 gap2;
    i16 Cell1;
    i16 Cell2;
    f32 Height;
    Vector3 Min;
    Vector3 Max;
};
check_size(PtlPortal, 0x24);

void asRenderWeb::LoadPortals(const char* city_name)
{
    Ptr<Stream> stream = as_ptr OpenFile(city_name, "city", ".ptl", 0, nullptr, 0, "portal file");

    if (!stream)
        Quitf("Missing .portal file for '%s'", city_name);

    i32 vec_count = 0;
    stream->Read(&vec_count, sizeof(vec_count));
    ArAssert(vec_count == 0, "Unexpected PTL data");

    i32 portal_count = 0;
    stream->Read(&portal_count, sizeof(portal_count));

    for (i32 i = 0; i < portal_count; ++i)
    {
        PtlPortal ptl;
        Vector3 extra_edge;

        stream->Read(&ptl, sizeof(ptl));

        ArAssert(ptl.EdgeCount >= 2 && ptl.EdgeCount <= 3, "Invalid edge count!");

        if (ptl.EdgeCount == 3)
            stream->Read(&extra_edge, sizeof(extra_edge));

        if ((ptl.Cell1 == 0) || (ptl.Cell1 > MaxCells) || (ptl.Cell2 == 0) || (ptl.Cell2 > MaxCells))
        {
            RegisterProblem("Bad portal index", city_name, arts_formatf<128>("%d or %d", ptl.Cell1, ptl.Cell2));
            continue;
        }

        asPortalCell* cell1 = CellArray[ptl.Cell1];

        if (!cell1)
        {
            RegisterProblem(
                "Cell doesn't exist [missing open area?]", city_name, arts_formatf<128>("CULL%02d", ptl.Cell1));
            continue;
        }

        asPortalCell* cell2 = CellArray[ptl.Cell2];

        if (!cell2)
        {
            RegisterProblem(
                "Cell doesn't exist [missing open area?]", city_name, arts_formatf<128>("CULL%02d", ptl.Cell2));
            continue;
        }

        asPortalEdge* edge = AddEdge("PORTAL"_xconst, cell1, cell2, ptl.EdgeCount + 2);

        if (ptl.EdgeCount == 3)
        {
            edge->Edges[0] = Vector3(ptl.Min.x, ptl.Min.y + ptl.Height, ptl.Min.z);
            edge->Edges[1] = Vector3(ptl.Max.x, ptl.Max.y + ptl.Height, ptl.Max.z);
            edge->Edges[2] = ptl.Max;
            edge->Edges[3] = extra_edge;
            edge->Edges[4] = ptl.Min;
        }
        else
        {
            edge->Edges[0] = Vector3(ptl.Min.x, ptl.Min.y + ptl.Height, ptl.Min.z);
            edge->Edges[1] = Vector3(ptl.Max.x, ptl.Max.y + ptl.Height, ptl.Max.z);
            edge->Edges[2] = ptl.Max;
            edge->Edges[3] = ptl.Min;
        }

        edge->Plane.CalculatePlane(edge->Edges[0], edge->Edges[1], edge->Edges[2]);
        edge->Flags |= ptl.Flags;
    }

    // We have already saved an optimized CHICAGO.PTL in 1560.ar
    if (std::strcmp(city_name, "chicago"))
    {
        OptimizePortals();
    }
}

void asRenderWeb::OptimizePortals()
{
    i32 optimized = 0;
    i32 total = 0;

    for (asPortalEdge* edge = Edges; edge; edge = edge->Next)
    {
        for (i32 j = 0; j < edge->NumEdges; ++j)
        {
            Vector3 vert = edge->Edges[j];
            f32 dist = edge->Plane.PlaneDist(edge->Edges[j]);

            if (std::abs(dist) > 0.1f)
            {
                Errorf("Edge %d/%d @ {%5.3f, %5.3f, %5.3f} is not planar!", edge->Cell1->CellIndex,
                    edge->Cell2->CellIndex, vert.x, vert.y, vert.z);
                edge->Flags &= ~asPortalEdge::Flags_Enabled;
                break;
            }
        }

        {
            mmCellRenderer* rend_1 = static_cast<mmCellRenderer*>(edge->Cell1->CellRenderer);
            mmCellRenderer* rend_2 = static_cast<mmCellRenderer*>(edge->Cell2->CellRenderer);

            Vector3 center_1 = rend_1->CellCenter;
            Vector3 center_2 = rend_2->CellCenter;
            center_1.y = center_2.y;

            f32 dist = rend_1->CellCenter.Dist(rend_2->CellCenter);
            f32 max_dist = rend_1->CellMagnitude + rend_2->CellMagnitude + 5.0f;

            if (dist > max_dist)
            {
                Vector3 vert = (edge->Edges[0] + edge->Edges[2]) * 0.5f;

                Errorf("Edge %d/%d @ {%5.3f, %5.3f, %5.3f} is suspicious, dist=%3.0f, max=%3.0f",
                    edge->Cell1->CellIndex, edge->Cell2->CellIndex, vert.x, vert.y, vert.z, dist, max_dist);
            }
        }

        if (!edge->IsEnabled())
            continue;

        ++total;
        edge->Flags &= ~asPortalEdge::Flags_ForwardPlane;

        Vector3 edge_1 = edge->Edges[0];
        Vector3 edge_2 = edge->Edges[2];
        Vector3 center = (edge_1 + edge_2) * 0.5f;
        Vector3 offset = Vector3(edge->Plane.x, edge->Plane.y, edge->Plane.z);
        Vector3 point_1 = center - offset;
        Vector3 point_2 = center + offset;

        asPortalCell* cell_1 = nullptr;
        asPortalCell* cell_2 = nullptr;

        for (i32 i = 0; i < 5; ++i)
        {
            point_1.y -= 10.0f;
            point_2.y -= 10.0f;

            if (cell_1 != edge->Cell1)
                cell_1 = GetStartCell(point_1, nullptr, nullptr);

            if (cell_2 != edge->Cell2)
                cell_2 = GetStartCell(point_2, nullptr, nullptr);
        }

        bool negate = false;

        if ((cell_1 != edge->Cell1) && (cell_2 != edge->Cell2))
        {
            std::swap(cell_1, cell_2);
            negate = true;
        }

        if (cell_1 == edge->Cell1)
        {
            if (!cell_2)
                cell_2 = edge->Cell2;
        }

        if (cell_2 == edge->Cell2)
        {
            if (!cell_1)
                cell_1 = edge->Cell1;
        }

        if ((cell_1 == edge->Cell1) && (cell_2 == edge->Cell2))
        {
            ++optimized;

            edge->Flags |= asPortalEdge::Flags_ForwardPlane;

            if (negate)
            {
                std::swap(edge->Edges[0], edge->Edges[1]);
                std::swap(edge->Edges[2], edge->Edges[edge->NumEdges - 1]);
                edge->Plane = -edge->Plane;
            }
        }
    }

    Displayf("Optimized %i/%i portal planes", optimized, total);
}

void asRenderWeb::SavePortals()
{
    i32 num_edges = 0;

    for (asPortalEdge* edge = Edges; edge; edge = edge->Next)
        ++num_edges;

    Ptr<asPortalEdge*[]> edges = arnewa asPortalEdge * [num_edges] {};

    {
        i32 index = num_edges;

        for (asPortalEdge* edge = Edges; edge; edge = edge->Next)
            edges[--index] = edge;
    }

    Ptr<Stream> output {arts_fopen("city/optimized.ptl", "w")};

    if (output)
    {
        i32 vec_count = 0;
        output->Write(&vec_count, sizeof(vec_count));
        output->Write(&num_edges, sizeof(num_edges));

        for (i32 i = 0; i < num_edges; ++i)
        {
            asPortalEdge* edge = edges[i];
            ArAssert(edge->NumEdges >= 4 && edge->NumEdges <= 5, "Invalid edge count");

            PtlPortal ptl {};
            ptl.Flags = edge->Flags & ~asPortalEdge::Flags_Enabled;
            ptl.EdgeCount = edge->NumEdges - 2;
            ptl.Cell1 = edge->Cell1->CellIndex;
            ptl.Cell2 = edge->Cell2->CellIndex;
            ptl.Height = edge->Edges[1].y - edge->Edges[2].y;
            ptl.Min = edge->Edges[edge->NumEdges - 1];
            ptl.Max = edge->Edges[2];
            output->Write(&ptl, sizeof(ptl));

            if (edge->NumEdges == 5)
                output->Write(&edge->Edges[3], sizeof(edge->Edges[3]));
        }
    }
}

void asRenderWeb::LoadHitId(const char* city_name)
{
    HitIdBound = as_rc mmBoundTemplate::GetBoundTemplate(
        arts_formatf<128>("%s_hitid", city_name), nullptr, nullptr, 1, 300, 1, 300, 0);

    if (HitIdBound)
    {
        HasHitIdBound = true;
    }
    else
    {
        HitIdBound = as_rc mmBoundTemplate::GetBoundTemplate(
            arts_formatf<128>("%scity", city_name), "BOUND"_xconst, nullptr, 1, 150, 1, 150, 0);

        HasHitIdBound = false;
    }
}

void asRenderWeb::LoadRoomBounds(const char* city_name, bool enable_lm)
{
    auto city_mesh = arts_formatf<128>("%scity", city_name);
    auto lm_mesh = arts_formatf<128>("%slm", city_name);

    Bounds = arnewa Rc<mmBoundTemplate>[MaxCells] {};

    if (!HasHitIdBound)
    {
        return;
    }

    for (i32 i = 0; i < MaxCells; ++i)
    {
        if (!CellArray[i])
            continue;

        const char* mesh_name = (i >= CITY_MESH_START || !enable_lm) ? city_mesh : lm_mesh;

        if (CHICAGO)
        {
            switch (i)
            {
                case CHICAGO_CELL_CONSTRUCTION: mesh_name = "dl60_bnd"; break;
                case CHICAGO_CELL_WRIGLEY_OUTER:
                case CHICAGO_CELL_WRIGLEY_INNER: mesh_name = "dl24_bnd"; break;
            }
        }

        Bounds[i] = as_rc mmBoundTemplate::GetBoundTemplate(
            xconst(mesh_name), arts_formatf<128>("BOUND%02d", i), nullptr, 0, 0, 0, 0, 0);
    }

    // TODO: Regenerate from DLP if present
}

#ifdef ARTS_DEV_BUILD
void asRenderWeb::DrawAllBounds()
{
    asPortalView* portals = Portals[CurrentPass];

    for (i32 i = 0, count = NumSubPortals[CurrentPass]; i < count; ++i)
    {
        asPortalCell* cell = portals[i].Cell;

        if (mmBoundTemplate* bound = Bounds[cell->CellIndex].get(); bound && bound->LockIfResident())
        {
            bound->Draw();
            bound->Unlock();
        }
    }
}

void asRenderWeb::AddWidgets(Bank* bank)
{
    asPortalWeb::AddWidgets(bank);
    bank->AddSlider("HitID", &HitID, 0, 10000, 0.0f); // Read-Only
    bank->AddSlider("ScreenClearY", &ScreenClearY, 0.0f, 10000.0f, 1.0f);
    bank->AddButton("Optimize Portals", [this] { OptimizePortals(); });
    bank->AddButton("Save Portals", [this] { SavePortals(); });
}
#endif

META_DEFINE_CHILD("asRenderWeb", asRenderWeb, asPortalWeb)
{}
