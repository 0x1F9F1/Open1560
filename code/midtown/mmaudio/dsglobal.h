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

#include <Windows.h>

#include <mmeapi.h>

#include <dsound.h>

typedef struct tag_dsdevdesc
{
    GUID guDevice;      // Device GUID
    PSTR pszDeviceDesc; // Description string
    DWORD dwRating;     // Device Rating
    tag_dsdevdesc* pNext;
} DSDeviceDesc;

check_size(DSDeviceDesc, 0x1C);

typedef struct tag_fd
{
    DWORD dwCode;
    BOOL fEnabled;
} DSFormatData;

check_size(DSFormatData, 0x8);

class CDMan;
class MixerCTL;

class DSGlobal
{
public:
    // ??0DSGlobal@@QAE@XZ
    ARTS_IMPORT DSGlobal();

    // ??1DSGlobal@@QAE@XZ
    ARTS_IMPORT ~DSGlobal();

    // ?AlwaysEAX@DSGlobal@@QAEII@Z
    ARTS_IMPORT u32 AlwaysEAX(u32 arg1);

    // ?CheckCDFile@DSGlobal@@QAEEPAD@Z
    ARTS_EXPORT u8 CheckCDFile(aconst char* file_name);

    // ?ClearDSDeviceList@DSGlobal@@QAEXXZ
    ARTS_IMPORT void ClearDSDeviceList();

    // ?ConvertTo8Bit@DSGlobal@@QAEXH@Z
    ARTS_IMPORT void ConvertTo8Bit(i32 arg1);

    // ?DSound3DEnabled@DSGlobal@@QAEIXZ
    ARTS_IMPORT u32 DSound3DEnabled();

    // ?DeInit@DSGlobal@@QAEXFF@Z
    ARTS_IMPORT void DeInit(i16 arg1, i16 arg2);

    // ?DeallocateADFRecord@DSGlobal@@QAEXH@Z
    ARTS_IMPORT void DeallocateADFRecord(i32 arg1);

    // ?DeallocateCityADF@DSGlobal@@QAEXXZ
    ARTS_IMPORT void DeallocateCityADF();

    // ?DeallocateUIADF@DSGlobal@@QAEXXZ
    ARTS_IMPORT void DeallocateUIADF();

    // ?DisableEAXFlag@DSGlobal@@QAEXXZ
    ARTS_IMPORT void DisableEAXFlag();

    // ?EAXEnabled@DSGlobal@@QAEIXZ
    ARTS_IMPORT u32 EAXEnabled();

    // ?EnumDSDevices@DSGlobal@@QAEHXZ
    ARTS_IMPORT i32 EnumDSDevices();

    // ?GetDeviceNames@DSGlobal@@QAEPAPADXZ
    ARTS_EXPORT char** GetDeviceNames();

    bool GetWaveDeviceID(u32 device_num, u32& wave_id);

    const char* GetDeviceName(u32 index);

    // ?Init@DSGlobal@@QAEHKEPAIPADFF@Z
    ARTS_IMPORT i32 Init(ulong arg1, u8 arg2, u32* arg3, char* arg4, i16 arg5, i16 arg6);

    // ?Init3DListener@DSGlobal@@QAEHMMMMM@Z
    ARTS_IMPORT i32 Init3DListener(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?InitCityADF@DSGlobal@@QAEHPADHK@Z
    ARTS_IMPORT i32 InitCityADF(char* arg1, i32 arg2, ulong arg3);

    // ?InitPrimarySoundBuffer@DSGlobal@@QAEHKEPAD@Z
    ARTS_IMPORT b32 InitPrimarySoundBuffer(ulong sample_rate, u8 stero, char* device_name);

    // ?InitUIADF@DSGlobal@@QAEHPADHK@Z
    ARTS_IMPORT i32 InitUIADF(char* arg1, i32 arg2, ulong arg3);

    // ?IsAlwaysEAX@DSGlobal@@QAEIXZ
    ARTS_IMPORT u32 IsAlwaysEAX();

    // ?LoadCityADF@DSGlobal@@QAEHPADHK@Z
    ARTS_IMPORT i32 LoadCityADF(char* arg1, i32 arg2, ulong arg3);

    // ?LoadUIADF@DSGlobal@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadUIADF(char* arg1);

    // ?SetBitDepth@DSGlobal@@QAEXH@Z
    ARTS_IMPORT void SetBitDepth(i32 arg1);

    // ?SetDeviceRating@DSGlobal@@QAEXPAUtag_dsdevdesc@@@Z
    ARTS_IMPORT void SetDeviceRating(tag_dsdevdesc* arg1);

    // ?SetPrimaryBufferFormat@DSGlobal@@QAEXKE@Z
    ARTS_IMPORT void SetPrimaryBufferFormat(ulong arg1, u8 arg2);

    // ?TranslateDSError@DSGlobal@@QAEPADJ@Z
    ARTS_IMPORT char* TranslateDSError(ilong arg1);

    ARTS_DIAGNOSTIC_PUSH;
    ARTS_CLANG_DIAGNOSTIC_IGNORED("-Wignored-qualifiers");

    // ?GetCDMusicOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetCDMusicOnMask();

    // ?GetCommentaryOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetCommentaryOnMask();

    // ?GetDSound3DMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetDSound3DMask();

    // ?GetEchoOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetEchoOnMask();

    // ?GetHiResMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetHiResMask();

    // ?GetHiSampleSizeMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetHiSampleSizeMask();

    // ?GetSoundFXOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetSoundFXOnMask();

    // ?GetStereoOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetStereoOnMask();

    // ?GetUsingEAXMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static const u32 GetUsingEAXMask();

    ARTS_DIAGNOSTIC_POP;

private:
    // ?s_iAlwaysEAXMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iAlwaysEAXMask;

    // ?s_iCDMusicOnMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iCDMusicOnMask;

    // ?s_iCommentaryOnMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iCommentaryOnMask;

    // ?s_iDSound3DMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iDSound3DMask;

    // ?s_iEchoOnMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iEchoOnMask;

    // ?s_iHiResMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iHiResMask;

    // ?s_iHiSampleSizeMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iHiSampleSizeMask;

    // ?s_iSoundFXOnMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iSoundFXOnMask;

    // ?s_iStereoOnMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iStereoOnMask;

    // ?s_iUsingEAXMask@DSGlobal@@0IB
    ARTS_IMPORT static const u32 s_iUsingEAXMask;

    IDirectSoundBuffer* DSBuffer;
    IDirectSound* DSound;
    HWND Window;
    i32 field_C;
    DSDeviceDesc* DevicesList;
    DSDeviceDesc* SelectedDevice;
    i32 field_18;
    char Name[100];
    u32 NumDevices;
    i32 BitDepth;
    i32 Flags;
    i32 AudFlags;
    u8 byte90;
    i32 HasDSBuffer;
    i32 field_98;
    i32 CdManagerLoaded;
    i32 field_A0;
    CDMan* CDManager;
    MixerCTL* Mixer;
    DSDeviceDesc** DevicesArray;
    i32 field_B0;
    i32 field_B4;
};

check_size(DSGlobal, 0xB8);

// ?DSEnumProc@@YGHPAU_GUID@@PAD1PAX@Z
ARTS_IMPORT i32 ARTS_STDCALL DSEnumProc(_GUID* arg1, char* arg2, char* arg3, void* arg4);

// ?FormatCodeToWFX@@YAHKPAUtWAVEFORMATEX@@@Z
ARTS_IMPORT i32 FormatCodeToWFX(ulong arg1, tWAVEFORMATEX* arg2);

// ?IsDSDeviceInList@@YAHPAU_GUID@@@Z
ARTS_IMPORT i32 IsDSDeviceInList(_GUID* arg1);

// ?UpperCase@@YAXPAD@Z
ARTS_IMPORT void UpperCase(char* arg1);

// ?DSGlobalPtr@@3PAVDSGlobal@@A
ARTS_IMPORT extern DSGlobal* DSGlobalPtr;

// ?aOutputFormats@@3PAUtag_fd@@A
ARTS_IMPORT extern DSFormatData aOutputFormats[16];
