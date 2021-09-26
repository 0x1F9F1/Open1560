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
    mmcityinfo:playercfg

    0x4CDA00 | public: __thiscall mmPlayerConfig::mmPlayerConfig(void) | ??0mmPlayerConfig@@QAE@XZ
    0x4CDAA0 | public: virtual __thiscall mmPlayerConfig::~mmPlayerConfig(void) | ??1mmPlayerConfig@@UAE@XZ
    0x4CDB10 | public: void __thiscall mmPlayerConfig::operator=(class mmPlayerConfig &) | ??4mmPlayerConfig@@QAEXAAV0@@Z
    0x4CDC90 | public: int __thiscall mmPlayerConfig::Load(char *) | ?Load@mmPlayerConfig@@QAEHPAD@Z
    0x4CDD60 | public: int __thiscall mmPlayerConfig::LoadBinary(char *) | ?LoadBinary@mmPlayerConfig@@QAEHPAD@Z
    0x4CDFE0 | public: int __thiscall mmPlayerConfig::SaveBinary(char *) | ?SaveBinary@mmPlayerConfig@@QAEHPAD@Z
    0x4CE230 | public: void __thiscall mmPlayerConfig::SetDefaults(void) | ?SetDefaults@mmPlayerConfig@@QAEXXZ
    0x4CE240 | public: int __thiscall mmPlayerConfig::Save(char *,int) | ?Save@mmPlayerConfig@@QAEHPADH@Z
    0x4CE2E0 | public: void __thiscall mmPlayerConfig::SetAudio(void) | ?SetAudio@mmPlayerConfig@@QAEXXZ
    0x4CE450 | public: void __thiscall mmPlayerConfig::SetControls(void) | ?SetControls@mmPlayerConfig@@QAEXXZ
    0x4CE540 | public: void __thiscall mmGfxCFG::Get(void) | ?Get@mmGfxCFG@@QAEXXZ
    0x4CE5B0 | public: void __thiscall mmGfxCFG::Set(void) | ?Set@mmGfxCFG@@QAEXXZ
    0x4CE630 | public: void __thiscall mmPlayerConfig::GetGraphics(void) | ?GetGraphics@mmPlayerConfig@@QAEXXZ
    0x4CE640 | public: void __thiscall mmPlayerConfig::SetGraphics(void) | ?SetGraphics@mmPlayerConfig@@QAEXXZ
    0x4CE650 | public: void __thiscall mmPlayerConfig::GetAudio(void) | ?GetAudio@mmPlayerConfig@@QAEXXZ
    0x4CE6C0 | public: void __thiscall mmPlayerConfig::GetControls(void) | ?GetControls@mmPlayerConfig@@QAEXXZ
    0x4CE7A0 | public: void __thiscall mmPlayerConfig::GetViewSettings(void) | ?GetViewSettings@mmPlayerConfig@@QAEXXZ
    0x4CE7D0 | public: void __thiscall mmPlayerConfig::SetViewSettings(void) | ?SetViewSettings@mmPlayerConfig@@QAEXXZ
    0x4CE800 | public: void __thiscall mmPlayerConfig::DefaultAudio(void) | ?DefaultAudio@mmPlayerConfig@@QAEXXZ
    0x4CE910 | public: void __thiscall mmPlayerConfig::DefaultControls(void) | ?DefaultControls@mmPlayerConfig@@QAEXXZ
    0x4CE970 | public: void __thiscall mmPlayerConfig::DefaultViewSettings(void) | ?DefaultViewSettings@mmPlayerConfig@@QAEXXZ
    0x4CE9B0 | public: void __thiscall mmPlayerConfig::Reset(void) | ?Reset@mmPlayerConfig@@QAEXXZ
    0x4CE9C0 | public: void __thiscall mmPlayerConfig::DefaultGraphics(void) | ?DefaultGraphics@mmPlayerConfig@@QAEXXZ
    0x4CE9E0 | public: static void __cdecl mmPlayerConfig::DeclareFields(void) | ?DeclareFields@mmPlayerConfig@@SAXXZ
    0x4CEE70 | public: virtual class MetaClass * __thiscall mmPlayerConfig::GetClass(void) | ?GetClass@mmPlayerConfig@@UAEPAVMetaClass@@XZ
    0x4CEE80 | public: __thiscall mmCtrlCFG::~mmCtrlCFG(void) | ??1mmCtrlCFG@@QAE@XZ
    0x4CEEA0 | public: virtual void * __thiscall mmPlayerConfig::`vector deleting destructor'(unsigned int) | ??_EmmPlayerConfig@@UAEPAXI@Z
    0x61F8E8 | const mmPlayerConfig::`vftable' | ??_7mmPlayerConfig@@6B@
    0x708520 | class MetaClass mmPlayerConfigMetaClass | ?mmPlayerConfigMetaClass@@3VMetaClass@@A
*/

#include "infobase.h"

class mmPlayerConfig final : public mmInfoBase
{
public:
    // ??0mmPlayerConfig@@QAE@XZ
    ARTS_IMPORT mmPlayerConfig();

    // ??_EmmPlayerConfig@@UAEPAXI@Z
    // ??1mmPlayerConfig@@UAE@XZ
    ARTS_IMPORT ~mmPlayerConfig() override;

    // ??4mmPlayerConfig@@QAEXAAV0@@Z | unused
    ARTS_IMPORT void operator=(mmPlayerConfig& arg1);

    // ?DefaultAudio@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void DefaultAudio();

    // ?DefaultControls@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void DefaultControls();

    // ?DefaultGraphics@mmPlayerConfig@@QAEXXZ | unused
    ARTS_IMPORT void DefaultGraphics();

    // ?DefaultViewSettings@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void DefaultViewSettings();

    // ?GetAudio@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void GetAudio();

    // ?GetClass@mmPlayerConfig@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetControls@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void GetControls();

    // ?GetGraphics@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void GetGraphics();

    // ?GetViewSettings@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void GetViewSettings();

    // ?Load@mmPlayerConfig@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // ?LoadBinary@mmPlayerConfig@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadBinary(char* arg1);

    // ?Reset@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?Save@mmPlayerConfig@@QAEHPADH@Z
    ARTS_IMPORT b32 Save(char* path, b32 binary);

    // ?SaveBinary@mmPlayerConfig@@QAEHPAD@Z
    ARTS_IMPORT i32 SaveBinary(char* arg1);

    // ?SetAudio@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void SetAudio();

    // ?SetControls@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void SetControls();

    // ?SetDefaults@mmPlayerConfig@@QAEXXZ | unused
    ARTS_IMPORT void SetDefaults();

    // ?SetGraphics@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void SetGraphics();

    // ?SetViewSettings@mmPlayerConfig@@QAEXXZ
    ARTS_IMPORT void SetViewSettings();

    // ?DeclareFields@mmPlayerConfig@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    alignas(8) u8 gap88[0x6DA8];
};

check_size(mmPlayerConfig, 0x6E30);

struct mmGfxCFG
{
public:
    // ?Get@mmGfxCFG@@QAEXXZ
    ARTS_IMPORT void Get();

    // ?Set@mmGfxCFG@@QAEXXZ
    ARTS_IMPORT void Set();

    u8 gap0[0x34];
};

check_size(mmGfxCFG, 0x34);

struct mmCtrlCFG
{
public:
    // ??1mmCtrlCFG@@QAE@XZ | inline
    ARTS_IMPORT ~mmCtrlCFG();

    u8 gap0[0x6C80];
};

check_size(mmCtrlCFG, 0x6C80);
