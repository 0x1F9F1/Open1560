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

#include "dsglobal.h"

void MixerCTL::RefreshAll(ulong /*arg1*/)
{}

void MixerCTL::SetDeviceNum(u32 device_num)
{
    u32 wave_id = 0;

    if (!DSGlobalPtr || !DSGlobalPtr->GetWaveDeviceID(device_num, wave_id))
    {
        Errorf("MixerCTL::SetDeviceNum: Couldn't find mixer for device #%u", device_num);

        // Just hope for the best if it's a valid mixer ID
        if (device_num < mixerGetNumDevs())
            wave_id = device_num;
    }

    DeviceId = wave_id;
}

const char* MixerCTL::GetErrorMessage(ulong error)
{
    // FIXME: These strings as used as the format strings when calling Errorf

    switch (error)
    {
        // clang-format off
        case MMSYSERR_NOERROR:      return "MMSYSERR_NOERROR";
        case MMSYSERR_ERROR:        return "MMSYSERR_ERROR";
        case MMSYSERR_BADDEVICEID:  return "MMSYSERR_BADDEVICEID The uMxId parameter specifies an invalid device identifier.";
        case MMSYSERR_NOTENABLED:   return "MMSYSERR_NOTENABLED";
        case MMSYSERR_ALLOCATED:    return "MMSYSERR_ALLOCATED The specified resource is already allocated by the maximum number of clients possible.";
        case MMSYSERR_INVALHANDLE:  return "MMSYSERR_INVALHANDLE The uMxId parameter specifies an invalid handle.";
        case MMSYSERR_NODRIVER:     return "MMSYSERR_NODRIVER No mixer device is available for the object specified by uMxId. Note that the location referenced by uMxId will also contain the value 1. ";
        case MMSYSERR_NOMEM:        return "MMSYSERR_NOMEM Error in MixerCTL::GetWaveBalance() Unable to allocate or lock memory";
        case MMSYSERR_NOTSUPPORTED: return "MMSYSERR_NOTSUPPORTED Error in MixerCTL::GetWaveBalance() Function isn't supported.";
        case MMSYSERR_BADERRNUM:    return "MMSYSERR_BADERRNUM";
        case MMSYSERR_INVALFLAG:    return "MMSYSERR_INVALFLAG One or more flags are invalid.";
        case MMSYSERR_INVALPARAM:   return "MMSYSERR_INVALPARAM One or more parameters are invalid.";
        case MMSYSERR_HANDLEBUSY:   return "MMSYSERR_HANDLEBUSY";
        case MMSYSERR_INVALIDALIAS: return "MMSYSERR_INVALIDALIAS";
        case MMSYSERR_BADDB:        return "MMSYSERR_BADDB";
        case MMSYSERR_KEYNOTFOUND:  return "MMSYSERR_KEYNOTFOUND";
        case MMSYSERR_READERROR:    return "MMSYSERR_READERROR";
        case MMSYSERR_WRITEERROR:   return "MMSYSERR_WRITEERROR";
        case MMSYSERR_DELETEERROR:  return "MMSYSERR_DELETEERROR";
        case MMSYSERR_VALNOTFOUND:  return "MMSYSERR_VALNOTFOUND";
        case MMSYSERR_NODRIVERCB:   return "MMSYSERR_NODRIVERCB";
        case MMSYSERR_MOREDATA:     return "MMSYSERR_MOREDATA";

        case MIXERR_INVALLINE:      return "MIXERR_INVALLINE The audio line reference is invalid.";
        case MIXERR_INVALCONTROL:   return "MIXERR_INVALCONTROL";
        case MIXERR_INVALVALUE:     return "MIXERR_INVALVALUE";

        default:                    return "Unknown Mixer Error";
        // clang-forat on
    }
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
