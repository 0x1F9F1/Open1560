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

/*
    mmbangers:active

    0x4CAEE0 | public: __thiscall mmBangerActive::mmBangerActive(void) | ??0mmBangerActive@@QAE@XZ
    0x4CAFC0 | public: virtual __thiscall mmBangerActive::~mmBangerActive(void) | ??1mmBangerActive@@UAE@XZ
    0x4CB030 | public: void __thiscall mmBangerActive::Attach(class mmBangerInstance *) | ?Attach@mmBangerActive@@QAEXPAVmmBangerInstance@@@Z
    0x4CB220 | public: void __thiscall mmBangerActive::Detach(void) | ?Detach@mmBangerActive@@QAEXXZ
    0x4CB280 | public: virtual void __thiscall mmBangerActive::DetachMe(void) | ?DetachMe@mmBangerActive@@UAEXXZ
    0x4CB2A0 | public: virtual void __thiscall mmBangerActive::Update(void) | ?Update@mmBangerActive@@UAEXXZ
    0x4CB350 | public: virtual void __thiscall mmBangerActive::PostUpdate(void) | ?PostUpdate@mmBangerActive@@UAEXXZ
    0x4CB3E0 | public: __thiscall mmBangerActiveManager::mmBangerActiveManager(void) | ??0mmBangerActiveManager@@QAE@XZ
    0x4CB490 | public: virtual __thiscall mmBangerActiveManager::~mmBangerActiveManager(void) | ??1mmBangerActiveManager@@UAE@XZ
    0x4CB4F0 | public: class mmBangerActive * __thiscall mmBangerActiveManager::GetActive(class mmBangerInstance *) | ?GetActive@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    0x4CB520 | public: class mmBangerActive * __thiscall mmBangerActiveManager::Attach(class mmBangerInstance *) | ?Attach@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    0x4CB5F0 | public: void __thiscall mmBangerActiveManager::Detach(class mmBangerActive *) | ?Detach@mmBangerActiveManager@@QAEXPAVmmBangerActive@@@Z
    0x4CB640 | public: virtual void __thiscall mmBangerActiveManager::Update(void) | ?Update@mmBangerActiveManager@@UAEXXZ
    0x4CB720 | public: virtual void __thiscall mmBangerActiveManager::Reset(void) | ?Reset@mmBangerActiveManager@@UAEXXZ
    0x4CB750 | public: virtual void * __thiscall mmBangerActive::`scalar deleting destructor'(unsigned int) | ??_GmmBangerActive@@UAEPAXI@Z
    0x4CB750 | public: virtual void * __thiscall mmBangerActive::`vector deleting destructor'(unsigned int) | ??_EmmBangerActive@@UAEPAXI@Z
    0x4CB780 | public: virtual void * __thiscall mmBangerActiveManager::`vector deleting destructor'(unsigned int) | ??_EmmBangerActiveManager@@UAEPAXI@Z
    0x4CB780 | public: virtual void * __thiscall mmBangerActiveManager::`scalar deleting destructor'(unsigned int) | ??_GmmBangerActiveManager@@UAEPAXI@Z
    0x4CB7B0 | public: virtual class asBound * __thiscall mmBangerActive::GetBound(void) | ?GetBound@mmBangerActive@@UAEPAVasBound@@XZ
    0x4CB7C0 | public: virtual class asInertialCS * __thiscall mmBangerActive::GetICS(void) | ?GetICS@mmBangerActive@@UAEPAVasInertialCS@@XZ
    0x61F800 | const mmBangerActive::`vftable' | ??_7mmBangerActive@@6B@
    0x61F850 | const mmBangerActiveManager::`vftable' | ??_7mmBangerActiveManager@@6B@
    0x642E44 | float ParticleMultiplier | ?ParticleMultiplier@@3MA
    0x706060 | protected: static class mmBangerActiveManager * mmBangerActiveManager::Instance | ?Instance@mmBangerActiveManager@@1PAV1@A
*/

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
    ARTS_EXPORT mmBangerActive();

    // ??_EmmBangerActive@@UAEPAXI@Z
    // ??_GmmBangerActive@@UAEPAXI@Z
    // ??1mmBangerActive@@UAE@XZ
    ARTS_EXPORT ~mmBangerActive() override;

    // ?Attach@mmBangerActive@@QAEXPAVmmBangerInstance@@@Z
    ARTS_EXPORT void Attach(mmBangerInstance* inst);

    // ?Detach@mmBangerActive@@QAEXXZ
    ARTS_EXPORT void Detach();

    // ?DetachMe@mmBangerActive@@UAEXXZ
    ARTS_EXPORT void DetachMe() override;

    // ?GetBound@mmBangerActive@@UAEPAVasBound@@XZ | inline
    ARTS_EXPORT asBound* GetBound() override
    {
        return &Bound;
    }

    // ?GetICS@mmBangerActive@@UAEPAVasInertialCS@@XZ | inline
    ARTS_EXPORT asInertialCS* GetICS() override
    {
        return &ICS;
    }

    // ?PostUpdate@mmBangerActive@@UAEXXZ
    ARTS_EXPORT void PostUpdate() override;

    // ?Update@mmBangerActive@@UAEXXZ
    ARTS_EXPORT void Update() override;

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

    // ??_GmmBangerActiveManager@@UAEPAXI@Z
    // ??_EmmBangerActiveManager@@UAEPAXI@Z
    // ??1mmBangerActiveManager@@UAE@XZ
    ARTS_EXPORT ~mmBangerActiveManager() override;

    // ?Attach@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    ARTS_EXPORT mmBangerActive* Attach(mmBangerInstance* inst);

    // ?Detach@mmBangerActiveManager@@QAEXPAVmmBangerActive@@@Z
    ARTS_EXPORT void Detach(mmBangerActive* active);

    // ?GetActive@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    ARTS_EXPORT mmBangerActive* GetActive(mmBangerInstance* inst);

    // ?Reset@mmBangerActiveManager@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@mmBangerActiveManager@@UAEXXZ
    ARTS_EXPORT void Update() override;

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
