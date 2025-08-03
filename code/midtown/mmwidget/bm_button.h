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

#include "widget.h"

class agiBitmap;
class AudSound;

class UIBMButton final : public uiWidget
{
public:
    // ??0UIBMButton@@QAE@XZ
    ARTS_IMPORT UIBMButton();

    // ??1UIBMButton@@UAE@XZ
    ARTS_IMPORT ~UIBMButton() override;

    // ?Action@UIBMButton@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?CreateDummyBitmap@UIBMButton@@QAEPAVagiBitmap@@XZ
    ARTS_IMPORT agiBitmap* CreateDummyBitmap();

    // ?Cull@UIBMButton@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Disable@UIBMButton@@UAEXXZ | inline
    ARTS_IMPORT void Disable() override;

    // ?DoToggle@UIBMButton@@QAEXXZ
    ARTS_IMPORT void DoToggle();

    // ?Enable@UIBMButton@@UAEXXZ | inline
    ARTS_IMPORT void Enable() override;

    // ?GetClass@UIBMButton@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetDiv@UIBMButton@@QAEHXZ
    ARTS_IMPORT i32 GetDiv();

    // ?GetHitArea@UIBMButton@@QAEXAAM0@Z
    ARTS_IMPORT void GetHitArea(f32& arg1, f32& arg2);

    // ?GetScreenHeight@UIBMButton@@UAEMXZ
    ARTS_IMPORT f32 GetScreenHeight() override;

    // ?Init@UIBMButton@@QAEXPADMMHHPAHHHPAULocString@@VCallback@@3@Z
    ARTS_IMPORT void Init(char* arg1, f32 arg2, f32 arg3, i32 arg4, i32 arg5, i32* arg6, i32 arg7, i32 arg8,
        LocString* arg9, Callback arg10, Callback arg11);

    // ?Kill@UIBMButton@@QAEXXZ
    ARTS_IMPORT void Kill();

    // ?LoadBitmap@UIBMButton@@QAEXPAD@Z
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // ?MexOff@UIBMButton@@QAEXXZ
    ARTS_IMPORT void MexOff();

    // ?MexOn@UIBMButton@@QAEXXZ
    ARTS_IMPORT void MexOn();

    // ?ReturnDescription@UIBMButton@@UAEPADXZ
    ARTS_IMPORT char* ReturnDescription() override;

    // ?SetPosition@UIBMButton@@UAEXMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2) override;

    // ?Switch@UIBMButton@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Unkill@UIBMButton@@QAEXXZ
    ARTS_IMPORT void Unkill();

    // ?Update@UIBMButton@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@UIBMButton@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?GetSize@UIBMButton@@AAEXXZ
    ARTS_IMPORT void GetSize();

    // ?PlaySound@UIBMButton@@AAEXXZ
    ARTS_IMPORT void PlaySound();

    // ?AllocateSounds@UIBMButton@@CAXXZ
    ARTS_IMPORT static void AllocateSounds();

    // ?s_pSound@UIBMButton@@0PAVAudSound@@A
    ARTS_IMPORT static AudSound* s_pSound;

    u8 gap74[0x7C];
};

check_size(UIBMButton, 0xF0);
