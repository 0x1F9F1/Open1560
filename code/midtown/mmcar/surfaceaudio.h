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

struct mmSurfaceAudio
{
public:
    // 0x487110 | ??0mmSurfaceAudio@@QAE@PAVmmCarSim@@PAVVector3@@@Z
    mmSurfaceAudio(class mmCarSim* arg1, class Vector3* arg2);

    // 0x487510 | ??1mmSurfaceAudio@@QAE@XZ
    ~mmSurfaceAudio();

    // 0x487B00 | ?DisableSurface@mmSurfaceAudio@@QAEXXZ
    void DisableSurface();

    // 0x487740 | ?EchoOff@mmSurfaceAudio@@QAEXPAVmmCarSim@@@Z
    void EchoOff(class mmCarSim* arg1);

    // 0x487630 | ?EchoOn@mmSurfaceAudio@@QAEXPAVmmCarSim@@M@Z
    void EchoOn(class mmCarSim* arg1, f32 arg2);

    // 0x4877F0 | ?EnableAir@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    i32 EnableAir(class mmCarSim* arg1);

    // 0x487970 | ?EnableSurface@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    i32 EnableSurface(class mmCarSim* arg1);

    // 0x4878C0 | ?EnableSuspension@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    i32 EnableSuspension(class mmCarSim* arg1);

    // 0x487580 | ?EnableTireWobble@mmSurfaceAudio@@QAEXXZ
    void EnableTireWobble();

    // 0x488E90 | ?OnTwoWheels@mmSurfaceAudio@@QAEFXZ
    i16 OnTwoWheels();

    // 0x487B20 | ?SetWheelPointers@mmSurfaceAudio@@QAEXPAVmmWheel@@000@Z
    void SetWheelPointers(class mmWheel* arg1, class mmWheel* arg2, class mmWheel* arg3, class mmWheel* arg4);

    // 0x488F20 | ?SetWobblePitch@mmSurfaceAudio@@QAEXMM@Z
    void SetWobblePitch(f32 arg1, f32 arg2);

    // 0x488F40 | ?SetWobbleVol@mmSurfaceAudio@@QAEXMM@Z
    void SetWobbleVol(f32 arg1, f32 arg2);

    // 0x487B50 | ?Update@mmSurfaceAudio@@QAEXM@Z
    void Update(f32 arg1);

    // 0x4882C0 | ?UpdateSkidClear@mmSurfaceAudio@@QAEXM@Z
    void UpdateSkidClear(f32 arg1);

    // 0x488680 | ?UpdateSkidRain@mmSurfaceAudio@@QAEXM@Z
    void UpdateSkidRain(f32 arg1);

    // 0x488A50 | ?UpdateSkidSnow@mmSurfaceAudio@@QAEXM@Z
    void UpdateSkidSnow(f32 arg1);

    // 0x487D30 | ?UpdateSurface@mmSurfaceAudio@@QAEXM@Z
    void UpdateSurface(f32 arg1);

    // 0x487FB0 | ?UpdateSurfaceSnow@mmSurfaceAudio@@QAEXM@Z
    void UpdateSurfaceSnow(f32 arg1);

    // 0x488D80 | ?UpdateSuspension@mmSurfaceAudio@@QAEXXZ
    void UpdateSuspension();

    // 0x487BE0 | ?UpdateTireWobble@mmSurfaceAudio@@QAEXXZ
    void UpdateTireWobble();

private:
    // 0x488190 | ?PlayCobble@mmSurfaceAudio@@AAEXM@Z
    void PlayCobble(f32 arg1);
};

check_size(mmSurfaceAudio, 0xAC);
