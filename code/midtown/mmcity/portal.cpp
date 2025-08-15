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
#include "data7/metadefine.h"
#include "dyna7/gfx.h"

u16 asPortalWeb::VisitTag = 0;

static b32 VisitOnce = true;
static b32 EnableGroups = true;

static i32 PortalCurrentIdx = 0;
static i32 PortalShowIdx = 0;
static i32 PortalDebugIdx = 0;

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

#define EDGE_CLIP_NX 0x01 // Clip -X
#define EDGE_CLIP_PX 0x02 // Clip +X
#define EDGE_CLIP_NY 0x04 // Clip -Y
#define EDGE_CLIP_PY 0x08 // Clip +Y
#define EDGE_CLIP_NZ 0x10 // Clip -Z
#define EDGE_CLIP_PZ 0x20 // Clip +Z

void asPortalWeb::Update()
{
    const agiViewParameters& vp = ViewParams();
    Vector3 near = vp.Camera.m3 + vp.Camera.m2 * -vp.Near;
    StartCell = GetStartCell(near, StartCell, 0);

    if (!StartCell)
    {
        Errorf("asPortalWeb::GetStartCell failed.");
        return;
    }

    static const usize TRAVERSE_QUEUE_SIZE = 128;
    asPortalView* portals[TRAVERSE_QUEUE_SIZE];
    usize traverse_head = 1;
    usize traverse_tail = 0;

    {
        asPortalView* portal = Portals[CurrentPass];
        NumSubPortals[CurrentPass] = 1;

        portal->X = vp.X;
        portal->Y = vp.Y;
        portal->Width = vp.Width;
        portal->Height = vp.Height;
        portal->ProjX = vp.ProjX;
        portal->ProjY = vp.ProjY;
        portal->ProjXZ = 0.0f;
        portal->ProjYZ = 0.0f;
        portal->ProjLeft = -vp.ProjRight;
        portal->ProjTop = -vp.ProjBottom;
        portal->ProjRight = vp.ProjRight;
        portal->ProjBottom = vp.ProjBottom;
        portal->ProjWidth = vp.ProjRight * 2.0f;
        portal->ProjHeight = vp.ProjBottom * 2.0f;
        portal->Cell = StartCell;
        portal->Edge = nullptr;
        portal->Texture = nullptr;
        portal->RenderDepth = 0;

        portals[1] = portal;
    }

    Vector3 eye_pos = vp.View.m3;
    f32 ndc_near = vp.Near * 2.0f;

    if (CullMgr())
        CullMgr()->DeclareCullable(this);

    ++VisitTag;
    StartCell->VisitTag = VisitTag;

    do
    {
        traverse_tail = (traverse_tail + 1) % TRAVERSE_QUEUE_SIZE;
        asPortalView* portal = portals[traverse_tail];

        if (portal->RenderDepth > MaxRenderDepth)
            continue;

        const i32 MAX_EDGES_PER_CELL = 128;
        asPortalEdge* edges[MAX_EDGES_PER_CELL];
        f32 edge_dists[MAX_EDGES_PER_CELL];
        usize num_edges = 0;

        asPortalCell* cell = portal->Cell;

        for (PortalLink* link = cell->Edges; link; link = link->Next)
        {
            ArAssert(num_edges < ARTS_SIZE(edges), "Too many edges!");

            asPortalEdge* edge = link->Edge;
            edges[num_edges] = edge;
            edge_dists[num_edges] = edge->GetDistance(eye_pos);
            ++num_edges;
        }

        if (cell->HasFlag1())
        {
            // Horrible inefficient sorting!
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

            if (!edge->IsEnabled())
                continue;

            asPortalCell* other_cell = (cell != edge->Cell1) ? edge->Cell1 : edge->Cell2;

            if (VisitOnce && (other_cell->VisitTag == VisitTag))
                continue;

            if (edge->VisitTag == VisitTag)
            {
                Errorf("This shouldn't happen: EyePos = %f %f %f", eye_pos.x, eye_pos.y, eye_pos.z);
                return;
            }

            f32 edge_dist = edge_dists[i];

            edge->VisitTag = VisitTag;
            edge->PlaneDist = edge->HasFlag8() ? ((cell == edge->Cell1) ? -edge_dist : edge_dist) : 0.0f;

            if (edge->PlaneDist < 0.0f)
                continue;

            u8 clip_any = 0;
            u8 clip_all = 0xFF;

            Vector4 verts[8];
            u8 codes[8];
            i32 num_verts = 0;

            const auto clip_verts = [&](const Vector3* input, i32 count) {
                for (i32 i = 0; i < count; ++i)
                {
                    Vector3 vert = input[i] ^ vp.View;

                    f32 x = (vert.x * portal->ProjX) + (vert.z * portal->ProjXZ);
                    f32 y = (vert.y * portal->ProjY) + (vert.z * portal->ProjYZ);
                    f32 z = (vert.z * vp.ProjZZ) + vp.ProjZW;
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

            if (clip_any & EDGE_CLIP_PZ)
            {
                should_clip = false;
            }
            else if (Vector3* group = EnableGroups ? edge->Groups : nullptr)
            {
                clip_verts(group, 4);

                if (clip_any & EDGE_CLIP_PZ)
                {
                    should_clip = false;
                }
            }
            else if (edge->IsOpenArea())
            {
                should_clip = false;
            }

            f32 minX = 1.0f;
            f32 maxX = -1.0f;
            f32 minY = 1.0f;
            f32 maxY = -1.0f;

            if (should_clip)
            {
                for (i32 j = 0; j < num_verts; ++j)
                {
                    Vector4 vert = verts[j];
                    u8 code = codes[j];
                    f32 rhw = 1.0f / vert.w;

                    if (code & EDGE_CLIP_PX)
                    {
                        minX = -1.0f;
                    }
                    else if (code & EDGE_CLIP_NX)
                    {
                        maxX = 1.0f;
                    }
                    else
                    {
                        f32 x = vert.x * rhw;
                        vert.x = x;
                        minX = std::min(minX, x);
                        maxX = std::max(maxX, x);
                    }

                    if (code & EDGE_CLIP_PY)
                    {
                        minY = -1.0f;
                    }
                    else if (code & EDGE_CLIP_NY)
                    {
                        maxY = 1.0f;
                    }
                    else
                    {
                        f32 y = vert.y * rhw;
                        vert.y = y;
                        minY = std::min(minY, y);
                        maxY = std::max(maxY, y);
                    }
                }
            }
            else
            {
                minX = -1.0;
                maxX = 1.0;
                minY = -1.0;
                maxY = 1.0;
            }

            if ((maxX - minX) < 0.001f)
                continue;

            if ((maxY - minY) < 0.001f)
                continue;

            if (edge->IsSemiOpenArea())
            {
                if (cell == edge->Cell1)
                    minX = -1.0;
                else
                    maxX = 1.0;
            }

            ArAssert(minX >= -1.0f && maxX <= 1.0f, "Invalid portal clipping");
            ArAssert(minY >= -1.0f && maxY <= 1.0f, "Invalid portal clipping");

            if (NumSubPortals[CurrentPass] == MAX_ACTIVE_PORTALS)
            {
                Errorf("Context stack overflow in Traverse");
                continue;
            }

            asPortalView* sub_portal = &Portals[CurrentPass][NumSubPortals[CurrentPass]++];

            sub_portal->Cell = other_cell;
            sub_portal->Edge = edge;
            sub_portal->RenderDepth = portal->RenderDepth + 1;
            other_cell->VisitTag = VisitTag;
            edge->PlaneDist = -1.0f;

            if (DisableTextures || !edge->Texture || (edge_dist >= -390.0f))
            {
                sub_portal->Texture = nullptr;

                traverse_head = (traverse_head + 1) % TRAVERSE_QUEUE_SIZE;
                if (traverse_head == traverse_tail)
                    Quitf("Context queue overflow in Traverse");

                portals[traverse_head] = sub_portal;

                f32 unit_width = (maxX - minX) * 0.5f;
                f32 unit_height = (maxY - minY) * 0.5f;

                f32 unit_minX = (minX * 0.5f) + 0.5f;
                f32 unit_minY = (minY * 0.5f) + 0.5f;

                f32 unit_maxX = (maxX * 0.5f) - 0.5f;
                f32 unit_maxY = (maxY * 0.5f) - 0.5f;

                sub_portal->X = portal->X + portal->Width * unit_minX;
                sub_portal->Y = portal->Y + portal->Height * unit_minY;
                sub_portal->Width = portal->Width * unit_width;
                sub_portal->Height = portal->Height * unit_height;
                sub_portal->ProjLeft = portal->ProjLeft + portal->ProjWidth * unit_minX;
                sub_portal->ProjTop = portal->ProjTop + portal->ProjHeight * unit_minY;
                sub_portal->ProjRight = portal->ProjRight + portal->ProjWidth * unit_maxX;
                sub_portal->ProjBottom = portal->ProjBottom + portal->ProjHeight * unit_maxY;
                sub_portal->ProjWidth = portal->ProjWidth * unit_width;
                sub_portal->ProjHeight = portal->ProjHeight * unit_height;

                f32 inv_width = 1.0f / (sub_portal->ProjRight - sub_portal->ProjLeft);
                f32 inv_height = 1.0f / (sub_portal->ProjBottom - sub_portal->ProjTop);

                sub_portal->ProjX = inv_width * ndc_near;
                sub_portal->ProjY = inv_height * ndc_near;
                sub_portal->ProjXZ = (sub_portal->ProjRight + sub_portal->ProjLeft) * inv_width;
                sub_portal->ProjYZ = (sub_portal->ProjTop + sub_portal->ProjBottom) * inv_height;
            }
            else
            {
                sub_portal->Texture = edge->Texture;
            }
        }
    } while (traverse_head != traverse_tail);
}

void asPortalWeb::Cull(b32 front_to_back)
{
    i32 nump = NumSubPortals[CurrentPass];

    if (nump == 0)
        return;

    asPortalView* group = Portals[CurrentPass];
    asPortalView* portal = &group[front_to_back ? -1 : nump];
    asPortalView* end = &group[front_to_back ? nump - 1 : 0];

    {
        // mmCellRenderer::Cull checks the VisitTag of cells, but when the rear view mirror is active,
        // the VisitTag will correspond to what the mirror can see, not the main camera. This can cause issues
        // with cells not being properly rendered.
        // Avoid this by updating the visit tag to match the currently active render group.
        ++VisitTag;

        for (i32 i = 0; i < nump; ++i)
            group[i].Cell->VisitTag = VisitTag;
    }

    agiViewParameters& vp = Viewport()->GetParams();
    Viewport()->SetWorld(xconst(IDENTITY));

    i32 idx = 0;
    i32 dir = front_to_back ? 1 : -1;

    // NOTE: Always draws at least 1 cell
    do
    {
        portal += dir;
        ++idx;

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

                i32 cell_idx = portal->Cell->CellIndex;
                i32 cell1_idx = edge->Cell1->CellIndex;
                i32 cell2_idx = edge->Cell2->CellIndex;

                DrawLabelf(label_pos, "%d->%d"_xconst, (cell_idx == cell1_idx) ? cell2_idx : cell1_idx,
                    (cell_idx == cell1_idx) ? cell1_idx : cell2_idx);

                DrawEnd();
            }

            {
                DrawBegin(xconst(IDENTITY));
                DrawColor(ColRed);

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
            PortalCurrentIdx = portal->Cell->CellIndex;

        if (!Debug || ((idx != PortalDebugIdx) && (portal->Cell->CellIndex != PortalShowIdx)) ||
            (static_cast<i32>(Sim()->GetElapsed() * 2.0f) & 1))
#endif
        {
            portal->Cell->CellRenderer->Cull(portal->Edge == nullptr);
        }
    } while (portal != end);
}

#ifdef ARTS_DEV_BUILD
void asPortalWeb::AddWidgets(Bank* bank)
{
    asNode::AddWidgets(bank);
    bank->AddToggle("Debug", &Debug);
    bank->AddSlider("DebugIdx", &PortalDebugIdx, 0, 100);
    bank->AddSlider("ShowIdx", &PortalShowIdx, 0, 300);
    bank->AddButton("Lock Target", [this] { PortalShowIdx = PortalCurrentIdx; });
    bank->AddToggle("SubClip", &SubClip);
    bank->AddToggle("NoPortals", &NoPortals);
    bank->AddToggle("VisitOnce", &VisitOnce);
    bank->AddToggle("EnableGroups", &EnableGroups);
    bank->AddSlider("MaxRenderDepth", &MaxRenderDepth, 0, 64);
}
#endif

META_DEFINE_CHILD("asPortalWeb", asPortalWeb, asNode)
{}
