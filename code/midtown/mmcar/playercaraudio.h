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
    mmcar:playercaraudio

    0x481B00 | public: __thiscall mmPlayerCarAudio::mmPlayerCarAudio(class mmCarSim *) | ??0mmPlayerCarAudio@@QAE@PAVmmCarSim@@@Z
    0x481BA0 | public: void __thiscall mmPlayerCarAudio::Init(class mmCarSim *) | ?Init@mmPlayerCarAudio@@QAEXPAVmmCarSim@@@Z
    0x481F30 | public: virtual __thiscall mmPlayerCarAudio::~mmPlayerCarAudio(void) | ??1mmPlayerCarAudio@@UAE@XZ
    0x482020 | public: void __thiscall mmPlayerCarAudio::EchoOn(float) | ?EchoOn@mmPlayerCarAudio@@QAEXM@Z
    0x482140 | public: void __thiscall mmPlayerCarAudio::EchoOff(void) | ?EchoOff@mmPlayerCarAudio@@QAEXXZ
    0x4821F0 | public: void __thiscall mmPlayerCarAudio::PlayReverseBeep(void) | ?PlayReverseBeep@mmPlayerCarAudio@@QAEXXZ
    0x482250 | public: void __thiscall mmPlayerCarAudio::Update(int,float,float,short) | ?Update@mmPlayerCarAudio@@QAEXHMMF@Z
    0x482460 | public: void __thiscall mmPlayerCarAudio::StartSiren(void) | ?StartSiren@mmPlayerCarAudio@@QAEXXZ
    0x4824F0 | public: void __thiscall mmPlayerCarAudio::StopSiren(void) | ?StopSiren@mmPlayerCarAudio@@QAEXXZ
    0x482530 | public: void __thiscall mmPlayerCarAudio::FluctuateSlowSiren(void) | ?FluctuateSlowSiren@mmPlayerCarAudio@@QAEXXZ
    0x482730 | public: void __thiscall mmPlayerCarAudio::FluctuateFastSiren(void) | ?FluctuateFastSiren@mmPlayerCarAudio@@QAEXXZ
    0x482A50 | public: virtual void __thiscall mmPlayerCarAudio::Reset(void) | ?Reset@mmPlayerCarAudio@@UAEXXZ
    0x482A90 | public: void __thiscall mmPlayerCarAudio::PlayHorn(void) | ?PlayHorn@mmPlayerCarAudio@@QAEXXZ
    0x482AD0 | public: void __thiscall mmPlayerCarAudio::SetUpDefault(class mmCarSim *) | ?SetUpDefault@mmPlayerCarAudio@@QAEXPAVmmCarSim@@@Z
    0x482C20 | public: void __thiscall mmPlayerCarAudio::LoadSucessful(void) | ?LoadSucessful@mmPlayerCarAudio@@QAEXXZ
    0x483080 | public: static void __cdecl mmPlayerCarAudio::DeclareFields(void) | ?DeclareFields@mmPlayerCarAudio@@SAXXZ
    0x483260 | public: virtual class MetaClass * __thiscall mmPlayerCarAudio::GetClass(void) | ?GetClass@mmPlayerCarAudio@@UAEPAVMetaClass@@XZ
    0x483390 | public: virtual void * __thiscall mmPlayerCarAudio::`vector deleting destructor'(unsigned int) | ??_EmmPlayerCarAudio@@UAEPAXI@Z
    0x4833F0 | public: __thiscall mmPlayerCarAudio::mmPlayerCarAudio(void) | ??0mmPlayerCarAudio@@QAE@XZ
    0x61C9A8 | const mmPlayerCarAudio::`vftable' | ??_7mmPlayerCarAudio@@6B@
    0x6A8198 | class MetaClass mmPlayerCarAudioMetaClass | ?mmPlayerCarAudioMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmPlayerCarAudio /*final*/ : public asNode
{
    // const mmPlayerCarAudio::`vftable' @ 0x61C9A8

public:
    // 0x4833F0 | ??0mmPlayerCarAudio@@QAE@XZ | inline
    ARTS_IMPORT mmPlayerCarAudio();

    // 0x481B00 | ??0mmPlayerCarAudio@@QAE@PAVmmCarSim@@@Z
    ARTS_IMPORT mmPlayerCarAudio(class mmCarSim* arg1);

    // 0x483390 | ??_EmmPlayerCarAudio@@UAEPAXI@Z
    // 0x481F30 | ??1mmPlayerCarAudio@@UAE@XZ
    ARTS_IMPORT ~mmPlayerCarAudio() override;

    // 0x482140 | ?EchoOff@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // 0x482020 | ?EchoOn@mmPlayerCarAudio@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // 0x482730 | ?FluctuateFastSiren@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void FluctuateFastSiren();

    // 0x482530 | ?FluctuateSlowSiren@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void FluctuateSlowSiren();

    // 0x483260 | ?GetClass@mmPlayerCarAudio@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x481BA0 | ?Init@mmPlayerCarAudio@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(class mmCarSim* arg1);

    // 0x482C20 | ?LoadSucessful@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void LoadSucessful();

    // 0x482A90 | ?PlayHorn@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void PlayHorn();

    // 0x4821F0 | ?PlayReverseBeep@mmPlayerCarAudio@@QAEXXZ | unused
    ARTS_IMPORT void PlayReverseBeep();

    // 0x482A50 | ?Reset@mmPlayerCarAudio@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x482AD0 | ?SetUpDefault@mmPlayerCarAudio@@QAEXPAVmmCarSim@@@Z | unused
    ARTS_IMPORT void SetUpDefault(class mmCarSim* arg1);

    // 0x482460 | ?StartSiren@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void StartSiren();

    // 0x4824F0 | ?StopSiren@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void StopSiren();

    // 0x482250 | ?Update@mmPlayerCarAudio@@QAEXHMMF@Z
    ARTS_IMPORT void Update(i32 arg1, f32 arg2, f32 arg3, i16 arg4);

    // 0x483080 | ?DeclareFields@mmPlayerCarAudio@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xE0];
};

check_size(mmPlayerCarAudio, 0x100);

// 0x6A8198 | ?mmPlayerCarAudioMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmPlayerCarAudioMetaClass;
