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

#include "arts7/node.h"

class EngineAudioOpponent final : public asNode
{
    // const EngineAudioOpponent::`vftable' @ 0x61CA90

public:
    // 0x485800 | ??0EngineAudioOpponent@@QAE@XZ
    ARTS_IMPORT EngineAudioOpponent();

    // 0x485DA0 | ??_EEngineAudioOpponent@@UAEPAXI@Z
    // 0x485860 | ??1EngineAudioOpponent@@UAE@XZ
    ARTS_IMPORT ~EngineAudioOpponent() override;

    // 0x485A10 | ?ClearName@EngineAudioOpponent@@QAEXXZ
    ARTS_IMPORT void ClearName();

    // 0x485A50 | ?Disable3DMode@EngineAudioOpponent@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // 0x485A30 | ?Enable3DMode@EngineAudioOpponent@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void Enable3DMode(class Vector3* arg1);

    // 0x485C70 | ?GetClass@EngineAudioOpponent@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x485890 | ?Init@EngineAudioOpponent@@QAEXXZ
    ARTS_IMPORT void Init();

    // 0x485900 | ?Init@EngineAudioOpponent@@QAEXF@Z | unused
    ARTS_IMPORT void Init(i16 arg1);

    // 0x477810 | ?SetSoundPtr@EngineAudioOpponent@@QAEXPAVAudSound@@@Z | inline
    ARTS_IMPORT void SetSoundPtr(class AudSound* arg1);

    // 0x485940 | ?UpdateRPM@EngineAudioOpponent@@QAEXM@Z
    ARTS_IMPORT void UpdateRPM(f32 arg1);

    // 0x485A60 | ?DeclareFields@EngineAudioOpponent@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x34];
};

check_size(EngineAudioOpponent, 0x54);

// 0x6A8248 | ?EngineAudioOpponentMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass EngineAudioOpponentMetaClass;
