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

define_dummy_symbol(mmgame_interface);

#include "interface.h"

#include "agi/rsys.h"
#include "agisw/swrend.h"
#include "agiworld//quality.h"
#include "agiworld/texsheet.h"
#include "data7/memstat.h"
#include "data7/timer.h"
#include "memory/allocator.h"
#include "midtown.h"
#include "mmaudio/manager.h"
#include "mmcar/carsim.h"
#include "mmcityinfo/state.h"
#include "mmcityinfo/vehlist.h"
#include "mmnetwork/network.h"
#include "mmwidget/manager.h"

// ?IsModemDialin@@YA_NXZ
ARTS_IMPORT /*static*/ bool IsModemDialin();

// ?ZoneWatcher@@YGKPAX@Z
ARTS_IMPORT /*static*/ ulong ARTS_STDCALL ZoneWatcher(void* arg1);

mmInterface::~mmInterface()
{
    agiCurState.SetTexFilter(agiRQ.TexFilter ? agiTexFilter::Trilinear : agiTexFilter::Bilinear);
    swSetInterlace(MMSTATE.Interlaced);
    EnableSmoke = ForceSmoke | !agiCurState.GetSoftwareRendering();
    ALLOCATOR.SanityCheck();

    {
        ARTS_MEM_STAT("mmInterface Destructor");

        AudMgr()->DeallocateUIADF();
        NETMGR.Deallocate();

        if (MenuManager::Instance)
        {
            delete MenuManager::Instance;

            MenuManager::Instance = nullptr;
        }

        std::memset(PlayerIDs, 0, sizeof(PlayerIDs));

        ALLOCATOR.SanityCheck();
    }

    TEXSHEET.Kill();

    if (VehicleListPtr)
    {
        delete VehicleListPtr;
        VehicleListPtr = nullptr;
    }

    ALLOCATOR.SanityCheck();
}

void mmInterface::SetStateRace(i32 /*arg1*/)
{}

void ReportTimeAlloc(f32 time)
{
    Displayf(
        "*********Load time %f = %f seconds, %dK Allocated", time, LoadTimer.Time(), ALLOCATOR.GetHeapUsed() >> 10);
}

ARTS_IMPORT extern b32 JoinViaZone;

void mmInterface::InitLobby()
{
    NETMGR.InitializeLobby(8, false);

    if (!JoinViaZone)
    {
        if (NETMGR.JoinLobbySession())
        {
            NETMGR.SetSysCallback([this](void* param) { MessageCallback(nullptr, param); });
            NETMGR.SetAppCallback([this](void* param) { MessageCallback2(nullptr, param); });
        }
        else
        {
            MMSTATE.NetworkStatus = 0;
            JoinViaZone = true;
        }
    }
}
