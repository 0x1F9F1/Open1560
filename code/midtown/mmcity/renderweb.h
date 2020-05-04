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

#include "portal.h"

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

class asRenderWeb : public asPortalWeb
{
    // const asRenderWeb::`vftable' @ 0x61CF38

public:
    // 0x48FCC0 | ??0asRenderWeb@@QAE@XZ
    asRenderWeb();

    // 0x4918A0 | ??_EasRenderWeb@@UAEPAXI@Z
    // 0x48FD40 | ??1asRenderWeb@@UAE@XZ
    ~asRenderWeb() override;

    // 0x491690 | ?AddWidgets@asRenderWeb@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x490FF0 | ?Cull@asRenderWeb@@UAEXXZ
    void Cull() override;

    // 0x491610 | ?DrawAllBounds@asRenderWeb@@QAEXXZ
    void DrawAllBounds();

    // 0x4915A0 | ?GetCellNeighbors@asRenderWeb@@QAEHHPAPAUasPortalCell@@H@Z
    i32 GetCellNeighbors(i32 arg1, struct asPortalCell** arg2, i32 arg3);

    // 0x491890 | ?GetClass@asRenderWeb@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x48FDD0 | ?GetStartCell@asRenderWeb@@UAEPAUasPortalCell@@AAVVector3@@PAU2@PAPAVmmPolygon@@@Z
    struct asPortalCell* GetStartCell(class Vector3& arg1, struct asPortalCell* arg2, class mmPolygon** arg3) override;

    // 0x48FFF0 | ?Load@asRenderWeb@@QAEHPADH@Z
    i32 Load(char* arg1, i32 arg2);

    // 0x490E70 | ?SetMirrorPos@asRenderWeb@@QAEXMMMMM@Z
    void SetMirrorPos(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x490CD0 | ?Update@asRenderWeb@@UAEXXZ
    void Update() override;

    // 0x490D60 | ?UpdateMirror@asRenderWeb@@QAEXXZ
    void UpdateMirror();

    // 0x491710 | ?DeclareFields@asRenderWeb@@SAXXZ
    static void DeclareFields();

    // 0x6A8EA8 | ?InvLodFactor@asRenderWeb@@2MA
    static inline extern_var(0x2A8EA8_Offset, f32, InvLodFactor);

    // 0x6A8EB8 | ?PassMask@asRenderWeb@@2HA
    static inline extern_var(0x2A8EB8_Offset, i32, PassMask);
};

check_size(asRenderWeb, 0x9178);

// 0x490F40 | ?DrawMirrorBorder@@YAXXZ
void DrawMirrorBorder();

// 0x6A8EB0 | ?CachedFullSegmentHits@@3HA
inline extern_var(0x2A8EB0_Offset, i32, CachedFullSegmentHits);

// 0x6A8E90 | ?CachedFullSegmentTests@@3HA
inline extern_var(0x2A8E90_Offset, i32, CachedFullSegmentTests);

// 0x6A8EAC | ?EnableCachedPoly@@3HA
inline extern_var(0x2A8EAC_Offset, i32, EnableCachedPoly);

// 0x63F1E8 | ?EnableSubClip@@3HA
inline extern_var(0x23F1E8_Offset, i32, EnableSubClip);

// 0x6A8F14 | ?Front2Back@@3HA
inline extern_var(0x2A8F14_Offset, i32, Front2Back);

// 0x6A8EBC | ?GridMtx@@3PAVMatrix34@@A
inline extern_var(0x2A8EBC_Offset, class Matrix34*, GridMtx);

// 0x63F1E0 | ?MULTIPASS@@3HA
inline extern_var(0x23F1E0_Offset, i32, MULTIPASS);

// 0x6A8F10 | ?PopupEnabled@@3HA
inline extern_var(0x2A8F10_Offset, i32, PopupEnabled);

// 0x6A8ED8 | ?SC_SVCP@@3HA
inline extern_var(0x2A8ED8_Offset, i32, SC_SVCP);

// 0x6A8EB4 | ?SC_SVP@@3HA
inline extern_var(0x2A8EB4_Offset, i32, SC_SVP);

// 0x63F1E4 | ?ScreenClearY@@3MA
inline extern_var(0x23F1E4_Offset, f32, ScreenClearY);

// 0x63F1EC | ?ShadowZBias@@3MA
inline extern_var(0x23F1EC_Offset, f32, ShadowZBias);

// 0x6A8E94 | ?StartCellCollides@@3HA
inline extern_var(0x2A8E94_Offset, i32, StartCellCollides);

// 0x63F1D8 | ?ZREAD@@3HA
inline extern_var(0x23F1D8_Offset, i32, ZREAD);

// 0x63F1DC | ?ZWRITE@@3HA
inline extern_var(0x23F1DC_Offset, i32, ZWRITE);

// 0x6A8EE8 | ?asRenderWebMetaClass@@3VMetaClass@@A
inline extern_var(0x2A8EE8_Offset, class MetaClass, asRenderWebMetaClass);

// 0x6A8EE0 | ?pass1Count@@3HA
inline extern_var(0x2A8EE0_Offset, i32, pass1Count);

// 0x6A8ED0 | ?pass2Count@@3HA
inline extern_var(0x2A8ED0_Offset, i32, pass2Count);

// 0x6A8ED4 | ?pass3Count@@3HA
inline extern_var(0x2A8ED4_Offset, i32, pass3Count);

// 0x6A8EA0 | ?pass4Count@@3HA
inline extern_var(0x2A8EA0_Offset, i32, pass4Count);

// 0x6A8ECC | ?upperCount@@3HA
inline extern_var(0x2A8ECC_Offset, i32, upperCount);
