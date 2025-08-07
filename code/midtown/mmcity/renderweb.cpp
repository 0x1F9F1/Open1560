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

#include "agi/pipeline.h"
#include "agi/viewport.h"
#include "data7/metadefine.h"
#include "mmdyna/bndtmpl.h"

static mem::cmd_param PARAM_mirrordist {"mirrordist"};

f32 MirrorDist = 200.0f;

hook_func(INIT_main, [] { MirrorDist = PARAM_mirrordist.get_or(200.0f); });

asRenderWeb::asRenderWeb()
{
    SetNodeFlag(NODE_FLAG_UPDATE_PAUSED);

    Viewport = Pipe()->CreateViewport();
}

asRenderWeb::~asRenderWeb()
{
    Viewport->Release();

    if (HitIdBound)
        HitIdBound->Release();

    delete[] CellArray;
}

#ifdef ARTS_DEV_BUILD
void asRenderWeb::DrawAllBounds()
{
    asPortalView* portals = Portals[CurrentGroup];

    for (i32 i = 0, count = NumSubPortals[CurrentGroup]; i < count; ++i)
    {
        asPortalCell* cell = portals[i].Cell;

        if (mmBoundTemplate* bound = Bounds[cell->CellIndex]; bound && bound->LockIfResident())
        {
            bound->Draw();
            bound->Unlock();
        }
    }
}

void asRenderWeb::AddWidgets(Bank* bank)
{
    bank->AddSlider("HitID", &HitID, 0, 10000, 0.0f); // Read-Only
    bank->AddSlider("ScreenClearY", &ScreenClearY, 0.0f, 10000.0f, 1.0f);
}
#endif

META_DEFINE_CHILD("asRenderWeb", asRenderWeb, asPortalWeb)
{}