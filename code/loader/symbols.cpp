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

#include "symbols.h"

#define import_symbol(ADDRESS, NAME)                                              \
    __pragma(comment(linker, "/ALTERNATENAME:__imp_" NAME "=_Symbol_" #ADDRESS)); \
    extern "C" const usize Symbol_##ADDRESS = ADDRESS;

import_symbol(0x5248E0, "?PrintRenderPerf@@YAXXZ");
import_symbol(0x6A6F1C, "?JoinViaZone@@3HA");
import_symbol(0x7057E8, "?LightQualityOption@@3MA");
import_symbol(0x705804, "?MaxTextureQuality@@3HA");
import_symbol(0x719740, "?LastPolySet@@3PAVagiPolySet@@A");
import_symbol(0x719748, "?ColoredPolySet@@3PAVagiPolySet@@A");
import_symbol(0x719808, "?BigPolySet@@3VagiPolySet@@A");
import_symbol(0x719840, "?CurrentMeshSetVariant@@3HA");
import_symbol(0x719848, "?ClippedTextures@@3PAPAUCT@@A");
import_symbol(0x71DE98, "?ClippedTris@@3PAUCT@@A");
import_symbol(0x7210E8, "?ShadowMatrix@@3VMatrix44@@A");
import_symbol(0x725134, "?DynTexFlag@@3HA");
import_symbol(0x72D390, "?ClippedVerts@@3PAUCV@@A");
import_symbol(0x7805D0, "?DebugLogReading@@3HA");
import_symbol(0x7805D8, "?DebugLogStream@@3PAVStream@@A");
import_symbol(0x790780, "?SunLight@@3PAVagiLight@@A");
import_symbol(0x790788, "?SunParams@@3VagiLightParameters@@A");
import_symbol(0x7907F8, "?PipelineInitialized@@3HA");
import_symbol(0x790868, "?CurrentFrameTime@@3MA");
import_symbol(0x790870, "?UpdateTime2D@@3MA");
import_symbol(0x790874, "?UpdateTime3D@@3MA");
import_symbol(0x790878, "?StatsTextOffset@@3HA");
import_symbol(0x7957D8, "?TextureFormats@@3PAU_DDPIXELFORMAT@@A");
import_symbol(0x795BDC, "?WantedDeviceName@@3PBDB");
import_symbol(0x795BE0, "?TextureFormatCount@@3HA");
import_symbol(0x795C08, "?TotalTextureMem@@3HA");
import_symbol(0x795C1C, "?SurfaceDumpStream@@3PAVStream@@A");
import_symbol(0x795D34, "?bEnableVerticalSync@@3HA");
import_symbol(0x7960A8, "?swFindColor@@3P6AII@ZA");
import_symbol(0x7A0018, "?swVtxBase@@3PAUagiScreenVtx@@A");
import_symbol(0x9092B4, "?InputWndWidth@@3JA");
import_symbol(0x9092BC, "?InputWndHeight@@3JA");
import_symbol(0x909424, "?MouseDevice@@3PAUIDirectInputDeviceA@@A");
import_symbol(0x909428, "?KeyboardDevice@@3PAUIDirectInputDeviceA@@A");
import_symbol(0x90942C, "?MouseEvent@@3PAXA");

const char* const NewSymbols[] {
    "DirectInputCreateA=",
    "NvOptimusEnablement=",
    "AmdPowerXpressRequestHighPerformance=",

    "?Link@asMemoryAllocator@@AAEXPAUFreeNode@1@@Z=?Link@asMemoryAllocator@@AAEXPAUnode@1@@Z",
    "?Unlink@asMemoryAllocator@@AAEXPAUFreeNode@1@@Z=?Unlink@asMemoryAllocator@@AAEXPAUnode@1@@Z",
    "?arts_calloc@@YAPAXII@Z=_calloc",
    "?arts_free@@YAXPAX@Z=_free",
    "?arts_malloc@@YAPAXI@Z=_malloc",
    "?arts_operator_delete@@YAXPAX@Z=??3@YAXPAX@Z",
    "?arts_operator_new@@YAPAXI@Z=??2@YAPAXI@Z",
    "?arts_realloc@@YAPAXPAXI@Z=_realloc",
    "?MidtownMain@@YGHPAUHINSTANCE__@@0PADH@Z=_WinMain@16",
    "?FindFile@@YAPAVFileSystem@@PBD00HPAD@Z=?FindFile@@YAPAVFileSystem@@PAD00H0@Z",
    "?OpenFile@@YAPAVStream@@PBD00HPAD0@Z=?OpenFile@@YAPAVStream@@PAD00H00@Z",
    "?Search@FileSystem@@QAEHPBD00HPADH@Z=?Search@FileSystem@@QAEHPAD00H0@Z",
    "?SearchAll@FileSystem@@SAPAV1@PBD00HPADH@Z=?SearchAll@FileSystem@@SAPAV1@PAD00H0@Z",
    "?Get@Stream@@QAEHPAIH@Z=?Get@Stream@@QAEHPAKH@Z",
    "?GetLong@Stream@@QAEIXZ=?GetLong@Stream@@QAEKXZ",
    "?Put@Stream@@QAEHI@Z=?Put@Stream@@QAEHK@Z",
    "?Put@Stream@@QAEHPBEH@Z=?Put@Stream@@QAEHPAEH@Z",
    "?Put@Stream@@QAEHPBGH@Z=?Put@Stream@@QAEHPAGH@Z",
    "?Put@Stream@@QAEHPBIH@Z=?Put@Stream@@QAEHPAKH@Z",
    "?SwapLongs@Stream@@CAXPAIH@Z=?SwapLongs@Stream@@CAXPAKH@Z",
    "?arts_fgets@@YAHPADHPAVStream@@@Z=?fgets@@YAHPADHPAVStream@@@Z",
    "?arts_fopen@@YAPAVStream@@PBD0@Z=?fopen@@YAPAVStream@@PAD0@Z",
    "?arts_fprintf@@YAXPAVStream@@PBDZZ=?fprintf@@YAXPAVStream@@PBDZZ",
    "?arts_fscanf@@YAHPAVStream@@PBDZZ=?fscanf@@YAHPAVStream@@PBDZZ",
    "?arts_fseek@@YAHPAVStream@@HH@Z=?fseek@@YAHPAVStream@@HH@Z",
    "?ExpandName@VirtualFileSystem@@SAXPADPAUVirtualFileInode@@PBD@Z=?ExpandName@VirtualFileSystem@@"
    "SAXPADPAUVirtualFileInode@@0@Z",
    "?Lookup@VirtualFileSystem@@SAPAUVirtualFileInode@@PAU2@HPBDPAD@Z=?Lookup@VirtualFileSystem@@SAPAUVirtualFileInode@"
    "@PAU2@HPAD1@Z",
    "?NormalizeName@VirtualFileSystem@@SAXPADPBD@Z=?NormalizeName@VirtualFileSystem@@SAXPAD0@Z",
    "?Hash@HashTable@@AAEIPBD@Z=?Hash@HashTable@@AAEHPAD@Z",
    "?AddSlider@asMidgets@@UAEPAVbkSlider@@PBDPADDDMVCallback@@@Z=?AddSlider@asMidgets@@UAEPAVbkSlider@@"
    "PAD0DDMVCallback@@@Z",
    "?Init@agiSurfaceDesc@@SAPAV1@HHABV1@@Z=?Init@agiSurfaceDesc@@SAPAV1@HHAAV1@@Z",
    "?ipcSpinUnlock@@YAXPAI@Z=?ipcSpunUnlock@@YAXPAI@Z",
    "?AddComponent@asPerfGraph@@QAEXPBDPAMABVVector3@@@Z=?AddComponent@asPerfGraph@@QAEXPADPAMAAVVector3@@@Z",
    "?arts_calloc_dbg@@YAPAXIIHPBDH@Z=__calloc_dbg",
    "?arts_free_dbg@@YAXPAXHPBDH@Z=__free_dbg",
    "?arts_malloc_dbg@@YAPAXIHPBDH@Z=__malloc_dbg",
    "?arts_msize@@YAIPAX@Z=__msize",
    "?arts_msize_dbg@@YAIPAXH@Z=__msize_dbg",
    "?arts_realloc_dbg@@YAPAXPAXIHPBDH@Z=__realloc_dbg",

    nullptr,
};

static SymbolInfo BaseSymbols[] {
    // clang-format off
    { 0x4010B0, 0x542C359C, 0x0000 }, // ?CreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
    { 0x4012D0, 0x3FEC0A83, 0x0000 }, // ?GenerateLoadScreenName@@YAHXZ
    { 0x4014B0, 0xA4453F3A, 0x0000 }, // ?GameFilter@@YAHPAU_EXCEPTION_POINTERS@@@Z
    { 0x4015A0, 0x9A3D9444, 0x0000 }, // ?GameLoop@@YAXPAVmmInterface@@PAVmmGameManager@@PAD@Z
    { 0x401830, 0x50F79112, 0x0000 }, // ?ApplicationHelper@@YAXHPAPAD@Z
    { 0x402E70, 0xB731A6DA, 0x0000 }, // ?TouchMemory@@YAXPAXH@Z
    { 0x402EC0, 0xDB3F601D, 0x0000 }, // ?exeDirFile@@YAPADPAD0@Z
    { 0x402F20, 0x3DC6CA2C, 0x0000 }, // ?GameCloseCallback@@YAXXZ
    { 0x402F40, 0x01201899, 0x0000 }, // ?InitAudioManager@@YAXXZ
    { 0x4030C0, 0xC38DAD14, 0x0000 }, // ?Application@@YAXHPAPAD@Z
    { 0x4031A0, 0x656B23C2, 0x0000 }, // _WinMain@16
    { 0x403CE0, 0xE0D962DF, 0x0000 }, // ?Update@mmScreenClearFlunky@@UAEXXZ
    { 0x403D10, 0x6AC56D52, 0x0000 }, // ?Cull@mmScreenClearFlunky@@UAEXXZ
    { 0x403E50, 0xCC152C8B, 0x0000 }, // ??0mmGameManager@@QAE@XZ
    { 0x404390, 0xB4C826A4, 0x0000 }, // ?randcall@@YAXXZ
    { 0x4043B0, 0x029C5F8A, 0x0000 }, // ??1mmGameManager@@UAE@XZ
    { 0x4044C0, 0x2EDDCE49, 0x0000 }, // ?BeDone@mmGameManager@@QAEXXZ
    { 0x4044D0, 0xC6C9115F, 0x0000 }, // ?Update@mmGameManager@@UAEXXZ
    { 0x4046D0, 0xEA66A8E5, 0x0000 }, // ?DoScan@@YAXPAX@Z
    { 0x404750, 0x036B5249, 0x0000 }, // ?Cull@mmGameManager@@UAEXXZ
    { 0x404790, 0x76B8CCEE, 0x0000 }, // ?StartReplay@mmGameManager@@QAEXXZ
    { 0x4047B0, 0x408DDB2A, 0x0000 }, // ?LoadReplay@mmGameManager@@QAEXPAD@Z
    { 0x404880, 0xF052C753, 0x0000 }, // ?SaveReplay@mmGameManager@@QAEXPAD@Z
    { 0x404910, 0x859C4E16, 0x0000 }, // ?Reset@mmGameManager@@UAEXXZ
    { 0x404920, 0x882D2DCE, 0x0000 }, // ?GetBrakes@mmGameManager@@QAEMXZ
    { 0x404950, 0xC4A8572C, 0x0000 }, // ?GetSteering@mmGameManager@@QAEMXZ
    { 0x404980, 0x0FDC4387, 0x0000 }, // ?GetThrottle@mmGameManager@@QAEMXZ
    { 0x4049B0, 0x0AEFD6E6, 0x0000 }, // ?AddWidgets@mmGameManager@@UAEXPAVBank@@@Z
    { 0x4049C0, 0xE2033284, 0x0000 }, // ?DeclareFields@mmGameManager@@SAXXZ
    { 0x404B30, 0xF7009987, 0x0000 }, // ?GetClass@mmGameManager@@UAEPAVMetaClass@@XZ
    { 0x404BA0, 0xC73986AB, 0x0000 }, // ??1mmScreenClearFlunky@@UAE@XZ
    { 0x404BB0, 0x31A86733, 0x0000 }, // ?UpdatePaused@asNode@@UAEXXZ
    { 0x404C20, 0x8917D52B, 0x0000 }, // ??0mmHUD@@QAE@XZ
    { 0x405060, 0xF73319FD, 0x0000 }, // ?PostChatMessage@mmHUD@@QAEXPAD@Z
    { 0x4050C0, 0x74BEA982, 0x0000 }, // ?ResChange@mmHUD@@UAEXHH@Z
    { 0x405190, 0x3CC55706, 0x0000 }, // ??1mmHUD@@UAE@XZ
    { 0x405320, 0x53537FB6, 0x0000 }, // ?StartTimers@mmHUD@@QAEXXZ
    { 0x405340, 0xF3918C48, 0x0000 }, // ?StopTimers@mmHUD@@QAEXXZ
    { 0x405360, 0x17662D44, 0x0000 }, // ?ResetTimers@mmHUD@@QAEXXZ
    { 0x405390, 0x47718683, 0x0000 }, // ?ShowClockTime@mmHUD@@QAEXXZ
    { 0x4053E0, 0xD216C7C0, 0x0000 }, // ?Init@mmHUD@@QAEXPADPAVmmPlayer@@@Z
    { 0x4056C0, 0x306F21AB, 0x0000 }, // ?Enable@mmHUD@@QAEXXZ
    { 0x405700, 0xFB4626CF, 0x0000 }, // ?Disable@mmHUD@@QAEXH@Z
    { 0x405750, 0x00ECE34C, 0x0000 }, // ?Toggle@mmHUD@@QAEXXZ
    { 0x405770, 0xA3E2ABA9, 0x0000 }, // ?ToggleExternalView@mmHUD@@QAEXXZ
    { 0x4057C0, 0x1BD8B3F8, 0x0000 }, // ?ToggleDash@mmHUD@@QAEXXZ
    { 0x405800, 0x4AF6889A, 0x0000 }, // ?ActivateDash@mmHUD@@QAEXXZ
    { 0x405830, 0xA4FA195F, 0x0000 }, // ?DeactivateDash@mmHUD@@QAEXXZ
    { 0x405860, 0x339639E4, 0x0000 }, // ?IsDashActive@mmHUD@@QAEHXZ
    { 0x405870, 0xA76B3848, 0x0000 }, // ?Reset@mmHUD@@UAEXXZ
    { 0x405910, 0xD28E01E2, 0x0000 }, // ?Update@mmHUD@@UAEXXZ
    { 0x405CE0, 0xC3C280CF, 0x0000 }, // ?UpdatePaused@mmHUD@@UAEXXZ
    { 0x405D10, 0x097E2052, 0x0000 }, // ?ToggleMirror@mmHUD@@QAEXXZ
    { 0x405D30, 0x6C5FBDFA, 0x0000 }, // ?Cull@mmHUD@@UAEXXZ
    { 0x405E00, 0x3DAAAE96, 0x0000 }, // ?SetStandings@mmHUD@@QAEXHH@Z
    { 0x405E40, 0x2D4E5E16, 0x0000 }, // ?SetLapTime@mmHUD@@QAEXHMH@Z
    { 0x405E80, 0x829BF40E, 0x0000 }, // ?SetWPCleared@mmHUD@@QAEXHH@Z
    { 0x405EA0, 0x172E7C41, 0x0000 }, // ?SetMessage@mmHUD@@QAEXPAULocString@@MH@Z
    { 0x405EE0, 0x434793E7, 0x0000 }, // ?SetMessage2@mmHUD@@QAEXPAULocString@@@Z
    { 0x405F10, 0xD054650A, 0x0000 }, // ?SetScore@mmHUD@@QAEXPAD@Z
    { 0x405F30, 0x05457B7C, 0x0000 }, // ?AddPlayer@mmHUD@@QAEXPADKHH@Z
    { 0x405F60, 0x9A525808, 0x0000 }, // ?SetScore@mmHUD@@QAEXKH@Z
    { 0x405F80, 0x47D6FB33, 0x0000 }, // ?RemovePlayer@mmHUD@@QAEXK@Z
    { 0x405FA0, 0xC387321D, 0x0000 }, // ?ActivateGold@mmHUD@@QAEXXZ
    { 0x405FB0, 0xF8406DDA, 0x0000 }, // ?DeactivateGold@mmHUD@@QAEXXZ
    { 0x405FC0, 0xDD1A35E3, 0x0000 }, // ?GetTime@mmHUD@@QAEXPADM@Z
    { 0x405FE0, 0xCDC1E008, 0x0000 }, // ?PlayNetAlert@mmHUD@@QAEXXZ
    { 0x406000, 0x1B15451A, 0x0000 }, // ?TogglePositionDisplay@mmHUD@@QAEXH@Z
    { 0x406060, 0x91375E86, 0x0000 }, // ?GetPosHdg@mmHUD@@QAEXAAVVector4@@@Z
    { 0x4060F0, 0xEB095E22, 0x0000 }, // ?RecordPosition@mmHUD@@QAEXPAD@Z
    { 0x406170, 0xD087DF57, 0x0000 }, // ?AddWidgets@mmHUD@@UAEXPAVBank@@@Z
    { 0x4061E0, 0x43C5FC3A, 0x0000 }, // ??0mmTimer@@QAE@XZ
    { 0x406200, 0x497928B9, 0x0000 }, // ??1mmTimer@@UAE@XZ
    { 0x406210, 0x142BAD42, 0x0000 }, // ?Init@mmTimer@@QAEXHM@Z
    { 0x406230, 0x13CE69E9, 0x0000 }, // ?GetTime@mmTimer@@QAEMXZ
    { 0x406240, 0x642002CD, 0x0000 }, // ?Update@mmTimer@@UAEXXZ
    { 0x406290, 0xE05703ED, 0x0000 }, // ?Reset@mmTimer@@UAEXXZ
    { 0x4062A0, 0x8369AF4C, 0x0000 }, // ?Start@mmTimer@@QAEXXZ
    { 0x4062B0, 0x1876DB5C, 0x0000 }, // ?Stop@mmTimer@@QAEXXZ
    { 0x4062C0, 0x456FF9F1, 0x0000 }, // ?StartStop@mmTimer@@QAEXXZ
    { 0x4062D0, 0x73961B4A, 0x0000 }, // ??0mmArrow@@QAE@XZ
    { 0x406450, 0x11A91FF3, 0x0000 }, // ??1mmArrow@@UAE@XZ
    { 0x4064C0, 0x8603D4B4, 0x0000 }, // ?Init@mmArrow@@QAEXPAVMatrix34@@@Z
    { 0x4064D0, 0xF3E50935, 0x0000 }, // ?Reset@mmArrow@@UAEXXZ
    { 0x4064E0, 0x8F66315E, 0x0000 }, // ?SetInterest@mmArrow@@QAEXPAVVector3@@@Z
    { 0x4064F0, 0x15DDAD18, 0x0000 }, // ?ReColorArrow@mmArrow@@AAEXH@Z
    { 0x406560, 0x785E0831, 0x0000 }, // ?Update@mmArrow@@UAEXXZ
    { 0x406760, 0x9531B3E0, 0x0000 }, // ?DeclareFields@mmHUD@@SAXXZ
    { 0x4068D0, 0x0317E67D, 0x0000 }, // ?GetClass@mmHUD@@UAEPAVMetaClass@@XZ
    { 0x406910, 0x0CF16B6F, 0x0000 }, // ??1mmExternalView@@UAE@XZ
    { 0x406960, 0xDEC1DA0C, 0x0000 }, // ??1mmCDPlayer@@UAE@XZ
    { 0x406A80, 0x8ED52484, 0x0000 }, // ?ReportTimeAlloc@@YAXM@Z
    { 0x406AC0, 0xC0DD2993, 0x0000 }, // ??0mmInterface@@QAE@XZ
    { 0x407A90, 0x44990D3A, 0x0000 }, // ?InitPlayerInfo@mmInterface@@QAEXXZ
    { 0x407E00, 0xC4F575C0, 0x0000 }, // ??1mmInterface@@UAE@XZ
    { 0x407F70, 0x9CAA99D7, 0x0000 }, // ?MessageCallback@mmInterface@@QAEXPAX0@Z
    { 0x408440, 0x8BA2B9C1, 0x0000 }, // ?MessageCallback2@mmInterface@@QAEXPAX0@Z
    { 0x408660, 0x221A3CE6, 0x0000 }, // ?Reset@mmInterface@@UAEXXZ
    { 0x408670, 0xE0E211F4, 0x0000 }, // ?ShowMain@mmInterface@@QAEXH@Z
    { 0x408790, 0xC8EA18D8, 0x0000 }, // ?ShowLockedVehicleMessage@mmInterface@@QAEXXZ
    { 0x4087B0, 0xD7328C91, 0x0000 }, // ?BeDone@mmInterface@@QAEXXZ
    { 0x4088A0, 0x81F37B84, 0x0000 }, // ?Update@mmInterface@@UAEXXZ
    { 0x409CD0, 0x4179C596, 0x0000 }, // ?IsModemDialin@@YA_NXZ
    { 0x409D50, 0x28A80291, 0x0000 }, // ?ZoneWatcher@@YGKPAX@Z
    { 0x409F00, 0x485567C7, 0x0000 }, // ?NetJoinCB@mmInterface@@AAEXXZ
    { 0x409F60, 0x6F6B5BE3, 0x0000 }, // ?NetNameCB@mmInterface@@AAEXXZ
    { 0x409F90, 0x5418894C, 0x0000 }, // ?JoinGame@mmInterface@@AAEXXZ
    { 0x40A010, 0x103B014A, 0x0000 }, // ?JoinLAN@mmInterface@@AAEXXZ
    { 0x40A070, 0x2CFA415E, 0x0000 }, // ?JoinSerial@mmInterface@@AAEHXZ
    { 0x40A100, 0x43A2EB30, 0x0000 }, // ?JoinModem@mmInterface@@AAEHXZ
    { 0x40A1F0, 0xCCDE1818, 0x0000 }, // ?UpdateLobby@mmInterface@@QAEXXZ
    { 0x40A7D0, 0x60340806, 0x0000 }, // ?Switch@mmInterface@@QAEXHH@Z
    { 0x40AB70, 0x81ECB972, 0x0000 }, // ?LobbySwitch@mmInterface@@QAEXHH@Z
    { 0x40ACA0, 0x7C2456EE, 0x0000 }, // ?RefreshCRPlayers@mmInterface@@AAEXXZ
    { 0x40AD40, 0x5FEEE926, 0x0000 }, // ?FillCRRoster@mmInterface@@AAEXXZ
    { 0x40AE40, 0x3E4DE737, 0x0000 }, // ?GetUnlockedCar@mmInterface@@AAEXXZ
    { 0x40AE90, 0x8AB37621, 0x0000 }, // ?RequestProverb@mmInterface@@AAEXXZ
    { 0x40AFF0, 0x61338865, 0x0000 }, // ?PlayerRemoveCB@mmInterface@@AAEXXZ
    { 0x40B020, 0x62C4FA42, 0x0000 }, // ?PlayerRemove@mmInterface@@AAEXPAD@Z
    { 0x40B1B0, 0xC5321030, 0x0000 }, // ?PlayerCreateCB@mmInterface@@AAEXXZ
    { 0x40B200, 0x240C9576, 0x0000 }, // ?PlayerCreate@mmInterface@@AAEHPAD@Z
    { 0x40B390, 0xA70BF099, 0x0000 }, // ?PlayerLoadCB@mmInterface@@AAEXXZ
    { 0x40B3C0, 0x769299BD, 0x0000 }, // ?PlayerGraphicsCB@mmInterface@@AAEXXZ
    { 0x40B430, 0x5CD794B6, 0x0000 }, // ?PlayerLoad@mmInterface@@AAEXPAD@Z
    { 0x40B4E0, 0xCFF13BCD, 0x0000 }, // ?PlayerSetState@mmInterface@@AAEXXZ
    { 0x40B6D0, 0xBE5CA17B, 0x0000 }, // ?CitySetupCB@mmInterface@@AAEXXZ
    { 0x40B790, 0x7085AFA2, 0x0000 }, // ?GetTimeString@mmInterface@@AAEXMPAD@Z
    { 0x40B7F0, 0x7B0F0CF7, 0x0000 }, // ?GetScoreString@mmInterface@@AAEXHPAD@Z
    { 0x40B830, 0x88279832, 0x0000 }, // ?GetRaceString@mmInterface@@AAEXHPAD@Z
    { 0x40B890, 0x9B2AFAD5, 0x0000 }, // ?GetRaceName@mmInterface@@AAEPADW4mmGameMode@@H@Z
    { 0x40B9F0, 0x87FC55E0, 0x0000 }, // ?RaceFillRecords@mmInterface@@AAEXXZ
    { 0x40C2E0, 0x67894A54, 0x0000 }, // ?PlayerFillStats@mmInterface@@AAEXXZ
    { 0x40C810, 0x390E6CE8, 0x0000 }, // ?PlayerResolveScore@mmInterface@@AAEXXZ
    { 0x40C950, 0xBCEE7983, 0x0000 }, // ?PlayerResolveCars@mmInterface@@AAEXXZ
    { 0x40CB20, 0x660CEE0A, 0x0000 }, // ?PlayerReadState@mmInterface@@AAEXXZ
    { 0x40CB40, 0x68439656, 0x0000 }, // ?RefreshDriverList@mmInterface@@AAEXXZ
    { 0x40CBF0, 0x6B7CBF95, 0x0000 }, // ?SetStateRace@mmInterface@@AAEXH@Z
    { 0x40CC00, 0x7170FF64, 0x0000 }, // ?SetStateDefaults@mmInterface@@AAEXXZ
    { 0x40CC20, 0x2D45D341, 0x0000 }, // ?InitNetwork@mmInterface@@AAEXXZ
    { 0x40CD10, 0xEB74F1A6, 0x0000 }, // ?InitLobby@mmInterface@@QAEXXZ
    { 0x40CD80, 0x86880CD5, 0x0000 }, // ?InitProtocols@mmInterface@@AAEXXZ
    { 0x40CDA0, 0xE6FCD36F, 0x0000 }, // ?ShowSessions@mmInterface@@AAEXXZ
    { 0x40CFA0, 0x2D76C587, 0x0000 }, // ?ClearSessions@mmInterface@@AAEXXZ
    { 0x40CFC0, 0xB479834B, 0x0000 }, // ?RefreshSessions@mmInterface@@AAEXXZ
    { 0x40D000, 0xC541BE24, 0x0000 }, // ?JoinSession@mmInterface@@AAEHH@Z
    { 0x40D200, 0x86C03541, 0x0000 }, // ?JoinPasswordSession@mmInterface@@AAEHH@Z
    { 0x40D3B0, 0xE02EFF39, 0x0000 }, // ?MultiStartGame@mmInterface@@AAEXXZ
    { 0x40D440, 0xE33905C4, 0x0000 }, // ?SetProtocol@mmInterface@@AAEXXZ
    { 0x40D4F0, 0xCDCAF5FA, 0x0000 }, // ?SetProtocol2@mmInterface@@AAEHXZ
    { 0x40D540, 0xC8B4FDAD, 0x0000 }, // ?CreatePlayer@mmInterface@@AAEHH@Z
    { 0x40D760, 0x9DF1627B, 0x0000 }, // ?GetHostPlayerData@mmInterface@@AAEHAAUmmPlayerInfo@@@Z
    { 0x40D7C0, 0x95CFB46A, 0x0000 }, // ?GetUniquePlayerName@mmInterface@@AAEXXZ
    { 0x40D8B0, 0xCA4BDF37, 0x0000 }, // ?ChangePlayerData@mmInterface@@AAEXXZ
    { 0x40D980, 0x49A4C78F, 0x0000 }, // ?RefreshPlayers@mmInterface@@AAEXXZ
    { 0x40DB80, 0xF26E33A6, 0x0000 }, // ?GetSessionData@mmInterface@@AAEXUNETSESSION_DESC@@@Z
    { 0x40DC40, 0x76C73611, 0x0000 }, // ?CreateSession@mmInterface@@AAEHXZ
    { 0x40DDC0, 0x4C8F7CEF, 0x0000 }, // ?SetSessionData@mmInterface@@AAEXPAUNETSESSION_DESC@@@Z
    { 0x40DE80, 0x712E55A8, 0x0000 }, // ?SetCRStateData@mmInterface@@AAEXXZ
    { 0x40DEF0, 0x04294AD4, 0x0000 }, // ?LobbyCreate@mmInterface@@AAEXXZ
    { 0x40E250, 0x8294B5FD, 0x0000 }, // ?SendChatMessage@mmInterface@@AAEXPAX@Z
    { 0x40E2F0, 0x3DB44613, 0x0000 }, // ?SendMsg@mmInterface@@AAEXH@Z
    { 0x40E330, 0x084B918B, 0x0000 }, // ?SendBootMsg@mmInterface@@AAEXK@Z
    { 0x40E370, 0xE9BDABE8, 0x0000 }, // ?SendReadyStatus@mmInterface@@AAEXXZ
    { 0x40E3B0, 0xAFA2C384, 0x0000 }, // ?SendReadyReq@mmInterface@@AAEXXZ
    { 0x40E3E0, 0xF729FF4B, 0x0000 }, // ?SetupArchiveTest@mmInterface@@QAEXAAH@Z
    { 0x40E660, 0xEA06F6AD, 0x0000 }, // ?DeclareFields@mmInterface@@SAXXZ
    { 0x40E7D0, 0xF7BFFFBC, 0x0000 }, // ?GetClass@mmInterface@@UAEPAVMetaClass@@XZ
    { 0x40E7E0, 0x0BA1CEAF, 0x0000 }, // ??1string@@QAE@XZ
    { 0x40E880, 0xE6B198B1, 0x0000 }, // ??0mmGame@@QAE@XZ
    { 0x40EA00, 0xD98AAA5D, 0x0000 }, // ?Init@mmGame@@QAEHXZ
    { 0x40F8C0, 0x1E9A9DC8, 0x0000 }, // ?InitOtherPlayers@mmGame@@UAEXXZ
    { 0x40F9C0, 0x339EB8A0, 0x0000 }, // ?CollideAIOpponents@mmGame@@QAEXXZ
    { 0x40FAC0, 0x8BE7ADB5, 0x0000 }, // ?InitGameStrings@mmGame@@UAEXXZ
    { 0x40FDB0, 0x9CAC3634, 0x0000 }, // ??1mmGame@@UAE@XZ
    { 0x410050, 0x476E955D, 0x0000 }, // ?Stats@mmGame@@QAEXXZ
    { 0x410130, 0x0B72F854, 0x0000 }, // ?RespawnXYZ@mmGame@@IAEXAAVVector3@@AAM@Z
    { 0x410230, 0x197DA971, 0x0000 }, // ?IsPopupEnabled@mmGame@@QAEHXZ
    { 0x410240, 0x1044216B, 0x0000 }, // ?Reset@mmGame@@UAEXXZ
    { 0x4102A0, 0xE1BE0DFA, 0x0000 }, // ?Update@mmGame@@UAEXXZ
    { 0x410490, 0x694EA217, 0x0000 }, // ?DropThruCityHandler@mmGame@@UAEXXZ
    { 0x4104A0, 0xF23585A3, 0x0000 }, // ?HitWaterHandler@mmGame@@UAEXXZ
    { 0x4104B0, 0x9EFDE145, 0x0000 }, // ?UpdateDebugInput@mmGame@@UAEXXZ
    { 0x410DA0, 0xECDBB1A5, 0x0000 }, // ?UpdatePaused@mmGame@@UAEXXZ
    { 0x410E90, 0xC8D0E328, 0x0000 }, // ?UpdateGameInput@mmGame@@QAEXXZ
    { 0x411320, 0x6C20F7E9, 0x0000 }, // ?UpdateSteeringBrakes@mmGame@@QAEXXZ
    { 0x411400, 0xEF8754BB, 0x0000 }, // ?SetIconsState@mmGame@@QAEXXZ
    { 0x411420, 0x8B02BD6C, 0x0000 }, // ?PlayerSetState@mmGame@@QAEXXZ
    { 0x411520, 0x3E38B110, 0x0000 }, // ?CalculateRaceScore@mmGame@@IAEHHH@Z
    { 0x411590, 0xC3CA8319, 0x0000 }, // ?SendChatMessage@mmGame@@UAEXPAD@Z
    { 0x411960, 0x8B2BCC2D, 0x0000 }, // ?GetCDTrack@mmGame@@QAEHF@Z
    { 0x411E30, 0xE5C23B4E, 0x0000 }, // ?AddWidgets@mmGame@@UAEXPAVBank@@@Z
    { 0x411EE0, 0xAD93C740, 0x0000 }, // ?Update@foobar@@EAEXXZ
    { 0x411F10, 0xFC32D895, 0x0000 }, // ?UpdatePaused@foobar@@EAEXXZ
    { 0x411F20, 0x0A857345, 0x0000 }, // ?DeclareFields@mmGame@@SAXXZ
    { 0x411FC0, 0xEF6DFD62, 0x0000 }, // ?GetClass@mmGame@@UAEPAVMetaClass@@XZ
    { 0x412150, 0xD88875C2, 0x0000 }, // ??0mmGameEdit@@QAE@XZ
    { 0x412220, 0x070D8299, 0x0000 }, // ??1mmGameEdit@@UAE@XZ
    { 0x4122D0, 0xB1029D2E, 0x0000 }, // ?Init@mmGameEdit@@QAEHXZ
    { 0x412380, 0xC7102C50, 0x0000 }, // ?InitMyPlayer@mmGameEdit@@UAEXXZ
    { 0x4123F0, 0x64B9F00C, 0x0000 }, // ?InitHUD@mmGameEdit@@UAEXXZ
    { 0x412430, 0x45D60C03, 0x0000 }, // ?InitGameObjects@mmGameEdit@@UAEXXZ
    { 0x412520, 0xEA4DEA59, 0x0000 }, // ?RegisterMapObjects@mmGameEdit@@QAEXXZ
    { 0x412570, 0x0829EA6B, 0x0000 }, // ?UpdateDebugKeyInput@mmGameEdit@@UAEXH@Z
    { 0x412760, 0x60315F0C, 0x0000 }, // ?Reset@mmGameEdit@@UAEXXZ
    { 0x4127F0, 0xCD815F6A, 0x0000 }, // ?Update@mmGameEdit@@UAEXXZ
    { 0x412810, 0xC711F351, 0x0000 }, // ?UpdateGameInput@mmGameEdit@@UAEXH@Z
    { 0x412820, 0x12C7FF47, 0x0000 }, // ?UpdateGame@mmGameEdit@@UAEXXZ
    { 0x412860, 0xEB4B7758, 0x0000 }, // ?AddWidgets@mmGameEdit@@UAEXPAVBank@@@Z
    { 0x412A80, 0xF73D0C32, 0x0000 }, // ?SetWPCallback@mmGameEdit@@QAEXXZ
    { 0x412B20, 0x554513D7, 0x0000 }, // ?ChangeWPCallback@mmGameEdit@@QAEXXZ
    { 0x412B80, 0x0ED76999, 0x0000 }, // ?DeclareFields@mmGameEdit@@SAXXZ
    { 0x412D00, 0x4B919700, 0x0000 }, // ?GetClass@mmGameEdit@@UAEPAVMetaClass@@XZ
    { 0x412EC0, 0xE36DD780, 0x0000 }, // ?InitOtherPlayers@mmGameEdit@@UAEXXZ
    { 0x412ED0, 0x2F1AC4ED, 0x0000 }, // ?NextRace@mmGameEdit@@UAEXXZ
    { 0x412EE0, 0xE72C8BBB, 0x0000 }, // ?GetWaypoints@mmGameEdit@@UAEPAVmmWaypoints@@XZ
    { 0x412EF0, 0xD6D4682F, 0x0000 }, // ??0mmSingleBlitz@@QAE@XZ
    { 0x412F90, 0x2E83D59C, 0x0000 }, // ??1mmSingleBlitz@@UAE@XZ
    { 0x413060, 0x27A76DB9, 0x0000 }, // ?Init@mmSingleBlitz@@QAEHXZ
    { 0x4131E0, 0xDC080AC0, 0x0000 }, // ?InitMyPlayer@mmSingleBlitz@@UAEXXZ
    { 0x413250, 0x1236D477, 0x0000 }, // ?InitHUD@mmSingleBlitz@@UAEXXZ
    { 0x4132D0, 0x8933531E, 0x0000 }, // ?InitGameObjects@mmSingleBlitz@@UAEXXZ
    { 0x413540, 0x08D78E8A, 0x0000 }, // ?InitOtherPlayers@mmSingleBlitz@@UAEXXZ
    { 0x413550, 0x2E7A51B0, 0x0000 }, // ?Reset@mmSingleBlitz@@UAEXXZ
    { 0x413660, 0xDC9ED3B4, 0x0000 }, // ?EnableRacers@mmSingleBlitz@@AAEXXZ
    { 0x4136F0, 0x2532067B, 0x0000 }, // ?DisableRacers@mmSingleBlitz@@AAEXXZ
    { 0x413760, 0xD71F2920, 0x0000 }, // ?HitWaterHandler@mmSingleBlitz@@UAEXXZ
    { 0x413800, 0xF2E633DE, 0x0000 }, // ?Update@mmSingleBlitz@@UAEXXZ
    { 0x413820, 0xFB249AE1, 0x0000 }, // ?UpdateGameInput@mmSingleBlitz@@UAEXH@Z
    { 0x413860, 0x08198B66, 0x0000 }, // ?UpdateGame@mmSingleBlitz@@UAEXXZ
    { 0x4140C0, 0x8AAA4698, 0x0000 }, // ?RegisterFinish@mmSingleBlitz@@AAEHXZ
    { 0x4143F0, 0x7CC98F1D, 0x0000 }, // ?FinishMessage@mmSingleBlitz@@AAEXH@Z
    { 0x414420, 0x8E10EC16, 0x0000 }, // ?ProgressCheck@mmSingleBlitz@@AAEHHH@Z
    { 0x4144F0, 0xD83B5DEF, 0x0000 }, // ?NextRace@mmSingleBlitz@@UAEXXZ
    { 0x414660, 0x489E0F00, 0x0000 }, // ?PlayTimerWarning@mmSingleBlitz@@QAEXM@Z
    { 0x414740, 0xF1E98151, 0x0000 }, // ?DeclareFields@mmSingleBlitz@@SAXXZ
    { 0x4148B0, 0xFCE6DF14, 0x0000 }, // ?GetClass@mmSingleBlitz@@UAEPAVMetaClass@@XZ
    { 0x414A10, 0xC4962919, 0x0000 }, // ??1foobar@@UAE@XZ
    { 0x414A50, 0x6346F577, 0x0000 }, // ??0mmPlayerRecord@@QAE@ABV0@@Z
    { 0x414BC0, 0xB33AC199, 0x0000 }, // ??1mmInfoBase@@UAE@XZ
    { 0x414BD0, 0xA976BB87, 0x0000 }, // ?UpdateDebugKeyInput@mmSingleBlitz@@UAEXH@Z
    { 0x414BE0, 0x66BF9D76, 0x0000 }, // ?GetWaypoints@mmSingleBlitz@@UAEPAVmmWaypoints@@XZ
    { 0x414BF0, 0x4D846F3B, 0x0000 }, // ??0mmSingleCircuit@@QAE@XZ
    { 0x414C90, 0x167A9A0E, 0x0000 }, // ??1mmSingleCircuit@@UAE@XZ
    { 0x414D50, 0x2601916B, 0x0000 }, // ?Init@mmSingleCircuit@@QAEHXZ
    { 0x414ED0, 0xDA99D85C, 0x0000 }, // ?InitMyPlayer@mmSingleCircuit@@UAEXXZ
    { 0x414F40, 0xB92A2AE3, 0x0000 }, // ?InitHUD@mmSingleCircuit@@UAEXXZ
    { 0x414F90, 0x1374BCA5, 0x0000 }, // ?InitGameObjects@mmSingleCircuit@@UAEXXZ
    { 0x415200, 0xC416CBB9, 0x0000 }, // ?InitOtherPlayers@mmSingleCircuit@@UAEXXZ
    { 0x415210, 0x8797E310, 0x0000 }, // ?Reset@mmSingleCircuit@@UAEXXZ
    { 0x4152E0, 0x38379DC6, 0x0000 }, // ?HitWaterHandler@mmSingleCircuit@@UAEXXZ
    { 0x415390, 0x43D655D1, 0x0000 }, // ?EnableRacers@mmSingleCircuit@@AAEXXZ
    { 0x415420, 0xB3EE00E2, 0x0000 }, // ?DisableRacers@mmSingleCircuit@@AAEXXZ
    { 0x415490, 0xF7AE95EE, 0x0000 }, // ?Update@mmSingleCircuit@@UAEXXZ
    { 0x4154B0, 0xF516EC29, 0x0000 }, // ?UpdateGameInput@mmSingleCircuit@@UAEXH@Z
    { 0x4154C0, 0x56385635, 0x0000 }, // ?UpdateScore@mmSingleCircuit@@QAEXXZ
    { 0x415850, 0xBBEAAB79, 0x0000 }, // ?UpdateGame@mmSingleCircuit@@UAEXXZ
    { 0x415FE0, 0x907FCEB3, 0x0000 }, // ?FinishMessage@mmSingleCircuit@@AAEXHH@Z
    { 0x416170, 0xDE45B537, 0x0000 }, // ?RegisterLap@mmSingleCircuit@@AAEHXZ
    { 0x4161D0, 0xF0B64EFE, 0x0000 }, // ?RegisterFinish@mmSingleCircuit@@AAEHXZ
    { 0x4165F0, 0x48EABFD7, 0x0000 }, // ?ProgressCheck@mmSingleCircuit@@AAEHHH@Z
    { 0x416620, 0x6388DE30, 0x0000 }, // ?NextRace@mmSingleCircuit@@UAEXXZ
    { 0x4167A0, 0xA807AEF2, 0x0000 }, // ?AddWidgets@mmSingleCircuit@@UAEXPAVBank@@@Z
    { 0x416940, 0x2FAD8507, 0x0000 }, // ?DeclareFields@mmSingleCircuit@@SAXXZ
    { 0x416AB0, 0x365342E3, 0x0000 }, // ?GetClass@mmSingleCircuit@@UAEPAVMetaClass@@XZ
    { 0x416C70, 0x22F5C149, 0x0000 }, // ?UpdateDebugKeyInput@mmSingleCircuit@@UAEXH@Z
    { 0x416C80, 0x76EB2CEE, 0x0000 }, // ?GetWaypoints@mmSingleCircuit@@UAEPAVmmWaypoints@@XZ
    { 0x416C90, 0xAB9E1934, 0x0000 }, // ?ThreadFunc@@YGKPAX@Z
    { 0x416CA0, 0xBD7D42ED, 0x0000 }, // ??0mmGameSingle@@QAE@XZ
    { 0x416D30, 0x2AF393DA, 0x0000 }, // ??1mmGameSingle@@UAE@XZ
    { 0x416DF0, 0x5EDFDEBA, 0x0000 }, // ?Init@mmGameSingle@@QAEHXZ
    { 0x416F70, 0xBBA54C34, 0x0000 }, // ?InitMyPlayer@mmGameSingle@@UAEXXZ
    { 0x416FE0, 0xE997AA31, 0x0000 }, // ?InitHUD@mmGameSingle@@UAEXXZ
    { 0x417040, 0x224075E9, 0x0000 }, // ?InitGameObjects@mmGameSingle@@UAEXXZ
    { 0x417340, 0x6B42181E, 0x0000 }, // ?InitOtherPlayers@mmGameSingle@@UAEXXZ
    { 0x4173A0, 0xD3EB7BF0, 0x0000 }, // ?Reset@mmGameSingle@@UAEXXZ
    { 0x4174A0, 0x7801F15E, 0x0000 }, // ?EnableRacers@mmGameSingle@@AAEXXZ
    { 0x417530, 0xACF0D663, 0x0000 }, // ?DisableRacers@mmGameSingle@@AAEXXZ
    { 0x4175A0, 0x73F071F4, 0x0000 }, // ?HitWaterHandler@mmGameSingle@@UAEXXZ
    { 0x417640, 0x543EA99C, 0x0000 }, // ?Update@mmGameSingle@@UAEXXZ
    { 0x417660, 0x2FCF2777, 0x0000 }, // ?UpdateGameInput@mmGameSingle@@UAEXH@Z
    { 0x4176A0, 0xC3F866C8, 0x0000 }, // ?UpdateGame@mmGameSingle@@UAEXXZ
    { 0x417EF0, 0x69273991, 0x0000 }, // ?UpdateScore@mmGameSingle@@QAEXXZ
    { 0x418270, 0x3D65DC4E, 0x0000 }, // ?FinishMessage@mmGameSingle@@AAEXHH@Z
    { 0x4183F0, 0x751DF112, 0x0000 }, // ?RegisterFinish@mmGameSingle@@AAEHXZ
    { 0x4187F0, 0x2F8F73C9, 0x0000 }, // ?ProgressCheck@mmGameSingle@@AAEHHH@Z
    { 0x418840, 0xDD1BF32B, 0x0000 }, // ?NextRace@mmGameSingle@@UAEXXZ
    { 0x4189E0, 0x924D2B2C, 0x0000 }, // ?AddWidgets@mmGameSingle@@UAEXPAVBank@@@Z
    { 0x418B90, 0xCDBE1F8A, 0x0000 }, // ?DeclareFields@mmGameSingle@@SAXXZ
    { 0x418D00, 0xB980FC93, 0x0000 }, // ?GetClass@mmGameSingle@@UAEPAVMetaClass@@XZ
    { 0x418EC0, 0x22B34E78, 0x0000 }, // ?UpdateDebugKeyInput@mmGameSingle@@UAEXH@Z
    { 0x418ED0, 0xCF80E264, 0x0000 }, // ?GetWaypoints@mmGameSingle@@UAEPAVmmWaypoints@@XZ
    { 0x418EE0, 0xF8D25002, 0x0000 }, // ??0mmMultiBlitz@@QAE@XZ
    { 0x418F50, 0x5118FB65, 0x0000 }, // ??1mmMultiBlitz@@UAE@XZ
    { 0x419010, 0xD7E2D290, 0x0000 }, // ?Init@mmMultiBlitz@@QAEHXZ
    { 0x419140, 0xD611C41F, 0x0000 }, // ?InitMyPlayer@mmMultiBlitz@@UAEXXZ
    { 0x4191B0, 0xD3FAD324, 0x0000 }, // ?InitHUD@mmMultiBlitz@@UAEXXZ
    { 0x419230, 0x0C3D88B4, 0x0000 }, // ?InitGameObjects@mmMultiBlitz@@UAEXXZ
    { 0x4194C0, 0x26E662A6, 0x0000 }, // ?InitNetworkPlayers@mmMultiBlitz@@UAEXXZ
    { 0x419820, 0xADE4E141, 0x0000 }, // ?Reset@mmMultiBlitz@@UAEXXZ
    { 0x4198D0, 0x32835904, 0x0000 }, // ?UpdateGameInput@mmMultiBlitz@@UAEXH@Z
    { 0x419910, 0xA87B1618, 0x0000 }, // ?UpdateGame@mmMultiBlitz@@UAEXXZ
    { 0x41A030, 0xE7D795D5, 0x0000 }, // ?SystemMessage@mmMultiBlitz@@UAEXPAUNETSYS_MSG@@@Z
    { 0x41A1C0, 0xD1A88654, 0x0000 }, // ?GameMessage@mmMultiBlitz@@UAEXPAUNETGAME_MSG@@@Z
    { 0x41A420, 0x3F47EA8A, 0x0000 }, // ?SendPlayerFinish@mmMultiBlitz@@AAEXXZ
    { 0x41A470, 0xCB3B0E18, 0x0000 }, // ?PlayTimerWarning@mmMultiBlitz@@QAEXM@Z
    { 0x41A550, 0x8B8BB576, 0x0000 }, // ?DeclareFields@mmMultiBlitz@@SAXXZ
    { 0x41A6D0, 0x2F2090D8, 0x0000 }, // ?GetClass@mmMultiBlitz@@UAEPAVMetaClass@@XZ
    { 0x41A890, 0x690403E0, 0x0000 }, // ?NextRace@mmGameMulti@@UAEXXZ
    { 0x41A8A0, 0x893177B2, 0x0000 }, // ?GetWaypoints@mmMultiBlitz@@UAEPAVmmWaypoints@@XZ
    { 0x41A8B0, 0xB020AF3A, 0x0000 }, // ??0mmMultiCircuit@@QAE@XZ
    { 0x41A920, 0xC4789F40, 0x0000 }, // ??1mmMultiCircuit@@UAE@XZ
    { 0x41A9E0, 0xFF13F097, 0x0000 }, // ?Init@mmMultiCircuit@@QAEHXZ
    { 0x41AB00, 0x76D06CD0, 0x0000 }, // ?InitMyPlayer@mmMultiCircuit@@UAEXXZ
    { 0x41AB70, 0x5EB77FEB, 0x0000 }, // ?InitHUD@mmMultiCircuit@@UAEXXZ
    { 0x41ABC0, 0xED1CD282, 0x0000 }, // ?InitGameObjects@mmMultiCircuit@@UAEXXZ
    { 0x41AE30, 0x03DE7D91, 0x0000 }, // ?InitNetworkPlayers@mmMultiCircuit@@UAEXXZ
    { 0x41B190, 0xDA9140A5, 0x0000 }, // ?Reset@mmMultiCircuit@@UAEXXZ
    { 0x41B230, 0x5B0D4D04, 0x0000 }, // ?UpdateGameInput@mmMultiCircuit@@UAEXH@Z
    { 0x41B270, 0x9463B748, 0x0000 }, // ?UpdateGame@mmMultiCircuit@@UAEXXZ
    { 0x41B820, 0x66B3CA0F, 0x0000 }, // ?UpdateDebugKeyInput@mmMultiCircuit@@UAEXH@Z
    { 0x41B830, 0xCD696565, 0x0000 }, // ?SystemMessage@mmMultiCircuit@@UAEXPAUNETSYS_MSG@@@Z
    { 0x41B9C0, 0xF8A47D4E, 0x0000 }, // ?GameMessage@mmMultiCircuit@@UAEXPAUNETGAME_MSG@@@Z
    { 0x41BC20, 0xF144D387, 0x0000 }, // ?SendPlayerFinish@mmMultiCircuit@@AAEXXZ
    { 0x41BC60, 0x5600C1ED, 0x0000 }, // ?DeclareFields@mmMultiCircuit@@SAXXZ
    { 0x41BDE0, 0x0C0AE0DD, 0x0000 }, // ?GetClass@mmMultiCircuit@@UAEPAVMetaClass@@XZ
    { 0x41BFA0, 0x05E630C5, 0x0000 }, // ?GetWaypoints@mmMultiCircuit@@UAEPAVmmWaypoints@@XZ
    { 0x41BFB0, 0x137E07E5, 0x0000 }, // ??0mmMultiCR@@QAE@XZ
    { 0x41C070, 0x55A883E2, 0x0000 }, // ??1mmMultiCR@@UAE@XZ
    { 0x41C140, 0xC20F101C, 0x0000 }, // ?Init@mmMultiCR@@QAEHXZ
    { 0x41C2A0, 0xA313D6B8, 0x0000 }, // ?InitMyPlayer@mmMultiCR@@UAEXXZ
    { 0x41C3A0, 0x07527343, 0x0000 }, // ?InitHUD@mmMultiCR@@UAEXXZ
    { 0x41C4E0, 0x4415F9DF, 0x0000 }, // ?InitGameObjects@mmMultiCR@@UAEXXZ
    { 0x41C940, 0x3426ABCB, 0x0000 }, // ?InitNetworkPlayers@mmMultiCR@@UAEXXZ
    { 0x41CCC0, 0x851427FA, 0x0000 }, // ?Reset@mmMultiCR@@UAEXXZ
    { 0x41CEA0, 0x6E7E8436, 0x0000 }, // ?LoadSets@mmMultiCR@@QAEHPAD@Z
    { 0x41CF40, 0xB37815E1, 0x0000 }, // ?LoadCSV@mmMultiCR@@QAEHPAD@Z
    { 0x41D090, 0xE94EF7A9, 0x0000 }, // ?ImpactCallback@mmMultiCR@@QAEXXZ
    { 0x41D180, 0x2C33CA5D, 0x0000 }, // ?FondleCarMass@mmMultiCR@@QAEXPAVmmCar@@M@Z
    { 0x41D1A0, 0x4E63B2FC, 0x0000 }, // ?ChangePlayerData@mmMultiCR@@QAEXXZ
    { 0x41D1F0, 0xC79A4703, 0x0000 }, // ?GetRandomIndex@mmMultiCR@@AAEHXZ
    { 0x41D210, 0xBE923771, 0x0000 }, // ?ResetPositions@mmMultiCR@@QAEXH@Z
    { 0x41D330, 0xAB86DCA7, 0x0000 }, // ?SelectTeams@mmMultiCR@@AAEHXZ
    { 0x41D340, 0x2CCA8747, 0x0000 }, // ?UpdateGameInput@mmMultiCR@@UAEXH@Z
    { 0x41D380, 0x9AEF4C66, 0x0000 }, // ?UpdateGame@mmMultiCR@@UAEXXZ
    { 0x41D760, 0xE22CB2F8, 0x0000 }, // ?HitWaterHandler@mmMultiCR@@UAEXXZ
    { 0x41D810, 0xA51B32CA, 0x0000 }, // ?DropThruCityHandler@mmMultiCR@@UAEXXZ
    { 0x41D8C0, 0xAF4E7803, 0x0000 }, // ?StealGold@mmMultiCR@@AAEXPAVmmCar@@@Z
    { 0x41D900, 0xC9FD33DA, 0x0000 }, // ?OppStealGold@mmMultiCR@@AAEXH@Z
    { 0x41D970, 0x7CB12A9E, 0x0000 }, // ?FindGround@mmMultiCR@@AAEXVVector3@@AAV2@@Z
    { 0x41DA30, 0xAADE9BE6, 0x0000 }, // ?DropGold@mmMultiCR@@AAEXVVector3@@H@Z
    { 0x41DC20, 0x1F6085D3, 0x0000 }, // ?UpdateGold@mmMultiCR@@AAEXXZ
    { 0x41DE50, 0xB703E5A1, 0x0000 }, // ?UpdateHideout@mmMultiCR@@AAEXXZ
    { 0x41DFA0, 0x4B4F9557, 0x0000 }, // ?UpdateBank@mmMultiCR@@AAEXXZ
    { 0x41E0F0, 0x23233860, 0x0000 }, // ?UpdateLimit@mmMultiCR@@AAEXXZ
    { 0x41E290, 0x9C805F6D, 0x0000 }, // ?FillResults@mmMultiCR@@AAEXXZ
    { 0x41E490, 0xAB61E4D4, 0x0000 }, // ?SystemMessage@mmMultiCR@@UAEXPAUNETSYS_MSG@@@Z
    { 0x41E6E0, 0x50044F14, 0x0000 }, // ?GameMessage@mmMultiCR@@UAEXPAUNETGAME_MSG@@@Z
    { 0x41EFC0, 0x766FA611, 0x0000 }, // ?UpdateTimeWarning@mmMultiCR@@AAEXXZ
    { 0x41F130, 0x2E3456F7, 0x0000 }, // ?DisplayTimeWarning@mmMultiCR@@AAEXH@Z
    { 0x41F1C0, 0x8D67667C, 0x0000 }, // ?SendGameState@mmMultiCR@@AAEXK@Z
    { 0x41F260, 0x26EE1554, 0x0000 }, // ?SendSetup@mmMultiCR@@AAEXK@Z
    { 0x41F270, 0x98A42F61, 0x0000 }, // ?SendGoldDrop@mmMultiCR@@AAEXVVector3@@@Z
    { 0x41F2C0, 0x2578B091, 0x0000 }, // ?SendGoldAck@mmMultiCR@@AAEXK@Z
    { 0x41F300, 0xC2C5D115, 0x0000 }, // ?SendGoldDeliver@mmMultiCR@@AAEXXZ
    { 0x41F350, 0x3F066835, 0x0000 }, // ?SendChangeSet@mmMultiCR@@AAEXH@Z
    { 0x41F390, 0xF0BCBF43, 0x0000 }, // ?SendLimitReached@mmMultiCR@@AAEXH@Z
    { 0x41F3D0, 0x16F698AF, 0x0000 }, // ?SendTimeWarning@mmMultiCR@@AAEXH@Z
    { 0x41F410, 0x494125D8, 0x0000 }, // ?UpdateHUD@mmMultiCR@@AAEXXZ
    { 0x41F530, 0xCE359F20, 0x0000 }, // ?Score@mmMultiCR@@AAEXH@Z
    { 0x41F560, 0x054FE103, 0x0000 }, // ?UpdateDebugKeyInput@mmMultiCR@@UAEXH@Z
    { 0x41F570, 0x803C081E, 0x0000 }, // ?CycleInterest@mmMultiCR@@AAEXH@Z
    { 0x41F5E0, 0xB582AE4C, 0x0000 }, // ?DeclareFields@mmMultiCR@@SAXXZ
    { 0x41F760, 0x636CD2EF, 0x0000 }, // ?GetClass@mmMultiCR@@UAEPAVMetaClass@@XZ
    { 0x41F920, 0xA4E9CE8F, 0x0000 }, // ?GetWaypoints@mmMultiCR@@UAEPAVmmWaypoints@@XZ
    { 0x41F930, 0x52D3A8D2, 0x0000 }, // ??0mmMultiRace@@QAE@XZ
    { 0x41F9A0, 0x54BD8CE7, 0x0000 }, // ??1mmMultiRace@@UAE@XZ
    { 0x41FA60, 0x3A2511B0, 0x0000 }, // ?Init@mmMultiRace@@QAEHXZ
    { 0x41FBA0, 0x518C0D7D, 0x0000 }, // ?InitMyPlayer@mmMultiRace@@UAEXXZ
    { 0x41FC10, 0xC9B6A6EE, 0x0000 }, // ?InitHUD@mmMultiRace@@UAEXXZ
    { 0x41FC70, 0xE8C48043, 0x0000 }, // ?InitGameObjects@mmMultiRace@@UAEXXZ
    { 0x41FF40, 0x0813231F, 0x0000 }, // ?InitNetworkPlayers@mmMultiRace@@UAEXXZ
    { 0x420370, 0x348B750F, 0x0000 }, // ?Reset@mmMultiRace@@UAEXXZ
    { 0x420480, 0x84346BE5, 0x0000 }, // ?ChangePlayerData@mmMultiRace@@QAEXXZ
    { 0x4204D0, 0xAE1A0016, 0x0000 }, // ?UpdateGameInput@mmMultiRace@@UAEXH@Z
    { 0x420510, 0x94ADB19F, 0x0000 }, // ?UpdateGame@mmMultiRace@@UAEXXZ
    { 0x420D10, 0xD0946011, 0x0000 }, // ?SystemMessage@mmMultiRace@@UAEXPAUNETSYS_MSG@@@Z
    { 0x420EE0, 0x5FDF3AFD, 0x0000 }, // ?GameMessage@mmMultiRace@@UAEXPAUNETGAME_MSG@@@Z
    { 0x421240, 0x100B29F2, 0x0000 }, // ?SendPlayerFinish@mmMultiRace@@AAEXXZ
    { 0x421280, 0xEE7E82CA, 0x0000 }, // ?DeclareFields@mmMultiRace@@SAXXZ
    { 0x421400, 0xE96FC5D6, 0x0000 }, // ?GetClass@mmMultiRace@@UAEPAVMetaClass@@XZ
    { 0x4215C0, 0xBC2A2B11, 0x0000 }, // ?GetWaypoints@mmMultiRace@@UAEPAVmmWaypoints@@XZ
    { 0x4215D0, 0x0F4390F7, 0x0000 }, // ??0mmDashView@@QAE@XZ
    { 0x421770, 0x61649CF1, 0x0000 }, // ??1mmDashView@@UAE@XZ
    { 0x421880, 0xDFE79B20, 0x0000 }, // ?Init@mmDashView@@QAEXPADPAVmmPlayer@@@Z
    { 0x421C10, 0x7A525E55, 0x0000 }, // ?Reset@mmDashView@@UAEXXZ
    { 0x421C20, 0xA02AE787, 0x0000 }, // ?BeforeSave@mmDashView@@UAEXXZ
    { 0x421CC0, 0x73170616, 0x0000 }, // ?AfterLoad@mmDashView@@UAEXXZ
    { 0x421D60, 0x338AB81E, 0x0000 }, // ?ActivateUntilTransitionIsOver@mmDashView@@QAEXXZ
    { 0x421D80, 0x71068188, 0x0000 }, // ?Activate@mmDashView@@QAEXXZ
    { 0x421DA0, 0xC855DBB9, 0x0000 }, // ?Deactivate@mmDashView@@QAEXXZ
    { 0x421DC0, 0x2B22D270, 0x0000 }, // ?TempDeactivate@mmDashView@@QAEXXZ
    { 0x421DD0, 0x8508C301, 0x0000 }, // ?Update@mmDashView@@UAEXXZ
    { 0x421F00, 0xF4B6709B, 0x0000 }, // ?Cull@mmDashView@@UAEXXZ
    { 0x4220F0, 0xDFE387D6, 0x0000 }, // ??0mmExternalView@@QAE@XZ
    { 0x422170, 0x18415FBE, 0x0000 }, // ?Init@mmExternalView@@QAEXPAVmmPlayer@@@Z
    { 0x4221B0, 0xECAB44AB, 0x0000 }, // ?ResChange@mmExternalView@@UAEXHH@Z
    { 0x422300, 0x3CCC9A0F, 0x0000 }, // ?Reset@mmExternalView@@UAEXXZ
    { 0x422310, 0x6C90779B, 0x0000 }, // ?Update@mmExternalView@@UAEXXZ
    { 0x422330, 0xBFC28F36, 0x0000 }, // ?WideFOV@mmExternalView@@QAEXH@Z
    { 0x422340, 0x22580422, 0x0000 }, // ?Cull@mmExternalView@@UAEXXZ
    { 0x4224E0, 0xCDB0C6CE, 0x0000 }, // ?AddWidgets@mmExternalView@@UAEXPAVBank@@@Z
    { 0x4227D0, 0xC9CFFEFF, 0x0000 }, // ?AddWidgets@mmDashView@@UAEXPAVBank@@@Z
    { 0x422BD0, 0x8476F13F, 0x0000 }, // ?DeclareFields@mmDashView@@SAXXZ
    { 0x422EC0, 0x86CEB354, 0x0000 }, // ?GetClass@mmDashView@@UAEPAVMetaClass@@XZ
    { 0x422F00, 0x148AB0D0, 0x0000 }, // ??1asLinearCS@@UAE@XZ
    { 0x422F10, 0x82C91D3C, 0x0000 }, // ??1RadialGauge@@UAE@XZ
    { 0x422FF0, 0xA11EC859, 0x0000 }, // ??0mmCDPlayer@@QAE@XZ
    { 0x423080, 0xFB02D956, 0x0000 }, // ?Init@mmCDPlayer@@QAEXPAVmmHUD@@@Z
    { 0x423190, 0x4C872713, 0x0000 }, // ?Reset@mmCDPlayer@@UAEXXZ
    { 0x4231A0, 0xF9D82171, 0x0000 }, // ?Update@mmCDPlayer@@UAEXXZ
    { 0x423210, 0xC475444E, 0x0000 }, // ?Cull@mmCDPlayer@@UAEXXZ
    { 0x423400, 0x2E2A6ABD, 0x0000 }, // ?PlayStop@mmCDPlayer@@QAEXXZ
    { 0x423450, 0xB7B105F9, 0x0000 }, // ?NextTrack@mmCDPlayer@@QAEXXZ
    { 0x4234C0, 0xB6C21C4E, 0x0000 }, // ?AddWidgets@mmCDPlayer@@UAEXPAVBank@@@Z
    { 0x423750, 0x3D23D3B8, 0x0000 }, // ?PrevTrack@mmCDPlayer@@QAEXXZ
    { 0x4237C0, 0xB3CA7A08, 0x0000 }, // ?Toggle@mmCDPlayer@@QAEXXZ
    { 0x423840, 0x4146EB02, 0x0000 }, // ??0RadialGauge@@QAE@XZ
    { 0x4238B0, 0x89E406E8, 0x0000 }, // ?Init@RadialGauge@@QAEXPAD0PAM1M@Z
    { 0x423910, 0x9EB7E0A9, 0x0000 }, // ?AddWidgets@RadialGauge@@UAEXPAVBank@@@Z
    { 0x423920, 0x6E99C0A0, 0x0000 }, // ?Update@RadialGauge@@UAEXXZ
    { 0x423A40, 0x9A7D0006, 0x0000 }, // ?Cull@RadialGauge@@UAEXXZ
    { 0x423A70, 0x308AD473, 0x0000 }, // ??0mmLinearGauge@@QAE@XZ
    { 0x423A80, 0xFC22209E, 0x0000 }, // ??1mmLinearGauge@@QAE@XZ
    { 0x423A90, 0x83CCBCB0, 0x0000 }, // ?Init@mmLinearGauge@@QAEXPADPAM11HPAVmmExternalView@@@Z
    { 0x423BA0, 0xF59C9B57, 0x0000 }, // ?Draw@mmLinearGauge@@QAEXXZ
    { 0x423C30, 0x1EBBE735, 0x0000 }, // ?Init@mmRadGauge@@QAEXPAM0PAVmmExternalView@@HI@Z
    { 0x423C60, 0x255CD414, 0x0000 }, // ?ResChange@mmRadGauge@@QAEXXZ
    { 0x423CB0, 0x1D079C49, 0x0000 }, // ?Draw@mmRadGauge@@QAEXXZ
    { 0x423DE0, 0x22B618B3, 0x0000 }, // ?Init@mmGearIndicator@@QAEXPAVmmExternalView@@PAVmmPlayer@@@Z
    { 0x423F10, 0x08E3EE42, 0x0000 }, // ?Draw@mmGearIndicator@@QAEXXZ
    { 0x423F90, 0x2BBE9FEB, 0x0000 }, // ?Init@mmSpeedIndicator@@QAEXPAVmmExternalView@@PAVmmCarSim@@@Z
    { 0x424020, 0x15881A0E, 0x0000 }, // ?Draw@mmSpeedIndicator@@QAEXXZ
    { 0x4241A0, 0x2C84F633, 0x0000 }, // ??0mmWPHUD@@QAE@XZ
    { 0x4242B0, 0x87171FBE, 0x0000 }, // ??1mmWPHUD@@UAE@XZ
    { 0x424360, 0x870FFCA9, 0x0000 }, // ?SetWPCleared@mmWPHUD@@QAEXXZ
    { 0x4243B0, 0xA1B7A445, 0x0000 }, // ?SetStandings@mmWPHUD@@QAEXHH@Z
    { 0x4243F0, 0x902BAFFD, 0x0000 }, // ?Init@mmWPHUD@@QAEXHPAH0H@Z
    { 0x4246E0, 0x6589878A, 0x0000 }, // ?Reset@mmWPHUD@@UAEXXZ
    { 0x424730, 0x7DBC4BD8, 0x0000 }, // ?Update@mmWPHUD@@UAEXXZ
    { 0x424770, 0x1985BE76, 0x0000 }, // ?Cull@mmWPHUD@@UAEXXZ
    { 0x424780, 0x35E93CB9, 0x0000 }, // ?AddWidgets@mmWPHUD@@UAEXPAVBank@@@Z
    { 0x424790, 0x7358180D, 0x0000 }, // ??0mmCircuitHUD@@QAE@XZ
    { 0x4248A0, 0xFE91A4C2, 0x0000 }, // ??1mmCircuitHUD@@UAE@XZ
    { 0x4249A0, 0x0D454C2A, 0x0000 }, // ?Init@mmCircuitHUD@@QAEXXZ
    { 0x424F50, 0x669D2A08, 0x0000 }, // ?Update@mmCircuitHUD@@UAEXXZ
    { 0x424F60, 0x6B42B9B7, 0x0000 }, // ?SetStandings@mmCircuitHUD@@QAEXHH@Z
    { 0x424FB0, 0xD8E54ACD, 0x0000 }, // ?SetLapTime@mmCircuitHUD@@QAEXHMPADH@Z
    { 0x425050, 0x618AEB73, 0x0000 }, // ?SetWPCleared@mmCircuitHUD@@QAEXHH@Z
    { 0x425090, 0x8B852705, 0x0000 }, // ?Reset@mmCircuitHUD@@UAEXXZ
    { 0x425140, 0xAF0765A4, 0x0000 }, // ??0mmCRHUD@@QAE@XZ
    { 0x4252E0, 0x7FE1E2EC, 0x0000 }, // ??1mmCRHUD@@UAE@XZ
    { 0x425410, 0x9C0B53EA, 0x0000 }, // ?Init@mmCRHUD@@QAEXPAVasLinearCS@@PADW4mmCRGameClass@@@Z
    { 0x425C20, 0x05FD5B59, 0x0000 }, // ?ToggleScores@mmCRHUD@@QAEXXZ
    { 0x425C50, 0x3B217219, 0x0000 }, // ?AddPlayer@mmCRHUD@@QAEXPADKHI@Z
    { 0x425D90, 0xD0BCBA1E, 0x0000 }, // ?UnPackColor@mmCRHUD@@QAEXIAAVVector4@@@Z
    { 0x425E10, 0x6E947D1E, 0x0000 }, // ?SetScore@mmCRHUD@@QAEXPAD@Z
    { 0x425E30, 0x02BDFB21, 0x0000 }, // ?SetName@mmCRHUD@@QAEXPADH@Z
    { 0x425EB0, 0xA0BFE9E1, 0x0000 }, // ?SetScore@mmCRHUD@@QAEXKH@Z
    { 0x425F20, 0x1208329E, 0x0000 }, // ?RemovePlayer@mmCRHUD@@QAEXK@Z
    { 0x426090, 0x1160265E, 0x0000 }, // ?ActivateGold@mmCRHUD@@QAEXXZ
    { 0x4260A0, 0xE0623629, 0x0000 }, // ?DeactivateGold@mmCRHUD@@QAEXXZ
    { 0x4260B0, 0xE684689F, 0x0000 }, // ?ActivateRosterGold@mmCRHUD@@QAEXK@Z
    { 0x426100, 0xF82F6EE9, 0x0000 }, // ?DeactivateRosterGold@mmCRHUD@@QAEXXZ
    { 0x426140, 0x05104283, 0x0000 }, // ?UpdateGold@mmCRHUD@@QAEXXZ
    { 0x426160, 0xA3E95E9D, 0x0000 }, // ?Update@mmCRHUD@@UAEXXZ
    { 0x426180, 0x727211B6, 0x0000 }, // ?Reset@mmCRHUD@@UAEXXZ
    { 0x426190, 0x1C9DAA64, 0x0000 }, // ?SetBlueScore@mmCRHUD@@QAEXH@Z
    { 0x4261D0, 0xD63AD5F3, 0x0000 }, // ?SetRedScore@mmCRHUD@@QAEXH@Z
    { 0x426390, 0x8D54AAFC, 0x0000 }, // ??0mmIcons@@QAE@XZ
    { 0x426410, 0x577D067B, 0x0000 }, // ??1mmIcons@@UAE@XZ
    { 0x426470, 0x69A70131, 0x0000 }, // ?Init@mmIcons@@QAEXPAVMatrix34@@MM@Z
    { 0x4264B0, 0x819BB0B3, 0x0000 }, // ?RegisterOpponents@mmIcons@@QAEXPAUOppIconInfo@@HPAX@Z
    { 0x426530, 0x147BD406, 0x0000 }, // ?Update@mmIcons@@UAEXXZ
    { 0x426570, 0xD94C3515, 0x0000 }, // ?Cull@mmIcons@@UAEXXZ
    { 0x426BA0, 0x21328589, 0x0000 }, // ??0mmPopup@@QAE@PAVmmGame@@MMMM@Z
    { 0x427010, 0xE1DEE5A4, 0x0000 }, // ??1mmPopup@@UAE@XZ
    { 0x427020, 0x99008C15, 0x0000 }, // ?IsEnabled@mmPopup@@QAEHXZ
    { 0x427030, 0xBC6DF424, 0x0000 }, // ?DisablePU@mmPopup@@QAEXH@Z
    { 0x427110, 0x9B013422, 0x0000 }, // ?ProcessEscape@mmPopup@@QAEXH@Z
    { 0x427250, 0x994026B4, 0x0000 }, // ?ProcessChat@mmPopup@@QAEXXZ
    { 0x427350, 0x24B8F278, 0x0000 }, // ?ProcessKeymap@mmPopup@@QAEXH@Z
    { 0x4274D0, 0xF4FEEA3A, 0x0000 }, // ?ShowResults@mmPopup@@QAEXXZ
    { 0x427560, 0x8D27DD47, 0x0000 }, // ?ShowRoster@mmPopup@@QAEXXZ
    { 0x427600, 0xD63079A3, 0x0000 }, // ?ForceRoster@mmPopup@@QAEXXZ
    { 0x427680, 0x8A10BB61, 0x0000 }, // ?Update@mmPopup@@UAEXXZ
    { 0x427C50, 0xDF15EA14, 0x0000 }, // ?Reset@mmPopup@@UAEXXZ
    { 0x427C70, 0x93120FBC, 0x0000 }, // ?GetComment@mmPopup@@QAEPADXZ
    { 0x427C80, 0x2125493A, 0x0000 }, // ?SetComment@mmPopup@@QAEXPAD@Z
    { 0x427CA0, 0x63B39E9E, 0x0000 }, // ?RecordPosition@mmPopup@@QAEXXZ
    { 0x427CD0, 0x25511C6C, 0x0000 }, // ?Lock@mmPopup@@QAEXXZ
    { 0x427CE0, 0x93848003, 0x0000 }, // ?Unlock@mmPopup@@QAEXXZ
    { 0x427CF0, 0x6CC7E202, 0x0000 }, // ?ChatCB@mmPopup@@QAEXXZ
    { 0x427DB0, 0x824EEDCC, 0x0000 }, // ??0mmAmbientAudio@@QAE@PAVmmPlayer@@@Z
    { 0x427E50, 0x82B84A84, 0x0000 }, // ??1mmAmbientAudio@@QAE@XZ
    { 0x427E60, 0xE8810C0C, 0x0000 }, // ?Update@mmAmbientAudio@@QAEXXZ
    { 0x4280C0, 0xF3288DC6, 0x0000 }, // ??0mmHudMap@@QAE@XZ
    { 0x4281B0, 0x2E0D6068, 0x0000 }, // ?Init@mmHudMap@@QAEXPAVasCamera@@PAVMatrix34@@PAVmmHUD@@PAVmmGame@@PAD@Z
    { 0x428750, 0x2699910D, 0x0000 }, // ?Reset@mmHudMap@@UAEXXZ
    { 0x428790, 0x57AC6F36, 0x0000 }, // ?RegisterOpponents@mmHudMap@@QAEXPAUOppIconInfo@@H@Z
    { 0x4287B0, 0x73F9A3F5, 0x0000 }, // ?RegisterCopsnRobbers@mmHudMap@@QAEXPAPAVVector3@@@Z
    { 0x4287E0, 0x1AEF6BFC, 0x0000 }, // ?RegisterMisc@mmHudMap@@QAEXPAPAVVector3@@H@Z
    { 0x428810, 0xC7EC05D2, 0x0000 }, // ?Activate@mmHudMap@@QAEXXZ
    { 0x428840, 0x79000F67, 0x0000 }, // ?Deactivate@mmHudMap@@QAEXXZ
    { 0x428870, 0xC36961C3, 0x0000 }, // ?SetMode@mmHudMap@@QAEXH@Z
    { 0x428B90, 0xDB1B6EB1, 0x0000 }, // ?Cycle@mmHudMap@@QAEXXZ
    { 0x428BC0, 0x0D6AA643, 0x0000 }, // ?ToggleFullScreen@mmHudMap@@QAEXXZ
    { 0x428BF0, 0xBC207FE1, 0x0000 }, // ?GetCurrentMap@mmHudMap@@AAEPAVagiBitmap@@XZ
    { 0x428C00, 0x8DE84640, 0x0000 }, // ?ToggleMapRes@mmHudMap@@QAEXXZ
    { 0x428C60, 0x2C216778, 0x0000 }, // ?Update@mmHudMap@@UAEXXZ
    { 0x428E50, 0xC9C2A66D, 0x0000 }, // ?Cull@mmHudMap@@UAEXXZ
    { 0x428FE0, 0xCA9F011A, 0x0000 }, // ?DrawCentered@mmHudMap@@AAEXPAVagiBitmap@@UPoint@@@Z
    { 0x429050, 0xB07F6F8D, 0x0000 }, // ?DrawClipped@mmHudMap@@AAEXPAVagiBitmap@@UPoint@@MMMM@Z
    { 0x4291F0, 0x6D4E3D72, 0x0000 }, // ?DrawOrientedBitmap@mmHudMap@@AAEXPAVMatrix34@@PAVagiBitmap@@@Z
    { 0x4293D0, 0xE58F0244, 0x0000 }, // ?ResChanged@mmHudMap@@QAEXXZ
    { 0x429410, 0x5CFAAC16, 0x0000 }, // ?DrawOriented@mmHudMap@@AAEXPAVMatrix34@@I@Z
    { 0x4295F0, 0x01BEF7BA, 0x0000 }, // ?DrawOpponents@mmHudMap@@AAEXXZ
    { 0x4296B0, 0xFCB2CC59, 0x0000 }, // ?DrawCops@mmHudMap@@AAEXXZ
    { 0x429720, 0xECC59465, 0x0000 }, // ?DrawWaypoints@mmHudMap@@AAEXXZ
    { 0x429860, 0x6FC1A4B1, 0x0000 }, // ?DrawCopsnRobbers@mmHudMap@@AAEXXZ
    { 0x429930, 0x05B51B21, 0x0000 }, // ?DrawMisc@mmHudMap@@QAEXXZ
    { 0x4299A0, 0x5B4BAEF4, 0x0000 }, // ?FlushVerts@mmHudMap@@AAEXXZ
    { 0x429B20, 0x604FEC51, 0x0000 }, // ?WorldToBitmap@mmHudMap@@AAE?AUPoint@@PAVVector3@@@Z
    { 0x429BC0, 0xF6C3D3C5, 0x0000 }, // ?BitmapToScreen@mmHudMap@@AAEHPAUPoint@@U2@@Z
    { 0x429C60, 0xFDF4DCEF, 0x0000 }, // ?AddWidgets@mmHudMap@@UAEXPAVBank@@@Z
    { 0x429DC0, 0x9E6A3067, 0x0000 }, // ?DeclareFields@mmHudMap@@SAXXZ
    { 0x429F30, 0x56E804C9, 0x0000 }, // ?GetClass@mmHudMap@@UAEPAVMetaClass@@XZ
    { 0x429FD0, 0xE85BBE31, 0x0000 }, // ??1mmHudMap@@UAE@XZ
    { 0x429FF0, 0xCE2C378E, 0x0000 }, // ??0mmPlayer@@QAE@XZ
    { 0x42A370, 0xCB51E19F, 0x0000 }, // ?BeforeSave@mmPlayer@@UAEXXZ
    { 0x42A380, 0x15D0E712, 0x0000 }, // ?AfterLoad@mmPlayer@@UAEXXZ
    { 0x42A390, 0x80DFF1CC, 0x0000 }, // ?ReInit@mmPlayer@@QAEXPAD@Z
    { 0x42A520, 0xE71333A6, 0x0000 }, // ?Init@mmPlayer@@QAEXPAD0PAVmmGame@@@Z
    { 0x42A9A0, 0xEADEF810, 0x0000 }, // ?SetMirrorFOV@mmPlayer@@QAEXXZ
    { 0x42A9D0, 0x33A2D882, 0x0000 }, // ?SetPreRaceCam@mmPlayer@@QAEXXZ
    { 0x42AAF0, 0x06471D6A, 0x0000 }, // ?SetPostRaceCam@mmPlayer@@QAEXXZ
    { 0x42AC10, 0x66D7EDDB, 0x0000 }, // ?IsPOV@mmPlayer@@QAEHXZ
    { 0x42AC60, 0xA557850A, 0x0000 }, // ?SetWideFOV@mmPlayer@@QAEXH@Z
    { 0x42ADF0, 0x1B1D63B7, 0x0000 }, // ?ToggleWideFOV@mmPlayer@@QAEXXZ
    { 0x42AE10, 0x902305B0, 0x0000 }, // ?ToggleCam@mmPlayer@@QAEXXZ
    { 0x42AF30, 0xCBB0A132, 0x0000 }, // ?ToggleExternalView@mmPlayer@@QAEXXZ
    { 0x42B0E0, 0x5CB0BB52, 0x0000 }, // ?ToggleDash@mmPlayer@@QAEXXZ
    { 0x42B310, 0xA9112D70, 0x0000 }, // ?UpdateHOG@mmPlayer@@QAEXXZ
    { 0x42B440, 0x234A006C, 0x0000 }, // ?Reset@mmPlayer@@UAEXXZ
    { 0x42B5F0, 0x3D226420, 0x0000 }, // ?SetSteering@mmPlayer@@QAEXM@Z
    { 0x42BBC0, 0x1BF381E6, 0x0000 }, // ?Update@mmPlayer@@UAEXXZ
    { 0x42C420, 0x34BFE854, 0x0000 }, // ?SetCamInterest@mmPlayer@@QAEXPAVasInertialCS@@@Z
    { 0x42C490, 0xDE3E70A7, 0x0000 }, // ?IsMaxDamaged@mmPlayer@@QAEHXZ
    { 0x42C4C0, 0xBA9B969B, 0x0000 }, // ?EnableRegen@mmPlayer@@QAEXH@Z
    { 0x42C4E0, 0x84666A62, 0x0000 }, // ?ResetDamage@mmPlayer@@QAEXXZ
    { 0x42C4F0, 0x0E79860C, 0x0000 }, // ?UpdateRegen@mmPlayer@@QAEXXZ
    { 0x42C590, 0x3433116B, 0x0000 }, // ?AddWidgets@mmPlayer@@UAEXPAVBank@@@Z
    { 0x42CD40, 0x51D548CE, 0x0000 }, // ?DeclareFields@mmPlayer@@SAXXZ
    { 0x42D1B0, 0xD421956E, 0x0000 }, // ?GetClass@mmPlayer@@UAEPAVMetaClass@@XZ
    { 0x42D1F0, 0x7C6848C7, 0x0000 }, // ??1mmCar@@UAE@XZ
    { 0x42D2B0, 0xF83268DC, 0x0000 }, // ??1PolarCamCS@@UAE@XZ
    { 0x42D2C0, 0x90449495, 0x0000 }, // ??1AICamCS@@UAE@XZ
    { 0x42D2D0, 0x0E110047, 0x0000 }, // ??1PointCamCS@@UAE@XZ
    { 0x42D2E0, 0x2FB95A19, 0x0000 }, // ??1PreCamCS@@UAE@XZ
    { 0x42D2F0, 0x2E3E0EA6, 0x0000 }, // ??1PostCamCS@@UAE@XZ
    { 0x42D300, 0x2B160BBB, 0x0000 }, // ??1asOverSample@@UAE@XZ
    { 0x42D370, 0xCA29BD00, 0x0000 }, // ??1mmPlayer@@UAE@XZ
    { 0x42D510, 0xE0E3C802, 0x0000 }, // ??1mmPhysEntity@@UAE@XZ
    { 0x42D540, 0x7E447E57, 0x0000 }, // ??0mmWaypoints@@QAE@XZ
    { 0x42D950, 0xC68FD4D7, 0x0000 }, // ?BlitzRemove@mmWaypoints@@QAEHH@Z
    { 0x42D9D0, 0x7838DD7D, 0x0000 }, // ?Init@mmWaypoints@@QAEHPAVmmPlayer@@PADHHHH@Z
    { 0x42DB00, 0xF12F7BA6, 0x0000 }, // ?GetStartAngle@mmWaypoints@@QAEMXZ
    { 0x42DB20, 0x36A8AFBF, 0x0000 }, // ??1mmWaypoints@@UAE@XZ
    { 0x42DC20, 0xAC365E73, 0x0000 }, // ?LoadCSV@mmWaypoints@@QAEHPADH@Z
    { 0x42E910, 0x6E15857D, 0x0000 }, // ?Cull@mmWaypoints@@UAEXXZ
    { 0x42E920, 0x2201501C, 0x0000 }, // ?CalculateGatePoints@mmWaypoints@@QAEXVVector3@@MMPAVVector2@@1@Z
    { 0x42E9A0, 0xBBB405F8, 0x0000 }, // ?Update@mmWaypoints@@UAEXXZ
    { 0x42ED30, 0xECC22D31, 0x0000 }, // ?DeactivateFinish@mmWaypoints@@QAEXXZ
    { 0x42ED50, 0x2A8906FB, 0x0000 }, // ?Reset@mmWaypoints@@UAEXXZ
    { 0x42EE40, 0x369EC0E0, 0x0000 }, // ?GetStart@mmWaypoints@@QAEXAAVVector3@@@Z
    { 0x42EE80, 0xFB964F87, 0x0000 }, // ?GetWaypoint@mmWaypoints@@QAEXHAAVVector3@@@Z
    { 0x42EED0, 0x42CB29CB, 0x0000 }, // ?GetHeading@mmWaypoints@@QAEMH@Z
    { 0x42EF00, 0x077F4A92, 0x0000 }, // ?GenerateHitRooms@mmWaypoints@@QAEXXZ
    { 0x42EF60, 0x3AC76F34, 0x0000 }, // ?GetHitRoom@mmWaypoints@@QAEHH@Z
    { 0x42EF80, 0x47A004E2, 0x0000 }, // ?SetArrow@mmWaypoints@@QAEXXZ
    { 0x42EFA0, 0x46B8F563, 0x0000 }, // ?UpdateWPHUD@mmWaypoints@@QAEXXZ
    { 0x42F010, 0xA19C5A9A, 0x0000 }, // ?ResetAllTags@mmWaypoints@@QAEXXZ
    { 0x42F050, 0x7580693B, 0x0000 }, // ?GetClosestWaypoint@mmWaypoints@@QAEXXZ
    { 0x42F130, 0x6AAAA034, 0x0000 }, // ?CycleCurrentWaypoint@mmWaypoints@@QAEXH@Z
    { 0x42F1A0, 0x99F17052, 0x0000 }, // ?GetNextWaypoint@mmWaypoints@@QAEXXZ
    { 0x42F1B0, 0x5C43C7C4, 0x0000 }, // ?GetLastWaypoint@mmWaypoints@@QAEXXZ
    { 0x42F1C0, 0x54610C38, 0x0000 }, // ?SetCurrentGoals@mmWaypoints@@QAEXH@Z
    { 0x42F200, 0x50B84FF6, 0x0000 }, // ?AIWPHit@mmWaypoints@@QAEHHHVMatrix34@@VVector3@@M@Z
    { 0x42F4C0, 0x0F445C61, 0x0000 }, // ?AnyAIWPHit@mmWaypoints@@QAEHAAIHVMatrix34@@VVector3@@M@Z
    { 0x42F820, 0xF4C50AB9, 0x0000 }, // ?WPHit@mmWaypoints@@QAEHHVVector3@@HH@Z
    { 0x42FAA0, 0xBBFE1F09, 0x0000 }, // ?AnyWPHits@mmWaypoints@@QAEHH@Z
    { 0x42FD50, 0x1824E2B9, 0x0000 }, // ?LineIntersect@mmWaypoints@@QAEHVVector2@@000M@Z
    { 0x42FF60, 0xD49C2CF3, 0x0000 }, // ?ClearWaypoint@mmWaypoints@@QAEXH@Z
    { 0x430020, 0x613ECF56, 0x0000 }, // ?DisplayHUDMessage@mmWaypoints@@QAEXHH@Z
    { 0x430170, 0xDDDA3609, 0x0000 }, // ?Init@mmGate@@QAEXVVector2@@0@Z
    { 0x4301F0, 0x3E338625, 0x0000 }, // ?LineEq@mmGate@@QAEMMM@Z
    { 0x430210, 0x581C0ABA, 0x0000 }, // ?CloseEnough@mmGate@@QAEHMM@Z
    { 0x430250, 0x16D310F4, 0x0000 }, // ?Check@mmGate@@QAEHVVector2@@0@Z
    { 0x430350, 0xEB40281C, 0x0000 }, // ??0Vector2@@QAE@ABV0@@Z
    { 0x430370, 0xBB1381BC, 0x0000 }, // ??0mmWaypointObject@@QAE@AAVVector4@@PADHMHM@Z
    { 0x430510, 0xF92CD572, 0x0000 }, // ??1mmWaypointObject@@UAE@XZ
    { 0x430520, 0x4B996B7D, 0x0000 }, // ?Reset@mmWaypointObject@@UAEXXZ
    { 0x430530, 0x02A698A5, 0x0000 }, // ?Update@mmWaypointObject@@UAEXXZ
    { 0x430540, 0x34BA0F50, 0x0000 }, // ?Activate@mmWaypointObject@@QAEXXZ
    { 0x430550, 0x454CA916, 0x0000 }, // ?Deactivate@mmWaypointObject@@QAEXXZ
    { 0x430560, 0x802D1E81, 0x0000 }, // ?SetHeading@mmWaypointObject@@QAEXM@Z
    { 0x4305D0, 0x4142BEFB, 0x0000 }, // ?Move@mmWaypointObject@@QAEXXZ
    { 0x430690, 0x27285752, 0x0000 }, // ??3mmInstance@@SAXPAX@Z
    { 0x4306A0, 0x85BB99F7, 0x0000 }, // ??0mmGameMulti@@QAE@XZ
    { 0x4307B0, 0x41D6DC41, 0x0000 }, // ??1mmGameMulti@@UAE@XZ
    { 0x430870, 0x72184FA2, 0x0000 }, // ?Init@mmGameMulti@@QAEHXZ
    { 0x4309A0, 0x14CFB5C5, 0x0000 }, // ?HitWaterHandler@mmGameMulti@@UAEXXZ
    { 0x430A90, 0x950C60FC, 0x0000 }, // ?DropThruCityHandler@mmGameMulti@@UAEXXZ
    { 0x430AA0, 0x5F8A4818, 0x0000 }, // ?InitGameStrings@mmGameMulti@@UAEXXZ
    { 0x430CC0, 0x2135388A, 0x0000 }, // ?StartXYZ@mmGameMulti@@IAEXHAAVVector3@@0MM@Z
    { 0x430EF0, 0x8497F666, 0x0000 }, // ?SystemMessageCB@mmGameMulti@@QAEXPAX0@Z
    { 0x431100, 0xF876BA6E, 0x0000 }, // ?GameMessageCB@mmGameMulti@@QAEXPAX0@Z
    { 0x431480, 0xABE91954, 0x0000 }, // ?BootStrapCars@mmGameMulti@@QAEXXZ
    { 0x431620, 0x25D0E7FE, 0x0000 }, // ?Reset@mmGameMulti@@UAEXXZ
    { 0x4316A0, 0xD2F2A861, 0x0000 }, // ?ClearNetObjects@mmGameMulti@@QAEXXZ
    { 0x4316E0, 0xBA46C011, 0x0000 }, // ?InitOtherPlayers@mmGameMulti@@UAEXXZ
    { 0x431960, 0x45B03A72, 0x0000 }, // ?InitRoster@mmGameMulti@@UAEXXZ
    { 0x4319F0, 0x30F01D6E, 0x0000 }, // ?Update@mmGameMulti@@UAEXXZ
    { 0x431A10, 0x767BB658, 0x0000 }, // ?UpdateGame@mmGameMulti@@UAEXXZ
    { 0x431AA0, 0x2DD41098, 0x0000 }, // ?UpdateScore@mmGameMulti@@QAEXXZ
    { 0x431ED0, 0xF1A72724, 0x0000 }, // ?UpdateDebugKeyInput@mmGameMulti@@UAEXH@Z
    { 0x431EE0, 0xF6D1A7BA, 0x0000 }, // ?RegisterMapNetObjects@mmGameMulti@@QAEXH@Z
    { 0x432000, 0xD962AD68, 0x0000 }, // ?DeactivateMapNetObject@mmGameMulti@@QAEXH@Z
    { 0x432030, 0x93F15F3E, 0x0000 }, // ?ActivateMapNetObject@mmGameMulti@@QAEXH@Z
    { 0x432070, 0xD7340AFE, 0x0000 }, // ?EnableRacers@mmGameMulti@@IAEXXZ
    { 0x4320F0, 0x3660E4A4, 0x0000 }, // ?DisableRacers@mmGameMulti@@IAEXXZ
    { 0x432140, 0x20922A03, 0x0000 }, // ?QuitNetwork@mmGameMulti@@QAEXXZ
    { 0x432160, 0x5AE8CC7E, 0x0000 }, // ?ParseChatMessage@mmGameMulti@@QAEHPADH@Z
    { 0x4321D0, 0xA3884FF4, 0x0000 }, // ?SendChatMessage@mmGameMulti@@UAEXPAD@Z
    { 0x432290, 0x63157F32, 0x0000 }, // ?SendToChatMessage@mmGameMulti@@QAEXPADK@Z
    { 0x432350, 0x5C7AD830, 0x0000 }, // ?FinishMessage@mmGameMulti@@QAEXH@Z
    { 0x432410, 0x30C14AF0, 0x0000 }, // ?BootPlayerCB@mmGameMulti@@QAEXPAX0@Z
    { 0x432450, 0xAF85732D, 0x0000 }, // ?UpdateNetWorkAudio@mmGameMulti@@QAEXXZ
    { 0x4324A0, 0x581999E3, 0x0000 }, // ?SendMsg@mmGameMulti@@QAEXH@Z
    { 0x4324D0, 0xA6826CB3, 0x0000 }, // ?SendBootMsg@mmGameMulti@@QAEXK@Z
    { 0x432510, 0xACCDDDE5, 0x0000 }, // ?DeclareFields@mmGameMulti@@SAXXZ
    { 0x4325B0, 0x09E17D4D, 0x0000 }, // ?GetClass@mmGameMulti@@UAEPAVMetaClass@@XZ
    { 0x432740, 0xDFFD56F7, 0x0000 }, // ??0mmNetObject@@QAE@XZ
    { 0x4327F0, 0x2F6738F9, 0x0000 }, // ??1mmNetObject@@UAE@XZ
    { 0x432800, 0x949F39B3, 0x0000 }, // ?Clear@mmNetObject@@QAEXXZ
    { 0x432850, 0x467B939E, 0x0000 }, // ?Activate@mmNetObject@@QAEXXZ
    { 0x4328A0, 0x6794FCD3, 0x0000 }, // ?Deactivate@mmNetObject@@QAEXXZ
    { 0x432900, 0xF74475F3, 0x0000 }, // ?Init@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    { 0x432980, 0x9E1D2F18, 0x0000 }, // ?ReInit@mmNetObject@@QAEXPAVmmCar@@PADHK1@Z
    { 0x432A40, 0xCDBB7389, 0x0000 }, // ?SetCar@mmNetObject@@QAEXPAVmmCar@@@Z
    { 0x432A50, 0xD8CFFA94, 0x0000 }, // ?SetActive@mmNetObject@@QAEXH@Z
    { 0x432A70, 0xF737D1BA, 0x0000 }, // ?SetScore@mmNetObject@@QAEXH@Z
    { 0x432A80, 0x8F4DFC13, 0x0000 }, // ?SetLocalData@mmNetObject@@UAEXXZ
    { 0x432BD0, 0x845751AF, 0x0000 }, // ?PositionUpdate@mmNetObject@@QAEXPAUNETGAME_MSG@@@Z
    { 0x432F80, 0xB845A7FF, 0x0000 }, // ?Predict@mmNetObject@@QAEXXZ
    { 0x433130, 0xBEF477CC, 0x0000 }, // ?Update@mmNetObject@@UAEXXZ
    { 0x433200, 0xD93B7855, 0x0000 }, // ??0mmRainAudio@@QAE@XZ
    { 0x433400, 0x8187FFED, 0x0000 }, // ??1mmRainAudio@@QAE@XZ
    { 0x433440, 0x4FA8CE2D, 0x0000 }, // ?SetInterior@mmRainAudio@@QAEXE@Z
    { 0x4334D0, 0x1D0D9A26, 0x0000 }, // ?ShelterOn@mmRainAudio@@QAEXXZ
    { 0x433540, 0x3A72240B, 0x0000 }, // ?ShelterOff@mmRainAudio@@QAEXXZ
    { 0x4335B0, 0xD5D753E0, 0x0000 }, // ?Update@mmRainAudio@@QAEXXZ
    { 0x433730, 0xC2BC8128, 0x0000 }, // ??0mmWaypointInstance@@QAE@HMM@Z
    { 0x433780, 0x417804C2, 0x0000 }, // ??1mmWaypointInstance@@UAE@XZ
    { 0x433790, 0xD9BCB46C, 0x0000 }, // ?GetScale@mmWaypointInstance@@UAIMXZ
    { 0x4337A0, 0x944A5DE9, 0x0000 }, // ?ComputeLod@mmWaypointInstance@@UAEHMM@Z
    { 0x4337C0, 0x663964BE, 0x0000 }, // ?Draw@mmWaypointInstance@@UAIXH@Z
    { 0x433B90, 0xD45A1648, 0x0000 }, // ?AddWidgets@mmWaypointInstance@@UAEXPAVBank@@@Z
    { 0x433BA0, 0xAB2E02EB, 0x0000 }, // ?DeclareFields@mmWaypointInstance@@SAXXZ
    { 0x433D20, 0xE8A98119, 0x0000 }, // ?GetClass@mmWaypointInstance@@UAEPAVMetaClass@@XZ
    { 0x433DB0, 0xCAE33CF8, 0x0000 }, // ?GetEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ
    { 0x433DC0, 0x540840A2, 0x0000 }, // ?AttachEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ
    { 0x433DD0, 0xCF50EE23, 0x0000 }, // ?GetVelocity@mmInstance@@UAE?AVVector3@@XZ
    { 0x433DF0, 0xFEDC85B3, 0x0000 }, // ?Impact@mmInstance@@UAEXPAV1@PAVVector3@@@Z
    { 0x433E00, 0x4B7E4995, 0x0000 }, // ?Detach@mmInstance@@UAEXXZ
    { 0x433E50, 0xEBB8BEA2, 0x0000 }, // ?Path@aiMap@@QAEPAVaiPath@@H@Z
    { 0x433E80, 0x3BA43DA7, 0x0000 }, // ?Intersection@aiMap@@QAEPAVaiIntersection@@H@Z
    { 0x433EB0, 0xDF6850E8, 0x0000 }, // ?Vehicle@aiMap@@QAEPAVaiVehicleAmbient@@H@Z
    { 0x433EF0, 0xD1DD3A74, 0x0000 }, // ?Police@aiMap@@QAEPAVaiVehiclePolice@@H@Z
    { 0x433F30, 0xEF6E483B, 0x0000 }, // ?Opponent@aiMap@@QAEPAVaiVehicleOpponent@@H@Z
    { 0x433F70, 0x56BC4A9C, 0x0000 }, // ?Pedestrian@aiMap@@QAEPAVaiPedestrian@@H@Z
    { 0x433FB0, 0x4A0397FE, 0x0000 }, // ?PlayerPos@aiMap@@QAEAAVVector3@@XZ
    { 0x433FC0, 0xD69C4A6B, 0x0000 }, // ??0aiMap@@QAE@XZ
    { 0x433FE0, 0x8DFC777C, 0x0000 }, // ??1aiMap@@UAE@XZ
    { 0x433FF0, 0x8BF72336, 0x0000 }, // ?Clean@aiMap@@QAEXXZ
    { 0x434220, 0x213343B9, 0x0000 }, // ?Init@aiMap@@QAEXPAD00PAVmmCar@@@Z
    { 0x435770, 0x65DCC86F, 0x0000 }, // ?Stats@aiMap@@QAEXXZ
    { 0x435830, 0x3FABE369, 0x0000 }, // ?SaveBinary@aiMap@@AAEXPAD@Z
    { 0x4359B0, 0xA9F4883E, 0x0000 }, // ?ReadBinary@aiMap@@AAEXPAD@Z
    { 0x435FB0, 0x1C805054, 0x0000 }, // ?Reset@aiMap@@UAEXXZ
    { 0x4362F0, 0xF4D29CAD, 0x0000 }, // ?Update@aiMap@@UAEXXZ
    { 0x436670, 0x4BDD1182, 0x0000 }, // ?UpdatePaused@aiMap@@UAEXXZ
    { 0x436680, 0x26799432, 0x0000 }, // ?Cull@aiMap@@UAEXXZ
    { 0x436CD0, 0x0B2CB704, 0x0000 }, // ?DrawNextVisibleAmbient@aiMap@@QAEXXZ
    { 0x436CF0, 0x9B834D71, 0x0000 }, // ?AllwaysGreen@aiMap@@QAEXXZ
    { 0x436D30, 0x3421B035, 0x0000 }, // ?AllwaysRed@aiMap@@QAEXXZ
    { 0x436D70, 0x1601B677, 0x0000 }, // ?DrawAppRoads@aiMap@@QAEXXZ
    { 0x436D90, 0x0911D770, 0x0000 }, // ?MapComponent@aiMap@@QAEHAAVVector3@@PAF1F@Z
    { 0x436F10, 0xD876BE00, 0x0000 }, // ?DetermineRoadPosInfo@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAFPAM23H@Z
    { 0x4370B0, 0xDCD0637F, 0x0000 }, // ?DeterminePerpMapComponent@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAF2PAM32@Z
    { 0x437310, 0x9347D03E, 0x0000 }, // ?DetermineOppMapComponent@aiMap@@QAEHAAVMatrix34@@PAVaiRailSet@@PAF2PAM323MFF@Z
    { 0x438CB0, 0xB27913C6, 0x0000 }, // ?DetermineOppRoadPosInfo@aiMap@@QAEHAAVVector3@@0PAVaiRailSet@@PAFPAM3H@Z
    { 0x438D90, 0x3D999EDE, 0x0000 }, // ?FindAmbAppRoad@aiMap@@QAEHH@Z
    { 0x438DE0, 0x95A1989C, 0x0000 }, // ?FindPedAppRoad@aiMap@@QAEHH@Z
    { 0x438E30, 0x0CA02608, 0x0000 }, // ?PredictIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    { 0x439010, 0x3917EA61, 0x0000 }, // ?PredictAmbIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    { 0x4391F0, 0x4AC4F1AA, 0x0000 }, // ?PredictAmbFreewayIntersectionPath@aiMap@@QAEPAVaiPath@@HAAVMatrix34@@@Z
    { 0x439400, 0xD046047B, 0x0000 }, // ?Dump@aiMap@@QAEXXZ
    { 0x439540, 0xA5362327, 0x0000 }, // ?GetCameraPos@aiMap@@QAEXXZ
    { 0x439570, 0x94E9BD68, 0x0000 }, // ?AddAIPath@aiMap@@AAEPAVaiPath@@AAVmmRoadSect@@HH@Z
    { 0x439670, 0x5F03873D, 0x0000 }, // ?AddIntersection@aiMap@@QAEPAVaiIntersection@@PAVVector3@@@Z
    { 0x4396A0, 0x8EF793B7, 0x0000 }, // ?ScanIntersections@aiMap@@AAEPAVaiIntersection@@AAVVector3@@@Z
    { 0x439720, 0xF1F10FB1, 0x0000 }, // ?NewIntersection@aiMap@@AAEPAVaiIntersection@@AAVVector3@@@Z
    { 0x439800, 0x67F2624F, 0x0000 }, // ?CreateAmbAppRoadMap@aiMap@@AAEXXZ
    { 0x439D80, 0x71F3BDD6, 0x0000 }, // ?CreatePedAppRoadMap@aiMap@@AAEXXZ
    { 0x43A300, 0xF026DB02, 0x0000 }, // ?AddIntToAppRoadMap@aiMap@@AAEXPAVCArrayList@@HMPAPAUasPortalCell@@H@Z
    { 0x43A380, 0x600EB6BB, 0x0000 }, // ?RoadDensity@aiMap@@AAEMHMH@Z
    { 0x43A3D0, 0x1214C851, 0x0000 }, // ?NumCars@aiMap@@AAEHHMM@Z
    { 0x43A400, 0x2486FD75, 0x0000 }, // ?FindRoad@aiMap@@AAEHPAVCArrayList@@H@Z
    { 0x43A440, 0x1467F26D, 0x0000 }, // ?ChooseNextRandomLink@aiMap@@QAEHPAVaiRailSet@@@Z
    { 0x43A5D0, 0xF7AC7BCE, 0x0000 }, // ?ChooseNextLeftStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    { 0x43A840, 0xF43B8DF8, 0x0000 }, // ?ChooseNextRightStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    { 0x43AAE0, 0x897088A0, 0x0000 }, // ?ChooseNextStraightLink@aiMap@@QAEHPAVaiRailSet@@@Z
    { 0x43ADF0, 0x9D19DE24, 0x0000 }, // ?ChooseNextLaneLink@aiMap@@QAEHPAVaiRailSet@@@Z
    { 0x43AE90, 0x77DC2FCA, 0x0000 }, // ?ChooseNextFreewayLink@aiMap@@QAEHPAVaiRailSet@@@Z
    { 0x43AFA0, 0xE4746C75, 0x0000 }, // ?ChooseNextRightStraightFreewayLink@aiMap@@QAEHPAVaiRailSet@@@Z
    { 0x43B160, 0x5D30BFF9, 0x0000 }, // ?AdjustPedestrians@aiMap@@AAEXHH@Z
    { 0x43B500, 0x43455F86, 0x0000 }, // ?AddPedestrian@aiMap@@QAEXPAVaiPedestrian@@@Z
    { 0x43B530, 0x7B4B8BB4, 0x0000 }, // ?RemovePedestrian@aiMap@@QAEXPAVaiPedestrian@@@Z
    { 0x43B5A0, 0x41A8BF69, 0x0000 }, // ?AdjustAmbients@aiMap@@AAEXHH@Z
    { 0x43BA60, 0xFD869B44, 0x0000 }, // ?AddAmbient@aiMap@@QAEXPAVaiVehicleSpline@@@Z
    { 0x43BAA0, 0x014FFAE9, 0x0000 }, // ?RemoveAmbient@aiMap@@QAEXPAVaiVehicleSpline@@@Z
    { 0x43BB10, 0xE87600F8, 0x0000 }, // ?DetRdSegBetweenInts@aiMap@@QAEPAVaiPath@@PAVaiIntersection@@0@Z
    { 0x43BB90, 0xCFD06F72, 0x0000 }, // ?GoodRoadForCopStartPos@aiMap@@QAEHH@Z
    { 0x43BBE0, 0x4C5BA5F0, 0x0000 }, // ?AddWidgets@aiMap@@UAEXPAVBank@@@Z
    { 0x43BC20, 0x262601B4, 0x0000 }, // ?DeclareFields@aiMap@@SAXXZ
    { 0x43BD90, 0xE739B637, 0x0000 }, // ?GetClass@aiMap@@UAEPAVMetaClass@@XZ
    { 0x43C0D0, 0xB5D5D1C9, 0x0000 }, // ?Clamp@@YAMMMM@Z
    { 0x43C100, 0x3A452E8E, 0x0000 }, // ??0Vector3@@QAE@MMM@Z
    { 0x43C180, 0xA6204AB1, 0x0000 }, // ??0CArrayList@@QAE@XZ
    { 0x43C190, 0x69C1080B, 0x0000 }, // ??1mmRoadSide@@UAE@XZ
    { 0x43C250, 0xAA0DEB03, 0x0000 }, // ??1mmRoadSect@@UAE@XZ
    { 0x43C390, 0x6A1E72CE, 0x0000 }, // ??0aiPath@@QAE@H@Z
    { 0x43C3C0, 0x9C5D87B4, 0x0000 }, // ??1aiPath@@QAE@XZ
    { 0x43C450, 0x4D7F8B33, 0x0000 }, // ?Reset@aiPath@@QAEXXZ
    { 0x43C490, 0x46454654, 0x0000 }, // ?UpdateAmbients@aiPath@@QAEXXZ
    { 0x43C5A0, 0x6FE35EDA, 0x0000 }, // ?UpdatePedestrians@aiPath@@QAEXXZ
    { 0x43C640, 0x4A683FC7, 0x0000 }, // ?ResetVehicleReactTicks@aiPath@@QAEXXZ
    { 0x43C670, 0x76188452, 0x0000 }, // ?AddPathVerts@aiPath@@QAEXAAVmmRoadSect@@HH@Z
    { 0x43CFA0, 0x70FAFE99, 0x0000 }, // ?AddPathVerts@aiPath@@QAEXPAVVector3@@H@Z
    { 0x43D610, 0x152F4229, 0x0000 }, // ?CalcCenterVerts@aiPath@@QAEXAAVmmRoadSect@@H@Z
    { 0x43D950, 0xBDBC1F10, 0x0000 }, // ?SaveBinary@aiPath@@QAEXPAVStream@@@Z
    { 0x43DBC0, 0x8367D2F1, 0x0000 }, // ?ReadBinary@aiPath@@QAEXPAVStream@@@Z
    { 0x43E0C0, 0x096A3E6D, 0x0000 }, // ?Draw@aiPath@@QAEXXZ
    { 0x43E280, 0x4DB56DCA, 0x0000 }, // ?DrawNormals@aiPath@@QAEXXZ
    { 0x43E370, 0x13609D09, 0x0000 }, // ?DrawId@aiPath@@QAEXXZ
    { 0x43E3E0, 0x2AFA177C, 0x0000 }, // ?DrawVehicleIds@aiPath@@QAEXXZ
    { 0x43E450, 0xBCB595EB, 0x0000 }, // ?Dump@aiPath@@QAEXXZ
    { 0x43E4F0, 0x6D6C5F90, 0x0000 }, // ?AllwaysStop@aiPath@@QAEXH@Z
    { 0x43E510, 0x2F21D6E6, 0x0000 }, // ?StopIncomingRoads@aiPath@@QAEXH@Z
    { 0x43E5D0, 0x80E45FB9, 0x0000 }, // ?StopDestinationSources@aiPath@@QAEXH@Z
    { 0x43E650, 0x8D354131, 0x0000 }, // ?AllwaysGo@aiPath@@QAEXH@Z
    { 0x43E670, 0x68FC24F1, 0x0000 }, // ?CenterLength@aiPath@@QAEMHH@Z
    { 0x43E690, 0xB6D6184D, 0x0000 }, // ?SubSectionLength@aiPath@@QAEMHH@Z
    { 0x43E6B0, 0x09786018, 0x0000 }, // ?GetHeading@aiPath@@QAEMMH@Z
    { 0x43E780, 0x3D8D0055, 0x0000 }, // ?SubSectionDist@aiPath@@QAEMMH@Z
    { 0x43E840, 0xADDA910E, 0x0000 }, // ?CenterIndex@aiPath@@QAEHM@Z
    { 0x43E8E0, 0xEFE723F9, 0x0000 }, // ?CenterPosition@aiPath@@QAEXMAAVVector3@@@Z
    { 0x43E9B0, 0xD44EC353, 0x0000 }, // ?Index@aiPath@@QAEHMH@Z
    { 0x43EA60, 0xDDA91003, 0x0000 }, // ?Index@aiPath@@QAEHAAVVector3@@@Z
    { 0x43EB60, 0xF92FF250, 0x0000 }, // ?RoadDistance@aiPath@@QAEXAAVVector3@@PAFPAMF2@Z
    { 0x43ED00, 0x9880C14D, 0x0000 }, // ?CenterDistance@aiPath@@QAEHAAVVector3@@PAFPAM2@Z
    { 0x43F020, 0xD0D84A93, 0x0000 }, // ?AmbientCenterDistance@aiPath@@QAEXPAVaiVehicleSpline@@PAM111@Z
    { 0x43F710, 0x83A75127, 0x0000 }, // ?SubSectionPt@aiPath@@QAEXAAVVector3@@HHM@Z
    { 0x43F780, 0x95EEBD4F, 0x0000 }, // ?SubSectionDir@aiPath@@QAEXAAVVector3@@HHM@Z
    { 0x43F7D0, 0xF43264F1, 0x0000 }, // ?IntersectionEntryPt@aiPath@@QAEXAAVVector3@@HM@Z
    { 0x43F890, 0x21728FE3, 0x0000 }, // ?IntersectionEntryVector@aiPath@@QAEXAAVVector3@@M@Z
    { 0x43F910, 0x0C38024A, 0x0000 }, // ?IntersectionExitVector@aiPath@@QAEXAAVVector3@@M@Z
    { 0x43F980, 0x10F087D6, 0x0000 }, // ?NumVehiclesAfterDist@aiPath@@QAEHHM@Z
    { 0x43F9D0, 0xF58C03C6, 0x0000 }, // ?ContinuityError@aiPath@@QAEHH@Z
    { 0x43FA30, 0x61CA0AAB, 0x0000 }, // ?PopVehicle@aiPath@@QAEXPAVaiVehicleSpline@@H@Z
    { 0x43FB10, 0x2EBA1778, 0x0000 }, // ?PushVehicle@aiPath@@QAEXPAVaiVehicleSpline@@H@Z
    { 0x43FB80, 0xCC83BD26, 0x0000 }, // ?AddVehicle@aiPath@@QAEXPAVaiVehicleSpline@@HM@Z
    { 0x43FCB0, 0x65CD0965, 0x0000 }, // ?RemoveVehicle@aiPath@@QAEHPAVaiVehicleSpline@@H@Z
    { 0x43FDC0, 0x84AF1542, 0x0000 }, // ?RoadCapacity@aiPath@@QAEHPAVaiVehicleSpline@@H@Z
    { 0x43FE80, 0x75FDB0A1, 0x0000 }, // ?AddPedestrian@aiPath@@QAEXPAVaiPedestrian@@@Z
    { 0x43FEC0, 0xB3AA4D2A, 0x0000 }, // ?RemovePedestrian@aiPath@@QAEXPAVaiPedestrian@@@Z
    { 0x43FF30, 0xD100A180, 0x0000 }, // ?Blocked@aiPath@@QAEXH@Z
    { 0x43FF50, 0x965107D0, 0x0000 }, // ?VertXDir@aiPath@@QAEPAVVector3@@H@Z
    { 0x43FFA0, 0xFFE91524, 0x0000 }, // ??GVector3@@QBE?AV0@ABV0@@Z
    { 0x43FFD0, 0x12116C96, 0x0000 }, // ?VertZDir@aiPath@@QAEPAVVector3@@H@Z
    { 0x440020, 0x3165A220, 0x0000 }, // ?CenterVertice@aiPath@@QAEPAVVector3@@H@Z
    { 0x440070, 0xA219FC01, 0x0000 }, // ??0aiAudioManager@@QAE@XZ
    { 0x440390, 0x8CAB2C18, 0x0000 }, // ??1aiAudioManager@@UAE@XZ
    { 0x440790, 0x76E7DC17, 0x0000 }, // ?AddVehicle@aiAudioManager@@QAEFPAVaiVehicleAmbient@@@Z
    { 0x440840, 0xF3787017, 0x0000 }, // ?AddVehicle@aiAudioManager@@QAEFPAVaiVehicleOpponent@@@Z
    { 0x4408F0, 0x60D10478, 0x0000 }, // ?AddVehicle@aiAudioManager@@QAEFPAVaiVehiclePolice@@@Z
    { 0x4409A0, 0x24961823, 0x0000 }, // ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehicleAmbient@@F@Z
    { 0x440A10, 0xD4D9575B, 0x0000 }, // ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    { 0x440A80, 0xDFC8B958, 0x0000 }, // ?RemoveVehicle@aiAudioManager@@QAEXPAVaiVehiclePolice@@F@Z
    { 0x440AF0, 0x4C0068D7, 0x0000 }, // ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehicleAmbient@@@Z
    { 0x440CE0, 0x62202E92, 0x0000 }, // ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehicleOpponent@@@Z
    { 0x440ED0, 0xC5E0382B, 0x0000 }, // ?FindGreatestDistance@aiAudioManager@@QAEFPAVaiVehiclePolice@@@Z
    { 0x441130, 0xB180B06C, 0x0000 }, // ?UnassignFurthestAmbient@aiAudioManager@@QAEFXZ
    { 0x4411F0, 0xE64087E2, 0x0000 }, // ?UnassignFurthestOpponent@aiAudioManager@@QAEFXZ
    { 0x4412C0, 0xDA27F342, 0x0000 }, // ?FindUnusedSlot@aiAudioManager@@QAEFXZ
    { 0x441300, 0xCC7C29B1, 0x0000 }, // ?Update@aiAudioManager@@UAEXXZ
    { 0x441670, 0x5340A691, 0x0000 }, // ?EchoOn@aiAudioManager@@QAEXM@Z
    { 0x4419C0, 0xEFF4AADE, 0x0000 }, // ?EchoOff@aiAudioManager@@QAEXXZ
    { 0x441B60, 0xF7E69529, 0x0000 }, // ?AssignSounds@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    { 0x441F50, 0x46577F25, 0x0000 }, // ?AssignAddOnSounds@aiAudioManager@@QAEXPAVaiVehicleOpponent@@F@Z
    { 0x442050, 0xAB4FF3EF, 0x0000 }, // ?AssignSounds@aiAudioManager@@QAEXPAVaiVehiclePolice@@F@Z
    { 0x442630, 0x9136D2F8, 0x0000 }, // ?AssignSounds@aiAudioManager@@QAEXPAVaiVehicleAmbient@@F@Z
    { 0x442820, 0xC9A2580A, 0x0000 }, // ?AllocateAmbients@aiAudioManager@@QAEXXZ
    { 0x442880, 0xC53A8481, 0x0000 }, // ?AllocateOpponents@aiAudioManager@@QAEXXZ
    { 0x4428D0, 0x794746EE, 0x0000 }, // ?AllocatePolice@aiAudioManager@@QAEXXZ
    { 0x442C10, 0xD3996735, 0x0000 }, // ?AllocateSkids@aiAudioManager@@QAEXXZ
    { 0x442EB0, 0x4CE3F4AC, 0x0000 }, // ?AllocateCopVoice@aiAudioManager@@QAEXXZ
    { 0x442F90, 0x7A6658BD, 0x0000 }, // ?LoadCopVoice@aiAudioManager@@QAEXXZ
    { 0x4430C0, 0x2ABC8099, 0x0000 }, // ?CatName@aiAudioManager@@AAEPADPADHH@Z
    { 0x4432C0, 0x4A052685, 0x0000 }, // ?AllocateImpacts@aiAudioManager@@QAEXXZ
    { 0x443370, 0x3CCD3FC2, 0x0000 }, // ?AllocateHorns@aiAudioManager@@QAEXXZ
    { 0x443550, 0xA6160F79, 0x0000 }, // ?AllocateVoices@aiAudioManager@@QAEXXZ
    { 0x443720, 0x7D6B0757, 0x0000 }, // ?AllocateEngine@aiAudioManager@@QAEXFF@Z
    { 0x443930, 0x371A8903, 0x0000 }, // ?AllocateAddOnEngine@aiAudioManager@@QAEFPAD@Z
    { 0x443B00, 0x3EEFF210, 0x0000 }, // ?AllocateEngine@aiAudioManager@@QAEPAPAVAudSound@@PAD@Z
    { 0x443C50, 0xAB675F6F, 0x0000 }, // ?AllocateReverseBeep@aiAudioManager@@QAEXXZ
    { 0x443DA0, 0x38E5A9EE, 0x0000 }, // ?QueueInCopVoice@aiAudioManager@@QAEFM@Z
    { 0x443E00, 0x2B390F2A, 0x0000 }, // ?PlayCopVoice@aiAudioManager@@QAEFXZ
    { 0x443E50, 0x0C14742D, 0x0000 }, // ?GetClosestCop@aiAudioManager@@QAEFXZ
    { 0x443F60, 0x3AB37F55, 0x0000 }, // ??0aiTrafficLightSet@@QAE@PAVaiIntersection@@@Z
    { 0x444150, 0xD83C68B5, 0x0000 }, // ??1aiTrafficLightSet@@UAE@XZ
    { 0x4441B0, 0x3829F8BD, 0x0000 }, // ?Reset@aiTrafficLightSet@@UAEXXZ
    { 0x444250, 0x0FD7B13A, 0x0000 }, // ?Update@aiTrafficLightSet@@UAEXXZ
    { 0x444330, 0x7DB50B32, 0x0000 }, // ?Init@aiTrafficLightInstance@@UAEHPADAAVVector3@@1H0@Z
    { 0x444530, 0x3AFB9B8D, 0x0000 }, // ?Draw@aiTrafficLightInstance@@UAIXH@Z
    { 0x4446F0, 0x011635EB, 0x0000 }, // ??0mmBangerInstance@@QAE@XZ
    { 0x444710, 0xD90B6855, 0x0000 }, // ?AddWidgets@mmBangerInstance@@UAEXPAVBank@@@Z
    { 0x444740, 0x1C71B206, 0x0000 }, // ??1mmBangerInstance@@UAE@XZ
    { 0x444750, 0x31BA3A45, 0x0000 }, // ?SizeOf@mmUnhitBangerInstance@@UAEIXZ
    { 0x444780, 0x8CED5E65, 0x0000 }, // ??1aiTrafficLightInstance@@UAE@XZ
    { 0x444790, 0x2CDC8FB6, 0x0000 }, // ??0aiVehiclePolice@@QAE@XZ
    { 0x4447F0, 0x84ED04BF, 0x0000 }, // ??1aiVehiclePolice@@QAE@XZ
    { 0x444930, 0xC1D84A74, 0x0000 }, // ?Init@aiVehiclePolice@@QAEXHPAVaiRaceData@@@Z
    { 0x444B40, 0xFE230837, 0x0000 }, // ?Reset@aiVehiclePolice@@UAEXXZ
    { 0x4451D0, 0xDDEC0708, 0x0000 }, // ?ResetPed@aiVehiclePolice@@QAEXXZ
    { 0x4453D0, 0xD4DCEDF1, 0x0000 }, // ?Update@aiVehiclePolice@@UAEXXZ
    { 0x4459D0, 0xB6DA4FE0, 0x0000 }, // ?InPersuit@aiVehiclePolice@@QAEHXZ
    { 0x445A00, 0x56D47D0F, 0x0000 }, // ?IsPerpInRange@aiVehiclePolice@@QAEHPAVmmCar@@@Z
    { 0x445C70, 0xE7AD790C, 0x0000 }, // ?FindPerp@aiVehiclePolice@@AAEHHHPAVaiPath@@HH@Z
    { 0x445DB0, 0x6C5AB5AC, 0x0000 }, // ?PerpEscapes@aiVehiclePolice@@QAEXE@Z
    { 0x445E20, 0x3280C7C2, 0x0000 }, // ?ConfigCar@aiVehiclePolice@@QAEXXZ
    { 0x445F20, 0x9B68C40A, 0x0000 }, // ?Backup@aiVehiclePolice@@QAEXXZ
    { 0x445F40, 0xB931116D, 0x0000 }, // ?DrawTargetPt@aiVehiclePolice@@QAEXXZ
    { 0x4460B0, 0x639563C4, 0x0000 }, // ?DrawDamage@aiVehiclePolice@@QAEXXZ
    { 0x446100, 0x8BD35601, 0x0000 }, // ?DrawId@aiVehiclePolice@@UAEXXZ
    { 0x446150, 0xD33DCA14, 0x0000 }, // ?UnAssignSounds@aiVehiclePolice@@QAEXXZ
    { 0x446170, 0xA85B5E34, 0x0000 }, // ?GetCarAudioPtr@aiVehiclePolice@@QAEPAVmmPoliceCarAudio@@XZ
    { 0x446180, 0x65131340, 0x0000 }, // ?GetEngineSoundIndex@aiVehiclePolice@@QAEHXZ
    { 0x446190, 0x0AD666F9, 0x0000 }, // ?SetMainSirenLoop@aiVehiclePolice@@QAEXH@Z
    { 0x4461B0, 0x9DA17643, 0x0000 }, // ?UpdateAudio@aiVehiclePolice@@QAEXXZ
    { 0x446270, 0x6D25E3F9, 0x0000 }, // ?GetDistanceToPlayer2@aiVehiclePolice@@QAEMXZ
    { 0x446280, 0xF204E952, 0x0000 }, // ?PlayVoice@aiVehiclePolice@@QAEXXZ
    { 0x446290, 0xB9CF03F5, 0x0000 }, // ?SetAudioMinDistance@aiVehiclePolice@@QAEXM@Z
    { 0x4462B0, 0x9053AF3A, 0x0000 }, // ?SetAudioMaxDistance@aiVehiclePolice@@QAEXM@Z
    { 0x4462E0, 0x7D6EC2FB, 0x0000 }, // ?SetAudioCloserMinDistMult@aiVehiclePolice@@QAEXM@Z
    { 0x446300, 0x6C543574, 0x0000 }, // ?AddToAiAudMgr@aiVehiclePolice@@AAEXXZ
    { 0x446370, 0x3CBBFE5C, 0x0000 }, // ?AssignSounds@aiVehiclePolice@@QAEXPAVAudSound@@000PAVmmOpponentImpactAudio@@0@Z
    { 0x4463A0, 0x1C5C6EE5, 0x0000 }, // ?GetAudioPtr@aiVehiclePolice@@QAEPAVmmPoliceCarAudio@@XZ
    { 0x4463B0, 0x4E17466C, 0x0000 }, // ?Dump@aiVehiclePolice@@QAEXXZ
    { 0x4465E0, 0x1C4B5315, 0x0000 }, // ?GetImpactAudioPtr@aiVehicleSpline@@UAEPAVmmOpponentImpactAudio@@XZ
    { 0x4465F0, 0x39B7B6C6, 0x0000 }, // ?PlayHorn@aiVehicleSpline@@UAEXMM@Z
    { 0x446600, 0xAC3B7852, 0x0000 }, // ?ImpactAudioReaction@aiVehicleSpline@@UAEXM@Z
    { 0x446610, 0x140FCEDF, 0x0000 }, // ?StopVoice@aiVehicleSpline@@UAEXXZ
    { 0x446620, 0x590ACD0D, 0x0000 }, // ?Type@aiVehiclePolice@@UAEHXZ
    { 0x446630, 0xC6EB8594, 0x0000 }, // ??0aiRaceData@@QAE@PAD0@Z
    { 0x446B10, 0xDC77D5AD, 0x0000 }, // ??1aiRaceData@@QAE@XZ
    { 0x446C00, 0x55EC3B19, 0x0000 }, // ??1CArrayList@@QAE@XZ
    { 0x446C20, 0x0F21CF29, 0x0000 }, // ?Append@CArrayList@@QAEXH@Z
    { 0x446C80, 0x0F6AC48F, 0x0000 }, // ??0aiPedAudioManager@@QAE@XZ
    { 0x446F80, 0xF5DE36FF, 0x0000 }, // ??1aiPedAudioManager@@UAE@XZ
    { 0x447030, 0x7A6420FC, 0x0000 }, // ?Add@aiPedAudioManager@@QAEFPAVaiPedestrian@@@Z
    { 0x4470E0, 0x1C0B9CCB, 0x0000 }, // ?Remove@aiPedAudioManager@@QAEXPAVaiPedestrian@@F@Z
    { 0x447150, 0x13169360, 0x0000 }, // ?FindGreatestDistance@aiPedAudioManager@@QAEFPAVaiPedestrian@@@Z
    { 0x4471E0, 0x32D994CF, 0x0000 }, // ?FindUnusedSlot@aiPedAudioManager@@QAEFXZ
    { 0x447220, 0xBC9D6A69, 0x0000 }, // ?Update@aiPedAudioManager@@UAEXXZ
    { 0x447280, 0x5EF14EEF, 0x0000 }, // ?AssignSounds@aiPedAudioManager@@QAEXF@Z
    { 0x4472A0, 0x13C19F70, 0x0000 }, // ?RandomizeSeconds@aiPedAudioManager@@QAEXMM@Z
    { 0x4472E0, 0x60F20425, 0x0000 }, // ??0aiIntersection@@QAE@H@Z
    { 0x447300, 0xEDE1F99B, 0x0000 }, // ??1aiIntersection@@QAE@XZ
    { 0x447370, 0x2A7C9366, 0x0000 }, // ?Init@aiIntersection@@QAEXXZ
    { 0x447520, 0x3E3A06F1, 0x0000 }, // ?Reset@aiIntersection@@QAEXXZ
    { 0x447530, 0x9F116767, 0x0000 }, // ?AddSinkPath@aiIntersection@@QAEXPAVaiPath@@@Z
    { 0x4475A0, 0x915B255F, 0x0000 }, // ?AddSourcePath@aiIntersection@@QAEXPAVaiPath@@@Z
    { 0x447610, 0xF9CAC81F, 0x0000 }, // ?SaveBinary@aiIntersection@@QAEXPAVStream@@@Z
    { 0x4476E0, 0x542CF74F, 0x0000 }, // ?ReadBinary@aiIntersection@@QAEXPAVStream@@@Z
    { 0x447880, 0x78D25679, 0x0000 }, // ?DrawPaths@aiIntersection@@QAEXXZ
    { 0x4478B0, 0x8F220002, 0x0000 }, // ?DrawId@aiIntersection@@QAEXXZ
    { 0x4478F0, 0xE3D6147C, 0x0000 }, // ?Dump@aiIntersection@@QAEXXZ
    { 0x447920, 0xAFC570BA, 0x0000 }, // ?CreateRoadMap@aiIntersection@@QAEXXZ
    { 0x447C50, 0xD87A7449, 0x0000 }, // ?Path@aiIntersection@@QAEPAVaiPath@@H@Z
    { 0x447CC0, 0xFF89C98D, 0x0000 }, // ??0aiPedestrian@@QAE@XZ
    { 0x447DA0, 0x09715670, 0x0000 }, // ??1aiPedestrian@@QAE@XZ
    { 0x447DB0, 0x69E7343A, 0x0000 }, // ?Init@aiPedestrian@@QAEXPADHH@Z
    { 0x448130, 0xCEE39B56, 0x0000 }, // ?Reset@aiPedestrian@@QAEXPAVaiPath@@@Z
    { 0x448460, 0x74A1FEAF, 0x0000 }, // ?Update@aiPedestrian@@QAEXXZ
    { 0x449850, 0xC8292492, 0x0000 }, // ?Wander@aiPedestrian@@AAEXXZ
    { 0x449CB0, 0x53CD8430, 0x0000 }, // ?Anticipate@aiPedestrian@@AAEXAAVmmIntersection@@H@Z
    { 0x449ED0, 0xAECFE5E3, 0x0000 }, // ?Avoid@aiPedestrian@@AAEXAAVmmIntersection@@PAM@Z
    { 0x44A2D0, 0x75C280E8, 0x0000 }, // ?TimeToCollision@aiPedestrian@@AAEMM@Z
    { 0x44A2F0, 0xF8CFA6A2, 0x0000 }, // ?DetectPlayerForwardCollision@aiPedestrian@@AAEHPAM0@Z
    { 0x44A4D0, 0xD9B6B7ED, 0x0000 }, // ?DetectPlayerAnticipate@aiPedestrian@@AAEHPAM0@Z
    { 0x44A690, 0x952AE9F3, 0x0000 }, // ?RoadDistance@aiPedestrian@@AAEMXZ
    { 0x44AD90, 0x84FD1C1F, 0x0000 }, // ?SolveRoadSegment@aiPedestrian@@AAEXM@Z
    { 0x44AED0, 0x806D1FCE, 0x0000 }, // ?PickNextRdSeg@aiPedestrian@@AAEPAVaiPath@@XZ
    { 0x44B0C0, 0x60E575A8, 0x0000 }, // ?DetectPlayerCollision@aiPedestrian@@AAEHPAM@Z
    { 0x44B420, 0x6E08008C, 0x0000 }, // ?DetectBangerCollision@aiPedestrian@@AAEHPAPAVmmInstance@@PAMM@Z
    { 0x44BA10, 0x23766062, 0x0000 }, // ?DetectBangerObstacle@aiPedestrian@@AAEPAVmmInstance@@XZ
    { 0x44BB80, 0xF277BBAA, 0x0000 }, // ?DetectPedObstacle@aiPedestrian@@AAEPAV1@XZ
    { 0x44BC00, 0xB3411233, 0x0000 }, // ?DetectPedCollision@aiPedestrian@@AAEHMPAPAV1@PAM@Z
    { 0x44C0E0, 0xC6E9E1AD, 0x0000 }, // ?AvoidPlayer@aiPedestrian@@AAEXAAVVector3@@M@Z
    { 0x44C170, 0x3FFD5E08, 0x0000 }, // ?AvoidBanger@aiPedestrian@@AAEXPAVmmInstance@@M@Z
    { 0x44C260, 0x932FF54C, 0x0000 }, // ?AvoidPedCollision@aiPedestrian@@AAEXPAV1@M@Z
    { 0x44C350, 0xAA968338, 0x0000 }, // ?AvoidObstacle@aiPedestrian@@AAEXAAVVector3@@M@Z
    { 0x44C670, 0xFD504203, 0x0000 }, // ?SolveTargetPoint@aiPedestrian@@AAEXM@Z
    { 0x44C6E0, 0x5577BE38, 0x0000 }, // ?CalcCurve@aiPedestrian@@AAEXHHM@Z
    { 0x44CDA0, 0x431D39E8, 0x0000 }, // ?ComputeCurve@aiPedestrian@@AAEXAAVVector3@@000@Z
    { 0x44CE50, 0xE3CC8D6C, 0x0000 }, // ?SolvePosition@aiPedestrian@@AAEXAAVVector3@@M@Z
    { 0x44CEA0, 0xF1952577, 0x0000 }, // ?PlayVoice@aiPedestrian@@QAEXF@Z
    { 0x44CF70, 0x47243263, 0x0000 }, // ?CalculateDistToPlayer2@aiPedestrian@@QAEXXZ
    { 0x44CFC0, 0x57376C59, 0x0000 }, // ?CalculateAudioPanning@aiPedestrian@@QAEXXZ
    { 0x44D010, 0x5CEAF9CE, 0x0000 }, // ?UpdateAudio@aiPedestrian@@QAEXXZ
    { 0x44D0E0, 0x8EA013A1, 0x0000 }, // ?SetVoiceSoundPtr@aiPedestrian@@QAEXPAVAudSound@@@Z
    { 0x44D0F0, 0xE403A734, 0x0000 }, // ?UnAssignSounds@aiPedestrian@@QAEXXZ
    { 0x44D130, 0xC57C0EE2, 0x0000 }, // ?Reset@aiPedestrian@@QAEXXZ
    { 0x44D160, 0xC7AD0E42, 0x0000 }, // ?Stop@aiPedestrian@@QAEXXZ
    { 0x44D1A0, 0xFCEDBB30, 0x0000 }, // ?Go@aiPedestrian@@QAEXXZ
    { 0x44D1E0, 0x18D24F0F, 0x0000 }, // ?Dump@aiPedestrian@@QAEXXZ
    { 0x44D3B0, 0x9B33623D, 0x0000 }, // ?DrawDebug@aiPedestrian@@QAEXXZ
    { 0x44D480, 0x2C896B3A, 0x0000 }, // ?GetRoamVoiceIndex@aiPedestrian@@AAEFXZ
    { 0x44D650, 0xF7FB4F15, 0x0000 }, // ?GetRaceVoiceIndex@aiPedestrian@@AAEFXZ
    { 0x44D7F0, 0x117719E8, 0x0000 }, // ?ToMatrix@aiPedestrianInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x44D800, 0x2B86EC24, 0x0000 }, // ?FromMatrix@aiPedestrianInstance@@UAIXABVMatrix34@@@Z
    { 0x44D810, 0xCD2935C6, 0x0000 }, // ?GetPos@aiPedestrianInstance@@UAIAAVVector3@@XZ
    { 0x44D820, 0xB3D85786, 0x0000 }, // ?ComputeLod@aiPedestrianInstance@@UAEHMM@Z
    { 0x44D850, 0x3EE1A26E, 0x0000 }, // ?Draw@aiPedestrianInstance@@UAIXH@Z
    { 0x44D960, 0xA639B1BB, 0x0000 }, // ?DrawShadow@aiPedestrianInstance@@UAIXXZ
    { 0x44DA30, 0xF2B1257B, 0x0000 }, // ?AddWidgets@aiPedestrianInstance@@UAEXPAVBank@@@Z
    { 0x44DA60, 0x0A7F3EBC, 0x0000 }, // ??1aiPedestrianInstance@@UAE@XZ
    { 0x44DA70, 0xFF0D93DE, 0x0000 }, // ??0aiVehicleOpponent@@QAE@XZ
    { 0x44DAD0, 0xDC0C3AEB, 0x0000 }, // ??1aiVehicleOpponent@@QAE@XZ
    { 0x44DC00, 0x17FB8BA5, 0x0000 }, // ?Init@aiVehicleOpponent@@QAEXHPAVaiRaceData@@PAD@Z
    { 0x44DE10, 0x9266C297, 0x0000 }, // ?Reset@aiVehicleOpponent@@UAEXXZ
    { 0x44DED0, 0x49F3B023, 0x0000 }, // ?Update@aiVehicleOpponent@@UAEXXZ
    { 0x44E060, 0x40727287, 0x0000 }, // ?Dump@aiVehicleOpponent@@QAEXXZ
    { 0x44E100, 0xDCBA3433, 0x0000 }, // ?UnAssignSounds@aiVehicleOpponent@@QAEXXZ
    { 0x44E120, 0x3362B7CC, 0x0000 }, // ?GetEngineSoundIndex@aiVehicleOpponent@@QAEHXZ
    { 0x44E130, 0xD50D70E4, 0x0000 }, // ?DrawTargetPt@aiVehicleOpponent@@QAEXXZ
    { 0x44E2A0, 0xB9ED3C9A, 0x0000 }, // ?DrawDamage@aiVehicleOpponent@@QAEXXZ
    { 0x44E2B0, 0x10FC787A, 0x0000 }, // ?DrawId@aiVehicleOpponent@@UAEXXZ
    { 0x44E300, 0x726986B8, 0x0000 }, // ?UpdateAudio@aiVehicleOpponent@@QAEXXZ
    { 0x44E3A0, 0x0AC38D6F, 0x0000 }, // ?GetDistanceToPlayer2@aiVehicleOpponent@@QAEMXZ
    { 0x44E3B0, 0x840BC140, 0x0000 }, // ?SetAudioMinDistance@aiVehicleOpponent@@QAEXM@Z
    { 0x44E3D0, 0x874993CC, 0x0000 }, // ?SetAudioMaxDistance@aiVehicleOpponent@@QAEXM@Z
    { 0x44E400, 0x5162E669, 0x0000 }, // ?SetAudioCloserMinDistMult@aiVehicleOpponent@@QAEXM@Z
    { 0x44E420, 0x7B40DE39, 0x0000 }, // ?GetCarAudioPtr@aiVehicleOpponent@@QAEPAVmmOpponentCarAudio@@XZ
    { 0x44E430, 0x65FD85FC, 0x0000 }, // ?AddToAiAudMgr@aiVehicleOpponent@@AAEXXZ
    { 0x44E490, 0xE86427BC, 0x0000 }, // ?AddWidget@aiVehicleOpponent@@QAEXPAVBank@@@Z
    { 0x44E4B0, 0xAB75CAE6, 0x0000 }, // ?AssignSounds@aiVehicleOpponent@@QAEXPAVAudSound@@0PAVmmOpponentImpactAudio@@0@Z
    { 0x44E4E0, 0x26488744, 0x0000 }, // ?DeclareFields@aiVehicleOpponent@@SAXXZ
    { 0x44E670, 0xE0798040, 0x0000 }, // ?GetClass@aiVehicleOpponent@@UAEPAVMetaClass@@XZ
    { 0x44E7D0, 0x49DD4C19, 0x0000 }, // ?Type@aiVehicleOpponent@@UAEHXZ
    { 0x44E7E0, 0x258CD118, 0x0000 }, // ??0aiPoliceForce@@QAE@XZ
    { 0x44E800, 0xEFB9E26A, 0x0000 }, // ??1aiPoliceForce@@QAE@XZ
    { 0x44E810, 0x562C445F, 0x0000 }, // ?Reset@aiPoliceForce@@QAEXXZ
    { 0x44E850, 0xE2B72C21, 0x0000 }, // ?Update@aiPoliceForce@@QAEXXZ
    { 0x44E860, 0xBBD109B5, 0x0000 }, // ?Find@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    { 0x44E8D0, 0xA4062FBB, 0x0000 }, // ?RegisterPerp@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    { 0x44E970, 0x782C6322, 0x0000 }, // ?UnRegisterCop@aiPoliceForce@@QAEHPAVmmCar@@0@Z
    { 0x44EA60, 0x9C874E4C, 0x0000 }, // ?State@aiPoliceForce@@QAEHPAVmmCar@@0M@Z
    { 0x44EC60, 0xA0C538F6, 0x0000 }, // ??0aiVehicleAmbient@@QAE@XZ
    { 0x44ED40, 0xA2D74CF1, 0x0000 }, // ??1aiVehicleAmbient@@QAE@XZ
    { 0x44EE10, 0x39AA7FD4, 0x0000 }, // ?Init@aiVehicleAmbient@@QAEXPADH@Z
    { 0x44F200, 0x831F98D4, 0x0000 }, // ?Reset@aiVehicleAmbient@@UAEXXZ
    { 0x44F2E0, 0xF0EB3B69, 0x0000 }, // ?Update@aiVehicleAmbient@@UAEXXZ
    { 0x44F490, 0x9F317B0A, 0x0000 }, // ?Impact@aiVehicleAmbient@@UAEXH@Z
    { 0x44F540, 0xB5C5CC7D, 0x0000 }, // ?UnAssignSounds@aiVehicleAmbient@@QAEXXZ
    { 0x44F620, 0x36AB7DE3, 0x0000 }, // ?CalculateDoppler@aiVehicleAmbient@@AAEMM@Z
    { 0x44F650, 0x82009686, 0x0000 }, // ?CalculateFerrariPitch@aiVehicleAmbient@@AAEMMH@Z
    { 0x44F820, 0x5932A4E1, 0x0000 }, // ?UpdateAudio@aiVehicleAmbient@@QAEXXZ
    { 0x44F850, 0xD604CFC8, 0x0000 }, // ?UpdateAudio@aiVehicleAmbient@@AAEXM@Z
    { 0x44FBE0, 0x53DF6ADA, 0x0000 }, // ?CalculateDistToPlayer2@aiVehicleAmbient@@QAEXXZ
    { 0x44FCF0, 0xE77CAC1B, 0x0000 }, // ?CalculateAudioPanning@aiVehicleAmbient@@QAEXXZ
    { 0x44FD80, 0xA23780CE, 0x0000 }, // ?DrawId@aiVehicleAmbient@@UAEXXZ
    { 0x44FD90, 0xF82019AF, 0x0000 }, // ?DrawBBox@aiVehicleAmbient@@QAEXF@Z
    { 0x4500F0, 0xB8982E56, 0x0000 }, // ?StopHorn@aiVehicleAmbient@@QAEXXZ
    { 0x450120, 0xE679A901, 0x0000 }, // ?PlayVoice@aiVehicleAmbient@@QAEXXZ
    { 0x450370, 0x53BCB9AA, 0x0000 }, // ?PlayHorn@aiVehicleAmbient@@QAEXXZ
    { 0x4505C0, 0xE085C12D, 0x0000 }, // ?PlayHorn@aiVehicleAmbient@@UAEXMM@Z
    { 0x4506B0, 0x79CCEAE7, 0x0000 }, // ?PlayTrippleHorn@aiVehicleAmbient@@QAEXM@Z
    { 0x450790, 0x3915A9F4, 0x0000 }, // ?UpdateHorn@aiVehicleAmbient@@QAEXXZ
    { 0x450A30, 0x78281ACF, 0x0000 }, // ?StopVoice@aiVehicleAmbient@@UAEXXZ
    { 0x450A70, 0x5F48E897, 0x0000 }, // ?UpdateAudImpactReaction@aiVehicleAmbient@@QAEXXZ
    { 0x450AB0, 0xD03C92B7, 0x0000 }, // ?ImpactAudioReaction@aiVehicleAmbient@@UAEXM@Z
    { 0x450B10, 0xBC13E584, 0x0000 }, // ?ImpactAudioReaction@aiVehicleAmbient@@AAEXXZ
    { 0x450BF0, 0x042CB2B7, 0x0000 }, // ?PlayDoubleHorn@aiVehicleAmbient@@QAEXM@Z
    { 0x450CC0, 0x1756AF6D, 0x0000 }, // ?AddToAiAudMgr@aiVehicleAmbient@@AAEXXZ
    { 0x450DA0, 0x97CF74A5, 0x0000 }, // ?SetAudioMaxDistance@aiVehicleAmbient@@SAXM@Z
    { 0x450DC0, 0x829AC9C8, 0x0000 }, // ?UpdateDSound3DAudio@aiVehicleAmbient@@AAEXXZ
    { 0x451000, 0x23BF5371, 0x0000 }, // ?AssignSounds@aiVehicleAmbient@@QAEXPAVAudSound@@00PAVmmOpponentImpactAudio@@@Z
    { 0x451150, 0xD35AD24E, 0x0000 }, // ?GetSecsSinceImpactReaction@aiVehicleAmbient@@SAMXZ
    { 0x451160, 0xBDF544C1, 0x0000 }, // ?Dump@aiVehicleAmbient@@QAEXXZ
    { 0x4512F0, 0x83574E01, 0x0000 }, // ??HVector3@@QBE?AV0@ABV0@@Z
    { 0x451320, 0x6888D567, 0x0000 }, // ??DVector3@@QBE?AV0@M@Z
    { 0x451350, 0x0F2AB3D6, 0x0000 }, // ?Type@aiVehicleAmbient@@UAEHXZ
    { 0x451360, 0x0D91E4F5, 0x0000 }, // ?GetImpactAudioPtr@aiVehicleAmbient@@UAEPAVmmOpponentImpactAudio@@XZ
    { 0x451450, 0xB1B2B7B5, 0x0000 }, // ?AMBIENTCB@@YAXPAVaiVehicleActive@@PAVasBound@@PAVmmIntersection@@PAVVector3@@M@Z
    { 0x4515E0, 0xBEEC4C80, 0x0000 }, // ?Draw@aiVehicleInstance@@UAIXH@Z
    { 0x451E20, 0x2229936D, 0x0000 }, // ?DrawGlow@aiVehicleInstance@@UAIXXZ
    { 0x451E70, 0x0A0DFD4F, 0x0000 }, // ?DrawShadow@aiVehicleInstance@@UAIXXZ
    { 0x451F10, 0x75023AA9, 0x0000 }, // ?GetEntity@aiVehicleInstance@@UAEPAVmmPhysEntity@@XZ
    { 0x451F40, 0x2D16CE1E, 0x0000 }, // ?Detach@aiVehicleInstance@@UAEXXZ
    { 0x451F70, 0x7D6A6323, 0x0000 }, // ?AttachEntity@aiVehicleInstance@@UAEPAVmmPhysEntity@@XZ
    { 0x451FD0, 0xE6981B1D, 0x0000 }, // ?GetVelocity@aiVehicleInstance@@UAE?AVVector3@@XZ
    { 0x452080, 0xBD47FAD7, 0x0000 }, // ?FromMatrix@aiVehicleInstance@@UAIXABVMatrix34@@@Z
    { 0x452090, 0x6D824EC6, 0x0000 }, // ?ToMatrix@aiVehicleInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x4520A0, 0x8D7CBB38, 0x0000 }, // ?GetPos@aiVehicleInstance@@UAIAAVVector3@@XZ
    { 0x4520B0, 0xBC12FF06, 0x0000 }, // ??0aiVehicleActive@@QAE@XZ
    { 0x4521A0, 0x3EBACE50, 0x0000 }, // ?Init@aiVehicleActive@@QAEXPAD@Z
    { 0x452450, 0x99D8B503, 0x0000 }, // ??1aiVehicleActive@@UAE@XZ
    { 0x452540, 0x931C348C, 0x0000 }, // ?Attach@aiVehicleActive@@QAEXPAVaiVehicleInstance@@@Z
    { 0x4526F0, 0xBC11D8E4, 0x0000 }, // ?DetachMe@aiVehicleActive@@UAEXXZ
    { 0x452710, 0x8AF2D139, 0x0000 }, // ?Detach@aiVehicleActive@@QAEXXZ
    { 0x4528E0, 0xDA6EB9C3, 0x0000 }, // ?Update@aiVehicleActive@@UAEXXZ
    { 0x452950, 0x146E70E7, 0x0000 }, // ?PostUpdate@aiVehicleActive@@UAEXXZ
    { 0x4529D0, 0xD73F440A, 0x0000 }, // ?UpdateDamage@aiVehicleActive@@QAEXXZ
    { 0x452A30, 0x52AF40CE, 0x0000 }, // ??0aiVehicleManager@@QAE@XZ
    { 0x452B10, 0x2B100672, 0x0000 }, // ??1aiVehicleManager@@UAE@XZ
    { 0x452BB0, 0x25187936, 0x0000 }, // ?Init@aiVehicleManager@@QAEXPAD@Z
    { 0x452BE0, 0x38B8D3E2, 0x0000 }, // ?Reset@aiVehicleManager@@UAEXXZ
    { 0x452C20, 0x8EFF4BEF, 0x0000 }, // ?Attach@aiVehicleManager@@QAEPAVaiVehicleActive@@PAVaiVehicleInstance@@@Z
    { 0x452CE0, 0xA43808BE, 0x0000 }, // ?Detach@aiVehicleManager@@QAEXPAVaiVehicleActive@@@Z
    { 0x452D70, 0x932ED39B, 0x0000 }, // ?Update@aiVehicleManager@@UAEXXZ
    { 0x452E60, 0x8DF30238, 0x0000 }, // ?LoadEntry@aiVehicleData@@QAEHPAD@Z
    { 0x453020, 0x05FE7DFD, 0x0000 }, // ?GetData@aiVehicleInstance@@QAEPAVaiVehicleData@@XZ
    { 0x453040, 0x74C561D4, 0x0000 }, // ?AddVehicleDataEntry@aiVehicleManager@@QAEHPAD@Z
    { 0x453350, 0x6B9F41AD, 0x0000 }, // ?Save@aiVehicleManager@@UAEXXZ
    { 0x453380, 0x818D5C5C, 0x0000 }, // ?AddWidgets@aiVehicleManager@@UAEXPAVBank@@@Z
    { 0x453390, 0x5A64CDE5, 0x0000 }, // ?AddWidgets@aiVehicleData@@UAEXPAVBank@@@Z
    { 0x453610, 0xBCB1127D, 0x0000 }, // ?DeclareFields@aiVehicleInstance@@SAXXZ
    { 0x4536B0, 0x7E4729BE, 0x0000 }, // ?GetClass@aiVehicleInstance@@UAEPAVMetaClass@@XZ
    { 0x4536C0, 0x9ECF6DD4, 0x0000 }, // ?DeclareFields@aiVehicleData@@SAXXZ
    { 0x4539F0, 0x2BD5656C, 0x0000 }, // ?GetClass@aiVehicleData@@UAEPAVMetaClass@@XZ
    { 0x453A30, 0x0B17D4E9, 0x0000 }, // ??1asInertialCS@@UAE@XZ
    { 0x453A40, 0x872BBD1E, 0x0000 }, // ??1asBound@@UAE@XZ
    { 0x453A50, 0x94AB4450, 0x0000 }, // ??1mmWheelCheap@@UAE@XZ
    { 0x453AF0, 0xD9BC8ADE, 0x0000 }, // ?Update@mmPhysEntity@@UAEXXZ
    { 0x453B00, 0x0304C249, 0x0000 }, // ?PostUpdate@mmPhysEntity@@UAEXXZ
    { 0x453B10, 0x03FE19BA, 0x0000 }, // ?GetBound@mmPhysEntity@@UAEPAVasBound@@XZ
    { 0x453B20, 0x0C2B3D34, 0x0000 }, // ?GetICS@mmPhysEntity@@UAEPAVasInertialCS@@XZ
    { 0x453B30, 0x9D6F37A0, 0x0000 }, // ?DetachMe@mmPhysEntity@@UAEXXZ
    { 0x453B70, 0xFC0ABBD3, 0x0000 }, // ??0aiVehicleData@@QAE@XZ
    { 0x453B90, 0x2CAF8660, 0x0000 }, // ??1aiVehicleData@@UAE@XZ
    { 0x453BA0, 0x541D2B87, 0x0000 }, // ?GetBound@aiVehicleActive@@UAEPAVasBound@@XZ
    { 0x453BB0, 0xEDC1C293, 0x0000 }, // ?GetICS@aiVehicleActive@@UAEPAVasInertialCS@@XZ
    { 0x453BC0, 0xE301FEB4, 0x0000 }, // ??1asBirthRule@@UAE@XZ
    { 0x453BF0, 0xFBCBD9DB, 0x0000 }, // ??0aiRailSet@@QAE@XZ
    { 0x453CF0, 0x2380EEDA, 0x0000 }, // ??1aiRailSet@@QAE@XZ
    { 0x453D00, 0x3852A699, 0x0000 }, // ?CalcRailPosition@aiRailSet@@QAEXAAVVector3@@M@Z
    { 0x454710, 0xA7EF0918, 0x0000 }, // ?CalcCopRailPosition@aiRailSet@@QAEHAAVVector3@@0MM@Z
    { 0x456B60, 0x19AB62EE, 0x0000 }, // ?CalcRailState@aiRailSet@@QAEHM@Z
    { 0x457170, 0x496D242B, 0x0000 }, // ?CalcRailLength@aiRailSet@@QAEMXZ
    { 0x457660, 0x21F095B3, 0x0000 }, // ?CalcTurnIntersection@aiRailSet@@QAEXAAVVector3@@HPAVaiPath@@1@Z
    { 0x457A70, 0x602A3021, 0x0000 }, // ?DrawTurn@aiRailSet@@QAEXM@Z
    { 0x458850, 0x01A8794D, 0x0000 }, // ?CalcRailPosOrient@aiRailSet@@QAEXAAVVector3@@0M@Z
    { 0x4593F0, 0xCED1097D, 0x0000 }, // ?SolveNextLane@aiRailSet@@QAEXXZ
    { 0x459470, 0x207DF7A2, 0x0000 }, // ?SolveTurnType@aiRailSet@@QAEHPAVaiPath@@0@Z
    { 0x459630, 0x0D743EFC, 0x0000 }, // ?CalcXZPosition@aiRailSet@@QAEXAAVVector3@@0000M@Z
    { 0x459740, 0x9069B137, 0x0000 }, // ?CalcXZDirection@aiRailSet@@QAEXAAVVector3@@0000M@Z
    { 0x459860, 0x8261E5E7, 0x0000 }, // ?CalcXZPosOrient@aiRailSet@@QAEXAAVVector3@@00000M@Z
    { 0x4599A0, 0x65AFA221, 0x0000 }, // ?ComputeXZCurve@aiRailSet@@QAEXAAVVector3@@000@Z
    { 0x459A50, 0x8A46B552, 0x0000 }, // ?ComputeXZCurve@aiRailSet@@QAEXAAVVector3@@000AAVVector4@@1@Z
    { 0x459AF0, 0x70C00155, 0x0000 }, // ?SolveXZCurve@aiRailSet@@QAEXAAVVector3@@0M@Z
    { 0x459B80, 0xDA201145, 0x0000 }, // ?SolveXZPosition@aiRailSet@@QAEXAAVVector3@@M@Z
    { 0x459BC0, 0xC8617B6A, 0x0000 }, // ?Dump@aiRailSet@@QAEXXZ
    { 0x459E00, 0x0BB914D1, 0x0000 }, // ??D@YA?AVVector3@@MABV0@@Z
    { 0x459E40, 0x5C784D7C, 0x0000 }, // ??TVector3@@QBEMABV0@@Z
    { 0x459E70, 0x6E0B0246, 0x0000 }, // ??GVector3@@QBE?AV0@XZ
    { 0x459E90, 0xC4C5DDC3, 0x0000 }, // ?LBoundary@aiPath@@QAEPAVVector3@@H@Z
    { 0x459EE0, 0x9DDE7CB1, 0x0000 }, // ??0aiVehicleSpline@@QAE@XZ
    { 0x459F50, 0x4F433556, 0x0000 }, // ??1aiVehicleSpline@@QAE@XZ
    { 0x459FC0, 0x2668F06F, 0x0000 }, // ?Init@aiVehicleSpline@@QAEXPADH@Z
    { 0x45A2B0, 0x8AC97E1F, 0x0000 }, // ?Reset@aiVehicleSpline@@UAEXXZ
    { 0x45A2F0, 0x7712BEBA, 0x0000 }, // ?Update@aiVehicleSpline@@UAEXXZ
    { 0x45A340, 0x5F63BC87, 0x0000 }, // ?ResetReactTicks@aiVehicleSpline@@QAEXXZ
    { 0x45A3A0, 0x197514A8, 0x0000 }, // ?SolvePositionAndOrientation@aiVehicleSpline@@QAEXXZ
    { 0x45AAB0, 0x038C0E11, 0x0000 }, // ?SolveYPositionAndOrientation@aiVehicleSpline@@QAEXXZ
    { 0x45B040, 0x2EBD68BF, 0x0000 }, // ?DetectPlayerForwardCollision@aiVehicleSpline@@QAEHXZ
    { 0x45B130, 0x89586764, 0x0000 }, // ?DetectPlayerTargetPtCollision@aiVehicleSpline@@QAEHXZ
    { 0x45B270, 0xEEDF1391, 0x0000 }, // ?DetectPlayerCollision@aiVehicleSpline@@QAEHHM@Z
    { 0x45B870, 0xEFDAAA9A, 0x0000 }, // ?DetectPlayerZoneCollision@aiVehicleSpline@@QAEHXZ
    { 0x45BA60, 0xC0F1831B, 0x0000 }, // ?IsThePlayerInFrontOfMe@aiVehicleSpline@@QAEHXZ
    { 0x45BB60, 0xA25E20BD, 0x0000 }, // ?IsAmbientBlockingPlayer@aiVehicleSpline@@QAEHXZ
    { 0x45BC50, 0x0463198F, 0x0000 }, // ?AvoidPlayerCollision@aiVehicleSpline@@QAEXXZ
    { 0x45BCD0, 0x8C4A9125, 0x0000 }, // ?WaitTime@aiVehicleSpline@@QAEHXZ
    { 0x45BCF0, 0x7EDC69AA, 0x0000 }, // ?TotLength@aiVehicleSpline@@QAEMXZ
    { 0x45BD00, 0x2C0C7E7D, 0x0000 }, // ?Impact@aiVehicleSpline@@UAEXH@Z
    { 0x45BD10, 0x40F77A74, 0x0000 }, // ?DistanceToVehicle@aiVehicleSpline@@QAEMPAV1@@Z
    { 0x45BFF0, 0x7B7D8C0C, 0x0000 }, // ?DistanceToIntersection@aiVehicleSpline@@QAEMXZ
    { 0x45C090, 0xA90D20CD, 0x0000 }, // ?Dump@aiVehicleSpline@@QAEXXZ
    { 0x45C1F0, 0xB1AE8974, 0x0000 }, // ?AddWidgets@aiVehicleSpline@@QAEXPAVBank@@@Z
    { 0x45C200, 0x798471F1, 0x0000 }, // ?DrawId@aiVehicleSpline@@UAEXXZ
    { 0x45C250, 0xD58290EB, 0x0000 }, // ?DeclareFields@aiVehicleSpline@@SAXXZ
    { 0x45C3E0, 0xBFF8CD6F, 0x0000 }, // ?GetClass@aiVehicleSpline@@UAEPAVMetaClass@@XZ
    { 0x45C420, 0x8C9D7E93, 0x0000 }, // ??LVector3@@QBE?AV0@ABV0@@Z
    { 0x45C470, 0x7F413CD1, 0x0000 }, // ?Scale@Vector3@@QAEXABV1@M@Z
    { 0x45C500, 0x74C6F58F, 0x0000 }, // ?Type@aiVehicleSpline@@UAEHXZ
    { 0x45C510, 0x8CEAF5D2, 0x0000 }, // ?AddWidgets@aiVehicleInstance@@UAEXPAVBank@@@Z
    { 0x45C550, 0xD65629E4, 0x0000 }, // ??1aiVehicleInstance@@UAE@XZ
    { 0x45C560, 0xD8BE19BC, 0x0000 }, // ??0AddOnCarAudio@@QAE@PADF@Z
    { 0x45C690, 0xD7EFD09A, 0x0000 }, // ??1AddOnCarAudio@@QAE@XZ
    { 0x45C6E0, 0xBFE2C592, 0x0000 }, // ?GetEngineSoundPtr@AddOnCarAudio@@QAEPAVAudSound@@F@Z
    { 0x45C700, 0xFFCFF659, 0x0000 }, // ?EchoOn@AddOnCarAudio@@QAEXM@Z
    { 0x45C750, 0x28958760, 0x0000 }, // ?EchoOff@AddOnCarAudio@@QAEXXZ
    { 0x45C780, 0x41302783, 0x0000 }, // ?Update@AddOnCarAudio@@QAEXXZ
    { 0x45C7E0, 0xFBD9976F, 0x0000 }, // ??0aiGoalRandomDrive@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    { 0x45C8A0, 0xA8BF3CB8, 0x0000 }, // ??1aiGoalRandomDrive@@QAE@XZ
    { 0x45C8B0, 0x559A5703, 0x0000 }, // ?Init@aiGoalRandomDrive@@UAEXXZ
    { 0x45C8D0, 0x70C37720, 0x0000 }, // ?Reset@aiGoalRandomDrive@@UAEXXZ
    { 0x45D320, 0xB3F23D65, 0x0000 }, // ?Update@aiGoalRandomDrive@@UAEXXZ
    { 0x45D440, 0x8D71E5D1, 0x0000 }, // ?Context@aiGoalRandomDrive@@UAEHXZ
    { 0x45D460, 0x3F3BF5EC, 0x0000 }, // ?Priority@aiGoalRandomDrive@@UAEHXZ
    { 0x45D470, 0x1FD5DC37, 0x0000 }, // ?SolveVelocity@aiGoalRandomDrive@@AAEXXZ
    { 0x45DC00, 0xE0816EBB, 0x0000 }, // ?OkayToEnterIntersection@aiGoalRandomDrive@@AAEHXZ
    { 0x45DE10, 0x7C2090E4, 0x0000 }, // ?AnyVehiclesComingThisWay@aiGoalRandomDrive@@AAEHXZ
    { 0x45E020, 0x1FB0AB7B, 0x0000 }, // ?AvoidCollision@aiGoalRandomDrive@@AAEXPAVaiVehicleSpline@@M@Z
    { 0x45E250, 0x603FF5F2, 0x0000 }, // ?SolvePosition@aiGoalRandomDrive@@QAEXAAVVector3@@M@Z
    { 0x45E2A0, 0x0EFBEDBD, 0x0000 }, // ?SolveRailType@aiGoalRandomDrive@@AAEXXZ
    { 0x45F0B0, 0x95EDC9B5, 0x0000 }, // ?SolveLane@aiGoalRandomDrive@@AAEXXZ
    { 0x45F1A0, 0xD7EC0E6F, 0x0000 }, // ?ChangeLanes@aiGoalRandomDrive@@AAEXXZ
    { 0x45F690, 0x63CBC5CF, 0x0000 }, // ?Dump@aiGoalRandomDrive@@QAEXXZ
    { 0x45F6F0, 0xE5A40B35, 0x0000 }, // ??1aiGoal@@QAE@XZ
    { 0x45F700, 0x634BC509, 0x0000 }, // ?Update@aiGoal@@UAEXXZ
    { 0x45F710, 0x79B5536D, 0x0000 }, // ??0aiGoalStop@@QAE@PAVmmCar@@PAF@Z
    { 0x45F740, 0x78D51D3E, 0x0000 }, // ??1aiGoalStop@@QAE@XZ
    { 0x45F750, 0x9AA1A0E4, 0x0000 }, // ?Init@aiGoalStop@@UAEXXZ
    { 0x45F760, 0xDA41B099, 0x0000 }, // ?Reset@aiGoalStop@@UAEXXZ
    { 0x45F770, 0x3233F016, 0x0000 }, // ?Update@aiGoalStop@@UAEXXZ
    { 0x45F7D0, 0x922C09D5, 0x0000 }, // ?Context@aiGoalStop@@UAEHXZ
    { 0x45F7F0, 0x386580BE, 0x0000 }, // ?Priority@aiGoalStop@@UAEHXZ
    { 0x45F830, 0xE119DB15, 0x0000 }, // ??0aiGoalBackup@@QAE@PAVaiRailSet@@PAVmmCar@@PAF@Z
    { 0x45F860, 0xD2D7577E, 0x0000 }, // ??1aiGoalBackup@@QAE@XZ
    { 0x45F870, 0xF3A7E4D2, 0x0000 }, // ?Init@aiGoalBackup@@UAEXXZ
    { 0x45F880, 0xE3D09998, 0x0000 }, // ?Context@aiGoalBackup@@UAEHXZ
    { 0x45F890, 0x1BE073A1, 0x0000 }, // ?Priority@aiGoalBackup@@UAEHXZ
    { 0x45F8A0, 0xA5A8AD84, 0x0000 }, // ?Reset@aiGoalBackup@@UAEXXZ
    { 0x45F8D0, 0xCD3E7DBA, 0x0000 }, // ?Update@aiGoalBackup@@UAEXXZ
    { 0x45FC10, 0xACD3B574, 0x0000 }, // ?FinishedBackingUp@aiGoalBackup@@AAEXXZ
    { 0x45FCC0, 0xCAA35DF3, 0x0000 }, // ??0aiGoalChase@@QAE@PAVaiVehiclePolice@@PAVaiRailSet@@PAPAVmmCar@@PAFPAVVector3@@3@Z
    { 0x45FD70, 0x72D32114, 0x0000 }, // ??1aiGoalChase@@QAE@XZ
    { 0x45FDC0, 0x93849D33, 0x0000 }, // ?Init@aiGoalChase@@UAEXXZ
    { 0x45FED0, 0xF3832343, 0x0000 }, // ?Reset@aiGoalChase@@UAEXXZ
    { 0x460080, 0x58B4410A, 0x0000 }, // ?Context@aiGoalChase@@UAEHXZ
    { 0x460420, 0x1FC94963, 0x0000 }, // ?Fov@aiGoalChase@@AAEHPAVmmCar@@@Z
    { 0x4605B0, 0x05996026, 0x0000 }, // ?Speeding@aiGoalChase@@AAEHPAVmmCar@@@Z
    { 0x460600, 0x8D7F944F, 0x0000 }, // ?Collision@aiGoalChase@@AAEHPAVmmCar@@@Z
    { 0x460620, 0x3AE4509A, 0x0000 }, // ?HitMe@aiGoalChase@@AAEHPAVmmCar@@@Z
    { 0x460640, 0xAA492F1A, 0x0000 }, // ?Stopped@aiGoalChase@@AAEHPAVmmCar@@@Z
    { 0x460670, 0xAFF380C5, 0x0000 }, // ?IsPerpACop@aiGoalChase@@AAEHPAVmmCar@@@Z
    { 0x460690, 0xE9599371, 0x0000 }, // ?OffRoad@aiGoalChase@@AAEHPAVmmCar@@@Z
    { 0x460760, 0xA5197798, 0x0000 }, // ?Priority@aiGoalChase@@UAEHXZ
    { 0x460770, 0x4EFCAF7B, 0x0000 }, // ?Update@aiGoalChase@@UAEXXZ
    { 0x4613F0, 0x036A5846, 0x0000 }, // ?PlanRoute@aiGoalChase@@AAEHXZ
    { 0x461490, 0x499293DB, 0x0000 }, // ?LocatePerpFromRoad@aiGoalChase@@AAEHPAVaiPath@@PAPAV2@1@Z
    { 0x461B60, 0xD8A866D2, 0x0000 }, // ?LocatePerpFromInt@aiGoalChase@@AAEHPAVaiIntersection@@PAPAVaiPath@@@Z
    { 0x461DC0, 0xD0C2B6D4, 0x0000 }, // ?FindPerp@aiGoalChase@@AAEHHHPAVaiPath@@@Z
    { 0x461EF0, 0xB1CA6A6A, 0x0000 }, // ?DetectCopCollision@aiGoalChase@@AAEPAVaiVehiclePolice@@XZ
    { 0x462030, 0x4FC4C732, 0x0000 }, // ?AvoidCopCollision@aiGoalChase@@AAEXPAVaiVehiclePolice@@@Z
    { 0x462300, 0x23ECC6FD, 0x0000 }, // ?Follow@aiGoalChase@@AAEXXZ
    { 0x462430, 0xB21FC5BB, 0x0000 }, // ?CalcSpeed@aiGoalChase@@AAEXM@Z
    { 0x462BB0, 0x3D83218F, 0x0000 }, // ?CloseInRoad@aiGoalChase@@AAEXXZ
    { 0x463090, 0xA3935E5B, 0x0000 }, // ?CloseInOpenArea@aiGoalChase@@AAEXXZ
    { 0x463570, 0x964523E0, 0x0000 }, // ?Barricade@aiGoalChase@@AAEXXZ
    { 0x463A00, 0x86D8C2B4, 0x0000 }, // ?Block@aiGoalChase@@AAEXXZ
    { 0x463E10, 0xDEB7DC6C, 0x0000 }, // ?Push@aiGoalChase@@AAEXXZ
    { 0x464000, 0xFF6E81FA, 0x0000 }, // ?DetectAmbientCollision@aiGoalChase@@AAEHPAH@Z
    { 0x464F10, 0x94A006CB, 0x0000 }, // ?AddToBlockedRange@aiGoalChase@@AAEXMMM@Z
    { 0x4650B0, 0x3CD74299, 0x0000 }, // ?AvoidAmbientCollision@aiGoalChase@@AAEXH@Z
    { 0x465310, 0x0291DF98, 0x0000 }, // ?ProcessCollision@aiGoalChase@@AAEXH@Z
    { 0x4655D0, 0x623F24B6, 0x0000 }, // ?Dump@aiGoalChase@@QAEXXZ
    { 0x4658E0, 0x10452FBC, 0x0000 }, // ??1aiStuck@@UAE@XZ
    { 0x4658F0, 0x6D67EB66, 0x0000 }, // ??0aiVehicle@@QAE@XZ
    { 0x465910, 0xB0FD0CD2, 0x0000 }, // ??1aiVehicle@@QAE@XZ
    { 0x465920, 0xC5C8C7D2, 0x0000 }, // ?Init@aiVehicle@@QAEXH@Z
    { 0x465930, 0x156AE3C7, 0x0000 }, // ?Reset@aiVehicle@@UAEXXZ
    { 0x465940, 0x1D694F46, 0x0000 }, // ?Update@aiVehicle@@UAEXXZ
    { 0x4659B0, 0xD67C739A, 0x0000 }, // ??0aiGoalFollowWayPts@@QAE@XZ
    { 0x465A10, 0xDE225158, 0x0000 }, // ??0aiGoalFollowWayPts@@QAE@PADPAVaiRailSet@@PAVaiVehicleOpponent@@PAF330M@Z
    { 0x466420, 0xF90F1EE8, 0x0000 }, // ??1aiGoalFollowWayPts@@QAE@XZ
    { 0x4664D0, 0x9DABDE29, 0x0000 }, // ?Init@aiGoalFollowWayPts@@UAEXXZ
    { 0x4668C0, 0xC0B97A6D, 0x0000 }, // ?Context@aiGoalFollowWayPts@@UAEHXZ
    { 0x4669B0, 0x01F92C9F, 0x0000 }, // ?Priority@aiGoalFollowWayPts@@UAEHXZ
    { 0x4669C0, 0xCBD8BA87, 0x0000 }, // ?Reset@aiGoalFollowWayPts@@UAEXXZ
    { 0x466AB0, 0xAB6882DE, 0x0000 }, // ?Update@aiGoalFollowWayPts@@UAEXXZ
    { 0x466EA0, 0x5E080BCB, 0x0000 }, // ?DetectOpponentCollision@aiGoalFollowWayPts@@AAEPAVaiVehicleOpponent@@XZ
    { 0x467040, 0xF8374B5A, 0x0000 }, // ?AvoidOpponentCollision@aiGoalFollowWayPts@@AAEXPAVaiVehicleOpponent@@@Z
    { 0x4674B0, 0x25170586, 0x0000 }, // ?PlanRoute@aiGoalFollowWayPts@@AAEXXZ
    { 0x4676E0, 0x03E9F287, 0x0000 }, // ?LocateWayPtFromRoad@aiGoalFollowWayPts@@AAEHPAVaiPath@@PAPAV2@1@Z
    { 0x467D60, 0x5A6BC845, 0x0000 }, // ?LocateWayPtFromInt@aiGoalFollowWayPts@@AAEHPAVaiIntersection@@PAPAVaiPath@@@Z
    { 0x467E40, 0xC76AC140, 0x0000 }, // ?DetRdSegBetweenInts@aiGoalFollowWayPts@@AAEPAVaiPath@@PAVaiIntersection@@0@Z
    { 0x467ED0, 0x9B27DC8B, 0x0000 }, // ?DetectCollision@aiGoalFollowWayPts@@AAEHPAH@Z
    { 0x468B00, 0xB0554416, 0x0000 }, // ?AddToBlockedRange@aiGoalFollowWayPts@@AAEXMMM@Z
    { 0x468CA0, 0x77D9B4C0, 0x0000 }, // ?AvoidCollision@aiGoalFollowWayPts@@AAEXH@Z
    { 0x469170, 0x3927D9D6, 0x0000 }, // ?CalcSpeed@aiGoalFollowWayPts@@AAEXXZ
    { 0x469E10, 0xA70AB98C, 0x0000 }, // ?SolveTargetPoint@aiGoalFollowWayPts@@AAEXXZ
    { 0x469E60, 0x17744E20, 0x0000 }, // ?Dump@aiGoalFollowWayPts@@QAEXXZ
    { 0x46A0E0, 0x217F90FD, 0x0000 }, // ?AddWidgets@aiGoalFollowWayPts@@QAEXPAVBank@@@Z
    { 0x46A140, 0x581C3873, 0x0000 }, // ?DeclareFields@aiGoalFollowWayPts@@SAXXZ
    { 0x46A2D0, 0x2DB38240, 0x0000 }, // ?GetClass@aiGoalFollowWayPts@@UAEPAVMetaClass@@XZ
    { 0x46A370, 0x3732EB8F, 0x0000 }, // ??0aiGoalAvoidPlayer@@QAE@PAVaiRailSet@@PAVaiVehicleAmbient@@@Z
    { 0x46A3A0, 0xF0D020FB, 0x0000 }, // ??1aiGoalAvoidPlayer@@QAE@XZ
    { 0x46A3B0, 0xE246AEC1, 0x0000 }, // ?Init@aiGoalAvoidPlayer@@UAEXXZ
    { 0x46A3C0, 0x40AADDB5, 0x0000 }, // ?Reset@aiGoalAvoidPlayer@@UAEXXZ
    { 0x46A530, 0xE7994D1F, 0x0000 }, // ?Update@aiGoalAvoidPlayer@@UAEXXZ
    { 0x46A700, 0x3F9725ED, 0x0000 }, // ?AvoidPlayer@aiGoalAvoidPlayer@@AAEXXZ
    { 0x46A970, 0x10FB4D28, 0x0000 }, // ?Context@aiGoalAvoidPlayer@@UAEHXZ
    { 0x46A990, 0xF83586E4, 0x0000 }, // ?Priority@aiGoalAvoidPlayer@@UAEHXZ
    { 0x46A9A0, 0xE5CFBAFD, 0x0000 }, // ?Dump@aiGoalAvoidPlayer@@QAEXXZ
    { 0x46AA20, 0xC4DBF093, 0x0000 }, // ??0aiGoalRegainRail@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    { 0x46AA50, 0x1EE7465B, 0x0000 }, // ??1aiGoalRegainRail@@QAE@XZ
    { 0x46AA60, 0x8EB190F5, 0x0000 }, // ?Init@aiGoalRegainRail@@UAEXXZ
    { 0x46AA80, 0x9EEC33B4, 0x0000 }, // ?Reset@aiGoalRegainRail@@UAEXXZ
    { 0x46B130, 0x3840EA50, 0x0000 }, // ?Update@aiGoalRegainRail@@UAEXXZ
    { 0x46B240, 0xE9DE1FBB, 0x0000 }, // ?Context@aiGoalRegainRail@@UAEHXZ
    { 0x46B260, 0x7B2EC978, 0x0000 }, // ?Priority@aiGoalRegainRail@@UAEHXZ
    { 0x46B270, 0x2DEF6E2F, 0x0000 }, // ?Dump@aiGoalRegainRail@@QAEXXZ
    { 0x46B2F0, 0x9BE56645, 0x0000 }, // ??0aiGoalCollision@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    { 0x46B320, 0x405269AE, 0x0000 }, // ??1aiGoalCollision@@QAE@XZ
    { 0x46B330, 0x98388FB9, 0x0000 }, // ?Init@aiGoalCollision@@UAEXXZ
    { 0x46B340, 0x32E39F69, 0x0000 }, // ?Reset@aiGoalCollision@@UAEXXZ
    { 0x46B350, 0x316A9A5A, 0x0000 }, // ?Update@aiGoalCollision@@UAEXXZ
    { 0x46B3D0, 0xFA3E7A2B, 0x0000 }, // ?Context@aiGoalCollision@@UAEHXZ
    { 0x46B3F0, 0x08E1E4DE, 0x0000 }, // ?Priority@aiGoalCollision@@UAEHXZ
    { 0x46B400, 0x416EE6B0, 0x0000 }, // ??0aiStuck@@QAE@XZ
    { 0x46B470, 0x7EE56A97, 0x0000 }, // ?StuckCB@@YAXPAVaiStuck@@@Z
    { 0x46B4A0, 0x72645083, 0x0000 }, // ?Init@aiStuck@@QAEXPAVmmCarSim@@@Z
    { 0x46B4C0, 0xF0BBACC0, 0x0000 }, // ?Impact@aiStuck@@QAEXXZ
    { 0x46B4D0, 0x22C29C56, 0x0000 }, // ?Reset@aiStuck@@UAEXXZ
    { 0x46B4E0, 0xDAB05A84, 0x0000 }, // ?Pegged@aiStuck@@QAEHXZ
    { 0x46B550, 0x9A1D8092, 0x0000 }, // ?Update@aiStuck@@UAEXXZ
    { 0x46B770, 0x5938875E, 0x0000 }, // ?AddWidgets@aiStuck@@UAEXPAVBank@@@Z
    { 0x46B8F0, 0x865EF2B2, 0x0000 }, // ?IMPACTCB@@YAXPAVmmCarSim@@PAVasBound@@PAVmmIntersection@@PAVVector3@@M3@Z
    { 0x46B950, 0x0E70CDF9, 0x0000 }, // ??0mmCarSim@@QAE@XZ
    { 0x46BFF0, 0xEBFE933D, 0x0000 }, // ?OnGround@mmCarSim@@QAEHXZ
    { 0x46C030, 0xC1B42FAB, 0x0000 }, // ?SetGlobalTuning@mmCarSim@@SAXMM@Z
    { 0x46C040, 0x3456AA89, 0x0000 }, // ??1mmCarSim@@UAE@XZ
    { 0x46C340, 0xE4FC8F30, 0x0000 }, // ?AddPlayerSpecifics@mmCarSim@@QAEXXZ
    { 0x46C3C0, 0xD2CB1655, 0x0000 }, // ?PlayHorn@mmCarSim@@QAEXXZ
    { 0x46C430, 0xA3B911F3, 0x0000 }, // ?StopHorn@mmCarSim@@QAEXXZ
    { 0x46C4A0, 0x3C87D6C6, 0x0000 }, // ?StartSiren@mmCarSim@@QAEXXZ
    { 0x46C4D0, 0xFCA4A8D1, 0x0000 }, // ?StopSiren@mmCarSim@@QAEXXZ
    { 0x46C500, 0x9E15FEB4, 0x0000 }, // ?Init@mmCarSim@@QAEXPADPAVmmCar@@H@Z
    { 0x46CB20, 0xADF32E65, 0x0000 }, // ?ReInit@mmCarSim@@QAEXPAD@Z
    { 0x46D020, 0xA60D6B2D, 0x0000 }, // ?RestoreImpactParams@mmCarSim@@QAEXXZ
    { 0x46D040, 0x51A0D259, 0x0000 }, // ?SetHackedImpactParams@mmCarSim@@QAEXXZ
    { 0x46D060, 0xE09C6CD0, 0x0000 }, // ?ReconfigureDrivetrain@mmCarSim@@QAEXXZ
    { 0x46D080, 0x64908FF1, 0x0000 }, // ?ConfigureDrivetrain@mmCarSim@@QAEXXZ
    { 0x46D300, 0x46BA1CB0, 0x0000 }, // ?UnconfigureDrivetrain@mmCarSim@@QAEXXZ
    { 0x46D500, 0x25FB37E6, 0x0000 }, // ?SetResetPos@mmCarSim@@QAEXAAVVector3@@@Z
    { 0x46D540, 0xDDAADF27, 0x0000 }, // ?AfterLoad@mmCarSim@@UAEXXZ
    { 0x46D600, 0xDEB53B9D, 0x0000 }, // ?BeforeSave@mmCarSim@@UAEXXZ
    { 0x46D680, 0xF2F771CF, 0x0000 }, // ?UpdateICSParams@mmCarSim@@QAEXXZ
    { 0x46D6B0, 0x840143BC, 0x0000 }, // ?Reset@mmCarSim@@UAEXXZ
    { 0x46D860, 0x2B58AA58, 0x0000 }, // ?Update@mmCarSim@@UAEXXZ
    { 0x46E080, 0xCD2C6851, 0x0000 }, // ?Explode@mmCarSim@@QAEXXZ
    { 0x46E160, 0x26636D4F, 0x0000 }, // ?UpdateExhaust@mmCarSim@@QAEXXZ
    { 0x46E270, 0x7E4CE8E9, 0x0000 }, // ?UpdateDamage@mmCarSim@@QAEXXZ
    { 0x46E520, 0x38A2E8A8, 0x0000 }, // ?UpdateFF@mmCarSim@@QAEXXZ
    { 0x46E7E0, 0xC679FDFB, 0x0000 }, // ?ShouldSkid@mmCarSim@@QAEHXZ
    { 0x46E830, 0x38044767, 0x0000 }, // ?RemoveNetVehicleAudio@mmCarSim@@QAEXXZ
    { 0x46E840, 0x2609AAA7, 0x0000 }, // ?AddWidgets@mmCarSim@@UAEXPAVBank@@@Z
    { 0x46F5B0, 0x91B449DC, 0x0000 }, // ?InitPtx@mmCarSim@@QAEXXZ
    { 0x46FAA0, 0x929717E4, 0x0000 }, // ?PlayImpactAudio@mmCarSim@@QAEXFPAVmmIntersection@@PAVVector3@@@Z
    { 0x46FBC0, 0x5E99A00A, 0x0000 }, // ?DeclareFields@mmCarSim@@SAXXZ
    { 0x4701A0, 0x854D1023, 0x0000 }, // ?GetClass@mmCarSim@@UAEPAVMetaClass@@XZ
    { 0x470300, 0x00EFD1A9, 0x0000 }, // ??1mmStuck@@UAE@XZ
    { 0x470310, 0xD5E21477, 0x0000 }, // ??1mmSplash@@UAE@XZ
    { 0x470320, 0xFAF5E769, 0x0000 }, // ??1asAero@@UAE@XZ
    { 0x470330, 0x7DD0804A, 0x0000 }, // ??1mmForce@@UAE@XZ
    { 0x470340, 0x2E296578, 0x0000 }, // ??1VehGyro@@UAE@XZ
    { 0x470350, 0xC664C764, 0x0000 }, // ??1mmDrivetrain@@UAE@XZ
    { 0x470360, 0xAD1E02E0, 0x0000 }, // ??1mmWheel@@UAE@XZ
    { 0x470370, 0x382BCB5F, 0x0000 }, // ??1mmAxle@@UAE@XZ
    { 0x470380, 0xBBCE4BE3, 0x0000 }, // ??1mmShock@@UAE@XZ
    { 0x470390, 0x4A9770B0, 0x0000 }, // ??1mmTransmission@@UAE@XZ
    { 0x4703A0, 0xDC96F9B2, 0x0000 }, // ?Struct@@YAPAUMetaType@@PAVMetaClass@@@Z
    { 0x470430, 0xCAD30731, 0x0000 }, // ??0mmTransmission@@QAE@XZ
    { 0x470500, 0x331E6BBA, 0x0000 }, // ?Init@mmTransmission@@QAEXPAVmmCarSim@@@Z
    { 0x470540, 0x4EB8BA1D, 0x0000 }, // ?Reset@mmTransmission@@UAEXXZ
    { 0x470570, 0xC6E6EF3A, 0x0000 }, // ?Upshift@mmTransmission@@QAEHXZ
    { 0x4705A0, 0xA1991FD0, 0x0000 }, // ?Downshift@mmTransmission@@QAEHXZ
    { 0x4705C0, 0xA0EC74B0, 0x0000 }, // ?Update@mmTransmission@@UAEXXZ
    { 0x4706C0, 0xB69AC6E7, 0x0000 }, // ?CopyTrans@mmTransmission@@QAEXXZ
    { 0x4706F0, 0x1CD9FF55, 0x0000 }, // ?Automatic@mmTransmission@@QAEXH@Z
    { 0x470710, 0xE4A1781D, 0x0000 }, // ?SetReverse@mmTransmission@@QAEXXZ
    { 0x470720, 0x7DE6DE54, 0x0000 }, // ?SetDrive@mmTransmission@@QAEXXZ
    { 0x470740, 0x27CBAC0A, 0x0000 }, // ?GetCurrentGear@mmTransmission@@QAEHXZ
    { 0x470750, 0x11B4872B, 0x0000 }, // ?SetCurrentGear@mmTransmission@@QAEHH@Z
    { 0x470790, 0x5830ADA8, 0x0000 }, // ?AddWidgets@mmTransmission@@UAEXPAVBank@@@Z
    { 0x470A30, 0xEDC21122, 0x0000 }, // ?DeclareFields@mmTransmission@@SAXXZ
    { 0x470C80, 0xA959EE81, 0x0000 }, // ?GetClass@mmTransmission@@UAEPAVMetaClass@@XZ
    { 0x470CC0, 0x17CF37F8, 0x0000 }, // ?ArrayOf@@YAPAUMetaType@@PAU1@H@Z
    { 0x470D50, 0x20A723A4, 0x0000 }, // ?SetClearSurfaceAudioInfos@@YAXXZ
    { 0x470FB0, 0x8632CAC0, 0x0000 }, // ?SetRainSurfaceAudioInfos@@YAXXZ
    { 0x471210, 0xBA05ED51, 0x0000 }, // ?SetSnowSurfaceAudioInfos@@YAXXZ
    { 0x471490, 0x85F13A7A, 0x0000 }, // ??0mmCarModel@@QAE@XZ
    { 0x471540, 0x00B60573, 0x0000 }, // ??1mmCarModel@@UAE@XZ
    { 0x4715A0, 0x0C34B934, 0x0000 }, // ?FromMatrix@mmCarModel@@UAIXABVMatrix34@@@Z
    { 0x4715C0, 0xB92DB7A0, 0x0000 }, // ?ToMatrix@mmCarModel@@UAIAAVMatrix34@@AAV2@@Z
    { 0x4715D0, 0x414856D4, 0x0000 }, // ?GetPos@mmCarModel@@UAIAAVVector3@@XZ
    { 0x471640, 0x4F2E14BD, 0x0000 }, // ?Impact@mmCarModel@@QAEXPAVVector3@@@Z
    { 0x471780, 0x99FC2A0C, 0x0000 }, // ?EjectWheels@mmCarModel@@QAEXH@Z
    { 0x4718D0, 0xB150C075, 0x0000 }, // ?EjectPart@mmCarModel@@QAEXPAVmmWheel@@FFH@Z
    { 0x471B70, 0xA2A6B992, 0x0000 }, // ?Draw@mmCarModel@@UAIXH@Z
    { 0x472B00, 0x8E6873FB, 0x0000 }, // ?DrawGlow@mmCarModel@@UAIXXZ
    { 0x472B90, 0x46EDC499, 0x0000 }, // ?DrawShadow@mmCarModel@@UAIXXZ
    { 0x472BE0, 0x3DA9F0C6, 0x0000 }, // ?GetCarFlags@mmCarModel@@QAEHPAD@Z
    { 0x472BF0, 0x8F73B6C8, 0x0000 }, // ?InitDamage@mmCarModel@@QAEXXZ
    { 0x472C50, 0xCDD0B1F2, 0x0000 }, // ?GetPart@mmCarModel@@QAEPAVmmHitBangerInstance@@H@Z
    { 0x472CA0, 0x67F990D5, 0x0000 }, // ?ClearDamage@mmCarModel@@QAEXH@Z
    { 0x472D90, 0xADFC0A6F, 0x0000 }, // ?ApplyDamage@mmCarModel@@QAEXAAVVector3@@M@Z
    { 0x472DC0, 0x644BB73B, 0x0000 }, // ?Init@mmCarModel@@QAEXPADPAVmmCar@@H@Z
    { 0x473080, 0x8719D1AF, 0x0000 }, // ?DashActivated@mmCarModel@@QAEXXZ
    { 0x473090, 0x83A7CAFB, 0x0000 }, // ?DashDeactivated@mmCarModel@@QAEXXZ
    { 0x4730A0, 0xE1F77012, 0x0000 }, // ?Activate@mmCarModel@@QAEXXZ
    { 0x4730B0, 0xFF17287A, 0x0000 }, // ?Deactivate@mmCarModel@@QAEXXZ
    { 0x4730D0, 0x8E9C47EA, 0x0000 }, // ?Kill@mmCarModel@@QAEXXZ
    { 0x4730E0, 0xE75F24CE, 0x0000 }, // ?AddWidgets@mmCarModel@@UAEXPAVBank@@@Z
    { 0x473100, 0x7C5F930A, 0x0000 }, // ?DeclareFields@mmCarModel@@SAXXZ
    { 0x473280, 0xB8AEB0AE, 0x0000 }, // ?GetClass@mmCarModel@@UAEPAVMetaClass@@XZ
    { 0x473320, 0x8DDFB3E4, 0x0000 }, // ?GetEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ
    { 0x473330, 0xB133B40B, 0x0000 }, // ?AttachEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ
    { 0x473340, 0x886FD07F, 0x0000 }, // ?GetVelocity@mmCarModel@@UAE?AVVector3@@XZ
    { 0x473370, 0x105452DA, 0x0000 }, // ?Reset@mmCarModel@@UAEXXZ
    { 0x473380, 0xC62FA0C8, 0x0000 }, // ??0mmCar@@QAE@XZ
    { 0x4734A0, 0x8993CCDD, 0x0000 }, // ?TranslateFlags@mmCar@@QAEXH@Z
    { 0x473500, 0x346DCA8B, 0x0000 }, // ?ReleaseTrailer@mmCar@@QAEXXZ
    { 0x473530, 0x227E45EA, 0x0000 }, // ?Init@mmCar@@QAEXPADHH@Z
    { 0x473960, 0xC8088577, 0x0000 }, // ?ReInit@mmCar@@QAEXPADH@Z
    { 0x473B90, 0xF484B3A3, 0x0000 }, // ?Reset@mmCar@@UAEXXZ
    { 0x473C40, 0x1FD223B0, 0x0000 }, // ?Update@mmCar@@UAEXXZ
    { 0x473C80, 0x95114596, 0x0000 }, // ?PostUpdate@mmCar@@UAEXXZ
    { 0x473D70, 0x65CA054B, 0x0000 }, // ?EnableDriving@mmCar@@QAEXH@Z
    { 0x473DE0, 0x93C27A44, 0x0000 }, // ?IsDrivingDisabled@mmCar@@QAEHXZ
    { 0x473DF0, 0xCA914373, 0x0000 }, // ?ToggleSiren@mmCar@@QAEXXZ
    { 0x473E20, 0xAADC4F24, 0x0000 }, // ?StartSiren@mmCar@@QAEXXZ
    { 0x473E40, 0x51CD35ED, 0x0000 }, // ?StopSiren@mmCar@@QAEXXZ
    { 0x473E60, 0x3AC92756, 0x0000 }, // ?RemoveVehicleAudio@mmCar@@QAEXXZ
    { 0x473E70, 0x23975227, 0x0000 }, // ?ClearDamage@mmCar@@QAEXXZ
    { 0x473EB0, 0x959575F1, 0x0000 }, // ?Impact@mmCar@@QAEXPAVmmIntersection@@PAVVector3@@MH1@Z
    { 0x4742E0, 0x39984E43, 0x0000 }, // ?EggNameIndex@@YAHPAD@Z
    { 0x474340, 0x196EC1E0, 0x0000 }, // ?VehNameRemap@mmCar@@QAEPADPADH@Z
    { 0x4745E0, 0x6146F90E, 0x0000 }, // ?AddWidgets@mmCar@@UAEXPAVBank@@@Z
    { 0x474640, 0xEF0847E5, 0x0000 }, // ?DeclareFields@mmCar@@SAXXZ
    { 0x4747C0, 0x42820C12, 0x0000 }, // ?GetClass@mmCar@@UAEPAVMetaClass@@XZ
    { 0x474860, 0x6AF21409, 0x0000 }, // ?GetICS@mmCar@@UAEPAVasInertialCS@@XZ
    { 0x474870, 0x33401A2F, 0x0000 }, // ?GetBound@mmCar@@UAEPAVasBound@@XZ
    { 0x474880, 0x9DB8E5CC, 0x0000 }, // ??0mmWheelCheap@@QAE@XZ
    { 0x474950, 0xA0229C01, 0x0000 }, // ?Init@mmWheelCheap@@QAEXPAVVector3@@PAVaiVehicleData@@PAVasInertialCS@@@Z
    { 0x474A20, 0x41E62BFB, 0x0000 }, // ?Update@mmWheelCheap@@UAEXXZ
    { 0x475180, 0xAD5C5795, 0x0000 }, // ?Reset@mmWheelCheap@@UAEXXZ
    { 0x4751D0, 0xE54E6C5F, 0x0000 }, // ??0NetAudioManager@@QAE@XZ
    { 0x4753B0, 0x602C16B6, 0x0000 }, // ??1NetAudioManager@@UAE@XZ
    { 0x475770, 0xBD520EBC, 0x0000 }, // ?AddVehicle@NetAudioManager@@QAEFPAVmmNetworkCarAudio@@@Z
    { 0x475800, 0x5EAB2554, 0x0000 }, // ?RemoveVehicle@NetAudioManager@@QAEXPAVmmNetworkCarAudio@@F@Z
    { 0x475860, 0x4E8D4AF4, 0x0000 }, // ?FindGreatestDistance@NetAudioManager@@QAEFPAVmmNetworkCarAudio@@@Z
    { 0x475900, 0xFBAC8696, 0x0000 }, // ?FindUnusedSlot@NetAudioManager@@QAEFXZ
    { 0x475940, 0x2D20C2E9, 0x0000 }, // ?Update@NetAudioManager@@UAEXXZ
    { 0x475B00, 0x8062DC6C, 0x0000 }, // ?EchoOn@NetAudioManager@@QAEXM@Z
    { 0x475E70, 0x6D5B334C, 0x0000 }, // ?EchoOff@NetAudioManager@@QAEXXZ
    { 0x476000, 0x182606F3, 0x0000 }, // ?AssignSounds@NetAudioManager@@QAEXPAVmmNetworkCarAudio@@F@Z
    { 0x476940, 0x93C31FFE, 0x0000 }, // ?AssignAddOnSounds@NetAudioManager@@AAEXPAVmmNetworkCarAudio@@F@Z
    { 0x476B60, 0x4A495E79, 0x0000 }, // ?GetAvailableDistance@NetAudioManager@@QAEMXZ
    { 0x476BA0, 0xFE40F53C, 0x0000 }, // ?AllocateEngine@NetAudioManager@@QAEXF@Z
    { 0x476D20, 0x6EB068C0, 0x0000 }, // ?AllocateAddOnEngine@NetAudioManager@@QAEFPAD@Z
    { 0x476EF0, 0xFC578468, 0x0000 }, // ?AllocateEngine@NetAudioManager@@QAEPAPAVAudSound@@PAD@Z
    { 0x477020, 0x402F9369, 0x0000 }, // ?AllocateReverseBeep@NetAudioManager@@QAEXXZ
    { 0x477170, 0x3749EEF1, 0x0000 }, // ?AllocateHorn@NetAudioManager@@QAEXF@Z
    { 0x477360, 0x7B33748F, 0x0000 }, // ?AllocateSkids@NetAudioManager@@QAEXXZ
    { 0x4775E0, 0xEDCEBC7B, 0x0000 }, // ?AllocateImpacts@NetAudioManager@@QAEXXZ
    { 0x477670, 0xD8BB83E3, 0x0000 }, // ?AllocatePoliceSiren@NetAudioManager@@QAEXXZ
    { 0x477810, 0x217E78F1, 0x0000 }, // ?SetSoundPtr@EngineAudioOpponent@@QAEXPAVAudSound@@@Z
    { 0x477850, 0x93B72060, 0x0000 }, // ??0mmSkid@@QAE@XZ
    { 0x477870, 0xFABA3F12, 0x0000 }, // ?Init@mmSkid@@QAEXPAD@Z
    { 0x477890, 0xC3F425B7, 0x0000 }, // ??1mmSkid@@UAE@XZ
    { 0x4778A0, 0x5DB84DC3, 0x0000 }, // ?AddSkid@mmSkid@@QAEXAAVMatrix34@@PAVVector3@@PAVagiPhysParameters@@M@Z
    { 0x477A60, 0x6AC5674C, 0x0000 }, // ?FromMatrix@mmSkid@@UAIXABVMatrix34@@@Z
    { 0x477A70, 0x0EF77DC7, 0x0000 }, // ?ToMatrix@mmSkid@@UAIAAVMatrix34@@AAV2@@Z
    { 0x477A80, 0x89337295, 0x0000 }, // ?GetPos@mmSkid@@UAIAAVVector3@@XZ
    { 0x477A90, 0x96469CF4, 0x0000 }, // ?Update@mmSkid@@QAEXXZ
    { 0x477AA0, 0xDCCFFD63, 0x0000 }, // ?Draw@mmSkid@@UAIXH@Z
    { 0x477B30, 0xAF771938, 0x0000 }, // ?DrawShadow@mmSkid@@UAIXXZ
    { 0x477B40, 0x2BAC4628, 0x0000 }, // ??0mmSkidManager@@QAE@XZ
    { 0x477B70, 0xF3DFB77D, 0x0000 }, // ??1mmSkidManager@@UAE@XZ
    { 0x477BD0, 0x31A1E04A, 0x0000 }, // ?Init@mmSkidManager@@QAEXPADHPAVmmWheel@@@Z
    { 0x477C90, 0x6D86B316, 0x0000 }, // ?ReInit@mmSkidManager@@QAEXPAVmmWheel@@@Z
    { 0x477CC0, 0x8CB56FFB, 0x0000 }, // ?Reset@mmSkidManager@@UAEXXZ
    { 0x477D10, 0x855B234E, 0x0000 }, // ?LayTrack@mmSkidManager@@QAEXXZ
    { 0x4780A0, 0x9FBF9378, 0x0000 }, // ?Update@mmSkidManager@@UAEXXZ
    { 0x478180, 0xE4A12FFC, 0x0000 }, // ?DeclareFields@mmSkid@@SAXXZ
    { 0x478300, 0x73C71C9B, 0x0000 }, // ?GetClass@mmSkid@@UAEPAVMetaClass@@XZ
    { 0x478310, 0xFA71E532, 0x0000 }, // ?DeclareFields@mmSkidManager@@SAXXZ
    { 0x478470, 0x96F60530, 0x0000 }, // ?GetClass@mmSkidManager@@UAEPAVMetaClass@@XZ
    { 0x478540, 0xB072BB76, 0x0000 }, // ??0Matrix34@@QAE@XZ
    { 0x478550, 0x18EEBC90, 0x0000 }, // ?AddWidgets@mmSkid@@UAEXPAVBank@@@Z
    { 0x478560, 0x37261412, 0x0000 }, // ??0mmShard@@QAE@XZ
    { 0x4785A0, 0xE0FB5BB8, 0x0000 }, // ?Init@mmShard@@QAEXPADH@Z
    { 0x4785D0, 0x4D57708E, 0x0000 }, // ??1mmShard@@UAE@XZ
    { 0x4785E0, 0xA67CECC9, 0x0000 }, // ?AddShard@mmShard@@QAEXVVector3@@00M@Z
    { 0x478640, 0x3A27E948, 0x0000 }, // ?Update@mmShard@@QAEXXZ
    { 0x478730, 0xCC7BCBE5, 0x0000 }, // ?Draw@mmShard@@UAIXH@Z
    { 0x4787F0, 0x18155B8D, 0x0000 }, // ??0mmShardManager@@QAE@XZ
    { 0x478860, 0xF8E661A2, 0x0000 }, // ??1mmShardManager@@UAE@XZ
    { 0x4788D0, 0x5140AB69, 0x0000 }, // ?GetInstance@mmShardManager@@SAPAV1@H@Z
    { 0x4788F0, 0x22CD7AE7, 0x0000 }, // ?Init@mmShardManager@@QAEXPADHPAVmmCarSim@@@Z
    { 0x4789E0, 0x660F2752, 0x0000 }, // ?ReInit@mmShardManager@@QAEXPAVmmCarSim@@@Z
    { 0x4789F0, 0xED4945B4, 0x0000 }, // ?EmitShards@mmShardManager@@QAEXVVector3@@MM@Z
    { 0x478A60, 0x847FF96C, 0x0000 }, // ?EmitAllShards@mmShardManager@@QAEXVVector3@@M@Z
    { 0x478AB0, 0xE2390011, 0x0000 }, // ?EmitShard@mmShardManager@@QAEXVVector3@@M@Z
    { 0x478C60, 0x8EFA2820, 0x0000 }, // ?Update@mmShardManager@@UAEXXZ
    { 0x478C90, 0xFFA96D09, 0x0000 }, // ?AddWidgets@mmShardManager@@UAEXPAVBank@@@Z
    { 0x478E00, 0xFF1879AC, 0x0000 }, // ?DeclareFields@mmShard@@SAXXZ
    { 0x478F80, 0xA40F830D, 0x0000 }, // ?GetClass@mmShard@@UAEPAVMetaClass@@XZ
    { 0x478F90, 0x61FB6461, 0x0000 }, // ?DeclareFields@mmShardManager@@SAXXZ
    { 0x479160, 0xDF3F9B21, 0x0000 }, // ?GetClass@mmShardManager@@UAEPAVMetaClass@@XZ
    { 0x479230, 0x43CA90C7, 0x0000 }, // ??0mmTrailer@@QAE@XZ
    { 0x479480, 0x142F9B43, 0x0000 }, // ?Init@mmTrailer@@QAEXPADPAVmmCarSim@@VVector3@@@Z
    { 0x4796D0, 0x70497DB2, 0x0000 }, // ?FromMatrix@mmTrailerInstance@@UAIXABVMatrix34@@@Z
    { 0x4796F0, 0x88C21C21, 0x0000 }, // ?ToMatrix@mmTrailerInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x479710, 0x42462719, 0x0000 }, // ?GetPos@mmTrailerInstance@@UAIAAVVector3@@XZ
    { 0x479720, 0x63E59874, 0x0000 }, // ?GetEntity@mmTrailerInstance@@UAEPAVmmPhysEntity@@XZ
    { 0x479730, 0x0696F1BB, 0x0000 }, // ?AttachEntity@mmTrailerInstance@@UAEPAVmmPhysEntity@@XZ
    { 0x479740, 0x61B3FE86, 0x0000 }, // ?GetVelocity@mmTrailerInstance@@UAE?AVVector3@@XZ
    { 0x479770, 0x77C36501, 0x0000 }, // ?Init@mmTrailerInstance@@QAEXPADPAVVector3@@@Z
    { 0x479910, 0xF4930918, 0x0000 }, // ?Draw@mmTrailerInstance@@UAIXH@Z
    { 0x479B20, 0x825AC4C6, 0x0000 }, // ?DrawShadow@mmTrailerInstance@@UAIXXZ
    { 0x479B40, 0xD41E8800, 0x0000 }, // ?AfterLoad@mmTrailer@@UAEXXZ
    { 0x479BB0, 0x77C3207C, 0x0000 }, // ?Activate@mmTrailer@@QAEXXZ
    { 0x479BC0, 0xBEE0281F, 0x0000 }, // ?Deactivate@mmTrailer@@QAEXXZ
    { 0x479BD0, 0xD2E87FB1, 0x0000 }, // ?BeforeSave@mmTrailer@@UAEXXZ
    { 0x479C00, 0x4FCFFD11, 0x0000 }, // ?UpdateICSParams@mmTrailer@@QAEXXZ
    { 0x479C30, 0x6A5BCDB7, 0x0000 }, // ?RestoreImpactParams@mmTrailer@@QAEXXZ
    { 0x479C60, 0xBE03252A, 0x0000 }, // ?SetHackedImpactParams@mmTrailer@@QAEXXZ
    { 0x479C80, 0x175C03FA, 0x0000 }, // ?Reset@mmTrailer@@UAEXXZ
    { 0x479D60, 0xE6000E5D, 0x0000 }, // ?Update@mmTrailer@@UAEXXZ
    { 0x479E30, 0xDD07B2F0, 0x0000 }, // ?PostUpdate@mmTrailer@@UAEXXZ
    { 0x479E40, 0x2B48AF22, 0x0000 }, // ?AddWidgets@mmTrailer@@UAEXPAVBank@@@Z
    { 0x479F30, 0x5C1968C2, 0x0000 }, // ?DeclareFields@mmTrailer@@SAXXZ
    { 0x47A130, 0x5D51254A, 0x0000 }, // ?GetClass@mmTrailer@@UAEPAVMetaClass@@XZ
    { 0x47A140, 0x8F28395D, 0x0000 }, // ??1mmTrailerInstance@@UAE@XZ
    { 0x47A1D0, 0xFB93ACB2, 0x0000 }, // ??1mmTrailer@@UAE@XZ
    { 0x47A300, 0x4579F733, 0x0000 }, // ?AddWidgets@mmTrailerInstance@@UAEXPAVBank@@@Z
    { 0x47A310, 0x74D9E62A, 0x0000 }, // ?GetICS@mmTrailer@@UAEPAVasInertialCS@@XZ
    { 0x47A320, 0xF87BD549, 0x0000 }, // ?GetBound@mmTrailer@@UAEPAVasBound@@XZ
    { 0x47A3B0, 0xD07CC304, 0x0000 }, // ??0mmOpponentImpactAudio@@QAE@XZ
    { 0x47A570, 0xB8053C57, 0x0000 }, // ??1mmOpponentImpactAudio@@QAE@XZ
    { 0x47A5A0, 0x6A652C22, 0x0000 }, // ?Play@mmOpponentImpactAudio@@QAEXMFMM@Z
    { 0x47A710, 0xDF0265EE, 0x0000 }, // ?Update@mmOpponentImpactAudio@@QAEXXZ
    { 0x47A770, 0x9A0FB6D6, 0x0000 }, // ?Enable3DMode@mmOpponentImpactAudio@@QAEXPAVVector3@@@Z
    { 0x47A7C0, 0x2B9EB454, 0x0000 }, // ?SetSecondsElapsed@mmOpponentImpactAudio@@SAXM@Z
    { 0x47A7D0, 0xBFA5F21A, 0x0000 }, // ?GetSecondsElapsed@mmOpponentImpactAudio@@SAMXZ
    { 0x47A7E0, 0xC05A65BF, 0x0000 }, // ?Disable3DMode@mmOpponentImpactAudio@@QAEXXZ
    { 0x47A800, 0x790CB750, 0x0000 }, // ??0mmPoliceCarAudio@@QAE@PAVmmCarSim@@M@Z
    { 0x47A8E0, 0xD5E77841, 0x0000 }, // ??1mmPoliceCarAudio@@UAE@XZ
    { 0x47A8F0, 0xF57DC11B, 0x0000 }, // ?ExplosionIsPlaying@mmPoliceCarAudio@@QAEHXZ
    { 0x47A910, 0x7A9960AB, 0x0000 }, // ?StartSiren@mmPoliceCarAudio@@QAEXXZ
    { 0x47A9C0, 0x15B38504, 0x0000 }, // ?StopSiren@mmPoliceCarAudio@@QAEXXZ
    { 0x47AA20, 0x6D06D214, 0x0000 }, // ?PlayExplosion@mmPoliceCarAudio@@QAEXXZ
    { 0x47AAD0, 0x5388D46B, 0x0000 }, // ?DamageSiren@mmPoliceCarAudio@@QAEXXZ
    { 0x47AC30, 0xDCAEDE01, 0x0000 }, // ?Update@mmPoliceCarAudio@@QAEXHMM@Z
    { 0x47AD50, 0x5D959191, 0x0000 }, // ?FluctuateSlowSiren@mmPoliceCarAudio@@AAEXXZ
    { 0x47AFE0, 0xDFF5234A, 0x0000 }, // ?FluctuateFastSiren@mmPoliceCarAudio@@AAEXXZ
    { 0x47B400, 0x8A1A73E0, 0x0000 }, // ?UpdateDoppler@mmPoliceCarAudio@@QAEXXZ
    { 0x47B410, 0xA0CE1941, 0x0000 }, // ?UpdateDoppler@mmPoliceCarAudio@@QAEXM@Z
    { 0x47B600, 0x2103E349, 0x0000 }, // ?PlayVoice@mmPoliceCarAudio@@QAEXXZ
    { 0x47B6A0, 0x28ED17C9, 0x0000 }, // ?AssignSounds@mmPoliceCarAudio@@QAEXPAVAudSound@@000PAVmmOpponentImpactAudio@@0@Z
    { 0x47B770, 0xE2FD27B6, 0x0000 }, // ?UnAssignSounds@mmPoliceCarAudio@@QAEXXZ
    { 0x47B950, 0x1230855F, 0x0000 }, // ??0mmOpponentCarAudio@@QAE@PAVmmCarSim@@@Z
    { 0x47B9C0, 0xA86E65D9, 0x0000 }, // ??1mmOpponentCarAudio@@UAE@XZ
    { 0x47BA30, 0xF452BC35, 0x0000 }, // ?Init@mmOpponentCarAudio@@QAEXPAVmmCarSim@@@Z
    { 0x47BB80, 0x535CCF01, 0x0000 }, // ?PlayReverseBeep@mmOpponentCarAudio@@QAEXXZ
    { 0x47BBE0, 0x9ADDC7FE, 0x0000 }, // ?Update@mmOpponentCarAudio@@QAEXHMM@Z
    { 0x47BC80, 0x89AD1480, 0x0000 }, // ?CalculateDistToPlayer2@mmOpponentCarAudio@@QAEXXZ
    { 0x47BD60, 0xC98EAF1D, 0x0000 }, // ?CalculatePan@mmOpponentCarAudio@@QAEXXZ
    { 0x47BDB0, 0x56217B12, 0x0000 }, // ?CalculateDoppler@mmOpponentCarAudio@@QAEXM@Z
    { 0x47BDE0, 0x4200A4BB, 0x0000 }, // ?UpdateDoppler@mmOpponentCarAudio@@QAEXXZ
    { 0x47BDF0, 0x8952D729, 0x0000 }, // ?UpdateDoppler@mmOpponentCarAudio@@QAEXM@Z
    { 0x47BF00, 0xF281138F, 0x0000 }, // ?Reset@mmOpponentCarAudio@@UAEXXZ
    { 0x47BF20, 0xFA330204, 0x0000 }, // ?LoadSucessful@mmOpponentCarAudio@@QAEXPAVmmCarSim@@@Z
    { 0x47BF50, 0x09BD347D, 0x0000 }, // ?AssignSounds@mmOpponentCarAudio@@QAEXPAVAudSound@@0PAVmmOpponentImpactAudio@@0@Z
    { 0x47C020, 0x2E5B04A9, 0x0000 }, // ?UnAssignSounds@mmOpponentCarAudio@@QAEXXZ
    { 0x47C0C0, 0xF3284464, 0x0000 }, // ?SetMinAmpSpeed@mmOpponentCarAudio@@QAEXM@Z
    { 0x47C0E0, 0x3308CF79, 0x0000 }, // ?DeclareFields@mmOpponentCarAudio@@SAXXZ
    { 0x47C2A0, 0x4A2D9812, 0x0000 }, // ?GetClass@mmOpponentCarAudio@@UAEPAVMetaClass@@XZ
    { 0x47C430, 0x8A232EC7, 0x0000 }, // ??0mmOpponentCarAudio@@QAE@XZ
    { 0x47C480, 0x46583FF7, 0x0000 }, // ??0mmStuck@@QAE@XZ
    { 0x47C4F0, 0x7AD0FB5F, 0x0000 }, // ?StuckCB@@YAXPAVmmStuck@@@Z
    { 0x47C520, 0x7F5907AC, 0x0000 }, // ?Init@mmStuck@@QAEXPAVmmCarSim@@@Z
    { 0x47C540, 0x1A31DDB7, 0x0000 }, // ?Impact@mmStuck@@QAEXXZ
    { 0x47C550, 0x6CF2F53C, 0x0000 }, // ?Reset@mmStuck@@UAEXXZ
    { 0x47C560, 0x9B788AE3, 0x0000 }, // ?Pegged@mmStuck@@QAEHXZ
    { 0x47C5B0, 0x673964A5, 0x0000 }, // ?Update@mmStuck@@UAEXXZ
    { 0x47C7D0, 0x9C9E391A, 0x0000 }, // ?AddWidgets@mmStuck@@UAEXPAVBank@@@Z
    { 0x47C930, 0x675CBF4D, 0x0000 }, // ??0mmEngine@@QAE@XZ
    { 0x47C990, 0xDCE0B417, 0x0000 }, // ??1mmEngine@@UAE@XZ
    { 0x47C9A0, 0xDDEE561A, 0x0000 }, // ?Init@mmEngine@@QAEXPAVmmCarSim@@@Z
    { 0x47C9D0, 0xBA286CD3, 0x0000 }, // ?AfterLoad@mmEngine@@UAEXXZ
    { 0x47C9E0, 0xFAF72388, 0x0000 }, // ?Load@mmEngine@@QAEXPAVStream@@@Z
    { 0x47CA60, 0xF97CE533, 0x0000 }, // ?ComputeConstants@mmEngine@@QAEXXZ
    { 0x47CAE0, 0xFEFF362F, 0x0000 }, // ?CalcTorqueAtFullThrottle@mmEngine@@QAEMXZ
    { 0x47CB70, 0x2E8F50C4, 0x0000 }, // ?CalcTorqueAtZeroThrottle@mmEngine@@QAEMXZ
    { 0x47CBB0, 0xB1A85B50, 0x0000 }, // ?CalcTorque@mmEngine@@QAEMM@Z
    { 0x47CBE0, 0x46D2C0D9, 0x0000 }, // ?Save@mmEngine@@QAEXPAVStream@@@Z
    { 0x47CC60, 0x8D11BC69, 0x0000 }, // ?Reset@mmEngine@@UAEXXZ
    { 0x47CC90, 0x83AFB759, 0x0000 }, // ?Update@mmEngine@@UAEXXZ
    { 0x47CE70, 0xA4553414, 0x0000 }, // ?AddWidgets@mmEngine@@UAEXPAVBank@@@Z
    { 0x47CFC0, 0x8542D36C, 0x0000 }, // ?DeclareFields@mmEngine@@SAXXZ
    { 0x47D180, 0x39483CE2, 0x0000 }, // ?GetClass@mmEngine@@UAEPAVMetaClass@@XZ
    { 0x47D1F0, 0xC069D512, 0x0000 }, // ??0mmShock@@QAE@XZ
    { 0x47D210, 0x33BB789E, 0x0000 }, // ?Init@mmShock@@QAEXPAD0PAVmmWheel@@@Z
    { 0x47D270, 0xCCE60638, 0x0000 }, // ?Update@mmShock@@UAEXXZ
    { 0x47D280, 0xEA7538CC, 0x0000 }, // ?AddWidgets@mmShock@@UAEXPAVBank@@@Z
    { 0x47D2A0, 0xFB8304E2, 0x0000 }, // ?DeclareFields@mmShock@@SAXXZ
    { 0x47D410, 0x8BC5AA81, 0x0000 }, // ?GetClass@mmShock@@UAEPAVMetaClass@@XZ
    { 0x47D480, 0x007D7B09, 0x0000 }, // ??0mmAxle@@QAE@XZ
    { 0x47D4A0, 0xF331BF03, 0x0000 }, // ?Init@mmAxle@@QAEXPAD0PAVmmWheel@@1@Z
    { 0x47D4F0, 0xAF948DEA, 0x0000 }, // ?Update@mmAxle@@UAEXXZ
    { 0x47D590, 0xDB328FBA, 0x0000 }, // ?AddWidgets@mmAxle@@UAEXPAVBank@@@Z
    { 0x47D5B0, 0xFCF5DC53, 0x0000 }, // ?DeclareFields@mmAxle@@SAXXZ
    { 0x47D720, 0x7E977A7D, 0x0000 }, // ?GetClass@mmAxle@@UAEPAVMetaClass@@XZ
    { 0x47D790, 0xF753D5F6, 0x0000 }, // ??0mmWheel@@QAE@XZ
    { 0x47D950, 0xC8C6D3A2, 0x0000 }, // ?ComputeConstants@mmWheel@@QAEXXZ
    { 0x47DA10, 0xEFC6C6B2, 0x0000 }, // ?AfterLoad@mmWheel@@UAEXXZ
    { 0x47DA20, 0x762DC490, 0x0000 }, // ?Init@mmWheel@@QAEXPAD0VVector3@@PAVasInertialCS@@HPAVmmBoundTemplate@@H@Z
    { 0x47DBB0, 0x5CF526F1, 0x0000 }, // ?ComputeDwtdw@mmWheel@@QAEMMPAM00@Z
    { 0x47E3E0, 0x22FCB62A, 0x0000 }, // ?Update@mmWheel@@UAEXXZ
    { 0x47F2D0, 0xD4582638, 0x0000 }, // ?Reset@mmWheel@@UAEXXZ
    { 0x47F340, 0x489F9166, 0x0000 }, // ?GenerateSkidParticles@mmWheel@@QAEXXZ
    { 0x47F360, 0xA9B7E08E, 0x0000 }, // ?SetInputs@mmWheel@@QAEXMM@Z
    { 0x47F380, 0xE5FAA6C7, 0x0000 }, // ?SetFricMultiplier@mmWheel@@QAEXM@Z
    { 0x47F3A0, 0xF3B80C89, 0x0000 }, // ?SetSteerMultiplier@mmWheel@@QAEXM@Z
    { 0x47F3B0, 0xA27E104C, 0x0000 }, // ?Load@mmWheel@@QAEXPAVStream@@@Z
    { 0x47F4B0, 0x38FF3E9D, 0x0000 }, // ?Save@mmWheel@@QAEXPAVStream@@@Z
    { 0x47F5F0, 0xC54F3F0F, 0x0000 }, // ?CopyVars@mmWheel@@QAEXPAV1@@Z
    { 0x47F6B0, 0x65609EEE, 0x0000 }, // ?GetSurfaceSound@mmWheel@@QAEHXZ
    { 0x47F6D0, 0x1AC8B182, 0x0000 }, // ?AddWidgets@mmWheel@@UAEXPAVBank@@@Z
    { 0x47FB00, 0xE8AC13CE, 0x0000 }, // ?DeclareFields@mmWheel@@SAXXZ
    { 0x47FDC0, 0xF5D11EBE, 0x0000 }, // ?GetClass@mmWheel@@UAEPAVMetaClass@@XZ
    { 0x47FE60, 0x25BBD0C7, 0x0000 }, // ??0mmDrivetrain@@QAE@XZ
    { 0x47FE90, 0x101E40AC, 0x0000 }, // ?Init@mmDrivetrain@@QAEXPAVmmCarSim@@@Z
    { 0x47FEC0, 0xA00CCA9E, 0x0000 }, // ?Attach@mmDrivetrain@@QAEXXZ
    { 0x47FEE0, 0x581E4BFC, 0x0000 }, // ?Detach@mmDrivetrain@@QAEXXZ
    { 0x47FEF0, 0x0E246420, 0x0000 }, // ?AddWheel@mmDrivetrain@@QAEHPAVmmWheel@@@Z
    { 0x47FF30, 0xBE189132, 0x0000 }, // ?Update@mmDrivetrain@@UAEXXZ
    { 0x4803E0, 0x6813E1DD, 0x0000 }, // ?AddWidgets@mmDrivetrain@@UAEXPAVBank@@@Z
    { 0x480460, 0xBDFB6696, 0x0000 }, // ?DeclareFields@mmDrivetrain@@SAXXZ
    { 0x4805E0, 0xBEDF53B4, 0x0000 }, // ?GetClass@mmDrivetrain@@UAEPAVMetaClass@@XZ
    { 0x480650, 0x7DD0ABE8, 0x0000 }, // ?Reset@mmDrivetrain@@UAEXXZ
    { 0x480660, 0xC1F5C384, 0x0000 }, // ??0VehGyro@@QAE@XZ
    { 0x480690, 0xB2D488E5, 0x0000 }, // ?Load@VehGyro@@QAEXPAVStream@@@Z
    { 0x480700, 0x75BA829D, 0x0000 }, // ?Save@VehGyro@@QAEXPAVStream@@@Z
    { 0x480780, 0xCACFC3BE, 0x0000 }, // ?Update@VehGyro@@UAEXXZ
    { 0x480930, 0x297E7FD3, 0x0000 }, // ?AddWidgets@VehGyro@@UAEXPAVBank@@@Z
    { 0x4809E0, 0x476ECC0B, 0x0000 }, // ?DeclareFields@VehGyro@@SAXXZ
    { 0x480B70, 0xE7FF27CC, 0x0000 }, // ?GetClass@VehGyro@@UAEPAVMetaClass@@XZ
    { 0x480BE0, 0xB69ADAC5, 0x0000 }, // ??0mmForce@@QAE@XZ
    { 0x480C00, 0xF5490CDF, 0x0000 }, // ?Update@mmForce@@UAEXXZ
    { 0x480E10, 0x38FF6029, 0x0000 }, // ?AddWidgets@mmForce@@UAEXPAVBank@@@Z
    { 0x480E20, 0xD54B85F3, 0x0000 }, // ?DeclareFields@mmForce@@SAXXZ
    { 0x480F80, 0x09D98161, 0x0000 }, // ?GetClass@mmForce@@UAEPAVMetaClass@@XZ
    { 0x480FF0, 0x2B946DCA, 0x0000 }, // ??0mmSplash@@QAE@XZ
    { 0x481050, 0x0BA4E3E3, 0x0000 }, // ?SplashCB@@YAXPAVmmSplash@@@Z
    { 0x481060, 0xAEA0CD13, 0x0000 }, // ?Reset@mmSplash@@UAEXXZ
    { 0x481070, 0x61761B38, 0x0000 }, // ?Init@mmSplash@@QAEXPAVasInertialCS@@VVector3@@1@Z
    { 0x4811C0, 0xBFECF9E5, 0x0000 }, // ?Activate@mmSplash@@QAEXM@Z
    { 0x4811E0, 0x041069BD, 0x0000 }, // ?Update@mmSplash@@UAEXXZ
    { 0x481420, 0xBC1A0BC1, 0x0000 }, // ?AddWidgets@mmSplash@@UAEXPAVBank@@@Z
    { 0x4814D0, 0x7D4BFBB9, 0x0000 }, // ??0mmCarRoadFF@@QAE@XZ
    { 0x481510, 0xFA9FF260, 0x0000 }, // ??1mmCarRoadFF@@UAE@XZ
    { 0x481570, 0x4B126B29, 0x0000 }, // ?AssignProperties@mmCarRoadFF@@QAEXMH@Z
    { 0x481610, 0x708F8D5D, 0x0000 }, // ?SetFGVals@mmCarRoadFF@@QAEXMMM@Z
    { 0x481700, 0x21BA260F, 0x0000 }, // ?Start@mmCarRoadFF@@QAEXXZ
    { 0x481720, 0xC9A0FF31, 0x0000 }, // ?Stop@mmCarRoadFF@@QAEXXZ
    { 0x481730, 0xA495AE35, 0x0000 }, // ?Reset@mmCarRoadFF@@UAEXXZ
    { 0x481760, 0x845C3B4B, 0x0000 }, // ?IsPlaying@mmCarRoadFF@@QAEHXZ
    { 0x481770, 0x254206CF, 0x0000 }, // ?Update@mmCarRoadFF@@UAEXXZ
    { 0x4817C0, 0xFD3FCC8D, 0x0000 }, // ?UpdateVals@mmCarRoadFF@@QAEXXZ
    { 0x481810, 0x057C6636, 0x0000 }, // ?AddWidgets@mmCarRoadFF@@UAEXPAVBank@@@Z
    { 0x481920, 0x9D5413A5, 0x0000 }, // ?DeclareFields@mmCarRoadFF@@SAXXZ
    { 0x481A90, 0xA9DF0E2D, 0x0000 }, // ?GetClass@mmCarRoadFF@@UAEPAVMetaClass@@XZ
    { 0x481B00, 0xB5BD65BC, 0x0000 }, // ??0mmPlayerCarAudio@@QAE@PAVmmCarSim@@@Z
    { 0x481BA0, 0xEC308AF0, 0x0000 }, // ?Init@mmPlayerCarAudio@@QAEXPAVmmCarSim@@@Z
    { 0x481F30, 0xD13D823D, 0x0000 }, // ??1mmPlayerCarAudio@@UAE@XZ
    { 0x482020, 0x38994C41, 0x0000 }, // ?EchoOn@mmPlayerCarAudio@@QAEXM@Z
    { 0x482140, 0x100BBBE6, 0x0000 }, // ?EchoOff@mmPlayerCarAudio@@QAEXXZ
    { 0x4821F0, 0xE1442980, 0x0000 }, // ?PlayReverseBeep@mmPlayerCarAudio@@QAEXXZ
    { 0x482250, 0xE4B15535, 0x0000 }, // ?Update@mmPlayerCarAudio@@QAEXHMMF@Z
    { 0x482460, 0x6D06C498, 0x0000 }, // ?StartSiren@mmPlayerCarAudio@@QAEXXZ
    { 0x4824F0, 0x70A18766, 0x0000 }, // ?StopSiren@mmPlayerCarAudio@@QAEXXZ
    { 0x482530, 0x5F0EA0BE, 0x0000 }, // ?FluctuateSlowSiren@mmPlayerCarAudio@@QAEXXZ
    { 0x482730, 0x1A259C29, 0x0000 }, // ?FluctuateFastSiren@mmPlayerCarAudio@@QAEXXZ
    { 0x482A50, 0x55EF4289, 0x0000 }, // ?Reset@mmPlayerCarAudio@@UAEXXZ
    { 0x482A90, 0xE0196BF2, 0x0000 }, // ?PlayHorn@mmPlayerCarAudio@@QAEXXZ
    { 0x482AD0, 0x4C382935, 0x0000 }, // ?SetUpDefault@mmPlayerCarAudio@@QAEXPAVmmCarSim@@@Z
    { 0x482C20, 0xE528F543, 0x0000 }, // ?LoadSucessful@mmPlayerCarAudio@@QAEXXZ
    { 0x483080, 0xD24A59EE, 0x0000 }, // ?DeclareFields@mmPlayerCarAudio@@SAXXZ
    { 0x483260, 0x23FC1BC2, 0x0000 }, // ?GetClass@mmPlayerCarAudio@@UAEPAVMetaClass@@XZ
    { 0x4833F0, 0x62BDD586, 0x0000 }, // ??0mmPlayerCarAudio@@QAE@XZ
    { 0x483440, 0xA0408600, 0x0000 }, // ??0mmNetworkCarAudio@@QAE@PAVmmCarSim@@@Z
    { 0x4834A0, 0x77FF40E9, 0x0000 }, // ?Init@mmNetworkCarAudio@@QAEXPAVmmCarSim@@G@Z
    { 0x483630, 0xA59CF0DC, 0x0000 }, // ??1mmNetworkCarAudio@@UAE@XZ
    { 0x4836A0, 0xA60FCE47, 0x0000 }, // ?Update@mmNetworkCarAudio@@UAEXXZ
    { 0x4836E0, 0xF15F8B79, 0x0000 }, // ?UpdateAudio@mmNetworkCarAudio@@QAEXXZ
    { 0x483810, 0x73286FA4, 0x0000 }, // ?FluctuateSlowSiren@mmNetworkCarAudio@@QAEXXZ
    { 0x483A60, 0xBCEA01CB, 0x0000 }, // ?FluctuateFastSiren@mmNetworkCarAudio@@QAEXXZ
    { 0x483E10, 0xB9720852, 0x0000 }, // ?DeactivateAudio@mmNetworkCarAudio@@QAEXXZ
    { 0x483EC0, 0x194217E7, 0x0000 }, // ?CalculateDistToPlayer2@mmNetworkCarAudio@@QAEXXZ
    { 0x483F80, 0x08967F3B, 0x0000 }, // ?CalculateDoppler@mmNetworkCarAudio@@QAEXXZ
    { 0x483FA0, 0xAF4A93FF, 0x0000 }, // ?UpdateDoppler@mmNetworkCarAudio@@QAEXXZ
    { 0x484250, 0xFD32DA40, 0x0000 }, // ?StopSiren@mmNetworkCarAudio@@QAEXXZ
    { 0x484290, 0xCE4B3CF8, 0x0000 }, // ?StartSiren@mmNetworkCarAudio@@QAEXXZ
    { 0x4842E0, 0xA0A84C48, 0x0000 }, // ?Reset@mmNetworkCarAudio@@UAEXXZ
    { 0x484300, 0x7605E962, 0x0000 }, // ?RemoveFromManager@mmNetworkCarAudio@@QAEXXZ
    { 0x484320, 0x824AF071, 0x0000 }, // ?LoadSucessful@mmNetworkCarAudio@@QAEXPAVmmCarSim@@@Z
    { 0x4843A0, 0x0FEB77D3, 0x0000 }, // ?DeclareFields@mmNetworkCarAudio@@SAXXZ
    { 0x484570, 0xB79DE0CB, 0x0000 }, // ?GetClass@mmNetworkCarAudio@@UAEPAVMetaClass@@XZ
    { 0x484700, 0x688F2735, 0x0000 }, // ??0mmNetworkCarAudio@@QAE@XZ
    { 0x484750, 0x97191428, 0x0000 }, // ??0mmImpactAudio@@QAE@PAVmmCarSim@@PAVVector3@@@Z
    { 0x484D80, 0x75E14A14, 0x0000 }, // ??1mmImpactAudio@@QAE@XZ
    { 0x484E60, 0x8C37331A, 0x0000 }, // ?EchoOn@mmImpactAudio@@QAEXPAVmmCarSim@@@Z
    { 0x484E70, 0x4D42BA19, 0x0000 }, // ?EchoOff@mmImpactAudio@@QAEXPAVmmCarSim@@@Z
    { 0x484E80, 0xE8CA972F, 0x0000 }, // ?Play@mmImpactAudio@@QAEXMFMM@Z
    { 0x484F10, 0x370FA9BB, 0x0000 }, // ?PlayWall@mmImpactAudio@@QAEXMMM@Z
    { 0x485010, 0xDDCB3AEE, 0x0000 }, // ?PlayCar@mmImpactAudio@@QAEXM@Z
    { 0x485020, 0x3183A841, 0x0000 }, // ?GetBangerPtrs@mmImpactAudio@@QAEXFPAPAVAudSound@@0@Z
    { 0x4852A0, 0x0F6E8EB7, 0x0000 }, // ?PlayBanger@mmImpactAudio@@QAEXMF@Z
    { 0x4853E0, 0x7D1B4221, 0x0000 }, // ?SetWallSoftVolumeRange@mmImpactAudio@@QAEXMM@Z
    { 0x485400, 0x41355981, 0x0000 }, // ?SetWallSoftVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    { 0x485420, 0x878343E3, 0x0000 }, // ?SetWallMedVolumeRange@mmImpactAudio@@QAEXMM@Z
    { 0x485440, 0x9AF06A62, 0x0000 }, // ?SetWallMedVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    { 0x485460, 0x0DF31798, 0x0000 }, // ?SetWallHugeVolumeRange@mmImpactAudio@@QAEXMM@Z
    { 0x485480, 0x90B7E562, 0x0000 }, // ?SetWallHugeVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    { 0x4854A0, 0x6A802254, 0x0000 }, // ?SetBangerVolumeRange@mmImpactAudio@@QAEXMMMF@Z
    { 0x485530, 0x777C3644, 0x0000 }, // ?Update@mmImpactAudio@@QAEXXZ
    { 0x485540, 0x7B2F4F2E, 0x0000 }, // ??0NetAddOnCarAudio@@QAE@PADF@Z
    { 0x485660, 0x6510C0F2, 0x0000 }, // ??1NetAddOnCarAudio@@QAE@XZ
    { 0x4856B0, 0x218747F0, 0x0000 }, // ?AssignSounds@NetAddOnCarAudio@@QAEHPAVmmNetworkCarAudio@@F@Z
    { 0x485740, 0x2D509A37, 0x0000 }, // ?EchoOn@NetAddOnCarAudio@@QAEXM@Z
    { 0x4857A0, 0xE3ECBA28, 0x0000 }, // ?EchoOff@NetAddOnCarAudio@@QAEXXZ
    { 0x4857D0, 0xBBEF4FB7, 0x0000 }, // ?Update@NetAddOnCarAudio@@QAEXXZ
    { 0x485800, 0x953C49DD, 0x0000 }, // ??0EngineAudioOpponent@@QAE@XZ
    { 0x485860, 0x6C36FB0C, 0x0000 }, // ??1EngineAudioOpponent@@UAE@XZ
    { 0x485890, 0x71F158C3, 0x0000 }, // ?Init@EngineAudioOpponent@@QAEXXZ
    { 0x485900, 0x95606625, 0x0000 }, // ?Init@EngineAudioOpponent@@QAEXF@Z
    { 0x485940, 0xBF420BB0, 0x0000 }, // ?UpdateRPM@EngineAudioOpponent@@QAEXM@Z
    { 0x485A10, 0xCFB0AA50, 0x0000 }, // ?ClearName@EngineAudioOpponent@@QAEXXZ
    { 0x485A30, 0x473194C2, 0x0000 }, // ?Enable3DMode@EngineAudioOpponent@@QAEXPAVVector3@@@Z
    { 0x485A50, 0x85A29901, 0x0000 }, // ?Disable3DMode@EngineAudioOpponent@@QAEXXZ
    { 0x485A60, 0xF3504237, 0x0000 }, // ?DeclareFields@EngineAudioOpponent@@SAXXZ
    { 0x485C70, 0x4DECCF7B, 0x0000 }, // ?GetClass@EngineAudioOpponent@@UAEPAVMetaClass@@XZ
    { 0x485E00, 0x7C6F1D28, 0x0000 }, // ??0mmOpponentSurfaceAudio@@QAE@XZ
    { 0x485E30, 0x3778D438, 0x0000 }, // ??1mmOpponentSurfaceAudio@@QAE@XZ
    { 0x485E40, 0x037CD326, 0x0000 }, // ?SetWheelPointers@mmOpponentSurfaceAudio@@QAEXPAVmmWheel@@000@Z
    { 0x485E60, 0x0180AD97, 0x0000 }, // ?Update@mmOpponentSurfaceAudio@@QAEXM@Z
    { 0x485EA0, 0xB9AC9835, 0x0000 }, // ?UpdateSkid@mmOpponentSurfaceAudio@@QAEXM@Z
    { 0x486120, 0xE3346E06, 0x0000 }, // ?UpdateSkidSnow@mmOpponentSurfaceAudio@@QAEXM@Z
    { 0x486380, 0xC50275E8, 0x0000 }, // ?Enable3DMode@mmOpponentSurfaceAudio@@QAEXPAVVector3@@@Z
    { 0x4863A0, 0xF8970C5C, 0x0000 }, // ?Disable3DMode@mmOpponentSurfaceAudio@@QAEXXZ
    { 0x4864D0, 0x0233E1EA, 0x0000 }, // ??0EngineAudio@@QAE@XZ
    { 0x486550, 0x5D83DFC0, 0x0000 }, // ?Init@EngineAudio@@QAEXPAVVector3@@@Z
    { 0x4867A0, 0x24AFCF1E, 0x0000 }, // ?Init@EngineAudio@@QAEXPAD0@Z
    { 0x486940, 0x5585939C, 0x0000 }, // ??1EngineAudio@@UAE@XZ
    { 0x4869F0, 0xF08E0502, 0x0000 }, // ?EchoOn@EngineAudio@@QAEXM@Z
    { 0x486A40, 0x488B881F, 0x0000 }, // ?EchoOff@EngineAudio@@QAEXXZ
    { 0x486A70, 0x45A522FF, 0x0000 }, // ?EnableClutch@EngineAudio@@QAEXPADM@Z
    { 0x486B30, 0x55CB8697, 0x0000 }, // ?UpdateRPM@EngineAudio@@UAEXM@Z
    { 0x486D90, 0xF3E418CD, 0x0000 }, // ?ResetVolume@EngineAudio@@QAEXXZ
    { 0x486DB0, 0x9DD452BC, 0x0000 }, // ?Stop@EngineAudio@@QAEXXZ
    { 0x486DF0, 0xE0C8FE48, 0x0000 }, // ?DeclareFields@EngineAudio@@SAXXZ
    { 0x4870A0, 0xC76426A2, 0x0000 }, // ?GetClass@EngineAudio@@UAEPAVMetaClass@@XZ
    { 0x487110, 0xA222FBBF, 0x0000 }, // ??0mmSurfaceAudio@@QAE@PAVmmCarSim@@PAVVector3@@@Z
    { 0x487510, 0xCC81E0C4, 0x0000 }, // ??1mmSurfaceAudio@@QAE@XZ
    { 0x487580, 0x32447647, 0x0000 }, // ?EnableTireWobble@mmSurfaceAudio@@QAEXXZ
    { 0x487630, 0xEA81EC91, 0x0000 }, // ?EchoOn@mmSurfaceAudio@@QAEXPAVmmCarSim@@M@Z
    { 0x487740, 0xBBA6B9C9, 0x0000 }, // ?EchoOff@mmSurfaceAudio@@QAEXPAVmmCarSim@@@Z
    { 0x4877F0, 0x5491CCDB, 0x0000 }, // ?EnableAir@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    { 0x4878C0, 0xEADD560E, 0x0000 }, // ?EnableSuspension@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    { 0x487970, 0xBAF65B33, 0x0000 }, // ?EnableSurface@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    { 0x487B00, 0xB9135B42, 0x0000 }, // ?DisableSurface@mmSurfaceAudio@@QAEXXZ
    { 0x487B20, 0x7A39E33F, 0x0000 }, // ?SetWheelPointers@mmSurfaceAudio@@QAEXPAVmmWheel@@000@Z
    { 0x487B50, 0x279ACEAC, 0x0000 }, // ?Update@mmSurfaceAudio@@QAEXM@Z
    { 0x487BE0, 0xEC92B5BD, 0x0000 }, // ?UpdateTireWobble@mmSurfaceAudio@@QAEXXZ
    { 0x487D30, 0x70CF78C1, 0x0000 }, // ?UpdateSurface@mmSurfaceAudio@@QAEXM@Z
    { 0x487FB0, 0x83727097, 0x0000 }, // ?UpdateSurfaceSnow@mmSurfaceAudio@@QAEXM@Z
    { 0x488190, 0x8CC3D8F2, 0x0000 }, // ?PlayCobble@mmSurfaceAudio@@AAEXM@Z
    { 0x4882C0, 0xCEACF7AB, 0x0000 }, // ?UpdateSkidClear@mmSurfaceAudio@@QAEXM@Z
    { 0x488680, 0x1E6022DE, 0x0000 }, // ?UpdateSkidRain@mmSurfaceAudio@@QAEXM@Z
    { 0x488A50, 0x62CF1BCD, 0x0000 }, // ?UpdateSkidSnow@mmSurfaceAudio@@QAEXM@Z
    { 0x488D80, 0x2BBEFF22, 0x0000 }, // ?UpdateSuspension@mmSurfaceAudio@@QAEXXZ
    { 0x488E90, 0x7E7D191D, 0x0000 }, // ?OnTwoWheels@mmSurfaceAudio@@QAEFXZ
    { 0x488F20, 0xBFD9B39C, 0x0000 }, // ?SetWobblePitch@mmSurfaceAudio@@QAEXMM@Z
    { 0x488F40, 0xDC7A2CBB, 0x0000 }, // ?SetWobbleVol@mmSurfaceAudio@@QAEXMM@Z
    { 0x488FA0, 0xB10B9A33, 0x0000 }, // ??0asNetwork@@QAE@XZ
    { 0x489010, 0xD4042723, 0x0000 }, // ??1asNetwork@@QAE@XZ
    { 0x489020, 0xB50A7FFD, 0x0000 }, // ?Initialize@asNetwork@@QAEHHHH@Z
    { 0x489080, 0x98436892, 0x0000 }, // ?InitializeLobby@asNetwork@@QAEHHH@Z
    { 0x4890F0, 0xC8394805, 0x0000 }, // ?WaitForLobbyConnection@asNetwork@@QAEXH@Z
    { 0x489150, 0x4301ADD9, 0x0000 }, // ?JoinLobbySession@asNetwork@@QAEHXZ
    { 0x489280, 0x6C6A9E20, 0x0000 }, // ?SendLobbyProperty@asNetwork@@QAEXPAXH@Z
    { 0x489360, 0xD6A6752F, 0x0000 }, // ?Logout@asNetwork@@QAEXXZ
    { 0x489430, 0x67E8D3B6, 0x0000 }, // ?Deallocate@asNetwork@@QAEXXZ
    { 0x489470, 0x5DA51A90, 0x0000 }, // ?CreateInterface@asNetwork@@QAEHXZ
    { 0x489490, 0xBEFD09F3, 0x0000 }, // ?GetNetworkCaps@asNetwork@@QAEHXZ
    { 0x489520, 0xF0EBD4FD, 0x0000 }, // ?GetProtocols@asNetwork@@QAEXXZ
    { 0x489550, 0x2C24200B, 0x0000 }, // ?SetProtocol@asNetwork@@QAEHHPAUNETCOMMPACK@@@Z
    { 0x4898B0, 0x7155D3C4, 0x0000 }, // ?SetProtocol@asNetwork@@QAEHH@Z
    { 0x489910, 0x9492EF74, 0x0000 }, // ?Disconnect@asNetwork@@QAEXXZ
    { 0x489960, 0x98FFF53D, 0x0000 }, // ?GetEnumProtocol@asNetwork@@QAEPADH@Z
    { 0x489990, 0x8F63BDDC, 0x0000 }, // ?GetNumProtocols@asNetwork@@QAEHXZ
    { 0x4899A0, 0x593C0A5A, 0x0000 }, // ?CreatePlayer@asNetwork@@QAEHPADPAXH@Z
    { 0x489A60, 0x4163B1A1, 0x0000 }, // ?DestroyPlayer@asNetwork@@QAEXXZ
    { 0x489AA0, 0x03DA98B8, 0x0000 }, // ?GetPlayers@asNetwork@@QAEHPAU_GUID@@@Z
    { 0x489AD0, 0xAB030B29, 0x0000 }, // ?GetEnumPlayer@asNetwork@@QAEPADH@Z
    { 0x489B00, 0x128E1163, 0x0000 }, // ?GetPlayerID@asNetwork@@QAEKH@Z
    { 0x489B40, 0x1BA88EB4, 0x0000 }, // ?GetNumPlayers@asNetwork@@QAEHXZ
    { 0x489C00, 0x52384D37, 0x0000 }, // ?GetPlayerName@asNetwork@@QAEPADK@Z
    { 0x489CC0, 0x07074DB6, 0x0000 }, // ?GetPlayerName@asNetwork@@QAEHKPAD@Z
    { 0x489DA0, 0xDA70A9C6, 0x0000 }, // ?SetPlayerData@asNetwork@@QAEXKPAXH@Z
    { 0x489E40, 0xA72CDC20, 0x0000 }, // ?GetEnumPlayerData@asNetwork@@QAEHHPAXH@Z
    { 0x489F00, 0x3C9F28DE, 0x0000 }, // ?GetPlayerData@asNetwork@@QAEHKPAXH@Z
    { 0x489FB0, 0xB322C490, 0x0000 }, // ?Ping@asNetwork@@QAEKK@Z
    { 0x48A080, 0x147C000C, 0x0000 }, // ?CreateSession@asNetwork@@QAEHPAD0HPAUNETSESSION_DESC@@@Z
    { 0x48A170, 0x8B520959, 0x0000 }, // ?JoinSession@asNetwork@@QAEHPADPAU_GUID@@0@Z
    { 0x48A3A0, 0xDF3D25D4, 0x0000 }, // ?CloseSession@asNetwork@@QAEXXZ
    { 0x48A3E0, 0x5813AED6, 0x0000 }, // ?GetEnumSession@asNetwork@@QAEPADH@Z
    { 0x48A410, 0x96665D2D, 0x0000 }, // ?GetEnumSessionID@asNetwork@@QAEHH@Z
    { 0x48A440, 0x4B4AD809, 0x0000 }, // ?GetNumSessions@asNetwork@@QAEHXZ
    { 0x48A450, 0x7AA9484D, 0x0000 }, // ?SealSession@asNetwork@@QAEXXZ
    { 0x48A570, 0xD92A4E4B, 0x0000 }, // ?UnSealSession@asNetwork@@QAEXXZ
    { 0x48A690, 0xB2B162F1, 0x0000 }, // ?GetSessionData@asNetwork@@QAEXPAUNETSESSION_DESC@@@Z
    { 0x48A750, 0x5D4703C9, 0x0000 }, // ?SetSessionData@asNetwork@@QAEXPAUNETSESSION_DESC@@PAD@Z
    { 0x48A890, 0x7E36DF8F, 0x0000 }, // ?GetSessionsSynch@asNetwork@@QAEHH@Z
    { 0x48A940, 0xACF3F783, 0x0000 }, // ?GetSessionsAsynch@asNetwork@@QAEXXZ
    { 0x48A9A0, 0xC3B657D8, 0x0000 }, // ?StopSessionsAsynch@asNetwork@@QAEXXZ
    { 0x48AA20, 0x2F96B1E7, 0x0000 }, // ?PollLobby@asNetwork@@QAEHXZ
    { 0x48AAC0, 0x4EF4652D, 0x0000 }, // ?Update@asNetwork@@QAEHXZ
    { 0x48ABC0, 0x47CD10ED, 0x0000 }, // ?HandleAppMessage@asNetwork@@QAEXPAX@Z
    { 0x48ABE0, 0xF2FB2AD8, 0x0000 }, // ?HandleSysMessage@asNetwork@@QAEXPAUDPMSG_GENERIC@@@Z
    { 0x48AE30, 0x3180C87F, 0x0000 }, // ?ChatMessage@asNetwork@@QAEXKPAD@Z
    { 0x48AEF0, 0xD7AFAFD1, 0x0000 }, // ?Send@asNetwork@@QAEXKPAXKH@Z
    { 0x48AFC0, 0x92FE3D05, 0x0000 }, // ?GetMyLogicalIndex@asNetwork@@QAEHXZ
    { 0x48B000, 0x9559D4D1, 0x0000 }, // ?GetGameVersion@asNetwork@@QAEHH@Z
    { 0x48B030, 0x103D4AD1, 0x0000 }, // ?GetEnumSessionStatus@asNetwork@@QAEHH@Z
    { 0x48B060, 0xAF673405, 0x0000 }, // ?GetEnumSessionLock@asNetwork@@QAEHH@Z
    { 0x48B090, 0xA58F97DC, 0x0000 }, // ?SetEnumSessionLock@asNetwork@@QAEXHH@Z
    { 0x48B0B0, 0x7760EE44, 0x0000 }, // ?EnumSessionCallback@@YGHPBUDPSESSIONDESC2@@PAKKPAX@Z
    { 0x48B170, 0x4C5BCE09, 0x0000 }, // ?EnumConnectionsCallback@@YGHPBU_GUID@@PAXKPBUDPNAME@@K1@Z
    { 0x48B1E0, 0xEF2592A7, 0x0000 }, // ?EnumPlayersCallback@@YGHKKPBUDPNAME@@KPAX@Z
    { 0x48B240, 0x4F9B4FA4, 0x0000 }, // ?JoinSession@asNetwork@@QAEHHPAD@Z
    { 0x48B2C0, 0x93E6368B, 0x0000 }, // ?GetNumModems@asNetwork@@QAEHXZ
    { 0x48B2D0, 0x7B6CBDAB, 0x0000 }, // ?GetEnumModem@asNetwork@@QAEPADH@Z
    { 0x48B300, 0x94A4D721, 0x0000 }, // ?QueryModems@asNetwork@@QAEHXZ
    { 0x48B430, 0xF1275C1A, 0x0000 }, // ?EnumModemAddress@@YGHABU_GUID@@KPBXPAX@Z
    { 0x48B4A0, 0x6EE8FE0C, 0x0000 }, // ??0asNetObject@@QAE@XZ
    { 0x48B4C0, 0xE28ED056, 0x0000 }, // ??1asNetObject@@UAE@XZ
    { 0x48B4D0, 0x3F66C391, 0x0000 }, // ?PositionUpdate@asNetObject@@UAEXPAVMatrix34@@VVector3@@MMM@Z
    { 0x48B4F0, 0xE8BF1420, 0x0000 }, // ?Update@asNetObject@@UAEXXZ
    { 0x48B530, 0x7CEC443E, 0x0000 }, // ??0mmLoader@@QAE@XZ
    { 0x48B680, 0x11EF9A22, 0x0000 }, // ??1mmLoader@@UAE@XZ
    { 0x48B720, 0xDA600C9B, 0x0000 }, // ?Init@mmLoader@@QAEXPADMM@Z
    { 0x48B810, 0xBE6F4197, 0x0000 }, // ?Shutdown@mmLoader@@QAEXXZ
    { 0x48B820, 0xA59A6232, 0x0000 }, // ?SetIntroText@mmLoader@@QAEXPAULocString@@@Z
    { 0x48B850, 0x92AD23CB, 0x0000 }, // ?BeginTask@mmLoader@@QAEXPAULocString@@M@Z
    { 0x48B8D0, 0xBCB54575, 0x0000 }, // ?EndTask@mmLoader@@QAEXM@Z
    { 0x48B970, 0xAC7B72B5, 0x0000 }, // ?Percent@mmLoader@@QAEXH@Z
    { 0x48B9C0, 0x858D1526, 0x0000 }, // ?Reset@mmLoader@@QAEXXZ
    { 0x48B9E0, 0x92979F4C, 0x0000 }, // ?Update@mmLoader@@QAEXXZ
    { 0x48BA70, 0x56723F39, 0x0000 }, // ?Cull@mmLoader@@UAEXXZ
    { 0x48BB80, 0xD95CB908, 0x0000 }, // ??1asCullable@@UAE@XZ
    { 0x48BB90, 0x3C379BD9, 0x0000 }, // ??0mmCullCity@@QAE@XZ
    { 0x48BD70, 0x5DC7CBEB, 0x0000 }, // ??1mmCullCity@@UAE@XZ
    { 0x48BF10, 0xFAB0B564, 0x0000 }, // ?GetHitId@mmCullCity@@QAEFAAVVector3@@@Z
    { 0x48BF40, 0xAE7E3F69, 0x0000 }, // ?Draw@mmUpperInstance@@EAIXH@Z
    { 0x48BFA0, 0xD8C1E527, 0x0000 }, // ??0mmRunwayLight@@QAE@PADAAVVector3@@1@Z
    { 0x48C160, 0x96556EDC, 0x0000 }, // ?GetPos@mmRunwayLight@@UAIAAVVector3@@XZ
    { 0x48C170, 0x25024CF3, 0x0000 }, // ?FromMatrix@mmRunwayLight@@UAIXABVMatrix34@@@Z
    { 0x48C180, 0xCE58C1A5, 0x0000 }, // ?ToMatrix@mmRunwayLight@@UAIAAVMatrix34@@AAV2@@Z
    { 0x48C1B0, 0xCA5587DC, 0x0000 }, // ?Draw@mmRunwayLight@@UAIXH@Z
    { 0x48C2B0, 0xC431733F, 0x0000 }, // ?GetScale@mmRunwayLight@@UAIMXZ
    { 0x48C2C0, 0x4C5CA831, 0x0000 }, // ?AddInstance@mmCullCity@@AAEXHPAD0HPAVVector3@@11M@Z
    { 0x48C640, 0x292A60E2, 0x0000 }, // ?ReparentObject@mmCullCity@@QAEXPAVmmInstance@@@Z
    { 0x48C6D0, 0x7C2EE8FD, 0x0000 }, // ?Init@mmCullCity@@QAEXPADPAVasCamera@@@Z
    { 0x48CDD0, 0x90120ADA, 0x0000 }, // ?Reset@mmCullCity@@UAEXXZ
    { 0x48CEA0, 0xEC50AEF2, 0x0000 }, // ?InitObjectDetail@mmCullCity@@QAEXXZ
    { 0x48CED0, 0x3BC5D944, 0x0000 }, // ?LoadBangers@mmCullCity@@QAEXPAD@Z
    { 0x48CFF0, 0xAB7823FF, 0x0000 }, // ?LoadFacades@mmCullCity@@QAEXPAD@Z
    { 0x48D100, 0x769E6D72, 0x0000 }, // ?InitSnowTextures@mmCullCity@@AAEXXZ
    { 0x48D2F0, 0x1156A51A, 0x0000 }, // ?UpdateSnowTextures@mmCullCity@@AAEXXZ
    { 0x48D590, 0x98B7EE17, 0x0000 }, // ?IsPolyWater@mmCullCity@@QAEHPAVmmPolygon@@@Z
    { 0x48D5D0, 0xB15C88B2, 0x0000 }, // ?Update@mmCullCity@@UAEXXZ
    { 0x48D820, 0x37821837, 0x0000 }, // ?Cull@mmCullCity@@UAEXXZ
    { 0x48D950, 0x008EA0F2, 0x0000 }, // ?ToggleSky@mmCullCity@@QAEXXZ
    { 0x48D960, 0xB0767401, 0x0000 }, // ?GetRoomFlags@mmCullCity@@QAEFF@Z
    { 0x48D9A0, 0x695A19E0, 0x0000 }, // ?RelightEverything@mmCullCity@@QAEXXZ
    { 0x48DA00, 0x9C28181F, 0x0000 }, // ?fix_clip@@YAXXZ
    { 0x48DA70, 0x278ABFFE, 0x0000 }, // ?fix_lighting@@YAXXZ
    { 0x48DB10, 0xE0A5DD36, 0x0000 }, // ?InitTimeOfDayAndWeather@mmCullCity@@AAEXXZ
    { 0x48E1B0, 0x373E3D52, 0x0000 }, // ?fix_sun@@YAXXZ
    { 0x48E220, 0x3B964FEE, 0x0000 }, // ?fix_fill1@@YAXXZ
    { 0x48E290, 0xD642AA9A, 0x0000 }, // ?fix_fill2@@YAXXZ
    { 0x48E300, 0x01EF30DE, 0x0000 }, // ?parseFloat@@YAXAAM@Z
    { 0x48E330, 0x8D2B245A, 0x0000 }, // ?parseVector3@@YAXAAVVector3@@@Z
    { 0x48E360, 0x939839A1, 0x0000 }, // ?parseRGB@@YAXAAI@Z
    { 0x48E3D0, 0x91727D76, 0x0000 }, // ?parseARGB@@YAXAAI@Z
    { 0x48E450, 0x07BD1C1C, 0x0000 }, // ?fix_fog@@YAXXZ
    { 0x48E480, 0x05ACDE41, 0x0000 }, // ?fix_shadow@@YAXXZ
    { 0x48E4B0, 0xAAEF2EC1, 0x0000 }, // ?AddWidgets@mmCullCity@@UAEXPAVBank@@@Z
    { 0x48F8C0, 0x3217E107, 0x0000 }, // ?DeclareFields@mmCullCity@@SAXXZ
    { 0x48FA30, 0x35389427, 0x0000 }, // ?GetClass@mmCullCity@@UAEPAVMetaClass@@XZ
    { 0x48FA40, 0x9A76FBAE, 0x0000 }, // ?AddWidgets@mmRunwayLight@@UAEXPAVBank@@@Z
    { 0x48FA70, 0xF900DC0E, 0x0000 }, // ??1mmRunwayLight@@UAE@XZ
    { 0x48FAA0, 0x91E270ED, 0x0000 }, // ??1mmUpperInstance@@UAE@XZ
    { 0x48FB10, 0xD9F90426, 0x0000 }, // ?Add@?$agiLib@VagiTexParameters@@VagiTexDef@@@@QAEHAAVagiTexParameters@@@Z
    { 0x48FC10, 0x81A94E82, 0x0000 }, // ??1mmShearInstance@@UAE@XZ
    { 0x48FC40, 0xC6E0F284, 0x0000 }, // ??1mmBuildingInstance@@UAE@XZ
    { 0x48FC70, 0x9B8C8CBA, 0x0000 }, // ??1mmUnhitBangerInstance@@UAE@XZ
    { 0x48FCB0, 0x77507D0A, 0x0000 }, // ??1mmBangerManager@@UAE@XZ
    { 0x48FCC0, 0x2E3627CE, 0x0000 }, // ??0asRenderWeb@@QAE@XZ
    { 0x48FD40, 0xFA0DF886, 0x0000 }, // ??1asRenderWeb@@UAE@XZ
    { 0x48FDD0, 0xCDF92A3F, 0x0000 }, // ?GetStartCell@asRenderWeb@@UAEPAUasPortalCell@@AAVVector3@@PAU2@PAPAVmmPolygon@@@Z
    { 0x48FFF0, 0x4F770694, 0x0000 }, // ?Load@asRenderWeb@@QAEHPADH@Z
    { 0x490CD0, 0x6A7324BF, 0x0000 }, // ?Update@asRenderWeb@@UAEXXZ
    { 0x490D60, 0x4842CABC, 0x0000 }, // ?UpdateMirror@asRenderWeb@@QAEXXZ
    { 0x490E70, 0xE4B08BA3, 0x0000 }, // ?SetMirrorPos@asRenderWeb@@QAEXMMMMM@Z
    { 0x490F40, 0xF3EC24E3, 0x0000 }, // ?DrawMirrorBorder@@YAXXZ
    { 0x490FF0, 0x75B393DE, 0x0000 }, // ?Cull@asRenderWeb@@UAEXXZ
    { 0x4915A0, 0x514C82B5, 0x0000 }, // ?GetCellNeighbors@asRenderWeb@@QAEHHPAPAUasPortalCell@@H@Z
    { 0x491610, 0x9A21CF22, 0x0000 }, // ?DrawAllBounds@asRenderWeb@@QAEXXZ
    { 0x491690, 0x02772514, 0x0000 }, // ?AddWidgets@asRenderWeb@@UAEXPAVBank@@@Z
    { 0x491710, 0xD46E5601, 0x0000 }, // ?DeclareFields@asRenderWeb@@SAXXZ
    { 0x491890, 0x2994DA52, 0x0000 }, // ?GetClass@asRenderWeb@@UAEPAVMetaClass@@XZ
    { 0x491900, 0x6F8E98B4, 0x0000 }, // ?InitPositions@@YAXXZ
    { 0x491940, 0x6312FA45, 0x0000 }, // ?LoadPositions@@YAXPAD@Z
    { 0x491B00, 0x27574ED2, 0x0000 }, // ?GetPositionCount@@YAHXZ
    { 0x491B10, 0xF0718CD5, 0x0000 }, // ?GetPositionVector4@@YAAAVVector4@@H@Z
    { 0x491B40, 0x41682832, 0x0000 }, // ?DumpPositions@@YAXPAD@Z
    { 0x491C00, 0x9D2FB171, 0x0000 }, // ?RecallPosition@@YAHHPAVMatrix34@@PAHPAD@Z
    { 0x491C90, 0xB8FC2EF7, 0x0000 }, // ?RegisterPosition@@YAHAAVVector4@@HHHHPAD@Z
    { 0x491DF0, 0x336A52DD, 0x0000 }, // ??1position_t@@QAE@XZ
    { 0x491E00, 0x27FE8B03, 0x0000 }, // ??0mmPositions@@QAE@XZ
    { 0x491E10, 0x48226845, 0x0000 }, // ?Init@mmPositions@@QAEXH@Z
    { 0x491E40, 0x9FB18FF5, 0x0000 }, // ?Load@mmPositions@@QAEHPAD@Z
    { 0x492010, 0x987BA35E, 0x0000 }, // ?GetCount@mmPositions@@QAEHXZ
    { 0x492020, 0x3D936B5D, 0x0000 }, // ?GetVector4@mmPositions@@QAEAAVVector4@@H@Z
    { 0x492050, 0x22013784, 0x0000 }, // ?Dump@mmPositions@@QAEXPAD@Z
    { 0x4920F0, 0x8B052C52, 0x0000 }, // ?Recall@mmPositions@@QAEHHPAVMatrix34@@PAHPAD@Z
    { 0x492180, 0xA4BB3B7A, 0x0000 }, // ?Register@mmPositions@@QAEHAAVVector4@@HHHHPAD@Z
    { 0x492280, 0x2DC1E41C, 0x0000 }, // ??0mmInstChain@@QAE@XZ
    { 0x492290, 0x222CB166, 0x0000 }, // ??1mmInstChain@@QAE@XZ
    { 0x4922B0, 0xC16524E9, 0x0000 }, // ?Init@mmInstChain@@QAEXH@Z
    { 0x492310, 0xF9A3072B, 0x0000 }, // ?Parent@mmInstChain@@QAEXPAVmmInstance@@F@Z
    { 0x4923A0, 0x26F52670, 0x0000 }, // ?Unparent@mmInstChain@@QAEXPAVmmInstance@@@Z
    { 0x492440, 0xAA68FE87, 0x0000 }, // ?Reparent@mmInstChain@@QAEXPAVmmInstance@@F@Z
    { 0x492470, 0x3AC310C1, 0x0000 }, // ?RelightEverything@mmInstChain@@QAEXXZ
    { 0x492490, 0xD7D115B3, 0x0000 }, // ?Relight@mmInstChain@@QAEXF@Z
    { 0x4924C0, 0x9A86AFF4, 0x0000 }, // ?Draw@mmInstChain@@QAEXFFIHM@Z
    { 0x492980, 0x35B52662, 0x0000 }, // ?AddWidgets@mmInstChain@@QAEXPAVBank@@@Z
    { 0x4929D0, 0x9DA38AA7, 0x0000 }, // ??0mmInstance@@QAE@XZ
    { 0x492A00, 0xEAF4AC8E, 0x0000 }, // ??1mmInstance@@UAE@XZ
    { 0x492A10, 0xF1F68B9D, 0x0000 }, // ?Relight@mmInstance@@UAIXXZ
    { 0x492A20, 0x8DCE871A, 0x0000 }, // ?GetScale@mmInstance@@UAIMXZ
    { 0x492A30, 0xA980BEE9, 0x0000 }, // ?ComputeLod@mmInstance@@UAEHMM@Z
    { 0x492AA0, 0xFB3F50C4, 0x0000 }, // ?Draw@mmInstance@@UAIXH@Z
    { 0x492B00, 0x67213096, 0x0000 }, // ?DrawShadow@mmInstance@@UAIXXZ
    { 0x492B10, 0xF5674ADD, 0x0000 }, // ?DrawGlow@mmInstance@@UAIXXZ
    { 0x492B20, 0x73480B2E, 0x0000 }, // ?Init@mmInstance@@UAEHPADAAVVector3@@1H0@Z
    { 0x492BC0, 0xFE5F2D59, 0x0000 }, // ?formatf@@YAPADPBDZZ
    { 0x492BE0, 0x336E2067, 0x0000 }, // ?GetResidentMeshSet@mmInstance@@QAEPAVagiMeshSet@@HHH@Z
    { 0x492C70, 0x1EA4F6B8, 0x0000 }, // ?GetMeshSetSet@mmInstance@@SAHPADH0PAVVector3@@@Z
    { 0x4930E0, 0x73D70FF4, 0x0000 }, // ?GetPolyInfo@@YAHPAVagiMeshSet@@@Z
    { 0x493120, 0x3BC0BCBC, 0x0000 }, // ?SizeOf@mmInstance@@UAEIXZ
    { 0x493130, 0xA099BBC5, 0x0000 }, // ?Reset@mmInstance@@UAEXXZ
    { 0x493140, 0x32464588, 0x0000 }, // ?ResetAll@mmInstance@@SAXXZ
    { 0x493250, 0xC81BC9E9, 0x0000 }, // ?InitMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    { 0x493290, 0x50CCF374, 0x0000 }, // ?AddMeshes@mmInstance@@QAEXPADH0PAVVector3@@@Z
    { 0x4932B0, 0x9C22D819, 0x0000 }, // ??0mmYInstance@@QAE@XZ
    { 0x4932E0, 0x85AFC740, 0x0000 }, // ??1mmYInstance@@UAE@XZ
    { 0x4932F0, 0xCF4F4411, 0x0000 }, // ?FromMatrix@mmYInstance@@UAIXABVMatrix34@@@Z
    { 0x493340, 0xFFD496CD, 0x0000 }, // ?ToMatrix@mmYInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x493390, 0xF0CFF0AD, 0x0000 }, // ?GetPos@mmYInstance@@UAIAAVVector3@@XZ
    { 0x4933A0, 0x62A3A898, 0x0000 }, // ?SizeOf@mmYInstance@@UAEIXZ
    { 0x4933B0, 0x59F5287A, 0x0000 }, // ?AddWidgets@mmYInstance@@UAEXPAVBank@@@Z
    { 0x493400, 0xFAD2E231, 0x0000 }, // ??0mmMatrixInstance@@QAE@XZ
    { 0x493430, 0x817B9E0F, 0x0000 }, // ??1mmMatrixInstance@@UAE@XZ
    { 0x493440, 0x26FB7BDF, 0x0000 }, // ?FromMatrix@mmMatrixInstance@@UAIXABVMatrix34@@@Z
    { 0x493460, 0x0E683CB7, 0x0000 }, // ?ToMatrix@mmMatrixInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x493470, 0x687245B1, 0x0000 }, // ?GetPos@mmMatrixInstance@@UAIAAVVector3@@XZ
    { 0x493480, 0x3EBC2169, 0x0000 }, // ?Init@mmMatrixInstance@@QAEHPADAAVVector3@@11H0@Z
    { 0x4935B0, 0xEA2E89D0, 0x0000 }, // ?Hit@mmMatrixInstance@@UAEXPAVmmInstance@@@Z
    { 0x4935C0, 0x6D078B1E, 0x0000 }, // ?SizeOf@mmMatrixInstance@@UAEIXZ
    { 0x4935D0, 0x971E2D5A, 0x0000 }, // ?AddWidgets@mmMatrixInstance@@UAEXPAVBank@@@Z
    { 0x4935E0, 0x8DE768D1, 0x0000 }, // ??0mmStaticInstance@@QAE@XZ
    { 0x493600, 0x909227CC, 0x0000 }, // ??1mmStaticInstance@@UAE@XZ
    { 0x493610, 0xD7D2AF7C, 0x0000 }, // ?Init@mmStaticInstance@@QAEHPADAAVVector3@@1MH0@Z
    { 0x493670, 0x8DCD1728, 0x0000 }, // ?MatrixFromPoints@@YAXAAVMatrix34@@AAVVector3@@1M@Z
    { 0x493790, 0x75ABA11A, 0x0000 }, // ??0mmFacadeInstance@@QAE@XZ
    { 0x4937B0, 0x1E9B1B2C, 0x0000 }, // ??1mmFacadeInstance@@UAE@XZ
    { 0x4937C0, 0xBCBBC37E, 0x0000 }, // ?DoubleArea@mmFacadeQuad@@SAMPAVagiMeshSet@@@Z
    { 0x493820, 0xED50AEB5, 0x0000 }, // ?Valid@mmFacadeQuad@@SAHPAVagiMeshSet@@@Z
    { 0x493850, 0xAC979B56, 0x0000 }, // ??0mmFacadeQuad@@QAE@PAVagiMeshSet@@MM@Z
    { 0x493B70, 0xBA37F70C, 0x0000 }, // ?DrawLit@mmFacadeQuad@@QAEXP6AXPAEPAI1PAVagiMeshSet@@@Z2@Z
    { 0x493CC0, 0x4AF0FB0C, 0x0000 }, // ?InitFacade@mmFacadeInstance@@QAEHPADAAVVector3@@1MHABV2@@Z
    { 0x493FF0, 0x8EEE0465, 0x0000 }, // ?GetScale@mmFacadeInstance@@UAIMXZ
    { 0x494000, 0x29A5CA6C, 0x0000 }, // ?SizeOf@mmFacadeInstance@@UAEIXZ
    { 0x494010, 0xAA465D43, 0x0000 }, // ?Draw@mmFacadeInstance@@UAIXH@Z
    { 0x494210, 0xD0FC27C6, 0x0000 }, // ?SizeOf@mmStaticInstance@@UAEIXZ
    { 0x494220, 0x8A01C87E, 0x0000 }, // ?Relight@mmStaticInstance@@UAIXXZ
    { 0x494230, 0x57247721, 0x0000 }, // ?Draw@mmStaticInstance@@UAIXH@Z
    { 0x494290, 0xD7F93DF6, 0x0000 }, // ?SizeOf@mmShearInstance@@UAEIXZ
    { 0x4942A0, 0x6E21DDC0, 0x0000 }, // ?Init@mmShearInstance@@QAEHPADAAVVector3@@1MH0@Z
    { 0x494460, 0x23504F0E, 0x0000 }, // ?Draw@mmShearInstance@@UAIXH@Z
    { 0x494480, 0x91AEAE10, 0x0000 }, // ?GetScale@mmShearInstance@@UAIMXZ
    { 0x494490, 0xEB13FB17, 0x0000 }, // ?SizeOf@mmBuildingInstance@@UAEIXZ
    { 0x4944A0, 0xF39C7041, 0x0000 }, // ?Init@mmBuildingInstance@@QAEHPADAAVVector3@@11@Z
    { 0x4945E0, 0xF021218C, 0x0000 }, // ?GetScale@mmBuildingInstance@@UAIMXZ
    { 0x4945F0, 0xBB6CC5B8, 0x0000 }, // ?Draw@mmBuildingInstance@@UAIXH@Z
    { 0x4946B0, 0x997BFDB9, 0x0000 }, // ?DrawDropShadow@mmInstance@@QAEXHHABVMatrix34@@@Z
    { 0x494960, 0xB2707262, 0x0000 }, // ?AddWidgets@mmStaticInstance@@UAEXPAVBank@@@Z
    { 0x494A10, 0x618109E4, 0x0000 }, // ?DeclareFields@mmInstance@@SAXXZ
    { 0x494AB0, 0x8303F3B3, 0x0000 }, // ?GetClass@mmInstance@@UAEPAVMetaClass@@XZ
    { 0x494AC0, 0x23AC5712, 0x0000 }, // ?DeclareFields@mmYInstance@@SAXXZ
    { 0x494B60, 0x085D8949, 0x0000 }, // ?GetClass@mmYInstance@@UAEPAVMetaClass@@XZ
    { 0x494B70, 0x055DD5E4, 0x0000 }, // ?DeclareFields@mmMatrixInstance@@SAXXZ
    { 0x494CF0, 0x83BC193D, 0x0000 }, // ?GetClass@mmMatrixInstance@@UAEPAVMetaClass@@XZ
    { 0x494D00, 0x709A1F40, 0x0000 }, // ?DeclareFields@mmShearInstance@@SAXXZ
    { 0x494E90, 0x6C3FE113, 0x0000 }, // ?GetClass@mmShearInstance@@UAEPAVMetaClass@@XZ
    { 0x494EA0, 0x47750A03, 0x0000 }, // ?DeclareFields@mmBuildingInstance@@SAXXZ
    { 0x495030, 0xA48275DA, 0x0000 }, // ?GetClass@mmBuildingInstance@@UAEPAVMetaClass@@XZ
    { 0x495040, 0xA74B66D9, 0x0000 }, // ?DeclareFields@mmStaticInstance@@SAXXZ
    { 0x4951C0, 0x77614F03, 0x0000 }, // ?GetClass@mmStaticInstance@@UAEPAVMetaClass@@XZ
    { 0x4951D0, 0xCC4A5DB9, 0x0000 }, // ?DeclareFields@mmFacadeInstance@@SAXXZ
    { 0x495350, 0x0BD4C036, 0x0000 }, // ?GetClass@mmFacadeInstance@@UAEPAVMetaClass@@XZ
    { 0x495460, 0xE8B561E7, 0x0000 }, // ??0mmShearInstance@@QAE@XZ
    { 0x4954E0, 0x42E0CDA6, 0x0000 }, // ??0mmBuildingInstance@@QAE@XZ
    { 0x4955C0, 0x39CDAD64, 0x0000 }, // ?mmHeapError@@YAXXZ
    { 0x4955D0, 0xD63F73A7, 0x0000 }, // ??0mmSky@@QAE@XZ
    { 0x495610, 0x68EE4679, 0x0000 }, // ??1mmSky@@QAE@XZ
    { 0x495650, 0x105F0D17, 0x0000 }, // ?Init@mmSky@@QAEXPAD@Z
    { 0x495680, 0x4A2530A4, 0x0000 }, // ?SetTexture@mmSky@@QAEXPAVagiTexDef@@@Z
    { 0x4956A0, 0xA86EC53B, 0x0000 }, // ?Draw@mmSky@@QAEXAAVMatrix34@@@Z
    { 0x4957E0, 0xCF3942B4, 0x0000 }, // ?AddCell@asPortalWeb@@QAEPAUasPortalCell@@PADPAVasPortalRenderable@@I@Z
    { 0x495830, 0xAD9283B5, 0x0000 }, // ?DeleteCell@asPortalWeb@@QAEXPAUasPortalCell@@@Z
    { 0x4958E0, 0xCF93AAF2, 0x0000 }, // ?AddEdge@asPortalWeb@@QAEPAUasPortalEdge@@PADPAUasPortalCell@@1H@Z
    { 0x4959A0, 0x0E5F5FA3, 0x0000 }, // ?DeleteEdge@asPortalWeb@@QAEXPAUasPortalEdge@@@Z
    { 0x4959B0, 0xFA3873EA, 0x0000 }, // ?LookupCell@@YAPAUasPortalCell@@PAD@Z
    { 0x4959C0, 0x65F261AD, 0x0000 }, // ?LookupEdge@@YAPAUasPortalCell@@PAD@Z
    { 0x4959D0, 0x5DE7EA3A, 0x0000 }, // ?Init@asPortalPVS@@QAEXHH@Z
    { 0x495A30, 0x144FA917, 0x0000 }, // ?Create@asPortalPVS@@SAPAU1@HZZ
    { 0x495AB0, 0xAEFD1310, 0x0000 }, // ?SetVisible@asPortalPVS@@QAEXI@Z
    { 0x495AE0, 0x9EB6BD19, 0x0000 }, // ??0asPortalWeb@@QAE@XZ
    { 0x495B70, 0xE1D5D846, 0x0000 }, // ?BuildVisibilityList@asPortalWeb@@QAEHAAVMatrix34@@PAPAUasPortalCell@@HM@Z
    { 0x495DD0, 0x694506CE, 0x0000 }, // ?BuildVisibilityList@asPortalWeb@@QAEHAAVVector3@@PAPAUasPortalCell@@HM@Z
    { 0x495EE0, 0xC7452ABF, 0x0000 }, // ?Update@asPortalWeb@@UAEXXZ
    { 0x4969F0, 0xA85396F1, 0x0000 }, // ?BuildGroups@asPortalWeb@@QAEXXZ
    { 0x496FE0, 0x4F5F08AD, 0x0000 }, // ?Cull@asPortalWeb@@QAEXH@Z
    { 0x497400, 0x7F1F3881, 0x0000 }, // ?Stats@asPortalWeb@@QAEXXZ
    { 0x4974C0, 0xFB740AB8, 0x0000 }, // ??1asPortalWeb@@UAE@XZ
    { 0x497530, 0xB9F59FD3, 0x0000 }, // ?LockTarget@asPortalWeb@@QAEXXZ
    { 0x497540, 0xA473804C, 0x0000 }, // ?AddWidgets@asPortalWeb@@UAEXPAVBank@@@Z
    { 0x4976D0, 0xB0094F58, 0x0000 }, // ?DeclareFields@asPortalWeb@@SAXXZ
    { 0x497770, 0xEB8B15C9, 0x0000 }, // ?GetClass@asPortalWeb@@UAEPAVMetaClass@@XZ
    { 0x4977B0, 0xEB98BF58, 0x0000 }, // ??0asPortalEdge@@QAE@PAUasPortalCell@@0H@Z
    { 0x497800, 0x59C9053C, 0x0000 }, // ??0mmPed@@QAE@XZ
    { 0x497820, 0x18685090, 0x0000 }, // ?Init@mmPed@@QAEXPADAAVVector3@@@Z
    { 0x4978B0, 0x1EBEAD8E, 0x0000 }, // ??1mmPed@@UAE@XZ
    { 0x4978C0, 0x747567FE, 0x0000 }, // ?Update@mmPed@@QAEXXZ
    { 0x4978E0, 0x78114361, 0x0000 }, // ?Draw@mmPed@@UAIXH@Z
    { 0x497930, 0x07E1868A, 0x0000 }, // ?ToMatrix@mmPed@@UAIAAVMatrix34@@AAV2@@Z
    { 0x497980, 0x9C9D973B, 0x0000 }, // ??0mmPedManager@@QAE@XZ
    { 0x4979A0, 0x4E3251BF, 0x0000 }, // ??1mmPedManager@@UAE@XZ
    { 0x4979B0, 0xBFA7C6B5, 0x0000 }, // ?Init@mmPedManager@@QAEXH@Z
    { 0x497A60, 0x94DEC6EF, 0x0000 }, // ?Update@mmPedManager@@UAEXXZ
    { 0x497A90, 0x35206EA1, 0x0000 }, // ?DeclareFields@mmPed@@SAXXZ
    { 0x497C10, 0x884D29A7, 0x0000 }, // ?GetClass@mmPed@@UAEPAVMetaClass@@XZ
    { 0x497C20, 0x4615A9CA, 0x0000 }, // ?DeclareFields@mmPedManager@@SAXXZ
    { 0x497D80, 0xE5D2DF23, 0x0000 }, // ?GetClass@mmPedManager@@UAEPAVMetaClass@@XZ
    { 0x497E50, 0x92B8D05E, 0x0000 }, // ?LookupSequence@mmAnimation@@QAEHPAD@Z
    { 0x497EB0, 0x18D8C08F, 0x0000 }, // ?Load@mmAnimation@@QAEXPADPAVStream@@@Z
    { 0x498700, 0x972E0316, 0x0000 }, // ?GetAnimation@@YAPAVmmAnimation@@PAD@Z
    { 0x498830, 0x39844410, 0x0000 }, // ?PreUpdate@mmAnimInstState@@SAXM@Z
    { 0x498880, 0x824B5D07, 0x0000 }, // ?Update@mmAnimInstState@@QAEXXZ
    { 0x498950, 0xF90DDF27, 0x0000 }, // ??1HashTable@@QAE@XZ
    { 0x498970, 0xC0138DF1, 0x0000 }, // ??0mmCellRenderer@@QAE@XZ
    { 0x4989A0, 0x5191FD8E, 0x0000 }, // ??1mmCellRenderer@@QAE@XZ
    { 0x4989E0, 0x91042EA4, 0x0000 }, // ?Init@mmCellRenderer@@QAEXPADHHHHPAH@Z
    { 0x498F90, 0xC30B9CDD, 0x0000 }, // ?Relight@mmCellRenderer@@QAEXXZ
    { 0x498FA0, 0x8C3D0A4A, 0x0000 }, // ?Cull@mmCellRenderer@@UAEXH@Z
    { 0x499710, 0xE6D4A821, 0x0000 }, // ?AutoDetect@@YAXHH@Z
    { 0x499970, 0xC15178D1, 0x0000 }, // ??0GraphicsOptions@@QAE@H@Z
    { 0x49A050, 0xE4A227B2, 0x0000 }, // ?SetTexQualString@@YAXXZ
    { 0x49A2F0, 0x29A7D863, 0x0000 }, // ??1GraphicsOptions@@UAE@XZ
    { 0x49A350, 0x86BDB2D8, 0x0000 }, // ?SetResolution@GraphicsOptions@@QAEXXZ
    { 0x49A370, 0x25ACD580, 0x0000 }, // ?SetLightQuality@GraphicsOptions@@QAEXXZ
    { 0x49A390, 0x9B46503B, 0x0000 }, // ?SetRenderer@GraphicsOptions@@QAEXXZ
    { 0x49A5A0, 0x2C222EFE, 0x0000 }, // ?PreSetup@GraphicsOptions@@UAEXXZ
    { 0x49A5C0, 0x1D1F249C, 0x0000 }, // ?ResetDefaultAction@GraphicsOptions@@UAEXXZ
    { 0x49A610, 0x3C57BEC6, 0x0000 }, // ?CancelAction@GraphicsOptions@@UAEXXZ
    { 0x49A640, 0xCFC8D4D9, 0x0000 }, // ?DoneAction@GraphicsOptions@@UAEXXZ
    { 0x49A6D0, 0x7EEEBC9F, 0x0000 }, // ?StoreCurrentSetup@OptionsBase@@UAEXXZ
    { 0x49A6E0, 0x4962750A, 0x0000 }, // ?IsAnOptionMenu@OptionsBase@@UAEHXZ
    { 0x49A6F0, 0x71472040, 0x0000 }, // ?Init@string@@QAEXH@Z
    { 0x49A730, 0x18A7237C, 0x0000 }, // ??0string@@QAE@ABV0@@Z
    { 0x49A790, 0x91426796, 0x0000 }, // ??0VehicleSelectBase@@QAE@H@Z
    { 0x49A8F0, 0x11274FC6, 0x0000 }, // ?IncColor@VehicleSelectBase@@QAEXXZ
    { 0x49A9B0, 0x7600A3EF, 0x0000 }, // ?DecColor@VehicleSelectBase@@QAEXXZ
    { 0x49AA70, 0xE6EB255F, 0x0000 }, // ?ColorCB@VehicleSelectBase@@QAEXXZ
    { 0x49AA90, 0x3DB08CD5, 0x0000 }, // ?InitCarSelection@VehicleSelectBase@@QAEXHMMMM@Z
    { 0x49B7D0, 0x37C5C007, 0x0000 }, // ??1VehicleSelectBase@@UAE@XZ
    { 0x49B870, 0xADF889D9, 0x0000 }, // ?PreSetup@VehicleSelectBase@@UAEXXZ
    { 0x49B960, 0xD1598DB7, 0x0000 }, // ?PostSetup@VehicleSelectBase@@UAEXXZ
    { 0x49B990, 0xA79C720C, 0x0000 }, // ?AllSetCar@VehicleSelectBase@@QAEXPADH@Z
    { 0x49B9E0, 0x5840DD74, 0x0000 }, // ?TDPickCB@VehicleSelectBase@@QAEXXZ
    { 0x49B9F0, 0x29C5153B, 0x0000 }, // ?Reset@VehicleSelectBase@@UAEXXZ
    { 0x49BA00, 0x1989C4A4, 0x0000 }, // ?Update@VehicleSelectBase@@UAEXXZ
    { 0x49BAA0, 0x53EEEF53, 0x0000 }, // ?GetCarTitle@VehicleSelectBase@@QAEPADHPADFPAVstring@@@Z
    { 0x49BBD0, 0xABAFECAE, 0x0000 }, // ?CurrentVehicleIsLocked@VehicleSelectBase@@QAEHXZ
    { 0x49BBF0, 0x78AC42F1, 0x0000 }, // ?SetLastUnlockedVehicle@VehicleSelectBase@@QAEXXZ
    { 0x49BC50, 0x40350EDA, 0x0000 }, // ?CarMod@VehicleSelectBase@@QAEXAAH@Z
    { 0x49BC80, 0x3C8DD483, 0x0000 }, // ?SetPick@VehicleSelectBase@@QAEXHF@Z
    { 0x49BF60, 0xA7105824, 0x0000 }, // ?LoadStats@VehicleSelectBase@@QAEHPAD@Z
    { 0x49C000, 0x01308474, 0x0000 }, // ?AssignVehicleStats@VehicleSelectBase@@QAEXHMMMM@Z
    { 0x49C1E0, 0x7CEE662D, 0x0000 }, // ?FillStats@VehicleSelectBase@@QAEXXZ
    { 0x49C230, 0x1EFA9DEA, 0x0000 }, // ?SetLockedLabel@VehicleSelectBase@@QAEXXZ
    { 0x49C430, 0x40F7A3EC, 0x0000 }, // ??1asDofCS@@UAE@XZ
    { 0x49C4A0, 0x3A7418C2, 0x0000 }, // ??1mmVehicleForm@@UAE@XZ
    { 0x49C4F0, 0x28A504CA, 0x0000 }, // ?IsAnOptionMenu@UIMenu@@UAEHXZ
    { 0x49C500, 0xFE13DC83, 0x0000 }, // ?DecCar@VehicleSelectBase@@QAEXXZ
    { 0x49C510, 0x68ABFD08, 0x0000 }, // ?IncCar@VehicleSelectBase@@QAEXXZ
    { 0x49C520, 0x65A2AF10, 0x0000 }, // ?SetShowcaseFlag@VehicleSelectBase@@QAEXXZ
    { 0x49C530, 0xF3929138, 0x0000 }, // ?SetColor@Card2D@@QAEXVVector4@@@Z
    { 0x49C590, 0xA9BBCE82, 0x0000 }, // ?IsValid@mmVehInfo@@QAEHXZ
    { 0x49C5A0, 0x86E030DE, 0x0000 }, // ??0AudioOptions@@QAE@H@Z
    { 0x49CE60, 0xE55B6B96, 0x0000 }, // ??1AudioOptions@@UAE@XZ
    { 0x49CEF0, 0x0215A477, 0x0000 }, // ?PreSetup@AudioOptions@@UAEXXZ
    { 0x49CF00, 0x877C0634, 0x0000 }, // ?SetWaveVolume@AudioOptions@@QAEXXZ
    { 0x49CF20, 0x4FCD839D, 0x0000 }, // ?SetCDVolume@AudioOptions@@QAEXXZ
    { 0x49CF40, 0x7EF85ABE, 0x0000 }, // ?SetBalance@AudioOptions@@QAEXXZ
    { 0x49CF70, 0x95DABEC1, 0x0000 }, // ?SetQuality@AudioOptions@@QAEXXZ
    { 0x49D040, 0x5DB1B049, 0x0000 }, // ?SetStereoFX@AudioOptions@@QAEXXZ
    { 0x49D0C0, 0xD12F645B, 0x0000 }, // ?StoreCurrentSetup@AudioOptions@@UAEXXZ
    { 0x49D0D0, 0x41442ECF, 0x0000 }, // ?ResetDefaultAction@AudioOptions@@UAEXXZ
    { 0x49D150, 0x3157B809, 0x0000 }, // ?CancelAction@AudioOptions@@UAEXXZ
    { 0x49D1D0, 0xF03C9473, 0x0000 }, // ?DoneAction@AudioOptions@@UAEXXZ
    { 0x49D1E0, 0xE938EEB7, 0x0000 }, // ?SetAudioState@AudioOptions@@QAEXXZ
    { 0x49D3F0, 0xB3E780FD, 0x0000 }, // ?SetCDMusic@AudioOptions@@QAEXXZ
    { 0x49D420, 0x15992EB2, 0x0000 }, // ?SetSoundFX@AudioOptions@@QAEXXZ
    { 0x49D450, 0x15079E19, 0x0000 }, // ?SetCommentary@AudioOptions@@QAEXXZ
    { 0x49D480, 0x11883E97, 0x0000 }, // ?FindDevice@AudioOptions@@QAEHPAD@Z
    { 0x49D510, 0x4393068C, 0x0000 }, // ?GetCurrentDeviceName@AudioOptions@@QAEPADXZ
    { 0x49D530, 0x41DF4CDC, 0x0000 }, // ?ResetStereo@AudioOptions@@QAEXXZ
    { 0x49D560, 0xDB260CDC, 0x0000 }, // ?ResetSoundFX@AudioOptions@@QAEXXZ
    { 0x49D590, 0x2AC3B05F, 0x0000 }, // ?ResetCDMusic@AudioOptions@@QAEXXZ
    { 0x49D5C0, 0xC5FA2418, 0x0000 }, // ?ResetSoundQuality@AudioOptions@@QAEXXZ
    { 0x49D620, 0x1DD146A8, 0x0000 }, // ?ResetCommentary@AudioOptions@@QAEXXZ
    { 0x49D650, 0xF5CE4849, 0x0000 }, // ?SetDevice@AudioOptions@@QAEXH@Z
    { 0x49D730, 0x28FDB1C0, 0x0000 }, // ??0Dialog_City@@QAE@HMMMMPAD@Z
    { 0x49D9B0, 0x7D6DE20B, 0x0000 }, // ??1Dialog_City@@UAE@XZ
    { 0x49DA10, 0xB5D98FD1, 0x0000 }, // ?PreSetup@Dialog_City@@UAEXXZ
    { 0x49DA20, 0xDEB8E2AE, 0x0000 }, // ?DoneCB@Dialog_City@@QAEXXZ
    { 0x49DAB0, 0x4FC34D0F, 0x0000 }, // ??0Dialog_Password@@QAE@HMMMMPAD@Z
    { 0x49DC20, 0x4C65075C, 0x0000 }, // ??1Dialog_Password@@UAE@XZ
    { 0x49DC30, 0xF45897DA, 0x0000 }, // ?PreSetup@Dialog_Password@@UAEXXZ
    { 0x49DC40, 0xB65D2B67, 0x0000 }, // ?PasswordCallback@Dialog_Password@@QAEXXZ
    { 0x49DC80, 0x68924931, 0x0000 }, // ??0Dialog_RaceEnvironment@@QAE@HMMMMPAD@Z
    { 0x49E290, 0xDBE00A0B, 0x0000 }, // ??1Dialog_RaceEnvironment@@UAE@XZ
    { 0x49E2A0, 0x6B40B2EB, 0x0000 }, // ?PreSetup@Dialog_RaceEnvironment@@UAEXXZ
    { 0x49E2F0, 0x9C4847F0, 0x0000 }, // ?ControlPedSlider@Dialog_RaceEnvironment@@QAEXXZ
    { 0x49E310, 0x21A0C662, 0x0000 }, // ?SetMultiRaceOptions@Dialog_RaceEnvironment@@QAEXH@Z
    { 0x49E350, 0xA1E2FE55, 0x0000 }, // ?DoneCallback@Dialog_RaceEnvironment@@QAEXXZ
    { 0x49E3A0, 0xF5EBA16A, 0x0000 }, // ?CancelCallback@Dialog_RaceEnvironment@@QAEXXZ
    { 0x49E3E0, 0x99D8B1B2, 0x0000 }, // ??0Dialog_HallOfFame@@QAE@HMMMMPAD@Z
    { 0x49E7E0, 0x07F5BAE2, 0x0000 }, // ??1Dialog_HallOfFame@@UAE@XZ
    { 0x49E7F0, 0x2F7B1AA5, 0x0000 }, // ?PreSetup@Dialog_HallOfFame@@UAEXXZ
    { 0x49E800, 0x4C114AF2, 0x0000 }, // ?AddRaceRecord@Dialog_HallOfFame@@QAEXHPAD00H00@Z
    { 0x49E940, 0x89D756CE, 0x0000 }, // ?ResetRaceRecord@Dialog_HallOfFame@@QAEXXZ
    { 0x49E9D0, 0xA2290A3E, 0x0000 }, // ?SetSortState@Dialog_HallOfFame@@QAEXXZ
    { 0x49EA50, 0x0C98BA4B, 0x0000 }, // ?InitRaceRecord@Dialog_HallOfFame@@QAEXXZ
    { 0x49EC10, 0x2DF581B6, 0x0000 }, // ??0Dialog_DriverRec@@QAE@HMMMMPAD@Z
    { 0x49EF70, 0xE2BF3BEA, 0x0000 }, // ??1Dialog_DriverRec@@UAE@XZ
    { 0x49EF80, 0xB591C69B, 0x0000 }, // ?PreSetup@Dialog_DriverRec@@UAEXXZ
    { 0x49EF90, 0x4DE668A6, 0x0000 }, // ?InitDriverRecord@Dialog_DriverRec@@QAEXH@Z
    { 0x49F060, 0xAF672C49, 0x0000 }, // ?AddDriverRecord@Dialog_DriverRec@@QAEHHPADHM0H@Z
    { 0x49F1A0, 0xD72F7AB5, 0x0000 }, // ?ResetDriverRecord@Dialog_DriverRec@@QAEXXZ
    { 0x49F230, 0x813BA478, 0x0000 }, // ?SetRecordPosition@Dialog_DriverRec@@QAEXH@Z
    { 0x49F250, 0xB00A2FFB, 0x0000 }, // ?SetSortState@Dialog_DriverRec@@QAEXXZ
    { 0x49F2E0, 0xCD8C2967, 0x0000 }, // ??0Dialog_Message@@QAE@HMMMMPAD@Z
    { 0x49F3F0, 0xB3A15C9F, 0x0000 }, // ?Init@Dialog_Message@@QAEXHPAD0@Z
    { 0x49F460, 0x90873448, 0x0000 }, // ??1Dialog_Message@@UAE@XZ
    { 0x49F470, 0xA456E625, 0x0000 }, // ?PreSetup@Dialog_Message@@UAEXXZ
    { 0x49F4B0, 0x191DD046, 0x0000 }, // ??0Dialog_NewPlayer@@QAE@HMMMMPAD@Z
    { 0x49F7D0, 0xFAE9EB50, 0x0000 }, // ??1Dialog_NewPlayer@@UAE@XZ
    { 0x49F7E0, 0xA5DE85C5, 0x0000 }, // ?EnterNewPlayer@Dialog_NewPlayer@@QAEXXZ
    { 0x49F7F0, 0x9631523B, 0x0000 }, // ?PreSetup@Dialog_NewPlayer@@UAEXXZ
    { 0x49F850, 0x11EC7013, 0x0000 }, // ??0Dialog_Serial@@QAE@HMMMMPAD@Z
    { 0x4A00B0, 0x2DC1900E, 0x0000 }, // ??1Dialog_Serial@@UAE@XZ
    { 0x4A0110, 0x158DA4B3, 0x0000 }, // ?PreSetup@Dialog_Serial@@UAEXXZ
    { 0x4A0120, 0xB5340E89, 0x0000 }, // ?IPAddressCallback@Dialog_Serial@@QAEXXZ
    { 0x4A0130, 0x8015DBDC, 0x0000 }, // ?BuildComs@Dialog_Serial@@QAEXXZ
    { 0x4A01F0, 0x9A65880E, 0x0000 }, // ?GetCommPack@Dialog_Serial@@QAEPAUNETCOMMPACK@@XZ
    { 0x4A0230, 0x0618677D, 0x0000 }, // ??0Dialog_ControlAssign@@QAE@HMMMMPAD@Z
    { 0x4A0330, 0xB5E92642, 0x0000 }, // ??1Dialog_ControlAssign@@UAE@XZ
    { 0x4A0340, 0xECBE1765, 0x0000 }, // ?PreSetup@Dialog_ControlAssign@@UAEXXZ
    { 0x4A0380, 0x43F61090, 0x0000 }, // ??0Dialog_TCPIP@@QAE@HMMMMPAD@Z
    { 0x4A04F0, 0xE314B68C, 0x0000 }, // ??1Dialog_TCPIP@@UAE@XZ
    { 0x4A0500, 0x15CEFF69, 0x0000 }, // ?PreSetup@Dialog_TCPIP@@UAEXXZ
    { 0x4A0510, 0xD1EF7E05, 0x0000 }, // ?IPAddressCallback@Dialog_TCPIP@@QAEXXZ
    { 0x4A0550, 0x7A6D6E39, 0x0000 }, // ??0CRSettings@@QAE@H@Z
    { 0x4A0E90, 0xC8C7ABC4, 0x0000 }, // ??1CRSettings@@UAE@XZ
    { 0x4A0F10, 0xEE1D2F2A, 0x0000 }, // ?SettingsCB@CRSettings@@QAEXXZ
    { 0x4A0F20, 0xD930B36A, 0x0000 }, // ?SetTeam@CRSettings@@QAEXXZ
    { 0x4A0F40, 0x83056530, 0x0000 }, // ?SetTeamWidget@CRSettings@@QAEXXZ
    { 0x4A0F50, 0x5BD8C7C9, 0x0000 }, // ?SetHost@CRSettings@@QAEXH@Z
    { 0x4A1050, 0x83DAAEF6, 0x0000 }, // ?InitPlayerRecord@CRSettings@@QAEXXZ
    { 0x4A1120, 0x7573849E, 0x0000 }, // ?AddPlayerRecord@CRSettings@@QAEHPADHH0@Z
    { 0x4A1260, 0x90B92BF3, 0x0000 }, // ?SetPlayerScore@CRSettings@@QAEXHH@Z
    { 0x4A12A0, 0x2FF115B3, 0x0000 }, // ?ResetPlayerRecord@CRSettings@@QAEXXZ
    { 0x4A1330, 0x589D56CA, 0x0000 }, // ?SetLimitControl@CRSettings@@QAEXXZ
    { 0x4A1490, 0x09696FD8, 0x0000 }, // ?EncodeCRData@CRSettings@@QAEHXZ
    { 0x4A14E0, 0x86DE7E44, 0x0000 }, // ?DecodeCRData@CRSettings@@QAEXH@Z
    { 0x4A1550, 0x7FA789B0, 0x0000 }, // ?GetLimit@CRSettings@@QAEXAAH0@Z
    { 0x4A15A0, 0xB9B3F84D, 0x0000 }, // ?SetLimit@CRSettings@@QAEXAAH0@Z
    { 0x4A1620, 0xDFBFC664, 0x0000 }, // ?SetGoldMass@CRSettings@@QAEXH@Z
    { 0x4A1650, 0x2E493C2A, 0x0000 }, // ?GetGoldMass@CRSettings@@QAEHXZ
    { 0x4A1660, 0x8993BC53, 0x0000 }, // ?GetLimitVal@CRSettings@@QAEHAAH@Z
    { 0x4A16B0, 0xD08C2D07, 0x0000 }, // ?GetGoldMassVal@CRSettings@@QAEHXZ
    { 0x4A16C0, 0x23B518C7, 0x0000 }, // ?SetGameClassCallback@CRSettings@@QAEXXZ
    { 0x4A16E0, 0x53AF3DBC, 0x0000 }, // ?SetTeamWidgets@CRSettings@@QAEXXZ
    { 0x4A1790, 0xC7591BD0, 0x0000 }, // ??0NetArena@@QAE@H@Z
    { 0x4A1D80, 0x5997E29A, 0x0000 }, // ??1NetArena@@UAE@XZ
    { 0x4A1E40, 0xE93A8FF1, 0x0000 }, // ?PreSetup@NetArena@@UAEXXZ
    { 0x4A1E50, 0xEF8ABAFD, 0x0000 }, // ?EnablePlayButton@NetArena@@QAEXXZ
    { 0x4A1E60, 0x4C6EEBA4, 0x0000 }, // ?DisablePlayButton@NetArena@@QAEXXZ
    { 0x4A1E70, 0x10C6ECEF, 0x0000 }, // ?ResetGameChat@NetArena@@QAEXXZ
    { 0x4A1F30, 0x1C9D575F, 0x0000 }, // ?AddGameChatLine@NetArena@@QAEXPAD@Z
    { 0x4A1FE0, 0xF446981F, 0x0000 }, // ?PostChatMessages@NetArena@@QAEXXZ
    { 0x4A20B0, 0xD72E061A, 0x0000 }, // ?ChatEntry@NetArena@@QAEXXZ
    { 0x4A2170, 0x7F0C62A6, 0x0000 }, // ?RetrieveChatLine@NetArena@@QAEHPAD@Z
    { 0x4A21C0, 0xAD30DCED, 0x0000 }, // ?FindRosterName@NetArena@@QAEHPAD@Z
    { 0x4A2230, 0x22F61067, 0x0000 }, // ?AddRosterName@NetArena@@QAEXPAD@Z
    { 0x4A2250, 0x58A4B9E3, 0x0000 }, // ?AddRosterName@NetArena@@QAEXPAULocString@@00K@Z
    { 0x4A23F0, 0x848AC87C, 0x0000 }, // ?RemoveRosterEntry@NetArena@@QAEXH@Z
    { 0x4A24C0, 0xF0AC94F6, 0x0000 }, // ?ResetRoster@NetArena@@QAEXXZ
    { 0x4A25E0, 0x8BA291B2, 0x0000 }, // ?RemoveRosterName@NetArena@@QAEXPAD@Z
    { 0x4A2620, 0x38467F9C, 0x0000 }, // ?SetReady@NetArena@@QAEXKH@Z
    { 0x4A2670, 0x4A0CBDA9, 0x0000 }, // ?GetRaceName@NetArena@@QAEPADXZ
    { 0x4A2880, 0x16390D82, 0x0000 }, // ?PostHostSettings@NetArena@@QAEXXZ
    { 0x4A2A40, 0x570E8C6E, 0x0000 }, // ?PostPlayerInfo@NetArena@@QAEXPAULocString@@00@Z
    { 0x4A2AF0, 0x71F25C23, 0x0000 }, // ?SetHost@NetArena@@QAEXH@Z
    { 0x4A2B60, 0xA16D9DD0, 0x0000 }, // ??0HostRaceMenu@@QAE@H@Z
    { 0x4A2C30, 0x55D42AFE, 0x0000 }, // ??1HostRaceMenu@@UAE@XZ
    { 0x4A2C40, 0x7C0DD46A, 0x0000 }, // ?EnableStart@HostRaceMenu@@QAEXXZ
    { 0x4A2C50, 0x6D637DB2, 0x0000 }, // ?DisableStart@HostRaceMenu@@QAEXXZ
    { 0x4A2C60, 0x9A78C2AB, 0x0000 }, // ?UsesLobby@HostRaceMenu@@UAEXH@Z
    { 0x4A2CA0, 0xF6F0427A, 0x0000 }, // ??0ControlSetup@@QAE@H@Z
    { 0x4A2E90, 0x8A59F3B5, 0x0000 }, // ??1ControlSetup@@UAE@XZ
    { 0x4A2EF0, 0x5C13E8AD, 0x0000 }, // ?CreateDeviceOptions@ControlSetup@@QAEXXZ
    { 0x4A31B0, 0x7FE5D831, 0x0000 }, // ?DeactivateAllDeviceOptions@ControlSetup@@QAEXXZ
    { 0x4A3210, 0x0F4755E5, 0x0000 }, // ?ActivateDeviceOptions@ControlSetup@@QAEXXZ
    { 0x4A34F0, 0x296B128F, 0x0000 }, // ?SetControlPosition@ControlSetup@@QAEMPAVuiWidget@@MM@Z
    { 0x4A3510, 0x33EB2D7E, 0x0000 }, // ?POVCB@ControlSetup@@QAEXXZ
    { 0x4A3520, 0x371CDC78, 0x0000 }, // ?SetSensitivityCB@ControlSetup@@QAEXXZ
    { 0x4A3530, 0xC7C06AD3, 0x0000 }, // ?ControlSelect@ControlSetup@@QAEXXZ
    { 0x4A3580, 0x4BCCEEC0, 0x0000 }, // ?PreSetup@ControlSetup@@UAEXXZ
    { 0x4A35B0, 0x84EF52C9, 0x0000 }, // ?SetFFPermissions@ControlSetup@@QAEXXZ
    { 0x4A35F0, 0xDA650137, 0x0000 }, // ?InitCustomControls@ControlSetup@@QAEXXZ
    { 0x4A3680, 0x34D28F43, 0x0000 }, // ?Update@ControlSetup@@UAEXXZ
    { 0x4A36A0, 0x16EB8FA4, 0x0000 }, // ?StoreCurrentSetup@ControlSetup@@UAEXXZ
    { 0x4A36B0, 0xADDE179A, 0x0000 }, // ?ResetDefaultAction@ControlSetup@@UAEXXZ
    { 0x4A36F0, 0xE43A23D3, 0x0000 }, // ?LaunchJoyCpl@ControlSetup@@QAEXXZ
    { 0x4A37A0, 0x30F6FF4E, 0x0000 }, // ?CalibrateWatcher@@YGKPAX@Z
    { 0x4A3880, 0xE2A5B13C, 0x0000 }, // ?CancelAction@ControlSetup@@UAEXXZ
    { 0x4A3890, 0x27C5E49C, 0x0000 }, // ?DoneAction@ControlSetup@@UAEXXZ
    { 0x4A38A0, 0xEBBF7252, 0x0000 }, // ?BadAssignCB@ControlSetup@@QAEXXZ
    { 0x4A38D0, 0xED70543D, 0x0000 }, // ?ClearBadAssignment@ControlSetup@@QAEXXZ
    { 0x4A38E0, 0x940BF04C, 0x0000 }, // ?CancelBadAssignment@ControlSetup@@QAEXXZ
    { 0x4A3900, 0x9A877DD1, 0x0000 }, // ?VerifyBadAssignment@ControlSetup@@QAEXXZ
    { 0x4A3950, 0xB84643CC, 0x0000 }, // ??0OptionsMenu@@QAE@H@Z
    { 0x4A3B10, 0x92B86283, 0x0000 }, // ??1OptionsMenu@@UAE@XZ
    { 0x4A3B20, 0x2FCFF0DC, 0x0000 }, // ?PreSetup@OptionsMenu@@UAEXXZ
    { 0x4A3B50, 0x9F1BF0D8, 0x0000 }, // ?PostSetup@OptionsMenu@@UAEXXZ
    { 0x4A3BA0, 0xC56DB3AC, 0x0000 }, // ??0NetSelectMenu@@QAE@H@Z
    { 0x4A42F0, 0x41DC8389, 0x0000 }, // ??1NetSelectMenu@@UAE@XZ
    { 0x4A4360, 0x0506BF5E, 0x0000 }, // ?PreSetup@NetSelectMenu@@UAEXXZ
    { 0x4A43D0, 0xF99611BD, 0x0000 }, // ?PostSetup@NetSelectMenu@@UAEXXZ
    { 0x4A43F0, 0x14E5F27E, 0x0000 }, // ?HostCB@NetSelectMenu@@QAEXXZ
    { 0x4A4400, 0xCDAE14B7, 0x0000 }, // ?JoinCB@NetSelectMenu@@QAEXXZ
    { 0x4A4410, 0x8E3C1E96, 0x0000 }, // ?GetHostJoin@NetSelectMenu@@QAEHXZ
    { 0x4A4420, 0xAAEF20C4, 0x0000 }, // ?FocusDescription@NetSelectMenu@@QAEXH@Z
    { 0x4A44A0, 0x19C3DB4D, 0x0000 }, // ?SetDescription@NetSelectMenu@@QAEXPAULocString@@@Z
    { 0x4A44B0, 0x64468226, 0x0000 }, // ?JoinCallback@NetSelectMenu@@QAEXXZ
    { 0x4A44C0, 0xE759BBF7, 0x0000 }, // ?ShowTCPIPNetSessions@NetSelectMenu@@QAEXXZ
    { 0x4A44D0, 0x28507346, 0x0000 }, // ?DisableSessions@NetSelectMenu@@QAEXXZ
    { 0x4A44E0, 0x280BF6A1, 0x0000 }, // ?ProtocolBack@NetSelectMenu@@QAEXXZ
    { 0x4A4500, 0x1B44EBBC, 0x0000 }, // ?SetNetname@NetSelectMenu@@QAEXPAD@Z
    { 0x4A4540, 0x523F86AC, 0x0000 }, // ?SetPhoneNumber@NetSelectMenu@@QAEXPAD@Z
    { 0x4A4560, 0xECE04647, 0x0000 }, // ?SetIPAddress@NetSelectMenu@@QAEXPAD@Z
    { 0x4A4580, 0x614946EA, 0x0000 }, // ?BuildAllTheModemWidgets@NetSelectMenu@@QAEXMMMMPAD@Z
    { 0x4A4690, 0x8970F23F, 0x0000 }, // ?BuildAllTheIPXWidgets@NetSelectMenu@@QAEXMMMM@Z
    { 0x4A46A0, 0xE4016E2D, 0x0000 }, // ?BuildAllTheTCPWidgets@NetSelectMenu@@QAEXMMMM@Z
    { 0x4A46B0, 0x99697C84, 0x0000 }, // ?GetSessions@NetSelectMenu@@QAEPAVUITextScroll@@XZ
    { 0x4A46C0, 0x50C16493, 0x0000 }, // ?GetSessionID@NetSelectMenu@@QAEHXZ
    { 0x4A46D0, 0xAA867097, 0x0000 }, // ?SetSession@NetSelectMenu@@QAEXPADH@Z
    { 0x4A4700, 0x8B60CBA5, 0x0000 }, // ?IPAddressCallback@NetSelectMenu@@QAEXXZ
    { 0x4A4720, 0x8A5853B2, 0x0000 }, // ?BuildComs@NetSelectMenu@@QAEXXZ
    { 0x4A4820, 0x6F609EBD, 0x0000 }, // ?SetComs@NetSelectMenu@@QAEXXZ
    { 0x4A4930, 0x867230B2, 0x0000 }, // ?ReparentWidgets@NetSelectMenu@@QAEXH@Z
    { 0x4A4940, 0x393CC775, 0x0000 }, // ?WidgetSwitch@NetSelectMenu@@QAEXHH@Z
    { 0x4A4950, 0x1F747CC7, 0x0000 }, // ?AddWidgetToList@NetSelectMenu@@QAEXHPAVuiWidget@@@Z
    { 0x4A4960, 0x5128F4CD, 0x0000 }, // ?AddModem@NetSelectMenu@@QAEXPADH@Z
    { 0x4A4A60, 0x8A4AD915, 0x0000 }, // ?ClearProtocol@NetSelectMenu@@QAEXXZ
    { 0x4A4A70, 0x638DD112, 0x0000 }, // ?SetIPXButton@NetSelectMenu@@QAEXH@Z
    { 0x4A4AA0, 0x98E77685, 0x0000 }, // ?SetTCPLocalButton@NetSelectMenu@@QAEXH@Z
    { 0x4A4AB0, 0xAD9C0CF5, 0x0000 }, // ?SetTCPNetButton@NetSelectMenu@@QAEXH@Z
    { 0x4A4AE0, 0x514CA31F, 0x0000 }, // ?SetModemButton@NetSelectMenu@@QAEXH@Z
    { 0x4A4B10, 0xFA249C1D, 0x0000 }, // ?SetSerialButton@NetSelectMenu@@QAEXH@Z
    { 0x4A4B40, 0x4E304312, 0x0000 }, // ?GetCommPack@NetSelectMenu@@QAEPAUNETCOMMPACK@@XZ
    { 0x4A4B70, 0xC8F709A7, 0x0000 }, // ?NetNameCB@NetSelectMenu@@QAEXXZ
    { 0x4A4BA0, 0xA94C472E, 0x0000 }, // ??0string@@QAE@PBD@Z
    { 0x4A4C30, 0xFC4EFE73, 0x0000 }, // ??0RaceMenu@@QAE@H@Z
    { 0x4A4CF0, 0x8469FE4D, 0x0000 }, // ??1RaceMenu@@UAE@XZ
    { 0x4A4D00, 0xBC24B5C4, 0x0000 }, // ?GetRaceID@RaceMenu@@QAEHXZ
    { 0x4A4D90, 0x89CE90D2, 0x0000 }, // ?SetProgressMask@RaceMenu@@QAEXH@Z
    { 0x4A4DB0, 0xA6828F2F, 0x0000 }, // ?SetBlitzMask@RaceMenu@@QAEXH@Z
    { 0x4A4DD0, 0xC4E9610F, 0x0000 }, // ?SetCheckpointMask@RaceMenu@@QAEXH@Z
    { 0x4A4DF0, 0xD65F5832, 0x0000 }, // ?SetCircuitMask@RaceMenu@@QAEXH@Z
    { 0x4A4E10, 0x37955675, 0x0000 }, // ?GetRaceName@RaceMenu@@QAEPADW4mmGameMode@@H@Z
    { 0x4A4F60, 0xD9AA9B2E, 0x0000 }, // ?UsesLobby@RaceMenuBase@@UAEXH@Z
    { 0x4A4F70, 0xEF8B7DE7, 0x0000 }, // ??0VehShowcase@@QAE@H@Z
    { 0x4A50C0, 0x7F51C453, 0x0000 }, // ??1VehShowcase@@UAE@XZ
    { 0x4A5120, 0x9D7AFE6C, 0x0000 }, // ?PreSetup@VehShowcase@@UAEXXZ
    { 0x4A5190, 0xA19F41D0, 0x0000 }, // ?PostSetup@VehShowcase@@UAEXXZ
    { 0x4A51D0, 0x6F0AD3C3, 0x0000 }, // ??0Vehicle@@QAE@H@Z
    { 0x4A52B0, 0xF4ACF3B3, 0x0000 }, // ??1Vehicle@@UAE@XZ
    { 0x4A52C0, 0x68D18A39, 0x0000 }, // ?SetSubMenu@Vehicle@@QAEXH@Z
    { 0x4A52E0, 0xDF74A663, 0x0000 }, // ?SetSubMenuButtons@Vehicle@@QAEXXZ
    { 0x4A5300, 0xCEEA8728, 0x0000 }, // ?PreSetup@Vehicle@@UAEXXZ
    { 0x4A5310, 0xB497506F, 0x0000 }, // ?PostSetup@Vehicle@@UAEXXZ
    { 0x4A5350, 0xE8049EB0, 0x0000 }, // ??0DriverMenu@@QAE@H@Z
    { 0x4A5430, 0x442DF3A4, 0x0000 }, // ?PreSetup@DriverMenu@@UAEXXZ
    { 0x4A5460, 0xC3BB5571, 0x0000 }, // ?InitPlayerSelection@DriverMenu@@QAEXXZ
    { 0x4A5850, 0x7148789C, 0x0000 }, // ??1DriverMenu@@UAE@XZ
    { 0x4A58C0, 0x735528AE, 0x0000 }, // ?RemovePlayer@DriverMenu@@QAEXPAD@Z
    { 0x4A5B00, 0x730BCB36, 0x0000 }, // ?SetPlayerPick@DriverMenu@@QAEXH@Z
    { 0x4A5B10, 0x8E4D6DF4, 0x0000 }, // ?DecPlayer@DriverMenu@@QAEXXZ
    { 0x4A5B40, 0x89D94309, 0x0000 }, // ?IncPlayer@DriverMenu@@QAEXXZ
    { 0x4A5B70, 0x4191C03E, 0x0000 }, // ?RemoveAllPlayers@DriverMenu@@QAEXXZ
    { 0x4A5B80, 0x160E5522, 0x0000 }, // ?AddPlayer@DriverMenu@@QAEXPAD@Z
    { 0x4A5C90, 0xFBD535D3, 0x0000 }, // ?TDPickCB@DriverMenu@@QAEXXZ
    { 0x4A5CA0, 0x45CEB610, 0x0000 }, // ?DeleteCB@DriverMenu@@QAEXXZ
    { 0x4A5CB0, 0xC67C1CC3, 0x0000 }, // ?NewPlayer@DriverMenu@@QAEXXZ
    { 0x4A5CC0, 0x5DF9D82A, 0x0000 }, // ?GetNewDriverName@DriverMenu@@QAEPADXZ
    { 0x4A5CD0, 0x3FC61A9E, 0x0000 }, // ?EnterNewPlayer@DriverMenu@@QAEXXZ
    { 0x4A5CE0, 0x33D343E7, 0x0000 }, // ?DisplayDriverInfo@DriverMenu@@QAEXPAD0000H@Z
    { 0x4A5DA0, 0x3EEE77F3, 0x0000 }, // ?SetController@DriverMenu@@QAEXPAD@Z
    { 0x4A5DC0, 0x0B09B96B, 0x0000 }, // ?SetNetName@DriverMenu@@QAEXPAD@Z
    { 0x4A5E30, 0x487E9A33, 0x0000 }, // ??0AboutMenu@@QAE@H@Z
    { 0x4A6050, 0x03D70A2D, 0x0000 }, // ??1AboutMenu@@UAE@XZ
    { 0x4A6060, 0x78026CA2, 0x0000 }, // ?PreSetup@AboutMenu@@UAEXXZ
    { 0x4A6080, 0x93570B1A, 0x0000 }, // ?Update@AboutMenu@@UAEXXZ
    { 0x4A6100, 0x380C188F, 0x0000 }, // ?Cull@AboutMenu@@UAEXXZ
    { 0x4A61F0, 0xA5AD83C0, 0x0000 }, // ??0MainMenu@@QAE@H@Z
    { 0x4A6370, 0xE136AD7B, 0x0000 }, // ??1MainMenu@@UAE@XZ
    { 0x4A6380, 0xC948B451, 0x0000 }, // ?PreSetup@MainMenu@@UAEXXZ
    { 0x4A63C0, 0xC5C459C0, 0x0000 }, // ??0RaceMenuBase@@QAE@H@Z
    { 0x4A6500, 0x3F9C689D, 0x0000 }, // ?Init@RaceMenuBase@@QAEXH@Z
    { 0x4A72C0, 0x88193C00, 0x0000 }, // ??1RaceMenuBase@@UAE@XZ
    { 0x4A7340, 0x2615EE93, 0x0000 }, // ?FocusDescription@RaceMenuBase@@QAEXH@Z
    { 0x4A7370, 0x55D15E26, 0x0000 }, // ?WidgetOnOff@RaceMenuBase@@QAEXHPAVuiWidget@@@Z
    { 0x4A73A0, 0xB78BD379, 0x0000 }, // ?SetRW@RaceMenuBase@@QAEXXZ
    { 0x4A7670, 0x487B7076, 0x0000 }, // ?IsEnvEnabled@RaceMenuBase@@QAEHXZ
    { 0x4A7690, 0x97BF6E49, 0x0000 }, // ?CheatCallback@RaceMenuBase@@QAEXXZ
    { 0x4A76A0, 0x4EB467D0, 0x0000 }, // ?SyncRaceState@RaceMenuBase@@QAEXXZ
    { 0x4A7750, 0x679698F9, 0x0000 }, // ?CityChange@RaceMenuBase@@QAEXXZ
    { 0x4A78D0, 0x2D015731, 0x0000 }, // ?GameCallback@RaceMenuBase@@QAEXXZ
    { 0x4A7950, 0xE3B272D5, 0x0000 }, // ?LapsCallback@RaceMenuBase@@QAEXXZ
    { 0x4A7960, 0x8EA9946F, 0x0000 }, // ?WPCallback@RaceMenuBase@@QAEXXZ
    { 0x4A79B0, 0x6C1F66C2, 0x0000 }, // ?AICallback@RaceMenuBase@@QAEXXZ
    { 0x4A7A00, 0xD690BBEB, 0x0000 }, // ?WeatherCallback@RaceMenuBase@@QAEXXZ
    { 0x4A7A10, 0x8C04DF74, 0x0000 }, // ?TimeCallback@RaceMenuBase@@QAEXXZ
    { 0x4A7A20, 0x38941224, 0x0000 }, // ?ChangeLocalVals@RaceMenuBase@@QAEXXZ
    { 0x4A7CB0, 0x2B769F3A, 0x0000 }, // ?SetStateRace@RaceMenuBase@@QAEXXZ
    { 0x4A8080, 0xB9D4CBAC, 0x0000 }, // ??0PUResults@@QAE@HMMMMPAD@Z
    { 0x4A81B0, 0x50441772, 0x0000 }, // ?Init320@PUResults@@QAEXXZ
    { 0x4A8590, 0x4B91B9EE, 0x0000 }, // ?Init640@PUResults@@QAEXXZ
    { 0x4A89C0, 0x9BA2342F, 0x0000 }, // ??1PUResults@@UAE@XZ
    { 0x4A89D0, 0x0A32BE77, 0x0000 }, // ?AddTitle@PUResults@@QAEXPAULocString@@0@Z
    { 0x4A8A00, 0xF22A60D5, 0x0000 }, // ?Reset@PUResults@@UAEXXZ
    { 0x4A8A10, 0xBFCE2E86, 0x0000 }, // ?RosterRO@PUResults@@QAEXH@Z
    { 0x4A8A30, 0x42496B90, 0x0000 }, // ?RestartRO@PUResults@@QAEXH@Z
    { 0x4A8A50, 0x01CF6CB9, 0x0000 }, // ?AddName@PUResults@@QAEXHPADM@Z
    { 0x4A8B00, 0x53CD1213, 0x0000 }, // ?AddName@PUResults@@QAEXHPADH@Z
    { 0x4A8BC0, 0xB027BF80, 0x0000 }, // ?ClearNames@PUResults@@QAEXXZ
    { 0x4A8C30, 0x9AEBD7FB, 0x0000 }, // ?DisableNextRace@PUResults@@QAEXXZ
    { 0x4A8C40, 0xFEBB57CE, 0x0000 }, // ?EnableNextRace@PUResults@@QAEXXZ
    { 0x4A8C50, 0x1C4C0368, 0x0000 }, // ?SetMessage@PUResults@@QAEXPAULocString@@@Z
    { 0x4A8CA0, 0xB8ACE230, 0x0000 }, // ??0PURoster@@QAE@HMMMM@Z
    { 0x4A8E10, 0x99F54A9F, 0x0000 }, // ??1PURoster@@UAE@XZ
    { 0x4A8E20, 0x45FF3C64, 0x0000 }, // ?Reset@PURoster@@UAEXXZ
    { 0x4A8E30, 0xCA5C319B, 0x0000 }, // ?BootButtonCB@PURoster@@QAEXXZ
    { 0x4A8E90, 0x73A83914, 0x0000 }, // ?SetHost@PURoster@@QAEXH@Z
    { 0x4A8F00, 0x40C9E9BE, 0x0000 }, // ?AddName@PURoster@@QAEXPADKH@Z
    { 0x4A8FD0, 0x4BE36E4C, 0x0000 }, // ?RemoveName@PURoster@@QAEXPADK@Z
    { 0x4A9110, 0xBA06F3ED, 0x0000 }, // ?RemoveName@PURoster@@QAEXK@Z
    { 0x4A9240, 0x34E9C920, 0x0000 }, // ?ClearNames@PURoster@@QAEXXZ
    { 0x4A92A0, 0xD8CE59B9, 0x0000 }, // ?PostNames@PURoster@@QAEXXZ
    { 0x4A92D0, 0x3FA581AB, 0x0000 }, // ?SetBootCB@PURoster@@QAEXVCallback@@@Z
    { 0x4A92F0, 0xCE11A282, 0x0000 }, // ?FindRosterName@PURoster@@QAEHPAD@Z
    { 0x4A9360, 0xA87DFFED, 0x0000 }, // ?FindRosterName@PURoster@@QAEHK@Z
    { 0x4A93C0, 0x50B3D331, 0x0000 }, // ??0PUKey@@QAE@HMMMM@Z
    { 0x4A9460, 0x1E909692, 0x0000 }, // ??1PUKey@@UAE@XZ
    { 0x4A9470, 0xFC50A048, 0x0000 }, // ?PreSetup@PUKey@@EAEXXZ
    { 0x4A9710, 0xF4F55124, 0x0000 }, // ?PostSetup@PUKey@@EAEXXZ
    { 0x4A9780, 0xE29BD588, 0x0000 }, // ??0PUChat@@QAE@HMMMMPAD@Z
    { 0x4A9880, 0x8D79B4C8, 0x0000 }, // ??1PUChat@@UAE@XZ
    { 0x4A9890, 0xE4930B09, 0x0000 }, // ?ClearChat@PUChat@@QAEXXZ
    { 0x4A98D0, 0x12897018, 0x0000 }, // ?ChatEntry@PUChat@@QAEXXZ
    { 0x4A9960, 0xBB6BF16A, 0x0000 }, // ??0PUGraphics@@QAE@HMMMM@Z
    { 0x4A9E70, 0x4C6EB119, 0x0000 }, // ?toggle_interlace@@YAXXZ
    { 0x4A9E90, 0x7A2E549B, 0x0000 }, // ?toggle_filter@@YAXXZ
    { 0x4A9EC0, 0xB11B16D8, 0x0000 }, // ?fix_lighting_lame@@YAXXZ
    { 0x4A9EE0, 0x65D2683B, 0x0000 }, // ??1PUGraphics@@UAE@XZ
    { 0x4A9EF0, 0xEDBF816F, 0x0000 }, // ?PreSetup@PUGraphics@@UAEXXZ
    { 0x4A9F00, 0x55307DD4, 0x0000 }, // ?CancelAction@PUGraphics@@QAEXXZ
    { 0x4A9F40, 0xA4A40DA5, 0x0000 }, // ?GetInstance@mmCullCity@@SAPAV1@XZ
    { 0x4A9F50, 0xFF3988DC, 0x0000 }, // ??0PUControl@@QAE@HMMMM@Z
    { 0x4AA250, 0xD5668AEB, 0x0000 }, // ??1PUControl@@UAE@XZ
    { 0x4AA2B0, 0x503505B8, 0x0000 }, // ?PreSetup@PUControl@@UAEXXZ
    { 0x4AA2D0, 0x798B34D9, 0x0000 }, // ?CancelAction@PUControl@@QAEXXZ
    { 0x4AA2F0, 0x8A73A1BF, 0x0000 }, // ?SetRWStates@PUControl@@QAEXXZ
    { 0x4AA380, 0xB2088E83, 0x0000 }, // ?ControlSelect@PUControl@@QAEXXZ
    { 0x4AA3B0, 0xB927F0AF, 0x0000 }, // ?SetSensitivityCB@PUControl@@QAEXXZ
    { 0x4AA3F0, 0xDF1BD61E, 0x0000 }, // ??0PUDebug@@QAE@HMMMM@Z
    { 0x4AA590, 0x11030F2F, 0x0000 }, // ??1PUDebug@@UAE@XZ
    { 0x4AA5A0, 0x472944DC, 0x0000 }, // ?RecordCB@PUDebug@@QAEXXZ
    { 0x4AA5E0, 0xFFF2046A, 0x0000 }, // ??0PUOptions@@QAE@HMMMM@Z
    { 0x4AA750, 0xD1710C68, 0x0000 }, // ??1PUOptions@@UAE@XZ
    { 0x4AA790, 0x1BCF1CCA, 0x0000 }, // ??0PUAudioOptions@@QAE@HMMMM@Z
    { 0x4AA9D0, 0xE786C1A9, 0x0000 }, // ??1PUAudioOptions@@UAE@XZ
    { 0x4AA9E0, 0xFEF6208D, 0x0000 }, // ?SetWaveVolume@PUAudioOptions@@QAEXXZ
    { 0x4AAA00, 0x3C072B02, 0x0000 }, // ?SetCDVolume@PUAudioOptions@@QAEXXZ
    { 0x4AAA20, 0xC7B51A6D, 0x0000 }, // ?SetBalance@PUAudioOptions@@QAEXXZ
    { 0x4AAA50, 0xD268A4DA, 0x0000 }, // ?PreSetup@PUAudioOptions@@UAEXXZ
    { 0x4AAA60, 0x0FC326E3, 0x0000 }, // ?CancelAction@PUAudioOptions@@QAEXXZ
    { 0x4AAAA0, 0x03E5A1DB, 0x0000 }, // ??0PUExit@@QAE@HMMMMPAD@Z
    { 0x4AABE0, 0x7A75452E, 0x0000 }, // ??1PUExit@@UAE@XZ
    { 0x4AAC20, 0xD7BDCDC0, 0x0000 }, // ??0PUQuit@@QAE@HMMMMPAD@Z
    { 0x4AAD60, 0xD3F587FF, 0x0000 }, // ??1PUQuit@@UAE@XZ
    { 0x4AADA0, 0xA94901B8, 0x0000 }, // ??0PUMain@@QAE@HMMMMPAD@Z
    { 0x4AAFA0, 0x2347677D, 0x0000 }, // ??1PUMain@@UAE@XZ
    { 0x4AAFE0, 0x8FCD75BB, 0x0000 }, // ??0PUMenuBase@@QAE@HMMMMPAD@Z
    { 0x4AB1B0, 0x1B25C843, 0x0000 }, // ??1PUMenuBase@@UAE@XZ
    { 0x4AB210, 0xB1C6B47C, 0x0000 }, // ?CreateDummyBitmap@PUMenuBase@@QAEPAVagiBitmap@@XZ
    { 0x4AB270, 0x0405D0F0, 0x0000 }, // ?CreateTitle@PUMenuBase@@QAEMXZ
    { 0x4AB280, 0x2089F3CD, 0x0000 }, // ?AddPrevious@PUMenuBase@@QAEMMMMM@Z
    { 0x4AB2F0, 0x9FC98F17, 0x0000 }, // ?AddOKCancel@PUMenuBase@@QAEXVCallback@@0@Z
    { 0x4AB390, 0x72322D72, 0x0000 }, // ?AddExit@PUMenuBase@@QAEMMMMM@Z
    { 0x4AB400, 0x3DC8A332, 0x0000 }, // ?Update@PUMenuBase@@UAEXXZ
    { 0x4AB430, 0x0B64978D, 0x0000 }, // ?Cull@PUMenuBase@@UAEXXZ
    { 0x4AB470, 0xFB4B325D, 0x0000 }, // ?DisableExit@PUMenuBase@@QAEXXZ
    { 0x4AB480, 0x1E2F1F18, 0x0000 }, // ?EnableExit@PUMenuBase@@QAEXXZ
    { 0x4AB4C0, 0x3FE9A8FC, 0x0000 }, // ??0OptionsBase@@QAE@H@Z
    { 0x4AB620, 0xF8CC570C, 0x0000 }, // ?CreateTitle@OptionsBase@@QAEXPAULocString@@@Z
    { 0x4AB650, 0x04BE8F0B, 0x0000 }, // ??1OptionsBase@@UAE@XZ
    { 0x4AB6F0, 0x9ED351FF, 0x0000 }, // ?ResetDefaultAction@OptionsBase@@UAEXXZ
    { 0x4AB700, 0x03E17F66, 0x0000 }, // ??0ControlBase@@QAE@XZ
    { 0x4AB710, 0x60386D6F, 0x0000 }, // ??1ControlBase@@QAE@XZ
    { 0x4AB720, 0xDBEB8379, 0x0000 }, // ?InitSensitivity@ControlBase@@QAEXXZ
    { 0x4AB780, 0x21AEE2EE, 0x0000 }, // ?SetSensitivity@ControlBase@@QAEXXZ
    { 0x4AB7B0, 0x8B739E25, 0x0000 }, // ??0MArray@@QAE@XZ
    { 0x4AB7C0, 0xB22EE450, 0x0000 }, // ??1MArray@@QAE@XZ
    { 0x4AB7D0, 0xAE085994, 0x0000 }, // ?Init@MArray@@QAEXH@Z
    { 0x4AB810, 0xB2655E5A, 0x0000 }, // ?Write@MArray@@QAEXPAD@Z
    { 0x4ABB20, 0xFC5C3A97, 0x0000 }, // ?Flush@MArray@@QAEXXZ
    { 0x4ABB30, 0xD6BF806B, 0x0000 }, // ?Read@MArray@@QAEXPAD@Z
    { 0x4ABCF0, 0x35D47038, 0x0000 }, // ?AddMenuData@MArray@@QAEXHAAVVector4@@PAD@Z
    { 0x4ABD60, 0x1597617D, 0x0000 }, // ?RetrieveMenuData@MArray@@QAEHHAAM000@Z
    { 0x4ABE40, 0xE4CB0CAC, 0x0000 }, // ??0WArray@@QAE@XZ
    { 0x4ABE50, 0x8781A0CA, 0x0000 }, // ??1WArray@@QAE@XZ
    { 0x4ABE60, 0xB1522FDD, 0x0000 }, // ?Init@WArray@@QAEXH@Z
    { 0x4ABEA0, 0x8F87888A, 0x0000 }, // ?Write@WArray@@QAEXPAD@Z
    { 0x4AC0C0, 0x4BDB3F6C, 0x0000 }, // ?DumpMenu@WArray@@QAEXPAVStream@@PAVUIMenu@@@Z
    { 0x4AC320, 0x17B3ED6D, 0x0000 }, // ?Flush@WArray@@QAEXXZ
    { 0x4AC330, 0xBC2355E0, 0x0000 }, // ?Read@WArray@@QAEXPAD@Z
    { 0x4AC510, 0x99458B27, 0x0000 }, // ?AddWidgetData@WArray@@QAEXHHAAVVector4@@PAD@Z
    { 0x4AC590, 0xB802B351, 0x0000 }, // ?RetrieveWidgetData@WArray@@QAEHHHAAM000@Z
    { 0x4AC7F0, 0x91DFDC9E, 0x0000 }, // ??0UIMenu@@QAE@H@Z
    { 0x4AC8F0, 0xC72485C6, 0x0000 }, // ??1UIMenu@@UAE@XZ
    { 0x4AC990, 0x7C68DFD7, 0x0000 }, // ?AssignName@UIMenu@@QAEXPAULocString@@@Z
    { 0x4AC9E0, 0xB1FE208C, 0x0000 }, // ?AssignBackground@UIMenu@@QAEXPAD@Z
    { 0x4ACA30, 0x501B5562, 0x0000 }, // ?Enable@UIMenu@@QAEXXZ
    { 0x4ACAB0, 0x3E30056F, 0x0000 }, // ?Disable@UIMenu@@QAEXXZ
    { 0x4ACAD0, 0x463E646F, 0x0000 }, // ?PreSetup@UIMenu@@UAEXXZ
    { 0x4ACB00, 0x58D12372, 0x0000 }, // ?PostSetup@UIMenu@@UAEXXZ
    { 0x4ACB10, 0xC267C126, 0x0000 }, // ?Update@UIMenu@@UAEXXZ
    { 0x4ACB20, 0xCB80F80F, 0x0000 }, // ?SetAction@UIMenu@@QAEXW4eSource@1@@Z
    { 0x4ACB40, 0x353FC81C, 0x0000 }, // ?ForceWidgetAction@UIMenu@@QAEXH@Z
    { 0x4ACB60, 0x49555EF6, 0x0000 }, // ?ClearAction@UIMenu@@QAEXXZ
    { 0x4ACB70, 0x52218FBA, 0x0000 }, // ?ClearToolTip@UIMenu@@QAEXXZ
    { 0x4ACBA0, 0xD8E4FC02, 0x0000 }, // ?BackUp@UIMenu@@UAEXXZ
    { 0x4ACBB0, 0x97FDE12C, 0x0000 }, // ?SetBstate@UIMenu@@QAEXH@Z
    { 0x4ACBE0, 0xE63117EF, 0x0000 }, // ?SetFocusWidget@UIMenu@@QAEXH@Z
    { 0x4ACC20, 0x50A1F62D, 0x0000 }, // ?GetWidgetID@UIMenu@@QAEHXZ
    { 0x4ACC30, 0x6EEF99BC, 0x0000 }, // ?GetBstate@UIMenu@@QAEHXZ
    { 0x4ACC40, 0x49840F8A, 0x0000 }, // ?GetDimensions@UIMenu@@QAEXAAM000@Z
    { 0x4ACC70, 0x76D0C367, 0x0000 }, // ?DisableIME@UIMenu@@QAEXXZ
    { 0x4ACC90, 0x08032C52, 0x0000 }, // ?FindTheFirstFocusWidget@UIMenu@@QAEHXZ
    { 0x4ACCD0, 0x926EF125, 0x0000 }, // ?Increment@UIMenu@@QAEHXZ
    { 0x4ACD90, 0x1A2F7501, 0x0000 }, // ?Decrement@UIMenu@@QAEHXZ
    { 0x4ACE40, 0x1B86DDED, 0x0000 }, // ?ScanInput@UIMenu@@QAEHPATeqEvent@@@Z
    { 0x4ACE80, 0x60B83F40, 0x0000 }, // ?CheckInput@UIMenu@@UAEXXZ
    { 0x4ACF20, 0xE585D83C, 0x0000 }, // ?ScaleWidget@UIMenu@@QAEXAAM000@Z
    { 0x4ACF60, 0x6CC7D564, 0x0000 }, // ?AddHotSpot@UIMenu@@QAEPAVuiWidget@@HPADMMMMVCallback@@@Z
    { 0x4AD040, 0x75FE1B13, 0x0000 }, // ?AddTextDropdown@UIMenu@@QAEPAVUITextDropdown@@HPAULocString@@PAHMMMMVstring@@HHHVCallback@@PAD@Z
    { 0x4AD1C0, 0xFA1E1161, 0x0000 }, // ?AddTextRoller@UIMenu@@QAEPAVUITextRoller@@HPAULocString@@PAHMMMMVstring@@HHHHVCallback@@@Z
    { 0x4AD310, 0xA3ADAA6B, 0x0000 }, // ?AddTextRoller2@UIMenu@@QAEPAVUITextRoller2@@HPAULocString@@PAHMMMMVstring@@HHHHVCallback@@@Z
    { 0x4AD490, 0xCB1F769C, 0x0000 }, // ?AddTextScroll@UIMenu@@QAEPAVUITextScroll@@HPAXMMMMVstring@@HPAHVCallback@@@Z
    { 0x4AD630, 0x2B71D002, 0x0000 }, // ?AddCompScroll@UIMenu@@QAEPAVUICompositeScroll@@HMMMMMHPAHHHVCallback@@@Z
    { 0x4AD7B0, 0xCD315943, 0x0000 }, // ?AddTextField@UIMenu@@QAEPAVUITextField@@HPAULocString@@PADMMMMHHHHHVCallback@@@Z
    { 0x4AD920, 0x08A67912, 0x0000 }, // ?AddUIControl@UIMenu@@QAEPAVUIControlWidget@@HMMMMMPAVmmIO@@VCallback@@@Z
    { 0x4AD9F0, 0x46C30710, 0x0000 }, // ?AddSlider@UIMenu@@QAEPAVUISlider@@HPAULocString@@PAMMMMMMMHHHHVCallback@@@Z
    { 0x4ADB30, 0x007B16FA, 0x0000 }, // ?AddButton@UIMenu@@QAEPAVUIButton@@HPAULocString@@MMMMHHVCallback@@@Z
    { 0x4ADC50, 0x7154077E, 0x0000 }, // ?AddLabel@UIMenu@@QAEPAVUILabel@@HPAULocString@@MMMMHH@Z
    { 0x4ADD60, 0xD74F9B79, 0x0000 }, // ?AddBMLabel@UIMenu@@QAEPAVUIBMLabel@@HPADPAVstring@@MMPAH@Z
    { 0x4ADE70, 0xCBEF16DE, 0x0000 }, // ?AddIcon@UIMenu@@QAEPAVUIIcon@@HPADMM@Z
    { 0x4ADF80, 0x3D0CD461, 0x0000 }, // ?AddIconW@UIMenu@@QAEPAVUIIconW@@HPAULocString@@PADMMMMVCallback@@@Z
    { 0x4AE090, 0x51CD2319, 0x0000 }, // ?AddToggle@UIMenu@@QAEPAVUIToggleButton@@HPAULocString@@PAHMMMMHHVCallback@@@Z
    { 0x4AE1B0, 0x384C878C, 0x0000 }, // ?AddToggle2@UIMenu@@QAEPAVUIToggleButton2@@HPAULocString@@PAHMMMMHHVCallback@@@Z
    { 0x4AE2D0, 0x6804F566, 0x0000 }, // ?AddMex@UIMenu@@QAEPAVUIMexButton@@HPAULocString@@PAHHMMMMHHVCallback@@@Z
    { 0x4AE3F0, 0x97331C0E, 0x0000 }, // ?AddBMButton@UIMenu@@QAEPAVUIBMButton@@HPADMMHVCallback@@PAHHH1@Z
    { 0x4AE580, 0x83618163, 0x0000 }, // ?AddCWArray@UIMenu@@QAEPAVUICWArray@@HMMMMHVCallback@@@Z
    { 0x4AE6C0, 0x8F3B10A9, 0x0000 }, // ?AddVScrollBar@UIMenu@@QAEPAVUIVScrollBar@@HPAHMMMMMMHHVCallback@@@Z
    { 0x4AE810, 0x8A9234E0, 0x0000 }, // ?MouseAction@UIMenu@@QAEXTeqEvent@@@Z
    { 0x4AE880, 0x8537E387, 0x0000 }, // ?KeyboardAction@UIMenu@@QAEXTeqEvent@@@Z
    { 0x4AE910, 0xB4C54CEE, 0x0000 }, // ?MouseHitCheck@UIMenu@@QAEPAVuiWidget@@HMM@Z
    { 0x4AEA40, 0x85D15908, 0x0000 }, // ?SetSelected@UIMenu@@QAEXXZ
    { 0x4AEA70, 0xB308DACA, 0x0000 }, // ?ClearSelected@UIMenu@@QAEXXZ
    { 0x4AEAA0, 0xDF1D86FA, 0x0000 }, // ?ClearWidgets@UIMenu@@QAEXXZ
    { 0x4AEAD0, 0x256F5755, 0x0000 }, // ?CheckMouseHits@UIMenu@@QAEXXZ
    { 0x4AEC40, 0xFC8D19CC, 0x0000 }, // ?AddWidget@UIMenu@@QAEXPAVuiWidget@@PADMMMMH1@Z
    { 0x4AED60, 0x9CC5F006, 0x0000 }, // ??0MenuManager@@QAE@XZ
    { 0x4AEF20, 0x9B7A34A0, 0x0000 }, // ??1MenuManager@@UAE@XZ
    { 0x4AF140, 0xFB6D088C, 0x0000 }, // ?GetScale@MenuManager@@QAEXAAM000@Z
    { 0x4AF1B0, 0x8912E1D7, 0x0000 }, // ?MouseAction@MenuManager@@QAEPAVuiWidget@@HMM@Z
    { 0x4AF230, 0xB4F30EFF, 0x0000 }, // ?ClearAllWidgets@MenuManager@@QAEXXZ
    { 0x4AF270, 0xBB10BA28, 0x0000 }, // ?Init@MenuManager@@QAEXHHPAD@Z
    { 0x4AF600, 0xBEC85E78, 0x0000 }, // ?Init@MenuManager@@QAEXPAVasCamera@@HHMMMM@Z
    { 0x4AF870, 0x47819BEC, 0x0000 }, // ?InitCommonStuff@MenuManager@@QAEXHH@Z
    { 0x4AFB50, 0x1B78AD80, 0x0000 }, // ?AddPointer@MenuManager@@QAEXXZ
    { 0x4AFB60, 0xCA20CA4A, 0x0000 }, // ?InitGlobalStrings@MenuManager@@QAEXXZ
    { 0x4B02D0, 0x806F372A, 0x0000 }, // ?LoadRaceNames@MenuManager@@QAEXXZ
    { 0x4B05D0, 0xEF5307AF, 0x0000 }, // ?GetControllerName@MenuManager@@QAEPADH@Z
    { 0x4B0670, 0x2B6ACE1F, 0x0000 }, // ?GetFont@MenuManager@@QAEPAXH@Z
    { 0x4B0740, 0xFE1F5EE2, 0x0000 }, // ?GetFGColor@MenuManager@@QAEAAVVector4@@H@Z
    { 0x4B08E0, 0x8D665310, 0x0000 }, // ?CheckBG@MenuManager@@QAEXPAVUIMenu@@@Z
    { 0x4B0900, 0xF9C6FB93, 0x0000 }, // ?SetDefaultBackgroundImage@MenuManager@@QAEXPAD@Z
    { 0x4B0960, 0xA7318D74, 0x0000 }, // ?SetBackgroundImage@MenuManager@@QAEXPAD@Z
    { 0x4B09B0, 0x4BFD2223, 0x0000 }, // ?TogglePU@MenuManager@@QAEXXZ
    { 0x4B09D0, 0x22EC9B94, 0x0000 }, // ?EnablePU@MenuManager@@QAEXXZ
    { 0x4B0A50, 0xBF3B0BA3, 0x0000 }, // ?AdjustPopupCard@MenuManager@@QAEXPAVUIMenu@@@Z
    { 0x4B0AA0, 0x4A81EF82, 0x0000 }, // ?DisablePU@MenuManager@@QAEXXZ
    { 0x4B0AE0, 0x1BDA9D4A, 0x0000 }, // ?OpenDialog@MenuManager@@QAEXH@Z
    { 0x4B0B60, 0x342A2BF2, 0x0000 }, // ?CloseDialog@MenuManager@@QAEXXZ
    { 0x4B0B90, 0x66536E8D, 0x0000 }, // ?Enable@MenuManager@@QAEXH@Z
    { 0x4B0C00, 0xCDCEC0A6, 0x0000 }, // ?Disable@MenuManager@@QAEXH@Z
    { 0x4B0C40, 0x5F109118, 0x0000 }, // ?EnableNavBar@MenuManager@@QAEXXZ
    { 0x4B0C60, 0x66E1090E, 0x0000 }, // ?DisableNavBar@MenuManager@@QAEXXZ
    { 0x4B0C70, 0xB5AFB894, 0x0000 }, // ?Kill@MenuManager@@QAEXXZ
    { 0x4B0D10, 0xBF6E7950, 0x0000 }, // ?PlaySound@MenuManager@@QAEXH@Z
    { 0x4B0DC0, 0xD9C96ABF, 0x0000 }, // ?DeclareLastDrawn@MenuManager@@QAEXPAVasNode@@@Z
    { 0x4B0DD0, 0x5BD421EA, 0x0000 }, // ?ResChange@MenuManager@@UAEXHH@Z
    { 0x4B0E00, 0x3F5AAC7C, 0x0000 }, // ?Update@MenuManager@@UAEXXZ
    { 0x4B0E30, 0x3E356EF8, 0x0000 }, // ?Flush@MenuManager@@QAEXXZ
    { 0x4B0E60, 0xCF4DFA53, 0x0000 }, // ?CheckInput@MenuManager@@QAEXXZ
    { 0x4B0EE0, 0x107FDB1A, 0x0000 }, // ?ToggleFocus@MenuManager@@QAEXH@Z
    { 0x4B0F60, 0xE9EA87DD, 0x0000 }, // ?RegisterWidgetFocus@MenuManager@@QAEXHMMMMPAVuiWidget@@@Z
    { 0x4B0FC0, 0xA9FE122B, 0x0000 }, // ?ScanGlobalKeys@MenuManager@@QAEHH@Z
    { 0x4B1370, 0x5511CF2B, 0x0000 }, // ?SwitchFocus@MenuManager@@QAEXPAVUIMenu@@@Z
    { 0x4B13C0, 0x7AB7BFDD, 0x0000 }, // ?NotifyMouseSelect@MenuManager@@QAEXPAVUIMenu@@@Z
    { 0x4B1400, 0x727E5922, 0x0000 }, // ?AddWidgets@MenuManager@@UAEXPAVBank@@@Z
    { 0x4B1410, 0x0E88EE59, 0x0000 }, // ?GetCurrentMenu@MenuManager@@QAEPAVUIMenu@@XZ
    { 0x4B1440, 0xC87FBFD3, 0x0000 }, // ?FindMenu@MenuManager@@QAEHH@Z
    { 0x4B1480, 0x9C851A66, 0x0000 }, // ?CurrentMenuSelected@MenuManager@@QAEHXZ
    { 0x4B14A0, 0xE8732576, 0x0000 }, // ?MenuState@MenuManager@@QAEHH@Z
    { 0x4B14E0, 0xDBB42F16, 0x0000 }, // ?ActionID@MenuManager@@QAEHH@Z
    { 0x4B1520, 0x944533DC, 0x0000 }, // ?ForceCurrentFocus@MenuManager@@QAEXXZ
    { 0x4B1550, 0x6EC0A9C1, 0x0000 }, // ?SetFocus@MenuManager@@QAEXPAVUIMenu@@@Z
    { 0x4B1560, 0x1F62C8B4, 0x0000 }, // ?Switch@MenuManager@@QAEHH@Z
    { 0x4B1620, 0x24E3C91F, 0x0000 }, // ?SetPreviousMenu@MenuManager@@QAEXH@Z
    { 0x4B1650, 0x4ADAA2FD, 0x0000 }, // ?GetPreviousMenu@MenuManager@@QAEHXZ
    { 0x4B1670, 0x991C2925, 0x0000 }, // ?AddMenu2@MenuManager@@QAEHPAVUIMenu@@@Z
    { 0x4B16D0, 0x1F7B9422, 0x0000 }, // ?DeleteMenu@MenuManager@@QAEXPAVUIMenu@@@Z
    { 0x4B1730, 0x3F7D8A1C, 0x0000 }, // ?PlayMenuSwitchSound@MenuManager@@AAEXXZ
    { 0x4B17D0, 0xC8F1031F, 0x0000 }, // ?AllocateMenuSwitchAudio@MenuManager@@QAEXXZ
    { 0x4B1950, 0x4E27FCAA, 0x0000 }, // ?PlayRecordsSound@MenuManager@@QAEXXZ
    { 0x4B1980, 0x16EF252E, 0x0000 }, // ?AddBrackets@MenuManager@@QAEXPAVUIIcon@@0PAVuiWidget@@MM@Z
    { 0x4B1A60, 0x24E9B81B, 0x0000 }, // ?Help@MenuManager@@QAEXXZ
    { 0x4B1B30, 0x9D56D0D2, 0x0000 }, // ?HelpWatcher@@YGKPAX@Z
    { 0x4B1D00, 0xDDF7F422, 0x0000 }, // ??0uiNavBar@@QAE@H@Z
    { 0x4B1F10, 0x6662D514, 0x0000 }, // ?Help@uiNavBar@@QAEXXZ
    { 0x4B1F20, 0xC50DAACB, 0x0000 }, // ?Minimize@uiNavBar@@QAEXXZ
    { 0x4B1F70, 0x92E5EB33, 0x0000 }, // ??1uiNavBar@@UAE@XZ
    { 0x4B1F80, 0x0A509B07, 0x0000 }, // ?ResetState@uiNavBar@@QAEXXZ
    { 0x4B1F90, 0x65CA2AD2, 0x0000 }, // ?OptionActive@uiNavBar@@QAEXXZ
    { 0x4B1FB0, 0x17F584B6, 0x0000 }, // ?OptionInActive@uiNavBar@@QAEXXZ
    { 0x4B1FD0, 0x57B11D61, 0x0000 }, // ?Update@uiNavBar@@UAEXXZ
    { 0x4B2070, 0x7FB105F2, 0x0000 }, // ?SetPrevPos@uiNavBar@@QAEXMM@Z
    { 0x4B20C0, 0xE2B60D93, 0x0000 }, // ?TurnOnPrev@uiNavBar@@QAEXXZ
    { 0x4B20E0, 0x74942128, 0x0000 }, // ?TurnOffPrev@uiNavBar@@QAEXXZ
    { 0x4B2100, 0xCF37F146, 0x0000 }, // ?SetPrevBitmap@uiNavBar@@QAEXPAD@Z
    { 0x4B2150, 0xE1FB48BE, 0x0000 }, // ?BackUp@uiNavBar@@UAEXXZ
    { 0x4B2160, 0x97805144, 0x0000 }, // ??0UITextField@@QAE@XZ
    { 0x4B2270, 0x708334B3, 0x0000 }, // ??1UITextField@@UAE@XZ
    { 0x4B22E0, 0xD0CBEF46, 0x0000 }, // ?Init@UITextField@@QAEXPAULocString@@PADMMMMHHHHHVCallback@@PAVUIMenu@@@Z
    { 0x4B25F0, 0xDA8BEF9A, 0x0000 }, // ?SetText@UITextField@@QAEXPAULocString@@@Z
    { 0x4B2610, 0x6A8CB899, 0x0000 }, // ?SetField@UITextField@@QAEXPAD@Z
    { 0x4B2670, 0x80D7C113, 0x0000 }, // ?CaptureAction@UITextField@@UAEXTeqEvent@@@Z
    { 0x4B2680, 0xCF12E278, 0x0000 }, // ?Action@UITextField@@UAEXTeqEvent@@@Z
    { 0x4B26D0, 0x80019F2C, 0x0000 }, // ?ClearField@UITextField@@QAEXXZ
    { 0x4B2730, 0x05A620BE, 0x0000 }, // ?SetTextField@UITextField@@QAEXXZ
    { 0x4B2780, 0xC2A60255, 0x0000 }, // ?ToggleField@UITextField@@QAEXH@Z
    { 0x4B28E0, 0x7AF76182, 0x0000 }, // ?Switch@UITextField@@UAEXH@Z
    { 0x4B2980, 0xCAFA7975, 0x0000 }, // ?IsValidChar@UITextField@@QAEHG@Z
    { 0x4B2A10, 0x13595C3E, 0x0000 }, // ?WmCharHandler@UITextField@@QAEXE@Z
    { 0x4B2B80, 0x6608238D, 0x0000 }, // ?KeyAction@UITextField@@QAEXPATeqEvent@@@Z
    { 0x4B2C90, 0x419FCA95, 0x0000 }, // ?SetCompositionWindow@UITextField@@QAEXXZ
    { 0x4B2DB0, 0x360FB9C5, 0x0000 }, // ??1uiWidget@@UAE@XZ
    { 0x4B2DC0, 0x3B6D3D38, 0x0000 }, // ?Disable@uiWidget@@UAEXXZ
    { 0x4B2DD0, 0xB7001479, 0x0000 }, // ?Enable@uiWidget@@UAEXXZ
    { 0x4B2DE0, 0xA2F13A44, 0x0000 }, // ?TurnOn@uiWidget@@UAEXXZ
    { 0x4B2E00, 0xA1B7EAE4, 0x0000 }, // ?TurnOff@uiWidget@@UAEXXZ
    { 0x4B2E10, 0x9453C80B, 0x0000 }, // ?SetReadOnly@uiWidget@@UAEXH@Z
    { 0x4B2E30, 0x312DEE63, 0x0000 }, // ?Action@uiWidget@@UAEXTeqEvent@@@Z
    { 0x4B2E40, 0x60749071, 0x0000 }, // ?CaptureAction@uiWidget@@UAEXTeqEvent@@@Z
    { 0x4B2E50, 0x0F3F3DD8, 0x0000 }, // ?EvalMouseX@uiWidget@@UAEXM@Z
    { 0x4B2E60, 0x02418B6B, 0x0000 }, // ?ReturnDescription@uiWidget@@UAEPADXZ
    { 0x4B2E70, 0x14DFC282, 0x0000 }, // ?SetPosition@uiWidget@@UAEXMM@Z
    { 0x4B2E80, 0x186FA6D7, 0x0000 }, // ?GetScreenHeight@uiWidget@@UAEMXZ
    { 0x4B2EC0, 0x74CE21CE, 0x0000 }, // ?Update@UITextField@@UAEXXZ
    { 0x4B2ED0, 0x59E8060A, 0x0000 }, // ??0UITextDropdown@@QAE@XZ
    { 0x4B2F60, 0xDC80D2F2, 0x0000 }, // ??1UITextDropdown@@UAE@XZ
    { 0x4B2FD0, 0xCAE8B08E, 0x0000 }, // ?Init@UITextDropdown@@QAEXPAULocString@@PAHMMMMVstring@@HHHVCallback@@PAD@Z
    { 0x4B3390, 0x99D7FA00, 0x0000 }, // ?GetScreenHeight@UITextDropdown@@UAEMXZ
    { 0x4B33A0, 0x7E4FF63A, 0x0000 }, // ?SetPos@UITextDropdown@@QAEXMM@Z
    { 0x4B33B0, 0x8CA42623, 0x0000 }, // ?AssignString@UITextDropdown@@QAEXVstring@@@Z
    { 0x4B3460, 0x82ED4792, 0x0000 }, // ?SetData@UITextDropdown@@QAEXPAH@Z
    { 0x4B3490, 0x1A2E624C, 0x0000 }, // ?Update@UITextDropdown@@UAEXXZ
    { 0x4B3500, 0x1C2776F1, 0x0000 }, // ?SetText@UITextDropdown@@QAEXPAULocString@@@Z
    { 0x4B3510, 0xF367566C, 0x0000 }, // ?CaptureAction@UITextDropdown@@UAEXTeqEvent@@@Z
    { 0x4B3680, 0x83B39217, 0x0000 }, // ?Action@UITextDropdown@@UAEXTeqEvent@@@Z
    { 0x4B37B0, 0xD07AAB6F, 0x0000 }, // ?Switch@UITextDropdown@@UAEXH@Z
    { 0x4B3830, 0xD9AF7947, 0x0000 }, // ?SetSliderFocus@UITextDropdown@@QAEXH@Z
    { 0x4B38B0, 0xD64B98B7, 0x0000 }, // ?GetValue@UITextDropdown@@QAEHXZ
    { 0x4B38C0, 0x15AC6CC3, 0x0000 }, // ?SetValue@UITextDropdown@@QAEHH@Z
    { 0x4B38F0, 0xB9425444, 0x0000 }, // ?SetDisabledMask@UITextDropdown@@QAEXJ@Z
    { 0x4B3910, 0xBA142B4B, 0x0000 }, // ?AnyEnabled@UITextDropdown@@QAEHXZ
    { 0x4B3920, 0xB563BE79, 0x0000 }, // ?Cull@UITextDropdown@@UAEXXZ
    { 0x4B39B0, 0x857DAA12, 0x0000 }, // ??0UISlider@@QAE@XZ
    { 0x4B3A40, 0x27786AAD, 0x0000 }, // ??1UISlider@@UAE@XZ
    { 0x4B3AB0, 0xBF86BB59, 0x0000 }, // ?Init@UISlider@@QAEXPAULocString@@PAMMMMMMMHHHHVCallback@@PAVUIMenu@@@Z
    { 0x4B3CD0, 0xAD2D00C9, 0x0000 }, // ?SetPosition@UISlider@@UAEXMM@Z
    { 0x4B3E30, 0xD08DEEEF, 0x0000 }, // ?SetText@UISlider@@QAEXPAULocString@@@Z
    { 0x4B3E40, 0x877B0397, 0x0000 }, // ?Update@UISlider@@UAEXXZ
    { 0x4B3EA0, 0x74F3AB6E, 0x0000 }, // ?Action@UISlider@@UAEXTeqEvent@@@Z
    { 0x4B3F70, 0x7F616A8D, 0x0000 }, // ?Switch@UISlider@@UAEXH@Z
    { 0x4B3FE0, 0x064A6967, 0x0000 }, // ?TestHit@UISlider@@QAEHMM@Z
    { 0x4B3FF0, 0x38EEF2F1, 0x0000 }, // ?SetReadWrite@UISlider@@QAEXH@Z
    { 0x4B4040, 0xC3A11F9C, 0x0000 }, // ?IsReadWrite@UISlider@@QAEHXZ
    { 0x4B4050, 0xC31FBFD5, 0x0000 }, // ?GetValue@UISlider@@QAEMXZ
    { 0x4B4060, 0x2CC38773, 0x0000 }, // ?SetValue@UISlider@@QAEMM@Z
    { 0x4B4090, 0x7C4A9D47, 0x0000 }, // ?SetMouseParams@UISlider@@QAEXM@Z
    { 0x4B40E0, 0x3AFDF329, 0x0000 }, // ?EvalMouseXY@UISlider@@QAEXMM@Z
    { 0x4B4210, 0x01905801, 0x0000 }, // ?SetData@UISlider@@QAEXM@Z
    { 0x4B4230, 0x076CB643, 0x0000 }, // ?GetFudgeWidth@UISlider@@QAEMXZ
    { 0x4B4270, 0x907AF24F, 0x0000 }, // ?GetScreenHeight@UISlider@@UAEMXZ
    { 0x4B4280, 0xA58D708E, 0x0000 }, // ??0UIBMLabel@@QAE@XZ
    { 0x4B42F0, 0x1763D815, 0x0000 }, // ??1UIBMLabel@@UAE@XZ
    { 0x4B4360, 0x0F90409E, 0x0000 }, // ?Init@UIBMLabel@@QAEXPAVstring@@MMPAH@Z
    { 0x4B4440, 0x1888DE0E, 0x0000 }, // ?SetBitmapName@UIBMLabel@@QAEXPAVstring@@@Z
    { 0x4B44E0, 0xCD25A5FB, 0x0000 }, // ?LoadBitmap@UIBMLabel@@AAEXXZ
    { 0x4B45C0, 0x9D526AEA, 0x0000 }, // ?CreateDummyBitmap@UIBMLabel@@QAEPAVagiBitmap@@XZ
    { 0x4B4610, 0xC710462F, 0x0000 }, // ?Update@UIBMLabel@@UAEXXZ
    { 0x4B4640, 0x40B66329, 0x0000 }, // ?Cull@UIBMLabel@@UAEXXZ
    { 0x4B4680, 0x90006803, 0x0000 }, // ?DeclareFields@UIBMLabel@@SAXXZ
    { 0x4B47F0, 0xDD7549BA, 0x0000 }, // ?GetClass@UIBMLabel@@UAEPAVMetaClass@@XZ
    { 0x4B4860, 0xC80ACD07, 0x0000 }, // ??0uiWidget@@QAE@XZ
    { 0x4B4890, 0x194AC7F0, 0x0000 }, // ?AddToolTip@uiWidget@@QAEXPAVUIMenu@@PAULocString@@@Z
    { 0x4B48A0, 0x34B87EDF, 0x0000 }, // ?Switch@uiWidget@@UAEXH@Z
    { 0x4B48C0, 0xCE72923C, 0x0000 }, // ?ResetToolTip@uiWidget@@QAEXXZ
    { 0x4B48D0, 0x1A4A7BFD, 0x0000 }, // ?SetToolTipText@uiWidget@@QAEXPAULocString@@@Z
    { 0x4B48F0, 0xABED01D2, 0x0000 }, // ??0mmCompRaceRecord@@QAE@XZ
    { 0x4B4930, 0xD726F5A1, 0x0000 }, // ??1mmCompRaceRecord@@UAE@XZ
    { 0x4B49D0, 0xD2330B15, 0x0000 }, // ?Init@mmCompRaceRecord@@QAEXHPAD0000HH@Z
    { 0x4B4A60, 0xEB89EE49, 0x0000 }, // ?InitTitle@mmCompRaceRecord@@QAEXMMMMPAULocString@@00000H@Z
    { 0x4B4AD0, 0xB8126E7F, 0x0000 }, // ?LoadBitmap@mmCompRaceRecord@@QAEXPAD@Z
    { 0x4B4B20, 0xFCC08312, 0x0000 }, // ?Reset@mmCompRaceRecord@@UAEXXZ
    { 0x4B4B30, 0x8DB95F8D, 0x0000 }, // ?Update@mmCompRaceRecord@@UAEXXZ
    { 0x4B4B40, 0xBD83A2E4, 0x0000 }, // ?SetSubwidgetGeometry@mmCompRaceRecord@@QAEXXZ
    { 0x4B4C70, 0xEDDC7FFF, 0x0000 }, // ?SetGeometry@mmCompRaceRecord@@UAEXMMMM@Z
    { 0x4B4CA0, 0x240B9415, 0x0000 }, // ?SelectIfRaceType@mmCompRaceRecord@@QAEXHH@Z
    { 0x4B4CE0, 0xBB00BD2C, 0x0000 }, // ?SetPosition@mmCompRaceRecord@@UAEXPAVmmTextNode@@HM@Z
    { 0x4B4D80, 0xF2B8A262, 0x0000 }, // ?Cull@mmCompRaceRecord@@UAEXXZ
    { 0x4B4DF0, 0xF2562A1D, 0x0000 }, // ??1mmCompBase@@UAE@XZ
    { 0x4B4E00, 0xCD8F492E, 0x0000 }, // ?DisableBlt@mmCompBase@@UAEXXZ
    { 0x4B4E10, 0x72764703, 0x0000 }, // ?SetBltXY@mmCompBase@@UAEXMM@Z
    { 0x4B4E40, 0xB85DD40A, 0x0000 }, // ?Action@mmCompBase@@UAEXTeqEvent@@@Z
    { 0x4B4E50, 0x6F5A5C96, 0x0000 }, // ?CaptureAction@mmCompBase@@UAEXTeqEvent@@@Z
    { 0x4B4E60, 0x4E8819C3, 0x0000 }, // ?Switch@mmCompBase@@UAEXH@Z
    { 0x4B4E70, 0x8E4CFDE7, 0x0000 }, // ?Action@mmCompBase@@UAEXTeqEvent@@MMH@Z
    { 0x4B4E80, 0xBCE1FA75, 0x0000 }, // ?EvalMouseXY@mmCompBase@@UAEXMM@Z
    { 0x4B4E90, 0x2D369080, 0x0000 }, // ?Highlight@mmCompBase@@UAEXPAVmmTextNode@@H@Z
    { 0x4B4EA0, 0xB7ECDEB1, 0x0000 }, // ?SetGeometry@mmCompBase@@UAEXMMMM@Z
    { 0x4B4EF0, 0x745412CD, 0x0000 }, // ??0UICompositeScroll@@QAE@XZ
    { 0x4B4FD0, 0x25D9B7CF, 0x0000 }, // ??1UICompositeScroll@@UAE@XZ
    { 0x4B5050, 0xB41BC537, 0x0000 }, // ?Init@UICompositeScroll@@QAEXMMMMMHPAHHHVCallback@@@Z
    { 0x4B5290, 0x178FB338, 0x0000 }, // ?InitVScroll@UICompositeScroll@@QAEXMMM@Z
    { 0x4B5310, 0x6F1FCAEC, 0x0000 }, // ?RemoveAllComponentChildren@UICompositeScroll@@QAEXXZ
    { 0x4B5360, 0xC10F40CB, 0x0000 }, // ?AddComponent@UICompositeScroll@@QAEXPAVmmCompBase@@@Z
    { 0x4B5430, 0x2AAE03D8, 0x0000 }, // ?AddTitle@UICompositeScroll@@QAEXPAVmmCompBase@@@Z
    { 0x4B5450, 0x3AC4098A, 0x0000 }, // ?GetSelectedCount@UICompositeScroll@@QAEHXZ
    { 0x4B54A0, 0x0458BB34, 0x0000 }, // ?Redraw@UICompositeScroll@@QAEXXZ
    { 0x4B55F0, 0xD0273E64, 0x0000 }, // ?VScrollCB@UICompositeScroll@@QAEXXZ
    { 0x4B5660, 0x24FFFAEE, 0x0000 }, // ?SetVScrollVals@UICompositeScroll@@QAEXXZ
    { 0x4B56B0, 0x2502B9CA, 0x0000 }, // ?SetVScrollPos@UICompositeScroll@@QAEXXZ
    { 0x4B56F0, 0x70849431, 0x0000 }, // ?Reset@UICompositeScroll@@UAEXXZ
    { 0x4B5710, 0xEA93CE0A, 0x0000 }, // ?Update@UICompositeScroll@@UAEXXZ
    { 0x4B5720, 0x68FCBD73, 0x0000 }, // ?GetHit@UICompositeScroll@@QAEHMM@Z
    { 0x4B57A0, 0x08221F45, 0x0000 }, // ?Action@UICompositeScroll@@UAEXTeqEvent@@@Z
    { 0x4B5920, 0x98D3FB0D, 0x0000 }, // ?CaptureAction@UICompositeScroll@@UAEXTeqEvent@@@Z
    { 0x4B5990, 0x4D9070F4, 0x0000 }, // ?Switch@UICompositeScroll@@UAEXH@Z
    { 0x4B59D0, 0xCF0D26C4, 0x0000 }, // ?Clear@UICompositeScroll@@QAEXXZ
    { 0x4B59E0, 0x555BC6F9, 0x0000 }, // ?SetHightlight@UICompositeScroll@@QAEXXZ
    { 0x4B59F0, 0x522AC2E8, 0x0000 }, // ?GetHeight@UICompositeScroll@@QAEMXZ
    { 0x4B5A10, 0xD42BDA73, 0x0000 }, // ?SetPosition@UICompositeScroll@@QAEXH@Z
    { 0x4B5A80, 0x59F9250F, 0x0000 }, // ??0mmCompDRecord@@QAE@XZ
    { 0x4B5AC0, 0x71E07EC5, 0x0000 }, // ??1mmCompDRecord@@UAE@XZ
    { 0x4B5B70, 0x4A163FB0, 0x0000 }, // ?Init@mmCompDRecord@@QAEXHPADM0HHH@Z
    { 0x4B5C60, 0xB4A6D7EE, 0x0000 }, // ?InitTitle@mmCompDRecord@@QAEXMMMMPAULocString@@0000H@Z
    { 0x4B5CD0, 0x8528B55F, 0x0000 }, // ?LoadBitmap@mmCompDRecord@@QAEXPAD@Z
    { 0x4B5D40, 0x69C545F7, 0x0000 }, // ?Reset@mmCompDRecord@@UAEXXZ
    { 0x4B5D50, 0xCBB55364, 0x0000 }, // ?Update@mmCompDRecord@@UAEXXZ
    { 0x4B5D80, 0xC0E0F63C, 0x0000 }, // ?SetSubwidgetGeometry@mmCompDRecord@@QAEXXZ
    { 0x4B5EA0, 0xBFB85D0D, 0x0000 }, // ?SetPosition@mmCompDRecord@@UAEXPAVmmTextNode@@HM@Z
    { 0x4B5F40, 0xF26770B9, 0x0000 }, // ?SetGeometry@mmCompDRecord@@UAEXMMMM@Z
    { 0x4B5F70, 0x176FDE4F, 0x0000 }, // ?SetBltXY@mmCompDRecord@@UAEXMM@Z
    { 0x4B5FC0, 0x738F7D66, 0x0000 }, // ?Cull@mmCompDRecord@@UAEXXZ
    { 0x4B6090, 0xB7134813, 0x0000 }, // ?DisableBlt@mmCompDRecord@@UAEXXZ
    { 0x4B60A0, 0x00750FD2, 0x0000 }, // ??0UIBMButton@@QAE@XZ
    { 0x4B6140, 0xD779E99E, 0x0000 }, // ??1UIBMButton@@UAE@XZ
    { 0x4B61C0, 0x4CDF439F, 0x0000 }, // ?Init@UIBMButton@@QAEXPADMMHHPAHHHPAULocString@@VCallback@@3@Z
    { 0x4B6450, 0xDDC941D0, 0x0000 }, // ?LoadBitmap@UIBMButton@@QAEXPAD@Z
    { 0x4B64C0, 0xCC970D4A, 0x0000 }, // ?GetDiv@UIBMButton@@QAEHXZ
    { 0x4B64F0, 0xC84F57F2, 0x0000 }, // ?CreateDummyBitmap@UIBMButton@@QAEPAVagiBitmap@@XZ
    { 0x4B6550, 0xC793BD6E, 0x0000 }, // ?GetSize@UIBMButton@@AAEXXZ
    { 0x4B6580, 0x17EDA58E, 0x0000 }, // ?SetPosition@UIBMButton@@UAEXMM@Z
    { 0x4B66F0, 0x703B44CF, 0x0000 }, // ?GetHitArea@UIBMButton@@QAEXAAM0@Z
    { 0x4B6750, 0x6257A34C, 0x0000 }, // ?DoToggle@UIBMButton@@QAEXXZ
    { 0x4B6810, 0xD7ADC2AD, 0x0000 }, // ?Kill@UIBMButton@@QAEXXZ
    { 0x4B6830, 0xDB8D4BCF, 0x0000 }, // ?Unkill@UIBMButton@@QAEXXZ
    { 0x4B6870, 0xBCEF76F2, 0x0000 }, // ?Switch@UIBMButton@@UAEXH@Z
    { 0x4B69A0, 0x46A6ED69, 0x0000 }, // ?Action@UIBMButton@@UAEXTeqEvent@@@Z
    { 0x4B6A50, 0xFD59E66B, 0x0000 }, // ?MexOff@UIBMButton@@QAEXXZ
    { 0x4B6A60, 0x0C2A36DE, 0x0000 }, // ?MexOn@UIBMButton@@QAEXXZ
    { 0x4B6AA0, 0x49B974C2, 0x0000 }, // ?MexToggle@UIBMButton@@QAEXXZ
    { 0x4B6AD0, 0x923C88CB, 0x0000 }, // ?Update@UIBMButton@@UAEXXZ
    { 0x4B6C60, 0xC436960F, 0x0000 }, // ?ReturnDescription@UIBMButton@@UAEPADXZ
    { 0x4B6D10, 0x52EA8F5F, 0x0000 }, // ?GetScreenHeight@UIBMButton@@UAEMXZ
    { 0x4B6D20, 0x51CC700A, 0x0000 }, // ?Cull@UIBMButton@@UAEXXZ
    { 0x4B6ED0, 0xC50F4245, 0x0000 }, // ?AllocateSounds@UIBMButton@@CAXXZ
    { 0x4B70C0, 0xC1443FC7, 0x0000 }, // ?PlaySound@UIBMButton@@AAEXXZ
    { 0x4B70F0, 0xAD8ED612, 0x0000 }, // ?DeclareFields@UIBMButton@@SAXXZ
    { 0x4B7260, 0x1301F9EA, 0x0000 }, // ?GetClass@UIBMButton@@UAEPAVMetaClass@@XZ
    { 0x4B7270, 0xC680F52F, 0x0000 }, // ?Enable@UIBMButton@@UAEXXZ
    { 0x4B7290, 0xD2743961, 0x0000 }, // ?Disable@UIBMButton@@UAEXXZ
    { 0x4B7310, 0x37CCE998, 0x0000 }, // ??0mmCompCRPlayer@@QAE@XZ
    { 0x4B7340, 0xDB3EF39B, 0x0000 }, // ??1mmCompCRPlayer@@UAE@XZ
    { 0x4B73D0, 0xCDE45DA9, 0x0000 }, // ?Init@mmCompCRPlayer@@QAEXPADH0HH@Z
    { 0x4B7500, 0x8C827734, 0x0000 }, // ?InitTitle@mmCompCRPlayer@@QAEXMMMMPAULocString@@000H@Z
    { 0x4B7510, 0x82472816, 0x0000 }, // ?LoadBitmap@mmCompCRPlayer@@QAEXPAD@Z
    { 0x4B7570, 0x02A5FB3D, 0x0000 }, // ?Reset@mmCompCRPlayer@@UAEXXZ
    { 0x4B7580, 0x71888AED, 0x0000 }, // ?Update@mmCompCRPlayer@@UAEXXZ
    { 0x4B7590, 0xCF8C6A7E, 0x0000 }, // ?SetPoints@mmCompCRPlayer@@QAEXH@Z
    { 0x4B75B0, 0xF799CD8A, 0x0000 }, // ?SetSubwidgetGeometry@mmCompCRPlayer@@QAEXXZ
    { 0x4B76B0, 0xF6CF4317, 0x0000 }, // ?SetPosition@mmCompCRPlayer@@UAEXPAVmmTextNode@@HM@Z
    { 0x4B7740, 0x165378E6, 0x0000 }, // ?SetGeometry@mmCompCRPlayer@@UAEXMMMM@Z
    { 0x4B7770, 0x7098EFF6, 0x0000 }, // ?Cull@mmCompCRPlayer@@UAEXXZ
    { 0x4B7840, 0x224F8687, 0x0000 }, // ??0mmCompRoster@@QAE@XZ
    { 0x4B78B0, 0x115A8934, 0x0000 }, // ??1mmCompRoster@@UAE@XZ
    { 0x4B7940, 0xE208DBE1, 0x0000 }, // ?Init@mmCompRoster@@QAEXPAD00K@Z
    { 0x4B79C0, 0xCC4FF38A, 0x0000 }, // ?InitTitle@mmCompRoster@@QAEXMMMMPAULocString@@000H@Z
    { 0x4B79D0, 0x0AD8BACC, 0x0000 }, // ?LoadBitmap@mmCompRoster@@QAEXPAD@Z
    { 0x4B7A20, 0x1FD31879, 0x0000 }, // ?Reset@mmCompRoster@@UAEXXZ
    { 0x4B7A30, 0x152DA85B, 0x0000 }, // ?Update@mmCompRoster@@UAEXXZ
    { 0x4B7A60, 0xDBB9652A, 0x0000 }, // ?SetReady@mmCompRoster@@QAEXH@Z
    { 0x4B7A80, 0xEF2A13A7, 0x0000 }, // ?SetSubwidgetGeometry@mmCompRoster@@QAEXXZ
    { 0x4B7B20, 0x53AE7A61, 0x0000 }, // ?SetPosition@mmCompRoster@@UAEXPAVmmTextNode@@HM@Z
    { 0x4B7BA0, 0x6543F53A, 0x0000 }, // ?SetGeometry@mmCompRoster@@UAEXMMMM@Z
    { 0x4B7BD0, 0x0052FF17, 0x0000 }, // ?SetBltXY@mmCompRoster@@UAEXMM@Z
    { 0x4B7C10, 0x6491B3DF, 0x0000 }, // ?Cull@mmCompRoster@@UAEXXZ
    { 0x4B7C70, 0x77951070, 0x0000 }, // ??0UICWArray@@QAE@XZ
    { 0x4B7D30, 0xC79444BB, 0x0000 }, // ??1UICWArray@@UAE@XZ
    { 0x4B7D40, 0x116C96DF, 0x0000 }, // ?Reset@UICWArray@@UAEXXZ
    { 0x4B7D50, 0xCDC5DF7D, 0x0000 }, // ?Init@UICWArray@@QAEXMMMMHVCallback@@@Z
    { 0x4B7FB0, 0xC017D1F1, 0x0000 }, // ?VScrollCB@UICWArray@@QAEXXZ
    { 0x4B8020, 0xBC7C4CAC, 0x0000 }, // ?SetVScrollVals@UICWArray@@QAEXXZ
    { 0x4B8090, 0xED786533, 0x0000 }, // ?SetVScrollPos@UICWArray@@QAEXXZ
    { 0x4B80C0, 0x416AEC8B, 0x0000 }, // ?SetStartOffset@UICWArray@@QAEXH@Z
    { 0x4B8100, 0x874A802F, 0x0000 }, // ?Redraw@UICWArray@@QAEXXZ
    { 0x4B8260, 0x9789F085, 0x0000 }, // ?Switch@UICWArray@@UAEXH@Z
    { 0x4B82A0, 0x3FD2D075, 0x0000 }, // ?Action@UICWArray@@UAEXTeqEvent@@@Z
    { 0x4B83D0, 0x0D8B0704, 0x0000 }, // ?CaptureAction@UICWArray@@UAEXTeqEvent@@@Z
    { 0x4B8440, 0x92F26820, 0x0000 }, // ?Update@UICWArray@@UAEXXZ
    { 0x4B84C0, 0xF30FB28C, 0x0000 }, // ?EnterCapture@UICWArray@@QAEXH@Z
    { 0x4B8530, 0x21A98B12, 0x0000 }, // ?ForceCapture@UICWArray@@QAEXXZ
    { 0x4B8560, 0x6B4404CF, 0x0000 }, // ?AcceptCapture@UICWArray@@QAEXXZ
    { 0x4B85B0, 0xE1AB7589, 0x0000 }, // ?ResetCapture@UICWArray@@QAEXXZ
    { 0x4B85E0, 0x81B35003, 0x0000 }, // ?CheckCapture@UICWArray@@QAEXXZ
    { 0x4B8690, 0x1B5CD9E7, 0x0000 }, // ?SaveCFG@UICWArray@@QAEXXZ
    { 0x4B86D0, 0x5A823C93, 0x0000 }, // ?LoadCFG@UICWArray@@QAEXXZ
    { 0x4B8720, 0xE307B0AA, 0x0000 }, // ?DefaultCFG@UICWArray@@QAEXXZ
    { 0x4B8740, 0xE0D4FDE9, 0x0000 }, // ?DebugForceSetting@UICWArray@@QAEXXZ
    { 0x4B87F0, 0xF72E78A6, 0x0000 }, // ??0UITextScroll@@QAE@XZ
    { 0x4B8900, 0x9EAA736A, 0x0000 }, // ??1UITextScroll@@UAE@XZ
    { 0x4B8980, 0x6DB61FE6, 0x0000 }, // ?Init@UITextScroll@@QAEXPAXMMMMVstring@@HPAHVCallback@@@Z
    { 0x4B8CF0, 0xED5BACC4, 0x0000 }, // ?InitVScroll@UITextScroll@@QAEXMMM@Z
    { 0x4B8D00, 0xB090099F, 0x0000 }, // ?VScrollCB@UITextScroll@@QAEXXZ
    { 0x4B8D40, 0xB28834EE, 0x0000 }, // ?SetVScrollVals@UITextScroll@@QAEXXZ
    { 0x4B8D60, 0xD1FC5C10, 0x0000 }, // ?SetVScrollPos@UITextScroll@@QAEXXZ
    { 0x4B8D90, 0xE5809AEA, 0x0000 }, // ?Recalc@UITextScroll@@QAEXVstring@@@Z
    { 0x4B8F00, 0x422E1B8A, 0x0000 }, // ?FillScroll@UITextScroll@@AAEXXZ
    { 0x4B8FE0, 0x3AB81A59, 0x0000 }, // ?GetCurrentString@UITextScroll@@QAEXPADH@Z
    { 0x4B9030, 0xA037C2CC, 0x0000 }, // ?SetHighlight@UITextScroll@@QAEXH@Z
    { 0x4B9080, 0xF0D32188, 0x0000 }, // ?GetHit@UITextScroll@@QAEHMM@Z
    { 0x4B9100, 0x7E0A9324, 0x0000 }, // ?KeyAction@UITextScroll@@AAEXXZ
    { 0x4B9160, 0x1105CFB2, 0x0000 }, // ?Action@UITextScroll@@UAEXTeqEvent@@@Z
    { 0x4B9210, 0x1BCD1E69, 0x0000 }, // ?Switch@UITextScroll@@UAEXH@Z
    { 0x4B9250, 0x78F4E666, 0x0000 }, // ?SetTextColor@UITextScroll@@AAEXXZ
    { 0x4B92B0, 0x238D49C1, 0x0000 }, // ?SetText@UITextScroll@@QAEXHPAULocString@@@Z
    { 0x4B92F0, 0x266A5F40, 0x0000 }, // ?ResetTextScroll@UITextScroll@@AAEXXZ
    { 0x4B9370, 0x65D7CFA7, 0x0000 }, // ?InitTextScroll@UITextScroll@@AAEXVstring@@@Z
    { 0x4B94A0, 0xD0FBFC29, 0x0000 }, // ?AddTextScrollLine@UITextScroll@@AAEXPADH@Z
    { 0x4B9530, 0xD153F338, 0x0000 }, // ?AddTextScrollLine@UITextScroll@@AAEXPAD@Z
    { 0x4B9600, 0x945149D3, 0x0000 }, // ??0UILabel@@QAE@XZ
    { 0x4B9690, 0x86C66F76, 0x0000 }, // ??1UILabel@@UAE@XZ
    { 0x4B96F0, 0x958E9317, 0x0000 }, // ?Init@UILabel@@QAEXPAULocString@@HMMMMH@Z
    { 0x4B97B0, 0x45ACC29F, 0x0000 }, // ?SetText@UILabel@@QAEXPAULocString@@@Z
    { 0x4B97D0, 0xFE3E7509, 0x0000 }, // ?Update@UILabel@@UAEXXZ
    { 0x4B9820, 0x5B00BFFA, 0x0000 }, // ?SetBlink@UILabel@@QAEXH@Z
    { 0x4B9850, 0xB5892809, 0x0000 }, // ?Switch@UILabel@@UAEXH@Z
    { 0x4B9860, 0x88BF7DB9, 0x0000 }, // ?SwitchState@UILabel@@QAEXH@Z
    { 0x4B98F0, 0x1628FCF9, 0x0000 }, // ?Action@UILabel@@UAEXTeqEvent@@@Z
    { 0x4B9900, 0x4ECC0F49, 0x0000 }, // ??0UIIcon@@QAE@XZ
    { 0x4B9950, 0x29A17F21, 0x0000 }, // ??1UIIcon@@UAE@XZ
    { 0x4B9960, 0xD3975688, 0x0000 }, // ?Init@UIIcon@@QAEXPADMM@Z
    { 0x4B99A0, 0x03289370, 0x0000 }, // ?LoadBitmap@UIIcon@@QAEXPAD@Z
    { 0x4B9A10, 0x9A25191D, 0x0000 }, // ?CreateDummyBitmap@UIIcon@@QAEPAVagiBitmap@@XZ
    { 0x4B9A60, 0x17F57CE2, 0x0000 }, // ?GetHitArea@UIIcon@@QAEXAAM0@Z
    { 0x4B9A90, 0x5D547668, 0x0000 }, // ?Switch@UIIcon@@UAEXH@Z
    { 0x4B9AD0, 0x247A817A, 0x0000 }, // ?Update@UIIcon@@UAEXXZ
    { 0x4B9AF0, 0xFD19C6DE, 0x0000 }, // ?Cull@UIIcon@@UAEXXZ
    { 0x4B9B50, 0x4AD2A09E, 0x0000 }, // ??0UIButton@@QAE@XZ
    { 0x4B9BE0, 0xCD612D8B, 0x0000 }, // ??1UIButton@@UAE@XZ
    { 0x4B9C50, 0x67B14295, 0x0000 }, // ?Init@UIButton@@QAEXPAULocString@@HMMMMHVCallback@@@Z
    { 0x4B9D20, 0xC8502F35, 0x0000 }, // ?Update@UIButton@@UAEXXZ
    { 0x4B9D30, 0x7AC1FAD1, 0x0000 }, // ?SetString@UIButton@@QAEXPAULocString@@@Z
    { 0x4B9D50, 0xD34F6C78, 0x0000 }, // ?DrawOff@UIButton@@AAEXXZ
    { 0x4B9D80, 0x0FEA9318, 0x0000 }, // ?DrawOn@UIButton@@AAEXXZ
    { 0x4B9DB0, 0x07AF507A, 0x0000 }, // ?Action@UIButton@@UAEXTeqEvent@@@Z
    { 0x4B9E00, 0x3F248B0B, 0x0000 }, // ?SetReadOnly@UIButton@@UAEXH@Z
    { 0x4B9E50, 0xC26DC894, 0x0000 }, // ?Switch@UIButton@@UAEXH@Z
    { 0x4B9ED0, 0x8302A721, 0x0000 }, // ?SetType@UIButton@@QAEXH@Z
    { 0x4B9F20, 0xA931ECED, 0x0000 }, // ?TestHit@UIButton@@QAEHMM@Z
    { 0x4B9F60, 0x8FB05735, 0x0000 }, // ?Enable@UIButton@@UAEXXZ
    { 0x4B9F80, 0x78E122D2, 0x0000 }, // ?Disable@UIButton@@UAEXXZ
    { 0x4B9F90, 0x0C0B7947, 0x0000 }, // ??0UITextRoller@@QAE@XZ
    { 0x4BA070, 0x84C59AF2, 0x0000 }, // ??1UITextRoller@@UAE@XZ
    { 0x4BA0E0, 0x425F1EF4, 0x0000 }, // ?Init@UITextRoller@@QAEXPAULocString@@PAHMMMMVstring@@HHHHVCallback@@PAVUIMenu@@@Z
    { 0x4BA5B0, 0x9F29EB7C, 0x0000 }, // ?Update@UITextRoller@@UAEXXZ
    { 0x4BA610, 0x51424B7D, 0x0000 }, // ?Switch@UITextRoller@@UAEXH@Z
    { 0x4BA640, 0xA00BBBF8, 0x0000 }, // ?Action@UITextRoller@@UAEXTeqEvent@@@Z
    { 0x4BA720, 0x96BF08FB, 0x0000 }, // ?EvalMouseXY@UITextRoller@@QAEXMM@Z
    { 0x4BA8B0, 0x797A1069, 0x0000 }, // ?SetValue@UITextRoller@@QAEHH@Z
    { 0x4BA950, 0x4B127FEB, 0x0000 }, // ?SetString@UITextRoller@@QAEXVstring@@@Z
    { 0x4BAA20, 0x08B7CF13, 0x0000 }, // ?SetText@UITextRoller@@QAEXXZ
    { 0x4BAA90, 0x4BF8C055, 0x0000 }, // ?Inc@UITextRoller@@QAEHXZ
    { 0x4BAAB0, 0x6E188D37, 0x0000 }, // ?Dec@UITextRoller@@QAEHXZ
    { 0x4BAAD0, 0x392A3117, 0x0000 }, // ?Cull@UITextRoller@@UAEXXZ
    { 0x4BABB0, 0x391DB38E, 0x0000 }, // ??0UITextRoller2@@QAE@XZ
    { 0x4BAC60, 0x8455EFD2, 0x0000 }, // ??1UITextRoller2@@UAE@XZ
    { 0x4BACD0, 0x24C13C96, 0x0000 }, // ?Init@UITextRoller2@@QAEXPAULocString@@PAHMMMMVstring@@HHHHVCallback@@PAVUIMenu@@@Z
    { 0x4BB3C0, 0x1B2EBD30, 0x0000 }, // ?Update@UITextRoller2@@UAEXXZ
    { 0x4BB420, 0xF85D6707, 0x0000 }, // ?Switch@UITextRoller2@@UAEXH@Z
    { 0x4BB4C0, 0xF7AF52DE, 0x0000 }, // ?Action@UITextRoller2@@UAEXTeqEvent@@@Z
    { 0x4BB5A0, 0xEA90C9B3, 0x0000 }, // ?EvalMouseXY@UITextRoller2@@QAEXMM@Z
    { 0x4BB710, 0x8250C71E, 0x0000 }, // ?SetValue@UITextRoller2@@QAEHH@Z
    { 0x4BB7C0, 0xB3CC23F1, 0x0000 }, // ?SetString@UITextRoller2@@QAEXVstring@@@Z
    { 0x4BB890, 0x396BD524, 0x0000 }, // ?SetData@UITextRoller2@@QAEXPAH@Z
    { 0x4BB8B0, 0x8C799A4A, 0x0000 }, // ?SetText@UITextRoller2@@QAEXXZ
    { 0x4BB920, 0xEF2C3391, 0x0000 }, // ?Inc@UITextRoller2@@QAEHXZ
    { 0x4BB950, 0xFDD8DB6A, 0x0000 }, // ?Dec@UITextRoller2@@QAEHXZ
    { 0x4BB980, 0x58CDD1B2, 0x0000 }, // ?Cull@UITextRoller2@@UAEXXZ
    { 0x4BBA80, 0xB9366FA9, 0x0000 }, // ??0UIControlWidget@@QAE@XZ
    { 0x4BBBA0, 0x4E25EAC7, 0x0000 }, // ??1UIControlWidget@@UAE@XZ
    { 0x4BBC40, 0x9F61B644, 0x0000 }, // ?Init@UIControlWidget@@QAEXMMMMMPAVmmIO@@VCallback@@@Z
    { 0x4BBE00, 0xFFB097AD, 0x0000 }, // ?SetPosition@UIControlWidget@@QAEXMMMM@Z
    { 0x4BBEC0, 0x7F29750D, 0x0000 }, // ?Update@UIControlWidget@@UAEXXZ
    { 0x4BBEE0, 0xA042F3F7, 0x0000 }, // ?UpdateField@UIControlWidget@@QAEXXZ
    { 0x4BBF10, 0xAC82F191, 0x0000 }, // ?Action@UIControlWidget@@UAEXTeqEvent@@@Z
    { 0x4BBF60, 0x00EFBAF9, 0x0000 }, // ?Switch@UIControlWidget@@UAEXH@Z
    { 0x4BBFE0, 0x37F0493B, 0x0000 }, // ?EnableField@UIControlWidget@@QAEXXZ
    { 0x4BC050, 0x5D02171E, 0x0000 }, // ?DisableField@UIControlWidget@@QAEXXZ
    { 0x4BC0D0, 0x398C662D, 0x0000 }, // ?TurnOn@UIControlWidget@@UAEXXZ
    { 0x4BC0E0, 0x32E036F8, 0x0000 }, // ?TurnOff@UIControlWidget@@UAEXXZ
    { 0x4BC0F0, 0xF26C2C6E, 0x0000 }, // ??0UIIconW@@QAE@XZ
    { 0x4BC1B0, 0x1358AAD2, 0x0000 }, // ??1UIIconW@@UAE@XZ
    { 0x4BC220, 0x0B204A70, 0x0000 }, // ?Init@UIIconW@@QAEXPAULocString@@PADMMMMVCallback@@@Z
    { 0x4BC300, 0x29330978, 0x0000 }, // ?Action@UIIconW@@UAEXTeqEvent@@@Z
    { 0x4BC360, 0xCF93E4B8, 0x0000 }, // ?Update@UIIconW@@UAEXXZ
    { 0x4BC3E0, 0x79A9A686, 0x0000 }, // ?Switch@UIIconW@@UAEXH@Z
    { 0x4BC490, 0x72F3C8A2, 0x0000 }, // ??0UIToggleButton@@QAE@XZ
    { 0x4BC510, 0x71FDF76C, 0x0000 }, // ??1UIToggleButton@@UAE@XZ
    { 0x4BC580, 0xBFB7C6AF, 0x0000 }, // ?Init@UIToggleButton@@QAEXPAULocString@@PAHMMMMHHVCallback@@@Z
    { 0x4BC620, 0x3BC1EF7C, 0x0000 }, // ?DrawOff@UIToggleButton@@MAEXXZ
    { 0x4BC640, 0x75EF6B66, 0x0000 }, // ?DrawOn@UIToggleButton@@MAEXXZ
    { 0x4BC660, 0xCA51A953, 0x0000 }, // ?DoToggle@UIToggleButton@@UAEXXZ
    { 0x4BC680, 0xCC6D8FCF, 0x0000 }, // ?Action@UIToggleButton@@UAEXTeqEvent@@@Z
    { 0x4BC720, 0x7188B63B, 0x0000 }, // ?Update@UIToggleButton@@UAEXXZ
    { 0x4BC730, 0x6F752A1E, 0x0000 }, // ??0UIToggleButton2@@QAE@XZ
    { 0x4BC7B0, 0x5D978128, 0x0000 }, // ??1UIToggleButton2@@UAE@XZ
    { 0x4BC7C0, 0x84B337A2, 0x0000 }, // ?Init@UIToggleButton2@@QAEXPAULocString@@PAHMMMMHHVCallback@@@Z
    { 0x4BC890, 0x38A98191, 0x0000 }, // ?DrawOff@UIToggleButton2@@MAEXXZ
    { 0x4BC8D0, 0xE54DAAC0, 0x0000 }, // ?DrawOn@UIToggleButton2@@MAEXXZ
    { 0x4BC910, 0x2342BCE8, 0x0000 }, // ?Unkill@UIToggleButton2@@QAEXXZ
    { 0x4BC940, 0x25A5E3F8, 0x0000 }, // ?DoToggle@UIToggleButton2@@UAEXXZ
    { 0x4BC960, 0x46AC3639, 0x0000 }, // ?Action@UIToggleButton2@@UAEXTeqEvent@@@Z
    { 0x4BC9E0, 0xC03A1EE3, 0x0000 }, // ?Switch@UIToggleButton2@@UAEXH@Z
    { 0x4BCA80, 0x28D57853, 0x0000 }, // ?Update@UIToggleButton2@@UAEXXZ
    { 0x4BCA90, 0x32DDEFF2, 0x0000 }, // ?Enable@UIToggleButton2@@UAEXXZ
    { 0x4BCAA0, 0xB57A7897, 0x0000 }, // ?Disable@UIToggleButton2@@UAEXXZ
    { 0x4BCAB0, 0xA56AB040, 0x0000 }, // ??0UIMexButton@@QAE@XZ
    { 0x4BCB30, 0xC9D42F07, 0x0000 }, // ??1UIMexButton@@UAE@XZ
    { 0x4BCB40, 0x0E94F5F4, 0x0000 }, // ?Init@UIMexButton@@QAEXPAULocString@@PAHHMMMMHHVCallback@@@Z
    { 0x4BCC10, 0x7CC5E50F, 0x0000 }, // ?Update@UIMexButton@@UAEXXZ
    { 0x4BCC60, 0x60BA2C2B, 0x0000 }, // ?DrawOff@UIMexButton@@EAEXXZ
    { 0x4BCC70, 0xF4128DD2, 0x0000 }, // ?DrawOn@UIMexButton@@EAEXXZ
    { 0x4BCCA0, 0xAE04DC77, 0x0000 }, // ?DoToggle@UIMexButton@@UAEXXZ
    { 0x4BCCC0, 0x50F1AC17, 0x0000 }, // ?Action@UIMexButton@@UAEXTeqEvent@@@Z
    { 0x4BCD60, 0xC8094412, 0x0000 }, // ??0UIVScrollBar@@QAE@XZ
    { 0x4BCE00, 0x90353112, 0x0000 }, // ??1UIVScrollBar@@UAE@XZ
    { 0x4BCE90, 0xCAC072A7, 0x0000 }, // ?Init@UIVScrollBar@@QAEXMMMMHMMPAHVCallback@@H@Z
    { 0x4BCF00, 0x55CCCD3B, 0x0000 }, // ?LoadBitmap@UIVScrollBar@@QAEXXZ
    { 0x4BD030, 0xA22E9C21, 0x0000 }, // ?SetHotSpots@UIVScrollBar@@QAEXXZ
    { 0x4BD0F0, 0x98E40357, 0x0000 }, // ?Inc@UIVScrollBar@@QAEMXZ
    { 0x4BD150, 0x1C11E80D, 0x0000 }, // ?Dec@UIVScrollBar@@QAEMXZ
    { 0x4BD1B0, 0x04D16DD9, 0x0000 }, // ?SetStep@UIVScrollBar@@QAEXHM@Z
    { 0x4BD210, 0x097845E1, 0x0000 }, // ?SetRange@UIVScrollBar@@QAEXMM@Z
    { 0x4BD280, 0x92D8C135, 0x0000 }, // ?SetTrough@UIVScrollBar@@QAEXMM@Z
    { 0x4BD300, 0xFD418A99, 0x0000 }, // ?Update@UIVScrollBar@@UAEXXZ
    { 0x4BD320, 0xB02806A0, 0x0000 }, // ?Switch@UIVScrollBar@@UAEXH@Z
    { 0x4BD370, 0x591638AF, 0x0000 }, // ?Action@UIVScrollBar@@UAEXTeqEvent@@@Z
    { 0x4BD430, 0xFCA08D47, 0x0000 }, // ?EvalMouseXY@UIVScrollBar@@QAEXMM@Z
    { 0x4BD5B0, 0x7E3F8440, 0x0000 }, // ?Cull@UIVScrollBar@@UAEXXZ
    { 0x4BD730, 0x06E9E9C8, 0x0000 }, // ?DeclareFields@UIVScrollBar@@SAXXZ
    { 0x4BD8A0, 0xE2DEDF04, 0x0000 }, // ?GetClass@UIVScrollBar@@UAEPAVMetaClass@@XZ
    { 0x4BD910, 0xEDC14FA5, 0x0000 }, // ?SetPosition@UIVScrollBar@@UAEXMM@Z
    { 0x4BD930, 0xBC51930F, 0x0000 }, // ?Enable@UIVScrollBar@@UAEXXZ
    { 0x4BD950, 0x7BDFB18B, 0x0000 }, // ?Disable@UIVScrollBar@@UAEXXZ
    { 0x4BD970, 0x504B26B2, 0x0000 }, // ??0sfPointer@@QAE@XZ
    { 0x4BD9A0, 0x5F348445, 0x0000 }, // ??1sfPointer@@UAE@XZ
    { 0x4BDA00, 0x4EF00E3D, 0x0000 }, // ?Init@sfPointer@@QAEXXZ
    { 0x4BDA20, 0x062DBF65, 0x0000 }, // ?ResChange@sfPointer@@UAEXHH@Z
    { 0x4BDA80, 0xCC08F23C, 0x0000 }, // ?GetPointerHeight@sfPointer@@QAEMXZ
    { 0x4BDA90, 0x1B4BED1B, 0x0000 }, // ?Update@sfPointer@@UAEXXZ
    { 0x4BDD10, 0xA21F95CA, 0x0000 }, // ?UpdateAttached@sfPointer@@AAEXXZ
    { 0x4BDD20, 0xFCBC0DD9, 0x0000 }, // ?WaitForRelease@sfPointer@@QAEXXZ
    { 0x4BDD30, 0x867013E1, 0x0000 }, // ?Cull@sfPointer@@UAEXXZ
    { 0x4BDDB0, 0x5BBBFB7D, 0x0000 }, // ?DeclareFields@sfPointer@@SAXXZ
    { 0x4BDF20, 0x579DB57F, 0x0000 }, // ?GetClass@sfPointer@@UAEPAVMetaClass@@XZ
    { 0x4BDF90, 0xE771C2EB, 0x0000 }, // ??0TextDropWidget@@QAE@XZ
    { 0x4BE040, 0x8420D554, 0x0000 }, // ??1TextDropWidget@@UAE@XZ
    { 0x4BE0B0, 0x526AA62A, 0x0000 }, // ?Init@TextDropWidget@@QAEXPAVasCamera@@PAXMMMMMVstring@@H@Z
    { 0x4BE1A0, 0x8F0DE026, 0x0000 }, // ?GetCount@TextDropWidget@@QAEHXZ
    { 0x4BE1B0, 0x81F41DA2, 0x0000 }, // ?SetString@TextDropWidget@@QAEXVstring@@@Z
    { 0x4BE270, 0xF7ED8D06, 0x0000 }, // ?SetValue@TextDropWidget@@QAEHH@Z
    { 0x4BE310, 0x83AD89D9, 0x0000 }, // ?SetHighlight@TextDropWidget@@QAEHH@Z
    { 0x4BE380, 0x5B56C448, 0x0000 }, // ?Inc@TextDropWidget@@QAEHXZ
    { 0x4BE390, 0xE563CB8E, 0x0000 }, // ?Dec@TextDropWidget@@QAEHXZ
    { 0x4BE3A0, 0x412DCFD7, 0x0000 }, // ?IncDrop@TextDropWidget@@QAEHXZ
    { 0x4BE3D0, 0xAB0E7FB5, 0x0000 }, // ?DecDrop@TextDropWidget@@QAEHXZ
    { 0x4BE400, 0xB4BB877A, 0x0000 }, // ?Capture@TextDropWidget@@QAEHMM@Z
    { 0x4BE440, 0x6B89E37B, 0x0000 }, // ?Switch@TextDropWidget@@QAEXHAAVVector4@@@Z
    { 0x4BE460, 0xB28F1CC1, 0x0000 }, // ?Update@TextDropWidget@@UAEXXZ
    { 0x4BE470, 0x40294936, 0x0000 }, // ?IsActive@TextDropWidget@@QAEHXZ
    { 0x4BE480, 0x62007D80, 0x0000 }, // ?SetActive@TextDropWidget@@QAEXH@Z
    { 0x4BE490, 0x518023B1, 0x0000 }, // ?SetDisabledMask@TextDropWidget@@QAEXJ@Z
    { 0x4BE4B0, 0xA5CFCC00, 0x0000 }, // ?GetDisabledMask@TextDropWidget@@QAEJXZ
    { 0x4BE4C0, 0xE2E6F1E4, 0x0000 }, // ?DeclareFields@TextDropWidget@@SAXXZ
    { 0x4BE630, 0x02ACC2B1, 0x0000 }, // ?GetClass@TextDropWidget@@UAEPAVMetaClass@@XZ
    { 0x4BE6A0, 0x19FA8A7F, 0x0000 }, // ??0mmSlider@@QAE@XZ
    { 0x4BE730, 0xE3030D7E, 0x0000 }, // ??1mmSlider@@UAE@XZ
    { 0x4BE7D0, 0x3869A124, 0x0000 }, // ?Init@mmSlider@@QAEXPADPAVuiWidget@@MMMMHMMHH@Z
    { 0x4BE830, 0xA48FDD9F, 0x0000 }, // ?LoadBitmap@mmSlider@@QAEXPAD@Z
    { 0x4BE9E0, 0x0668F334, 0x0000 }, // ?SetReadWrite@mmSlider@@QAEXH@Z
    { 0x4BEA00, 0x01BC6769, 0x0000 }, // ?IsReadWrite@mmSlider@@QAEHXZ
    { 0x4BEA10, 0x21664960, 0x0000 }, // ?SetValue@mmSlider@@QAEMM@Z
    { 0x4BEA70, 0x25335D44, 0x0000 }, // ?GetScreenHeight@mmSlider@@QAEMXZ
    { 0x4BEAA0, 0x0F951886, 0x0000 }, // ?FudgeWidth@mmSlider@@QAEMXZ
    { 0x4BEAD0, 0xC39DFEA1, 0x0000 }, // ?SetPosition@mmSlider@@QAEXMM@Z
    { 0x4BEAF0, 0xECE3D792, 0x0000 }, // ?GetSliderHotSpots@mmSlider@@QAEXAAM00000@Z
    { 0x4BEBC0, 0xC03DC1E3, 0x0000 }, // ?UpdatePosition@mmSlider@@QAEXXZ
    { 0x4BEBF0, 0x9326771F, 0x0000 }, // ?Inc@mmSlider@@QAEMXZ
    { 0x4BEC10, 0xFF9F6356, 0x0000 }, // ?Dec@mmSlider@@QAEMXZ
    { 0x4BEC30, 0x9824E5B5, 0x0000 }, // ?SetStep@mmSlider@@QAEXM@Z
    { 0x4BECB0, 0xD6DC9250, 0x0000 }, // ?SetRange@mmSlider@@QAEXMM@Z
    { 0x4BED20, 0x203345F6, 0x0000 }, // ?Update@mmSlider@@UAEXXZ
    { 0x4BED40, 0xC72DE7D9, 0x0000 }, // ?Cull@mmSlider@@UAEXXZ
    { 0x4BEF00, 0xB5D7E618, 0x0000 }, // ?DeclareFields@mmSlider@@SAXXZ
    { 0x4BF070, 0x950C5787, 0x0000 }, // ?GetClass@mmSlider@@UAEPAVMetaClass@@XZ
    { 0x4BF0E0, 0xB30C9B27, 0x0000 }, // ??0mmToolTip@@QAE@XZ
    { 0x4BF150, 0xBCDB55E5, 0x0000 }, // ??1mmToolTip@@UAE@XZ
    { 0x4BF1B0, 0x12C9DC02, 0x0000 }, // ?Init@mmToolTip@@QAEXPAVUIMenu@@PAULocString@@@Z
    { 0x4BF260, 0xB9617C3D, 0x0000 }, // ?SetText@mmToolTip@@QAEXPAULocString@@@Z
    { 0x4BF280, 0x11887C28, 0x0000 }, // ?Switch@mmToolTip@@QAEXH@Z
    { 0x4BF290, 0x755B8A95, 0x0000 }, // ?Update@mmToolTip@@UAEXXZ
    { 0x4BF2D0, 0x6EC48240, 0x0000 }, // ?Reset@mmCompBase@@UAEXXZ
    { 0x4BF2E0, 0x4450203E, 0x0000 }, // ?Update@mmCompBase@@UAEXXZ
    { 0x4BF2F0, 0x695D718A, 0x0000 }, // ??0VSWidget@@QAE@XZ
    { 0x4BF370, 0xC500FB35, 0x0000 }, // ??1VSWidget@@UAE@XZ
    { 0x4BF3F0, 0x1FE5EC92, 0x0000 }, // ?Init@VSWidget@@QAEXMMMMPAHVCallback@@H@Z
    { 0x4BF450, 0x128C6B3E, 0x0000 }, // ?LoadBitmap@VSWidget@@QAEXXZ
    { 0x4BF5A0, 0x449268CB, 0x0000 }, // ?CalcTroughRatio@VSWidget@@QAEXM@Z
    { 0x4BF620, 0x931C8ED4, 0x0000 }, // ?SetHotSpots@VSWidget@@QAEXXZ
    { 0x4BF6D0, 0x288180CF, 0x0000 }, // ?SyncData@VSWidget@@QAEXXZ
    { 0x4BF710, 0xE83EBB15, 0x0000 }, // ?Inc@VSWidget@@QAEMXZ
    { 0x4BF770, 0xD0DE4F66, 0x0000 }, // ?Dec@VSWidget@@QAEMXZ
    { 0x4BF7D0, 0xA50499B0, 0x0000 }, // ?SetStep@VSWidget@@QAEXHM@Z
    { 0x4BF840, 0x930DA0BF, 0x0000 }, // ?SetTrough@VSWidget@@QAEXM@Z
    { 0x4BF8D0, 0x85C80D60, 0x0000 }, // ?Update@VSWidget@@UAEXXZ
    { 0x4BF900, 0x672F5B66, 0x0000 }, // ?Switch@VSWidget@@QAEXHMM@Z
    { 0x4BF950, 0x1925090B, 0x0000 }, // ?Action@VSWidget@@QAEHTeqEvent@@MMH@Z
    { 0x4BFA00, 0xE1E4C18D, 0x0000 }, // ?EvalMouseXY@VSWidget@@QAEXMMH@Z
    { 0x4BFBB0, 0x2264C8A5, 0x0000 }, // ?Cull@VSWidget@@UAEXXZ
    { 0x4BFD30, 0xA56D651C, 0x0000 }, // ?DeclareFields@VSWidget@@SAXXZ
    { 0x4BFEA0, 0x942E9977, 0x0000 }, // ?GetClass@VSWidget@@UAEPAVMetaClass@@XZ
    { 0x4BFF10, 0x5A541803, 0x0000 }, // ??0mmToggle2@@QAE@XZ
    { 0x4BFF30, 0xAC388EC9, 0x0000 }, // ??1mmToggle2@@UAE@XZ
    { 0x4BFF90, 0x6C8238E7, 0x0000 }, // ?Init@mmToggle2@@QAEXPADMMPAH@Z
    { 0x4BFFC0, 0x15153B5C, 0x0000 }, // ?LoadBitmap@mmToggle2@@AAEXPAD@Z
    { 0x4C0020, 0x4779E65D, 0x0000 }, // ?SetPosition@mmToggle2@@QAEXMM@Z
    { 0x4C00C0, 0x4F9C7F24, 0x0000 }, // ?Update@mmToggle2@@UAEXXZ
    { 0x4C00E0, 0xD5165495, 0x0000 }, // ?Cull@mmToggle2@@UAEXXZ
    { 0x4C01A0, 0x8AE384FC, 0x0000 }, // ?DeclareFields@mmToggle2@@SAXXZ
    { 0x4C0300, 0x21C79F22, 0x0000 }, // ?GetClass@mmToggle2@@UAEPAVMetaClass@@XZ
    { 0x4C0370, 0x06B0FBC8, 0x0000 }, // ??0mmToggle@@QAE@XZ
    { 0x4C0390, 0x02693492, 0x0000 }, // ??1mmToggle@@UAE@XZ
    { 0x4C03F0, 0x8C577AA5, 0x0000 }, // ?Init@mmToggle@@QAEXPADMMMM@Z
    { 0x4C0490, 0x8BE388B8, 0x0000 }, // ?LoadBitmap@mmToggle@@AAEXPAD@Z
    { 0x4C04E0, 0x0EF5FE3D, 0x0000 }, // ?SetSize@mmToggle@@AAEXMM@Z
    { 0x4C0590, 0x69612F2B, 0x0000 }, // ?Update@mmToggle@@UAEXXZ
    { 0x4C05B0, 0xC95965AE, 0x0000 }, // ?Cull@mmToggle@@UAEXXZ
    { 0x4C0630, 0x2F6C0E4E, 0x0000 }, // ?DeclareFields@mmToggle@@SAXXZ
    { 0x4C07A0, 0x8A6FE46C, 0x0000 }, // ?GetClass@mmToggle@@UAEPAVMetaClass@@XZ
    { 0x4C0810, 0x5F4F88C7, 0x0000 }, // ??0mmDropDown@@QAE@XZ
    { 0x4C0870, 0x3F90E9CA, 0x0000 }, // ??1mmDropDown@@UAE@XZ
    { 0x4C08F0, 0x8024A964, 0x0000 }, // ?Init@mmDropDown@@QAEXPAVasCamera@@PAXMMMMVstring@@H@Z
    { 0x4C09F0, 0xA23EF93F, 0x0000 }, // ?InitString@mmDropDown@@QAEXVstring@@@Z
    { 0x4C0C70, 0x5964254E, 0x0000 }, // ?SetString@mmDropDown@@AAEXVstring@@@Z
    { 0x4C0D60, 0x1EBAF34B, 0x0000 }, // ?GetCurrentString@mmDropDown@@QAEXPADH@Z
    { 0x4C0DB0, 0x14B16C10, 0x0000 }, // ?SetDisabledColors@mmDropDown@@QAEXXZ
    { 0x4C0E30, 0x2BE96478, 0x0000 }, // ?FindFirstEnabled@mmDropDown@@QAEHXZ
    { 0x4C0E60, 0x817DDCE6, 0x0000 }, // ?SetHighlight@mmDropDown@@QAEXH@Z
    { 0x4C0EC0, 0xB0236E3C, 0x0000 }, // ?GetHit@mmDropDown@@QAEHMM@Z
    { 0x4C0F20, 0x4D829948, 0x0000 }, // ?Update@mmDropDown@@UAEXXZ
    { 0x4C0F30, 0x9FE59224, 0x0000 }, // ?DeclareFields@mmDropDown@@SAXXZ
    { 0x4C10A0, 0x32554A9F, 0x0000 }, // ?GetClass@mmDropDown@@UAEPAVMetaClass@@XZ
    { 0x4C1110, 0x58892A39, 0x0000 }, // ??0mmAnimMgr@@QAE@XZ
    { 0x4C1190, 0x913D526E, 0x0000 }, // ??1mmAnimMgr@@UAE@XZ
    { 0x4C11F0, 0x80829266, 0x0000 }, // ?Init@mmAnimMgr@@QAEHPADPAVmmInstance@@PAPAV2@H@Z
    { 0x4C13A0, 0x2E387EA8, 0x0000 }, // ?Update@mmAnimMgr@@UAEXXZ
    { 0x4C13B0, 0x1B4D85B1, 0x0000 }, // ?TestDOFAct@mmAnimMgr@@QAEXH@Z
    { 0x4C13C0, 0x220D7FED, 0x0000 }, // ?AirlinerSwap@mmAnimMgr@@QAEXXZ
    { 0x4C1400, 0x05A28F62, 0x0000 }, // ?UFOSwap@mmAnimMgr@@QAEXXZ
    { 0x4C1440, 0xED07B5D9, 0x0000 }, // ?DeclareFields@mmAnimMgr@@SAXXZ
    { 0x4C15B0, 0x870E0227, 0x0000 }, // ?GetClass@mmAnimMgr@@UAEPAVMetaClass@@XZ
    { 0x4C16B0, 0x7111B613, 0x0000 }, // ??0mmBridgeMgr@@QAE@XZ
    { 0x4C17C0, 0x7D7FC5E8, 0x0000 }, // ??1mmBridgeMgr@@UAE@XZ
    { 0x4C1850, 0xE6A78057, 0x0000 }, // ?ToggleDrawLabels@mmBridgeMgr@@QAEXXZ
    { 0x4C1860, 0xB104C7CE, 0x0000 }, // ?Cull@mmBridgeMgr@@UAEXXZ
    { 0x4C18A0, 0x235BEEFC, 0x0000 }, // ?Init@mmBridgeMgr@@QAEXPADPAVmmInstance@@PAPAV2@H@Z
    { 0x4C1CC0, 0x746BC4A0, 0x0000 }, // ?Save@mmBridgeMgr@@UAEXXZ
    { 0x4C1CD0, 0xAF596622, 0x0000 }, // ?AddWidgets@mmBridgeMgr@@UAEXPAVBank@@@Z
    { 0x4C1F00, 0xA5F1277D, 0x0000 }, // ??0mmBridgeSet@@QAE@XZ
    { 0x4C2010, 0xA80A2B76, 0x0000 }, // ??1mmBridgeSet@@UAE@XZ
    { 0x4C2080, 0x35E9650E, 0x0000 }, // ?Reset@mmBridgeSet@@UAEXXZ
    { 0x4C2150, 0x4D8C7F94, 0x0000 }, // ?ReadEntry@mmBridgeSet@@QAEHPAVStream@@H@Z
    { 0x4C2290, 0x4E3BD427, 0x0000 }, // ?InitTrigger@mmBridgeSet@@QAEXXZ
    { 0x4C22C0, 0x6D7A4B02, 0x0000 }, // ?Init@mmBridgeSet@@QAEHPADPAVStream@@@Z
    { 0x4C2380, 0x6E9C20C9, 0x0000 }, // ?Update@mmBridgeSet@@UAEXXZ
    { 0x4C2730, 0x7A0AE33F, 0x0000 }, // ?Cull@mmBridgeSet@@UAEXXZ
    { 0x4C27D0, 0x2B720B96, 0x0000 }, // ?AddWidgets@mmBridgeSet@@UAEXPAVBank@@@Z
    { 0x4C29A0, 0xCE20F4CC, 0x0000 }, // ?DeclareFields@mmBridgeSet@@SAXXZ
    { 0x4C2A40, 0x708813B3, 0x0000 }, // ?UpdateAudio@mmBridgeSet@@QAEXXZ
    { 0x4C2CA0, 0x304F72A3, 0x0000 }, // ?CalculateDistToPlayer2@mmBridgeSet@@AAEXXZ
    { 0x4C2D80, 0x206755C3, 0x0000 }, // ?CalculateAudioPanning@mmBridgeSet@@AAEXXZ
    { 0x4C2DD0, 0xF00A0303, 0x0000 }, // ?CalculateDoppler@mmBridgeSet@@AAEMM@Z
    { 0x4C2E00, 0x367D701D, 0x0000 }, // ?UnAssignSounds@mmBridgeSet@@QAEXXZ
    { 0x4C2E20, 0x7054B881, 0x0000 }, // ?SetSoundPtrs@mmBridgeSet@@QAEXPAVAudSound@@0@Z
    { 0x4C2E80, 0x0C67234C, 0x0000 }, // ?RampDownBridgeVolume@mmBridgeSet@@AAEXXZ
    { 0x4C3060, 0x64D190AE, 0x0000 }, // ?GetClass@mmBridgeSet@@UAEPAVMetaClass@@XZ
    { 0x4C3070, 0x77BDBBDB, 0x0000 }, // ?DeclareFields@mmBridgeMgr@@SAXXZ
    { 0x4C32E0, 0x37F0C36F, 0x0000 }, // ?GetClass@mmBridgeMgr@@UAEPAVMetaClass@@XZ
    { 0x4C34D0, 0x8A24AAB1, 0x0000 }, // ??0mmAnimExcel@@QAE@XZ
    { 0x4C34F0, 0x82E8A152, 0x0000 }, // ??1mmAnimExcel@@UAE@XZ
    { 0x4C3530, 0x6A8E1D5C, 0x0000 }, // ?Init@mmAnimExcel@@QAEHPAD0@Z
    { 0x4C35C0, 0x6B8CFD0E, 0x0000 }, // ?GetNextName@mmAnimExcel@@QAEPADXZ
    { 0x4C3600, 0x792EDCC5, 0x0000 }, // ?AddFile@mmAnimExcel@@QAEXPAD0@Z
    { 0x4C3740, 0x17D212FC, 0x0000 }, // ?GetPriorName@mmAnimExcel@@QAEPADXZ
    { 0x4C3770, 0x5EA75B0F, 0x0000 }, // ?GetName@mmAnimExcel@@QAEPADH@Z
    { 0x4C37D0, 0x92F89652, 0x0000 }, // ??0mmAnimSpline@@QAE@XZ
    { 0x4C37F0, 0x28BCE271, 0x0000 }, // ??1mmAnimSpline@@UAE@XZ
    { 0x4C3850, 0x96A4321B, 0x0000 }, // ?Init@mmAnimSpline@@QAEHPADH@Z
    { 0x4C38F0, 0xC583908D, 0x0000 }, // ?LoadFile@mmAnimSpline@@QAEHPAD@Z
    { 0x4C39D0, 0xB064BE8D, 0x0000 }, // ?ClearVectors@mmAnimSpline@@QAEXXZ
    { 0x4C39F0, 0xD890A19F, 0x0000 }, // ?AddVector@mmAnimSpline@@QAEXAAVVector3@@@Z
    { 0x4C3A90, 0x48B6CEF6, 0x0000 }, // ?InitBoat@mmAnimSpline@@QAEHXZ
    { 0x4C3AA0, 0x261C06B7, 0x0000 }, // ?InitPlane@mmAnimSpline@@QAEHXZ
    { 0x4C3B40, 0x687AE1F9, 0x0000 }, // ?InitTrain@mmAnimSpline@@QAEHXZ
    { 0x4C3BC0, 0x59B1A7E9, 0x0000 }, // ?Update@mmAnimSpline@@UAEXXZ
    { 0x4C3BF0, 0x3B8272C1, 0x0000 }, // ?Reset@mmAnimSpline@@UAEXXZ
    { 0x4C3C10, 0xEBB00445, 0x0000 }, // ?AirlinerSwap@mmAnimSpline@@QAEXXZ
    { 0x4C3CC0, 0x8A235398, 0x0000 }, // ?UFOSwap@mmAnimSpline@@QAEXXZ
    { 0x4C3D10, 0x6B156CA7, 0x0000 }, // ??0mmBridgeAudMgr@@QAE@XZ
    { 0x4C3EC0, 0x5614FA5A, 0x0000 }, // ??1mmBridgeAudMgr@@UAE@XZ
    { 0x4C3F80, 0xF26C8C64, 0x0000 }, // ?Add@mmBridgeAudMgr@@QAEFPAVmmBridgeSet@@@Z
    { 0x4C4010, 0xC007D4C0, 0x0000 }, // ?Remove@mmBridgeAudMgr@@QAEXPAVmmBridgeSet@@F@Z
    { 0x4C4070, 0x8ED437E7, 0x0000 }, // ?FindGreatestDistance@mmBridgeAudMgr@@QAEFPAVmmBridgeSet@@@Z
    { 0x4C4110, 0x3E9D5071, 0x0000 }, // ?FindUnusedSlot@mmBridgeAudMgr@@QAEFXZ
    { 0x4C4150, 0xDDEC8824, 0x0000 }, // ?Update@mmBridgeAudMgr@@UAEXXZ
    { 0x4C4180, 0x490579DB, 0x0000 }, // ?AssignSounds@mmBridgeAudMgr@@QAEXF@Z
    { 0x4C41E0, 0xA83C627C, 0x0000 }, // ??0mmAnimTrigger@@QAE@XZ
    { 0x4C41F0, 0x077EEEBF, 0x0000 }, // ??1mmAnimTrigger@@QAE@XZ
    { 0x4C4200, 0xA031104C, 0x0000 }, // ?Init@mmAnimTrigger@@QAEXPAVmmInstance@@H@Z
    { 0x4C4220, 0x30C688A0, 0x0000 }, // ?Init@mmAnimTrigger@@QAEXPAVVector3@@PAM@Z
    { 0x4C4240, 0x749A9A53, 0x0000 }, // ?Init@mmAnimTrigger@@QAEXPAHM@Z
    { 0x4C4270, 0x6BBBD9C5, 0x0000 }, // ?Init@mmAnimTrigger@@QAEXM@Z
    { 0x4C4290, 0x8E603A47, 0x0000 }, // ?CheckCondition@mmAnimTrigger@@QAEHXZ
    { 0x4C4300, 0xA9E4A9B7, 0x0000 }, // ?CheckObjectHit@mmAnimTrigger@@QAEHXZ
    { 0x4C4320, 0xB3D0C616, 0x0000 }, // ?CheckTimeDelay@mmAnimTrigger@@QAEHXZ
    { 0x4C4350, 0x13674DDA, 0x0000 }, // ?CheckStateStatus@mmAnimTrigger@@QAEHXZ
    { 0x4C43A0, 0x37DA2DD1, 0x0000 }, // ?Reset@mmAnimTrigger@@QAEXXZ
    { 0x4C43B0, 0x8879E7D6, 0x0000 }, // ?CheckObjectDistance@mmAnimTrigger@@QAEHXZ
    { 0x4C4460, 0x62C6EE16, 0x0000 }, // ?Draw@mmDrawbridgeInstance@@UAIXH@Z
    { 0x4C4510, 0x85F29B86, 0x0000 }, // ?InitBridge@mmDrawbridgeInstance@@QAEHPAD0HPAVMatrix34@@PAVVector3@@@Z
    { 0x4C4550, 0x001D9341, 0x0000 }, // ??0mmAnimDOF@@QAE@XZ
    { 0x4C4570, 0x7B913524, 0x0000 }, // ??1mmAnimDOF@@QAE@XZ
    { 0x4C4580, 0x0F78C7AE, 0x0000 }, // ?Init@mmAnimDOF@@QAEHPAVmmAnimTrigger@@PADAAVVector3@@2HPAH@Z
    { 0x4C4900, 0x16B0B7B8, 0x0000 }, // ?Reset@mmAnimDOF@@QAEXXZ
    { 0x4C4940, 0xB2DF4516, 0x0000 }, // ?Update@mmAnimDOF@@QAEXXZ
    { 0x4C4B60, 0x99D21218, 0x0000 }, // ?SetSwitch@mmAnimDOF@@QAEXH@Z
    { 0x4C4BB0, 0x1A2887CA, 0x0000 }, // ?SetState@mmAnimDOF@@QAEXH@Z
    { 0x4C4BF0, 0xC404B8D4, 0x0000 }, // ?DeclareFields@mmAnimDOF@@SAXXZ
    { 0x4C4D80, 0xF83CB51D, 0x0000 }, // ?GetClass@mmAnimDOF@@UAEPAVMetaClass@@XZ
    { 0x4C4DB0, 0x35E84A86, 0x0000 }, // ??1mmDrawbridgeInstance@@UAE@XZ
    { 0x4C4E20, 0x8C1311D2, 0x0000 }, // ??0mmUnhitBangerInstance@@QAE@XZ
    { 0x4C4E50, 0xD480BEFE, 0x0000 }, // ?FromMatrix@mmDofBangerInstance@@UAIXABVMatrix34@@@Z
    { 0x4C4E60, 0x8E477A07, 0x0000 }, // ?ToMatrix@mmDofBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x4C4E90, 0x8258B168, 0x0000 }, // ?GetPos@mmDofBangerInstance@@UAIAAVVector3@@XZ
    { 0x4C4EE0, 0x108D48AC, 0x0000 }, // ??1mmDofBangerInstance@@UAE@XZ
    { 0x4C4F20, 0x5B4F21BB, 0x0000 }, // ??0mmAnimPlane@@QAE@XZ
    { 0x4C5010, 0x65DF6EFB, 0x0000 }, // ??1mmAnimPlane@@UAE@XZ
    { 0x4C50C0, 0xC45D968B, 0x0000 }, // ?Init@mmAnimPlane@@QAEXHPAD0PAVVector3@@HHPAM@Z
    { 0x4C52C0, 0xB92D4EA6, 0x0000 }, // ?Reset@mmAnimPlane@@UAEXXZ
    { 0x4C5330, 0xC1EBD2E5, 0x0000 }, // ?Activate@mmAnimPlane@@QAEXXZ
    { 0x4C5340, 0x92838EBC, 0x0000 }, // ?Deactivate@mmAnimPlane@@QAEXXZ
    { 0x4C5350, 0x539D3977, 0x0000 }, // ?Update@mmAnimPlane@@QAEXXZ
    { 0x4C5370, 0xA089658D, 0x0000 }, // ?UpdatePathPosition@mmAnimPlane@@QAEXXZ
    { 0x4C5540, 0x082D771C, 0x0000 }, // ?SetPathSpeed@mmAnimPlane@@QAEXXZ
    { 0x4C5550, 0x0593ADCA, 0x0000 }, // ?ReverseCalcPathSpeed@mmAnimPlane@@QAEXXZ
    { 0x4C5560, 0x0BBAFBA8, 0x0000 }, // ?SolvePosition@mmAnimPlane@@QAEXAAVVector3@@AAM@Z
    { 0x4C5630, 0xD6923E9C, 0x0000 }, // ?AdjustPhaseOffsets@mmAnimPlane@@QAEXXZ
    { 0x4C56A0, 0xF0153687, 0x0000 }, // ?PreCalcCubics@mmAnimPlane@@QAEXXZ
    { 0x4C5770, 0x8ACD8CD9, 0x0000 }, // ?CalculateCubics@mmAnimPlane@@QAEXHAAVVector4@@00@Z
    { 0x4C58F0, 0x6067E856, 0x0000 }, // ?SolveVector@mmAnimPlane@@QAEXMAAVVector3@@0@Z
    { 0x4C5A70, 0x1C8C90FE, 0x0000 }, // ?Draw@mmAnimPlane@@UAIXH@Z
    { 0x4C5AC0, 0x92BEACDF, 0x0000 }, // ?UpdateAudio@mmAnimPlane@@AAEXXZ
    { 0x4C5C20, 0x99649EC0, 0x0000 }, // ?CalculateDistToPlayer2@mmAnimPlane@@AAEXXZ
    { 0x4C5CF0, 0x502B8BC3, 0x0000 }, // ?CalculateAudioPanning@mmAnimPlane@@AAEXXZ
    { 0x4C5D40, 0x739C8766, 0x0000 }, // ?CalculateDoppler@mmAnimPlane@@AAEMM@Z
    { 0x4C5F20, 0x96D4BF17, 0x0000 }, // ??0mmAnimTrain@@QAE@XZ
    { 0x4C6010, 0x8EEAD453, 0x0000 }, // ??1mmAnimTrain@@QAE@XZ
    { 0x4C6080, 0x1CAC5095, 0x0000 }, // ?Init@mmAnimTrain@@QAEXHPAD0PAVVector3@@HHPAM@Z
    { 0x4C6350, 0x5940C162, 0x0000 }, // ?Reset@mmAnimTrain@@QAEXXZ
    { 0x4C63C0, 0x9B4FD37E, 0x0000 }, // ?Update@mmAnimTrain@@QAEXXZ
    { 0x4C6460, 0x85630863, 0x0000 }, // ?UpdatePathPosition@mmAnimTrain@@QAEXXZ
    { 0x4C65B0, 0x80D4B1C4, 0x0000 }, // ?SetPathSpeed@mmAnimTrain@@QAEXXZ
    { 0x4C65C0, 0x10B6ECEA, 0x0000 }, // ?ReverseCalcPathSpeed@mmAnimTrain@@QAEXXZ
    { 0x4C65D0, 0x0D4276B0, 0x0000 }, // ?SolvePosition@mmAnimTrain@@QAEXAAVVector3@@AAM@Z
    { 0x4C66D0, 0xE752AB57, 0x0000 }, // ?AdjustPhaseOffsets@mmAnimTrain@@QAEXXZ
    { 0x4C6740, 0xD68EBD16, 0x0000 }, // ?GetStart@mmAnimTrain@@QAEXMAAHAAM@Z
    { 0x4C67C0, 0xCB8C5E9E, 0x0000 }, // ?PreCalcCubics@mmAnimTrain@@QAEXXZ
    { 0x4C6890, 0x61BE369E, 0x0000 }, // ?CalculateCubics@mmAnimTrain@@QAEXHAAVVector4@@00@Z
    { 0x4C6A90, 0x146B1FA4, 0x0000 }, // ?ComputeXZCurve@mmAnimTrain@@QAEXAAVVector3@@000AAVVector4@@11@Z
    { 0x4C6B70, 0x0F93F86F, 0x0000 }, // ?SolveXZCurve@mmAnimTrain@@QAEXAAVVector3@@0M@Z
    { 0x4C6CA0, 0x3C0654C2, 0x0000 }, // ?UpdateAudio@mmAnimTrain@@AAEXXZ
    { 0x4C6E00, 0x17AA45E7, 0x0000 }, // ?CalculateDistToPlayer2@mmAnimTrain@@AAEXXZ
    { 0x4C6ED0, 0x7122C0EE, 0x0000 }, // ?CalculateAudioPanning@mmAnimTrain@@AAEXXZ
    { 0x4C6F20, 0xB6370400, 0x0000 }, // ?CalculateDoppler@mmAnimTrain@@AAEMM@Z
    { 0x4C7120, 0x0EDBAFF4, 0x0000 }, // ??0mmBoat@@QAE@XZ
    { 0x4C7200, 0x9DD135DE, 0x0000 }, // ??1mmBoat@@UAE@XZ
    { 0x4C7270, 0x9BB3850F, 0x0000 }, // ?Init@mmBoat@@QAEXHPAD0PAVVector3@@HHPAM@Z
    { 0x4C7570, 0x1965E3E0, 0x0000 }, // ?Reset@mmBoat@@UAEXXZ
    { 0x4C75D0, 0x5C04D50E, 0x0000 }, // ?Update@mmBoat@@UAEXXZ
    { 0x4C7600, 0x5FE84AC7, 0x0000 }, // ?UpdatePathPosition@mmBoat@@QAEXXZ
    { 0x4C7650, 0x684E85CB, 0x0000 }, // ?SetPathSpeed@mmBoat@@QAEXXZ
    { 0x4C7670, 0x818C150B, 0x0000 }, // ?SetRock@mmBoat@@QAEXMM@Z
    { 0x4C76A0, 0x60FB611C, 0x0000 }, // ?ReverseCalcPathSpeed@mmBoat@@QAEXXZ
    { 0x4C76C0, 0xE70C02BA, 0x0000 }, // ?SolvePosition@mmBoat@@QAEXAAVVector3@@AAM@Z
    { 0x4C77A0, 0x7E2767F9, 0x0000 }, // ?AdjustPhaseOffsets@mmBoat@@QAEXXZ
    { 0x4C7820, 0x61601C6A, 0x0000 }, // ?AddWidgets@mmBoat@@UAEXPAVBank@@@Z
    { 0x4C7910, 0xF62E99D0, 0x0000 }, // ?CalculateCubics@mmBoat@@QAEXH@Z
    { 0x4C7B20, 0xFDCA3D5A, 0x0000 }, // ?SolveVector@mmBoat@@QAEXMAAVVector3@@0@Z
    { 0x4C7C90, 0x13B83292, 0x0000 }, // ?ComputeXZCurve@mmBoat@@QAEXAAVVector3@@000@Z
    { 0x4C7D80, 0xA70581E7, 0x0000 }, // ?SolveXZCurve@mmBoat@@QAEXAAVVector3@@0M@Z
    { 0x4C7E50, 0xAB811BF5, 0x0000 }, // ?DeclareFields@mmBoat@@SAXXZ
    { 0x4C7FC0, 0x9E069B88, 0x0000 }, // ?GetClass@mmBoat@@UAEPAVMetaClass@@XZ
    { 0x4C8030, 0xF542365B, 0x0000 }, // ??0mmAnimTrainCar@@QAE@XZ
    { 0x4C8050, 0xB8E3A27A, 0x0000 }, // ??1mmAnimTrainCar@@UAE@XZ
    { 0x4C8060, 0x84427F7E, 0x0000 }, // ?Init@mmAnimTrainCar@@QAEXPAD0@Z
    { 0x4C80E0, 0x62DA7722, 0x0000 }, // ?SetMatrix@mmAnimTrainCar@@QAEXAAVMatrix34@@@Z
    { 0x4C8100, 0x1CBF40A7, 0x0000 }, // ?Draw@mmAnimTrainCar@@UAIXH@Z
    { 0x4C8150, 0xCD386E1B, 0x0000 }, // ?Reset@mmAnimTrainCar@@UAEXXZ
    { 0x4C8160, 0xD72951C9, 0x0000 }, // ?SetStart@mmAnimTrainCar@@QAEXMM@Z
    { 0x4C81B0, 0x8CC24280, 0x0000 }, // ?LoadEntry@mmBangerData@@QAEHPAD@Z
    { 0x4C8370, 0x11953172, 0x0000 }, // ?LaunchInstance@mmBangerData@@QAEXMPAVVector3@@@Z
    { 0x4C8550, 0x76ADDE5A, 0x0000 }, // ?AddWidgets@mmBangerDataManager@@UAEXPAVBank@@@Z
    { 0x4C85E0, 0xAF673E8C, 0x0000 }, // ?AddWidgets@mmBangerData@@UAEXPAVBank@@@Z
    { 0x4C8A30, 0x06DDD32A, 0x0000 }, // ??0mmBangerDataManager@@QAE@XZ
    { 0x4C8B50, 0x474162A8, 0x0000 }, // ??1mmBangerDataManager@@UAE@XZ
    { 0x4C8C10, 0x61235D58, 0x0000 }, // ?AddBangerDataEntry@mmBangerDataManager@@QAEHPAD0@Z
    { 0x4C8E70, 0x9B38FF45, 0x0000 }, // ?Bootstrap@mmBangerData@@QAEHPAD0@Z
    { 0x4C8ED0, 0xFC800EA2, 0x0000 }, // ?BootstrapBreakablesOnly@mmBangerData@@QAEXPAD@Z
    { 0x4C8F10, 0x12CFE3C1, 0x0000 }, // ?InitBreakables@mmBangerData@@QAEXPAD@Z
    { 0x4C9150, 0xAB8F7003, 0x0000 }, // ?InitPhysics@mmBangerData@@QAEHPAD0@Z
    { 0x4C93D0, 0x010A73D5, 0x0000 }, // ?ComputeYRadius@mmBangerData@@QAEXPAD@Z
    { 0x4C9510, 0x65A736B1, 0x0000 }, // ?Save@mmBangerDataManager@@UAEXXZ
    { 0x4C9540, 0x57D95CFB, 0x0000 }, // ?DeclareFields@mmBangerData@@SAXXZ
    { 0x4C98C0, 0xAD86F014, 0x0000 }, // ?GetClass@mmBangerData@@UAEPAVMetaClass@@XZ
    { 0x4C98D0, 0x1791FDD1, 0x0000 }, // ?DeclareFields@mmBangerDataManager@@SAXXZ
    { 0x4C9A40, 0xF53C31A2, 0x0000 }, // ?GetClass@mmBangerDataManager@@UAEPAVMetaClass@@XZ
    { 0x4C9A50, 0xA7CC71A2, 0x0000 }, // ?RefTo@@YAPAUMetaType@@PAU1@HPAF@Z
    { 0x4C9B50, 0xE1CA5A7F, 0x0000 }, // ??0mmBangerData@@QAE@XZ
    { 0x4C9BE0, 0x2C28729B, 0x0000 }, // ??1mmBangerData@@UAE@XZ
    { 0x4C9C30, 0xBCA7709B, 0x0000 }, // ?ComputeLod@mmBangerInstance@@UAEHMM@Z
    { 0x4C9C50, 0x36A29084, 0x0000 }, // ?Draw@mmBangerInstance@@UAIXH@Z
    { 0x4C9E50, 0x96A8AA36, 0x0000 }, // ?DrawGlow@mmBangerInstance@@UAIXXZ
    { 0x4C9F20, 0xFD84896D, 0x0000 }, // ?Draw@mmHitBangerInstance@@UAIXH@Z
    { 0x4CA110, 0xABCD7F87, 0x0000 }, // ?DrawShadow@mmBangerInstance@@UAIXXZ
    { 0x4CA460, 0xA8D49C8E, 0x0000 }, // ?GetData@mmBangerInstance@@QAEPAVmmBangerData@@XZ
    { 0x4CA480, 0xB564EEC1, 0x0000 }, // ?GetEntity@mmBangerInstance@@UAEPAVmmPhysEntity@@XZ
    { 0x4CA490, 0x7EF20CA0, 0x0000 }, // ?AttachEntity@mmBangerInstance@@UAEPAVmmPhysEntity@@XZ
    { 0x4CA4D0, 0x3988BBE6, 0x0000 }, // ?GetVelocity@mmBangerInstance@@UAE?AVVector3@@XZ
    { 0x4CA520, 0xB65E76C7, 0x0000 }, // ?FromMatrix@mmHitBangerInstance@@UAIXABVMatrix34@@@Z
    { 0x4CA540, 0x92081B60, 0x0000 }, // ?ToMatrix@mmHitBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x4CA550, 0x05C1F879, 0x0000 }, // ?GetPos@mmHitBangerInstance@@UAIAAVVector3@@XZ
    { 0x4CA560, 0xCB22642E, 0x0000 }, // ?InitBreakables@mmUnhitBangerInstance@@QAEXPAD0PAVmmBangerData@@@Z
    { 0x4CA5F0, 0x030A9BA0, 0x0000 }, // ?Init@mmUnhitBangerInstance@@UAEHPADAAVVector3@@1H0@Z
    { 0x4CA810, 0xE6513501, 0x0000 }, // ?FromMatrix@mmUnhitBangerInstance@@UAIXABVMatrix34@@@Z
    { 0x4CA830, 0x466ECADD, 0x0000 }, // ?Reset@mmUnhitBangerInstance@@UAEXXZ
    { 0x4CA880, 0xFC1C7A7D, 0x0000 }, // ?ToMatrix@mmUnhitBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x4CA8D0, 0xDB16F96D, 0x0000 }, // ?GetPos@mmUnhitBangerInstance@@UAIAAVVector3@@XZ
    { 0x4CA8E0, 0xEA0C1AB3, 0x0000 }, // ?Impact@mmUnhitBangerInstance@@UAEXPAVmmInstance@@PAVVector3@@@Z
    { 0x4CAC40, 0xEA124A85, 0x0000 }, // ?Detach@mmHitBangerInstance@@UAEXXZ
    { 0x4CAC70, 0x748C415F, 0x0000 }, // ?GetBanger@mmBangerManager@@QAEPAVmmHitBangerInstance@@XZ
    { 0x4CACD0, 0xF4BEE747, 0x0000 }, // ?Init@mmBangerManager@@QAEXH@Z
    { 0x4CAD90, 0xEDC66BC1, 0x0000 }, // ?Reset@mmBangerManager@@UAEXXZ
    { 0x4CAE60, 0x989E9B32, 0x0000 }, // ??0mmHitBangerInstance@@QAE@XZ
    { 0x4CAEC0, 0xFA4E96BB, 0x0000 }, // ?SizeOf@mmHitBangerInstance@@UAEIXZ
    { 0x4CAED0, 0x9FE62E52, 0x0000 }, // ??1mmHitBangerInstance@@UAE@XZ
    { 0x4CAEE0, 0x4D2C8766, 0x0000 }, // ??0mmBangerActive@@QAE@XZ
    { 0x4CAFC0, 0xED114C39, 0x0000 }, // ??1mmBangerActive@@UAE@XZ
    { 0x4CB030, 0x10ED1FD2, 0x0000 }, // ?Attach@mmBangerActive@@QAEXPAVmmBangerInstance@@@Z
    { 0x4CB220, 0xECE4DFB9, 0x0000 }, // ?Detach@mmBangerActive@@QAEXXZ
    { 0x4CB280, 0xFB804FBD, 0x0000 }, // ?DetachMe@mmBangerActive@@UAEXXZ
    { 0x4CB2A0, 0xFC3D89E9, 0x0000 }, // ?Update@mmBangerActive@@UAEXXZ
    { 0x4CB350, 0xBEA3C811, 0x0000 }, // ?PostUpdate@mmBangerActive@@UAEXXZ
    { 0x4CB3E0, 0xF240FC05, 0x0000 }, // ??0mmBangerActiveManager@@QAE@XZ
    { 0x4CB490, 0x046C4022, 0x0000 }, // ??1mmBangerActiveManager@@UAE@XZ
    { 0x4CB4F0, 0x4F6F578D, 0x0000 }, // ?GetActive@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    { 0x4CB520, 0x6C43F528, 0x0000 }, // ?Attach@mmBangerActiveManager@@QAEPAVmmBangerActive@@PAVmmBangerInstance@@@Z
    { 0x4CB5F0, 0xD95B5E8B, 0x0000 }, // ?Detach@mmBangerActiveManager@@QAEXPAVmmBangerActive@@@Z
    { 0x4CB640, 0x09B92E6D, 0x0000 }, // ?Update@mmBangerActiveManager@@UAEXXZ
    { 0x4CB720, 0x8A4F4391, 0x0000 }, // ?Reset@mmBangerActiveManager@@UAEXXZ
    { 0x4CB7B0, 0xC2EB96E0, 0x0000 }, // ?GetBound@mmBangerActive@@UAEPAVasBound@@XZ
    { 0x4CB7C0, 0xB297AAAE, 0x0000 }, // ?GetICS@mmBangerActive@@UAEPAVasInertialCS@@XZ
    { 0x4CB7D0, 0x496FCEFD, 0x0000 }, // ?SizeOf@mmDofBangerInstance@@UAEIXZ
    { 0x4CB7E0, 0xCFAABD8B, 0x0000 }, // ?Init@mmDofBangerInstance@@QAEHPAD0HPAVMatrix34@@PAVVector3@@@Z
    { 0x4CB890, 0xB15FAC96, 0x0000 }, // ?ToMatrix@mmFacadeBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    { 0x4CB940, 0xE99B7477, 0x0000 }, // ?GetPos@mmFacadeBangerInstance@@UAIAAVVector3@@XZ
    { 0x4CB9C0, 0x69BBA360, 0x0000 }, // ?Draw@mmGlassBangerInstance@@EAIXH@Z
    { 0x4CBB40, 0x711E9B0B, 0x0000 }, // ??1mmPlayerData@@UAE@XZ
    { 0x4CBC10, 0x76FDDF8A, 0x0000 }, // ??0mmCityList@@QAE@XZ
    { 0x4CBC30, 0x0C6D72ED, 0x0000 }, // ??1mmCityList@@UAE@XZ
    { 0x4CBC90, 0x6270604E, 0x0000 }, // ?Init@mmCityList@@QAEXH@Z
    { 0x4CBCA0, 0xDA469E26, 0x0000 }, // ?GetCityInfo@mmCityList@@QAEPAVmmCityInfo@@H@Z
    { 0x4CBCD0, 0x342315FA, 0x0000 }, // ?GetCityInfo@mmCityList@@QAEPAVmmCityInfo@@PAD@Z
    { 0x4CBD50, 0xE5916D9A, 0x0000 }, // ?GetCityID@mmCityList@@QAEHPAD@Z
    { 0x4CBDD0, 0xB6D916D0, 0x0000 }, // ?SetCurrentCity@mmCityList@@QAEXPAD@Z
    { 0x4CBDF0, 0x93F5D459, 0x0000 }, // ?SetCurrentCity@mmCityList@@QAEXH@Z
    { 0x4CBE20, 0x9B3953C9, 0x0000 }, // ?GetCurrentCity@mmCityList@@QAEPAVmmCityInfo@@XZ
    { 0x4CBE30, 0x41D0D061, 0x0000 }, // ?Load@mmCityList@@QAEXPAD@Z
    { 0x4CBF60, 0xB64F915A, 0x0000 }, // ?Print@mmCityList@@QAEXXZ
    { 0x4CBFA0, 0x094CA0E9, 0x0000 }, // ?LoadAll@mmCityList@@QAEXXZ
    { 0x4CC080, 0x2B5388D4, 0x0000 }, // ??0mmVehList@@QAE@XZ
    { 0x4CC0A0, 0xAD896481, 0x0000 }, // ??1mmVehList@@UAE@XZ
    { 0x4CC100, 0x8F3BA795, 0x0000 }, // ?Init@mmVehList@@QAEXH@Z
    { 0x4CC110, 0xC807567D, 0x0000 }, // ?GetVehicleInfo@mmVehList@@QAEPAVmmVehInfo@@H@Z
    { 0x4CC140, 0x4AD9EDA8, 0x0000 }, // ?GetVehicleInfo@mmVehList@@QAEPAVmmVehInfo@@PAD@Z
    { 0x4CC1C0, 0x0A979A87, 0x0000 }, // ?GetVehicleID@mmVehList@@QAEHPAD@Z
    { 0x4CC240, 0xC721F633, 0x0000 }, // ?Load@mmVehList@@QAEXPAD@Z
    { 0x4CC370, 0x37CBFC37, 0x0000 }, // ?Print@mmVehList@@QAEXXZ
    { 0x4CC3C0, 0x75452FB5, 0x0000 }, // ?LoadAll@mmVehList@@QAEXXZ
    { 0x4CC490, 0xFFA7D535, 0x0000 }, // ??0mmMiscData@@QAE@XZ
    { 0x4CC5A0, 0x337C93FF, 0x0000 }, // ??1mmMiscData@@UAE@XZ
    { 0x4CC6A0, 0xB6ADF07B, 0x0000 }, // ?Load@mmMiscData@@QAEHPAD@Z
    { 0x4CC710, 0xE4BDBB6E, 0x0000 }, // ?Save@mmMiscData@@QAEHPADH@Z
    { 0x4CC7A0, 0x3B1CAF0F, 0x0000 }, // ?LoadBinary@mmMiscData@@QAEHPAD@Z
    { 0x4CC960, 0xCD02FDEF, 0x0000 }, // ?SaveBinary@mmMiscData@@QAEHPAD@Z
    { 0x4CCAE0, 0x412BB29E, 0x0000 }, // ?GetBestRaceTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    { 0x4CCC10, 0xCE5C71F7, 0x0000 }, // ?GetBestBlitzTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    { 0x4CCD40, 0xA5B204E1, 0x0000 }, // ?GetBestCircuitTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    { 0x4CCE70, 0xC565BF54, 0x0000 }, // ?GetBestRaceScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    { 0x4CCFA0, 0xC0338C42, 0x0000 }, // ?GetBestBlitzScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    { 0x4CD0D0, 0x260A438F, 0x0000 }, // ?GetBestCircuitScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    { 0x4CD200, 0x4595CA7F, 0x0000 }, // ?CheckCheckpoint@mmMiscData@@QAEHPADMH0HH@Z
    { 0x4CD3A0, 0x866C13CD, 0x0000 }, // ?CheckCircuit@mmMiscData@@QAEHPADMH0HH@Z
    { 0x4CD540, 0x39657D2D, 0x0000 }, // ?CheckBlitz@mmMiscData@@QAEHPADMH0HH@Z
    { 0x4CD6E0, 0x7AEBFB07, 0x0000 }, // ?DeclareFields@mmMiscData@@SAXXZ
    { 0x4CD960, 0x93D20368, 0x0000 }, // ?GetClass@mmMiscData@@UAEPAVMetaClass@@XZ
    { 0x4CDA00, 0x98DB46FA, 0x0000 }, // ??0mmPlayerConfig@@QAE@XZ
    { 0x4CDAA0, 0x1A6992FF, 0x0000 }, // ??1mmPlayerConfig@@UAE@XZ
    { 0x4CDB10, 0xA0842FBC, 0x0000 }, // ??4mmPlayerConfig@@QAEXAAV0@@Z
    { 0x4CDC90, 0xF2BE1109, 0x0000 }, // ?Load@mmPlayerConfig@@QAEHPAD@Z
    { 0x4CDD60, 0xB6046486, 0x0000 }, // ?LoadBinary@mmPlayerConfig@@QAEHPAD@Z
    { 0x4CDFE0, 0x1105B79D, 0x0000 }, // ?SaveBinary@mmPlayerConfig@@QAEHPAD@Z
    { 0x4CE230, 0xC05192DB, 0x0000 }, // ?SetDefaults@mmPlayerConfig@@QAEXXZ
    { 0x4CE240, 0xD4B2835C, 0x0000 }, // ?Save@mmPlayerConfig@@QAEHPADH@Z
    { 0x4CE2E0, 0x51568AAA, 0x0000 }, // ?SetAudio@mmPlayerConfig@@QAEXXZ
    { 0x4CE450, 0x81B355A6, 0x0000 }, // ?SetControls@mmPlayerConfig@@QAEXXZ
    { 0x4CE540, 0xB91F4B6A, 0x0000 }, // ?Get@mmGfxCFG@@QAEXXZ
    { 0x4CE5B0, 0x142DDCD3, 0x0000 }, // ?Set@mmGfxCFG@@QAEXXZ
    { 0x4CE630, 0x35187901, 0x0000 }, // ?GetGraphics@mmPlayerConfig@@QAEXXZ
    { 0x4CE640, 0x5A0608E4, 0x0000 }, // ?SetGraphics@mmPlayerConfig@@QAEXXZ
    { 0x4CE650, 0x1567CCFF, 0x0000 }, // ?GetAudio@mmPlayerConfig@@QAEXXZ
    { 0x4CE6C0, 0x96618DD6, 0x0000 }, // ?GetControls@mmPlayerConfig@@QAEXXZ
    { 0x4CE7A0, 0x679ED143, 0x0000 }, // ?GetViewSettings@mmPlayerConfig@@QAEXXZ
    { 0x4CE7D0, 0x7B7F34F9, 0x0000 }, // ?SetViewSettings@mmPlayerConfig@@QAEXXZ
    { 0x4CE800, 0x1C3CE2FA, 0x0000 }, // ?DefaultAudio@mmPlayerConfig@@QAEXXZ
    { 0x4CE910, 0xFAA523C6, 0x0000 }, // ?DefaultControls@mmPlayerConfig@@QAEXXZ
    { 0x4CE970, 0xD1BC39CA, 0x0000 }, // ?DefaultViewSettings@mmPlayerConfig@@QAEXXZ
    { 0x4CE9B0, 0x735D9714, 0x0000 }, // ?Reset@mmPlayerConfig@@QAEXXZ
    { 0x4CE9C0, 0xCC93623D, 0x0000 }, // ?DefaultGraphics@mmPlayerConfig@@QAEXXZ
    { 0x4CE9E0, 0x02B22093, 0x0000 }, // ?DeclareFields@mmPlayerConfig@@SAXXZ
    { 0x4CEE70, 0x073CB435, 0x0000 }, // ?GetClass@mmPlayerConfig@@UAEPAVMetaClass@@XZ
    { 0x4CEE80, 0xF3150BF0, 0x0000 }, // ??1mmCtrlCFG@@QAE@XZ
    { 0x4CEF00, 0x3FFD1D9A, 0x0000 }, // ??0mmPlayerDirectory@@QAE@XZ
    { 0x4CEF40, 0x93E297A1, 0x0000 }, // ??1mmPlayerDirectory@@UAE@XZ
    { 0x4CEFA0, 0x485F6FE8, 0x0000 }, // ?NewDirectory@mmPlayerDirectory@@QAEXH@Z
    { 0x4CEFE0, 0x6A047212, 0x0000 }, // ?SetPlayer@mmPlayerDirectory@@QAEXHPAD0@Z
    { 0x4CF010, 0x453BD688, 0x0000 }, // ?SetLastPlayer@mmPlayerDirectory@@QAEXPAD@Z
    { 0x4CF060, 0xAEBBCCF4, 0x0000 }, // ?GetPlayer@mmPlayerDirectory@@QAEPADH@Z
    { 0x4CF090, 0xA9773E42, 0x0000 }, // ?GetNumPlayers@mmPlayerDirectory@@QAEHXZ
    { 0x4CF0A0, 0x0BE090DD, 0x0000 }, // ?GetLastPlayer@mmPlayerDirectory@@QAEPADXZ
    { 0x4CF0D0, 0xC20536AB, 0x0000 }, // ?AddPlayer@mmPlayerDirectory@@QAEHPAD@Z
    { 0x4CF210, 0xDF98DABE, 0x0000 }, // ?CreatePlayer@mmPlayerDirectory@@AAEXPAD0@Z
    { 0x4CF320, 0x66FEAC7B, 0x0000 }, // ?FindPlayer@mmPlayerDirectory@@QAEHPAD@Z
    { 0x4CF390, 0x934EF272, 0x0000 }, // ?GetFileName@mmPlayerDirectory@@QAEPADPAD@Z
    { 0x4CF420, 0xB0BF4AA6, 0x0000 }, // ?GetPlayerName@mmPlayerDirectory@@QAEPADPAD@Z
    { 0x4CF4B0, 0x77CFA56F, 0x0000 }, // ?GetFileName@mmPlayerDirectory@@QAEPADH@Z
    { 0x4CF4E0, 0xACC7984A, 0x0000 }, // ?MakeFileName@mmPlayerDirectory@@AAEPADXZ
    { 0x4CF5A0, 0xB0E26452, 0x0000 }, // ?RemovePlayer@mmPlayerDirectory@@QAEHPAD@Z
    { 0x4CF6A0, 0x4FE5B209, 0x0000 }, // ?Load@mmPlayerDirectory@@QAEHPAD@Z
    { 0x4CF6D0, 0x12964F7A, 0x0000 }, // ?Save@mmPlayerDirectory@@QAEHPADH@Z
    { 0x4CF770, 0x6AA680D1, 0x0000 }, // ?SaveBinary@mmPlayerDirectory@@QAEHPAD@Z
    { 0x4CF870, 0xB8ACCCAD, 0x0000 }, // ?LoadBinary@mmPlayerDirectory@@QAEHPAD@Z
    { 0x4CF9B0, 0xB8407FDA, 0x0000 }, // ?DeclareFields@mmPlayerDirectory@@SAXXZ
    { 0x4CFB80, 0x9D133D73, 0x0000 }, // ?GetClass@mmPlayerDirectory@@UAEPAVMetaClass@@XZ
    { 0x4CFB90, 0x39AC8CBC, 0x0000 }, // ?RefTo@@YAPAUMetaType@@PAU1@HPAH@Z
    { 0x4CFC30, 0xA4DEF8B0, 0x0000 }, // ??0mmPlayerRecord@@QAE@XZ
    { 0x4CFC50, 0xFB84D80D, 0x0000 }, // ??1mmPlayerRecord@@UAE@XZ
    { 0x4CFC60, 0xC7EF75E0, 0x0000 }, // ?Reset@mmPlayerRecord@@QAEXXZ
    { 0x4CFC90, 0xE9598174, 0x0000 }, // ??4mmPlayerRecord@@QAEXAAV0@@Z
    { 0x4CFCE0, 0xC04567B3, 0x0000 }, // ?ComputeCRC@mmPlayerRecord@@QAEIXZ
    { 0x4CFD40, 0xB477B48F, 0x0000 }, // ?SaveBinary@mmPlayerRecord@@QAEHPAVStream@@@Z
    { 0x4CFDC0, 0xED1E8DC6, 0x0000 }, // ?LoadBinary@mmPlayerRecord@@QAEHPAVStream@@@Z
    { 0x4CFE40, 0x8744DEDB, 0x0000 }, // ?DeclareFields@mmPlayerRecord@@SAXXZ
    { 0x4D0010, 0x36AB02D7, 0x0000 }, // ?GetClass@mmPlayerRecord@@UAEPAVMetaClass@@XZ
    { 0x4D0020, 0x7351111B, 0x0000 }, // ??0mmPlayerData@@QAE@XZ
    { 0x4D0140, 0xFB866818, 0x0000 }, // ??4mmPlayerData@@QAEXAAV0@@Z
    { 0x4D0280, 0xB39C3807, 0x0000 }, // ?RegisterFinish@mmPlayerData@@QAEHHMD@Z
    { 0x4D0290, 0xAA6784C1, 0x0000 }, // ?GetCheckpointProgress@mmPlayerData@@QAEHH@Z
    { 0x4D02B0, 0xC9220081, 0x0000 }, // ?GetBlitzMask@mmPlayerData@@QAEHXZ
    { 0x4D02E0, 0x9CA0846D, 0x0000 }, // ?GetCheckpointMask@mmPlayerData@@QAEHXZ
    { 0x4D0310, 0x19180D74, 0x0000 }, // ?GetCircuitMask@mmPlayerData@@QAEHXZ
    { 0x4D0340, 0xD1579F7B, 0x0000 }, // ?GetBlitzPassed@mmPlayerData@@QAEHXZ
    { 0x4D0360, 0x11088DC8, 0x0000 }, // ?GetCheckpointPassed@mmPlayerData@@QAEHXZ
    { 0x4D0380, 0x13453D1E, 0x0000 }, // ?GetCircuitPassed@mmPlayerData@@QAEHXZ
    { 0x4D03A0, 0x00EA2B40, 0x0000 }, // ?GetTotalPassed@mmPlayerData@@QAEHXZ
    { 0x4D03C0, 0x6C453582, 0x0000 }, // ?GetTotalScore@mmPlayerData@@QAEHXZ
    { 0x4D0410, 0x43D18738, 0x0000 }, // ?ResolveCheckpointProgress@mmPlayerData@@QAEXXZ
    { 0x4D04A0, 0x340C09BA, 0x0000 }, // ?RegisterFinish@mmPlayerData@@QAEHVmmPlayerRecord@@HH@Z
    { 0x4D0750, 0xD8AE526D, 0x0000 }, // ?Reset@mmPlayerData@@QAEXXZ
    { 0x4D0820, 0x2AE79DD1, 0x0000 }, // ?SetName@mmPlayerData@@QAEXPAD@Z
    { 0x4D0860, 0x990CBC41, 0x0000 }, // ?GetName@mmPlayerData@@QAEPADXZ
    { 0x4D0870, 0xAFEB8341, 0x0000 }, // ?SetNetName@mmPlayerData@@QAEXPAD@Z
    { 0x4D08B0, 0x111D43AF, 0x0000 }, // ?GetNetName@mmPlayerData@@QAEPADXZ
    { 0x4D08C0, 0xE0F38E09, 0x0000 }, // ?SetFileName@mmPlayerData@@QAEXPAD@Z
    { 0x4D0900, 0x5377E921, 0x0000 }, // ?GetFileName@mmPlayerData@@QAEPADXZ
    { 0x4D0910, 0x8A344C3B, 0x0000 }, // ?Load@mmPlayerData@@QAEHPAD@Z
    { 0x4D0940, 0xD9BCE92F, 0x0000 }, // ?Save@mmPlayerData@@QAEHPADH@Z
    { 0x4D09E0, 0xE236CF6B, 0x0000 }, // ?ComputeCRC@mmPlayerData@@QAEIXZ
    { 0x4D0A90, 0xE178C97E, 0x0000 }, // ?LoadBinary@mmPlayerData@@QAEHPAD@Z
    { 0x4D0CF0, 0xBE27BDBD, 0x0000 }, // ?SaveBinary@mmPlayerData@@QAEHPAD@Z
    { 0x4D0F00, 0x3652468C, 0x0000 }, // ?DeclareFields@mmPlayerData@@SAXXZ
    { 0x4D11E0, 0x8CA7854C, 0x0000 }, // ?GetClass@mmPlayerData@@UAEPAVMetaClass@@XZ
    { 0x4D12B0, 0xBEAB1855, 0x0000 }, // ??0mmInfoBase@@QAE@XZ
    { 0x4D12E0, 0x70B07C11, 0x0000 }, // ?Load@mmInfoBase@@QAEHPAD@Z
    { 0x4D1390, 0xD6E7C8D6, 0x0000 }, // ?Save@mmInfoBase@@QAEHPAD@Z
    { 0x4D1440, 0x9206E57B, 0x0000 }, // ?SetIOPath@mmInfoBase@@QAEXPAD@Z
    { 0x4D1460, 0x1618FA8C, 0x0000 }, // ?DeclareFields@mmInfoBase@@SAXXZ
    { 0x4D15D0, 0x232ADD60, 0x0000 }, // ?GetClass@mmInfoBase@@UAEPAVMetaClass@@XZ
    { 0x4D1640, 0xECFF5BB5, 0x0000 }, // ??0mmRecord@@QAE@XZ
    { 0x4D1680, 0xE934AEBB, 0x0000 }, // ??1mmRecord@@UAE@XZ
    { 0x4D1690, 0xAE63D523, 0x0000 }, // ?GetTime@mmRecord@@QAEMXZ
    { 0x4D16A0, 0xA2F353F2, 0x0000 }, // ?GetCarName@mmRecord@@QAEPADXZ
    { 0x4D16B0, 0xD2C29FD1, 0x0000 }, // ?GetName@mmRecord@@QAEPADXZ
    { 0x4D16C0, 0xDAE47792, 0x0000 }, // ?GetPassed@mmRecord@@QAEHXZ
    { 0x4D16D0, 0x246D73C8, 0x0000 }, // ?GetScore@mmRecord@@QAEHXZ
    { 0x4D16E0, 0xACBC3D50, 0x0000 }, // ?SetTime@mmRecord@@QAEXM@Z
    { 0x4D16F0, 0x4661F1CE, 0x0000 }, // ?SetCarName@mmRecord@@QAEXPAD@Z
    { 0x4D1710, 0x1950A7D3, 0x0000 }, // ?SetName@mmRecord@@QAEXPAD@Z
    { 0x4D1750, 0x61D22142, 0x0000 }, // ?SetPassed@mmRecord@@QAEXH@Z
    { 0x4D1770, 0xE461D645, 0x0000 }, // ?SetScore@mmRecord@@QAEXH@Z
    { 0x4D1780, 0xF79D07D1, 0x0000 }, // ??4mmRecord@@QAEXAAV0@@Z
    { 0x4D1810, 0xD7DD3055, 0x0000 }, // ?SaveBinary@mmRecord@@QAEHPAVStream@@@Z
    { 0x4D1890, 0x879D2C36, 0x0000 }, // ?LoadBinary@mmRecord@@QAEHPAVStream@@@Z
    { 0x4D1910, 0xA4E67FD4, 0x0000 }, // ?ComputeCRC@mmRecord@@QAEIXZ
    { 0x4D1970, 0xB63ED124, 0x0000 }, // ?DeclareFields@mmRecord@@SAXXZ
    { 0x4D1B50, 0x7FFC2B9E, 0x0000 }, // ?GetClass@mmRecord@@UAEPAVMetaClass@@XZ
    { 0x4D1BC0, 0x4AADAD4B, 0x0000 }, // ??0mmRaceData@@QAE@XZ
    { 0x4D1BD0, 0xD7E3F373, 0x0000 }, // ??1mmRaceData@@QAE@XZ
    { 0x4D1BE0, 0xB33D3C75, 0x0000 }, // ?Load@mmRaceData@@QAEHPAD@Z
    { 0x4D1F60, 0x369033F5, 0x0000 }, // ?GetNumRaces@mmRaceData@@QAEHXZ
    { 0x4D1F70, 0xCD9CD8A8, 0x0000 }, // ?GetRaceName@mmRaceData@@QAEPADH@Z
    { 0x4D1F80, 0x65E313A5, 0x0000 }, // ?GetCarType@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    { 0x4D1FB0, 0x6B3B20FD, 0x0000 }, // ?GetNumLaps@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    { 0x4D1FE0, 0xB760719D, 0x0000 }, // ?GetTimeLimit@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    { 0x4D2010, 0xC3D785B0, 0x0000 }, // ?GetNumOpponents@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    { 0x4D2040, 0x6E82E581, 0x0000 }, // ?GetNumCops@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    { 0x4D2070, 0x7403A4BE, 0x0000 }, // ?GetTimeOfDay@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    { 0x4D20A0, 0x0E69C7BF, 0x0000 }, // ?GetWeather@mmRaceData@@QAEHHW4mmSkillLevel@@@Z
    { 0x4D20D0, 0xDB1D5C81, 0x0000 }, // ?GetPedDensity@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    { 0x4D2100, 0x570B2839, 0x0000 }, // ?GetAmbientDensity@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    { 0x4D2130, 0xBF49F8CA, 0x0000 }, // ?GetDifficulty@mmRaceData@@QAEMHW4mmSkillLevel@@@Z
    { 0x4D2160, 0x7A137CD3, 0x0000 }, // ??0mmPropInfo@@QAE@XZ
    { 0x4D2190, 0xB2BCE6A4, 0x0000 }, // ??1mmPropInfo@@UAE@XZ
    { 0x4D21F0, 0xB990933E, 0x0000 }, // ?NewItems@mmPropInfo@@QAEXH@Z
    { 0x4D2220, 0x1F8329BA, 0x0000 }, // ?SetItem@mmPropInfo@@QAEXHPAD@Z
    { 0x4D2240, 0xE2B5BE1E, 0x0000 }, // ?SetSpacing@mmPropInfo@@QAEXM@Z
    { 0x4D2250, 0x007EF4F2, 0x0000 }, // ?GetItem@mmPropInfo@@QAEPADH@Z
    { 0x4D2280, 0x123F7C51, 0x0000 }, // ?GetSpacing@mmPropInfo@@QAEMXZ
    { 0x4D2290, 0xBD79F4C0, 0x0000 }, // ?GetNumItems@mmPropInfo@@QAEHXZ
    { 0x4D22A0, 0xCC4449B1, 0x0000 }, // ?Append@mmPropInfo@@QAEXPAD@Z
    { 0x4D2320, 0x04E3A2CD, 0x0000 }, // ??0mmRoadSide@@QAE@XZ
    { 0x4D23B0, 0x1EA0BD6B, 0x0000 }, // ??0mmRoadSect@@QAE@XZ
    { 0x4D24F0, 0xC7DAE2E5, 0x0000 }, // ?SetStreetWidth@mmRoadSect@@QAEXM@Z
    { 0x4D2500, 0x60500685, 0x0000 }, // ?SetStreetType@mmRoadSect@@QAEXPAD@Z
    { 0x4D2510, 0xE14C97A9, 0x0000 }, // ?SetRSidewalk@mmRoadSect@@QAEXMM@Z
    { 0x4D2530, 0x33ED2B24, 0x0000 }, // ?SetLSidewalk@mmRoadSect@@QAEXMM@Z
    { 0x4D2550, 0xD62A5283, 0x0000 }, // ?NewVertexs@mmRoadSect@@QAEXHHHHH@Z
    { 0x4D2600, 0xBF62B58E, 0x0000 }, // ?SetRoadVertex@mmRoadSect@@QAEXHHHAAVVector3@@@Z
    { 0x4D2650, 0xCEBB5D8A, 0x0000 }, // ?SetSidewalkVertex@mmRoadSect@@QAEXHHHAAVVector3@@@Z
    { 0x4D26B0, 0xFFD59DBF, 0x0000 }, // ?GetVertex@mmRoadSect@@QAEPAVVector3@@HHH@Z
    { 0x4D26E0, 0x88F2544F, 0x0000 }, // ?GetSidewalkVertex@mmRoadSect@@QAEPAVVector3@@HHH@Z
    { 0x4D2720, 0xA0854240, 0x0000 }, // ?SetRoadNormal@mmRoadSect@@QAEXHAAVVector3@@@Z
    { 0x4D2750, 0xC004DC29, 0x0000 }, // ?SetRoomId@mmRoadSect@@QAEXHH@Z
    { 0x4D2770, 0x40455EED, 0x0000 }, // ?SetIntersectionType@mmRoadSect@@QAEXHH@Z
    { 0x4D2790, 0x00D1FE40, 0x0000 }, // ?GetNormal@mmRoadSect@@QAEPAVVector3@@H@Z
    { 0x4D27B0, 0xFBA75C94, 0x0000 }, // ?GetRoomId@mmRoadSect@@QAEHH@Z
    { 0x4D27D0, 0x490A812E, 0x0000 }, // ?GetIntersectionType@mmRoadSect@@QAEHH@Z
    { 0x4D27F0, 0xB684FA3A, 0x0000 }, // ?SetStopLightPos@mmRoadSect@@QAEXHABVVector3@@0@Z
    { 0x4D2840, 0x47769AA4, 0x0000 }, // ?GetStopLightPos@mmRoadSect@@QAEXHAAVVector3@@0@Z
    { 0x4D2890, 0x1BA30BEB, 0x0000 }, // ?SetBlocked@mmRoadSect@@QAEXHH@Z
    { 0x4D28B0, 0x4AD14A05, 0x0000 }, // ?IsBlocked@mmRoadSect@@QAEHH@Z
    { 0x4D28D0, 0xE2CA6255, 0x0000 }, // ?SetPedBlocked@mmRoadSect@@QAEXHH@Z
    { 0x4D28F0, 0xEAAFE240, 0x0000 }, // ?IsPedBlocked@mmRoadSect@@QAEHH@Z
    { 0x4D2910, 0x15C60198, 0x0000 }, // ?SetStopLightName@mmRoadSect@@QAEXHPAD@Z
    { 0x4D2940, 0x562EBD3C, 0x0000 }, // ?GetStopLightName@mmRoadSect@@QAEPADH@Z
    { 0x4D2960, 0xE565E3B6, 0x0000 }, // ?SetDivided@mmRoadSect@@QAEXH@Z
    { 0x4D2970, 0xD2BB7915, 0x0000 }, // ?IsDivided@mmRoadSect@@QAEHXZ
    { 0x4D2980, 0xD848CD68, 0x0000 }, // ?SetAlley@mmRoadSect@@QAEXH@Z
    { 0x4D2990, 0x842CE4A9, 0x0000 }, // ?IsAlley@mmRoadSect@@QAEHXZ
    { 0x4D29A0, 0xC28FD32F, 0x0000 }, // ?DeclareFields@mmPropInfo@@SAXXZ
    { 0x4D2B60, 0x4A13BBA8, 0x0000 }, // ?GetClass@mmPropInfo@@UAEPAVMetaClass@@XZ
    { 0x4D2B70, 0x12C7C65D, 0x0000 }, // ?DeclareFields@mmRoadSide@@SAXXZ
    { 0x4D2D80, 0xA6833001, 0x0000 }, // ?GetClass@mmRoadSide@@UAEPAVMetaClass@@XZ
    { 0x4D2D90, 0xC8440E8E, 0x0000 }, // ?DeclareFields@mmRoadSect@@SAXXZ
    { 0x4D3140, 0xCA17B572, 0x0000 }, // ?GetClass@mmRoadSect@@UAEPAVMetaClass@@XZ
    { 0x4D3270, 0x8D49E37F, 0x0000 }, // ??0mmMapData@@QAE@XZ
    { 0x4D3290, 0x98A7814E, 0x0000 }, // ??1mmMapData@@UAE@XZ
    { 0x4D32F0, 0x44884E1C, 0x0000 }, // ?NewItems@mmMapData@@QAEXH@Z
    { 0x4D3320, 0x95AC6AA8, 0x0000 }, // ?SetItem@mmMapData@@QAEXHPAD@Z
    { 0x4D3340, 0xDA967EDC, 0x0000 }, // ?GetItem@mmMapData@@QAEPADH@Z
    { 0x4D3370, 0x9C44ECED, 0x0000 }, // ?GetNumItems@mmMapData@@QAEHXZ
    { 0x4D3380, 0x26FD59EF, 0x0000 }, // ?Append@mmMapData@@QAEXPAD@Z
    { 0x4D3400, 0x83DA217A, 0x0000 }, // ?DeclareFields@mmMapData@@SAXXZ
    { 0x4D35B0, 0xE04D0AF0, 0x0000 }, // ?GetClass@mmMapData@@UAEPAVMetaClass@@XZ
    { 0x4D3620, 0x341F0DFF, 0x0000 }, // ??0mmCityInfo@@QAE@XZ
    { 0x4D3640, 0xD24D2401, 0x0000 }, // ??1mmCityInfo@@UAE@XZ
    { 0x4D3650, 0xB35C4159, 0x0000 }, // ?Load@mmCityInfo@@QAEHPAD@Z
    { 0x4D39D0, 0x45F12E5E, 0x0000 }, // ??0mmVehInfo@@QAE@XZ
    { 0x4D39F0, 0x33E21FF8, 0x0000 }, // ??1mmVehInfo@@UAE@XZ
    { 0x4D3A00, 0xBBB9A430, 0x0000 }, // ?Load@mmVehInfo@@QAEHPAD@Z
    { 0x4D3BE0, 0x48B9BBD7, 0x0000 }, // ?HasColorVariations@mmVehInfo@@QAEHXZ
    { 0x4D3C00, 0x85CF1B6E, 0x0000 }, // ?Print@mmVehInfo@@QAEXXZ
    { 0x4D3CC0, 0x7C0776BC, 0x0000 }, // ?UpdateCrc@@YAKPAEI@Z
    { 0x4D3DA0, 0x5D02211A, 0x0000 }, // ?DoUpdateAll@mmPhysExec@@QAEXXZ
    { 0x4D3FF0, 0x9532A044, 0x0000 }, // ?DoUpdatePlayerOnly@mmPhysExec@@QAEXXZ
    { 0x4D42A0, 0xDCB82587, 0x0000 }, // ??0mmPhysicsMGR@@QAE@XZ
    { 0x4D43A0, 0x25FA4557, 0x0000 }, // ??1mmPhysicsMGR@@UAE@XZ
    { 0x4D4430, 0x7DBC050F, 0x0000 }, // ?Init@mmPhysicsMGR@@QAEXPAVasInertialCS@@PAVmmViewCS@@@Z
    { 0x4D44D0, 0x4067468E, 0x0000 }, // ?Reset@mmPhysicsMGR@@UAEXXZ
    { 0x4D4520, 0x7BF9E146, 0x0000 }, // ?Shutdown@mmPhysicsMGR@@QAEXXZ
    { 0x4D4540, 0x72DBBEED, 0x0000 }, // ?DeclareMover@mmPhysicsMGR@@QAEXPAVmmInstance@@HH@Z
    { 0x4D4740, 0x2DC1EA0B, 0x0000 }, // ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@0@Z
    { 0x4D4840, 0xD9FE0043, 0x0000 }, // ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@@Z
    { 0x4D48C0, 0xF916C978, 0x0000 }, // ?NewMover@mmPhysicsMGR@@QAEXPAVmmInstance@@00@Z
    { 0x4D49E0, 0xDA3EBDCF, 0x0000 }, // ?IgnoreMover@mmPhysicsMGR@@QAEXPAVmmInstance@@@Z
    { 0x4D4A30, 0x87D20D45, 0x0000 }, // ?GatherRoomCollidables@mmPhysicsMGR@@IAEXHFH@Z
    { 0x4D4B50, 0x3A35C1DE, 0x0000 }, // ?ClosestNeighboringCullRoom@mmPhysicsMGR@@IAEHH@Z
    { 0x4D4CA0, 0x59C66D0A, 0x0000 }, // ?GatherCollidables@mmPhysicsMGR@@IAEXHH@Z
    { 0x4D4D00, 0xB83CE0B3, 0x0000 }, // ?UpdateEverythingButPlayer@mmPhysicsMGR@@QAEXXZ
    { 0x4D4F40, 0xBE98086A, 0x0000 }, // ?Update@mmPhysicsMGR@@UAEXXZ
    { 0x4D52F0, 0xB8466134, 0x0000 }, // ?UpdatePaused@mmPhysicsMGR@@UAEXXZ
    { 0x4D5320, 0x0DC7E189, 0x0000 }, // ?DeclareBound@mmPhysicsMGR@@IAEXPAVmmBoundTemplate@@@Z
    { 0x4D5390, 0xCB64791A, 0x0000 }, // ?Cull@mmPhysicsMGR@@UAEXXZ
    { 0x4D5520, 0x69505A74, 0x0000 }, // ?Stats@mmPhysicsMGR@@IAEXXZ
    { 0x4D5730, 0xE13AD535, 0x0000 }, // ?TrivialCollideInstances@mmPhysicsMGR@@IAEHPAVmmInstance@@0@Z
    { 0x4D5950, 0xDC3DD80F, 0x0000 }, // ?CollideInstances@mmPhysicsMGR@@IAEHPAVmmInstance@@0HH@Z
    { 0x4D5DF0, 0x6247F6D7, 0x0000 }, // ?CollideTerrain@mmPhysicsMGR@@IAEXPAVmmInstance@@@Z
    { 0x4D62D0, 0xE4093415, 0x0000 }, // ?CollideProbe@mmPhysicsMGR@@IAEHFPAVmmIntersection@@H@Z
    { 0x4D6460, 0x196B23DA, 0x0000 }, // ?Collide@mmPhysicsMGR@@QAEHPAVmmIntersection@@HFF@Z
    { 0x4D6580, 0x866AB285, 0x0000 }, // ?CollideLOS@mmPhysicsMGR@@QAEHPAVmmIntersection@@HFF@Z
    { 0x4D66E0, 0x7BBC7BEF, 0x0000 }, // ?FindIntersections@@YAHPAVmmIntersection@@HPAVasBound@@1PAVmmBoundTemplate@@2PAVmmEdgeBodyIsect@@H3H@Z
    { 0x4D7B10, 0x047B6C33, 0x0000 }, // ?DoEndPtSearch@@YAXHABVVector3@@PAVmmEdgeBodyIsect@@HPAPAVmmIntersection@@PAHH@Z
    { 0x4D8130, 0x04850BAB, 0x0000 }, // ?DoEdgeEdge@@YAXPAVmmEdgeBodyIsect@@PAPAVmmIntersection@@PAHH@Z
    { 0x4D8210, 0x488F8C37, 0x0000 }, // ?SegSegDistNorm@@YAXABVVector3@@00000PAV1@11PAMPAH@Z
    { 0x4D8730, 0xD3A0BA84, 0x0000 }, // ?GetCollidePolyEdge@@YAHABVVector3@@PAVmmPolygon@@PAVmmBoundTemplate@@PAVasInertialCS@@0M0000PAV1@4PAMPAH6@Z
    { 0x4D8E00, 0xCC1DC390, 0x0000 }, // ?AddWidgets@mmPhysicsMGR@@UAEXPAVBank@@@Z
    { 0x4D8EF0, 0x64ACB8E6, 0x0000 }, // ?DeclareFields@mmPhysicsMGR@@SAXXZ
    { 0x4D9070, 0xBEF9AB53, 0x0000 }, // ?GetClass@mmPhysicsMGR@@UAEPAVMetaClass@@XZ
    { 0x4D9080, 0x18395A1D, 0x0000 }, // ??KVector3@@QBE?AV0@M@Z
    { 0x4D90C0, 0xF82E7CBA, 0x0000 }, // ?testNoOverlap@@YAHMM@Z
    { 0x4D9190, 0x5717E41D, 0x0000 }, // ?Update@mmPhysExec@@UAEXXZ
    { 0x4D91E0, 0xD18F6512, 0x0000 }, // ??1mmPhysExec@@UAE@XZ
    { 0x4D91F0, 0x5C9BD2DC, 0x0000 }, // ??0asInertialCS@@QAE@XZ
    { 0x4D92F0, 0x71295C68, 0x0000 }, // ?SetMass@asInertialCS@@QAEXMMMM@Z
    { 0x4D9400, 0x6F251AFE, 0x0000 }, // ?SetDensity@asInertialCS@@QAEXMMMM@Z
    { 0x4D9450, 0xFDCD3EA3, 0x0000 }, // ?SetZeroDOF@asInertialCS@@QAEXMM@Z
    { 0x4D9510, 0x145AE90F, 0x0000 }, // ?Zero@asInertialCS@@QAEXXZ
    { 0x4D9630, 0x8ECBD836, 0x0000 }, // ?Reset@asInertialCS@@UAEXXZ
    { 0x4D9650, 0x23EFA8D2, 0x0000 }, // ?UpdateKids@asInertialCS@@QAEXXZ
    { 0x4D9680, 0x54283098, 0x0000 }, // ?Update@asInertialCS@@UAEXXZ
    { 0x4D9740, 0xDA50F582, 0x0000 }, // ?FinishForces@asInertialCS@@QAEXXZ
    { 0x4D9AE0, 0x8486D449, 0x0000 }, // ?MoveICS@asInertialCS@@QAEXXZ
    { 0x4D9B60, 0x94E587ED, 0x0000 }, // ?FinishUpdate@asInertialCS@@QAEXXZ
    { 0x4DA200, 0xD3CEA851, 0x0000 }, // ?ApplyForce@asInertialCS@@QAEXABVVector3@@@Z
    { 0x4DA290, 0x5D5DFFA0, 0x0000 }, // ?ApplyForce@asInertialCS@@QAEXABVVector3@@0@Z
    { 0x4DA3A0, 0xEBD39D18, 0x0000 }, // ?ApplyTorque@asInertialCS@@QAEXABVVector3@@@Z
    { 0x4DA430, 0x108B6E6A, 0x0000 }, // ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@@Z
    { 0x4DA4C0, 0x3B5A47F1, 0x0000 }, // ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@0@Z
    { 0x4DA5D0, 0x5F063321, 0x0000 }, // ?ApplyAngImpulse@asInertialCS@@QAEXABVVector3@@@Z
    { 0x4DA660, 0x8F977A26, 0x0000 }, // ?ApplyPush@asInertialCS@@UAEXABVVector3@@0@Z
    { 0x4DA7D0, 0xB3C009E3, 0x0000 }, // ?ApplyPush@asInertialCS@@QAEXABVVector3@@@Z
    { 0x4DA940, 0x0581B131, 0x0000 }, // ?ApplyTurn@asInertialCS@@QAEXABVVector3@@@Z
    { 0x4DA980, 0xCB53D100, 0x0000 }, // ?DrawForce@asInertialCS@@AAEXABVVector3@@0@Z
    { 0x4DA9D0, 0x6E1B1144, 0x0000 }, // ?DrawForce@asInertialCS@@AAEXABVVector3@@00@Z
    { 0x4DAA20, 0x71DAF205, 0x0000 }, // ?DoConstrain@asInertialCS@@QAEXXZ
    { 0x4DAAD0, 0x9CB18081, 0x0000 }, // ?GetVelocity@asInertialCS@@QAE?AVVector3@@PBV2@@Z
    { 0x4DABA0, 0xC328EB0B, 0x0000 }, // ?CalcCMatrix@asInertialCS@@QBEXAAVMatrix34@@ABVVector3@@@Z
    { 0x4DAD70, 0x0A0FF5EC, 0x0000 }, // ?GetCMatrix@asInertialCS@@UBEXAAVMatrix34@@ABVVector3@@@Z
    { 0x4DADE0, 0xA4A2B129, 0x0000 }, // ?InertiaAxis@@YAMABVVector3@@0@Z
    { 0x4DAE20, 0xBA719FC4, 0x0000 }, // ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@M@Z
    { 0x4DAEF0, 0xA18CD385, 0x0000 }, // ?MatricesToMomenta@asInertialCS@@QAEXABVMatrix34@@0M@Z
    { 0x4DB120, 0x71AA2DBF, 0x0000 }, // ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@0M@Z
    { 0x4DB180, 0x3B437961, 0x0000 }, // ?FileIO@asInertialCS@@QAEXPAVMiniParser@@@Z
    { 0x4DB190, 0xD8D3173A, 0x0000 }, // ?AddWidgets@asInertialCS@@UAEXPAVBank@@@Z
    { 0x4DB970, 0x4AD4C3B3, 0x0000 }, // ?DeclareFields@asInertialCS@@SAXXZ
    { 0x4DBAF0, 0x0C2ECF03, 0x0000 }, // ?GetClass@asInertialCS@@UAEPAVMetaClass@@XZ
    { 0x4DBB30, 0x45BA4DD1, 0x0000 }, // ?Set@Vector3@@QAEXMMM@Z
    { 0x4DBB50, 0x43FE2DEE, 0x0000 }, // ??YVector3@@QAEXABV0@@Z
    { 0x4DBC20, 0xF78B88A4, 0x0000 }, // ??0Joint3Dof@@QAE@XZ
    { 0x4DBC70, 0x886AF6BE, 0x0000 }, // ?Init@Joint3Dof@@QAEXXZ
    { 0x4DBCE0, 0x103C2A50, 0x0000 }, // ?Reset@Joint3Dof@@UAEXXZ
    { 0x4DBCF0, 0xC121446A, 0x0000 }, // ?InitJoint3Dof@Joint3Dof@@QAEXPAVasInertialCS@@ABVVector3@@01@Z
    { 0x4DBD70, 0xE56AB981, 0x0000 }, // ?SetPosition@Joint3Dof@@QAEXABVVector3@@@Z
    { 0x4DBE50, 0xB63AD575, 0x0000 }, // ?SetRotate1@Joint3Dof@@QAEXABVMatrix34@@@Z
    { 0x4DBE70, 0x598835B0, 0x0000 }, // ?SetRotate2@Joint3Dof@@QAEXABVMatrix34@@@Z
    { 0x4DBE90, 0xED4B483A, 0x0000 }, // ?SetFrictionLean@Joint3Dof@@QAEXMMM@Z
    { 0x4DBEC0, 0x59456360, 0x0000 }, // ?SetFrictionRoll@Joint3Dof@@QAEXMMM@Z
    { 0x4DBEF0, 0xBC726B2B, 0x0000 }, // ?SetLeanLimit@Joint3Dof@@QAEXMM@Z
    { 0x4DBF10, 0xB097324D, 0x0000 }, // ?SetRollLimit@Joint3Dof@@QAEXMMM@Z
    { 0x4DBF40, 0x1B501ED1, 0x0000 }, // ?SetRestOrientation@Joint3Dof@@QAEXXZ
    { 0x4DBFB0, 0x3C8F03B0, 0x0000 }, // ?SetRestOrientMat@Joint3Dof@@QAEXABVMatrix34@@@Z
    { 0x4DBFF0, 0xF3554967, 0x0000 }, // ?SetRestOrientMat@Joint3Dof@@QAEXABVMatrix34@@0@Z
    { 0x4DC040, 0xDABA7672, 0x0000 }, // ?SetForceLimit@Joint3Dof@@QAEXM@Z
    { 0x4DC050, 0x5BFF10E6, 0x0000 }, // ?SetJointForceFlag@Joint3Dof@@QAEXXZ
    { 0x4DC0F0, 0x072F3783, 0x0000 }, // ?Update@Joint3Dof@@UAEXXZ
    { 0x4DD350, 0x9709FBD7, 0x0000 }, // ?MoveICS@Joint3Dof@@QAEXXZ
    { 0x4DD3A0, 0x70F406C4, 0x0000 }, // ?BreakJoint@Joint3Dof@@QAEXXZ
    { 0x4DD3D0, 0x9F1F3B84, 0x0000 }, // ?UnbreakJoint@Joint3Dof@@QAEXXZ
    { 0x4DD400, 0x56099F23, 0x0000 }, // ?DoJointTorque@Joint3Dof@@QAEXABVMatrix34@@000AAM1AAVVector3@@11@Z
    { 0x4DD990, 0xCEA3D58C, 0x0000 }, // ?DoJointLimits@Joint3Dof@@QAEXMABVVector3@@M0AAV2@ABVMatrix34@@2222@Z
    { 0x4DE050, 0x5528043E, 0x0000 }, // ?GetCMatrix@Joint3Dof@@UAEXPBVasInertialCS@@AAVMatrix34@@ABVVector3@@@Z
    { 0x4DE3B0, 0xFEE5282D, 0x0000 }, // ?GetCMatrix@Joint3Dof@@UAEXPBVasInertialCS@@0AAVMatrix34@@ABVVector3@@@Z
    { 0x4DE9A0, 0xDFB78270, 0x0000 }, // ?AddWidgets@Joint3Dof@@UAEXPAVBank@@@Z
    { 0x4DE9B0, 0x2611AAAA, 0x0000 }, // ?DeclareFields@Joint3Dof@@SAXXZ
    { 0x4DEB20, 0xCD119EC7, 0x0000 }, // ?GetClass@Joint3Dof@@UAEPAVMetaClass@@XZ
    { 0x4DEB60, 0x8B8AB087, 0x0000 }, // ??1JointedStruct@@UAE@XZ
    { 0x4DEB70, 0x4F14DB95, 0x0000 }, // ??TVector3@@QBE?AV0@ABVMatrix34@@@Z
    { 0x4DEBA0, 0x49A318A8, 0x0000 }, // ??ZVector3@@QAEXABV0@@Z
    { 0x4DEBD0, 0x82C9C237, 0x0000 }, // ??XVector3@@QAEXM@Z
    { 0x4DEC60, 0x7BC4D3C7, 0x0000 }, // ??1Joint3Dof@@UAE@XZ
    { 0x4DEC70, 0x6078E405, 0x0000 }, // ?RotateNoTrans@Matrix34@@QBE?AVVector3@@ABV2@@Z
    { 0x4DECA0, 0x3BC73E8E, 0x0000 }, // ?Transpose@Matrix34@@QBE?AV1@XZ
    { 0x4DECD0, 0x9D2A4784, 0x0000 }, // ?CrossProdMatrix@@YAXPAVMatrix34@@ABVVector3@@@Z
    { 0x4DED20, 0x0A7674E1, 0x0000 }, // ??0asOverSample@@QAE@XZ
    { 0x4DED50, 0xE737CF37, 0x0000 }, // ?RealTime@asOverSample@@QAEXM@Z
    { 0x4DED70, 0x04FAA1B5, 0x0000 }, // ?Update@asOverSample@@UAEXXZ
    { 0x4DEE30, 0xF8590CCA, 0x0000 }, // ?AddWidgets@asOverSample@@UAEXPAVBank@@@Z
    { 0x4DEEE0, 0xC815527F, 0x0000 }, // ?DeclareFields@asOverSample@@SAXXZ
    { 0x4DF060, 0x6020F519, 0x0000 }, // ?GetClass@asOverSample@@UAEPAVMetaClass@@XZ
    { 0x4DF0D0, 0xC847B6C8, 0x0000 }, // ??0asBound@@QAE@XZ
    { 0x4DF110, 0x659E9741, 0x0000 }, // ?Impact@asBound@@QAEHPAVmmIntersection@@PAV1@HHH@Z
    { 0x4DFAF0, 0x9356C190, 0x0000 }, // ?GetPhysMtl@asBound@@QAEAAVagiPhysParameters@@ABVmmPolygon@@@Z
    { 0x4DFC10, 0x83460E06, 0x0000 }, // ??0asAero@@QAE@XZ
    { 0x4DFC70, 0x050BF426, 0x0000 }, // ?Update@asAero@@UAEXXZ
    { 0x4E0130, 0x278B8900, 0x0000 }, // ?Load@asAero@@QAEXPAVStream@@@Z
    { 0x4E0200, 0x5930A3F4, 0x0000 }, // ?Save@asAero@@QAEXPAVStream@@@Z
    { 0x4E0330, 0xBDA49728, 0x0000 }, // ?AddWidgets@asAero@@UAEXPAVBank@@@Z
    { 0x4E0490, 0x3EEA4003, 0x0000 }, // ?DeclareFields@asAero@@SAXXZ
    { 0x4E0670, 0xE620DC5A, 0x0000 }, // ?GetClass@asAero@@UAEPAVMetaClass@@XZ
    { 0x4E06E0, 0xBCB9A2AA, 0x0000 }, // ?testsuperq@@YAXXZ
    { 0x4E0710, 0x42A7EB3C, 0x0000 }, // ??0mmInput@@QAE@XZ
    { 0x4E0930, 0x84E25B96, 0x0000 }, // ??1mmInput@@UAE@XZ
    { 0x4E09F0, 0xB0AA39A9, 0x0000 }, // ?AttachToPipe@mmInput@@QAEHXZ
    { 0x4E0EA0, 0x758EBCD7, 0x0000 }, // ?Reset@mmInput@@UAEXXZ
    { 0x4E0ED0, 0x0D220D0F, 0x0000 }, // ?IOInit@mmInput@@QAEXHPAULocString@@J@Z
    { 0x4E0F00, 0x9561FFBD, 0x0000 }, // ?AutoSetup@mmInput@@QAEXXZ
    { 0x4E0FD0, 0x5F8509CD, 0x0000 }, // ?SaveCB@mmInput@@QAEXXZ
    { 0x4E1010, 0x93855A87, 0x0000 }, // ?RestoreDefaultConfig@mmInput@@QAEXH@Z
    { 0x4E1070, 0x035D25D2, 0x0000 }, // ?SetDefaultConfig@mmInput@@QAEXH@Z
    { 0x4E1C60, 0xD5B51329, 0x0000 }, // ?Init@mmInput@@QAEXH@Z
    { 0x4E1E40, 0x64ADC3B3, 0x0000 }, // ?FlagIODevChanged@mmInput@@QAEXXZ
    { 0x4E1E60, 0xC9BB4E57, 0x0000 }, // ?ReturnStateCaptured@mmInput@@QAEHXZ
    { 0x4E1E80, 0xA6E2A87A, 0x0000 }, // ?CaptureState@mmInput@@QAEXH@Z
    { 0x4E1EB0, 0x0046D33A, 0x0000 }, // ?BuildCaptureIO@mmInput@@QAEHHPAVmmIO@@TeqEvent@@@Z
    { 0x4E2070, 0x492D7057, 0x0000 }, // ?ForceAssignment@mmInput@@QAEXPAVmmIO@@@Z
    { 0x4E2090, 0xC3A26318, 0x0000 }, // ?SanityCheck@mmInput@@QAEHPAVmmIO@@HH@Z
    { 0x4E2110, 0x2CE45C9D, 0x0000 }, // ?IsAlreadyAssigned@mmInput@@QAEHPAVmmIO@@HHH@Z
    { 0x4E21F0, 0x617F8DEF, 0x0000 }, // ?AssignIO@mmInput@@QAEXPAVmmIO@@HH@Z
    { 0x4E2290, 0x54538FE6, 0x0000 }, // ?Update@mmInput@@UAEXXZ
    { 0x4E2370, 0x3FE16D5F, 0x0000 }, // ?PollStates@mmInput@@QAEHXZ
    { 0x4E2420, 0xE0424C11, 0x0000 }, // ?PollSuperQ@mmInput@@QAEHXZ
    { 0x4E2450, 0x91BD4285, 0x0000 }, // ?Flush@mmInput@@QAEXXZ
    { 0x4E24B0, 0x2C8D4487, 0x0000 }, // ?ClearEventHitFlags@mmInput@@QAEXXZ
    { 0x4E24D0, 0x7712B6C5, 0x0000 }, // ?ProcessMouseEvents@mmInput@@AAEXXZ
    { 0x4E2530, 0x59C9C28C, 0x0000 }, // ?ProcessKeyboardEvents@mmInput@@AAEXXZ
    { 0x4E2580, 0x08CC8C5A, 0x0000 }, // ?GetBufferedKeyboardData@mmInput@@AAEXXZ
    { 0x4E25A0, 0x6333D541, 0x0000 }, // ?GetNextKeyboardEvent@mmInput@@AAEHPATeqEvent@@@Z
    { 0x4E25E0, 0xD5585519, 0x0000 }, // ?ProcessEvents@mmInput@@AAEXXZ
    { 0x4E2600, 0xAF77EABB, 0x0000 }, // ?ProcessStates@mmInput@@AAE_JXZ
    { 0x4E26E0, 0xC44F73B3, 0x0000 }, // ?ScanState@mmInput@@AAE_JPAVmmIO@@@Z
    { 0x4E2890, 0xCBD15A17, 0x0000 }, // ?EventToButton@mmInput@@AAEHH@Z
    { 0x4E28C0, 0xE44A1F9C, 0x0000 }, // ?ProcessJoyEvents@mmInput@@AAEXXZ
    { 0x4E2D90, 0xBE85CDC9, 0x0000 }, // ?ScanForEvent@mmInput@@AAE_JPATeqEvent@@@Z
    { 0x4E2E50, 0x296B0BBC, 0x0000 }, // ?PutEventInQueue@mmInput@@AAEX_J@Z
    { 0x4E2E80, 0x4CA8151D, 0x0000 }, // ?PollContinuous@mmInput@@AAEXPAVmmIO@@@Z
    { 0x4E3310, 0x37CECD62, 0x0000 }, // ?GetThrottle@mmInput@@QAEMXZ
    { 0x4E3330, 0x9A8AEAC8, 0x0000 }, // ?GetThrottleVal@mmInput@@QAEMXZ
    { 0x4E33A0, 0x0F9442CC, 0x0000 }, // ?GetBrakes@mmInput@@QAEMXZ
    { 0x4E33C0, 0x9872DB90, 0x0000 }, // ?GetBrakesVal@mmInput@@QAEMXZ
    { 0x4E3430, 0x044EFCCA, 0x0000 }, // ?GetHandBrake@mmInput@@QAEMXZ
    { 0x4E34B0, 0x442767F8, 0x0000 }, // ?FilterDiscreteSteering@mmInput@@AAEMM@Z
    { 0x4E3650, 0xC66A50C0, 0x0000 }, // ?FilterGamepadSteering@mmInput@@QAEMXZ
    { 0x4E37E0, 0xD06C3038, 0x0000 }, // ?GetSteering@mmInput@@QAEMXZ
    { 0x4E3890, 0xAEA783B7, 0x0000 }, // ?GetCamPan@mmInput@@QAEMXZ
    { 0x4E3990, 0x9751CDB5, 0x0000 }, // ?DeviceConnected@mmInput@@QAEHXZ
    { 0x4E39A0, 0x69EDC09F, 0x0000 }, // ?JoystickConnected@mmInput@@QAEHXZ
    { 0x4E39B0, 0x98A36223, 0x0000 }, // ?GamepadConnected@mmInput@@QAEHXZ
    { 0x4E39C0, 0x1A0A0410, 0x0000 }, // ?WheelConnected@mmInput@@QAEHXZ
    { 0x4E39D0, 0x573426E0, 0x0000 }, // ?SetDeadZone@mmInput@@QAEXM@Z
    { 0x4E3A00, 0x9E54FF1C, 0x0000 }, // ?JoystickHasCoolie@mmInput@@QAEHXZ
    { 0x4E3A10, 0xD3EDD1D7, 0x0000 }, // ?JoystickHasThrottle@mmInput@@QAEHXZ
    { 0x4E3A20, 0xAD6ADC22, 0x0000 }, // ?WheelHas3Axis@mmInput@@QAEHXZ
    { 0x4E3A60, 0xB1A9F22E, 0x0000 }, // ?DoingFF@mmInput@@QAEHXZ
    { 0x4E3A90, 0x27C59DD7, 0x0000 }, // ?StopAllFF@mmInput@@QAEXXZ
    { 0x4E3AA0, 0x9A2C61E9, 0x0000 }, // ?SetForceFeedbackScale@mmInput@@QAEXM@Z
    { 0x4E3AF0, 0x23A40E24, 0x0000 }, // ?SetRoadForceScale@mmInput@@QAEXM@Z
    { 0x4E3B40, 0x498ADB66, 0x0000 }, // ?ToggleFFEnabled@mmInput@@QAEHH@Z
    { 0x4E3B60, 0x07619B3A, 0x0000 }, // ?FFPlay@mmInput@@QAEHH@Z
    { 0x4E3B90, 0xEC506A22, 0x0000 }, // ?FFStop@mmInput@@QAEHH@Z
    { 0x4E3BC0, 0xBE6EE05F, 0x0000 }, // ?FFIsPlaying@mmInput@@QAEHH@Z
    { 0x4E3BF0, 0x7EABABCB, 0x0000 }, // ?FFSetValues@mmInput@@QAEHHMM@Z
    { 0x4E3C20, 0xEC4AEAA8, 0x0000 }, // ?PopEvent@mmInput@@QAEHPAH@Z
    { 0x4E3C50, 0xB22715F1, 0x0000 }, // ?LoadConfig@mmInput@@QAEHPAVStream@@@Z
    { 0x4E3CE0, 0x2BCF74A4, 0x0000 }, // ?BinaryLoadConfig@mmInput@@QAEHPAVStream@@@Z
    { 0x4E3DA0, 0xDB3606C1, 0x0000 }, // ?SaveConfig@mmInput@@QAEHPAVStream@@@Z
    { 0x4E3E20, 0xE2ED18FB, 0x0000 }, // ?BinarySaveConfig@mmInput@@QAEHPAVStream@@@Z
    { 0x4E3EB0, 0x53E9B0A3, 0x0000 }, // ?AddWidgets@mmInput@@EAEXPAVBank@@@Z
    { 0x4E40E0, 0xB164D8A7, 0x0000 }, // ?DeclareFields@mmInput@@SAXXZ
    { 0x4E4290, 0xD1F06E8F, 0x0000 }, // ?GetClass@mmInput@@UAEPAVMetaClass@@XZ
    { 0x4E42A0, 0x3A896526, 0x0000 }, // ?PrintIODev@mmInput@@QAEXXZ
    { 0x4E4370, 0x9D4565CE, 0x0000 }, // ?SaveCodeConfig@mmInput@@QAEHPAVStream@@@Z
    { 0x4E4B60, 0x96DF9F44, 0x0000 }, // ??0mmIO@@QAE@XZ
    { 0x4E4B80, 0x4C8BD2A6, 0x0000 }, // ??1mmIO@@QAE@XZ
    { 0x4E4B90, 0xFF788ED1, 0x0000 }, // ?Clear@mmIO@@QAEXXZ
    { 0x4E4BB0, 0x13351CAE, 0x0000 }, // ?Init@mmIO@@QAEXPADHJ@Z
    { 0x4E4C10, 0xA9D7A555, 0x0000 }, // ?InitDev@mmIO@@QAEXH_JHHH@Z
    { 0x4E4CC0, 0xDB83661A, 0x0000 }, // ?Assign@mmIO@@QAEXHH@Z
    { 0x4E4D20, 0x492FD566, 0x0000 }, // ??8mmIO@@QAEHPATeqEvent@@@Z
    { 0x4E4D70, 0x982A09E8, 0x0000 }, // ?GetDescription@mmIO@@QAEXPAD@Z
    { 0x4E4DC0, 0xB1BD380C, 0x0000 }, // ?Write@mmIO@@QAEHPAVStream@@@Z
    { 0x4E4E00, 0xFE2ECFB3, 0x0000 }, // ?Read@mmIO@@QAEHPAVStream@@@Z
    { 0x4E4ED0, 0x285B283D, 0x0000 }, // ?CompareComponent@mmIO@@QAEHH@Z
    { 0x4E4FA0, 0x64F9CC41, 0x0000 }, // ?ForceSettingAcrossConfigs@mmIO@@QAEXH@Z
    { 0x4E5060, 0xAA64FBF4, 0x0000 }, // ??0mmIODev@@QAE@XZ
    { 0x4E50A0, 0x8ED1CD3B, 0x0000 }, // ??1mmIODev@@UAE@XZ
    { 0x4E50B0, 0xE493D8FA, 0x0000 }, // ?Init@mmIODev@@QAEXH_J@Z
    { 0x4E50E0, 0xCF9D5593, 0x0000 }, // ?Assign@mmIODev@@QAEXHHH@Z
    { 0x4E5200, 0x5E5F73DE, 0x0000 }, // ??8mmIODev@@QAEHPATeqEvent@@@Z
    { 0x4E5260, 0xBA6EA624, 0x0000 }, // ?ConvertDItoString@@YAHHPADH@Z
    { 0x4E52C0, 0x8EF50AF2, 0x0000 }, // ?GetDescription@mmIODev@@QAEXPAD@Z
    { 0x4E5580, 0x3389A902, 0x0000 }, // ?GetComponentType@mmIODev@@QAEHHH@Z
    { 0x4E55F0, 0x79558B37, 0x0000 }, // ?SanityCheckioType@mmIODev@@QAEHHHH@Z
    { 0x4E5670, 0x0D86185C, 0x0000 }, // ?Print@mmIODev@@QAEXH@Z
    { 0x4E5740, 0x1809DB08, 0x0000 }, // ?Write@mmIODev@@QAEHPAVStream@@@Z
    { 0x4E57A0, 0x4A621B31, 0x0000 }, // ?WriteBinary@mmIODev@@QAEHPAVStream@@@Z
    { 0x4E57F0, 0x72585F6D, 0x0000 }, // ?Read@mmIODev@@QAEHPAVStream@@@Z
    { 0x4E5850, 0x1F66DA17, 0x0000 }, // ?ReadBinary@mmIODev@@QAEHPAVStream@@@Z
    { 0x4E58A0, 0x6F8E1EC4, 0x0000 }, // ?DeclareFields@mmIODev@@SAXXZ
    { 0x4E5A50, 0x1511B9D1, 0x0000 }, // ?GetClass@mmIODev@@UAEPAVMetaClass@@XZ
    { 0x4E5A60, 0xB1913C9F, 0x0000 }, // ?inputEnumDeviceProc@@YGHPAUDIDEVICEINSTANCEA@@PAX@Z
    { 0x4E5A90, 0xBA97AA93, 0x0000 }, // ??0mmJoyMan@@QAE@XZ
    { 0x4E5AA0, 0x66FD6CE3, 0x0000 }, // ??1mmJoyMan@@QAE@XZ
    { 0x4E5AE0, 0x420EA10A, 0x0000 }, // ?Init@mmJoyMan@@QAEHPAUHINSTANCE__@@PAUHWND__@@@Z
    { 0x4E5C40, 0x8ACBCD4B, 0x0000 }, // ?ButtonToBit@mmJoyMan@@QAEHH@Z
    { 0x4E5C70, 0x8B92A4AB, 0x0000 }, // ?QJoystick@mmJoyMan@@QAEHXZ
    { 0x4E5C80, 0x8FB2B709, 0x0000 }, // ?Update@mmJoyMan@@QAEXXZ
    { 0x4E5CB0, 0xBF0029D3, 0x0000 }, // ?GetJoyAxis@mmJoyMan@@QAEMHH@Z
    { 0x4E5CF0, 0xA2245A4E, 0x0000 }, // ?GetJoyButton@mmJoyMan@@QAEHHH@Z
    { 0x4E5D40, 0x95C8B692, 0x0000 }, // ?PollJoyButtons@mmJoyMan@@QAEHXZ
    { 0x4E5DA0, 0x530B9471, 0x0000 }, // ?PollJoyAxes@mmJoyMan@@QAEHXZ
    { 0x4E5DE0, 0x782C3DEC, 0x0000 }, // ?SetCapture@mmJoyMan@@QAEXH@Z
    { 0x4E5E50, 0x39AC2245, 0x0000 }, // ?GetOneButton@mmJoyMan@@QAEHJ@Z
    { 0x4E5E80, 0x3318BD39, 0x0000 }, // ?GetFFEffect@mmJoyMan@@QAEPAVmmEffectFF@@H@Z
    { 0x4E5EB0, 0xBA512C09, 0x0000 }, // ?ToggleEnabled@mmJoyMan@@QAEHH@Z
    { 0x4E5EF0, 0x150E3B51, 0x0000 }, // ?FFPlay@mmJoyMan@@QAEHH@Z
    { 0x4E5F20, 0x7B32371C, 0x0000 }, // ?FFStop@mmJoyMan@@QAEHH@Z
    { 0x4E5F50, 0x06334F80, 0x0000 }, // ?FFIsPlaying@mmJoyMan@@QAEHH@Z
    { 0x4E5F80, 0x0A3B706E, 0x0000 }, // ?FFSetValues@mmJoyMan@@QAEHHMM@Z
    { 0x4E5FC0, 0xBE7B19DD, 0x0000 }, // ?StopAllFF@mmJoyMan@@QAEXXZ
    { 0x4E5FE0, 0x6317E533, 0x0000 }, // ?HasCoolie@mmJoyMan@@QAEHXZ
    { 0x4E6000, 0x268EE07C, 0x0000 }, // ?HasThrottle@mmJoyMan@@QAEHXZ
    { 0x4E6080, 0x1AE645A7, 0x0000 }, // ??0mmJaxis@@QAE@XZ
    { 0x4E60A0, 0xE2FF11B4, 0x0000 }, // ??1mmJaxis@@QAE@XZ
    { 0x4E60B0, 0xF845D253, 0x0000 }, // ?SetRange@mmJaxis@@QAEXMM@Z
    { 0x4E60D0, 0x248523A2, 0x0000 }, // ?Normalize@mmJaxis@@QAEXM@Z
    { 0x4E60F0, 0x3A44579E, 0x0000 }, // ?NormalizePOV@mmJaxis@@QAEXK@Z
    { 0x4E6130, 0xDC2A649C, 0x0000 }, // ?Capture@mmJaxis@@QAEHXZ
    { 0x4E6160, 0x9E3CC057, 0x0000 }, // ?ResetCapture@mmJaxis@@QAEXXZ
    { 0x4E6180, 0x400B995C, 0x0000 }, // ??0mmJoystick@@QAE@XZ
    { 0x4E6240, 0x8F5C1AD5, 0x0000 }, // ??1mmJoystick@@QAE@XZ
    { 0x4E6360, 0x05ADD3A1, 0x0000 }, // ?Init@mmJoystick@@QAEHPAUIDirectInputDevice2A@@PAUHWND__@@@Z
    { 0x4E6470, 0xF911CFB4, 0x0000 }, // ?inputPrepareDevice@mmJoystick@@QAEHXZ
    { 0x4E6620, 0x874DD652, 0x0000 }, // ?SetDeadZone@mmJoystick@@QAEHM@Z
    { 0x4E66C0, 0xEEBDB989, 0x0000 }, // ?DisableAutoCenter@mmJoystick@@QAEHXZ
    { 0x4E6720, 0xEBBB678C, 0x0000 }, // ?Poll@mmJoystick@@QAEKXZ
    { 0x4E6850, 0xC196E838, 0x0000 }, // ?GetAxis@mmJoystick@@QAEMH@Z
    { 0x4E6950, 0xF4384896, 0x0000 }, // ?GetButton@mmJoystick@@QAEMH@Z
    { 0x4E6980, 0xC66A668D, 0x0000 }, // ?Update@mmJoystick@@QAEXXZ
    { 0x4E6A10, 0x3DCA98A1, 0x0000 }, // ?ResetAxisCapture@mmJoystick@@QAEXXZ
    { 0x4E6A90, 0xC3953233, 0x0000 }, // ?InputCreateEffect@mmJoystick@@QAEXXZ
    { 0x4E6BB0, 0xA1C940FE, 0x0000 }, // ?InputInitEffect@mmJoystick@@QAEXXZ
    { 0x4E6BF0, 0x108EB489, 0x0000 }, // ?InputStopEffect@mmJoystick@@QAEXXZ
    { 0x4E6C30, 0x9D5208DF, 0x0000 }, // ?SetShake@mmJoystick@@QAEHKK@Z
    { 0x4E6C60, 0xFC19B055, 0x0000 }, // ?PlayShake@mmJoystick@@QAEHXZ
    { 0x4E6C80, 0x7954F916, 0x0000 }, // ?StopShake@mmJoystick@@QAEHXZ
    { 0x4E6CA0, 0x06C74E14, 0x0000 }, // ?PlayCollision@mmJoystick@@QAEHXZ
    { 0x4E6CC0, 0x83C39CB9, 0x0000 }, // ?SetSteer@mmJoystick@@QAEHJ@Z
    { 0x4E6CE0, 0x59DD0591, 0x0000 }, // ?PlaySteer@mmJoystick@@QAEHXZ
    { 0x4E6D00, 0xEE44D31E, 0x0000 }, // ?StopSteer@mmJoystick@@QAEHXZ
    { 0x4E6D20, 0x411E6E9D, 0x0000 }, // ?SetFriction@mmJoystick@@QAEHJ@Z
    { 0x4E6D40, 0xD651A02B, 0x0000 }, // ?PlayFriction@mmJoystick@@QAEHXZ
    { 0x4E6D60, 0x1447135C, 0x0000 }, // ?StopFriction@mmJoystick@@QAEHXZ
    { 0x4E6D80, 0x52A91A23, 0x0000 }, // ?GetFFEffect@mmJoystick@@QAEPAVmmEffectFF@@H@Z
    { 0x4E6DD0, 0x5A3474A9, 0x0000 }, // ?PrintDeviceCaps@mmJoystick@@QAEXXZ
    { 0x4E6FB0, 0xDC1D803C, 0x0000 }, // ?DecodeDIErrorMFlag@@YAXJ@Z
    { 0x4E7310, 0xBD038822, 0x0000 }, // ?AngelReadKeyString@@YAPAULocString@@I@Z
    { 0x4E7350, 0x66EE43DE, 0x0000 }, // ?inputEnumEffectTypeProc@@YGHPBUDIEFFECTINFOA@@PAX@Z
    { 0x4E73B0, 0x59011C17, 0x0000 }, // ??0mmEffectFF@@QAE@XZ
    { 0x4E7420, 0xB335D80E, 0x0000 }, // ??1mmEffectFF@@QAE@XZ
    { 0x4E7440, 0xBD7DEAF2, 0x0000 }, // ?Play@mmEffectFF@@UAEHXZ
    { 0x4E7450, 0x51228044, 0x0000 }, // ?Stop@mmEffectFF@@UAEHXZ
    { 0x4E7460, 0x2AEDD383, 0x0000 }, // ?SetValues@mmEffectFF@@UAEHMM@Z
    { 0x4E7470, 0x4A5673B7, 0x0000 }, // ?Init@mmCollideFF@@UAEHPAUIDirectInputDevice2A@@@Z
    { 0x4E7630, 0x7701CE83, 0x0000 }, // ?SetValues@mmCollideFF@@UAEHMM@Z
    { 0x4E7660, 0xD98DFE5D, 0x0000 }, // ?Assign@mmCollideFF@@QAEHJJ@Z
    { 0x4E7760, 0xDA9C33C5, 0x0000 }, // ?Play@mmCollideFF@@UAEHXZ
    { 0x4E77B0, 0x48B42FDA, 0x0000 }, // ?Stop@mmCollideFF@@UAEHXZ
    { 0x4E77C0, 0xD313A031, 0x0000 }, // ?Init@mmRoadFF@@UAEHPAUIDirectInputDevice2A@@@Z
    { 0x4E78C0, 0x00EE5A96, 0x0000 }, // ?SetValues@mmRoadFF@@UAEHMM@Z
    { 0x4E78F0, 0xD4BA5633, 0x0000 }, // ?Assign@mmRoadFF@@QAEHJJ@Z
    { 0x4E79E0, 0x088A7279, 0x0000 }, // ?Play@mmRoadFF@@UAEHXZ
    { 0x4E7A50, 0x5075D7BE, 0x0000 }, // ?Stop@mmRoadFF@@UAEHXZ
    { 0x4E7AA0, 0xE23195CB, 0x0000 }, // ?Init@mmFrictionFF@@UAEHPAUIDirectInputDevice2A@@@Z
    { 0x4E7BB0, 0x4CC1ACB1, 0x0000 }, // ?SetValues@mmFrictionFF@@UAEHMM@Z
    { 0x4E7BE0, 0x0623353C, 0x0000 }, // ?Assign@mmFrictionFF@@QAEHJ@Z
    { 0x4E7CB0, 0x44E64372, 0x0000 }, // ?Play@mmFrictionFF@@UAEHXZ
    { 0x4E7D10, 0x42CB8C98, 0x0000 }, // ?Stop@mmFrictionFF@@UAEHXZ
    { 0x4E7D50, 0xAA3FF959, 0x0000 }, // ?Init@mmSpringFF@@UAEHPAUIDirectInputDevice2A@@@Z
    { 0x4E7E50, 0xFAFBDDA8, 0x0000 }, // ?SetValues@mmSpringFF@@UAEHMM@Z
    { 0x4E7E80, 0xBBC11E20, 0x0000 }, // ?Assign@mmSpringFF@@QAEHJ@Z
    { 0x4E7F70, 0xD65FBFB2, 0x0000 }, // ?Play@mmSpringFF@@UAEHXZ
    { 0x4E7FE0, 0x945A3375, 0x0000 }, // ?Stop@mmSpringFF@@UAEHXZ
    { 0x4E8020, 0xBF83B716, 0x0000 }, // ??0AudManager@@QAE@XZ
    { 0x4E8160, 0x4600EF95, 0x0000 }, // ??1AudManager@@UAE@XZ
    { 0x4E82A0, 0x2A106663, 0x0000 }, // ?DeallocateADFRecord@AudManager@@QAEXH@Z
    { 0x4E82D0, 0x698AE178, 0x0000 }, // ?SetNumChannels@AudManager@@QAEXH@Z
    { 0x4E8390, 0xFDD6BB9B, 0x0000 }, // ?CheckPriority@AudManager@@QAEHHHH@Z
    { 0x4E8630, 0x04799180, 0x0000 }, // ?RemoveSoundFromPlayList@AudManager@@QAEXPAVAudSound@@@Z
    { 0x4E8670, 0x40CB8159, 0x0000 }, // ?RemoveSoundFromPlayList@AudManager@@QAEXH@Z
    { 0x4E86C0, 0x07DAB56B, 0x0000 }, // ?Update@AudManager@@UAEXXZ
    { 0x4E86F0, 0x5966608B, 0x0000 }, // ?Init@AudManager@@QAEXHIPADFF@Z
    { 0x4E8820, 0xA7BBEEE1, 0x0000 }, // ?LoadUIADF@AudManager@@QAEXXZ
    { 0x4E8880, 0xC0701604, 0x0000 }, // ?LoadCityADF@AudManager@@QAEXHK@Z
    { 0x4E8930, 0xE7FF00DE, 0x0000 }, // ?InitCityADF@AudManager@@QAEXHK@Z
    { 0x4E89E0, 0x9FB662EA, 0x0000 }, // ?InitUIADF@AudManager@@QAEXHK@Z
    { 0x4E8A70, 0x5B4A563A, 0x0000 }, // ?DeallocateUIADF@AudManager@@QAEXXZ
    { 0x4E8A80, 0xE4B2FCDB, 0x0000 }, // ?DeallocateCityADF@AudManager@@QAEXXZ
    { 0x4E8A90, 0x4DFC6F9A, 0x0000 }, // ?DeallocateDSound@AudManager@@QAEXFF@Z
    { 0x4E8C10, 0xFFC55B33, 0x0000 }, // ?ReallocateDSound@AudManager@@QAEXPADFF@Z
    { 0x4E8DA0, 0xEA9DEBF2, 0x0000 }, // ?SetStereo@AudManager@@QAEXH@Z
    { 0x4E8DD0, 0x97BE9364, 0x0000 }, // ?AttenuateAudSounds@AudManager@@QAEXM@Z
    { 0x4E8E40, 0x468EE92D, 0x0000 }, // ?AddSound@AudManager@@QAEHPAVAudSound@@@Z
    { 0x4E8EA0, 0x3DCBC327, 0x0000 }, // ?AddStream@AudManager@@QAEHPAVAudStream@@@Z
    { 0x4E8EF0, 0x61181327, 0x0000 }, // ?RemoveSound@AudManager@@QAEXPAVAudSound@@H@Z
    { 0x4E8F60, 0x088F3947, 0x0000 }, // ?RemoveStream@AudManager@@QAEXPAVAudStream@@H@Z
    { 0x4E8FD0, 0x165A64B8, 0x0000 }, // ?Reset@AudManager@@UAEXXZ
    { 0x4E8FE0, 0x7B3F1515, 0x0000 }, // ?Enable@AudManager@@QAEXPADFF@Z
    { 0x4E9090, 0x714190B4, 0x0000 }, // ?Disable@AudManager@@QAEXFF@Z
    { 0x4E9180, 0x8560FE36, 0x0000 }, // ?StopAllSounds@AudManager@@QAEXXZ
    { 0x4E9220, 0x4E2ECF4E, 0x0000 }, // ?ZeroVolAllSounds@AudManager@@QAEXXZ
    { 0x4E9230, 0x3FA38AEF, 0x0000 }, // ?PlayCDTrack@AudManager@@QAEHHH@Z
    { 0x4E92B0, 0xA6CB77E9, 0x0000 }, // ?PlayCDTrack@AudManager@@QAEHHEEEH@Z
    { 0x4E9340, 0x30DE6903, 0x0000 }, // ?ResumeCDPlay@AudManager@@QAEHXZ
    { 0x4E9360, 0x4AF2E7DB, 0x0000 }, // ?GetNumCDTracks@AudManager@@QAEFXZ
    { 0x4E9380, 0x78144EBF, 0x0000 }, // ?GetCDTrackNum@AudManager@@QAEEXZ
    { 0x4E93A0, 0xE52FA82A, 0x0000 }, // ?CDIsPlaying@AudManager@@QAEFXZ
    { 0x4E93C0, 0x8FE73A12, 0x0000 }, // ?DisableCD@AudManager@@QAEXXZ
    { 0x4E93E0, 0x5F17949B, 0x0000 }, // ?StopCD@AudManager@@QAEXXZ
    { 0x4E9400, 0x077852E5, 0x0000 }, // ?EnableCD@AudManager@@QAEHXZ
    { 0x4E9430, 0x3C15A827, 0x0000 }, // ?AssignWaveVolume@AudManager@@QAEXM@Z
    { 0x4E9450, 0xD208B9E0, 0x0000 }, // ?GetWaveVolume@AudManager@@QAEMXZ
    { 0x4E9470, 0x6C5E1AB4, 0x0000 }, // ?AssignCDVolume@AudManager@@QAEXM@Z
    { 0x4E94B0, 0xA690315B, 0x0000 }, // ?SetCDPlayMode@AudManager@@QAEXE@Z
    { 0x4E94E0, 0xE4BF7EFA, 0x0000 }, // ?CDIsEnabled@AudManager@@QAEHXZ
    { 0x4E9500, 0xC45632F7, 0x0000 }, // ?GetCDVolume@AudManager@@QAEMXZ
    { 0x4E9530, 0x51FC9382, 0x0000 }, // ?AttenuateCDVolume@AudManager@@QAEXM@Z
    { 0x4E9570, 0x00CA522A, 0x0000 }, // ?AssignWaveBalance@AudManager@@QAEXM@Z
    { 0x4E9590, 0x13C5E26D, 0x0000 }, // ?GetWaveBalance@AudManager@@QAEMXZ
    { 0x4E95B0, 0x298A56CC, 0x0000 }, // ?AssignCDBalance@AudManager@@QAEXM@Z
    { 0x4E95D0, 0x0B45F690, 0x0000 }, // ?GetCDBalance@AudManager@@QAEMXZ
    { 0x4E9600, 0x7D8831E1, 0x0000 }, // ?IsStereo@AudManager@@QAEHXZ
    { 0x4E9610, 0x2ABEC2FA, 0x0000 }, // ?AddWidgets@AudManager@@UAEXPAVBank@@@Z
    { 0x4E9620, 0x92D20821, 0x0000 }, // ?Supports16Bit@AudManager@@QAEFXZ
    { 0x4E9630, 0xF7AC4A14, 0x0000 }, // ?CheckCDFile@AudManager@@QAEEPAD@Z
    { 0x4E9650, 0xCAA54269, 0x0000 }, // ?Update3DCDMusic@AudManager@@AAEXXZ
    { 0x4E97B0, 0x44C1B668, 0x0000 }, // ?GetUsingEAXMask@AudManager@@SA?BIXZ
    { 0x4E97C0, 0x83B0AB81, 0x0000 }, // ?IsAlwaysEAX@AudManager@@QAEIXZ
    { 0x4E97D0, 0xD5A97CC5, 0x0000 }, // ?AlwaysEAX@AudManager@@QAEXI@Z
    { 0x4E9800, 0xBEFF66AC, 0x0000 }, // ?EAXEnabled@AudManager@@QAEIXZ
    { 0x4E9810, 0xBB989927, 0x0000 }, // ?DSound3DEnabled@AudManager@@QAEIXZ
    { 0x4E9820, 0xAA9AC583, 0x0000 }, // ?CreateListenerSoundObj@AudManager@@AAEIXZ
    { 0x4E9960, 0x6A3C720B, 0x0000 }, // ?GetListenerEAXObj@AudManager@@AAEPAVCReverb@@XZ
    { 0x4E9970, 0xA0096405, 0x0000 }, // ?SetEAXPreset@AudManager@@QAEHKMMM@Z
    { 0x4E99F0, 0xBEC2D2F3, 0x0000 }, // ?SetEAXPreset@AudManager@@QAEHPAUEAX_REVERBPROPERTIES@@@Z
    { 0x4E9A60, 0xDCA4B42E, 0x0000 }, // ?GetEAXAll@AudManager@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    { 0x4E9AB0, 0xDE57D66F, 0x0000 }, // ?SetEAXEnvironmet@AudManager@@QAEHK@Z
    { 0x4E9B20, 0x8B110AD0, 0x0000 }, // ?GetEAXEnvironmet@AudManager@@QAEKXZ
    { 0x4E9B70, 0x8AA38225, 0x0000 }, // ?SetEAXReverbVolume@AudManager@@QAEHM@Z
    { 0x4E9BE0, 0xDA889377, 0x0000 }, // ?GetEAXReverbVolume@AudManager@@QAEMXZ
    { 0x4E9C30, 0x4D8A0859, 0x0000 }, // ?SetEAXDecayTime@AudManager@@QAEHM@Z
    { 0x4E9CA0, 0x63CC7AC4, 0x0000 }, // ?GetEAXDecayTime@AudManager@@QAEMXZ
    { 0x4E9CF0, 0xEF41B817, 0x0000 }, // ?SetEAXDamping@AudManager@@QAEHM@Z
    { 0x4E9D60, 0x30A7E1AC, 0x0000 }, // ?GetEAXDamping@AudManager@@QAEMXZ
    { 0x4E9DB0, 0x5DE15E17, 0x0000 }, // ?UpdatePaused@AudManager@@UAEXXZ
    { 0x4E9DD0, 0x1F23C853, 0x0000 }, // ?SetBitDepthAndSampleRate@AudManager@@QAEXHK@Z
    { 0x4E9E60, 0x58CD0DFC, 0x0000 }, // ?GetDeviceNames@AudManager@@QAEPAPADXZ
    { 0x4E9E80, 0xF78E0FE1, 0x0000 }, // ?GetNumDevices@AudManager@@QAEHXZ
    { 0x4E9EA0, 0x6210ABD4, 0x0000 }, // ?GetActiveDeviceName@AudManager@@QAEPADXZ
    { 0x4E9EC0, 0x9E78B6BB, 0x0000 }, // ?GetNum3DHalBufs@AudManager@@QAEKXZ
    { 0x4E9ED0, 0x364BB241, 0x0000 }, // ?GetStereoOnMask@AudManager@@SA?BIXZ
    { 0x4E9EE0, 0x625F797E, 0x0000 }, // ?GetHiResMask@AudManager@@SA?BIXZ
    { 0x4E9EF0, 0x2459C453, 0x0000 }, // ?GetHiSampleSizeMask@AudManager@@SA?BIXZ
    { 0x4E9F00, 0xDBD692F5, 0x0000 }, // ?GetEchoOnMask@AudManager@@SA?BIXZ
    { 0x4E9F10, 0x25BFBA09, 0x0000 }, // ?GetDSound3DMask@AudManager@@SA?BIXZ
    { 0x4E9F20, 0x03B05169, 0x0000 }, // ?GetSoundFXOnMask@AudManager@@SA?BIXZ
    { 0x4E9F30, 0xB82B5DE6, 0x0000 }, // ?GetCDMusicOnMask@AudManager@@SA?BIXZ
    { 0x4E9F40, 0x2E7A966D, 0x0000 }, // ?GetCommentaryOnMask@AudManager@@SA?BIXZ
    { 0x4E9F50, 0x8BC4F07F, 0x0000 }, // ?SetDeviceName@AudManager@@QAEXPAD@Z
    { 0x4E9F90, 0xD50D47FC, 0x0000 }, // ?GetCDPosition@AudManager@@QAEKPAE000@Z
    { 0x4E9FD0, 0xAD7E0FF4, 0x0000 }, // ?GetMixerPtr@AudManager@@QAEPAVMixerCTL@@XZ
    { 0x4E9FE0, 0x7464C52E, 0x0000 }, // ?GetVoiceCommentaryPtr@AudManager@@QAEPAVmmVoiceCommentary@@XZ
    { 0x4E9FF0, 0x0F55FE9C, 0x0000 }, // ?SetVoiceCommentaryPtr@AudManager@@QAEXPAVmmVoiceCommentary@@@Z
    { 0x4EA000, 0x1C8C0D39, 0x0000 }, // ?DeactivateApplication@@YAXXZ
    { 0x4EA040, 0x020BA178, 0x0000 }, // ?RestoreApplication@@YAXXZ
    { 0x4EA070, 0x347D0786, 0x0000 }, // ?DeclareFields@AudManager@@SAXXZ
    { 0x4EA1E0, 0x9DD91E69, 0x0000 }, // ?GetClass@AudManager@@UAEPAVMetaClass@@XZ
    { 0x4EA250, 0x56E2D5E1, 0x0000 }, // ??0AudSound@@QAE@KHF@Z
    { 0x4EA530, 0x43C3B8B0, 0x0000 }, // ??1AudSound@@UAE@XZ
    { 0x4EA670, 0x7B466D69, 0x0000 }, // ?SetPriority@AudSound@@QAEXH@Z
    { 0x4EA690, 0xF8CB326F, 0x0000 }, // ?DeallocateSoundObjs@AudSound@@QAEXXZ
    { 0x4EA6F0, 0x0BFFB350, 0x0000 }, // ?ReallocateSoundObjs@AudSound@@QAEXXZ
    { 0x4EA8D0, 0xA16A4F57, 0x0000 }, // ?Load@AudSound@@QAEHPADH@Z
    { 0x4EAB20, 0x8E8C5CDA, 0x0000 }, // ?Load@AudSound@@QAEHHH@Z
    { 0x4EAD10, 0xD602371F, 0x0000 }, // ?EnabledAction@AudSound@@QAEXXZ
    { 0x4EAD30, 0x3BE49B26, 0x0000 }, // ?Enable@AudSound@@QAEXXZ
    { 0x4EAD40, 0x6C59EC6F, 0x0000 }, // ?Disable@AudSound@@QAEXXZ
    { 0x4EAD60, 0xD705C323, 0x0000 }, // ?Reset@AudSound@@UAEXXZ
    { 0x4EAD70, 0x169B7F2E, 0x0000 }, // ?Update@AudSound@@UAEXXZ
    { 0x4EAE00, 0x5669F375, 0x0000 }, // ?Update3DSettings@AudSound@@QAEXXZ
    { 0x4EAFC0, 0xE364A2EC, 0x0000 }, // ?SetPlayPosition@AudSound@@QAEXK@Z
    { 0x4EAFF0, 0x7943BF8E, 0x0000 }, // ?PlayOnce@AudSound@@QAEXMM@Z
    { 0x4EB0D0, 0x4AF6BE52, 0x0000 }, // ?PlayLoop@AudSound@@QAEXMM@Z
    { 0x4EB1B0, 0xA0F3F0F6, 0x0000 }, // ?Stop@AudSound@@QAEXXZ
    { 0x4EB1F0, 0x3FECFA88, 0x0000 }, // ?StopEchoBuffers@AudSound@@QAEXXZ
    { 0x4EB210, 0x9B18EE1B, 0x0000 }, // ?SetFrequency@AudSound@@QAEXMH@Z
    { 0x4EB290, 0xB9BF8412, 0x0000 }, // ?GetFrequency@AudSound@@QAEMH@Z
    { 0x4EB2D0, 0xE4623944, 0x0000 }, // ?SetVolume@AudSound@@QAEXMH@Z
    { 0x4EB350, 0x672E6717, 0x0000 }, // ?SetEAXReverbMix@AudSound@@QAEXMH@Z
    { 0x4EB3B0, 0x0541CDCA, 0x0000 }, // ?GetEAXReverbMix@AudSound@@QAEMH@Z
    { 0x4EB410, 0x81E5B669, 0x0000 }, // ?SetPan@AudSound@@QAEXMH@Z
    { 0x4EB4B0, 0x3F9C0099, 0x0000 }, // ?SetEchoPan@AudSound@@QAEXM@Z
    { 0x4EB510, 0x70A390E8, 0x0000 }, // ?SetEchoFrequency@AudSound@@QAEXMH@Z
    { 0x4EB580, 0xDA13C2E8, 0x0000 }, // ?SetRamp@AudSound@@QAEXMM@Z
    { 0x4EB660, 0xE8D7F6AF, 0x0000 }, // ?Set3DMode@AudSound@@QAEXK@Z
    { 0x4EB690, 0x214B4A60, 0x0000 }, // ?IsPlaying@AudSound@@QAEHH@Z
    { 0x4EB6C0, 0xC051AC73, 0x0000 }, // ?GetSampleTime@AudSound@@QAEMXZ
    { 0x4EB6E0, 0x6F7C6F58, 0x0000 }, // ?AddWidgets@AudSound@@UAEXPAVBank@@@Z
    { 0x4EB730, 0xC40F62DF, 0x0000 }, // ?SetConeAngles@AudSound@@QAEXKK@Z
    { 0x4EB760, 0x03B944AB, 0x0000 }, // ?SetConeOutsideVolume@AudSound@@QAEXJ@Z
    { 0x4EB790, 0xAA3E3B50, 0x0000 }, // ?SetConeOrientation@AudSound@@QAEXPAVVector3@@@Z
    { 0x4EB7C0, 0x4105ED36, 0x0000 }, // ?SetEchoAttenuation@AudSound@@QAEXM@Z
    { 0x4EB800, 0xAE7062FC, 0x0000 }, // ?EchoPending@AudSound@@QAEEXZ
    { 0x4EB820, 0x639E1B7D, 0x0000 }, // ?SetChorusAttenuation@AudSound@@QAEXM@Z
    { 0x4EB860, 0xD529BF08, 0x0000 }, // ?SetChorusPitchMult@AudSound@@QAEXM@Z
    { 0x4EB8A0, 0x760F2C36, 0x0000 }, // ?SetChorusPitchMult@AudSound@@QAEXMM@Z
    { 0x4EB8F0, 0xC48767E2, 0x0000 }, // ?SetDelayTime@AudSound@@QAEXM@Z
    { 0x4EB940, 0x361DBE4F, 0x0000 }, // ?SetupOneShotLayerBuffers@AudSound@@QAEXHMH@Z
    { 0x4EB9B0, 0xC4655803, 0x0000 }, // ?ReadyOneShotLayerBuf@AudSound@@QAEHXZ
    { 0x4EB9E0, 0x99916164, 0x0000 }, // ?AllOneShotLayersPlaying@AudSound@@QAEHXZ
    { 0x4EBA10, 0x24BCECF1, 0x0000 }, // ?GetEffect@AudSound@@QAEHXZ
    { 0x4EBA30, 0x6AAD1345, 0x0000 }, // ?SetEffect@AudSound@@QAEXH@Z
    { 0x4EBAA0, 0x20A333C4, 0x0000 }, // ?DisableEffect@AudSound@@QAEXH@Z
    { 0x4EBAF0, 0xC48F968F, 0x0000 }, // ?Get2DFlags@AudSound@@SA?BKXZ
    { 0x4EBB10, 0x14B19D9C, 0x0000 }, // ?GetSoft2DFlags@AudSound@@SA?BKXZ
    { 0x4EBB30, 0xB12D4863, 0x0000 }, // ?GetFreqChange2DFlags@AudSound@@SA?BKXZ
    { 0x4EBB50, 0x6859B5A5, 0x0000 }, // ?GetSoftFreqChange2DFlags@AudSound@@SA?BKXZ
    { 0x4EBB70, 0x883E6F62, 0x0000 }, // ?Get3DFlags@AudSound@@SA?BKXZ
    { 0x4EBB80, 0x4456D906, 0x0000 }, // ?GetFreqChange3DFlags@AudSound@@SA?BKXZ
    { 0x4EBB90, 0x75C1B009, 0x0000 }, // ?GetSecondaryEAXObj@AudSound@@QAEPAVCReverbBuffer@@H@Z
    { 0x4EBBC0, 0x7FA7CC2F, 0x0000 }, // ?Enable3DMode@AudSound@@QAEXXZ
    { 0x4EBC00, 0x616E9000, 0x0000 }, // ?Disable3DMode@AudSound@@QAEXXZ
    { 0x4EBC40, 0xC598D99C, 0x0000 }, // ?GetCurrentSoundObj@AudSound@@QAEPAVSoundObj@@XZ
    { 0x4EBC50, 0x701EAFF7, 0x0000 }, // ?GetVolume@AudSound@@QAEMH@Z
    { 0x4EBCB0, 0x881AF7F6, 0x0000 }, // ??0AudHead@@QAE@PAVMatrix34@@@Z
    { 0x4EBD00, 0xB54764A0, 0x0000 }, // ??1AudHead@@UAE@XZ
    { 0x4EBD10, 0x743D1B3E, 0x0000 }, // ?Init@AudHead@@QAEHXZ
    { 0x4EBD60, 0xE9ACAB39, 0x0000 }, // ?Update@AudHead@@EAEXXZ
    { 0x4EBEE0, 0x1901D472, 0x0000 }, // ?WidgetSetRolloff@AudHead@@QAEXXZ
    { 0x4EBEF0, 0x0FE5D647, 0x0000 }, // ?AddWidgets@AudHead@@UAEXPAVBank@@@Z
    { 0x4EBF50, 0x3C87B362, 0x0000 }, // ?SetRolloff@AudHead@@QAEXM@Z
    { 0x4EBFB0, 0x8510165C, 0x0000 }, // ?SetDoppler@AudHead@@QAEXM@Z
    { 0x4EC010, 0x2B95690D, 0x0000 }, // ?GetPositionPtr@AudHead@@QAEPAVVector3@@XZ
    { 0x4EC020, 0xAF20B9F8, 0x0000 }, // ?SetHeadPtr@AudHead@@QAEXPAVMatrix34@@@Z
    { 0x4EC030, 0xB04B9E69, 0x0000 }, // ?GetHeadPtr@AudHead@@QAEPAVMatrix34@@XZ
    { 0x4EC070, 0x3D95C3AE, 0x0000 }, // ??0mmVoiceCommentary@@QAE@XZ
    { 0x4EC110, 0x682211C4, 0x0000 }, // ??1mmVoiceCommentary@@QAE@XZ
    { 0x4EC130, 0x3C334A45, 0x0000 }, // ?ValidateCity@mmVoiceCommentary@@QAEXPAD@Z
    { 0x4EC170, 0x033131C7, 0x0000 }, // ?SetFrequency@mmVoiceCommentary@@QAEXM@Z
    { 0x4EC190, 0x40F9E482, 0x0000 }, // ?Stop@mmVoiceCommentary@@QAEXXZ
    { 0x4EC1A0, 0xADEEA666, 0x0000 }, // ?StopNow@mmVoiceCommentary@@QAEXXZ
    { 0x4EC1F0, 0xFA744885, 0x0000 }, // ?PlayAirBorne@mmVoiceCommentary@@QAEXXZ
    { 0x4EC260, 0x732FCEAB, 0x0000 }, // ?PlayRoam@mmVoiceCommentary@@QAEXXZ
    { 0x4EC2D0, 0x03F66C89, 0x0000 }, // ?PlayCheckPoint@mmVoiceCommentary@@QAEXXZ
    { 0x4EC320, 0x1FBE4C53, 0x0000 }, // ?PlayFinalCheckPoint@mmVoiceCommentary@@QAEXXZ
    { 0x4EC390, 0xC1912F34, 0x0000 }, // ?PlayLap@mmVoiceCommentary@@QAEXF@Z
    { 0x4EC3A0, 0x27109CB0, 0x0000 }, // ?PlayFinalLap@mmVoiceCommentary@@QAEXXZ
    { 0x4EC410, 0x216C01B1, 0x0000 }, // ?Play@mmVoiceCommentary@@QAEXPAD@Z
    { 0x4EC460, 0xD5B56FAD, 0x0000 }, // ?PlayPreRace@mmVoiceCommentary@@QAEXXZ
    { 0x4EC4D0, 0x7477CAFC, 0x0000 }, // ?GetRandomPreRace@mmVoiceCommentary@@QAEPADXZ
    { 0x4EC650, 0x527FFF0C, 0x0000 }, // ?GetRandomPreBlitz@mmVoiceCommentary@@QAEPADXZ
    { 0x4EC730, 0x68B51B08, 0x0000 }, // ?GetRandomPreCircuit@mmVoiceCommentary@@QAEPADXZ
    { 0x4EC810, 0xF5B96D32, 0x0000 }, // ?GetRandomPreCheckPoint@mmVoiceCommentary@@QAEPADXZ
    { 0x4EC920, 0x426E2147, 0x0000 }, // ?PlayWinResults@mmVoiceCommentary@@QAEXXZ
    { 0x4EC990, 0x7DADB5A1, 0x0000 }, // ?PlayMidResults@mmVoiceCommentary@@QAEXXZ
    { 0x4ECA00, 0x8BEF9119, 0x0000 }, // ?PlayResults@mmVoiceCommentary@@QAEXF@Z
    { 0x4ECA70, 0xD9AEDDAC, 0x0000 }, // ?GetRandomResults@mmVoiceCommentary@@QAEPADF@Z
    { 0x4ECB50, 0x6350F615, 0x0000 }, // ?GetRandomPreRaceVeh@mmVoiceCommentary@@QAEPADXZ
    { 0x4ECBB0, 0xF81440A5, 0x0000 }, // ?GetRandomResultsWin@mmVoiceCommentary@@QAEPADXZ
    { 0x4ECD50, 0xD82C4D67, 0x0000 }, // ?GetRandomResultsPoor@mmVoiceCommentary@@QAEPADXZ
    { 0x4ECEF0, 0x885E9E28, 0x0000 }, // ?GetRandomResultsMid@mmVoiceCommentary@@QAEPADXZ
    { 0x4ED090, 0xF4DDF91E, 0x0000 }, // ?GetRandomTOD@mmVoiceCommentary@@QAEPADXZ
    { 0x4ED0F0, 0x0143FCA8, 0x0000 }, // ?GetRandomWeather@mmVoiceCommentary@@QAEPADXZ
    { 0x4ED190, 0xD0568843, 0x0000 }, // ?CatName@mmVoiceCommentary@@QAEPADPADHH@Z
    { 0x4ED390, 0x46A87B4E, 0x0000 }, // ?GetLapName@mmVoiceCommentary@@QAEPADF@Z
    { 0x4ED450, 0x4DB53810, 0x0000 }, // ?PlayNetworkPreRace@mmVoiceCommentary@@QAEXXZ
    { 0x4ED4C0, 0xE30BD2D4, 0x0000 }, // ?PlayCRPreRace@mmVoiceCommentary@@QAEXXZ
    { 0x4ED5C0, 0xE69E275C, 0x0000 }, // ?PlayCollision@mmVoiceCommentary@@QAEXXZ
    { 0x4ED630, 0x3B369AB8, 0x0000 }, // ?PlayCR@mmVoiceCommentary@@QAEXFF@Z
    { 0x4ED6C0, 0x7AE97E16, 0x0000 }, // ?PlayTeamCR@mmVoiceCommentary@@QAEXFF@Z
    { 0x4ED730, 0x2E87950D, 0x0000 }, // ?GetRandomRobber@mmVoiceCommentary@@QAEPADF@Z
    { 0x4ED7B0, 0x16D93A37, 0x0000 }, // ?GetRandomRedCR@mmVoiceCommentary@@QAEPADF@Z
    { 0x4ED830, 0x79784231, 0x0000 }, // ?GetRandomBlueCR@mmVoiceCommentary@@QAEPADF@Z
    { 0x4ED8B0, 0xF1633041, 0x0000 }, // ?GetRandomCop@mmVoiceCommentary@@QAEPADF@Z
    { 0x4ED930, 0x47CC0775, 0x0000 }, // ?PlayOpponentFinish@mmVoiceCommentary@@QAEXF@Z
    { 0x4EDA90, 0xC0D5D286, 0x0000 }, // ?PlayTimePenalty@mmVoiceCommentary@@QAEXXZ
    { 0x4EDB60, 0x50A6A64E, 0x0000 }, // ?PlayEndRaceDamage@mmVoiceCommentary@@QAEXXZ
    { 0x4EDBD0, 0xF52914E7, 0x0000 }, // ?PlayUnlock@mmVoiceCommentary@@QAEXH@Z
    { 0x4EDC20, 0x80064FB6, 0x0000 }, // ?PlayGTUnlocked@mmVoiceCommentary@@QAEXXZ
    { 0x4EDC80, 0x730CEFF0, 0x0000 }, // ?PlayBusUnlocked@mmVoiceCommentary@@QAEXXZ
    { 0x4EDCE0, 0xE644E6D2, 0x0000 }, // ?PlayCopCarUnlocked@mmVoiceCommentary@@QAEXXZ
    { 0x4EDDE0, 0x97A12D0A, 0x0000 }, // ?PlayBulletUnlocked@mmVoiceCommentary@@QAEXXZ
    { 0x4EDE40, 0x49B90CD2, 0x0000 }, // ?PlaySemiUnlocked@mmVoiceCommentary@@QAEXXZ
    { 0x4EDEA0, 0x5F2A8DD6, 0x0000 }, // ?PlayNextRacesUnlocked@mmVoiceCommentary@@QAEXXZ
    { 0x4EDF70, 0x92725E72, 0x0000 }, // ?Update@mmVoiceCommentary@@QAEXXZ
    { 0x4EE040, 0x931DA374, 0x0000 }, // ?Set@VolumeDW@@QAEXMM@Z
    { 0x4EE110, 0xA306E3D2, 0x0000 }, // ?Value@VolumeDW@@QAEKXZ
    { 0x4EE140, 0xEFFF7601, 0x0000 }, // ?Init@MixerCTL@@QAEKXZ
    { 0x4EE180, 0x4FCC37F5, 0x0000 }, // ??1MixerCTL@@UAE@XZ
    { 0x4EE1F0, 0x5C19C41F, 0x0000 }, // ?AssignWaveBalance@MixerCTL@@QAEXM@Z
    { 0x4EE240, 0xC614B13A, 0x0000 }, // ?AssignCDBalance@MixerCTL@@QAEXM@Z
    { 0x4EE290, 0x7E03CD0E, 0x0000 }, // ?RefreshAll@MixerCTL@@QAEXK@Z
    { 0x4EE2A0, 0x96F8F52F, 0x0000 }, // ?GetWaveBalance@MixerCTL@@QAEMXZ
    { 0x4EE2B0, 0x587D001A, 0x0000 }, // ?GetWaveVolume@MixerCTL@@QAEMXZ
    { 0x4EE2C0, 0xE103072B, 0x0000 }, // ?AssignWaveVolume@MixerCTL@@QAEXM@Z
    { 0x4EE2E0, 0xA8A1E8D6, 0x0000 }, // ?AssignCDVolume@MixerCTL@@QAEXM@Z
    { 0x4EE300, 0xCDDA492F, 0x0000 }, // ?GetCDBalance@MixerCTL@@QAEMXZ
    { 0x4EE310, 0xCC08C81A, 0x0000 }, // ?GetCDVolume@MixerCTL@@QAEMXZ
    { 0x4EE320, 0x34A406DC, 0x0000 }, // ?AssignMixerVolume@MixerCTL@@QAEKMK@Z
    { 0x4EE580, 0xC1CEC285, 0x0000 }, // ?AssignMixerBalance@MixerCTL@@QAEKMK@Z
    { 0x4EE830, 0xB41BA466, 0x0000 }, // ?GetMixerBalance@MixerCTL@@QAEMK@Z
    { 0x4EEAB0, 0x6BC5655C, 0x0000 }, // ?SetDeviceNum@MixerCTL@@QAEXI@Z
    { 0x4EEAD0, 0xE5C6B5AB, 0x0000 }, // ?GetErrorMessage@MixerCTL@@AAEPADK@Z
    { 0x4EEB70, 0xB79FCA57, 0x0000 }, // ?WindowProc@MixerCTL@@EAEJPAUHWND__@@IIJ@Z
    { 0x4EEB80, 0xF20B5287, 0x0000 }, // ??1VolumeDW@@QAE@XZ
    { 0x4EEBC0, 0xA1DB737A, 0x0000 }, // ??0DupBuffCreator@@QAE@XZ
    { 0x4EEC00, 0xDB98BCB3, 0x0000 }, // ??1DupBuffCreator@@QAE@XZ
    { 0x4EEC60, 0x7DA64169, 0x0000 }, // ?Create@DupBuffCreator@@QAEPAUIDirectSoundBuffer@@PADPAFPAH@Z
    { 0x4EED60, 0xAFDAE243, 0x0000 }, // ?Add@DupBuffCreator@@QAEXPADPAUIDirectSoundBuffer@@@Z
    { 0x4EEF00, 0xF0A33739, 0x0000 }, // ?FindOriginal@DupBuffCreator@@QAEPAUIDirectSoundBuffer@@PADPAF@Z
    { 0x4EEF90, 0xC22BB4D8, 0x0000 }, // ?GetWAVEFORMATEX@DupBuffCreator@@AAEPAUtWAVEFORMATEX@@PAUIDirectSoundBuffer@@@Z
    { 0x4EF010, 0x44A12BA7, 0x0000 }, // ?IntegrityCheck@DupBuffCreator@@AAEHPAUIDirectSoundBuffer@@0PAH@Z
    { 0x4EF140, 0x91653B80, 0x0000 }, // ??0DSGlobal@@QAE@XZ
    { 0x4EF200, 0x820C0C9E, 0x0000 }, // ??1DSGlobal@@QAE@XZ
    { 0x4EF2E0, 0xCA4EDF5B, 0x0000 }, // ?DeallocateUIADF@DSGlobal@@QAEXXZ
    { 0x4EF340, 0x2AD8CF2D, 0x0000 }, // ?DeallocateCityADF@DSGlobal@@QAEXXZ
    { 0x4EF370, 0xC1C5439B, 0x0000 }, // ?DeallocateADFRecord@DSGlobal@@QAEXH@Z
    { 0x4EF400, 0x9726502E, 0x0000 }, // ?DeInit@DSGlobal@@QAEXFF@Z
    { 0x4EF550, 0xAA3F4B94, 0x0000 }, // ?Init@DSGlobal@@QAEHKEPAIPADFF@Z
    { 0x4EF770, 0x5648404C, 0x0000 }, // ?Init3DListener@DSGlobal@@QAEHMMMMM@Z
    { 0x4EF800, 0xA7AE860A, 0x0000 }, // ?UpperCase@@YAXPAD@Z
    { 0x4EF850, 0x3470B5B3, 0x0000 }, // ?IsDSDeviceInList@@YAHPAU_GUID@@@Z
    { 0x4EF8B0, 0x5B7875CD, 0x0000 }, // ?DSEnumProc@@YGHPAU_GUID@@PAD1PAX@Z
    { 0x4EFA50, 0xE77AD8F0, 0x0000 }, // ?SetDeviceRating@DSGlobal@@QAEXPAUtag_dsdevdesc@@@Z
    { 0x4EFBB0, 0xDCDF8877, 0x0000 }, // ?EnumDSDevices@DSGlobal@@QAEHXZ
    { 0x4EFBD0, 0x26FE86B2, 0x0000 }, // ?InitPrimarySoundBuffer@DSGlobal@@QAEHKEPAD@Z
    { 0x4EFDD0, 0x6BBCE14F, 0x0000 }, // ?ClearDSDeviceList@DSGlobal@@QAEXXZ
    { 0x4EFE10, 0x88208552, 0x0000 }, // ?LoadUIADF@DSGlobal@@QAEHPAD@Z
    { 0x4EFFB0, 0x000908AB, 0x0000 }, // ?LoadCityADF@DSGlobal@@QAEHPADHK@Z
    { 0x4F01C0, 0x57B2A56C, 0x0000 }, // ?InitCityADF@DSGlobal@@QAEHPADHK@Z
    { 0x4F0280, 0x2EEE829C, 0x0000 }, // ?InitUIADF@DSGlobal@@QAEHPADHK@Z
    { 0x4F0340, 0x31E9DE1B, 0x0000 }, // ?ConvertTo8Bit@DSGlobal@@QAEXH@Z
    { 0x4F04D0, 0x6F61DFCE, 0x0000 }, // ?FormatCodeToWFX@@YAHKPAUtWAVEFORMATEX@@@Z
    { 0x4F0580, 0xF17BD69A, 0x0000 }, // ?SetPrimaryBufferFormat@DSGlobal@@QAEXKE@Z
    { 0x4F0670, 0x15EEDD19, 0x0000 }, // ?ScanAvailableDSFormats@DSGlobal@@QAEXXZ
    { 0x4F0730, 0x11F54E1D, 0x0000 }, // ?TranslateDSError@DSGlobal@@QAEPADJ@Z
    { 0x4F08E0, 0x45DFAE9E, 0x0000 }, // ?CheckCDFile@DSGlobal@@QAEEPAD@Z
    { 0x4F0990, 0xC6B5D5C9, 0x0000 }, // ?SetBitDepth@DSGlobal@@QAEXH@Z
    { 0x4F09C0, 0xE4F96733, 0x0000 }, // ?GetDeviceNames@DSGlobal@@QAEPAPADXZ
    { 0x4F09F0, 0x4E8DF30A, 0x0000 }, // ?GetNum3DHallBufs@DSGlobal@@QAEKXZ
    { 0x4F0A20, 0x6F1CD99B, 0x0000 }, // ?GetStereoOnMask@DSGlobal@@SA?BIXZ
    { 0x4F0A30, 0xDB1F7937, 0x0000 }, // ?GetHiResMask@DSGlobal@@SA?BIXZ
    { 0x4F0A40, 0x2ECFFBF0, 0x0000 }, // ?GetHiSampleSizeMask@DSGlobal@@SA?BIXZ
    { 0x4F0A50, 0xF9DEB196, 0x0000 }, // ?GetEchoOnMask@DSGlobal@@SA?BIXZ
    { 0x4F0A60, 0x1F1522C4, 0x0000 }, // ?GetDSound3DMask@DSGlobal@@SA?BIXZ
    { 0x4F0A70, 0x16BD9D03, 0x0000 }, // ?GetSoundFXOnMask@DSGlobal@@SA?BIXZ
    { 0x4F0A80, 0xB60C5331, 0x0000 }, // ?GetCommentaryOnMask@DSGlobal@@SA?BIXZ
    { 0x4F0A90, 0x0D8BCACF, 0x0000 }, // ?GetCDMusicOnMask@DSGlobal@@SA?BIXZ
    { 0x4F0AA0, 0xAB233E70, 0x0000 }, // ?GetUsingEAXMask@DSGlobal@@SA?BIXZ
    { 0x4F0AB0, 0xCD82600F, 0x0000 }, // ?EAXEnabled@DSGlobal@@QAEIXZ
    { 0x4F0AC0, 0x57D68343, 0x0000 }, // ?IsAlwaysEAX@DSGlobal@@QAEIXZ
    { 0x4F0AD0, 0x0B89D5AA, 0x0000 }, // ?AlwaysEAX@DSGlobal@@QAEII@Z
    { 0x4F0B00, 0x2BAD8528, 0x0000 }, // ?DSound3DEnabled@DSGlobal@@QAEIXZ
    { 0x4F0B10, 0xA120DE18, 0x0000 }, // ?DisableEAXFlag@DSGlobal@@QAEXXZ
    { 0x4F0B20, 0x0C9DAC01, 0x0000 }, // ??0SoundObj@@QAE@XZ
    { 0x4F0BE0, 0x50B9F3E3, 0x0000 }, // ??1SoundObj@@QAE@XZ
    { 0x4F0CA0, 0x47E78892, 0x0000 }, // ?DeallocateEffects@SoundObj@@QAEXXZ
    { 0x4F0D70, 0xE858C257, 0x0000 }, // ?SetDelayTime@SoundObj@@QAEXM@Z
    { 0x4F0E90, 0x9B7B44F6, 0x0000 }, // ?SetupOneShotLayerBuffers@SoundObj@@QAEFFMPAD@Z
    { 0x4F0F20, 0x3D1CEA99, 0x0000 }, // ?FreeOneShotLayerBuffers@SoundObj@@QAEXXZ
    { 0x4F0FA0, 0x82500E81, 0x0000 }, // ?DSCreateSoundBuffer@SoundObj@@QAEHPAPAUIDirectSoundBuffer@@E@Z
    { 0x4F1030, 0x9B19285F, 0x0000 }, // ?DSLoadSoundBuffer@SoundObj@@QAEPAUIDirectSoundBuffer@@PBDK@Z
    { 0x4F1210, 0x875B3C78, 0x0000 }, // ?DSLoadSoundBuffer@SoundObj@@QAEXGK@Z
    { 0x4F1350, 0xDA805100, 0x0000 }, // ?ReadADFRecord@SoundObj@@QAEXG@Z
    { 0x4F1510, 0x25EF1C2D, 0x0000 }, // ?DSGetWaveResource@SoundObj@@QAEHPAUHINSTANCE__@@PBDPAPAUtWAVEFORMATEX@@PAPAEPAK@Z
    { 0x4F15F0, 0xBBA6489A, 0x0000 }, // ?ConvertTo8Bit@SoundObj@@QAEXXZ
    { 0x4F1750, 0x5304C543, 0x0000 }, // ?DSGetWaveFile@SoundObj@@QAEHPAUHINSTANCE__@@PBDPAPAUtWAVEFORMATEX@@PAPAEPAKPAPAX@Z
    { 0x4F1A20, 0xFC4DF2F7, 0x0000 }, // ?InitDummy@SoundObj@@QAEHXZ
    { 0x4F1BD0, 0x4DD7692D, 0x0000 }, // ?Init@SoundObj@@QAEHPBDKF@Z
    { 0x4F1C90, 0xEF502ED5, 0x0000 }, // ?Init@SoundObj@@QAEHGKF@Z
    { 0x4F1D40, 0x89468685, 0x0000 }, // ?SetEffect@SoundObj@@QAEXFPAD@Z
    { 0x4F1EC0, 0xEA917E17, 0x0000 }, // ?SetPlayPosition@SoundObj@@QAEXK@Z
    { 0x4F1EE0, 0xC505E0E2, 0x0000 }, // ?Play@SoundObj@@QAEHKPAD@Z
    { 0x4F2120, 0x09A925F9, 0x0000 }, // ?Stop@SoundObj@@QAEHXZ
    { 0x4F21B0, 0xE786ECB2, 0x0000 }, // ?StopEchoBuffers@SoundObj@@QAEXXZ
    { 0x4F21D0, 0x1D7D0716, 0x0000 }, // ?DSFillSoundBuffer@SoundObj@@QAEHPAUIDirectSoundBuffer@@@Z
    { 0x4F2290, 0x45EB39FA, 0x0000 }, // ?DSParseWaveResource@SoundObj@@QAEHPAXPAPAUtWAVEFORMATEX@@PAPAEPAK@Z
    { 0x4F2390, 0x59A655F5, 0x0000 }, // ?IsPlaying@SoundObj@@QAEFF@Z
    { 0x4F2470, 0x91E2ECF7, 0x0000 }, // ?ReadyOneShotLayerBuf@SoundObj@@QAEFXZ
    { 0x4F2500, 0x9C02C8C6, 0x0000 }, // ?AllOneShotLayersPlaying@SoundObj@@QAEFXZ
    { 0x4F25A0, 0x836B8A2E, 0x0000 }, // ?SetPosition@SoundObj@@QAEXMMM@Z
    { 0x4F25E0, 0x83186190, 0x0000 }, // ?SetVelocity@SoundObj@@QAEXMMM@Z
    { 0x4F2620, 0xFDFADB70, 0x0000 }, // ?SetFrequency@SoundObj@@QAEXM@Z
    { 0x4F2860, 0xD931721C, 0x0000 }, // ?SetEchoFrequency@SoundObj@@QAEXM@Z
    { 0x4F2920, 0x194B4064, 0x0000 }, // ?SetVolume@SoundObj@@QAEXM@Z
    { 0x4F2A60, 0xE004F864, 0x0000 }, // ?SetPan@SoundObj@@QAEXM@Z
    { 0x4F2BA0, 0xEA7B4B3D, 0x0000 }, // ?SetEchoPan@SoundObj@@QAEXM@Z
    { 0x4F2BD0, 0x9C533D4B, 0x0000 }, // ?SetRamp@SoundObj@@QAEXMM@Z
    { 0x4F2C00, 0xEA391D82, 0x0000 }, // ?Set3DMode@SoundObj@@QAEXK@Z
    { 0x4F2C20, 0x68AF5639, 0x0000 }, // ?SetConeOutsideVolume@SoundObj@@QAEXJ@Z
    { 0x4F2C50, 0x9E581B0D, 0x0000 }, // ?SetConeAngles@SoundObj@@QAEXKK@Z
    { 0x4F2C90, 0x97C40488, 0x0000 }, // ?SetConeOrientation@SoundObj@@QAEXPAVVector3@@@Z
    { 0x4F2CC0, 0x8F01DD8F, 0x0000 }, // ?SetupDuplicateBuffer@SoundObj@@QAEPAUIDirectSoundBuffer@@PAD@Z
    { 0x4F2D70, 0x015C1244, 0x0000 }, // ?SetupEchoBuffer@SoundObj@@QAEXPAD@Z
    { 0x4F2E10, 0x8A62D872, 0x0000 }, // ?SetupChorusBuffer@SoundObj@@AAEPAUIDirectSoundBuffer@@PAD@Z
    { 0x4F2E90, 0x0E185905, 0x0000 }, // ?UpdateSeconds@SoundObj@@QAEXXZ
    { 0x4F2EC0, 0xC70B27A8, 0x0000 }, // ?UpdateEcho@SoundObj@@QAEXXZ
    { 0x4F2F30, 0x7D34BCF5, 0x0000 }, // ?UpdatePlayEcho@SoundObj@@QAEXXZ
    { 0x4F3030, 0x5AB80A34, 0x0000 }, // ?UpdateStopEcho@SoundObj@@QAEXXZ
    { 0x4F30F0, 0x25093716, 0x0000 }, // ?UpdateVolumeEcho@SoundObj@@QAEXXZ
    { 0x4F31B0, 0x63A2A2E7, 0x0000 }, // ?UpdatePitchEcho@SoundObj@@QAEXXZ
    { 0x4F3270, 0x7A382A1D, 0x0000 }, // ?DisableEffect@SoundObj@@QAEXF@Z
    { 0x4F3370, 0x230FD82C, 0x0000 }, // ?CreateListenerEAXObj@SoundObj@@QAEGXZ
    { 0x4F3410, 0xBE8505D7, 0x0000 }, // ?CreateSecondaryEAXObj@SoundObj@@QAEGXZ
    { 0x4F34D0, 0x46B9B5E3, 0x0000 }, // ?GetFormat@SoundObj@@QAEPAUtWAVEFORMATEX@@XZ
    { 0x4F3550, 0x7783A54E, 0x0000 }, // ?Enable3DMode@SoundObj@@QAEXXZ
    { 0x4F3580, 0x2BBBB21D, 0x0000 }, // ?Disable3DMode@SoundObj@@QAEXXZ
    { 0x4F35A0, 0xAABC1D9F, 0x0000 }, // ??0AudStream@@QAE@KHF@Z
    { 0x4F36E0, 0x18916F64, 0x0000 }, // ??1AudStream@@UAE@XZ
    { 0x4F37E0, 0xAFE6F21A, 0x0000 }, // ?SetPriority@AudStream@@QAEXH@Z
    { 0x4F3800, 0x2996C8CC, 0x0000 }, // ?DeallocateStreamObjs@AudStream@@QAEXXZ
    { 0x4F3890, 0x84BA32E9, 0x0000 }, // ?ReallocateStreamObjs@AudStream@@QAEXXZ
    { 0x4F3910, 0x4B055ED7, 0x0000 }, // ?Load@AudStream@@QAEHPADH@Z
    { 0x4F3AB0, 0x6269DEB7, 0x0000 }, // ?Enable@AudStream@@QAEXXZ
    { 0x4F3AC0, 0xCB90F31A, 0x0000 }, // ?Disable@AudStream@@QAEXXZ
    { 0x4F3AE0, 0xFC00E940, 0x0000 }, // ?Reset@AudStream@@UAEXXZ
    { 0x4F3B00, 0x4C383FE5, 0x0000 }, // ?Update@AudStream@@UAEXXZ
    { 0x4F3B50, 0x602C929D, 0x0000 }, // ?SetPlayPosition@AudStream@@QAEXK@Z
    { 0x4F3B60, 0xB59EADDA, 0x0000 }, // ?PlayOnce@AudStream@@QAEXMM@Z
    { 0x4F3C10, 0x2D8BF35C, 0x0000 }, // ?PlayOnce@AudStream@@QAEXPADMM@Z
    { 0x4F3D20, 0x1E33D35E, 0x0000 }, // ?PlayLoop@AudStream@@QAEXPADMM@Z
    { 0x4F3E40, 0x0C8903F5, 0x0000 }, // ?PlayLoop@AudStream@@QAEXMM@Z
    { 0x4F3EF0, 0x975A6748, 0x0000 }, // ?Stop@AudStream@@QAEXXZ
    { 0x4F3F10, 0xE4564D38, 0x0000 }, // ?StopNow@AudStream@@QAEXXZ
    { 0x4F3F30, 0x0034D6BC, 0x0000 }, // ?SetFrequency@AudStream@@QAEXMH@Z
    { 0x4F3FA0, 0x2778FDEE, 0x0000 }, // ?GetFrequency@AudStream@@QAEMH@Z
    { 0x4F3FE0, 0x99CA64A6, 0x0000 }, // ?SetVolume@AudStream@@QAEXMH@Z
    { 0x4F4050, 0x07A2A8B8, 0x0000 }, // ?SetPan@AudStream@@QAEXMH@Z
    { 0x4F40E0, 0xC95C0FD9, 0x0000 }, // ?IsPlaying@AudStream@@QAEHXZ
    { 0x4F4100, 0x17AAD145, 0x0000 }, // ?Get2DFlags@AudStream@@SA?BKXZ
    { 0x4F4120, 0xADAC7B67, 0x0000 }, // ?GetFreqChange2DFlags@AudStream@@SA?BKXZ
    { 0x4F4140, 0xAE2BF1B6, 0x0000 }, // ?GetCurrentSoundObj@AudStream@@QAEPAVStreamObj@@XZ
    { 0x4F4150, 0xDB566DC6, 0x0000 }, // ?SetNumLoopIndices@AudStream@@QAEXF@Z
    { 0x4F4180, 0xA201BBEF, 0x0000 }, // ?SetLoopIndex@AudStream@@QAEXF@Z
    { 0x4F41B0, 0x9616300D, 0x0000 }, // ?SetLoopPointInfo@AudStream@@QAEXKKIFF@Z
    { 0x4F41F0, 0x72E0D823, 0x0000 }, // ?SetupNotifications@AudStream@@QAEXXZ
    { 0x4F4240, 0xEC824287, 0x0000 }, // ??1CDMan@@QAE@XZ
    { 0x4F4280, 0x8BED27B2, 0x0000 }, // ?Init@CDMan@@QAEKF@Z
    { 0x4F4340, 0x45D943EE, 0x0000 }, // ?PlayTrack@CDMan@@QAEKEE@Z
    { 0x4F4430, 0x5D317E33, 0x0000 }, // ?ResumePlay@CDMan@@QAEKXZ
    { 0x4F4450, 0x4F93FAF8, 0x0000 }, // ?PlayTrack@CDMan@@QAEKEEEEE@Z
    { 0x4F4560, 0xD9F43F75, 0x0000 }, // ?Stop@CDMan@@QAEKXZ
    { 0x4F45A0, 0xA2E832B2, 0x0000 }, // ?SeekTrack@CDMan@@QAEKE@Z
    { 0x4F4610, 0xCB2C4372, 0x0000 }, // ?GetPosition@CDMan@@QAEKPAE000@Z
    { 0x4F4690, 0xF014C662, 0x0000 }, // ?WindowProc@CDMan@@EAEJPAUHWND__@@IIJ@Z
    { 0x4F4700, 0x78D1C9B1, 0x0000 }, // ?GetNumTracks@CDMan@@QAEFXZ
    { 0x4F4760, 0x7E8DB9C7, 0x0000 }, // ??0CReverb@@QAE@PAUIDirectSound3DBuffer@@@Z
    { 0x4F4800, 0xB49C5FD8, 0x0000 }, // ??1CReverb@@QAE@XZ
    { 0x4F4810, 0x8C30E1C1, 0x0000 }, // ?PropertySetOk@CReverb@@QAEHXZ
    { 0x4F4820, 0x48FA3597, 0x0000 }, // ?QueryProperty@CReverb@@AAEHK@Z
    { 0x4F4870, 0x19D17EC6, 0x0000 }, // ?SetEnvironment@CReverb@@QAEXK@Z
    { 0x4F4890, 0xC342D93C, 0x0000 }, // ?SetVolume@CReverb@@QAEXM@Z
    { 0x4F48B0, 0x6DE5C4C7, 0x0000 }, // ?SetDecayTime@CReverb@@QAEXM@Z
    { 0x4F48D0, 0x622D45B5, 0x0000 }, // ?SetDamping@CReverb@@QAEXM@Z
    { 0x4F48F0, 0x01BA4AB8, 0x0000 }, // ?SetAll@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    { 0x4F4910, 0x75A6F6F6, 0x0000 }, // ?SetPreset@CReverb@@QAEXKMMM@Z
    { 0x4F4950, 0x2A7AC9D2, 0x0000 }, // ?SetPreset@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    { 0x4F4970, 0x4BA4F882, 0x0000 }, // ?GetEnvironment@CReverb@@QAEKXZ
    { 0x4F49B0, 0x2EF5737E, 0x0000 }, // ?GetVolume@CReverb@@QAEMXZ
    { 0x4F49F0, 0x65B175D4, 0x0000 }, // ?GetDecayTime@CReverb@@QAEMXZ
    { 0x4F4A30, 0xB55CAAD6, 0x0000 }, // ?GetDamping@CReverb@@QAEMXZ
    { 0x4F4A70, 0x5EC84496, 0x0000 }, // ?GetAll@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    { 0x4F4AA0, 0x02583B7E, 0x0000 }, // ??0CReverbBuffer@@QAE@PAUIDirectSound3DBuffer@@@Z
    { 0x4F4AF0, 0x017AD860, 0x0000 }, // ??1CReverbBuffer@@QAE@XZ
    { 0x4F4B00, 0xD54D9269, 0x0000 }, // ?PropertySetOk@CReverbBuffer@@QAEHXZ
    { 0x4F4B10, 0x0B5089C2, 0x0000 }, // ?QueryProperty@CReverbBuffer@@AAEHK@Z
    { 0x4F4B60, 0xB9E9047F, 0x0000 }, // ?SetReverbMix@CReverbBuffer@@QAEXM@Z
    { 0x4F4B80, 0x55432D9F, 0x0000 }, // ?SetAll@CReverbBuffer@@QAEXPAUEAXBUFFER_REVERBPROPERTIES@@@Z
    { 0x4F4BA0, 0x91F95652, 0x0000 }, // ?GetReverbMix@CReverbBuffer@@QAEMXZ
    { 0x4F4BE0, 0x4D878197, 0x0000 }, // ?GetAll@CReverbBuffer@@QAEXPAUEAXBUFFER_REVERBPROPERTIES@@@Z
    { 0x4F4C10, 0xC9165462, 0x0000 }, // ??0StreamObj@@QAE@XZ
    { 0x4F4CA0, 0xCDD9DCF8, 0x0000 }, // ??1StreamObj@@QAE@XZ
    { 0x4F4DC0, 0x015B2601, 0x0000 }, // ?DSCreateSoundBuffer@StreamObj@@QAEHXZ
    { 0x4F4E50, 0xBFAE386D, 0x0000 }, // ?DSLoadSoundBuffer@StreamObj@@QAEPAUIDirectSoundBuffer@@PBDK@Z
    { 0x4F4EA0, 0xDCB27DED, 0x0000 }, // ?OpenWaveFile@StreamObj@@AAEPAVStream@@PBDF@Z
    { 0x4F50C0, 0x4E64E257, 0x0000 }, // ?GetWaveBytesOffset@StreamObj@@AAEIPAVStream@@F@Z
    { 0x4F5200, 0x8D4483D3, 0x0000 }, // ?Init@StreamObj@@QAEHPBDK@Z
    { 0x4F5270, 0x95B65C48, 0x0000 }, // ?SetPlayPosition@StreamObj@@QAEXK@Z
    { 0x4F5290, 0x702288EB, 0x0000 }, // ?Play@StreamObj@@QAEHXZ
    { 0x4F5330, 0x5356CDFE, 0x0000 }, // ?SetPlayOneShotEvent@StreamObj@@QAEXPAD@Z
    { 0x4F5390, 0x0E8F6586, 0x0000 }, // ?SetStopEvent@StreamObj@@QAEXXZ
    { 0x4F53B0, 0xA5E2ADC0, 0x0000 }, // ?SetVolumeEvent@StreamObj@@QAEXM@Z
    { 0x4F53E0, 0xC2D2D1ED, 0x0000 }, // ?SetFrequencyEvent@StreamObj@@QAEXM@Z
    { 0x4F5410, 0xE4632234, 0x0000 }, // ?SetPanEvent@StreamObj@@QAEXM@Z
    { 0x4F5440, 0x6CBDA998, 0x0000 }, // ?Play@StreamObj@@QAEHPAD@Z
    { 0x4F5510, 0x2F551B63, 0x0000 }, // ?Stop@StreamObj@@QAEHXZ
    { 0x4F5540, 0x781D5712, 0x0000 }, // ?FillDataBuffer@StreamObj@@QAEHI@Z
    { 0x4F5750, 0xCFF77FDC, 0x0000 }, // ?IsPlaying@StreamObj@@QAEFXZ
    { 0x4F57B0, 0xC5079AAD, 0x0000 }, // ?SetFrequency@StreamObj@@QAEXM@Z
    { 0x4F5860, 0xAD2D49AD, 0x0000 }, // ?SetVolume@StreamObj@@QAEXM@Z
    { 0x4F58A0, 0x5F4C22B5, 0x0000 }, // ?SetPan@StreamObj@@QAEXM@Z
    { 0x4F58E0, 0x9B035477, 0x0000 }, // ?SetupNotifications@StreamObj@@QAEHXZ
    { 0x4F5B80, 0xB21948FF, 0x0000 }, // ?HandleNotifications@@YAKPAX@Z
    { 0x4F5F80, 0xCD396CB9, 0x0000 }, // ?Update@StreamObj@@QAEXXZ
    { 0x4F6040, 0x8EBA3DDB, 0x0000 }, // ?GetFileStreamPtr@StreamObj@@QAEPAVStream@@XZ
    { 0x4F6050, 0x5D1362EF, 0x0000 }, // ?SetNumLoopIndices@StreamObj@@QAEXF@Z
    { 0x4F60B0, 0xB8BCC911, 0x0000 }, // ?SetLoopPointInfo@StreamObj@@QAEXKKIFF@Z
    { 0x4F61C0, 0x950353D0, 0x0000 }, // ?ReadInLoopIndex@StreamObj@@QAEXF@Z
    { 0x4F6290, 0xDC4EF6D4, 0x0000 }, // ?SetPlayingFlag@StreamObj@@QAEXF@Z
    { 0x4F62B0, 0x5716906A, 0x0000 }, // ??0PovCamCS@@QAE@XZ
    { 0x4F63B0, 0x70041041, 0x0000 }, // ??1PovCamCS@@UAE@XZ
    { 0x4F63C0, 0xB9AD8E38, 0x0000 }, // ?MakeActive@PovCamCS@@UAEXXZ
    { 0x4F6410, 0xAC4FF6CF, 0x0000 }, // ?AfterLoad@PovCamCS@@UAEXXZ
    { 0x4F6420, 0xC80BCCAB, 0x0000 }, // ?Reset@PovCamCS@@UAEXXZ
    { 0x4F6460, 0xD6F8AF33, 0x0000 }, // ?AddWidgets@PovCamCS@@UAEXPAVBank@@@Z
    { 0x4F6530, 0xBAE2D22A, 0x0000 }, // ?Update@PovCamCS@@UAEXXZ
    { 0x4F6550, 0xEF4873DD, 0x0000 }, // ?UpdateInput@PovCamCS@@UAEXXZ
    { 0x4F6560, 0xC0074883, 0x0000 }, // ?UpdatePOV@PovCamCS@@AAEXXZ
    { 0x4F6800, 0x5FCAF738, 0x0000 }, // ?DeclareFields@PovCamCS@@SAXXZ
    { 0x4F69B0, 0xFB8BCF4B, 0x0000 }, // ?GetClass@PovCamCS@@UAEPAVMetaClass@@XZ
    { 0x4F6A50, 0xBBBAC2FF, 0x0000 }, // ?SetST@BaseCamCS@@UAEXPAM@Z
    { 0x4F6A60, 0xFD948B84, 0x0000 }, // ??0TrackCamCS@@QAE@XZ
    { 0x4F6D00, 0xFD30F262, 0x0000 }, // ??1TrackCamCS@@UAE@XZ
    { 0x4F6D50, 0x6AE9FAE2, 0x0000 }, // ?MakeActive@TrackCamCS@@UAEXXZ
    { 0x4F6D90, 0x0E6E1BDE, 0x0000 }, // ?AfterLoad@TrackCamCS@@UAEXXZ
    { 0x4F6DA0, 0x7D9CD269, 0x0000 }, // ?Reset@TrackCamCS@@UAEXXZ
    { 0x4F6DE0, 0x4D01F3F8, 0x0000 }, // ?AddWidgets@TrackCamCS@@UAEXPAVBank@@@Z
    { 0x4F7270, 0x4628FA01, 0x0000 }, // ?Update@TrackCamCS@@UAEXXZ
    { 0x4F7350, 0x9765150C, 0x0000 }, // ?UpdateInput@TrackCamCS@@UAEXXZ
    { 0x4F7360, 0x07A52097, 0x0000 }, // ?UpdateCar@TrackCamCS@@AAEXXZ
    { 0x4F7500, 0xE9E52D76, 0x0000 }, // ?UpdateHill@TrackCamCS@@AAEXXZ
    { 0x4F7510, 0x6DA7DEC9, 0x0000 }, // ?UpdateTrack@TrackCamCS@@AAEXXZ
    { 0x4F7E50, 0xD86C7926, 0x0000 }, // ?UpdateSwing@TrackCamCS@@AAEXXZ
    { 0x4F8230, 0x62682045, 0x0000 }, // ?PreApproach@TrackCamCS@@AAEXXZ
    { 0x4F8430, 0x7DB831C3, 0x0000 }, // ?MinMax@TrackCamCS@@AAEXVMatrix34@@@Z
    { 0x4F85D0, 0xB5284B9D, 0x0000 }, // ?Collide@TrackCamCS@@AAEXVVector3@@@Z
    { 0x4F8A70, 0x147354B0, 0x0000 }, // ?SwingToRear@TrackCamCS@@QAEXXZ
    { 0x4F8AE0, 0x79371299, 0x0000 }, // ?Front@TrackCamCS@@AAEXM@Z
    { 0x4F8B60, 0xE67BBBEE, 0x0000 }, // ?Rear@TrackCamCS@@AAEXM@Z
    { 0x4F8BE0, 0x27A24722, 0x0000 }, // ?DeclareFields@TrackCamCS@@SAXXZ
    { 0x4F8F00, 0xFEDB3F53, 0x0000 }, // ?GetClass@TrackCamCS@@UAEPAVMetaClass@@XZ
    { 0x4F8F40, 0x18AA58AB, 0x0000 }, // ??1Spline@@UAE@XZ
    { 0x4F8FB0, 0x269850AC, 0x0000 }, // ??0mmViewCS@@QAE@XZ
    { 0x4F9070, 0xAC286E83, 0x0000 }, // ??1mmViewCS@@UAE@XZ
    { 0x4F9080, 0x01F2D678, 0x0000 }, // ?Instance@mmViewCS@@SAPAV1@PAVasCamera@@@Z
    { 0x4F9110, 0xFF97C2D3, 0x0000 }, // ?SetCurrentCam@mmViewCS@@QAEXPAVCarCamCS@@@Z
    { 0x4F9180, 0xA64F5D44, 0x0000 }, // ?NewCam@mmViewCS@@QAEHPAVCarCamCS@@HMVCallback@@@Z
    { 0x4F9230, 0xDB975366, 0x0000 }, // ?Update@mmViewCS@@UAEXXZ
    { 0x4F9260, 0x86F19545, 0x0000 }, // ?Init@mmViewCS@@QAEXXZ
    { 0x4F9270, 0x4DB06DDF, 0x0000 }, // ?SetCamera@mmViewCS@@QAEXPAVasCamera@@@Z
    { 0x4F92C0, 0xE53B3C7D, 0x0000 }, // ?Reset@mmViewCS@@UAEXXZ
    { 0x4F9320, 0x2009C6B8, 0x0000 }, // ?ForceMatrixDelta@mmViewCS@@QAEXABVMatrix34@@@Z
    { 0x4F9340, 0x6E7327D9, 0x0000 }, // ?ForceMatrixDelta@mmViewCS@@QAEXABVVector3@@@Z
    { 0x4F9360, 0x99F28672, 0x0000 }, // ?OneShot@mmViewCS@@QAEXXZ
    { 0x4F9380, 0x2E2504AD, 0x0000 }, // ?DeclareFields@mmViewCS@@SAXXZ
    { 0x4F94F0, 0xE0190318, 0x0000 }, // ?GetClass@mmViewCS@@UAEPAVMetaClass@@XZ
    { 0x4F9560, 0xF02DC46A, 0x0000 }, // ?AddWidgets@mmViewCS@@UAEXPAVBank@@@Z
    { 0x4F9570, 0x1ADDEBA2, 0x0000 }, // ??0PostCamCS@@QAE@XZ
    { 0x4F95C0, 0x67207898, 0x0000 }, // ?Init@PostCamCS@@QAEXPAVmmCar@@@Z
    { 0x4F95E0, 0x84DF221F, 0x0000 }, // ?Reset@PostCamCS@@UAEXXZ
    { 0x4F95F0, 0x759162AD, 0x0000 }, // ?MakeActive@PostCamCS@@UAEXXZ
    { 0x4F9670, 0x17C76678, 0x0000 }, // ?Update@PostCamCS@@UAEXXZ
    { 0x4F97A0, 0xE1935F76, 0x0000 }, // ?AddWidgets@PostCamCS@@UAEXPAVBank@@@Z
    { 0x4F97C0, 0x1C5EE668, 0x0000 }, // ?DeclareFields@PostCamCS@@SAXXZ
    { 0x4F9930, 0x8340DCC5, 0x0000 }, // ?GetClass@PostCamCS@@UAEPAVMetaClass@@XZ
    { 0x4F99D0, 0xBAE808F7, 0x0000 }, // ?UpdateInput@BaseCamCS@@UAEXXZ
    { 0x4F99E0, 0x8DFABABF, 0x0000 }, // ??0PreCamCS@@QAE@XZ
    { 0x4F9A30, 0x83DCD7CA, 0x0000 }, // ?Init@PreCamCS@@QAEXPAVmmCar@@@Z
    { 0x4F9A60, 0x413158D9, 0x0000 }, // ?Reset@PreCamCS@@UAEXXZ
    { 0x4F9A70, 0x73EBE713, 0x0000 }, // ?MakeActive@PreCamCS@@UAEXXZ
    { 0x4F9AC0, 0x6FC9E55F, 0x0000 }, // ?Update@PreCamCS@@UAEXXZ
    { 0x4F9B20, 0xE1F243A3, 0x0000 }, // ?AddWidgets@PreCamCS@@UAEXPAVBank@@@Z
    { 0x4F9C10, 0x7AD8858D, 0x0000 }, // ?DeclareFields@PreCamCS@@SAXXZ
    { 0x4F9D80, 0xBD39181F, 0x0000 }, // ?GetClass@PreCamCS@@UAEPAVMetaClass@@XZ
    { 0x4F9E20, 0xBE7A49F0, 0x0000 }, // ??0PointCamCS@@QAE@XZ
    { 0x4F9E50, 0x952B3476, 0x0000 }, // ?Init@PointCamCS@@QAEXPAVmmCar@@@Z
    { 0x4F9E80, 0x784F49FD, 0x0000 }, // ?Reset@PointCamCS@@UAEXXZ
    { 0x4F9E90, 0x0A2007E5, 0x0000 }, // ?MakeActive@PointCamCS@@UAEXXZ
    { 0x4F9EC0, 0x7FA02A4C, 0x0000 }, // ?SetPos@PointCamCS@@QAEXAAVVector3@@@Z
    { 0x4F9F00, 0x41058C02, 0x0000 }, // ?SetMaxDist@PointCamCS@@QAEXM@Z
    { 0x4F9F20, 0xE4CC8985, 0x0000 }, // ?SetMinDist@PointCamCS@@QAEXM@Z
    { 0x4F9F40, 0xFC4E4EB4, 0x0000 }, // ?SetAppRate@PointCamCS@@QAEXM@Z
    { 0x4F9F50, 0xB4BA3BF1, 0x0000 }, // ?SetVel@PointCamCS@@QAEXAAVVector3@@@Z
    { 0x4F9F70, 0x7BD5AAF4, 0x0000 }, // ?GetPos@PointCamCS@@QAE?AVVector3@@XZ
    { 0x4F9FA0, 0x2CCCB90D, 0x0000 }, // ?Update@PointCamCS@@UAEXXZ
    { 0x4FA280, 0x256C6A88, 0x0000 }, // ?DeclareFields@PointCamCS@@SAXXZ
    { 0x4FA3F0, 0xD854B1E7, 0x0000 }, // ?GetClass@PointCamCS@@UAEPAVMetaClass@@XZ
    { 0x4FA490, 0xA96B9425, 0x0000 }, // ??0AICamCS@@QAE@XZ
    { 0x4FA4C0, 0xDBF1EB6D, 0x0000 }, // ?Init@AICamCS@@QAEXPAVmmCar@@@Z
    { 0x4FA4D0, 0x9339C40B, 0x0000 }, // ?Reset@AICamCS@@UAEXXZ
    { 0x4FA4E0, 0xDAA60748, 0x0000 }, // ?MakeActive@AICamCS@@UAEXXZ
    { 0x4FA5F0, 0x3909F009, 0x0000 }, // ?Update@AICamCS@@UAEXXZ
    { 0x4FA950, 0xB7BE011A, 0x0000 }, // ?DeclareFields@AICamCS@@SAXXZ
    { 0x4FAAC0, 0xAA4C84FF, 0x0000 }, // ?GetClass@AICamCS@@UAEPAVMetaClass@@XZ
    { 0x4FAB60, 0x789697D2, 0x0000 }, // ??0PolarCamCS@@QAE@XZ
    { 0x4FABB0, 0x2467FBC8, 0x0000 }, // ?Init@PolarCamCS@@QAEXPAVmmCar@@@Z
    { 0x4FABE0, 0x0F84EFC4, 0x0000 }, // ?Reset@PolarCamCS@@UAEXXZ
    { 0x4FABF0, 0x6FECD053, 0x0000 }, // ?MakeActive@PolarCamCS@@UAEXXZ
    { 0x4FAC20, 0x9E910A50, 0x0000 }, // ?Update@PolarCamCS@@UAEXXZ
    { 0x4FB010, 0x3EBB5AB3, 0x0000 }, // ?DeclareFields@PolarCamCS@@SAXXZ
    { 0x4FB180, 0x96B601D8, 0x0000 }, // ?GetClass@PolarCamCS@@UAEPAVMetaClass@@XZ
    { 0x4FB220, 0xE2743C7A, 0x0000 }, // ??0CarCamCS@@QAE@XZ
    { 0x4FB240, 0x6E1DC6C0, 0x0000 }, // ??1CarCamCS@@UAE@XZ
    { 0x4FB250, 0xC3BEED3D, 0x0000 }, // ?Init@CarCamCS@@QAEXPAVmmCar@@PAD@Z
    { 0x4FB280, 0x538BBF23, 0x0000 }, // ?AddWidgets@CarCamCS@@UAEXPAVBank@@@Z
    { 0x4FB290, 0xF815A7CF, 0x0000 }, // ?DeclareFields@CarCamCS@@SAXXZ
    { 0x4FB400, 0xEFC5634C, 0x0000 }, // ?GetClass@CarCamCS@@UAEPAVMetaClass@@XZ
    { 0x4FB4A0, 0xBBAF385E, 0x0000 }, // ?MakeActive@BaseCamCS@@UAEXXZ
    { 0x4FB4B0, 0x7EEAB530, 0x0000 }, // ??0TransitionCS@@QAE@XZ
    { 0x4FB540, 0x91F2C37C, 0x0000 }, // ??1TransitionCS@@UAE@XZ
    { 0x4FB550, 0x55215F6C, 0x0000 }, // ?Init@TransitionCS@@QAEXPAVmmCar@@@Z
    { 0x4FB570, 0x1B3CC2F0, 0x0000 }, // ?Reset@TransitionCS@@UAEXXZ
    { 0x4FB580, 0x2948870B, 0x0000 }, // ?Update@TransitionCS@@UAEXXZ
    { 0x4FBC00, 0x42904C08, 0x0000 }, // ?ForceMatrixDelta@TransitionCS@@UAEXABVVector3@@@Z
    { 0x4FBC30, 0x62E0B6D0, 0x0000 }, // ?NewTransition@TransitionCS@@QAEXPAVCarCamCS@@0@Z
    { 0x4FBC60, 0x9FFA804F, 0x0000 }, // ?NextTransition@TransitionCS@@QAEXPAVCarCamCS@@@Z
    { 0x4FBCA0, 0xB8FB45F2, 0x0000 }, // ?StartTransition@TransitionCS@@QAEXXZ
    { 0x4FBD10, 0xE7A60770, 0x0000 }, // ?StartNextTransition@TransitionCS@@QAEXXZ
    { 0x4FBD50, 0x412C3A9D, 0x0000 }, // ?ReverseTransition@TransitionCS@@QAEXXZ
    { 0x4FBE00, 0xD76A1C59, 0x0000 }, // ??0BaseCamCS@@QAE@XZ
    { 0x4FBEA0, 0xE478AC41, 0x0000 }, // ??1BaseCamCS@@UAE@XZ
    { 0x4FBEB0, 0x3C0A0FC8, 0x0000 }, // ?AfterLoad@BaseCamCS@@UAEXXZ
    { 0x4FBEC0, 0xBEE49A4F, 0x0000 }, // ?IsViewCSInTransition@BaseCamCS@@QAEHXZ
    { 0x4FBEF0, 0xF6DB0ED7, 0x0000 }, // ?UpdateView@BaseCamCS@@QAEXXZ
    { 0x4FBF40, 0xD3CDB6F7, 0x0000 }, // ?AddWidgets@BaseCamCS@@UAEXPAVBank@@@Z
    { 0x4FC090, 0xE2CF177F, 0x0000 }, // ?ForceMatrixDelta@BaseCamCS@@UAEXABVVector3@@@Z
    { 0x4FC0E0, 0x4747EB79, 0x0000 }, // ?DeclareFields@BaseCamCS@@SAXXZ
    { 0x4FC2C0, 0xBDDAFC02, 0x0000 }, // ?GetClass@BaseCamCS@@UAEPAVMetaClass@@XZ
    { 0x4FC330, 0x5DF9BAA3, 0x0000 }, // ??0AppCamCS@@QAE@XZ
    { 0x4FC420, 0x0620CFC7, 0x0000 }, // ??1AppCamCS@@UAE@XZ
    { 0x4FC430, 0x2D40D519, 0x0000 }, // ?ApproachIt@AppCamCS@@IAEXXZ
    { 0x4FC460, 0xE635FE4D, 0x0000 }, // ?UpdateApproach@AppCamCS@@AAEXXZ
    { 0x4FC9D0, 0x2FF0B352, 0x0000 }, // ?UpdateMaxDist@AppCamCS@@AAEXXZ
    { 0x4FCC60, 0x34F803D0, 0x0000 }, // ?DApproach@AppCamCS@@AAEHAAMMMM0M@Z
    { 0x4FCDB0, 0x8C080C52, 0x0000 }, // ?AddWidgets@AppCamCS@@UAEXPAVBank@@@Z
    { 0x4FD0D0, 0xA98C2ADF, 0x0000 }, // ?DeclareFields@AppCamCS@@SAXXZ
    { 0x4FD380, 0x4AAC01D0, 0x0000 }, // ?GetClass@AppCamCS@@UAEPAVMetaClass@@XZ
    { 0x4FD3F0, 0x0FB7904F, 0x0000 }, // ??0Spline@@QAE@XZ
    { 0x4FD420, 0x000CA3B7, 0x0000 }, // ?Init@Spline@@QAEXPAMH@Z
    { 0x4FD550, 0xB6D11CAE, 0x0000 }, // ?InRange@Spline@@QAEHXZ
    { 0x4FD5B0, 0xD8BADCF8, 0x0000 }, // ?CalcCoeff@Spline@@QAEXXZ
    { 0x4FD710, 0xDF9DF6CE, 0x0000 }, // ?SetValue@Spline@@QAEXPAM@Z
    { 0x4FD790, 0xD6149435, 0x0000 }, // ?SetGoal@Spline@@QAEXPAMM@Z
    { 0x4FD880, 0x7FBCE74F, 0x0000 }, // ?Solve@Spline@@QAEXM@Z
    { 0x4FD9F0, 0x0D0A147B, 0x0000 }, // ?Print@Spline@@QAEXH@Z
    { 0x4FDAF0, 0x44004D4D, 0x0000 }, // ?FixTimeStop@Spline@@QAEXXZ
    { 0x4FDB30, 0xAF1AF598, 0x0000 }, // ?Update@Spline@@UAEXXZ
    { 0x4FDB80, 0x5622636C, 0x0000 }, // ?AddWidgets@Spline@@UAEXPAVBank@@@Z
    { 0x4FDB90, 0x430E93E7, 0x0000 }, // ?DeclareFields@Spline@@SAXXZ
    { 0x4FDD00, 0xD0AA8670, 0x0000 }, // ?GetClass@Spline@@UAEPAVMetaClass@@XZ
    { 0x4FDD70, 0x502E8E49, 0x0000 }, // ??0mmGameRecord@@QAE@M@Z
    { 0x4FDDA0, 0xCBEEC0E8, 0x0000 }, // ??1mmGameRecord@@QAE@XZ
    { 0x4FDDE0, 0x44045FE5, 0x0000 }, // ?Init@mmGameRecord@@QAEXH@Z
    { 0x4FDE50, 0x291FA22D, 0x0000 }, // ?GetCount@mmGameRecord@@QAEHXZ
    { 0x4FDE60, 0x5B1FCE3A, 0x0000 }, // ?GetVector4@mmGameRecord@@QAEAAVVector4@@H@Z
    { 0x4FDE90, 0xD1044AA5, 0x0000 }, // ?Dump@mmGameRecord@@QAEXPAD@Z
    { 0x4FDF90, 0x4B5AF140, 0x0000 }, // ?Register@mmGameRecord@@QAEHAAVVector4@@MMMMMMMM@Z
    { 0x4FE070, 0xC386E828, 0x0000 }, // ?DoScan@mmGameRecord@@QAEXAAVVector4@@@Z
    { 0x4FE140, 0xB36456F9, 0x0000 }, // ?Sim@mmGameRecord@@QAEXXZ
    { 0x4FE150, 0x1B51CF5E, 0x0000 }, // ??0Card2D@@QAE@XZ
    { 0x4FE170, 0x3DB5BE40, 0x0000 }, // ?Init@Card2D@@QAEXPAVasCamera@@MMMMM@Z
    { 0x4FE1B0, 0xB51DCE6D, 0x0000 }, // ?SetDimensions@Card2D@@QAEXMMMM@Z
    { 0x4FE2A0, 0xBA0E7F07, 0x0000 }, // ?SetPosition@Card2D@@QAEXMM@Z
    { 0x4FE2C0, 0x675EF21C, 0x0000 }, // ?SetAlpha@Card2D@@QAEXM@Z
    { 0x4FE320, 0xB62B5F8D, 0x0000 }, // ?Update@Card2D@@UAEXXZ
    { 0x4FE330, 0xAFEC79B5, 0x0000 }, // ?Cull@Card2D@@EAEXXZ
    { 0x4FE540, 0xCAC7E676, 0x0000 }, // ?AddWidgets@Card2D@@EAEXPAVBank@@@Z
    { 0x4FE650, 0x6ACB9BA9, 0x0000 }, // ??1Card2D@@UAE@XZ
    { 0x4FE660, 0xF2B79763, 0x0000 }, // ??0mmNumberFont@@QAE@XZ
    { 0x4FE730, 0x8CF14ED0, 0x0000 }, // ??1mmNumberFont@@QAE@XZ
    { 0x4FE780, 0x9C0F026D, 0x0000 }, // ?LoadFont@mmNumberFont@@QAEXPADHI@Z
    { 0x4FE880, 0x1DD81A5F, 0x0000 }, // ?LoadLocFont@mmNumberFont@@QAEXPADPAULocString@@HI@Z
    { 0x4FEA10, 0xA822E2A8, 0x0000 }, // ??0mmNumber@@QAE@XZ
    { 0x4FEAA0, 0x95CDEE48, 0x0000 }, // ??1mmNumber@@UAE@XZ
    { 0x4FEAB0, 0x33FF0863, 0x0000 }, // ?Init@mmNumber@@QAEXPAVmmNumberFont@@MM@Z
    { 0x4FEB20, 0xF1CFC629, 0x0000 }, // ?SetString@mmNumber@@QAEXPAD@Z
    { 0x4FEB50, 0x050FDCA7, 0x0000 }, // ?Printf@mmNumber@@QAAXPBDZZ
    { 0x4FEB70, 0xCC00FB66, 0x0000 }, // ?Update@mmNumber@@UAEXXZ
    { 0x4FEB90, 0x74772920, 0x0000 }, // ?Cull@mmNumber@@UAEXXZ
    { 0x4FECA0, 0x1F848011, 0x0000 }, // ?AddWidgets@mmNumber@@UAEXPAVBank@@@Z
    { 0x4FECB0, 0xC336BAFC, 0x0000 }, // ?DeclareFields@mmNumber@@SAXXZ
    { 0x4FEE20, 0x2941DF12, 0x0000 }, // ?GetClass@mmNumber@@UAEPAVMetaClass@@XZ
    { 0x4FEE30, 0xFD1AC3CA, 0x0000 }, // ?ddGDIFlip@@YAXXZ
    { 0x4FEE40, 0xF56514EA, 0x0000 }, // ??0mmText@@QAE@XZ
    { 0x4FEE50, 0xFDA5A162, 0x0000 }, // ??1mmText@@QAE@XZ
    { 0x4FEE60, 0x73E6ABDA, 0x0000 }, // ?CreateLocFont@mmText@@SAPAXPAULocString@@H@Z
    { 0x4FEF30, 0x06383299, 0x0000 }, // ?CreateFont@mmText@@SAPAXPADH@Z
    { 0x4FEF60, 0x51E050A8, 0x0000 }, // ?DeleteFont@mmText@@SAXPAX@Z
    { 0x4FEF70, 0x8FB6A14B, 0x0000 }, // ?GetDC@mmText@@SAPAXPAVagiSurfaceDesc@@@Z
    { 0x4FF010, 0xB75B8464, 0x0000 }, // ?ReleaseDC@mmText@@SAXXZ
    { 0x4FF0C0, 0xEEA49863, 0x0000 }, // ?CreateFitBitmap@mmText@@SAPAVagiBitmap@@PADPAXHH@Z
    { 0x4FF2D0, 0xD960487C, 0x0000 }, // ?Draw@mmText@@QAEXPAVagiSurfaceDesc@@MMPADPAX@Z
    { 0x4FF360, 0x001B8C0A, 0x0000 }, // ?Draw2@mmText@@QAEXPAVagiSurfaceDesc@@MMPADPAXI@Z
    { 0x4FF450, 0x141C642F, 0x0000 }, // ??0mmTextNode@@QAE@XZ
    { 0x4FF4D0, 0xE61391E4, 0x0000 }, // ??1mmTextNode@@UAE@XZ
    { 0x4FF540, 0x5AEEE6F7, 0x0000 }, // ?Init@mmTextNode@@QAEXMMMMHH@Z
    { 0x4FF690, 0x6DADC8AA, 0x0000 }, // ?SetBGColor@mmTextNode@@QAEXAAVVector4@@@Z
    { 0x4FF6F0, 0xD1A32C89, 0x0000 }, // ?SetFGColor@mmTextNode@@QAEXAAVVector4@@@Z
    { 0x4FF750, 0x84E6E54B, 0x0000 }, // ?GetFGColor@mmTextNode@@QAEIXZ
    { 0x4FF760, 0xBE5607C7, 0x0000 }, // ?SetEffects@mmTextNode@@QAEXHH@Z
    { 0x4FF790, 0x128E7AC1, 0x0000 }, // ?GetTextDimensions@mmTextNode@@QAEXPAXPAULocString@@AAM2@Z
    { 0x4FF8D0, 0xA7AF84F0, 0x0000 }, // ?SetTextPosition@mmTextNode@@QAEXHMM@Z
    { 0x4FF930, 0x5F183F86, 0x0000 }, // ?AddText@mmTextNode@@QAEHPAXPAULocString@@HMM@Z
    { 0x4FFA40, 0xB3AAB050, 0x0000 }, // ?SetString@mmTextNode@@QAEXHPAULocString@@@Z
    { 0x4FFAA0, 0x9CA2CF90, 0x0000 }, // ?SetPosition@mmTextNode@@QAEXHMM@Z
    { 0x4FFB00, 0x014703B8, 0x0000 }, // ?Printf@mmTextNode@@QAAXPBDZZ
    { 0x4FFB30, 0xFDCFE848, 0x0000 }, // ?Update@mmTextNode@@UAEXXZ
    { 0x4FFB60, 0x4C93FF23, 0x0000 }, // ?RenderText@mmTextNode@@QAEXPAVagiSurfaceDesc@@PAUmmTextData@@HI@Z
    { 0x4FFD90, 0x86033D1A, 0x0000 }, // ?Cull@mmTextNode@@UAEXXZ
    { 0x4FFEA0, 0xD0B6F4AA, 0x0000 }, // ??0asMeshSetForm@@QAE@XZ
    { 0x4FFEC0, 0x9FC1854F, 0x0000 }, // ?SetShape@asMeshSetForm@@QAEXPAD0PAVVector3@@@Z
    { 0x4FFF00, 0x98C43EB0, 0x0000 }, // ?SetZRead@asMeshSetForm@@QAEXH@Z
    { 0x4FFF20, 0x085EA776, 0x0000 }, // ?SetZWrite@asMeshSetForm@@QAEXH@Z
    { 0x4FFF40, 0xAA1F126A, 0x0000 }, // ?Update@asMeshSetForm@@UAEXXZ
    { 0x4FFF60, 0x70C5AFD0, 0x0000 }, // ?Cull@asMeshSetForm@@UAEXXZ
    { 0x5000A0, 0x13EE5BBD, 0x0000 }, // ??1asMeshSetForm@@UAE@XZ
    { 0x5000B0, 0xB22D50D2, 0x0000 }, // ??0asParticles@@QAE@XZ
    { 0x500120, 0x550632E7, 0x0000 }, // ??1asParticles@@UAE@XZ
    { 0x5001A0, 0x048DECA6, 0x0000 }, // ?Init@asParticles@@QAEXHHHHPAUagiMeshCardVertex@@@Z
    { 0x500210, 0x089D2925, 0x0000 }, // ?Reset@asParticles@@UAEXXZ
    { 0x500220, 0x10803341, 0x0000 }, // ?SetTexture@asParticles@@QAEXPAVagiTexDef@@@Z
    { 0x500250, 0x25EFB1A0, 0x0000 }, // ?SetTexture@asParticles@@QAEXPAD@Z
    { 0x5002A0, 0xF7143463, 0x0000 }, // ?Update@asParticles@@UAEXXZ
    { 0x5005F0, 0x8CA1171C, 0x0000 }, // ?Blast@asParticles@@QAEXHPAVasBirthRule@@@Z
    { 0x500690, 0x9060BF7D, 0x0000 }, // ?cmpPtx@@YAHPBX0@Z
    { 0x5006B0, 0xE43B36F3, 0x0000 }, // ?Cull@asParticles@@UAEXXZ
    { 0x500750, 0x03EA4E5E, 0x0000 }, // ?AddWidgets@asParticles@@UAEXPAVBank@@@Z
    { 0x500830, 0x37B4386B, 0x0000 }, // ?DeclareFields@asParticles@@SAXXZ
    { 0x500990, 0xA88044C4, 0x0000 }, // ?GetClass@asParticles@@UAEPAVMetaClass@@XZ
    { 0x500A00, 0x8233C1AC, 0x0000 }, // ??0asBirthRule@@QAE@XZ
    { 0x500AB0, 0x07F71C80, 0x0000 }, // ?InitSpark@asBirthRule@@QAEXPAUasSparkInfo@@PAUasSparkPos@@@Z
    { 0x500D30, 0x95C17737, 0x0000 }, // ?AddWidgets@asBirthRule@@UAEXPAVBank@@@Z
    { 0x5012A0, 0xCE248B25, 0x0000 }, // ?DeclareFields@asBirthRule@@SAXXZ
    { 0x501620, 0x49B6C52A, 0x0000 }, // ?GetClass@asBirthRule@@UAEPAVMetaClass@@XZ
    { 0x501700, 0x6B3E0174, 0x0000 }, // ?GetSparkLut@@YAPAVasSparkLut@@PAD@Z
    { 0x501740, 0x8421F00F, 0x0000 }, // ?Init@asSparkLut@@QAEXPAD@Z
    { 0x501920, 0x908CE271, 0x0000 }, // ?Init@asLineSparks@@QAEXHPAVasSparkLut@@@Z
    { 0x501A10, 0x52A60213, 0x0000 }, // ?AddWidgets@asLineSparks@@QAEXPAVBank@@@Z
    { 0x501C40, 0xDCDB1182, 0x0000 }, // ?RadialBlast@asLineSparks@@QAEXHAAVVector3@@0@Z
    { 0x501F80, 0x12AAC459, 0x0000 }, // ?Update@asLineSparks@@QAEXXZ
    { 0x501FC0, 0xF6A60C22, 0x0000 }, // ?Update@asLineSparks@@QAEXM@Z
    { 0x502190, 0x5F19B8D8, 0x0000 }, // ?Draw@asLineSparks@@QAEXXZ
    { 0x502220, 0x3E8B2A78, 0x0000 }, // ??0mmDamage@@QAE@XZ
    { 0x502230, 0xB3C153B9, 0x0000 }, // ??1mmDamage@@QAE@XZ
    { 0x502240, 0xBB26F700, 0x0000 }, // ?Init@mmDamage@@QAEXPAVagiMeshSet@@@Z
    { 0x502420, 0x119BBCF5, 0x0000 }, // ?Reset@mmDamage@@QAEXH@Z
    { 0x502470, 0x576319D3, 0x0000 }, // ?Apply@mmDamage@@QAEXAAVVector3@@M@Z
    { 0x5026B0, 0x5D75FC45, 0x0000 }, // ??0mmVehicleForm@@QAE@XZ
    { 0x502710, 0x116457D9, 0x0000 }, // ?SetShape@mmVehicleForm@@QAEXPAD00PAVVector3@@@Z
    { 0x502780, 0x1FCB102B, 0x0000 }, // ?Update@mmVehicleForm@@UAEXXZ
    { 0x5027A0, 0x38CC2A34, 0x0000 }, // ?Cull@mmVehicleForm@@UAEXXZ
    { 0x502930, 0x73937AAF, 0x0000 }, // ??0mmMouseSteerBar@@QAE@XZ
    { 0x502950, 0x2DFAA80D, 0x0000 }, // ??1mmMouseSteerBar@@UAE@XZ
    { 0x502960, 0x1E9E6D42, 0x0000 }, // ?Init@mmMouseSteerBar@@QAEXMMPAM@Z
    { 0x502A00, 0xD1050DDB, 0x0000 }, // ?Update@mmMouseSteerBar@@UAEXXZ
    { 0x502A30, 0xEE5CCCB2, 0x0000 }, // ?Cull@mmMouseSteerBar@@UAEXXZ
    { 0x502AB0, 0x90A45381, 0x0000 }, // ?AddWidgets@mmMouseSteerBar@@UAEXPAVBank@@@Z
    { 0x502BD0, 0xF4E39EA4, 0x0000 }, // ?BinaryLoad@agiMeshSet@@QAEXPAVStream@@@Z
    { 0x503180, 0xB6DBD269, 0x0000 }, // ?PageOutCallback@agiMeshSet@@CAXPAXH@Z
    { 0x5032A0, 0x4B532335, 0x0000 }, // ?DoPageIn@agiMeshSet@@AAEXXZ
    { 0x503830, 0x86926B6F, 0x0000 }, // ??0agiTexSorter@@QAE@XZ
    { 0x503A50, 0xEA7AD6EE, 0x0000 }, // ??1agiTexSorter@@QAE@XZ
    { 0x503A60, 0x78359B49, 0x0000 }, // ?GetEnv@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@HH@Z
    { 0x503B20, 0x5DF42CF5, 0x0000 }, // ?BeginVerts@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@HH@Z
    { 0x503D70, 0x09700686, 0x0000 }, // ?BeginVerts2@agiTexSorter@@SAPAVagiPolySet@@PAVagiTexDef@@0HH@Z
    { 0x503FF0, 0xD1FDBED0, 0x0000 }, // ?EndVerts@agiTexSorter@@SAXXZ
    { 0x504040, 0x0019CEE4, 0x0000 }, // ?EndVerts2@agiTexSorter@@SAXXZ
    { 0x504090, 0x8F036026, 0x0000 }, // ?Cull@agiTexSorter@@QAEXH@Z
    { 0x504150, 0xD26D68CC, 0x0000 }, // ?DoTexture@agiTexSorter@@SAXPAVagiPolySet@@@Z
    { 0x5043E0, 0x7A926638, 0x0000 }, // ?GetPackedTexture@@YAPAVagiTexDef@@PADH@Z
    { 0x504620, 0x8E4DCCFB, 0x0000 }, // ?AddWidgets@agiTexSorter@@QAEXPAVBank@@@Z
    { 0x504690, 0x2993C7FA, 0x0000 }, // ?SetClipMode@@YAXH@Z
    { 0x504730, 0x0DCB78B8, 0x0000 }, // ?InitMtx@agiMeshSet@@KIXAAVagiViewParameters@@H@Z
    { 0x504A00, 0x855F6016, 0x0000 }, // ?InitLocalize@agiMeshSet@@SAXXZ
    { 0x504AC0, 0x7E77B504, 0x0000 }, // ?Localize@agiMeshSet@@SAXAAVVector3@@0@Z
    { 0x504B70, 0x4891FEE8, 0x0000 }, // ?LocalizeDirection@agiMeshSet@@SAXAAVVector3@@0@Z
    { 0x504C00, 0x50DE18D6, 0x0000 }, // ?Init@agiMeshSet@@SIXH@Z
    { 0x504C80, 0xCB575209, 0x0000 }, // ?ShadowInit@agiMeshSet@@KIXABVVector4@@ABVVector3@@@Z
    { 0x504EB0, 0x5C311115, 0x0000 }, // ?InitViewport@agiMeshSet@@KIXAAVagiViewParameters@@@Z
    { 0x5050C0, 0xA9DF156F, 0x0000 }, // ?SetFog@agiMeshSet@@SAXMH@Z
    { 0x5050F0, 0xBCD5F4C9, 0x0000 }, // ?Transform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z
    { 0x505360, 0xE50A2CF7, 0x0000 }, // ?ShadowTransform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z
    { 0x5055E0, 0x9086ABF6, 0x0000 }, // ?TransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z
    { 0x505990, 0x0B21F90F, 0x0000 }, // ?EyePlaneOutcode@@YAIPAEEAAVVector4@@PAVVector3@@H@Z
    { 0x505A30, 0x2787185F, 0x0000 }, // ?ShadowTransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z
    { 0x505E00, 0x14FA7A48, 0x0000 }, // ?begin_invert@@YIXPAVVector4@@@Z
    { 0x505E10, 0xB1FA62FE, 0x0000 }, // ?end_invert@@YIXPAVVector4@@@Z
    { 0x505E20, 0xDC36791E, 0x0000 }, // ?BeginGfx@agiMeshSet@@AAEXXZ
    { 0x505E30, 0x4477F9C3, 0x0000 }, // ?EndGfx@agiMeshSet@@AAEXXZ
    { 0x505E40, 0xC171E018, 0x0000 }, // ?ClipTri@agiMeshSet@@IAEXHHHH@Z
    { 0x5061B0, 0x330E5A3D, 0x0000 }, // ?FullClip@@YAHPAUCV@@0H@Z
    { 0x506260, 0x2EDC4DA2, 0x0000 }, // ?ClipNX@@YAHPAUCV@@0H@Z
    { 0x506380, 0x7C097EF8, 0x0000 }, // ?ClipNX@@YIXAAUCV@@0@Z
    { 0x506470, 0x995BCDE7, 0x0000 }, // ?ClipPX@@YAHPAUCV@@0H@Z
    { 0x506590, 0x7D10BC56, 0x0000 }, // ?ClipPX@@YIXAAUCV@@0@Z
    { 0x506680, 0x068327F3, 0x0000 }, // ?ClipNY@@YAHPAUCV@@0H@Z
    { 0x5067A0, 0xFEC5B6A9, 0x0000 }, // ?ClipNY@@YIXAAUCV@@0@Z
    { 0x506890, 0x5C316B90, 0x0000 }, // ?ClipPY@@YAHPAUCV@@0H@Z
    { 0x5069B0, 0xE178F4CA, 0x0000 }, // ?ClipPY@@YIXAAUCV@@0@Z
    { 0x506A90, 0x0F198189, 0x0000 }, // ?ClipNZ@@YAHPAUCV@@0H@Z
    { 0x506BB0, 0x84E2548B, 0x0000 }, // ?ClipNZ@@YIXAAUCV@@0@Z
    { 0x506CA0, 0x20F6640A, 0x0000 }, // ?ClipPZ@@YAHPAUCV@@0H@Z
    { 0x506DC0, 0x691BE920, 0x0000 }, // ?ClipPZ@@YIXAAUCV@@0@Z
    { 0x506EA0, 0x3BC50353, 0x0000 }, // ?ZClipOnly@@YAHPAUCV@@0H@Z
    { 0x506ED0, 0x865EB6A2, 0x0000 }, // ?Draw@agiMeshSet@@QAEHI@Z
    { 0x506F40, 0x5EF56C8B, 0x0000 }, // ?DrawShadow@agiMeshSet@@QAEXIABVVector4@@ABVVector3@@@Z
    { 0x506FD0, 0x2E90F627, 0x0000 }, // ?DrawColor@agiMeshSet@@QAEHII@Z
    { 0x507040, 0x176AC6F7, 0x0000 }, // ?DrawLit@agiMeshSet@@QAEHP6AXPAEPAI1PAV1@@ZI1@Z
    { 0x507120, 0xB4E5B3C1, 0x0000 }, // ?DrawLitEnv@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@AAVMatrix34@@I@Z
    { 0x507250, 0x3B632129, 0x0000 }, // ?DrawLitSph@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@I@Z
    { 0x507320, 0x6B7C7A05, 0x0000 }, // ?Geometry@agiMeshSet@@QAEHIPAVVector3@@PAVVector4@@@Z
    { 0x507920, 0x462C1188, 0x0000 }, // ?ShadowGeometry@agiMeshSet@@QAEHIPAVVector3@@ABVVector4@@ABV2@@Z
    { 0x507D30, 0x02B53673, 0x0000 }, // ?FirstPass_SW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x508330, 0xAEA2273E, 0x0000 }, // ?FirstPass_SW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x508910, 0x65D6AC82, 0x0000 }, // ?FirstPass_SW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x508D30, 0x7C260E2F, 0x0000 }, // ?FirstPass_SW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x509130, 0x93F124A2, 0x0000 }, // ?FirstPass_SW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x5095E0, 0x15E91DFD, 0x0000 }, // ?FirstPass_SW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x509A70, 0x3D280A66, 0x0000 }, // ?FirstPass_SW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x509D30, 0xBB117B71, 0x0000 }, // ?FirstPass_SW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x509FE0, 0x168C3474, 0x0000 }, // ?FirstPass_HW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50A780, 0xD456D129, 0x0000 }, // ?FirstPass_HW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50AF10, 0x0AED3E62, 0x0000 }, // ?FirstPass_HW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50B4E0, 0x82B656F1, 0x0000 }, // ?FirstPass_HW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50BA90, 0xEC4408F0, 0x0000 }, // ?FirstPass_HW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50C130, 0x2A1D59A6, 0x0000 }, // ?FirstPass_HW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50C7A0, 0x7A812844, 0x0000 }, // ?FirstPass_HW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50CC50, 0x0C5C6832, 0x0000 }, // ?FirstPass_HW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50D0E0, 0x5242DE07, 0x0000 }, // ?FirstPass@agiMeshSet@@QAEXPAIPAVVector2@@I@Z
    { 0x50D170, 0x05997141, 0x0000 }, // ?MultiTexEnvMap@agiMeshSet@@QAEXPAIIPAVagiTexDef@@AAVMatrix34@@@Z
    { 0x50DB10, 0x817F8833, 0x0000 }, // ?EnvMap@agiMeshSet@@QAEXAAVMatrix34@@PAVagiTexDef@@I@Z
    { 0x50E1D0, 0x22A1FA54, 0x0000 }, // ?SphereMap@agiMeshSet@@QAEXPAVagiTexDef@@I@Z
    { 0x50EBC0, 0x4B826C28, 0x0000 }, // ?DrawNormals@agiMeshSet@@QAEXAAVVector3@@@Z
    { 0x50EC90, 0x5BBA76C8, 0x0000 }, // ?Init@agiMeshCardInfo@@QAEXHPAUagiMeshCardVertex@@HHH@Z
    { 0x50EE30, 0x9E269D8D, 0x0000 }, // ?InitCards@agiMeshSet@@SAXAAUagiMeshCardInfo@@@Z
    { 0x50EE70, 0x34B0BA02, 0x0000 }, // ?DrawCard@agiMeshSet@@SAXAAVVector3@@MIII@Z
    { 0x50F9B0, 0xC93DD8D6, 0x0000 }, // ?DrawLines@agiMeshSet@@SAXPAVVector3@@0PAIH@Z
    { 0x50FE00, 0x6C304D5B, 0x0000 }, // ?DrawWideLines@agiMeshSet@@SAXPAVVector3@@0PAMPAIH@Z
    { 0x510480, 0xB275797A, 0x0000 }, // ?Triangle@agiPolySet@@QAEXHHH@Z
    { 0x510640, 0xC8EC76CF, 0x0000 }, // ?agiMeshLighterReset@@YAXXZ
    { 0x510730, 0x9D7F03A5, 0x0000 }, // ?agiMeshLighterQuarter@@YAXPAEPAI1PAVagiMeshSet@@@Z
    { 0x5108F0, 0x3A08EEB7, 0x0000 }, // ?agiMeshLighterUpdateColors@@YAXXZ
    { 0x510AE0, 0xC2FB9CEC, 0x0000 }, // ?agiMeshLighterTriple@@YAXPAEPAI1PAVagiMeshSet@@@Z
    { 0x510EE0, 0x320939EA, 0x0000 }, // ?mmxTriple@@YAXPAI0HPAEH@Z
    { 0x511010, 0x39651E2F, 0x0000 }, // ?agiMeshPrelight@@YAXPAIPAVagiMeshSet@@AAVMatrix34@@@Z
    { 0x5111E0, 0x96D1D14E, 0x0000 }, // ?agiBeginCones@@YAXXZ
    { 0x5111F0, 0x787BCCCD, 0x0000 }, // ?agiDeclareCone@@YAXAAVVector3@@00MM0H@Z
    { 0x5112C0, 0x45EE423D, 0x0000 }, // ?agiConeLighter@@YAXPAEPAI1PAVagiMeshSet@@@Z
    { 0x5116B0, 0x793DC7F3, 0x0000 }, // ?agiInitCones@@YAXAAVMatrix34@@M@Z
    { 0x5118F0, 0x76247385, 0x0000 }, // ?agiDrawCones@@YAXXZ
    { 0x5119F0, 0x5DF2433C, 0x0000 }, // ?agiMeshLighterSpecular@@YAXPAEPAI1PAVagiMeshSet@@@Z
    { 0x511B30, 0x1AC396C1, 0x0000 }, // ?mystrtok@@YAPADPADPBD@Z
    { 0x511B90, 0x126D97B6, 0x0000 }, // ?Load@agiTexSheet@@QAEXPAD@Z
    { 0x512080, 0xF0E31F69, 0x0000 }, // ?cmpTex@@YAHPBX0@Z
    { 0x5120A0, 0x416B2618, 0x0000 }, // ?Kill@agiTexSheet@@QAEXXZ
    { 0x5120D0, 0x6BBC95ED, 0x0000 }, // ?Save@agiTexSheet@@QAEXPAD@Z
    { 0x512340, 0xDB0D0BBF, 0x0000 }, // ?Lookup@agiTexSheet@@QAEPAUagiTexProp@@PADH@Z
    { 0x5123A0, 0x8E7970A1, 0x0000 }, // ?LookupAlternate@agiTexSheet@@QAEPAUagiTexProp@@PAD@Z
    { 0x512410, 0x5EE60CB6, 0x0000 }, // ?GetVariationCount@agiTexSheet@@QAEHPAD@Z
    { 0x512460, 0x07CD46F5, 0x0000 }, // ?RemapName@agiTexSheet@@QAEPADPADH@Z
    { 0x5124A0, 0x589C7871, 0x0000 }, // ?Add@agiTexSheet@@QAEXPAD@Z
    { 0x512610, 0x7254F5BB, 0x0000 }, // ?FixTexFlags@@YAXAAVagiTexParameters@@@Z
    { 0x5128A0, 0x2A14CCCF, 0x0000 }, // ?GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z
    { 0x5140E0, 0x2E09DD23, 0x0000 }, // ??0DLPVertex2@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@XZ
    { 0x5140F0, 0x6130CBCA, 0x0000 }, // ??0DLPVertex2@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@ABU0@@Z
    { 0x514150, 0xE1129C2D, 0x0000 }, // ??0nbuf@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@XZ
    { 0x514170, 0x48560832, 0x0000 }, // ??0nbuf@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@ABU0@@Z
    { 0x5141B0, 0xF6DD6764, 0x0000 }, // ?ModelGeometry@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    { 0x5142B0, 0xFCD8B3FD, 0x0000 }, // ?ModelDraw@agiMeshModel@@QAEHIPAVagiLitAnimation@@H@Z
    { 0x5142D0, 0xBDF5F676, 0x0000 }, // ?ModelDraw@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    { 0x514330, 0x0D36FEBC, 0x0000 }, // ?ModelDrawSkel@agiMeshModel@@QAEHIPAVbnAnimation@@H@Z
    { 0x5144F0, 0x7CFF1A87, 0x0000 }, // ?ModelDrawLit@agiMeshModel@@QAEHP6AXPAEPAI1PAVagiMeshSet@@@ZIPAVagiLitAnimation@@H@Z
    { 0x5145C0, 0x948E0809, 0x0000 }, // ??0agiLitAnimation@@QAE@PAVagiMeshModel@@PAVbnAnimation@@PAVStream@@@Z
    { 0x5147D0, 0xEAE652AF, 0x0000 }, // ??0agiMeshSet@@QAE@XZ
    { 0x5147F0, 0x7735FE7C, 0x0000 }, // ??1agiMeshSet@@QAE@XZ
    { 0x514880, 0x9D624E29, 0x0000 }, // ?Offset@agiMeshSet@@QAEXVVector3@@@Z
    { 0x5148D0, 0x0EFEF66F, 0x0000 }, // ?ComputePlaneEquations@agiMeshSet@@QAEXXZ
    { 0x514AF0, 0xF5701B27, 0x0000 }, // ?PageInCallback@agiMeshSet@@CAXPAX@Z
    { 0x514B00, 0x471FC8A5, 0x0000 }, // ?PageIn@agiMeshSet@@QAEXXZ
    { 0x514B20, 0x01AFA4E1, 0x0000 }, // ?LockIfResident@agiMeshSet@@QAEHXZ
    { 0x514B50, 0xCF2D54DB, 0x0000 }, // ?Unlock@agiMeshSet@@QAEXXZ
    { 0x514B70, 0xE53C4FCF, 0x0000 }, // ?UnlockAndFree@agiMeshSet@@QAEXXZ
    { 0x514B90, 0x3848F4B3, 0x0000 }, // ?MakeResident@agiMeshSet@@QAEXXZ
    { 0x514BC0, 0x8B1629E9, 0x0000 }, // ?IsFullyResident@agiMeshSet@@QAEHH@Z
    { 0x514C40, 0x30AECBF6, 0x0000 }, // ??0bnSkeleton@@QAE@XZ
    { 0x514C50, 0x833F267E, 0x0000 }, // ??1bnSkeleton@@QAE@XZ
    { 0x514C70, 0x2FF99149, 0x0000 }, // ?Load@bnSkeleton@@QAEHPBD@Z
    { 0x514FA0, 0x94249253, 0x0000 }, // ?Save@bnSkeleton@@QAEHPBD@Z
    { 0x515050, 0x713962E6, 0x0000 }, // ?Transform@bnSkeleton@@QAEXPAVMatrix34@@@Z
    { 0x515070, 0xB14BC1AA, 0x0000 }, // ?Draw@bnSkeleton@@QAEXXZ
    { 0x515080, 0x2A9B9C88, 0x0000 }, // ?Attach@bnSkeleton@@QAEXQAVMatrix34@@@Z
    { 0x5150B0, 0xCADA0780, 0x0000 }, // ?Pose@bnSkeleton@@QAEXPBVVector3@@@Z
    { 0x515100, 0x0BCF5541, 0x0000 }, // ?FindBone@bnSkeleton@@QAEPAVbnBone@@PADHD@Z
    { 0x515220, 0x2FEB25A2, 0x0000 }, // ?HowMany@bnSkeleton@@QAEHPADD@Z
    { 0x515260, 0xFA962833, 0x0000 }, // ?Load@bnAnimation@@QAEHPAD@Z
    { 0x5153F0, 0x48A77C9E, 0x0000 }, // ?Lookup@bnAnimation@@SAPAV1@PAD@Z
    { 0x5154C0, 0x6C36AA40, 0x0000 }, // ?GetModel@@YAPAVagiMeshModel@@PAD00@Z
    { 0x516400, 0x02C2AE46, 0x0000 }, // ?PackNormalSlow@@YAEAAVVector3@@@Z
    { 0x5164B0, 0xF253ADC6, 0x0000 }, // ?PackNormal@@YAEAAVVector3@@@Z
    { 0x516620, 0x0119B469, 0x0000 }, // ?ToScreen@agiMeshSet@@KIXPAEPAVVector4@@H@Z
    { 0x516B30, 0x7C6DEB34, 0x0000 }, // ?BinarySave@agiMeshSet@@QAEXPAVStream@@@Z
    { 0x516DE0, 0xE2695DC1, 0x0000 }, // ??0bnBone@@QAE@XZ
    { 0x516E40, 0xFBA0BE25, 0x0000 }, // ?AddChild@bnBone@@QAEXPAV1@@Z
    { 0x516E80, 0x57EB8E78, 0x0000 }, // ?Load@bnBone@@QAEHPAVTokenizer@@PAPAV1@@Z
    { 0x516F70, 0xCCFD3ACC, 0x0000 }, // ?Transform@bnBone@@QAEXPAVMatrix34@@@Z
    { 0x516FC0, 0xB7F43FE2, 0x0000 }, // ?Draw@bnBone@@QAEXXZ
    { 0x516FD0, 0x9E195B51, 0x0000 }, // ?Attach@bnBone@@QAEXQAVMatrix34@@AAH@Z
    { 0x517030, 0x9AC54464, 0x0000 }, // ?Pose@bnBone@@QAEXPBVVector3@@AAH@Z
    { 0x517090, 0xD3D2BB37, 0x0000 }, // ?Matrix34__FromEulersXZY@@YAXAAVMatrix34@@ABVVector3@@@Z
    { 0x5171D0, 0x9BC2D8BA, 0x0000 }, // ?InitGeometry@mmBoundTemplate@@QAEXHH@Z
    { 0x517280, 0x9CB9835D, 0x0000 }, // ?AddTriangle@mmBoundTemplate@@QAEXHHHHH@Z
    { 0x517370, 0xB366070F, 0x0000 }, // ?AddQuad@mmBoundTemplate@@QAEXHHHHHH@Z
    { 0x5175E0, 0x0D3FB401, 0x0000 }, // ?ComputeBounds@mmBoundTemplate@@QAEXXZ
    { 0x517620, 0xE68CEEF9, 0x0000 }, // ?EdgeInList@@YA_NHHJPAH0@Z
    { 0x517680, 0x3A6491A8, 0x0000 }, // ?ComputeEdges@mmBoundTemplate@@QAEXXZ
    { 0x517850, 0xDF0B6CE2, 0x0000 }, // ?Load@mmBoundTemplate@@QAEHPAD0PAVVector3@@HHHHHH@Z
    { 0x518D40, 0x352D60D2, 0x0000 }, // ?PageOutCallback@mmBoundTemplate@@CAXPAXH@Z
    { 0x518E90, 0xDCD84A09, 0x0000 }, // ?DoPageIn@mmBoundTemplate@@AAEXXZ
    { 0x5192F0, 0xF8C8F5FC, 0x0000 }, // ?PageInCallback@mmBoundTemplate@@CAXPAX@Z
    { 0x519300, 0xE25F58D3, 0x0000 }, // ?PageIn@mmBoundTemplate@@QAEXXZ
    { 0x519320, 0xF866C9E1, 0x0000 }, // ?LockIfResident@mmBoundTemplate@@QAEHXZ
    { 0x519380, 0xE84E45B7, 0x0000 }, // ?Unlock@mmBoundTemplate@@QAEXXZ
    { 0x5193A0, 0x8057D797, 0x0000 }, // ?ComputeEdgeNormals@mmBoundTemplate@@QAEXXZ
    { 0x519830, 0x42A12323, 0x0000 }, // ?MakeTable@mmBoundTemplate@@AAEXHHH@Z
    { 0x519A30, 0x9D5BFE28, 0x0000 }, // ?DoMakeTable@mmBoundTemplate@@AAEXHHH@Z
    { 0x519F70, 0x76564F1C, 0x0000 }, // ?AddIndex@mmBoundTemplate@@QAEXHHH@Z
    { 0x51A090, 0x172C93A5, 0x0000 }, // ?PlotLine@mmBoundTemplate@@QAEXVVector3@@0@Z
    { 0x51A1A0, 0x36E96611, 0x0000 }, // ?PlotSpan@mmBoundTemplate@@QAEXHHH@Z
    { 0x51A1B0, 0xFE4066F8, 0x0000 }, // ??0mmIntersection@@QAE@XZ
    { 0x51A1C0, 0x1A2C8FAD, 0x0000 }, // ?InitSegment@mmIntersection@@QAEXABVVector3@@0PAVmmBoundTemplate@@HH@Z
    { 0x51A2D0, 0xB4EFAC47, 0x0000 }, // ?InitTransformedSegment@mmIntersection@@QAEXABVVector3@@0PAVmmBoundTemplate@@HH@Z
    { 0x51A3B0, 0x74DCB5E7, 0x0000 }, // ?InitSphere@mmIntersection@@QAEXABVVector3@@MPAVmmBoundTemplate@@H@Z
    { 0x51A410, 0xC9CCE4B8, 0x0000 }, // ?InitTransformedSphere@mmIntersection@@QAEXABVVector3@@MPAVmmBoundTemplate@@H@Z
    { 0x51A470, 0x391501D0, 0x0000 }, // ?Reset@mmIntersection@@QAEXXZ
    { 0x51A4D0, 0x80FE29FF, 0x0000 }, // ?Transform@mmIntersection@@QAEXPBVMatrix34@@@Z
    { 0x51A5A0, 0x2C0B3F2F, 0x0000 }, // ?Draw@mmIntersection@@QAEXXZ
    { 0x51A650, 0xCB0FE4EF, 0x0000 }, // ??0mmEdgeBodyIsect@@QAE@XZ
    { 0x51A660, 0x2EC0A72D, 0x0000 }, // ?Reset@mmEdgeBodyIsect@@QAEXXZ
    { 0x51A680, 0xCE43AA1C, 0x0000 }, // ?InitSegment@mmEdgeBodyIsect@@QAEXABVVector3@@0HH0M@Z
    { 0x51A720, 0x69FFC257, 0x0000 }, // ?Draw@mmEdgeBodyIsect@@QAEXXZ
    { 0x51A7E0, 0x2A24C754, 0x0000 }, // ??0mmPolygon@@QAE@XZ
    { 0x51A820, 0xD9832476, 0x0000 }, // ?Init@mmPolygon@@AAEXXZ
    { 0x51ADA0, 0x23C3F50D, 0x0000 }, // ?GetST@mmPolygon@@AAEXPAVVector3@@0PAVmmBoundTemplate@@@Z
    { 0x51AEB0, 0xBE2D843E, 0x0000 }, // ?FullSegment@mmPolygon@@AAEHPAVmmEdgeBodyIsect@@@Z
    { 0x51B440, 0x74DD1ABA, 0x0000 }, // ?FullSegment@mmPolygon@@AAEHPAVmmIntersection@@@Z
    { 0x51B990, 0x80A966F9, 0x0000 }, // ?GetCorner@mmPolygon@@AAEHAAVVector3@@00000AAM@Z
    { 0x51BC80, 0x56454479, 0x0000 }, // ?FullSphere@mmPolygon@@AAEHPAVmmIntersection@@@Z
    { 0x51C2A0, 0xED565D85, 0x0000 }, // ?Draw@mmPolygon@@AAEXXZ
    { 0x51C320, 0xFF83ED69, 0x0000 }, // ?Plot@mmPolygon@@AAEXPAVmmBoundTemplate@@H@Z
    { 0x51C380, 0x81EA1FB1, 0x0000 }, // ?PlotTriangle@mmPolygon@@AAEXHHHPAVmmBoundTemplate@@H@Z
    { 0x51CBD0, 0x793837A6, 0x0000 }, // ?PlotScan@mmPolygon@@AAEXHHHPAVmmBoundTemplate@@H@Z
    { 0x51CC60, 0xFA7240A7, 0x0000 }, // ?MaxY@mmPolygon@@AAEMMMMM@Z
    { 0x51CDB0, 0x965EF100, 0x0000 }, // ?CornersHeight@mmPolygon@@AAEMMMMM@Z
    { 0x51CFD0, 0xEB5198DE, 0x0000 }, // ?CheckCorner@mmPolygon@@AAEMMMPAM00@Z
    { 0x51D080, 0xD677B75D, 0x0000 }, // ?CheckCellXSide@mmPolygon@@AAEMMMM@Z
    { 0x51D170, 0xBC29DF91, 0x0000 }, // ?CheckCellZSide@mmPolygon@@AAEMMMM@Z
    { 0x51D2E0, 0xB85B68E1, 0x0000 }, // ?GetBoundTemplate@mmBoundTemplate@@SAPAV1@PAD0PAVVector3@@HHHHH@Z
    { 0x51D3F0, 0x8C53388F, 0x0000 }, // ?MakeBox@mmBoundTemplate@@SAPAV1@PAD0HPAVVector3@@1@Z
    { 0x51D8F0, 0x925FFB01, 0x0000 }, // ?AddRef@mmBoundTemplate@@QAEXXZ
    { 0x51D910, 0x1F4EB936, 0x0000 }, // ?Release@mmBoundTemplate@@QAEHXZ
    { 0x51D940, 0x0410B332, 0x0000 }, // ?ValidatePtr@mmBoundTemplate@@QAEXPAD@Z
    { 0x51D9A0, 0x20763A23, 0x0000 }, // ??0mmBoundTemplate@@QAE@XZ
    { 0x51DA60, 0x0576EF7C, 0x0000 }, // ??1mmBoundTemplate@@QAE@XZ
    { 0x51DB20, 0xDBD77746, 0x0000 }, // ?Reset@mmBoundTemplate@@QAEXXZ
    { 0x51DB70, 0xF0C959E2, 0x0000 }, // ?Collide@mmBoundTemplate@@QAEHPAV1@AAVMatrix34@@11PAVmmEdgeBodyIsect@@HHPAVasInertialCS@@3PAVVector3@@4@Z
    { 0x51E240, 0x9E99A84F, 0x0000 }, // ?CollideTerrains@mmBoundTemplate@@QAEHPAPAV1@AAVMatrix34@@PAVmmEdgeBodyIsect@@HH@Z
    { 0x51E4F0, 0xB45222F9, 0x0000 }, // ?Collide@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    { 0x51E550, 0xCE4C648D, 0x0000 }, // ?Collide@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51E620, 0xDD173062, 0x0000 }, // ?QuickSphereSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51E6C0, 0x37F582E8, 0x0000 }, // ?QuickLineSphere@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@@Z
    { 0x51E820, 0x55A0CE32, 0x0000 }, // ?QuickLineSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51E940, 0x9DD7E734, 0x0000 }, // ?QuickSphereBox@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51EA00, 0xFA8599EC, 0x0000 }, // ?QuickLineBox@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@@Z
    { 0x51EAF0, 0x74531305, 0x0000 }, // ?QuickLineBox@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51EBE0, 0x94BDB32C, 0x0000 }, // ?SphereSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51ED80, 0x39FA8C67, 0x0000 }, // ?SphereGeometry@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51EEB0, 0x562C6091, 0x0000 }, // ?SphereTable@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51F110, 0xCE41980F, 0x0000 }, // ?LineSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51F120, 0x09C79CD7, 0x0000 }, // ?LineGeometry@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    { 0x51F1E0, 0x5C4EA83B, 0x0000 }, // ?LineTable@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    { 0x51F500, 0xEE8CB8A0, 0x0000 }, // ?LineSpan@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@HHHH@Z
    { 0x51F670, 0x6383021F, 0x0000 }, // ?LineGeometry@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51F7A0, 0x68B888E2, 0x0000 }, // ?LineTable@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    { 0x51FB20, 0x4B02ED1A, 0x0000 }, // ?LineSpan@mmBoundTemplate@@QAEHPAVmmIntersection@@HHH@Z
    { 0x51FCF0, 0x8ACA39C9, 0x0000 }, // ?Draw@mmBoundTemplate@@QAEXXZ
    { 0x51FD30, 0x00006BB0, 0x0000 }, // ?DrawSphere@mmBoundTemplate@@QAEXXZ
    { 0x51FD70, 0xBA6096D0, 0x0000 }, // ?DrawBox@mmBoundTemplate@@QAEXXZ
    { 0x51FD90, 0x28AF4183, 0x0000 }, // ?DrawGeometry@mmBoundTemplate@@QAEXXZ
    { 0x51FE00, 0x075ED026, 0x0000 }, // ?DrawTable@mmBoundTemplate@@QAEXXZ
    { 0x520000, 0xD42F1FBB, 0x0000 }, // ?DrawGraph@mmBoundTemplate@@QAEXXZ
    { 0x520010, 0xF8F68CE2, 0x0000 }, // ?GetLocTime@@YAPADM@Z
    { 0x5200D0, 0x9F989469, 0x0000 }, // ?AngelReadString@@YAPAULocString@@I@Z
    { 0x520130, 0xC772BD28, 0x0000 }, // ?LookupAddress@@YAXPADH@Z
    { 0x5201C0, 0xC9B6326C, 0x0000 }, // ?InitMap@@YAXXZ
    { 0x5204C0, 0x2613DF48, 0x0000 }, // ?DoStackTraceback@@YAXHPAH@Z
    { 0x520590, 0x33978FF0, 0x0000 }, // ?StackTraceback@@YAXH@Z
    { 0x5205B0, 0x8D5A4FFA, 0x0000 }, // ?LogStackTraceback@@YAHPAHH@Z
    { 0x520670, 0x71CC1044, 0x0000 }, // ?DumpStackTraceback@@YAXPAHH@Z
    { 0x5206C0, 0xBFA4AB4B, 0x0000 }, // ?DebugLogInit@@YAXH@Z
    { 0x520700, 0x511DC726, 0x0000 }, // ?DebugLogShutdown@@YAXXZ
    { 0x520720, 0x6C27BC86, 0x0000 }, // ?DebugLog@@YAXHPAXH@Z
    { 0x5209B0, 0x46F56CFD, 0x0000 }, // ??0asMemoryAllocator@@QAE@XZ
    { 0x5209C0, 0x48C1415D, 0x0000 }, // ??1asMemoryAllocator@@QAE@XZ
    { 0x5209D0, 0x8E03AB21, 0x0000 }, // ?Init@asMemoryAllocator@@QAEXPAXIH@Z
    { 0x520A10, 0x30155CFC, 0x0000 }, // ?Kill@asMemoryAllocator@@QAEXXZ
    { 0x520A20, 0x8A462D45, 0x0000 }, // ?Allocate@asMemoryAllocator@@QAEPAXI@Z
    { 0x520C40, 0x1DF7E1B3, 0x0000 }, // ?CheckPointer@asMemoryAllocator@@QAEXPAX@Z
    { 0x520C90, 0x16347040, 0x0000 }, // ?Free@asMemoryAllocator@@QAEXPAX@Z
    { 0x520DF0, 0x486B23DD, 0x0000 }, // ?Unlink@asMemoryAllocator@@AAEXPAUnode@1@@Z
    { 0x520E50, 0xB86B998F, 0x0000 }, // ?Link@asMemoryAllocator@@AAEXPAUnode@1@@Z
    { 0x520EA0, 0x64D6E114, 0x0000 }, // ?Reallocate@asMemoryAllocator@@QAEPAXPAXI@Z
    { 0x520F00, 0x93655D92, 0x0000 }, // ?Verify@asMemoryAllocator@@AAEXPAX@Z
    { 0x520FC0, 0xD8FF3A26, 0x0000 }, // ?GetStats@asMemoryAllocator@@QAEXPAUasMemStats@@@Z
    { 0x521090, 0x4BA38D37, 0x0000 }, // ?SanityCheck@asMemoryAllocator@@QAEXXZ
    { 0x521250, 0x7D517FA6, 0x0000 }, // ?HeapAssert@@YAHPAXHPADH@Z
    { 0x521390, 0x2645ADA6, 0x0000 }, // ??0asSafeHeap@@QAE@XZ
    { 0x5213A0, 0x9E615BC9, 0x0000 }, // ??1asSafeHeap@@QAE@XZ
    { 0x5213B0, 0x2051A1C6, 0x0000 }, // ?Init@asSafeHeap@@QAEXHH@Z
    { 0x521420, 0x20A6138F, 0x0000 }, // ?Restart@asSafeHeap@@QAEXXZ
    { 0x521450, 0x715EB285, 0x0000 }, // ?Kill@asSafeHeap@@QAEXXZ
    { 0x521480, 0x024502A5, 0x0000 }, // ?Activate@asSafeHeap@@IAEXXZ
    { 0x5214C0, 0x337722C0, 0x0000 }, // ?Deactivate@asSafeHeap@@IAEXXZ
    { 0x5214F0, 0xB0A73A48, 0x0000 }, // _malloc
    { 0x521510, 0xB50C6BC2, 0x0000 }, // _realloc
    { 0x521530, 0x47CB5C9B, 0x0000 }, // _calloc
    { 0x521570, 0x4F0E36B1, 0x0000 }, // _free
    { 0x521590, 0x629B0BB5, 0x0000 }, // __msize
    { 0x5215A0, 0x41E62155, 0x0000 }, // ??2@YAPAXI@Z
    { 0x5215C0, 0xF9F84998, 0x0000 }, // ??3@YAXPAX@Z
    { 0x5215E0, 0x72455801, 0x0000 }, // __realloc_dbg
    { 0x521630, 0x0E2CA990, 0x0000 }, // __malloc_dbg
    { 0x521670, 0x8520E5A9, 0x0000 }, // __free_dbg
    { 0x5216B0, 0x05564945, 0x0000 }, // __calloc_dbg
    { 0x521710, 0x54BD8273, 0x0000 }, // __msize_dbg
    { 0x521730, 0x3EEC93CA, 0x0000 }, // __CrtCheckMemory
    { 0x521740, 0xC1C8B7A9, 0x0000 }, // __CrtSetDbgFlag
    { 0x521750, 0xE9E02E19, 0x0000 }, // __CrtIsValidPointer
    { 0x521790, 0x85B506F9, 0x0000 }, // __CrtMemCheckpoint
    { 0x5217D0, 0x07129F5B, 0x0000 }, // __CrtDumpMemoryLeaks
    { 0x521800, 0x7DF4E18F, 0x0000 }, // ??0asSimulation@@QAE@XZ
    { 0x521A60, 0xD06AD989, 0x0000 }, // ??1asSimulation@@UAE@XZ
    { 0x521C10, 0xB5A0607F, 0x0000 }, // ?Quiet@asSimulation@@QAEXXZ
    { 0x521C20, 0xC7A43DD5, 0x0000 }, // ?QuietPrinter@@YAXHPBDPAD@Z
    { 0x521C40, 0xADAED8BE, 0x0000 }, // ?Init@asSimulation@@QAEXPADHPAPAD@Z
    { 0x522290, 0x938F61A8, 0x0000 }, // ?Reset@asSimulation@@UAEXXZ
    { 0x5222A0, 0x9C571D68, 0x0000 }, // ?FirstUpdate@asSimulation@@QAEXXZ
    { 0x5222C0, 0xC051E4EC, 0x0000 }, // ?Update@asSimulation@@UAEXXZ
    { 0x5225F0, 0x5CBCD900, 0x0000 }, // ?invert@@YANN@Z
    { 0x522600, 0x7AD2F63D, 0x0000 }, // ?Device@asSimulation@@QAEXXZ
    { 0x5229C0, 0x231A91A5, 0x0000 }, // ?Widgets@asSimulation@@QAEXXZ
    { 0x522A60, 0x1B14AB7E, 0x0000 }, // ?Simulate@asSimulation@@QAEXXZ
    { 0x522B10, 0x9173C0D2, 0x0000 }, // ?UpdatePaused@asSimulation@@QAEXPAVasNode@@@Z
    { 0x522B80, 0x354C495F, 0x0000 }, // ?DeclareVector@asSimulation@@QAEXPBVVector3@@00@Z
    { 0x522C20, 0x33EEEB0F, 0x0000 }, // ?Cull@asSimulation@@UAEXXZ
    { 0x522CA0, 0xACC6FDA6, 0x0000 }, // ?ResetClock@asSimulation@@QAEXXZ
    { 0x522CF0, 0xFF1A9953, 0x0000 }, // ?BeginOverSample@asSimulation@@QAEXH@Z
    { 0x522D30, 0x4DC374D2, 0x0000 }, // ?EndOverSample@asSimulation@@QAEXXZ
    { 0x522D60, 0x1229F6FC, 0x0000 }, // ?EndOverSample@asSimulation@@QAEXH@Z
    { 0x522D90, 0xD4B08EB4, 0x0000 }, // ?RealTime@asSimulation@@QAEXM@Z
    { 0x522DF0, 0x0DE547E4, 0x0000 }, // ?FixedFrame@asSimulation@@QAEXMH@Z
    { 0x522E30, 0x45726C6C, 0x0000 }, // ?FrameLock@asSimulation@@QAEXHH@Z
    { 0x522E40, 0xD6A4A1C5, 0x0000 }, // ?Benchmark@asSimulation@@QAEXXZ
    { 0x522EC0, 0x8C1932E2, 0x0000 }, // ?Pause@asSimulation@@QAEXXZ
    { 0x522FA0, 0x47DB0307, 0x0000 }, // ?OpenPhysicsBank@asSimulation@@QAEXXZ
    { 0x522FC0, 0xBA9B536C, 0x0000 }, // ?InitBank@@YAXHPAPAD@Z
    { 0x522FD0, 0x6EE6C340, 0x0000 }, // ?AddWidgets@asSimulation@@UAEXPAVBank@@@Z
    { 0x523210, 0x72B419B7, 0x0000 }, // ?InitPipeline@@YAHPADHPAPAD@Z
    { 0x5232D0, 0x4F75B93A, 0x0000 }, // ?ShutdownPipeline@@YAXXZ
    { 0x523340, 0xC9AEDE2A, 0x0000 }, // ?RestartPipeline@@YAHHHHHH@Z
    { 0x523440, 0x0B333B22, 0x0000 }, // ?VerifyTree@asNode@@QAEPADXZ
    { 0x523510, 0x9587FF69, 0x0000 }, // ?IsValidPointer@@YAHPAXIH@Z
    { 0x523530, 0x0BDAE5B3, 0x0000 }, // ?DeclareFields@asSimulation@@SAXXZ
    { 0x5236A0, 0xE287EB2F, 0x0000 }, // ?GetClass@asSimulation@@UAEPAVMetaClass@@XZ
    { 0x5236B0, 0x53668BF9, 0x0000 }, // ??0artsReplayChannel@@QAE@XZ
    { 0x5236D0, 0xEA726874, 0x0000 }, // ?DoRecord@artsReplayChannel@@UAEXPAVStream@@@Z
    { 0x523710, 0x2F61815B, 0x0000 }, // ?DoPlayback@artsReplayChannel@@UAEXPAVStream@@@Z
    { 0x523740, 0x16F32C90, 0x0000 }, // ??1artsReplayChannel@@QAE@XZ
    { 0x5237C0, 0x7E1569B8, 0x0000 }, // ??0asNode@@QAE@XZ
    { 0x5237F0, 0x4B96D984, 0x0000 }, // ??1asNode@@UAE@XZ
    { 0x523860, 0xF86439A9, 0x0000 }, // ?SetName@asNode@@QAEXPAD@Z
    { 0x523890, 0x58A92032, 0x0000 }, // ?Update@asNode@@UAEXXZ
    { 0x523960, 0xDB88DC05, 0x0000 }, // ?Reset@asNode@@UAEXXZ
    { 0x523980, 0x99A69719, 0x0000 }, // ?ResChange@asNode@@UAEXHH@Z
    { 0x5239B0, 0xA7E2133E, 0x0000 }, // ?ResetTime@asNode@@QAEXXZ
    { 0x5239D0, 0xCE965606, 0x0000 }, // ?PerfReport@asNode@@QAEXPAVStream@@H@Z
    { 0x523A70, 0x09B42B5C, 0x0000 }, // ?AddChild@asNode@@QAEHPAV1@@Z
    { 0x523AF0, 0x3A759130, 0x0000 }, // ?InsertChild@asNode@@QAEHHPAV1@@Z
    { 0x523B80, 0xEE7510F8, 0x0000 }, // ?RemoveChild@asNode@@QAEHH@Z
    { 0x523C20, 0xF7A221D7, 0x0000 }, // ?RemoveChild@asNode@@QAEHPAV1@@Z
    { 0x523C60, 0x4831AA7C, 0x0000 }, // ?RemoveAllChildren@asNode@@QAEXXZ
    { 0x523C80, 0x010782A1, 0x0000 }, // ?GetChild@asNode@@QAEPAV1@H@Z
    { 0x523CB0, 0x5FAAF420, 0x0000 }, // ?GetNext@asNode@@QAEPAV1@XZ
    { 0x523CC0, 0x3B1B5228, 0x0000 }, // ?GetLastChild@asNode@@QAEPAV1@XZ
    { 0x523D00, 0xE5EF32A9, 0x0000 }, // ?NumChildren@asNode@@QAEHXZ
    { 0x523D20, 0x635DC48C, 0x0000 }, // ?SwitchTo@asNode@@QAEXH@Z
    { 0x523D80, 0xC7BE781E, 0x0000 }, // ?GetParent@asNode@@QAEPAV1@PAVMetaClass@@@Z
    { 0x523DC0, 0xFE80BAAD, 0x0000 }, // ?GetNodeType@asNode@@QAEPADXZ
    { 0x523DD0, 0x053B6729, 0x0000 }, // ?Load@asNode@@QAEHPAD@Z
    { 0x523EC0, 0xFC1A8C80, 0x0000 }, // ?Save@asNode@@QAEHPAD@Z
    { 0x523F70, 0x40479FC2, 0x0000 }, // ?Save@asNode@@UAEXXZ
    { 0x524150, 0x4736A764, 0x0000 }, // ?Load@asNode@@UAEXXZ
    { 0x524330, 0x1ABAE3DB, 0x0000 }, // ?AddWidgets@asNode@@UAEXPAVBank@@@Z
    { 0x5243E0, 0x54910DF2, 0x0000 }, // ?OpenWidgets@asNode@@UAEXPADPAVbkWindow@@@Z
    { 0x5243F0, 0x8AD4033A, 0x0000 }, // ?CloseWidgets@asNode@@UAEXXZ
    { 0x524400, 0x09D7228E, 0x0000 }, // ?AddButton@asNode@@QAEXPAVBank@@AAH@Z
    { 0x524410, 0x53263724, 0x0000 }, // ?DeclareFields@asNode@@SAXXZ
    { 0x524600, 0xEFB575EA, 0x0000 }, // ?GetClass@asNode@@UAEPAVMetaClass@@XZ
    { 0x524610, 0xBE3C8464, 0x0000 }, // ?PtrTo@@YAPAUMetaType@@PAU1@@Z
    { 0x5246C0, 0x9FA7AA68, 0x0000 }, // ??0asCullManager@@QAE@HH@Z
    { 0x524D40, 0xC1F72040, 0x0000 }, // ??1asCullManager@@UAE@XZ
    { 0x524DF0, 0x181E84B5, 0x0000 }, // ?Reset@asCullManager@@UAEXXZ
    { 0x524E50, 0x89B02554, 0x0000 }, // ?DisplayVersionString@asCullManager@@IAEXXZ
    { 0x524E70, 0xD7E24EC5, 0x0000 }, // ?Statsf@@YAXPBDZZ
    { 0x524F00, 0x72F81BE7, 0x0000 }, // ?PrintMiniStats@asCullManager@@IAEXXZ
    { 0x524F90, 0x8C503555, 0x0000 }, // ?PrintStats@asCullManager@@IAEXXZ
    { 0x525090, 0xBC0E5FB0, 0x0000 }, // ?Update@asCullManager@@UAEXXZ
    { 0x525400, 0xAB5921CB, 0x0000 }, // ?AddPage@asCullManager@@QAEXVCallback@@@Z
    { 0x525440, 0x64E5D583, 0x0000 }, // ?DeclareCamera@asCullManager@@UAEXPAVasCamera@@@Z
    { 0x5254A0, 0xB7968C5A, 0x0000 }, // ?DeclareCullable@asCullManager@@UAEXPAVasCullable@@@Z
    { 0x525550, 0xB19DA752, 0x0000 }, // ?DeclareCullable2D@asCullManager@@UAEXPAVasCullable@@@Z
    { 0x5255F0, 0x19925277, 0x0000 }, // ?DeclareBitmap@asCullManager@@QAEXPAVasCullable@@PAVagiBitmap@@@Z
    { 0x525660, 0x94A6F01D, 0x0000 }, // ?DeclarePrint@asCullManager@@QAEXPAVasCullable@@@Z
    { 0x5256D0, 0xE96A9178, 0x0000 }, // ?DeclareFields@asCullManager@@SAXXZ
    { 0x525840, 0x0BE32367, 0x0000 }, // ?GetClass@asCullManager@@UAEPAVMetaClass@@XZ
    { 0x5258C0, 0xAA6A97E5, 0x0000 }, // ?Cull@asCullable@@UAEXXZ
    { 0x5258D0, 0x67DFBC60, 0x0000 }, // ?AddWidgets@asCullable@@QAEXPAVBank@@@Z
    { 0x5258E0, 0x98500E71, 0x0000 }, // ?DeclareFields@asCullable@@SAXXZ
    { 0x525A30, 0x2BA1CFD5, 0x0000 }, // ?GetClass@asCullable@@UAEPAVMetaClass@@XZ
    { 0x525AA0, 0x0905F11E, 0x0000 }, // ??0asCullable@@QAE@XZ
    { 0x525AB0, 0x0C519808, 0x0000 }, // ??0asLinearCS@@QAE@XZ
    { 0x525B20, 0xB901E6CA, 0x0000 }, // ?Update@asLinearCS@@UAEXXZ
    { 0x525C00, 0xCAD3E463, 0x0000 }, // ?Cull@asLinearCS@@UAEXXZ
    { 0x525CB0, 0x85479E89, 0x0000 }, // ?FileIO@asLinearCS@@QAEXPAVMiniParser@@@Z
    { 0x525CC0, 0x99058BA2, 0x0000 }, // ?AddWidgets@asLinearCS@@UAEXPAVBank@@@Z
    { 0x525E20, 0x1CA4E79A, 0x0000 }, // ?DeclareFields@asLinearCS@@SAXXZ
    { 0x525FF0, 0xC25BAB3E, 0x0000 }, // ?GetClass@asLinearCS@@UAEPAVMetaClass@@XZ
    { 0x526000, 0x9A3557CE, 0x0000 }, // ??0asLamp@@QAE@XZ
    { 0x5260C0, 0x65551F77, 0x0000 }, // ??1asLamp@@UAE@XZ
    { 0x526130, 0xFCCAE34F, 0x0000 }, // ?SetColor@asLamp@@QAEXABVVector3@@M@Z
    { 0x526170, 0x50ADC683, 0x0000 }, // ?SetDistant@asLamp@@QAEXXZ
    { 0x526180, 0x0A05BF33, 0x0000 }, // ?SetPoint@asLamp@@QAEXXZ
    { 0x526190, 0x4D2FA793, 0x0000 }, // ?Update@asLamp@@UAEXXZ
    { 0x526290, 0xAEA0FE82, 0x0000 }, // ?Cull@asLamp@@UAEXXZ
    { 0x5262E0, 0xA015275A, 0x0000 }, // ?FileIO@asLamp@@QAEXPAVMiniParser@@@Z
    { 0x5262F0, 0xCB7ED25B, 0x0000 }, // ?Regen@asLamp@@AAEXXZ
    { 0x526310, 0xB49EED2F, 0x0000 }, // ?AddWidgets@asLamp@@UAEXPAVBank@@@Z
    { 0x526680, 0x7C670ED7, 0x0000 }, // ?DeclareFields@asLamp@@SAXXZ
    { 0x5267E0, 0x81C29445, 0x0000 }, // ?GetClass@asLamp@@UAEPAVMetaClass@@XZ
    { 0x5267F0, 0xE7561DDD, 0x0000 }, // ??0asMidgets@@QAE@XZ
    { 0x526890, 0x55A223FF, 0x0000 }, // ??1asMidgets@@UAE@XZ
    { 0x526900, 0xA931877A, 0x0000 }, // ?Off@asMidgets@@UAEXXZ
    { 0x526950, 0xE768E9DB, 0x0000 }, // ?Open@asMidgets@@QAEXPAVasNode@@@Z
    { 0x526B60, 0xFC2BE2A8, 0x0000 }, // ?Toggle@asMidgets@@QAEXXZ
    { 0x526B80, 0x781A8DA8, 0x0000 }, // ?Update@asMidgets@@QAEXXZ
    { 0x526BF0, 0xF06E17A6, 0x0000 }, // ?UpdateKey@asMidgets@@QAEXHH@Z
    { 0x526E40, 0xB21BAC9F, 0x0000 }, // ?SetLabel@asMidgets@@UAEXPAD@Z
    { 0x526E50, 0x08DE7D12, 0x0000 }, // ?AddItem@asMidgets@@AAEXPAVMI@@@Z
    { 0x526E90, 0xF140A6D8, 0x0000 }, // ?IsVisible@asMidgets@@AAEHH@Z
    { 0x526ED0, 0x27ECD78D, 0x0000 }, // ?Cull@asMidgets@@UAEXXZ
    { 0x526FC0, 0xAECBA3A8, 0x0000 }, // ?AddTitle@asMidgets@@UAEPAVbkWindow@@PAD@Z
    { 0x527020, 0x3B9413E8, 0x0000 }, // ?AddButton@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    { 0x527090, 0xBFFEB8D0, 0x0000 }, // ?AddToggle@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    { 0x527110, 0x3E5E248C, 0x0000 }, // ?AddMex@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    { 0x527190, 0xC2C52A09, 0x0000 }, // ?AddText@asMidgets@@UAEPAVbkButton@@VCallback@@@Z
    { 0x5271C0, 0x7277DDB2, 0x0000 }, // ?AddText@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    { 0x5271F0, 0x2E744579, 0x0000 }, // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PAD0DDMVCallback@@@Z
    { 0x527280, 0x1A77071B, 0x0000 }, // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAEEEMVCallback@@@Z
    { 0x527310, 0xBC60FDAB, 0x0000 }, // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAFFFMVCallback@@@Z
    { 0x5273A0, 0xD3CF66FA, 0x0000 }, // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAGGGMVCallback@@@Z
    { 0x527430, 0x882E4497, 0x0000 }, // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAHHHMVCallback@@@Z
    { 0x5274C0, 0x044A3924, 0x0000 }, // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAIIIMVCallback@@@Z
    { 0x527550, 0xFB881D06, 0x0000 }, // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAMMMMVCallback@@@Z
    { 0x5275E0, 0x3138ABB6, 0x0000 }, // ?AddTextSlider@asMidgets@@UAEPAVbkSlider@@PAD0PAHMVCallback@@@Z
    { 0x527610, 0xA24F1A32, 0x0000 }, // ?AddVector@asMidgets@@UAEXPADPAVVector2@@MMMVCallback@@@Z
    { 0x5276B0, 0xABC24D61, 0x0000 }, // ?AddVector@asMidgets@@UAEXPADPAVVector3@@MMMVCallback@@@Z
    { 0x527790, 0xC90A7EC6, 0x0000 }, // ?AddVector@asMidgets@@UAEXPADPAVVector4@@MMMVCallback@@@Z
    { 0x5278B0, 0x558D5B2A, 0x0000 }, // ?AddColor@asMidgets@@UAEXPADPAVVector3@@VCallback@@@Z
    { 0x527990, 0xAADE310E, 0x0000 }, // ?AddColor@asMidgets@@UAEXPADPAVVector4@@VCallback@@@Z
    { 0x527AB0, 0xA16FFD31, 0x0000 }, // ?AddFileButton@asMidgets@@UAEXPADVCallback@@@Z
    { 0x527AE0, 0xC2B1DD76, 0x0000 }, // ?PushSection@asMidgets@@UAEXPADH@Z
    { 0x527B50, 0xE403DA93, 0x0000 }, // ?PopSection@asMidgets@@UAEXXZ
    { 0x527B80, 0x73945580, 0x0000 }, // ?PushColumn@asMidgets@@UAEXH@Z
    { 0x527B90, 0x122DD5D8, 0x0000 }, // ?PopColumn@asMidgets@@UAEXXZ
    { 0x527BD0, 0x3BBA23B6, 0x0000 }, // ?Key@SMI@@UAEXHH@Z
    { 0x527BE0, 0xD29367A5, 0x0000 }, // ?Update@SMI@@UAEHH@Z
    { 0x527C00, 0x93E445BA, 0x0000 }, // ?Key@BMI@@UAEXHH@Z
    { 0x527C20, 0x24368B47, 0x0000 }, // ?Update@BMI@@UAEHH@Z
    { 0x527C40, 0x6296234D, 0x0000 }, // ?Key@TMI@@UAEXHH@Z
    { 0x527CA0, 0xD4D6A2D8, 0x0000 }, // ?Update@TMI@@UAEHH@Z
    { 0x527CF0, 0xA451297C, 0x0000 }, // ?Key@scharMI@@UAEXHH@Z
    { 0x527D80, 0x3F5D79BB, 0x0000 }, // ?Update@scharMI@@UAEHH@Z
    { 0x527DD0, 0xC92C5A2C, 0x0000 }, // ?Key@ucharMI@@UAEXHH@Z
    { 0x527E60, 0x723DEDA3, 0x0000 }, // ?Update@ucharMI@@UAEHH@Z
    { 0x527EB0, 0xDDA5785A, 0x0000 }, // ?Key@shortMI@@UAEXHH@Z
    { 0x527F50, 0x3B5249FF, 0x0000 }, // ?Update@shortMI@@UAEHH@Z
    { 0x527FA0, 0x118223B0, 0x0000 }, // ?Key@ushortMI@@UAEXHH@Z
    { 0x528040, 0xA0B9672A, 0x0000 }, // ?Update@ushortMI@@UAEHH@Z
    { 0x528090, 0x5072FCA4, 0x0000 }, // ?Key@intMI@@UAEXHH@Z
    { 0x528120, 0x5D88C095, 0x0000 }, // ?Update@intMI@@UAEHH@Z
    { 0x528170, 0x4F3C28F6, 0x0000 }, // ?Key@uintMI@@UAEXHH@Z
    { 0x528210, 0x22FE529B, 0x0000 }, // ?Update@uintMI@@UAEHH@Z
    { 0x528260, 0x64BF3E67, 0x0000 }, // ?Key@floatMI@@UAEXHH@Z
    { 0x5282F0, 0x21B36256, 0x0000 }, // ?Update@floatMI@@UAEHH@Z
    { 0x528340, 0x40386938, 0x0000 }, // ?Key@SBMI@@UAEXHH@Z
    { 0x528360, 0xCE6C2D80, 0x0000 }, // ?Update@SBMI@@UAEHH@Z
    { 0x528390, 0x625C14EC, 0x0000 }, // ??0asForm@@QAE@XZ
    { 0x5283C0, 0x53D7B484, 0x0000 }, // ??1asForm@@UAE@XZ
    { 0x528420, 0x8B68A6CA, 0x0000 }, // ?SetDLP@asForm@@QAEXPAVDLP@@@Z
    { 0x528450, 0xE5AF42A5, 0x0000 }, // ?SetShape@asForm@@QAEXPAD0PAVVector3@@HH@Z
    { 0x5284D0, 0xCEFB6BEA, 0x0000 }, // ?SetCull@asForm@@QAEXHM@Z
    { 0x5284F0, 0x8696265B, 0x0000 }, // ?Update@asForm@@UAEXXZ
    { 0x528520, 0x0414FABB, 0x0000 }, // ?Cull@asForm@@UAEXXZ
    { 0x528600, 0xD9B141FB, 0x0000 }, // ?Visible@asForm@@QBEHPAVasCamera@@ABVMatrix34@@@Z
    { 0x5287D0, 0x8016269C, 0x0000 }, // ?GetBoundMin@asForm@@QAE?AVVector3@@XZ
    { 0x528820, 0x8F341D63, 0x0000 }, // ?GetBoundMax@asForm@@QAE?AVVector3@@XZ
    { 0x528870, 0x97F865E9, 0x0000 }, // ?GetBoundSphere@asForm@@QAE?AVVector4@@XZ
    { 0x5288D0, 0xB580C73D, 0x0000 }, // ?FileIO@asForm@@QAEXPAVMiniParser@@@Z
    { 0x5288E0, 0xD632357C, 0x0000 }, // ?AddWidgets@asForm@@UAEXPAVBank@@@Z
    { 0x5289D0, 0x2DB9F8B4, 0x0000 }, // ?DeclareFields@asForm@@SAXXZ
    { 0x528B40, 0x92A50866, 0x0000 }, // ?GetClass@asForm@@UAEPAVMetaClass@@XZ
    { 0x528BB0, 0xF1D78191, 0x0000 }, // ??1asCamera@@UAE@XZ
    { 0x528C40, 0xC63A93BE, 0x0000 }, // ??0asCamera@@QAE@XZ
    { 0x528DF0, 0x27A28ED9, 0x0000 }, // ?Update@asCamera@@UAEXXZ
    { 0x529100, 0x2A9C5648, 0x0000 }, // ?SetClipArea@asCamera@@QAEXMMMM@Z
    { 0x529230, 0x641C47E8, 0x0000 }, // ?SetLighting@asCamera@@QAEXH@Z
    { 0x529250, 0x36F5170A, 0x0000 }, // ?SetWorld@asCamera@@QAEXAAVMatrix34@@@Z
    { 0x529270, 0x964F032C, 0x0000 }, // ?GetNearClip@asCamera@@QAEXPAVVector3@@AAVMatrix34@@W4kNearClip@1@@Z
    { 0x5297D0, 0x35D4C27B, 0x0000 }, // ?DrawBegin@asCamera@@QAEXXZ
    { 0x5299C0, 0x83AC65DE, 0x0000 }, // ?DrawEnd@asCamera@@QAEXXZ
    { 0x529B70, 0x47697768, 0x0000 }, // ?SetViewport@asCamera@@QAEXMMMMH@Z
    { 0x529BC0, 0x7AA9C6FE, 0x0000 }, // ?SetView@asCamera@@QAEXMMMM@Z
    { 0x529C10, 0xD5C04399, 0x0000 }, // ?SetFog@asCamera@@QAEXMMMM@Z
    { 0x529C40, 0xECBDED1F, 0x0000 }, // ?SetUnderlay@asCamera@@QAEXPAD@Z
    { 0x529C80, 0x8E32E8B7, 0x0000 }, // ?SetUnderlayCB@asCamera@@QAEXPAVagiBitmap@@PAVCallback@@@Z
    { 0x529CA0, 0xE10A4E18, 0x0000 }, // ?GetViewportWidth@asCamera@@QAEHXZ
    { 0x529CC0, 0xC71C621F, 0x0000 }, // ?GetViewportHeight@asCamera@@QAEHXZ
    { 0x529CE0, 0x642B3C1B, 0x0000 }, // ?FadeOut@asCamera@@QAEXMH@Z
    { 0x529D40, 0x768F56E7, 0x0000 }, // ?FadeIn@asCamera@@QAEXMH@Z
    { 0x529DA0, 0x24872ACA, 0x0000 }, // ?FileIO@asCamera@@QAEXPAVMiniParser@@@Z
    { 0x529DB0, 0x6C95F180, 0x0000 }, // ?SphereVisible@asCamera@@QAEMABVVector3@@MPAM@Z
    { 0x529F50, 0xFEC2EDC1, 0x0000 }, // ?SetAmbient@asCamera@@QAEXABVVector3@@@Z
    { 0x529F90, 0xDB476CE5, 0x0000 }, // ?SetMonochrome@asCamera@@QAEXH@Z
    { 0x529FB0, 0xA18D9D72, 0x0000 }, // ?Regen@asCamera@@AAEXXZ
    { 0x529FD0, 0x43F9A66A, 0x0000 }, // ?FadeItOut@@YAXPAVasCamera@@@Z
    { 0x529FF0, 0xC54898FF, 0x0000 }, // ?FadeItIn@@YAXPAVasCamera@@@Z
    { 0x52A010, 0xC8B6EAE8, 0x0000 }, // ?FritzIt@@YAXPAVasCamera@@@Z
    { 0x52A020, 0xEE1D482B, 0x0000 }, // ?ViewIt@@YAXPAVasCamera@@@Z
    { 0x52A040, 0x1F060AD5, 0x0000 }, // ?AddWidgets@asCamera@@UAEXPAVBank@@@Z
    { 0x52A6A0, 0x7B452611, 0x0000 }, // ?DeclareFields@asCamera@@SAXXZ
    { 0x52A810, 0x33054817, 0x0000 }, // ?GetClass@asCamera@@UAEPAVMetaClass@@XZ
    { 0x52A8A0, 0x67A53EC7, 0x0000 }, // ??0asPerfGraph@@QAE@XZ
    { 0x52A930, 0x32C57CDD, 0x0000 }, // ??1asPerfGraph@@QAE@XZ
    { 0x52A960, 0xE5A71A26, 0x0000 }, // ?AddComponent@asPerfGraph@@QAEXPADPAMAAVVector3@@@Z
    { 0x52A9E0, 0xBB440D67, 0x0000 }, // ?Key@asPerfGraph@@QAEXH@Z
    { 0x52AA30, 0x7FA12C68, 0x0000 }, // ?Update@asPerfGraph@@QAEXXZ
    { 0x52AB30, 0xF6B6D2A2, 0x0000 }, // ?Cull@asPerfGraph@@QAEXXZ
    { 0x52ACF0, 0xDC628489, 0x0000 }, // ??0asDofCS@@QAE@XZ
    { 0x52ADE0, 0xEDC06B21, 0x0000 }, // ??4asDofCS@@QAEXABV0@@Z
    { 0x52AF20, 0x47E2156E, 0x0000 }, // ?Reset@asDofCS@@UAEXXZ
    { 0x52AF50, 0x1082CBC4, 0x0000 }, // ?SetTime@asDofCS@@QAEXMMH@Z
    { 0x52AFC0, 0xCFC6F8BF, 0x0000 }, // ?Update@asDofCS@@UAEXXZ
    { 0x52B5D0, 0x56733A22, 0x0000 }, // ?FileIO@asDofCS@@QAEXPAVMiniParser@@@Z
    { 0x52B5E0, 0x15447BFB, 0x0000 }, // ?ModeCB@asDofCS@@IAEXXZ
    { 0x52B600, 0x9D6767E9, 0x0000 }, // ?AddWidgets@asDofCS@@UAEXPAVBank@@@Z
    { 0x52B9F0, 0xA14172E3, 0x0000 }, // ?DeclareFields@asDofCS@@SAXXZ
    { 0x52BB60, 0xBA432732, 0x0000 }, // ?GetClass@asDofCS@@UAEPAVMetaClass@@XZ
    { 0x52BB70, 0x8244EC0F, 0x0000 }, // ?Add@Vector3@@QAEXABV1@0@Z
    { 0x52BBA0, 0xFD6310EF, 0x0000 }, // ??0asViewCS@@QAE@XZ
    { 0x52BCD0, 0x455455B2, 0x0000 }, // ?SetAzimuth@asViewCS@@QAEXXZ
    { 0x52BD30, 0x2F6B701E, 0x0000 }, // ?Reset@asViewCS@@UAEXXZ
    { 0x52BF00, 0x254E586A, 0x0000 }, // ?Update@asViewCS@@UAEXXZ
    { 0x52BF80, 0xD4E1CD20, 0x0000 }, // ?UpdatePolar@asViewCS@@QAEXXZ
    { 0x52C0C0, 0xCED77FBF, 0x0000 }, // ?UpdateRoam@asViewCS@@QAEXXZ
    { 0x52C1D0, 0xB8A4DD1E, 0x0000 }, // ?UpdatePOV@asViewCS@@QAEXXZ
    { 0x52C220, 0x1AF25801, 0x0000 }, // ?UpdateLookAt@asViewCS@@QAEXXZ
    { 0x52C280, 0xC86EAC7B, 0x0000 }, // ?UpdateTrack@asViewCS@@QAEXXZ
    { 0x52C640, 0xBC862A5E, 0x0000 }, // ?UpdateStereo@asViewCS@@QAEXXZ
    { 0x52C770, 0x4B367914, 0x0000 }, // ?FileIO@asViewCS@@QAEXPAVMiniParser@@@Z
    { 0x52C780, 0x523C3DEF, 0x0000 }, // ?AddWidgets@asViewCS@@UAEXPAVBank@@@Z
    { 0x52CC70, 0xEB427DBB, 0x0000 }, // ?DeclareFields@asViewCS@@SAXXZ
    { 0x52CDE0, 0x05332C8A, 0x0000 }, // ?GetClass@asViewCS@@UAEPAVMetaClass@@XZ
    { 0x52CE50, 0x791443B9, 0x0000 }, // ??1asViewCS@@UAE@XZ
    { 0x52CE60, 0x1038D929, 0x0000 }, // ?Reset@asBenchStats@@QAEXXZ
    { 0x52CEA0, 0xE970D983, 0x0000 }, // ?Print@asBenchStats@@QAEXXZ
    { 0x52CEB0, 0x37E7F7EB, 0x0000 }, // ?Average@asBenchStats@@QAEXPAV1@MH@Z
    { 0x52CFD0, 0x0B0EB3AC, 0x0000 }, // ?Current@asBenchStats@@QAEXPAV1@@Z
    { 0x52D020, 0xE9C64FB1, 0x0000 }, // ?DrawColor@@YAXAAVVector3@@@Z
    { 0x52D080, 0x914379AA, 0x0000 }, // ?DrawColor2@@YAXAAVVector3@@@Z
    { 0x52D0D0, 0x226230E3, 0x0000 }, // ?DrawColor@@YAXAAVVector4@@@Z
    { 0x52D130, 0x813DBE68, 0x0000 }, // ?DrawColor2@@YAXAAVVector4@@@Z
    { 0x52D190, 0x881EC026, 0x0000 }, // ?DrawLine@@YAXMMMMMM@Z
    { 0x52D230, 0xCED6080C, 0x0000 }, // ?DrawLine@@YAXAAVVector3@@0@Z
    { 0x52D260, 0x99EEA129, 0x0000 }, // ?DrawTri@@YAXPAVVector3@@AAV1@11@Z
    { 0x52D320, 0x866A937B, 0x0000 }, // ?DrawWireSphere@@YAXAAVVector3@@M@Z
    { 0x52D620, 0x9E5F20B5, 0x0000 }, // ?DrawWireSphere@@YAXAAVVector4@@@Z
    { 0x52D640, 0x19662043, 0x0000 }, // ?DrawWireBox@@YAXAAVVector3@@0@Z
    { 0x52D800, 0x1721CC89, 0x0000 }, // ?DrawBegin@@YAXAAVMatrix34@@@Z
    { 0x52D8C0, 0x438C74C3, 0x0000 }, // ?DrawQuad@@YAXPAVVector3@@AAV1@111@Z
    { 0x52D9C0, 0xAEEBFDF9, 0x0000 }, // ?DrawLabelf@@YAXAAVVector3@@PADZZ
    { 0x52DA30, 0x3490A827, 0x0000 }, // ?DrawEnd@@YAXXZ
    { 0x52DFC0, 0x39F0EA51, 0x0000 }, // ?d3dCreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
    { 0x52E550, 0xEEFCDD43, 0x0000 }, // ??0agiD3DRasterizer@@QAE@PAVagiPipeline@@@Z
    { 0x52E570, 0xDB596B01, 0x0000 }, // ?BeginGfx@agiD3DRasterizer@@UAEHXZ
    { 0x52E580, 0x19B18EF2, 0x0000 }, // ?EndGfx@agiD3DRasterizer@@UAEXXZ
    { 0x52E590, 0x10941A4E, 0x0000 }, // ??1agiD3DRasterizer@@UAE@XZ
    { 0x52E5A0, 0xF92A0B41, 0x0000 }, // ?BeginGroup@agiD3DRasterizer@@UAEXXZ
    { 0x52E5B0, 0xD9D72672, 0x0000 }, // ?EndGroup@agiD3DRasterizer@@UAEXXZ
    { 0x52E5C0, 0xAFEBF152, 0x0000 }, // ?d3d_state_init@@YAXXZ
    { 0x52E630, 0xC7B966A0, 0x0000 }, // ?FlushState@agiD3DRasterizer@@IAEXXZ
    { 0x52F770, 0x0FF783CF, 0x0000 }, // ?Verts@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    { 0x52F7C0, 0x1ADAB663, 0x0000 }, // ?SetVertCount@agiD3DRasterizer@@UAEXH@Z
    { 0x52F7D0, 0xF65A2E38, 0x0000 }, // ?Triangle@agiD3DRasterizer@@UAEXHHH@Z
    { 0x52F860, 0x364272FF, 0x0000 }, // ?Line@agiD3DRasterizer@@UAEXHH@Z
    { 0x52F8E0, 0xA974B0B1, 0x0000 }, // ?Card@agiD3DRasterizer@@UAEXHH@Z
    { 0x52F8F0, 0x7C8D7BA3, 0x0000 }, // ?Points@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    { 0x52F950, 0xB717406C, 0x0000 }, // ?Mesh@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@HPAGH@Z
    { 0x52F9C0, 0x65613C84, 0x0000 }, // ?Mesh2@agiD3DRasterizer@@UAEXPAUagiScreenVtx2@@HPAGH@Z
    { 0x52FA90, 0x1849368F, 0x0000 }, // ?Prober@agiD3DTexDef@@SAXPAX@Z
    { 0x52FB50, 0x5CCDB846, 0x0000 }, // ??0agiD3DPipeline@@QAE@XZ
    { 0x52FB90, 0xB0AF5B8E, 0x0000 }, // ?BeginGfx@agiD3DPipeline@@UAEHXZ
    { 0x5307B0, 0x9608869F, 0x0000 }, // ?EnumCallback@@YGJPAU_GUID@@PAD1PAU_D3DDeviceDesc@@2PAX@Z
    { 0x5308B0, 0x683F462D, 0x0000 }, // ?EnumTextureCallback@@YGJPAU_DDPIXELFORMAT@@PAX@Z
    { 0x530980, 0x2C971A18, 0x0000 }, // ?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z
    { 0x5309D0, 0x19A3E7C3, 0x0000 }, // ??1agiD3DPipeline@@UAE@XZ
    { 0x530A20, 0x8D92385D, 0x0000 }, // ?RestoreCallback@@YGJPAUIDirectDrawSurface4@@PAU_DDSURFACEDESC2@@PAX@Z
    { 0x530A40, 0x4674175A, 0x0000 }, // ?BeginFrame@agiD3DPipeline@@UAEXXZ
    { 0x530AF0, 0xC831AB6B, 0x0000 }, // ?BeginScene@agiD3DPipeline@@UAEXXZ
    { 0x530B60, 0x68A72C3C, 0x0000 }, // ?EndScene@agiD3DPipeline@@UAEXXZ
    { 0x530BD0, 0x1E624B2D, 0x0000 }, // ?EndFrame@agiD3DPipeline@@UAEXXZ
    { 0x530D30, 0xD0D0F3D1, 0x0000 }, // ?callb@@YGJPAUIDirectDrawSurface4@@PAU_DDSURFACEDESC2@@PAX@Z
    { 0x530FE0, 0xE12955E0, 0x0000 }, // ?DumpStatus@agiD3DPipeline@@UAEXAAUagiMemStatus@@@Z
    { 0x531100, 0xF1ED2E85, 0x0000 }, // ?EndGfx@agiD3DPipeline@@UAEXXZ
    { 0x5311F0, 0x798B9075, 0x0000 }, // ?CreateViewport@agiD3DPipeline@@UAEPAVagiViewport@@XZ
    { 0x531250, 0x76AE1167, 0x0000 }, // ?CreateMtlDef@agiD3DPipeline@@UAEPAVagiMtlDef@@XZ
    { 0x5312B0, 0xE1CFA446, 0x0000 }, // ?CreateTexDef@agiD3DPipeline@@UAEPAVagiTexDef@@XZ
    { 0x531310, 0x5745FD68, 0x0000 }, // ?CreateTexLut@agiD3DPipeline@@UAEPAVagiTexLut@@XZ
    { 0x5313A0, 0x5B01D545, 0x0000 }, // ?CreateLight@agiD3DPipeline@@UAEPAVagiLight@@XZ
    { 0x531400, 0x79D4B598, 0x0000 }, // ?ClearAll@agiD3DPipeline@@UAEXH@Z
    { 0x5314C0, 0xEC02E0C9, 0x0000 }, // ?CreateBitmap@agiD3DPipeline@@UAEPAVagiBitmap@@XZ
    { 0x531520, 0x35F66FC5, 0x0000 }, // ?CopyBitmap@agiD3DPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    { 0x531580, 0x93FB88A6, 0x0000 }, // ?Defragment@agiD3DPipeline@@UAEXXZ
    { 0x5315F0, 0x21B105B9, 0x0000 }, // ??1agiD3DTexLut@@UAE@XZ
    { 0x531600, 0xA6E06D6D, 0x0000 }, // ??0agiD3DRPipeline@@QAE@XZ
    { 0x531620, 0x475004C6, 0x0000 }, // ??1agiD3DRPipeline@@UAE@XZ
    { 0x531630, 0x55E74361, 0x0000 }, // ?BeginGfx@agiD3DRPipeline@@UAEHXZ
    { 0x531700, 0xE44BA262, 0x0000 }, // ?EndGfx@agiD3DRPipeline@@UAEXXZ
    { 0x531730, 0x34C74E7B, 0x0000 }, // ?CreateViewport@agiD3DRPipeline@@UAEPAVagiViewport@@XZ
    { 0x531790, 0x70928B89, 0x0000 }, // ?CreateDLP@agiD3DRPipeline@@UAEPAVDLP@@XZ
    { 0x5317F0, 0x3FFFDD48, 0x0000 }, // ?BeginScene@agiD3DRPipeline@@UAEXXZ
    { 0x531890, 0xEDFE0C2E, 0x0000 }, // ?EndScene@agiD3DRPipeline@@UAEXXZ
    { 0x5318B0, 0xFB7A31B0, 0x0000 }, // ?CreateLightModel@agiD3DRPipeline@@UAEPAVagiLightModel@@XZ
    { 0x531910, 0x7AAE8BAE, 0x0000 }, // ?CreateLight@agiD3DRPipeline@@UAEPAVagiLight@@XZ
    { 0x5319A0, 0x29079C69, 0x0000 }, // ??0agiD3DTexDef@@QAE@PAVagiPipeline@@@Z
    { 0x5319D0, 0xB7C3771C, 0x0000 }, // ??1agiD3DTexDef@@UAE@XZ
    { 0x5319E0, 0xDCFF670E, 0x0000 }, // ?BeginGfx@agiD3DTexDef@@UAEHXZ
    { 0x531D40, 0x6BCBE6DA, 0x0000 }, // ?Request@agiD3DTexDef@@UAEXXZ
    { 0x531DA0, 0xFE900F45, 0x0000 }, // ?GetHandle@agiD3DTexDef@@QAEPAUIDirect3DTexture2@@H@Z
    { 0x531E20, 0x4E40DF7C, 0x0000 }, // ?Lock@agiD3DTexDef@@UAEHAAUagiTexLock@@@Z
    { 0x531EC0, 0xE32FD3F2, 0x0000 }, // ?Unlock@agiD3DTexDef@@UAEXAAUagiTexLock@@@Z
    { 0x531EF0, 0x2814C930, 0x0000 }, // ?EndGfx@agiD3DTexDef@@UAEXXZ
    { 0x531F60, 0x66BCDB32, 0x0000 }, // ?IsAvailable@agiD3DTexDef@@UAEHXZ
    { 0x531F70, 0xD4369F0D, 0x0000 }, // ?Set@agiD3DTexDef@@UAEXAAVVector2@@0@Z
    { 0x531F90, 0x14E42DC5, 0x0000 }, // ?Restore@agiD3DTexDef@@UAEXXZ
    { 0x531FD0, 0xC46E8208, 0x0000 }, // ?BeginGfx@agiD3DTexLut@@UAEHXZ
    { 0x532020, 0x58D04ACC, 0x0000 }, // ?EndGfx@agiD3DTexLut@@UAEXXZ
    { 0x532090, 0x06896BD8, 0x0000 }, // ?DDErrorToString@@YAPADJ@Z
    { 0x5327B0, 0x7DABE9E1, 0x0000 }, // ?__DDTry@@YAXHPBD0H@Z
    { 0x532890, 0x6F920CA7, 0x0000 }, // ?__DDRelease@@YAXPAUIUnknown@@PBD1H@Z
    { 0x5328C0, 0x1635DC9E, 0x0000 }, // ?Validate@agiDDPipeline@@UAEHXZ
    { 0x5328D0, 0x2CE4534C, 0x0000 }, // ?DDCallback@@YGHPAU_GUID@@PAD1PAX@Z
    { 0x532950, 0x9DF02E44, 0x0000 }, // ?EnumModesCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z
    { 0x532A00, 0xDCFF0A39, 0x0000 }, // ?EnumSurfsCallback@@YGJPAUIDirectDrawSurface@@PAU_DDSURFACEDESC@@PAX@Z
    { 0x532A40, 0x2A53FFAF, 0x0000 }, // ??0agiDDPipeline@@QAE@XZ
    { 0x532AE0, 0x5C93151F, 0x0000 }, // ?BeginGfx@agiDDPipeline@@UAEHXZ
    { 0x532E30, 0x97EBFF6E, 0x0000 }, // ?EndGfx@agiDDPipeline@@UAEXXZ
    { 0x532EF0, 0x91B58EF6, 0x0000 }, // ??1agiDDPipeline@@UAE@XZ
    { 0x532F40, 0x89ACF80C, 0x0000 }, // ?BeginFrame@agiDDPipeline@@UAEXXZ
    { 0x532FA0, 0x9E85D1AD, 0x0000 }, // ?BeginScene@agiDDPipeline@@UAEXXZ
    { 0x532FF0, 0xC7BDDAEA, 0x0000 }, // ?EndScene@agiDDPipeline@@UAEXXZ
    { 0x533000, 0xE7D5232E, 0x0000 }, // ?EndFrame@agiDDPipeline@@UAEXXZ
    { 0x533010, 0x663C0F9D, 0x0000 }, // ?CreateBitmap@agiDDPipeline@@UAEPAVagiBitmap@@XZ
    { 0x533070, 0x414A1B49, 0x0000 }, // ?CopyBitmap@agiDDPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    { 0x5331E0, 0x210266DB, 0x0000 }, // ?LockFrameBuffer@agiDDPipeline@@UAEHAAVagiSurfaceDesc@@@Z
    { 0x533220, 0x8B34FD09, 0x0000 }, // ?UnlockFrameBuffer@agiDDPipeline@@UAEXXZ
    { 0x533240, 0xC731ED46, 0x0000 }, // ?ClearRect@agiDDPipeline@@UAEXHHHHI@Z
    { 0x5332D0, 0x1F4DD4C3, 0x0000 }, // ??0agiD3DViewport@@QAE@PAVagiPipeline@@@Z
    { 0x533300, 0x87AE9307, 0x0000 }, // ?BeginGfx@agiD3DViewport@@UAEHXZ
    { 0x533330, 0x5EB23B79, 0x0000 }, // ?EndGfx@agiD3DViewport@@UAEXXZ
    { 0x533340, 0xE7DD0C32, 0x0000 }, // ??1agiD3DViewport@@UAE@XZ
    { 0x533350, 0x55014E88, 0x0000 }, // ?Activate@agiD3DViewport@@UAEXXZ
    { 0x533410, 0x45BCA6DB, 0x0000 }, // ?SetBackground@agiD3DViewport@@UAEXAAVVector3@@@Z
    { 0x533460, 0x0C6B0149, 0x0000 }, // ?Clear@agiD3DViewport@@UAEXH@Z
    { 0x533560, 0xD13D6CDD, 0x0000 }, // ??0agiD3DMtlDef@@QAE@PAVagiPipeline@@@Z
    { 0x533590, 0xEC9510F3, 0x0000 }, // ?BeginGfx@agiD3DMtlDef@@UAEHXZ
    { 0x533620, 0x8C92B6BD, 0x0000 }, // ?EndGfx@agiD3DMtlDef@@UAEXXZ
    { 0x533660, 0x2976C6FF, 0x0000 }, // ??1agiD3DMtlDef@@UAE@XZ
    { 0x533670, 0x47B4F9C5, 0x0000 }, // ?Activate@agiD3DMtlDef@@QAEXXZ
    { 0x533720, 0x94F89B09, 0x0000 }, // ?xlat@@YAXAAU_D3DCOLORVALUE@@AAVVector4@@@Z
    { 0x533750, 0x9D02E4C5, 0x0000 }, // ?GetHandle@agiD3DMtlDef@@QAEKXZ
    { 0x5337A0, 0xBF24BBD6, 0x0000 }, // ??0agiD3DLight@@QAE@PAVagiPipeline@@@Z
    { 0x5337E0, 0x9F8289FC, 0x0000 }, // ??1agiD3DLight@@UAE@XZ
    { 0x533840, 0x80054F88, 0x0000 }, // ?BeginGfx@agiD3DLight@@UAEHXZ
    { 0x5338C0, 0x68395CA1, 0x0000 }, // ?EndGfx@agiD3DLight@@UAEXXZ
    { 0x533910, 0x071E40F9, 0x0000 }, // ?Update@agiD3DLight@@UAEHXZ
    { 0x5339F0, 0xCDB4A082, 0x0000 }, // ??0agiDDBitmap@@QAE@PAVagiPipeline@@@Z
    { 0x533A20, 0x5B57F6DA, 0x0000 }, // ?BeginGfx@agiDDBitmap@@UAEHXZ
    { 0x533C80, 0x3F389F20, 0x0000 }, // ?UpdateFlags@agiDDBitmap@@UAEXXZ
    { 0x533CC0, 0x7664FCAE, 0x0000 }, // ?EndGfx@agiDDBitmap@@UAEXXZ
    { 0x533CF0, 0xBD499AD3, 0x0000 }, // ??1agiDDBitmap@@UAE@XZ
    { 0x533D40, 0x8D69C021, 0x0000 }, // ?breakme@@YAXXZ
    { 0x533D50, 0x5228BD36, 0x0000 }, // ?Restore@agiDDBitmap@@UAEXXZ
    { 0x533DC0, 0x413967EC, 0x0000 }, // ?Validate@agiSWPipeline@@UAEHXZ
    { 0x533DD0, 0xDA6B4674, 0x0000 }, // ??0agiSWPipeline@@QAE@HPAPAD@Z
    { 0x533E50, 0x17E5E979, 0x0000 }, // ??1agiSWPipeline@@UAE@XZ
    { 0x533E60, 0x097C462E, 0x0000 }, // ?BeginGfx@agiSWPipeline@@UAEHXZ
    { 0x534010, 0x9F72A5F2, 0x0000 }, // ?EndGfx@agiSWPipeline@@UAEXXZ
    { 0x534030, 0x15089127, 0x0000 }, // ?BeginFrame@agiSWPipeline@@UAEXXZ
    { 0x534070, 0x5C47D7C5, 0x0000 }, // ?BeginScene@agiSWPipeline@@UAEXXZ
    { 0x5340A0, 0x01B46FAD, 0x0000 }, // ?EndScene@agiSWPipeline@@UAEXXZ
    { 0x5340C0, 0xA7CDE248, 0x0000 }, // ?EndFrame@agiSWPipeline@@UAEXXZ
    { 0x5340E0, 0x3F0B5683, 0x0000 }, // ?CreateDLP@agiSWPipeline@@UAEPAVDLP@@XZ
    { 0x534140, 0x2F81D3C1, 0x0000 }, // ?CreateLight@agiSWPipeline@@UAEPAVagiLight@@XZ
    { 0x5341A0, 0x72A21FF7, 0x0000 }, // ?ClearAll@agiSWPipeline@@UAEXH@Z
    { 0x534230, 0xD3D05410, 0x0000 }, // ?ClearRect@agiSWPipeline@@UAEXHHHHI@Z
    { 0x534290, 0xF3F3FF80, 0x0000 }, // ?CreateViewport@agiSWPipeline@@UAEPAVagiViewport@@XZ
    { 0x5342F0, 0x6C72DB8E, 0x0000 }, // ?zmemset@@YAXPAGI@Z
    { 0x534320, 0x72F0B64E, 0x0000 }, // ?CreateLightModel@agiSWPipeline@@UAEPAVagiLightModel@@XZ
    { 0x534380, 0x7ED81927, 0x0000 }, // ?CreateTexDef@agiSWPipeline@@UAEPAVagiTexDef@@XZ
    { 0x5343E0, 0x29B757F6, 0x0000 }, // ?CreateTexLut@agiSWPipeline@@UAEPAVagiTexLut@@XZ
    { 0x534440, 0x556A10C7, 0x0000 }, // ?CreateMtlDef@agiSWPipeline@@UAEPAVagiMtlDef@@XZ
    { 0x534450, 0x0A5AA42C, 0x0000 }, // ?CreateBitmap@agiSWPipeline@@UAEPAVagiBitmap@@XZ
    { 0x5344C0, 0x5719CF41, 0x0000 }, // ?CopyBitmap@agiSWPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    { 0x534690, 0xCE172D6F, 0x0000 }, // ?swCreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
    { 0x534930, 0xE3734F1C, 0x0000 }, // ?Activate@agiSWViewport@@UAEXXZ
    { 0x534950, 0x1CE39C56, 0x0000 }, // ?SetBackground@agiSWViewport@@UAEXAAVVector3@@@Z
    { 0x5349B0, 0x3A5B6D36, 0x0000 }, // ?Clear@agiSWViewport@@UAEXH@Z
    { 0x534BC0, 0x84EA5893, 0x0000 }, // ?BeginGfx@agiSWViewport@@UAEHXZ
    { 0x534BD0, 0xA386FD62, 0x0000 }, // ?EndGfx@agiSWViewport@@UAEXXZ
    { 0x534C10, 0x90446557, 0x0000 }, // ??1agiSWViewport@@UAE@XZ
    { 0x534C20, 0x7A92F916, 0x0000 }, // ?BeginGfx@agiSWBitmap@@UAEHXZ
    { 0x534DA0, 0xE4C0A50C, 0x0000 }, // ?UpdateFlags@agiSWBitmap@@UAEXXZ
    { 0x534DC0, 0xD8062D8A, 0x0000 }, // ?EndGfx@agiSWBitmap@@UAEXXZ
    { 0x534DE0, 0x90B2B65D, 0x0000 }, // ?Restore@agiSWBitmap@@UAEXXZ
    { 0x534E20, 0x6EC1939F, 0x0000 }, // ??1agiSWBitmap@@UAE@XZ
    { 0x534E30, 0x69BB3166, 0x0000 }, // ?ddAttach@@YAXHH@Z
    { 0x534EA0, 0x8242568D, 0x0000 }, // ?ddStart@@YAXXZ
    { 0x534FA0, 0x83A25639, 0x0000 }, // ?ddEnd@@YAXXZ
    { 0x534FC0, 0x277C0389, 0x0000 }, // ?ddStartFrame@@YAXXZ
    { 0x534FD0, 0xF923B7DA, 0x0000 }, // ?ddStartScene@@YAXXZ
    { 0x535030, 0xC389EBC7, 0x0000 }, // ?ddEndScene@@YAXXZ
    { 0x535070, 0x9444FAC6, 0x0000 }, // ?ddEndFrame@@YAXXZ
    { 0x5351C0, 0x4B0B76C7, 0x0000 }, // ?__emitDebug@@YIXPAUswSurface@@H@Z
    { 0x535220, 0x5AFB8E1E, 0x0000 }, // ?__emitDepthComplexity@@YIXH@Z
    { 0x535260, 0xBF7DA001, 0x0000 }, // ?__emitSolid@@YIXH@Z
    { 0x5352B0, 0xBD919A94, 0x0000 }, // ?__emitSolidZ@@YIXH@Z
    { 0x535320, 0xC359CF01, 0x0000 }, // ?__emitWireframe@@YIXH@Z
    { 0x535340, 0x7E6D7BC1, 0x0000 }, // ?swAddEdge@@YAXHH@Z
    { 0x535460, 0x2956E908, 0x0000 }, // ?swSetupEdgeScan@@YAXPAUswEdge@@HH@Z
    { 0x535510, 0x1DF66047, 0x0000 }, // ?__setupUV@@YIXPAUswSurface@@@Z
    { 0x5355D0, 0x40392984, 0x0000 }, // ?__setupUVZ@@YIXPAUswSurface@@@Z
    { 0x5356A0, 0x346BC6D3, 0x0000 }, // ?__setupZ@@YIXPAUswSurface@@@Z
    { 0x5356E0, 0xADB0D557, 0x0000 }, // ?__setupUVI@@YIXPAUswSurface@@@Z
    { 0x5357B0, 0x05A4138D, 0x0000 }, // ?__setupUVIZ@@YIXPAUswSurface@@@Z
    { 0x535890, 0xF581BE58, 0x0000 }, // ?__setupNone@@YIXPAUswSurface@@@Z
    { 0x5358A0, 0x4BA32CD6, 0x0000 }, // ?__spanLinear@@YIXPAUswSurface@@H@Z
    { 0x5358D0, 0x56216825, 0x0000 }, // ?__spanLinearZwrite@@YIXPAUswSurface@@H@Z
    { 0x535910, 0xFDD3ACE0, 0x0000 }, // ?__emitZwrite@@YIXPAUswSurface@@H@Z
    { 0x5359D0, 0xDC68DDE8, 0x0000 }, // ?__spanPerspXY@@YIXPAUswSurface@@H@Z
    { 0x535BD0, 0xC9E47B44, 0x0000 }, // ?__spanPerspXYZwrite@@YIXPAUswSurface@@H@Z
    { 0x535BF0, 0x021D4E95, 0x0000 }, // ?swScanSurface@@YAXPAUswSurface@@@Z
    { 0x535E30, 0xBD4E6681, 0x0000 }, // ?swInitSurface@@YAPAUswSurface@@UagiScreenVtx@@00I@Z
    { 0x5367C0, 0x8D546CB3, 0x0000 }, // ?__emitSemiBlack@@YIXH@Z
    { 0x536800, 0x9B2220C3, 0x0000 }, // ?__emitStippleBlack@@YIXH@Z
    { 0x536840, 0x3689F0A3, 0x0000 }, // ?swComputeIntensity@@YAHAAUagiScreenVtx@@@Z
    { 0x536880, 0x88C75831, 0x0000 }, // ?swScanSurfaces@@YAXXZ
    { 0x536940, 0x27231CD9, 0x0000 }, // ?emms@@YAXXZ
    { 0x536950, 0xB86A6FD8, 0x0000 }, // ?swTri@@YAXPAUagiScreenVtx@@00@Z
    { 0x536B10, 0x1621C24E, 0x0000 }, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z
    { 0x536EE0, 0x0D158C2D, 0x0000 }, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z
    { 0x537270, 0x70346B1C, 0x0000 }, // ?swLineInt@@YAXHHHHH@Z
    { 0x537360, 0xD3599FF6, 0x0000 }, // ?swLine@@YAXPAUagiScreenVtx@@0@Z
    { 0x537410, 0x9F0506DD, 0x0000 }, // ?swKill@@YAXXZ
    { 0x537440, 0xED2C753D, 0x0000 }, // ?swSetInterlace@@YAXH@Z
    { 0x537480, 0x7008C6BA, 0x0000 }, // ?swInit@@YAXXZ
    { 0x537550, 0xC2E829E7, 0x0000 }, // ?swFindColor555@@YAII@Z
    { 0x537590, 0x737454E2, 0x0000 }, // ?swFindColor565@@YAII@Z
    { 0x5375D0, 0xB8434C06, 0x0000 }, // ?swClampAddColor565@@YIII@Z
    { 0x537610, 0xB310D5AF, 0x0000 }, // ?swClampAddColor555@@YIII@Z
    { 0x537650, 0x153D029E, 0x0000 }, // ?swClampAdd565@@YIIII@Z
    { 0x537690, 0x1827C99B, 0x0000 }, // ?swClampAdd555@@YIIII@Z
    { 0x5376D0, 0x5011467D, 0x0000 }, // ??0agiSWTexDef@@QAE@PAVagiSWPipeline@@@Z
    { 0x537700, 0xF97B924F, 0x0000 }, // ??1agiSWTexDef@@UAE@XZ
    { 0x537710, 0xB29548A0, 0x0000 }, // ?Set@agiSWTexDef@@UAEXAAVVector2@@0@Z
    { 0x537730, 0x6CB1D32B, 0x0000 }, // ?BeginGfx@agiSWTexDef@@UAEHXZ
    { 0x537810, 0xB2B1A10D, 0x0000 }, // ?IsAvailable@agiSWTexDef@@UAEHXZ
    { 0x537820, 0x374E8FA8, 0x0000 }, // ?EndGfx@agiSWTexDef@@UAEXXZ
    { 0x537870, 0x0EC44D1E, 0x0000 }, // ?Lock@agiSWTexDef@@UAEHAAUagiTexLock@@@Z
    { 0x5378C0, 0xB7A8939D, 0x0000 }, // ?Unlock@agiSWTexDef@@UAEXAAUagiTexLock@@@Z
    { 0x5378D0, 0x0A81F1D8, 0x0000 }, // ?Request@agiSWTexDef@@UAEXXZ
    { 0x537930, 0xE2AA1081, 0x0000 }, // ??0agiSWTexLut@@QAE@PAVagiSWPipeline@@@Z
    { 0x537950, 0x5BFA44CB, 0x0000 }, // ?BeginGfx@agiSWTexLut@@UAEHXZ
    { 0x537B30, 0x7D6422CA, 0x0000 }, // ?EndGfx@agiSWTexLut@@UAEXXZ
    { 0x537BA0, 0xD2354FAA, 0x0000 }, // ??1agiSWTexLut@@UAE@XZ
    { 0x537BB0, 0x5A2C37C7, 0x0000 }, // ??0agiSWRasterizer@@QAE@PAVagiPipeline@@@Z
    { 0x537BD0, 0xDD3CA1CC, 0x0000 }, // ??1agiSWRasterizer@@UAE@XZ
    { 0x537BE0, 0x6F49DBFC, 0x0000 }, // ?BeginGfx@agiSWRasterizer@@UAEHXZ
    { 0x537BF0, 0x4E3C727C, 0x0000 }, // ?EndGfx@agiSWRasterizer@@UAEXXZ
    { 0x537C00, 0x17D55813, 0x0000 }, // ?BeginGroup@agiSWRasterizer@@UAEXXZ
    { 0x537C10, 0x6953EEC3, 0x0000 }, // ?EndGroup@agiSWRasterizer@@UAEXXZ
    { 0x537C20, 0x0A6AE6A1, 0x0000 }, // ?Verts@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    { 0x537C30, 0xDE24493B, 0x0000 }, // ?SetVertCount@agiSWRasterizer@@UAEXH@Z
    { 0x537C40, 0x09C968B7, 0x0000 }, // ?Triangle@agiSWRasterizer@@UAEXHHH@Z
    { 0x537C70, 0x6D94E8F0, 0x0000 }, // ?Quad@agiSWRasterizer@@UAEXHHHH@Z
    { 0x537CB0, 0x6DB67341, 0x0000 }, // ?Line@agiSWRasterizer@@UAEXHH@Z
    { 0x537CF0, 0x51AC92B1, 0x0000 }, // ?Card@agiSWRasterizer@@UAEXHH@Z
    { 0x537D00, 0x555C3E43, 0x0000 }, // ?Points@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    { 0x537D10, 0x8FD7DB74, 0x0000 }, // ?Mesh@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@HPAGH@Z
    { 0x537DF0, 0x1E383082, 0x0000 }, // ?swEmitRun1_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x537E80, 0xCBC23D5A, 0x0000 }, // ?swEmitRun2_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x537F10, 0x112EFA9B, 0x0000 }, // ?swEmitRun3_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x537FA0, 0x6CF1DD23, 0x0000 }, // ?swEmitRun4_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538030, 0x7B67CDD3, 0x0000 }, // ?swEmitRun5_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538250, 0xE00C7161, 0x0000 }, // ?swEmitRun6_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538470, 0x1C10B9BB, 0x0000 }, // ?swEmitRun7_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538690, 0x1A75C811, 0x0000 }, // ?swEmitRun8_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x5388A0, 0x9875AF66, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538980, 0x36350FFA, 0x0000 }, // ?swEmitRun1_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538A60, 0xC73EFE80, 0x0000 }, // ?swEmitRun2_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538B40, 0xF32923FB, 0x0000 }, // ?swEmitRun3_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538C20, 0xF4B99BB1, 0x0000 }, // ?swEmitRun4_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x538D00, 0xBFDBA444, 0x0000 }, // ?swEmitRun5_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x539060, 0x178050E7, 0x0000 }, // ?swEmitRun6_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x5393C0, 0xBE362DAD, 0x0000 }, // ?swEmitRun7_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x539720, 0xE3C9C2E1, 0x0000 }, // ?swEmitRun8_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    { 0x539A70, 0xE51C6C62, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalLinearStippleWUWV@@YIXH@Z
    { 0x539B20, 0x81C31DE9, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalLinearStippleWUWV@@YIXH@Z
    { 0x539C20, 0xADB2A6B1, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUWV@@YIXH@Z
    { 0x539D20, 0x58A6953C, 0x0000 }, // ?swEmitRun0_NoZChromaDecalLinearSolidWUWV@@YIXH@Z
    { 0x539DC0, 0x06E2664A, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalLinearSolidWUWV@@YIXH@Z
    { 0x539EB0, 0x1071ED59, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalLinearSolidWUWV@@YIXH@Z
    { 0x539FA0, 0x11E892B7, 0x0000 }, // ?swEmitRun0_NoZChromaDecalLinearStippleWUWV@@YIXH@Z
    { 0x53A060, 0xF519B57D, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalLinearStippleWUWV@@YIXH@Z
    { 0x53A160, 0xE3F0F4E1, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalLinearStippleWUWV@@YIXH@Z
    { 0x53A270, 0x451D46E3, 0x0000 }, // ?swEmitRun0_NoZGlowDecalLinearSolidWUWV@@YIXH@Z
    { 0x53A340, 0xD68D25DA, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalLinearSolidWUWV@@YIXH@Z
    { 0x53A460, 0x719792F2, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalLinearSolidWUWV@@YIXH@Z
    { 0x53A590, 0x8A7D520A, 0x0000 }, // ?swEmitRun0_NoZGlowDecalLinearStippleWUWV@@YIXH@Z
    { 0x53A670, 0x419E4B9B, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalLinearStippleWUWV@@YIXH@Z
    { 0x53A7A0, 0x8FB78F0C, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalLinearStippleWUWV@@YIXH@Z
    { 0x53A8E0, 0x5361F5F5, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateLinearSolidWUWV@@YIXH@Z
    { 0x53A980, 0x6371F2E6, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateLinearSolidWUWV@@YIXH@Z
    { 0x53AA70, 0xAD07D3FC, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUWV@@YIXH@Z
    { 0x53AB70, 0x8FF3D2A9, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateLinearStippleWUWV@@YIXH@Z
    { 0x53AC20, 0x97AAB507, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateLinearStippleWUWV@@YIXH@Z
    { 0x53AD20, 0xC774A774, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUWV@@YIXH@Z
    { 0x53AE30, 0x69E39D58, 0x0000 }, // ?swEmitRun0_NoZChromaModulateLinearSolidWUWV@@YIXH@Z
    { 0x53AEE0, 0xC80FC739, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateLinearSolidWUWV@@YIXH@Z
    { 0x53AFE0, 0xD2CF9A2D, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateLinearSolidWUWV@@YIXH@Z
    { 0x53B0E0, 0xF504B02F, 0x0000 }, // ?swEmitRun0_NoZChromaModulateLinearStippleWUWV@@YIXH@Z
    { 0x53B1A0, 0x36C4305C, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateLinearStippleWUWV@@YIXH@Z
    { 0x53B2B0, 0x470AED55, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateLinearStippleWUWV@@YIXH@Z
    { 0x53B3C0, 0xEC3C9943, 0x0000 }, // ?swEmitRun0_NoZGlowModulateLinearSolidWUWV@@YIXH@Z
    { 0x53B490, 0x970B22AE, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateLinearSolidWUWV@@YIXH@Z
    { 0x53B5B0, 0x24FB03C2, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateLinearSolidWUWV@@YIXH@Z
    { 0x53B6E0, 0x2EB6F6BF, 0x0000 }, // ?swEmitRun0_NoZGlowModulateLinearStippleWUWV@@YIXH@Z
    { 0x53B7C0, 0xEB69BFE9, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateLinearStippleWUWV@@YIXH@Z
    { 0x53B8F0, 0x055C3039, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateLinearStippleWUWV@@YIXH@Z
    { 0x53BA30, 0x010CD061, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalParaSolidWUWV@@YIXH@Z
    { 0x53BAF0, 0xE198880B, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalParaSolidWUWV@@YIXH@Z
    { 0x53BC00, 0x7D8BCCC3, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUWV@@YIXH@Z
    { 0x53BD10, 0x69AC02D5, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalParaStippleWUWV@@YIXH@Z
    { 0x53BDE0, 0x27E61D3B, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalParaStippleWUWV@@YIXH@Z
    { 0x53BF00, 0x5C719B60, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUWV@@YIXH@Z
    { 0x53C020, 0xDAD2BB1F, 0x0000 }, // ?swEmitRun0_NoZChromaDecalParaSolidWUWV@@YIXH@Z
    { 0x53C0E0, 0x3DFB50D1, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalParaSolidWUWV@@YIXH@Z
    { 0x53C200, 0xC4FAB591, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalParaSolidWUWV@@YIXH@Z
    { 0x53C320, 0x079C2C16, 0x0000 }, // ?swEmitRun0_NoZChromaDecalParaStippleWUWV@@YIXH@Z
    { 0x53C400, 0xA8570075, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalParaStippleWUWV@@YIXH@Z
    { 0x53C530, 0x3C266B28, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalParaStippleWUWV@@YIXH@Z
    { 0x53C660, 0xE2C8F5E9, 0x0000 }, // ?swEmitRun0_NoZGlowDecalParaSolidWUWV@@YIXH@Z
    { 0x53C750, 0x08FAEFD7, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalParaSolidWUWV@@YIXH@Z
    { 0x53C890, 0xCC6B55E6, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalParaSolidWUWV@@YIXH@Z
    { 0x53C9E0, 0xDB063B6C, 0x0000 }, // ?swEmitRun0_NoZGlowDecalParaStippleWUWV@@YIXH@Z
    { 0x53CAF0, 0xF207D6A0, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalParaStippleWUWV@@YIXH@Z
    { 0x53CC40, 0xDC1C5CF9, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalParaStippleWUWV@@YIXH@Z
    { 0x53CDA0, 0xF88ED741, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateParaSolidWUWV@@YIXH@Z
    { 0x53CE60, 0x3A5F5206, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateParaSolidWUWV@@YIXH@Z
    { 0x53CF70, 0x425575FE, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUWV@@YIXH@Z
    { 0x53D080, 0x2A9D83E2, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateParaStippleWUWV@@YIXH@Z
    { 0x53D160, 0xA460A47D, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateParaStippleWUWV@@YIXH@Z
    { 0x53D280, 0x24AA179A, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUWV@@YIXH@Z
    { 0x53D3B0, 0x22DFC153, 0x0000 }, // ?swEmitRun0_NoZChromaModulateParaSolidWUWV@@YIXH@Z
    { 0x53D480, 0xF0D4AC95, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateParaSolidWUWV@@YIXH@Z
    { 0x53D5A0, 0xECAD70BA, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateParaSolidWUWV@@YIXH@Z
    { 0x53D6C0, 0x4C26E482, 0x0000 }, // ?swEmitRun0_NoZChromaModulateParaStippleWUWV@@YIXH@Z
    { 0x53D7A0, 0xA1FCB362, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateParaStippleWUWV@@YIXH@Z
    { 0x53D8D0, 0xBC87FC94, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateParaStippleWUWV@@YIXH@Z
    { 0x53DA10, 0x0795D74C, 0x0000 }, // ?swEmitRun0_NoZGlowModulateParaSolidWUWV@@YIXH@Z
    { 0x53DB00, 0xC26CBFBD, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateParaSolidWUWV@@YIXH@Z
    { 0x53DC40, 0x9D573EF2, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateParaSolidWUWV@@YIXH@Z
    { 0x53DD90, 0x533F3293, 0x0000 }, // ?swEmitRun0_NoZGlowModulateParaStippleWUWV@@YIXH@Z
    { 0x53DEA0, 0x16E8ABFC, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateParaStippleWUWV@@YIXH@Z
    { 0x53DFF0, 0xC5E61E92, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateParaStippleWUWV@@YIXH@Z
    { 0x53E150, 0xE4C39554, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalLinearSolidCUWV@@YIXH@Z
    { 0x53E220, 0xEBA448FC, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalLinearSolidCUWV@@YIXH@Z
    { 0x53E350, 0x82DDE4E0, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUWV@@YIXH@Z
    { 0x53E470, 0x578FF176, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalLinearStippleCUWV@@YIXH@Z
    { 0x53E550, 0xBB0EDECD, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalLinearStippleCUWV@@YIXH@Z
    { 0x53E680, 0x353A9BA0, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUWV@@YIXH@Z
    { 0x53E7C0, 0x9BE94EED, 0x0000 }, // ?swEmitRun0_NoZChromaDecalLinearSolidCUWV@@YIXH@Z
    { 0x53E8B0, 0xEB163A40, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalLinearSolidCUWV@@YIXH@Z
    { 0x53E9F0, 0xADEBF8D1, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalLinearSolidCUWV@@YIXH@Z
    { 0x53EB30, 0xB6FA6D72, 0x0000 }, // ?swEmitRun0_NoZChromaDecalLinearStippleCUWV@@YIXH@Z
    { 0x53EC30, 0xF43F49E1, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalLinearStippleCUWV@@YIXH@Z
    { 0x53ED80, 0x9CC3233B, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalLinearStippleCUWV@@YIXH@Z
    { 0x53EED0, 0xC832E2DE, 0x0000 }, // ?swEmitRun0_NoZGlowDecalLinearSolidCUWV@@YIXH@Z
    { 0x53EFD0, 0xC54A5CD0, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalLinearSolidCUWV@@YIXH@Z
    { 0x53F120, 0x7C9692BC, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalLinearSolidCUWV@@YIXH@Z
    { 0x53F260, 0x84CD5C93, 0x0000 }, // ?swEmitRun0_NoZGlowDecalLinearStippleCUWV@@YIXH@Z
    { 0x53F370, 0x231F3840, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalLinearStippleCUWV@@YIXH@Z
    { 0x53F4D0, 0xCBA0EC28, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalLinearStippleCUWV@@YIXH@Z
    { 0x53F630, 0xAE76A63C, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateLinearSolidCUWV@@YIXH@Z
    { 0x53F710, 0xF4963712, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateLinearSolidCUWV@@YIXH@Z
    { 0x53F850, 0x31CEC5A3, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUWV@@YIXH@Z
    { 0x53F980, 0x432FD7A5, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateLinearStippleCUWV@@YIXH@Z
    { 0x53FA70, 0xFEED8C18, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateLinearStippleCUWV@@YIXH@Z
    { 0x53FBB0, 0xA3FE0814, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUWV@@YIXH@Z
    { 0x53FD00, 0x0392DA7F, 0x0000 }, // ?swEmitRun0_NoZChromaModulateLinearSolidCUWV@@YIXH@Z
    { 0x53FE00, 0x1FDCD566, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateLinearSolidCUWV@@YIXH@Z
    { 0x53FF50, 0xAF194A24, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateLinearSolidCUWV@@YIXH@Z
    { 0x5400A0, 0x8828BB6D, 0x0000 }, // ?swEmitRun0_NoZChromaModulateLinearStippleCUWV@@YIXH@Z
    { 0x5401B0, 0x9DEF7D67, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateLinearStippleCUWV@@YIXH@Z
    { 0x540310, 0xCA33B622, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateLinearStippleCUWV@@YIXH@Z
    { 0x540470, 0xCC62E72E, 0x0000 }, // ?swEmitRun0_NoZGlowModulateLinearSolidCUWV@@YIXH@Z
    { 0x540570, 0x66FA8E0D, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateLinearSolidCUWV@@YIXH@Z
    { 0x5406C0, 0x8B63A2A0, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateLinearSolidCUWV@@YIXH@Z
    { 0x540800, 0xA72E3175, 0x0000 }, // ?swEmitRun0_NoZGlowModulateLinearStippleCUWV@@YIXH@Z
    { 0x540910, 0x83247A54, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateLinearStippleCUWV@@YIXH@Z
    { 0x540A70, 0xA79EB068, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateLinearStippleCUWV@@YIXH@Z
    { 0x540BD0, 0xE96A8498, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalParaSolidCUWV@@YIXH@Z
    { 0x540CD0, 0x2E8066C5, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalParaSolidCUWV@@YIXH@Z
    { 0x540E20, 0x433F56D5, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUWV@@YIXH@Z
    { 0x540F70, 0xF9D67016, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalParaStippleCUWV@@YIXH@Z
    { 0x541080, 0x75FADD28, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalParaStippleCUWV@@YIXH@Z
    { 0x5411E0, 0x40735A93, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUWV@@YIXH@Z
    { 0x541340, 0x2EF7D370, 0x0000 }, // ?swEmitRun0_NoZChromaDecalParaSolidCUWV@@YIXH@Z
    { 0x541450, 0xBF8254B3, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalParaSolidCUWV@@YIXH@Z
    { 0x5415B0, 0x43F7CAC9, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalParaSolidCUWV@@YIXH@Z
    { 0x541710, 0x6C1CDAA4, 0x0000 }, // ?swEmitRun0_NoZChromaDecalParaStippleCUWV@@YIXH@Z
    { 0x541830, 0x7EB37DB7, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalParaStippleCUWV@@YIXH@Z
    { 0x5419A0, 0x2936BC53, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalParaStippleCUWV@@YIXH@Z
    { 0x541B10, 0x5AB60DC3, 0x0000 }, // ?swEmitRun0_NoZGlowDecalParaSolidCUWV@@YIXH@Z
    { 0x541C30, 0xE55A2720, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalParaSolidCUWV@@YIXH@Z
    { 0x541DA0, 0x12D3BA7C, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalParaSolidCUWV@@YIXH@Z
    { 0x541F10, 0x851E86FB, 0x0000 }, // ?swEmitRun0_NoZGlowDecalParaStippleCUWV@@YIXH@Z
    { 0x542040, 0x749F54EB, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalParaStippleCUWV@@YIXH@Z
    { 0x5421C0, 0x472FFAB7, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalParaStippleCUWV@@YIXH@Z
    { 0x542350, 0xA8375781, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateParaSolidCUWV@@YIXH@Z
    { 0x542460, 0xF3B9E537, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateParaSolidCUWV@@YIXH@Z
    { 0x5425C0, 0xE71DC3F6, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUWV@@YIXH@Z
    { 0x542710, 0x48D1CA3B, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateParaStippleCUWV@@YIXH@Z
    { 0x542830, 0xF18925B0, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateParaStippleCUWV@@YIXH@Z
    { 0x542990, 0x76BE03C9, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUWV@@YIXH@Z
    { 0x542B00, 0xE48A8AC8, 0x0000 }, // ?swEmitRun0_NoZChromaModulateParaSolidCUWV@@YIXH@Z
    { 0x542C20, 0xD2253CD7, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateParaSolidCUWV@@YIXH@Z
    { 0x542D90, 0xC12643C7, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateParaSolidCUWV@@YIXH@Z
    { 0x542EF0, 0x312EA7AA, 0x0000 }, // ?swEmitRun0_NoZChromaModulateParaStippleCUWV@@YIXH@Z
    { 0x543020, 0x710C569F, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateParaStippleCUWV@@YIXH@Z
    { 0x5431A0, 0x1B121619, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateParaStippleCUWV@@YIXH@Z
    { 0x543320, 0x09278F05, 0x0000 }, // ?swEmitRun0_NoZGlowModulateParaSolidCUWV@@YIXH@Z
    { 0x543440, 0x2A62A55F, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateParaSolidCUWV@@YIXH@Z
    { 0x5435B0, 0xE2E0A7E7, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateParaSolidCUWV@@YIXH@Z
    { 0x543720, 0x98FFD062, 0x0000 }, // ?swEmitRun0_NoZGlowModulateParaStippleCUWV@@YIXH@Z
    { 0x543850, 0x9E365DFA, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateParaStippleCUWV@@YIXH@Z
    { 0x5439D0, 0x522134A0, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateParaStippleCUWV@@YIXH@Z
    { 0x543B60, 0xE68E9236, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalLinearSolidWUCV@@YIXH@Z
    { 0x543C30, 0x27200549, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalLinearSolidWUCV@@YIXH@Z
    { 0x543D60, 0x4FE4F950, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidWUCV@@YIXH@Z
    { 0x543E80, 0xAFAB7439, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalLinearStippleWUCV@@YIXH@Z
    { 0x543F60, 0xA1DE1F5B, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalLinearStippleWUCV@@YIXH@Z
    { 0x544090, 0xCD8FDCB9, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUCV@@YIXH@Z
    { 0x5441D0, 0xB5AF3680, 0x0000 }, // ?swEmitRun0_NoZChromaDecalLinearSolidWUCV@@YIXH@Z
    { 0x5442B0, 0x9DE3E038, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalLinearSolidWUCV@@YIXH@Z
    { 0x5443E0, 0x094C6C6A, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalLinearSolidWUCV@@YIXH@Z
    { 0x544520, 0x88AE0AC6, 0x0000 }, // ?swEmitRun0_NoZChromaDecalLinearStippleWUCV@@YIXH@Z
    { 0x544620, 0xC089EE9D, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalLinearStippleWUCV@@YIXH@Z
    { 0x544770, 0xF5CE4472, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalLinearStippleWUCV@@YIXH@Z
    { 0x5448C0, 0x529D0FA5, 0x0000 }, // ?swEmitRun0_NoZGlowDecalLinearSolidWUCV@@YIXH@Z
    { 0x5449C0, 0x0C2CD90D, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalLinearSolidWUCV@@YIXH@Z
    { 0x544B00, 0x322B315E, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalLinearSolidWUCV@@YIXH@Z
    { 0x544C40, 0xE1698EF0, 0x0000 }, // ?swEmitRun0_NoZGlowDecalLinearStippleWUCV@@YIXH@Z
    { 0x544D40, 0x7AE5B0FF, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalLinearStippleWUCV@@YIXH@Z
    { 0x544EA0, 0x5BC99671, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalLinearStippleWUCV@@YIXH@Z
    { 0x545000, 0xC7AC2849, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateLinearSolidWUCV@@YIXH@Z
    { 0x5450E0, 0x9E61BE4A, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateLinearSolidWUCV@@YIXH@Z
    { 0x545220, 0x1EBAB7BF, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUCV@@YIXH@Z
    { 0x545350, 0x8A1EA150, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateLinearStippleWUCV@@YIXH@Z
    { 0x545440, 0x9C354145, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateLinearStippleWUCV@@YIXH@Z
    { 0x545580, 0x1A1009E4, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUCV@@YIXH@Z
    { 0x5456D0, 0x1D8790B7, 0x0000 }, // ?swEmitRun0_NoZChromaModulateLinearSolidWUCV@@YIXH@Z
    { 0x5457C0, 0x301FC7FD, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateLinearSolidWUCV@@YIXH@Z
    { 0x545900, 0x2C44A91B, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateLinearSolidWUCV@@YIXH@Z
    { 0x545A40, 0xD8456AAE, 0x0000 }, // ?swEmitRun0_NoZChromaModulateLinearStippleWUCV@@YIXH@Z
    { 0x545B40, 0xC51D6217, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateLinearStippleWUCV@@YIXH@Z
    { 0x545CA0, 0x52520753, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateLinearStippleWUCV@@YIXH@Z
    { 0x545E00, 0xDD30E85B, 0x0000 }, // ?swEmitRun0_NoZGlowModulateLinearSolidWUCV@@YIXH@Z
    { 0x545F00, 0xFB9CD66E, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateLinearSolidWUCV@@YIXH@Z
    { 0x546040, 0x21238756, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateLinearSolidWUCV@@YIXH@Z
    { 0x546180, 0x26206C48, 0x0000 }, // ?swEmitRun0_NoZGlowModulateLinearStippleWUCV@@YIXH@Z
    { 0x546280, 0xF1300EF5, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateLinearStippleWUCV@@YIXH@Z
    { 0x5463E0, 0x63EC3DBD, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateLinearStippleWUCV@@YIXH@Z
    { 0x546540, 0x0E3283AE, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalParaSolidWUCV@@YIXH@Z
    { 0x546630, 0x82220173, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalParaSolidWUCV@@YIXH@Z
    { 0x546780, 0x47F79D22, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUCV@@YIXH@Z
    { 0x5468C0, 0xA019404F, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalParaStippleWUCV@@YIXH@Z
    { 0x5469C0, 0x0382D1AE, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalParaStippleWUCV@@YIXH@Z
    { 0x546B10, 0xFA32F8D1, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUCV@@YIXH@Z
    { 0x546C70, 0x87F22981, 0x0000 }, // ?swEmitRun0_NoZChromaDecalParaSolidWUCV@@YIXH@Z
    { 0x546D80, 0x8E941366, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalParaSolidWUCV@@YIXH@Z
    { 0x546ED0, 0x50663A58, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalParaSolidWUCV@@YIXH@Z
    { 0x547020, 0x9EE134FE, 0x0000 }, // ?swEmitRun0_NoZChromaDecalParaStippleWUCV@@YIXH@Z
    { 0x547140, 0x6815A3CD, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalParaStippleWUCV@@YIXH@Z
    { 0x5472A0, 0x3CF3A2CB, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalParaStippleWUCV@@YIXH@Z
    { 0x547410, 0x542A72A6, 0x0000 }, // ?swEmitRun0_NoZGlowDecalParaSolidWUCV@@YIXH@Z
    { 0x547530, 0x0321FD74, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalParaSolidWUCV@@YIXH@Z
    { 0x5476A0, 0x81320298, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalParaSolidWUCV@@YIXH@Z
    { 0x547810, 0x3B499F51, 0x0000 }, // ?swEmitRun0_NoZGlowDecalParaStippleWUCV@@YIXH@Z
    { 0x547930, 0x3785C4B2, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalParaStippleWUCV@@YIXH@Z
    { 0x547AB0, 0xC9C6CAC6, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalParaStippleWUCV@@YIXH@Z
    { 0x547C30, 0x3390504E, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateParaSolidWUCV@@YIXH@Z
    { 0x547D30, 0x767698A0, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateParaSolidWUCV@@YIXH@Z
    { 0x547E90, 0xC31C5B62, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUCV@@YIXH@Z
    { 0x547FE0, 0x3AEE8BC3, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateParaStippleWUCV@@YIXH@Z
    { 0x5480F0, 0x19FF3E35, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateParaStippleWUCV@@YIXH@Z
    { 0x548250, 0x372D2488, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUCV@@YIXH@Z
    { 0x5483C0, 0x09EA11CB, 0x0000 }, // ?swEmitRun0_NoZChromaModulateParaSolidWUCV@@YIXH@Z
    { 0x5484E0, 0x4AF4BF8D, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateParaSolidWUCV@@YIXH@Z
    { 0x548640, 0xBE703FE4, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateParaSolidWUCV@@YIXH@Z
    { 0x5487A0, 0x6B9524B8, 0x0000 }, // ?swEmitRun0_NoZChromaModulateParaStippleWUCV@@YIXH@Z
    { 0x5488C0, 0xE620F718, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateParaStippleWUCV@@YIXH@Z
    { 0x548A30, 0xBAA98F53, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateParaStippleWUCV@@YIXH@Z
    { 0x548BA0, 0x168E4695, 0x0000 }, // ?swEmitRun0_NoZGlowModulateParaSolidWUCV@@YIXH@Z
    { 0x548CC0, 0x7A262297, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateParaSolidWUCV@@YIXH@Z
    { 0x548E30, 0xEEF8E7EB, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateParaSolidWUCV@@YIXH@Z
    { 0x548FA0, 0x0E045307, 0x0000 }, // ?swEmitRun0_NoZGlowModulateParaStippleWUCV@@YIXH@Z
    { 0x5490C0, 0xA410F7D9, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateParaStippleWUCV@@YIXH@Z
    { 0x549240, 0xA28A6E2A, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateParaStippleWUCV@@YIXH@Z
    { 0x5493C0, 0x5CE90071, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalLinearSolidCUCV@@YIXH@Z
    { 0x5494C0, 0x23ADFDCA, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalLinearSolidCUCV@@YIXH@Z
    { 0x549620, 0xE74F91D7, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUCV@@YIXH@Z
    { 0x549770, 0x466E861B, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalLinearStippleCUCV@@YIXH@Z
    { 0x549880, 0x2CEAA357, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalLinearStippleCUCV@@YIXH@Z
    { 0x5499E0, 0xF84E454F, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUCV@@YIXH@Z
    { 0x549B40, 0x84A0534C, 0x0000 }, // ?swEmitRun0_NoZChromaDecalLinearSolidCUCV@@YIXH@Z
    { 0x549C60, 0x5F54FCC9, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalLinearSolidCUCV@@YIXH@Z
    { 0x549DD0, 0x7E0A623D, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalLinearSolidCUCV@@YIXH@Z
    { 0x549F40, 0x832F1449, 0x0000 }, // ?swEmitRun0_NoZChromaDecalLinearStippleCUCV@@YIXH@Z
    { 0x54A070, 0xA1F7C3AC, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalLinearStippleCUCV@@YIXH@Z
    { 0x54A1F0, 0x47706124, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalLinearStippleCUCV@@YIXH@Z
    { 0x54A370, 0xB8E21663, 0x0000 }, // ?swEmitRun0_NoZGlowDecalLinearSolidCUCV@@YIXH@Z
    { 0x54A4A0, 0x10E745B4, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalLinearSolidCUCV@@YIXH@Z
    { 0x54A620, 0x4A088262, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalLinearSolidCUCV@@YIXH@Z
    { 0x54A790, 0x7EB21F93, 0x0000 }, // ?swEmitRun0_NoZGlowDecalLinearStippleCUCV@@YIXH@Z
    { 0x54A8D0, 0xC2FD44D5, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalLinearStippleCUCV@@YIXH@Z
    { 0x54AA60, 0x3FB89934, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalLinearStippleCUCV@@YIXH@Z
    { 0x54ABE0, 0xB7ACCCD8, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateLinearSolidCUCV@@YIXH@Z
    { 0x54ACF0, 0x35DB358B, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateLinearSolidCUCV@@YIXH@Z
    { 0x54AE50, 0xE4B89427, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUCV@@YIXH@Z
    { 0x54AFB0, 0x02A450E0, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateLinearStippleCUCV@@YIXH@Z
    { 0x54B0D0, 0x74DE35A6, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateLinearStippleCUCV@@YIXH@Z
    { 0x54B240, 0x9D5DF229, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUCV@@YIXH@Z
    { 0x54B3B0, 0x179F9011, 0x0000 }, // ?swEmitRun0_NoZChromaModulateLinearSolidCUCV@@YIXH@Z
    { 0x54B4E0, 0x39DE685F, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateLinearSolidCUCV@@YIXH@Z
    { 0x54B660, 0xB626BF06, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateLinearSolidCUCV@@YIXH@Z
    { 0x54B7E0, 0x36F51199, 0x0000 }, // ?swEmitRun0_NoZChromaModulateLinearStippleCUCV@@YIXH@Z
    { 0x54B920, 0x52035BE2, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateLinearStippleCUCV@@YIXH@Z
    { 0x54BAB0, 0x82D2D365, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateLinearStippleCUCV@@YIXH@Z
    { 0x54BC40, 0xB073818E, 0x0000 }, // ?swEmitRun0_NoZGlowModulateLinearSolidCUCV@@YIXH@Z
    { 0x54BD70, 0xFDB6114E, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateLinearSolidCUCV@@YIXH@Z
    { 0x54BEF0, 0xF9C53C77, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateLinearSolidCUCV@@YIXH@Z
    { 0x54C060, 0x7F67C395, 0x0000 }, // ?swEmitRun0_NoZGlowModulateLinearStippleCUCV@@YIXH@Z
    { 0x54C1A0, 0x65748EB1, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateLinearStippleCUCV@@YIXH@Z
    { 0x54C330, 0x03A20514, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateLinearStippleCUCV@@YIXH@Z
    { 0x54C4B0, 0xBF110AE9, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalParaSolidCUCV@@YIXH@Z
    { 0x54C5D0, 0x1657771B, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalParaSolidCUCV@@YIXH@Z
    { 0x54C750, 0x8A39448F, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUCV@@YIXH@Z
    { 0x54C8C0, 0xB3060CF3, 0x0000 }, // ?swEmitRun0_NoZOpaqueDecalParaStippleCUCV@@YIXH@Z
    { 0x54C9F0, 0x45C9FA8C, 0x0000 }, // ?swEmitRun0_ZReadOpaqueDecalParaStippleCUCV@@YIXH@Z
    { 0x54CB70, 0x74D73C95, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUCV@@YIXH@Z
    { 0x54CD00, 0xD2FFFAE4, 0x0000 }, // ?swEmitRun0_NoZChromaDecalParaSolidCUCV@@YIXH@Z
    { 0x54CE40, 0x8CF9A4FE, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalParaSolidCUCV@@YIXH@Z
    { 0x54CFD0, 0xEF517F3D, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalParaSolidCUCV@@YIXH@Z
    { 0x54D160, 0xC7344FC8, 0x0000 }, // ?swEmitRun0_NoZChromaDecalParaStippleCUCV@@YIXH@Z
    { 0x54D2B0, 0xB76B0F8D, 0x0000 }, // ?swEmitRun0_ZReadChromaDecalParaStippleCUCV@@YIXH@Z
    { 0x54D450, 0xB9F26129, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaDecalParaStippleCUCV@@YIXH@Z
    { 0x54D5F0, 0x2AD7A7E8, 0x0000 }, // ?swEmitRun0_NoZGlowDecalParaSolidCUCV@@YIXH@Z
    { 0x54D740, 0x8537C87E, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalParaSolidCUCV@@YIXH@Z
    { 0x54D8E0, 0x6EDCBA42, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalParaSolidCUCV@@YIXH@Z
    { 0x54DA70, 0x961FDB82, 0x0000 }, // ?swEmitRun0_NoZGlowDecalParaStippleCUCV@@YIXH@Z
    { 0x54DBD0, 0x7ED3D42D, 0x0000 }, // ?swEmitRun0_ZReadGlowDecalParaStippleCUCV@@YIXH@Z
    { 0x54DD80, 0xF377F5F6, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowDecalParaStippleCUCV@@YIXH@Z
    { 0x54DF30, 0xE2BEFA8A, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateParaSolidCUCV@@YIXH@Z
    { 0x54E060, 0x944CB5BE, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateParaSolidCUCV@@YIXH@Z
    { 0x54E1F0, 0x4A24B731, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUCV@@YIXH@Z
    { 0x54E370, 0x60ECCC47, 0x0000 }, // ?swEmitRun0_NoZOpaqueModulateParaStippleCUCV@@YIXH@Z
    { 0x54E4B0, 0xD244C879, 0x0000 }, // ?swEmitRun0_ZReadOpaqueModulateParaStippleCUCV@@YIXH@Z
    { 0x54E640, 0xFF61668B, 0x0000 }, // ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUCV@@YIXH@Z
    { 0x54E7E0, 0xD16B8C78, 0x0000 }, // ?swEmitRun0_NoZChromaModulateParaSolidCUCV@@YIXH@Z
    { 0x54E930, 0x9D251737, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateParaSolidCUCV@@YIXH@Z
    { 0x54EAD0, 0x509D03E1, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateParaSolidCUCV@@YIXH@Z
    { 0x54EC70, 0x1C01B8E4, 0x0000 }, // ?swEmitRun0_NoZChromaModulateParaStippleCUCV@@YIXH@Z
    { 0x54EDD0, 0x912443DC, 0x0000 }, // ?swEmitRun0_ZReadChromaModulateParaStippleCUCV@@YIXH@Z
    { 0x54EF80, 0x5035E01E, 0x0000 }, // ?swEmitRun0_ZReadWriteChromaModulateParaStippleCUCV@@YIXH@Z
    { 0x54F130, 0xE7151A0D, 0x0000 }, // ?swEmitRun0_NoZGlowModulateParaSolidCUCV@@YIXH@Z
    { 0x54F280, 0x9D77037C, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateParaSolidCUCV@@YIXH@Z
    { 0x54F420, 0x2410DD71, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateParaSolidCUCV@@YIXH@Z
    { 0x54F5B0, 0xFA2DF59D, 0x0000 }, // ?swEmitRun0_NoZGlowModulateParaStippleCUCV@@YIXH@Z
    { 0x54F710, 0x0E7DAFE3, 0x0000 }, // ?swEmitRun0_ZReadGlowModulateParaStippleCUCV@@YIXH@Z
    { 0x54F8C0, 0xCFED1321, 0x0000 }, // ?swEmitRun0_ZReadWriteGlowModulateParaStippleCUCV@@YIXH@Z
    { 0x54FA70, 0xC6BB1AE7, 0x0000 }, // ??0agiZBufRenderer@@QAE@PAVagiRasterizer@@@Z
    { 0x54FA90, 0x9857D55E, 0x0000 }, // ??1agiZBufRenderer@@UAE@XZ
    { 0x54FAA0, 0x6588DBEE, 0x0000 }, // ?EndGroup@agiZBufRenderer@@UAEXXZ
    { 0x550800, 0x7E14C3C8, 0x0000 }, // ??0RDLP@@QAE@PAVagiPipeline@@@Z
    { 0x550850, 0xD82EC0C7, 0x0000 }, // ??1RDLP@@UAE@XZ
    { 0x5508A0, 0x4B8B1E16, 0x0000 }, // ?InitFacet@RDLP@@AAEHPAUagiPatch@@HHHH@Z
    { 0x550C40, 0x459674D3, 0x0000 }, // ?BeginGfx@RDLP@@UAEHXZ
    { 0x551200, 0xD84006E0, 0x0000 }, // ?EndGfx@RDLP@@UAEXXZ
    { 0x551290, 0x1A003FC4, 0x0000 }, // ??0RDynamicDLP@@QAE@HPAVRDLP@@@Z
    { 0x5512F0, 0xD4D79380, 0x0000 }, // ??1RDynamicDLP@@UAE@XZ
    { 0x551360, 0xB1E23940, 0x0000 }, // ?Init@RDynamicDLP@@UAEHPAD@Z
    { 0x5513B0, 0xAE2DE020, 0x0000 }, // ?SetTexture@RDynamicDLP@@UAEXF@Z
    { 0x551440, 0xD99535DC, 0x0000 }, // ?Lock@RDynamicDLP@@UAEXXZ
    { 0x551480, 0x72BF4330, 0x0000 }, // ?Unlock@RDynamicDLP@@UAEXXZ
    { 0x551490, 0x1F87E604, 0x0000 }, // ?GetDynamic@RDLP@@UAEPAVDynamicDLP@@H@Z
    { 0x551530, 0x01361D09, 0x0000 }, // ?GetMultipass@RDLP@@UAEPAVMultipassDLP@@H@Z
    { 0x551540, 0x3B91A6B8, 0x0000 }, // ?FixROpts@RDLP@@UAEXHH@Z
    { 0x551740, 0x99FE4310, 0x0000 }, // ??0agiLighter@@QAE@XZ
    { 0x551750, 0x25E5CF43, 0x0000 }, // ??1agiLighter@@MAE@XZ
    { 0x551760, 0x5D999DE9, 0x0000 }, // ?BeginScene@agiLighter@@SAXXZ
    { 0x551780, 0x8E0A1102, 0x0000 }, // ?DeclareLight@agiLighter@@SAXPAVagiLight@@@Z
    { 0x5517A0, 0xAB0E8BF9, 0x0000 }, // ?RemoveLight@agiLighter@@SAXPAVagiLight@@@Z
    { 0x551800, 0x491265F9, 0x0000 }, // ?TransformAll@agiLighter@@UAEXPAVMatrix34@@PAVVector3@@I@Z
    { 0x5519F0, 0x1C2EEC36, 0x0000 }, // ??0agiMonoLighter@@QAE@XZ
    { 0x551A10, 0xC2518180, 0x0000 }, // ??1agiMonoLighter@@UAE@XZ
    { 0x551A20, 0x2A07D55C, 0x0000 }, // ?LightVertex@agiMonoLighter@@UAEIIPAUagiLitVtx@@PAVVector3@@@Z
    { 0x551E40, 0x376393A1, 0x0000 }, // ??0agiRGBLighter@@QAE@XZ
    { 0x551E60, 0xA520F67B, 0x0000 }, // ??1agiRGBLighter@@UAE@XZ
    { 0x551E70, 0xF5677B7F, 0x0000 }, // ?LightVertex@agiRGBLighter@@UAEIIPAUagiLitVtx@@PAVVector3@@@Z
    { 0x5524F0, 0x03E58E6F, 0x0000 }, // ?InitMtx@agiProjVtx@@SAXAAVMatrix34@@MMMM@Z
    { 0x552630, 0xA3251B74, 0x0000 }, // ?SetOutcode@agiProjVtx@@SAXH@Z
    { 0x552710, 0x6AC2AD15, 0x0000 }, // ?Project@agiProjVtx@@SAHHPAUagiLitVtx@@@Z
    { 0x552A20, 0x466C5995, 0x0000 }, // ?ToScreen@agiProjVtx@@SAXH@Z
    { 0x552BA0, 0x6087287F, 0x0000 }, // ?Init@agiProjVtx@@SAXHPAVagiLighter@@I@Z
    { 0x552D60, 0x44A5EA74, 0x0000 }, // ??0agiSurfRenderer@@QAE@PAVagiRasterizer@@@Z
    { 0x552DB0, 0xB4CDEA30, 0x0000 }, // ??1agiSurfRenderer@@MAE@XZ
    { 0x552DC0, 0xD1B2AC74, 0x0000 }, // ?BeginGroup@agiSurfRenderer@@UAEXXZ
    { 0x552E00, 0xB27E9F38, 0x0000 }, // ?AddSurface@agiSurfRenderer@@CAHPAUagiPatch@@HHHH@Z
    { 0x5544F0, 0x9A640EED, 0x0000 }, // ?Draw@agiSurfRenderer@@UAEXPAVDLP@@H@Z
    { 0x554890, 0x4DF7E6A2, 0x0000 }, // ?DrawCard@agiSurfRenderer@@UAEXAAVVector3@@@Z
    { 0x554D70, 0x8351F370, 0x0000 }, // ?BeginDraw@agiSurfRenderer@@UAEXH@Z
    { 0x554DA0, 0x2347BA3B, 0x0000 }, // ?Verts@agiSurfRenderer@@UAEXPATagiVtx@@H@Z
    { 0x554E40, 0x85B1221B, 0x0000 }, // ?Points@agiSurfRenderer@@UAEXPATagiVtx@@H@Z
    { 0x554EB0, 0x66D42383, 0x0000 }, // ?DrawTri@agiSurfRenderer@@UAEXHHH@Z
    { 0x554EE0, 0xA94DEB73, 0x0000 }, // ?DrawLine@agiSurfRenderer@@UAEXHH@Z
    { 0x555180, 0x886CA94B, 0x0000 }, // ?DrawLabel@agiSurfRenderer@@UAEXAATagiVtx@@PAD@Z
    { 0x5551F0, 0x11DD30EE, 0x0000 }, // ?EndDraw@agiSurfRenderer@@UAEXXZ
    { 0x555260, 0xC6EE78FE, 0x0000 }, // ??0agiBILightModel@@QAE@PAVagiPipeline@@@Z
    { 0x555280, 0x6B21809C, 0x0000 }, // ??1agiBILightModel@@UAE@XZ
    { 0x5552E0, 0xCEF3BF51, 0x0000 }, // ?BeginGfx@agiBILightModel@@UAEHXZ
    { 0x555310, 0xE74B0F38, 0x0000 }, // ?EndGfx@agiBILightModel@@UAEXXZ
    { 0x555320, 0xD1CC1C5C, 0x0000 }, // ?Activate@agiBILightModel@@UAEHXZ
    { 0x555370, 0x976C4C51, 0x0000 }, // ??0agiBILight@@QAE@PAVagiPipeline@@@Z
    { 0x555390, 0xF4EE261A, 0x0000 }, // ??1agiBILight@@UAE@XZ
    { 0x5553E0, 0x8EE9FA10, 0x0000 }, // ?BeginGfx@agiBILight@@UAEHXZ
    { 0x555400, 0x4DEDB28F, 0x0000 }, // ?EndGfx@agiBILight@@UAEXXZ
    { 0x555410, 0x99EF5436, 0x0000 }, // ?Update@agiBILight@@UAEHXZ
    { 0x555420, 0xF831CE20, 0x0000 }, // ?Remove@agiBILight@@UAEXXZ
    { 0x555480, 0xBBFB7127, 0x0000 }, // ??0agiPipeline@@IAE@XZ
    { 0x555540, 0x99D83AE9, 0x0000 }, // ?Validate@agiPipeline@@UAEHXZ
    { 0x555550, 0x5488A563, 0x0000 }, // ?Init@agiPipeline@@QAEHPADHHHHHHPAX@Z
    { 0x5555C0, 0xE611C3CF, 0x0000 }, // ?GetTexture@agiPipeline@@QAEPAVagiTexDef@@PADH@Z
    { 0x555620, 0xC456F835, 0x0000 }, // ?GetTexture@agiPipeline@@QAEPAVagiTexDef@@HH@Z
    { 0x555750, 0x0F628902, 0x0000 }, // ?GetBitmap@agiPipeline@@QAEPAVagiBitmap@@PADMMH@Z
    { 0x5557F0, 0xF2AE5BA0, 0x0000 }, // ?GetTexLut@agiPipeline@@QAEPAVagiTexLut@@PAD@Z
    { 0x555860, 0x25494AAC, 0x0000 }, // ?GetMaterial@agiPipeline@@QAEPAVagiMtlDef@@PAD@Z
    { 0x5558C0, 0x5F4E7418, 0x0000 }, // ?GetMaterial@agiPipeline@@QAEPAVagiMtlDef@@H@Z
    { 0x555950, 0xEB69EB31, 0x0000 }, // ?GetDLP@agiPipeline@@QAEPAVDLP@@PAD0PAVVector3@@HH@Z
    { 0x555B10, 0x40A35AC6, 0x0000 }, // ?CreateMtlDef@agiPipeline@@UAEPAVagiMtlDef@@XZ
    { 0x555B20, 0x50679F44, 0x0000 }, // ?CreateLight@agiPipeline@@UAEPAVagiLight@@XZ
    { 0x555B30, 0xC26CD503, 0x0000 }, // ?CreateLightModel@agiPipeline@@UAEPAVagiLightModel@@XZ
    { 0x555B40, 0xC6B495DA, 0x0000 }, // ?BeginAllGfx@agiPipeline@@QAEHXZ
    { 0x555C40, 0x8EC2C44A, 0x0000 }, // ?EndAllGfx@agiPipeline@@QAEXXZ
    { 0x555CD0, 0x6AF8D604, 0x0000 }, // ?RestoreAll@agiPipeline@@QAEXXZ
    { 0x555D10, 0xA33EF6EE, 0x0000 }, // ?BeginFrame@agiPipeline@@UAEXXZ
    { 0x555D30, 0x80B041BE, 0x0000 }, // ?CreateBitmap@agiPipeline@@UAEPAVagiBitmap@@XZ
    { 0x555D40, 0x91D6BEAC, 0x0000 }, // ?CopyBitmap@agiPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    { 0x555D50, 0x7D19C9B5, 0x0000 }, // ?CopyClippedBitmap@agiPipeline@@QAEHHHPAVagiBitmap@@HHHH@Z
    { 0x555D90, 0x442CAFB8, 0x0000 }, // ?CopyClippedBitmap@agiPipeline@@QAEHHHPAVagiBitmap@@HHHHHHHH@Z
    { 0x555E40, 0x968AA399, 0x0000 }, // ?NotifyNew@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    { 0x555E70, 0xEA6E2342, 0x0000 }, // ?NotifyDelete@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    { 0x555EB0, 0x52096C77, 0x0000 }, // ?ValidateObject@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    { 0x555F00, 0x50F56480, 0x0000 }, // ?DumpStatus@agiPipeline@@QAEXXZ
    { 0x555F70, 0xC3F85708, 0x0000 }, // ?GetRootWindow@@YAPAXXZ
    { 0x555F80, 0x10A6A4E1, 0x0000 }, // ?CreatePipelineAttachableWindow@@YAPAXPADHHHHPAX@Z
    { 0x555F90, 0x79AFBE7C, 0x0000 }, // ?DestroyPipelineAttachableWindow@@YAXXZ
    { 0x555FA0, 0x6C302604, 0x0000 }, // ??1agiPipeline@@UAE@XZ
    { 0x556000, 0x0A2ADF7E, 0x0000 }, // ?BeginScene@agiPipeline@@UAEXXZ
    { 0x556020, 0x77175C2E, 0x0000 }, // ?EndScene@agiPipeline@@UAEXXZ
    { 0x556030, 0x1E9BC80F, 0x0000 }, // ?EndFrame@agiPipeline@@UAEXXZ
    { 0x556040, 0xA02AC8F4, 0x0000 }, // ?LockFrameBuffer@agiPipeline@@UAEHAAVagiSurfaceDesc@@@Z
    { 0x556050, 0xC44469C0, 0x0000 }, // ?UnlockFrameBuffer@agiPipeline@@UAEXXZ
    { 0x556060, 0xACFB010D, 0x0000 }, // ?DumpStatus@agiPipeline@@UAEXAAUagiMemStatus@@@Z
    { 0x556070, 0xC972818C, 0x0000 }, // ?ClearRect@agiPipeline@@UAEXHHHHI@Z
    { 0x556080, 0x31584642, 0x0000 }, // ?Defragment@agiPipeline@@UAEXXZ
    { 0x556100, 0xF6091108, 0x0000 }, // ??0agiTexParameters@@QAE@XZ
    { 0x556120, 0x0E4B3ED5, 0x0000 }, // ?Load@agiTexParameters@@QAEXPAVStream@@@Z
    { 0x556170, 0x4CCC8984, 0x0000 }, // ?Save@agiTexParameters@@QAEXPAVStream@@@Z
    { 0x5561C0, 0x438A40C5, 0x0000 }, // ??0agiTexDef@@IAE@PAVagiPipeline@@@Z
    { 0x556230, 0xB07D1AE1, 0x0000 }, // ??1agiTexDef@@MAE@XZ
    { 0x5562F0, 0xCA268BAA, 0x0000 }, // ?CheckSurface@agiTexDef@@QAEXXZ
    { 0x556310, 0x16B1C039, 0x0000 }, // ?Reload@agiTexDef@@QAEHXZ
    { 0x556380, 0x97C3B2B8, 0x0000 }, // ?Init@agiTexDef@@QAEHABVagiTexParameters@@@Z
    { 0x556400, 0xDE53A9B5, 0x0000 }, // ?GetName@agiTexDef@@UAEPADXZ
    { 0x556430, 0x1240090E, 0x0000 }, // ?IsTexture@agiTexDef@@UAEHXZ
    { 0x556440, 0x96703B04, 0x0000 }, // ?Lock@agiTexDef@@UAEHAAUagiTexLock@@@Z
    { 0x556450, 0x1CFEAE18, 0x0000 }, // ?Unlock@agiTexDef@@UAEXAAUagiTexLock@@@Z
    { 0x556460, 0xF41C88EB, 0x0000 }, // ?PageOutCallback@agiTexDef@@SAXPAXH@Z
    { 0x5564A0, 0x425AC1C6, 0x0000 }, // ?UpdateLutQueue@@YAXXZ
    { 0x556530, 0x827F9D4F, 0x0000 }, // ?ShutdownLutQueue@@YAXXZ
    { 0x556550, 0x0A29DE87, 0x0000 }, // ?DoPageIn@agiTexDef@@QAEXXZ
    { 0x5566A0, 0x9729EB1D, 0x0000 }, // ?PageInCallback@agiTexDef@@SAXPAX@Z
    { 0x5566B0, 0xDF490143, 0x0000 }, // ?PageInSurface@agiTexDef@@QAEXXZ
    { 0x556770, 0xC3FA7CFF, 0x0000 }, // ?LockSurfaceIfResident@agiTexDef@@QAEHXZ
    { 0x5567A0, 0x8B81FB05, 0x0000 }, // ?UnlockSurface@agiTexDef@@QAEXXZ
    { 0x5567C0, 0x0C3E6309, 0x0000 }, // ?UnlockAndFreeSurface@agiTexDef@@QAEXXZ
    { 0x5567E0, 0xC537561D, 0x0000 }, // ?Request@agiTexDef@@UAEXXZ
    { 0x5567F0, 0x17FDFD4E, 0x0000 }, // ?IsAvailable@agiTexDef@@UAEHXZ
    { 0x556800, 0x16CA8F6C, 0x0000 }, // ?Init@agiTexLut@@QAEHPAD@Z
    { 0x5568D0, 0xED1FF3FD, 0x0000 }, // ?GetName@agiTexLut@@UAEPADXZ
    { 0x5568F0, 0xFD952D96, 0x0000 }, // ??0agiTexLut@@IAE@PAVagiPipeline@@@Z
    { 0x556920, 0xDA57EB7B, 0x0000 }, // ??1agiTexLut@@MAE@XZ
    { 0x5569D0, 0x9EF1DAD3, 0x0000 }, // ?OutOfDate@@YAHPAD0@Z
    { 0x556A30, 0x6A789589, 0x0000 }, // ?CheckLibraries@@YAXXZ
    { 0x556AD0, 0xB13C2E69, 0x0000 }, // ?LibOutOfDate@@YAHPAD0@Z
    { 0x556B60, 0x3FDB5265, 0x0000 }, // ?GetDLPTemplate@@YAPAVDLPTemplate@@PAD@Z
    { 0x556DF0, 0xD96F3F54, 0x0000 }, // ?GetGroupVerts@@YAHPAD0PAVVector3@@H@Z
    { 0x556F90, 0x534EE021, 0x0000 }, // ?Load@agiPhysParameters@@QAEXPAVStream@@@Z
    { 0x557040, 0x152E14DC, 0x0000 }, // ?Save@agiPhysParameters@@QAEXPAVStream@@@Z
    { 0x557120, 0x37E9111D, 0x0000 }, // ??0?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAE@XZ
    { 0x557150, 0xE8C0119F, 0x0000 }, // ??1?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAE@XZ
    { 0x5571D0, 0x4DC26A94, 0x0000 }, // ??0agiViewParameters@@QAE@XZ
    { 0x557240, 0x3F6D3ECA, 0x0000 }, // ?Perspective@agiViewParameters@@QAEXMMMM@Z
    { 0x557310, 0x688A517E, 0x0000 }, // ?Ortho@agiViewParameters@@QAEXMMMM@Z
    { 0x5573B0, 0x5CC2AD61, 0x0000 }, // ?Frustum@agiViewParameters@@QAEXMMMMMM@Z
    { 0x557490, 0x63551ABD, 0x0000 }, // ?SphereVisible@agiViewParameters@@QAEHAAVVector3@@M@Z
    { 0x557590, 0x71CF7C9A, 0x0000 }, // ?SetBill@agiViewParameters@@QAEXAAVVector3@@@Z
    { 0x5576D0, 0xEA1E7D96, 0x0000 }, // ?SetBillY@agiViewParameters@@QAEXAAVMatrix34@@@Z
    { 0x557870, 0xFFC51EAD, 0x0000 }, // ?Aspect@agiViewport@@QAEMXZ
    { 0x5578A0, 0x71C14E72, 0x0000 }, // ?SetWorld@agiViewport@@UAEXAAVMatrix34@@@Z
    { 0x5578E0, 0x27AB8EB6, 0x0000 }, // ??0agiViewport@@IAE@PAVagiPipeline@@@Z
    { 0x557940, 0x7E2372C0, 0x0000 }, // ??1agiViewport@@MAE@XZ
    { 0x557960, 0xB69751A2, 0x0000 }, // ?Project@agiViewParameters@@QAEXAAVVector3@@0@Z
    { 0x5579D0, 0xBF370E64, 0x0000 }, // ?GetName@agiViewport@@UAEPADXZ
    { 0x557A20, 0xF4A205CA, 0x0000 }, // ??0agiRefreshable@@QAE@PAVagiPipeline@@@Z
    { 0x557A60, 0x35737214, 0x0000 }, // ??1agiRefreshable@@MAE@XZ
    { 0x557AA0, 0x1F59E2E1, 0x0000 }, // ?SafeBeginGfx@agiRefreshable@@QAEHXZ
    { 0x557AD0, 0x3FFAFFE2, 0x0000 }, // ?Restore@agiRefreshable@@UAEXXZ
    { 0x557AE0, 0x74AC4B28, 0x0000 }, // ?AddRef@agiRefreshable@@QAEXXZ
    { 0x557B00, 0xA58CD6CC, 0x0000 }, // ?Release@agiRefreshable@@QAEHXZ
    { 0x557B30, 0x40EA6712, 0x0000 }, // ?ValidatePtr@agiRefreshable@@AAEXPAD@Z
    { 0x557B90, 0x8FDE6AA5, 0x0000 }, // ?GetName@agiRefreshable@@UAEPADXZ
    { 0x557BA0, 0x077CB944, 0x0000 }, // ?IsTexture@agiRefreshable@@MAEHXZ
    { 0x557BE0, 0x702804E6, 0x0000 }, // ??0agiRasterizer@@QAE@PAVagiPipeline@@@Z
    { 0x557CE0, 0x867CD042, 0x0000 }, // ?Reset@agiRendStateStruct@@QAEXXZ
    { 0x557D10, 0x3CACD8A5, 0x0000 }, // ??1agiRasterizer@@UAE@XZ
    { 0x557D20, 0x3E142E1E, 0x0000 }, // ?BeginGroup@agiRasterizer@@UAEXXZ
    { 0x557D30, 0x90DB6C83, 0x0000 }, // ?EndGroup@agiRasterizer@@UAEXXZ
    { 0x557D40, 0x287D023E, 0x0000 }, // ?Quad@agiRasterizer@@UAEXHHHH@Z
    { 0x557D70, 0xB0EE1778, 0x0000 }, // ?Poly@agiRasterizer@@UAEXPAHH@Z
    { 0x557DB0, 0x82878A61, 0x0000 }, // ?Mesh2@agiRasterizer@@UAEXPAUagiScreenVtx2@@HPAGH@Z
    { 0x557DD0, 0x9201615B, 0x0000 }, // ?LineList@agiRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    { 0x557E70, 0xB412F54B, 0x0000 }, // ?agiPrint@@YAXHHHPBD@Z
    { 0x557E90, 0x275430D3, 0x0000 }, // ?agiPrintf@@YAXHHHPBDZZ
    { 0x557EF0, 0x6F55543D, 0x0000 }, // ?agiPrintIs3D@@YAHXZ
    { 0x557F00, 0xA82EC01B, 0x0000 }, // ?agiPrintInit@@YAXXZ
    { 0x557F10, 0x3A65584C, 0x0000 }, // ?agiPrintShutdown@@YAXXZ
    { 0x557F20, 0xE248E38A, 0x0000 }, // ?Print@agiPipeline@@UAEXHHHPBD@Z
    { 0x557FE0, 0x293468E2, 0x0000 }, // ?InitBuiltin@@YAXXZ
    { 0x558110, 0xA7FEE600, 0x0000 }, // ?PrintIs3D@agiPipeline@@UAEHXZ
    { 0x558130, 0x0644E4CE, 0x0000 }, // ?PrintInit@agiPipeline@@UAEXXZ
    { 0x558140, 0x1FCFB228, 0x0000 }, // ?PrintShutdown@agiPipeline@@UAEXXZ
    { 0x5581A0, 0x4EEF1E45, 0x0000 }, // ??0?$agiLib@VagiTexParameters@@VagiTexDef@@@@QAE@XZ
    { 0x5581D0, 0x68C8C526, 0x0000 }, // ??1?$agiLib@VagiTexParameters@@VagiTexDef@@@@QAE@XZ
    { 0x5582E0, 0x00C7651C, 0x0000 }, // ??0DLPTemplate@@QAE@PAD@Z
    { 0x558330, 0x7C1C86BA, 0x0000 }, // ??1DLPTemplate@@AAE@XZ
    { 0x5583D0, 0xF0C20FC8, 0x0000 }, // ?Init@DLPTemplate@@QAEXHHH@Z
    { 0x558500, 0xA2B593DF, 0x0000 }, // ?Save@DLPTemplate@@QAEXPAVStream@@@Z
    { 0x558640, 0xEA3B714C, 0x0000 }, // ?Load@DLPTemplate@@QAEXPAVStream@@@Z
    { 0x558990, 0xC8AB33B8, 0x0000 }, // ?GetProp@DLPPatch@@QAEPADPAD@Z
    { 0x558A40, 0x8DA7274D, 0x0000 }, // ?InitRemap@DLPTemplate@@QAEXAAV?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@AAV?$agiLib@VagiTexParameters@@VagiTexDef@@@@AAV?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@@Z
    { 0x558B60, 0xC5F63AA0, 0x0000 }, // ?Load@DLPTemplate@@QAEHPAD@Z
    { 0x558BA0, 0xE39FA960, 0x0000 }, // ?Print@DLPTemplate@@QAEXPAVStream@@@Z
    { 0x558C90, 0xB27C70C8, 0x0000 }, // ??0DLPGroup@@QAE@XZ
    { 0x558CB0, 0x129043E2, 0x0000 }, // ??0DLPGroup@@QAE@PAVDLPTemplate@@PAV0@@Z
    { 0x558E90, 0xF5931D36, 0x0000 }, // ??1DLPGroup@@QAE@XZ
    { 0x558EC0, 0xD8DF9CD7, 0x0000 }, // ?Load@DLPGroup@@QAEXPAVStream@@@Z
    { 0x558F40, 0x62B2220F, 0x0000 }, // ?Save@DLPGroup@@QAEXPAVStream@@@Z
    { 0x558FC0, 0x1E595708, 0x0000 }, // ?Print@DLPGroup@@QAEXPAVStream@@@Z
    { 0x559040, 0xF2C8B6B2, 0x0000 }, // ?Init@DLPGroup@@QAEXHH@Z
    { 0x559080, 0xD940EAA0, 0x0000 }, // ?Load@DLPPatch@@QAEXPAVStream@@@Z
    { 0x559180, 0x2A762C62, 0x0000 }, // ?Save@DLPPatch@@QAEXPAVStream@@@Z
    { 0x559250, 0xFBA7E047, 0x0000 }, // ?Print@DLPPatch@@QAEXPAVStream@@@Z
    { 0x559310, 0xA77978BD, 0x0000 }, // ?UnpackAngle@@YAME@Z
    { 0x559340, 0x4CE6D3FF, 0x0000 }, // ?UnpackNormal@@YAXAAVVector3@@AAG@Z
    { 0x5593A0, 0xBE44C9EC, 0x0000 }, // ?PackAngle@@YAIM@Z
    { 0x559400, 0x91B4845E, 0x0000 }, // ?PackNormal@@YAXAAGAAVVector3@@@Z
    { 0x5594D0, 0x5E231CC9, 0x0000 }, // ?Load@DLPVertex@@QAEXPAVStream@@@Z
    { 0x5595A0, 0x476FEA55, 0x0000 }, // ?Save@DLPVertex@@QAEXPAVStream@@@Z
    { 0x559630, 0x5BD1972E, 0x0000 }, // ?GroupExists@DLPTemplate@@QAEPAVDLPGroup@@PAD@Z
    { 0x5596B0, 0xAF72D1A3, 0x0000 }, // ?Restrict@DLPTemplate@@QAEHPAD@Z
    { 0x5597C0, 0x12FD62DA, 0x0000 }, // ?AddRef@DLPTemplate@@QAEXXZ
    { 0x5597D0, 0x805F96DC, 0x0000 }, // ?Release@DLPTemplate@@QAEHXZ
    { 0x559800, 0xD81A58F9, 0x0000 }, // ?GetVertexCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z
    { 0x559930, 0x75244B09, 0x0000 }, // ?GetCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z
    { 0x5599B0, 0x55D8FB0A, 0x0000 }, // ?GetGroupVertex@DLPTemplate@@QAEPAVVector3@@PAD@Z
    { 0x559A00, 0x36970347, 0x0000 }, // ?BoundBox@DLPTemplate@@QAEHAAVVector3@@0PAD@Z
    { 0x559CF0, 0xAD4E2BD8, 0x0000 }, // ??1?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAE@XZ
    { 0x559D90, 0xE016CBF5, 0x0000 }, // ?Add@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEHAAVagiMtlParameters@@@Z
    { 0x559EF0, 0xB8ACC5AC, 0x0000 }, // ?Add@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEHAAVagiPhysParameters@@@Z
    { 0x55A030, 0x80F611FC, 0x0000 }, // ?Kill@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEXXZ
    { 0x55A080, 0xA4FD35CB, 0x0000 }, // ?Init@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEXH@Z
    { 0x55A140, 0x2312BDBE, 0x0000 }, // ?Kill@?$agiLib@VagiTexParameters@@VagiTexDef@@@@QAEXXZ
    { 0x55A190, 0xDCE58C8E, 0x0000 }, // ?Init@?$agiLib@VagiTexParameters@@VagiTexDef@@@@QAEXH@Z
    { 0x55A250, 0x4C2CB4CE, 0x0000 }, // ?Kill@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEXXZ
    { 0x55A290, 0xFDEA785F, 0x0000 }, // ?Init@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEXH@Z
    { 0x55A310, 0xB607438A, 0x0000 }, // ??0DLPPatch@@QAE@XZ
    { 0x55A320, 0xE7D8A17D, 0x0000 }, // ??1DLPPatch@@QAE@XZ
    { 0x55A3B0, 0x1ABC272D, 0x0000 }, // ??0agiBitmap@@QAE@PAVagiPipeline@@@Z
    { 0x55A3F0, 0xDDB5A1DD, 0x0000 }, // ?Init@agiBitmap@@QAEHPADMMH@Z
    { 0x55A600, 0x7A861479, 0x0000 }, // ?SetTransparency@agiBitmap@@QAEXH@Z
    { 0x55A630, 0x6BD5E2FB, 0x0000 }, // ?UpdateFlags@agiBitmap@@UAEXXZ
    { 0x55A640, 0x3907C5D9, 0x0000 }, // ??1agiBitmap@@MAE@XZ
    { 0x55A6D0, 0xFF381FEA, 0x0000 }, // ?GetName@agiBitmap@@UAEPADXZ
    { 0x55A720, 0xF4320401, 0x0000 }, // ?Init@agiSurfaceDesc@@SAPAV1@HHAAV1@@Z
    { 0x55A7A0, 0x7358B62E, 0x0000 }, // ?Load@agiSurfaceDesc@@SAPAV1@PAD0HHHH@Z
    { 0x55AAE0, 0xA696E778, 0x0000 }, // ?RescaleJpeg@@YAXIIPAEAAUjpeg_decompress_struct@@@Z
    { 0x55ADE0, 0x8E2D2E51, 0x0000 }, // ?Reload@agiSurfaceDesc@@QAEXPAD0HHPAVStream@@HH@Z
    { 0x55B160, 0xA4F58E08, 0x0000 }, // ?Unload@agiSurfaceDesc@@QAEXXZ
    { 0x55B180, 0x5975CEDF, 0x0000 }, // ?CopyFrom@agiSurfaceDesc@@QAEXPAV1@H@Z
    { 0x55B510, 0xAEA028A7, 0x0000 }, // ?copyrow565_to_555@@YAXPAX0II@Z
    { 0x55B560, 0x5486A6E6, 0x0000 }, // ?copyrow565_to_5551@@YAXPAX0II@Z
    { 0x55B5C0, 0xCFC40D8E, 0x0000 }, // ?copyrow565_to_888@@YAXPAX0II@Z
    { 0x55B640, 0x31E333EB, 0x0000 }, // ?copyrow565_to_888rev@@YAXPAX0II@Z
    { 0x55B6C0, 0xE85E41AA, 0x0000 }, // ?copyrow4444_to_8888@@YAXPAX0II@Z
    { 0x55B750, 0x7CBE2361, 0x0000 }, // ?copyrow4444_to_8888rev@@YAXPAX0II@Z
    { 0x55B7E0, 0x7CEB78F4, 0x0000 }, // ?copyrow4444_to_555@@YAXPAX0II@Z
    { 0x55B860, 0x12BB49CB, 0x0000 }, // ?copyrow4444_to_565@@YAXPAX0II@Z
    { 0x55B8E0, 0x9B4EFB51, 0x0000 }, // ?copyrow4444_to_5551@@YAXPAX0II@Z
    { 0x55B9B0, 0x144B95AF, 0x0000 }, // ??0?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAE@XZ
    { 0x55B9E0, 0xD576266A, 0x0000 }, // ??0agiLightParameters@@QAE@XZ
    { 0x55BA60, 0x88ADDF2F, 0x0000 }, // ??4agiLightParameters@@QAEXABV0@@Z
    { 0x55BA80, 0xE428E20A, 0x0000 }, // ??0agiLight@@QAE@PAVagiPipeline@@@Z
    { 0x55BAD0, 0xAFA3C8A4, 0x0000 }, // ?Init@agiLight@@QAEHABVagiLightParameters@@@Z
    { 0x55BB00, 0x74B5E67B, 0x0000 }, // ?Remove@agiLight@@UAEXXZ
    { 0x55BB10, 0x8543C785, 0x0000 }, // ??1agiLight@@UAE@XZ
    { 0x55BB20, 0xC384280A, 0x0000 }, // ?GetName@agiLight@@UAEPADXZ
    { 0x55BB70, 0xED261935, 0x0000 }, // ??1agiColorModel@@MAE@XZ
    { 0x55BB80, 0x657ED8D9, 0x0000 }, // ?GetColor@agiColorModel@@QAEIHHHH@Z
    { 0x55BBB0, 0xA9B1A451, 0x0000 }, // ?FindColor@agiColorModel@@QAEIHHHH@Z
    { 0x55BBE0, 0x3FBCFCA6, 0x0000 }, // ?GetColor@agiColorModel@@QAEIABVVector3@@@Z
    { 0x55BC40, 0x58B310E6, 0x0000 }, // ?GetColor@agiColorModel@@QAEIABVVector4@@@Z
    { 0x55BCA0, 0xAF0EE29F, 0x0000 }, // ??0agiLightModelParameters@@QAE@XZ
    { 0x55BCD0, 0xA3C1927C, 0x0000 }, // ??4agiLightModelParameters@@QAEXABV0@@Z
    { 0x55BCF0, 0x8748C542, 0x0000 }, // ??1agiLightModelParameters@@QAE@XZ
    { 0x55BD00, 0x8DC378C2, 0x0000 }, // ??0agiLightModel@@IAE@PAVagiPipeline@@@Z
    { 0x55BD50, 0x32B8EE58, 0x0000 }, // ?Init@agiLightModel@@QAEHABVagiLightModelParameters@@@Z
    { 0x55BD80, 0x5CEE06CD, 0x0000 }, // ??1agiLightModel@@UAE@XZ
    { 0x55BDD0, 0xDAE11F82, 0x0000 }, // ?GetName@agiLightModel@@UAEPADXZ
    { 0x55BE20, 0x0F06FAEA, 0x0000 }, // ?agiGetError@@YAPADH@Z
    { 0x55BE80, 0xAC0536C5, 0x0000 }, // ?agiDisplayf@@YAXPBDZZ
    { 0x55BEB0, 0xAC6B398B, 0x0000 }, // ??0agiColorModel8@@QAE@PAVagiPalette@@@Z
    { 0x55BF00, 0x59069F8E, 0x0000 }, // ??1agiColorModel8@@UAE@XZ
    { 0x55BF10, 0x6033A616, 0x0000 }, // ?GetColor@agiColorModel8@@UAEIUagiRgba@@@Z
    { 0x55BF30, 0x56943DBC, 0x0000 }, // ?FindColor@agiColorModel8@@UAEIUagiRgba@@@Z
    { 0x55BF50, 0x10C262D6, 0x0000 }, // ?Filter@agiColorModel8@@UAEIIIII@Z
    { 0x55C000, 0x3641BCED, 0x0000 }, // ?GetPixel@agiColorModel8@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55C020, 0x07118E8A, 0x0000 }, // ?SetPixel@agiColorModel8@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55C090, 0xCF60A64F, 0x0000 }, // ??0agiPalette@@QAE@XZ
    { 0x55C0B0, 0x434DEBED, 0x0000 }, // ?Kill@agiPalette@@QAEXXZ
    { 0x55C0F0, 0x43616609, 0x0000 }, // ?Cube@agiPalette@@QAEXXZ
    { 0x55C180, 0x2450853E, 0x0000 }, // ?Load@agiPalette@@QAEXPAD@Z
    { 0x55C310, 0xF4FED20A, 0x0000 }, // ?GetColor@agiPalette@@QAEIUagiRgba@@@Z
    { 0x55C3A0, 0x25059EEF, 0x0000 }, // ?FindColor@agiPalette@@QAEIUagiRgba@@@Z
    { 0x55C4A0, 0xCC7F2E00, 0x0000 }, // ??0agiColorModelRGB555@@QAE@XZ
    { 0x55C4E0, 0xBA993C80, 0x0000 }, // ?GetColor@agiColorModelRGB555@@UAEIUagiRgba@@@Z
    { 0x55C520, 0x8A8B202C, 0x0000 }, // ?FindColor@agiColorModelRGB555@@UAEIUagiRgba@@@Z
    { 0x55C560, 0x883002E3, 0x0000 }, // ?Filter@agiColorModelRGB555@@UAEIIIII@Z
    { 0x55C5F0, 0x65C0DAD0, 0x0000 }, // ?GetPixel@agiColorModelRGB555@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55C610, 0x21F2B4EF, 0x0000 }, // ?SetPixel@agiColorModelRGB555@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55C680, 0x490A4E0F, 0x0000 }, // ??0agiColorModelRGB565@@QAE@XZ
    { 0x55C6C0, 0x21924793, 0x0000 }, // ?GetColor@agiColorModelRGB565@@UAEIUagiRgba@@@Z
    { 0x55C700, 0xC71803CA, 0x0000 }, // ?FindColor@agiColorModelRGB565@@UAEIUagiRgba@@@Z
    { 0x55C740, 0x1D742728, 0x0000 }, // ?Filter@agiColorModelRGB565@@UAEIIIII@Z
    { 0x55C7D0, 0xBE2B1A72, 0x0000 }, // ?GetPixel@agiColorModelRGB565@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55C7F0, 0x0FE32A5C, 0x0000 }, // ?SetPixel@agiColorModelRGB565@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55C860, 0xBBC2E686, 0x0000 }, // ??0agiColorModelRGB555_Rev@@QAE@XZ
    { 0x55C8A0, 0x4E8CF9CB, 0x0000 }, // ?GetColor@agiColorModelRGB555_Rev@@UAEIUagiRgba@@@Z
    { 0x55C8E0, 0x743603DE, 0x0000 }, // ?FindColor@agiColorModelRGB555_Rev@@UAEIUagiRgba@@@Z
    { 0x55C920, 0xEAE098FB, 0x0000 }, // ?Filter@agiColorModelRGB555_Rev@@UAEIIIII@Z
    { 0x55C9B0, 0xFD5742F5, 0x0000 }, // ?GetPixel@agiColorModelRGB555_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55C9D0, 0xE512B1F5, 0x0000 }, // ?SetPixel@agiColorModelRGB555_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55CA40, 0x79FC77EB, 0x0000 }, // ??0agiColorModelRGB565_Rev@@QAE@XZ
    { 0x55CA80, 0x1A967D95, 0x0000 }, // ?GetColor@agiColorModelRGB565_Rev@@UAEIUagiRgba@@@Z
    { 0x55CAC0, 0xEAADA78B, 0x0000 }, // ?FindColor@agiColorModelRGB565_Rev@@UAEIUagiRgba@@@Z
    { 0x55CB00, 0x2AA5D6B5, 0x0000 }, // ?Filter@agiColorModelRGB565_Rev@@UAEIIIII@Z
    { 0x55CB90, 0x7D3DFAA3, 0x0000 }, // ?GetPixel@agiColorModelRGB565_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55CBB0, 0xAC330A20, 0x0000 }, // ?SetPixel@agiColorModelRGB565_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55CC20, 0x24A89C7B, 0x0000 }, // ??0agiColorModelRGB888@@QAE@XZ
    { 0x55CC60, 0x3962902A, 0x0000 }, // ?GetColor@agiColorModelRGB888@@UAEIUagiRgba@@@Z
    { 0x55CC90, 0x6668DB69, 0x0000 }, // ?FindColor@agiColorModelRGB888@@UAEIUagiRgba@@@Z
    { 0x55CCC0, 0xA85B2E42, 0x0000 }, // ?Filter@agiColorModelRGB888@@UAEIIIII@Z
    { 0x55CD40, 0xFC0F64C3, 0x0000 }, // ?GetPixel@agiColorModelRGB888@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55CD60, 0x7342A663, 0x0000 }, // ?SetPixel@agiColorModelRGB888@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55CDC0, 0x7AD0798A, 0x0000 }, // ??0agiColorModelRGB888_Rev@@QAE@XZ
    { 0x55CE00, 0xB3E39C55, 0x0000 }, // ?GetColor@agiColorModelRGB888_Rev@@UAEIUagiRgba@@@Z
    { 0x55CE30, 0xA4351790, 0x0000 }, // ?FindColor@agiColorModelRGB888_Rev@@UAEIUagiRgba@@@Z
    { 0x55CE60, 0x7F78A4BB, 0x0000 }, // ?Filter@agiColorModelRGB888_Rev@@UAEIIIII@Z
    { 0x55CEE0, 0x9A67EE59, 0x0000 }, // ?GetPixel@agiColorModelRGB888_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55CF00, 0xF504DE5B, 0x0000 }, // ?SetPixel@agiColorModelRGB888_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55CF60, 0xE5081224, 0x0000 }, // ??0agiColorModelRGBA5551@@QAE@XZ
    { 0x55CFB0, 0xFA464DAD, 0x0000 }, // ?GetColor@agiColorModelRGBA5551@@UAEIUagiRgba@@@Z
    { 0x55D000, 0x9E1DDBD6, 0x0000 }, // ?FindColor@agiColorModelRGBA5551@@UAEIUagiRgba@@@Z
    { 0x55D050, 0x4C6B81AE, 0x0000 }, // ?Filter@agiColorModelRGBA5551@@UAEIIIII@Z
    { 0x55D110, 0x9ECC14EF, 0x0000 }, // ?GetPixel@agiColorModelRGBA5551@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55D130, 0xBE5A7FE3, 0x0000 }, // ?SetPixel@agiColorModelRGBA5551@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55D1A0, 0x8DB8C016, 0x0000 }, // ??0agiColorModelRGBA4444@@QAE@XZ
    { 0x55D1E0, 0x9417C586, 0x0000 }, // ?GetColor@agiColorModelRGBA4444@@UAEIUagiRgba@@@Z
    { 0x55D230, 0x29C01A33, 0x0000 }, // ?FindColor@agiColorModelRGBA4444@@UAEIUagiRgba@@@Z
    { 0x55D280, 0xC469B7CA, 0x0000 }, // ?Filter@agiColorModelRGBA4444@@UAEIIIII@Z
    { 0x55D340, 0x90A33149, 0x0000 }, // ?GetPixel@agiColorModelRGBA4444@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55D360, 0xBF997A80, 0x0000 }, // ?SetPixel@agiColorModelRGBA4444@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55D3D0, 0x769FA984, 0x0000 }, // ??0agiColorModelARGB@@QAE@XZ
    { 0x55D410, 0xD57D5864, 0x0000 }, // ?GetColor@agiColorModelARGB@@UAEIUagiRgba@@@Z
    { 0x55D450, 0x296D21A5, 0x0000 }, // ?FindColor@agiColorModelARGB@@UAEIUagiRgba@@@Z
    { 0x55D490, 0xB51C942F, 0x0000 }, // ?Filter@agiColorModelARGB@@UAEIIIII@Z
    { 0x55D530, 0x6B5CE6B0, 0x0000 }, // ?GetPixel@agiColorModelARGB@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55D550, 0x5E9F10B0, 0x0000 }, // ?SetPixel@agiColorModelARGB@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55D5B0, 0xD21F8647, 0x0000 }, // ??0agiColorModelABGR@@QAE@XZ
    { 0x55D5F0, 0x8EF7AF0B, 0x0000 }, // ?GetColor@agiColorModelABGR@@UAEIUagiRgba@@@Z
    { 0x55D630, 0x7E8C5204, 0x0000 }, // ?FindColor@agiColorModelABGR@@UAEIUagiRgba@@@Z
    { 0x55D670, 0x409498B2, 0x0000 }, // ?Filter@agiColorModelABGR@@UAEIIIII@Z
    { 0x55D720, 0x18AA51F6, 0x0000 }, // ?GetPixel@agiColorModelABGR@@UAEIPAVagiSurfaceDesc@@HH@Z
    { 0x55D740, 0xFFDCF1CF, 0x0000 }, // ?SetPixel@agiColorModelABGR@@UAEXPAVagiSurfaceDesc@@HHI@Z
    { 0x55D760, 0x52FD4CBA, 0x0000 }, // ?FindMatch@agiColorModel@@SAPAV1@HHHH@Z
    { 0x55D810, 0x6E2C4AA4, 0x0000 }, // ?FindMatch@agiColorModel@@SAPAV1@PAVagiSurfaceDesc@@@Z
    { 0x55D830, 0xB6EA25B5, 0x0000 }, // ??1agiColorModelRGB555@@UAE@XZ
    { 0x55D870, 0x31D0A42F, 0x0000 }, // ??1agiColorModelRGB565@@UAE@XZ
    { 0x55D8B0, 0x549C831D, 0x0000 }, // ??1agiColorModelRGB555_Rev@@UAE@XZ
    { 0x55D8F0, 0x5006806C, 0x0000 }, // ??1agiColorModelRGB565_Rev@@UAE@XZ
    { 0x55D930, 0x23163D7F, 0x0000 }, // ??1agiColorModelRGB888@@UAE@XZ
    { 0x55D970, 0x04E4BEB0, 0x0000 }, // ??1agiColorModelRGB888_Rev@@UAE@XZ
    { 0x55D9B0, 0x1F9877B4, 0x0000 }, // ??1agiColorModelRGBA5551@@UAE@XZ
    { 0x55D9F0, 0x5952C9A6, 0x0000 }, // ??1agiColorModelRGBA4444@@UAE@XZ
    { 0x55DA30, 0x38B88BE2, 0x0000 }, // ??1agiColorModelARGB@@UAE@XZ
    { 0x55DA70, 0xB8E44CE8, 0x0000 }, // ??1agiColorModelABGR@@UAE@XZ
    { 0x55DAB0, 0xD29BDD31, 0x0000 }, // ??0agiMtlParameters@@QAE@XZ
    { 0x55DB00, 0x8A20C421, 0x0000 }, // ?Load@agiMtlParameters@@QAEXPAVStream@@@Z
    { 0x55DB70, 0xA104B338, 0x0000 }, // ?Save@agiMtlParameters@@QAEXPAVStream@@@Z
    { 0x55DBE0, 0x6936A680, 0x0000 }, // ??4agiMtlParameters@@QAEXABV0@@Z
    { 0x55DC00, 0xDA90319E, 0x0000 }, // ??0agiMtlDef@@IAE@PAVagiPipeline@@@Z
    { 0x55DC50, 0xEB99B70F, 0x0000 }, // ?Init@agiMtlDef@@QAEHABVagiMtlParameters@@@Z
    { 0x55DC80, 0x1207ED2B, 0x0000 }, // ??1agiMtlDef@@MAE@XZ
    { 0x55DD30, 0x0CC6F1A5, 0x0000 }, // ?GetName@agiMtlDef@@UAEPADXZ
    { 0x55DD80, 0x984C390A, 0x0000 }, // ??0agiRenderer@@QAE@XZ
    { 0x55DE90, 0xC693DED6, 0x0000 }, // ??0DLP@@QAE@PAVagiPipeline@@@Z
    { 0x55DEF0, 0x88F2072F, 0x0000 }, // ??1DLP@@UAE@XZ
    { 0x55E000, 0x1FA32BC1, 0x0000 }, // ?FixTemplateRefs@DLP@@IAEXH@Z
    { 0x55E0D0, 0x54C79134, 0x0000 }, // ?BeginGfx@DLP@@UAEHXZ
    { 0x55E2F0, 0x0C7C306D, 0x0000 }, // ?EndGfx@DLP@@UAEXXZ
    { 0x55E300, 0x6D7BD67C, 0x0000 }, // ?Init@DLP@@QAEHPAD0PAVVector3@@@Z
    { 0x55E380, 0x83C42794, 0x0000 }, // ?Init@DLP@@QAEHPAVDLPTemplate@@PADPAVVector3@@@Z
    { 0x55E460, 0xDAF90FE8, 0x0000 }, // ?Clone@DLP@@QAEPAV1@XZ
    { 0x55E490, 0x3C584EFB, 0x0000 }, // ?Cull@DLP@@UAEXH@Z
    { 0x55E4F0, 0x0E0944E6, 0x0000 }, // ?GetName@DLP@@UAEPADXZ
    { 0x55E530, 0x2AB4060E, 0x0000 }, // ?FixROpts@DLP@@UAEXHH@Z
    { 0x55E5B0, 0x7CBF6B3C, 0x0000 }, // ??0DynamicDLP@@QAE@H@Z
    { 0x55E5E0, 0xDD67A2EF, 0x0000 }, // ??1DynamicDLP@@MAE@XZ
    { 0x55E600, 0x1BAE6304, 0x0000 }, // ?Release@DynamicDLP@@QAEHXZ
    { 0x55E620, 0x258C7796, 0x0000 }, // ?InitOffsets@DynamicDLP@@QAEHPAVDLP@@PAD@Z
    { 0x55E8B0, 0x98056622, 0x0000 }, // ??0Stream@@QAE@PAXHPAVFileSystem@@@Z
    { 0x55E940, 0xDEBA0A08, 0x0000 }, // ??1Stream@@UAE@XZ
    { 0x55E9C0, 0x81624F06, 0x0000 }, // ?Read@Stream@@QAEHPAXH@Z
    { 0x55EB00, 0x5F1D8A9A, 0x0000 }, // ?Write@Stream@@QAEHPAXH@Z
    { 0x55EC00, 0xB37B84C4, 0x0000 }, // ?GetCh@Stream@@QAEHXZ
    { 0x55EC30, 0xC777FFFB, 0x0000 }, // ?PutCh@Stream@@QAEHE@Z
    { 0x55EC60, 0xB83065AE, 0x0000 }, // ?Seek@Stream@@QAEHH@Z
    { 0x55EC90, 0x77178516, 0x0000 }, // ?Tell@Stream@@QAEHXZ
    { 0x55ECA0, 0xFB4B05A4, 0x0000 }, // ?Size@Stream@@QAEHXZ
    { 0x55ECC0, 0xC8C2830D, 0x0000 }, // ?Flush@Stream@@QAEHXZ
    { 0x55ED30, 0x04E9E821, 0x0000 }, // ?AlignSize@Stream@@MAEHXZ
    { 0x55ED40, 0xF847B47F, 0x0000 }, // ?GetError@Stream@@MAEHPADH@Z
    { 0x55ED80, 0x489BC454, 0x0000 }, // ?GetMapping@Stream@@UAEPAXXZ
    { 0x55ED90, 0x409D3D8D, 0x0000 }, // ?GetPagerHandle@Stream@@UAEIXZ
    { 0x55EDA0, 0xFFB2F0D8, 0x0000 }, // ?GetPagingInfo@Stream@@UAEHAAI00@Z
    { 0x55EDB0, 0xD1A56927, 0x0000 }, // ?Error@Stream@@QAEXPAD@Z
    { 0x55EDF0, 0x6D662606, 0x0000 }, // ?Printf@Stream@@QAAHPBDZZ
    { 0x55EE40, 0x1A76047F, 0x0000 }, // ?Vprintf@Stream@@QAEHPBDPAD@Z
    { 0x55EE90, 0x480608B5, 0x0000 }, // ?RawDebug@Stream@@MAEXXZ
    { 0x55EEA0, 0x7B94A5E6, 0x0000 }, // ?Debug@Stream@@QAEXXZ
    { 0x55EEB0, 0xAA26BF09, 0x0000 }, // ?PutString@Stream@@QAEHPAD@Z
    { 0x55EEF0, 0x6CEBE508, 0x0000 }, // ?GetString@Stream@@QAEHPADH@Z
    { 0x55EF80, 0x724C6597, 0x0000 }, // ?Put@Stream@@QAEHE@Z
    { 0x55EFA0, 0x00BD81CC, 0x0000 }, // ?Put@Stream@@QAEHG@Z
    { 0x55EFD0, 0xE2E4E4F6, 0x0000 }, // ?Put@Stream@@QAEHK@Z
    { 0x55F020, 0x46081BC8, 0x0000 }, // ?Put@Stream@@QAEHM@Z
    { 0x55F080, 0xD5CA6AE9, 0x0000 }, // ?Put@Stream@@QAEHPAEH@Z
    { 0x55F0A0, 0xCEC0DE50, 0x0000 }, // ?Put@Stream@@QAEHPAGH@Z
    { 0x55F100, 0xC43F65F5, 0x0000 }, // ?Put@Stream@@QAEHPAKH@Z
    { 0x55F170, 0x67880187, 0x0000 }, // ?Get@Stream@@QAEHPAEH@Z
    { 0x55F190, 0x0911C783, 0x0000 }, // ?Get@Stream@@QAEHPAGH@Z
    { 0x55F1D0, 0x7E09E5C8, 0x0000 }, // ?Get@Stream@@QAEHPAKH@Z
    { 0x55F210, 0xA4D2C59E, 0x0000 }, // ?SwapShorts@Stream@@CAXPAGH@Z
    { 0x55F240, 0xF7D47599, 0x0000 }, // ?SwapLongs@Stream@@CAXPAKH@Z
    { 0x55F290, 0x5871722F, 0x0000 }, // ?GetShort@Stream@@QAEGXZ
    { 0x55F2B0, 0xA3966E9F, 0x0000 }, // ?GetLong@Stream@@QAEKXZ
    { 0x55F2D0, 0xA04DB4C1, 0x0000 }, // ?fprintf@@YAXPAVStream@@PBDZZ
    { 0x55F2F0, 0xF646B2F9, 0x0000 }, // ?fopen@@YAPAVStream@@PAD0@Z
    { 0x55F330, 0x81B6319E, 0x0000 }, // ?fseek@@YAHPAVStream@@HH@Z
    { 0x55F390, 0x22D3D4F9, 0x0000 }, // _vprintf
    { 0x55F3B0, 0x09DD0BEB, 0x0000 }, // _printf
    { 0x55F3E0, 0xB9E9B9DA, 0x0000 }, // ?fgets@@YAHPADHPAVStream@@@Z
    { 0x55F450, 0xB5BF4C7F, 0x0000 }, // ?fscanf@@YAHPAVStream@@PBDZZ
    { 0x55F530, 0xB7150C54, 0x0000 }, // ??0FileSystem@@QAE@XZ
    { 0x55F5A0, 0x1F6D8FD2, 0x0000 }, // ??1FileSystem@@UAE@XZ
    { 0x55F610, 0x11A86A90, 0x0000 }, // ?NotifyDelete@FileSystem@@MAEXXZ
    { 0x55F620, 0x0AF29D6B, 0x0000 }, // ?SearchAll@FileSystem@@SAPAV1@PAD00H0@Z
    { 0x55F690, 0xFB4529AD, 0x0000 }, // ?Search@FileSystem@@QAEHPAD00H0@Z
    { 0x55FAF0, 0x5CC85D8B, 0x0000 }, // ?SubString@@YAPADHPAD@Z
    { 0x55FB70, 0x2DF3D61E, 0x0000 }, // ?NumSubStrings@@YAHPAD@Z
    { 0x55FBA0, 0xEEC7D85E, 0x0000 }, // ?Contains@@YAHPAD0@Z
    { 0x55FC20, 0xBCE28382, 0x0000 }, // ?ExpandEnvs@@YAXPAD@Z
    { 0x55FD30, 0x8D5A8A12, 0x0000 }, // ?FindFile@@YAPAVFileSystem@@PAD00H0@Z
    { 0x55FD60, 0x11229F9C, 0x0000 }, // ?OpenFile@@YAPAVStream@@PAD00H00@Z
    { 0x55FE60, 0xB3501A66, 0x0000 }, // ?OpenAny@FileSystem@@SAPAVStream@@PADHPAXH@Z
    { 0x55FEC0, 0x994D6733, 0x0000 }, // ?PagerInfo@FileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    { 0x55FED0, 0xB7926A12, 0x0000 }, // ?PagerInfoAny@FileSystem@@SAHPADAAUPagerInfo_t@@@Z
    { 0x55FF50, 0x6BA959ED, 0x0000 }, // ??0HierFileSystem@@QAE@XZ
    { 0x55FF70, 0xB1FA9B3E, 0x0000 }, // ??1HierFileSystem@@UAE@XZ
    { 0x55FF80, 0xEF48259A, 0x0000 }, // ?ValidPath@HierFileSystem@@UAEHPAD@Z
    { 0x55FF90, 0xB37A60B5, 0x0000 }, // ?FQN@@YAPADPAD@Z
    { 0x560040, 0x1B6DF24C, 0x0000 }, // ?QueryOn@HierFileSystem@@UAEHPAD@Z
    { 0x560100, 0x71646AC5, 0x0000 }, // ?OpenOn@HierFileSystem@@UAEPAVStream@@PADHPAXH@Z
    { 0x5602A0, 0x3E3CC49A, 0x0000 }, // ?CreateOn@HierFileSystem@@UAEPAVStream@@PADPAXH@Z
    { 0x560380, 0x2FA751C4, 0x0000 }, // ?ChangeDir@HierFileSystem@@UAEHPAD@Z
    { 0x5603A0, 0x1EEE7BE8, 0x0000 }, // ?GetDir@HierFileSystem@@UAEHPADH@Z
    { 0x5603C0, 0x4D7FD869, 0x0000 }, // ?FirstEntry@HierFileSystem@@UAEPAUFileInfo@@PAD@Z
    { 0x560500, 0xFBAC875A, 0x0000 }, // ?NextEntry@HierFileSystem@@UAEPAUFileInfo@@PAU2@@Z
    { 0x5605D0, 0x29C4F080, 0x0000 }, // ?Read@PagerInfo_t@@QAEXPAXII@Z
    { 0x560650, 0x9642362D, 0x0000 }, // ??0VirtualFileSystem@@QAE@PAVStream@@@Z
    { 0x560710, 0xD7767677, 0x0000 }, // ??1VirtualFileSystem@@UAE@XZ
    { 0x560780, 0x403ECF92, 0x0000 }, // ?ValidPath@VirtualFileSystem@@UAEHPAD@Z
    { 0x560790, 0x001C53BB, 0x0000 }, // ?NormalizeName@VirtualFileSystem@@SAXPAD0@Z
    { 0x560800, 0xD8226378, 0x0000 }, // ?ExpandName@VirtualFileSystem@@SAXPADPAUVirtualFileInode@@0@Z
    { 0x560920, 0xFE314508, 0x0000 }, // ?Lookup@VirtualFileSystem@@SAPAUVirtualFileInode@@PAU2@HPAD1@Z
    { 0x560A00, 0x73B75432, 0x0000 }, // ?QueryOn@VirtualFileSystem@@UAEHPAD@Z
    { 0x560A50, 0xCECCCCA5, 0x0000 }, // ?PagerInfo@VirtualFileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    { 0x560AD0, 0x01F1CEF1, 0x0000 }, // ?OpenOn@VirtualFileSystem@@UAEPAVStream@@PADHPAXH@Z
    { 0x560B80, 0xDC52D03F, 0x0000 }, // ?CreateOn@VirtualFileSystem@@UAEPAVStream@@PADPAXH@Z
    { 0x560B90, 0x6F676724, 0x0000 }, // ?ChangeDir@VirtualFileSystem@@UAEHPAD@Z
    { 0x560BA0, 0x4AE2D170, 0x0000 }, // ?GetDir@VirtualFileSystem@@UAEHPADH@Z
    { 0x560BB0, 0x0C6347D7, 0x0000 }, // ?FirstEntry@VirtualFileSystem@@UAEPAUFileInfo@@PAD@Z
    { 0x560D00, 0x202D48ED, 0x0000 }, // ?NextEntry@VirtualFileSystem@@UAEPAUFileInfo@@PAU2@@Z
    { 0x560DB0, 0x6F3F100F, 0x0000 }, // ?InitProblems@@YAXXZ
    { 0x560E10, 0x893CF17F, 0x0000 }, // ?DumpProblems@@YAXXZ
    { 0x561050, 0xC23480C6, 0x0000 }, // ?cmpProblem@@YAHPBX0@Z
    { 0x561100, 0x01BFAAC6, 0x0000 }, // ?RegisterProblem@@YAXPAD00@Z
    { 0x561340, 0xD8F22B2B, 0x0000 }, // ??1problem_t@@QAE@XZ
    { 0x561370, 0x1BA6348B, 0x0000 }, // ??0StreamMiniParser@@QAE@PADPAVStream@@@Z
    { 0x5613A0, 0x12B7EE22, 0x0000 }, // ??1StreamMiniParser@@QAE@XZ
    { 0x561400, 0xB85A1D15, 0x0000 }, // ?RawPutCh@StreamMiniParser@@UAEXH@Z
    { 0x561440, 0xEEA36D37, 0x0000 }, // ?RawGetCh@StreamMiniParser@@UAEHXZ
    { 0x561470, 0x24D40D07, 0x0000 }, // ?Load@StreamMiniParser@@SAXPAVMetaClass@@PADPAX@Z
    { 0x561520, 0x8C792413, 0x0000 }, // ?Save@StreamMiniParser@@SAXPAVMetaClass@@PADPAX@Z
    { 0x5615D0, 0xD7D87B39, 0x0000 }, // ??0Tokenizer@@QAE@PBDPAVStream@@@Z
    { 0x561600, 0x671B8DE6, 0x0000 }, // ?GetToken@Tokenizer@@QAEHPADH@Z
    { 0x561690, 0x9D0FBC7A, 0x0000 }, // ?MatchToken@Tokenizer@@QAEXPAD@Z
    { 0x561710, 0xBFB8DC27, 0x0000 }, // ?GetInt@Tokenizer@@QAEHXZ
    { 0x561770, 0x09AF8BD6, 0x0000 }, // ?GetFloat@Tokenizer@@QAEMXZ
    { 0x5617D0, 0x64B8B93F, 0x0000 }, // ?IgnoreToken@Tokenizer@@QAEXXZ
    { 0x5617F0, 0xED20A582, 0x0000 }, // ??0FileStream@@QAE@PAXHPAVFileSystem@@@Z
    { 0x561830, 0xF253634B, 0x0000 }, // ?GetPagerHandle@FileStream@@UAEIXZ
    { 0x561840, 0x2A0B76EC, 0x0000 }, // ?Create@FileStream@@QAEHPAD@Z
    { 0x561870, 0x649705FE, 0x0000 }, // ?Open@FileStream@@QAEHPADH@Z
    { 0x5618E0, 0x3B46ACD7, 0x0000 }, // ??0FileStream@@QAE@H@Z
    { 0x561910, 0x79CE8749, 0x0000 }, // ?Stdin@FileStream@@QAEHXZ
    { 0x561930, 0xFC7DEEF9, 0x0000 }, // ?Stdout@FileStream@@QAEHXZ
    { 0x561950, 0xBF2CBB2B, 0x0000 }, // ?Stderr@FileStream@@QAEHXZ
    { 0x561970, 0x78D9FF83, 0x0000 }, // ?RawRead@FileStream@@UAEHPAXH@Z
    { 0x561990, 0x0074FE6F, 0x0000 }, // ?RawWrite@FileStream@@UAEHPAXH@Z
    { 0x5619B0, 0x40335115, 0x0000 }, // ?RawSeek@FileStream@@UAEHH@Z
    { 0x5619D0, 0xA88875D6, 0x0000 }, // ?RawTell@FileStream@@UAEHXZ
    { 0x5619F0, 0xDF8DCBF7, 0x0000 }, // ?RawSize@FileStream@@UAEHXZ
    { 0x561A20, 0x279A168D, 0x0000 }, // ?Close@FileStream@@QAEHXZ
    { 0x561A60, 0xBC2A60D7, 0x0000 }, // ??1FileStream@@UAE@XZ
    { 0x561B40, 0x2CBDA853, 0x0000 }, // ??0VirtualStream@@QAE@PAVStream@@PAUVirtualFileInode@@PAXHPAVFileSystem@@@Z
    { 0x561BD0, 0x2675B25D, 0x0000 }, // ?GetPagingInfo@VirtualStream@@UAEHAAI00@Z
    { 0x561C00, 0x0801937C, 0x0000 }, // ??1VirtualStream@@UAE@XZ
    { 0x561C60, 0xDEB316A8, 0x0000 }, // ?RawRead@VirtualStream@@UAEHPAXH@Z
    { 0x561CD0, 0x00A54005, 0x0000 }, // ?RawWrite@VirtualStream@@UAEHPAXH@Z
    { 0x561CE0, 0xFEB4D105, 0x0000 }, // ?RawSeek@VirtualStream@@UAEHH@Z
    { 0x561D10, 0x4104DB47, 0x0000 }, // ?RawTell@VirtualStream@@UAEHXZ
    { 0x561D30, 0x020AC8A4, 0x0000 }, // ?RawSize@VirtualStream@@UAEHXZ
    { 0x561D40, 0xF7D27125, 0x0000 }, // ?GetMapping@VirtualStream@@UAEPAXXZ
    { 0x561D90, 0xC1C2DBA0, 0x0000 }, // ??0WINEventHandler@@QAE@XZ
    { 0x561EC0, 0xA1A2323F, 0x0000 }, // ??1WINEventHandler@@UAE@XZ
    { 0x561F20, 0x71E82493, 0x0000 }, // ?BeginGfx@WINEventHandler@@UAEHHHH@Z
    { 0x561FC0, 0xF494426D, 0x0000 }, // ?EndGfx@WINEventHandler@@UAEXXZ
    { 0x561FE0, 0x945837B7, 0x0000 }, // ?GKeyName@WINEventHandler@@UAEPADH@Z
    { 0x562350, 0xEDC3E206, 0x0000 }, // ?Update@WINEventHandler@@UAEXH@Z
    { 0x562610, 0x138DAB55, 0x0000 }, // ?BeginTracking@WINEventHandler@@UAEXXZ
    { 0x562640, 0x44AD6DD8, 0x0000 }, // ?EndTracking@WINEventHandler@@UAEXXZ
    { 0x562660, 0x400DC56C, 0x0000 }, // ?AdjustMouse@WINEventHandler@@QAEXAAH0@Z
    { 0x562720, 0x46BFA181, 0x0000 }, // ?WindowProc@WINEventHandler@@EAEJPAUHWND__@@IIJ@Z
    { 0x562DF0, 0x9367C946, 0x0000 }, // ?InitEventQueue@@YAXXZ
    { 0x562E60, 0x647DC817, 0x0000 }, // ?DeallocateEventQueue@@YAXXZ
    { 0x562EB0, 0x331DE770, 0x0000 }, // ??0eqEventHandler@@QAE@XZ
    { 0x562F00, 0x23E6988C, 0x0000 }, // ??1eqEventHandler@@UAE@XZ
    { 0x562F30, 0x22F2AB46, 0x0000 }, // ?EKeyName@eqEventHandler@@SAPADH@Z
    { 0x563200, 0x00DD7FD1, 0x0000 }, // ?AddClient@eqEventHandler@@QAEXPAVeqEventMonitor@@@Z
    { 0x563260, 0xE4BBE624, 0x0000 }, // ?RemoveClient@eqEventHandler@@QAEXPAVeqEventMonitor@@@Z
    { 0x5632A0, 0x53B0450E, 0x0000 }, // ??0eqEventMonitor@@QAE@H@Z
    { 0x5632C0, 0xA3C13CBA, 0x0000 }, // ??1eqEventMonitor@@UAE@XZ
    { 0x5632E0, 0xB1A60776, 0x0000 }, // ?Redraw@eqEventMonitor@@UAEXPAXHHHH@Z
    { 0x563320, 0x38A7622D, 0x0000 }, // ?Refocus@eqEventMonitor@@UAEXPAXH@Z
    { 0x563360, 0x3AD8C21C, 0x0000 }, // ?Mouse@eqEventMonitor@@UAEXPAXHHHHHHH@Z
    { 0x5633E0, 0x1D927722, 0x0000 }, // ?Keyboard@eqEventMonitor@@UAEXPAXHHHH@Z
    { 0x563470, 0x8C15AE5A, 0x0000 }, // ?Destroy@eqEventMonitor@@UAEXPAX@Z
    { 0x5634A0, 0x902B5604, 0x0000 }, // ?Activate@eqEventMonitor@@UAEXPAXH@Z
    { 0x5634E0, 0x5A78CDE9, 0x0000 }, // ?SetWantMotion@eqEventMonitor@@QAEXH@Z
    { 0x563560, 0xA2652126, 0x0000 }, // ??0eqEventReplayChannelClass@@QAE@XZ
    { 0x563580, 0xE4C6B787, 0x0000 }, // ?DoRecord@eqEventReplayChannelClass@@UAEXPAVStream@@@Z
    { 0x563790, 0x54C42F7C, 0x0000 }, // ?DoPlayback@eqEventReplayChannelClass@@UAEXPAVStream@@@Z
    { 0x563880, 0x523A5C4A, 0x0000 }, // ?QueueMouse@eqEventReplayChannelClass@@QAEXHHHHHHH@Z
    { 0x563910, 0x49A70F30, 0x0000 }, // ?QueueKeyboard@eqEventReplayChannelClass@@QAEXHHHH@Z
    { 0x5639E0, 0x1EBB128E, 0x0000 }, // ??1eqEventReplayChannelClass@@QAE@XZ
    { 0x5639F0, 0x5E75F642, 0x0000 }, // ??0eqEventQ@@QAE@HHH@Z
    { 0x563A80, 0xF4ECD784, 0x0000 }, // ??1eqEventQ@@UAE@XZ
    { 0x563AF0, 0xC3F947B9, 0x0000 }, // ?Redraw@eqEventQ@@UAEXPAXHHHH@Z
    { 0x563B50, 0xE36C5679, 0x0000 }, // ?Refocus@eqEventQ@@UAEXPAXH@Z
    { 0x563B90, 0xF0B91234, 0x0000 }, // ?Mouse@eqEventQ@@UAEXPAXHHHHHHH@Z
    { 0x563C20, 0xDA020EB6, 0x0000 }, // ?Keyboard@eqEventQ@@UAEXPAXHHHH@Z
    { 0x563C80, 0x944646C2, 0x0000 }, // ?Destroy@eqEventQ@@UAEXPAX@Z
    { 0x563CC0, 0xD3C775F3, 0x0000 }, // ?Activate@eqEventQ@@UAEXPAXH@Z
    { 0x563D00, 0x94F3F438, 0x0000 }, // ?Queue@eqEventQ@@AAEXAATeqEvent@@@Z
    { 0x563D40, 0xE5900E4F, 0x0000 }, // ?Pop@eqEventQ@@QAEHPATeqEvent@@@Z
    { 0x563DE0, 0x8D681D78, 0x0000 }, // ?inputSetup@@YAHHHHHH@Z
    { 0x564050, 0xAF910DAB, 0x0000 }, // ?DIError@@YAPADH@Z
    { 0x564200, 0x5960D562, 0x0000 }, // ?geinputAcquireMouse@@YAXXZ
    { 0x564210, 0x1D7FF615, 0x0000 }, // ?geinputUnacquireMouse@@YAXXZ
    { 0x564220, 0xA19D59C4, 0x0000 }, // ?geinputGetBufferedKeyboard@@YAHPAD@Z
    { 0x5642B0, 0x3AA2A5ED, 0x0000 }, // ?geinputGetKeyboard@@YAPADXZ
    { 0x564320, 0xA6BA1745, 0x0000 }, // ?geinputGetMouse@@YAXPAJ0PAD10001@Z
    { 0x564570, 0xA436EB69, 0x0000 }, // ?geinputCleanup@@YAXXZ
    { 0x564610, 0x69AED56D, 0x0000 }, // ?geinputClearCache@@YAXXZ
    { 0x564620, 0x59473AD5, 0x0000 }, // ??0eqReplayChannel@@IAE@K@Z
    { 0x564650, 0xB29A9FC6, 0x0000 }, // ??1eqReplayChannel@@QAE@XZ
    { 0x564680, 0xA4097049, 0x0000 }, // ?InitRecord@eqReplayChannel@@UAEXXZ
    { 0x564690, 0xAC9DFFEB, 0x0000 }, // ?InitPlayback@eqReplayChannel@@UAEXXZ
    { 0x5646A0, 0x0A778578, 0x0000 }, // ?ShutdownRecord@eqReplayChannel@@UAEXXZ
    { 0x5646B0, 0x0D091A76, 0x0000 }, // ?ShutdownPlayback@eqReplayChannel@@UAEXXZ
    { 0x5646C0, 0xF2D7A3EB, 0x0000 }, // ?InitRecord@eqReplay@@SAXPAD@Z
    { 0x564750, 0xF6AFC56D, 0x0000 }, // ?InitPlayback@eqReplay@@SAXPAD@Z
    { 0x564800, 0xDE678E15, 0x0000 }, // ?ShutdownRecord@eqReplay@@SAXXZ
    { 0x564860, 0x1BD2FBAF, 0x0000 }, // ?ShutdownPlayback@eqReplay@@SAXXZ
    { 0x5648C0, 0x3265C965, 0x0000 }, // ?DoRecord@eqReplay@@SAXXZ
    { 0x564920, 0xFE5D6EF9, 0x0000 }, // ?DoPlayback@eqReplay@@SAXXZ
    { 0x564A00, 0x8CAA0D37, 0x0000 }, // ?irand@@YAHH@Z
    { 0x564A30, 0xF74365E9, 0x0000 }, // ?irand@@YAHXZ
    { 0x564A70, 0x38F6957B, 0x0000 }, // ?frand@@YAMXZ
    { 0x564A90, 0xD6C63955, 0x0000 }, // ?frand@@YAMH@Z
    { 0x564AB0, 0xD0B54456, 0x0000 }, // _rand
    { 0x564AC0, 0x3A3BA01D, 0x0000 }, // _srand
    { 0x564AE0, 0xBDF85D10, 0x0000 }, // ?Dot@Vector3@@QAIXABV1@ABVMatrix34@@@Z
    { 0x564B50, 0x61149E4F, 0x0000 }, // ?Dot3x3@Vector3@@QAIXABV1@ABVMatrix34@@@Z
    { 0x564BB0, 0xCCD697C2, 0x0000 }, // ?Cos@Vector3@@QBEMABV1@@Z
    { 0x564CF0, 0x0C5DBF67, 0x0000 }, // ?Angle@Vector3@@QBEMABV1@@Z
    { 0x564EC0, 0xCE164E5D, 0x0000 }, // ?Area@Vector3@@QBEMABV1@0@Z
    { 0x564F60, 0x59C19FE2, 0x0000 }, // ?Project@Vector3@@QAE?AV1@AAV1@@Z
    { 0x565000, 0xCB22227C, 0x0000 }, // ?Atan3@Vector3@@QBEMDD@Z
    { 0x5651C0, 0xFACC1F7C, 0x0000 }, // ?Reflect@Vector3@@QBE?AV1@ABV1@@Z
    { 0x5652C0, 0xB15BFD6B, 0x0000 }, // ?Rotate@Vector3@@QAEXMH@Z
    { 0x565490, 0x77CE3E9F, 0x0000 }, // ?HalfSpace@Vector3@@QBEHABVVector4@@@Z
    { 0x565540, 0x6C851E2F, 0x0000 }, // ?RayIntersectPlane@Vector3@@QAEHABV1@0ABVVector4@@M@Z
    { 0x5656A0, 0xED356325, 0x0000 }, // ?Approach@Vector3@@QAEHABV1@MMPAM@Z
    { 0x5657E0, 0x402EDC1A, 0x0000 }, // ?CatmullRom@Vector3@@QAEXMABV1@000@Z
    { 0x565990, 0x46D5F396, 0x0000 }, // ?Slerp@Vector3@@QAEXMABV1@0@Z
    { 0x565B50, 0x90C281D3, 0x0000 }, // ?Hermite@Vector3@@QAEXMABV1@000M@Z
    { 0x565D00, 0x4F384479, 0x0000 }, // ?Bilinear@Vector3@@QAEXMMABV1@000@Z
    { 0x565DD0, 0xD4743020, 0x0000 }, // ?PointToLine@Vector3@@QBEMABV1@0@Z
    { 0x565EB0, 0x0861E5BB, 0x0000 }, // ?PointToSegment@Vector3@@QBEMABV1@0AAV1@AAHPAM@Z
    { 0x566080, 0x8A791B2F, 0x0000 }, // ?PointToSegment2@Vector3@@QBEMABV1@0AAV1@AAHPAM@Z
    { 0x5662A0, 0x5F8D084C, 0x0000 }, // ?Equal@Vector3@@QBEIABV1@M@Z
    { 0x566300, 0x96E8D76B, 0x0000 }, // ?rgbtohsv@Vector3@@QAEXXZ
    { 0x566420, 0x0B61771D, 0x0000 }, // ?hsvtorgb@Vector3@@QAEXXZ
    { 0x566550, 0x16F1F016, 0x0000 }, // ?Clamp@Vector3@@QAEXMM@Z
    { 0x5665E0, 0x795E4D8D, 0x0000 }, // ?Clamp@Vector3@@QAEXABV1@0@Z
    { 0x566680, 0xD77FC652, 0x0000 }, // ?GetPolar@Vector3@@QBEXABV1@PAVVector4@@PAV1@@Z
    { 0x5667C0, 0xF1733B2F, 0x0000 }, // ?Rebound@Vector3@@QAEXABV1@M@Z
    { 0x566820, 0x3FAAABAE, 0x0000 }, // ?Bounce@Vector3@@QAEXABV1@M@Z
    { 0x5668A0, 0x31D5A33C, 0x0000 }, // ?Mag@Vector3@@QBEMXZ
    { 0x566960, 0xC2A3C1B0, 0x0000 }, // ?InvMag@Vector3@@QBEMXZ
    { 0x5669C0, 0x81866D9A, 0x0000 }, // ?Dist@Vector3@@QBEMABV1@@Z
    { 0x566A80, 0xDEEE8CC0, 0x0000 }, // ?TransformVertNorm@@YAXAAVVector3@@0ABV1@0ABVMatrix34@@@Z
    { 0x566B70, 0xDE723E95, 0x0000 }, // ?TransformVertList@@YAXPAVVector3@@PBV1@HABVMatrix34@@@Z
    { 0x566C30, 0xF9DA6EF1, 0x0000 }, // ?TransformVertList@@YAXPAPAVVector3@@PAPBV1@HABVMatrix34@@@Z
    { 0x566D00, 0xED8AB758, 0x0000 }, // ?TransformNormalList@@YAXPAVVector3@@PBV1@HABVMatrix34@@@Z
    { 0x566DD0, 0xC91F499C, 0x0000 }, // ?TransformNormalList@@YAXPAPAVVector3@@PAPBV1@HABVMatrix34@@@Z
    { 0x566E80, 0x9EDB924E, 0x0000 }, // ?Init@Vector3Array@@QAEXH@Z
    { 0x566EF0, 0x7FBDDFB1, 0x0000 }, // ?Delete@Vector3Array@@QAEXXZ
    { 0x566F40, 0xD10282AC, 0x0000 }, // ?NewTable@Vector3Array@@AAEXH@Z
    { 0x566FB0, 0xFBEB8A2D, 0x0000 }, // ??AVector3Array@@QAEAAVVector3@@H@Z
    { 0x567030, 0xBE1EFDA1, 0x0000 }, // ??4Vector3Array@@QAEXAAV0@@Z
    { 0x567120, 0x440D8331, 0x0000 }, // ?BlockCopy@Vector3Array@@QAEXAAV1@@Z
    { 0x567320, 0x24131C49, 0x0000 }, // ?Save@Vector3Type@@UAEXPAVMiniParser@@PAX@Z
    { 0x567360, 0xA62793EE, 0x0000 }, // ?Load@Vector3Type@@UAEXPAVMiniParser@@PAX@Z
    { 0x567390, 0xE6CCD71D, 0x0000 }, // ?SizeOf@Vector3Type@@UAEIXZ
    { 0x5673A0, 0xF8B8E974, 0x0000 }, // ?New@Vector3Type@@UAEPAXH@Z
    { 0x5673F0, 0x11CDFB45, 0x0000 }, // ?Delete@Vector3Type@@UAEXPAXH@Z
    { 0x567450, 0xDE093160, 0x0000 }, // ??0Matrix34@@QAE@ABVMatrix44@@@Z
    { 0x5674B0, 0x3B37CEC4, 0x0000 }, // ?Identity@Matrix34@@QAEXXZ
    { 0x5674E0, 0x5C01A905, 0x0000 }, // ??HMatrix34@@QAE?AV0@ABV0@@Z
    { 0x5675B0, 0xF7FD02A1, 0x0000 }, // ??GMatrix34@@QAE?AV0@ABV0@@Z
    { 0x567680, 0x0760B832, 0x0000 }, // ?Dot@Matrix34@@QAEXABV1@0@Z
    { 0x5678A0, 0xC24AC8F1, 0x0000 }, // ?Dot3x3@Matrix34@@QAEXABV1@0@Z
    { 0x567A30, 0xFF9BCAAE, 0x0000 }, // ?SolveSVD@Matrix34@@QBE?AVVector3@@ABV2@@Z
    { 0x5686F0, 0xA6EDF44E, 0x0000 }, // ?Determinant@Matrix34@@QBEMXZ
    { 0x5687A0, 0xC50C7FDC, 0x0000 }, // ?Inverse@Matrix34@@QBE?AV1@XZ
    { 0x568980, 0x8860E31D, 0x0000 }, // ?FastInverse@Matrix34@@QAEXABV1@@Z
    { 0x568A80, 0x3CF55D15, 0x0000 }, // ?FastInverseFull@Matrix34@@QAEXABV1@@Z
    { 0x568D20, 0xE713D006, 0x0000 }, // ?ArbitraryRotation@Matrix34@@AAEXABVVector3@@M@Z
    { 0x5691D0, 0x68F24A80, 0x0000 }, // ?Rotate@Matrix34@@QAEXABVVector3@@M@Z
    { 0x569820, 0xA5896DF4, 0x0000 }, // ?RotateAbs@Matrix34@@QAEXABVVector3@@M@Z
    { 0x569D20, 0x1E8F7823, 0x0000 }, // ?RotateFull@Matrix34@@QAEXABVVector3@@M@Z
    { 0x56A400, 0x8E3744B2, 0x0000 }, // ?RotateToAbs@Matrix34@@QAEXABVVector3@@0M@Z
    { 0x56A670, 0x38330CFF, 0x0000 }, // ?RotateToFull@Matrix34@@QAEXABVVector3@@0M@Z
    { 0x56A6C0, 0xF7A6CC6C, 0x0000 }, // ?RotateTo@Matrix34@@QAEXABVVector3@@0M@Z
    { 0x56A6F0, 0x947AE7EE, 0x0000 }, // ??DMatrix34@@QBE?AV0@M@Z
    { 0x56A7F0, 0xF4E9307B, 0x0000 }, // ??D@YA?AVMatrix34@@MABV0@@Z
    { 0x56A8F0, 0x37B6F570, 0x0000 }, // ?Scale@Matrix34@@QAEXMMM@Z
    { 0x56A970, 0xCE3E3CC7, 0x0000 }, // ?ScaleAbs@Matrix34@@QAEXMMM@Z
    { 0x56A9A0, 0xADB24863, 0x0000 }, // ?Scale@Matrix34@@QAEXM@Z
    { 0x56AA20, 0xED5C46D6, 0x0000 }, // ?ScaleAbs@Matrix34@@QAEXM@Z
    { 0x56AA50, 0x8EBFEB74, 0x0000 }, // ?ScaleFull@Matrix34@@QAEXMMM@Z
    { 0x56AAF0, 0xF5B8AB6F, 0x0000 }, // ?ScaleFullAbs@Matrix34@@QAEXMMM@Z
    { 0x56AB30, 0xAFD21ED6, 0x0000 }, // ?ScaleFull@Matrix34@@QAEXM@Z
    { 0x56ABD0, 0xE66DACD6, 0x0000 }, // ?ScaleFullAbs@Matrix34@@QAEXM@Z
    { 0x56AC10, 0xFBF514BD, 0x0000 }, // ?ScaleVolume@Matrix34@@QAEXMD@Z
    { 0x56AD10, 0x5C437847, 0x0000 }, // ?ScaleVolumeAbs@Matrix34@@QAEXMD@Z
    { 0x56AE10, 0x3E86DF70, 0x0000 }, // ?Transform@Matrix34@@QAEXABVVector3@@0M@Z
    { 0x56AE80, 0x532DFA04, 0x0000 }, // ?Normalize@Matrix34@@QAEXXZ
    { 0x56AFA0, 0x5A764A71, 0x0000 }, // ?TrackBall@Matrix34@@QAEXMMMMM@Z
    { 0x56B250, 0xB7CA825A, 0x0000 }, // ?Transpose@Matrix34@@QAEXABV1@@Z
    { 0x56B2B0, 0xAE87E4C7, 0x0000 }, // ?Atan3@Matrix34@@QBEMDD@Z
    { 0x56B630, 0xBBFFF23A, 0x0000 }, // ?GetEulers@Matrix34@@QBE?AVVector3@@PBD@Z
    { 0x56BCE0, 0x6D9AD052, 0x0000 }, // ?GetEulers@Matrix34@@QBE?AVVector3@@XZ
    { 0x56BE80, 0xBFB47A9F, 0x0000 }, // ?FromEulers@Matrix34@@QAEXABVVector3@@PBD@Z
    { 0x56C7E0, 0xACDF6A71, 0x0000 }, // ?FromEulers@Matrix34@@QAEXABVVector3@@@Z
    { 0x56CD00, 0x85B369F1, 0x0000 }, // ?FromQuaternion@Matrix34@@QAEXABVQuaternion@@@Z
    { 0x56CE30, 0x5F2F648F, 0x0000 }, // ?LookAt@Matrix34@@QAEXABVVector3@@0@Z
    { 0x56CFD0, 0x353C35E3, 0x0000 }, // ?PolarView@Matrix34@@QAEXMMMM@Z
    { 0x56D030, 0x081F3F27, 0x0000 }, // ?PolarView2@Matrix34@@QAEXMMMM@Z
    { 0x56D090, 0xA734D303, 0x0000 }, // ?PolarView@Matrix34@@QAEXABVVector4@@@Z
    { 0x56D0B0, 0xF6EE8036, 0x0000 }, // ?GetLookAt@Matrix34@@QBEXPAVVector3@@0M@Z
    { 0x56D140, 0x580CAD9D, 0x0000 }, // ?GetPolar@Matrix34@@QBEXPAVVector4@@PAVVector3@@M@Z
    { 0x56D180, 0x6153AB1C, 0x0000 }, // ?RotEqual@Matrix34@@QBEIABV1@M@Z
    { 0x56D1E0, 0x24BEF1A0, 0x0000 }, // ?Equal@Matrix34@@QBEIABV1@M@Z
    { 0x56D220, 0x4644132F, 0x0000 }, // ?CalcAppRates@Matrix34@@QAEXAAM0ABV1@MM@Z
    { 0x56D310, 0x31DDD475, 0x0000 }, // ?Approach@Matrix34@@QAEHABV1@MMM@Z
    { 0x56D460, 0xEA647B44, 0x0000 }, // ?Approach@Matrix34@@QAEHABV1@MM@Z
    { 0x56D5B0, 0x22C6944C, 0x0000 }, // ?Interpolate@Matrix34@@QAEXABV1@0M@Z
    { 0x56D6A0, 0xBD260F0E, 0x0000 }, // ?Print@Matrix34@@QBEXXZ
    { 0x56D760, 0xC9880AD7, 0x0000 }, // ?DeclareFields@Matrix34@@SAXXZ
    { 0x56D8A0, 0x3F9B6919, 0x0000 }, // ?GetClass@Matrix34@@SAPAVMetaClass@@XZ
    { 0x56D8B0, 0x9A92DCED, 0x0000 }, // ?ASinf@@YAMM@Z
    { 0x56D950, 0x71D73D4D, 0x0000 }, // ?asinf_fast@@YAMM@Z
    { 0x56D980, 0xD580B9F2, 0x0000 }, // ?ATan2f@@YAMMM@Z
    { 0x56D9F0, 0x32183798, 0x0000 }, // ?Seed@Random@@QAEXH@Z
    { 0x56DAB0, 0x35388C5E, 0x0000 }, // ?Number@Random@@QAEMXZ
    { 0x56DB10, 0xA45EAB07, 0x0000 }, // ?Normal@Random@@QAEMMM@Z
    { 0x56DBA0, 0xB245CAAD, 0x0000 }, // ?Mag@Vector4@@QBEMXZ
    { 0x56DC70, 0x30068A43, 0x0000 }, // ??KVector4@@QBE?AV0@M@Z
    { 0x56DD00, 0xB98D4B20, 0x0000 }, // ??7Vector4@@QBE?AV0@XZ
    { 0x56DD80, 0x9A1682DD, 0x0000 }, // ?Bilinear@Vector4@@QAEXMMABV1@000@Z
    { 0x56DDD0, 0x5BE47C97, 0x0000 }, // ?CalculatePlane@Vector4@@QAEXABVVector3@@00@Z
    { 0x56DED0, 0xAA448B92, 0x0000 }, // ?GetLookAt@Vector4@@QBEXABVVector3@@PAV2@1@Z
    { 0x56DF50, 0x7892791E, 0x0000 }, // ?Lerp@Vector4@@QAEXMABV1@0@Z
    { 0x56E040, 0x1CD70D0B, 0x0000 }, // ?Init@Vector4Array@@QAEXH@Z
    { 0x56E0B0, 0xB34687DF, 0x0000 }, // ?Delete@Vector4Array@@QAEXXZ
    { 0x56E100, 0x3A855EBA, 0x0000 }, // ?NewTable@Vector4Array@@AAEXH@Z
    { 0x56E170, 0xDCF246FD, 0x0000 }, // ??AVector4Array@@QAEAAVVector4@@H@Z
    { 0x56E1F0, 0xBA85A51D, 0x0000 }, // ??4Vector4Array@@QAEXAAV0@@Z
    { 0x56E2F0, 0x0C5DBED1, 0x0000 }, // ?BlockCopy@Vector4Array@@QAEXAAV1@@Z
    { 0x56E3F0, 0x5D3EF63C, 0x0000 }, // ?Save@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    { 0x56E430, 0x651C46F1, 0x0000 }, // ?Load@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    { 0x56E470, 0x1718700E, 0x0000 }, // ?SizeOf@Vector4Type@@UAEIXZ
    { 0x56E480, 0x9F05D546, 0x0000 }, // ?New@Vector4Type@@UAEPAXH@Z
    { 0x56E4D0, 0x12770A37, 0x0000 }, // ?Delete@Vector4Type@@UAEXPAXH@Z
    { 0x56E500, 0x7F04BFBB, 0x0000 }, // ??0Matrix44@@QAE@ABVMatrix34@@@Z
    { 0x56E570, 0x035B2EBA, 0x0000 }, // ??HMatrix44@@QBE?AV0@ABV0@@Z
    { 0x56E6D0, 0x6E7C1938, 0x0000 }, // ??GMatrix44@@QBE?AV0@ABV0@@Z
    { 0x56E820, 0x38197ABD, 0x0000 }, // ??GMatrix44@@QBE?AV0@XZ
    { 0x56E920, 0x682C08AE, 0x0000 }, // ??D@YA?AVMatrix44@@MABV0@@Z
    { 0x56EA80, 0xE315D9E8, 0x0000 }, // ??DMatrix44@@QBE?AV0@M@Z
    { 0x56EBD0, 0x48EDCB0C, 0x0000 }, // ??KMatrix44@@QBE?AV0@M@Z
    { 0x56EDB0, 0xFA09EA93, 0x0000 }, // ??TMatrix44@@QBE?AV0@ABV0@@Z
    { 0x56F020, 0xC9CFDD83, 0x0000 }, // ?Dot@Matrix44@@QAEXABV1@0@Z
    { 0x56F2F0, 0xD33036E2, 0x0000 }, // ??TMatrix44@@QBE?AVVector4@@ABV1@@Z
    { 0x56F3F0, 0x32C352E2, 0x0000 }, // ??T@YA?AVVector3@@ABV0@ABVMatrix44@@@Z
    { 0x56F460, 0x89126B86, 0x0000 }, // ??T@YA?AVVector4@@ABV0@ABVMatrix44@@@Z
    { 0x56F490, 0xA7D52EF4, 0x0000 }, // ?Perspective@Matrix44@@QAEXMMMM@Z
    { 0x56F580, 0x4A43BC32, 0x0000 }, // ?Ortho@Matrix44@@QAEXMMMMMM@Z
    { 0x56F690, 0xC6652AD9, 0x0000 }, // ?Determinant@Matrix44@@QBEMXZ
    { 0x56F8E0, 0x43C5A3A2, 0x0000 }, // ?Inverse@Matrix44@@QBE?AV1@XZ
    { 0x570380, 0x3B04CB14, 0x0000 }, // ?Transpose@Matrix44@@QBE?AV1@XZ
    { 0x570460, 0xBECB5925, 0x0000 }, // ?Identity@Matrix44@@QAEXXZ
    { 0x5704A0, 0xDB7DBBEE, 0x0000 }, // ?Rotate@Matrix44@@QAEXDM@Z
    { 0x570620, 0x9C002F1D, 0x0000 }, // ?Rotate@Matrix44@@QAEXABVVector3@@M@Z
    { 0x570680, 0x9F3CC863, 0x0000 }, // ?Rotate@Matrix44@@QAEXABVVector3@@0@Z
    { 0x5708D0, 0x0E28EC72, 0x0000 }, // ?Translate@Matrix44@@QAEXMMM@Z
    { 0x570920, 0x73347DCB, 0x0000 }, // ?Scale@Matrix44@@QAEXMMM@Z
    { 0x570970, 0x42BFC8B6, 0x0000 }, // ?Scale@Matrix44@@QAEXABVVector3@@M@Z
    { 0x5709D0, 0xDC0BA241, 0x0000 }, // ?FromQuaternion@Matrix44@@QAEXABVQuaternion@@@Z
    { 0x570B10, 0x403AAA7C, 0x0000 }, // ?Print@Matrix44@@QBEXXZ
    { 0x570C80, 0x698A5C65, 0x0000 }, // ??0Matrix44@@QAE@ABV0@@Z
    { 0x570D00, 0x781F0633, 0x0000 }, // ??SVector3@@QBE?AV0@XZ
    { 0x570D50, 0xEECBA2EB, 0x0000 }, // ?Set@Vector4@@QAEXMMMM@Z
    { 0x570D70, 0x2F8F1DD7, 0x0000 }, // ??TVector4@@QBEMABV0@@Z
    { 0x570DB0, 0xA4124DA3, 0x0000 }, // ?Bias@@YAMMM@Z
    { 0x570E00, 0x0A88CA06, 0x0000 }, // ?Gain@@YAMMM@Z
    { 0x570E80, 0x004836C2, 0x0000 }, // ?logf_fast@@YAMM@Z
    { 0x570F10, 0x23F03C6C, 0x0000 }, // ?sqrtf_faster@@YAMM@Z
    { 0x570F80, 0x7DF0D087, 0x0000 }, // ?invsqrtf_fast@@YAMM@Z
    { 0x571000, 0xBAE23E0D, 0x0000 }, // ?expf_fast@@YAMM@Z
    { 0x571090, 0xE09B9E7F, 0x0000 }, // ?expf_faster@@YAMM@Z
    { 0x571110, 0xCE142769, 0x0000 }, // ??KVector2@@QBE?AV0@M@Z
    { 0x571170, 0xD283971C, 0x0000 }, // ??SVector2@@QBE?AV0@XZ
    { 0x5711E0, 0x386E0FE3, 0x0000 }, // ?Mag@Vector2@@QBEMXZ
    { 0x571260, 0xA741D541, 0x0000 }, // ?InvMag@Vector2@@QBEMXZ
    { 0x5712C0, 0x22B13288, 0x0000 }, // ?Init@Vector2Array@@QAEXH@Z
    { 0x571330, 0xC46B5ACD, 0x0000 }, // ?Delete@Vector2Array@@QAEXXZ
    { 0x571380, 0x92D584FC, 0x0000 }, // ?NewTable@Vector2Array@@AAEXH@Z
    { 0x5713F0, 0x96F28D95, 0x0000 }, // ??AVector2Array@@QAEAAVVector2@@H@Z
    { 0x571460, 0xFA3E5DA5, 0x0000 }, // ??4Vector2Array@@QAEXAAV0@@Z
    { 0x571540, 0xA856CEB5, 0x0000 }, // ?BlockCopy@Vector2Array@@QAEXAAV1@@Z
    { 0x571640, 0x38539B64, 0x0000 }, // ?Save@Vector2Type@@UAEXPAVMiniParser@@PAX@Z
    { 0x571670, 0xA64BD6CC, 0x0000 }, // ?Load@Vector2Type@@UAEXPAVMiniParser@@PAX@Z
    { 0x5716A0, 0x3A6FA68A, 0x0000 }, // ?SizeOf@Vector2Type@@UAEIXZ
    { 0x5716B0, 0x70E07F7C, 0x0000 }, // ?New@Vector2Type@@UAEPAXH@Z
    { 0x571700, 0x0D718299, 0x0000 }, // ?Delete@Vector2Type@@UAEXPAXH@Z
    { 0x571730, 0xBE876314, 0x0000 }, // ?GetBoundSphere@@YA?AVVector4@@HPAVVector3@@@Z
    { 0x571790, 0x1909F7CC, 0x0000 }, // ?GetBoundInfo@@YAXHPAVVector3@@000PAM@Z
    { 0x571D50, 0x214F1113, 0x0000 }, // ?CollideTri@@YAHABVVector3@@0000AAMAAV1@2@Z
    { 0x572210, 0x9A282905, 0x0000 }, // ?IsQuadCoplanar@@YAHAAVVector3@@000@Z
    { 0x572360, 0x6013ACE2, 0x0000 }, // ?ComputeMirrorMatrix@@YAXAAVMatrix34@@AAVVector4@@@Z
    { 0x572430, 0x65226EF2, 0x0000 }, // ?ComputeShadowMatrix@@YAXAAVMatrix34@@AAVVector4@@@Z
    { 0x5724D0, 0x247487B1, 0x0000 }, // ?Neg@Vector3@@QAEXABV1@@Z
    { 0x5724F0, 0x062DAB4F, 0x0000 }, // ?Cross@Vector3@@QAEXABV1@0@Z
    { 0x572550, 0x6E75CB26, 0x0000 }, // ?Init@Quaternion@@QAEXMMMM@Z
    { 0x5726A0, 0x46D123F8, 0x0000 }, // ?FromMatrix@Quaternion@@QAEXABVMatrix34@@@Z
    { 0x5727F0, 0x48DC7580, 0x0000 }, // ??SQuaternion@@QBE?AV0@XZ
    { 0x572890, 0xD3CAB2CF, 0x0000 }, // ?Mag@Quaternion@@QBEMXZ
    { 0x572960, 0xC129F8DD, 0x0000 }, // ?Normalize@Quaternion@@QAEXXZ
    { 0x5729C0, 0xC11FBAFD, 0x0000 }, // ?Angle@Quaternion@@QBEMABV1@@Z
    { 0x572A30, 0x910E1F5F, 0x0000 }, // ?TrackBall@Quaternion@@QAEXMMMMM@Z
    { 0x572CE0, 0x91E84CBA, 0x0000 }, // ?Lerp@Quaternion@@QAEXMABV1@0@Z
    { 0x572F60, 0x9E99E0B9, 0x0000 }, // ?Slerp@Quaternion@@QAEXMABV1@0@Z
    { 0x573120, 0x2FC9444A, 0x0000 }, // ?Approach@Quaternion@@QAEHABV1@MM@Z
    { 0x5731A0, 0xA7C76ACC, 0x0000 }, // ?CatmullRom@Quaternion@@QAEXMABV1@000@Z
    { 0x573250, 0xEE714B48, 0x0000 }, // ?tanf_fast@@YAMM@Z
    { 0x5732C0, 0x67B4B2BB, 0x0000 }, // ?atanf_fast_large_values@@YAMM@Z
    { 0x5732F0, 0x9EAF2FA4, 0x0000 }, // ?atanf_fast@@YAMM@Z
    { 0x573370, 0x252DF84C, 0x0000 }, // ?atanf_faster@@YAMM@Z
    { 0x5733D0, 0xA2D69A33, 0x0000 }, // ?atan2f_fast@@YAMMM@Z
    { 0x573450, 0xCEC4B878, 0x0000 }, // ?atan2f_faster@@YAMMM@Z
    { 0x5734D0, 0x11AA9A12, 0x0000 }, // ?SetMathSpeedSlow@@YAXXZ
    { 0x5734F0, 0x13902998, 0x0000 }, // ?SetMathSpeedMed@@YAXXZ
    { 0x573510, 0x33623B9D, 0x0000 }, // ?SetMathSpeedFast@@YAXXZ
    { 0x573530, 0xD9A449A1, 0x0000 }, // ?ResetMathSpeed@@YAXXZ
    { 0x573540, 0xDFB03AD8, 0x0000 }, // ?Init@IntArray@@QAEXH@Z
    { 0x5735B0, 0xB4261622, 0x0000 }, // ?Delete@IntArray@@QAEXXZ
    { 0x573600, 0x4633F0A2, 0x0000 }, // ?NewTable@IntArray@@AAEXH@Z
    { 0x573670, 0x2DA51C6B, 0x0000 }, // ??AIntArray@@QAEAAHH@Z
    { 0x5736D0, 0xCF8F7B56, 0x0000 }, // ??4IntArray@@QAEXAAV0@@Z
    { 0x573790, 0x11CBDDCA, 0x0000 }, // ?BlockCopy@IntArray@@QAEXAAV1@@Z
    { 0x573860, 0x4FD44342, 0x0000 }, // ?Init@FloatArray@@QAEXH@Z
    { 0x5738D0, 0x9308B720, 0x0000 }, // ?Delete@FloatArray@@QAEXXZ
    { 0x573920, 0x8A8EFCC2, 0x0000 }, // ?NewTable@FloatArray@@AAEXH@Z
    { 0x573990, 0xB0A0CC23, 0x0000 }, // ??AFloatArray@@QAEAAMH@Z
    { 0x5739F0, 0xC75DE177, 0x0000 }, // ??4FloatArray@@QAEXAAV0@@Z
    { 0x573AB0, 0x8E000B69, 0x0000 }, // ?BlockCopy@FloatArray@@QAEXAAV1@@Z
    { 0x573B80, 0x4A3A86D6, 0x0000 }, // ?dxiWindowCreate@@YAXPAD@Z
    { 0x573C60, 0x6BED87DE, 0x0000 }, // ?dxiChangeDisplaySettings@@YAHHHH@Z
    { 0x573CC0, 0xC35D6AF8, 0x0000 }, // ?dxiDirectDrawCreate@@YAXXZ
    { 0x573D80, 0xE74DC8E6, 0x0000 }, // ?dxiSetDisplayMode@@YAXXZ
    { 0x573EC0, 0x59F435C6, 0x0000 }, // ?dxiDirectDrawSurfaceCreate@@YAXXZ
    { 0x574190, 0x6E51CBDC, 0x0000 }, // ?dxiDirectDrawSurfaceDestroy@@YAXXZ
    { 0x574200, 0x5ADB8860, 0x0000 }, // ?dxiDirectInputCreate@@YAXXZ
    { 0x574240, 0xBE7078E9, 0x0000 }, // ?dxiShutdown@@YAXXZ
    { 0x5742C0, 0xB01B3DA5, 0x0000 }, // ?dxiMemoryAllocate@@YAPAXPAPAUIDirectDrawSurface4@@I@Z
    { 0x5744E0, 0xE4735A3C, 0x0000 }, // ?dxiMemoryFree@@YAXPAUIDirectDrawSurface4@@@Z
    { 0x574550, 0x5475C3A4, 0x0000 }, // ?dxiInit@@YAXPADHPAPAD@Z
    { 0x574690, 0xCED766AA, 0x0000 }, // ?dxiScreenShot@@YAXPAD@Z
    { 0x5748D0, 0xFC1D2FE6, 0x0000 }, // ?translate565@@YAXPAEPAGI@Z
    { 0x574940, 0x29AEA503, 0x0000 }, // ?translate555@@YAXPAEPAGI@Z
    { 0x5749B0, 0x2A8E8021, 0x0000 }, // ?dxiResClosestMatch@@YAHHHH@Z
    { 0x574A60, 0x05C83B63, 0x0000 }, // ?dxiResGetRecommended@@YAHHH@Z
    { 0x574B00, 0xEDF8859B, 0x0000 }, // ?dxiReadConfigFile@@YAHXZ
    { 0x574DF0, 0x905720E8, 0x0000 }, // ?strtoguid@@YAXPAU_GUID@@PAD@Z
    { 0x574E90, 0x4D84D360, 0x0000 }, // ?dxiWriteConfigFile@@YAXXZ
    { 0x575090, 0xE716FA46, 0x0000 }, // ?guidtostr@@YAXPADPAU_GUID@@@Z
    { 0x575100, 0x58F2063A, 0x0000 }, // ?dxiPlayMovie@@YAXPAD@Z
    { 0x575320, 0xB5415DEB, 0x0000 }, // ?MultiMonCallback@@YGHPAU_GUID@@PAD1PAX2@Z
    { 0x575360, 0x9679B425, 0x0000 }, // ?dxiConfig@@YAXHPAPAD@Z
    { 0x575710, 0x6C3D10A0, 0x0000 }, // ?NeedDX6@@YAXXZ
    { 0x575740, 0xC1E5DFE1, 0x0000 }, // ?EnumCounter@@YGHPAU_GUID@@PAD1PAX@Z
    { 0x575760, 0x0221779E, 0x0000 }, // ?MyDirectDrawEnumerate@@YAXP6GHPAU_GUID@@PAD1PAX@Z2@Z
    { 0x5757D0, 0xA80C66BD, 0x0000 }, // ?EnumerateRenderers2@@YAXXZ
    { 0x575920, 0x845EA510, 0x0000 }, // ?CheckSoftwareRenderer@@YAHPAUIDirectDraw4@@PAU_GUID@@@Z
    { 0x575A10, 0x3A36405F, 0x0000 }, // ?LockScreen@@YAJPAUIDirectDraw4@@@Z
    { 0x575AD0, 0x707FBDBC, 0x0000 }, // ?UnlockScreen@@YAXXZ
    { 0x575AF0, 0x418951EA, 0x0000 }, // ?TestResolution@@YAHPAUIDirectDraw4@@AAUdxiRendererInfo_t@@@Z
    { 0x575F40, 0x86AD6A61, 0x0000 }, // ?ModeCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z
    { 0x575FD0, 0xC9D80754, 0x0000 }, // EnumZ_dxsetup
    { 0x576000, 0xF0777E3D, 0x0000 }, // ?AddRenderer@@YAXPAUIDirectDraw4@@PAU_GUID@@PAD@Z
    { 0x576470, 0x2E54E954, 0x0000 }, // ?EnumTextures@@YGJPAU_DDPIXELFORMAT@@PAX@Z
    { 0x5764A0, 0x92727BAC, 0x0000 }, // ?NotLameChipset@@YAHKK@Z
    { 0x5764B0, 0x43A04C22, 0x0000 }, // ?GetSpecialFlags@@YAIKK@Z
    { 0x576580, 0xCE490DAB, 0x0000 }, // ?Enumerator@@YGHPAU_GUID@@PAD1PAX@Z
    { 0x5765F0, 0x2685EFE0, 0x0000 }, // ?MasterWindowProc@@YGJPAUHWND__@@IIJ@Z
    { 0x576670, 0x2E8DEFFE, 0x0000 }, // ?RegisterMap@@YAXPADPAIHPAVDispatchable@@@Z
    { 0x576750, 0xD3D96129, 0x0000 }, // ?UnregisterMap@@YAXPAD@Z
    { 0x576830, 0xBC84A84C, 0x0000 }, // ?Ticks@Timer@@SAKXZ
    { 0x576860, 0xF6698C20, 0x0000 }, // ?Sleep@Timer@@SAXH@Z
    { 0x576870, 0x1915AF97, 0x0000 }, // ??0Timer@@QAE@XZ
    { 0x5768E0, 0x83E25D06, 0x0000 }, // ?Reset@Timer@@QAEXXZ
    { 0x5768F0, 0xF5626676, 0x0000 }, // ?Time@Timer@@QAEMXZ
    { 0x576920, 0x345A4F58, 0x0000 }, // ?BeginBenchmark@Timer@@SAXXZ
    { 0x576990, 0x2545AA1C, 0x0000 }, // ?EndBenchmark@Timer@@SAXXZ
    { 0x5769C0, 0xF135F77B, 0x0000 }, // ?DefaultPrinter@@YAXHPBDPAD@Z
    { 0x576C70, 0xC0F1C2E5, 0x0000 }, // ?Displayf@@YAXPBDZZ
    { 0x576C90, 0xB7100118, 0x0000 }, // ?Printf@@YAXPBDZZ
    { 0x576CB0, 0x2A56AC82, 0x0000 }, // ?Debugf@@YAXPBDZZ
    { 0x576CD0, 0x627E5800, 0x0000 }, // ?Warningf@@YAXPBDZZ
    { 0x576CF0, 0x911886F7, 0x0000 }, // ?Errorf@@YAXPBDZZ
    { 0x576D10, 0x1283C30F, 0x0000 }, // ?PErrorf@@YAXPBDZZ
    { 0x576D60, 0x525EACED, 0x0000 }, // ?PDebug@@YAXPBDZZ
    { 0x576DB0, 0xF72634D8, 0x0000 }, // ?Abortf@@YAXPBDZZ
    { 0x576DD0, 0x893AA3CF, 0x0000 }, // ?Quit@@YAXPBD@Z
    { 0x576E00, 0xF9EC3FA6, 0x0000 }, // ?LogToCommPort@@YAHHH@Z
    { 0x576E90, 0xAAFC6D0D, 0x0000 }, // ?LogToMonochromeMonitor@@YAXXZ
    { 0x576EA0, 0x26559552, 0x0000 }, // ?LogToFile@@YAXPAD@Z
    { 0x576F00, 0xFDBC3777, 0x0000 }, // ?LogToFile@@YAXXZ
    { 0x576F80, 0x2063AC4A, 0x0000 }, // ?Quitf@@YAXPBDZZ
    { 0x576FC0, 0xD15FE391, 0x0000 }, // ??0DataCache@@QAE@XZ
    { 0x576FD0, 0x9B815628, 0x0000 }, // ?Init@DataCache@@QAEXIHPAD@Z
    { 0x577070, 0xFFDF5CB6, 0x0000 }, // ?Shutdown@DataCache@@QAEXXZ
    { 0x5770B0, 0x09AC1CCB, 0x0000 }, // ?Unload@DataCache@@AAEXH@Z
    { 0x5771A0, 0x732942A1, 0x0000 }, // ?Relocate@DataCache@@AAEXPAUDataCacheObject@@PAE@Z
    { 0x5771F0, 0x557E23DC, 0x0000 }, // ?Lock@DataCache@@QAEHPAH@Z
    { 0x577290, 0x596A8C68, 0x0000 }, // ?Unlock@DataCache@@QAEXH@Z
    { 0x577300, 0xAE35FADB, 0x0000 }, // ?UnlockAndFree@DataCache@@QAEXH@Z
    { 0x5773A0, 0x612E21A8, 0x0000 }, // ?CleanEndOfHeap@DataCache@@AAEXXZ
    { 0x577410, 0x38ED73EE, 0x0000 }, // ?BeginObject@DataCache@@QAEHPAHP6AXPAXH@Z1I@Z
    { 0x5775C0, 0x39D65404, 0x0000 }, // ?InitObject@DataCache@@AAEXHPAHP6AXPAXH@Z1PAEI@Z
    { 0x577690, 0x1D541E15, 0x0000 }, // ?EndObject@DataCache@@QAEXH@Z
    { 0x5776D0, 0x4C4EE8C0, 0x0000 }, // ?Flush@DataCache@@QAEXXZ
    { 0x577750, 0xE6FD8B31, 0x0000 }, // ?Age@DataCache@@QAEXXZ
    { 0x577920, 0x854DF3CE, 0x0000 }, // ?Allocate@DataCache@@QAEPAXHI@Z
    { 0x5779D0, 0x4C2D9D2C, 0x0000 }, // ?GetStatus@DataCache@@QAEXAAI00@Z
    { 0x577AA0, 0x64D821EB, 0x0000 }, // ??0MetaClass@@QAE@PADIP6APAXH@ZP6AXPAXH@ZP6AXXZPAV0@@Z
    { 0x577B20, 0xE00D6D50, 0x0000 }, // ??1MetaClass@@QAE@XZ
    { 0x577B80, 0x27B70614, 0x0000 }, // ?UndeclareAll@MetaClass@@SAXXZ
    { 0x577BB0, 0x9EFFA360, 0x0000 }, // ?IsSubclassOf@MetaClass@@QAEHPAV1@@Z
    { 0x577BE0, 0xA78B2449, 0x0000 }, // ?FindByName@MetaClass@@SAPAV1@PADPAV1@@Z
    { 0x577C50, 0x2B7F7B53, 0x0000 }, // ?__BadSafeCall@@YAXPADPAVBase@@@Z
    { 0x577C70, 0xBEBEDA81, 0x0000 }, // ?InitFields@MetaClass@@QAEXXZ
    { 0x577C90, 0x2EF0A2B2, 0x0000 }, // ?Save@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    { 0x577DE0, 0x32A41ABD, 0x0000 }, // ?SkipBlock@MetaClass@@QAEXPAVMiniParser@@@Z
    { 0x577E90, 0xCC696FDF, 0x0000 }, // ?Load@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    { 0x578000, 0x434108D7, 0x0000 }, // ?DeclareNamedTypedField@MetaClass@@SAXPADIPAUMetaType@@@Z
    { 0x578040, 0x5BCE9385, 0x0000 }, // ?Begin@HashIterator@@QAEXXZ
    { 0x578050, 0x4C87BF07, 0x0000 }, // ?Next@HashIterator@@QAEHXZ
    { 0x5780A0, 0x98AA22D0, 0x0000 }, // ?Init@HashTable@@QAEXH@Z
    { 0x578110, 0x16C782E3, 0x0000 }, // ?Kill@HashTable@@QAEXXZ
    { 0x578180, 0x9EAE1A86, 0x0000 }, // ??4HashTable@@QAEXAAV0@@Z
    { 0x5781D0, 0xA1AFB346, 0x0000 }, // ?Insert@HashTable@@QAEHPADPAX@Z
    { 0x5782B0, 0xD1DF68CA, 0x0000 }, // ?Delete@HashTable@@QAEHPAD@Z
    { 0x5783F0, 0xFC8BDFBA, 0x0000 }, // ?Change@HashTable@@QAEHPAD0@Z
    { 0x578430, 0xF2EF7A8B, 0x0000 }, // ?Access@HashTable@@QAEPAXPAD@Z
    { 0x5784C0, 0x5927F15B, 0x0000 }, // ?Hash@HashTable@@AAEHPAD@Z
    { 0x578500, 0x343B9C76, 0x0000 }, // ?ComputePrime@HashTable@@AAEHH@Z
    { 0x578550, 0xB94C527D, 0x0000 }, // ?Recompute@HashTable@@AAEXH@Z
    { 0x578610, 0x7ED0D38B, 0x0000 }, // ?KillAll@HashTable@@SAXXZ
    { 0x578630, 0x5685A605, 0x0000 }, // ?RemoveMe@HashTable@@AAEXXZ
    { 0x578650, 0x3A37365A, 0x0000 }, // ?ipcCreateEvent@@YAIH@Z
    { 0x578670, 0x5CF4F784, 0x0000 }, // ?ipcCreateMutex@@YAIH@Z
    { 0x578690, 0x1F49B670, 0x0000 }, // ?ipcCreateThread@@YAIP6GKPAX@Z0PAK@Z
    { 0x5786B0, 0x1A221371, 0x0000 }, // ?ipcTriggerEvent@@YAXI@Z
    { 0x5786D0, 0xA007E03E, 0x0000 }, // ?ipcReleaseMutex@@YAXI@Z
    { 0x5786F0, 0x6A3D83D3, 0x0000 }, // ?ipcWaitSingle@@YAXI@Z
    { 0x578720, 0x023F43F0, 0x0000 }, // ?ipcWaitMultiple@@YAHHPAIH@Z
    { 0x578740, 0x7BD7AB80, 0x0000 }, // ?ipcCloseHandle@@YAXI@Z
    { 0x578760, 0xD98AB5EB, 0x0000 }, // ?ipcYield@@YAXXZ
    { 0x578770, 0x1EDD08E8, 0x0000 }, // ?ipcSleep@@YAXI@Z
    { 0x578780, 0x67D3DBBD, 0x0000 }, // ?Proc@ipcMessageQueue@@CGKPAX@Z
    { 0x578790, 0x46559622, 0x0000 }, // ?MessageLoop@ipcMessageQueue@@AAEHXZ
    { 0x578870, 0xC5096537, 0x0000 }, // ?Init@ipcMessageQueue@@QAEXHH@Z
    { 0x578920, 0x9A4028A0, 0x0000 }, // ?Shutdown@ipcMessageQueue@@QAEXXZ
    { 0x578980, 0x71A93F84, 0x0000 }, // ?Send@ipcMessageQueue@@QAEXP6AXPAX@Z0@Z
    { 0x578A70, 0x952A8B08, 0x0000 }, // ?ipcSpinLock@@YAXPAI@Z
    { 0x578AB0, 0xD3EB799E, 0x0000 }, // ?compareExchange@@YIHPAIH@Z
    { 0x578AC0, 0x28782055, 0x0000 }, // ?ipcSpunUnlock@@YAXPAI@Z
    { 0x578AF0, 0x238B457F, 0x0000 }, // ?ipcCreateSpinLock@@YAXPAI@Z
    { 0x578B00, 0x83EEE227, 0x0000 }, // ?ipcCloseSpinLock@@YAXPAI@Z
    { 0x578B20, 0xC7A64714, 0x0000 }, // ?BeginMemStat@@YAXPBD@Z
    { 0x578B80, 0xBB46CAA3, 0x0000 }, // ?getMem@@YAHXZ
    { 0x578BB0, 0x78BFCC47, 0x0000 }, // ?EndMemStat@@YAXXZ
    { 0x578C30, 0x08A5E80C, 0x0000 }, // ??0asArg@@QAE@DPAD@Z
    { 0x578C80, 0xA3FB65D1, 0x0000 }, // ?Print@asArg@@QAEXPAD@Z
    { 0x578D80, 0xB5913EE6, 0x0000 }, // ?Print@ArgSet@@QAEXPAD@Z
    { 0x578DD0, 0x7D09804D, 0x0000 }, // ?ParseArgs@ArgSet@@QAEXHPAPAD@Z
    { 0x579010, 0xB6E9FC6E, 0x0000 }, // ?Usage@ArgSet@@QAEXXZ
    { 0x5790A0, 0xC884035A, 0x0000 }, // ?HexDump@@YAXPAXH@Z
    { 0x5791A0, 0xA7979239, 0x0000 }, // ?GetTypeNameV@Base@@UAEPADXZ
    { 0x5791B0, 0x143C6BAE, 0x0000 }, // ?GetTypeName@Base@@QAEPADXZ
    { 0x5791C0, 0x18BB31E4, 0x0000 }, // ?BeforeSave@Base@@UAEXXZ
    { 0x5791D0, 0x54167814, 0x0000 }, // ?AfterLoad@Base@@UAEXXZ
    { 0x5791E0, 0x64F0B990, 0x0000 }, // ??1Base@@UAE@XZ
    { 0x5791F0, 0x272FF997, 0x0000 }, // ?DeclareFields@Base@@SAXXZ
    { 0x579290, 0x6ED0D576, 0x0000 }, // ?GetClass@Base@@UAEPAVMetaClass@@XZ
    { 0x5792C0, 0xFB94A410, 0x0000 }, // ??0Callback@@QAE@XZ
    { 0x5792D0, 0xF6331776, 0x0000 }, // ??0Callback@@QAE@P8Base@@AEXXZPAV1@@Z
    { 0x579310, 0x6E3A5668, 0x0000 }, // ??0Callback@@QAE@P8Base@@AEXPAX@ZPAV1@0@Z
    { 0x579350, 0x110921C4, 0x0000 }, // ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@0@Z
    { 0x579390, 0x1896F155, 0x0000 }, // ??0Callback@@QAE@P8Base@@AEXPAX0@ZPAV1@00@Z
    { 0x5793D0, 0xBA56BB8D, 0x0000 }, // ??0Callback@@QAE@P6AXXZ@Z
    { 0x5793F0, 0x02FB6357, 0x0000 }, // ??0Callback@@QAE@P6AXPAX@Z0@Z
    { 0x579420, 0x7A0A6090, 0x0000 }, // ??0Callback@@QAE@P6AXPAX0@Z0@Z
    { 0x579450, 0x31AF2E33, 0x0000 }, // ?Call@Callback@@QAEXPAX@Z
    { 0x5794E0, 0xD8B28989, 0x0000 }, // ??0string@@QAE@XZ
    { 0x579510, 0xFB2EB9B9, 0x0000 }, // ??Hstring@@QBE?AV0@PBD@Z
    { 0x579640, 0xD3FF023F, 0x0000 }, // ??H@YA?AVstring@@PBDABV0@@Z
    { 0x579770, 0xCAF20F62, 0x0000 }, // ??Ystring@@QAEXPBD@Z
    { 0x579860, 0xBA79EB71, 0x0000 }, // ??Ystring@@QAEXD@Z
    { 0x579900, 0x8A2AC308, 0x0000 }, // ??Gstring@@QBE?AV0@PBD@Z
    { 0x579A60, 0xFA6C4579, 0x0000 }, // ??Zstring@@QAEXPBD@Z
    { 0x579B10, 0x192666CC, 0x0000 }, // ?MinusEqual@string@@QAEXD@Z
    { 0x579C60, 0x49A6D0FD, 0x0000 }, // ?Contains@string@@QBEHAAV1@@Z
    { 0x579D00, 0x17781F17, 0x0000 }, // ?SaveName@string@@QAEXABV1@H00@Z
    { 0x579ED0, 0xB1420D68, 0x0000 }, // ?FindFile@string@@QAEHABV1@H00@Z
    { 0x57A260, 0x9962CB5A, 0x0000 }, // ?FileExists@string@@QBEHXZ
    { 0x57A290, 0x8FCB7589, 0x0000 }, // ?DirFileExt@string@@QBEXAAV1@00@Z
    { 0x57A4A0, 0x33039DB9, 0x0000 }, // ?CommaFile@string@@QBEHXZ
    { 0x57A6A0, 0x2D933133, 0x0000 }, // ?FileName@string@@QBE?AV1@XZ
    { 0x57A800, 0x1E9E6F34, 0x0000 }, // ?Extension@string@@QBE?AV1@XZ
    { 0x57A950, 0x3D4DF36F, 0x0000 }, // ?ChangeExtension@string@@QAEXABV1@@Z
    { 0x57AAD0, 0x938B7DAD, 0x0000 }, // ?RemoveExtension@string@@QAEXXZ
    { 0x57AB10, 0xFC1BD613, 0x0000 }, // ?ExpandEnvs@string@@QAEXXZ
    { 0x57ACB0, 0x7FF4634C, 0x0000 }, // ?SubString@string@@QBE?AV1@H@Z
    { 0x57ADC0, 0x5CD64B78, 0x0000 }, // ?NumSubStrings@string@@QBEHXZ
    { 0x57AE10, 0x8E462EBE, 0x0000 }, // ?IsNumeric@string@@QBEHXZ
    { 0x57AE60, 0x08219E74, 0x0000 }, // ?Init@StringArray@@QAEXH@Z
    { 0x57AED0, 0xC740FCF2, 0x0000 }, // ?Delete@StringArray@@QAEXXZ
    { 0x57AF30, 0xE37CB46F, 0x0000 }, // ?NewTable@StringArray@@AAEXH@Z
    { 0x57AFA0, 0x02A9D251, 0x0000 }, // ??AStringArray@@QAEAAVstring@@H@Z
    { 0x57B050, 0xDA8A87B2, 0x0000 }, // ??4StringArray@@QAEXAAV0@@Z
    { 0x57B1F0, 0xCCF51BA3, 0x0000 }, // ?BlockCopy@StringArray@@QAEXAAV1@@Z
    { 0x57B320, 0x65199A4E, 0x0000 }, // ??4string@@QAEXPBD@Z
    { 0x57B380, 0x05E01419, 0x0000 }, // ??Hstring@@QBE?AV0@ABV0@@Z
    { 0x57B410, 0xA8B58C57, 0x0000 }, // ?PerfInit@@YAXXZ
    { 0x57B450, 0x2FB3CB41, 0x0000 }, // ?PerfShutdown@@YAXXZ
    { 0x57B470, 0x7E9C0077, 0x0000 }, // ?PerfLookup@@YAHPAD@Z
    { 0x57B530, 0x639C4F82, 0x0000 }, // ?PerfGetValue@@YAIH@Z
    { 0x57B590, 0xB08B8C1E, 0x0000 }, // ?Save@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57B5B0, 0x14559D3F, 0x0000 }, // ?Load@PtrToType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57B5D0, 0xD48231BA, 0x0000 }, // ?New@PtrToType@@UAEPAXH@Z
    { 0x57B5E0, 0x70D55105, 0x0000 }, // ?Delete@PtrToType@@UAEXPAXH@Z
    { 0x57B5F0, 0x4CCA6525, 0x0000 }, // ?SizeOf@PtrToType@@UAEIXZ
    { 0x57B600, 0xE58AE712, 0x0000 }, // ?GetCount@RefToType@@QAEHPAX@Z
    { 0x57B640, 0xF72FA4E4, 0x0000 }, // ?Save@RefToType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57B6F0, 0xCE73C775, 0x0000 }, // ?Load@RefToType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57B7A0, 0x2285E706, 0x0000 }, // ?New@RefToType@@UAEPAXH@Z
    { 0x57B7B0, 0x0AEC686B, 0x0000 }, // ?Delete@RefToType@@UAEXPAXH@Z
    { 0x57B7C0, 0x81243269, 0x0000 }, // ?SizeOf@RefToType@@UAEIXZ
    { 0x57B7D0, 0xF38ED67E, 0x0000 }, // ?Save@ArrayOfType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57B870, 0x5F6D1EE0, 0x0000 }, // ?Load@ArrayOfType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57B900, 0x5B5B8965, 0x0000 }, // ?SizeOf@ArrayOfType@@UAEIXZ
    { 0x57B920, 0x9B846BC2, 0x0000 }, // ?New@ArrayOfType@@UAEPAXH@Z
    { 0x57B940, 0x0AF58608, 0x0000 }, // ?Delete@ArrayOfType@@UAEXPAXH@Z
    { 0x57B960, 0xCA7804B4, 0x0000 }, // ?Save@StructType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57B980, 0x9B9AE5D1, 0x0000 }, // ?Load@StructType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57B9A0, 0xB5B62CBD, 0x0000 }, // ?SizeOf@StructType@@UAEIXZ
    { 0x57B9B0, 0x30E875FC, 0x0000 }, // ?New@StructType@@UAEPAXH@Z
    { 0x57B9D0, 0xF8FFB2E1, 0x0000 }, // ?Delete@StructType@@UAEXPAXH@Z
    { 0x57B9F0, 0xD6F4E341, 0x0000 }, // ?Save@CharType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BA10, 0xA7254773, 0x0000 }, // ?Load@CharType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BA30, 0x7C90DBC3, 0x0000 }, // ?SizeOf@CharType@@UAEIXZ
    { 0x57BA40, 0xF4A1B05A, 0x0000 }, // ?New@CharType@@UAEPAXH@Z
    { 0x57BA70, 0x03D2EA15, 0x0000 }, // ?Delete@CharType@@UAEXPAXH@Z
    { 0x57BAC0, 0x4F9422A7, 0x0000 }, // ?Save@SignedCharType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BAE0, 0xAB68A613, 0x0000 }, // ?Load@SignedCharType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BB00, 0x41476EE3, 0x0000 }, // ?SizeOf@SignedCharType@@UAEIXZ
    { 0x57BB10, 0xB5A3C83E, 0x0000 }, // ?New@SignedCharType@@UAEPAXH@Z
    { 0x57BB40, 0x4468AE33, 0x0000 }, // ?Delete@SignedCharType@@UAEXPAXH@Z
    { 0x57BB90, 0xC7D14809, 0x0000 }, // ?Save@UnsignedCharType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BBB0, 0x3D8690F0, 0x0000 }, // ?Load@UnsignedCharType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BBD0, 0x05511D9F, 0x0000 }, // ?SizeOf@UnsignedCharType@@UAEIXZ
    { 0x57BBE0, 0xD9A66C82, 0x0000 }, // ?New@UnsignedCharType@@UAEPAXH@Z
    { 0x57BC10, 0xA1FC066B, 0x0000 }, // ?Delete@UnsignedCharType@@UAEXPAXH@Z
    { 0x57BC60, 0x088B8F3F, 0x0000 }, // ?Save@SignedShortType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BC80, 0x384BB73D, 0x0000 }, // ?Load@SignedShortType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BCA0, 0x8FBA4553, 0x0000 }, // ?SizeOf@SignedShortType@@UAEIXZ
    { 0x57BCB0, 0x67CDB34B, 0x0000 }, // ?New@SignedShortType@@UAEPAXH@Z
    { 0x57BCE0, 0x4502C04C, 0x0000 }, // ?Delete@SignedShortType@@UAEXPAXH@Z
    { 0x57BD30, 0xBA29B0F4, 0x0000 }, // ?Save@UnsignedShortType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BD60, 0x1D1BA2A4, 0x0000 }, // ?Load@UnsignedShortType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BD80, 0xC2559F2F, 0x0000 }, // ?SizeOf@UnsignedShortType@@UAEIXZ
    { 0x57BD90, 0xF6EA0FB4, 0x0000 }, // ?New@UnsignedShortType@@UAEPAXH@Z
    { 0x57BDC0, 0x1940C975, 0x0000 }, // ?Delete@UnsignedShortType@@UAEXPAXH@Z
    { 0x57BE10, 0x511083C8, 0x0000 }, // ?Save@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BE30, 0xC5BA4C18, 0x0000 }, // ?Load@SignedIntType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BE50, 0x0766C02F, 0x0000 }, // ?SizeOf@SignedIntType@@UAEIXZ
    { 0x57BE60, 0x2CD88A88, 0x0000 }, // ?New@SignedIntType@@UAEPAXH@Z
    { 0x57BE90, 0xFE5AA712, 0x0000 }, // ?Delete@SignedIntType@@UAEXPAXH@Z
    { 0x57BEE0, 0x8A4017E8, 0x0000 }, // ?Save@SignedInt64Type@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BF10, 0x620A6AE5, 0x0000 }, // ?Load@SignedInt64Type@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BF30, 0x221CB143, 0x0000 }, // ?SizeOf@SignedInt64Type@@UAEIXZ
    { 0x57BF40, 0xDFB8A64C, 0x0000 }, // ?New@SignedInt64Type@@UAEPAXH@Z
    { 0x57BF70, 0x5C1212B6, 0x0000 }, // ?Delete@SignedInt64Type@@UAEXPAXH@Z
    { 0x57BFC0, 0x387EDCFA, 0x0000 }, // ?Save@UnsignedIntType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57BFE0, 0xE3780374, 0x0000 }, // ?Load@UnsignedIntType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57C000, 0xC7A6DD6E, 0x0000 }, // ?SizeOf@UnsignedIntType@@UAEIXZ
    { 0x57C010, 0xA6C7BB01, 0x0000 }, // ?New@UnsignedIntType@@UAEPAXH@Z
    { 0x57C040, 0x5B570C55, 0x0000 }, // ?Delete@UnsignedIntType@@UAEXPAXH@Z
    { 0x57C090, 0x12F10C59, 0x0000 }, // ?Save@FloatType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57C0C0, 0x46371B6C, 0x0000 }, // ?Load@FloatType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57C0E0, 0xCD49E9B6, 0x0000 }, // ?SizeOf@FloatType@@UAEIXZ
    { 0x57C0F0, 0x1F526099, 0x0000 }, // ?New@FloatType@@UAEPAXH@Z
    { 0x57C120, 0x8E98BF8F, 0x0000 }, // ?Delete@FloatType@@UAEXPAXH@Z
    { 0x57C190, 0xA1B4D47D, 0x0000 }, // ?Save@StringType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57C1D0, 0x60123C56, 0x0000 }, // ?Load@StringType@@UAEXPAVMiniParser@@PAX@Z
    { 0x57C220, 0xFA6CCB9F, 0x0000 }, // ?New@StringType@@UAEPAXH@Z
    { 0x57C260, 0xC385F2AF, 0x0000 }, // ?Delete@StringType@@UAEXPAXH@Z
    { 0x57C270, 0x1E19A081, 0x0000 }, // ?SizeOf@StringType@@UAEIXZ
    { 0x57C280, 0x1D34A3A9, 0x0000 }, // ??1List@@QAE@XZ
    { 0x57C290, 0x0CE4624D, 0x0000 }, // ?Kill@List@@QAEXXZ
    { 0x57C2B0, 0xB5CC544F, 0x0000 }, // ?Insert@List@@QAEHHPAX@Z
    { 0x57C330, 0xEF1137AB, 0x0000 }, // ?Access@List@@QAEPAXH@Z
    { 0x57C360, 0x0618BD6F, 0x0000 }, // ?Delete@List@@QAEHH@Z
    { 0x57C400, 0x638F472F, 0x0000 }, // ?cpuid@@YAHXZ
    { 0x57C410, 0xD9D5C8A2, 0x0000 }, // ??0initHaveMMX@@QAE@XZ
    { 0x57C4C0, 0xF723952D, 0x0000 }, // ?utimer@@YAKXZ
    { 0x57C5E0, 0x9514C80A, 0x0000 }, // ??0MiniParser@@QAE@PAD@Z
    { 0x57C640, 0x1CB214B8, 0x0000 }, // ??1MiniParser@@QAE@XZ
    { 0x57C660, 0x160D3262, 0x0000 }, // ?Printf@MiniParser@@QAAXPBDZZ
    { 0x57C6B0, 0x1A5F4804, 0x0000 }, // ?PrintString@MiniParser@@QAEXPADH@Z
    { 0x57C710, 0x5F0F2E2F, 0x0000 }, // ?Errorf@MiniParser@@QAAXPBDZZ
    { 0x57C7B0, 0x4D52ACB8, 0x0000 }, // ?Commentf@MiniParser@@QAAXPBDZZ
    { 0x57C810, 0xC9610B1A, 0x0000 }, // ?GetCh@MiniParser@@QAEHXZ
    { 0x57C830, 0x2B2F5034, 0x0000 }, // ?PutCh@MiniParser@@QAEXH@Z
    { 0x57C880, 0x9CE1606C, 0x0000 }, // ?Indent@MiniParser@@QAEXH@Z
    { 0x57C8A0, 0xFFC05B7D, 0x0000 }, // ?Match@MiniParser@@QAEXH@Z
    { 0x57C8E0, 0xBA90FFCA, 0x0000 }, // ?TokenName@MiniParser@@SAPADH@Z
    { 0x57CA80, 0xB3E1C907, 0x0000 }, // ?PlaceLabel@MiniParser@@QAEXPAX@Z
    { 0x57CAA0, 0x9E493897, 0x0000 }, // ?PlaceLabelRef@MiniParser@@QAEXPAX@Z
    { 0x57CAC0, 0x5EA0FF7F, 0x0000 }, // ?ResolveLabel@MiniParser@@QAEPAXPADPAPAX@Z
    { 0x57CAD0, 0x9D43AA31, 0x0000 }, // ?PutBack@MiniParser@@QAEXH@Z
    { 0x57CB00, 0xD1DA64D4, 0x0000 }, // ?NextToken@MiniParser@@QAEHXZ
    { 0x57CD00, 0xBBC79DAF, 0x0000 }, // ?IntVal@MiniParser@@QAEHXZ
    { 0x57CD40, 0x0982A940, 0x0000 }, // ?Int64Val@MiniParser@@QAE_JXZ
    { 0x57CD80, 0x04257B04, 0x0000 }, // ?FloatVal@MiniParser@@QAEMXZ
    { 0x57CDC0, 0x2A24843D, 0x0000 }, // ?GetMachineName@@YAXPADH@Z
    { 0x57CE90, 0xC62789AB, 0x0000 }, // ?__ComputeCpuSpeed@@YAIXZ
    { 0x57CF40, 0x6DE77C80, 0x0000 }, // ?rdtsc@@YAIXZ
    { 0x57CF50, 0x6D0FD18F, 0x0000 }, // ?ComputeCpuSpeed@@YAIXZ
    { 0x57D000, 0x98A31EEB, 0x0000 }, // ?jpeg_CreateDecompress@@YAXPAUjpeg_decompress_struct@@HI@Z
    { 0x57D0E0, 0xBAB41052, 0x0000 }, // ?jpeg_destroy_decompress@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x57D100, 0x83BB99F9, 0x0000 }, // ?jpeg_abort_decompress@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x57D120, 0x06DB2F48, 0x0000 }, // ?jpeg_read_header@@YAHPAUjpeg_decompress_struct@@E@Z
    { 0x57D1A0, 0x4F9A5642, 0x0000 }, // ?jpeg_consume_input@@YAHPAUjpeg_decompress_struct@@@Z
    { 0x57D420, 0x5181DF3E, 0x0000 }, // ?jpeg_input_complete@@YAEPAUjpeg_decompress_struct@@@Z
    { 0x57D460, 0xAFC73558, 0x0000 }, // ?jpeg_has_multiple_scans@@YAEPAUjpeg_decompress_struct@@@Z
    { 0x57D4A0, 0x496E838D, 0x0000 }, // ?jpeg_finish_decompress@@YAEPAUjpeg_decompress_struct@@@Z
    { 0x57D570, 0xCA6033B8, 0x0000 }, // ?jpeg_start_decompress@@YAEPAUjpeg_decompress_struct@@@Z
    { 0x57D680, 0x8E42B842, 0x0000 }, // ?jpeg_read_scanlines@@YAIPAUjpeg_decompress_struct@@PAPAEI@Z
    { 0x57D720, 0x703DFE11, 0x0000 }, // ?jpeg_read_raw_data@@YAIPAUjpeg_decompress_struct@@PAPAPAEI@Z
    { 0x57D7E0, 0x9D2FF98F, 0x0000 }, // ?jpeg_stdio_src@@YAXPAUjpeg_decompress_struct@@PAVStream@@@Z
    { 0x57D930, 0x1D4A8124, 0x0000 }, // ?jpeg_std_error@@YAPAUjpeg_error_mgr@@PAU1@@Z
    { 0x57DB10, 0xB5B4CD2E, 0x0000 }, // ?jinit_input_controller@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x57E150, 0x12847D81, 0x0000 }, // ?jpeg_resync_to_restart@@YAEPAUjpeg_decompress_struct@@H@Z
    { 0x57E380, 0x4824E363, 0x0000 }, // ?jinit_marker_reader@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x57FCB0, 0x51F630CF, 0x0000 }, // ?jpeg_set_marker_processor@@YAXPAUjpeg_decompress_struct@@HP6AE0@Z@Z
    { 0x57FD10, 0x24844A4E, 0x0000 }, // ?jinit_memory_mgr@@YAXPAUjpeg_common_struct@@@Z
    { 0x580960, 0xF75CC17F, 0x0000 }, // ?jpeg_abort@@YAXPAUjpeg_common_struct@@@Z
    { 0x5809B0, 0xCE3B77F0, 0x0000 }, // ?jpeg_destroy@@YAXPAUjpeg_common_struct@@@Z
    { 0x5809E0, 0x2E2E71CD, 0x0000 }, // ?jpeg_alloc_quant_table@@YAPAUJQUANT_TBL@@PAUjpeg_common_struct@@@Z
    { 0x580A00, 0x0405D0A4, 0x0000 }, // ?jpeg_alloc_huff_table@@YAPAUJHUFF_TBL@@PAUjpeg_common_struct@@@Z
    { 0x580A20, 0x23ED0044, 0x0000 }, // ?jpeg_calc_output_dimensions@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x580AE0, 0x8FA5E95D, 0x0000 }, // ?jinit_master_decompress@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x580EC0, 0x9CF4B629, 0x0000 }, // ?jdiv_round_up@@YAJJJ@Z
    { 0x580EE0, 0x534DF267, 0x0000 }, // ?jround_up@@YAJJJ@Z
    { 0x580F00, 0x11726012, 0x0000 }, // ?jcopy_sample_rows@@YAXPAPAEH0HHI@Z
    { 0x580F50, 0x30DE2969, 0x0000 }, // ?jcopy_block_row@@YAXPAY0EA@F0I@Z
    { 0x580F80, 0xC2E1B51D, 0x0000 }, // ?jzero_far@@YAXPAXI@Z
    { 0x580FA0, 0x6BCD2158, 0x0000 }, // ?jpeg_get_small@@YAPAXPAUjpeg_common_struct@@I@Z
    { 0x580FC0, 0xCA2F8BD9, 0x0000 }, // ?jpeg_free_small@@YAXPAUjpeg_common_struct@@PAXI@Z
    { 0x580FE0, 0x99BC36BC, 0x0000 }, // ?jpeg_get_large@@YAPAXPAUjpeg_common_struct@@I@Z
    { 0x581000, 0x41B34DFC, 0x0000 }, // ?jpeg_free_large@@YAXPAUjpeg_common_struct@@PAXI@Z
    { 0x581020, 0x79CC2A3E, 0x0000 }, // ?jpeg_mem_available@@YAJPAUjpeg_common_struct@@JJJ@Z
    { 0x581030, 0xB177A9AE, 0x0000 }, // ?jpeg_open_backing_store@@YAXPAUjpeg_common_struct@@PAUbacking_store_struct@@J@Z
    { 0x581050, 0x32B1876B, 0x0000 }, // ?jpeg_mem_init@@YAJPAUjpeg_common_struct@@@Z
    { 0x581060, 0xAB1AEE55, 0x0000 }, // ?jpeg_mem_term@@YAXPAUjpeg_common_struct@@@Z
    { 0x581070, 0x71A57695, 0x0000 }, // ?jinit_d_main_controller@@YAXPAUjpeg_decompress_struct@@E@Z
    { 0x581730, 0x93C34389, 0x0000 }, // ?jinit_d_coef_controller@@YAXPAUjpeg_decompress_struct@@E@Z
    { 0x581AA0, 0xA1991A0C, 0x0000 }, // ?jpeg_make_d_derived_tbl@@YAXPAUjpeg_decompress_struct@@EHPAPAUd_derived_tbl@@@Z
    { 0x581D60, 0x06F04D20, 0x0000 }, // ?jpeg_fill_bit_buffer@@YAEPAUbitread_working_state@@JHH@Z
    { 0x581E80, 0xAB402BA9, 0x0000 }, // ?jpeg_huff_decode@@YAHPAUbitread_working_state@@JHPAUd_derived_tbl@@H@Z
    { 0x581F80, 0xE2B73532, 0x0000 }, // ?jinit_huff_decoder@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x5825E0, 0x2BBF5290, 0x0000 }, // ?jinit_inverse_dct@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x582840, 0x05794E9A, 0x0000 }, // ?jinit_d_post_controller@@YAXPAUjpeg_decompress_struct@@E@Z
    { 0x5829E0, 0x20026AF2, 0x0000 }, // ?jinit_upsampler@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x583130, 0x03C689C8, 0x0000 }, // ?jinit_color_deconverter@@YAXPAUjpeg_decompress_struct@@@Z
    { 0x583790, 0x57E2FA6E, 0x0000 }, // ?jpeg_idct_islow@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
    { 0x583D40, 0x2BF5D92D, 0x0000 }, // ?jpeg_idct_ifast@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
    { 0x5841B0, 0xEFE64C2D, 0x0000 }, // ?jpeg_idct_float@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
    { 0x585F30, 0xE3D84AA3, 0x0000 }, // __purecall
    { 0x61CB70, 0x274AA20D, 0x0003 }, // _MM_GUID
    { 0x61FD98, 0x8F051F2D, 0x0001 }, // ?s_DWDefault3DCtrlFlags@AudSound@@0KB
    { 0x61FD9C, 0x758B17EE, 0x0001 }, // ?s_DWDefault2DCtrlFlags@AudSound@@0KB
    { 0x61FDA0, 0x2687A85C, 0x0001 }, // ?s_DWFreqChange3DCtrlFlags@AudSound@@0KB
    { 0x61FDA4, 0x3057DCDE, 0x0001 }, // ?s_DWFreqChange2DCtrlFlags@AudSound@@0KB
    { 0x61FDA8, 0xEE4563B4, 0x0001 }, // ?s_DWSoft2DCtrlFlags@AudSound@@0KB
    { 0x61FDAC, 0xE305B1D2, 0x0001 }, // ?s_DWSoftFreqChange2DCtrlFlags@AudSound@@0KB
    { 0x61FED0, 0x29D83B6D, 0x0001 }, // ?s_iStereoOnMask@DSGlobal@@0IB
    { 0x61FED4, 0xF34390AF, 0x0001 }, // ?s_iHiResMask@DSGlobal@@0IB
    { 0x61FED8, 0xCDEA18F3, 0x0001 }, // ?s_iHiSampleSizeMask@DSGlobal@@0IB
    { 0x61FEDC, 0xE2A9775A, 0x0001 }, // ?s_iEchoOnMask@DSGlobal@@0IB
    { 0x61FEE0, 0x80FA0FFD, 0x0001 }, // ?s_iDSound3DMask@DSGlobal@@0IB
    { 0x61FEE4, 0x6CC61B9A, 0x0001 }, // ?s_iSoundFXOnMask@DSGlobal@@0IB
    { 0x61FEE8, 0x1EF07EFF, 0x0001 }, // ?s_iCDMusicOnMask@DSGlobal@@0IB
    { 0x61FEEC, 0xA9B72CE3, 0x0001 }, // ?s_iUsingEAXMask@DSGlobal@@0IB
    { 0x61FEF0, 0xBB3A483E, 0x0001 }, // ?s_iAlwaysEAXMask@DSGlobal@@0IB
    { 0x61FEF4, 0x52220D19, 0x0001 }, // ?s_iCommentaryOnMask@DSGlobal@@0IB
    { 0x61FF24, 0x67628B93, 0x0001 }, // ?s_DWDefault2DCtrlFlags@AudStream@@0KB
    { 0x61FF28, 0x48B46FC8, 0x0001 }, // ?s_DWFreqChange2DCtrlFlags@AudStream@@0KB
    { 0x61FFA0, 0x9A8023B5, 0x0008 }, // _DSPROPSETID_EAX_ReverbProperties
    { 0x61FFB0, 0x61DEB58E, 0x0019 }, // _DSPROPSETID_EAXBUFFER_ReverbProperties
    { 0x6220E8, 0x2985E999, 0x0022 }, // ?jpeg_natural_order@@3PBHB
    { 0x634680, 0x7426EBE8, 0x0029 }, // ?CycleTime@@3MA
    { 0x634684, 0xF0B62662, 0x0031 }, // ?page_override@@3HA
    { 0x634688, 0x10174745, 0x0042 }, // ?GlobalDamageScale@@3MA
    { 0x63468C, 0xDA423903, 0x004D }, // ?APPTITLE@@3PADA
    { 0x634690, 0x1828CF51, 0x0074 }, // ?VERSION_STRING@@3PADA
    { 0x635170, 0xDCC94B04, 0x007E }, // ?arotX@@3MA
    { 0x635174, 0x6775B397, 0x0085 }, // ?FirstPrintTime@@3HA
    { 0x635AC0, 0xA87E3ADD, 0x008C }, // ?ProjectileY@@3MA
    { 0x635AC8, 0xED56F1FB, 0x0091 }, // ?IconColor@@3PAIA
    { 0x636504, 0xBFBD5CF0, 0x0001 }, // ?MAX_SPEED@@3MA
    { 0x636A00, 0x1717F3D3, 0x0099 }, // ?fontscalar@@3MA
    { 0x639370, 0xE24D00E0, 0x009E }, // ?s_fAudioVolume@aiPedestrian@@0MA
    { 0x639374, 0x12A352BA, 0x00A3 }, // ?s_fAudioMaxDistance@aiPedestrian@@0MA
    { 0x6398B0, 0x6DE0E556, 0x00AE }, // ?s_fAudioVolume@aiVehicleAmbient@@0MA
    { 0x6398B4, 0x304AAB84, 0x00B7 }, // ?s_fAudioVolumeSemi@aiVehicleAmbient@@0MA
    { 0x6398B8, 0xA3C923D6, 0x00BF }, // ?s_fAudioMaxDistance@aiVehicleAmbient@@0MA
    { 0x6398BC, 0x425539ED, 0x00CC }, // ?s_fHornVolume@aiVehicleAmbient@@0MA
    { 0x6398C0, 0x8148499D, 0x00D9 }, // ?s_fVoiceVolume@aiVehicleAmbient@@0MA
    { 0x6398C4, 0x7B8C9AD5, 0x00E4 }, // ?s_fSecsSinceImpactReaction@aiVehicleAmbient@@0MA
    { 0x63ABC0, 0x86D0483C, 0x00EF }, // ?MetricFactor@@3MA
    { 0x63ABC4, 0x92CCE213, 0x00F4 }, // ?WeatherFriction@@3MA
    { 0x63C1E8, 0xD54906B2, 0x00FF }, // ?m_fBareMinimum@mmOpponentImpactAudio@@0MA
    { 0x63C1EC, 0x990C7478, 0x0106 }, // ?m_fSoft@mmOpponentImpactAudio@@0MA
    { 0x63C1F0, 0x8D4D7E85, 0x010D }, // ?m_fMedium@mmOpponentImpactAudio@@0MA
    { 0x63C1F4, 0x17300F96, 0x0115 }, // ?m_fMinSoftVolume@mmOpponentImpactAudio@@0MA
    { 0x63C1F8, 0x42723B04, 0x011A }, // ?m_fMaxSoftVolume@mmOpponentImpactAudio@@0MA
    { 0x63C1FC, 0xCB8BE28A, 0x011F }, // ?m_fMinMedVolume@mmOpponentImpactAudio@@0MA
    { 0x63C200, 0x8EEAF569, 0x0124 }, // ?m_fMaxMedVolume@mmOpponentImpactAudio@@0MA
    { 0x63C204, 0x890EBCBA, 0x0129 }, // ?m_fMinHugeVolume@mmOpponentImpactAudio@@0MA
    { 0x63C208, 0xF475D190, 0x012E }, // ?m_fMaxHugeVolume@mmOpponentImpactAudio@@0MA
    { 0x63C490, 0xF18C3715, 0x0133 }, // ?PtxMaxSkidCount@mmWheel@@2MA
    { 0x63C9EC, 0x18B4864E, 0x0138 }, // ?YDownForceMinHeight@@3MA
    { 0x63C9F0, 0x7EE3D7FE, 0x0142 }, // ?YDownForceMaxHeight@@3MA
    { 0x63C9F4, 0x72097608, 0x014A }, // ?YDownForceMin@@3MA
    { 0x63C9F8, 0x3B909C1E, 0x0153 }, // ?YDownForceMax@@3MA
    { 0x63E260, 0xBC84F31D, 0x015B }, // ?mmEnvSetup@@3PAY03Ut_mmEnvSetup@@A
    { 0x63E4E4, 0x5665EF95, 0x0160 }, // ?BoneScale@@3MA
    { 0x63F1D8, 0xDE4C3155, 0x016D }, // ?ZREAD@@3HA
    { 0x63F1DC, 0xDB834B3F, 0x017D }, // ?ZWRITE@@3HA
    { 0x63F1E0, 0xC77AA3BE, 0x018B }, // ?MULTIPASS@@3HA
    { 0x63F1E4, 0x15CB7E84, 0x0192 }, // ?ScreenClearY@@3MA
    { 0x63F1E8, 0x0B55815C, 0x0199 }, // ?EnableSubClip@@3HA
    { 0x63F1EC, 0xE7D10C99, 0x01A6 }, // ?ShadowZBias@@3MA
    { 0x63F6B4, 0xB30B3233, 0x01B3 }, // ?EnableSphereCull@@3HA
    { 0x63F828, 0xE75C6D10, 0x01BC }, // ?LodTable@mmInstance@@2PAY132MA
    { 0x63F8B8, 0x5B58E869, 0x01FC }, // ?EnableFacadeSideClipping@@3HA
    { 0x63FC50, 0xE07297FB, 0x0205 }, // ?Color@mmSky@@2IA
    { 0x63FC54, 0x22B60A09, 0x020E }, // ?SkyScale@@3MA
    { 0x6401C0, 0x68AA48A6, 0x0216 }, // ?StaticTerrainLodTable@@3PAY01MA
    { 0x6401E0, 0xD1B80803, 0x022C }, // ?ObjectMaxDist@@3MA
    { 0x6401E4, 0x1EE5B573, 0x0239 }, // ?EnableSlide@@3HA
    { 0x640A60, 0x4849F4A5, 0x0001 }, // ?GameType_PenaltyTable@@3PAHA
    { 0x640A88, 0x60980DFB, 0x0001 }, // ?Limit_ValueTable@@3PAHA
    { 0x641198, 0x5FC0F29E, 0x0001 }, // ?GoldHPScale@@3MA
    { 0x64119C, 0x9DFF1DD9, 0x0001 }, // ?GoldDamageScale@@3MA
    { 0x641848, 0x01924581, 0x0244 }, // ?UI_LEFT_MARGIN@UIMenu@@2MA
    { 0x64184C, 0xF8491783, 0x0281 }, // ?UI_LEFT_MARGIN2@UIMenu@@2MA
    { 0x641850, 0x842168F6, 0x028C }, // ?UI_TOP_MARGIN@UIMenu@@2MA
    { 0x641854, 0x8D8E2194, 0x0001 }, // ?UI_BOTTOM_MARGIN@UIMenu@@2MA
    { 0x641858, 0x5817156A, 0x0299 }, // ?WIDGET_WIDTH@UIMenu@@2MA
    { 0x64185C, 0xB62F88E4, 0x02C1 }, // ?WIDGET_HEIGHT@UIMenu@@2MA
    { 0x6418B4, 0x952FE635, 0x02DF }, // ?DELAYTTIME@@3MA
    { 0x6420E4, 0xD300E422, 0x02E7 }, // ?s_fAudioMinDistance@mmBridgeSet@@0MA
    { 0x6420E8, 0xC2E08788, 0x02EC }, // ?s_fCloserMinDistMult@mmBridgeSet@@0MA
    { 0x6420EC, 0xCE5C3B68, 0x02F1 }, // ?s_fAudioMaxDistance@mmBridgeSet@@0MA
    { 0x6420F0, 0xCEB83A9B, 0x02FF }, // ?s_fAudioVolume@mmBridgeSet@@0MA
    { 0x6426F4, 0x6B00EE5E, 0x0304 }, // ?s_fAudioMinDistance@mmAnimPlane@@0MA
    { 0x6426F8, 0x6D3B6E15, 0x0309 }, // ?s_fCloserMinDistMult@mmAnimPlane@@0MA
    { 0x6426FC, 0x2FFB52EE, 0x030E }, // ?s_fAudioMaxDistance@mmAnimPlane@@0MA
    { 0x642700, 0x88A49A88, 0x031A }, // ?s_fAudioVolume@mmAnimPlane@@0MA
    { 0x642780, 0xD4C37310, 0x031F }, // ?s_fAudioMinDistance@mmAnimTrain@@0MA
    { 0x642784, 0x5F4969BF, 0x0324 }, // ?s_fCloserMinDistMult@mmAnimTrain@@0MA
    { 0x642788, 0x74A347B6, 0x0329 }, // ?s_fAudioMaxDistance@mmAnimTrain@@0MA
    { 0x64278C, 0xC8A2B046, 0x0335 }, // ?s_fAudioVolume@mmAnimTrain@@0MA
    { 0x642808, 0x617BE1C8, 0x033A }, // ?cb@@3PAMA
    { 0x642848, 0x5EE2B3CA, 0x033F }, // ?GSFDef@@3MA
    { 0x642C8C, 0xF517A9ED, 0x0348 }, // ?ExpensiveShadows@@3HA
    { 0x642E44, 0x2630CB89, 0x034D }, // ?ParticleMultiplier@@3MA
    { 0x643E6C, 0x6C3F3AAD, 0x0001 }, // ?CallImpactCallbacks@@3HA
    { 0x647DD8, 0x9184B1E3, 0x0362 }, // ?aOutputFormats@@3PAUtag_fd@@A
    { 0x649C9C, 0xA3BA81DC, 0x0371 }, // ?NUMBERSTRING@@3PADA
    { 0x649D8C, 0x9527D08A, 0x037B }, // ?Lighter@asMeshSetForm@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    { 0x64A0D8, 0x27810B26, 0x0385 }, // ?BuiltinClut@asSparkLut@@0PAIA
    { 0x64A348, 0xB3F7F616, 0x038A }, // ?Lighter@mmVehicleForm@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    { 0x64A3E0, 0xF7699799, 0x0390 }, // ?MaxOpaqueSetCount@agiTexSorter@@2HA
    { 0x64A3E4, 0x7CC8F1F4, 0x0397 }, // ?MaxAlphaSetCount@agiTexSorter@@2HA
    { 0x64A3E8, 0xB128C2D9, 0x039E }, // ?MaxVertsPerSet@agiTexSorter@@2HA
    { 0x64A3EC, 0x81BBA395, 0x03A7 }, // ?MaxIndicesPerSet@agiTexSorter@@2HA
    { 0x64A3F0, 0x8E5798B7, 0x03B0 }, // ?EnableTexSorting@@3HA
    { 0x64A3F4, 0xC1DE3B69, 0x0001 }, // ?InitialZMode@agiTexSorter@@2HA
    { 0x64A6DC, 0x8730F785, 0x03BA }, // ?DepthScale@agiMeshSet@@2MA
    { 0x64A6E0, 0x6F138C05, 0x03DC }, // ?DepthOffset@agiMeshSet@@2MA
    { 0x64A6E4, 0x2203FBC2, 0x0001 }, // ?ShadowFudge@@3MA
    { 0x64A6E8, 0x33ED2C25, 0x03FE }, // ?ShadowColor@@3IA
    { 0x64A6EC, 0x57367412, 0x040A }, // ?SphMapColor@@3IA
    { 0x64A730, 0x731AC3A0, 0x0416 }, // ?DefaultQuad@agiMeshSet@@2PAUagiMeshCardVertex@@A
    { 0x64A770, 0x01F98F56, 0x042A }, // ?MaxCardSize@@3MA
    { 0x64ABB8, 0x6CE91749, 0x0431 }, // ?agiMeshLighterMin@@3MA
    { 0x64ABBC, 0x18172F80, 0x0442 }, // ?agiMeshLighterMax@@3MA
    { 0x64ABC0, 0x64D02246, 0x044A }, // ?agiMeshLighterConeRange2@@3MA
    { 0x64ABC8, 0xEB911C63, 0x0452 }, // ?agiMeshLighterSpecularExponent@@3MA
    { 0x64ACD8, 0x57835429, 0x045A }, // ?agiRQ@@3UagiWorldRenderQuality@@A
    { 0x64B6A0, 0x63D73CA1, 0x056D }, // ?UnpackNormal@@3PAVVector3@@A
    { 0x64DF5C, 0x35BD3214, 0x05E7 }, // ?Duration@@3MA
    { 0x64E358, 0xA164682E, 0x05EF }, // ?DynaDrawMode@@3HA
    { 0x64E35C, 0x947B5ECC, 0x0001 }, // ?DynaDrawScale@@3MA
    { 0x64E7C8, 0x405893DD, 0x0624 }, // ?NoTextureCompression@@3HA
    { 0x652048, 0x8B6FB50D, 0x062B }, // ?swFbWidth@@3HA
    { 0x65204C, 0x365FC42F, 0x0641 }, // ?swFbHeight@@3HA
    { 0x65225C, 0xF1DB98AD, 0x0650 }, // ?FLIPWINDING@@3HA
    { 0x652260, 0xE571DF64, 0x065C }, // ?BACKFACE@@3HA
    { 0x652264, 0x9A09AA1C, 0x0668 }, // ?XPTHRESH@@3HA
    { 0x652268, 0xBA914911, 0x066D }, // ?YPTHRESH@@3HA
    { 0x65226C, 0x6D5AFB45, 0x0672 }, // ?PERSP2@@3HA
    { 0x652270, 0x34FF6173, 0x0677 }, // ?PERSP_THRESH@@3MA
    { 0x6522C0, 0xDD5E2B6E, 0x067D }, // ?QUADS@@3HA
    { 0x652304, 0x751F2A3C, 0x0687 }, // ?swLutInvGamma@@3MA
    { 0x652348, 0x6FC17355, 0x0001 }, // ?swCurrentEmitterSet@@3UswEmitterSet@@A
    { 0x656348, 0xB3B40FE8, 0x068F }, // ?twiddle@@3HA
    { 0x65634C, 0xEFE2C71F, 0x0698 }, // ?aa_expansion@@3MA
    { 0x656588, 0x183A545A, 0x069F }, // ?DepthOffset@@3MA
    { 0x65658C, 0x69937AA7, 0x06AA }, // ?DepthScale@@3MA
    { 0x656590, 0xE9C4213F, 0x06B5 }, // ?EarlyBackface@@3HA
    { 0x6565B8, 0x2E32873E, 0x0001 }, // ?ZFill@@3HA
    { 0x6565BC, 0xC4737044, 0x06BA }, // ?agiEnableZBuffer@@3DA
    { 0x656834, 0x18381B86, 0x0001 }, // ?MaxTexSize@@3HA
    { 0x656838, 0x1B2CB8BE, 0x06CE }, // ?TexSearchPath@@3PADA
    { 0x656BD0, 0xEA691E52, 0x0001 }, // ?ROPTS@@3UagiRenderOpts@@A
    { 0x656C30, 0xA9AC4C12, 0x06E0 }, // ?CharSet@@3PAEA
    { 0x6570F0, 0x46DC9B29, 0x06E5 }, // ?BitmapSearchPath@@3PADA
    { 0x6573E0, 0x6FE01AAA, 0x06F1 }, // ?Converter@agiShadowMap@@0NA
    { 0x657820, 0x45193366, 0x06FA }, // ?ActiveFlag@@3HA
    { 0x658A60, 0x70790B30, 0x0742 }, // ?gRandSeed@@3HA
    { 0x658D70, 0xBE506926, 0x075B }, // ?id@@3PAMA
    { 0x658DB0, 0xDFFDD324, 0x0760 }, // ?bb@@3PAMA
    { 0x658DF0, 0x21678418, 0x0765 }, // ?bt@@3PAMA
    { 0x658E30, 0xD7BFA03F, 0x076A }, // ?hb@@3PAMA
    { 0x658E70, 0x456B674E, 0x0774 }, // ?ht@@3PAMA
    { 0x65A4E0, 0x7849C3A3, 0x0779 }, // ?QuadCoplanarTolerance@@3MA
    { 0x65A548, 0xF9C5E6D1, 0x077E }, // ?asintable@@3PAMA
    { 0x65E878, 0x14C03DC2, 0x07CC }, // ?TRIGMATH_COSTABLE@@3PAMA
    { 0x65F8A0, 0x62442D44, 0x08DA }, // ?TRIGMATH_TANTABLE@@3PAMA
    { 0x6608C8, 0x673CDF27, 0x08E2 }, // ?TRIGMATH_ATANTABLE@@3PAMA
    { 0x660F10, 0x2E3281F8, 0x08ED }, // ?dxiWidth@@3HA
    { 0x660F14, 0x04BECA57, 0x090E }, // ?dxiHeight@@3HA
    { 0x660F18, 0x593C1297, 0x092E }, // ?dxiDepth@@3HA
    { 0x660F1C, 0x3E13ABD7, 0x093A }, // ?dxiFlags@@3HA
    { 0x661380, 0x6B78A297, 0x096A }, // ?dxiRendererChoice@@3HA
    { 0x661AA4, 0x1A5D0615, 0x09A3 }, // ?EnableNormalOutput@@3HA
    { 0x661AA8, 0x693F8E47, 0x09AA }, // ?EnableDebugOutput@@3HA
    { 0x661AB8, 0x9870AD7D, 0x09B1 }, // ?Printer@@3P6AXHPBDPAD@ZA
    { 0x661AC0, 0x29131BEB, 0x09C9 }, // ?__assertFailed@@3PADA
    { 0x661EF8, 0x758774FE, 0x0B9B }, // ?NoDefault@@3HA
    { 0x6620A8, 0x10B144F5, 0x0BA2 }, // ?EnableMemStat@@3HA
    { 0x6622CC, 0x21E4ADBD, 0x0BA9 }, // ?DevelopmentMode@@3HA
    { 0x662478, 0x5E1AC636, 0x0BE0 }, // ?ByteToFloatTable@@3PAMA
    { 0x671D04, 0x3877D45B, 0x0C68 }, // ?bHaveIME@@3HA
    { 0x671D08, 0x0FE05FA9, 0x0C80 }, // ?LoadScreen@@3PADA
    { 0x671D30, 0xBC7EEF78, 0x0C8B }, // ?__VtResumeSampling@@3P6AHXZA
    { 0x671E38, 0x00DF28E3, 0x0C91 }, // ?LoadTimer@@3VTimer@@A
    { 0x672040, 0xBFA4C60D, 0x0C9B }, // ?__VtPauseSampling@@3P6AHXZA
    { 0x672044, 0x45D513BF, 0x0CA2 }, // ?SystemStatsRecord@@3PAVmmGameRecord@@A
    { 0x672048, 0x13D871CB, 0x0CAB }, // ?hImmContext@@3KA
    { 0x672050, 0x778CA842, 0x0CB2 }, // ?CityName@@3PADA
    { 0x672078, 0x2125A01D, 0x0CCA }, // ?CycleTest@@3HA
    { 0x67207C, 0x5A5F8535, 0x0CD5 }, // ?SampleStats@@3HA
    { 0x672080, 0xB12CC991, 0x0CDF }, // ?DragTimer@@3HA
    { 0x672084, 0x6E037031, 0x0CE6 }, // ?CycleState@@3HA
    { 0x672088, 0xAA6A218A, 0x0CEF }, // ?GraphicsChange@@3EA
    { 0x67208C, 0xBFC65505, 0x0CFD }, // ?GraphicsPreviousMenu@@3EA
    { 0x672090, 0x11830E93, 0x0D05 }, // ?BlitzCheatTime@@3HA
    { 0x672094, 0x11C4610A, 0x0D0F }, // ?AllCars@@3HA
    { 0x67216C, 0x8F9B0966, 0x0D17 }, // ?dummyGlobal2@@3EA
    { 0x6A6D58, 0xACB67C30, 0x0D1E }, // ?ScreenClearCount@@3HA
    { 0x6A6D60, 0x9DC41302, 0x0001 }, // ?ReplayLog@@3PAVStream@@A
    { 0x6A6D68, 0xDB913E4E, 0x0D2C }, // ?mmGameManagerMetaClass@@3VMetaClass@@A
    { 0x6A6D94, 0x697675E9, 0x0D34 }, // ?Instance@mmGameManager@@0PAV1@A
    { 0x6A6D98, 0x5E6C3E29, 0x0D49 }, // ?defmass@@3MA
    { 0x6A6DA8, 0x59A9464C, 0x0D51 }, // ?mmHUDMetaClass@@3VMetaClass@@A
    { 0x6A6DD0, 0x92421D77, 0x0D59 }, // ?LastResetTime@@3MA
    { 0x6A6E18, 0x62D68364, 0x0D5F }, // ?mmInterfaceMetaClass@@3VMetaClass@@A
    { 0x6A6E40, 0xB62C2FCE, 0x0001 }, // ?szSearchPath@@3PADA
    { 0x6A6EC8, 0x980B19AA, 0x0D67 }, // ?defcarname@@3PADA
    { 0x6A6F30, 0xDDF68ADE, 0x0D88 }, // ?LocPlayerName@@3PADA
    { 0x6A6F60, 0x709A71AD, 0x0D94 }, // ?mmGameMetaClass@@3VMetaClass@@A
    { 0x6A6F90, 0x7550F47D, 0x0D9B }, // ?ProjectileV@@3VVector3@@A
    { 0x6A6FB4, 0x85309132, 0x0DB2 }, // ?masscycle@@3HA
    { 0x6A6FB8, 0x13C90EC5, 0x0DB9 }, // ?BangerProjectile@@3PAVmmBangerData@@A
    { 0x6A6FE0, 0x93FBBB92, 0x0DC0 }, // ?mmGameEditMetaClass@@3VMetaClass@@A
    { 0x6A7040, 0x47369CE5, 0x0DC8 }, // ?mmSingleBlitzMetaClass@@3VMetaClass@@A
    { 0x6A70A8, 0x0DB3E87F, 0x0DD0 }, // ?mmSingleCircuitMetaClass@@3VMetaClass@@A
    { 0x6A7110, 0xBC03C88D, 0x0DD8 }, // ?mmGameSingleMetaClass@@3VMetaClass@@A
    { 0x6A7170, 0x5FF7E6B1, 0x0DE0 }, // ?mmMultiBlitzMetaClass@@3VMetaClass@@A
    { 0x6A71B8, 0xF4E1E13D, 0x0DE8 }, // ?mmMultiCircuitMetaClass@@3VMetaClass@@A
    { 0x6A7210, 0x43F137B6, 0x0DF0 }, // ?mmMultiCRMetaClass@@3VMetaClass@@A
    { 0x6A7240, 0x6596F72E, 0x0DF8 }, // ?TwoPlayers@@3HA
    { 0x6A7280, 0x40C9EE01, 0x0E01 }, // ?mmMultiRaceMetaClass@@3VMetaClass@@A
    { 0x6A72B8, 0x35321D1D, 0x0E09 }, // ?mmDashViewMetaClass@@3VMetaClass@@A
    { 0x6A7350, 0xD8540358, 0x0E11 }, // ?mmHudMapMetaClass@@3VMetaClass@@A
    { 0x6A7378, 0x620B8347, 0x0E19 }, // ?Tris@@3PATagiVtx@@A
    { 0x6A7750, 0x8B4609D4, 0x0E3B }, // ?mmPlayerMetaClass@@3VMetaClass@@A
    { 0x6A7778, 0xFCA917E9, 0x0E43 }, // ?RestoreCityCam@@3HA
    { 0x6A7788, 0x236C71DE, 0x0E4A }, // ?Size@@3VVector3@@A
    { 0x6A77A0, 0x63B5B1C3, 0x0E7C }, // ?mmGameMultiMetaClass@@3VMetaClass@@A
    { 0x6A77E8, 0x50EAB92D, 0x0E83 }, // ?time_delta@@3MA
    { 0x6A7800, 0xD768A35A, 0x0E8A }, // ?mmWaypointInstanceMetaClass@@3VMetaClass@@A
    { 0x6A7830, 0x56774F81, 0x0E92 }, // ?_fPedUpdate@@3MA
    { 0x6A7834, 0x28A11802, 0x0E9B }, // ?_fAmbientUpdate@@3MA
    { 0x6A7838, 0x72B1187F, 0x0EA9 }, // ?_fCopUpdate@@3MA
    { 0x6A7840, 0x60DF9D85, 0x0EB0 }, // ?_nPedQty@@3HA
    { 0x6A7848, 0x9F00542E, 0x0EBB }, // ?AIMAP@@3VaiMap@@A
    { 0x6A7908, 0x06020016, 0x124B }, // ?aiMapMetaClass@@3VMetaClass@@A
    { 0x6A7934, 0xB36D517B, 0x1253 }, // ?_nRdQty@@3HA
    { 0x6A7938, 0xF3E96F1D, 0x1259 }, // ?_fOppUpdate@@3MA
    { 0x6A793C, 0x4F8B6804, 0x1263 }, // ?_nAmbientQty@@3HA
    { 0x6A7948, 0xDFDAC0AC, 0x126D }, // ?_fTotUpdate@@3MA
    { 0x6A796C, 0x773D5802, 0x1278 }, // ?AIAUDMGRPTR@@3PAVaiAudioManager@@A
    { 0x6A7970, 0x87AB5812, 0x12D1 }, // ?ObjCount@aiTrafficLightSet@@0FA
    { 0x6A79AC, 0x71301601, 0x12D9 }, // ?AIPEDAUDMGRPTR@@3PAVaiPedAudioManager@@A
    { 0x6A7A18, 0x6332A27F, 0x12F5 }, // ?s_fAttenuationMult@aiPedestrian@@0MA
    { 0x6A7A58, 0x335D07D3, 0x12FD }, // ?aiVehicleOpponentMetaClass@@3VMetaClass@@A
    { 0x6A7AA0, 0xABF7B312, 0x1305 }, // ?s_fAttenuationMult@aiVehicleAmbient@@0MA
    { 0x6A7AD0, 0x7E8AF344, 0x130E }, // ?s_iPrevSoundObjIndex@aiVehicleAmbient@@0FA
    { 0x6A7AD8, 0x0BCE6498, 0x1316 }, // ?Instance@aiVehicleManager@@2PAV1@A
    { 0x6A7AE0, 0x6CE471C8, 0x1338 }, // ?VehicleDataHash@@3VHashTable@@A
    { 0x6A7AF0, 0xE136E565, 0x1356 }, // ?aiVehicleDataMetaClass@@3VMetaClass@@A
    { 0x6A7B18, 0x3B771B1E, 0x135E }, // ?aiVehicleInstanceMetaClass@@3VMetaClass@@A
    { 0x6A7B40, 0x11A42E9F, 0x1365 }, // ?NoDataWhined@@3VHashTable@@A
    { 0x6A7B50, 0xF718E7DB, 0x137B }, // ?FloatClock@aiVehicleManager@@2MA
    { 0x6A7B54, 0x2D75D780, 0x1381 }, // ?SignalClock@aiVehicleManager@@2HA
    { 0x6A7BA0, 0xE5534A88, 0x1389 }, // ?aiVehicleSplineMetaClass@@3VMetaClass@@A
    { 0x6A7C00, 0x65101E6D, 0x1391 }, // ?aiGoalFollowWayPtsMetaClass@@3VMetaClass@@A
    { 0x6A7C40, 0x0A44488A, 0x1399 }, // ?PlayerPos@@3VVector3@@A
    { 0x6A7C50, 0x08165D52, 0x13AA }, // ?mmCarSimMetaClass@@3VMetaClass@@A
    { 0x6A7C78, 0x5B638956, 0x13B2 }, // ?HitWaterTimer@@3MA
    { 0x6A7C90, 0x033961CB, 0x13C3 }, // ?GrassTex@mmCarSim@@2PAVagiTexDef@@A
    { 0x6A7C94, 0x529061F0, 0x13D0 }, // ?DirtTex@mmCarSim@@2PAVagiTexDef@@A
    { 0x6A7C98, 0xADBC8D38, 0x13D6 }, // ?SnowTex@mmCarSim@@2PAVagiTexDef@@A
    { 0x6A7C9C, 0x77ABF48C, 0x13DC }, // ?PlayerRawSteering@mmCarSim@@2MA
    { 0x6A7CB8, 0x3E83FDA9, 0x13E4 }, // ?mmTransmissionMetaClass@@3VMetaClass@@A
    { 0x6A7CE0, 0x927A104F, 0x13EE }, // ?SURFACEAUDIOINFO@@3PAUtagSurfaceAudioInfo@@A
    { 0x6A7DF8, 0x24D79EB6, 0x15F2 }, // ?mmCarModelMetaClass@@3VMetaClass@@A
    { 0x6A7E2C, 0xFB170F87, 0x15FA }, // ?IsPlayerAutoCam@@3HA
    { 0x6A7E30, 0x93898BCB, 0x1604 }, // ?ProbeTime@mmCar@@2MA
    { 0x6A7E34, 0x1B98A465, 0x160A }, // ?TotalUpdateTime@mmCar@@2MA
    { 0x6A7E3C, 0xC5EC8110, 0x1613 }, // ?ffval@@3MA
    { 0x6A7E40, 0x242C5FF4, 0x1620 }, // ?mmCarMetaClass@@3VMetaClass@@A
    { 0x6A7E68, 0x668A401C, 0x1628 }, // ?UpdateTime@mmCar@@2MA
    { 0x6A7E6C, 0x4AA9E2A0, 0x1632 }, // ?PostUpdateTime@mmCar@@2MA
    { 0x6A7E7C, 0xF8FECDB5, 0x1638 }, // ?EggFriction@@3MA
    { 0x6A7E98, 0x43342DAA, 0x1643 }, // ?NETAUDMGRPTR@@3PAVNetAudioManager@@A
    { 0x6A7EA0, 0x8DFD187D, 0x1674 }, // ?mmSkidMetaClass@@3VMetaClass@@A
    { 0x6A7EC8, 0x2064251B, 0x167C }, // ?mmSkidManagerMetaClass@@3VMetaClass@@A
    { 0x6A7EF0, 0xDC617AB3, 0x1684 }, // ?mmShardManagerMetaClass@@3VMetaClass@@A
    { 0x6A7F18, 0x91029B39, 0x168C }, // ?Instances@mmShardManager@@1PAPAV1@A
    { 0x6A7F68, 0xB07495D6, 0x1693 }, // ?mmShardMetaClass@@3VMetaClass@@A
    { 0x6A7F90, 0xF967B987, 0x169B }, // ?NumInstances@mmShardManager@@1HA
    { 0x6A7F98, 0xAF6199F7, 0x16A6 }, // ?mmTrailerMetaClass@@3VMetaClass@@A
    { 0x6A7FC0, 0x60AD34DF, 0x16AE }, // ?s_fSecondsElapsed@mmOpponentImpactAudio@@0MA
    { 0x6A7FC4, 0x744E34DE, 0x16BA }, // ?m_fSoftVolumeMultiplier@mmOpponentImpactAudio@@0MA
    { 0x6A7FC8, 0x1EEB9CA2, 0x16C1 }, // ?m_fMedVolumeMultiplier@mmOpponentImpactAudio@@0MA
    { 0x6A7FCC, 0xCC367CCB, 0x16C8 }, // ?m_fHugeVolumeMultiplier@mmOpponentImpactAudio@@0MA
    { 0x6A7FE8, 0xF8E735CF, 0x16CF }, // ?s_iPlayingFluctuator@mmPoliceCarAudio@@0FA
    { 0x6A7FF8, 0x1553C9A4, 0x16E7 }, // ?mmOpponentCarAudioMetaClass@@3VMetaClass@@A
    { 0x6A8030, 0x260CB04E, 0x16EF }, // ?mmEngineMetaClass@@3VMetaClass@@A
    { 0x6A8058, 0xD58C1AD2, 0x16FA }, // ?mmShockMetaClass@@3VMetaClass@@A
    { 0x6A8080, 0x3CDDA530, 0x1702 }, // ?mmAxleMetaClass@@3VMetaClass@@A
    { 0x6A80B8, 0xAC88E94C, 0x170A }, // ?mmWheelMetaClass@@3VMetaClass@@A
    { 0x6A80F4, 0xB61A9697, 0x0001 }, // ?DispLatZeroThresh@@3MA
    { 0x6A80F8, 0xE582115C, 0x171A }, // ?mmDrivetrainMetaClass@@3VMetaClass@@A
    { 0x6A8120, 0xD69D3A61, 0x1722 }, // ?VehGyroMetaClass@@3VMetaClass@@A
    { 0x6A8148, 0xBD4E5D77, 0x172A }, // ?mmForceMetaClass@@3VMetaClass@@A
    { 0x6A8170, 0xAC8C3DC8, 0x1732 }, // ?mmCarRoadFFMetaClass@@3VMetaClass@@A
    { 0x6A8198, 0xDE3879B2, 0x173A }, // ?mmPlayerCarAudioMetaClass@@3VMetaClass@@A
    { 0x6A81F0, 0x2421FAD7, 0x1742 }, // ?mmNetworkCarAudioMetaClass@@3VMetaClass@@A
    { 0x6A822C, 0x6A4B2D2E, 0x174A }, // ?s_iPlayingFluctuator@mmNetworkCarAudio@@2FA
    { 0x6A8248, 0x68B7049A, 0x1762 }, // ?EngineAudioOpponentMetaClass@@3VMetaClass@@A
    { 0x6A82A0, 0xB40B7047, 0x176F }, // ?EngineAudioMetaClass@@3VMetaClass@@A
    { 0x6A8918, 0x493A2F49, 0x1779 }, // ?NETMGR@@3VasNetwork@@A
    { 0x6A8DA4, 0xD1A2BDF4, 0x1AC9 }, // ?Current@mmLoader@@0PAV1@A
    { 0x6A8DA8, 0x35B7A6BC, 0x1AEE }, // ?IntroFont@@3PAXA
    { 0x6A8DAC, 0xDE6F23E5, 0x1AF3 }, // ?myFont@@3PAXA
    { 0x6A8DCC, 0x81CDFCEB, 0x1AFE }, // ?facadeTriCount@@3HA
    { 0x6A8DD0, 0x3959AE46, 0x1B09 }, // ?EnvVel@@3MA
    { 0x6A8DDC, 0xDF50A399, 0x1B12 }, // ?ambTriCount@@3HA
    { 0x6A8DE0, 0xD720C783, 0x1B1D }, // ?carTriCount@@3HA
    { 0x6A8DE4, 0x9097AA7F, 0x1B28 }, // ?bangerTriCount@@3HA
    { 0x6A8E20, 0xC7030425, 0x1B3D }, // ?UsePixelFog@@3HA
    { 0x6A8E24, 0x9D14D1BD, 0x1B46 }, // ?pedTriCount@@3HA
    { 0x6A8E28, 0x9D95C2C7, 0x1B55 }, // ?Instance@mmCullCity@@0PAV1@A
    { 0x6A8E30, 0x8B0CC1D1, 0x1D12 }, // ?PlaneFudge@@3VVector3@@A
    { 0x6A8E40, 0x098815DE, 0x1D1C }, // ?mmCullCityMetaClass@@3VMetaClass@@A
    { 0x6A8E68, 0x82C6C0F6, 0x1D24 }, // ?FadeConstant@@3MA
    { 0x6A8E70, 0xE9414379, 0x1D2F }, // ?StaticLog@@3PAVStream@@A
    { 0x6A8E74, 0x8282E778, 0x1D3B }, // ?Phase@mmRunwayLight@@2MA
    { 0x6A8E78, 0xAA5F2BF9, 0x1D43 }, // ?FadeScale@@3MA
    { 0x6A8E7C, 0xC4C1F8C8, 0x1D4E }, // ?DisableUpper@@3HA
    { 0x6A8E90, 0x49120CB4, 0x1D55 }, // ?CachedFullSegmentTests@@3HA
    { 0x6A8E94, 0x532032B0, 0x1D67 }, // ?StartCellCollides@@3HA
    { 0x6A8EA0, 0xCE4CBB69, 0x1D71 }, // ?pass4Count@@3HA
    { 0x6A8EA8, 0xC8EA6A0A, 0x1D7C }, // ?InvLodFactor@asRenderWeb@@2MA
    { 0x6A8EAC, 0x943CDDFA, 0x1D85 }, // ?EnableCachedPoly@@3HA
    { 0x6A8EB0, 0x4F20472E, 0x1D98 }, // ?CachedFullSegmentHits@@3HA
    { 0x6A8EB4, 0x3D46540B, 0x1DA8 }, // ?SC_SVP@@3HA
    { 0x6A8EB8, 0x76A50A35, 0x1DB2 }, // ?PassMask@asRenderWeb@@2HA
    { 0x6A8EBC, 0xCB2C5B4B, 0x1DD7 }, // ?GridMtx@@3PAVMatrix34@@A
    { 0x6A8ECC, 0xDEE4432D, 0x1DDC }, // ?upperCount@@3HA
    { 0x6A8ED0, 0xC8FA9356, 0x1DE7 }, // ?pass2Count@@3HA
    { 0x6A8ED4, 0x9FE53B80, 0x1DF2 }, // ?pass3Count@@3HA
    { 0x6A8ED8, 0xCD79A7D5, 0x1DFD }, // ?SC_SVCP@@3HA
    { 0x6A8EE0, 0x32B2AB92, 0x1E07 }, // ?pass1Count@@3HA
    { 0x6A8EE8, 0xA4FE81BE, 0x1E12 }, // ?asRenderWebMetaClass@@3VMetaClass@@A
    { 0x6A8F10, 0x5036B006, 0x1E1A }, // ?PopupEnabled@@3HA
    { 0x6A8F14, 0x3BAF3635, 0x1E2B }, // ?Front2Back@@3HA
    { 0x6A8F18, 0xE4DA0346, 0x1E35 }, // ?DontClearPositions@@3HA
    { 0x6ED4E4, 0x94D8C849, 0x1E3E }, // ?WorstRoom@@3HA
    { 0x6ED4E8, 0x095583F1, 0x1E46 }, // ?LabelInstances@@3HA
    { 0x6ED4EC, 0xA6C788DA, 0x1E54 }, // ?WorstCount@@3HA
    { 0x6ED4F0, 0x228F5E70, 0x1E5E }, // ?NormalsOnInstances@@3HA
    { 0x6ED4F8, 0x8E1D3A0D, 0x1E65 }, // ?MeshSetNames@mmInstance@@2PAPADA
    { 0x6F14F8, 0x25887284, 0x1E74 }, // ?DynamicLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    { 0x6F1500, 0x3899D69A, 0x1EA1 }, // ?mmInstanceMetaClass@@3VMetaClass@@A
    { 0x6F1528, 0xE647DEA7, 0x1EB1 }, // ?mmInstanceHeap@@3V?$mmHeap@H@@A
    { 0x6F1538, 0x683E3A63, 0x1FE0 }, // ?MeshSetTable@mmInstance@@2PAUMeshSetTableEntry@1@A
    { 0x705538, 0x1AC4193E, 0x20F2 }, // ?mmMatrixInstanceMetaClass@@3VMetaClass@@A
    { 0x705560, 0x3DF2CD57, 0x2102 }, // ?ShowLights@mmInstance@@2HA
    { 0x705578, 0x088B6F11, 0x2119 }, // ?mmFacadeInstanceMetaClass@@3VMetaClass@@A
    { 0x7055A0, 0xBA04F250, 0x2121 }, // ?mmYInstanceMetaClass@@3VMetaClass@@A
    { 0x7055D0, 0x160E593B, 0x212C }, // ?LodTableIndex@mmInstance@@2HA
    { 0x7055D8, 0x409D71FF, 0x2133 }, // ?mmBuildingInstanceMetaClass@@3VMetaClass@@A
    { 0x705688, 0xB1F43890, 0x213B }, // ?StaticLighter@mmInstance@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    { 0x705690, 0xA1F96F89, 0x2167 }, // ?mmShearInstanceMetaClass@@3VMetaClass@@A
    { 0x7056C0, 0x46DAE09D, 0x216F }, // ?mmStaticInstanceMetaClass@@3VMetaClass@@A
    { 0x7056F8, 0xD631AE83, 0x217B }, // ?MeshSetSetCount@mmInstance@@2HA
    { 0x7056FC, 0x834FCC52, 0x2190 }, // ?DoFlash@mmSky@@0HA
    { 0x705700, 0xE40093AC, 0x219A }, // ?FlashTex@@3PAVagiTexDef@@A
    { 0x705704, 0x89CFFFF1, 0x21A1 }, // ?Instance@mmSky@@0PAV1@A
    { 0x705714, 0x419DD9D0, 0x21AA }, // ?VisitTag@asPortalWeb@@2GA
    { 0x705718, 0xC4A8FE6A, 0x21B8 }, // ?asPortalWebMetaClass@@3VMetaClass@@A
    { 0x705740, 0x27228085, 0x21C2 }, // ?mmPedManagerMetaClass@@3VMetaClass@@A
    { 0x705768, 0xE604A9F5, 0x21CA }, // ?mmPedMetaClass@@3VMetaClass@@A
    { 0x7057B0, 0xC8A12577, 0x21D2 }, // ?FrameFraction@mmAnimInstState@@2MA
    { 0x7057B4, 0xF392A2A1, 0x21DA }, // ?FrameDelta@mmAnimInstState@@2HA
    { 0x7057B8, 0x4F21CA7A, 0x21E2 }, // ?CRPassBoth@@3HA
    { 0x7057BC, 0x1BD0AE5D, 0x21E7 }, // ?CRPass1Only@@3HA
    { 0x7057C0, 0xEA82735F, 0x21EC }, // ?CellTriCount@@3PAHA
    { 0x7057D0, 0xC34DB740, 0x2202 }, // ?CellTypeCount@@3PAHA
    { 0x7057DC, 0x93337B01, 0x2218 }, // ?CRPass3Only@@3HA
    { 0x7057EC, 0xC03A8ADF, 0x0001 }, // ?data1@@3HA
    { 0x7057F0, 0x59D34636, 0x0001 }, // ?data2@@3HA
    { 0x7057F4, 0x965EEB53, 0x0001 }, // ?data3@@3HA
    { 0x7057F8, 0x46FBF99F, 0x0001 }, // ?data4@@3HA
    { 0x7057FC, 0x8700A805, 0x0001 }, // ?data5@@3HA
    { 0x705800, 0x569F0C33, 0x0001 }, // ?data6@@3HA
    { 0x705820, 0x64986748, 0x221D }, // ?RenderToSystemMemory@@3HA
    { 0x705824, 0x6B93BBDD, 0x0001 }, // ?TextureLevel@@3HA
    { 0x705958, 0x375C7879, 0x2221 }, // ?PUOptionsConfig@@3PAVmmPlayerConfig@@A
    { 0x70595C, 0xCD7E2BF4, 0x222F }, // ?UI_RIGHT_MARGIN@UIMenu@@2MA
    { 0x705960, 0x42B84B69, 0x2234 }, // ?Instance@MenuManager@@2PAV1@A
    { 0x7059A0, 0xC3F4649F, 0x250F }, // ?UIBMLabelMetaClass@@3VMetaClass@@A
    { 0x7059D0, 0x658DBAEB, 0x2517 }, // ?UIBMButtonMetaClass@@3VMetaClass@@A
    { 0x705A08, 0x2DBECD7D, 0x251F }, // ?s_pSound@UIBMButton@@0PAVAudSound@@A
    { 0x705A10, 0x9CF7C22B, 0x253F }, // ?TextHeight@UILabel@@2MA
    { 0x705C1C, 0xB8E37D05, 0x2545 }, // ?ToggleBMLoaded@UIToggleButton@@1HA
    { 0x705C20, 0x8846293B, 0x0001 }, // ?ToggleBMLoaded@UIToggleButton2@@1HA
    { 0x705C28, 0x06C6D140, 0x254B }, // ?UIVScrollBarMetaClass@@3VMetaClass@@A
    { 0x705C50, 0x0F9F600E, 0x2553 }, // ?sfPointerMetaClass@@3VMetaClass@@A
    { 0x705C78, 0xDE1F2CA5, 0x255B }, // ?TextDropWidgetMetaClass@@3VMetaClass@@A
    { 0x705CA0, 0x526F7BE3, 0x2563 }, // ?mmSliderMetaClass@@3VMetaClass@@A
    { 0x705CC8, 0x9636BCB5, 0x256B }, // ?VSWidgetMetaClass@@3VMetaClass@@A
    { 0x705CF0, 0xA6F69F9A, 0x2573 }, // ?mmToggle2MetaClass@@3VMetaClass@@A
    { 0x705D18, 0x798432D2, 0x257B }, // ?mmToggleMetaClass@@3VMetaClass@@A
    { 0x705D40, 0xEE10FF0F, 0x2583 }, // ?mmDropDownMetaClass@@3VMetaClass@@A
    { 0x705D68, 0xC77489E4, 0x258B }, // ?mmAnimMgrMetaClass@@3VMetaClass@@A
    { 0x705D98, 0xD1648B4B, 0x2593 }, // ?s_fAudioAttenuationMult@mmBridgeSet@@0MA
    { 0x705DA0, 0x2ECEAFC2, 0x259A }, // ?mmBridgeMgrMetaClass@@3VMetaClass@@A
    { 0x705DD0, 0x636A5582, 0x25A2 }, // ?mmBridgeSetMetaClass@@3VMetaClass@@A
    { 0x705DFC, 0x1011A35B, 0x25AC }, // ?Instance@mmBridgeMgr@@1PAV1@A
    { 0x705E1C, 0xD4C861A8, 0x25BE }, // ?MMBRIDGEAUDMGRPTR@@3PAVmmBridgeAudMgr@@A
    { 0x705E20, 0xBA9C2C6C, 0x25D2 }, // ?mmAnimDOFMetaClass@@3VMetaClass@@A
    { 0x705E58, 0xEEDB5C26, 0x25DA }, // ?s_fAudioAttenuationMult@mmAnimPlane@@0MA
    { 0x705E70, 0x22E6CF26, 0x25E1 }, // ?TrainHermite@@3VMatrix44@@A
    { 0x705EB0, 0x7A7647E2, 0x0001 }, // ?SplineBasis@@3VMatrix44@@A
    { 0x705EFC, 0xF176A28D, 0x25EA }, // ?s_fAudioAttenuationMult@mmAnimTrain@@0MA
    { 0x705F08, 0xA1713101, 0x25F1 }, // ?mmBoatMetaClass@@3VMetaClass@@A
    { 0x705F30, 0x28518F09, 0x25F9 }, // ?_Hermite@@3VMatrix44@@A
    { 0x705F70, 0x5079FB0B, 0x2602 }, // ?CatmullBasis@@3VMatrix44@@A
    { 0x705FB0, 0xFB443B89, 0x260B }, // ?mmBangerDataMetaClass@@3VMetaClass@@A
    { 0x705FD8, 0xA19CE93E, 0x0001 }, // ?FloatClock@mmBangerDataManager@@2MA
    { 0x705FDC, 0x203A0E9D, 0x2613 }, // ?Instance@mmBangerDataManager@@1PAV1@A
    { 0x705FF0, 0xB0FE2686, 0x0001 }, // ?SignalClock@mmBangerDataManager@@2HA
    { 0x706008, 0xF4CD8341, 0x2643 }, // ?mmBangerDataManagerMetaClass@@3VMetaClass@@A
    { 0x706048, 0x39D3B656, 0x264B }, // ?Instance@mmBangerManager@@1PAV1@A
    { 0x706060, 0x471759CC, 0x265A }, // ?Instance@mmBangerActiveManager@@1PAV1@A
    { 0x706068, 0xD0935FA5, 0x267A }, // ?MMSTATE@@3UmmStatePack@@A
    { 0x706360, 0x6972610B, 0x33FC }, // ?CHEATING@@3HA
    { 0x706368, 0x2269FF03, 0x3417 }, // ?MMCURRPLAYER@@3VmmPlayerData@@A
    { 0x7084E0, 0xEB8288CB, 0x367E }, // ?CHICAGO@@3HA
    { 0x7084E4, 0x699905D8, 0x3697 }, // ?CityListPtr@@3PAVmmCityList@@A
    { 0x7084EC, 0x235F3064, 0x371F }, // ?VehicleListPtr@@3PAVmmVehList@@A
    { 0x7084F8, 0x8AC87135, 0x37DD }, // ?mmMiscDataMetaClass@@3VMetaClass@@A
    { 0x708520, 0xF93F1E42, 0x37E5 }, // ?mmPlayerConfigMetaClass@@3VMetaClass@@A
    { 0x708548, 0xFE7C12E4, 0x37ED }, // ?mmPlayerDirectoryMetaClass@@3VMetaClass@@A
    { 0x708570, 0xE671648A, 0x37F5 }, // ?mmPlayerDataMetaClass@@3VMetaClass@@A
    { 0x708598, 0x2A8404B8, 0x37FD }, // ?mmPlayerRecordMetaClass@@3VMetaClass@@A
    { 0x7085C8, 0x6F418757, 0x3809 }, // ?mmInfoBaseMetaClass@@3VMetaClass@@A
    { 0x7085F0, 0x32162E71, 0x3825 }, // ?mmRecordMetaClass@@3VMetaClass@@A
    { 0x708618, 0xEAB23185, 0x3835 }, // ?mmPropInfoMetaClass@@3VMetaClass@@A
    { 0x708640, 0x651E66AB, 0x3841 }, // ?mmRoadSideMetaClass@@3VMetaClass@@A
    { 0x708668, 0x89BFCC4E, 0x3849 }, // ?mmRoadSectMetaClass@@3VMetaClass@@A
    { 0x708690, 0x744F2B2E, 0x3851 }, // ?mmMapDataMetaClass@@3VMetaClass@@A
    { 0x7086C0, 0x896135E7, 0x3859 }, // ?EBISECTS@@3PAVmmEdgeBodyIsect@@A
    { 0x70A548, 0x8FD7BAD4, 0x3868 }, // ?mmPhysicsMGRMetaClass@@3VMetaClass@@A
    { 0x716F70, 0xE7F04FDE, 0x3870 }, // ?Instance@mmPhysicsMGR@@1PAV1@A
    { 0x716F80, 0x151B83D8, 0x3878 }, // ?ImpactTime@@3KA
    { 0x716F88, 0x094F5133, 0x387E }, // ?PhysUpdate@@3MA
    { 0x716F90, 0x157BFB93, 0x388A }, // ?ISECTS@@3PAVmmIntersection@@A
    { 0x718590, 0x2155E3BF, 0x38A6 }, // ?physTerrainCollisions@@3KA
    { 0x718698, 0xF6601ED4, 0x38B6 }, // ?PHYS@@3VmmPhysicsMGR@@A
    { 0x7188BC, 0x93DF3F27, 0x39E3 }, // ?ImpactCallbackTime@@3KA
    { 0x7188C0, 0xA077816C, 0x39E9 }, // ?physCollisions@@3KA
    { 0x7190D0, 0xA4136954, 0x39F9 }, // ?physUpdate@@3KA
    { 0x7190E8, 0x3F48E199, 0x3A09 }, // ?asInertialCSMetaClass@@3VMetaClass@@A
    { 0x719118, 0xA9AB2A84, 0x3A11 }, // ?Joint3DofMetaClass@@3VMetaClass@@A
    { 0x719140, 0x7E559608, 0x0001 }, // ?Veldiscrepancy@@3VVector3@@A
    { 0x719150, 0x1029A406, 0x3A19 }, // ?discrepancy@@3VVector3@@A
    { 0x719160, 0x2D4481B0, 0x3A23 }, // ?asOverSampleMetaClass@@3VMetaClass@@A
    { 0x719188, 0x518C28BB, 0x3A2B }, // ?BenchOSample@@3HA
    { 0x719194, 0x8022CF2C, 0x3A30 }, // ?ImpactCallbackCount@@3HA
    { 0x7191F8, 0x791DB177, 0x3A3C }, // ?asAeroMetaClass@@3VMetaClass@@A
    { 0x719220, 0xB97B6B55, 0x3A47 }, // ?IODev@@3PAVmmIODev@@A
    { 0x719228, 0x35FD605F, 0x3A95 }, // ?mmInputMetaClass@@3VMetaClass@@A
    { 0x719250, 0x394A700C, 0x3A9D }, // ?LocStrKey@@3PADA
    { 0x719254, 0xD4D3B441, 0x3AA3 }, // ?GameInputPtr@@3PAVmmInput@@A
    { 0x719258, 0xDCF68E42, 0x3B99 }, // ?LocStrButton@@3PADA
    { 0x71925C, 0xA3864FBE, 0x3BA2 }, // ?LocStrUndef@@3PADA
    { 0x719260, 0x2578FE6C, 0x3BB0 }, // ?LocStrJoystick@@3PADA
    { 0x719264, 0xDAE1035B, 0x3BBB }, // ?UseDIKey@@3HA
    { 0x719268, 0x7B3F8027, 0x3BC3 }, // ?InputConfiguration@@3HA
    { 0x71926C, 0x17B86CC7, 0x3C12 }, // ?gpdi@@3PAUIDirectInputA@@A
    { 0x719270, 0x24956BF0, 0x3C1E }, // ?testValue@@3MA
    { 0x719288, 0xFD45A2BD, 0x3C26 }, // ?mmIODevMetaClass@@3VMetaClass@@A
    { 0x7192F8, 0x1FC4D8D1, 0x3C31 }, // ?AudManagerMetaClass@@3VMetaClass@@A
    { 0x719320, 0xBC4B8F46, 0x3C39 }, // ?AUDMGRPTR@@3PAVAudManager@@A
    { 0x719330, 0x71636EEF, 0x3D6C }, // ?DUPBUFCREATORPTR@@3PAVDupBuffCreator@@A
    { 0x719334, 0x83B10B1D, 0x3D80 }, // ?DSGlobalPtr@@3PAVDSGlobal@@A
    { 0x719350, 0xD8D3525C, 0x3DE1 }, // ?PovCamCSMetaClass@@3VMetaClass@@A
    { 0x719380, 0x552FC49F, 0x3DE9 }, // ?TrackCamCSMetaClass@@3VMetaClass@@A
    { 0x7193A8, 0xD74316FA, 0x3DF1 }, // ?mmViewCSMetaClass@@3VMetaClass@@A
    { 0x7193D8, 0x81414516, 0x3DF9 }, // ?PostCamCSMetaClass@@3VMetaClass@@A
    { 0x719400, 0xC90D6AF0, 0x3E01 }, // ?PreCamCSMetaClass@@3VMetaClass@@A
    { 0x719438, 0x2DBA5DF2, 0x3E09 }, // ?PointCamCSMetaClass@@3VMetaClass@@A
    { 0x719468, 0x70DFAE6F, 0x3E11 }, // ?AICamCSMetaClass@@3VMetaClass@@A
    { 0x719498, 0x19B20C30, 0x3E19 }, // ?PolarCamCSMetaClass@@3VMetaClass@@A
    { 0x7194C8, 0x9D24C961, 0x3E21 }, // ?CarCamCSMetaClass@@3VMetaClass@@A
    { 0x7194F8, 0xB720F921, 0x3E37 }, // ?BaseCamCSMetaClass@@3VMetaClass@@A
    { 0x719520, 0xAFDBD8ED, 0x3E41 }, // ?AppCamCSMetaClass@@3VMetaClass@@A
    { 0x719548, 0x75EBDD22, 0x3E4B }, // ?SplineMetaClass@@3VMetaClass@@A
    { 0x719570, 0x5E7E74BD, 0x3E53 }, // ?mmNumberMetaClass@@3VMetaClass@@A
    { 0x7195A4, 0x9FD91A42, 0x3E5B }, // ?SphMapTex@asMeshSetForm@@2PAVagiTexDef@@A
    { 0x7195A8, 0xC022BD58, 0x3E64 }, // ?asParticlesMetaClass@@3VMetaClass@@A
    { 0x7195D0, 0x3998752F, 0x3E6C }, // ?EnablePtxSorting@@3HA
    { 0x7195D8, 0x9803D606, 0x3E71 }, // ?asBirthRuleMetaClass@@3VMetaClass@@A
    { 0x719600, 0xDEEEC504, 0x3E83 }, // ?SLH@@3VHashTable@@A
    { 0x719610, 0x1644CC43, 0x3E97 }, // ?SphMapTex@mmVehicleForm@@2PAVagiTexDef@@A
    { 0x719614, 0x9813857D, 0x3E9C }, // ?MeshBytesPaged@@3HA
    { 0x719618, 0x16C35A18, 0x3EA7 }, // ?MeshesPaged@@3HA
    { 0x719620, 0x010DAB46, 0x3EB2 }, // ?GeometryCalls@agiTexSorter@@2HA
    { 0x719624, 0x53ED45E3, 0x3EBC }, // ?Instance@agiTexSorter@@0PAV1@A
    { 0x719628, 0xC8A0CDD5, 0x3EE9 }, // ?TextureSuffix@@3PADA
    { 0x71962C, 0x50328DCC, 0x3EF6 }, // ?EnvMapFlushes@@3HA
    { 0x719630, 0x562C1B93, 0x3F03 }, // ?OpaquePolySets@agiTexSorter@@2PAPAVagiPolySet@@A
    { 0x719730, 0x15942E64, 0x3F1F }, // ?OutOfPoolFlushes@agiTexSorter@@2HA
    { 0x719734, 0xF766A782, 0x3F2D }, // ?BigPoolFlushes@agiTexSorter@@2HA
    { 0x719738, 0x97CA021F, 0x3F3B }, // ?TriCount@agiPolySet@@2HA
    { 0x71973C, 0xAD7E78F2, 0x3FD1 }, // ?OverflowFlushes@agiTexSorter@@2HA
    { 0x719744, 0xABD08D28, 0x3FDF }, // ?OpaqueSetCount@agiTexSorter@@2HA
    { 0x719750, 0x1870EE69, 0x3FEC }, // ?EnvPolySet@agiTexSorter@@2VagiPolySet@@A
    { 0x71977C, 0xC18162E4, 0x4034 }, // ?TotalTris@agiTexSorter@@2HA
    { 0x719780, 0x171EFC1B, 0x4051 }, // ?AlphaSetCount@agiTexSorter@@2HA
    { 0x719788, 0xB2FE2610, 0x4060 }, // ?AlphaPolySets@agiTexSorter@@2PAPAVagiPolySet@@A
    { 0x719838, 0xC41C8F99, 0x4078 }, // ?DisableFogOnAlphaGlow@@3HA
    { 0x719C48, 0x4DB6265B, 0x4089 }, // ?indexCounts@agiMeshSet@@1PAFA
    { 0x719E4C, 0x06DE3D15, 0x40B0 }, // ?MtxSerial@agiMeshSet@@1IA
    { 0x719E50, 0x3CC6069A, 0x40B6 }, // ?codes@agiMeshSet@@2PAEA
    { 0x71DE50, 0x48AEA707, 0x40DA }, // ?EyePos@agiMeshSet@@2VVector3@@A
    { 0x71DE60, 0xEE930519, 0x40FA }, // ?M@agiMeshSet@@1VMatrix34@@A
    { 0x71DE90, 0x376E2DFA, 0x41E0 }, // ?OffsX@agiMeshSet@@1MA
    { 0x720E98, 0x6CBB79E5, 0x41FB }, // ?MaxY@agiMeshSet@@1MA
    { 0x720EB8, 0xCE5CE30D, 0x0001 }, // ?HitEyePlanes@agiMeshSet@@2PAVVector4@@A
    { 0x720ED8, 0x10E0C598, 0x0001 }, // ?EyePlaneCount@agiMeshSet@@2HA
    { 0x720EDC, 0x16452EAB, 0x4216 }, // ?MaxX@agiMeshSet@@1MA
    { 0x720EE0, 0x0966CCD7, 0x4231 }, // ?vertCounts@agiMeshSet@@1PAFA
    { 0x7210E0, 0x96549CAD, 0x4272 }, // ?MinY@agiMeshSet@@1MA
    { 0x7210E4, 0xEE0027D5, 0x428D }, // ?MirrorMode@agiMeshSet@@2HA
    { 0x721128, 0xAC2A9BBB, 0x429B }, // ?fogout@agiMeshSet@@1PAEA
    { 0x725128, 0x6726A7D0, 0x42C8 }, // ?ViewSerial@agiMeshSet@@1IA
    { 0x72512C, 0xF9E3AA36, 0x42D4 }, // ?ProjZW@agiMeshSet@@1MA
    { 0x725130, 0x7B3DEC11, 0x0001 }, // ?EyePlanesHit@agiMeshSet@@2HA
    { 0x72513C, 0x8E04DB63, 0x42EA }, // ?HalfWidth@agiMeshSet@@1MA
    { 0x725140, 0xC40B763F, 0x430B }, // ?nextFacet@agiMeshSet@@1PAFA
    { 0x72D140, 0xBE92D393, 0x4352 }, // ?ProjZZ@agiMeshSet@@1MA
    { 0x72D148, 0x094EF3C6, 0x4368 }, // ?LocPos@agiMeshSet@@1VVector3@@A
    { 0x72D154, 0xDE404869, 0x4378 }, // ?FlipX@agiMeshSet@@2HA
    { 0x72D158, 0xCD80E330, 0x4382 }, // ?FogValue@agiMeshSet@@2MA
    { 0x72D160, 0x8E7A3A3D, 0x43A4 }, // ?firstFacet@agiMeshSet@@1PAFA
    { 0x73D390, 0x618BF8C8, 0x43EB }, // ?MinX@agiMeshSet@@1MA
    { 0x73D398, 0xD625E337, 0x0001 }, // ?EyePlanes@agiMeshSet@@2PAVVector4@@A
    { 0x73D3B8, 0xAD3A9BFE, 0x4406 }, // ?OffsY@agiMeshSet@@1MA
    { 0x73D3BC, 0xEBCA33E7, 0x4421 }, // ?AllowEyeBackfacing@agiMeshSet@@1HA
    { 0x73D3C0, 0xDE6B4D10, 0x442C }, // ?HalfHeight@agiMeshSet@@1MA
    { 0x73D3C4, 0x035A444B, 0x444C }, // ?MinCardSize@@3MA
    { 0x73D3D8, 0xDAFCA67B, 0x4453 }, // ?minus1@@3Tmmx@@A
    { 0x73D3E0, 0x7E8CE6D8, 0x4466 }, // ?agiMeshLighterSunColor@@3VVector3@@A
    { 0x73D3F0, 0xC24A268C, 0x0001 }, // ?zero@@3Tmmx@@A
    { 0x73D3F8, 0x2A8E1499, 0x448C }, // ?keyColor@@3Tmmx@@A
    { 0x73E618, 0x347AA013, 0x449B }, // ?agiMeshLighterSun@@3VVector3@@A
    { 0x73E628, 0xCD77221F, 0x44D4 }, // ?agiMeshLighterFill1@@3VVector3@@A
    { 0x73E638, 0x6E83EFEB, 0x44F0 }, // ?agiMeshLighterFill2@@3VVector3@@A
    { 0x73E648, 0xA8FE4B8F, 0x450C }, // ?agiMeshLighterSpecularColor@@3VVector3@@A
    { 0x73E658, 0x0DCD9AF5, 0x451A }, // ?unclampSSS_3_10@@3Tmmx@@A
    { 0x73E660, 0xF356C817, 0x4529 }, // ?agiMeshLighterAmbient@@3VVector3@@A
    { 0x73E670, 0xEA426587, 0x454F }, // ?ambColor@@3Tmmx@@A
    { 0x73E678, 0xCF749C39, 0x455C }, // ?clampSSS_3_10@@3Tmmx@@A
    { 0x73E680, 0xB17A990B, 0x456B }, // ?fill1Color@@3Tmmx@@A
    { 0x73E688, 0x9FAB09AC, 0x457A }, // ?agiMeshLighterFill2Color@@3VVector3@@A
    { 0x73E6A8, 0xC8DE584A, 0x45A0 }, // ?agiMeshLighterFill1Color@@3VVector3@@A
    { 0x73E6B8, 0x7FB42657, 0x45C6 }, // ?fill2Color@@3Tmmx@@A
    { 0x73E6C0, 0xCD7F5DDB, 0x45D6 }, // ?TEXSHEET@@3VagiTexSheet@@A
    { 0x73E6E4, 0xA4E53C41, 0x461D }, // ?IsSnowing@@3HA
    { 0x73E70C, 0x60DF165C, 0x4626 }, // ?MeshCurrentObject@@3PADA
    { 0x73E720, 0x70ECCFB9, 0x4630 }, // ?MeshModelHash@@3VHashTable@@A
    { 0x73E738, 0x83CBAD03, 0x4645 }, // ?UnpackNormalMMX@@3PATmmx@@A
    { 0x73EE30, 0x498AE830, 0x464F }, // ?out@agiMeshSet@@1PAVVector4@@A
    { 0x77EE30, 0x062A3101, 0x468A }, // ?BoundBytesPaged@@3HA
    { 0x77EE38, 0xA93122B6, 0x4695 }, // ?WinID@mmBoundTemplate@@2HA
    { 0x77EE3C, 0xFF6FC4A5, 0x469A }, // ?NumIndexs@mmBoundTemplate@@2HA
    { 0x77EE44, 0x198BE5B6, 0x46B6 }, // ?BoundsPaged@@3HA
    { 0x77EE48, 0x29B40026, 0x46C1 }, // ?DrawGrid@mmBoundTemplate@@2HA
    { 0x77EED0, 0x19B34E76, 0x46C6 }, // ?ConstructionTable@mmBoundTemplate@@2PAGA
    { 0x77EED4, 0xBEF153DE, 0x46D2 }, // ?MaxPerBucket@mmBoundTemplate@@2HA
    { 0x77EED8, 0x6C2401C6, 0x46D9 }, // ?MakeTableStats@@3PAVStream@@A
    { 0x77F498, 0x1EC9BFB4, 0x0001 }, // ?LastIsect@mmBoundTemplate@@2PAGA
    { 0x77F4A0, 0x1CA85945, 0x46E9 }, // ?CollidedLines@@3PAPAHA
    { 0x77F518, 0x66309FA7, 0x46F8 }, // ?InsideVerts@@3PAHA
    { 0x77F590, 0x83E6E753, 0x4703 }, // ?IsectCount@mmBoundTemplate@@2GA
    { 0x77F594, 0x35183611, 0x4728 }, // ?VertPtr@mmBoundTemplate@@2PAVVector3@@A
    { 0x77F598, 0xA13D78C6, 0x4748 }, // ?BoundPtr@mmBoundTemplate@@2PAV1@A
    { 0x7805E8, 0x9FC2C49C, 0x4753 }, // ?ALLOCATOR@@3VasMemoryAllocator@@A
    { 0x780688, 0x0A1C9D76, 0x47C8 }, // ?CURHEAP@@3PAVasMemoryAllocator@@A
    { 0x780690, 0x81E8BADB, 0x47D6 }, // ?CRTALLOCATOR@@3VasMemoryAllocator@@A
    { 0x780730, 0xDFBB71FE, 0x47EB }, // ?CRTHEAP@@3PAEA
    { 0x790730, 0xCF1C72D1, 0x47F3 }, // ?SAFEHEAP@@3VasSafeHeap@@A
    { 0x790750, 0x37EB85E6, 0x47FF }, // ?asSimulationMetaClass@@3VMetaClass@@A
    { 0x79077C, 0x87BFE638, 0x4807 }, // ?ARTSPTR@@3PAVasSimulation@@A
    { 0x790800, 0xDD77E9BB, 0x4A76 }, // ?Argc@@3HA
    { 0x790804, 0x9969EC92, 0x4A7B }, // ?Argv@@3PAPADA
    { 0x790808, 0xC4BBFA43, 0x4A80 }, // ?VFS@@3PAVVirtualFileSystem@@A
    { 0x790820, 0x668ADC93, 0x0001 }, // ?StereoBuffer@@3HA
    { 0x790830, 0xBB288E59, 0x4A8C }, // ?DebugMemory@@3HA
    { 0x790834, 0xF478EB51, 0x4A9C }, // ?TimingCount@asNode@@2HA
    { 0x790838, 0xA3A2067C, 0x4AA4 }, // ?asNodeMetaClass@@3VMetaClass@@A
    { 0x79086C, 0x8E65E5DB, 0x4B4F }, // ?CULLMGR@@3PAVasCullManager@@A
    { 0x790880, 0x97E4DC64, 0x4BEC }, // ?asCullManagerMetaClass@@3VMetaClass@@A
    { 0x7908A8, 0x017630B3, 0x4BF4 }, // ?Update3D@@3MA
    { 0x7908B0, 0x9C837E2D, 0x4BFC }, // ?asCullableMetaClass@@3VMetaClass@@A
    { 0x7908D8, 0x49664C04, 0x4C06 }, // ?asLinearCSMetaClass@@3VMetaClass@@A
    { 0x790900, 0x627F444E, 0x4C27 }, // ?asLampMetaClass@@3VMetaClass@@A
    { 0x790928, 0xFDD5E0A1, 0x4C2F }, // ?MIDGETSPTR@@3PAVasMidgets@@A
    { 0x790930, 0x859EA59E, 0x4C4F }, // ?asFormMetaClass@@3VMetaClass@@A
    { 0x790958, 0xA2D69913, 0x4C57 }, // ?asCameraMetaClass@@3VMetaClass@@A
    { 0x790980, 0x7E2B9A17, 0x4C5F }, // ?VW@@3PAVagiViewport@@A
    { 0x790984, 0x90DE4106, 0x4C64 }, // ?PGRAPH@@3PAVasPerfGraph@@A
    { 0x790990, 0x78AD046C, 0x4C7D }, // ?asDofCSMetaClass@@3VMetaClass@@A
    { 0x7909B8, 0x4CE905CB, 0x4C85 }, // ?asViewCSMetaClass@@3VMetaClass@@A
    { 0x7909E0, 0x73D72434, 0x4C8D }, // ?ColLightCyan@@3VVector3@@A
    { 0x7909F0, 0x4FC703A0, 0x4C97 }, // ?ColCyan@@3VVector3@@A
    { 0x790A60, 0x626480C9, 0x4CA1 }, // ?ColGreen@@3VVector3@@A
    { 0x790A70, 0x3E3F1216, 0x4CC5 }, // ?ColLightGreen@@3VVector3@@A
    { 0x790A80, 0x1A0E0C54, 0x4CCF }, // ?ColGrey@@3VVector3@@A
    { 0x790A98, 0xE6DE898C, 0x4CD9 }, // ?ColBlack@@3VVector3@@A
    { 0x790AA8, 0xB0715127, 0x4CE3 }, // ?ColDarkRed@@3VVector3@@A
    { 0x790AB8, 0x54B638F8, 0x4CED }, // ?ColDarkYellow@@3VVector3@@A
    { 0x790AC8, 0xCA4FA1B4, 0x4CF7 }, // ?ColLightPurple@@3VVector3@@A
    { 0x790AD8, 0xF82C1C37, 0x4D01 }, // ?ColLightOrange@@3VVector3@@A
    { 0x790AE8, 0xF261119E, 0x4D0B }, // ?ColLightRed@@3VVector3@@A
    { 0x790B28, 0xADF06ED1, 0x4D15 }, // ?ColDarkPurple@@3VVector3@@A
    { 0x790B38, 0x743DCBAD, 0x4D1F }, // ?ColDarkBlue@@3VVector3@@A
    { 0x790B48, 0x13BBAFB8, 0x4D29 }, // ?ColDarkOrange@@3VVector3@@A
    { 0x790B58, 0xECC6746C, 0x4D37 }, // ?ColDarkCyan@@3VVector3@@A
    { 0x790B68, 0x53C69D42, 0x4D41 }, // ?ColPurple@@3VVector3@@A
    { 0x790B78, 0x49680C14, 0x4D56 }, // ?ColDarkGreen@@3VVector3@@A
    { 0x790BA8, 0xEF128615, 0x4D60 }, // ?ColYellow@@3VVector3@@A
    { 0x790BB8, 0xF6ACA6AC, 0x4D72 }, // ?ColRed@@3VVector3@@A
    { 0x790BC8, 0x1E4CD5D1, 0x4D8F }, // ?ColLightYellow@@3VVector3@@A
    { 0x790C18, 0xDB7F3087, 0x4D99 }, // ?ColLightBlue@@3VVector3@@A
    { 0x790C28, 0x81369D3F, 0x4DA7 }, // ?ColOrange@@3VVector3@@A
    { 0x790CB8, 0xD46CE2A8, 0x4DB1 }, // ?ColBlue@@3VVector3@@A
    { 0x790CC8, 0x34BDA18C, 0x4DCD }, // ?ColWhite@@3VVector3@@A
    { 0x790CD8, 0xEF30CF96, 0x4DDF }, // ?CollTestColor@@3VVector3@@A
    { 0x790CE8, 0x3D6EFF29, 0x4DF8 }, // ?PushColor@@3VVector3@@A
    { 0x790CF8, 0x37F6B737, 0x4E09 }, // ?NormalColor@@3VVector3@@A
    { 0x790D08, 0xC6EBF00B, 0x4E1A }, // ?TestColor@@3VVector3@@A
    { 0x790D18, 0x04AC6003, 0x4E2B }, // ?CloseColor@@3VVector3@@A
    { 0x790D28, 0x03953543, 0x4E35 }, // ?SpringColor@@3VVector3@@A
    { 0x790D38, 0xA181EAEA, 0x4E3F }, // ?TorqueColor@@3VVector3@@A
    { 0x790D48, 0x73262AEA, 0x4E4D }, // ?ForceColor@@3VVector3@@A
    { 0x790D58, 0x57DB9B8D, 0x4E5E }, // ?HitColor@@3VVector3@@A
    { 0x790D68, 0x4745212A, 0x4E6F }, // ?FluidColor@@3VVector3@@A
    { 0x790D78, 0x7199FC47, 0x4E79 }, // ?ImpulseColor@@3VVector3@@A
    { 0x790D88, 0x0A59A92A, 0x4E8D }, // ?MissColor@@3VVector3@@A
    { 0x790D98, 0x6F87F6E5, 0x4EA1 }, // ?VolumeColor@@3VVector3@@A
    { 0x790DA4, 0xFA138045, 0x4EAB }, // ?SphVSph@@3HA
    { 0x790DA8, 0x18E07576, 0x0001 }, // ?SphVCyl@@3HA
    { 0x790DAC, 0x0447BF2F, 0x4EB9 }, // ?SphVPoly@@3HA
    { 0x790DB0, 0x67402947, 0x4EC4 }, // ?SphVCPoly@@3HA
    { 0x790DB4, 0xE47200E2, 0x4ECF }, // ?SegVSph@@3HA
    { 0x790DB8, 0x612DDF25, 0x0001 }, // ?SegVCyl@@3HA
    { 0x790DBC, 0xD0EFAB46, 0x4EDD }, // ?SegVPoly@@3HA
    { 0x790DC0, 0x9F5ECE07, 0x4EF0 }, // ?SegVCPoly@@3HA
    { 0x790DC4, 0x3C3BA705, 0x4F03 }, // ?NoMultiTexture@@3HA
    { 0x790DC8, 0x7627D95E, 0x4F0B }, // ?MaxTexMem@@3HA
    { 0x790DCC, 0x34E42FEF, 0x4F13 }, // ?AutoMip@@3HA
    { 0x790DD0, 0x5CCCFE91, 0x4F18 }, // ?DrawLabelFArg@@3HA
    { 0x790DD4, 0x3E85506E, 0x4F21 }, // ?NoMip@@3HA
    { 0x790DD8, 0xCA61117C, 0x4F28 }, // ?NormalizedFog@@3HA
    { 0x790DDC, 0xE2F8086B, 0x4F30 }, // ?FullMip@@3HA
    { 0x790DE0, 0x631CE2E5, 0x4F35 }, // ?ForceSquare@@3HA
    { 0x790DE4, 0xA970B7ED, 0x4F3C }, // ?NoBlitHack@@3HA
    { 0x790DE8, 0x6794105B, 0x4F44 }, // ?DrawLabelPArg@@3HA
    { 0x790DF0, 0x043F1D11, 0x0001 }, // ?NoOutput@@3HA
    { 0x794DFC, 0xCB2A7927, 0x4F4D }, // ?d3ddev@@3PAUIDirect3DDevice3@@A
    { 0x794E10, 0x89789839, 0x4F93 }, // ?VtxBase@@3PAXA
    { 0x794F18, 0xD9A9E5D9, 0x4F9C }, // ?OneTexture@@3HA
    { 0x794F1C, 0xF3B36C08, 0x4FA1 }, // ?OrthoFix@@3HA
    { 0x795BD8, 0xC897D97B, 0x4FA6 }, // ?agiFOURCC@@3KA
    { 0x795C0C, 0x4207FFFE, 0x4FB0 }, // ?SeparateTextureMemories@@3HA
    { 0x795C14, 0xF7ADFB1F, 0x4FB5 }, // ?dummyGlobal@@3IA
    { 0x795C18, 0x3C07464C, 0x4FBB }, // ?AlphaPalette@@3HA
    { 0x795C20, 0x48935B0F, 0x4FC2 }, // ?NotIndependentUV@@3HA
    { 0x795C34, 0x84656AB1, 0x0001 }, // ?UseSimpleRenderer@@3HA
    { 0x795C38, 0x2975F9B2, 0x4FC7 }, // ?DontCacheTextures@@3HA
    { 0x795C88, 0xF9E2C6E0, 0x4FCE }, // ?DDIgnoreErrors@@3HA
    { 0x795C8C, 0x157C03A0, 0x4FD3 }, // ?DDNeedRestore@@3HA
    { 0x795CB0, 0x05475EB1, 0x4FDD }, // ?swScreenDesc@@3VagiSurfaceDesc@@A
    { 0x795D38, 0xCF0166F1, 0x4FE4 }, // ?swNibbleLut@@3PAEA
    { 0x795F40, 0x1CA4ADFE, 0x4FEA }, // ?bRenderToSystem@@3HA
    { 0x795F48, 0xB99DED92, 0x4FF5 }, // ?swDepthBuffer@@3PAGA
    { 0x795F4C, 0xC18DD30E, 0x5005 }, // ?FLIPLOD@@3HA
    { 0x795F50, 0x29DD7453, 0x500A }, // ?swScreen@@3PAXA
    { 0x795F54, 0x5C7C4A5D, 0x0001 }, // ?swCurrentDepthLine@@3PAGA
    { 0x795F5C, 0xCA6811D9, 0x0001 }, // ?swr_sizes@@3Tswr_sizes_t@@A
    { 0x795F60, 0x6A3895CF, 0x5014 }, // ?swFbStartFrame@@3P6AXXZA
    { 0x795F68, 0x9E8389FE, 0x501B }, // ?swr_color@@3HA
    { 0x795F6C, 0xF4367009, 0x50E9 }, // ?swr_texmask@@3HA
    { 0x795F70, 0xB860EBCF, 0x547E }, // ?EnableParabolic@@3HA
    { 0x795F74, 0xAD7C4292, 0x5483 }, // ?swFbEndFrame@@3P6AXXZA
    { 0x795F78, 0xB83DCCA9, 0x548A }, // ?swPixelSizeShift@@3HA
    { 0x795F7C, 0xEC5EC9B4, 0x5491 }, // ?swStippleTest@@3PAEA
    { 0x795F80, 0x8A78E3BC, 0x55B8 }, // ?swr_di@@3HA
    { 0x795F84, 0x2F5ECB35, 0x55BF }, // ?debugTri@@3HA
    { 0x795F88, 0x39B83F6F, 0x55C7 }, // ?swr_du@@3HA
    { 0x795F8C, 0xC67F6D37, 0x585E }, // ?swr_dv@@3HA
    { 0x795F90, 0x19FB2765, 0x5AF4 }, // ?swr_dz@@3HA
    { 0x795F98, 0x6D70F96A, 0x5CA3 }, // ?swr_zb@@3PAGA
    { 0x795FA0, 0x3AE31301, 0x5F01 }, // ?swGreenMask@@3HA
    { 0x795FA8, 0xEF2ABF75, 0x5F08 }, // ?debugTriGate@@3HA
    { 0x795FAC, 0x733E0F2A, 0x5F10 }, // ?swActualScreenStride@@3IA
    { 0x795FB0, 0x8416762B, 0x5F17 }, // ?swClampAdd@@3P6IIII@ZA
    { 0x795FF8, 0x32C206AC, 0x5FDD }, // ?swFbStartScene@@3P6AXXZA
    { 0x795FFC, 0xAA252018, 0x5FE6 }, // ?swBlueMask@@3HA
    { 0x796044, 0xA6877E05, 0x5FED }, // ?swIsInterlaced@@3HA
    { 0x796048, 0xE66D8159, 0x6009 }, // ?BADEDGE@@3HA
    { 0x79604C, 0xFB93FB1C, 0x0001 }, // ?swr_texstride@@3HA
    { 0x796090, 0xD0C03223, 0x6011 }, // ?swr_i@@3HA
    { 0x796094, 0xB777C730, 0x601C }, // ?swr_ddu@@3HA
    { 0x796098, 0x6738F0D1, 0x613D }, // ?swr_ddv@@3HA
    { 0x79609C, 0x76685D63, 0x625F }, // ?swr_u@@3HA
    { 0x7960A0, 0xD4D37C93, 0x6609 }, // ?swr_v@@3HA
    { 0x7960A4, 0x5E25DF84, 0x699F }, // ?swr_z@@3HA
    { 0x7960AC, 0xA0E04193, 0x6B3A }, // ?swCurrentScanline@@3PAXA
    { 0x7960B0, 0x099B24A7, 0x6B3F }, // ?swBytesPerPixel@@3HA
    { 0x7960B4, 0x03A17FAB, 0x0001 }, // ?swFbParent@@3PAXA
    { 0x7960B8, 0x530BD884, 0x6B46 }, // ?swFrameOffset@@3IA
    { 0x7960BC, 0xAE141A41, 0x6B4B }, // ?swFbEnd@@3P6AXXZA
    { 0x7960C0, 0x41CDA8C4, 0x6B52 }, // ?swRedMask@@3HA
    { 0x7960C4, 0xFEF2C8DE, 0x6B5C }, // ?swr_dest@@3PAXA
    { 0x7960C8, 0x95FCC6CB, 0x6EEF }, // ?swFbEndScene@@3P6AXXZA
    { 0x7960CC, 0x8C0F955F, 0x6EF8 }, // ?swFbStart@@3P6AXXZA
    { 0x7960D0, 0x393870D2, 0x6EFF }, // ?swCurrentLut@@3PAGA
    { 0x79BEE4, 0xC3F6ADF5, 0x7194 }, // ?swr_texshift@@3HA
    { 0x79BEE8, 0x9EFBE385, 0x73D5 }, // ?debugTriMatch@@3HA
    { 0x79BEF0, 0xF918AC6C, 0x0001 }, // ?swInfo@@3UswRastInfo@@A
    { 0x79FF00, 0xC920FA7E, 0x73DF }, // ?swr_src@@3PAXA
    { 0x79FF04, 0x6843895F, 0x765C }, // ?swScreenStride@@3IA
    { 0x79FF08, 0xB67295C7, 0x7669 }, // ?swFbX@@3HA
    { 0x79FF0C, 0x982259F0, 0x766F }, // ?swFbY@@3HA
    { 0x79FF10, 0xC6BA4E73, 0x7675 }, // ?LODBIAS@@3HA
    { 0x7E0020, 0x48F7FA4F, 0x767A }, // ?RGBLIGHTER@@3VagiRGBLighter@@A
    { 0x7E0028, 0x1FF41DA7, 0x7682 }, // ?Positional@agiLighter@@2PADA
    { 0x7E0038, 0x4BF68748, 0x768C }, // ?ShadowMap@agiLighter@@2PAVagiShadowMap@@A
    { 0x7E0040, 0x25FF6C07, 0x7693 }, // ?LIGHTS@agiLighter@@2PAPAVagiLight@@A
    { 0x7E0080, 0x5422AAC9, 0x769F }, // ?Attenuate@agiLighter@@2PADA
    { 0x7E0090, 0xEF95041E, 0x76A8 }, // ?Eye@agiLighter@@2VVector3@@A
    { 0x7E009C, 0xBE7B524C, 0x76BC }, // ?Current@agiLighter@@2HA
    { 0x7E00A0, 0xCC9F9265, 0x76C6 }, // ?SceneCurrent@agiLighter@@2HA
    { 0x7E00A4, 0x0FB2902D, 0x76CF }, // ?LMODEL@agiLighter@@2PAVagiLightModel@@A
    { 0x7E00A8, 0x8437DE81, 0x76DC }, // ?LocalViewer@agiLighter@@2HA
    { 0x7E00B0, 0xB1EFD361, 0x76E6 }, // ?Pos@agiLighter@@2PAVVector3@@A
    { 0x7E0170, 0x04010BC1, 0x770F }, // ?ACTIVELIGHTS@agiLighter@@2PAPAVagiLight@@A
    { 0x7E01B0, 0x031D8C5D, 0x771E }, // ?Dir@agiLighter@@2PAVVector3@@A
    { 0x7E0270, 0xAD4B4A66, 0x7732 }, // ?CosSpread@agiLighter@@2PAMA
    { 0x7E02B0, 0x3642994C, 0x773B }, // ?SceneActive@agiLighter@@2HA
    { 0x7E02B4, 0xCC20E144, 0x774A }, // ?MONOLIGHTER@@3VagiMonoLighter@@A
    { 0x7E02B8, 0x5694AAF2, 0x7752 }, // ?SceneAmbient@agiLighter@@2VVector3@@A
    { 0x7E02C8, 0xBBD1664D, 0x776C }, // ?ProjZW@agiProjVtx@@2MA
    { 0x7E02CC, 0x9FCECC4A, 0x7777 }, // ?NoModelView@agiProjVtx@@2HA
    { 0x7E02D0, 0xB6165FE3, 0x777C }, // ?OffsX@agiProjVtx@@2MA
    { 0x7E02D8, 0x496541DD, 0x7787 }, // ?Vtx@agiProjVtx@@2PATagiVtx@@A
    { 0x8B31D8, 0x13F83D7D, 0x7A76 }, // ?M@agiProjVtx@@2VMatrix34@@A
    { 0x8B3208, 0xB70259CC, 0x7AAB }, // ?ProjYZ@agiProjVtx@@2MA
    { 0x8B320C, 0x936CDF6B, 0x7AB2 }, // ?clip_pz@@3HA
    { 0x8B3210, 0x1F4A55B5, 0x7AB9 }, // ?HalfHeight@agiProjVtx@@2MA
    { 0x8B3214, 0x586B2BBF, 0x7AC4 }, // ?ProjX@agiProjVtx@@2MA
    { 0x8B3220, 0x4D3D18EE, 0x7ACD }, // ?Adj@agiProjVtx@@2PAUagiAdjunctData@@A
    { 0x8B9B98, 0x09EEC58A, 0x7B58 }, // ?LIGHTER@agiProjVtx@@2PAVagiLighter@@A
    { 0x8B9BA0, 0x4257F9ED, 0x7B5F }, // ?M2@agiProjVtx@@2VMatrix34@@A
    { 0x8B9BD0, 0x3F00D498, 0x7B7E }, // ?ProjXZ@agiProjVtx@@2MA
    { 0x8B9BD4, 0xF239B210, 0x7B85 }, // ?ScreenHeight@agiProjVtx@@2MA
    { 0x8B9BD8, 0x24630051, 0x7B8A }, // ?Orthographic@agiProjVtx@@2HA
    { 0x8B9BDC, 0xB2D699E1, 0x7B92 }, // ?ProjY@agiProjVtx@@2MA
    { 0x8B9BE0, 0x17035C57, 0x7B9B }, // ?NeedsClip@agiProjVtx@@2HA
    { 0x8B9BE4, 0xB62C2F0F, 0x7BA2 }, // ?ProjZZ@agiProjVtx@@2MA
    { 0x8B9BE8, 0x346BB466, 0x7BAD }, // ?OffsY@agiProjVtx@@2MA
    { 0x8BABF0, 0xB6574E91, 0x7BB8 }, // ?ScreenWidth@agiProjVtx@@2MA
    { 0x8BABF4, 0x61D66817, 0x7BBD }, // ?HalfWidth@agiProjVtx@@2MA
    { 0x8BABF8, 0x91665757, 0x7BC9 }, // ?SurfaceCount@agiSurfRenderer@@1HA
    { 0x8BABFC, 0xD5E79AE8, 0x7BE8 }, // ?VertexCount@agiSurfRenderer@@1HA
    { 0x8BAC00, 0x095B7972, 0x7C1F }, // ?NoClip@@3HA
    { 0x8BAC08, 0xD28A9A95, 0x7C2E }, // ?SurfaceHeap@agiSurfRenderer@@1PAUagiSurface@@A
    { 0x8FAC14, 0x65F0A08A, 0x7C49 }, // ?ZTrick@@3HA
    { 0x8FAC18, 0x0504E567, 0x7C4E }, // ?STATS@@3UagiStats@@A
    { 0x8FAC5C, 0x801325BB, 0x7D7B }, // ?agiBeginFrame@@3KA
    { 0x8FAC60, 0xADABFCE7, 0x7D86 }, // ?agiLightTimer@@3KA
    { 0x8FAC64, 0xE0F1F180, 0x7D99 }, // ?agiCopyBitmap@@3KA
    { 0x8FAC68, 0xD4B30920, 0x7DA7 }, // ?agiBitmapPixels@@3HA
    { 0x8FAC6C, 0x04B2FA5B, 0x7DB5 }, // ?agiEndFrame@@3KA
    { 0x8FAC70, 0x9F08ED69, 0x7DC6 }, // ?agiBitmapCount@@3HA
    { 0x8FACA0, 0x9B86F7E4, 0x7DD4 }, // ?agiTraverseTimer@@3KA
    { 0x8FACA4, 0x0A950B7D, 0x7DE6 }, // ?agiEndScene@@3KA
    { 0x8FACA8, 0x4AF6C3DA, 0x7DF7 }, // ?agiBeginScene@@3KA
    { 0x8FACAC, 0x9DDC7768, 0x7E07 }, // ?CurrentRenderer@agiPipeline@@2PAVagiRenderer@@A
    { 0x8FACB0, 0x6C01B8DB, 0x7E18 }, // ?agiRasterization@@3KA
    { 0x8FACB4, 0x2B59FEB7, 0x7E2E }, // ?CurrentPipe@agiPipeline@@2PAV1@A
    { 0x8FACB8, 0xA2989490, 0x80E2 }, // ?agiSecondPass@@3KA
    { 0x8FACBC, 0xFBDFAC86, 0x80F2 }, // ?agiTransformTimer@@3KA
    { 0x8FACC0, 0x811BC7E2, 0x8102 }, // ?PROBER@@3P6AXPAX@ZA
    { 0x8FACC4, 0x77640BF0, 0x810A }, // ?agiInvertTimer@@3KA
    { 0x8FACC8, 0xDAEFE23A, 0x8115 }, // ?agiStateChanges@@3KA
    { 0x8FACCC, 0x19DF6415, 0x8122 }, // ?agiClipTimer@@3KA
    { 0x8FACD0, 0x40481CAD, 0x8130 }, // ?agiFirstPass@@3KA
    { 0x8FACD4, 0x2E9F77E2, 0x813D }, // ?agiClearViewport@@3KA
    { 0x8FACD8, 0x42E66EF1, 0x814C }, // ?LightCount@@3HA
    { 0x8FACDC, 0x04024F8D, 0x0001 }, // ?DrawModeOr@@3HA
    { 0x8FACE0, 0x53A0C69A, 0x8154 }, // ?DrawModeAnd@@3HA
    { 0x8FAD28, 0x6F80862D, 0x8159 }, // ?PackShift@@3HA
    { 0x8FAD2C, 0x248AB51D, 0x8164 }, // ?TexBytesPaged@@3HA
    { 0x8FAD70, 0xF2F7A4FC, 0x816F }, // ?lutQ@@3PAUlutQentry@@A
    { 0x8FAF70, 0x5279729A, 0x817E }, // ?TexLutHash@@3VHashTable@@A
    { 0x8FAF88, 0xF965DC64, 0x8193 }, // ?TEXCACHE@@3VDataCache@@A
    { 0x8FAFC8, 0x962C6195, 0x81BB }, // ?TexsPaged@@3HA
    { 0x8FAFD0, 0x0696B318, 0x81C6 }, // ?DLPTemplateBadHash@@3VHashTable@@A
    { 0x8FAFE0, 0xA476F8D5, 0x81DB }, // ?FlagGetDLPTemplateCalls@@3HA
    { 0x8FAFE8, 0x09790198, 0x81DF }, // ?agiPhysLib@@3V?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@A
    { 0x8FF040, 0x29E486E5, 0x8275 }, // ?ViewSerial@agiViewParameters@@2IA
    { 0x8FF044, 0x583DDE7B, 0x82A1 }, // ?MtxSerial@agiViewParameters@@2IA
    { 0x8FF048, 0xBFB47830, 0x82DD }, // ?Active@agiViewport@@1PAV1@A
    { 0x8FF050, 0x80DEE085, 0x838B }, // ?agiLastState@@3UagiRendStateStruct@@A
    { 0x8FF090, 0xBAF8F9D5, 0x8402 }, // ?agiCurState@@3VagiRendState@@A
    { 0x8FF0D0, 0x8819B3AC, 0x89BE }, // ?RAST@@3PAVagiRasterizer@@A
    { 0x8FF0D8, 0xE97B269F, 0x89DA }, // ?agiTexLib@@3V?$agiLib@VagiTexParameters@@VagiTexDef@@@@A
    { 0x903130, 0xD0E4446F, 0x8ABD }, // ?DLPTemplateHash@@3VHashTable@@A
    { 0x903140, 0x9FA3FC2F, 0x8AD8 }, // ?BitmapHash@@3VHashTable@@A
    { 0x903190, 0x3567732F, 0x8AF1 }, // ?AnnotateTextures@@3HA
    { 0x903198, 0x8D209B3F, 0x8AFC }, // ?agiMtlLib@@3V?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@A
    { 0x907230, 0xA8A86C28, 0x8B61 }, // ?agiVerbose@@3HA
    { 0x907238, 0x3E2BCE08, 0x8B6C }, // ?agiPal@@3VagiPalette@@A
    { 0x907648, 0xBC18102B, 0x8B88 }, // ?ColorModelARGB@@3VagiColorModelARGB@@A
    { 0x907678, 0xEF46BC29, 0x8B91 }, // ?ColorModelRGB565_Rev@@3VagiColorModelRGB565_Rev@@A
    { 0x9076A8, 0xECC9A870, 0x8B9A }, // ?ColorModelABGR@@3VagiColorModelABGR@@A
    { 0x9076D8, 0x9B787298, 0x8BA3 }, // ?ColorModelRGB555_Rev@@3VagiColorModelRGB555_Rev@@A
    { 0x907708, 0xC19B366B, 0x8BAC }, // ?ColorModelRGB888_Rev@@3VagiColorModelRGB888_Rev@@A
    { 0x907738, 0x5B47C2B8, 0x8BB5 }, // ?ColorModelRGBA5551@@3VagiColorModelRGBA5551@@A
    { 0x907768, 0x1E0E5B6A, 0x8BBE }, // ?ColorModelRGBA4444@@3VagiColorModelRGBA4444@@A
    { 0x907798, 0xB1F51CB8, 0x8BC7 }, // ?ColorModelRGB888@@3VagiColorModelRGB888@@A
    { 0x9077C8, 0x4D14C9DB, 0x8BD0 }, // ?ColorModelRGB565@@3VagiColorModelRGB565@@A
    { 0x9077F8, 0x11497F14, 0x8BD9 }, // ?ColorModelRGB555@@3VagiColorModelRGB555@@A
    { 0x907868, 0xDD314CD8, 0x0001 }, // ?agiLastCardState@@3UagiCardStateStruct@@A
    { 0x907898, 0xCB4155DF, 0x8BE2 }, // ?agiCurCardState@@3VagiCardState@@A
    { 0x907950, 0x02D45282, 0x8C25 }, // ?DLPHash@@3VHashTable@@A
    { 0x907960, 0xB6DDF554, 0x8C3F }, // ?EnableBinaryFileMapping@@3HA
    { 0x907A30, 0x1A042B0B, 0x8C5B }, // ?FSCount@FileSystem@@2HA
    { 0x907A38, 0x5405A2A7, 0x8C75 }, // ?FS@FileSystem@@2PAPAV1@A
    { 0x907B38, 0x67859096, 0x8C91 }, // ?fsVerbose@@3HA
    { 0x907B40, 0x6BF82C60, 0x8CA4 }, // ?HierPrefix@@3PADA
    { 0x907BC8, 0x701471BA, 0x8CAC }, // ?HFS@@3VHierFileSystem@@A
    { 0x907BD0, 0x6255A2F4, 0x8CBB }, // ?HierAllowPath@@3PADA
    { 0x907BD4, 0x86BF4C65, 0x8CC3 }, // ?LogOpenOn@@3HA
    { 0x908BE0, 0x4B23FFD2, 0x8CD4 }, // ?__stdout@@3VFileStream@@A
    { 0x908C08, 0xA70FEFA5, 0x8CE3 }, // ?__stdin@@3VFileStream@@A
    { 0x908C34, 0x9C9D9E90, 0x8CE9 }, // ?CloseCallback@@3P6AXXZA
    { 0x908C38, 0x17D77AA3, 0x8CF0 }, // ?InitialCursorState@@3HA
    { 0x908C48, 0xF0CE6628, 0x8CFA }, // ?eqRestoreFlag@@3HA
    { 0x908C58, 0xB28BD963, 0x8CFF }, // ?eqEventReplayChannel@@3VeqEventReplayChannelClass@@A
    { 0x909290, 0xF5AE0EE0, 0x8D36 }, // ?SuperQ@eqEventHandler@@2PAV1@A
    { 0x9092C0, 0x410F9BA5, 0x8D99 }, // ?MOUSESTATE@@3U_DIMOUSESTATE@@A
    { 0x909438, 0x14647B0C, 0x8DB7 }, // ?First@eqReplayChannel@@0PAV1@A
    { 0x90943C, 0x3E48B482, 0x8DC8 }, // ?ReplayStream@eqReplay@@0PAVStream@@A
    { 0x909440, 0x8B8B7C9C, 0x8DDA }, // ?Playback@eqReplay@@2HA
    { 0x909444, 0x5462F61C, 0x8DF3 }, // ?Recording@eqReplay@@2HA
    { 0x909448, 0xE28D1186, 0x8E0E }, // ?LogRandomCalls@@3P6AXXZA
    { 0x909450, 0xD504DBD1, 0x8E1C }, // ?ORIGIN@@3VVector3@@A
    { 0x909460, 0x50D03F77, 0x8E66 }, // ?XAXIS@@3VVector3@@A
    { 0x90946C, 0x404C0A90, 0x8EC0 }, // ?Vector3Inst@@3UVector3Type@@A
    { 0x909470, 0x6A0BC817, 0x8F12 }, // ?YAXIS@@3VVector3@@A
    { 0x909480, 0x601000D8, 0x9028 }, // ?ZAXIS@@3VVector3@@A
    { 0x909490, 0xA7AEE43B, 0x9057 }, // ?IDENTITY@@3VMatrix34@@A
    { 0x9094C0, 0x871431E5, 0x908F }, // ?Matrix34MetaClass@@3VMetaClass@@A
    { 0x9094EC, 0x5278EA53, 0x909A }, // ?Vector4Inst@@3UVector4Type@@A
    { 0x9094F0, 0x2634E876, 0x909F }, // ?HermiteBasis@@3VMatrix44@@A
    { 0x909530, 0x4EBAC206, 0x90A4 }, // ?BezierBasis@@3VMatrix44@@A
    { 0x909570, 0x3CF102DB, 0x90A9 }, // ?HermiteTranspose@@3VMatrix44@@A
    { 0x9095B0, 0xDBA2E4E9, 0x90AE }, // ?BezierTranspose@@3VMatrix44@@A
    { 0x9095F0, 0x4174EAAC, 0x90B3 }, // ?Identity@@3VMatrix44@@A
    { 0x909644, 0x4CAD3E46, 0x90B8 }, // ?Vector2Inst@@3UVector2Type@@A
    { 0x909648, 0x098B65F8, 0x90BD }, // ?MathSpeed@@3HA
    { 0x90964C, 0x0D6F7554, 0x912E }, // ?OldMathSpeed@@3HA
    { 0x909650, 0xD617278D, 0x9136 }, // ?dxiIcon@@3HA
    { 0x909658, 0x59B01FD9, 0x913D }, // ?lpdsBack2@@3PAUIDirectDrawSurface4@@A
    { 0x90965C, 0xEF3C2C59, 0x9148 }, // ?lpDI@@3PAUIDirectInputA@@A
    { 0x909660, 0x541B4486, 0x9155 }, // ?lpDD4@@3PAUIDirectDraw4@@A
    { 0x909664, 0xC17E09C5, 0x9179 }, // ?lpdsFront@@3PAUIDirectDrawSurface4@@A
    { 0x909668, 0xC42F4FA1, 0x9196 }, // ?hwndMain@@3PAUHWND__@@A
    { 0x909670, 0x70FB9382, 0x91EE }, // ?lpdsBack@@3PAUIDirectDrawSurface4@@A
    { 0x909674, 0xBBF42741, 0x9202 }, // ?lpClip@@3PAUIDirectDrawClipper@@A
    { 0x909678, 0x9246AB16, 0x9210 }, // ?lpdsRend@@3PAUIDirectDrawSurface4@@A
    { 0x909680, 0xA575841F, 0x923A }, // ?dxiInfo@@3PAUdxiRendererInfo_t@@A
    { 0x90A350, 0x3AA5204C, 0x92EB }, // ?dxiRendererCount@@3HA
    { 0x90A560, 0x020A656D, 0x930E }, // ?dxiCpuSpeed@@3HA
    { 0x90A66C, 0xC106A2FA, 0x931E }, // ?TicksToSeconds@Timer@@2MA
    { 0x90A680, 0xDD2C6E36, 0x9326 }, // ?MessageFirst@@3HA
    { 0x90A684, 0x66CA61C6, 0x932F }, // ?MonoPointer@@3PAGA
    { 0x90A688, 0x415F4363, 0x933A }, // ?MessageFifo@@3PAY0FA@DA
    { 0x90A9B0, 0xA4392B65, 0x9342 }, // ?CACHE@@3VDataCache@@A
    { 0x90A9F0, 0xD5AB37EB, 0x93A6 }, // ?PAGER@@3VipcMessageQueue@@A
    { 0x90AA18, 0x19D94C92, 0x93B5 }, // ?EnablePaging@@3HA
    { 0x90AA20, 0x8F6529F8, 0x93CD }, // ?NextSerial@MetaClass@@2HA
    { 0x90AA28, 0xEEE210EE, 0x93DA }, // ?ClassIndex@MetaClass@@2PAPAV1@A
    { 0x90AE28, 0x68831AAE, 0x93E4 }, // ?Current@MetaClass@@2PAV1@A
    { 0x90AE2C, 0x3E4A7EAD, 0x93E9 }, // ?ppField@MetaClass@@2PAPAUMetaField@@A
    { 0x90AE30, 0x593BBAE5, 0x93F1 }, // ?RootMetaClass@MetaClass@@2V1@A
    { 0x90AE5C, 0x4D5BD63D, 0x9401 }, // ?First@HashTable@@0PAV1@A
    { 0x90AE60, 0xF6C7F195, 0x9458 }, // ?SynchronousMessageQueues@@3HA
    { 0x90AEA8, 0xEF407241, 0x9462 }, // ?beginStackCount@@3HA
    { 0x90AEF0, 0xFBAF9F31, 0x946E }, // ?GBArgs@@3VArgSet@@A
    { 0x90B100, 0xF9DE8F10, 0x94A1 }, // ?BaseMetaClass@@3VMetaClass@@A
    { 0x90B128, 0x96414453, 0x94B8 }, // ?NullCallback@@3VCallback@@A
    { 0x90B208, 0xBE1A7627, 0x98B1 }, // ?ProjPath@@3PADA
    { 0x90B288, 0x9B998406, 0x98CC }, // ?ImageExts@@3PADA
    { 0x90B3D0, 0xCAB46C9F, 0x98D1 }, // ?ExecPath@@3PADA
    { 0x90B474, 0x4DB0574D, 0x98DB }, // ?UnsignedCharInst@@3UUnsignedCharType@@A
    { 0x90B478, 0x62133EBC, 0x98E8 }, // ?CharInst@@3UCharType@@A
    { 0x90B47C, 0x23E01063, 0x98FE }, // ?SignedIntInst@@3USignedIntType@@A
    { 0x90B480, 0x6145356E, 0x9968 }, // ?FloatInst@@3UFloatType@@A
    { 0x90B484, 0xBEDBCBA2, 0x9A83 }, // ?SignedShortInst@@3USignedShortType@@A
    { 0x90B488, 0xB984B65F, 0x9A99 }, // ?StringInst@@3UStringType@@A
    { 0x90B48C, 0x8827B525, 0x9ABD }, // ?SignedCharInst@@3USignedCharType@@A
    { 0x90B490, 0x6D1AE016, 0x9ACC }, // ?UnsignedIntInst@@3UUnsignedIntType@@A
    { 0x90B494, 0xEEF77B01, 0x9AD7 }, // ?UnsignedShortInst@@3UUnsignedShortType@@A
    { 0x90B498, 0x3ECDA8C0, 0x9ADC }, // ?SignedInt64Inst@@3USignedInt64Type@@A
    { 0x90B4A0, 0x6B1B58CD, 0x9AE1 }, // ?UseKNI@@3HA
    { 0x90B4A4, 0x2ECEF408, 0x9AF0 }, // ?UseMMX@@3HA
    { 0x90B4A8, 0x5BF0D8B0, 0x9B00 }, // ?HavePPro@@3HA
    { 0x90B4AC, 0xF07BB052, 0x9B06 }, // ?HaveKNI@@3HA
    { 0x90B4B0, 0x12D33D75, 0x9B11 }, // ?HaveMMX@@3HA
    { 0x90B4B4, 0x1C0A4ECA, 0x9B1F }, // ?ut2float@@3MA
    { 0x90B4C0, 0x6C66AFB4, 0x9B3D }, // ?jpeg_allocated@@3HA
    // clang-format on
};
static constexpr u32 BaseSymbolData[] {
    // clang-format off
    0x01000100, 0x0022A0BB, 0x3D90B801, 0x1C1C1C48, 0x2A21371C, 0x323C3C3C, 0x96A80100, 0x2A1C483D, 0xA3010032, 0x56B15FF1, 0x2C9F0100, 0x08171DD0, 0x348F0100, 0x03050522, 0x01FE220D, 0xEB811BF6,
    0xAB010025, 0x1ACDB248, 0x0E019F0E, 0x22950100, 0x01AC7749, 0x617F11E5, 0x3001A34D, 0xA73310CD, 0x05A901D8, 0xA346BB9E, 0x14C4CC02, 0xDC67019F, 0x0001A204, 0xEF36F101, 0xEBE903F9, 0xA0010044,
    0x0ABB01C3, 0xB1FC0100, 0x000C3B01, 0x049DCA01, 0xD3900200, 0x38180003, 0xA8FC0100, 0x93010009, 0x010013A1, 0x9211F9A8, 0x039701A4, 0x92010021, 0xEC4213F3, 0x0100522D, 0xBC13F790, 0x0100412A,
    0xCB13D8C8, 0x28867918, 0x004C018E, 0x13F5BA01, 0x01BF1786, 0x09A40AAF, 0xF5EC0100, 0xDE10C713, 0x000AD910, 0x148FD901, 0x07CF0F02, 0x01000B89, 0x001BB791, 0x1BC08901, 0xD601DAAC, 0x010002B3,
    0xEE1EC6C8, 0xF1010004, 0x04D91EC6, 0xC7980100, 0x2B04E11E, 0xCBE00100, 0xE601001E, 0x01001ECB, 0x001ECC8F, 0x1ECC9501, 0xCCBE0100, 0xC401001E, 0x01001ECC, 0x001FE6C8, 0x1BD18001, 0x1904C9C9,
    0xB1010004, 0xC9A91BD1, 0xE2010004, 0xC9A31BD1, 0x01001A04, 0xE11BD293, 0x010004C8, 0x0023B6B9, 0x04ABBA01, 0x0F859122, 0x1099A425, 0xCDF70100, 0x8E4CAF23, 0x8701DE06, 0x02A00286, 0xCE9B0100,
    0xA0529823, 0x06F00281, 0x010002A0, 0xB823CDD3, 0x94010055, 0x13DB249A, 0x9DA70100, 0xE3319423, 0xBA02C554, 0xD8010001, 0x519E22FA, 0x861E58DC, 0x01000281, 0xB3239581, 0x0069A44D, 0x23D1E202,
    0x2A082A00, 0x2A083F08, 0x3F082A08, 0x2A082A08, 0x2A203F08, 0x3F082A08, 0x2A082A08, 0x2A083F08, 0x3F082A08, 0x2A082A20, 0x2A083F08, 0x3F082A08, 0x2A082A08, 0xFF789308, 0x00000301, 0x23DFC901,
    0x5301A2E7, 0xBBB00100, 0xF3A05923, 0x9B010001, 0xE39023CB, 0xF9020001, 0x2A0023DC, 0x2A083F08, 0x2A083F08, 0x02C1AD08, 0x00081627, 0x23B49C01, 0xC618C40B, 0x019602DD, 0xBCF20100, 0x0EFB4D23,
    0x0002D5B3, 0x279AF401, 0x708E3949, 0x6A545074, 0x8175536F, 0x1509D149, 0x1B151C22, 0x3C1B1B1B, 0x21142114, 0x1A1A1A14, 0x0A841539, 0x98653F24, 0xE234C604, 0x653F2416, 0xF20E048D, 0x258A019F,
    0x99A10100, 0xB41B3E27, 0x0005B07A, 0x28DAA001, 0x1DE601A4, 0x142207D7, 0xB3F30100, 0xA05A8626, 0xE16B3B33, 0xF505B051, 0x41048240, 0xB9680285, 0xA9029045, 0xD103C501, 0x6A13DB1B, 0x01816745,
    0xBA960100, 0xFB27B326, 0x65038504, 0xAD5B6672, 0x05B001A7, 0x4F8140F5, 0x86D720E7, 0x01006D01, 0xBB2DD7D6, 0x010001AF, 0x0030D5B6, 0x30D5D101, 0xAD980100, 0xC612A830, 0xEE0AD302, 0x01004D07,
    0x0030D68A, 0x31B69501, 0xB6B00100, 0x88010031, 0x01D0319E, 0x0FDF0690, 0xE2010030, 0x010031B6, 0x0031D9F5, 0x31DA9001, 0xBE880100, 0x9901D331, 0x3012B307, 0xDAC20100, 0xD8010031, 0x010031E1,
    0xE431A1F5, 0x0025A61F, 0x32C7A101, 0xC4B10100, 0xFF03981B, 0x08EE0495, 0xB003B6F2, 0x679D0FC6, 0x9A020078, 0x66003C8D, 0xF70A0280, 0x02800601, 0xCFE00100, 0xA1038D3F, 0x01001005, 0x5C01C6E5,
    0x0F3EB8D3, 0xAEF00100, 0xB3010040, 0x001F40D1, 0x40F9AB01, 0x010004F4, 0xF440F8CA, 0x84010004, 0x04F540F7, 0x010010C8, 0xF540F792, 0x0010E804, 0x23E1F001, 0xF51D9582, 0xBB010004, 0xFE0822FA,
    0x01E2ED50, 0x90D07511, 0x02A4C51C, 0x0CF006DD, 0x3E0CDF3D, 0x8001C797, 0x0002AB04, 0x24A4E601, 0x9615080C, 0x70200189, 0x991C90FD, 0x06DD02A4, 0xDF3D0CF0, 0xC79E3E0C, 0xAB03F901, 0xFE010002,
    0x08A523C0, 0xBBA25AD4, 0xF501001D, 0x8DBC14AD, 0xAA851D0F, 0xD101001E, 0x01EC14C4, 0x4D06B5A6, 0x0895833A, 0x830FC8D1, 0x80010004, 0x09AB43E2, 0xBAF60100, 0x1E01A923, 0xDC20D1CB, 0x04AC0B13,
    0x9E010002, 0x13E9448E, 0xCA01000B, 0xE1E223C2, 0xC4010020, 0xCA9B23EB, 0xA8020020, 0x894801FC, 0x9F0F08DD, 0xD5CE0001, 0x07EE0708, 0x32000E07, 0x0FC1C700, 0xE808021F, 0x0EED2022, 0x9D0F1B17,
    0x01B11006, 0x57000B20, 0x172BE417, 0x08200820, 0x01C71727, 0x0736D920, 0x8B2008D9, 0x03D13701, 0x302D8100, 0x0001CBEF, 0x2C2F06DE, 0x1003ED00, 0x00590006, 0x02812040, 0x27000D00, 0x0B001207,
    0x36001200, 0x0F001300, 0x100F2C00, 0x0E380817, 0x11000800, 0x11000F00, 0x10000417, 0x07271810, 0x09081400, 0x18038F00, 0x03BF0857, 0x5708312F, 0x402F6140, 0x2802E907, 0xAD1707D3, 0xE9980004,
    0x018B1F03, 0x1B087930, 0x1702C917, 0x08570859, 0x6A3001A7, 0xEB273C00, 0x0408098C, 0x052F0408, 0x05080408, 0x04170528, 0x0B302707, 0x0508051F, 0x0508042F, 0x09280508, 0x28070417, 0x1F079A30,
    0xCED70808, 0x0019080A, 0x590002C1, 0x00499800, 0x0EE90012, 0x2F3FB500, 0x1F011801, 0xCDBA1801, 0x57B31001, 0x01D3D31F, 0x080DBC00, 0xC5830200, 0x08090032, 0x105E0703, 0x07030709, 0x00030037,
    0x00118186, 0x03000998, 0x03080308, 0x0800060F, 0x03006600, 0x08080308, 0x1006830F, 0x07030706, 0x030037BB, 0xA80F0610, 0x0F031009, 0x07030805, 0x060007FD, 0xE8070308, 0x10060007, 0x0BA40F03,
    0x03080608, 0x01928D0F, 0x25903C08, 0x0424EF27, 0x05080527, 0x25906E08, 0x259F01E3, 0x07050805, 0x07030805, 0x01000003, 0x1C4ABFD4, 0x010009A6, 0x8136C4C8, 0x8C019702, 0x97028101, 0xEC038E01,
    0x0FF98902, 0x36F602FC, 0x0DED338D, 0xB90E33CA, 0x2363F302, 0x23202020, 0x20232020, 0xC5232320, 0x0052FC53, 0x4BC98801, 0x010043E6, 0xDF4D8BF6, 0x21018509, 0x03E206A9, 0x16DE475D, 0x2D9602E0,
    0x8BE90100, 0xE909E04D, 0x5D03E207, 0x0046C94D, 0x23D0C201, 0xE32A84A6, 0x00088E04, 0x23CFFA01, 0xE52A84D9, 0x00088D04, 0x4DC78101, 0xC7B70100, 0x9E01004D, 0x010023CC, 0x114DC6B6, 0xCFD60100,
    0x2A86CD23, 0x01000897, 0xAA23E4C0, 0x01002A8E, 0x9D53FDE0, 0x0004910C, 0x5489BC01, 0x01000491, 0x224CB0A5, 0x08A5972D, 0x9B01006B, 0x2D224CB0, 0x4508A59B, 0x8AD60100, 0x91010055, 0x92A64BD7,
    0x9E2BCF01, 0x6C01C929, 0xA402F262, 0xCE010009, 0x018F4C83, 0x26F708CC, 0xC6CB4B94, 0x0007B308, 0x5680DD01, 0xF5B70100, 0x23B4204C, 0x09AFB720, 0xB58E0100, 0x09B60454, 0x9E010004, 0xDE0B0287,
    0x01F30318, 0x0B20800D, 0x77C50A06, 0xCB05070B, 0x440708D4, 0x3D93B312, 0xB002A98F, 0xAE20EE27, 0x13A96F01, 0x30DA25BE, 0x08AB0AB6, 0x03BE3F99, 0x08B6089A, 0xEF0AE083, 0x03750309, 0x9403D525,
    0x8A010031, 0xA61C018A, 0xF41602F8, 0x830E09C0, 0x3BDDCC01, 0xECCB059A, 0x0100180F, 0x005C9888, 0x5C989901, 0x98AA0100, 0xD801005C, 0x24AC31BD, 0x002AB6CC, 0x5C98E901, 0xC6AD0100, 0x8702005C,
    0x8080599D, 0xFFFF0302, 0x08001001, 0xF5028080, 0xFF030030, 0x000601FF, 0x0280802B, 0x01FFFF03, 0x8006000A, 0x7CDC0280, 0xFFFF0300, 0x06000601, 0xBC028080, 0x01FFFF2F, 0x00120006, 0x369D000A,
    0x14000600, 0x24000A00, 0x00000600, 0x4BA6E402, 0x61002B00, 0xD6000700, 0x002B0001, 0x0022003B, 0x000DFBA2, 0x074C0803, 0x07340803, 0x758D0024, 0x56080300, 0x38080307, 0xA8002D07, 0x08030006,
    0x08030756, 0x002D0738, 0x030002A9, 0x03075608, 0x2D073808, 0x0002A600, 0x07560803, 0x07380803, 0x039A002D, 0x53080300, 0x37080307, 0xBD002A07, 0x08030001, 0x08030753, 0x002A0737, 0x030001B3,
    0x03075308, 0x2A073708, 0x0001F600, 0x07560803, 0x07380803, 0x02D6002D, 0x56080300, 0x38080307, 0xD5002D07, 0x08030002, 0x08030756, 0x002D0738, 0x0300399B, 0x03074E08, 0x03076708, 0x03074F08,
    0x03076708, 0x03074F08, 0x26075508, 0x27004D00, 0x27004D00, 0x000BE500, 0x074E0803, 0x07670803, 0x074F0803, 0x07660803, 0x074C0803, 0x07540803, 0x004D0026, 0x004C0027, 0x1EA50024, 0x01958F00,
    0x49080300, 0x000DD807, 0x07350803, 0x03000181, 0x03075908, 0x2D073408, 0x9F020000, 0x06005CE5, 0xA6020008, 0x06005CE6, 0x07018E08, 0x3ABE0100, 0x4C9BC332, 0x209726CD, 0x820FDAEE, 0x29112B04,
    0xEF6603B0, 0xAE02950A, 0xD2105101, 0xCB010012, 0x9BC32F3A, 0x9426CC4C, 0x0FDAE220, 0x232A0482, 0x6603AF19, 0x01FB0BA4, 0xA73D01DB, 0xCE010012, 0x26CC4CD6, 0x1A0FFEF2, 0xEB010027, 0x0F421421,
    0xAE2F92B5, 0xB99709A9, 0xEE3EBA13, 0x0896E24A, 0x5D07C1E6, 0x0296467A, 0xAA6C0199, 0x0306A104, 0x03180318, 0x22870315, 0xB6010003, 0xCF118B21, 0x0F8622F9, 0x868B6CEE, 0xC006D602, 0x37265816,
    0xBE03EAF4, 0x1AB116CC, 0x4203AEA5, 0xB007E797, 0x10C39301, 0x02D101B8, 0x06E01997, 0x71140EF6, 0x01000A09, 0x9DC336D8, 0xDE01005D, 0x5DA0A336, 0x29D20100, 0xEF47E0C9, 0x0EC5822D, 0x1C06DBE3,
    0xBC1C1C1C, 0x039A2E01, 0x50A80100, 0x920FB18D, 0xAB019F72, 0xB309F10D, 0xA802CC37, 0xDE23EF13, 0x02AC01C8, 0x28DD28AA, 0xC901DE22, 0xCF25DE1F, 0x4F4F07D6, 0x4C4F068E, 0x4F4C119C, 0x379F5190,
    0x9196019F, 0x01FDBE03, 0x139130F2, 0x149547B0, 0x5F283B98, 0xD9028028, 0x9E12CC03, 0xA259A401, 0xA205B102, 0x3809DE02, 0xA7340884, 0x4D16E52F, 0x822BA224, 0x198C0497, 0x4BC0109C, 0xCA01F39A,
    0xE72D8D6A, 0x229A0299, 0x91058B2C, 0x891EC601, 0x9324A801, 0xD930BF01, 0x9405BB22, 0x300FC401, 0x932604DD, 0x9D08AE15, 0x15E102B1, 0x8D2E0389, 0x8107E902, 0xC1E17C02, 0x01F28B02, 0x8801D6ED,
    0xDC019404, 0x01D0DD05, 0xE95006E1, 0xD801B401, 0x01FA9E03, 0x528E36B4, 0x9101DF1B, 0x1E29C806, 0x1F2104AD, 0xAC4C04A3, 0xFD1CB207, 0xD5059004, 0x9D09F008, 0xD916A325, 0xF90BFF0B, 0x9006F407,
    0x9E09A909, 0x8206F905, 0x84098306, 0xEC099F06, 0xF005C405, 0xCB04E905, 0xC807B105, 0xB807BC05, 0xB703D405, 0x9605F105, 0xD10CA407, 0x8107D705, 0x900BFD07, 0xD904C808, 0x5103C004, 0x0B8A5E51,
    0x58D101B8, 0x01C8089D, 0x01E601CD, 0x02B805CF, 0xDF049743, 0x8602C302, 0x79262605, 0xB54F03DC, 0xC60AFC03, 0xD806F223, 0x01822202, 0x21B047CA, 0xB7381294, 0xA5018B02, 0xEE01B001, 0x0187EF47,
    0x08A106E1, 0x01CA1E57, 0x461D02C1, 0x11B50CEE, 0x01AC66EF, 0xF66C019C, 0x7E8501A5, 0xC508ADE5, 0xC301D001, 0xDF01CC01, 0x1FF50296, 0x02E402DC, 0x01E7028C, 0x10DC05E4, 0x8D02B1DA, 0x5C019F01,
    0xCF8C615C, 0xA4355E04, 0x6D01A701, 0x049601B2, 0x05F1371F, 0x2397262D, 0x01000188, 0x685DF9C5, 0xA401007C, 0x01895E96, 0x31820100, 0x1BCC02B6, 0xB7B502A0, 0x1687BF0C, 0xAE0181A6, 0xE7640E89,
    0x01E912B8, 0x1EFC02AE, 0xC44E7ABA, 0xB22DFC1F, 0x018AEC74, 0x480D8788, 0x03940CE6, 0x0002C4C1, 0x4281CB01, 0x16171003, 0x1F034703, 0xE50D0315, 0x17100309, 0x033B0316, 0x0E031B21, 0x0C0318DD,
    0x3C110325, 0x03231303, 0x03079E0E, 0x1003250C, 0x1B1E0339, 0x16A90E03, 0x03250C03, 0x13033C11, 0x8F0E0323, 0x2110030D, 0x033E1203, 0x0D031522, 0x10032396, 0x40120321, 0x03152103, 0x030AFC0E,
    0x12032110, 0x1522033E, 0x219E0D03, 0x17161003, 0x20034603, 0xA60F0314, 0xF40F0F60, 0xBE365B0A, 0xA50D1805, 0x00090E09, 0xC221CF01, 0xBC12E701, 0xF320BD05, 0xE8F525D3, 0x01B7E804, 0x0002E4C6,
    0x8B25ED01, 0x67424201, 0x01002D95, 0x388D2E84, 0x21A10100, 0x0DDD2A86, 0x01007BF9, 0x37AC2ED8, 0xDB010004, 0x902A9A2D, 0x01001102, 0x959C3BCE, 0x8501002C, 0x2924CE26, 0x599B33BF, 0xAC01CB90,
    0xE01CD403, 0xD6E1131A, 0x84010023, 0xCC033C2C, 0x1C038919, 0x2DB00100, 0x10F51988, 0x01000294, 0x6AC746DD, 0xBA01006B, 0x0F29852C, 0x010001E8, 0xB8F854C4, 0xBEEF3701, 0x02A9AF24, 0x8DF20100,
    0x26E8B702, 0x42F10100, 0xA09E01E4, 0x01000604, 0x903542CB, 0x010002D0, 0x12018E89, 0xF301000B, 0x0FEB1379, 0xB5D1309A, 0x007DA707, 0x0193FC01, 0x000C02A1, 0x867ACA01, 0x8A0AB104, 0x07E30387,
    0x10140EA7, 0x4005C7E2, 0xAC9E0100, 0x02E7EC01, 0xCF9F0100, 0x0C029E01, 0xB1F60100, 0x01006701, 0x9E03CD9F, 0x01000C02, 0x8401D6FD, 0x01C8019F, 0x02B701C8, 0x01C801C8, 0x01C802B7, 0x01FF01C8,
    0xB902EA55, 0x00029E02, 0x03D3CE01, 0xAE01A3F0, 0x003A9A43, 0x04BEDC01, 0x02000C51, 0x0003D0E2, 0x08060806, 0xC30F4CD5, 0x0806000F, 0x0FB20806, 0xE201000F, 0x05130493, 0x9DC00100, 0x000FCC04,
    0x04D7BF01, 0x000C02AE, 0x058EFF01, 0x000C029E, 0x05D2FF01, 0x000C029E, 0x0697CF01, 0x000C029E, 0x06CB8F01, 0x000C02AE, 0x06F99F01, 0x000C02AE, 0x07EC9F01, 0x000C02AE, 0x0780DB01, 0x01975AE5,
    0xA5BF0100, 0x0C02AE08, 0xDB8F0100, 0x0C029E08, 0xBBFF0100, 0x0C029E0A, 0xA9E20200, 0x081A000A, 0x08143813, 0x08163813, 0x400E6711, 0x7711400E, 0x400E400E, 0x01A70880, 0x01004820, 0x9E0BA0FF,
    0x01000C02, 0x110B87B1, 0xB7020038, 0x02000BB5, 0x05080B00, 0x07100107, 0xCC000800, 0x0014001D, 0x620F1CD2, 0x7F001408, 0x09006607, 0x0801FD00, 0x0779001F, 0x01CA0002, 0x00005900, 0x0CCACC01,
    0x01000C51, 0xAD0CCFAE, 0xDC01000E, 0x02B10CF7, 0x9901000C, 0x19A70DAF, 0x010001B0, 0x8B0DAFBF, 0x01C2A619, 0x30B69402, 0xB0840100, 0x001CA10D, 0x0DAF9001, 0xC1AB19A4, 0x02000A04, 0x05002FCD,
    0x00338200, 0x81980005, 0xC00E0003, 0x01BF1401, 0x2C01C035, 0x01BF1500, 0x01C0018E, 0x1301BF0A, 0x672701C0, 0x00175710, 0x00230023, 0x582F0025, 0x0AA32046, 0x01BF0D48, 0x8C000B90, 0x57145804,
    0x23000BD4, 0x01982600, 0x0501D430, 0x1F019800, 0x041C0006, 0x071C0005, 0xC7170006, 0x22002302, 0x038501C0, 0x000601A4, 0x00050F3E, 0x02D32792, 0x9E00089B, 0x0AE5001C, 0x01C01300, 0x1101BF05,
    0x01C01300, 0x1001BF2B, 0xBF0501C0, 0x13001101, 0x10A501C0, 0xC00A01BF, 0x01BF2901, 0x01C001C0, 0x01BF1B97, 0x13000BA5, 0xBF0501C0, 0x13001101, 0xBF2B01C0, 0x01C01001, 0x1101BF05, 0x01C01300,
    0xBF66006A, 0xC001A201, 0x01BF5D01, 0x2F01C063, 0xC06C01BF, 0x34007F01, 0x0007C700, 0x01BF03ED, 0x3001C00A, 0x000701BF, 0x00720018, 0x01C001D4, 0x01BF1E98, 0x13000C95, 0xBF0501C0, 0x13001101,
    0xBF2B01C0, 0x01C01001, 0x1101BF05, 0x01C01300, 0xF30006EB, 0x0A01BF07, 0xBF3001C0, 0x12000701, 0xD4006F00, 0x7601C001, 0x01BF6600, 0x01C001A2, 0x6301BF5D, 0xBF2F01C0, 0x01C06C01, 0x002D007F,
    0x01BF1CC4, 0xAA0033CC, 0x31BF002E, 0x89007900, 0xB7D60040, 0x04019802, 0x001C0197, 0x97019821, 0x019702CE, 0x57B6001C, 0x006602A8, 0xA701E4C1, 0x00018F02, 0x71A2001A, 0x58E90280, 0xBF12E528,
    0x0B671B01, 0x0F000B00, 0x11001000, 0x11671D68, 0x0D000B00, 0x00018E00, 0x01D90066, 0x0001B000, 0xA3000384, 0x4901E006, 0x870AC257, 0x0001B401, 0x018807B6, 0x01872AC6, 0xF70001A3, 0x004C0006,
    0x860001AC, 0x10B20008, 0x03910280, 0x07101D00, 0xA00F0708, 0x00660702, 0x006D003A, 0x0AFD005D, 0xDE001700, 0x0023280E, 0xE42703ED, 0x02E30006, 0x0007D900, 0x1F200492, 0xBB00631F, 0x004E0001,
    0x00630064, 0x007B0072, 0x01FF12D7, 0x460001EA, 0x03D60280, 0x001CBF00, 0x040F3C8C, 0xF30F0808, 0x47364027, 0x8D4805F9, 0x1CD10023, 0x000FC14C, 0xFE4B1F9C, 0xC00001EA, 0x01EC271A, 0xBE007D00,
    0x02D70001, 0x00099E00, 0xE8000281, 0x01FE0001, 0x0001E700, 0x1B6B0018, 0x01E31CC8, 0x028010FA, 0x01FF03A3, 0x02A80BA9, 0x01BF02A1, 0x680F6708, 0xCE7C0196, 0x6401E313, 0x00019700, 0xB00004B1,
    0xE8018826, 0x86018704, 0x74028003, 0x11000D00, 0x0D000D00, 0x14000D00, 0x3F019500, 0x5801BF08, 0x01C04900, 0xD901BF1F, 0x00430006, 0x04CC0008, 0xBA004F00, 0x00100003, 0x0280039A, 0x01FF0DF8,
    0x02F50013, 0x87004900, 0x06EB000B, 0x97120198, 0x78006B01, 0x97100198, 0x80068301, 0x000EF802, 0xDC0008D2, 0x4AF80009, 0xDF09EF1F, 0x83000701, 0x02D10001, 0x13003400, 0x0003CC00, 0x140002C8,
    0x0003A900, 0x03E80061, 0x8D001B00, 0x00620008, 0x04940059, 0xBF1201C0, 0xD5006B01, 0x1001C001, 0x0BCF01BF, 0x00018000, 0x02A50026, 0x0001AF00, 0x01890061, 0xFF006100, 0x00610001, 0x7C0031F8,
    0xCB006100, 0x1502801D, 0x46005A00, 0x58005000, 0x9E001500, 0x6901FF02, 0x038F0280, 0xA705BB28, 0x27004F02, 0x63002600, 0x3D005500, 0xC2004000, 0x00190001, 0x02A806C9, 0xCB0008F8, 0xD7F30002,
    0x1202A715, 0x0ACF9100, 0x010001C0, 0x9E0EF8DF, 0x01000C02, 0x350DC8D8, 0xAFE00100, 0xAA1BAC0D, 0x010031F6, 0x840DAFB6, 0x01C29419, 0xAE9A0100, 0x1DD9540D, 0x0031F4F7, 0x03E5BB01, 0xB10185B8,
    0xDE6C9E10, 0x078CB30E, 0x01DF1A80, 0x04C303A8, 0x2402DADA, 0x9BCC05F2, 0xB0218D01, 0x01F6C402, 0x02A509B2, 0x05C016C2, 0x11950CA6, 0x4003F144, 0x80255C45, 0x3E255C01, 0x019903CF, 0x5F6602C8,
    0xEF440184, 0xD601E503, 0x01C20CA5, 0x50166DE7, 0xE3E60100, 0x0D9F8E03, 0x82F70100, 0xEA2AC60D, 0xCF2404AB, 0xF2298005, 0xD3450194, 0x01D02302, 0x03CC06C3, 0xF9AE0100, 0x01A7D811, 0xCA9F0100,
    0x0C02BE13, 0xD8CE0100, 0x9019D013, 0xDB010029, 0xA4331485, 0xEA010010, 0xABF00DC2, 0x05BE8001, 0x4B6910D4, 0x9E0E8577, 0x01AC1707, 0xE4DD09BC, 0x018EA101, 0x000393CD, 0x14A78702, 0x050F0610,
    0x19170618, 0xE7000600, 0x000F002E, 0x86000A83, 0x03F90001, 0xBF010000, 0x029E14F1, 0xC901000C, 0x0C5414EC, 0xA7F70200, 0x0F061014, 0x17061805, 0x00060019, 0xB40038A4, 0x01000005, 0x0214DB88,
    0xAFA50100, 0x2BC32E14, 0x858F0100, 0x0C02BE17, 0xC2FF0100, 0x0C02BE1A, 0x2F9D0200, 0x08070810, 0x1B91AA07, 0x06080500, 0xEF010008, 0x029E1C80, 0xC501000C, 0x03970484, 0x39023B13, 0xF706F8FE,
    0x01001281, 0x131AFCD6, 0xAE0B04D0, 0x001104DB, 0x1B81D601, 0xEB01000B, 0x000B1B81, 0x0AEC8A01, 0x0014F7D5, 0x1BFABA01, 0x029E1C91, 0xE902000C, 0x03001C9A, 0x01040104, 0x01080108, 0x06080208,
    0x05080608, 0x01080108, 0x03080308, 0x01040104, 0x01080108, 0x06080208, 0x05080608, 0x01080108, 0x02080208, 0x02040104, 0x06080608, 0x06080608, 0x06080608, 0x07080608, 0x01040310, 0x06080204,
    0x06080608, 0x06080608, 0x06080608, 0x03100708, 0x02040304, 0x06080608, 0x06080608, 0x06080608, 0x07080608, 0x01040310, 0x06080204, 0x06080608, 0x06080608, 0x06080608, 0x01FF0608, 0x58025802,
    0x87215802, 0x01040304, 0x01080104, 0x02080108, 0x06080608, 0x01080508, 0x03080108, 0x01040308, 0x01080104, 0x02080108, 0x06080608, 0x01080508, 0x02080108, 0x01040208, 0x06080204, 0x06080608,
    0x06080608, 0x06080608, 0x03100708, 0x02040104, 0x06080608, 0x06080608, 0x06080608, 0x07080608, 0x03040310, 0x06080204, 0x06080608, 0x06080608, 0x06080608, 0x03100708, 0x02040304, 0x06080608,
    0x06080608, 0x06080608, 0x06080608, 0x580201FF, 0x58025802, 0x0603F716, 0x0104020F, 0x06100204, 0x06080608, 0x05080608, 0x02080108, 0x02080608, 0x02040104, 0x06080608, 0x06080608, 0x05080608,
    0x02080108, 0x02080608, 0x02040104, 0x06080608, 0x06080608, 0x06080608, 0x06080608, 0x02080608, 0x02040104, 0x06080608, 0x06080608, 0x06080608, 0x06080608, 0x02080608, 0x02040104, 0x06080608,
    0x06080608, 0x06080608, 0x06080608, 0x05080708, 0x02040304, 0x06080608, 0x06080608, 0x06080608, 0x06080608, 0x05979808, 0x2C530483, 0x2F2B04A3, 0x2F36E52C, 0x50090029, 0x08040F05, 0x0F05272B,
    0x03A00804, 0x2B002A17, 0x95375C50, 0x20791701, 0x07080705, 0x9D0B04EE, 0x10022401, 0x06B90705, 0x24018E2B, 0x07051002, 0x2C2B0682, 0x1E071E2C, 0xBF010010, 0x02AE1CE2, 0xA701000C, 0xF90A0B86,
    0x007C11CF, 0x1FBA9701, 0xF1010009, 0xD4021CF8, 0x01000201, 0xEB1CFDC0, 0x05081704, 0x0022BEC0, 0x1D8CFF01, 0x000C02AE, 0x1CF8E401, 0x02C19D03, 0xB601001A, 0x000F1CFA, 0x04ADD001, 0x18E3CB1D,
    0x010008E7, 0x0E069FC5, 0xB30E33BA, 0x72A10E2E, 0x04BA860E, 0x2410F5CA, 0x9AB703B0, 0xE301BD03, 0xA803FB06, 0x5E02D31C, 0x134417E8, 0xC8070707, 0x00380E2A, 0x1E83BC01, 0x000C02B1, 0x1E86CC01,
    0x000C0291, 0x1EA0AC01, 0x000C02A1, 0x1E908E01, 0x010001D3, 0xB11E9CBC, 0x01000C02, 0x041E8FFF, 0x0B018209, 0xFF01002F, 0x029E1EBF, 0xCE01000C, 0x03CE1ECA, 0x01840F08, 0xCE010007, 0x05881EC6,
    0xC6F60100, 0x00058F1E, 0x1EC79E01, 0x01000596, 0xC01ED195, 0x3507EE02, 0xA902C972, 0x5601AC01, 0x6F01DA5D, 0x010001C1, 0xBE1F82CF, 0x01000C02, 0xAE1BFA9A, 0x02A103A6, 0xDF01000C, 0x029E1FA5,
    0xEF01000C, 0x029E1FAB, 0xFA01000C, 0xEF1C1BFA, 0xDE1C02C3, 0x029E01B9, 0xBC01000C, 0x02912089, 0xCC01000C, 0x02912094, 0xDC01000C, 0x0291209C, 0xDC01000C, 0x02A120B2, 0x9F01000C, 0x02AE20E2,
    0x9F01000C, 0x02BE2188, 0x8D01000C, 0x06F420EA, 0x02A9662F, 0x01960191, 0x01C4574A, 0xD401A566, 0xF8010008, 0x85CD1F81, 0xA12EEF02, 0x01000C02, 0xA520E1C6, 0x0C029E7D, 0xF4A70200, 0x08EE0001,
    0x0002E700, 0x3A0003A1, 0xA801F900, 0x01A70E01, 0x01950024, 0x01C01400, 0x01BF0195, 0x6746685A, 0x0E01A846, 0x000601A7, 0xC03A0019, 0x1702E201, 0x02E11805, 0xA703BE17, 0xCC000E01, 0x00060004,
    0x3501A04A, 0x0594019F, 0x61002A00, 0x9C001E00, 0x00480001, 0x0065005F, 0x01BC0037, 0xD2000600, 0x01AD0004, 0x10000600, 0xCA000600, 0x00060004, 0x5900019F, 0xBF0501C0, 0x30001401, 0x3802C768,
    0x1D019F0A, 0x00099500, 0x00210006, 0x000A0008, 0x00060032, 0x00380028, 0x0034003A, 0x05A60006, 0xAE002300, 0xCD01C002, 0x6801BF01, 0xBF0501C0, 0x30001401, 0x0003C568, 0x10000182, 0x74000667,
    0x03400468, 0x000601A7, 0xFB01A06D, 0x38543701, 0x019F01A1, 0x0023001F, 0x00460010, 0x0023001D, 0x02900010, 0x01F501A0, 0x9F38DE00, 0x1A086D01, 0x4D2F0328, 0x1D001100, 0x0E281A08, 0x1D003B2F,
    0xA2001000, 0x002B0001, 0x002A000E, 0x01B0004E, 0x18002400, 0x0A001400, 0xF1002200, 0x00410001, 0x000A003E, 0x01F10022, 0x49004100, 0x48281A08, 0x3E00062F, 0x2B000600, 0x39000600, 0xFE000F00,
    0x004A0002, 0x00180072, 0x00360045, 0x01C00282, 0x671A5734, 0x0023003E, 0x01B1001C, 0x04681A00, 0x29002867, 0x16000F00, 0x67039A68, 0x00410062, 0x1A080390, 0x9001D328, 0x01BF1501, 0x028C6846,
    0x45005567, 0x43685400, 0x01C01F67, 0x67065710, 0x6710681E, 0x67116828, 0x670E6827, 0x01A03AF5, 0x0AC23707, 0x0009FD38, 0x00290019, 0x003C0029, 0xE10003B0, 0x85FE0007, 0x0A019F02, 0x0F007F00,
    0xB4670268, 0x67426801, 0x038D000E, 0x004201C0, 0x2500019F, 0x57098400, 0x0888671A, 0xBA007068, 0x67320003, 0x0A0013F5, 0x0F007F00, 0xB4670268, 0x67426801, 0x038D000E, 0x003401C0, 0x2500019D,
    0x5707C300, 0x06EC6717, 0xBD007068, 0x67230003, 0xE9680C84, 0x67140001, 0x67086814, 0x01C001EF, 0xC40008A6, 0x6401BF01, 0x02680E00, 0x6801C167, 0xBF375829, 0xB2001101, 0x1101C003, 0x09B201BF,
    0x06670E68, 0xC2670E68, 0x5601C003, 0x000AD500, 0x0A0006F0, 0x0001EB57, 0x895806BE, 0x4501BF01, 0x67018268, 0xF86802E9, 0x05C75802, 0x5701CA00, 0x7D67089D, 0x570A01C0, 0xF35804C0, 0x67785703,
    0x671D682A, 0x0501C02B, 0x1E671157, 0x21672768, 0x27671168, 0x27671168, 0xD9671168, 0x9A01C002, 0x1601BF14, 0x00019100, 0x67026812, 0x1C680294, 0x01BF3F58, 0x04B0000E, 0x003401C0, 0x670E575B,
    0x670E6806, 0x2501C05E, 0x570BFE00, 0x07BC6717, 0x8C006F68, 0x04A30001, 0xA3672300, 0x01C003EC, 0x1A01B763, 0x01903528, 0x01BF0C86, 0xD90001F0, 0x58616801, 0x67605734, 0x0BCC0076, 0x0001EB68,
    0x572B5807, 0xC0786712, 0x01BF4901, 0x02FC6866, 0x87004400, 0x00066709, 0x01AB0006, 0x7D673B68, 0x8A673E68, 0x0801C002, 0x40004A57, 0x17670600, 0x98671068, 0xA601A00B, 0xBC019F02, 0x1C0015C7,
    0x06E7DA00, 0x00408F00, 0xDAF90100, 0x08D3C603, 0xE38F59C8, 0x5601C215, 0x02E422C4, 0x01F00AF0, 0xF901DF28, 0x0C049E5F, 0xC70909AF, 0x89010009, 0x010022EC, 0xB522EBED, 0x1501E201, 0xBB01003D,
    0x01F72399, 0x0601E8B7, 0xACDF0100, 0x0CE11923, 0x8901004D, 0x970714BC, 0x01F70EDD, 0xD5BF0100, 0xC3E8061C, 0x0001F706, 0x118DA001, 0x128C9108, 0xA0FB01F7, 0x05AC080F, 0x0733D907, 0xB0CA0100,
    0xF20BA623, 0xC301000E, 0xD70713B2, 0x01F70FE6, 0x0802D6E4, 0x7CAE0100, 0x03D239BC, 0x02A6FA49, 0x0DEB34BF, 0x92AD0C96, 0x2F946402, 0x9018BB64, 0xDB01DB01, 0x23E57E01, 0xFA6E17AB, 0xA601894E,
    0xDC25E821, 0x0E0D01EA, 0x08FE03EE, 0x09BB05CC, 0x0F860C8F, 0x2B9357DD, 0xA61102E2, 0x41E75B1D, 0x9209B93C, 0xF604A817, 0xE51CB302, 0xCC02CE05, 0x02807608, 0xF44601F6, 0xA608A00A, 0xC00EBA25,
    0x6205DE1B, 0x019A01BD, 0x6C52019E, 0x9201805E, 0x6201D301, 0x019A01BD, 0x6C52019E, 0x9201805E, 0x802AA701, 0x02969005, 0x15EE01E1, 0x088B05C8, 0xCB01CA08, 0xDE48AB0C, 0xC103E901, 0x3CE96C22,
    0x1604D91D, 0xC70902F7, 0x1F844F2A, 0x9B2E29C2, 0x84028D0F, 0x9C0CEC27, 0x9703C70D, 0x12019813, 0xCE02D2CE, 0x2551B52D, 0xB301A0B6, 0xBA09AB7C, 0x3269B70A, 0x049C71EF, 0x4F5A019D, 0x01F50383,
    0x4E4F018E, 0x0A9F04E2, 0x4E1501F8, 0x23019F4D, 0x04E71899, 0x01CA0189, 0xE54F01F5, 0xDA08C703, 0x11688E08, 0x08D005CE, 0x01AD09FB, 0xCD2EA626, 0xD401E03C, 0x9413BC3F, 0x23A8018C, 0x4B8405F7,
    0x1801AACB, 0x388C02B8, 0x518D14E8, 0xEA08953E, 0xD31E903F, 0xC003A80B, 0x2DF52761, 0x04BF01A4, 0xB64201ED, 0x8F02C001, 0xDE431B01, 0x87C40490, 0xDD139A06, 0xF22E9701, 0x84168205, 0x8B01CD13,
    0xDB01CD22, 0x05833523, 0x31B303B1, 0x018E05BB, 0x0AAC02F8, 0x8602A273, 0x0E02D201, 0x935601E8, 0xD709F502, 0x09B40D01, 0xA93E03DB, 0xD8280293, 0x490BB202, 0x02A0109C, 0x019711FA, 0x028D02AA,
    0x05DD01B3, 0x018A0B30, 0xAB7B0185, 0xDAE802A2, 0xB2010006, 0x01DF23C8, 0x000DDFD4, 0x23F1FF01, 0x000C029E, 0x0CF4E701, 0x8016BFFA, 0x01000F86, 0xE8239094, 0x81830C07, 0x01007003, 0xDA2383CA,
    0x01000229, 0xFA0CF4DB, 0x868016BF, 0xC701000F, 0x649122FE, 0x96840100, 0xA3A6031D, 0xC3D50302, 0xAFFA1004, 0x01006411, 0x0823FE9C, 0x6711AEE0, 0x98F30100, 0x86029523, 0x000B018C, 0x23D1A601,
    0x2EE14FEF, 0x95F10100, 0x02A3B11D, 0x8A04AA91, 0x118A8519, 0x000196C8, 0x1D96B001, 0xF502A3AD, 0xBE0204C3, 0x006311AF, 0x23FF9601, 0x11ADD216, 0xB7010079, 0xA0832383, 0x01EC5401, 0x08442542,
    0x018558FC, 0x03C4078C, 0xD50194F2, 0x8C02A004, 0xBA029702, 0x01000ADC, 0x0024A9AA, 0x23999601, 0x888001EC, 0x01000D01, 0x952398FF, 0x018A9002, 0xF901000D, 0x02952398, 0x07018B91, 0xFF9F0100,
    0xADC51523, 0x01007811, 0x95239985, 0x0188B902, 0xCF01000D, 0x02AE24AE, 0xED01000C, 0x01C709DF, 0x04FD02B3, 0xD37801E0, 0x01001AAF, 0xC823CEE3, 0x4202C654, 0xFCEB0100, 0xBA856D03, 0xE3010020,
    0xB0FF2399, 0xED010001, 0x70AA23DF, 0x2C01D8F9, 0x00370281, 0x2399E901, 0x01B09043, 0x91010018, 0x71A423E0, 0xD0E30200, 0x0FDC0724, 0x0002D708, 0x00000198, 0x13B2A401, 0x8E9D7BAC, 0x9B01F508,
    0xF80A9D07, 0x2202D501, 0x9D01DEBF, 0x090C0582, 0x9A06F316, 0x2BCC0DCD, 0x38F84D8C, 0x34CD04CC, 0xECB10100, 0x07F5EC14, 0x5408B2A4, 0x01AC2C0C, 0x87E90200, 0x0802100C, 0x05980708, 0x006BCF00,
    0x07080802, 0xA40001F4, 0x02000485, 0x81070808, 0x003C000E, 0x020006C0, 0x8B070808, 0x08020066, 0xB8E50708, 0x8B920001, 0x08020003, 0x4AC40708, 0x05D98500, 0x0A080200, 0x0002A307, 0x00019EBB,
    0x07080802, 0x810004E8, 0x08020014, 0x05D50708, 0x001FAB00, 0x0F04B6D8, 0x07071007, 0x01B81002, 0x15070200, 0x0208100F, 0x02100207, 0x070AFD08, 0x07080802, 0x02000183, 0x54070808, 0x08080B00,
    0x02005A07, 0x8A070808, 0x07080801, 0x410008E2, 0x0B080200, 0x02004307, 0x3F075C08, 0x08080200, 0x005E9807, 0x02EC002C, 0x2C002C00, 0x0F5ADA00, 0x021044F5, 0xF6070808, 0x08020002, 0x038A0708,
    0x08080200, 0x00038E07, 0x07080802, 0x020002FA, 0xC3070808, 0x001C0001, 0x005C004D, 0x007C007C, 0x48C3005C, 0x08080200, 0x0002D807, 0x07080802, 0xE20004E5, 0x06000AF9, 0xC2070A08, 0x080A0018,
    0x01BA0706, 0x3A070608, 0x0F080200, 0x000AD007, 0xBC0002AC, 0x248D001F, 0x0021FB00, 0x0000599D, 0x118D8302, 0x01808F0F, 0x0059EE00, 0x1C0007A3, 0x1C003D00, 0x0005F200, 0x003A001C, 0x0BDB001C,
    0x0001AE00, 0x5CE6001C, 0x685C8F17, 0x84912742, 0x50182702, 0x924F37C2, 0x570003CF, 0x00029200, 0xB001F0C3, 0x2801F504, 0x3702E74E, 0xE806E228, 0x23003702, 0xA87A0487, 0x37283F05, 0x283704D7,
    0x28372837, 0xA82701B2, 0x78352801, 0x01EC282F, 0x2801F828, 0x04EF02B0, 0x0598019D, 0x01A80037, 0x01B504AF, 0xC207214F, 0x50140804, 0x4F0198B1, 0xA31719AE, 0x1FC61804, 0x01F04D00, 0xC735002F,
    0x30283001, 0x2C283328, 0xCCBA01B7, 0xC8F81804, 0x00530001, 0x04AB0018, 0x1F01EB08, 0x2A0005D9, 0x3001E607, 0x821808F1, 0x18871701, 0x2801E618, 0x322802DD, 0x53776628, 0x86785228, 0xB1019F09,
    0x03D73F01, 0xA1004400, 0xB59B2879, 0x0686180C, 0xD608182F, 0x1A0002D8, 0x0808FD00, 0x1E0005F5, 0x0003C800, 0x0AB0001F, 0xCD001C07, 0x049F0805, 0xA1010000, 0x18FC1E83, 0xB106FB87, 0x9C2C0C02,
    0xC2010003, 0x939414AE, 0x06858302, 0xD6AB16B6, 0x0587DD01, 0x23E201A0, 0xA48C0100, 0x0C02B125, 0x95F90100, 0xFC0C5425, 0x0054CC09, 0x24CA8D01, 0x01000AA3, 0xC1259DDC, 0x01000C02, 0x1E0CECB2,
    0xFD09B534, 0xF3B80494, 0x1B35FD11, 0xA11B110E, 0x2E3201CB, 0x0A450A45, 0xEB019C32, 0x96D12C07, 0x04AC5F01, 0x01000191, 0xC1259ABC, 0x01000C02, 0xB70CF7C1, 0x02B118A9, 0x01002C0C, 0xE224DA9B,
    0x150F3405, 0x01C12836, 0xA78D2472, 0x00150901, 0x0CECC201, 0x18C1E83C, 0x81010033, 0x02F325AC, 0xA1EC0100, 0x0189F324, 0xF7010050, 0x118D25AF, 0xFD03F656, 0x005DED09, 0x24AEB101, 0x5101BFD7,
    0xDC01000C, 0x029125F8, 0xCC01000C, 0x02B125F5, 0xC101000C, 0x14022690, 0xE6010009, 0x1D352690, 0xEA01004A, 0x01002696, 0x002696F6, 0x2399FD02, 0x0E070810, 0x02101F07, 0xDC070207, 0x2200038A,
    0x83020000, 0x0D10239A, 0x2A070A07, 0x02070210, 0x038AC307, 0x00001100, 0x26978601, 0x248E0100, 0xBDF20100, 0x07B40C2A, 0x980DDD17, 0x01000C01, 0x002B8FDE, 0x01D6EA01, 0x070E0182, 0x0A15D310,
    0xF8200F9A, 0x58058003, 0x9701B347, 0x01B77801, 0x1F140A0C, 0x0D141E0D, 0x02A73A26, 0x4D430707, 0x0B0C0B0C, 0x2A0A3607, 0x453B0755, 0x4E31240E, 0x5D1A2A2B, 0x1201A02E, 0x14221222, 0x1F12516A,
    0x123801E9, 0xB102B33F, 0x1C018701, 0x27162863, 0x64163A41, 0x01C11440, 0x154E076B, 0x14556E31, 0x01CE1C1C, 0x01DF1123, 0x18350180, 0x09C1270E, 0x018C02B1, 0x0C260707, 0x0A2D0719, 0x2401AE34,
    0x01841211, 0x370701C6, 0x2815019A, 0x02871447, 0x0C01A606, 0x0F0F1409, 0x01A90C4C, 0x08591A7E, 0x655C018C, 0x200ACD08, 0xC30CCC0E, 0x5F1FFA17, 0x554E1FD5, 0x08068E8E, 0xDE048C2E, 0x50081402,
    0x01C81013, 0x1401EC10, 0x36071D1D, 0x31082D68, 0x1E01C207, 0x190C172A, 0x200C5407, 0x13191A2D, 0x1B101C12, 0x1F23181D, 0x074F2909, 0x0E110712, 0x080E2F08, 0x42080E2F, 0x1C12080E, 0x080E2812,
    0x0A12073D, 0x1D0A2223, 0x1D0A3307, 0x080E0A17, 0xB507130E, 0xBC641CBE, 0xFF21B303, 0x068B2604, 0x02CA0B83, 0x9008E017, 0x831C8F1B, 0xF401AC1C, 0x365E4F02, 0x3303DD1A, 0x3904861A, 0x01B801AA,
    0x1DB307EF, 0x06D812A0, 0x01AB01DC, 0x431A0EB3, 0x01A93827, 0x01E801BC, 0x01D80CA7, 0x019C13C1, 0x9A0E1ADC, 0x9606E503, 0x1804BF02, 0x3C3C158B, 0x01950AD7, 0x477101A5, 0x02952492, 0x2D02891F,
    0xC63B01EF, 0x06DE5201, 0x01B013CD, 0x0CD001C2, 0x01A06B6B, 0x04842D21, 0x01A96B6B, 0xCE152D43, 0x483A481B, 0x03F802C0, 0x0EB90191, 0x02AD1CCE, 0x029F10BC, 0x28110AE1, 0xB50B10C8, 0x04F05703,
    0x366501AB, 0xE301D062, 0xCB02FD01, 0x9802FC02, 0xBC02FC03, 0x9702BC04, 0xEF02A102, 0x8C029901, 0x9C029C02, 0xF102B702, 0xE902BC02, 0x21531301, 0x8202D16B, 0x01A13201, 0xA5581BC0, 0xBC02AC2D,
    0xA0028D1A, 0x1F01B207, 0x4C59261F, 0x286A03EE, 0x856F4971, 0x9001BF04, 0xF606DB01, 0x0D192E01, 0xDE1202F9, 0x19018F03, 0x7C3B1C2D, 0x411002B2, 0x0182059C, 0xCB317C1F, 0x02D73402, 0x168A05C0,
    0xDA38089C, 0x280BB601, 0x01A22212, 0xDE0AF442, 0x4903D316, 0x059F1DF6, 0xD6210A92, 0x02CC5B01, 0x019B09F4, 0x039408F3, 0x01974762, 0xED2608FB, 0x4107DE02, 0x8A3A0293, 0x1909AF01, 0x4C05A841,
    0x5A330FD1, 0x02F801E8, 0x1D05A91A, 0xE94C5317, 0x06C92C07, 0x214A1721, 0x1903FF2F, 0x2B3D2717, 0x03DE1313, 0x62234659, 0xE73305EF, 0xBD02D902, 0x0DA43306, 0xAB01BC34, 0x0AAB2201, 0x1B3D0286,
    0x290E4638, 0x0ED81B8E, 0x190ED957, 0x010003E3, 0x9E2D8DBF, 0x01000C02, 0x9E2DE2AF, 0x01000C02, 0x5E2DC298, 0x071B9F0C, 0x0E0E0E0E, 0x0E0E0E0E, 0x0E0E0E0E, 0x0E0E0E0E, 0x0E0E0E0E, 0x0100141E,
    0x1E2EAEED, 0x8ACD0100, 0x01000B2F, 0x9E2FAEEF, 0x01000C02, 0xA12FBBEC, 0x01000C02, 0xA12FC9FC, 0x01000C02, 0x9E2FDEBF, 0x01000C02, 0x9E2FFAEF, 0x01000C02, 0x913083DC, 0x01000C02, 0xA1308CEC,
    0x01000C02, 0x9E309EEF, 0x01000C02, 0x9E30A8FF, 0x01000C02, 0x9A30AD9E, 0xAF010028, 0x029E30E3, 0xAF01000C, 0x029E30DE, 0x0001F40C, 0x04AEEF01, 0xF0830F83, 0x01D8172B, 0xC65657D4, 0x9401000A,
    0x194E30AF, 0x05E411E1, 0x04870193, 0xFA292DC9, 0xAF010002, 0x02BE3198, 0x8E01000C, 0x1889319E, 0xBDDD0100, 0x27188F31, 0x8E010027, 0x1BE931BE, 0xFD8F0100, 0x0C029E31, 0xE28D0100, 0x2817E231,
    0xEC010028, 0x272731B0, 0x01003097, 0xFE32AEAF, 0x01000C02, 0xE604ACD9, 0x04920CD9, 0x1B0BD0FC, 0xC306AA98, 0xE44B0F82, 0x01DE210B, 0x2B1005F4, 0x8A02FC13, 0xD103F718, 0x930A9F01, 0x16A87C02,
    0x01000DBD, 0x9E32B28F, 0x01000C02, 0x8A1CB1DD, 0x8FE706C6, 0xD24C9D0F, 0xD8010002, 0xAFEB118B, 0xB005BC21, 0x0E0F4407, 0x9208A82A, 0xD9029107, 0xB501E709, 0xAF6F1701, 0xE102000B, 0x8F04A821,
    0x03BF0001, 0x082D03CF, 0x0039003D, 0x03C803EB, 0x0065001F, 0x0203CF04, 0x04900A3F, 0x0F930010, 0x04083B50, 0x04083607, 0x04083307, 0x04881C07, 0x0603D302, 0xDB030390, 0x06100603, 0x04E70607,
    0x06019006, 0x06080610, 0x06680277, 0x0218023F, 0x06070248, 0x02080218, 0xA00201BF, 0x02080204, 0x02DF0217, 0x02038002, 0x06F80608, 0x02020202, 0x8D4E0202, 0x01A03F0B, 0x1602D00E, 0x001D0497,
    0xA01D001D, 0x02EF1D04, 0x0102F04C, 0x801E02EF, 0x19082A03, 0x100203B7, 0x90020802, 0x03971D03, 0x0816475F, 0x001A0719, 0x487C0823, 0x294F03E7, 0x03E0630F, 0x06A9002F, 0x98390497, 0x07B81004,
    0x2C07B773, 0x01EB0494, 0x100D03DB, 0xEC03CC0D, 0x09049301, 0x018703DF, 0xBD070218, 0x01E90F02, 0xDF0603E0, 0x04B05A03, 0x000B0012, 0x00080009, 0x3312340A, 0x0009002B, 0x2C03C43E, 0x1DF403BB,
    0x401804E7, 0xDB0002B1, 0xA703D007, 0xBC048F15, 0x029B400A, 0xBF0F07E8, 0xCA039E05, 0x05031208, 0x22033B04, 0x0A002C00, 0x0109DF04, 0x069B37A1, 0x90410035, 0x03CB0803, 0x039701A6, 0x0001004A,
    0x9501A00D, 0x05019F02, 0x0002E100, 0x02DE0005, 0x02D60A90, 0x00110B8F, 0xBB00028F, 0x000D3702, 0x00383850, 0x00473F33, 0xBA0001BF, 0x01A64001, 0xF200463F, 0x01BC0001, 0x61000600, 0xA00C01C0,
    0x029F1C01, 0xC8790808, 0x8F079203, 0xEB006104, 0xE0023015, 0xCF029803, 0x2D006403, 0xC003C93F, 0x7F098F01, 0x05E93F11, 0x00018140, 0xEB07F838, 0x1B07F702, 0xF1001900, 0xE0060F02, 0x3003A303,
    0x0604BF07, 0x0B3F0240, 0x09000F40, 0xF840083F, 0xC0133F01, 0x00018001, 0x0401BF16, 0xB807C100, 0x13000A08, 0x06F73900, 0xA0170001, 0x05C82201, 0x10250028, 0x1E06F717, 0x60002C00, 0x80059600,
    0x02FF3803, 0xA01B0005, 0x01E06701, 0x02FF019D, 0x0901A00B, 0x0806029F, 0x06000298, 0x04800807, 0x0902FF3C, 0x01A01300, 0x05019F15, 0x01A01600, 0xD822081E, 0xFF1ECD01, 0x8D080503, 0x08050702,
    0x05070295, 0x7008D908, 0x70017705, 0x0FF96701, 0xC2000647, 0x2501C002, 0x9F1201A0, 0xBB005601, 0x1001B701, 0xE76002E0, 0xA8038202, 0x06E70C08, 0x0106F810, 0xB71906F7, 0x02D81501, 0xC205D82F,
    0x0B06FF04, 0x0207256F, 0x392F0270, 0x30010388, 0x2702080E, 0xF703D723, 0x08020002, 0x08056802, 0x09038818, 0x03D70627, 0x0703C81C, 0x03B70F30, 0xF0093F2B, 0x09101C07, 0x09071210, 0x08CF6C08,
    0x4F01C01F, 0x0003D500, 0xE501B73E, 0x00503804, 0x573B0057, 0x78166011, 0x1801A00B, 0x0808029F, 0xD8235F55, 0x018F2101, 0x04900890, 0x1504BF14, 0x2C081B40, 0x86002C00, 0xB0416805, 0x0F001603,
    0xB83603AF, 0x8702A007, 0x87018004, 0x2E686804, 0x01FD03A0, 0x9F02A63F, 0x04A03D04, 0x02EF03A7, 0x9B01AF05, 0x08784002, 0xB20001B8, 0xE04E0001, 0xA714F907, 0x93074908, 0x083D4807, 0x98240007,
    0x70000B04, 0x04FB6234, 0xAA00039E, 0x0DE20003, 0x00090B9E, 0xD20003F6, 0x8106F501, 0xBC02FF01, 0x07050708, 0x956F01DE, 0x0203D80E, 0x0001AF00, 0x03D70BD2, 0x03C814E3, 0x03BF01AC, 0x2103F017,
    0x9403D627, 0x0001A204, 0xE6048B6D, 0xF3048C01, 0x02890006, 0xDC7207DB, 0x8B019E07, 0x048C7304, 0x890002FA, 0x4207DB04, 0x626F0F78, 0x9C070207, 0x78060803, 0x9F03801F, 0xF7020001, 0x09401503,
    0xC70F03B8, 0x03C80903, 0x0303870F, 0x8F0F0388, 0x03900403, 0xEF4A070F, 0x1D001603, 0x24070500, 0x000F0480, 0x0F03AF0A, 0xB70703B0, 0x03B80D03, 0x0F03C702, 0x870103C8, 0x01070E03, 0x000F0390,
    0x380F3702, 0xE70F0701, 0x03C00203, 0x03C713B1, 0x2103F018, 0x03EF2500, 0x03C802EE, 0x7A04943A, 0x8B028500, 0x000CC804, 0x048C02B9, 0xF40001F3, 0x7403E301, 0x072603F7, 0x0A0808DB, 0xB71503F8,
    0x03B80D03, 0x0C03C70F, 0x870F03C8, 0x03880803, 0x08038F0F, 0x070F0390, 0xAF150807, 0x19301203, 0x4F081F77, 0x96070207, 0x1103F803, 0x780903EF, 0x780B7707, 0x5E02F819, 0x03F74408, 0x001D0016,
    0x80240705, 0x0A000F04, 0xB00F03AF, 0x03B70703, 0x0203B80D, 0xC00F03BF, 0x03C70203, 0x8801400E, 0x01000F03, 0x900F038F, 0x0E070103, 0x0F370208, 0xC00203B7, 0xCF10CE03, 0x00018903, 0x005E0848,
    0x00100719, 0x038E005E, 0x07E47400, 0x1407E364, 0x07E40C00, 0xE6048B6A, 0x1703D701, 0x029707E4, 0xE40A07E3, 0xE302A907, 0x4E006F07, 0x028007E4, 0x004F07DB, 0x03D00180, 0x1D03D719, 0x02F507E4,
    0x07E35E00, 0x0EE0000D, 0x03F80A08, 0x0D03B715, 0xC70F03B8, 0x03C80C03, 0x0803870F, 0x8F0F0388, 0x19101503, 0x57081E77, 0x81070407, 0x45048003, 0x780603F7, 0x8C03801F, 0xF7450001, 0x0B601B03,
    0x0900125F, 0x0A002B00, 0x04802207, 0xAF0A000F, 0x03B00D03, 0x0C03B70A, 0xC70203B8, 0x03C80F03, 0x0F038701, 0x8F010388, 0x03900E03, 0x2F020702, 0x0203B70F, 0x0ED103C0, 0x0001B607, 0x01B8000A,
    0xF01703BF, 0x03EF4103, 0x0D9B071A, 0x058507E4, 0x05B3048B, 0x1AAF048C, 0xF01707DB, 0x21002003, 0x071A03EF, 0x07E40CEA, 0x048B04C2, 0x048C02FB, 0x048B12C8, 0x049005E1, 0x2806E70B, 0x000D06F8,
    0xCF05007E, 0x05D85D05, 0x102B0F15, 0x028F0020, 0x1009E017, 0xDD0F01F6, 0x0F7E2803, 0x581005BB, 0x13059117, 0x01900C28, 0x019A0497, 0x172604B8, 0x0504A756, 0x02C30494, 0x1801AA14, 0x7A0001AC,
    0x17099500, 0x02F20035, 0xE3176518, 0x17651801, 0x01A80720, 0x09070A00, 0x87005A20, 0x02E61F01, 0x0AA705BF, 0x002C05D0, 0x8718039E, 0x01FB0002, 0x2801EC27, 0xF61F03B9, 0x10050709, 0x05D701B2,
    0x029F09DF, 0x01F0080D, 0x0001A707, 0x47000193, 0x1A005808, 0x53001007, 0x00039700, 0x920001CD, 0x028B0002, 0xB1004F00, 0x04990001, 0x07E42E00, 0x6F049B31, 0x07019710, 0x03CF0196, 0xAD07E436,
    0x3F049B04, 0x8C02EF10, 0xE303C904, 0x0007FE07, 0xF74724F5, 0x4C08AC1F, 0x0006EC00, 0x03EB22A2, 0x220008CA, 0x85004C00, 0x01EC0001, 0x0001AA00, 0x220001D0, 0xC3003100, 0xAE03EC3F, 0x02D00001,
    0x00028000, 0x08A302C4, 0x049009EC, 0x20048F0A, 0x03E00630, 0x8B5008D1, 0xB5049F0B, 0xD207E801, 0x16038204, 0x06EB0702, 0x0A06EA07, 0x00029A00, 0x020E0219, 0x020E0147, 0x420101BC, 0x0A03C802,
    0x000B000B, 0x0AF705AF, 0xA10011B7, 0x3D0AF807, 0xD710C400, 0xAF03A108, 0x01B04E01, 0xBC01B810, 0x13079008, 0x0004D106, 0x600102F1, 0x0B01DC08, 0x05080C45, 0x0040064B, 0x053D000E, 0x05050896,
    0x0A072F0C, 0x28053F02, 0x3D011006, 0x18041002, 0x0BB75001, 0x04E80BE1, 0x0006000B, 0xF14709E6, 0x08079001, 0xE5398306, 0x0745A10A, 0x06380EE0, 0x03801710, 0x1503C70F, 0x01D503C8, 0x09B503C7,
    0xFE080400, 0xFB03C802, 0xBD03CF06, 0xD503D001, 0xFC01A70A, 0x3601B00D, 0xDF249C00, 0x0702EF02, 0x6E08019D, 0x03A85400, 0xF003A74C, 0x080D772D, 0x0019002E, 0xDE4701DD, 0x0B019001, 0x018F0F00,
    0x04E00193, 0x03D701B4, 0x00170024, 0x8D018716, 0xA104E001, 0xAF0D2F03, 0xE003D704, 0x06E04304, 0x5B0ABF0F, 0x01C58E30, 0x0191CA37, 0x23F503F0, 0x002DAA07, 0x860002D7, 0xAF6A0002, 0xB004AE03,
    0x0009BC03, 0xAF0003DC, 0x02C9000B, 0xA713DB00, 0x770ACA03, 0xF2001BBC, 0xBF04A011, 0x0CE31F08, 0xA701F828, 0xF13F0904, 0x054001C1, 0xE028D63F, 0xDF18CC04, 0x0005C204, 0x01B803A2, 0x03A802A6,
    0x750005DB, 0x079B04DF, 0x09F204E0, 0x03F004DF, 0xDF4504E0, 0x0004CE04, 0x8B04E06E, 0x3004DF01, 0x01A804E0, 0x07DF04DF, 0x01A004E0, 0xDF01F700, 0x04E03504, 0x04DF01A5, 0x04E004A1, 0x0002EAD0,
    0x04C779FC, 0x049009FF, 0x02F71295, 0x6F01B0BA, 0x03F818E9, 0xC70004A5, 0x039F019B, 0xA92034ED, 0x0309F007, 0xD5478E06, 0xD62BF90A, 0x92030A0A, 0x0604011C, 0x0B720605, 0x05100C05, 0x0BAD2F9E,
    0x1DC14009, 0x0EA004A8, 0x002BE407, 0xA40002AF, 0x048A0002, 0x03AF2A00, 0x03B005DE, 0x03AF078E, 0x03B0538C, 0x8F0005E0, 0x03EB0001, 0x0001FE00, 0xBE0001C4, 0x01DD0001, 0x0001EB00, 0xBB0001A5,
    0x01B70002, 0x0001AC00, 0xCF0001B7, 0x01B80002, 0x0004F900, 0x8E0001B1, 0x09E50001, 0xFC007800, 0x00490005, 0xF71F199E, 0xA0038F42, 0xC201AF65, 0x03DB0001, 0x005B04E0, 0xA80010D2, 0x005F0017,
    0xA2000196, 0x01980002, 0x00019600, 0xAD0001A5, 0x01A30002, 0xDF35C000, 0x86007704, 0xCA04E001, 0x2503AF09, 0x03FA03B0, 0x0004D900, 0xAE000595, 0x0C8F0003, 0x0007EA00, 0x03AF0187, 0xF10009A2,
    0x04AC0001, 0x0003D700, 0x08FE0024, 0x85E503B0, 0xF603AF01, 0x01A40007, 0xC0071008, 0x02890002, 0xEE08046F, 0x08C87008, 0x0707D000, 0x200001BE, 0x00079700, 0x05B90806, 0x07018400, 0x09080299,
    0x0002FC07, 0xCE0821F8, 0x3E830704, 0x0184EE08, 0xDF080D07, 0x08AC007B, 0x000A0A90, 0x9F0702D1, 0x084D000A, 0x0EAC085B, 0x05B107BF, 0xF86A04A7, 0x02F74D02, 0x2A02F874, 0xF7079800, 0x9C003502,
    0xB602F805, 0x1D02F706, 0x02001100, 0x9F2B02F8, 0x27049C01, 0x03FD3F7F, 0x02F8046F, 0x02F70183, 0x3D0008AA, 0x01EC01D8, 0x0DD001A0, 0x001F0280, 0x001B0025, 0x03FD0047, 0x4B09CE34, 0x0754104C,
    0x1C0701CE, 0x0E071C10, 0x0B104900, 0x07000600, 0x06080300, 0x06000807, 0x03000700, 0x08070608, 0x07000600, 0x08080300, 0x12001207, 0x07000400, 0x07001200, 0x07000400, 0x3401D100, 0x33340034,
    0x002F000C, 0x3418000E, 0x002A0067, 0x05039036, 0xCC0D03CB, 0x03BB2603, 0x33322C4C, 0x00060008, 0x00080016, 0x00160006, 0x00060008, 0x2C0001BF, 0x31002C00, 0x50080300, 0x12003C07, 0x85341400,
    0x0903E318, 0x082F0808, 0x08070707, 0x8F770AC8, 0x0708090A, 0x0707082F, 0x0AC80807, 0x06FF249C, 0x01C6005B, 0x00029500, 0x03E81BF5, 0x00660063, 0x006C085B, 0x0EBF005A, 0xF0000E08, 0x02DE0707,
    0x4C070600, 0x02281F00, 0xB4000B1F, 0x002F0703, 0x05BF13E0, 0x02A70B9B, 0x8708018F, 0x00670001, 0x3D6801C3, 0x03883D08, 0x0503FF2C, 0xF73303F8, 0x03F80503, 0x04BF078C, 0x01A8039B, 0x01A70691,
    0x7C000687, 0x0CFD01A8, 0x000B01C8, 0x02FF29F7, 0xF71005F1, 0x03F7502F, 0x0701B270, 0x1053376C, 0x079E0758, 0x975F6928, 0x01B60001, 0x0702B900, 0x080004C4, 0x08000800, 0x06000400, 0x03F03508,
    0x2603EF05, 0x001003F0, 0x3603EF12, 0x0C201548, 0xB1770B08, 0x00040801, 0x040001AA, 0x03F00C00, 0x03F70287, 0xF8310804, 0x0C000B03, 0xB00703AF, 0x03B70C03, 0x0403B806, 0xC00903BF, 0x03C70203,
    0x0503C80B, 0x07060387, 0x0B039001, 0x06070200, 0x02DF0A2F, 0x071D5702, 0x0B03F833, 0x03B70C00, 0x0403B807, 0xC00803BF, 0x03C70403, 0x0103C809, 0x880B0387, 0x038F0503, 0x0B039013, 0x0B370200,
    0xF02303B7, 0x0B001803, 0x03B70C00, 0x0403B806, 0xC00903BF, 0x03C70203, 0x0503C80B, 0x07060387, 0x0B039001, 0x0B070100, 0x08370408, 0x03E70230, 0x0706301C, 0x28061006, 0x072D0806, 0x3CD40809,
    0x078C0A98, 0x02950BD7, 0xDF005D00, 0x9C04E808, 0x106F1701, 0x07720770, 0x071C101C, 0x19FD000E, 0x004904D7, 0xB002F9BC, 0xAF1BFA08, 0x0004D908, 0xF4000581, 0x020802A5, 0x0002EB40, 0x00160810,
    0x47310016, 0xE8000DE4, 0xDB04E00F, 0x23DC0060, 0xA7668800, 0xDC76F203, 0x330ECD03, 0x17120009, 0x07081008, 0x080A1007, 0x33132C10, 0x3435000B, 0x06039012, 0xCC0D03CB, 0x03DB2403, 0x000E080E,
    0x0D04D736, 0x0B600E00, 0x62082140, 0xD85501A7, 0x040F0D0B, 0x0D085E08, 0x3308050F, 0x100906FF, 0x10080707, 0x2C0D080A, 0x09059B2D, 0x3F0801A0, 0x01894832, 0x080A0A88, 0x0F1D0805, 0x08060805,
    0x9704CE95, 0x01A7150A, 0x0013000F, 0x00050013, 0x2701A824, 0x55AC01A7, 0x958D01A8, 0x78435F02, 0x01B27754, 0x0001DC08, 0xC50001DC, 0x00237806, 0x00230035, 0x00230023, 0x00230023, 0x00230023,
    0x00230023, 0x0023003D, 0x00230023, 0x00230023, 0x00230023, 0x00230023, 0x0023003D, 0x00230023, 0x00230023, 0x00230023, 0x00230023, 0x075C0734, 0x06F808D9, 0x880001F6, 0x0007E70B, 0x04ACE801,
    0x2D49018B, 0x02AD2C68, 0x42874FC9, 0x85C2449C, 0x038FE004, 0x02000BAB, 0x0001F5A4, 0x100001FD, 0x14001100, 0x0F001B00, 0x10000800, 0x06000700, 0x85E81800, 0x16001801, 0x550185E7, 0x160184B0,
    0x159B01B8, 0x01B70E00, 0xA00E0012, 0x85CF0901, 0x85D80E01, 0x85D70601, 0x85E00101, 0x85DF0701, 0xDA002301, 0x0185E80D, 0x0185E73C, 0x0185E81B, 0x85E71FD8, 0xE811AA01, 0xE7090185, 0x11DC0181,
    0xE80C03FF, 0xD71E0185, 0x8F390183, 0x0001DA02, 0x800D0007, 0x03FF0904, 0x00380046, 0x00070008, 0x0C048021, 0x018B03FF, 0x0E0184B0, 0x080601A0, 0x0185D708, 0x0185E001, 0x0185DF10, 0x00250007,
    0xE8020019, 0xE7220185, 0xE0740185, 0x07080185, 0x0181D708, 0x0180B019, 0xA00A000D, 0x46002401, 0x060182EF, 0x01A02600, 0x87360802, 0x0F001504, 0x85E87E00, 0x81DF0601, 0x01000D01, 0x00150487,
    0x17CD000F, 0xB01D0480, 0x001D0180, 0x2001A80C, 0x81DF3108, 0x21004E01, 0x904603FF, 0x8F01B704, 0x2EF07E04, 0x2AE0029E, 0x55BF02E1, 0x032AE059, 0x23D03200, 0x32079003, 0x03CA23D0, 0x019C799F,
    0x15D303FF, 0x1E8F02E0, 0x0E0181D0, 0x010184AF, 0x120185D0, 0x85D70608, 0x85E00101, 0x85DF0701, 0xFB002301, 0x0185E82F, 0x0185E762, 0xD8002BFA, 0x0185E84D, 0x0183D730, 0x07028F2F, 0x000C8700,
    0x00090006, 0x00160030, 0x46048011, 0x000A03FF, 0x001E0031, 0x001B003A, 0x03D20051, 0x120185E8, 0x010185E7, 0x020185D8, 0x85DF0708, 0xE829F501, 0x04C80185, 0x83D73400, 0x028F0801, 0x0CE60007,
    0x09000600, 0x16003000, 0x04801100, 0x0A03FF46, 0x1E003100, 0x1B003A00, 0xF1007D00, 0x0185E801, 0x0185E712, 0x0185D801, 0xDF070802, 0x25B60185, 0x340185E8, 0x530183D7, 0x060183D8, 0x530185E7,
    0xFE000700, 0x04048815, 0x00060487, 0x002F0009, 0x80110016, 0x03FF4304, 0x0031000A, 0x8835001C, 0x04872304, 0x0064001C, 0x07D00197, 0x07CF01C3, 0x0185E814, 0x0185E70B, 0x0185D801, 0xDF070802,
    0xFBD50185, 0x8F980003, 0x00050003, 0x0005002C, 0x05000A9F, 0x05002C00, 0x05002B00, 0x0FDE9A00, 0xED000600, 0x048009E9, 0x900013C2, 0x03FF02A4, 0x85E844C1, 0x0988FB01, 0x1C0185E7, 0x8C010000,
    0x210803DE, 0xC01CBBF5, 0x7EA402FA, 0xC18E03C7, 0xEA3BF301, 0x01000FAC, 0x599B7EC2, 0x04C41DEC, 0x54CB1DAE, 0x03D401B7, 0x14A002FF, 0x029E02B9, 0x373706A2, 0x04DE08B3, 0xB60E223A, 0x0E223A02,
    0x059F06F0, 0x07AA06ED, 0x32410198, 0xBD1BB807, 0xB501B40D, 0x2C3A9F01, 0x0DDB4EA9, 0x1C03F159, 0x0E8430DD, 0x1C02BC59, 0xCD4F26FC, 0x02D87C18, 0x219EBE1C, 0xF901AF30, 0x841A1302, 0x01840199,
    0x01AC0184, 0x1BB877A1, 0x69140AE8, 0x0295C566, 0x1101AD11, 0xBA1101D6, 0xC15D06EE, 0x01005606, 0xAA018981, 0xEB02AD6B, 0x9B04A402, 0x01B40E02, 0x1D8C3495, 0x05E80180, 0x029301A2, 0x39150185,
    0x10EB05E8, 0x01C801C8, 0x01C802B7, 0x02B701C8, 0x01C801C8, 0x03AC029C, 0x029E02B9, 0xA11E03F6, 0x07EC6D18, 0x660A8863, 0x59956AF7, 0x2943AA29, 0xC52943B5, 0xF5029C1F, 0x9C2ED301, 0xF201F502,
    0x8F12B723, 0x15B93652, 0x02A902F7, 0x4304A3AC, 0x7E27EC0E, 0x941097C5, 0x09DD8F08, 0x9B3F1F1F, 0x1B564D05, 0x04C72E17, 0x04B002DF, 0x01A501CB, 0xF6291939, 0x2A02A10A, 0x2301C021, 0x470E4215,
    0x01A11409, 0x7103C11D, 0x6403CE2C, 0x2C1801E5, 0x330298C5, 0xE0BE2818, 0x06BB5F09, 0xB09F0100, 0x0C02AE33, 0xDABF0100, 0x0C029E33, 0xF4CF0100, 0x0C029E33, 0xA1AF0100, 0x0C029E34, 0xFDDF0100,
    0x0C029E33, 0x27271FE9, 0xB0810100, 0x8C2A9C33, 0xCC098C1A, 0x9E088A23, 0x08AC0C02, 0x049C208C, 0x08EC07BC, 0xADE30100, 0x27272733, 0x84E12727, 0x0C029E01, 0xD4AF0100, 0x0C029E34, 0x1C1C1C3A,
    0xD8CF0100, 0x0C029E34, 0xE08F0100, 0x0C029E34, 0xE8FF0100, 0x0C029E34, 0xFB830100, 0x523AD834, 0x0523028D, 0x00460B8B, 0x369EBF01, 0x000C029E, 0x3585F801, 0x0001D419, 0x37F3CB01, 0xAF010006,
    0x1CA33589, 0x97AF04CE, 0xD302000A, 0xFA0034FA, 0x002C003D, 0x3A02A813, 0x805802A7, 0x01FF4402, 0x0D0009DE, 0xB3010000, 0xF90E34FD, 0x19AD0604, 0xE90FA906, 0x97020002, 0x979A6049, 0x12B75F03,
    0x00029400, 0xAF0009DE, 0x0008602F, 0x31CA000D, 0x02D3F05F, 0x03CDAE00, 0xD3001100, 0xFB0001AE, 0x30D00001, 0xF0001700, 0xD306A80D, 0x06A704AE, 0xAE0001A0, 0x004A000F, 0x36000196, 0x000B8F00,
    0xB7000296, 0x05C70046, 0x0022C500, 0x000190C1, 0x04BD001D, 0x01808A00, 0x5F0CB960, 0xA4000BFD, 0xE90001A2, 0x05B10001, 0x0004F500, 0x8E0004B5, 0x028C003E, 0x00028800, 0x8900069E, 0x029E0002,
    0x01AEC200, 0x000EE400, 0xAF0003C6, 0xC80002B0, 0x03890016, 0x6024D000, 0xAB000BDC, 0xA95F019E, 0x02F9605D, 0x0192F85F, 0x018CE560, 0x5F03C400, 0x0003D7D2, 0xA3006D93, 0x3D000190, 0x0CFAEB00,
    0x004BCB00, 0xC9000298, 0x01BC480A, 0x0008FF47, 0x000E0014, 0x48028E90, 0x001F4721, 0x006E0066, 0xA876003D, 0xDF018706, 0x1F471F05, 0x23005600, 0x39007200, 0x06A87000, 0x1C06A725, 0x0016D700,
    0x0047006E, 0x0F001DA7, 0x0009C700, 0x0008C4D3, 0xC10001B5, 0x21F10002, 0x001BF200, 0xDA000795, 0x0100000D, 0x0637F4D4, 0xFEF90100, 0x04ED0634, 0x0619C70D, 0x02BB0DFE, 0xFBE70100, 0x04D50D34,
    0x0D1A970D, 0x03980FF9, 0xF3BF0100, 0x0C029E36, 0xD3EF0100, 0x0C029E37, 0xA5C80200, 0x080C0037, 0x01000811, 0x9137DEBC, 0x01000C02, 0x0037DBC3, 0x35ADBC01, 0x02C6F855, 0x00053305, 0x1BFADA01,
    0xA11C8FDE, 0x01000C02, 0xEE33CA9F, 0x04C2AA04, 0x02C801EA, 0x345B2BF0, 0x07F001E2, 0x02B901B4, 0x2B2B01C1, 0x717F654C, 0x2901EF1E, 0x01E202EB, 0x8401C17A, 0x8C05D501, 0x109F6C01, 0x937F01C6,
    0xCE09B201, 0xC3018F05, 0x4F5F490B, 0xFA02CE53, 0x100C1B01, 0x82DF0100, 0x0C029E39, 0x90AD0100, 0x01002038, 0xB71552CB, 0x2930D008, 0xB16A9218, 0xB313028F, 0x4201B902, 0x04BC4343, 0xAF0CD019,
    0x01E97B01, 0xF71302E4, 0xBE289002, 0xA239AD1B, 0x03F99F43, 0x8701BF07, 0x01830701, 0x6E0701A2, 0xB707019F, 0x95019301, 0x018CD301, 0x0C018956, 0x197B671C, 0x2C0D0D2F, 0x0D27191E, 0xA82C2C0D,
    0xDAAA01AC, 0x830EB50E, 0xBE081E1A, 0x0D0A9010, 0xB52B0D08, 0x01B0CB04, 0x0A02A32B, 0xF103A9A4, 0x0F3C0D01, 0x08ABB675, 0xAF3C03C5, 0x2E01BF01, 0x02A803FB, 0x01C001B3, 0xCE415C22, 0x018201BC,
    0x85018660, 0xBF716C14, 0x27C84603, 0x038EEB42, 0x971C04BD, 0x45423307, 0x3F714D13, 0x05AC9839, 0x10370E95, 0x0A0B110D, 0xB41E0B0B, 0x0E1A1403, 0x0E0E0E0E, 0xBBEB03D0, 0xDB02AC04, 0x2B0BA602,
    0x3501CAD5, 0x905B02BA, 0x41039901, 0x09A5019E, 0xCDB501E3, 0x018E9203, 0x8FAF0100, 0x98BA2238, 0xF0010001, 0xCC22388E, 0x01970196, 0x004702B5, 0x388FEE01, 0x01988122, 0x010001B7, 0x8A38928E,
    0x01000195, 0x890AF8E4, 0xB5851DF3, 0x17B9060F, 0x01FD0185, 0x8E6D05F1, 0x8501FD02, 0xAC04E301, 0xAB02C101, 0x7F02A201, 0x9C7C4006, 0x97019D02, 0x01895001, 0x01C101A6, 0x05AA0184, 0xCB6C018C,
    0xB604F007, 0xC6049812, 0x5C5A4E0C, 0xE702D553, 0xD7010001, 0xFD0D3892, 0x01A19D01, 0xC0010038, 0x9A2638E5, 0x9B010019, 0xDB8033D7, 0x0C029E05, 0xC1AF0100, 0x0C029E3A, 0x52870100, 0x01E702D4,
    0x03E9110D, 0x3C03DD4E, 0x0925121D, 0x09091518, 0x0191B710, 0xF30A9A08, 0x03B301DE, 0x23B82EBB, 0x991DB251, 0x01A9121B, 0x06ED02D4, 0x029502FF, 0x26880388, 0x93018112, 0xF201E511, 0x0194182E,
    0x02B502E5, 0x049503E0, 0x3AD20383, 0x289A0AC0, 0x39C807C5, 0x609403EB, 0x07E60493, 0xDC0C4BCB, 0x312E1304, 0x452C05BE, 0x8C72930B, 0xA61B0701, 0xD61B0702, 0xA11B0701, 0x16E602C4, 0xDF06DE80,
    0x0AF78952, 0xC3D611C1, 0x028A0B01, 0xD205A10B, 0xB828A010, 0xDF309302, 0xFC04DC0D, 0x8F03AE04, 0xBF07EE0C, 0xE50D05AA, 0x04911D04, 0x079D1F0C, 0x2D0F1C1C, 0x04AA02A7, 0x1127210E, 0xE807130C,
    0x16211405, 0x1C03A693, 0x81D50F1C, 0xDC60C206, 0x01ECE923, 0x0C112907, 0x8F0D0F10, 0xED2406B8, 0x2D3BA603, 0xD90B04CF, 0x2C301001, 0xD502DD0B, 0xC205A601, 0xB004D304, 0x6403D101, 0x05DC6574,
    0x1C1C0DB3, 0x8D038E1C, 0x01A69A01, 0x0BDE01E1, 0x02CD30AC, 0x950F0AA9, 0xE602F403, 0x01B96703, 0x028F028C, 0x01860493, 0x001B841C, 0x3A84CD01, 0x8D1B10CA, 0x01BEF203, 0xD547132E, 0x0001DA48,
    0x3A84B301, 0x140AA27F, 0xAC018A62, 0x49018901, 0xAA314A0C, 0x01883801, 0xC1291876, 0x1C3A7C0A, 0x1C1C1C1C, 0x20192F1C, 0x2F1D293B, 0x1A1F193B, 0x86131C2B, 0x140E1203, 0x16019B0C, 0x351A0AC6,
    0x01E51C1B, 0xB03AC039, 0x5C03C701, 0x09AD5998, 0x8902D826, 0xD12EE00B, 0x4E01B202, 0x74E302C1, 0xD0FF0100, 0x0C029E3D, 0x9BCF0100, 0x0C029E3E, 0xA7BF0100, 0x0C029E3E, 0xAFFF0100, 0x0C029E3E,
    0xB8CF0100, 0x0C029E3E, 0xC5BF0100, 0x0C029E3E, 0xD38F0100, 0x0C029E3E, 0xE0CF0100, 0x0C029E3E, 0xD0E10100, 0xAC4ACC3D, 0xEC08CC14, 0xBC0DCC0C, 0x9E059A0D, 0x01000C02, 0x9E3F838F, 0x1EEC0C02,
    0xE5B10100, 0x9E3F9A3E, 0x01000C02, 0xA13FB7CC, 0x01000C02, 0x9E3FD9EF, 0x01000C02, 0x5C01C6EB, 0x003EB8C3, 0x4090EC01, 0x000C0291, 0x23E29401, 0xFBD10100, 0x1C1C1C1B, 0x16B0BD1C, 0x9E0DFCD9,
    0x02000C02, 0x1040ADA7, 0x18050F06, 0x00191706, 0x001A0006, 0x01000021, 0x0040D1A8, 0x01858701, 0xDEE201DE, 0x0100193F, 0xD301858D, 0x3FDEE101, 0xDF01000C, 0x02912398, 0x001DEAC9, 0x08C1BA01,
    0x8C018E84, 0xACA503A6, 0xC74D7917, 0x25427D01, 0xFAD27D54, 0xC201C401, 0x50B919DB, 0x221EC26D, 0x6D2803F3, 0x04F40298, 0xDBA00100, 0xB4861703, 0xF8F0151F, 0xB101001D, 0x02CB2398, 0x0A1DD9F4,
    0x02000B5F, 0x0040F1B7, 0x04800182, 0x03FF06F5, 0x0809000A, 0x0A0704D9, 0xD7080900, 0x01000702, 0xB32398B7, 0x1DDEFE02, 0x0404EC04, 0x98C60100, 0xCF029823, 0xFE061DDF, 0x01000304, 0xDA118BB9,
    0x02A3C001, 0x7AC001DF, 0xFDB90EFB, 0x951BF407, 0x039508AB, 0xB7116E85, 0x01ED0CC8, 0x01FC03BC, 0x01A432BC, 0x020FCFDD, 0x8D0201C4, 0x069F0207, 0x0201C402, 0xB6020790, 0x01C40306, 0x0203B105,
    0xC60206A1, 0x03B40501, 0x0205B802, 0x9C0201C4, 0x05830406, 0x0201C402, 0x8B040696, 0x01C40205, 0x0402BE02, 0xC40204F1, 0x02BE0201, 0x0308C004, 0xEF0201BD, 0x07930409, 0xF6027C07, 0x09D20404,
    0x020A8102, 0xE1061398, 0x019E0307, 0x0316CE02, 0x98BD0100, 0x8202A723, 0xEB051DDD, 0x01000504, 0x1340F9A5, 0xDC1304DD, 0x000D3002, 0x40EEB302, 0x01080100, 0x01080108, 0x01080108, 0x01080108,
    0x0B3F2218, 0xD9070707, 0x30091004, 0x3802370E, 0x470D0802, 0x171D1837, 0x17101806, 0x080F2801, 0x1F02080B, 0x001E1701, 0x0BD00009, 0x07170318, 0x00000818, 0x2398D901, 0x87AC029D, 0x1C2D5601,
    0x55019831, 0xAF471F1F, 0x01F701FC, 0x041AE093, 0xF8C40100, 0xB5241340, 0x87241304, 0x00062304, 0x40F2CA02, 0x80018200, 0xFF058102, 0xDE001201, 0x00120004, 0x000004AA, 0x23BBBD01, 0xE6420194,
    0x0BFC1EBE, 0x089E0BDA, 0xE9A20100, 0xD5049841, 0x03DF2A02, 0x01CC02CE, 0x8C48A72A, 0xB40FA10F, 0x830AEF0B, 0x930D850D, 0xD30B9009, 0x000DB013, 0x4198A401, 0xB1010009, 0x01DE41E1, 0x01FF028E,
    0x07DB01A6, 0x04150526, 0x4E550B16, 0x04DB01A6, 0x13150528, 0x90E04804, 0xC1020003, 0x02084193, 0xA50F0608, 0x070E0858, 0x03921004, 0x04080907, 0x02C4CA0F, 0x01080200, 0x9C020008, 0x0418418F,
    0x02180818, 0x04205B47, 0x022F1118, 0x0E272348, 0x02300217, 0x1711BA18, 0x18072F04, 0x0808080B, 0x57042004, 0x0F0D1802, 0x28121802, 0x01B0081C, 0x072F040F, 0x08080B18, 0x04200408, 0x14180257,
    0x1218020F, 0xAF081C28, 0x17042706, 0x270B3007, 0x38040808, 0x30025704, 0x3002270D, 0x081F1010, 0x042702B2, 0x0B300717, 0x0617061F, 0x023F0750, 0x02370620, 0x16181B30, 0x02C2CB08, 0x072F0C0F,
    0x42301E18, 0x072F0417, 0x3F300B18, 0x022F0427, 0x04201218, 0x04180B2F, 0x41081728, 0x022F041F, 0x04201218, 0x04180B2F, 0xDD081728, 0x01870804, 0x07170F2F, 0x62181430, 0x0717042F, 0x3F180B30,
    0x0217043F, 0x040F1230, 0x04300B17, 0x41081710, 0x02170437, 0x040F1230, 0x04300B17, 0x00081710, 0x419F9F01, 0x20934C2F, 0xDA02A6B0, 0x710CFD05, 0x9F1C088C, 0x04C501CA, 0x010002AB, 0x0B41A187,
    0xA6D420CA, 0xEF04DE02, 0x0CAF760C, 0xCF01C6B3, 0x02A40504, 0xB3010006, 0x850B41A0, 0x02A6D421, 0x0DE003ED, 0xB90CAF76, 0x04AF01C6, 0x0602A205, 0xE9840100, 0xD404AE41, 0x03E12A02, 0x01CB02CE,
    0x2A03B12B, 0x0BDF0BCE, 0xCE07EE27, 0x09802D06, 0x8D2A098B, 0x3105F705, 0x0F840EF3, 0xD70B9B32, 0x0CE92C0A, 0xF92C0CEF, 0x400AE708, 0x9735139A, 0xDD01000D, 0xFE0B41A0, 0x02A6D420, 0x0CEF04DE,
    0xA30CAF76, 0x04F201C6, 0x0602A305, 0xC89D0100, 0x8A070932, 0x59F40ECA, 0x010003A7, 0xEC41A2AB, 0xC9059404, 0xD9499408, 0xFC0BFC0B, 0x9506F307, 0xA309A209, 0x8906D305, 0xB40F9F0F, 0x800AE50B,
    0x900D800D, 0x000BC809, 0x4198C101, 0x0704BC07, 0x0004B0EA, 0x41989E01, 0x02C80BB2, 0x03B007C3, 0xFD02ACA8, 0x08EC6116, 0x8701007A, 0x460E419F, 0xF7047D41, 0x02A6B21E, 0x0D8505D5, 0x1408896C,
    0xF80C029E, 0x04CC01C7, 0x010002AB, 0xFF41EA88, 0xE105B904, 0xDE07EA03, 0x810BEF0B, 0x9A06DD08, 0xA3099709, 0x9C05BD05, 0x9D0BE903, 0xA60BFE03, 0xA7088A03, 0x9E07A803, 0x9D09DE03, 0x9E09DF03,
    0x9D05EE03, 0xAD09AA03, 0xF80FA303, 0xA70CAF02, 0x95010002, 0x0BA74198, 0x07C502C8, 0xACA503B8, 0x6116FD02, 0x007A08EC, 0x4194DA02, 0x02084800, 0x1B076808, 0x000F1B08, 0x24A0E901, 0xF88B08A3,
    0xF401001C, 0xB91E26A0, 0x1AF5870B, 0x01F90E04, 0x028A02EF, 0x029E02EE, 0x02A706AA, 0xA0FF098D, 0x001BC702, 0x41E8E501, 0xCC0B04E0, 0x02D61203, 0xC40902E8, 0x01A10302, 0x0BDC0BFC, 0x07E8089C,
    0x098D09AF, 0x05B205BC, 0x100F9007, 0xC1070EF9, 0x0B940C0B, 0x0AA402F2, 0x0A9202D8, 0x06BC02EA, 0x088702D0, 0x9D0713B4, 0x0100390D, 0x1E419FF6, 0xA6D421B9, 0x9D04B002, 0x0CAF760D, 0xDB01C6A2,
    0x02A30504, 0x90010006, 0x263841A0, 0xA6D01FCC, 0x8005B802, 0x0889760D, 0x01CAAC19, 0x02AB049F, 0x92D10100, 0xFD019741, 0x0003AC57, 0x419FB801, 0x01820804, 0xFE1F9226, 0x05AB02A6, 0xF7760D8D,
    0x177B1C07, 0xA601C99A, 0x0002AB04, 0x43E1EC01, 0x020009AB, 0x004493B5, 0x04020402, 0x0BA40402, 0x18000D0B, 0xE2020000, 0x8D0023BF, 0x9C9B002F, 0x08060020, 0x01F20806, 0x0608060F, 0x0004C408,
    0x07020702, 0x3D0008E2, 0x00085D08, 0x4492BC02, 0x270C0400, 0x94041B07, 0x0200070C, 0x0023C3FB, 0x08020804, 0x0F0F83BB, 0x0011C2B6, 0x08060806, 0x060F02A8, 0xE8080608, 0x07AC0F01, 0x000ABF00,
    0x07061007, 0x080C0706, 0x0F04080B, 0x07081004, 0x000712EE, 0x23C4EB02, 0x02080400, 0x20C5B508, 0x0608060F, 0x0F029608, 0x08060806, 0x000F098B, 0x23C5DB02, 0x02080400, 0x20C4F508, 0x0608060F,
    0x0F028408, 0x08060806, 0x000F08FE, 0x23EB9102, 0x20C8BD00, 0x06080600, 0xC6020008, 0x02004495, 0x02040204, 0x0B09FB04, 0xC0BD0200, 0x2FC80023, 0x209C9500, 0x06080600, 0x0F01BC08, 0x08060806,
    0x35000589, 0x97071B07, 0x08500007, 0x0200085B, 0x08449592, 0x04030708, 0x00030A9D, 0x4495AB02, 0x02040200, 0x8B040304, 0x02000B0A, 0x0C4492CA, 0x04360B5E, 0x0BA7041B, 0xB0020007, 0xA30023C0,
    0x9C97002F, 0x08060020, 0x01CE0806, 0x0608060F, 0x0004B708, 0x07210728, 0x3D000880, 0x00085B08, 0x23C08902, 0x002F9800, 0x00209C99, 0x08060806, 0x060F01E0, 0xB8080608, 0x07020004, 0x08DA0702,
    0x5B083D00, 0xE8020008, 0xE20C4492, 0x08280B01, 0x0AAB030A, 0xEC020003, 0xF60001FD, 0xD30020FD, 0x12DB1013, 0xFA070C07, 0xDAF70801, 0x070D000F, 0x0D08088B, 0x01EFDF07, 0x0BE2AA00, 0x000CFA00,
    0x0A0821AD, 0x32006107, 0xEA006C00, 0x9E0003C1, 0x070D0805, 0xC7000DB7, 0x0F1D1002, 0x8E860100, 0xA9098723, 0xAB010005, 0x2EA140DB, 0x0003C9B5, 0x45A8E702, 0x050F0610, 0x19170618, 0x37000600,
    0x001CF900, 0x9DFA0200, 0xA9A50044, 0x01000401, 0x4E41BD95, 0x2B29884E, 0x7009DE28, 0x06C5242B, 0x0BD903C7, 0x07FC0BFE, 0x099506EE, 0x05A309A7, 0x0F8906C9, 0x0BB40FA7, 0x0D800ADD, 0x09900D88,
    0x13BC0BAF, 0x8F8B0DAF, 0x9F010002, 0x01D00185, 0x094596DB, 0xB4A70100, 0x91010047, 0x098745F6, 0x16C4110E, 0x02A201A6, 0x01C51A80, 0x04DE01A6, 0xB60A0595, 0xA4010073, 0x01C60185, 0x094596CA,
    0xB4A10100, 0x87010047, 0x02F946B5, 0x894C06B6, 0x9E010075, 0x7EED46B5, 0x99890100, 0x21F8DC24, 0xAE311ECA, 0x1B1B2702, 0xB9F10200, 0x02A90047, 0xEF4E01F0, 0x00000301, 0x47B9B501, 0xBC1602BF,
    0x01000C01, 0x0E47DB89, 0x3F018C47, 0xA65502E8, 0x71360E01, 0x05A102C7, 0x67085159, 0xF10C5B45, 0x04885C02, 0x004E01B4, 0x4685CC01, 0x1BCF2F8A, 0x01842EB7, 0x01BF05D0, 0xF311C427, 0xEC05BB02,
    0xB80AFC01, 0x002FBE1D, 0x46E5D301, 0x5501BF04, 0x02006288, 0xB6282BE5, 0x284F2702, 0xDA1F0292, 0x06890004, 0xCC071600, 0x200C001C, 0x10100F02, 0xE51F01E0, 0x10021032, 0xDB0047A6, 0x00131F27,
    0x001C0035, 0x8C94000B, 0xB5F00003, 0x000E000E, 0x0014000C, 0x000C000E, 0x001CE699, 0x000392B4, 0xE7A50011, 0x001B0006, 0x0F0001C4, 0x0DEFE600, 0xCE001C00, 0x00260016, 0x4C0002AE, 0x45003C00,
    0x75004500, 0x001F0D20, 0xA630DF01, 0x47EDEB0B, 0x2C371C21, 0xE301001C, 0x47E29A30, 0x1118BF1C, 0x09112A09, 0x1A09111A, 0x01001213, 0x4C48ABF4, 0x01003E3C, 0x0FB33BFE, 0xCA9B1189, 0x01001C47,
    0x9E48EAEF, 0x01000C02, 0x02B22C90, 0x04F11EA1, 0x01EF03C5, 0x03C40185, 0x4C1A2EF2, 0x86572695, 0x03EA5802, 0xF9260BB2, 0x01C7C712, 0x05CB6396, 0x5C1D06BF, 0x252601A1, 0x03AD1D25, 0xB001B448,
    0x5C55D304, 0x01C409FE, 0x23F60FBE, 0x9D02FB5C, 0x5A388701, 0x01A608A4, 0x01C63B8A, 0x3B08BB5C, 0x1D910AA1, 0xBF5C01C6, 0x3BCF3C05, 0x0184344B, 0xA83060C6, 0x5F01C502, 0x883C05D4, 0x601DE630,
    0x01FE78FA, 0x8801E064, 0x69C06402, 0x08800CF2, 0x02B20698, 0xBA01FF6E, 0xBF966F02, 0x3A2AF301, 0x0BD50298, 0x56C001CA, 0x8D660DBD, 0x5AED02D5, 0x5A9205E2, 0xB9E947B5, 0x8D06AD01, 0x831CB123,
    0x01EAFC2F, 0x6CBC6FF7, 0xD802AED8, 0xBC08FE11, 0x9F44CD02, 0xA9264001, 0xFE01D708, 0xE0458008, 0xEA0ABB29, 0xF10F9A03, 0xA503EA2B, 0xD205B316, 0x57141A6C, 0xC023C654, 0xB706A924, 0xF5118009,
    0xB5119303, 0xC80BD102, 0xDC239101, 0x9B12C601, 0x03CC3F04, 0xEE4E068F, 0x9B179F1F, 0x8606C80D, 0xC015A801, 0xCA05DD07, 0xA308B520, 0xAB799A04, 0x01A2AF0B, 0x67059233, 0x01A41F2A, 0x5DBB0F96,
    0x2AFB3A9F, 0x07A904AF, 0x1FCB01BE, 0xE239E528, 0x4401A73A, 0x8A6804D8, 0xD0160397, 0xAEE102E1, 0x92068201, 0x56FF2258, 0xBFD3018E, 0x49019201, 0x2AC7128A, 0x0CDD1A45, 0x159F131E, 0x0FDE0198,
    0x12D01188, 0x4B8C0F99, 0x27A505CC, 0xB2D90DF3, 0x02D06F02, 0x28A923FB, 0x03F302F1, 0x02D8338A, 0x0DA8049B, 0x01970281, 0x0281018C, 0x038F0197, 0x01A202EC, 0x6739C851, 0x09DB6868, 0x15E607C9,
    0x1AED08D5, 0x06292044, 0x418138B8, 0x12B1029C, 0x6102BA70, 0x870196AF, 0x5B4E9509, 0x01871E9A, 0xC101E0E9, 0xBC01F601, 0xA601BC01, 0xEE1AB869, 0xB11A8B02, 0xC820B308, 0x0BB25112, 0x2A290CC0,
    0x37302929, 0x21263127, 0xCE0FD32C, 0x9821E41C, 0x7701AD04, 0x01B80398, 0x0BFE2026, 0x3890048B, 0x39DA06BE, 0xE8FB109C, 0x08915A06, 0x805904FA, 0x7C039E6A, 0x1DD616A5, 0x8E3504CE, 0x3401A834,
    0x2504F93B, 0x0BDB0183, 0x211E0E11, 0x88530BD5, 0xAB0BAD01, 0x11CC3239, 0x1515151A, 0x2F4E02CC, 0x0E910183, 0x2CE70388, 0x02A21FD3, 0x7202F86B, 0x912005B0, 0xBD010001, 0x010048E4, 0x0048E4C3,
    0xB64D8401, 0x47DBEA0E, 0x0008E612, 0x48BCFD01, 0x15031503, 0xFA17CF03, 0x0074281B, 0x48CBA001, 0x0026B406, 0x0193E101, 0xBC02B99C, 0xBC18DC71, 0xCC43FC37, 0x8C33BC44, 0x9C72FC2E, 0x0296BC39,
    0xA9CC64FC, 0x02AE8C01, 0x9C04D1BC, 0x93CC01A7, 0x03BDEC02, 0xDC01BDEC, 0xCC76AC15, 0xCC19DC79, 0xFC42CC1F, 0x8C68EC1D, 0xFC088C0B, 0xFC2FBC15, 0xAC2E9C25, 0x02938C28, 0xCC01FC8C, 0x0794DC0A,
    0xCCBC54EC, 0x8C0CFC01, 0xAC14BC0E, 0x8C08EC1C, 0x8C11FC09, 0xFC35AC0A, 0xDC34FC04, 0xDC319C64, 0x03ECAC03, 0xCC01B5AC, 0x9C2BFC0A, 0x01BECC78, 0xBC04C1DC, 0xFC229C34, 0x08D9FC36, 0x22221DD0,
    0x0C029167, 0x0FAC21EC, 0x46CC0FFC, 0x010039CC, 0x03A279FC, 0x2BA60E9A, 0x3F02CAB6, 0x27C914B3, 0x03FFAC11, 0x1DD408E3, 0xE20E66D0, 0x0391C751, 0x4815C688, 0x14BE2393, 0x99FA7094, 0x0203DF01,
    0xF606FD10, 0x10DC0290, 0x25A741FC, 0x6CAF778E, 0x819139F6, 0xAB238B02, 0xFE1DDD2E, 0x9B41931B, 0x861C8516, 0xE60FAF3E, 0xDA17BE24, 0xFB09CC0F, 0x1C9A04FD, 0xA0900848, 0xC910D50A, 0x1F07FA1F,
    0xD61550A3, 0xE18C1004, 0x0E8E0C07, 0xA506F23C, 0xA6030A02, 0xF847E108, 0x160CF119, 0x12AC270F, 0x27069B11, 0x2AE9323B, 0x0016DC79, 0x49AE8F01, 0x000C029E, 0x3FC1ED01, 0x0009E5A1, 0x4989C101,
    0x028128D7, 0x8101000C, 0x8BEC01CF, 0x16CACC07, 0x4D9C068C, 0xFC16FAAC, 0x95B007B3, 0x029E660B, 0x01B49C0C, 0x010024FC, 0x9149CDBC, 0x01000C02, 0x3B04D0E7, 0x3C093C09, 0x39093C09, 0x38093609,
    0xB326C89C, 0x81451D97, 0x4EC3161F, 0x010033D7, 0x9E4A948F, 0x01000C02, 0x9E4ACDDF, 0x01000C02, 0x004A9988, 0x0DAE9101, 0xC427DB90, 0x418913C6, 0x0992361A, 0xAEA30894, 0x01891901, 0xF4AF0100,
    0x0C029E4A, 0x99AF0100, 0x0C029E4B, 0xB8DE0200, 0x0806004B, 0x02000806, 0x004BB8A2, 0x08060806, 0xC2980200, 0x01D5000F, 0x01FD8700, 0x0283F200, 0x12A1A900, 0x23AADC00, 0x0027A900, 0x0001FDA2,
    0x08060806, 0xB68E0200, 0x0806004B, 0x02000806, 0x004BBB90, 0x08060806, 0xBAF20200, 0x0806004B, 0x02000806, 0x004BB580, 0x08060806, 0xB7D00200, 0x0806004B, 0x02000806, 0x004BB9CE, 0x08060806,
    0xBABE0200, 0x0806004B, 0x02000806, 0x004BB59E, 0x08060806, 0xB9B00200, 0x0806004B, 0x02000806, 0x004BB6E0, 0x08060806, 0x89AA0200, 0xB0F20035, 0x08060016, 0x02000806, 0x004BB8C0, 0x08060806,
    0xBECE0200, 0xE9C30011, 0x1AA50001, 0x37F6D000, 0x06080600, 0xF0020008, 0x06004BB5, 0x00080608, 0x0FC58A02, 0x169EE600, 0x25D3BA00, 0x06080600, 0x9F020008, 0xD5000FC2, 0xBD980001, 0xE4940004,
    0xD2DD0011, 0xFCD10023, 0x08060001, 0x02000806, 0x004BB7EE, 0x08060806, 0x8ADC0200, 0xAC9E004A, 0x08060001, 0x02000806, 0x004BBA82, 0x08060806, 0xC2910200, 0x01D5000F, 0x04BD9F00, 0x35908C00,
    0x0027AA00, 0x0001FDF3, 0x08060806, 0xE8B10200, 0xD7980013, 0xFBDD0007, 0x0806002F, 0x02000806, 0x0046CBBC, 0x02D30020, 0x006AA200, 0xA0000DED, 0x060003F6, 0x00080608, 0x36CFB702, 0x0002E900,
    0x0014EC88, 0x08060806, 0xCC840200, 0x02D20046, 0x04EEB200, 0x06080600, 0xC9020008, 0xE20047FA, 0xBFCD0001, 0x08060003, 0x02000806, 0x004BBC9E, 0x08060806, 0xBF9E0200, 0x0806004B, 0x02000806,
    0x0036C7FF, 0x0014F5DD, 0x08060806, 0xC4DF0200, 0x01FE0036, 0x14F6DD00, 0x06080600, 0xBE020008, 0xE20047FA, 0xC0940001, 0x08060003, 0x02000806, 0x004BBF80, 0x08060806, 0xC98F0200, 0x01FE0036,
    0x00019A00, 0x0014F1DF, 0x08060806, 0x85A90200, 0x75A30047, 0x0001E200, 0x0003BFA8, 0x08060806, 0xBEE20200, 0x0806004B, 0x01000806, 0x9135ACCA, 0x129ED401, 0x020BBA03, 0xACC40100, 0xB7019135,
    0x001112AD, 0x35ACBF01, 0xCC950190, 0x01000511, 0x8235ACEB, 0x129FE301, 0x0502D402, 0xFCA10100, 0xD402E823, 0x018211AD, 0x1812B4BF, 0x00230AAD, 0x23FCAA01, 0xADB402FA, 0xF7018111, 0x9C0611B0,
    0x0100030B, 0xC54BC9A6, 0x01001145, 0xF94BC9E1, 0x01002634, 0x004BC884, 0x26A98E01, 0x259D862C, 0xC8A50100, 0x00398F4B, 0x4BC8E701, 0x005A23E6, 0x4BC7E301, 0xC8C60100, 0x003A8C4B, 0x4BC69E01,
    0x001E2221, 0x26ABC301, 0x259AEC37, 0xCBD20100, 0x03CD264B, 0x2D01D734, 0x2E231D30, 0x01E302C2, 0x4545325C, 0x1D1D019E, 0x451D1D26, 0x4C5E4D47, 0x1B1C1B22, 0x1B1C1C20, 0x47516F1C, 0x2C334852,
    0x2C394F46, 0x272F2A30, 0x3A019B2B, 0x314D0184, 0x010010AE, 0xE04BCDB6, 0x0003E521, 0x4BCBE401, 0xD0E60100, 0xF6010023, 0x193D4C8B, 0x00341A0D, 0x4C8F9101, 0xF5EE0100, 0x01000B4B, 0xBE4C8D8F,
    0x91010032, 0x01004C83, 0x914CB68C, 0xEA010009, 0x01004CCF, 0xE54CCFD8, 0x130A1F0E, 0xFDB90100, 0x0020C54C, 0x4D9EEE01, 0x82010016, 0xA7019623, 0x04DD4CF8, 0x8BEF0100, 0x8009F14D, 0xD822C901,
    0x018C142E, 0xCFB20100, 0x86010023, 0xD2404DA0, 0x002CFA17, 0x4D80BA01, 0x01001CB0, 0x4C4DA4E7, 0x17831393, 0x3C1CC62E, 0x01C865B4, 0x01D901EC, 0x028301E3, 0x01DB01D0, 0x01D60283, 0x028F01EF,
    0x01E635AD, 0x01F1028C, 0x02A3028D, 0x01FD01EC, 0x01FA02A4, 0x02B8028A, 0x01DA39C1, 0x02C902A7, 0x02BA01CF, 0x01FA02E5, 0x02E902B7, 0x02DC028E, 0x028B40C5, 0x02E902C7, 0x02C40295, 0x029B0384,
    0x02E402EC, 0x02FC02AE, 0x01DA3CC2, 0x02C102A7, 0x02BB01D6, 0x01F502E5, 0x02D1029C, 0x02DC0286, 0x01FB3F95, 0x02E102C7, 0x02DB01F6, 0x028A0384, 0x02DC02ED, 0x038C0286, 0x028A4392, 0x02F202CE,
    0x02EB01FE, 0x02A1038E, 0x02FC0385, 0x039602B3, 0x02AB4985, 0x039202FE, 0x038B029E, 0x02CB03BD, 0x03A40393, 0x03AD02DD, 0xB8E50100, 0x9759954D, 0x01B04523, 0x01AA0282, 0x01DD01D4, 0x1601C516,
    0x01F801CF, 0x4D01D10E, 0x028701BC, 0x5D019B65, 0x028801C9, 0xD1018170, 0x5301D601, 0xA84D0182, 0xC6028201, 0x01BE1601, 0xD51601ED, 0x01D21601, 0x01E901FF, 0x8701BC4D, 0x019B6502, 0x8801C95D,
    0x01947002, 0x01F401F0, 0x45019E4B, 0x029F01D1, 0xD91601CB, 0x14028E01, 0xF51601F1, 0x1502A301, 0xDE4D01ED, 0x6502A601, 0xFD5D01BA, 0x7002A501, 0x01EE01A2, 0x9A5301F6, 0x01D24D01, 0x01DB02A2,
    0x8E01E916, 0x01F21402, 0xA201F516, 0x01FD1502, 0xA601DE4D, 0x01BA6502, 0xA501FD5D, 0x01B37002, 0x02A9028E, 0x029301F6, 0x01E402B3, 0x6B01B659, 0xA36E01CD, 0x01B46B01, 0x7F01CD7D, 0xB96601A0,
    0x01EE7801, 0xE77201F8, 0xAD230E01, 0x9F028902, 0x8602B902, 0xC302A302, 0x5E01F302, 0xD67001C2, 0x01B56F01, 0x8101C66A, 0x8401D701, 0x6601A201, 0xEE7801B9, 0x7201F801, 0x230E01E7, 0x029602AD,
    0xA81D02BD, 0x01FC2402, 0xB91D02CC, 0x59028302, 0x220E01EB, 0x220E0292, 0xFB6B01FA, 0xA5220E01, 0xF4230E02, 0x01EE6601, 0x02BD220E, 0x877202A9, 0xCD230E02, 0xCC02BC02, 0xA602D902, 0x1D02DC02,
    0x029202B9, 0x0E01F75E, 0x2002B022, 0x8B6A0282, 0xB3230E02, 0xFB230E02, 0x01EE6601, 0x02BD220E, 0x877202A9, 0xCD230E02, 0x8E029C02, 0xF202A902, 0xB3029701, 0x5D01E202, 0xC16B019E, 0x019F7201,
    0x8001B16E, 0x8501CD01, 0x6D019701, 0xE87B01AE, 0x7901EF01, 0x018D01A7, 0x02810288, 0x02B9029F, 0x02A30286, 0x01F102C3, 0x7001A962, 0xA17101CD, 0x01B26E01, 0x01D90182, 0x0199018A, 0x7B01AE6D,
    0x01EF01E8, 0x8D01A779, 0x8A028801, 0x2202A502, 0x9602A108, 0xD302B302, 0x5D028102, 0x082201EC, 0x08220287, 0xFA6E01EC, 0x9B082201, 0xF9082202, 0x01E96D01, 0x02CB0822, 0xF279029F, 0xDC082201,
    0xBC02A402, 0xA602D902, 0xE302C302, 0x62029002, 0x082201F8, 0x08220297, 0xF86E01FE, 0xAB082201, 0xF0082202, 0x01E96D01, 0x02CB0822, 0xF279029F, 0xDC082201, 0x34028E02, 0x3401FC02, 0x2602A402,
    0x2F01ED02, 0x2F028E02, 0x2D02AC02, 0x3B01C502, 0x01BB2D16, 0xCD2D164F, 0x42163B01, 0x164F01A7, 0x6501B52D, 0x01C82D16, 0xA042164F, 0x3A163B01, 0x164F01BE, 0x2D01F53A, 0x4C01EB02, 0x01BF3716,
    0x86371665, 0xF1022D02, 0x8D023401, 0xA4023402, 0xFD022602, 0x9E022F01, 0xBC022F02, 0xD5022D02, 0x32163B01, 0x164F01C6, 0x3B01D832, 0x01B14716, 0xC132164F, 0x32166501, 0x164F01D5, 0x3B01A344,
    0x01BE3A16, 0xF53A164F, 0xEB022D01, 0x37164C01, 0x166501BF, 0x2D028637, 0x3401FA02, 0x34029D02, 0x2602C402, 0x2F028D02, 0x2F02AE02, 0x2D02CC02, 0x3B01F402, 0x01DC2D16, 0xF02D164D, 0x42163901,
    0x164F01C7, 0x6301D62D, 0x01EA2D16, 0xBF42164F, 0x3A163B01, 0x164D01DF, 0x3202923A, 0x4C028B02, 0x01DF3716, 0xA5371663, 0x9E023202, 0xAE023402, 0xD4023402, 0x9D022602, 0xBE022F02, 0xDC022F02,
    0x84022D02, 0x32163B02, 0x164D01E7, 0x3901FB32, 0x01D14716, 0xE232164F, 0x32166301, 0x164F01F7, 0x3B01C244, 0x01DF3A16, 0x923A164D, 0x8B023202, 0x37164C02, 0x166301DF, 0x3202A537, 0xCB010002,
    0x01004DC7, 0xAF4D81C5, 0xD401001B, 0x45F54DA3, 0xBA900100, 0x8916834D, 0x8301CB65, 0xD706D702, 0xA4028701, 0xB301FF08, 0xCB078302, 0x97028301, 0x8E01DA07, 0xFF08AA02, 0xE702B301, 0xA301E907,
    0xFC07F202, 0xA702B301, 0xD302B009, 0xF507F902, 0x9302A301, 0xB401FA08, 0xB009B702, 0xC102D302, 0xB3028108, 0xA3098802, 0xB402CB02, 0xE102AB09, 0x91098B02, 0xC602C302, 0xDC02B409, 0xAB09BB02,
    0xE402E102, 0xE302B109, 0xBB0A8702, 0xCB02ED02, 0x8102CB0A, 0xC10AAB03, 0xB602E302, 0xFE02CB0A, 0xCB0AD202, 0xE9038102, 0xB3028508, 0xA308E702, 0xA302CD02, 0xD902A309, 0x91098B02, 0x9602C302,
    0xDE02A309, 0xA309AA02, 0xC402D902, 0xD302A109, 0xBA09E602, 0xCC02DE02, 0x8102BB0A, 0xB10A8B03, 0xA602E302, 0xEE02BA0A, 0xBB0AC302, 0xF3038102, 0xE302B109, 0xD30AB802, 0xF302FC02, 0x8902E40A,
    0xC10AAA03, 0xF702F302, 0x8B02E40A, 0xE40AFB03, 0xF3038902, 0x8302D10A, 0xF40BC703, 0xF3039C02, 0xA803840B, 0xE10BCB03, 0x86039302, 0xAB03850C, 0x840BFB03, 0x0003A803, 0x4DB5C101, 0x010002F5,
    0xB14D9FC2, 0x01000D18, 0xEE4DB5A4, 0xA0018E01, 0x8C018D44, 0xA2018C01, 0x37373D01, 0x9033395D, 0x37373D01, 0x9033395D, 0x37373D01, 0x8F33395D, 0x34343A01, 0xC3363656, 0xDD01D201, 0xDC01DC01,
    0x6501EA01, 0x01926565, 0x01C75468, 0x92656565, 0xC7546801, 0x65656501, 0x54680192, 0x616101BE, 0x5C018B61, 0xE801B456, 0xAB028901, 0xF601DA01, 0xF801B701, 0x56028001, 0x029B01DB, 0x01E402A5,
    0x038502B5, 0x01F801D6, 0x01E801C8, 0x01BE0289, 0x028601E7, 0x01FB01C7, 0xDB4F028C, 0xA5029B01, 0xB501E402, 0xEF02A202, 0xF901E701, 0xED028A01, 0xE6029B01, 0x9601FD01, 0xA2028102, 0xBC028502,
    0xBF01FA02, 0x9202DD02, 0xCC02C202, 0xF9028A01, 0xB101D601, 0xF602AB02, 0x9901FD01, 0xA901F702, 0xBC029502, 0xBF01FA02, 0x9202DD02, 0xCF02CF02, 0xBE029201, 0xAA01BA02, 0xEF02D502, 0xB902BC01,
    0xD601FF02, 0xFF02BF02, 0xC402CC01, 0xDC028E02, 0xDF02CF02, 0xCE02A201, 0xBA01CA02, 0xFF02E502, 0xEE02B201, 0xDC028E02, 0xFF02CF02, 0xC402CC01, 0xDC028E02, 0xC602CF02, 0xD4028502, 0xBF028502,
    0x8F02F502, 0xD902DC02, 0xF6029F02, 0x9F02DF02, 0xEB02F502, 0x8502AE02, 0x8F02F603, 0xEE02C202, 0xBF029502, 0x9F038502, 0xE402EC02, 0xFC02AE02, 0x9F02EF02, 0xEB02F502, 0x8502AE02, 0xCF02F603,
    0xB1029701, 0xAB01C102, 0xE302D502, 0xB902A801, 0xD601FF02, 0x8302BF02, 0xBC02B802, 0xDC028602, 0xDF02CF02, 0xC602A201, 0xBB01D102, 0xEC02E502, 0xD602A501, 0xDC028602, 0x8302CF02, 0xBC02B802,
    0xDC028602, 0xBC02CF02, 0xD801E302, 0xCB01E102, 0xD602F502, 0xE201EC02, 0x81028402, 0xD802DF03, 0xE302BC02, 0x85029D02, 0xFF02EF03, 0xE602C201, 0xDB01F102, 0xEF038502, 0xDC028C02, 0x91028102,
    0xD802DF03, 0xE302BC02, 0x85029D02, 0xFF02EF03, 0xE802C801, 0xDB01E902, 0x93038102, 0xE002F502, 0xFC02AF02, 0xA3038502, 0xEC02FC02, 0x8202C602, 0x8F02F903, 0xFD02C302, 0xEB01F902, 0x9B039902,
    0xF0038502, 0x9602BF02, 0xA3038B03, 0xEC02FC02, 0x8202C602, 0x9F02F903, 0x8D02E302, 0xFB028903, 0xBC03B102, 0x89038302, 0x9302D803, 0xCC03A503, 0x83039C02, 0xAC02EF03, 0xAF039603, 0x9D02F302,
    0x8B029903, 0xC403C903, 0x99039302, 0xAD02E803, 0xCC03AB03, 0x83039C02, 0xAC02EF03, 0xB5010003, 0x01EA4DB5, 0x44A1018A, 0x018C018D, 0x018E018C, 0x5E37373D, 0x01804239, 0x5E37373D, 0x01804239,
    0x5E37373D, 0x3A7F4239, 0x36573434, 0xD101D536, 0xDC01DD01, 0xEA01DC01, 0x66656501, 0x51670192, 0x656501CA, 0x67019266, 0x6501CA51, 0x01926665, 0x01C75167, 0x8B616161, 0xA94E5B01, 0xF701F701,
    0xE901AE01, 0xBA01E401, 0x85028701, 0x01CB6102, 0x02AE029B, 0x02B501DB, 0x01F702E4, 0x01CB01E6, 0x01F701F7, 0x01F601C1, 0x01CA01F4, 0x028E028A, 0x9B01CB5D, 0xDB02AE02, 0xA002B501, 0x9701C002,
    0xCC028002, 0x9402AB01, 0xC601B602, 0xF201DC02, 0x8902E401, 0xFB02A602, 0xB002D301, 0xC002AB02, 0xA801AF02, 0xD6028002, 0xA402B101, 0xC601C602, 0x9701E102, 0x9902BA02, 0xFB02A602, 0xB002D301,
    0xD502AB02, 0x9701C902, 0xBF02B902, 0xD602AA01, 0xBC01E902, 0xF902BF02, 0xC502D601, 0xCC01F902, 0x8E02C402, 0xD202DC02, 0xA701DC02, 0xCF02C902, 0xE302BA01, 0xB701FC02, 0x8E02E902, 0xD502DC02,
    0xCC01F902, 0x8E02C402, 0xDA02DC02, 0x9702A902, 0x8502D402, 0xFB02C402, 0xDC028402, 0x9402E402, 0xEA02F602, 0xF5029402, 0xAE02EB02, 0xF9038502, 0xC7028C02, 0x9502E902, 0x8302C402, 0xEC029C03,
    0xAE02E402, 0xFA02FC02, 0xF5029402, 0xAE02EB02, 0xFC038502, 0x9701C902, 0xC602B102, 0xD602AB01, 0xA001E502, 0xF902BF02, 0xC502D601, 0xB0028502, 0x8602BC02, 0xD202DC02, 0xA701DC02, 0xD102C102,
    0xE302C001, 0xA401EF02, 0x8602D102, 0xD502DC02, 0xB0028502, 0x8602BC02, 0xDA02DC02, 0x82029702, 0xE102D302, 0xFB02D001, 0xCA01ED02, 0xF902ED02, 0xEA038101, 0xFE028B02, 0x9D02E302, 0xF2038502,
    0xC701FC02, 0xF102E102, 0x8302E001, 0xF3028503, 0x8102DC02, 0xEA039102, 0xFE028B02, 0x9D02E302, 0xF5038502, 0xCE01F902, 0xEE02E202, 0xFE02DB01, 0xF5029102, 0xA202ED02, 0x8702FC02, 0xFC02A103,
    0xC602EC02, 0xFC038202, 0xC8028C02, 0xF902F802, 0xFF02F001, 0x8502B002, 0xBC02F303, 0x8D039602, 0xFC02A103, 0xC602EC02, 0x84038202, 0xE3029403, 0x89038D02, 0xB4038002, 0x8302B403, 0xCD039403,
    0xAD039302, 0x9C02C403, 0xEF038303, 0x9903AC02, 0xF302AC03, 0x99039D02, 0xAF039002, 0x9302D903, 0xE5039C03, 0xB303AD02, 0x9C02C403, 0xEF038303, 0x0003AC02, 0x4DA5CF01, 0x03830FE8, 0x01DA59F1,
    0x01DC01DD, 0x01E801DC, 0x92626565, 0x029F6B01, 0x92626565, 0x029F6B01, 0x92626565, 0x02936B01, 0x8B616161, 0x03F26101, 0x038F0283, 0x03B901F0, 0x02DB0283, 0x048D029B, 0x04B602B5, 0x03BA01F2,
    0x03AF0283, 0x03CC0280, 0x02D7028C, 0x048D029B, 0x04F002B5, 0x03EE0280, 0x03DF02A1, 0x04980292, 0x038E02A5, 0x04DD02C5, 0x058602D5, 0x04880280, 0x03FF0297, 0x04880292, 0x039602B5, 0x04DD02C5,
    0x049002D5, 0x03FC0297, 0x04C202AB, 0x04BC02BC, 0x04C202D6, 0x04D602CC, 0x04BB02DC, 0x049C02A7, 0x04E202BB, 0x04FB02B7, 0x04C902DC, 0x04D602CC, 0x04C702DC, 0x04DD02E9, 0x058202C5, 0x04FC02DC,
    0x058202F6, 0x05A602EC, 0x059B02FC, 0x058202C7, 0x05A202C5, 0x059602EC, 0x058902FC, 0x05A602EC, 0x04C002FC, 0x03F602A5, 0x049002A2, 0x04BC02CF, 0x049F02D6, 0x04C602DF, 0x04BB02DC, 0x049602B5,
    0x04B302B2, 0x04CD02D5, 0x04A602DC, 0x04C602DF, 0x049C02DC, 0x04B702FC, 0x04E902C2, 0x04DE02E4, 0x04F202FD, 0x058D02F5, 0x04FB0385, 0x04D602D5, 0x058902D2, 0x04F002F6, 0x04E90389, 0x058D02F5,
    0x04E00385, 0x04CF02DC, 0x059302D2, 0x059302F5, 0x05AC02FC, 0x05B602FC, 0x05950382, 0x04EF02DC, 0x05B302E2, 0x05B30385, 0x05A90396, 0x05B602FC, 0x05AE0382, 0x058F02FC, 0x05E302F2, 0x05DC038C,
    0x05EC039C, 0x05F6039C, 0x05DB03AC, 0x05AF038C, 0x06830382, 0x05FC039C, 0x05E903B6, 0x05F6039C, 0x010003AC, 0xBC4DA5D7, 0xBC07E30C, 0x01AD1C57, 0x2B01AD2B, 0xAD2B01AD, 0x01AF2B01, 0x3306A533,
    0xA23306A5, 0x07D53406, 0x1F01D31E, 0xBD1C02FF, 0x038C2B01, 0x2C01D31C, 0x801103E6, 0x03F71802, 0x0C02A011, 0xBD1C0392, 0x038D2B01, 0x1F01D31E, 0xCD1C039F, 0x039D2B01, 0x2C01E01E, 0x801103E6,
    0x03F71802, 0x0C02A011, 0xD52303BC, 0x03B53201, 0x2501ED28, 0xE52303B7, 0x03E42401, 0x25028123, 0xA02104A0, 0x04C71802, 0x0C02C011, 0xD41F03CF, 0x03CF3201, 0x2501ED1E, 0xE52303D7, 0x03DE2401,
    0x25028129, 0xA02104B0, 0x04C71802, 0x0C02C011, 0x841D03FA, 0x03D42402, 0x2401F324, 0x9B1D049C, 0x049B1D02, 0x0F02BB1D, 0xB21D04A9, 0x04B81902, 0x1202CC0C, 0x941D049F, 0x03F42402, 0x24028324,
    0xA41D04BC, 0x04CB2402, 0x0F02C90F, 0xB21D04B0, 0x04B81902, 0x1202CC0C, 0xB03504AB, 0x04C21D02, 0x2402A316, 0xBE1A04DC, 0x04DE1A02, 0x0F02DE1A, 0xD51A04E9, 0x05881902, 0x1202EC0C, 0xB41D04FF,
    0x04D22402, 0x2402A316, 0xCE1A04FC, 0x04FB1D02, 0x0F02EC0C, 0xD51A04F0, 0x05881902, 0x1202EC0C, 0xE41A04A4, 0x03D14401, 0x14028627, 0x922D03F5, 0x049E1A02, 0x0F02BE1A, 0xA22D0492, 0x04AB1D02,
    0x1502C60C, 0xF41A04A2, 0x03F14401, 0x14029627, 0xF92D0494, 0x04AE4401, 0x0F02CC0C, 0xA22D0499, 0x04AB1D02, 0x1502C60C, 0xB51C0490, 0x04913C02, 0x1402A627, 0xB00F04C2, 0x04C03B02, 0x2702B528,
    0xD02104E3, 0x04F21D02, 0x1502EA11, 0x941A04E2, 0x04B14402, 0x1402B627, 0xE10F04E2, 0x04D41A02, 0x2702C524, 0xD02104DA, 0x04F21D02, 0x1502EA11, 0x891D04C7, 0x04B44F02, 0x2502A224, 0xD41D04EC,
    0x04FC1302, 0x1D02DB1D, 0xE21D058B, 0x05981902, 0x2002E90F, 0x891D04F1, 0x04D44F02, 0x2502B224, 0xE41D058C, 0x059C1302, 0x0F02FB1D, 0xE21D0590, 0x05981902, 0x2002E90F, 0xA91D058A, 0x04F44F02,
    0x2502C224, 0xEB1D05BC, 0x05BB1D02, 0x1D02FB1D, 0x821D05CB, 0x05D81903, 0x1203990F, 0xB91D05BF, 0x05944F02, 0x2502D224, 0xFB1D05DC, 0x05DB1D02, 0x0F039B1D, 0x821D05D0, 0x05D81903, 0x1203990F,
    0xFED60100, 0x001FD54C, 0x23A6A101, 0x002A91EB, 0x4D9EDA01, 0x010049FE, 0x394DE9F3, 0x02865BCD, 0x01FF02A3, 0x02B20293, 0x028617CB, 0x01FF02A3, 0x02B20293, 0x02A91AAC, 0x029E02C1, 0x02D002C6,
    0x02A91AFA, 0x029E02C1, 0x02D002C6, 0x02B51D99, 0x028E02CE, 0x02DA02D6, 0x02B51EC7, 0x028E02CE, 0x02DA02D6, 0x02DF20D8, 0x02BC02E7, 0x02FA02F6, 0x02DF2286, 0x02BC02E7, 0x02FA02F6, 0x02AD1D87,
    0x028E02C6, 0x02E602B8, 0x02AD1E89, 0x028E02C6, 0x02E602B8, 0x02DD1FEA, 0x02BE02E7, 0x02FB02E3, 0x02DD2198, 0x02BE02E7, 0x02FB02E3, 0x02E921F0, 0x02C402F8, 0x038902FD, 0x02E9238D, 0x02C402F8,
    0x038902FD, 0x038824FE, 0x02E4039A, 0x03AD039B, 0x038826DA, 0x02E4039A, 0x03AD039B, 0x80FF0100, 0xFE13FD4D, 0xD0010007, 0x1FE14CFE, 0xB0F90100, 0xF268F123, 0x018906A1, 0x8F22D7CA, 0x08827901,
    0x27F21EA5, 0x0CA003D4, 0xD09E0100, 0x29EA8423, 0xB1B90100, 0x03E62F4D, 0x0013019F, 0x4EF5A101, 0x02800298, 0x028C01E2, 0x01CC029D, 0x0295028F, 0x02A601E3, 0xF15A02C1, 0xBE02C501, 0xD5029B02,
    0x9E038D02, 0xE6028202, 0x99029C01, 0x9F01DC02, 0xE4029502, 0xC502A101, 0x01F16202, 0x02BE02C5, 0x02D5029B, 0x01DC57C5, 0x02D402F9, 0x02C40285, 0x029902E6, 0x02CF02DC, 0x02F602A9, 0x02A902D5,
    0x02EB02F5, 0x038502AE, 0x02840381, 0x02E902C7, 0x02C40295, 0x0294038B, 0x02E402EC, 0x02FC02AE, 0x02A902E5, 0x02EB02F5, 0x038502AE, 0x01FC56CC, 0x02D302B2, 0x02D001E1, 0x028802E6, 0x02D802C4,
    0x0381028E, 0x02A002D5, 0x02E302FE, 0x0385029D, 0x01F402FA, 0x02E102C7, 0x02E001F1, 0x0283038B, 0x02DC02ED, 0x03910281, 0x02A002D5, 0x02E302FE, 0x0385029D, 0x02A964D5, 0x038802E8, 0x03800289,
    0x02C503A3, 0x02FF0383, 0x039302E2, 0x02D5039C, 0x0383039C, 0x03AC02EF, 0x02A403A1, 0x039D02F3, 0x03900299, 0x02C503C3, 0x03A40393, 0x03AD02DD, 0x02D503A2, 0x0383039C, 0x03AC02EF, 0xF5B00100,
    0x8602924E, 0x8F01E102, 0xC3029B02, 0x95029201, 0xAF01E702, 0x7B02A202, 0x02C501E2, 0x028C02CD, 0x039B02D5, 0x0289028F, 0x029801E5, 0x01D3029E, 0x029502A2, 0x02A501E8, 0x018302AB, 0x02C501E2,
    0x028C02CD, 0x57D402D5, 0x02F401D2, 0x028502D4, 0x02F502C4, 0x02DC028A, 0x029A02DE, 0x02E402F6, 0x02F5029A, 0x02AE02EB, 0x02F00385, 0x02C70295, 0x029502E9, 0x02FA02C4, 0x02EC02A5, 0x02AE02E4,
    0x02F402FC, 0x02F5029A, 0x02AE02EB, 0x56DB0385, 0x02B001EF, 0x01E602D3, 0x02F502CB, 0x02CF01F9, 0x028402DC, 0x02E402FC, 0x02FE0291, 0x029D02E3, 0x02E90385, 0x02C70285, 0x01F102E1, 0x02FA02E0,
    0x02ED0294, 0x028102DC, 0x02E40391, 0x02FE0291, 0x029D02E3, 0x64E40385, 0x02EE029A, 0x028E0382, 0x03AD02FB, 0x038302BB, 0x02CC0395, 0x03A60393, 0x039C02CB, 0x02EF0383, 0x039003AC, 0x02F802B5,
    0x02990398, 0x03B10390, 0x039302D7, 0x02EE0393, 0x03AC03AD, 0x039C02CB, 0x02EF0383, 0x010003AC, 0x2F4DB1A7, 0x478403AF, 0x36523751, 0x38523652, 0xE53303E5, 0x03E53303, 0x4C03DB25, 0xA13C018C,
    0x01A23701, 0x3601A236, 0x9D4301A2, 0x069D3B06, 0x27069D3B, 0x251A0683, 0x01AC487C, 0x2C01C13C, 0x01A2446C, 0x1D01BA36, 0xB34A018F, 0x01C44001, 0x56019B2E, 0xB07201BE, 0x018D5301, 0x6801B968,
    0x673701D0, 0x3C019C4B, 0x843301BC, 0x01B44001, 0x2B01C934, 0xAA420187, 0x01C23E01, 0x47019624, 0xC83E01C2, 0x019B2A01, 0x7201BE56, 0x8D5301B0, 0x01B96801, 0x4A01D068, 0x01DB326E, 0x4101C24C,
    0xD83E018A, 0x01CF4A01, 0xE9267C3B, 0x01B06701, 0x33018E47, 0xFD3201FB, 0x01B72D01, 0x7C01CF6E, 0xA46401BE, 0x02963F01, 0x4A01DE6E, 0x01B25976, 0x3901CA46, 0xC45C0196, 0x01D74401, 0x2E018443,
    0xB85F01F1, 0x01A14001, 0x2901EA39, 0xB7350285, 0x01CF6E01, 0x6401BE7C, 0x963F01A4, 0x01DE6E02, 0xBA6D7F53, 0x01BB6801, 0x5E01B225, 0xC66901C9, 0x01984A01, 0x7001C874, 0xAE4901CB, 0x01DA6E01,
    0x4601ED5F, 0xD57301A9, 0x01D56B01, 0x6101D62D, 0xFC6201F6, 0x01844F01, 0x7301BF79, 0xC02701C0, 0x01CE6901, 0x5401CB74, 0xCD7C01A1, 0x01D37501, 0x6901D734, 0xF26901EF, 0x01A94801, 0x6B01D573,
    0xD62D01D5, 0x01F66101, 0x5801FC62, 0xD4730192, 0xBE018C01, 0x01D83A01, 0x9001D478, 0x5601D901, 0xE37901AC, 0x01E67501, 0x7701BE55, 0xF76C01F5, 0x01B95B01, 0x6801F07C, 0xF63501FB, 0x02867301,
    0x6A02CC36, 0x0193019B, 0x018301CF, 0xE62501D0, 0xD9018301, 0xDE018B01, 0x01B16001, 0x01E80185, 0x01D00188, 0x7B01F72F, 0xFC7E01FA, 0x01B95D01, 0x6801F07C, 0xF63501FB, 0x02867301, 0x2D02CC36,
    0xC06801A0, 0x01A96D01, 0x7301A82C, 0xEA4D01B7, 0x01BB2D01, 0x6201CD56, 0xD02601D2, 0x01E06801, 0x2701E861, 0xDD6201CF, 0x01C96A01, 0x5B01D429, 0xE47901F0, 0x01AD2A01, 0x7801C574, 0xBA2E01AE,
    0x01BC7A01, 0x2F01EF58, 0xD26101C8, 0x01C27301, 0x6601D22A, 0xED7301E5, 0x01CF2901, 0x6A01DD62, 0xD42901C9, 0x01F05B01, 0x2D01E479, 0xC67801BF, 0xB9018701, 0x01D22A01, 0x5D01C77B, 0xDD2B01FD,
    0xCB018901, 0x01D27601, 0x8101EE1F, 0x7101DF01, 0xED3401E5, 0x01EE7801, 0x01DC0184, 0x7401F434, 0x018E01F4, 0xCF2B01F4, 0xD5018101, 0xBE018801, 0x01E02C01, 0x01CC0186, 0x2D028268, 0x019501EA,
    0xDD7901D0, 0x01F22201, 0x01E20187, 0x2601EA7E, 0xEE7801ED, 0xDC018401, 0x01F43401, 0x8E01F474, 0x4C01F401, 0xDF7001AC, 0x01E07301, 0x6501DB30, 0xEF7001F2, 0x01EF1D01, 0x7301F771, 0x872501F9,
    0x029F5D02, 0x1E029E59, 0x847401FC, 0x02955C02, 0x6201ED45, 0x8F6C02A8, 0x01B15002, 0x6E01E47C, 0xE93201E5, 0x01F77001, 0x2201F47B, 0xFC7C01FA, 0x01FE7E01, 0x69029427, 0x9F6102A4, 0x01FC2702,
    0x5C028474, 0xED450295, 0x02A86201, 0x59028F6C, 0x018201BB, 0x018301EF, 0xFD2E01F0, 0x02827501, 0x02820180, 0x82028D2B, 0x83028501, 0x2D028401, 0xA76E02A5, 0x02AC7102, 0x85029A21, 0x7E029201,
    0xFB590291, 0x02F63801, 0x6302F332, 0x018E01C0, 0x018E01F4, 0x8B3001F5, 0x87018002, 0x87018B02, 0x029B2D02, 0x028A018D, 0x0289018E, 0x7A02B22F, 0xAF7902AC, 0x029A2802, 0x02920185, 0x5902917E,
    0xF63801FB, 0x02F33202, 0xB1B00100, 0x03AF2F4D, 0x137546DD, 0x12761276, 0x04891476, 0x0F04890F, 0xD52C0489, 0x01B52203, 0x4501933C, 0x94440194, 0x01944401, 0x2D06AB35, 0xAB2D06AB, 0x06833506,
    0x01881A0C, 0x5B01C92A, 0x891B01A4, 0x01CB1B01, 0x2B01AC36, 0xDC2F0181, 0x01DA2B01, 0xA86C7943, 0x01C66901, 0x5101B828, 0x813701D0, 0x01851802, 0x3C01C522, 0x902801AE, 0x01D12201, 0x3701AC53,
    0x01D32779, 0x3E01B43E, 0x01DF287E, 0x3E01DF37, 0x01A86C79, 0x2801C669, 0xD05101B8, 0x02813701, 0x4D019720, 0xB44A01C2, 0x01A12B01, 0x5C01D151, 0xA41F01B2, 0x01D04101, 0x1E01E730, 0xE24E01B5,
    0x01F33901, 0x3B018752, 0xD467028E, 0x01D53301, 0x2D029241, 0x9F2002A1, 0x01E22901, 0x2301BC46, 0xE13E01AD, 0x01BA6301, 0x4901AC27, 0xEF2801D8, 0x01B51C01, 0x33028E22, 0x875A01FB, 0x028E3B01,
    0x3301D467, 0x924101D5, 0x02A12D02, 0x5D01A928, 0xDD3A01CA, 0x01B72001, 0x4B01EB3C, 0xC22C01E4, 0x01D86401, 0x1F01DB60, 0xEA5E01D8, 0x029E2F01, 0x6301D31B, 0xEC5501E5, 0x01DB1B01, 0x3102A73D,
    0xB61C02AD, 0x01CF6901, 0x2201E245, 0xF04701C5, 0x01E95601, 0x6C01D32E, 0xF54701DD, 0x01DC2F01, 0x2F02A93C, 0xD31D02AC, 0x01E56301, 0x1B01EC55, 0xA73D01DB, 0x02AD3102, 0x6101CA1F, 0xD47301EA,
    0x01DD2801, 0x6501EB6E, 0xE42A01F7, 0x01D57B01, 0x01D80183, 0x7901F629, 0xB93601E7, 0x01F12302, 0x3A01E27E, 0xFB2302B6, 0x02C83D01, 0x2802C839, 0x018301DE, 0xF25501DF, 0x01EB2001, 0x6001F079,
    0xF42901FC, 0xDA018701, 0x01E67F01, 0x3C01FC1D, 0xC73202C6, 0x01F12502, 0x3A01E27E, 0xFB2302B6, 0x02C83D01, 0x4C02C839, 0x01B27676, 0x4501BA69, 0xC863018E, 0x01C57101, 0x6401914B, 0xC47001BF,
    0x01A65001, 0x3D01D276, 0xA5440299, 0x01CF7001, 0x4201DF61, 0xA12B01BA, 0x02A73702, 0x01827B4E, 0xBF7401B7, 0x01975001, 0x7C01CD6A, 0x965501CA, 0x01C46F01, 0x4C01D36F, 0x9F2D01AF, 0x02A73902,
    0x7001A546, 0xDF6101CF, 0x01BA4201, 0x3702A12B, 0x875702A7, 0x02903C01, 0x5501CA75, 0xD86B01A6, 0xD8018101, 0x01A55701, 0x5401D77B, 0xB65901F4, 0x01F66801, 0x5E02B036, 0x018601B5, 0xB03E01E0,
    0x01C85E02, 0x3A028B5E, 0x8F5E02C8, 0xC7018F01, 0xCF018401, 0x01AB6001, 0x8C01DD76, 0x6101DD01, 0x018701AA, 0x018901DC, 0xBD6301CF, 0x01E87501, 0x5002BE38, 0x018601B5, 0xB03E01E0, 0x01C85E02,
    0x3A028B5E, 0xD62102C8, 0x01EF6001, 0x2C028343, 0x8B4B01E0, 0x028C5302, 0x6101EA2F, 0xBA310287, 0x01EC3502, 0x6802906C, 0xF62F028F, 0x02946501, 0x2C01FE66, 0xD93E0287, 0x029E5C02, 0x6C01E31E,
    0x883E01F4, 0x01EE2E02, 0x5E029056, 0xF8310291, 0x028C6C01, 0x4302C833, 0x957801ED, 0x02D93402, 0x6501F62B, 0xFE660294, 0x02872C01, 0x5C02D93E, 0xF321029E, 0x01FF7201, 0x2A029353, 0x9B5B0282,
    0x029F6302, 0x30028B3A, 0x947202D8, 0x01F94D02, 0x7302EE34, 0x982F029D, 0x02E53302, 0x1F02DD33, 0xF24702A7, 0x02EF3602, 0x7E028321, 0x985E0284, 0x02902C02, 0x6E02A066, 0x993C02A4, 0x02E63202,
    0x5802997D, 0xFC3701FD, 0x02FB2D02, 0x33029829, 0xDD3302E5, 0x02A71F02, 0x3602F247, 0x010002EF, 0xF64DA5C7, 0x03CF300B, 0xA01601A4, 0xDC01F05A, 0xDC01DC01, 0xDC01E301, 0xE606DC06, 0x9107D806,
    0x80038602, 0x9B039802, 0x9B03E602, 0xB5048D02, 0x8003AA02, 0x91039902, 0x9003A602, 0xAA03A902, 0x9B03E602, 0xB5048D02, 0xB003CA02, 0xC403B902, 0xBE03B302, 0xD503DA02, 0xC504A402, 0xD504DD02,
    0xA603E202, 0xB103DC02, 0xBE03D302, 0xD503DA02, 0xC504B402, 0xD504DD02, 0x97049002, 0xAA03FC02, 0xBC04C302, 0xD604BC02, 0xCC04C202, 0xDC04D602, 0xA704BB02, 0xBA049C02, 0xB704E302, 0xDC04FB02,
    0xCC04C902, 0xDC04D602, 0xEC04C402, 0xC404DD02, 0xDC058302, 0xF604FC02, 0x8C058202, 0x8B058603, 0xC7058C03, 0xC4058202, 0xEC05A302, 0xFC059602, 0x8C058902, 0x8B058603, 0x9D04B103, 0xA303FD02,
    0x9C04C302, 0xD604BC02, 0xAC04D202, 0xDC04C602, 0xAD04BB02, 0xB3049D02, 0x9E04E202, 0xDC04D502, 0xAC04D902, 0xDC04C602, 0xA604E302, 0xC304C502, 0xB2059502, 0xFC04E402, 0x8E04F302, 0x8504F403,
    0xCD04FB03, 0xD304DD02, 0xCA05B502, 0x8B04ED02, 0x8E04EA03, 0x8504F403, 0xCE04E003, 0xD304DC02, 0xF5059302, 0xFC059302, 0xFC05AC02, 0x8205B602, 0xCE059503, 0xE304FC02, 0x8505B302, 0x9605B303,
    0xFC05A903, 0x8205B602, 0xEE05AE03, 0xF3059C02, 0xEE068102, 0xF7068102, 0x8E068A02, 0xAC05F503, 0xFE05CC03, 0x8305BC02, 0xFE06A103, 0x9106A102, 0x8E068703, 0xAC05F503, 0xE7010003, 0x01004DA3,
    0x964D9E9A, 0xFF01004B, 0x01004D9F, 0xC64D809A, 0xDC01001C, 0x1FC94CFE, 0x00464B91, 0x4DA4A201, 0xD162573C, 0x3615CB13, 0x7A0E2BF9, 0x7A0E7A0E, 0x8A0E7C0E, 0x048A0E04, 0x1304840E, 0xB02803F2,
    0x01C61201, 0x1201C612, 0xC61201C6, 0x06BF1901, 0x1906BF19, 0xB51106BF, 0x019B1006, 0x1201CF29, 0x880701EE, 0x01C02801, 0x1601DA12, 0xD128019E, 0x01FC1201, 0x0E01B017, 0x9D0D028A, 0x01C01602,
    0x0E029A0E, 0x8A0802AA, 0x01C02801, 0x1001E412, 0xCF29019B, 0x01F91201, 0x28018E16, 0xE71201D0, 0x01A61201, 0x1201DF29, 0xB01701FC, 0x028A0E01, 0x16029D0D, 0x9A0E01C0, 0x02A40E02, 0x2A019721,
    0xF61201DE, 0x01A72201, 0x0C01F721, 0x991F028B, 0x01EE2A01, 0x11029512, 0xFF2A01B8, 0x02A20C01, 0x0D01CB1C, 0xBD0D02AB, 0x01EB1B02, 0x0E02BA0E, 0x972102C4, 0x01D03801, 0x2201F612, 0xDD3401BE,
    0x029B0C01, 0x2A01A91F, 0x861201EE, 0x01B82002, 0x0C028623, 0xCB1C02B2, 0x02AB0D01, 0x1B02BD0D, 0xBA0E01EB, 0x02CD0E02, 0x0D01AF16, 0xD31702C6, 0x01EE1801, 0x21029117, 0xCF1601EF, 0x02AB0D01,
    0x1602AE0D, 0xBB0D01DF, 0x02BD0E02, 0x0D01DF16, 0xA80D02BB, 0x01F31802, 0x0E02CA0E, 0xC21302CD, 0x02DF0D01, 0x1801DA17, 0xA1170287, 0x01F62102, 0x0D01E213, 0xFA1702EF, 0x01F31801, 0x0E02CA0E,
    0xDF1602CD, 0x02BB0D01, 0x1802A80D, 0xCA0E01F3, 0x02CD0E02, 0x3001EC1B, 0xB80D0286, 0x01F31802, 0x2103870E, 0xEA1B01FD, 0x02CB0D01, 0x1B02CE0D, 0xDB0D01FA, 0x02DD0E02, 0x0D01FA1B, 0xD80D02DB,
    0x02931802, 0x0E02EA0E, 0xF21302FD, 0x03910D01, 0x1801E817, 0x900E0283, 0x02842103, 0x0D028213, 0xC80D02DB, 0x02931802, 0x0E02EA0E, 0xFA1B02ED, 0x02DB0D01, 0x1802D80D, 0xEA0E0293, 0x02FD0E02,
    0x0D01AF16, 0xD91902BD, 0x01DD1101, 0x28029129, 0xC41601EF, 0x02960D01, 0x1602AE0D, 0xBB0D01DF, 0x02BD0E02, 0x0D01E416, 0xA70D02A6, 0x01EB1102, 0x0E02CA0E, 0xC21302CD, 0x02D60D01, 0x1101E019,
    0xA12901F6, 0x01F62802, 0x0601D713, 0xF01902D8, 0x01EB1101, 0x0E02CA0E, 0xE41602CD, 0x02A60D01, 0x1102A70D, 0xCA0E01EB, 0x02CD0E02, 0x1E01CF1B, 0xE71A02D8, 0x028F1101, 0x2802B129, 0xF91B01FD,
    0x02835101, 0x1B01F23E, 0x8137029C, 0x02DD0C02, 0x0D01FA1B, 0xD70D02DB, 0x028B1102, 0x0E02EA0E, 0xE21302ED, 0x03880D01, 0x1101EE19, 0xC12902A8, 0x02842802, 0x5A029113, 0xC70D01EF, 0x02B71102,
    0x0C028836, 0xFA1B02DD, 0x02DB0D01, 0x1102D70D, 0xEA0E028B, 0x02ED0E02, 0x0D01DF16, 0x831902F4, 0x02851802, 0x2202C030, 0x8213028F, 0x02DB0D02, 0x1D02DE0D, 0xEB0D0288, 0x02EE0D02, 0x0D029213,
    0xD70D02EB, 0x02AB1102, 0x0D02FA0E, 0xF21302EE, 0x02FD0D01, 0x18028A19, 0xD030029E, 0x02962202, 0x0D028A1B, 0xEE0D02EB, 0x02A21302, 0x0E02FB0D, 0x921302FD, 0x02EB0D02, 0x1102D70D, 0xFA0E02AB,
    0x02EE0D02, 0x0D01FA1B, 0x911903A6, 0x02B71802, 0x2202E030, 0xA21302AD, 0x02FB0D02, 0x1B02FE0D, 0x8B0D02AA, 0x038E0D03, 0x0D02B213, 0xF70D038B, 0x02CB1102, 0x0E039A0E, 0x9213039D, 0x03BF0D02,
    0x18029819, 0xF03002D0, 0x02B42202, 0x0D02AA1B, 0x8E0D038B, 0x02C21303, 0x0E039B0D, 0xB213039D, 0x038B0D02, 0x1102F70D, 0x9A0E02CB, 0x01000E03, 0xB24D81B0, 0x0009A212, 0x4CFDA901, 0x01001FA7,
    0xBE4DB980, 0x8C018D43, 0x95018C01, 0x373A3D01, 0x8639395E, 0x373A3D01, 0x8639395E, 0x373A3D01, 0x8539395E, 0x34343D01, 0xB8363657, 0xDD01D701, 0xDC01DC01, 0x6501E801, 0x01926565, 0x01B96268,
    0x92656565, 0xB9626801, 0x65656501, 0x62680192, 0x616101B0, 0x61018B61, 0xE301A85F, 0xB6028301, 0xF301CF01, 0xEB01C701, 0xDC028001, 0x9E028801, 0x95028202, 0xCC02B002, 0xEC01CE01, 0xE301D901,
    0xCB028301, 0x8301DA01, 0xEE01D702, 0xDA028F01, 0x9E028801, 0x95028202, 0xDE02B002, 0x8C01EC01, 0x8301ED02, 0xD602A102, 0x9E01ED01, 0x8901FF02, 0xF802B402, 0xBF02A801, 0xC802A102, 0xEC02CE02,
    0x8C01EC01, 0x8D01F102, 0xE602A302, 0x9E01FD01, 0x8A028002, 0x8802B202, 0xBF02A802, 0xC802A102, 0x8502CE02, 0xA4028C02, 0x9301F602, 0x8002B302, 0xBF02A502, 0xB5029202, 0xFA02D302, 0xCE02B501,
    0xD6029102, 0xFB02D702, 0xB4029F01, 0xA3028602, 0x8D02C302, 0xC802B602, 0xCB02A702, 0x8102DF02, 0xCE02B502, 0xD6029102, 0x8802D702, 0xD002B302, 0xC902A002, 0x9F02DD02, 0xDF02CF02, 0xDF02A802,
    0x9402EF02, 0xE702DF02, 0xF602BF02, 0xAE02F702, 0xD402CC02, 0xD902A602, 0xAC02DD02, 0xE502E002, 0xF202B102, 0x9B02FD02, 0xE702DF02, 0xF602BF02, 0x9402F702, 0xA4028C02, 0x9701F202, 0xEC02C202,
    0xB7028D01, 0xB5029102, 0xF602D902, 0xC602AD01, 0xB8029102, 0x8102E302, 0xB4029F02, 0xA3028602, 0xFB02D002, 0xC2029D01, 0xB8029602, 0xFD02E702, 0xC602AD01, 0xB8029102, 0x8A02E302, 0xC402B202,
    0xB8029102, 0x8B02DD02, 0xCB02D102, 0xDF029902, 0x9602DF02, 0xE702DD02, 0xE302C102, 0xA402F802, 0xD402BC02, 0xC602A602, 0x9A02ED02, 0xDB02E202, 0xDF02A902, 0x8D02EF02, 0xE702DD02, 0xE302C102,
    0xB002F802, 0xD402B802, 0xC702A602, 0x9F02E302, 0xEC02D902, 0xE902C502, 0xAA02FB02, 0xF802E902, 0xFD02C702, 0xA2038602, 0xD402CB02, 0xD702B602, 0xAD02F302, 0xFC02E902, 0xFA02D402, 0xAF038D02,
    0xF802E902, 0xFD02C702, 0xAB038602, 0xF402D902, 0xE702C602, 0xCE038302, 0x8D02F802, 0x8802E503, 0xC9039D03, 0x9A038802, 0x9B02E703, 0xCF03AA03, 0x8402EC02, 0xF702D603, 0xDC039302, 0x9D038802,
    0x9902F403, 0xCE03AF03, 0x9A038802, 0x9B02E703, 0x0003AA03, 0x4DB8F101, 0x23AD598F, 0x028801E3, 0x01CF01A9, 0x01DF01E4, 0x01D801E2, 0x02890287, 0x0285029A, 0x02AB0296, 0x01D101D2, 0x01D701EE,
    0x028801E3, 0x01D101C7, 0x01EF01F4, 0x01FF01E5, 0x028901ED, 0x0285029A, 0x02AB0296, 0x01F001E5, 0x01EB028C, 0x02A50284, 0x01EC01CC, 0x028B0293, 0x02A80288, 0x02AB0285, 0x02A402B9, 0x02C802CA,
    0x01EE01F3, 0x01EF028E, 0x02A8028D, 0x01FC01DC, 0x028C0293, 0x02A70288, 0x02AB0295, 0x02A402B9, 0x02C802CA, 0x028E0290, 0x01F602A4, 0x02AC0293, 0x02A501F5, 0x02A702AA, 0x02BE02B5, 0x02B5028F,
    0x029302CC, 0x02CA02DC, 0x029F0292, 0x028602B4, 0x02BC02A3, 0x02B60284, 0x02B802B7, 0x02CA02CB, 0x02B50296, 0x029302CC, 0x02CA02DC, 0x02BB029F, 0x029A02D0, 0x02D002CF, 0x02D50294, 0x02B702CA,
    0x02DE02E5, 0x02E5029F, 0x02C602DA, 0x02EA02FC, 0x02CC02C5, 0x02A602D4, 0x02D002DF, 0x02E602A3, 0x02BC02D4, 0x02EC02F8, 0x02E502A6, 0x02C602DA, 0x02EA02FC, 0x028E02B1, 0x01F202A4, 0x02B30297,
    0x028D01EE, 0x02A602A2, 0x02BE02B5, 0x02AD0290, 0x029102C6, 0x02E302B8, 0x029F028D, 0x028602B4, 0x02C302A3, 0x029D01FD, 0x02A802B0, 0x02CC02B8, 0x02AD0297, 0x029102C6, 0x02E302B8, 0x02A50296,
    0x029602CE, 0x02D302B3, 0x02C6028D, 0x02B602B9, 0x02CD02D4, 0x02D302B2, 0x02C102F1, 0x038202D9, 0x02BC02B0, 0x02A602D4, 0x02E302C3, 0x02D7029C, 0x02C602C9, 0x02DD02D4, 0x02D302A9, 0x02C102F1,
    0x038202D9, 0x02BA02C2, 0x02A602D4, 0x02E302C7, 0x02D90284, 0x02DA02D7, 0x02E602E9, 0x02E902BF, 0x02BB0384, 0x039202FD, 0x02CB02AF, 0x02B602D4, 0x02F302D7, 0x02E90294, 0x02E902E7, 0x02F802FA,
    0x02E902C4, 0x02BB0384, 0x039202FD, 0x02DB02B8, 0x02C602F4, 0x038302E7, 0x02F802B3, 0x02FA02F8, 0x03880388, 0x038802DE, 0x02DB03A6, 0x03B6039B, 0x02EC02DC, 0x02D60384, 0x039302F7, 0x038802C3,
    0x03890388, 0x039A0399, 0x038802E3, 0x02DB03A6, 0x03B6039B, 0xAC8A0100, 0xCA21A123, 0x010029EA, 0xA94DB8DA, 0x8C018C43, 0x8C018C01, 0x9C049C01, 0xF4049704, 0xDD01D604, 0xDC01DC01, 0x6501E801,
    0x01926565, 0x01B86368, 0x92656565, 0xB8636801, 0x65656501, 0x63680192, 0x616101AF, 0x61018B61, 0xE301A95F, 0xB0028301, 0xE101CF01, 0xBC018801, 0x8A01F402, 0x9C01CC01, 0xDC02AC02, 0x8102AC01,
    0xEC01CE03, 0xE301D901, 0x84028301, 0xF1029B01, 0xC1019601, 0x8E01FD02, 0x9C01CC01, 0xDC02AC02, 0x9302AC01, 0x8C01EC03, 0x8301ED02, 0xD002A102, 0x9201ED01, 0x89028B02, 0x9502A802, 0xBC01EC01,
    0x8C02CC02, 0xB302CC02, 0x8C01EC03, 0x8D01F102, 0xE002A302, 0x9201FD01, 0x8A028C02, 0xA502A602, 0xBC01EC01, 0x8C02CC02, 0xDC02CC02, 0xB401CC02, 0xDC029C02, 0xB602AA01, 0xBC01EC02, 0xFC02BC02,
    0xCC02CC01, 0xCC01FC02, 0x8402C402, 0xDC02DC02, 0xC401DC02, 0xEC02AC02, 0xC602BA01, 0xD401FC02, 0x8402CC02, 0xDC02DC02, 0xCC01FC02, 0x8402C402, 0xDC02DC02, 0xC5028302, 0x8402D402, 0xD602E202,
    0xDC028C02, 0x9C02DC02, 0xEC02EC02, 0xEC029C02, 0xA402F402, 0x8C02FC02, 0xE4028C03, 0x9402CC02, 0xE602E202, 0xEC029C02, 0xA402E402, 0xFC02FC02, 0xEC029C02, 0xA402F402, 0x8C02FC02, 0xAD01CC03,
    0xDC02A202, 0xB602AB01, 0xAC01DC02, 0xFC02BC02, 0xCC02CC01, 0xBC01FC02, 0xF502C302, 0xDC02DC01, 0xC401DC02, 0xF502AB02, 0xC602B201, 0xC401EC02, 0xF502BB02, 0xDC02DC01, 0xBC01FC02, 0xF502C302,
    0xDC02DC01, 0xD201EC02, 0x8E02BD02, 0xD602B902, 0xE7028C02, 0xB502B102, 0xEC02C302, 0xEC029C02, 0x9502F302, 0xFC02FC02, 0xE401FC02, 0xA702CB02, 0xE602C002, 0xDC029C02, 0xB702E302, 0xEC02CA02,
    0xEC029C02, 0x9502F302, 0xFC02FC02, 0xDE01FC02, 0x8B02D202, 0xD602DB02, 0xEC029C02, 0xAC02EC02, 0xFC02FC02, 0xFC02AC02, 0xB502F302, 0xFC038C02, 0xE5028C02, 0xA402DB02, 0xE602E202, 0xFC02AC02,
    0xBC02FC02, 0x8C038C02, 0xFC02AC03, 0xB502F302, 0xFC038C02, 0x8E029C02, 0xBD02E203, 0x8602E902, 0x8C02BC03, 0xCC038C03, 0x9C039C02, 0x9C02CC03, 0xD5039303, 0xAC03AC02, 0xA702AC03, 0xD602E903,
    0x9602F002, 0x9C02CC03, 0xDC039C03, 0xAC03AC02, 0x9C02CC03, 0xD5039303, 0x0003AC02, 0x4D9EE101, 0x02D61ABC, 0x03D62994, 0xA2870100, 0x0100414D, 0x474DA28D, 0xCF8E0100, 0x91010023, 0xB51C54AE,
    0xBD01002D, 0xC93354B1, 0x0009BE03, 0x54B4E801, 0x010009BE, 0x2154AF93, 0x1550790C, 0x01003C49, 0x9554B2C5, 0x0009BE04, 0x54B09D02, 0x00098700, 0x08020802, 0x020F0A8C, 0x00080208, 0x54AEE101,
    0x09111902, 0xF0010039, 0x01B354AE, 0x010002B1, 0xA054B2F0, 0xE203A925, 0x00710A49, 0x54B3A901, 0x9405C02B, 0xBE02000A, 0x940054B0, 0x07041001, 0x07020806, 0x020003DF, 0x5B100907, 0x0208020F,
    0x0708C008, 0x10090702, 0x08020F5B, 0x01000802, 0x8054B0EE, 0x03E91B06, 0xC51B05B2, 0xA6020004, 0x8B0054B1, 0x08020806, 0x09AF0F05, 0x05070210, 0xD7010007, 0x059B54B2, 0x010009BE, 0x2D54B0B3,
    0xFE03C30D, 0xE601F406, 0xD1010008, 0xEC1C54AD, 0x8F02002D, 0x080054B3, 0x15080208, 0x0608060F, 0x00018208, 0x040F0990, 0x00080408, 0x54CEEE01, 0x01CF02E1, 0x010004B3, 0x0054CE9A, 0x54D58301,
    0x01FB01DB, 0x0200363A, 0x0053F6C5, 0xB8001090, 0x1F022001, 0x1F022011, 0xB80002B1, 0x1F022001, 0x1F022011, 0x04184080, 0x02001017, 0x100F1218, 0x12100200, 0x02001C07, 0x13176A08, 0x02101308,
    0x0F01CD07, 0x08020804, 0x0F02101E, 0x00140F0A, 0x07041004, 0x08020004, 0x07020810, 0x020801A9, 0x02080217, 0x07070810, 0x09070B10, 0x58080C18, 0x0200021F, 0x02003A17, 0x3A100208, 0x0208020F,
    0x0E074408, 0x16271118, 0x08080200, 0x08080200, 0x0F06C900, 0x0011001F, 0x1500049D, 0x043F5300, 0x02283118, 0x00018D00, 0x003E003D, 0x1702185C, 0x18040002, 0x180A1702, 0x00130F06, 0x08040802,
    0x20020707, 0x071B0802, 0x1F100804, 0x08021709, 0x0804000D, 0x2004000C, 0x08040002, 0x17060002, 0x001F0002, 0x025F0291, 0x02283118, 0x00018B00, 0x003E003D, 0x17021850, 0x18040002, 0x180A1702,
    0x00130F06, 0x08040802, 0x20020707, 0x071B0802, 0x1F0C0804, 0x08021709, 0x0804000D, 0x2002000C, 0x08040002, 0x17060002, 0x001F0002, 0x10045737, 0x00022831, 0x3D00018E, 0x5A003E00, 0x020F0218,
    0x02100400, 0x06100A0F, 0x0C000E17, 0x02080410, 0x0E080218, 0x04200427, 0x041F0408, 0x05001117, 0x040F0418, 0x02000F08, 0x04000E20, 0x06000208, 0x1F000217, 0x02573200, 0x02283110, 0x00018C00,
    0x003E003D, 0x0F02184E, 0x10040002, 0x100A0F02, 0x000E1706, 0x0804100C, 0x08021802, 0x2004270E, 0x1F040804, 0x00111704, 0x0F071802, 0x000F0802, 0x000E2002, 0x00020804, 0x00021706, 0x4F34001F,
    0x28310804, 0x018E0002, 0x3E003D00, 0x02185A00, 0x04000207, 0x0A070208, 0x0E170608, 0x07080900, 0x020F0410, 0x0E080228, 0x11080407, 0x1117041F, 0x11080200, 0x04100200, 0x02200407, 0x02080400,
    0x02170600, 0x32001F00, 0x3108024F, 0x8C000228, 0x003D0001, 0x184E003E, 0x00020702, 0x07020804, 0x1706080A, 0x0809000E, 0x0F041007, 0x08022802, 0x0804070E, 0x17041F11, 0x08020011, 0x10020011,
    0x20020704, 0x08040002, 0x17060002, 0x001F0002, 0x0A0708AD, 0x13080207, 0x0B000D00, 0x3F0701C0, 0x47023F04, 0x0401C019, 0x763F023F, 0x0908534F, 0x48080578, 0x07080857, 0x19080278, 0x023F0428,
    0x263F043F, 0x023F0860, 0x023F0270, 0x02400267, 0x0240020F, 0x01C00277, 0x02018F02, 0x670201C0, 0x0F024002, 0x018B4002, 0x000201F7, 0x00023002, 0x00021708, 0x180C1702, 0x170E0006, 0x00061804,
    0x300B1706, 0x27150002, 0x30020002, 0x1F080002, 0x0F020002, 0x0006100C, 0x10040F0E, 0x0F060006, 0x0002300B, 0xBE0802B6, 0x00023F01, 0x40020012, 0x073704BE, 0x9B020007, 0x1E0054CA, 0x16181918,
    0x143F1418, 0x13181418, 0x073F0718, 0x07180718, 0x2705E918, 0x20021702, 0x200E1702, 0x2704170B, 0x3F0F4817, 0x3F16480B, 0x01004806, 0xE854CC9D, 0xE6010004, 0x09D254CD, 0xD5C70100, 0xA2018954,
    0x00383302, 0x54CC8901, 0x02B202AE, 0xF68F0200, 0x57B70053, 0x0C002200, 0x0005F200, 0x00030009, 0x0A0008AB, 0x14000200, 0xA6001400, 0x01FC0005, 0x50004300, 0xBA001F00, 0x00430006, 0x001F0050,
    0x430004D3, 0x1F005000, 0x0004DA00, 0x00500043, 0x04D2001F, 0x50004300, 0xDA001F00, 0x00430004, 0x001F0050, 0xBA00059A, 0x04020009, 0x1700018A, 0x58037002, 0x0002C201, 0x02000390, 0x0E006E00,
    0x71020700, 0x78000A01, 0x02000700, 0x0D001400, 0x07007800, 0x00000200, 0x54CF9801, 0x0200098E, 0x0054CAD2, 0x023804D0, 0x02200217, 0x0B080E17, 0x170F0417, 0x0A3F0F48, 0x16570C48, 0x97010048,
    0x04DC54CC, 0xD8BC0100, 0xBC010054, 0xC16454D3, 0x8F010003, 0x02BE54CC, 0x010002C2, 0xCC54D3D8, 0xD7010003, 0x02C254CE, 0x04DE01D1, 0xD5CD0100, 0x9D01A354, 0x00360C02, 0x54D8B301, 0xD4FD0100,
    0x8701C454, 0x384C0702, 0xF5CF0100, 0x07987E53, 0x04B00D8B, 0x02FA4C9F, 0x0660033B, 0x36E30D2C, 0x0D06BE1F, 0x00120183, 0x53F5AA01, 0x06F71C50, 0x01C502E6, 0x01CC01DE, 0x03CC01B7, 0x2603E726,
    0x9E4C995E, 0x3D6F6A02, 0x0E2AA309, 0x05F606EA, 0x1B03C52E, 0x02B70927, 0x03A3355A, 0x01000914, 0xEC54E6CD, 0x8C069B07, 0x8C069C06, 0xE2020006, 0xAC1053F6, 0x0CF60407, 0x0F53D003, 0x860001DB,
    0x06CF0037, 0x00019900, 0xAFF10100, 0xFF02004C, 0xFA403FC1, 0x131F01DF, 0x0004D500, 0x04E50013, 0x02001310, 0x9E000D0F, 0x00131008, 0x000E0F02, 0x041813EF, 0x00048100, 0x0400048D, 0x0003FF00,
    0x040003FF, 0x00048100, 0x3707C299, 0x7002ADA8, 0x01AE000C, 0x86000C17, 0x17022006, 0x01A20005, 0xE3000908, 0x000E0001, 0x0009003E, 0x000E0031, 0x000E0033, 0x000E0033, 0x0E000383, 0x0E003500,
    0x0E003B00, 0x00069F00, 0x007E0009, 0x00160010, 0x00340011, 0x003E000E, 0x00230012, 0x00160012, 0x001A0012, 0x00140012, 0x00190012, 0x00110012, 0x00150012, 0x01840012, 0x28000E00, 0x65000E00,
    0x4D000900, 0x20000E00, 0xA2000E00, 0x000D2701, 0x000D087B, 0x0F7D086B, 0x00640004, 0xE1EF0004, 0x00070001, 0x060007B6, 0x081C9100, 0x082D000B, 0x1F06D2BC, 0x01D00008, 0xBE000E0F, 0x00490801,
    0x031018D8, 0x0007DF00, 0x069A0003, 0x83000300, 0x00030006, 0x03000697, 0x00068300, 0x0B870003, 0x2A001217, 0xD4000830, 0x8EF84F24, 0x00060002, 0x08050809, 0x08050005, 0x0100000B, 0x9749929C,
    0x02FC9607, 0xC2010007, 0xD20841E1, 0x02810901, 0x07B08A08, 0x028201EF, 0x91F30100, 0xC407A249, 0xE8060391, 0x01000861, 0xFB4991E8, 0x03C7A907, 0x1C28A912, 0x92A20100, 0xC402A549, 0x03818304,
    0x0188F808, 0xBA010008, 0x07AF4992, 0x0803C78C, 0x000C28C0, 0x41F1EF01, 0x06088606, 0x10079B98, 0xE901E736, 0xC2010001, 0x01BC4992, 0xFE980599, 0x898F0702, 0x01000701, 0x2F4992B1, 0xFD9806C9,
    0x89B50702, 0x01000701, 0x9D4BA3BB, 0xB90BC702, 0x29019D01, 0x000A82D2, 0x4991FC01, 0x05F401B3, 0x0602B4B2, 0xC40726DB, 0x15D201DD, 0x9F010006, 0x9B22BD58, 0x8B0FD204, 0x01CF440C, 0x6403EF52,
    0x2617FC23, 0x5A5A22CE, 0x5A6A5A5A, 0x5A6A01B9, 0xAF02B2FC, 0x0186049B, 0x9E5B6263, 0x690A0E0B, 0x02973D37, 0x254F1C24, 0x17DF6E1F, 0x15151517, 0x483602A0, 0x462B1C0C, 0x990EAE60, 0x03946602,
    0x1F303439, 0x434B711F, 0x2C29236C, 0x01B62C13, 0x0BC82629, 0x13972629, 0x9D1B383E, 0xC807EF03, 0xC616FC03, 0xF905DB05, 0x26807306, 0x181C0498, 0x31181818, 0x211C241C, 0x1C0D1F1C, 0x18181818,
    0x8B181818, 0x12161505, 0x0A1601C2, 0x0B0B5C16, 0x018606B4, 0x3F461F25, 0xF803C251, 0x0BB91903, 0x2801E445, 0x058812C9, 0xE4A00DB1, 0x16AC8D01, 0xE61E2F16, 0x06FE1A01, 0x80279332, 0xAB11EB5D,
    0x27692411, 0xEE272D24, 0x1EA2029A, 0x6608CC5A, 0x0DC05A83, 0x946B01C4, 0xBD0FAC0F, 0xD502B520, 0x9469E802, 0x2B0EE133, 0x04971415, 0x09893027, 0x269E36D2, 0x7C4837B4, 0x0B028112, 0x0C8003F8,
    0x282603C3, 0x790AE723, 0x282603B2, 0x1A07D423, 0x211F57F5, 0x22212222, 0x1F039522, 0x22222122, 0x03992221, 0xEF7B4891, 0x06AB261C, 0x1A02F760, 0x2055180C, 0x14C70CFD, 0x8502E647, 0x09976901,
    0x01B11763, 0xD702D511, 0x1801A31E, 0x4C1903CD, 0x06B43116, 0xAE5A4D45, 0x4501C201, 0x1D641F47, 0x370BDF18, 0x6A13112A, 0x14131113, 0x01930DA7, 0x981201A0, 0x862C1502, 0x1601A304, 0x211802AF,
    0x30133ACB, 0x76103C75, 0xBD4B0CA2, 0x1F181F01, 0x0D0F2941, 0x0FD10F0C, 0x5303B038, 0x2303B448, 0x1F706C25, 0x0D0D3110, 0x164E1822, 0x3B360FCC, 0x07A422DB, 0x4526342D, 0x28113159, 0x069E01DA,
    0x018F01DF, 0xFF06E37D, 0x5416AF05, 0xCC019E52, 0x20562401, 0x84272920, 0xD8029301, 0xCF324301, 0x2631270B, 0x59412D6F, 0xA51F0E2B, 0x3B05A302, 0x8B01896E, 0x068C7401, 0x58440186, 0x11100E22,
    0x018506D3, 0xBA98452D, 0xFA861F08, 0x0586C501, 0x018E08DF, 0x018E01FB, 0x0C7603FA, 0x03BB09CD, 0x04BA0193, 0x02E56E1D, 0x1C01B212, 0xC4018D2C, 0x2C06C902, 0x300A56BE, 0x1C019610, 0x11E436CD,
    0xA68D303C, 0x03809004, 0x18B407C1, 0x12082D1C, 0x250C0743, 0x07080A0B, 0x082B0708, 0x1C2439D6, 0x1D019B1B, 0xA87902AF, 0x8F1DA619, 0x0F10812B, 0x15840490, 0x44068F27, 0x2C19BC1C, 0x8D24018C,
    0x2D773D02, 0x7D973326, 0x36EB42AC, 0xDA07CEBC, 0x9C71B039, 0x0C4C2633, 0xDA68660C, 0xAA0CD848, 0xAF010074, 0xE00643C3, 0xBF9C0613, 0x83018905, 0xB0010002, 0xA30641E8, 0xA1A6060B, 0xE802D007,
    0x82010001, 0xB3A64BF7, 0xF4010009, 0xC19E45D5, 0x01FB2403, 0x91EE0100, 0xC601E949, 0x02D5A705, 0x90010006, 0x800841C3, 0x01CA07D2, 0x0001F657, 0x43A2CF01, 0x05F3C008, 0x028301B7, 0x928A0100,
    0x05FE7D49, 0x0803D0FA, 0x00082D83, 0x4CEFC001, 0x000B4802, 0x4CD7FF01, 0xC7C60100, 0x01C7FD4B, 0x00089E81, 0x0185B901, 0xC5E201C0, 0x02000B54, 0x0855C9C6, 0x00050721, 0x090001BD, 0xFD020008,
    0x330055AF, 0x1010EF00, 0x18050F06, 0x00191706, 0x02000006, 0xBF002EBB, 0x07880025, 0x002B9000, 0x07010807, 0x0701081E, 0x0054C5BF, 0x004D001C, 0x230001F5, 0x94001C00, 0x01000003, 0xB50185BF,
    0x54C5ED01, 0x8702000E, 0x061055D6, 0x0618050F, 0x06001917, 0xC2006200, 0x01000003, 0x020051C4, 0x80A04FC2, 0x03000602, 0x0702809F, 0x080280A0, 0x0920081F, 0x2D1F0300, 0x809F0320, 0x80A01702,
    0x809F0F02, 0x80800E02, 0xF4201002, 0x80A71CC7, 0x02B48102, 0x03DE9100, 0x14CBE200, 0x10BFE700, 0x060280A8, 0x809F0300, 0x80A00702, 0xC01F0802, 0x0006200A, 0x02809F03, 0x0280A007, 0x20081F08,
    0x1F030009, 0x9F03202B, 0xA0170280, 0x9F0F0280, 0x800E0280, 0x20100280, 0x9F0D9EB6, 0x001C0280, 0x80A029ED, 0x07000902, 0x0902809F, 0x860280A0, 0x02809F0A, 0x7BBB0100, 0x14051E03, 0xEF081408,
    0x8E0223A0, 0xEA0901C4, 0x04C71BB6, 0x8A04AFE3, 0x04E9AA01, 0x02AFBD02, 0x0F2BB009, 0x1508D1CB, 0xD0BE0100, 0xCBD30C09, 0x35C9051A, 0x1467F611, 0xD6092795, 0x89050CD8, 0x02861003, 0x0ED8AA05,
    0x080989A6, 0x0902C5AE, 0xB5092BB7, 0x019008D3, 0x0401D404, 0x9B0404B1, 0x04660403, 0x79E10100, 0x2638F635, 0x8BC12621, 0xFC06EF07, 0xFD57A72D, 0x03A0E703, 0xC16702EB, 0x94C65501, 0x02A5E504,
    0x7A9901E0, 0x01BA0FA7, 0xA707FBCF, 0x019EE11D, 0x23A719AE, 0xD804CCA4, 0x04E1019C, 0xCA28F861, 0xC4048807, 0xBC049C2A, 0xDF05A207, 0x08D0391C, 0x22D606CF, 0xEF4C11A2, 0xE40AD42C, 0x2C8C0ADE,
    0x37D04D8C, 0x94039710, 0xE1019902, 0x2C826006, 0xD90D99BE, 0x8554CA35, 0xFB45B601, 0x13B901C4, 0xBD4410DA, 0xCB02A609, 0x9E059603, 0xB829A81F, 0x03B5078B, 0x7BC937F3, 0xE3AE2AB2, 0xB761D406,
    0x812FFA02, 0xAC069401, 0x02000661, 0x104BD09B, 0x080A0F0C, 0xB80803D6, 0x08080F02, 0x00382A72, 0x002D0D18, 0x003A0407, 0x003A3607, 0x003A3B07, 0x02C00303, 0x3F030700, 0x3C020700, 0x424A0700,
    0xC0450C00, 0x0C230003, 0x015A0203, 0x020A0039, 0x2A070039, 0x1008003E, 0x3D290016, 0x3A070065, 0x4B2F000B, 0x070003B2, 0x0F1A0C0E, 0x0E080F08, 0x11018817, 0x085A1A16, 0xC8B10F5C, 0x41BF3709,
    0x91020000, 0x066401F3, 0x0900083D, 0x0C250300, 0x0300092E, 0x0440022D, 0xB73F0200, 0x00142608, 0xC1B52502, 0x00196E06, 0x3A636D02, 0x39030006, 0x00063801, 0x2E013703, 0x2D030006, 0x056E01FA,
    0xCA6D0200, 0x06380189, 0x01370300, 0x0300063A, 0x0C2E0139, 0xD92D0300, 0x000B1001, 0x10590F06, 0x0F020005, 0x092E0181, 0xAF2D0200, 0x0C3203A5, 0x30310300, 0x02000532, 0x0ED28131, 0x02C7AF64,
    0x03000939, 0x042A0F29, 0xE8290200, 0xD46401CF, 0xF300039A, 0x00055309, 0x10160F02, 0x0F060006, 0x0F702BA0, 0x2670026F, 0x130A0F4B, 0x102D0200, 0x02000540, 0x0C48153F, 0x08470600, 0x02000950,
    0x062E354F, 0xAE2D0300, 0x01836403, 0x0562FF06, 0x0C3906F7, 0x23290300, 0x0300063A, 0x06380239, 0x02370300, 0x03000C2E, 0x052E202D, 0x072D0200, 0x02000B3A, 0x03380239, 0xB4370200, 0x08232A01,
    0x31030005, 0x29032A0A, 0x00102A5D, 0x32052902, 0x31030006, 0x053801FF, 0x01370300, 0x0300063A, 0x376C1D39, 0x11411800, 0x92290200, 0x08096468, 0x1BFB0036, 0x0073AB07, 0x00032B15, 0x3A0B3702,
    0x39020005, 0x0B38049F, 0x05370300, 0x03010C3A, 0x063A0537, 0x05390300, 0x06330564, 0x6F2F0300, 0x05330664, 0x182F0300, 0x02000A38, 0x053A0E37, 0xEB390200, 0x000A3801, 0x3A0E3702, 0x39020005,
    0x33056401, 0x2F030006, 0x330C6466, 0x2F030005, 0x64048CCF, 0xFA000296, 0x00093D01, 0xAFF62502, 0x9C8C6401, 0x2B050005, 0x37020004, 0x2B056412, 0x37030006, 0x1001B3BF, 0x0F02000C, 0x2E02E9D4,
    0x2D030006, 0x320AA1B1, 0x3103001A, 0x00063808, 0x3A013703, 0x39030006, 0x00061001, 0x32350F06, 0x31020004, 0x0E3834D9, 0x05370200, 0x0200073A, 0x1F320239, 0x03000800, 0x05325231, 0x86310200,
    0x0005100D, 0x35950F02, 0x03000D32, 0x06101C31, 0x1A0F0600, 0x02000932, 0x3A0BFF31, 0x3903000C, 0x00053806, 0x64053703, 0x00120806, 0x1F8F0753, 0x00019106, 0x5C00018F, 0x370EF700, 0x0C080304,
    0x1406150E, 0x3702000D, 0x39023A0D, 0x31033207, 0x000B2002, 0x100A1F02, 0x0F020005, 0x31033224, 0x00072022, 0x3A061F02, 0x2E023902, 0x0D080004, 0x08080004, 0x27020004, 0x00051844, 0x181C1702,
    0x17020004, 0x00062828, 0x20022703, 0x1F020004, 0x00052E05, 0x32052D02, 0x31020005, 0x00053A05, 0x5AE33902, 0x3B198B6A, 0x00051D19, 0x2E1D0F02, 0x09D12D03, 0x0200052E, 0x2E01C42D, 0x00051D19,
    0x2E1D0F02, 0x09B42D03, 0x0200052E, 0x2E01C22D, 0x00051D16, 0x2E180F02, 0x2D030006, 0x052E05E8, 0xCA2D0200, 0x1D192E01, 0x0F020005, 0x2D032E1D, 0x052E05D0, 0xE42D0200, 0x4026247F, 0x813F0198,
    0x003C0013, 0x3F000CFC, 0x001CA100, 0x064004D5, 0x80543453, 0x04D40003, 0xE7534100, 0x000F1A19, 0x10092902, 0x0F060006, 0x00062A23, 0x43C92902, 0x0481C664, 0x0200163D, 0x60039825, 0x5F02000D,
    0x00162610, 0x53C32502, 0x02000410, 0x0408060F, 0xEE070200, 0x09240189, 0x16230200, 0x03000F2E, 0x0948082D, 0x0C470200, 0x02000950, 0x09580C4F, 0x44570200, 0x02000640, 0x2401883F, 0x2D030A28,
    0x093202AB, 0x01310200, 0x03000638, 0x063A0137, 0xE3390300, 0x000F1079, 0x08020F02, 0x07020003, 0x00033202, 0x20023102, 0x1F020003, 0x00043802, 0x3A023702, 0x39020004, 0x06241CED, 0x02000413,
    0x1700060F, 0x0B1A0C18, 0x0102090B, 0x0701C317, 0x080A080A, 0x0806070A, 0x800801CD, 0x51534A01, 0x019A0705, 0x02000924, 0x0A360533, 0x50350200, 0x08001508, 0x0F082B08, 0x06390C22, 0x0601013A,
    0x3C370300, 0x0301073A, 0x3904430B, 0x39360800, 0x393B0800, 0x9B404000, 0x47700001, 0x0208003E, 0x4A08003B, 0x03DD0041, 0x82010937, 0x003D2C02, 0x000F1008, 0x3E0301A4, 0xD900554B, 0x0E080002,
    0x080F1A0B, 0x170E080F, 0x003A1142, 0x085A1A19, 0x3F320F5A, 0x0075003B, 0xCF00018C, 0x000E3009, 0x60092F02, 0x5F020005, 0x00052202, 0x13E42102, 0x3D20EC6A, 0x2B03000C, 0x2B022C1C, 0x00082C1B,
    0x30B22B02, 0x0C1E9A24, 0x2F030010, 0x09F96A15, 0x1332C845, 0x022A01E8, 0x0001C501, 0x151A020E, 0x0159163F, 0x325E0203, 0x612B01AD, 0x1A061F05, 0x86190600, 0x07CF0A01, 0x0B02D50A, 0xE4030499,
    0x088E0004, 0x3A06BE00, 0x6302000F, 0x000A644D, 0x0A886301, 0x06838240, 0x0300051D, 0x0B242B21, 0x02000713, 0x0308020F, 0x07070200, 0x03000532, 0x09200231, 0x0A121000, 0x04211900, 0x020F0200,
    0x1C000932, 0x0A000D0D, 0x02000313, 0x0D24170F, 0x031B0A00, 0x09070200, 0x02000320, 0x0A32051F, 0x07310200, 0x050C102C, 0x13370200, 0x02000A38, 0x033A0A37, 0x06010300, 0x01370300, 0x0300063A,
    0x6801F639, 0x0305431A, 0x1F030006, 0x00053202, 0x09F43103, 0x02000410, 0x8E686A0F, 0x02AF0004, 0x03000647, 0x2C48851F, 0x02860757, 0xBD541900, 0x05B0533B, 0x101DC623, 0x0F05000B, 0x00060802,
    0x11EE0705, 0x3F2D8C64, 0x2301000D, 0x00082C02, 0x66022B01, 0x65010004, 0x00046802, 0x2A046701, 0x29010004, 0x0003280A, 0x6E022701, 0x6D010004, 0x0F2404FD, 0x56240623, 0x02000900, 0xBA010023,
    0xF90D0AB3, 0x90B93101, 0x1203B035, 0x01BBF80E, 0x02F59E2C, 0xF0F20CE1, 0x98020011, 0x808008B4, 0x6A007F02, 0x5B005B00, 0x1AFFE100, 0x6D01FFFF, 0xC8007B00, 0x02808051, 0x00422010, 0x02809F03,
    0x0280A002, 0x20071F0A, 0x01809F03, 0x0180A005, 0xFEDF0002, 0x02809F1C, 0xD4940708, 0x02B80003, 0x88019F00, 0x20100280, 0x9F030042, 0xA0020280, 0x1F0A0280, 0x9F032007, 0xA0050180, 0x00020180,
    0x101F5588, 0x03004220, 0x0202809F, 0x0A0280A0, 0x0320071F, 0x0501809F, 0x020180A0, 0x02FC9200, 0x03000600, 0x0702809F, 0x060280A0, 0x0A01809F, 0x050180A0, 0x000AC01F, 0xB6ED2017, 0x01809F0B,
    0x0EDB0710, 0xBD070A08, 0x808801A4, 0x00018901, 0x077FFF09, 0x7FFF7907, 0x808816EC, 0x7FFF1C02, 0x3DAF0707, 0x001C7FF7, 0x80A008BB, 0x07000902, 0x0902809F, 0xDE0280A0, 0x02809F09, 0xBEB30200,
    0x18CF0055, 0x102DFD00, 0x18050F06, 0x00191706, 0x00320006, 0x000001AF, 0x55AF8102, 0x8A004400, 0x06100197, 0x0618050F, 0x06001917, 0x0005F400, 0xC9FB0100, 0x01C7B14B, 0x0009CEED, 0x44E7E202,
    0x03CE8207, 0x090280A8, 0x809F0300, 0x80A00702, 0x809F0602, 0x80A00A01, 0xF91F0501, 0x2010000A, 0x9F0BB7C9, 0x07100180, 0x7FFF239B, 0x9E0002BF, 0x80880192, 0x7FFF3302, 0xFF410707, 0xA858F57F,
    0x00090280, 0x02809F07, 0x0280A009, 0x809F09B9, 0x005DFD02, 0x46BE001C, 0x0B028080, 0x07077FFF, 0xC0810100, 0x0A99D94B, 0x0001A3A2, 0x4C898202, 0x00018800, 0x10904DFD, 0x8C108F07, 0x258A0001,
    0xE4005D00, 0x00000A81, 0x57A7A101, 0x3EBF931C, 0x94910100, 0xD2971C57, 0x8101003E, 0xB71C57AB, 0x01003EBB, 0x1C5790B1, 0x003ED5F3, 0x579B9101, 0x3ECB871C, 0x9EB10100, 0xC7FB1C57, 0xF101003E,
    0xBF1C57A2, 0x01003EC3, 0x1C5797F1, 0x003ECEA3, 0x578CD101, 0x3ED9CF1C, 0x88F10100, 0xDDAB1C57, 0x8F02003E, 0x166053FA, 0x0160D302, 0x60015F0A, 0x61030202, 0x37B26201, 0x3F018611, 0x08020802,
    0x27023002, 0x00132802, 0x0917019C, 0x07100807, 0xB0101D08, 0xA3E04F01, 0x4F0F4802, 0x08065002, 0x58025705, 0xB4970200, 0x01B40055, 0x0286E400, 0x050F0610, 0x19170618, 0xCB000600, 0x01000002,
    0x7340DBF8, 0x586E5751, 0xA851685C, 0xB2710594, 0x58586F01, 0x6101836F, 0x0100667A, 0xEA175BC7, 0xA46432A3, 0xE28A6407, 0x3E0F1724, 0x80374710, 0x224A1E10, 0x5BD30200, 0x32A48907, 0x00088C08,
    0x0024E38A, 0x390001BC, 0x000FF600, 0x00420026, 0xBA940100, 0x9D048A48, 0x0E90E801, 0xA7D803AC, 0x004C1C01, 0x48C0E801, 0x000FBEAE, 0xBC4DD201, 0x57978A01, 0xD71C24FD, 0x01003DDC, 0xD8083BDE,
    0x010057C4, 0x8003D6D6, 0x44BDD726, 0xA80FC8E9, 0x0015D503, 0x57E79C02, 0x0D3E1400, 0x004E863D, 0x0100001E, 0x3458B5C3, 0x30E90100, 0x0058A19D, 0x0D22BE01, 0x898626D0, 0xD7010058, 0x020048E7,
    0x3058C7CA, 0x0114900A, 0x01C40FFF, 0xA7621080, 0x05080414, 0x08080490, 0x96048F07, 0x17060801, 0x90080805, 0x05080704, 0x09CD048F, 0x00059927, 0x1C000FBF, 0x93010000, 0x209102A2, 0x99B277EC,
    0x15A0930A, 0x370480A0, 0x8401FA95, 0xD01001C3, 0xCF250283, 0x01CA9B08, 0x4E01ACE0, 0x08D6D36B, 0xCD0E37C9, 0x90018A01, 0x10993206, 0x01A40184, 0x9305EACD, 0x28665C01, 0xA7245B5D, 0x29292E07,
    0xF28F2F2A, 0xE511C909, 0x690E0CD9, 0x2703A3A7, 0xD20C1411, 0x05837517, 0x86C40200, 0x0F2E1059, 0x0192002C, 0x07080B00, 0x260F0908, 0x89002608, 0x02071001, 0x0100020B, 0x04598CB3, 0x01B51618,
    0x5C5A01A9, 0x00018A4C, 0x598E8101, 0x7B107910, 0x4211665C, 0x0A07143C, 0xF701000A, 0x0DE648C6, 0xC80FF2D0, 0x9904A202, 0x84018D3F, 0x36018001, 0x01000186, 0xB948D5F3, 0x0FE58810, 0x01B608B5,
    0x028A02FB, 0x2B5E338E, 0x8236019E, 0xED010001, 0x9ED80183, 0x058E0848, 0x000FECC6, 0x007B8002, 0x0024F99B, 0x001185D7, 0x000782DF, 0x07171012, 0x070189AE, 0x0805080E, 0x08040F0A, 0x0F0A0804,
    0x08040805, 0x0F0F03A3, 0xA8071210, 0x08020703, 0xA9FB0802, 0x001B0F0A, 0x68F0001B, 0x0FC3CD00, 0x06080600, 0xF0020008, 0x960001CD, 0xE0000BA2, 0x02001181, 0x6B080208, 0x09070407, 0x0008B810,
    0x07130702, 0x0410018C, 0xCD070407, 0x07091001, 0x018F0710, 0x04070410, 0x01E3AD07, 0x20D6A500, 0x02070210, 0x1B000607, 0xF3070410, 0x560708FD, 0x10AB9A00, 0x06080600, 0x01BBDB08, 0x0000470F,
    0x08D7FF01, 0x41131313, 0x93A74158, 0x02A4100C, 0x10101010, 0x0786DF10, 0xD103C713, 0xBE9E1304, 0x1295C202, 0x1001D6DA, 0xB0F91010, 0x13742602, 0xAB811313, 0x10101003, 0xC6881010, 0xD247DC05,
    0x81E6018B, 0x10101001, 0xCB19C0B1, 0x101001C8, 0x92020010, 0x020001CC, 0x02080200, 0x09070F08, 0x07F68508, 0x01879B0F, 0x0004F300, 0x0001BACD, 0x730001EE, 0x000DB500, 0xD70056C1, 0x070009D8,
    0xC1080508, 0x08070F01, 0x86960805, 0x1DCE0F04, 0x003FAA00, 0x00038BEC, 0xFD0055C4, 0x0EA1002B, 0x001A9D00, 0x2CC3000C, 0x02070210, 0x23000207, 0xF7070410, 0x07060809, 0xEEF90702, 0x08050004,
    0x23BB080B, 0x000E9A0F, 0x080BEBED, 0x0F070802, 0x10040007, 0x21A6070F, 0x07080200, 0x0400070F, 0x9B070F10, 0x04070CA3, 0x09080908, 0x0808040F, 0x0F03E108, 0x08090804, 0x08040F09, 0x07E90808,
    0x0208020F, 0x120F0208, 0x3F080D08, 0x0053EA0F, 0xE9BB0028, 0x07040801, 0x001E1007, 0x07020702, 0x101B0006, 0xFEF70704, 0x00490708, 0x0801C28F, 0x1010070C, 0x08040F09, 0x0BF70812, 0x2308070F,
    0x040F0408, 0xA4080808, 0x00500F05, 0x000ED691, 0x08060806, 0x0F01B8DF, 0x08020006, 0x07090802, 0x02AB0806, 0x0000610F, 0x08BCD502, 0x0037CC00, 0xF40006B4, 0x030004CC, 0x8B080508, 0xB40F11E3,
    0xD5A80038, 0x003C0029, 0x0010ABD6, 0x08060806, 0x0F01BAE6, 0x01000071, 0xA809CBF5, 0x02B8CE04, 0xB26901FD, 0xA44401C1, 0x33333301, 0x85018A61, 0x17E716FE, 0x04EE7896, 0xD4399C6F, 0x0AA4AC0A,
    0x8C04D98D, 0x35D90AE6, 0xBF03EEBE, 0x010015B6, 0xC749BCA1, 0x01A111F3, 0xE201000C, 0x01005BC7, 0x005C98DD, 0x5C989E01, 0x98EE0100, 0xAF01005C, 0x01005C98, 0x005C988D, 0x5CACB201, 0x97B70100,
    0xE002BC59, 0xD508E602, 0x1EAA6D08, 0x01BC03E6, 0x4D488059, 0x03FE07FD, 0x04F003FB, 0x0381038B, 0x04AB03C3, 0x04BC04AA, 0x0CCF03B7, 0x05B401FC, 0x04CE01D9, 0x7E01A17E, 0xCC7E0199, 0x945F6E01,
    0x9E6A5D01, 0x886B6B01, 0xED6C5F01, 0x02A53A02, 0x21F912DC, 0x03F701C4, 0xB77C6CBA, 0xD805F326, 0xA501D903, 0x020FD403, 0x02160216, 0xE001001B, 0x1C1C5CE9, 0xE801000D, 0x5C95B461, 0x83E80100,
    0x0FFC884D, 0x000C03C6, 0x3894E101, 0xEB20E7AF, 0x0C3A0487, 0xDCB10100, 0xEE02F03F, 0x43920CF7, 0x2B0FDFE8, 0x0C100D7B, 0x2002A73A, 0x496801BF, 0x0D02AA2F, 0x02870C10, 0xD7A70100, 0xDE03B24C,
    0x02D51425, 0x890F1EA0, 0x0FDBF701, 0x02D02A28, 0xDE0C7350, 0xA5010002, 0xCBC70F3B, 0x1AE90A01, 0x05A902AC, 0xD20A13CF, 0x9E073F04, 0xD7085777, 0x092425B3, 0xA8DA019F, 0x019CB602, 0x01BF0924,
    0x07D706FD, 0x2D090AE7, 0xF907C717, 0xCDAF0BBA, 0xDCE45107, 0x07B7FF15, 0x900801B3, 0x01B47C02, 0x029605C9, 0x1D910D23, 0x01A511DA, 0xB3010009, 0x2C974CD7, 0xDE971DE8, 0x59350B0F, 0x01DA1D56,
    0xCA01000C, 0xA9CA4CD7, 0x1A01A310, 0x000F1616, 0x4CD7BF01, 0x1F920DAD, 0x5805AF56, 0x08B701B5, 0xF41608E6, 0x01895601, 0xEA4D3923, 0x77120FDD, 0xDD0C01AB, 0xFA01DD09, 0xCA020001, 0x8ADB0021,
    0x0FA12023, 0xC5280A08, 0x86932F6C, 0x11068802, 0x1037048F, 0x0E01D728, 0x01E501D0, 0x2F5D01CF, 0x028A0823, 0x60000230, 0x0EEE05D0, 0xF73D048F, 0xB5082901, 0x048B2702, 0x005506A8, 0xEB810054,
    0x9F050703, 0x16CCAF06, 0x281AC028, 0x2703AE99, 0xE797003F, 0x01B80007, 0x10C38D28, 0x3F0E01C8, 0x054001A7, 0x4002CC3F, 0x040815EA, 0x02A30304, 0x02980183, 0xE10002A7, 0x0C8B0006, 0x843F4100,
    0xBD018702, 0x0A01A803, 0x080701EF, 0x18020F0A, 0x08050806, 0x10010801, 0x2001D802, 0x4F0D01BF, 0xA006A047, 0x9206A701, 0x0100000D, 0x2626B4C2, 0xE02216DC, 0x873436CA, 0x2502A404, 0x09A102F1,
    0x69018D3C, 0x203404E4, 0x06910E81, 0xDA010003, 0x01E326AE, 0x04C616D2, 0xDC36DDB0, 0xF8010008, 0x1B295DD0, 0x8401004A, 0xBCB2499A, 0x01000A14, 0xAB499D8B, 0xAF2114B8, 0x9A010007, 0xBCC2499A,
    0xB1020014, 0x25B0002E, 0x0007AB00, 0x06002ACA, 0x64070208, 0xDA070108, 0x2B003FE0, 0xC1001900, 0x00410001, 0x00490033, 0x003F0046, 0x003A003C, 0x002C002D, 0x0004A8AB, 0x001C0023, 0x000188C4,
    0x00430020, 0x00320035, 0x00350032, 0x00600032, 0x0034003B, 0x0052003A, 0x000C0011, 0x2C000181, 0x17B8A400, 0x8B010000, 0xC006C354, 0x8FFB44BB, 0x0FA8B701, 0x2EAA0100, 0x150C24E4, 0xF307B30B,
    0x9DD043F9, 0x06CCE101, 0x430987DE, 0xF5D70100, 0x040C125D, 0x2E0D151C, 0x8C02001B, 0x35005DF6, 0x00084700, 0x5DF8F501, 0xF8FA0100, 0x0607A65D, 0xB2810100, 0x21FDCC39, 0x3102C58B, 0x26D208A2,
    0xD7D10100, 0x4F8D1B13, 0xAE1B4D1B, 0xDD2F10AE, 0xBD1601A6, 0x1B4D1B0E, 0x1B0C859D, 0x99AD1B4D, 0x9CFD1B0E, 0x1B4D1B04, 0xAD1B5BBD, 0xFBFD1B01, 0x9BFD1B01, 0x14BD1B0E, 0x050C8E1B, 0xC20520F3,
    0x09881B01, 0x7F1A7E1C, 0x1B35CD0D, 0xE2052CCE, 0xCFBF1B48, 0x00011A06, 0xD2359F01, 0x01A85DDB, 0xAD01005F, 0x16205E96, 0x021F3E09, 0xB0020019, 0xB0070036, 0x8009EB06, 0x9708DF01, 0x48018F01,
    0xCF2F0792, 0x30380CB3, 0x3038301F, 0x303F3030, 0x3BB1FC30, 0xE198079F, 0x88030015, 0x08872108, 0x94B10100, 0x0F94CC25, 0xAC0C80CC, 0xC7A60988, 0xD206A414, 0x000C5424, 0x01C38A01, 0x1C01E4B8,
    0x300194E0, 0x0192802E, 0x2C2C2C2F, 0xE92C2A2E, 0x2C2C2F41, 0x2C2A2E2C, 0x2A02B3B1, 0x2F2F2F34, 0x3131312F, 0x2F2F342C, 0x37282A51, 0x31312E2E, 0x342E3131, 0x31313131, 0xBE313131, 0x31372C12,
    0x31313131, 0x2F2C3131, 0x2F01CADC, 0x3632322F, 0x431B199F, 0x05E802AF, 0x01CD02B3, 0xBC5C01CB, 0x2601891F, 0x5101E346, 0x2F2C03E5, 0x2F3C312F, 0x2F462F2F, 0x312F2F2F, 0x322F2C44, 0x322F2D31,
    0x2C462F2F, 0x2F2F322F, 0x2F2F322F, 0x3409CDBF, 0x2E2E2C2C, 0x31312E2E, 0xD6983629, 0xA92D8F05, 0x5FF93101, 0x312D2D2D, 0x2F2F2F2F, 0x3230342F, 0x41323D32, 0x2F2F3232, 0x2F2F2F2F, 0x2F322F2F,
    0x3034322F, 0xE3323232, 0x2F2F7401, 0x2F2F2F2F, 0x2F2F2F2F, 0x3201E72F, 0x25DD322F, 0x47293B32, 0x01922C32, 0x9378AF46, 0x2C2F018D, 0x2E2E2C2C, 0xBB2F21AD, 0x3101A952, 0x4ECD0DC2, 0x02812F35,
    0x30343232, 0x332F2F32, 0x332F2F2B, 0x8D3112AB, 0x8A332F0A, 0x08CC2715, 0x01EDCD33, 0x0F089A1D, 0x2201A1C4, 0x2D222B2D, 0x22202B2A, 0x2020283B, 0x25222020, 0x20202020, 0x2A353720, 0x2A2A3F2A,
    0x3F2A2A3F, 0x2A3F2A2A, 0x2A2A3F2A, 0x3F2A2A3F, 0x2A41282A, 0x41283F2A, 0x442A3F2A, 0x20202020, 0x25222020, 0x5B202020, 0x6D03DB76, 0x2E332934, 0x04F9203E, 0xE42E3CFF, 0x2F2BB039, 0x2456FF2A,
    0x22225927, 0x47EC2520, 0x5E03C161, 0x3717391D, 0x2A1A2724, 0x3D172A1F, 0x19BB531A, 0x6C08C667, 0x765F06C6, 0x59437B66, 0x9524C216, 0x0C01D204, 0x0E3B0C34, 0x494C1782, 0x13049D13, 0x02A71525,
    0x570E550E, 0x720E570E, 0x4911650E, 0x51115816, 0x28774F58, 0x04911949, 0x625701C0, 0x4F61685E, 0xE40A8111, 0x50625A02, 0x1308A113, 0x03FE1927, 0xE520331A, 0x9B134C01, 0x13291111, 0x271304A5,
    0x1302E213, 0x02B51325, 0x655B6260, 0xEB586261, 0x8305B002, 0x0D2F1C01, 0x16B705C9, 0x311301FD, 0x201D960F, 0x784C06B2, 0x911B492F, 0x970E6701, 0x0F3E1110, 0x0D270F2C, 0x6B05CA2B, 0xCE58625D,
    0x5101D703, 0x1414B151, 0xD013079E, 0x09AA1403, 0x243D2D13, 0xE30D2B1A, 0x1301BE0C, 0x3E1105DE, 0x270F2C0F, 0x1314A10D, 0x615203C1, 0x029A4066, 0x4224EE17, 0xA02E4242, 0x42423606, 0x3A20E142,
    0x575B0595, 0x01AC04EA, 0x05FB5A65, 0x3A03B670, 0xB1029F3A, 0x02CC2C06, 0x4A02B22C, 0xCD484632, 0xEA028C06, 0x114C5302, 0x1301CEFF, 0x0F361927, 0x13341430, 0x5BB306D9, 0x12FD5EDD, 0x3702A8D3,
    0x31313131, 0x31313131, 0x31261297, 0x292E2E2B, 0x9E9F2F2C, 0x3719DC01, 0x2F2C2C65, 0x2C2C342A, 0x221F3425, 0x211F1F1F, 0x048AD926, 0x922A2D2C, 0x7B323247, 0x25232749, 0x272D2525, 0x25502F26,
    0x2F2F2B27, 0x322F462F, 0x49323232, 0x34323232, 0x2D2F6AD0, 0x2C2C29A7, 0xA12E2E39, 0x2C362F75, 0x322F2F2F, 0x04C7CF36, 0x12A62A37, 0x2E2E2E31, 0x2E402B34, 0x2A2E3329, 0x2E2E2E56, 0xA9272E43,
    0x272E3452, 0xBF274787, 0x3131261C, 0x312E3131, 0x33292E2E, 0xC92A3131, 0x2C2C3129, 0x2F2F42ED, 0x2A0ACA30, 0x2C2C2F31, 0x2C2C2C2C, 0x2B2C3127, 0x2C1F372B, 0x262C2C2C, 0x24312E33, 0xA9221F34,
    0x2C34240F, 0x2C2C2C2C, 0xBB2A2F2C, 0x2F342A1D, 0xC12A35CD, 0x232307D3, 0x23202020, 0x20232020, 0x22E32320, 0x2F2F33AC, 0x0ACB334A, 0x9C2C1CE3, 0xB109CC08, 0x2F2F2F4B, 0x25254432, 0x372002A3,
    0x3C2F2F2F, 0x84292620, 0x32323223, 0x32323034, 0x25253C2F, 0x1C8B02AB, 0x25252525, 0x322F2D25, 0x49018A32, 0x32443132, 0x25462F2F, 0x138D8032, 0xF6AC0100, 0xE303FC01, 0xCEFF2B66, 0x02908243,
    0x0D94951D, 0x010204F8, 0x0002C2C1, 0x48C18D01, 0xC0E00100, 0x0D94A648, 0x01000583, 0xB31F81E1, 0x268501DF, 0x003DF1AD, 0x33F3F401, 0x21A508E2, 0xAA1E634C, 0xBC923513, 0xB001A12A, 0xC1010004,
    0xDEB40B9A, 0x951BB410, 0x14BDD301, 0x01D9C541, 0x01A69713, 0x132A1358, 0xCB13132A, 0x13131301, 0x1AF61313, 0x8E1309C5, 0x13134C21, 0x208A1485, 0x131307D5, 0x91131313, 0x136F1301, 0x133D1313,
    0xF5F008BD, 0x01D3A802, 0xE6A51313, 0xA7131304, 0x0186FC02, 0x0185CD13, 0x13131313, 0xEE131358, 0x34A908DE, 0x0015C190, 0x08D7D101, 0x2A136F13, 0x132A1313, 0x02C0932A, 0x13131313, 0x13131313,
    0x13131313, 0x2A131313, 0x13131313, 0x13131313, 0x1313132A, 0xCDC11313, 0x2A131309, 0x13131313, 0xC3131313, 0x13410787, 0x2A131313, 0x13131313, 0x1302EA13, 0x13131313, 0x13131313, 0x13131313,
    0x13131313, 0x121014C9, 0x1C321B1B, 0x1002898A, 0xCC101010, 0xC7132A1E, 0x10101060, 0x13135680, 0x13131313, 0x13131313, 0x13131313, 0xE810109A, 0xA210100A, 0xBC26824D, 0x1010102D, 0x26D91010,
    0x10101010, 0x10101010, 0x10101010, 0x130EF58E, 0x0CCB2427, 0x13131313, 0x13131313, 0x01C8F813, 0xE1101010, 0x01A69701, 0x01861313, 0x13131358, 0x01CB1313, 0xAC23D813, 0xCC20AC36, 0xC6E51303,
    0xEC54FC01, 0x01A3FC6A, 0xCE851313, 0x488A1304, 0x13131313, 0x13131313, 0x2A131313, 0x1366DE13, 0xBE131313, 0x1313131F, 0x13131313, 0xF113132A, 0x10100181, 0x10101010, 0x83101010, 0x84131301,
    0x01001EDA, 0xE20B9DC8, 0x09CF9001, 0x9B0CC7A7, 0x131310F6, 0x2CCDCD13, 0xEDC10100, 0x0BF3BC14, 0x278C53DC, 0xCE9E1313, 0xF502AD10, 0x1EE301A7, 0x0BAC6083, 0xA0F10995, 0x15F9E714, 0xD8FC0100,
    0x13131333, 0x44C71313, 0x002AD8C4, 0x32AAD501, 0x8502B2A0, 0x01002AA4, 0x005EFC82, 0x5EFFB201, 0xCCE00100, 0x0381E245, 0x0303DB03, 0x0016B6E6, 0x23C2FF01, 0xCCD506E1, 0x09BC8020, 0x0011B6D2,
    0x5F88E001, 0xBB010020, 0x03E448CE, 0x1B16B6C4, 0xC2F70100, 0x9306CB23, 0xD6F102E8, 0x01002838, 0x2335ABA2, 0x13E6D624, 0x2424232A, 0x1E291823, 0x24232A31, 0x52242324, 0x15F1FB70, 0x9FA80100,
    0x05330560, 0x00000000,
    // clang-format on
};

static u16 BaseSymbolBuckets[0x2000];

void InitBaseSymbols()
{
    std::memset(BaseSymbolBuckets, 0xFF, sizeof(BaseSymbolBuckets));

    for (usize i = 0; i < ARTS_SIZE(BaseSymbols); ++i)
    {
        auto& symbol = BaseSymbols[i];
        symbol.HashNext = BaseSymbolBuckets[symbol.Hash & 0x1FFF];
        BaseSymbolBuckets[symbol.Hash & 0x1FFF] = static_cast<u16>(i);
    }
}

static const SymbolInfo* LookupBaseSymbolHash(u32 hash)
{
    for (u16 i = BaseSymbolBuckets[hash & 0x1FFF]; i != 0xFFFF;)
    {
        auto& symbol = BaseSymbols[i];

        if (symbol.Hash == hash)
            return &symbol;

        i = BaseSymbols[i].HashNext;
    }

    return nullptr;
}

static u32 HashSymbol(std::string_view string)
{
    u32 hash = 0;

    for (unsigned char c : string)
    {
        hash += c;
        hash += hash << 10;
        hash ^= hash >> 6;
    }

    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;

    return hash;
}

const SymbolInfo* LookupBaseSymbol(std::string_view name)
{
    return LookupBaseSymbolHash(HashSymbol(name));
}

const SymbolInfo* LookupBaseSymbolAddress(usize addr)
{
    if (auto find = std::lower_bound(std::begin(BaseSymbols), std::end(BaseSymbols), addr,
            [](const SymbolInfo& lhs, usize addr) { return lhs.Address < addr; });
        find != std::end(BaseSymbols) && find->Address == addr)
    {
        return &*find;
    }

    return nullptr;
}

static usize leb128_decode_usize(const void** input)
{
    const u8* input8 = static_cast<const u8*>(*input);
    usize result = 0;
    usize shift = 0;

    while (true)
    {
        u8 v = *input8++;
        result |= (v & 0x7F) << shift;
        shift += 7;
        if ((v & 0x80) == 0)
            break;
    }

    *input = input8;

    return result;
}

static isize leb128_decode_isize(const void** input)
{
    usize result = leb128_decode_usize(input);

    return (result >> 1) ^ -isize(result & 1);
}

bool SymbolInfo::IsFunction() const
{
    const void* input = reinterpret_cast<const u8*>(BaseSymbolData) + DataIndex;
    usize type = leb128_decode_usize(&input);
    return type == 0;
}

void SymbolInfo::Hook(mem::pointer new_address) const
{
    const void* input = reinterpret_cast<const u8*>(BaseSymbolData) + DataIndex;

    usize type = leb128_decode_usize(&input);

    switch (type)
    {
        case 0: // Function
        {
            create_hook("", "", Address, new_address, hook_type::jmp);

            break;
        }

        case 1: // "Simple" Data (No Deltas)
        case 2: // "Complex" Data (With Deltas)
        {
            mem::pointer addr = 0x400000;
            isize delta = 0;

            while (true)
            {
                usize off = leb128_decode_usize(&input);
                if (off == 0)
                    break;
                addr += off;

                if (type == 2)
                    delta += leb128_decode_isize(&input);

                create_hook("", "", addr, new_address + delta, hook_type::pointer);
                addr += 4;
            }

            break;
        }
    }
}
