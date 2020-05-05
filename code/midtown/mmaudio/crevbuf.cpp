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

define_dummy_symbol(mmaudio_crevbuf);

#include "crevbuf.h"

CReverbBuffer::CReverbBuffer(struct IDirectSound3DBuffer* arg1)
{
    unimplemented(arg1);
}

CReverbBuffer::~CReverbBuffer()
{
    unimplemented();
}

void CReverbBuffer::GetAll(struct EAXBUFFER_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<void, CReverbBuffer*, struct EAXBUFFER_REVERBPROPERTIES*>>(0xF4BE0_Offset, this, arg1);
}

f32 CReverbBuffer::GetReverbMix()
{
    return stub<thiscall_t<f32, CReverbBuffer*>>(0xF4BA0_Offset, this);
}

i32 CReverbBuffer::PropertySetOk()
{
    return stub<thiscall_t<i32, CReverbBuffer*>>(0xF4B00_Offset, this);
}

void CReverbBuffer::SetAll(struct EAXBUFFER_REVERBPROPERTIES* arg1)
{
    return stub<thiscall_t<void, CReverbBuffer*, struct EAXBUFFER_REVERBPROPERTIES*>>(0xF4B80_Offset, this, arg1);
}

void CReverbBuffer::SetReverbMix(f32 arg1)
{
    return stub<thiscall_t<void, CReverbBuffer*, f32>>(0xF4B60_Offset, this, arg1);
}

i32 CReverbBuffer::QueryProperty(u32 arg1)
{
    return stub<thiscall_t<i32, CReverbBuffer*, u32>>(0xF4B10_Offset, this, arg1);
}
