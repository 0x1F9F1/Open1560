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

class AudHead final : public asNode
{
public:
    // ??0AudHead@@QAE@PAVMatrix34@@@Z
    ARTS_IMPORT AudHead(Matrix34* arg1);

    // ??1AudHead@@UAE@XZ
    ARTS_EXPORT ~AudHead() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@AudHead@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetHeadPtr@AudHead@@QAEPAVMatrix34@@XZ
    ARTS_IMPORT Matrix34* GetHeadPtr();

    // ?GetPositionPtr@AudHead@@QAEPAVVector3@@XZ
    ARTS_IMPORT Vector3* GetPositionPtr();

    // ?Init@AudHead@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?SetDoppler@AudHead@@QAEXM@Z
    ARTS_IMPORT void SetDoppler(f32 arg1);

    // ?SetRolloff@AudHead@@QAEXM@Z
    ARTS_IMPORT void SetRolloff(f32 arg1);

    // ?WidgetSetRolloff@AudHead@@QAEXXZ
    ARTS_IMPORT void WidgetSetRolloff();

private:
    // ?Update@AudHead@@EAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x30];
};

check_size(AudHead, 0x50);
