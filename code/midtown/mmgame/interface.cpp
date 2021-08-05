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

#include "data7/timer.h"
#include "memory/allocator.h"
#include "midtown.h"
#include "mmcityinfo/state.h"
#include "mmnetwork/network.h"

// ?IsModemDialin@@YA_NXZ
ARTS_IMPORT /*static*/ bool IsModemDialin();

// ?ZoneWatcher@@YGKPAX@Z
ARTS_IMPORT /*static*/ ulong ARTS_STDCALL ZoneWatcher(void* arg1);

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
            NETMGR.SetSysCallback(MFA2(mmInterface::MessageCallback, this, nullptr));
            NETMGR.SetAppCallback(MFA2(mmInterface::MessageCallback2, this, nullptr));
        }
        else
        {
            MMSTATE.NetworkStatus = 0;
            JoinViaZone = true;
        }
    }
}
