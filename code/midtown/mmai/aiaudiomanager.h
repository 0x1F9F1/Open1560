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

class aiVehicleAmbient;
class aiVehicleOpponent;
class aiVehiclePolice;
class AudSound;

class aiAudioManager final : public asNode
{
public:
    // ??0aiAudioManager@@QAE@XZ
    ARTS_IMPORT aiAudioManager();

    // ??1aiAudioManager@@UAE@XZ
    ARTS_IMPORT ~aiAudioManager() override;

    // ?AddVehicle@aiAudioManager@@QAEFPAVaiVehicleAmbient@@@Z
    ARTS_IMPORT i16 AddVehicle(aiVehicleAmbient* arg1);

    // ?AddVehicle@aiAudioManager@@QAEFPAVaiVehicleOpponent@@@Z
    ARTS_IMPORT i16 AddVehicle(aiVehicleOpponent* arg1);

    // ?AddVehicle@aiAudioManager@@QAEFPAVaiVehiclePolice@@@Z
    ARTS_IMPORT i16 AddVehicle(aiVehiclePolice* arg1);

    // ?AllocateAddOnEngine@aiAudioManager@@QAEFPAD@Z
    ARTS_IMPORT i16 AllocateAddOnEngine(char* arg1);

    // ?AllocateAmbients@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateAmbients();

    // ?AllocateCopVoice@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateCopVoice();

    // ?AllocateEngine@aiAudioManager@@QAEPAPAVAudSound@@PAD@Z
    ARTS_IMPORT AudSound** AllocateEngine(char* arg1);

    // ?AllocateEngine@aiAudioManager@@QAEXFF@Z
    ARTS_IMPORT void AllocateEngine(i16 arg1, i16 arg2);

    // ?AllocateHorns@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateHorns();

    // ?AllocateImpacts@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateImpacts();

    // ?AllocateOpponents@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateOpponents();

    // ?AllocatePolice@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocatePolice();

    // ?AllocateReverseBeep@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateReverseBeep();

    // ?AllocateSkids@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateSkids();

    // ?AllocateVoices@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateVoices();

    // ?AssignAddOnSounds@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    ARTS_IMPORT void AssignAddOnSounds(aiVehicleOpponent* arg1, i16 arg2);

    // ?AssignSounds@aiAudioManager@@QAEXPAVaiVehicleAmbient@@F@Z
    ARTS_IMPORT void AssignSounds(aiVehicleAmbient* arg1, i16 arg2);

    // ?AssignSounds@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    ARTS_IMPORT void AssignSounds(aiVehicleOpponent* arg1, i16 arg2);

    // ?AssignSounds@aiAudioManager@@QAEXPAVaiVehiclePolice@@F@Z
    ARTS_IMPORT void AssignSounds(aiVehiclePolice* arg1, i16 arg2);

    // ?EchoOff@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // ?EchoOn@aiAudioManager@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehicleAmbient@@@Z
    ARTS_IMPORT i16 FindGreatestDistance(aiVehicleAmbient* arg1);

    // ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehicleOpponent@@@Z
    ARTS_IMPORT i16 FindGreatestDistance(aiVehicleOpponent* arg1);

    // ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehiclePolice@@@Z
    ARTS_IMPORT i16 FindGreatestDistance(aiVehiclePolice* arg1);

    // ?FindUnusedSlot@aiAudioManager@@QAEFXZ
    ARTS_IMPORT i16 FindUnusedSlot();

    // ?GetClosestCop@aiAudioManager@@QAEFXZ
    ARTS_IMPORT i16 GetClosestCop();

    // ?LoadCopVoice@aiAudioManager@@QAEXXZ
    ARTS_IMPORT void LoadCopVoice();

    // ?PlayCopVoice@aiAudioManager@@QAEFXZ
    ARTS_IMPORT i16 PlayCopVoice();

    // ?QueueInCopVoice@aiAudioManager@@QAEFM@Z
    ARTS_IMPORT i16 QueueInCopVoice(f32 arg1);

    // ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehicleAmbient@@F@Z
    ARTS_IMPORT void RemoveVehicle(aiVehicleAmbient* arg1, i16 arg2);

    // ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    ARTS_IMPORT void RemoveVehicle(aiVehicleOpponent* arg1, i16 arg2);

    // ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehiclePolice@@F@Z
    ARTS_IMPORT void RemoveVehicle(aiVehiclePolice* arg1, i16 arg2);

    // ?UnassignFurthestAmbient@aiAudioManager@@QAEFXZ
    ARTS_IMPORT i16 UnassignFurthestAmbient();

    // ?UnassignFurthestOpponent@aiAudioManager@@QAEFXZ
    ARTS_IMPORT i16 UnassignFurthestOpponent();

    // ?Update@aiAudioManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    offset_field(0x118, f32*, PlayerSpeed);

private:
    // ?CatName@aiAudioManager@@AAEPADPADHH@Z
    ARTS_IMPORT char* CatName(char* arg1, i32 arg2, i32 arg3);

    u8 gap20[0x1E4];
};

check_size(aiAudioManager, 0x204);

// ?AIAUDMGRPTR@@3PAVaiAudioManager@@A
ARTS_IMPORT extern aiAudioManager* AIAUDMGRPTR;

inline aiAudioManager* AiAudMgr()
{
    return AIAUDMGRPTR;
}
