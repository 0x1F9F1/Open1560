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
    mmcar:impactaudio

    0x484750 | public: __thiscall mmImpactAudio::mmImpactAudio(class mmCarSim *,class Vector3 *) | ??0mmImpactAudio@@QAE@PAVmmCarSim@@PAVVector3@@@Z
    0x484D80 | public: __thiscall mmImpactAudio::~mmImpactAudio(void) | ??1mmImpactAudio@@QAE@XZ
    0x484E60 | public: void __thiscall mmImpactAudio::EchoOn(class mmCarSim *) | ?EchoOn@mmImpactAudio@@QAEXPAVmmCarSim@@@Z
    0x484E70 | public: void __thiscall mmImpactAudio::EchoOff(class mmCarSim *) | ?EchoOff@mmImpactAudio@@QAEXPAVmmCarSim@@@Z
    0x484E80 | public: void __thiscall mmImpactAudio::Play(float,short,float,float) | ?Play@mmImpactAudio@@QAEXMFMM@Z
    0x484F10 | public: void __thiscall mmImpactAudio::PlayWall(float,float,float) | ?PlayWall@mmImpactAudio@@QAEXMMM@Z
    0x485010 | public: void __thiscall mmImpactAudio::PlayCar(float) | ?PlayCar@mmImpactAudio@@QAEXM@Z
    0x485020 | public: void __thiscall mmImpactAudio::GetBangerPtrs(short,class AudSound * *,class AudSound * *) | ?GetBangerPtrs@mmImpactAudio@@QAEXFPAPAVAudSound@@0@Z
    0x4852A0 | public: void __thiscall mmImpactAudio::PlayBanger(float,short) | ?PlayBanger@mmImpactAudio@@QAEXMF@Z
    0x4853E0 | public: void __thiscall mmImpactAudio::SetWallSoftVolumeRange(float,float) | ?SetWallSoftVolumeRange@mmImpactAudio@@QAEXMM@Z
    0x485400 | public: void __thiscall mmImpactAudio::SetWallSoftVolumeMultiplier(float) | ?SetWallSoftVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    0x485420 | public: void __thiscall mmImpactAudio::SetWallMedVolumeRange(float,float) | ?SetWallMedVolumeRange@mmImpactAudio@@QAEXMM@Z
    0x485440 | public: void __thiscall mmImpactAudio::SetWallMedVolumeMultiplier(float) | ?SetWallMedVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    0x485460 | public: void __thiscall mmImpactAudio::SetWallHugeVolumeRange(float,float) | ?SetWallHugeVolumeRange@mmImpactAudio@@QAEXMM@Z
    0x485480 | public: void __thiscall mmImpactAudio::SetWallHugeVolumeMultiplier(float) | ?SetWallHugeVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    0x4854A0 | public: void __thiscall mmImpactAudio::SetBangerVolumeRange(float,float,float,short) | ?SetBangerVolumeRange@mmImpactAudio@@QAEXMMMF@Z
    0x485530 | public: void __thiscall mmImpactAudio::Update(void) | ?Update@mmImpactAudio@@QAEXXZ
*/

struct mmImpactAudio
{
public:
    // 0x484750 | ??0mmImpactAudio@@QAE@PAVmmCarSim@@PAVVector3@@@Z
    ARTS_IMPORT mmImpactAudio(class mmCarSim* arg1, class Vector3* arg2);

    // 0x484D80 | ??1mmImpactAudio@@QAE@XZ
    ARTS_IMPORT ~mmImpactAudio();

    // 0x484E70 | ?EchoOff@mmImpactAudio@@QAEXPAVmmCarSim@@@Z | unused
    ARTS_IMPORT void EchoOff(class mmCarSim* arg1);

    // 0x484E60 | ?EchoOn@mmImpactAudio@@QAEXPAVmmCarSim@@@Z | unused
    ARTS_IMPORT void EchoOn(class mmCarSim* arg1);

    // 0x485020 | ?GetBangerPtrs@mmImpactAudio@@QAEXFPAPAVAudSound@@0@Z
    ARTS_IMPORT void GetBangerPtrs(i16 arg1, class AudSound** arg2, class AudSound** arg3);

    // 0x484E80 | ?Play@mmImpactAudio@@QAEXMFMM@Z
    ARTS_IMPORT void Play(f32 arg1, i16 arg2, f32 arg3, f32 arg4);

    // 0x4852A0 | ?PlayBanger@mmImpactAudio@@QAEXMF@Z
    ARTS_IMPORT void PlayBanger(f32 arg1, i16 arg2);

    // 0x485010 | ?PlayCar@mmImpactAudio@@QAEXM@Z
    ARTS_IMPORT void PlayCar(f32 arg1);

    // 0x484F10 | ?PlayWall@mmImpactAudio@@QAEXMMM@Z
    ARTS_IMPORT void PlayWall(f32 arg1, f32 arg2, f32 arg3);

    // 0x4854A0 | ?SetBangerVolumeRange@mmImpactAudio@@QAEXMMMF@Z
    ARTS_IMPORT void SetBangerVolumeRange(f32 arg1, f32 arg2, f32 arg3, i16 arg4);

    // 0x485480 | ?SetWallHugeVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    ARTS_IMPORT void SetWallHugeVolumeMultiplier(f32 arg1);

    // 0x485460 | ?SetWallHugeVolumeRange@mmImpactAudio@@QAEXMM@Z
    ARTS_IMPORT void SetWallHugeVolumeRange(f32 arg1, f32 arg2);

    // 0x485440 | ?SetWallMedVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    ARTS_IMPORT void SetWallMedVolumeMultiplier(f32 arg1);

    // 0x485420 | ?SetWallMedVolumeRange@mmImpactAudio@@QAEXMM@Z
    ARTS_IMPORT void SetWallMedVolumeRange(f32 arg1, f32 arg2);

    // 0x485400 | ?SetWallSoftVolumeMultiplier@mmImpactAudio@@QAEXM@Z
    ARTS_IMPORT void SetWallSoftVolumeMultiplier(f32 arg1);

    // 0x4853E0 | ?SetWallSoftVolumeRange@mmImpactAudio@@QAEXMM@Z
    ARTS_IMPORT void SetWallSoftVolumeRange(f32 arg1, f32 arg2);

    // 0x485530 | ?Update@mmImpactAudio@@QAEXXZ
    ARTS_IMPORT void Update();

    u8 gap0[0x1EC];
};

check_size(mmImpactAudio, 0x1EC);
