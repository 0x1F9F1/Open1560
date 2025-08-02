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

#include "vector7/vector2.h"

class agiBitmap;
union agiVtx;
class aiMap;
class asCamera;
class mmGame;
class mmHUD;
class mmPlayer;
class mmWaypoints;
struct Point;

#define OPP_ICON_1ST 1
#define OPP_ICON_9TH 9
#define OPP_ICON_GOLD 10
#define OPP_ICON_BLANK 11

struct OppIconInfo
{
    u32 Color;
    b32 Enabled;
    Matrix34* Position;

    // Corresponds to OPP_ICON.DDS index + 1
    // 0:   Invalid
    // 1-9: Number 1-9
    // 10:  CnR Gold $
    // 11:  Blank
    i32 Place;
    char Name[16];
    agiBitmap* Bitmap;
};

check_size(OppIconInfo, 0x24);

#define HUD_MAP_NONE 0
#define HUD_MAP_SMALL 1
#define HUD_MAP_MEDIUM 2
#define HUD_MAP_LARGE 3

class mmHudMap final : public asNode
{
public:
    // ??0mmHudMap@@QAE@XZ
    ARTS_IMPORT mmHudMap();

    // ??_EmmHudMap@@UAEPAXI@Z
    // ??1mmHudMap@@UAE@XZ | inline
    ARTS_EXPORT ~mmHudMap() override;

    // ?Activate@mmHudMap@@QAEXXZ
    ARTS_IMPORT void Activate();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmHudMap@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmHudMap@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?Cycle@mmHudMap@@QAEXXZ
    ARTS_IMPORT void Cycle();

    // ?Deactivate@mmHudMap@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // ?DrawMisc@mmHudMap@@QAEXXZ
    ARTS_IMPORT void DrawMisc();

    // ?GetClass@mmHudMap@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmHudMap@@QAEXPAVasCamera@@PAVMatrix34@@PAVmmHUD@@PAVmmGame@@PAD@Z
    ARTS_IMPORT void Init(asCamera* arg1, Matrix34* arg2, mmHUD* arg3, mmGame* arg4, char* arg5);

    // ?RegisterCopsnRobbers@mmHudMap@@QAEXPAPAVVector3@@@Z
    ARTS_IMPORT void RegisterCopsnRobbers(Vector3** arg1);

    // ?RegisterMisc@mmHudMap@@QAEXPAPAVVector3@@H@Z
    ARTS_IMPORT void RegisterMisc(Vector3** arg1, i32 arg2);

    // ?RegisterOpponents@mmHudMap@@QAEXPAUOppIconInfo@@H@Z
    ARTS_IMPORT void RegisterOpponents(OppIconInfo* arg1, i32 arg2);

    // ?ResChanged@mmHudMap@@QAEXXZ
    ARTS_IMPORT void ResChanged();

    // ?Reset@mmHudMap@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetMode@mmHudMap@@QAEXH@Z
    ARTS_IMPORT void SetMode(i32 arg1);

    // ?ToggleFullScreen@mmHudMap@@QAEXXZ
    ARTS_IMPORT void ToggleFullScreen();

    // ?ToggleMapRes@mmHudMap@@QAEXXZ
    ARTS_IMPORT void ToggleMapRes();

    // ?Update@mmHudMap@@UAEXXZ
    ARTS_IMPORT void Update() override;

    void ToggleShowAllCops()
    {
        ShowAllCops ^= true;
    }

    i32 GetMode()
    {
        return Mode;
    }

    // ?DeclareFields@mmHudMap@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?BitmapToScreen@mmHudMap@@AAEHPAUPoint@@U2@@Z
    ARTS_IMPORT i32 BitmapToScreen(Point* arg1, Point arg2);

    // ?DrawClipped@mmHudMap@@AAEXPAVagiBitmap@@UPoint@@MMMM@Z
    ARTS_IMPORT void DrawClipped(agiBitmap* arg1, Point arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

    // ?DrawCops@mmHudMap@@AAEXXZ
    ARTS_IMPORT void DrawCops();

    // ?DrawCopsnRobbers@mmHudMap@@AAEXXZ
    ARTS_IMPORT void DrawCopsnRobbers();

    // ?DrawOpponents@mmHudMap@@AAEXXZ
    ARTS_EXPORT void DrawOpponents();

    // ?DrawOrientedBitmap@mmHudMap@@AAEXPAVMatrix34@@PAVagiBitmap@@@Z
    ARTS_IMPORT void DrawOrientedBitmap(Matrix34* arg1, agiBitmap* arg2);

    // ?DrawWaypoints@mmHudMap@@AAEXXZ
    ARTS_IMPORT void DrawWaypoints();

    // ?GetCurrentMap@mmHudMap@@AAEPAVagiBitmap@@XZ
    ARTS_IMPORT agiBitmap* GetCurrentMap();

    // ?WorldToBitmap@mmHudMap@@AAE?AUPoint@@PAVVector3@@@Z
    ARTS_IMPORT Point WorldToBitmap(Vector3* arg1);

    [[deprecated("Use AIMAP")]] aiMap* AiMap;
    mmWaypoints* Waypoints;
    i32 dword28;
    Vector3* MiscPositions[100];
    i32 NumMiscPositions;
    Vector3* CnrPos1;
    Vector3* CnrPos2;
    Vector3* CnrPos3;
    b32 WideFov;
    i32 field_1D0;
    mmPlayer* Player;
    OppIconInfo* OppIcons;
    i32 field_1DC;
    i32 field_1E0;

    // 3 | Fullscreen
    i32 Mode;

    Matrix34* Transform;
    mmHUD* Hud;
    agiBitmap* Resolutions[2];
    agiBitmap* Current;
    i32 field_1FC;
    i32 field_200;
    i32 field_204;
    i32 field_208;
    i32 field_20C;
    i32 field_210;
    i32 field_214;
    i32 field_218;
    i16 NumOpps;
    i16 field_21E;
    Vector2 MinX;
    Vector2 MaxX;
    f32 ScaleX;
    f32 ScaleY;
    i32 field_238;
    i32 field_23C;
    i32 field_240;
    i32 field_244;
    i32 MapSrcX;
    i32 MapSrcY;
    i32 MapWidth;
    i32 MapHeight;
    i32 MapDstX;
    i32 MapDstY;

    agiBitmap* Dot_Hideout;
    agiBitmap* Dot_Bank;
    agiBitmap* Dot_Gold;
    agiBitmap* Dot_Grey;
    agiBitmap* Dot_Yellow;
    agiBitmap* Dot_Finish;

    agiBitmap* Icon_Player;
    agiBitmap* Icon_Cop;

    agiBitmap* Icon_Blue;
    agiBitmap* Icon_Green;
    agiBitmap* Icon_Red;
    agiBitmap* Icon_Yellow;
    agiBitmap* Icon_Orange;
    agiBitmap* Icon_Purple;
    agiBitmap* Icon_Cyan;

#if ARTS_TARGET_BUILD < 1588
    static
#endif
        agiBitmap* Icon_Pink;

    asCamera* Camera;
    b32 ShowAllCops;
    f32 dword2A4;
    f32 dword2A8;
    Callback* CullCallback;
    i32 dword2B0;
    i32 dword2B4;
    f32 dword2B8;
    f32 dword2BC;
    i32 field_2C0;
    i16 DisableHudmap;
};

check_size(mmHudMap, 0x2C8);

// ?Tris@@3PATagiVtx@@A
ARTS_IMPORT extern agiVtx Tris[30];
