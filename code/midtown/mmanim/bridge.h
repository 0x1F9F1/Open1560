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
    mmanim:bridge

    0x4C16B0 | public: __thiscall mmBridgeMgr::mmBridgeMgr(void) | ??0mmBridgeMgr@@QAE@XZ
    0x4C17C0 | public: virtual __thiscall mmBridgeMgr::~mmBridgeMgr(void) | ??1mmBridgeMgr@@UAE@XZ
    0x4C1850 | public: void __thiscall mmBridgeMgr::ToggleDrawLabels(void) | ?ToggleDrawLabels@mmBridgeMgr@@QAEXXZ
    0x4C1860 | public: virtual void __thiscall mmBridgeMgr::Cull(void) | ?Cull@mmBridgeMgr@@UAEXXZ
    0x4C18A0 | public: void __thiscall mmBridgeMgr::Init(char *,class mmInstance *,class mmInstance * *,int) | ?Init@mmBridgeMgr@@QAEXPADPAVmmInstance@@PAPAV2@H@Z
    0x4C1CC0 | public: virtual void __thiscall mmBridgeMgr::Save(void) | ?Save@mmBridgeMgr@@UAEXXZ
    0x4C1CD0 | public: virtual void __thiscall mmBridgeMgr::AddWidgets(class Bank *) | ?AddWidgets@mmBridgeMgr@@UAEXPAVBank@@@Z
    0x4C1F00 | public: __thiscall mmBridgeSet::mmBridgeSet(void) | ??0mmBridgeSet@@QAE@XZ
    0x4C2010 | public: virtual __thiscall mmBridgeSet::~mmBridgeSet(void) | ??1mmBridgeSet@@UAE@XZ
    0x4C2080 | public: virtual void __thiscall mmBridgeSet::Reset(void) | ?Reset@mmBridgeSet@@UAEXXZ
    0x4C2150 | public: int __thiscall mmBridgeSet::ReadEntry(class Stream *,int) | ?ReadEntry@mmBridgeSet@@QAEHPAVStream@@H@Z
    0x4C2290 | public: void __thiscall mmBridgeSet::InitTrigger(void) | ?InitTrigger@mmBridgeSet@@QAEXXZ
    0x4C22C0 | public: int __thiscall mmBridgeSet::Init(char *,class Stream *) | ?Init@mmBridgeSet@@QAEHPADPAVStream@@@Z
    0x4C2380 | public: virtual void __thiscall mmBridgeSet::Update(void) | ?Update@mmBridgeSet@@UAEXXZ
    0x4C2730 | public: virtual void __thiscall mmBridgeSet::Cull(void) | ?Cull@mmBridgeSet@@UAEXXZ
    0x4C27D0 | public: virtual void __thiscall mmBridgeSet::AddWidgets(class Bank *) | ?AddWidgets@mmBridgeSet@@UAEXPAVBank@@@Z
    0x4C29A0 | public: static void __cdecl mmBridgeSet::DeclareFields(void) | ?DeclareFields@mmBridgeSet@@SAXXZ
    0x4C2A40 | public: void __thiscall mmBridgeSet::UpdateAudio(void) | ?UpdateAudio@mmBridgeSet@@QAEXXZ
    0x4C2CA0 | private: void __thiscall mmBridgeSet::CalculateDistToPlayer2(void) | ?CalculateDistToPlayer2@mmBridgeSet@@AAEXXZ
    0x4C2D80 | private: void __thiscall mmBridgeSet::CalculateAudioPanning(void) | ?CalculateAudioPanning@mmBridgeSet@@AAEXXZ
    0x4C2DD0 | private: float __thiscall mmBridgeSet::CalculateDoppler(float) | ?CalculateDoppler@mmBridgeSet@@AAEMM@Z
    0x4C2E00 | public: void __thiscall mmBridgeSet::UnAssignSounds(void) | ?UnAssignSounds@mmBridgeSet@@QAEXXZ
    0x4C2E20 | public: void __thiscall mmBridgeSet::SetSoundPtrs(class AudSound *,class AudSound *) | ?SetSoundPtrs@mmBridgeSet@@QAEXPAVAudSound@@0@Z
    0x4C2E80 | private: void __thiscall mmBridgeSet::RampDownBridgeVolume(void) | ?RampDownBridgeVolume@mmBridgeSet@@AAEXXZ
    0x4C3060 | public: virtual class MetaClass * __thiscall mmBridgeSet::GetClass(void) | ?GetClass@mmBridgeSet@@UAEPAVMetaClass@@XZ
    0x4C3070 | public: static void __cdecl mmBridgeMgr::DeclareFields(void) | ?DeclareFields@mmBridgeMgr@@SAXXZ
    0x4C32E0 | public: virtual class MetaClass * __thiscall mmBridgeMgr::GetClass(void) | ?GetClass@mmBridgeMgr@@UAEPAVMetaClass@@XZ
    0x4C3410 | public: virtual void * __thiscall mmBridgeSet::`vector deleting destructor'(unsigned int) | ??_EmmBridgeSet@@UAEPAXI@Z
    0x4C3470 | public: virtual void * __thiscall mmBridgeMgr::`vector deleting destructor'(unsigned int) | ??_EmmBridgeMgr@@UAEPAXI@Z
    0x61F370 | const mmBridgeMgr::`vftable' | ??_7mmBridgeMgr@@6B@
    0x61F3B0 | const mmBridgeSet::`vftable' | ??_7mmBridgeSet@@6B@
    0x6420E4 | private: static float mmBridgeSet::s_fAudioMinDistance | ?s_fAudioMinDistance@mmBridgeSet@@0MA
    0x6420E8 | private: static float mmBridgeSet::s_fCloserMinDistMult | ?s_fCloserMinDistMult@mmBridgeSet@@0MA
    0x6420EC | private: static float mmBridgeSet::s_fAudioMaxDistance | ?s_fAudioMaxDistance@mmBridgeSet@@0MA
    0x6420F0 | private: static float mmBridgeSet::s_fAudioVolume | ?s_fAudioVolume@mmBridgeSet@@0MA
    0x705D98 | private: static float mmBridgeSet::s_fAudioAttenuationMult | ?s_fAudioAttenuationMult@mmBridgeSet@@0MA
    0x705DA0 | class MetaClass mmBridgeMgrMetaClass | ?mmBridgeMgrMetaClass@@3VMetaClass@@A
    0x705DD0 | class MetaClass mmBridgeSetMetaClass | ?mmBridgeSetMetaClass@@3VMetaClass@@A
    0x705DFC | protected: static class mmBridgeMgr * mmBridgeMgr::Instance | ?Instance@mmBridgeMgr@@1PAV1@A
*/

#include "arts7/node.h"

class mmBridgeMgr final : public asNode
{
public:
    // ??0mmBridgeMgr@@QAE@XZ
    ARTS_IMPORT mmBridgeMgr();

    // ??_EmmBridgeMgr@@UAEPAXI@Z
    // ??1mmBridgeMgr@@UAE@XZ
    ARTS_IMPORT ~mmBridgeMgr() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmBridgeMgr@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?Cull@mmBridgeMgr@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@mmBridgeMgr@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Init@mmBridgeMgr@@QAEXPADPAVmmInstance@@PAPAV2@H@Z
    ARTS_IMPORT void Init(char* arg1, class mmInstance* arg2, class mmInstance** arg3, i32 arg4);

    // ?Save@mmBridgeMgr@@UAEXXZ
    ARTS_IMPORT void Save() override;

    // ?ToggleDrawLabels@mmBridgeMgr@@QAEXXZ
    ARTS_IMPORT void ToggleDrawLabels();

    // ?DeclareFields@mmBridgeMgr@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

protected:
    // ?Instance@mmBridgeMgr@@1PAV1@A
    ARTS_IMPORT static class mmBridgeMgr* Instance;

    u8 gap20[0x2654];
};

check_size(mmBridgeMgr, 0x2674);

class mmBridgeSet final : public asNode
{
public:
    // ??0mmBridgeSet@@QAE@XZ
    ARTS_IMPORT mmBridgeSet();

    // ??_EmmBridgeSet@@UAEPAXI@Z
    // ??1mmBridgeSet@@UAE@XZ
    ARTS_IMPORT ~mmBridgeSet() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmBridgeSet@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?Cull@mmBridgeSet@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@mmBridgeSet@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Init@mmBridgeSet@@QAEHPADPAVStream@@@Z
    ARTS_IMPORT i32 Init(char* arg1, class Stream* arg2);

    // ?InitTrigger@mmBridgeSet@@QAEXXZ
    ARTS_IMPORT void InitTrigger();

    // ?ReadEntry@mmBridgeSet@@QAEHPAVStream@@H@Z
    ARTS_IMPORT i32 ReadEntry(class Stream* arg1, i32 arg2);

    // ?Reset@mmBridgeSet@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetSoundPtrs@mmBridgeSet@@QAEXPAVAudSound@@0@Z
    ARTS_IMPORT void SetSoundPtrs(class AudSound* arg1, class AudSound* arg2);

    // ?UnAssignSounds@mmBridgeSet@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // ?Update@mmBridgeSet@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateAudio@mmBridgeSet@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // ?DeclareFields@mmBridgeSet@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?CalculateAudioPanning@mmBridgeSet@@AAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // ?CalculateDistToPlayer2@mmBridgeSet@@AAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // ?CalculateDoppler@mmBridgeSet@@AAEMM@Z
    ARTS_IMPORT f32 CalculateDoppler(f32 arg1);

    // ?RampDownBridgeVolume@mmBridgeSet@@AAEXXZ
    ARTS_IMPORT void RampDownBridgeVolume();

    // ?s_fAudioAttenuationMult@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fAudioAttenuationMult;

    // ?s_fAudioMaxDistance@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fAudioMaxDistance;

    // ?s_fAudioMinDistance@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fAudioMinDistance;

    // ?s_fAudioVolume@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fAudioVolume;

    // ?s_fCloserMinDistMult@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fCloserMinDistMult;

    u8 gap20[0x418];
};

check_size(mmBridgeSet, 0x438);
