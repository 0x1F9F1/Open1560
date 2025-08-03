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

#pragma once

#include "arts7/node.h"
#include "mmeffects/ptx.h"
#include "mmphysics/bound.h"
#include "mmphysics/entity.h"
#include "mmphysics/inertia.h"

#ifndef MAX_ACTIVE_BANGERS
#    define MAX_ACTIVE_BANGERS 32
#endif

class mmBangerInstance;

class mmBangerActive final : public mmPhysEntity
{
public:
    // ??0mmBangerActive@@QAE@XZ
    mmBangerActive();

    // ??1mmBangerActive@@UAE@XZ
    ~mmBangerActive() override;

    // ?Attach@mmBangerActive@@QAEXPAVmmBangerInstance@@@Z
    void Attach(mmBangerInstance* inst);

    // ?Detach@mmBangerActive@@QAEXXZ
    void Detach();

    // ?DetachMe@mmBangerActive@@UAEXXZ
    void DetachMe() override;

    // ?GetBound@mmBangerActive@@UAEPAVasBound@@XZ | inline
    asBound* GetBound() override
    {
        return &Bound;
    }

    // ?GetICS@mmBangerActive@@UAEPAVasInertialCS@@XZ | inline
    asInertialCS* GetICS() override
    {
        return &ICS;
    }

    // ?PostUpdate@mmBangerActive@@UAEXXZ
    void PostUpdate() override;

    // ?Update@mmBangerActive@@UAEXXZ
    void Update() override;

    i32 Index {-1};
    asInertialCS ICS {};
    asBound Bound {};
    mmBangerInstance* Target {};
    asParticles Particles {};
    f32 Age {}; // Unused in MM1
};

check_size(mmBangerActive, 0x27C);

class mmBangerActiveManager final : public asNode
{
public:
    // ??0mmBangerActiveManager@@QAE@XZ
    ARTS_EXPORT mmBangerActiveManager();

    // ??1mmBangerActiveManager@@UAE@XZ
    ARTS_EXPORT ~mmBangerActiveManager() override;

    // ?Attach@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    mmBangerActive* Attach(mmBangerInstance* inst);

    // ?Detach@mmBangerActiveManager@@QAEXPAVmmBangerActive@@@Z
    void Detach(mmBangerActive* active);

    // ?GetActive@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    ARTS_EXPORT mmBangerActive* GetActive(mmBangerInstance* inst);

    // ?Reset@mmBangerActiveManager@@UAEXXZ
    void Reset() override;

    // ?Update@mmBangerActiveManager@@UAEXXZ
    void Update() override;

    friend mmBangerActiveManager* BangerActiveMgr();

protected:
    // ?Instance@mmBangerActiveManager@@1PAV1@A
    ARTS_EXPORT static mmBangerActiveManager* Instance;

    mmBangerActive* Active[MAX_ACTIVE_BANGERS] {};
    mmBangerActive Bangers[MAX_ACTIVE_BANGERS] {};
    i32 NumActive {};
};

check_size(mmBangerActiveManager, 0x5024);

inline mmBangerActiveManager* BangerActiveMgr()
{
    return mmBangerActiveManager::Instance;
}

// ?ParticleMultiplier@@3MA
ARTS_IMPORT extern f32 ParticleMultiplier;
