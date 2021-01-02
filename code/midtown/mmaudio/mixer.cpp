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

define_dummy_symbol(mmaudio_mixer);

#include "mixer.h"

#include "manager.h"
#include <mmsystem.h>

void MixerCTL::RefreshAll(ulong /*arg1*/)
{}

void MixerCTL::SetDeviceNum(u32 device_num)
{
    Ptr<char* []> device_names { AUDMGRPTR->GetDeviceNames() };
    char* device_name = device_names[device_num];

    UINT num_mixers = mixerGetNumDevs();

    for (UINT mixer_id = 0; mixer_id < num_mixers; ++mixer_id)
    {
        if (MIXERCAPSA mxcaps; mixerGetDevCapsA(mixer_id, &mxcaps, sizeof(mxcaps)) == MMSYSERR_NOERROR)
        {
            if (std::strncmp(mxcaps.szPname, device_name, 31) == 0)
            {
                DeviceId = mixer_id;

                return;
            }
        }
    }

    Errorf("MixerCTL::SetDeviceNum: Couldn't find mixer for '%s' (%u)", device_name, device_num);

    // Just hope for the best if it's a valid mixer ID
    DeviceId = (device_num < num_mixers) ? device_num : 0;
}

LRESULT MixerCTL::WindowProc(HWND /*hwnd*/, UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
    return 0;
}

run_once([] {
    for (mem::pointer address : {0x4EE463, 0x4EE697, 0x4EE9A3})
    {
        // The code writes to the first 2 channels, even when there are less.
        // operator new(4 * pmxl.cChannels) -> operator new(4 * (pmxl.cChannels + 2))
        create_patch("MixerCTL", "Fix paDetails allocation", address + 3, "\x08", 1);
    }

    create_patch("AudioOptions::AudioOptions", "Fix Device Name Truncation", 0x49C889,
        "\x83\xC4\x0C\x52\x90\x90\x90\x90\x90\x90\x90\x90", 12);

    create_patch(
        "AudioOptions::AudioOptions", "Fix Device Name Truncation", 0x49C7ED, "\x89\xD7\x90\x90\x90\x90\x90\x90", 8);

    create_patch("AudioOptions::AudioOptions", "Fix Device Name Truncation", 0x49C846, "\x89\xD6\x89\xCA\x90", 5);
});