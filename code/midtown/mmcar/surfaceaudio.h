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
    mmcar:surfaceaudio

    0x487110 | public: __thiscall mmSurfaceAudio::mmSurfaceAudio(class mmCarSim *,class Vector3 *) | ??0mmSurfaceAudio@@QAE@PAVmmCarSim@@PAVVector3@@@Z
    0x487510 | public: __thiscall mmSurfaceAudio::~mmSurfaceAudio(void) | ??1mmSurfaceAudio@@QAE@XZ
    0x487580 | public: void __thiscall mmSurfaceAudio::EnableTireWobble(void) | ?EnableTireWobble@mmSurfaceAudio@@QAEXXZ
    0x487630 | public: void __thiscall mmSurfaceAudio::EchoOn(class mmCarSim *,float) | ?EchoOn@mmSurfaceAudio@@QAEXPAVmmCarSim@@M@Z
    0x487740 | public: void __thiscall mmSurfaceAudio::EchoOff(class mmCarSim *) | ?EchoOff@mmSurfaceAudio@@QAEXPAVmmCarSim@@@Z
    0x4877F0 | public: int __thiscall mmSurfaceAudio::EnableAir(class mmCarSim *) | ?EnableAir@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    0x4878C0 | public: int __thiscall mmSurfaceAudio::EnableSuspension(class mmCarSim *) | ?EnableSuspension@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    0x487970 | public: int __thiscall mmSurfaceAudio::EnableSurface(class mmCarSim *) | ?EnableSurface@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    0x487B00 | public: void __thiscall mmSurfaceAudio::DisableSurface(void) | ?DisableSurface@mmSurfaceAudio@@QAEXXZ
    0x487B20 | public: void __thiscall mmSurfaceAudio::SetWheelPointers(class mmWheel *,class mmWheel *,class mmWheel *,class mmWheel *) | ?SetWheelPointers@mmSurfaceAudio@@QAEXPAVmmWheel@@000@Z
    0x487B50 | public: void __thiscall mmSurfaceAudio::Update(float) | ?Update@mmSurfaceAudio@@QAEXM@Z
    0x487BE0 | public: void __thiscall mmSurfaceAudio::UpdateTireWobble(void) | ?UpdateTireWobble@mmSurfaceAudio@@QAEXXZ
    0x487D30 | public: void __thiscall mmSurfaceAudio::UpdateSurface(float) | ?UpdateSurface@mmSurfaceAudio@@QAEXM@Z
    0x487FB0 | public: void __thiscall mmSurfaceAudio::UpdateSurfaceSnow(float) | ?UpdateSurfaceSnow@mmSurfaceAudio@@QAEXM@Z
    0x488190 | private: void __thiscall mmSurfaceAudio::PlayCobble(float) | ?PlayCobble@mmSurfaceAudio@@AAEXM@Z
    0x4882C0 | public: void __thiscall mmSurfaceAudio::UpdateSkidClear(float) | ?UpdateSkidClear@mmSurfaceAudio@@QAEXM@Z
    0x488680 | public: void __thiscall mmSurfaceAudio::UpdateSkidRain(float) | ?UpdateSkidRain@mmSurfaceAudio@@QAEXM@Z
    0x488A50 | public: void __thiscall mmSurfaceAudio::UpdateSkidSnow(float) | ?UpdateSkidSnow@mmSurfaceAudio@@QAEXM@Z
    0x488D80 | public: void __thiscall mmSurfaceAudio::UpdateSuspension(void) | ?UpdateSuspension@mmSurfaceAudio@@QAEXXZ
    0x488E90 | public: short __thiscall mmSurfaceAudio::OnTwoWheels(void) | ?OnTwoWheels@mmSurfaceAudio@@QAEFXZ
    0x488F20 | public: void __thiscall mmSurfaceAudio::SetWobblePitch(float,float) | ?SetWobblePitch@mmSurfaceAudio@@QAEXMM@Z
    0x488F40 | public: void __thiscall mmSurfaceAudio::SetWobbleVol(float,float) | ?SetWobbleVol@mmSurfaceAudio@@QAEXMM@Z
*/

class mmCarSim;
class mmWheel;

class mmSurfaceAudio
{
public:
    // ??0mmSurfaceAudio@@QAE@PAVmmCarSim@@PAVVector3@@@Z
    ARTS_IMPORT mmSurfaceAudio(mmCarSim* arg1, Vector3* arg2);

    // ??1mmSurfaceAudio@@QAE@XZ
    ARTS_IMPORT ~mmSurfaceAudio();

    // ?DisableSurface@mmSurfaceAudio@@QAEXXZ | unused
    ARTS_IMPORT void DisableSurface();

    // ?EchoOff@mmSurfaceAudio@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void EchoOff(mmCarSim* arg1);

    // ?EchoOn@mmSurfaceAudio@@QAEXPAVmmCarSim@@M@Z
    ARTS_IMPORT void EchoOn(mmCarSim* arg1, f32 arg2);

    // ?EnableAir@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z | unused
    ARTS_IMPORT i32 EnableAir(mmCarSim* arg1);

    // ?EnableSurface@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    ARTS_IMPORT i32 EnableSurface(mmCarSim* arg1);

    // ?EnableSuspension@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    ARTS_IMPORT i32 EnableSuspension(mmCarSim* arg1);

    // ?EnableTireWobble@mmSurfaceAudio@@QAEXXZ
    ARTS_IMPORT void EnableTireWobble();

    // ?OnTwoWheels@mmSurfaceAudio@@QAEFXZ | unused
    ARTS_IMPORT i16 OnTwoWheels();

    // ?SetWheelPointers@mmSurfaceAudio@@QAEXPAVmmWheel@@000@Z
    ARTS_IMPORT void SetWheelPointers(mmWheel* arg1, mmWheel* arg2, mmWheel* arg3, mmWheel* arg4);

    // ?SetWobblePitch@mmSurfaceAudio@@QAEXMM@Z
    ARTS_IMPORT void SetWobblePitch(f32 arg1, f32 arg2);

    // ?SetWobbleVol@mmSurfaceAudio@@QAEXMM@Z
    ARTS_IMPORT void SetWobbleVol(f32 arg1, f32 arg2);

    // ?Update@mmSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void Update(f32 arg1);

    // ?UpdateSkidClear@mmSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSkidClear(f32 arg1);

    // ?UpdateSkidRain@mmSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSkidRain(f32 arg1);

    // ?UpdateSkidSnow@mmSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSkidSnow(f32 arg1);

    // ?UpdateSurface@mmSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSurface(f32 arg1);

    // ?UpdateSurfaceSnow@mmSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSurfaceSnow(f32 arg1);

    // ?UpdateSuspension@mmSurfaceAudio@@QAEXXZ
    ARTS_IMPORT void UpdateSuspension();

    // ?UpdateTireWobble@mmSurfaceAudio@@QAEXXZ
    ARTS_IMPORT void UpdateTireWobble();

private:
    // ?PlayCobble@mmSurfaceAudio@@AAEXM@Z
    ARTS_IMPORT void PlayCobble(f32 arg1);

    u8 gap0[0xAC];
};

check_size(mmSurfaceAudio, 0xAC);
