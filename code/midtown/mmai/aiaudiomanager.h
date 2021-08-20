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
    mmai:aiaudiomanager

    0x440070 | public: __thiscall aiAudioManager::aiAudioManager(void) | ??0aiAudioManager@@QAE@XZ
    0x440390 | public: virtual __thiscall aiAudioManager::~aiAudioManager(void) | ??1aiAudioManager@@UAE@XZ
    0x440790 | public: short __thiscall aiAudioManager::AddVehicle(class aiVehicleAmbient *) | ?AddVehicle@aiAudioManager@@QAEFPAVaiVehicleAmbient@@@Z
    0x440840 | public: short __thiscall aiAudioManager::AddVehicle(class aiVehicleOpponent *) | ?AddVehicle@aiAudioManager@@QAEFPAVaiVehicleOpponent@@@Z
    0x4408F0 | public: short __thiscall aiAudioManager::AddVehicle(class aiVehiclePolice *) | ?AddVehicle@aiAudioManager@@QAEFPAVaiVehiclePolice@@@Z
    0x4409A0 | public: void __thiscall aiAudioManager::RemoveVehicle(class aiVehicleAmbient *,short) | ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehicleAmbient@@F@Z
    0x440A10 | public: void __thiscall aiAudioManager::RemoveVehicle(class aiVehicleOpponent *,short) | ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    0x440A80 | public: void __thiscall aiAudioManager::RemoveVehicle(class aiVehiclePolice *,short) | ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehiclePolice@@F@Z
    0x440AF0 | public: short __thiscall aiAudioManager::FindGreatestDistance(class aiVehicleAmbient *) | ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehicleAmbient@@@Z
    0x440CE0 | public: short __thiscall aiAudioManager::FindGreatestDistance(class aiVehicleOpponent *) | ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehicleOpponent@@@Z
    0x440ED0 | public: short __thiscall aiAudioManager::FindGreatestDistance(class aiVehiclePolice *) | ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehiclePolice@@@Z
    0x441130 | public: short __thiscall aiAudioManager::UnassignFurthestAmbient(void) | ?UnassignFurthestAmbient@aiAudioManager@@QAEFXZ
    0x4411F0 | public: short __thiscall aiAudioManager::UnassignFurthestOpponent(void) | ?UnassignFurthestOpponent@aiAudioManager@@QAEFXZ
    0x4412C0 | public: short __thiscall aiAudioManager::FindUnusedSlot(void) | ?FindUnusedSlot@aiAudioManager@@QAEFXZ
    0x441300 | public: virtual void __thiscall aiAudioManager::Update(void) | ?Update@aiAudioManager@@UAEXXZ
    0x441670 | public: void __thiscall aiAudioManager::EchoOn(float) | ?EchoOn@aiAudioManager@@QAEXM@Z
    0x4419C0 | public: void __thiscall aiAudioManager::EchoOff(void) | ?EchoOff@aiAudioManager@@QAEXXZ
    0x441B60 | public: void __thiscall aiAudioManager::AssignSounds(class aiVehicleOpponent *,short) | ?AssignSounds@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    0x441F50 | public: void __thiscall aiAudioManager::AssignAddOnSounds(class aiVehicleOpponent *,short) | ?AssignAddOnSounds@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    0x442050 | public: void __thiscall aiAudioManager::AssignSounds(class aiVehiclePolice *,short) | ?AssignSounds@aiAudioManager@@QAEXPAVaiVehiclePolice@@F@Z
    0x442630 | public: void __thiscall aiAudioManager::AssignSounds(class aiVehicleAmbient *,short) | ?AssignSounds@aiAudioManager@@QAEXPAVaiVehicleAmbient@@F@Z
    0x442820 | public: void __thiscall aiAudioManager::AllocateAmbients(void) | ?AllocateAmbients@aiAudioManager@@QAEXXZ
    0x442880 | public: void __thiscall aiAudioManager::AllocateOpponents(void) | ?AllocateOpponents@aiAudioManager@@QAEXXZ
    0x4428D0 | public: void __thiscall aiAudioManager::AllocatePolice(void) | ?AllocatePolice@aiAudioManager@@QAEXXZ
    0x442C10 | public: void __thiscall aiAudioManager::AllocateSkids(void) | ?AllocateSkids@aiAudioManager@@QAEXXZ
    0x442EB0 | public: void __thiscall aiAudioManager::AllocateCopVoice(void) | ?AllocateCopVoice@aiAudioManager@@QAEXXZ
    0x442F90 | public: void __thiscall aiAudioManager::LoadCopVoice(void) | ?LoadCopVoice@aiAudioManager@@QAEXXZ
    0x4430C0 | private: char * __thiscall aiAudioManager::CatName(char *,int,int) | ?CatName@aiAudioManager@@AAEPADPADHH@Z
    0x4432C0 | public: void __thiscall aiAudioManager::AllocateImpacts(void) | ?AllocateImpacts@aiAudioManager@@QAEXXZ
    0x443370 | public: void __thiscall aiAudioManager::AllocateHorns(void) | ?AllocateHorns@aiAudioManager@@QAEXXZ
    0x443550 | public: void __thiscall aiAudioManager::AllocateVoices(void) | ?AllocateVoices@aiAudioManager@@QAEXXZ
    0x443720 | public: void __thiscall aiAudioManager::AllocateEngine(short,short) | ?AllocateEngine@aiAudioManager@@QAEXFF@Z
    0x443930 | public: short __thiscall aiAudioManager::AllocateAddOnEngine(char *) | ?AllocateAddOnEngine@aiAudioManager@@QAEFPAD@Z
    0x443B00 | public: class AudSound * * __thiscall aiAudioManager::AllocateEngine(char *) | ?AllocateEngine@aiAudioManager@@QAEPAPAVAudSound@@PAD@Z
    0x443C50 | public: void __thiscall aiAudioManager::AllocateReverseBeep(void) | ?AllocateReverseBeep@aiAudioManager@@QAEXXZ
    0x443DA0 | public: short __thiscall aiAudioManager::QueueInCopVoice(float) | ?QueueInCopVoice@aiAudioManager@@QAEFM@Z
    0x443E00 | public: short __thiscall aiAudioManager::PlayCopVoice(void) | ?PlayCopVoice@aiAudioManager@@QAEFXZ
    0x443E50 | public: short __thiscall aiAudioManager::GetClosestCop(void) | ?GetClosestCop@aiAudioManager@@QAEFXZ
    0x443F30 | public: virtual void * __thiscall aiAudioManager::`scalar deleting destructor'(unsigned int) | ??_GaiAudioManager@@UAEPAXI@Z
    0x443F30 | public: virtual void * __thiscall aiAudioManager::`vector deleting destructor'(unsigned int) | ??_EaiAudioManager@@UAEPAXI@Z
    0x61B398 | const aiAudioManager::`vftable' | ??_7aiAudioManager@@6B@
    0x6A796C | class aiAudioManager * AIAUDMGRPTR | ?AIAUDMGRPTR@@3PAVaiAudioManager@@A
*/

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

    // ??_EaiAudioManager@@UAEPAXI@Z
    // ??_GaiAudioManager@@UAEPAXI@Z
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

private:
    // ?CatName@aiAudioManager@@AAEPADPADHH@Z
    ARTS_IMPORT char* CatName(char* arg1, i32 arg2, i32 arg3);

    u8 gap20[0x1E4];
};

check_size(aiAudioManager, 0x204);

// ?AIAUDMGRPTR@@3PAVaiAudioManager@@A
ARTS_IMPORT extern aiAudioManager* AIAUDMGRPTR;
