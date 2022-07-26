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
#include "pcwindis/pcwindis.h"

MixerCTL::MixerCTL(HWND window)
    : window_(window)
{
    static u32 msgs[] {MM_WOM_OPEN};

    RegisterMap("Mixer", msgs, ARTS_SSIZE32(msgs), this);
}

MixerCTL::~MixerCTL()
{
    UnregisterMap("Mixer");
}

void MixerCTL::RefreshAll(ulong /*arg1*/)
{}

static bool GetWaveDeviceIDFromName(const char* device_name, u32& wave_id)
{
    for (u32 i = 0, count = mixerGetNumDevs(); i < count; ++i)
    {
        if (MIXERCAPSA mxcaps; mixerGetDevCapsA(i, &mxcaps, sizeof(mxcaps)) == MMSYSERR_NOERROR)
        {
            if (std::strncmp(mxcaps.szPname, device_name, 31) == 0)
            {
                wave_id = i;
                return true;
            }
        }
    }

    return false;
}

void MixerCTL::SetDeviceNum(u32 device_num)
{
    u32 wave_id = 0;
    const char* device_name = nullptr;

    if (DSGlobalPtr)
    {
        device_name = DSGlobalPtr->GetDeviceName(device_num);

        // Try and query the device ID directly from DirectSound
        if (!DSGlobalPtr->GetWaveDeviceID(device_num, wave_id) || (wave_id >= mixerGetNumDevs()))
        {
            // If that fails, try and find the mixer with the matching name
            if (!device_name || !GetWaveDeviceIDFromName(device_name, wave_id))
            {
                // If that fails, default to 0 (which should be the Default Device/Primary Sound Driver)
                wave_id = 0;
            }
        }
    }

    MIXERCAPSA mxcaps;

    Displayf("Using Mixer '%s' (%i) for Device '%s' (%i)",
        (mixerGetDevCapsA(wave_id, &mxcaps, sizeof(mxcaps)) == MMSYSERR_NOERROR) ? mxcaps.szPname : "[INVALID]",
        wave_id, device_name ? device_name : "[INVALID]", device_num);

    device_id_ = wave_id;
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

hook_func(INIT_main, [] {
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