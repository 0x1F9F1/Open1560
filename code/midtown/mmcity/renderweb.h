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
    mmcity:renderweb

    0x48FCC0 | public: __thiscall asRenderWeb::asRenderWeb(void) | ??0asRenderWeb@@QAE@XZ
    0x48FD40 | public: virtual __thiscall asRenderWeb::~asRenderWeb(void) | ??1asRenderWeb@@UAE@XZ
    0x48FDD0 | public: virtual struct asPortalCell * __thiscall asRenderWeb::GetStartCell(class Vector3 &,struct asPortalCell *,class mmPolygon * *) | ?GetStartCell@asRenderWeb@@UAEPAUasPortalCell@@AAVVector3@@PAU2@PAPAVmmPolygon@@@Z
    0x48FFF0 | public: int __thiscall asRenderWeb::Load(char *,int) | ?Load@asRenderWeb@@QAEHPADH@Z
    0x490CD0 | public: virtual void __thiscall asRenderWeb::Update(void) | ?Update@asRenderWeb@@UAEXXZ
    0x490D60 | public: void __thiscall asRenderWeb::UpdateMirror(void) | ?UpdateMirror@asRenderWeb@@QAEXXZ
    0x490E70 | public: void __thiscall asRenderWeb::SetMirrorPos(float,float,float,float,float) | ?SetMirrorPos@asRenderWeb@@QAEXMMMMM@Z
    0x490F40 | void __cdecl DrawMirrorBorder(void) | ?DrawMirrorBorder@@YAXXZ
    0x490FF0 | public: virtual void __thiscall asRenderWeb::Cull(void) | ?Cull@asRenderWeb@@UAEXXZ
    0x4915A0 | public: int __thiscall asRenderWeb::GetCellNeighbors(int,struct asPortalCell * *,int) | ?GetCellNeighbors@asRenderWeb@@QAEHHPAPAUasPortalCell@@H@Z
    0x491610 | public: void __thiscall asRenderWeb::DrawAllBounds(void) | ?DrawAllBounds@asRenderWeb@@QAEXXZ
    0x491690 | public: virtual void __thiscall asRenderWeb::AddWidgets(class Bank *) | ?AddWidgets@asRenderWeb@@UAEXPAVBank@@@Z
    0x491710 | public: static void __cdecl asRenderWeb::DeclareFields(void) | ?DeclareFields@asRenderWeb@@SAXXZ
    0x491890 | public: virtual class MetaClass * __thiscall asRenderWeb::GetClass(void) | ?GetClass@asRenderWeb@@UAEPAVMetaClass@@XZ
    0x4918A0 | public: virtual void * __thiscall asRenderWeb::`vector deleting destructor'(unsigned int) | ??_EasRenderWeb@@UAEPAXI@Z
    0x61CF38 | const asRenderWeb::`vftable' | ??_7asRenderWeb@@6B@
    0x63F1D8 | int ZREAD | ?ZREAD@@3HA
    0x63F1DC | int ZWRITE | ?ZWRITE@@3HA
    0x63F1E0 | int MULTIPASS | ?MULTIPASS@@3HA
    0x63F1E4 | float ScreenClearY | ?ScreenClearY@@3MA
    0x63F1E8 | int EnableSubClip | ?EnableSubClip@@3HA
    0x63F1EC | float ShadowZBias | ?ShadowZBias@@3MA
    0x6A8E90 | int CachedFullSegmentTests | ?CachedFullSegmentTests@@3HA
    0x6A8E94 | int StartCellCollides | ?StartCellCollides@@3HA
    0x6A8EA0 | int pass4Count | ?pass4Count@@3HA
    0x6A8EA8 | public: static float asRenderWeb::InvLodFactor | ?InvLodFactor@asRenderWeb@@2MA
    0x6A8EAC | int EnableCachedPoly | ?EnableCachedPoly@@3HA
    0x6A8EB0 | int CachedFullSegmentHits | ?CachedFullSegmentHits@@3HA
    0x6A8EB4 | int SC_SVP | ?SC_SVP@@3HA
    0x6A8EB8 | public: static int asRenderWeb::PassMask | ?PassMask@asRenderWeb@@2HA
    0x6A8EBC | class Matrix34 * GridMtx | ?GridMtx@@3PAVMatrix34@@A
    0x6A8ECC | int upperCount | ?upperCount@@3HA
    0x6A8ED0 | int pass2Count | ?pass2Count@@3HA
    0x6A8ED4 | int pass3Count | ?pass3Count@@3HA
    0x6A8ED8 | int SC_SVCP | ?SC_SVCP@@3HA
    0x6A8EE0 | int pass1Count | ?pass1Count@@3HA
    0x6A8EE8 | class MetaClass asRenderWebMetaClass | ?asRenderWebMetaClass@@3VMetaClass@@A
    0x6A8F10 | int PopupEnabled | ?PopupEnabled@@3HA
    0x6A8F14 | int Front2Back | ?Front2Back@@3HA
*/

#include "portal.h"

class asRenderWeb final : public asPortalWeb
{
    // const asRenderWeb::`vftable'

public:
    // ??0asRenderWeb@@QAE@XZ
    ARTS_IMPORT asRenderWeb();

    // ??_EasRenderWeb@@UAEPAXI@Z
    // ??1asRenderWeb@@UAE@XZ
    ARTS_IMPORT ~asRenderWeb() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asRenderWeb@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?Cull@asRenderWeb@@UAEXXZ
    ARTS_IMPORT void Cull() override;

#ifdef ARTS_DEV_BUILD
    // ?DrawAllBounds@asRenderWeb@@QAEXXZ
    ARTS_IMPORT void DrawAllBounds();
#endif

    // ?GetCellNeighbors@asRenderWeb@@QAEHHPAPAUasPortalCell@@H@Z
    ARTS_IMPORT i32 GetCellNeighbors(i32 arg1, struct asPortalCell** arg2, i32 arg3);

    // ?GetClass@asRenderWeb@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetStartCell@asRenderWeb@@UAEPAUasPortalCell@@AAVVector3@@PAU2@PAPAVmmPolygon@@@Z
    ARTS_IMPORT struct asPortalCell* GetStartCell(
        class Vector3& arg1, struct asPortalCell* arg2, class mmPolygon** arg3) override;

    // ?Load@asRenderWeb@@QAEHPADH@Z
    ARTS_IMPORT i32 Load(char* arg1, i32 arg2);

    // ?SetMirrorPos@asRenderWeb@@QAEXMMMMM@Z
    ARTS_IMPORT void SetMirrorPos(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?Update@asRenderWeb@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateMirror@asRenderWeb@@QAEXXZ
    ARTS_IMPORT void UpdateMirror();

    // ?DeclareFields@asRenderWeb@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?InvLodFactor@asRenderWeb@@2MA
    ARTS_IMPORT static f32 InvLodFactor;

    // ?PassMask@asRenderWeb@@2HA
    ARTS_IMPORT static i32 PassMask;

    u8 gap904C[0x12C];
};

check_size(asRenderWeb, 0x9178);

// ?DrawMirrorBorder@@YAXXZ
ARTS_IMPORT void DrawMirrorBorder();

// ?CachedFullSegmentHits@@3HA
ARTS_IMPORT extern i32 CachedFullSegmentHits;

// ?CachedFullSegmentTests@@3HA
ARTS_IMPORT extern i32 CachedFullSegmentTests;

// ?EnableCachedPoly@@3HA
ARTS_IMPORT extern i32 EnableCachedPoly;

// ?EnableSubClip@@3HA
ARTS_IMPORT extern i32 EnableSubClip;

// ?Front2Back@@3HA
ARTS_IMPORT extern i32 Front2Back;

// ?GridMtx@@3PAVMatrix34@@A
ARTS_IMPORT extern class Matrix34* GridMtx;

// ?MULTIPASS@@3HA
ARTS_IMPORT extern i32 MULTIPASS;

// ?PopupEnabled@@3HA
ARTS_IMPORT extern i32 PopupEnabled;

// ?SC_SVCP@@3HA
ARTS_IMPORT extern i32 SC_SVCP;

// ?SC_SVP@@3HA
ARTS_IMPORT extern i32 SC_SVP;

// ?ScreenClearY@@3MA
ARTS_IMPORT extern f32 ScreenClearY;

// ?ShadowZBias@@3MA
ARTS_IMPORT extern f32 ShadowZBias;

// ?StartCellCollides@@3HA
ARTS_IMPORT extern i32 StartCellCollides;

// ?ZREAD@@3HA
ARTS_IMPORT extern i32 ZREAD;

// ?ZWRITE@@3HA
ARTS_IMPORT extern i32 ZWRITE;

// ?asRenderWebMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asRenderWebMetaClass;

#ifdef ARTS_DEV_BUILD
// ?pass1Count@@3HA
ARTS_IMPORT extern i32 pass1Count;

// ?pass2Count@@3HA
ARTS_IMPORT extern i32 pass2Count;

// ?pass3Count@@3HA
ARTS_IMPORT extern i32 pass3Count;

// ?pass4Count@@3HA
ARTS_IMPORT extern i32 pass4Count;

// ?upperCount@@3HA
ARTS_IMPORT extern i32 upperCount;
#endif
