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

class mmCarSim;
class mmWheel;

class mmSurfaceAudio
{
public:
    // ??0mmSurfaceAudio@@QAE@PAVmmCarSim@@PAVVector3@@@Z
    ARTS_IMPORT mmSurfaceAudio(mmCarSim* arg1, Vector3* arg2);

    // ??1mmSurfaceAudio@@QAE@XZ
    ARTS_IMPORT ~mmSurfaceAudio();

    // ?EchoOff@mmSurfaceAudio@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void EchoOff(mmCarSim* arg1);

    // ?EchoOn@mmSurfaceAudio@@QAEXPAVmmCarSim@@M@Z
    ARTS_IMPORT void EchoOn(mmCarSim* arg1, f32 arg2);

    // ?EnableSurface@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    ARTS_IMPORT i32 EnableSurface(mmCarSim* arg1);

    // ?EnableSuspension@mmSurfaceAudio@@QAEHPAVmmCarSim@@@Z
    ARTS_IMPORT i32 EnableSuspension(mmCarSim* arg1);

    // ?EnableTireWobble@mmSurfaceAudio@@QAEXXZ
    ARTS_IMPORT void EnableTireWobble();

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
