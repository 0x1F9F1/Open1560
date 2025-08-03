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

#include "infobase.h"

class mmRoadSide final : public mmInfoBase
{
public:
    // ??0mmRoadSide@@QAE@XZ
    ARTS_IMPORT mmRoadSide();

    // ??1mmRoadSide@@UAE@XZ | inline
    ARTS_IMPORT ~mmRoadSide() override;

    // ?GetClass@mmRoadSide@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?DeclareFields@mmRoadSide@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x258];
};

check_size(mmRoadSide, 0x2E0);

class mmRoadSect final : public mmInfoBase
{
public:
    // ??0mmRoadSect@@QAE@XZ
    ARTS_IMPORT mmRoadSect();

    // ??1mmRoadSect@@UAE@XZ | inline
    ARTS_IMPORT ~mmRoadSect() override;

    // ?GetClass@mmRoadSect@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetIntersectionType@mmRoadSect@@QAEHH@Z
    ARTS_IMPORT i32 GetIntersectionType(i32 arg1);

    // ?GetNormal@mmRoadSect@@QAEPAVVector3@@H@Z
    ARTS_IMPORT Vector3* GetNormal(i32 arg1);

    // ?GetSidewalkVertex@mmRoadSect@@QAEPAVVector3@@HHH@Z
    ARTS_IMPORT Vector3* GetSidewalkVertex(i32 arg1, i32 arg2, i32 arg3);

    // ?GetStopLightName@mmRoadSect@@QAEPADH@Z
    ARTS_IMPORT char* GetStopLightName(i32 arg1);

    // ?GetStopLightPos@mmRoadSect@@QAEXHAAVVector3@@0@Z
    ARTS_IMPORT void GetStopLightPos(i32 arg1, Vector3& arg2, Vector3& arg3);

    // ?GetVertex@mmRoadSect@@QAEPAVVector3@@HHH@Z
    ARTS_IMPORT Vector3* GetVertex(i32 arg1, i32 arg2, i32 arg3);

    // ?IsAlley@mmRoadSect@@QAEHXZ
    ARTS_IMPORT i32 IsAlley();

    // ?IsBlocked@mmRoadSect@@QAEHH@Z
    ARTS_IMPORT i32 IsBlocked(i32 arg1);

    // ?IsDivided@mmRoadSect@@QAEHXZ
    ARTS_IMPORT i32 IsDivided();

    // ?IsPedBlocked@mmRoadSect@@QAEHH@Z
    ARTS_IMPORT i32 IsPedBlocked(i32 arg1);

    // ?DeclareFields@mmRoadSect@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x644];
};

check_size(mmRoadSect, 0x6CC);

class mmPropInfo final : public mmInfoBase
{
public:
    // ??0mmPropInfo@@QAE@XZ
    ARTS_IMPORT mmPropInfo();

    // ??1mmPropInfo@@UAE@XZ
    ARTS_IMPORT ~mmPropInfo() override;

    // ?GetClass@mmPropInfo@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?NewItems@mmPropInfo@@QAEXH@Z
    ARTS_IMPORT void NewItems(i32 arg1);

    // ?SetItem@mmPropInfo@@QAEXHPAD@Z
    ARTS_IMPORT void SetItem(i32 arg1, char* arg2);

    // ?DeclareFields@mmPropInfo@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0xC];
};

check_size(mmPropInfo, 0x94);
