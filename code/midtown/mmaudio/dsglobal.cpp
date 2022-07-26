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

define_dummy_symbol(mmaudio_dsglobal);

#include "dsglobal.h"

#include <dsconf.h>

#include "stream/stream.h"

typedef HRESULT(WINAPI* LPFNDLLGETCLASSOBJECT)(const CLSID&, const IID&, void**);

static bool DirectSoundPrivateCreate(LPKSPROPERTYSET* ppKsPropertySet)
{
    LPFNDLLGETCLASSOBJECT pfnDllGetClassObject =
        (LPFNDLLGETCLASSOBJECT) GetProcAddress(GetModuleHandleA("DSOUND"), "DllGetClassObject");

    if (!pfnDllGetClassObject)
        return false;

    HRESULT hr = DS_OK;
    LPCLASSFACTORY pClassFactory = NULL;
    LPKSPROPERTYSET pKsPropertySet = NULL;

    if (hr = pfnDllGetClassObject(CLSID_DirectSoundPrivate, IID_IClassFactory, (LPVOID*) &pClassFactory); SUCCEEDED(hr))
        hr = pClassFactory->CreateInstance(NULL, IID_IKsPropertySet, (LPVOID*) &pKsPropertySet);

    if (pClassFactory)
        pClassFactory->Release();

    if (SUCCEEDED(hr))
        *ppKsPropertySet = pKsPropertySet;
    else if (pKsPropertySet)
        pKsPropertySet->Release();

    return true;
}

static bool GetInfoFromDSoundGUID(GUID i_sGUID, u32& dwWaveID)
{
    BOOL success = FALSE;

    if (LPKSPROPERTYSET pKsPropertySet = NULL; DirectSoundPrivateCreate(&pKsPropertySet))
    {
        DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA sDirectSoundDeviceDescription {};
        sDirectSoundDeviceDescription.DeviceId = i_sGUID;
        sDirectSoundDeviceDescription.DataFlow = DIRECTSOUNDDEVICE_DATAFLOW_RENDER;

        ULONG ulBytesReturned = 0;

        if (SUCCEEDED(pKsPropertySet->Get(DSPROPSETID_DirectSoundDevice, DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION, NULL,
                0, &sDirectSoundDeviceDescription, sizeof(sDirectSoundDeviceDescription), &ulBytesReturned)) &&
            ulBytesReturned)
        {
            PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA psDirectSoundDeviceDescription =
                (PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA) new BYTE[ulBytesReturned];

            *psDirectSoundDeviceDescription = sDirectSoundDeviceDescription;

            if (SUCCEEDED(pKsPropertySet->Get(DSPROPSETID_DirectSoundDevice, DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION,
                    NULL, 0, psDirectSoundDeviceDescription, ulBytesReturned, &ulBytesReturned)))
            {
                dwWaveID = psDirectSoundDeviceDescription->WaveDeviceId;
                success = dwWaveID;
            }

            delete[] psDirectSoundDeviceDescription;
        }

        pKsPropertySet->Release();
    }

    return success;
}

char** DSGlobal::GetDeviceNames()
{
    char** results = new char*[NumDevices];

    for (u32 i = 0; i < NumDevices; ++i)
        results[i] = DevicesArray[i]->pszDeviceDesc;

    return results;
}

bool DSGlobal::GetWaveDeviceID(u32 device_num, u32& wave_id)
{
    if (device_num < NumDevices)
        return GetInfoFromDSoundGUID(DevicesArray[device_num]->guDevice, wave_id);

    return false;
}

const char* DSGlobal::GetDeviceName(u32 index)
{
    return (index < NumDevices) ? DevicesArray[index]->pszDeviceDesc : nullptr;
}

static mem::cmd_param PARAM_cdid {"cdid"};

u8 DSGlobal::CheckCDFile(aconst char* file_name)
{
    if (!std::strcmp(file_name, "cdid.txt"))
    {
        if (bool cdid = false; PARAM_cdid.get(cdid))
            return cdid;
    }

    for (char letter = 'A'; letter <= 'Z'; ++letter)
    {
        char path[200];
        arts_strcpy(path, "A:\\");
        path[0] = letter;

        if (GetDriveTypeA(path) == DRIVE_CDROM)
        {
            arts_strcat(path, file_name);

            if (Ptr<Stream> stream {arts_fopen(path, "r")})
                return true;
        }
    }

    return false;
}

hook_func(INIT_main,
    [] { create_patch("DSGlobal::InitPrimarySoundBuffer", "Better device priority", 0x4EFC2B, "\x7C\x09", 2); });
