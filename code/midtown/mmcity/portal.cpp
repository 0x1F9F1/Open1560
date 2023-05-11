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

void asPortalWeb::CullHack(b32 front_to_back)
{
    // mmCellRenderer::Cull checks the VisitTag of cells, but when the rear view mirror is active,
    // the VisitTag will correspond to what the mirror can see, not the main camera. This can cause issues
    // with cells not being properly rendered.
    // Avoid this by updating the visit tag to match the currently active render group.
    ++VisitTag;

    for (i32 i = 0; i < NumSubPortals[CurrentGroup]; ++i)
        Portals[CurrentGroup][i].Cell->VisitTag = VisitTag;

    Cull(front_to_back);
}

void asPortalWeb::DeleteEdge(asPortalEdge* /*arg1*/)
{}

asPortalCell* LookupCell(char* /*arg1*/)
{
    return nullptr;
}

asPortalCell* LookupEdge(char* /*arg1*/)
{
    return nullptr;
}

hook_func(INIT_main, [] {
    for (u32 addr : {0x4911C2, 0x49128A, 0x49130E, 0x491354, 0x49137D, 0x4913D5})
        create_hook("", "", addr, &asPortalWeb::CullHack, hook_type::call);
});
