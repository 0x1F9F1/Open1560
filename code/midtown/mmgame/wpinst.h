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

#include "mmcity/inst.h"

class mmWaypointInstance final : public mmStaticInstance
{
public:
    // ??0mmWaypointInstance@@QAE@HMM@Z
    ARTS_IMPORT mmWaypointInstance(i32 arg1, f32 arg2, f32 arg3);

    // ??1mmWaypointInstance@@UAE@XZ
    ARTS_EXPORT ~mmWaypointInstance() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmWaypointInstance@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?ComputeLod@mmWaypointInstance@@UAEHMM@Z
    ARTS_IMPORT i32 ComputeLod(f32 arg1, f32 arg2) override;

    // ?Draw@mmWaypointInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?GetClass@mmWaypointInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetScale@mmWaypointInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // ??_FmmWaypointInstance@@QAEXXZ | invalid name

    // ?DeclareFields@mmWaypointInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap38[0xC];
};

check_size(mmWaypointInstance, 0x44);
