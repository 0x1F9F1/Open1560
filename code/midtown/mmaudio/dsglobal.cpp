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

typedef WINUSERAPI HRESULT(WINAPI* LPFNDLLGETCLASSOBJECT)(const CLSID&, const IID&, void**);

bool DirectSoundPrivateCreate(LPKSPROPERTYSET* ppKsPropertySet)
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

bool GetInfoFromDSoundGUID(GUID i_sGUID, u32& dwWaveID)
{
    BOOL success = FALSE;

    if (LPKSPROPERTYSET pKsPropertySet = NULL; DirectSoundPrivateCreate(&pKsPropertySet))
    {
        DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA sDirectSoundDeviceDescription {};
        sDirectSoundDeviceDescription.DeviceId = i_sGUID;

        ULONG ulBytesReturned = 0;

        pKsPropertySet->Get(DSPROPSETID_DirectSoundDevice, DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION, NULL, 0,
            &sDirectSoundDeviceDescription, sizeof(sDirectSoundDeviceDescription), &ulBytesReturned);

        if (ulBytesReturned)
        {
            PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA psDirectSoundDeviceDescription =
                (PDSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION_DATA) new BYTE[ulBytesReturned];

            *psDirectSoundDeviceDescription = sDirectSoundDeviceDescription;

            if (SUCCEEDED(pKsPropertySet->Get(DSPROPSETID_DirectSoundDevice, DSPROPERTY_DIRECTSOUNDDEVICE_DESCRIPTION,
                    NULL, 0, psDirectSoundDeviceDescription, ulBytesReturned, &ulBytesReturned)))
            {
                dwWaveID = psDirectSoundDeviceDescription->WaveDeviceId;
                success = TRUE;
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
