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

#include "event.h"

/*
    eventq7:eventq

    0x5639F0 | public: __thiscall eqEventQ::eqEventQ(int,int,int) | ??0eqEventQ@@QAE@HHH@Z
    0x563A80 | public: virtual __thiscall eqEventQ::~eqEventQ(void) | ??1eqEventQ@@UAE@XZ
    0x563AF0 | public: virtual void __thiscall eqEventQ::Redraw(void *,int,int,int,int) | ?Redraw@eqEventQ@@UAEXPAXHHHH@Z
    0x563B50 | public: virtual void __thiscall eqEventQ::Refocus(void *,int) | ?Refocus@eqEventQ@@UAEXPAXH@Z
    0x563B90 | public: virtual void __thiscall eqEventQ::Mouse(void *,int,int,int,int,int,int,int) | ?Mouse@eqEventQ@@UAEXPAXHHHHHHH@Z
    0x563C20 | public: virtual void __thiscall eqEventQ::Keyboard(void *,int,int,int,int) | ?Keyboard@eqEventQ@@UAEXPAXHHHH@Z
    0x563C80 | public: virtual void __thiscall eqEventQ::Destroy(void *) | ?Destroy@eqEventQ@@UAEXPAX@Z
    0x563CC0 | public: virtual void __thiscall eqEventQ::Activate(void *,int) | ?Activate@eqEventQ@@UAEXPAXH@Z
    0x563D00 | private: void __thiscall eqEventQ::Queue(union eqEvent &) | ?Queue@eqEventQ@@AAEXAATeqEvent@@@Z
    0x563D40 | public: int __thiscall eqEventQ::Pop(union eqEvent *) | ?Pop@eqEventQ@@QAEHPATeqEvent@@@Z
    0x563DB0 | public: virtual void * __thiscall eqEventQ::`vector deleting destructor'(unsigned int) | ??_EeqEventQ@@UAEPAXI@Z
    0x563DB0 | public: virtual void * __thiscall eqEventQ::`scalar deleting destructor'(unsigned int) | ??_GeqEventQ@@UAEPAXI@Z
    0x621B00 | const eqEventQ::`vftable' | ??_7eqEventQ@@6B@
*/

class eqEventQ : public eqEventMonitor
{
    // const eqEventQ::`vftable' @ 0x621B00

public:
    // 0x5639F0 | ??0eqEventQ@@QAE@HHH@Z
    eqEventQ(i32 arg1, i32 arg2, i32 arg3);

    // 0x563DB0 | ??_GeqEventQ@@UAEPAXI@Z
    // 0x563A80 | ??1eqEventQ@@UAE@XZ
    ~eqEventQ() override;

    // 0x563CC0 | ?Activate@eqEventQ@@UAEXPAXH@Z
    void Activate(void* arg1, i32 arg2) override;

    // 0x563C80 | ?Destroy@eqEventQ@@UAEXPAX@Z
    void Destroy(void* arg1) override;

    // 0x563C20 | ?Keyboard@eqEventQ@@UAEXPAXHHHH@Z
    void Keyboard(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5) override;

    // 0x563B90 | ?Mouse@eqEventQ@@UAEXPAXHHHHHHH@Z
    void Mouse(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8) override;

    // 0x563D40 | ?Pop@eqEventQ@@QAEHPATeqEvent@@@Z
    i32 Pop(union eqEvent* arg1);

    // 0x563AF0 | ?Redraw@eqEventQ@@UAEXPAXHHHH@Z
    void Redraw(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5) override;

    // 0x563B50 | ?Refocus@eqEventQ@@UAEXPAXH@Z
    void Refocus(void* arg1, i32 arg2) override;

private:
    // 0x563D00 | ?Queue@eqEventQ@@AAEXAATeqEvent@@@Z
    void Queue(union eqEvent& arg1);
};

check_size(eqEventQ, 0x2C);
