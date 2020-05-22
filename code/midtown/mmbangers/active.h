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
#include "mmai/aiVehicleMGR.h"

class mmBangerActive : public mmPhysEntity
{
    // const mmBangerActive::`vftable' @ 0x61F800

public:
    // 0x4CAEE0 | ??0mmBangerActive@@QAE@XZ
    mmBangerActive();

    // 0x4CB750 | ??_EmmBangerActive@@UAEPAXI@Z
    // 0x4CAFC0 | ??1mmBangerActive@@UAE@XZ
    ~mmBangerActive() override;

    // 0x4CB030 | ?Attach@mmBangerActive@@QAEXPAVmmBangerInstance@@@Z
    void Attach(class mmBangerInstance* arg1);

    // 0x4CB220 | ?Detach@mmBangerActive@@QAEXXZ
    void Detach();

    // 0x4CB280 | ?DetachMe@mmBangerActive@@UAEXXZ
    void DetachMe() override;

    // 0x4CB7B0 | ?GetBound@mmBangerActive@@UAEPAVasBound@@XZ
    class asBound* GetBound() override;

    // 0x4CB7C0 | ?GetICS@mmBangerActive@@UAEPAVasInertialCS@@XZ
    class asInertialCS* GetICS() override;

    // 0x4CB350 | ?PostUpdate@mmBangerActive@@UAEXXZ
    void PostUpdate() override;

    // 0x4CB2A0 | ?Update@mmBangerActive@@UAEXXZ
    void Update() override;
};

check_size(mmBangerActive, 0x27C);

class mmBangerActiveManager : public asNode
{
    // const mmBangerActiveManager::`vftable' @ 0x61F850

public:
    // 0x4CB3E0 | ??0mmBangerActiveManager@@QAE@XZ
    mmBangerActiveManager();

    // 0x4CB780 | ??_GmmBangerActiveManager@@UAEPAXI@Z
    // 0x4CB490 | ??1mmBangerActiveManager@@UAE@XZ
    ~mmBangerActiveManager() override;

    // 0x4CB520 | ?Attach@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    class mmBangerActive* Attach(class mmBangerInstance* arg1);

    // 0x4CB5F0 | ?Detach@mmBangerActiveManager@@QAEXPAVmmBangerActive@@@Z
    void Detach(class mmBangerActive* arg1);

    // 0x4CB4F0 | ?GetActive@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    class mmBangerActive* GetActive(class mmBangerInstance* arg1);

    // 0x4CB720 | ?Reset@mmBangerActiveManager@@UAEXXZ
    void Reset() override;

    // 0x4CB640 | ?Update@mmBangerActiveManager@@UAEXXZ
    void Update() override;

protected:
    // 0x706060 | ?Instance@mmBangerActiveManager@@1PAV1@A
    static inline extern_var(0x706060, class mmBangerActiveManager*, Instance);
};

check_size(mmBangerActiveManager, 0x0);

// 0x642E44 | ?ParticleMultiplier@@3MA
inline extern_var(0x642E44, f32, ParticleMultiplier);
