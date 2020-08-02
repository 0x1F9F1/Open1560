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

define_dummy_symbol(arts7_sim);

#include "sim.h"

#include "agi/mtllib.h"
#include "agi/physlib.h"
#include "agi/texlib.h"
#include "cullmgr.h"
#include "data7/metadefine.h"
#include "eventq7/key_codes.h"
#include "midgets.h"
#include "stream/vfsystem.h"

void InitBank(i32 /*arg1*/, char** /*arg2*/)
{}

// 0x523510 | ?IsValidPointer@@YAHPAXIH@Z
ARTS_IMPORT /*static*/ i32 IsValidPointer(void* arg1, u32 arg2, i32 arg3);

// 0x521C20 | ?QuietPrinter@@YAXHPBDPAD@Z
ARTS_IMPORT /*static*/ void QuietPrinter(i32 arg1, char const* arg2, char* arg3);

void asSimulation::Widgets()
{
    Timer timer;

    for (eqEvent event; widgets_queue_.Pop(&event);)
    {
        if ((event.Common.Type == eqEventType::Keyboard) && (event.Key.Modifiers == (EQ_KMOD_DOWN | EQ_KMOD_CTRL)) &&
            (event.Key.VirtualKey == EQ_VK_M) && !no_debug_)
        {
            if (MIDGETSPTR->IsOpen() && MIDGETSPTR->GetVisibleLines() == 5)
            {
                MIDGETSPTR->SetVisibleLines(21);
            }
            else
            {
                MIDGETSPTR->SetVisibleLines(5);
                MIDGETSPTR->Toggle();
            }
        }
    }

    stats_.Widgets += timer.Time();
}

const char* asNode::VerifyTree()
{
    if (!IsValidPointer(this, sizeof(*this), true))
        return "Bad 'this'";

    if (!IsValidPointer(*reinterpret_cast<void**>(this), 8 * sizeof(void*), false))
        return "Bad virtual table";

    if (!IsValidPointer(parent_node_, sizeof(*this), 1) && (this != parent_node_))
        return "Bad parent";

    const char* msg = nullptr;

    i32 i = 1;
    for (asNode* n = child_node_; n; n = n->next_node_, ++i)
    {
        msg = n->VerifyTree();

        if (msg)
        {
            Errorf("Kid %d(%p) of type %s name %s: %s", i, n, GetNodeType(), node_name_.get(), msg);
            break;
        }
    }

    return msg;
}

META_DEFINE_CHILD("asSimulation", asSimulation, asNode)
{}

asSimulation::~asSimulation()
{
    ARTSPTR = nullptr;

    if (MIDGETSPTR)
        delete MIDGETSPTR;

    if (CULLMGR)
    {
        delete CULLMGR;
        CULLMGR = nullptr;
    }

    delete[] vector_colors_;
    delete[] vector_ends_;
    delete[] vector_starts_;

    agiMtlLib.Kill();
    agiTexLib.Kill();
    agiPhysLib.Kill();

    if (VFS)
    {
        delete VFS;
        VFS = nullptr;
    }
}
