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
    mmcar:engineaudioopponent

    0x485800 | public: __thiscall EngineAudioOpponent::EngineAudioOpponent(void) | ??0EngineAudioOpponent@@QAE@XZ
    0x485860 | public: virtual __thiscall EngineAudioOpponent::~EngineAudioOpponent(void) | ??1EngineAudioOpponent@@UAE@XZ
    0x485890 | public: void __thiscall EngineAudioOpponent::Init(void) | ?Init@EngineAudioOpponent@@QAEXXZ
    0x485900 | public: void __thiscall EngineAudioOpponent::Init(short) | ?Init@EngineAudioOpponent@@QAEXF@Z
    0x485940 | public: void __thiscall EngineAudioOpponent::UpdateRPM(float) | ?UpdateRPM@EngineAudioOpponent@@QAEXM@Z
    0x485A10 | public: void __thiscall EngineAudioOpponent::ClearName(void) | ?ClearName@EngineAudioOpponent@@QAEXXZ
    0x485A30 | public: void __thiscall EngineAudioOpponent::Enable3DMode(class Vector3 *) | ?Enable3DMode@EngineAudioOpponent@@QAEXPAVVector3@@@Z
    0x485A50 | public: void __thiscall EngineAudioOpponent::Disable3DMode(void) | ?Disable3DMode@EngineAudioOpponent@@QAEXXZ
    0x485A60 | public: static void __cdecl EngineAudioOpponent::DeclareFields(void) | ?DeclareFields@EngineAudioOpponent@@SAXXZ
    0x485C70 | public: virtual class MetaClass * __thiscall EngineAudioOpponent::GetClass(void) | ?GetClass@EngineAudioOpponent@@UAEPAVMetaClass@@XZ
    0x485DA0 | public: virtual void * __thiscall EngineAudioOpponent::`vector deleting destructor'(unsigned int) | ??_EEngineAudioOpponent@@UAEPAXI@Z
    0x61CA90 | const EngineAudioOpponent::`vftable' | ??_7EngineAudioOpponent@@6B@
    0x6A8248 | class MetaClass EngineAudioOpponentMetaClass | ?EngineAudioOpponentMetaClass@@3VMetaClass@@A
*/

class EngineAudioOpponent : public asNode
{
    // const EngineAudioOpponent::`vftable' @ 0x61CA90

public:
    // 0x485800 | ??0EngineAudioOpponent@@QAE@XZ
    EngineAudioOpponent();

    // 0x485DA0 | ??_EEngineAudioOpponent@@UAEPAXI@Z
    // 0x485860 | ??1EngineAudioOpponent@@UAE@XZ
    ~EngineAudioOpponent() override;

    // 0x485A10 | ?ClearName@EngineAudioOpponent@@QAEXXZ
    void ClearName();

    // 0x485A50 | ?Disable3DMode@EngineAudioOpponent@@QAEXXZ
    void Disable3DMode();

    // 0x485A30 | ?Enable3DMode@EngineAudioOpponent@@QAEXPAVVector3@@@Z
    void Enable3DMode(class Vector3* arg1);

    // 0x485C70 | ?GetClass@EngineAudioOpponent@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x485890 | ?Init@EngineAudioOpponent@@QAEXXZ
    void Init();

    // 0x485900 | ?Init@EngineAudioOpponent@@QAEXF@Z
    void Init(i16 arg1);

    // 0x477810 | ?SetSoundPtr@EngineAudioOpponent@@QAEXPAVAudSound@@@Z
    void SetSoundPtr(class AudSound* arg1);

    // 0x485940 | ?UpdateRPM@EngineAudioOpponent@@QAEXM@Z
    void UpdateRPM(f32 arg1);

    // 0x485A60 | ?DeclareFields@EngineAudioOpponent@@SAXXZ
    static void DeclareFields();
};

check_size(EngineAudioOpponent, 0x54);

// 0x6A8248 | ?EngineAudioOpponentMetaClass@@3VMetaClass@@A
inline extern_var(0x2A8248_Offset, class MetaClass, EngineAudioOpponentMetaClass);
