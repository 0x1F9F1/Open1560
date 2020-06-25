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
    mmaudio:dsglobal

    0x4EF140 | public: __thiscall DSGlobal::DSGlobal(void) | ??0DSGlobal@@QAE@XZ
    0x4EF200 | public: __thiscall DSGlobal::~DSGlobal(void) | ??1DSGlobal@@QAE@XZ
    0x4EF2E0 | public: void __thiscall DSGlobal::DeallocateUIADF(void) | ?DeallocateUIADF@DSGlobal@@QAEXXZ
    0x4EF340 | public: void __thiscall DSGlobal::DeallocateCityADF(void) | ?DeallocateCityADF@DSGlobal@@QAEXXZ
    0x4EF370 | public: void __thiscall DSGlobal::DeallocateADFRecord(int) | ?DeallocateADFRecord@DSGlobal@@QAEXH@Z
    0x4EF400 | public: void __thiscall DSGlobal::DeInit(short,short) | ?DeInit@DSGlobal@@QAEXFF@Z
    0x4EF550 | public: int __thiscall DSGlobal::Init(unsigned long,unsigned char,unsigned int *,char *,short,short) | ?Init@DSGlobal@@QAEHKEPAIPADFF@Z
    0x4EF770 | public: int __thiscall DSGlobal::Init3DListener(float,float,float,float,float) | ?Init3DListener@DSGlobal@@QAEHMMMMM@Z
    0x4EF800 | void __cdecl UpperCase(char *) | ?UpperCase@@YAXPAD@Z
    0x4EF850 | int __cdecl IsDSDeviceInList(struct _GUID *) | ?IsDSDeviceInList@@YAHPAU_GUID@@@Z
    0x4EF8B0 | int __stdcall DSEnumProc(struct _GUID *,char *,char *,void *) | ?DSEnumProc@@YGHPAU_GUID@@PAD1PAX@Z
    0x4EFA50 | public: void __thiscall DSGlobal::SetDeviceRating(struct tag_dsdevdesc *) | ?SetDeviceRating@DSGlobal@@QAEXPAUtag_dsdevdesc@@@Z
    0x4EFBB0 | public: int __thiscall DSGlobal::EnumDSDevices(void) | ?EnumDSDevices@DSGlobal@@QAEHXZ
    0x4EFBD0 | public: int __thiscall DSGlobal::InitPrimarySoundBuffer(unsigned long,unsigned char,char *) | ?InitPrimarySoundBuffer@DSGlobal@@QAEHKEPAD@Z
    0x4EFDD0 | public: void __thiscall DSGlobal::ClearDSDeviceList(void) | ?ClearDSDeviceList@DSGlobal@@QAEXXZ
    0x4EFE10 | public: int __thiscall DSGlobal::LoadUIADF(char *) | ?LoadUIADF@DSGlobal@@QAEHPAD@Z
    0x4EFFB0 | public: int __thiscall DSGlobal::LoadCityADF(char *,int,unsigned long) | ?LoadCityADF@DSGlobal@@QAEHPADHK@Z
    0x4F01C0 | public: int __thiscall DSGlobal::InitCityADF(char *,int,unsigned long) | ?InitCityADF@DSGlobal@@QAEHPADHK@Z
    0x4F0280 | public: int __thiscall DSGlobal::InitUIADF(char *,int,unsigned long) | ?InitUIADF@DSGlobal@@QAEHPADHK@Z
    0x4F0340 | public: void __thiscall DSGlobal::ConvertTo8Bit(int) | ?ConvertTo8Bit@DSGlobal@@QAEXH@Z
    0x4F04D0 | int __cdecl FormatCodeToWFX(unsigned long,struct tWAVEFORMATEX *) | ?FormatCodeToWFX@@YAHKPAUtWAVEFORMATEX@@@Z
    0x4F0580 | public: void __thiscall DSGlobal::SetPrimaryBufferFormat(unsigned long,unsigned char) | ?SetPrimaryBufferFormat@DSGlobal@@QAEXKE@Z
    0x4F0670 | public: void __thiscall DSGlobal::ScanAvailableDSFormats(void) | ?ScanAvailableDSFormats@DSGlobal@@QAEXXZ
    0x4F0730 | public: char * __thiscall DSGlobal::TranslateDSError(long) | ?TranslateDSError@DSGlobal@@QAEPADJ@Z
    0x4F08E0 | public: unsigned char __thiscall DSGlobal::CheckCDFile(char *) | ?CheckCDFile@DSGlobal@@QAEEPAD@Z
    0x4F0990 | public: void __thiscall DSGlobal::SetBitDepth(int) | ?SetBitDepth@DSGlobal@@QAEXH@Z
    0x4F09C0 | public: char * * __thiscall DSGlobal::GetDeviceNames(void) | ?GetDeviceNames@DSGlobal@@QAEPAPADXZ
    0x4F09F0 | public: unsigned long __thiscall DSGlobal::GetNum3DHallBufs(void) | ?GetNum3DHallBufs@DSGlobal@@QAEKXZ
    0x4F0A20 | public: static unsigned int const __cdecl DSGlobal::GetStereoOnMask(void) | ?GetStereoOnMask@DSGlobal@@SA?BIXZ
    0x4F0A30 | public: static unsigned int const __cdecl DSGlobal::GetHiResMask(void) | ?GetHiResMask@DSGlobal@@SA?BIXZ
    0x4F0A40 | public: static unsigned int const __cdecl DSGlobal::GetHiSampleSizeMask(void) | ?GetHiSampleSizeMask@DSGlobal@@SA?BIXZ
    0x4F0A50 | public: static unsigned int const __cdecl DSGlobal::GetEchoOnMask(void) | ?GetEchoOnMask@DSGlobal@@SA?BIXZ
    0x4F0A60 | public: static unsigned int const __cdecl DSGlobal::GetDSound3DMask(void) | ?GetDSound3DMask@DSGlobal@@SA?BIXZ
    0x4F0A70 | public: static unsigned int const __cdecl DSGlobal::GetSoundFXOnMask(void) | ?GetSoundFXOnMask@DSGlobal@@SA?BIXZ
    0x4F0A80 | public: static unsigned int const __cdecl DSGlobal::GetCommentaryOnMask(void) | ?GetCommentaryOnMask@DSGlobal@@SA?BIXZ
    0x4F0A90 | public: static unsigned int const __cdecl DSGlobal::GetCDMusicOnMask(void) | ?GetCDMusicOnMask@DSGlobal@@SA?BIXZ
    0x4F0AA0 | public: static unsigned int const __cdecl DSGlobal::GetUsingEAXMask(void) | ?GetUsingEAXMask@DSGlobal@@SA?BIXZ
    0x4F0AB0 | public: unsigned int __thiscall DSGlobal::EAXEnabled(void) | ?EAXEnabled@DSGlobal@@QAEIXZ
    0x4F0AC0 | public: unsigned int __thiscall DSGlobal::IsAlwaysEAX(void) | ?IsAlwaysEAX@DSGlobal@@QAEIXZ
    0x4F0AD0 | public: unsigned int __thiscall DSGlobal::AlwaysEAX(unsigned int) | ?AlwaysEAX@DSGlobal@@QAEII@Z
    0x4F0B00 | public: unsigned int __thiscall DSGlobal::DSound3DEnabled(void) | ?DSound3DEnabled@DSGlobal@@QAEIXZ
    0x4F0B10 | public: void __thiscall DSGlobal::DisableEAXFlag(void) | ?DisableEAXFlag@DSGlobal@@QAEXXZ
    0x61FED0 | private: static unsigned int const DSGlobal::s_iStereoOnMask | ?s_iStereoOnMask@DSGlobal@@0IB
    0x61FED4 | private: static unsigned int const DSGlobal::s_iHiResMask | ?s_iHiResMask@DSGlobal@@0IB
    0x61FED8 | private: static unsigned int const DSGlobal::s_iHiSampleSizeMask | ?s_iHiSampleSizeMask@DSGlobal@@0IB
    0x61FEDC | private: static unsigned int const DSGlobal::s_iEchoOnMask | ?s_iEchoOnMask@DSGlobal@@0IB
    0x61FEE0 | private: static unsigned int const DSGlobal::s_iDSound3DMask | ?s_iDSound3DMask@DSGlobal@@0IB
    0x61FEE4 | private: static unsigned int const DSGlobal::s_iSoundFXOnMask | ?s_iSoundFXOnMask@DSGlobal@@0IB
    0x61FEE8 | private: static unsigned int const DSGlobal::s_iCDMusicOnMask | ?s_iCDMusicOnMask@DSGlobal@@0IB
    0x61FEEC | private: static unsigned int const DSGlobal::s_iUsingEAXMask | ?s_iUsingEAXMask@DSGlobal@@0IB
    0x61FEF0 | private: static unsigned int const DSGlobal::s_iAlwaysEAXMask | ?s_iAlwaysEAXMask@DSGlobal@@0IB
    0x61FEF4 | private: static unsigned int const DSGlobal::s_iCommentaryOnMask | ?s_iCommentaryOnMask@DSGlobal@@0IB
    0x61FEF8 | const CDMan::`vftable' | ??_7CDMan@@6B@
    0x647DD8 | struct tag_fd * aOutputFormats | ?aOutputFormats@@3PAUtag_fd@@A
    0x719334 | class DSGlobal * DSGlobalPtr | ?DSGlobalPtr@@3PAVDSGlobal@@A
*/

class DSGlobal
{
public:
    // 0x4EF140 | ??0DSGlobal@@QAE@XZ
    ARTS_IMPORT DSGlobal();

    // 0x4EF200 | ??1DSGlobal@@QAE@XZ
    ARTS_IMPORT ~DSGlobal();

    // 0x4F0AD0 | ?AlwaysEAX@DSGlobal@@QAEII@Z
    ARTS_IMPORT u32 AlwaysEAX(u32 arg1);

    // 0x4F08E0 | ?CheckCDFile@DSGlobal@@QAEEPAD@Z
    ARTS_IMPORT u8 CheckCDFile(char* arg1);

    // 0x4EFDD0 | ?ClearDSDeviceList@DSGlobal@@QAEXXZ
    ARTS_IMPORT void ClearDSDeviceList();

    // 0x4F0340 | ?ConvertTo8Bit@DSGlobal@@QAEXH@Z
    ARTS_IMPORT void ConvertTo8Bit(i32 arg1);

    // 0x4F0B00 | ?DSound3DEnabled@DSGlobal@@QAEIXZ
    ARTS_IMPORT u32 DSound3DEnabled();

    // 0x4EF400 | ?DeInit@DSGlobal@@QAEXFF@Z
    ARTS_IMPORT void DeInit(i16 arg1, i16 arg2);

    // 0x4EF370 | ?DeallocateADFRecord@DSGlobal@@QAEXH@Z
    ARTS_IMPORT void DeallocateADFRecord(i32 arg1);

    // 0x4EF340 | ?DeallocateCityADF@DSGlobal@@QAEXXZ
    ARTS_IMPORT void DeallocateCityADF();

    // 0x4EF2E0 | ?DeallocateUIADF@DSGlobal@@QAEXXZ
    ARTS_IMPORT void DeallocateUIADF();

    // 0x4F0B10 | ?DisableEAXFlag@DSGlobal@@QAEXXZ
    ARTS_IMPORT void DisableEAXFlag();

    // 0x4F0AB0 | ?EAXEnabled@DSGlobal@@QAEIXZ
    ARTS_IMPORT u32 EAXEnabled();

    // 0x4EFBB0 | ?EnumDSDevices@DSGlobal@@QAEHXZ
    ARTS_IMPORT i32 EnumDSDevices();

    // 0x4F09C0 | ?GetDeviceNames@DSGlobal@@QAEPAPADXZ
    ARTS_IMPORT char** GetDeviceNames();

    // 0x4F09F0 | ?GetNum3DHallBufs@DSGlobal@@QAEKXZ | unused
    ARTS_IMPORT u32 GetNum3DHallBufs();

    // 0x4EF550 | ?Init@DSGlobal@@QAEHKEPAIPADFF@Z
    ARTS_IMPORT i32 Init(u32 arg1, u8 arg2, u32* arg3, char* arg4, i16 arg5, i16 arg6);

    // 0x4EF770 | ?Init3DListener@DSGlobal@@QAEHMMMMM@Z
    ARTS_IMPORT i32 Init3DListener(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x4F01C0 | ?InitCityADF@DSGlobal@@QAEHPADHK@Z
    ARTS_IMPORT i32 InitCityADF(char* arg1, i32 arg2, u32 arg3);

    // 0x4EFBD0 | ?InitPrimarySoundBuffer@DSGlobal@@QAEHKEPAD@Z
    ARTS_IMPORT i32 InitPrimarySoundBuffer(u32 arg1, u8 arg2, char* arg3);

    // 0x4F0280 | ?InitUIADF@DSGlobal@@QAEHPADHK@Z
    ARTS_IMPORT i32 InitUIADF(char* arg1, i32 arg2, u32 arg3);

    // 0x4F0AC0 | ?IsAlwaysEAX@DSGlobal@@QAEIXZ
    ARTS_IMPORT u32 IsAlwaysEAX();

    // 0x4EFFB0 | ?LoadCityADF@DSGlobal@@QAEHPADHK@Z
    ARTS_IMPORT i32 LoadCityADF(char* arg1, i32 arg2, u32 arg3);

    // 0x4EFE10 | ?LoadUIADF@DSGlobal@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadUIADF(char* arg1);

    // 0x4F0670 | ?ScanAvailableDSFormats@DSGlobal@@QAEXXZ | unused
    ARTS_IMPORT void ScanAvailableDSFormats();

    // 0x4F0990 | ?SetBitDepth@DSGlobal@@QAEXH@Z
    ARTS_IMPORT void SetBitDepth(i32 arg1);

    // 0x4EFA50 | ?SetDeviceRating@DSGlobal@@QAEXPAUtag_dsdevdesc@@@Z
    ARTS_IMPORT void SetDeviceRating(struct tag_dsdevdesc* arg1);

    // 0x4F0580 | ?SetPrimaryBufferFormat@DSGlobal@@QAEXKE@Z
    ARTS_IMPORT void SetPrimaryBufferFormat(u32 arg1, u8 arg2);

    // 0x4F0730 | ?TranslateDSError@DSGlobal@@QAEPADJ@Z
    ARTS_IMPORT char* TranslateDSError(i32 arg1);

    // 0x4F0A90 | ?GetCDMusicOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetCDMusicOnMask();

    // 0x4F0A80 | ?GetCommentaryOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetCommentaryOnMask();

    // 0x4F0A60 | ?GetDSound3DMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetDSound3DMask();

    // 0x4F0A50 | ?GetEchoOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetEchoOnMask();

    // 0x4F0A30 | ?GetHiResMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetHiResMask();

    // 0x4F0A40 | ?GetHiSampleSizeMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetHiSampleSizeMask();

    // 0x4F0A70 | ?GetSoundFXOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetSoundFXOnMask();

    // 0x4F0A20 | ?GetStereoOnMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetStereoOnMask();

    // 0x4F0AA0 | ?GetUsingEAXMask@DSGlobal@@SA?BIXZ
    ARTS_IMPORT static u32 const GetUsingEAXMask();

private:
    // 0x61FEF0 | ?s_iAlwaysEAXMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iAlwaysEAXMask;

    // 0x61FEE8 | ?s_iCDMusicOnMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iCDMusicOnMask;

    // 0x61FEF4 | ?s_iCommentaryOnMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iCommentaryOnMask;

    // 0x61FEE0 | ?s_iDSound3DMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iDSound3DMask;

    // 0x61FEDC | ?s_iEchoOnMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iEchoOnMask;

    // 0x61FED4 | ?s_iHiResMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iHiResMask;

    // 0x61FED8 | ?s_iHiSampleSizeMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iHiSampleSizeMask;

    // 0x61FEE4 | ?s_iSoundFXOnMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iSoundFXOnMask;

    // 0x61FED0 | ?s_iStereoOnMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iStereoOnMask;

    // 0x61FEEC | ?s_iUsingEAXMask@DSGlobal@@0IB
    ARTS_IMPORT static u32 const s_iUsingEAXMask;
};

check_size(DSGlobal, 0xB8);

// 0x4EF8B0 | ?DSEnumProc@@YGHPAU_GUID@@PAD1PAX@Z
ARTS_IMPORT i32 ARTS_STDCALL DSEnumProc(struct _GUID* arg1, char* arg2, char* arg3, void* arg4);

// 0x4F04D0 | ?FormatCodeToWFX@@YAHKPAUtWAVEFORMATEX@@@Z
ARTS_IMPORT i32 FormatCodeToWFX(u32 arg1, struct tWAVEFORMATEX* arg2);

// 0x4EF850 | ?IsDSDeviceInList@@YAHPAU_GUID@@@Z
ARTS_IMPORT i32 IsDSDeviceInList(struct _GUID* arg1);

// 0x4EF800 | ?UpperCase@@YAXPAD@Z
ARTS_IMPORT void UpperCase(char* arg1);

// 0x719334 | ?DSGlobalPtr@@3PAVDSGlobal@@A
ARTS_IMPORT extern class DSGlobal* DSGlobalPtr;

// 0x647DD8 | ?aOutputFormats@@3PAUtag_fd@@A
ARTS_IMPORT extern struct tag_fd aOutputFormats[16];
