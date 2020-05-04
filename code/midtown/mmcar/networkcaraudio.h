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

/*
    mmcar:networkcaraudio

    0x483440 | public: __thiscall mmNetworkCarAudio::mmNetworkCarAudio(class mmCarSim *) | ??0mmNetworkCarAudio@@QAE@PAVmmCarSim@@@Z
    0x4834A0 | public: void __thiscall mmNetworkCarAudio::Init(class mmCarSim *,unsigned short) | ?Init@mmNetworkCarAudio@@QAEXPAVmmCarSim@@G@Z
    0x483630 | public: virtual __thiscall mmNetworkCarAudio::~mmNetworkCarAudio(void) | ??1mmNetworkCarAudio@@UAE@XZ
    0x4836A0 | public: virtual void __thiscall mmNetworkCarAudio::Update(void) | ?Update@mmNetworkCarAudio@@UAEXXZ
    0x4836E0 | public: void __thiscall mmNetworkCarAudio::UpdateAudio(void) | ?UpdateAudio@mmNetworkCarAudio@@QAEXXZ
    0x483810 | public: void __thiscall mmNetworkCarAudio::FluctuateSlowSiren(void) | ?FluctuateSlowSiren@mmNetworkCarAudio@@QAEXXZ
    0x483A60 | public: void __thiscall mmNetworkCarAudio::FluctuateFastSiren(void) | ?FluctuateFastSiren@mmNetworkCarAudio@@QAEXXZ
    0x483E10 | public: void __thiscall mmNetworkCarAudio::DeactivateAudio(void) | ?DeactivateAudio@mmNetworkCarAudio@@QAEXXZ
    0x483EC0 | public: void __thiscall mmNetworkCarAudio::CalculateDistToPlayer2(void) | ?CalculateDistToPlayer2@mmNetworkCarAudio@@QAEXXZ
    0x483F80 | public: void __thiscall mmNetworkCarAudio::CalculateDoppler(void) | ?CalculateDoppler@mmNetworkCarAudio@@QAEXXZ
    0x483FA0 | public: void __thiscall mmNetworkCarAudio::UpdateDoppler(void) | ?UpdateDoppler@mmNetworkCarAudio@@QAEXXZ
    0x484250 | public: void __thiscall mmNetworkCarAudio::StopSiren(void) | ?StopSiren@mmNetworkCarAudio@@QAEXXZ
    0x484290 | public: void __thiscall mmNetworkCarAudio::StartSiren(void) | ?StartSiren@mmNetworkCarAudio@@QAEXXZ
    0x4842E0 | public: virtual void __thiscall mmNetworkCarAudio::Reset(void) | ?Reset@mmNetworkCarAudio@@UAEXXZ
    0x484300 | public: void __thiscall mmNetworkCarAudio::RemoveFromManager(void) | ?RemoveFromManager@mmNetworkCarAudio@@QAEXXZ
    0x484320 | public: void __thiscall mmNetworkCarAudio::LoadSucessful(class mmCarSim *) | ?LoadSucessful@mmNetworkCarAudio@@QAEXPAVmmCarSim@@@Z
    0x4843A0 | public: static void __cdecl mmNetworkCarAudio::DeclareFields(void) | ?DeclareFields@mmNetworkCarAudio@@SAXXZ
    0x484570 | public: virtual class MetaClass * __thiscall mmNetworkCarAudio::GetClass(void) | ?GetClass@mmNetworkCarAudio@@UAEPAVMetaClass@@XZ
    0x4846A0 | public: virtual void * __thiscall mmNetworkCarAudio::`vector deleting destructor'(unsigned int) | ??_EmmNetworkCarAudio@@UAEPAXI@Z
    0x484700 | public: __thiscall mmNetworkCarAudio::mmNetworkCarAudio(void) | ??0mmNetworkCarAudio@@QAE@XZ
    0x61CA30 | const mmNetworkCarAudio::`vftable' | ??_7mmNetworkCarAudio@@6B@
    0x6A81F0 | class MetaClass mmNetworkCarAudioMetaClass | ?mmNetworkCarAudioMetaClass@@3VMetaClass@@A
    0x6A822C | public: static short mmNetworkCarAudio::s_iPlayingFluctuator | ?s_iPlayingFluctuator@mmNetworkCarAudio@@2FA
*/

class mmNetworkCarAudio : public asNode
{
    // const mmNetworkCarAudio::`vftable' @ 0x61CA30

public:
    // 0x484700 | ??0mmNetworkCarAudio@@QAE@XZ
    mmNetworkCarAudio();

    // 0x483440 | ??0mmNetworkCarAudio@@QAE@PAVmmCarSim@@@Z
    mmNetworkCarAudio(class mmCarSim* arg1);

    // 0x4846A0 | ??_EmmNetworkCarAudio@@UAEPAXI@Z
    // 0x483630 | ??1mmNetworkCarAudio@@UAE@XZ
    ~mmNetworkCarAudio() override;

    // 0x483EC0 | ?CalculateDistToPlayer2@mmNetworkCarAudio@@QAEXXZ
    void CalculateDistToPlayer2();

    // 0x483F80 | ?CalculateDoppler@mmNetworkCarAudio@@QAEXXZ
    void CalculateDoppler();

    // 0x483E10 | ?DeactivateAudio@mmNetworkCarAudio@@QAEXXZ
    void DeactivateAudio();

    // 0x483A60 | ?FluctuateFastSiren@mmNetworkCarAudio@@QAEXXZ
    void FluctuateFastSiren();

    // 0x483810 | ?FluctuateSlowSiren@mmNetworkCarAudio@@QAEXXZ
    void FluctuateSlowSiren();

    // 0x484570 | ?GetClass@mmNetworkCarAudio@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4834A0 | ?Init@mmNetworkCarAudio@@QAEXPAVmmCarSim@@G@Z
    void Init(class mmCarSim* arg1, u16 arg2);

    // 0x484320 | ?LoadSucessful@mmNetworkCarAudio@@QAEXPAVmmCarSim@@@Z
    void LoadSucessful(class mmCarSim* arg1);

    // 0x484300 | ?RemoveFromManager@mmNetworkCarAudio@@QAEXXZ
    void RemoveFromManager();

    // 0x4842E0 | ?Reset@mmNetworkCarAudio@@UAEXXZ
    void Reset() override;

    // 0x484290 | ?StartSiren@mmNetworkCarAudio@@QAEXXZ
    void StartSiren();

    // 0x484250 | ?StopSiren@mmNetworkCarAudio@@QAEXXZ
    void StopSiren();

    // 0x4836A0 | ?Update@mmNetworkCarAudio@@UAEXXZ
    void Update() override;

    // 0x4836E0 | ?UpdateAudio@mmNetworkCarAudio@@QAEXXZ
    void UpdateAudio();

    // 0x483FA0 | ?UpdateDoppler@mmNetworkCarAudio@@QAEXXZ
    void UpdateDoppler();

    // 0x4843A0 | ?DeclareFields@mmNetworkCarAudio@@SAXXZ
    static void DeclareFields();

    // 0x6A822C | ?s_iPlayingFluctuator@mmNetworkCarAudio@@2FA
    static inline extern_var(0x2A822C_Offset, i16, s_iPlayingFluctuator);
};

check_size(mmNetworkCarAudio, 0xD4);

// 0x6A81F0 | ?mmNetworkCarAudioMetaClass@@3VMetaClass@@A
inline extern_var(0x2A81F0_Offset, class MetaClass, mmNetworkCarAudioMetaClass);
