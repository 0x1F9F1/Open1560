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
#include "vector7/matrix44.h"

#define EDGE_CLIP_PX 0x01 // Clip +X
#define EDGE_CLIP_NX 0x02 // Clip -X
#define EDGE_CLIP_PY 0x04 // Clip +Y
#define EDGE_CLIP_NY 0x08 // Clip -Y
#define EDGE_CLIP_PZ 0x10 // Clip +Z
#define EDGE_CLIP_NZ 0x20 // Clip -Z

static const usize MAX_ACTIVE_EDGES = 512;
static const usize TRAVERSE_QUEUE_SIZE = 128;
static const f32 PORTAL_PLANE_FUDGE = 0.0001f;

u16 asPortalWeb::VisitTag = 0;

static b32 VisitOnce = false;
static b32 BackPortals = false;
static b32 EdgeClip = true;

static i32 PortalCurrentIdx = 0;
static i32 PortalShowIdx = 0;
static i32 PortalDebugIdx = 0;

static utimer_t PortalUpdateTimer[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 CellTests[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 CellEdgeTests[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 BackfaceEdges[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 UniqueEdges[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 VertCacheHits[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 TransformedVerts[asPortalWeb::NUM_PORTAL_PASSES] {};
static i32 ClippedVerts[asPortalWeb::NUM_PORTAL_PASSES] {};

template <typename T, typename TestFunc, typename ClipFunc>
static inline i32 Clipper(T* output, T* input, i32 count, TestFunc tester, ClipFunc clipper)
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

static inline i32 ClipNX(Vector4* output, Vector4* input, i32 count)
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

static inline i32 ClipPX(Vector4* output, Vector4* input, i32 count)
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

static inline i32 ClipNY(Vector4* output, Vector4* input, i32 count)
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

static inline i32 ClipPY(Vector4* output, Vector4* input, i32 count)
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

struct ClipBox
{
    f32 MinX {};
    f32 MaxX {};
    f32 MinY {};
    f32 MaxY {};

    ClipBox operator&(ClipBox rhs) const
    {
        return {
            std::max(MinX, rhs.MinX),
            std::min(MaxX, rhs.MaxX),
            std::max(MinY, rhs.MinY),
            std::min(MaxY, rhs.MaxY),
        };
    }

    ClipBox operator|(ClipBox rhs) const
    {
        return {
            std::min(MinX, rhs.MinX),
            std::max(MaxX, rhs.MaxX),
            std::min(MinY, rhs.MinY),
            std::max(MaxY, rhs.MaxY),
        };
    }

    bool IsEmpty(f32 fudge) const
    {
        return (MinX + fudge >= MaxX) || (MinY + fudge >= MaxY);
    }

    bool Extends(ClipBox inner, f32 fudge) const
    {
        return (MinX + fudge <= inner.MinX) || (MaxX - fudge >= inner.MaxX) || (MinY + fudge <= inner.MinY) ||
            (MaxY - fudge >= inner.MaxY);
    }
};

template <typename ValueType, size_t MaxValues, size_t NumBuckets>
struct FixedHashMap
{
    static_assert((NumBuckets & (NumBuckets - 1)) == 0, "NumBuckets must be a power of two!");

    struct Entry
    {
        const void* Key;
        Entry* Next;
        ValueType Value;
    };

    usize NumValues;
    PodArray<Entry, MaxValues> Values;
    PodArray<Entry*, NumBuckets> Buckets;

    inline void Reset()
    {
        NumValues = 0;
        Buckets = {};
    }

    inline usize Size() const
    {
        return NumValues;
    }

    inline ValueType* operator[](usize index)
    {
        return &Values[index].Value;
    }

    static inline u32 HashKey(const void* ptr)
    {
        u32 hash = static_cast<u32>(reinterpret_cast<usize>(ptr));
        hash ^= hash << 13;
        hash ^= hash >> 17;
        hash ^= hash << 5;
        return static_cast<u32>((hash * 0x2545F4914F6CDD1D_u64) >> 32);
    };

    bool Access(const void* key, ValueType*& result)
    {
        usize bucket = HashKey(key) & (NumBuckets - 1);

        for (Entry* entry = Buckets[bucket]; entry; entry = entry->Next)
        {
            if (entry->Key == key)
            {
                result = &entry->Value;
                return true;
            }
        }

        if (NumValues < MaxValues)
        {
            Entry* entry = &Values[NumValues++];
            entry->Key = key;
            entry->Next = Buckets[bucket];
            Buckets[bucket] = entry;
            result = &entry->Value;
        }
        else
        {
            result = nullptr;
        }

        return false;
    }
};

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
    // However, if VisitOnce is enabled, we do not visit a cell multiple times from different edges.
    // This means we cannot rely purely on the frustum bounds for visibility,
    // since multiple cells may have different levels of visiblity into another.
    //
    // Instead, edges can have "open" and "half-open" flags to avoid clipping parts of the frustum.
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

    struct VisitedCell
    {
        asPortalCell* Cell;
        i32 RenderDepth;
        ClipBox Box;
        usize ActiveCommand;
        asPortalEdge* Edges[8];
        usize NumEdges;

        void AddEdge(asPortalEdge* edge)
        {
            if (NumEdges == SIZE_MAX)
                return;

            for (usize i = 0; i < NumEdges; ++i)
            {
                if (Edges[i] == edge)
                    return;
            }

            if (NumEdges == std::size(Edges))
            {
                NumEdges = SIZE_MAX;
                return;
            }

            Edges[NumEdges++] = edge;
        }
    };

    static FixedHashMap<VisitedCell, MAX_ACTIVE_PORTALS, 128> traverse_cells;
    static FixedHashMap<ClipBox, MAX_ACTIVE_EDGES, 128> traverse_edges;
    static VisitedCell* traverse_queue[TRAVERSE_QUEUE_SIZE];

    Matrix44 proj = {
        // clang-format off
        { vp.ProjX,      0.0f,      0.0f,  0.0f},
        {     0.0f,  vp.ProjY,      0.0f,  0.0f},
        {vp.ProjXZ, vp.ProjYZ, vp.ProjZZ, -1.0f},
        {     0.0f,      0.0f, vp.ProjZW,  0.0f},
        // clang-format on
    };
    Matrix44 proj_view;
    proj_view.Dot(vp.View, proj);

    // Compute the screen-space bounding box of this edge.
    const auto clip_edge = [&, proj_view](asPortalEdge* edge) -> ClipBox {
        ClipBox* result = nullptr;

        if (traverse_edges.Access(edge, result))
        {
            ++VertCacheHits[CurrentPass];
            return *result;
        }
        else if (!result)
        {
            Errorf("Context edge overflow in Traverse");
            return {1.0f, -1.0f, 1.0f, -1.0f};
        }

        const Vector3* input = edge->Edges;
        i32 count = edge->NumEdges;
        TransformedVerts[CurrentPass] += count;

        PodArray<Vector4, 16> verts;
        u8 clip_any = 0;
        u8 clip_all = 0xFF;

        for (i32 i = 0; i < count; ++i)
        {
            Vector4 vert = Vector4(input[i].x, input[i].y, input[i].z, 1.0f) ^ proj_view;
            verts[i] = vert;

            f32 w_abs = std::abs(vert.w);
            u8 clip_x = (((w_abs - std::abs(vert.x)) < 0.0f) << ((vert.x < 0.0f) + 0));
            u8 clip_y = (((w_abs - std::abs(vert.y)) < 0.0f) << ((vert.y < 0.0f) + 2));
            u8 clip_z = (((w_abs - std::abs(vert.z)) < 0.0f) << ((vert.z < 0.0f) + 4));

            u8 code = clip_x | clip_y | clip_z;
            clip_any |= code;
            clip_all &= code;
        }

        if (clip_all)
        {
            count = 0;
        }
        else if (EdgeClip && (clip_any & (EDGE_CLIP_PX | EDGE_CLIP_NX | EDGE_CLIP_PY | EDGE_CLIP_NY)))
        {
            count = XYClip(verts, count);
        }

        f32 minX = 1.0f;
        f32 maxX = -1.0f;
        f32 minY = 1.0f;
        f32 maxY = -1.0f;

        for (i32 i = 0; i < count; ++i)
        {
            Vector4 vert = verts[i];

            if (-vert.z >= vert.w)
            {
                minX = -1.0f;
                maxX = 1.0f;
                minY = -1.0f;
                maxY = 1.0f;
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

        *result = {minX, maxX, minY, maxY};

        return *result;
    };

    if (CullMgr())
        CullMgr()->DeclareCullable(this);

    traverse_cells.Reset();
    traverse_edges.Reset();
    usize traverse_head = 0;
    usize traverse_tail = 0;
    ++VisitTag;

    const auto traverse = [&](asPortalCell* cell, asPortalEdge* edge, i32 render_depth, ClipBox box) {
        ArAssert(box.MinX >= -1.0f && box.MaxX <= 1.0f, "Invalid portal clipping");
        ArAssert(box.MinY >= -1.0f && box.MaxY <= 1.0f, "Invalid portal clipping");

        if (render_depth > MaxRenderDepth)
            return;

        VisitedCell* visit = nullptr;

        if (traverse_cells.Access(cell, visit))
        {
            if (!box.Extends(visit->Box, PORTAL_PLANE_FUDGE))
                return;

            visit->RenderDepth = std::min(visit->RenderDepth, render_depth);
            visit->Box = visit->Box | box;
        }
        else if (visit)
        {
            visit->Cell = cell;
            visit->RenderDepth = render_depth;
            visit->Box = box;
            visit->ActiveCommand = SIZE_MAX;
            visit->NumEdges = 0;

            cell->VisitTag = VisitTag;
        }
        else
        {
            Errorf("Context stack overflow in Traverse");
            return;
        }

        usize head = (traverse_head + 1) % TRAVERSE_QUEUE_SIZE;

        if (head == traverse_tail)
        {
            Errorf("Context queue overflow in Traverse");
            return;
        }

        visit->ActiveCommand = head;

        if (edge)
            visit->AddEdge(edge);

        traverse_queue[head] = visit;
        traverse_head = head;
    };

    traverse(StartCell, nullptr, 0, {-1.0f, 1.0f, -1.0f, 1.0f});

    while (traverse_head != traverse_tail)
    {
        traverse_tail = (traverse_tail + 1) % TRAVERSE_QUEUE_SIZE;
        VisitedCell* visit = traverse_queue[traverse_tail];

        if (visit->ActiveCommand == traverse_tail)
            visit->ActiveCommand = SIZE_MAX;
        else
            continue;

        asPortalCell* source_cell = visit->Cell;
        ++CellTests[CurrentPass];

        for (PortalLink* link = source_cell->Edges; link; link = link->Next)
        {
            asPortalEdge* edge = link->Edge;
            asPortalCell* cell = (source_cell != edge->Cell1) ? edge->Cell1 : edge->Cell2;

            if (!edge->IsEnabled())
                continue;

            f32 edge_dist = edge->GetDistance(eye_pos);

            if (edge->IsOneWay())
            {
                if (((source_cell == edge->Cell1) ? -edge_dist : edge_dist) < 0.0f)
                    continue;
            }

            if (VisitOnce)
            {
                if (cell->VisitTag == VisitTag)
                    continue;

                if (edge->VisitTag == VisitTag)
                {
                    Errorf("This shouldn't happen: EyePos = %f %f %f", eye_pos.x, eye_pos.y, eye_pos.z);
                    break;
                }
            }

            ++CellEdgeTests[CurrentPass];

            if (!BackPortals && (visit->NumEdges > 0 && visit->NumEdges <= std::size(visit->Edges)))
            {
                f32 eye_dist = edge_dist;
                f32 dist_sign = 1.0f;

                if (eye_dist < 0.0f)
                {
                    eye_dist = -eye_dist;
                    dist_sign = -dist_sign;
                }

                if (eye_dist > 1.0f)
                {
                    bool backedge = true;

                    for (usize i = 0; i < visit->NumEdges; ++i)
                    {
                        asPortalEdge* source_edge = visit->Edges[i];
                        f32 dist_1 = edge->GetDistance(source_edge->Edges[0]) * dist_sign;
                        f32 dist_2 = edge->GetDistance(source_edge->Edges[1]) * dist_sign;

                        if (std::max(dist_1, dist_2) > PORTAL_PLANE_FUDGE)
                        {
                            backedge = false;
                            break;
                        }
                    }

                    // We only want to visit portals moving "away" from the camera.
                    // Skip this edge if the camera and all source edges are on the same side of its plane.
                    // This helps to both reduce the number of edge tests, and hide more cells around open areas.
                    if (backedge)
                    {
                        ++BackfaceEdges[CurrentPass];
                        continue;
                    }
                }
            }

            edge->VisitTag = VisitTag;

            ClipBox edge_box = visit->Box & clip_edge(edge);

            if (edge_box.IsEmpty(PORTAL_PLANE_FUDGE))
                continue;

            if (VisitOnce)
            {
                if (edge->IsOpenArea() || source_cell->UseEdgeSorting())
                {
                    edge_box = visit->Box;
                }
                else if (edge->IsHalfOpenArea())
                {
                    if (cell == edge->Cell1)
                        edge_box.MaxX = visit->Box.MaxX;
                    else
                        edge_box.MinX = visit->Box.MinX;

                    edge_box.MinY = visit->Box.MinY;
                    edge_box.MaxY = visit->Box.MaxY;
                }

                if (edge_box.IsEmpty(PORTAL_PLANE_FUDGE))
                    continue;
            }

            traverse(cell, edge, visit->RenderDepth + 1, edge_box);
        }
    }

    i32 num_cells = static_cast<i32>(traverse_cells.Size());
    NumSubPortals[CurrentPass] = num_cells;
    UniqueEdges[CurrentPass] = static_cast<i32>(traverse_edges.Size());

    const f32 vp_x = vp.X;
    const f32 vp_y = vp.Y;
    const f32 vp_width = vp.Width;
    const f32 vp_height = vp.Height;
    const f32 vp_proj_left = -vp.ProjRight;
    const f32 vp_proj_top = -vp.ProjBottom;
    const f32 vp_proj_width = vp.ProjRight * 2.0f;
    const f32 vp_proj_height = vp.ProjBottom * 2.0f;
    const f32 vp_proj_near = vp.Near * 2.0f;

    for (i32 i = 0; i < num_cells; ++i)
    {
        asPortalView* portal = &Portals[CurrentPass][i];
        VisitedCell* visit = traverse_cells[i];

        f32 minX = visit->Box.MinX * 0.5f + 0.5f;
        f32 maxX = visit->Box.MaxX * 0.5f + 0.5f;
        f32 minY = visit->Box.MinY * 0.5f + 0.5f;
        f32 maxY = visit->Box.MaxY * 0.5f + 0.5f;

        portal->X = vp_x + vp_width * minX;
        portal->Y = vp_y + vp_height * minY;
        portal->Width = vp_width * (maxX - minX);
        portal->Height = vp_height * (maxY - minY);

        portal->ProjLeft = vp_proj_left + vp_proj_width * minX;
        portal->ProjTop = vp_proj_top + vp_proj_height * minY;
        portal->ProjRight = vp_proj_left + vp_proj_width * maxX;
        portal->ProjBottom = vp_proj_top + vp_proj_height * maxY;

        portal->ProjWidth = portal->ProjRight - portal->ProjLeft;
        portal->ProjHeight = portal->ProjBottom - portal->ProjTop;

        portal->ProjX = vp_proj_near / portal->ProjWidth;
        portal->ProjY = vp_proj_near / portal->ProjHeight;
        portal->ProjXZ = (portal->ProjRight + portal->ProjLeft) / portal->ProjWidth;
        portal->ProjYZ = (portal->ProjTop + portal->ProjBottom) / portal->ProjHeight;

        portal->Cell = visit->Cell;
        portal->Edge = (visit->NumEdges == 1) ? visit->Edges[0] : nullptr;
        portal->Texture = nullptr;
        portal->RenderDepth = visit->RenderDepth;
    }
}

void asPortalWeb::Cull(b32 front_to_back)
{
    i32 nump = NumSubPortals[CurrentPass];

    if (nump == 0)
        return;

    asPortalView* group = Portals[CurrentPass];

    agiViewParameters& vp = Viewport()->GetParams();
    agiViewParameters old_vp = vp;

    Viewport()->SetWorld(xconst(IDENTITY));

    i32 start = front_to_back ? 0 : (nump - 1);
    i32 dir = front_to_back ? 1 : -1;
    i32 end = front_to_back ? nump : -1;

    ++VisitTag;

    // mmCellRenderer::Cull checks the VisitTag of cells, but when the rear view mirror is active,
    // the VisitTag will correspond to what the mirror can see, not the main camera. This can cause issues
    // with cells not being properly rendered.
    // Avoid this by updating the visit tag to match the currently active render group.
    for (i32 i = 0; i < nump; ++i)
        group[i].Cell->VisitTag = VisitTag;

    for (i32 idx = start; idx != end; idx += dir)
    {
        asPortalView* portal = &group[idx];
        asPortalCell* cell = portal->Cell;

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
        if (Debug && ((PortalDebugIdx == 0) || (PortalDebugIdx == idx)))
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

                if (edge)
                {
                    i32 cell1_idx = edge->Cell1->CellIndex;
                    i32 cell2_idx = edge->Cell2->CellIndex;
                    DrawLabelf(label_pos, "%d(%d)"_xconst, cell_idx, (cell_idx == cell1_idx) ? cell2_idx : cell1_idx);
                }
                else
                {
                    DrawLabelf(label_pos, "%d"_xconst, cell_idx);
                }

                DrawEnd();
            }

            if (edge)
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

            if (edge && edge->Groups)
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
            cell->CellRenderer->Cull(idx == 0);
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
            Statsf("%d: %3d portals in %5.2f (%3d cells, %4d edges: %4d back, %d cached, %4d unique, %d verts)", i,
                nump, PortalUpdateTimer[i] * ut2float, CellTests[i], CellEdgeTests[i], BackfaceEdges[i],
                VertCacheHits[i], UniqueEdges[i], TransformedVerts[i]);
        }

        PortalUpdateTimer[i] = 0;
        CellTests[i] = 0;
        CellEdgeTests[i] = 0;
        UniqueEdges[i] = 0;
        BackfaceEdges[i] = 0;
        VertCacheHits[i] = 0;
        TransformedVerts[i] = 0;
    }

    for (i32 i = 0; i < NUM_PORTAL_PASSES; ++i)
    {
        for (i32 j = 0; j < NumSubPortals[i]; ++j)
        {
            asPortalView* portal = &Portals[i][j];
            asPortalEdge* edge = portal->Edge;
            i32 cell = portal->Cell->CellIndex;

            if (edge)
            {
                i32 cell1 = edge->Cell1->CellIndex;
                i32 cell2 = edge->Cell2->CellIndex;
                i32 source = (cell == cell1) ? cell2 : cell1;
                char edge_type = 'P';

                if (edge->IsOpenArea())
                    edge_type = 'O';
                else if (edge->IsHalfOpenArea())
                    edge_type = 'S';

                Statsf("%d(%2d): %4d %c %4d", i, j, cell, edge_type, source);
            }
            else
            {
                Statsf("%d(%2d): %4d", i, j, cell);
            }
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
    bank->AddToggle("VisitOnce", &VisitOnce);
    bank->AddToggle("BackPortals", &BackPortals);
    bank->AddToggle("EdgeClip", &EdgeClip);
    bank->AddSlider("MaxRenderDepth", &MaxRenderDepth, 0, 64);
}
#endif

META_DEFINE_CHILD("asPortalWeb", asPortalWeb, asNode)
{}
