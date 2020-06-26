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
    mmcityinfo:roadsect

    0x4D2160 | public: __thiscall mmPropInfo::mmPropInfo(void) | ??0mmPropInfo@@QAE@XZ
    0x4D2190 | public: virtual __thiscall mmPropInfo::~mmPropInfo(void) | ??1mmPropInfo@@UAE@XZ
    0x4D21F0 | public: void __thiscall mmPropInfo::NewItems(int) | ?NewItems@mmPropInfo@@QAEXH@Z
    0x4D2220 | public: void __thiscall mmPropInfo::SetItem(int,char *) | ?SetItem@mmPropInfo@@QAEXHPAD@Z
    0x4D2240 | public: void __thiscall mmPropInfo::SetSpacing(float) | ?SetSpacing@mmPropInfo@@QAEXM@Z
    0x4D2250 | public: char * __thiscall mmPropInfo::GetItem(int) | ?GetItem@mmPropInfo@@QAEPADH@Z
    0x4D2280 | public: float __thiscall mmPropInfo::GetSpacing(void) | ?GetSpacing@mmPropInfo@@QAEMXZ
    0x4D2290 | public: int __thiscall mmPropInfo::GetNumItems(void) | ?GetNumItems@mmPropInfo@@QAEHXZ
    0x4D22A0 | public: void __thiscall mmPropInfo::Append(char *) | ?Append@mmPropInfo@@QAEXPAD@Z
    0x4D2320 | public: __thiscall mmRoadSide::mmRoadSide(void) | ??0mmRoadSide@@QAE@XZ
    0x4D23B0 | public: __thiscall mmRoadSect::mmRoadSect(void) | ??0mmRoadSect@@QAE@XZ
    0x4D24F0 | public: void __thiscall mmRoadSect::SetStreetWidth(float) | ?SetStreetWidth@mmRoadSect@@QAEXM@Z
    0x4D2500 | public: void __thiscall mmRoadSect::SetStreetType(char *) | ?SetStreetType@mmRoadSect@@QAEXPAD@Z
    0x4D2510 | public: void __thiscall mmRoadSect::SetRSidewalk(float,float) | ?SetRSidewalk@mmRoadSect@@QAEXMM@Z
    0x4D2530 | public: void __thiscall mmRoadSect::SetLSidewalk(float,float) | ?SetLSidewalk@mmRoadSect@@QAEXMM@Z
    0x4D2550 | public: void __thiscall mmRoadSect::NewVertexs(int,int,int,int,int) | ?NewVertexs@mmRoadSect@@QAEXHHHHH@Z
    0x4D2600 | public: void __thiscall mmRoadSect::SetRoadVertex(int,int,int,class Vector3 &) | ?SetRoadVertex@mmRoadSect@@QAEXHHHAAVVector3@@@Z
    0x4D2650 | public: void __thiscall mmRoadSect::SetSidewalkVertex(int,int,int,class Vector3 &) | ?SetSidewalkVertex@mmRoadSect@@QAEXHHHAAVVector3@@@Z
    0x4D26B0 | public: class Vector3 * __thiscall mmRoadSect::GetVertex(int,int,int) | ?GetVertex@mmRoadSect@@QAEPAVVector3@@HHH@Z
    0x4D26E0 | public: class Vector3 * __thiscall mmRoadSect::GetSidewalkVertex(int,int,int) | ?GetSidewalkVertex@mmRoadSect@@QAEPAVVector3@@HHH@Z
    0x4D2720 | public: void __thiscall mmRoadSect::SetRoadNormal(int,class Vector3 &) | ?SetRoadNormal@mmRoadSect@@QAEXHAAVVector3@@@Z
    0x4D2750 | public: void __thiscall mmRoadSect::SetRoomId(int,int) | ?SetRoomId@mmRoadSect@@QAEXHH@Z
    0x4D2770 | public: void __thiscall mmRoadSect::SetIntersectionType(int,int) | ?SetIntersectionType@mmRoadSect@@QAEXHH@Z
    0x4D2790 | public: class Vector3 * __thiscall mmRoadSect::GetNormal(int) | ?GetNormal@mmRoadSect@@QAEPAVVector3@@H@Z
    0x4D27B0 | public: int __thiscall mmRoadSect::GetRoomId(int) | ?GetRoomId@mmRoadSect@@QAEHH@Z
    0x4D27D0 | public: int __thiscall mmRoadSect::GetIntersectionType(int) | ?GetIntersectionType@mmRoadSect@@QAEHH@Z
    0x4D27F0 | public: void __thiscall mmRoadSect::SetStopLightPos(int,class Vector3 const &,class Vector3 const &) | ?SetStopLightPos@mmRoadSect@@QAEXHABVVector3@@0@Z
    0x4D2840 | public: void __thiscall mmRoadSect::GetStopLightPos(int,class Vector3 &,class Vector3 &) | ?GetStopLightPos@mmRoadSect@@QAEXHAAVVector3@@0@Z
    0x4D2890 | public: void __thiscall mmRoadSect::SetBlocked(int,int) | ?SetBlocked@mmRoadSect@@QAEXHH@Z
    0x4D28B0 | public: int __thiscall mmRoadSect::IsBlocked(int) | ?IsBlocked@mmRoadSect@@QAEHH@Z
    0x4D28D0 | public: void __thiscall mmRoadSect::SetPedBlocked(int,int) | ?SetPedBlocked@mmRoadSect@@QAEXHH@Z
    0x4D28F0 | public: int __thiscall mmRoadSect::IsPedBlocked(int) | ?IsPedBlocked@mmRoadSect@@QAEHH@Z
    0x4D2910 | public: void __thiscall mmRoadSect::SetStopLightName(int,char *) | ?SetStopLightName@mmRoadSect@@QAEXHPAD@Z
    0x4D2940 | public: char * __thiscall mmRoadSect::GetStopLightName(int) | ?GetStopLightName@mmRoadSect@@QAEPADH@Z
    0x4D2960 | public: void __thiscall mmRoadSect::SetDivided(int) | ?SetDivided@mmRoadSect@@QAEXH@Z
    0x4D2970 | public: int __thiscall mmRoadSect::IsDivided(void) | ?IsDivided@mmRoadSect@@QAEHXZ
    0x4D2980 | public: void __thiscall mmRoadSect::SetAlley(int) | ?SetAlley@mmRoadSect@@QAEXH@Z
    0x4D2990 | public: int __thiscall mmRoadSect::IsAlley(void) | ?IsAlley@mmRoadSect@@QAEHXZ
    0x4D29A0 | public: static void __cdecl mmPropInfo::DeclareFields(void) | ?DeclareFields@mmPropInfo@@SAXXZ
    0x4D2B60 | public: virtual class MetaClass * __thiscall mmPropInfo::GetClass(void) | ?GetClass@mmPropInfo@@UAEPAVMetaClass@@XZ
    0x4D2B70 | public: static void __cdecl mmRoadSide::DeclareFields(void) | ?DeclareFields@mmRoadSide@@SAXXZ
    0x4D2D80 | public: virtual class MetaClass * __thiscall mmRoadSide::GetClass(void) | ?GetClass@mmRoadSide@@UAEPAVMetaClass@@XZ
    0x4D2D90 | public: static void __cdecl mmRoadSect::DeclareFields(void) | ?DeclareFields@mmRoadSect@@SAXXZ
    0x4D3140 | public: virtual class MetaClass * __thiscall mmRoadSect::GetClass(void) | ?GetClass@mmRoadSect@@UAEPAVMetaClass@@XZ
    0x4D3150 | public: virtual void * __thiscall mmPropInfo::`vector deleting destructor'(unsigned int) | ??_EmmPropInfo@@UAEPAXI@Z
    0x4D31B0 | public: virtual void * __thiscall mmRoadSide::`vector deleting destructor'(unsigned int) | ??_EmmRoadSide@@UAEPAXI@Z
    0x4D3210 | public: virtual void * __thiscall mmRoadSect::`vector deleting destructor'(unsigned int) | ??_EmmRoadSect@@UAEPAXI@Z
    0x61F918 | const mmPropInfo::`vftable' | ??_7mmPropInfo@@6B@
    0x708618 | class MetaClass mmPropInfoMetaClass | ?mmPropInfoMetaClass@@3VMetaClass@@A
    0x708640 | class MetaClass mmRoadSideMetaClass | ?mmRoadSideMetaClass@@3VMetaClass@@A
    0x708668 | class MetaClass mmRoadSectMetaClass | ?mmRoadSectMetaClass@@3VMetaClass@@A
*/

#include "infobase.h"

class mmRoadSide : public mmInfoBase
{
    // const mmRoadSide::`vftable' @ 0x61B2D8

public:
    // 0x4D2320 | ??0mmRoadSide@@QAE@XZ
    ARTS_IMPORT mmRoadSide();

    // 0x4D31B0 | ??_EmmRoadSide@@UAEPAXI@Z
    // 0x43C220 | ??_GmmRoadSide@@UAEPAXI@Z | unused
    // 0x43C190 | ??1mmRoadSide@@UAE@XZ | inline
    ARTS_IMPORT ~mmRoadSide() override;

    // 0x4D2D80 | ?GetClass@mmRoadSide@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4D2B70 | ?DeclareFields@mmRoadSide@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x258];
};

check_size(mmRoadSide, 0x2E0);

class mmRoadSect : public mmInfoBase
{
    // const mmRoadSect::`vftable' @ 0x61B2F0

public:
    // 0x4D23B0 | ??0mmRoadSect@@QAE@XZ
    ARTS_IMPORT mmRoadSect();

    // 0x4D3210 | ??_EmmRoadSect@@UAEPAXI@Z
    // 0x43C360 | ??_GmmRoadSect@@UAEPAXI@Z | unused
    // 0x43C250 | ??1mmRoadSect@@UAE@XZ | inline
    ARTS_IMPORT ~mmRoadSect() override;

    // 0x4D3140 | ?GetClass@mmRoadSect@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4D27D0 | ?GetIntersectionType@mmRoadSect@@QAEHH@Z
    ARTS_IMPORT i32 GetIntersectionType(i32 arg1);

    // 0x4D2790 | ?GetNormal@mmRoadSect@@QAEPAVVector3@@H@Z
    ARTS_IMPORT class Vector3* GetNormal(i32 arg1);

    // 0x4D27B0 | ?GetRoomId@mmRoadSect@@QAEHH@Z | unused
    ARTS_IMPORT i32 GetRoomId(i32 arg1);

    // 0x4D26E0 | ?GetSidewalkVertex@mmRoadSect@@QAEPAVVector3@@HHH@Z
    ARTS_IMPORT class Vector3* GetSidewalkVertex(i32 arg1, i32 arg2, i32 arg3);

    // 0x4D2940 | ?GetStopLightName@mmRoadSect@@QAEPADH@Z
    ARTS_IMPORT char* GetStopLightName(i32 arg1);

    // 0x4D2840 | ?GetStopLightPos@mmRoadSect@@QAEXHAAVVector3@@0@Z
    ARTS_IMPORT void GetStopLightPos(i32 arg1, class Vector3& arg2, class Vector3& arg3);

    // 0x4D26B0 | ?GetVertex@mmRoadSect@@QAEPAVVector3@@HHH@Z
    ARTS_IMPORT class Vector3* GetVertex(i32 arg1, i32 arg2, i32 arg3);

    // 0x4D2990 | ?IsAlley@mmRoadSect@@QAEHXZ
    ARTS_IMPORT i32 IsAlley();

    // 0x4D28B0 | ?IsBlocked@mmRoadSect@@QAEHH@Z
    ARTS_IMPORT i32 IsBlocked(i32 arg1);

    // 0x4D2970 | ?IsDivided@mmRoadSect@@QAEHXZ
    ARTS_IMPORT i32 IsDivided();

    // 0x4D28F0 | ?IsPedBlocked@mmRoadSect@@QAEHH@Z
    ARTS_IMPORT i32 IsPedBlocked(i32 arg1);

    // 0x4D2550 | ?NewVertexs@mmRoadSect@@QAEXHHHHH@Z | unused
    ARTS_IMPORT void NewVertexs(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    // 0x4D2980 | ?SetAlley@mmRoadSect@@QAEXH@Z | unused
    ARTS_IMPORT void SetAlley(i32 arg1);

    // 0x4D2890 | ?SetBlocked@mmRoadSect@@QAEXHH@Z | unused
    ARTS_IMPORT void SetBlocked(i32 arg1, i32 arg2);

    // 0x4D2960 | ?SetDivided@mmRoadSect@@QAEXH@Z | unused
    ARTS_IMPORT void SetDivided(i32 arg1);

    // 0x4D2770 | ?SetIntersectionType@mmRoadSect@@QAEXHH@Z | unused
    ARTS_IMPORT void SetIntersectionType(i32 arg1, i32 arg2);

    // 0x4D2530 | ?SetLSidewalk@mmRoadSect@@QAEXMM@Z | unused
    ARTS_IMPORT void SetLSidewalk(f32 arg1, f32 arg2);

    // 0x4D28D0 | ?SetPedBlocked@mmRoadSect@@QAEXHH@Z | unused
    ARTS_IMPORT void SetPedBlocked(i32 arg1, i32 arg2);

    // 0x4D2510 | ?SetRSidewalk@mmRoadSect@@QAEXMM@Z | unused
    ARTS_IMPORT void SetRSidewalk(f32 arg1, f32 arg2);

    // 0x4D2720 | ?SetRoadNormal@mmRoadSect@@QAEXHAAVVector3@@@Z | unused
    ARTS_IMPORT void SetRoadNormal(i32 arg1, class Vector3& arg2);

    // 0x4D2600 | ?SetRoadVertex@mmRoadSect@@QAEXHHHAAVVector3@@@Z | unused
    ARTS_IMPORT void SetRoadVertex(i32 arg1, i32 arg2, i32 arg3, class Vector3& arg4);

    // 0x4D2750 | ?SetRoomId@mmRoadSect@@QAEXHH@Z | unused
    ARTS_IMPORT void SetRoomId(i32 arg1, i32 arg2);

    // 0x4D2650 | ?SetSidewalkVertex@mmRoadSect@@QAEXHHHAAVVector3@@@Z | unused
    ARTS_IMPORT void SetSidewalkVertex(i32 arg1, i32 arg2, i32 arg3, class Vector3& arg4);

    // 0x4D2910 | ?SetStopLightName@mmRoadSect@@QAEXHPAD@Z | unused
    ARTS_IMPORT void SetStopLightName(i32 arg1, char* arg2);

    // 0x4D27F0 | ?SetStopLightPos@mmRoadSect@@QAEXHABVVector3@@0@Z | unused
    ARTS_IMPORT void SetStopLightPos(i32 arg1, class Vector3 const& arg2, class Vector3 const& arg3);

    // 0x4D2500 | ?SetStreetType@mmRoadSect@@QAEXPAD@Z | unused
    ARTS_IMPORT void SetStreetType(char* arg1);

    // 0x4D24F0 | ?SetStreetWidth@mmRoadSect@@QAEXM@Z | unused
    ARTS_IMPORT void SetStreetWidth(f32 arg1);

    // 0x4D2D90 | ?DeclareFields@mmRoadSect@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x644];
};

check_size(mmRoadSect, 0x6CC);

class mmPropInfo : public mmInfoBase
{
    // const mmPropInfo::`vftable' @ 0x61F918

public:
    // 0x4D2160 | ??0mmPropInfo@@QAE@XZ
    ARTS_IMPORT mmPropInfo();

    // 0x4D3150 | ??_EmmPropInfo@@UAEPAXI@Z
    // 0x4D2190 | ??1mmPropInfo@@UAE@XZ
    ARTS_IMPORT ~mmPropInfo() override;

    // 0x4D22A0 | ?Append@mmPropInfo@@QAEXPAD@Z | unused
    ARTS_IMPORT void Append(char* arg1);

    // 0x4D2B60 | ?GetClass@mmPropInfo@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4D2250 | ?GetItem@mmPropInfo@@QAEPADH@Z | unused
    ARTS_IMPORT char* GetItem(i32 arg1);

    // 0x4D2290 | ?GetNumItems@mmPropInfo@@QAEHXZ | unused
    ARTS_IMPORT i32 GetNumItems();

    // 0x4D2280 | ?GetSpacing@mmPropInfo@@QAEMXZ | unused
    ARTS_IMPORT f32 GetSpacing();

    // 0x4D21F0 | ?NewItems@mmPropInfo@@QAEXH@Z
    ARTS_IMPORT void NewItems(i32 arg1);

    // 0x4D2220 | ?SetItem@mmPropInfo@@QAEXHPAD@Z
    ARTS_IMPORT void SetItem(i32 arg1, char* arg2);

    // 0x4D2240 | ?SetSpacing@mmPropInfo@@QAEXM@Z | unused
    ARTS_IMPORT void SetSpacing(f32 arg1);

    // 0x4D29A0 | ?DeclareFields@mmPropInfo@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0xC];
};

check_size(mmPropInfo, 0x94);

// 0x708618 | ?mmPropInfoMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmPropInfoMetaClass;

// 0x708668 | ?mmRoadSectMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmRoadSectMetaClass;

// 0x708640 | ?mmRoadSideMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmRoadSideMetaClass;
