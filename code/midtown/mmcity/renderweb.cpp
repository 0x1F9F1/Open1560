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

#include "agi/dlptmpl.h"
#include "agi/getdlp.h"
#include "data7/memstat.h"
#include "localize/localize.h"
#include "mmcityinfo/state.h"
#include "mmdyna/bndtmpl.h"
#include "mmdyna/bndtmpl2.h"
#include "stream/fsystem.h"
#include "stream/problems.h"
#include "stream/stream.h"

#include "cellrend.h"
#include "loader.h"

static mem::cmd_param PARAM_mirrordist {"mirrordist"};

hook_func(INIT_main, [] {
    create_packed_patch<f32>(
        "Mirror Render Distance", "Adjust mirror render distance", 0x490E96 + 1, PARAM_mirrordist.get_or(200.0f));
});

i32 asRenderWeb::Load(char* city_name, i32 enable_lm)
{
    char city_mesh[256];
    char lm_mesh[256];
    char hitid_name[256];
    char buffer[512];           // original: 128
    i32 visit_tags[512] = {0};  // original: 128
    char cull_problem_1[32];
    // char cull_problem_2[32];
    // char cull_problem_3[32];

    i32 ptr = 0;
    i32 room_flags = 0;
    i32 visit_tag_count = 0;

    arts_sprintf(city_mesh, "%scity", city_name);
    arts_sprintf(lm_mesh, "%slm", city_name);

    if (CellArray)
        delete[] CellArray;

    BeginMemStat("asRenderWeb::Load");

    Stream* stream = OpenFile(city_name, "city", ".cells", 0, buffer, sizeof(buffer), "Cell info file");

    if (!stream)
        Quitf("Missing .cells file for '%s'", city_name);

    arts_fgets(buffer, sizeof(buffer), stream);
    i32 num_cells = atoi(buffer);

    arts_fgets(buffer, sizeof(buffer), stream);
    MaxCells = atoi(buffer) + 1;

    Loader()->BeginTask(AngelReadString(MM_IDS_LOADING_STATIC_TERRAIN));
    BeginMemStat("asRenderWeb CELLS");

    CellArray = new asPortalCell*[MaxCells];
    std::memset(CellArray, 0, sizeof(asPortalCell*) * MaxCells); 

    ////////////////////////////////////////////////////////////////////////////////////

    for (i32 i = 0; i < num_cells; ++i)
    {
        arts_fgets(buffer, sizeof(buffer), stream);
        i32 cell_index = atoi(buffer);

        char* cull_flags_str = strchr(buffer, ',') + 1;
        i32 cull_flags = atoi(cull_flags_str);

        char* context = nullptr;
        char* token = arts_strtok(cull_flags_str, ", \n", &context);

        if (token)
            room_flags = atoi(token);

        token = arts_strtok(nullptr, ", \n", &context);

        if (token)
            visit_tag_count = atoi(token);

        for (i32 j = 0; j < visit_tag_count; ++j)
        {
            token = arts_strtok(nullptr, ", \n", &context);
            visit_tags[j] = atoi(token);
        }

        if (cell_index < 1 || cell_index > MaxCells)
            Quitf("Bad cell index CULL%02d", cell_index);

        mmCellRenderer* rndr = new mmCellRenderer;
        rndr->Init(enable_lm ? lm_mesh : city_mesh, cell_index, cull_flags, room_flags, visit_tag_count, visit_tags);

        CellArray[cell_index] = AddCell(city_mesh, rndr, cell_index);
        CellArray[cell_index]->Flags = cell_index == 24 || cell_index == 31 || cell_index == 32 || cell_index == 39;
    }

    EndMemStat();
    Loader()->EndTask(0.16f);

    ////////////////////////////////////////////////////////////////////////////////////

    Loader()->BeginTask(AngelReadString(MM_IDS_LOADING_PORTAL_INFO));
    BeginMemStat("asRenderWeb PORTALS");

    stream = OpenFile(city_name, "city", ".ptl", 0, buffer, sizeof(buffer), "portal file");

    if (!stream)
        Quitf("Missing .portal file for '%s'", city_name);

    stream->Read(reinterpret_cast<char*>(&ptr), sizeof(ptr));
    stream->Read(reinterpret_cast<char*>(&visit_tag_count), sizeof(visit_tag_count));

    PtlPortal* portal_data = new PtlPortal[ptr];
    stream->Read(reinterpret_cast<char*>(portal_data), sizeof(PtlPortal) * ptr);

    ////////////////////////////////////////////////////////////////////////////////////

    for (i32 i = 0; i < visit_tag_count; ++i)
    {
        PtlPortal ptl {};
        stream->Read(reinterpret_cast<char*>(&ptl), sizeof(PtlPortal) - sizeof(ptl.ExtraEdge));

        if (ptl.EdgeCount == 3)
            stream->Read(reinterpret_cast<char*>(&ptl.ExtraEdge), sizeof(ptl.ExtraEdge));

        if (!ptl.Cell1 || ptl.Cell1 > MaxCells || (ptl.Cell2 && ptl.Cell2 > MaxCells))
        {
            RegisterProblem("Bad portal index", city_name, arts_formatf<128>("%d or %d", ptl.Cell1, ptl.Cell2));
            continue;
        }

        // Problematic I think
        asPortalCell* cell_array_1 = CellArray[ptl.Cell1];
        asPortalCell* cell_array_2 = CellArray[ptl.Cell2];

        if (cell_array_1 && cell_array_2)
        {
            AddEdge("PORTAL"_xconst, cell_array_1, cell_array_2, ptl.EdgeCount + 2);

            asPortalEdge* edge = new asPortalEdge(cell_array_1, cell_array_2, ptl.EdgeCount + 2);
            edge->Groups = new Vector3[4];

            if (ptl.EdgeCount == 2)
            {
                edge->Edges = new Vector3[4];
                edge->Edges[0] = {ptl.Min.x, ptl.Min.y + ptl.Height, ptl.Min.z};
                edge->Edges[0] = {ptl.Min.x, ptl.Min.y + ptl.Height, ptl.Min.z};
                edge->Edges[1] = {ptl.Max.x, ptl.Max.y + ptl.Height, ptl.Max.z};
                edge->Edges[2] = ptl.Max;
                edge->Edges[3] = ptl.Min;
            }
            else
            {
                edge->Edges = new Vector3[5];
                edge->Edges[0] = {ptl.Min.x, ptl.Min.y + ptl.Height, ptl.Min.z};
                edge->Edges[1] = {ptl.Max.x, ptl.Max.y + ptl.Height, ptl.Max.z};
                edge->Edges[2] = ptl.Max;
                edge->Edges[3] = ptl.ExtraEdge;
                edge->Edges[4] = ptl.Min;
            }

            edge->Plane.CalculatePlane(edge->Edges[0], edge->Edges[1], edge->Edges[2]);
            edge->Flags |= ptl.Flags;

            delete[] edge->Edges;
            delete[] edge->Groups;
            delete edge;
        }

        else
        {
            arts_sprintf(cull_problem_1, "CULL%02d", ptl.Cell1);
            RegisterProblem("Cell doesn't exist [missing open area?]", city_name, cull_problem_1);
        }
        // register problem 2 & 3
    }

    delete[] portal_data;
    stream->~Stream();

    BuildGroups(); 
    EndMemStat();

    ////////////////////////////////////////////////////////////////////////////////////

    Loader()->EndTask();
    Loader()->BeginTask(AngelReadString(MM_IDS_LOADING_COLLISION_DATABASE));

    BeginMemStat("asRenderWeb hitid bound");

    arts_sprintf(hitid_name, "%s_hitid", city_name);

    HitIdBound = mmBoundTemplate::GetBoundTemplate(hitid_name, nullptr, nullptr, 1, 300, 1, 300, 0);

    if (HitIdBound)
    {
        HasHitIdBound = true;
    }
    else
    {
        HitIdBound = mmBoundTemplate::GetBoundTemplate(city_mesh, "BOUND"_xconst, nullptr, 1, 150, 1, 150, 0);
        HasHitIdBound = false;
    }

    EndMemStat();

    ////////////////////////////////////////////////////////////////////////////////////

    BeginMemStat("asRenderWeb per-room bound");

    Bounds = new mmBoundTemplate*[MaxCells]();
    memset(Bounds, 0, sizeof(mmBoundTemplate*) * MaxCells);

    if (HasHitIdBound)
    {
        for (i32 i = 0; i < MaxCells; ++i)
        {
            if (!CellArray[i])
                continue;

            char* mesh = (i >= 200 || !enable_lm) ? city_mesh : lm_mesh;
            char* bound_name = arts_formatf<128>("BOUND%02d"_xconst, i);

            if (CHICAGO)
            {
                if (i == 60)
                {
                    Bounds[60] =
                        mmBoundTemplate::GetBoundTemplate("dl60_bnd"_xconst, bound_name, nullptr, 0, 0, 0, 0, 0);
                    continue;
                }
                if (i == 24)
                {
                    Bounds[24] =
                        mmBoundTemplate::GetBoundTemplate("dl24_bnd"_xconst, bound_name, nullptr, 0, 0, 0, 0, 0);
                    continue;
                }
                if (i == 174)
                {
                    Bounds[174] =
                        mmBoundTemplate::GetBoundTemplate("dl24_bnd"_xconst, bound_name, nullptr, 0, 0, 0, 0, 0);
                    continue;
                }
            }

            Bounds[i] = mmBoundTemplate::GetBoundTemplate(mesh, bound_name, nullptr, 0, 0, 0, 0, 0);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////

    else
    {
        DLPTemplate* city_template = GetDLPTemplate(city_mesh);
        DLPTemplate* lm_template = GetDLPTemplate(lm_mesh);

        if (city_template)
        {
            for (i32 i = 0; i < MaxCells; ++i)
            {
                if (!CellArray[i])
                    continue;

                char* mesh = (i >= 200 || !enable_lm) ? city_mesh : lm_mesh;
                char* bound_name = arts_formatf<128>("BOUND%02d"_xconst, i);

                DLPTemplate* tmpl = new DLPTemplate(bound_name);
                DLPGroup* grp = tmpl->GroupExists(bound_name);

                if (!grp)
                {
                    Errorf("No group %s in %s", bound_name, city_name);
                    continue;
                }

                i32 num_patches = static_cast<i32>(sqrt(grp->NumPatches));

                if (num_patches > 30)
                    num_patches = 30;

                if (!CHICAGO)
                {
                    if (num_patches <= 1)
                    {
                        Bounds[i] = mmBoundTemplate::GetBoundTemplate(mesh, bound_name, nullptr, 1, 0, 0, 0, 0);
                    }
                    else
                    {
                        Bounds[i] = mmBoundTemplate::GetBoundTemplate(
                            mesh, bound_name, nullptr, 1, num_patches, 1, num_patches, 0);
                    }
                    continue;
                }

                if (i == 623 || i == 350)
                    num_patches = 1;

                if (i == 60)
                {
                    Bounds[60] = mmBoundTemplate::GetBoundTemplate(
                        "dl60_bnd"_xconst, bound_name, nullptr, 1, num_patches, 1, num_patches, 0);
                    continue;
                }
                if (i == 24)
                {
                    Bounds[24] = mmBoundTemplate::GetBoundTemplate(
                        "dl24_bnd"_xconst, bound_name, nullptr, 1, num_patches, 1, num_patches, 0);
                    continue;
                }
                if (i == 174)
                {
                    Bounds[174] = mmBoundTemplate::GetBoundTemplate(
                        "dl24_bnd"_xconst, bound_name, nullptr, 1, num_patches, 1, num_patches, 0);
                    continue;
                }

                Bounds[i] =
                    mmBoundTemplate::GetBoundTemplate(mesh, bound_name, nullptr, 1, num_patches, 1, num_patches, 0);
            }

            city_template->Release();
        }

        if (lm_template)
        {
            lm_template->Release();
        }
        else
        {
            Errorf("Not able to get city template");
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////

    if (MakeTableStats)
        // ?
        // MakeTableStats->Destructor(MakeTableStats, 1u);
        EndMemStat();

    EndMemStat();
    Loader()->EndTask();
    return 1;
}