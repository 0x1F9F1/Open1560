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
    mmcar:engineaudio

    0x4864D0 | public: __thiscall EngineAudio::EngineAudio(void) | ??0EngineAudio@@QAE@XZ
    0x486550 | public: void __thiscall EngineAudio::Init(class Vector3 *) | ?Init@EngineAudio@@QAEXPAVVector3@@@Z
    0x4867A0 | public: void __thiscall EngineAudio::Init(char *,char *) | ?Init@EngineAudio@@QAEXPAD0@Z
    0x486940 | public: virtual __thiscall EngineAudio::~EngineAudio(void) | ??1EngineAudio@@UAE@XZ
    0x4869F0 | public: void __thiscall EngineAudio::EchoOn(float) | ?EchoOn@EngineAudio@@QAEXM@Z
    0x486A40 | public: void __thiscall EngineAudio::EchoOff(void) | ?EchoOff@EngineAudio@@QAEXXZ
    0x486A70 | public: void __thiscall EngineAudio::EnableClutch(char *,float) | ?EnableClutch@EngineAudio@@QAEXPADM@Z
    0x486B30 | public: virtual void __thiscall EngineAudio::UpdateRPM(float) | ?UpdateRPM@EngineAudio@@UAEXM@Z
    0x486D90 | public: void __thiscall EngineAudio::ResetVolume(void) | ?ResetVolume@EngineAudio@@QAEXXZ
    0x486DB0 | public: void __thiscall EngineAudio::Stop(void) | ?Stop@EngineAudio@@QAEXXZ
    0x486DF0 | public: static void __cdecl EngineAudio::DeclareFields(void) | ?DeclareFields@EngineAudio@@SAXXZ
    0x4870A0 | public: virtual class MetaClass * __thiscall EngineAudio::GetClass(void) | ?GetClass@EngineAudio@@UAEPAVMetaClass@@XZ
    0x4870B0 | public: virtual void * __thiscall EngineAudio::`vector deleting destructor'(unsigned int) | ??_EEngineAudio@@UAEPAXI@Z
    0x61CAE8 | const EngineAudio::`vftable' | ??_7EngineAudio@@6B@
    0x6A82A0 | class MetaClass EngineAudioMetaClass | ?EngineAudioMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class EngineAudio : public asNode
{
    // const EngineAudio::`vftable' @ 0x61CAE8

public:
    // 0x4864D0 | ??0EngineAudio@@QAE@XZ
    EngineAudio();

    // 0x4870B0 | ??_EEngineAudio@@UAEPAXI@Z
    // 0x486940 | ??1EngineAudio@@UAE@XZ
    ~EngineAudio() override;

    // 0x486B30 | ?UpdateRPM@EngineAudio@@UAEXM@Z
    virtual void UpdateRPM(f32 arg1);

    // 0x486A40 | ?EchoOff@EngineAudio@@QAEXXZ
    void EchoOff();

    // 0x4869F0 | ?EchoOn@EngineAudio@@QAEXM@Z
    void EchoOn(f32 arg1);

    // 0x486A70 | ?EnableClutch@EngineAudio@@QAEXPADM@Z
    void EnableClutch(char* arg1, f32 arg2);

    // 0x4870A0 | ?GetClass@EngineAudio@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x486550 | ?Init@EngineAudio@@QAEXPAVVector3@@@Z
    void Init(class Vector3* arg1);

    // 0x4867A0 | ?Init@EngineAudio@@QAEXPAD0@Z
    void Init(char* arg1, char* arg2);

    // 0x486D90 | ?ResetVolume@EngineAudio@@QAEXXZ
    void ResetVolume();

    // 0x486DB0 | ?Stop@EngineAudio@@QAEXXZ
    void Stop();

    // 0x486DF0 | ?DeclareFields@EngineAudio@@SAXXZ
    static void DeclareFields();
};

check_size(EngineAudio, 0x90);

// 0x6A82A0 | ?EngineAudioMetaClass@@3VMetaClass@@A
inline extern_var(0x2A82A0_Offset, class MetaClass, EngineAudioMetaClass);
