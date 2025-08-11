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

// ?VisitOnce@@3HA
ARTS_EXPORT b32 VisitOnce = true;

// ?EnableGroups@@3HA
ARTS_EXPORT b32 EnableGroups = true;

u16 asPortalWeb::VisitTag = 0;

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

void asPortalWeb::Cull(b32 front_to_back)
{
    i32 nump = NumSubPortals[CurrentGroup];

    if (nump == 0)
        return;

    asPortalView* group = Portals[CurrentGroup];
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
