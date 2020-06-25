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
    mmcar:netaudiomanager

    0x4751D0 | public: __thiscall NetAudioManager::NetAudioManager(void) | ??0NetAudioManager@@QAE@XZ
    0x4753B0 | public: virtual __thiscall NetAudioManager::~NetAudioManager(void) | ??1NetAudioManager@@UAE@XZ
    0x475770 | public: short __thiscall NetAudioManager::AddVehicle(class mmNetworkCarAudio *) | ?AddVehicle@NetAudioManager@@QAEFPAVmmNetworkCarAudio@@@Z
    0x475800 | public: void __thiscall NetAudioManager::RemoveVehicle(class mmNetworkCarAudio *,short) | ?RemoveVehicle@NetAudioManager@@QAEXPAVmmNetworkCarAudio@@F@Z
    0x475860 | public: short __thiscall NetAudioManager::FindGreatestDistance(class mmNetworkCarAudio *) | ?FindGreatestDistance@NetAudioManager@@QAEFPAVmmNetworkCarAudio@@@Z
    0x475900 | public: short __thiscall NetAudioManager::FindUnusedSlot(void) | ?FindUnusedSlot@NetAudioManager@@QAEFXZ
    0x475940 | public: virtual void __thiscall NetAudioManager::Update(void) | ?Update@NetAudioManager@@UAEXXZ
    0x475B00 | public: void __thiscall NetAudioManager::EchoOn(float) | ?EchoOn@NetAudioManager@@QAEXM@Z
    0x475E70 | public: void __thiscall NetAudioManager::EchoOff(void) | ?EchoOff@NetAudioManager@@QAEXXZ
    0x476000 | public: void __thiscall NetAudioManager::AssignSounds(class mmNetworkCarAudio *,short) | ?AssignSounds@NetAudioManager@@QAEXPAVmmNetworkCarAudio@@F@Z
    0x476940 | private: void __thiscall NetAudioManager::AssignAddOnSounds(class mmNetworkCarAudio *,short) | ?AssignAddOnSounds@NetAudioManager@@AAEXPAVmmNetworkCarAudio@@F@Z
    0x476B60 | public: float __thiscall NetAudioManager::GetAvailableDistance(void) | ?GetAvailableDistance@NetAudioManager@@QAEMXZ
    0x476BA0 | public: void __thiscall NetAudioManager::AllocateEngine(short) | ?AllocateEngine@NetAudioManager@@QAEXF@Z
    0x476D20 | public: short __thiscall NetAudioManager::AllocateAddOnEngine(char *) | ?AllocateAddOnEngine@NetAudioManager@@QAEFPAD@Z
    0x476EF0 | public: class AudSound * * __thiscall NetAudioManager::AllocateEngine(char *) | ?AllocateEngine@NetAudioManager@@QAEPAPAVAudSound@@PAD@Z
    0x477020 | public: void __thiscall NetAudioManager::AllocateReverseBeep(void) | ?AllocateReverseBeep@NetAudioManager@@QAEXXZ
    0x477170 | public: void __thiscall NetAudioManager::AllocateHorn(short) | ?AllocateHorn@NetAudioManager@@QAEXF@Z
    0x477360 | public: void __thiscall NetAudioManager::AllocateSkids(void) | ?AllocateSkids@NetAudioManager@@QAEXXZ
    0x4775E0 | public: void __thiscall NetAudioManager::AllocateImpacts(void) | ?AllocateImpacts@NetAudioManager@@QAEXXZ
    0x477670 | public: void __thiscall NetAudioManager::AllocatePoliceSiren(void) | ?AllocatePoliceSiren@NetAudioManager@@QAEXXZ
    0x4777E0 | public: virtual void * __thiscall NetAudioManager::`scalar deleting destructor'(unsigned int) | ??_GNetAudioManager@@UAEPAXI@Z
    0x4777E0 | public: virtual void * __thiscall NetAudioManager::`vector deleting destructor'(unsigned int) | ??_ENetAudioManager@@UAEPAXI@Z
    0x477810 | public: void __thiscall EngineAudioOpponent::SetSoundPtr(class AudSound *) | ?SetSoundPtr@EngineAudioOpponent@@QAEXPAVAudSound@@@Z
    0x61C1C8 | const NetAudioManager::`vftable' | ??_7NetAudioManager@@6B@
    0x6A7E98 | class NetAudioManager * NETAUDMGRPTR | ?NETAUDMGRPTR@@3PAVNetAudioManager@@A
*/

#include "arts7/node.h"

class NetAudioManager : public asNode
{
    // const NetAudioManager::`vftable' @ 0x61C1C8

public:
    // 0x4751D0 | ??0NetAudioManager@@QAE@XZ
    ARTS_IMPORT NetAudioManager();

    // 0x4777E0 | ??_ENetAudioManager@@UAEPAXI@Z
    // 0x4753B0 | ??1NetAudioManager@@UAE@XZ
    ARTS_IMPORT ~NetAudioManager() override;

    // 0x475770 | ?AddVehicle@NetAudioManager@@QAEFPAVmmNetworkCarAudio@@@Z
    ARTS_IMPORT i16 AddVehicle(class mmNetworkCarAudio* arg1);

    // 0x476D20 | ?AllocateAddOnEngine@NetAudioManager@@QAEFPAD@Z
    ARTS_IMPORT i16 AllocateAddOnEngine(char* arg1);

    // 0x476EF0 | ?AllocateEngine@NetAudioManager@@QAEPAPAVAudSound@@PAD@Z
    ARTS_IMPORT class AudSound** AllocateEngine(char* arg1);

    // 0x476BA0 | ?AllocateEngine@NetAudioManager@@QAEXF@Z
    ARTS_IMPORT void AllocateEngine(i16 arg1);

    // 0x477170 | ?AllocateHorn@NetAudioManager@@QAEXF@Z
    ARTS_IMPORT void AllocateHorn(i16 arg1);

    // 0x4775E0 | ?AllocateImpacts@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateImpacts();

    // 0x477670 | ?AllocatePoliceSiren@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocatePoliceSiren();

    // 0x477020 | ?AllocateReverseBeep@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateReverseBeep();

    // 0x477360 | ?AllocateSkids@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void AllocateSkids();

    // 0x476000 | ?AssignSounds@NetAudioManager@@QAEXPAVmmNetworkCarAudio@@F@Z
    ARTS_IMPORT void AssignSounds(class mmNetworkCarAudio* arg1, i16 arg2);

    // 0x475E70 | ?EchoOff@NetAudioManager@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // 0x475B00 | ?EchoOn@NetAudioManager@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // 0x475860 | ?FindGreatestDistance@NetAudioManager@@QAEFPAVmmNetworkCarAudio@@@Z
    ARTS_IMPORT i16 FindGreatestDistance(class mmNetworkCarAudio* arg1);

    // 0x475900 | ?FindUnusedSlot@NetAudioManager@@QAEFXZ
    ARTS_IMPORT i16 FindUnusedSlot();

    // 0x476B60 | ?GetAvailableDistance@NetAudioManager@@QAEMXZ
    ARTS_IMPORT f32 GetAvailableDistance();

    // 0x475800 | ?RemoveVehicle@NetAudioManager@@QAEXPAVmmNetworkCarAudio@@F@Z
    ARTS_IMPORT void RemoveVehicle(class mmNetworkCarAudio* arg1, i16 arg2);

    // 0x475940 | ?Update@NetAudioManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // 0x476940 | ?AssignAddOnSounds@NetAudioManager@@AAEXPAVmmNetworkCarAudio@@F@Z
    ARTS_IMPORT void AssignAddOnSounds(class mmNetworkCarAudio* arg1, i16 arg2);
};

check_size(NetAudioManager, 0x74);

// 0x6A7E98 | ?NETAUDMGRPTR@@3PAVNetAudioManager@@A
ARTS_IMPORT extern class NetAudioManager* NETAUDMGRPTR;
