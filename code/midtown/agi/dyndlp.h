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
    agi:dyndlp

    0x55E5B0 | public: __thiscall DynamicDLP::DynamicDLP(int) | ??0DynamicDLP@@QAE@H@Z
    0x55E5E0 | protected: virtual __thiscall DynamicDLP::~DynamicDLP(void) | ??1DynamicDLP@@MAE@XZ
    0x55E600 | public: int __thiscall DynamicDLP::Release(void) | ?Release@DynamicDLP@@QAEHXZ
    0x55E620 | public: int __thiscall DynamicDLP::InitOffsets(class DLP *,char *) | ?InitOffsets@DynamicDLP@@QAEHPAVDLP@@PAD@Z
    0x55E880 | protected: virtual void * __thiscall DynamicDLP::`scalar deleting destructor'(unsigned int) | ??_GDynamicDLP@@MAEPAXI@Z
    0x55E880 | protected: virtual void * __thiscall DynamicDLP::`vector deleting destructor'(unsigned int) | ??_EDynamicDLP@@MAEPAXI@Z
    0x6218D0 | const DynamicDLP::`vftable' | ??_7DynamicDLP@@6B@
*/

class DLP;

class DynamicDLP
{
public:
    // ??0DynamicDLP@@QAE@H@Z
    ARTS_IMPORT DynamicDLP(i32 arg1);

protected:
    // ??_EDynamicDLP@@MAEPAXI@Z
    // ??_GDynamicDLP@@MAEPAXI@Z
    // ??1DynamicDLP@@MAE@XZ
    ARTS_IMPORT virtual ~DynamicDLP();

public:
    virtual i32 Init(char* arg1) = 0;

    virtual void Lock() = 0;

    virtual void Unlock() = 0;

    virtual void SetTexture(i16 arg1) = 0;

    // ?InitOffsets@DynamicDLP@@QAEHPAVDLP@@PAD@Z
    ARTS_IMPORT i32 InitOffsets(DLP* arg1, char* arg2);

    // ?Release@DynamicDLP@@QAEHXZ | unused
    ARTS_IMPORT i32 Release();

    u8 gap4[0x20];
};

check_size(DynamicDLP, 0x24);
