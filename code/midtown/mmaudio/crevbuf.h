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
    mmaudio:crevbuf

    0x4F4AA0 | public: __thiscall CReverbBuffer::CReverbBuffer(struct IDirectSound3DBuffer *) | ??0CReverbBuffer@@QAE@PAUIDirectSound3DBuffer@@@Z
    0x4F4AF0 | public: __thiscall CReverbBuffer::~CReverbBuffer(void) | ??1CReverbBuffer@@QAE@XZ
    0x4F4B00 | public: int __thiscall CReverbBuffer::PropertySetOk(void) | ?PropertySetOk@CReverbBuffer@@QAEHXZ
    0x4F4B10 | private: int __thiscall CReverbBuffer::QueryProperty(unsigned long) | ?QueryProperty@CReverbBuffer@@AAEHK@Z
    0x4F4B60 | public: void __thiscall CReverbBuffer::SetReverbMix(float) | ?SetReverbMix@CReverbBuffer@@QAEXM@Z
    0x4F4B80 | public: void __thiscall CReverbBuffer::SetAll(struct EAXBUFFER_REVERBPROPERTIES *) | ?SetAll@CReverbBuffer@@QAEXPAUEAXBUFFER_REVERBPROPERTIES@@@Z
    0x4F4BA0 | public: float __thiscall CReverbBuffer::GetReverbMix(void) | ?GetReverbMix@CReverbBuffer@@QAEMXZ
    0x4F4BE0 | public: void __thiscall CReverbBuffer::GetAll(struct EAXBUFFER_REVERBPROPERTIES *) | ?GetAll@CReverbBuffer@@QAEXPAUEAXBUFFER_REVERBPROPERTIES@@@Z
*/

class CReverbBuffer
{
public:
    // 0x4F4AA0 | ??0CReverbBuffer@@QAE@PAUIDirectSound3DBuffer@@@Z
    ARTS_IMPORT CReverbBuffer(struct IDirectSound3DBuffer* arg1);

    // 0x4F4AF0 | ??1CReverbBuffer@@QAE@XZ
    ARTS_IMPORT ~CReverbBuffer();

    // 0x4F4BE0 | ?GetAll@CReverbBuffer@@QAEXPAUEAXBUFFER_REVERBPROPERTIES@@@Z | unused
    ARTS_IMPORT void GetAll(struct EAXBUFFER_REVERBPROPERTIES* arg1);

    // 0x4F4BA0 | ?GetReverbMix@CReverbBuffer@@QAEMXZ
    ARTS_IMPORT f32 GetReverbMix();

    // 0x4F4B00 | ?PropertySetOk@CReverbBuffer@@QAEHXZ
    ARTS_IMPORT i32 PropertySetOk();

    // 0x4F4B80 | ?SetAll@CReverbBuffer@@QAEXPAUEAXBUFFER_REVERBPROPERTIES@@@Z | unused
    ARTS_IMPORT void SetAll(struct EAXBUFFER_REVERBPROPERTIES* arg1);

    // 0x4F4B60 | ?SetReverbMix@CReverbBuffer@@QAEXM@Z
    ARTS_IMPORT void SetReverbMix(f32 arg1);

private:
    // 0x4F4B10 | ?QueryProperty@CReverbBuffer@@AAEHK@Z
    ARTS_IMPORT i32 QueryProperty(u32 arg1);

    u8 gap0[0x4];
};

check_size(CReverbBuffer, 0x4);
