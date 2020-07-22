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
    mmaudio:head

    0x4EBCB0 | public: __thiscall AudHead::AudHead(class Matrix34 *) | ??0AudHead@@QAE@PAVMatrix34@@@Z
    0x4EBD00 | public: virtual __thiscall AudHead::~AudHead(void) | ??1AudHead@@UAE@XZ
    0x4EBD10 | public: int __thiscall AudHead::Init(void) | ?Init@AudHead@@QAEHXZ
    0x4EBD60 | private: virtual void __thiscall AudHead::Update(void) | ?Update@AudHead@@EAEXXZ
    0x4EBEE0 | public: void __thiscall AudHead::WidgetSetRolloff(void) | ?WidgetSetRolloff@AudHead@@QAEXXZ
    0x4EBEF0 | public: virtual void __thiscall AudHead::AddWidgets(class Bank *) | ?AddWidgets@AudHead@@UAEXPAVBank@@@Z
    0x4EBF50 | public: void __thiscall AudHead::SetRolloff(float) | ?SetRolloff@AudHead@@QAEXM@Z
    0x4EBFB0 | public: void __thiscall AudHead::SetDoppler(float) | ?SetDoppler@AudHead@@QAEXM@Z
    0x4EC010 | public: class Vector3 * __thiscall AudHead::GetPositionPtr(void) | ?GetPositionPtr@AudHead@@QAEPAVVector3@@XZ
    0x4EC020 | public: void __thiscall AudHead::SetHeadPtr(class Matrix34 *) | ?SetHeadPtr@AudHead@@QAEXPAVMatrix34@@@Z
    0x4EC030 | public: class Matrix34 * __thiscall AudHead::GetHeadPtr(void) | ?GetHeadPtr@AudHead@@QAEPAVMatrix34@@XZ
    0x4EC040 | public: virtual void * __thiscall AudHead::`scalar deleting destructor'(unsigned int) | ??_GAudHead@@UAEPAXI@Z
    0x4EC040 | public: virtual void * __thiscall AudHead::`vector deleting destructor'(unsigned int) | ??_EAudHead@@UAEPAXI@Z
    0x61FE08 | const AudHead::`vftable' | ??_7AudHead@@6B@
*/

#include "arts7/node.h"

class AudHead final : public asNode
{
    // const AudHead::`vftable' @ 0x61FE08

public:
    // 0x4EBCB0 | ??0AudHead@@QAE@PAVMatrix34@@@Z
    ARTS_IMPORT AudHead(class Matrix34* arg1);

    // 0x4EC040 | ??_EAudHead@@UAEPAXI@Z
    // 0x4EC040 | ??_GAudHead@@UAEPAXI@Z
    // 0x4EBD00 | ??1AudHead@@UAE@XZ
    ARTS_IMPORT ~AudHead() override = default;

    // 0x4EBEF0 | ?AddWidgets@AudHead@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4EC030 | ?GetHeadPtr@AudHead@@QAEPAVMatrix34@@XZ
    ARTS_IMPORT class Matrix34* GetHeadPtr();

    // 0x4EC010 | ?GetPositionPtr@AudHead@@QAEPAVVector3@@XZ
    ARTS_IMPORT class Vector3* GetPositionPtr();

    // 0x4EBD10 | ?Init@AudHead@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // 0x4EBFB0 | ?SetDoppler@AudHead@@QAEXM@Z
    ARTS_IMPORT void SetDoppler(f32 arg1);

    // 0x4EC020 | ?SetHeadPtr@AudHead@@QAEXPAVMatrix34@@@Z | unused
    ARTS_IMPORT void SetHeadPtr(class Matrix34* arg1);

    // 0x4EBF50 | ?SetRolloff@AudHead@@QAEXM@Z
    ARTS_IMPORT void SetRolloff(f32 arg1);

    // 0x4EBEE0 | ?WidgetSetRolloff@AudHead@@QAEXXZ
    ARTS_IMPORT void WidgetSetRolloff();

private:
    // 0x4EBD60 | ?Update@AudHead@@EAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x30];
};

check_size(AudHead, 0x50);
