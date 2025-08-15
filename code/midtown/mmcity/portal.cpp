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

define_dummy_symbol(mmcity_portal);

#include "portal.h"

#include "agi/viewport.h"
#include "arts7/cullmgr.h"
#include "arts7/sim.h"
#include "core/podarray.h"
#include "data7/metadefine.h"
#include "data7/utimer.h"
#include "dyna7/gfx.h"

#define EDGE_CLIP_PX 0x01 // Clip +X
#define EDGE_CLIP_NX 0x02 // Clip -X
#define EDGE_CLIP_PY 0x04 // Clip +Y
#define EDGE_CLIP_NY 0x08 // Clip -Y
#define EDGE_CLIP_PZ 0x10 // Clip +Z
#define EDGE_CLIP_NZ 0x20 // Clip -Z

u16 asPortalWeb::VisitTag = 0;

static b32 VisitOnce = true;
static b32 EnableGroups = true;
static b32 BackfacingPortals = false;

static i32 PortalCurrentIdx = 0;
static i32 PortalShowIdx = 0;
static i32 PortalDebugIdx = 0;

static utimer_t PortalUpdateTimer[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 CellTests[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 CellEdgeTests[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 BackfaceEdges[asPortalWeb::NUM_PORTAL_PASSES] {};

template <typename T, typename TestFunc, typename ClipFunc>
static i32 Clipper(T* output, T* input, i32 count, TestFunc tester, ClipFunc clipper)
{
    i32 done = 0;
    i32 prev = count - 1;
    bool prev_clipped = tester(input[prev]);

    for (i32 i = 0; i < count; ++i)
    {
        bool clipped = tester(input[i]);

        if (clipped != prev_clipped)
        {
            output[done] = clipper(input[clipped ? i : prev], input[clipped ? prev : i]);
            ++done;
        }

        if (!clipped)
        {
            output[done] = input[i];
            ++done;
        }

        prev_clipped = clipped;
        prev = i;
    }

    return done;
}

static i32 ClipNX(Vector4* output, Vector4* input, i32 count)
{
    const auto clip = [](Vector4 v0, Vector4 v1) {
        Vector4 d = v1 - v0;
        f32 t = -(v0.w + v0.x) / (d.w + d.x);

        v0.y += t * d.y;
        v0.z += t * d.z;
        v0.w += t * d.w;
        v0.x = -v0.w;

        return v0;
    };

    return Clipper(output, input, count, [](const Vector4& vert) { return -vert.x > vert.w; }, clip);
}

static i32 ClipPX(Vector4* output, Vector4* input, i32 count)
{
    const auto clip = [](Vector4 v0, Vector4 v1) {
        Vector4 d = v1 - v0;
        f32 t = -(v0.w - v0.x) / (d.w - d.x);

        v0.y += t * d.y;
        v0.z += t * d.z;
        v0.w += t * d.w;
        v0.x = v0.w;

        return v0;
    };

    return Clipper(output, input, count, [](const Vector4& vert) { return vert.x > vert.w; }, clip);
}

static i32 ClipNY(Vector4* output, Vector4* input, i32 count)
{
    const auto clip = [](Vector4 v0, Vector4 v1) {
        Vector4 d = v1 - v0;
        f32 t = -(v0.w + v0.y) / (d.w + d.y);

        v0.x += t * d.x;
        v0.z += t * d.z;
        v0.w += t * d.w;
        v0.y = -v0.w;

        return v0;
    };

    return Clipper(output, input, count, [](const Vector4& vert) { return -vert.y > vert.w; }, clip);
}

static i32 ClipPY(Vector4* output, Vector4* input, i32 count)
{
    const auto clip = [](Vector4 v0, Vector4 v1) {
        Vector4 d = v1 - v0;
        f32 t = -(v0.w - v0.y) / (d.w - d.y);

        v0.x += t * d.x;
        v0.z += t * d.z;
        v0.w += t * d.w;
        v0.y = v0.w;

        return v0;
    };

    return Clipper(output, input, count, [](const Vector4& vert) { return vert.y > vert.w; }, clip);
}

static i32 XYClip(Vector4* verts, i32 count)
{
    PodArray<Vector4, 16> temp;

    if (count = ClipPX(temp, verts, count); count == 0)
        return 0;

    if (count = ClipNX(verts, temp, count); count == 0)
        return 0;

    if (count = ClipPY(temp, verts, count); count == 0)
        return 0;

    if (count = ClipNY(verts, temp, count); count == 0)
        return 0;

    return count;
}

asPortalWeb::asPortalWeb()
{
    CullMgr()->AddPage([this] { Stats(); });
}

asPortalWeb::~asPortalWeb()
{
    while (asPortalCell* cell = CellList)
    {
        CellList = cell->Next;

        delete cell;
    }
}

void asPortalWeb::Update()
{
    // Starting from our eye position, recursively visit neighbouring cells via their edges.
    // Frustum culling is used to calculate the visible bounds of each cell.
    // When you visit a cell, the frustum is intersected with the edge you are visiting it from.
    // If the frustum does not intersect with the edge, we know that cell is not visible.
    //
    // Unfortunately, we do not support visiting a cell multiple times from different edges.
    // This means we cannot rely purely on the frustum bounds for visibility,
    // since multiple cells may have different levels of visiblity into another.
    //
    // Instead, edges have "open" and "half-open" flags to avoid clipping parts of the frustum.
    // Plus, cells have an "edge sorting" flag to try and ensure the closest edge is used.

    ARTS_UTIMED(PortalUpdateTimer[CurrentPass]);

    const agiViewParameters& vp = ViewParams();
    Vector3 eye_pos = vp.Camera.m3 + vp.Camera.m2 * -vp.Near;
    StartCell = GetStartCell(eye_pos, StartCell, 0);

    if (!StartCell)
    {
        Errorf("asPortalWeb::GetStartCell failed.");
        return;
    }

    struct TraverseCommand
    {
        asPortalCell* Cell;
        asPortalEdge* Edge;
        i32 RenderDepth;

        f32 MinX;
        f32 MaxX;
        f32 MinY;
        f32 MaxY;
    };

    static const usize TRAVERSE_QUEUE_SIZE = 128;
    TraverseCommand traverse_queue[TRAVERSE_QUEUE_SIZE];
    usize traverse_head = 0;
    usize traverse_tail = 0;

    ++VisitTag;

    const auto traverse = [&](asPortalCell* cell, asPortalEdge* edge, i32 render_depth, f32 minX, f32 maxX, f32 minY,
                              f32 maxY) {
        if (render_depth > MaxRenderDepth)
            return;

        traverse_head = (traverse_head + 1) % TRAVERSE_QUEUE_SIZE;

        if (traverse_head == traverse_tail)
            Quitf("Context queue overflow in Traverse");

        TraverseCommand& cmd = traverse_queue[traverse_head];

        cmd.Cell = cell;
        cmd.Edge = edge;
        cmd.RenderDepth = render_depth;
        cmd.MinX = minX;
        cmd.MaxX = maxX;
        cmd.MinY = minY;
        cmd.MaxY = maxY;

        cell->VisitTag = VisitTag;
    };

    traverse(StartCell, nullptr, 0, 0.0f, 1.0f, 0.0f, 1.0f);

    if (CullMgr())
        CullMgr()->DeclareCullable(this);

    ++VisitTag;
    StartCell->VisitTag = VisitTag;

    const f32 vp_x = vp.X;
    const f32 vp_y = vp.Y;
    const f32 vp_width = vp.Width;
    const f32 vp_height = vp.Height;
    const f32 vp_proj_left = -vp.ProjRight;
    const f32 vp_proj_top = -vp.ProjBottom;
    const f32 vp_proj_width = vp.ProjRight * 2.0f;
    const f32 vp_proj_height = vp.ProjBottom * 2.0f;
    const f32 vp_proj_near = vp.Near * 2.0f;
    const f32 vp_proj_zz = vp.ProjZZ;
    const f32 vp_proj_zw = vp.ProjZW;
    const Matrix34 proj_view = vp.View;

    do
    {
        traverse_tail = (traverse_tail + 1) % TRAVERSE_QUEUE_SIZE;
        TraverseCommand cmd = traverse_queue[traverse_tail];

        asPortalCell* cell = cmd.Cell;
        asPortalEdge* source_edge = cmd.Edge;

        ++CellTests[CurrentPass];

        if (NumSubPortals[CurrentPass] == MAX_ACTIVE_PORTALS)
        {
            Errorf("Context stack overflow in Traverse");
            break;
        }

        asPortalView* portal = &Portals[CurrentPass][NumSubPortals[CurrentPass]++];

        {
            portal->X = vp_x + vp_width * cmd.MinX;
            portal->Y = vp_y + vp_height * cmd.MinY;
            portal->Width = vp_width * (cmd.MaxX - cmd.MinX);
            portal->Height = vp_height * (cmd.MaxY - cmd.MinY);

            portal->ProjLeft = vp_proj_left + vp_proj_width * cmd.MinX;
            portal->ProjTop = vp_proj_top + vp_proj_height * cmd.MinY;
            portal->ProjRight = vp_proj_left + vp_proj_width * cmd.MaxX;
            portal->ProjBottom = vp_proj_top + vp_proj_height * cmd.MaxY;

            portal->ProjWidth = portal->ProjRight - portal->ProjLeft;
            portal->ProjHeight = portal->ProjBottom - portal->ProjTop;

            f32 inv_width = 1.0f / portal->ProjWidth;
            f32 inv_height = 1.0f / portal->ProjHeight;

            portal->ProjX = inv_width * vp_proj_near;
            portal->ProjY = inv_height * vp_proj_near;
            portal->ProjXZ = (portal->ProjRight + portal->ProjLeft) * inv_width;
            portal->ProjYZ = (portal->ProjTop + portal->ProjBottom) * inv_height;

            portal->Cell = cell;
            portal->Edge = source_edge;
            portal->Texture = nullptr;
            portal->RenderDepth = cmd.RenderDepth;
        }

        const f32 proj_x = portal->ProjX;
        const f32 proj_y = portal->ProjY;
        const f32 proj_xz = portal->ProjXZ;
        const f32 proj_yz = portal->ProjYZ;

        const i32 MAX_EDGES_PER_CELL = 128;
        asPortalEdge* edges[MAX_EDGES_PER_CELL];
        f32 edge_dists[MAX_EDGES_PER_CELL];
        usize num_edges = 0;

        for (PortalLink* link = cell->Edges; link; link = link->Next)
        {
            asPortalEdge* edge = link->Edge;

            if (!edge->IsEnabled())
                continue;

            f32 edge_dist = edge->GetDistance(eye_pos);

            if (!BackfacingPortals && source_edge)
            {
                f32 dist_1 = edge->GetDistance(source_edge->Edges[0]);
                f32 dist_2 = edge->GetDistance(source_edge->Edges[1]);

                if (edge_dist < 0.0f)
                {
                    edge_dist = -edge_dist;
                    dist_1 = -dist_1;
                    dist_2 = -dist_2;
                }

                // We only want to visit portals moving "away" from the camera.
                // Skip this edge if the camera and the source edge are both on the same side of its plane.
                // This helps to both reduce the number of edge tests, and hide more cells around open areas.
                if ((edge_dist > 1.0f) && std::max(dist_1, dist_2) < 0.001f)
                {
                    ++BackfaceEdges[CurrentPass];
                    continue;
                }
            }

            ++CellEdgeTests[CurrentPass];

            ArAssert(num_edges < ARTS_SIZE(edges), "Too many edges!");
            edges[num_edges] = edge;
            edge_dists[num_edges] = edge_dist;
            ++num_edges;
        }

        if (cell->UseEdgeSorting())
        {
            // Sort by distance, closest first.
            // This used for enclosed areas where there could be multiple entrances from one cell to another.
            for (usize i = 0; i < num_edges; ++i)
            {
                usize min_edge = i;
                f32 min_dist = std::abs(edge_dists[i]);

                for (usize j = i + 1; j < num_edges; ++j)
                {
                    if (f32 dist = std::abs(edge_dists[j]); dist < min_dist)
                    {
                        min_edge = j;
                        min_dist = dist;
                    }
                }

                std::swap(edges[i], edges[min_edge]);
                std::swap(edge_dists[i], edge_dists[min_edge]);
            }
        }

        for (usize i = 0; i < num_edges; ++i)
        {
            asPortalEdge* edge = edges[i];
            asPortalCell* other_cell = (cell != edge->Cell1) ? edge->Cell1 : edge->Cell2;

            if (VisitOnce && (other_cell->VisitTag == VisitTag))
                continue;

            if (edge->VisitTag == VisitTag)
            {
                Errorf("This shouldn't happen: EyePos = %f %f %f", eye_pos.x, eye_pos.y, eye_pos.z);
                break;
            }

            f32 edge_dist = edge_dists[i];

            edge->VisitTag = VisitTag;
            edge->PlaneDist = edge->IsOneWay() ? ((cell == edge->Cell1) ? -edge_dist : edge_dist) : 0.0f;

            if (edge->PlaneDist < 0.0f)
                continue;

            u8 clip_any = 0;
            u8 clip_all = 0xFF;

            PodArray<Vector4, 16> verts;
            u8 codes[8];
            i32 num_verts = 0;

            const auto clip_verts = [&](const Vector3* input, i32 count) {
                for (i32 i = 0; i < count; ++i)
                {
                    Vector3 vert = input[i] ^ proj_view;

                    f32 x = (vert.x * proj_x) + (vert.z * proj_xz);
                    f32 y = (vert.y * proj_y) + (vert.z * proj_yz);
                    f32 z = (vert.z * vp_proj_zz) + vp_proj_zw;
                    f32 w = -vert.z;

                    verts[i] = Vector4(x, y, z, w);

                    f32 w_abs = std::abs(w);

                    u8 clip_x = (((w_abs - std::abs(x)) < 0.0f) << ((x < 0.0f) + 0));
                    u8 clip_y = (((w_abs - std::abs(y)) < 0.0f) << ((y < 0.0f) + 2));
                    u8 clip_z = (((w_abs - std::abs(z)) < 0.0f) << ((z < 0.0f) + 4));

                    u8 code = clip_x | clip_y | clip_z;
                    codes[i] = code;

                    clip_any |= code;
                    clip_all &= code;
                }

                num_verts = count;
            };

            clip_verts(edge->Edges, edge->NumEdges);

            if (clip_all)
                continue;

            bool should_clip = true;

            if (edge->IsOpenArea())
            {
                should_clip = false;
            }

            f32 minX = 1.0f;
            f32 maxX = -1.0f;
            f32 minY = 1.0f;
            f32 maxY = -1.0f;

            if (should_clip)
            {
                if (clip_any & (EDGE_CLIP_PX | EDGE_CLIP_NX | EDGE_CLIP_PY | EDGE_CLIP_NY))
                {
                    num_verts = XYClip(verts, num_verts);

                    if (num_verts == 0)
                        continue;
                }

                for (i32 j = 0; j < num_verts; ++j)
                {
                    Vector4 vert = verts[j];

                    if (-vert.z >= vert.w)
                    {
                        should_clip = false;
                        break;
                    }

                    f32 rhw = 1.0f / vert.w;

                    f32 x = vert.x * rhw;
                    f32 y = vert.y * rhw;

                    minX = std::min(minX, x);
                    maxX = std::max(maxX, x);
                    minY = std::min(minY, y);
                    maxY = std::max(maxY, y);
                }
            }

            if (should_clip)
            {
                minX = std::max(minX, -1.0f);
                maxX = std::min(maxX, 1.0f);
                minY = std::max(minY, -1.0f);
                maxY = std::min(maxY, 1.0f);

                if ((maxX - minX) < 0.0001f)
                    continue;

                if ((maxY - minY) < 0.0001f)
                    continue;

                if (edge->IsHalfOpenArea())
                {
                    if (cell == edge->Cell1)
                        minX = -1.0f;
                    else
                        maxX = 1.0f;

                    minY = -1.0f;
                    maxY = 1.0f;
                }
            }
            else
            {
                minX = -1.0f;
                maxX = 1.0f;
                minY = -1.0f;
                maxY = 1.0f;
            }

            ArAssert(minX >= -1.0f && maxX <= 1.0f, "Invalid portal clipping");
            ArAssert(minY >= -1.0f && maxY <= 1.0f, "Invalid portal clipping");

            f32 half_width = (cmd.MaxX - cmd.MinX) * 0.5f;
            f32 half_height = (cmd.MaxY - cmd.MinY) * 0.5f;

            f32 center_x = cmd.MinX + half_width;
            f32 center_y = cmd.MinY + half_height;

            traverse(other_cell, edge, cmd.RenderDepth + 1, center_x + (minX * half_width),
                center_x + (maxX * half_width), center_y + (minY * half_height), center_y + (maxY * half_height));
        }
    } while (traverse_head != traverse_tail);
}

void asPortalWeb::Cull(b32 front_to_back)
{
    i32 nump = NumSubPortals[CurrentPass];

    if (nump == 0)
        return;

    asPortalView* group = Portals[CurrentPass];

    ++VisitTag;

    agiViewParameters& vp = Viewport()->GetParams();
    agiViewParameters old_vp = vp;

    Viewport()->SetWorld(xconst(IDENTITY));

    i32 start = front_to_back ? 0 : (nump - 1);
    i32 dir = front_to_back ? 1 : -1;
    i32 end = front_to_back ? nump : -1;

    for (i32 idx = start; idx != end; idx += dir)
    {
        asPortalView* portal = &group[idx];
        asPortalCell* cell = portal->Cell;

        // mmCellRenderer::Cull checks the VisitTag of cells, but when the rear view mirror is active,
        // the VisitTag will correspond to what the mirror can see, not the main camera. This can cause issues
        // with cells not being properly rendered.
        // Avoid this by updating the visit tag to match the currently active render group.
        // This also helps to fix VisitOnce.
        if (cell->VisitTag == VisitTag)
            continue;

        cell->VisitTag = VisitTag;

        if (portal->Texture)
            continue;

        if (SubClip)
        {
            vp.X = portal->X;
            vp.Y = portal->Y;
            vp.Width = portal->Width;
            vp.Height = portal->Height;
            vp.ProjX = portal->ProjX;
            vp.ProjY = portal->ProjY;
            vp.ProjXZ = portal->ProjXZ;
            vp.ProjYZ = portal->ProjYZ;

            ++vp.MtxSerial;
            ++vp.ViewSerial;
        }

        vp.LeftPlane = ~Vector2(-vp.Near, portal->ProjLeft);
        vp.RightPlane = ~Vector2(vp.Near, -portal->ProjRight);
        vp.TopPlane = ~Vector2(-vp.Near, portal->ProjTop);
        vp.BottomPlane = ~Vector2(vp.Near, -portal->ProjBottom);

        bool draw_cell = true;

#ifdef ARTS_DEV_BUILD
        if (Debug && (portal->Edge != nullptr) && ((PortalDebugIdx == 0) || (PortalDebugIdx == idx)))
        {
            asPortalEdge* edge = portal->Edge;

            {
                DrawBegin(vp.Camera);
                DrawColor(ColYellow);

                f32 from_z = -vp.Near * 1.001f;

                DrawLine(portal->ProjLeft, portal->ProjTop, from_z, portal->ProjRight, portal->ProjBottom, from_z);
                DrawLine(portal->ProjLeft, portal->ProjBottom, from_z, portal->ProjRight, portal->ProjTop, from_z);

                Vector3 label_pos {
                    (portal->ProjLeft + portal->ProjRight) * 0.5f,
                    (portal->ProjTop + portal->ProjBottom) * 0.5f,
                    from_z,
                };

                i32 cell_idx = cell->CellIndex;
                i32 cell1_idx = edge->Cell1->CellIndex;
                i32 cell2_idx = edge->Cell2->CellIndex;

                DrawLabelf(label_pos, "%d->%d"_xconst, (cell_idx == cell1_idx) ? cell2_idx : cell1_idx,
                    (cell_idx == cell1_idx) ? cell1_idx : cell2_idx);

                DrawEnd();
            }

            {
                DrawBegin(xconst(IDENTITY));

                Vector3 color = edge->IsOpenArea() ? ColBlue : edge->IsHalfOpenArea() ? ColOrange : ColRed;
                DrawColor(color);

                for (i32 i = 0, prev = edge->NumEdges - 1; i < edge->NumEdges; ++i)
                {
                    DrawLine(edge->Edges[prev], edge->Edges[i]);
                    prev = i;
                }

                DrawEnd();
            }

            if (edge->Groups)
            {
                DrawBegin(xconst(IDENTITY));
                DrawColor(ColGreen);

                for (i32 i = 0, prev = 3; i < 4; ++i)
                {
                    DrawLine(edge->Groups[prev], edge->Groups[i]);
                    prev = i;
                }

                DrawLine(portal->Edge->Groups[0], portal->Edge->Groups[2]);
                DrawLine(portal->Edge->Groups[1], portal->Edge->Groups[3]);

                DrawEnd();
            }
        }

        if (idx == PortalDebugIdx)
            PortalCurrentIdx = cell->CellIndex;

        if (Debug)
        {
            if (((PortalDebugIdx != 0) && (idx == PortalDebugIdx)) || (cell->CellIndex == PortalShowIdx))
            {
                draw_cell = (static_cast<i32>(Sim()->GetElapsed() * 2.0f) & 1);
            }
        }
#endif

        if (draw_cell)
        {
            cell->CellRenderer->Cull(portal->Edge == nullptr);
        }
    }

    // We modify the viewport parameters for for each cell.
    // When using front_to_back, that means our final viewport will be clipped to some far away cell.
    // So make sure to restore them afterwards.
    vp = old_vp;
    ++vp.MtxSerial;
    ++vp.ViewSerial;
}

void asPortalWeb::Stats()
{
    for (i32 i = 0; i < NUM_PORTAL_PASSES; ++i)
    {
        if (i32 nump = NumSubPortals[i])
        {
            Statsf("%d: %3d portals in %5.2f (%3d edges + %3d backface)", i, nump, PortalUpdateTimer[i] * ut2float,
                CellEdgeTests[i], BackfaceEdges[i]);
        }

        PortalUpdateTimer[i] = 0;
        CellTests[i] = 0;
        CellEdgeTests[i] = 0;
        BackfaceEdges[i] = 0;
    }

    for (i32 i = 0; i < NUM_PORTAL_PASSES; ++i)
    {
        for (i32 j = 0; j < NumSubPortals[i]; ++j)
        {
            asPortalView* portal = &Portals[i][j];
            asPortalEdge* edge = portal->Edge;

            i32 cell = portal->Cell->CellIndex;
            i32 source = -666;
            char edge_type = 'P';

            if (edge)
            {
                i32 cell1 = edge->Cell1->CellIndex;
                i32 cell2 = edge->Cell2->CellIndex;
                source = (cell == cell1) ? cell2 : cell1;

                if (edge->IsOpenArea())
                    edge_type = 'O';
                else if (edge->IsHalfOpenArea())
                    edge_type = 'S';
            }
            else
            {
                edge_type = ' ';
            }

            Statsf("%d(%2d): %4d->%4d %c", i, j, source, cell, edge_type);
        }
    }
}

#ifdef ARTS_DEV_BUILD
void asPortalWeb::AddWidgets(Bank* bank)
{
    asNode::AddWidgets(bank);
    bank->AddToggle("Debug", &Debug);
    bank->AddSlider("DebugIdx", &PortalDebugIdx, 0, MAX_ACTIVE_PORTALS);
    bank->AddSlider("ShowIdx", &PortalShowIdx, 0, 2000);
    bank->AddButton("Lock Target", [this] { PortalShowIdx = PortalCurrentIdx; });
    bank->AddToggle("SubClip", &SubClip);
    bank->AddToggle("NoPortals", &NoPortals);
    bank->AddToggle("VisitOnce", &VisitOnce);
    bank->AddToggle("EnableGroups", &EnableGroups);
    bank->AddToggle("BackfacingPortals", &BackfacingPortals);
    bank->AddSlider("MaxRenderDepth", &MaxRenderDepth, 0, 64);
}
#endif

META_DEFINE_CHILD("asPortalWeb", asPortalWeb, asNode)
{}
