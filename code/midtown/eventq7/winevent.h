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
    eventq7:winevent

    0x561D90 | public: __thiscall WINEventHandler::WINEventHandler(void) | ??0WINEventHandler@@QAE@XZ
    0x561EC0 | public: virtual __thiscall WINEventHandler::~WINEventHandler(void) | ??1WINEventHandler@@UAE@XZ
    0x561F20 | public: virtual int __thiscall WINEventHandler::BeginGfx(int,int,int) | ?BeginGfx@WINEventHandler@@UAEHHHH@Z
    0x561FC0 | public: virtual void __thiscall WINEventHandler::EndGfx(void) | ?EndGfx@WINEventHandler@@UAEXXZ
    0x561FE0 | public: virtual char * __thiscall WINEventHandler::GKeyName(int) | ?GKeyName@WINEventHandler@@UAEPADH@Z
    0x562350 | public: virtual void __thiscall WINEventHandler::Update(int) | ?Update@WINEventHandler@@UAEXH@Z
    0x562610 | public: virtual void __thiscall WINEventHandler::BeginTracking(void) | ?BeginTracking@WINEventHandler@@UAEXXZ
    0x562640 | public: virtual void __thiscall WINEventHandler::EndTracking(void) | ?EndTracking@WINEventHandler@@UAEXXZ
    0x562660 | public: void __thiscall WINEventHandler::AdjustMouse(int &,int &) | ?AdjustMouse@WINEventHandler@@QAEXAAH0@Z
    0x562720 | private: virtual long __thiscall WINEventHandler::WindowProc(struct HWND__ *,unsigned int,unsigned int,long) | ?WindowProc@WINEventHandler@@EAEJPAUHWND__@@IIJ@Z
    0x562DF0 | void __cdecl InitEventQueue(void) | ?InitEventQueue@@YAXXZ
    0x562E60 | void __cdecl DeallocateEventQueue(void) | ?DeallocateEventQueue@@YAXXZ
    0x562E80 | public: virtual void * __thiscall WINEventHandler::`scalar deleting destructor'(unsigned int) | ??_GWINEventHandler@@UAEPAXI@Z
    0x562E80 | public: virtual void * __thiscall WINEventHandler::`vector deleting destructor'(unsigned int) | ??_EWINEventHandler@@UAEPAXI@Z
    0x621A78 | const WINEventHandler::`vftable'{for `Dispatchable'} | ??_7WINEventHandler@@6BDispatchable@@@
    0x621A80 | const WINEventHandler::`vftable'{for `eqEventHandler'} | ??_7WINEventHandler@@6BeqEventHandler@@@
    0x621A9C | const Dispatchable::`vftable' | ??_7Dispatchable@@6B@
    0x657820 | int ActiveFlag | ?ActiveFlag@@3HA
    0x908C34 | void (__cdecl* CloseCallback)(void) | ?CloseCallback@@3P6AXXZA
    0x908C38 | int InitialCursorState | ?InitialCursorState@@3HA
    0x908C48 | int eqRestoreFlag | ?eqRestoreFlag@@3HA
*/

#include "event.h"

struct WINEventHandler
    : eqEventHandler
    , Dispatchable /* Warning: Unordered Multiple Inheritance */
{
    // const WINEventHandler::`vftable'{for `Dispatchable'} @ 0x621A78
    // const WINEventHandler::`vftable'{for `eqEventHandler'} @ 0x621A80

public:
    // 0x561D90 | ??0WINEventHandler@@QAE@XZ
    WINEventHandler();

    // 0x562E80 | ??_EWINEventHandler@@UAEPAXI@Z
    // 0x561EC0 | ??1WINEventHandler@@UAE@XZ
    ~WINEventHandler() override;

    // 0x562660 | ?AdjustMouse@WINEventHandler@@QAEXAAH0@Z
    void AdjustMouse(i32& arg1, i32& arg2);

    // 0x561F20 | ?BeginGfx@WINEventHandler@@UAEHHHH@Z
    i32 BeginGfx(i32 arg1, i32 arg2, i32 arg3) override;

    // 0x562610 | ?BeginTracking@WINEventHandler@@UAEXXZ
    void BeginTracking() override;

    // 0x561FC0 | ?EndGfx@WINEventHandler@@UAEXXZ
    void EndGfx() override;

    // 0x562640 | ?EndTracking@WINEventHandler@@UAEXXZ
    void EndTracking() override;

    // 0x561FE0 | ?GKeyName@WINEventHandler@@UAEPADH@Z
    char* GKeyName(i32 arg1) override;

    // 0x562350 | ?Update@WINEventHandler@@UAEXH@Z
    void Update(i32 arg1) override;

private:
    // 0x562720 | ?WindowProc@WINEventHandler@@EAEJPAUHWND__@@IIJ@Z
    i32 WindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4) override;
};

check_size(WINEventHandler, 0x16C);

// 0x562E60 | ?DeallocateEventQueue@@YAXXZ
void DeallocateEventQueue();

// 0x562DF0 | ?InitEventQueue@@YAXXZ
void InitEventQueue();

// 0x657820 | ?ActiveFlag@@3HA
inline extern_var(0x657820, i32, ActiveFlag);

// 0x908C34 | ?CloseCallback@@3P6AXXZA
inline extern_var(0x908C34, void (*)(void), CloseCallback);

// 0x908C38 | ?InitialCursorState@@3HA
inline extern_var(0x908C38, i32, InitialCursorState);

// 0x908C48 | ?eqRestoreFlag@@3HA
inline extern_var(0x908C48, i32, eqRestoreFlag);

class Dispatchable
{
    // const Dispatchable::`vftable' @ 0x621A9C

private:
    virtual i32 WindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4) = 0;
};

check_size(Dispatchable, 0x0);
