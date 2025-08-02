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

class AudSound;
class mmNetworkCarAudio;

class NetAudioManager final : public asNode
{
public:
    // ??0NetAudioManager@@QAE@XZ
    ARTS_IMPORT NetAudioManager();

    // ??_ENetAudioManager@@UAEPAXI@Z
    // ??_GNetAudioManager@@UAEPAXI@Z
    // ??1NetAudioManager@@UAE@XZ
    ARTS_IMPORT ~NetAudioManager() override;

    // ?AddVehicle@NetAudioManager@@QAEFPAVmmNetworkCarAudio@@@Z
    ARTS_IMPORT i16 AddVehicle(mmNetworkCarAudio* arg1);

    // ?AllocateAddOnEngine@NetAudioManager@@QAEFPAD@Z
    ARTS_IMPORT i16 AllocateAddOnEngine(char* arg1);

    // ?AllocateEngine@NetAudioManager@@QAEPAPAVAudSound@@PAD@Z
    ARTS_IMPORT AudSound** AllocateEngine(char* arg1);

    // ?AllocateEngine@NetAudioManager@@QAEXF@Z
    ARTS_IMPORT void AllocateEngine(i16 arg1);

    // ?AllocateHorn@NetAudioManager@@QAEXF@Z
    ARTS_IMPORT void AllocateHorn(i16 arg1);

    // ?AllocateImpacts@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateImpacts();

    // ?AllocatePoliceSiren@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocatePoliceSiren();

    // ?AllocateReverseBeep@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateReverseBeep();

    // ?AllocateSkids@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateSkids();

    // ?AssignSounds@NetAudioManager@@QAEXPAVmmNetworkCarAudio@@F@Z
    ARTS_IMPORT void AssignSounds(mmNetworkCarAudio* arg1, i16 arg2);

    // ?EchoOff@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // ?EchoOn@NetAudioManager@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // ?FindGreatestDistance@NetAudioManager@@QAEFPAVmmNetworkCarAudio@@@Z
    ARTS_IMPORT i16 FindGreatestDistance(mmNetworkCarAudio* arg1);

    // ?FindUnusedSlot@NetAudioManager@@QAEFXZ
    ARTS_IMPORT i16 FindUnusedSlot();

    // ?GetAvailableDistance@NetAudioManager@@QAEMXZ
    ARTS_IMPORT f32 GetAvailableDistance();

    // ?RemoveVehicle@NetAudioManager@@QAEXPAVmmNetworkCarAudio@@F@Z
    ARTS_IMPORT void RemoveVehicle(mmNetworkCarAudio* arg1, i16 arg2);

    // ?Update@NetAudioManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?AssignAddOnSounds@NetAudioManager@@AAEXPAVmmNetworkCarAudio@@F@Z
    ARTS_IMPORT void AssignAddOnSounds(mmNetworkCarAudio* arg1, i16 arg2);

    u8 gap20[0x54];
};

check_size(NetAudioManager, 0x74);

// ?NETAUDMGRPTR@@3PAVNetAudioManager@@A
ARTS_IMPORT extern NetAudioManager* NETAUDMGRPTR;
