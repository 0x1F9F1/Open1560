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

define_dummy_symbol(mmbangers_active);

#include "active.h"

#include "arts7/sim.h"
#include "banger.h"
#include "data.h"
#include "mmphysics/phys.h"

void mmBangerActiveManager::Update()
{
    // TODO: Is there a better way to avoid updating while paused?
    if (ARTSPTR->IsPaused())
        return;

    for (i32 i = 0; i < NumActive; ++i)
    {
        mmBangerActive* banger = Active[i];
        mmBangerInstance* target = banger->Target;
        ArAssert(target->SizeOf() == sizeof(mmHitBangerInstance), "Invalid Banger");

        i16 banger_type = target->GetData()->CollisionType;

        if (banger_type == BANGER_COLLISION_TYPE_1)
        {
            banger->Update();
            banger->PostUpdate();
        }
        else
        {
            i32 mover_type = (banger_type == BANGER_COLLISION_TYPE_6) ? MOVER_TYPE_1 : MOVER_TYPE_2;
            i32 mover_flags = MOVER_FLAG_ACTIVE;

            if (banger_type != BANGER_COLLISION_TYPE_2)
                mover_flags |= MOVER_FLAG_COLLIDE_TERRAIN | MOVER_FLAG_COLLIDE_MOVERS;

            PHYS.DeclareMover(banger->Target, mover_type, mover_flags);
        }
    }
}
