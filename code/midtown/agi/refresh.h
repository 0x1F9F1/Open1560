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
    agi:refresh

    0x557A20 | public: __thiscall agiRefreshable::agiRefreshable(class agiPipeline *) | ??0agiRefreshable@@QAE@PAVagiPipeline@@@Z
    0x557A60 | protected: virtual __thiscall agiRefreshable::~agiRefreshable(void) | ??1agiRefreshable@@MAE@XZ
    0x557AA0 | public: int __thiscall agiRefreshable::SafeBeginGfx(void) | ?SafeBeginGfx@agiRefreshable@@QAEHXZ
    0x557AD0 | public: virtual void __thiscall agiRefreshable::Restore(void) | ?Restore@agiRefreshable@@UAEXXZ
    0x557AE0 | public: void __thiscall agiRefreshable::AddRef(void) | ?AddRef@agiRefreshable@@QAEXXZ
    0x557B00 | public: int __thiscall agiRefreshable::Release(void) | ?Release@agiRefreshable@@QAEHXZ
    0x557B30 | private: void __thiscall agiRefreshable::ValidatePtr(char *) | ?ValidatePtr@agiRefreshable@@AAEXPAD@Z
    0x557B90 | public: virtual char * __thiscall agiRefreshable::GetName(void) | ?GetName@agiRefreshable@@UAEPADXZ
    0x557BA0 | protected: virtual int __thiscall agiRefreshable::IsTexture(void) | ?IsTexture@agiRefreshable@@MAEHXZ
    0x557BB0 | protected: virtual void * __thiscall agiRefreshable::`scalar deleting destructor'(unsigned int) | ??_GagiRefreshable@@MAEPAXI@Z
    0x557BB0 | protected: virtual void * __thiscall agiRefreshable::`vector deleting destructor'(unsigned int) | ??_EagiRefreshable@@MAEPAXI@Z
    0x621648 | const agiRefreshable::`vftable' | ??_7agiRefreshable@@6B@
*/

class agiPipeline;

class agiRefreshable
{
    // const agiRefreshable::`vftable' @ 0x621648

public:
    // 0x557A20 | ??0agiRefreshable@@QAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiRefreshable(class agiPipeline* pipe);

    virtual void EndGfx() = 0;

    // 0x557AD0 | ?Restore@agiRefreshable@@UAEXXZ
    ARTS_EXPORT virtual void Restore();

    // 0x557B90 | ?GetName@agiRefreshable@@UAEPADXZ
    ARTS_EXPORT virtual const char* GetName();

protected:
    // 0x557BB0 | ??_EagiRefreshable@@MAEPAXI@Z
    // 0x557BB0 | ??_GagiRefreshable@@MAEPAXI@Z
    // 0x557A60 | ??1agiRefreshable@@MAE@XZ
    ARTS_EXPORT virtual ~agiRefreshable();

public:
    virtual i32 BeginGfx() = 0;

    // 0x557AE0 | ?AddRef@agiRefreshable@@QAEXXZ
    ARTS_EXPORT void AddRef();

    // 0x557B00 | ?Release@agiRefreshable@@QAEHXZ
    ARTS_EXPORT i32 Release();

    // 0x557AA0 | ?SafeBeginGfx@agiRefreshable@@QAEHXZ
    ARTS_EXPORT i32 SafeBeginGfx();

    agiPipeline* Pipe() const
    {
        return pipe_;
    }

protected:
    // 0x557BA0 | ?IsTexture@agiRefreshable@@MAEHXZ
    ARTS_EXPORT virtual b32 IsTexture();

private:
    // 0x557B30 | ?ValidatePtr@agiRefreshable@@AAEXPAD@Z
    ARTS_EXPORT void ValidatePtr(const char* reason);

    agiRefreshable* prev_ {nullptr};
    agiRefreshable* next_ {nullptr};

    agiPipeline* pipe_ {nullptr};

    // 0 | Not Started
    // 1 | Started 1
    // 2 | Started 2
    u32 state_ {0};

    u32 ref_count_ {1};

    friend class agiPipeline;
};

check_size(agiRefreshable, 0x18);
