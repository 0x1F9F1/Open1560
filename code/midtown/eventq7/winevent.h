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

#include "dispatchable.h"
#include "event.h"

class WINEventHandler final
    : public eqEventHandler
    , public Dispatchable
{
public:
    // ??0WINEventHandler@@QAE@XZ
    ARTS_EXPORT WINEventHandler();

    // ??_EWINEventHandler@@UAEPAXI@Z
    // ??_GWINEventHandler@@UAEPAXI@Z
    // ??1WINEventHandler@@UAE@XZ
    ARTS_EXPORT ~WINEventHandler() override;

    // ?AdjustMouse@WINEventHandler@@QAEXAAH0@Z
    ARTS_EXPORT void AdjustMouse(i32& mouse_x, i32& mouse_y);

    // ?BeginGfx@WINEventHandler@@UAEHHHH@Z
    ARTS_EXPORT i32 BeginGfx(i32 width, i32 height, b32 fullscreen) override;

    // ?BeginTracking@WINEventHandler@@UAEXXZ
    ARTS_EXPORT void BeginTracking() override;

    // ?EndGfx@WINEventHandler@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    // ?EndTracking@WINEventHandler@@UAEXXZ
    ARTS_EXPORT void EndTracking() override;

    // ?GKeyName@WINEventHandler@@UAEPADH@Z
    ARTS_EXPORT const char* GKeyName(i32 arg1) override;

    // ?Update@WINEventHandler@@UAEXH@Z
    ARTS_EXPORT void Update(i32 arg1) override;

private:
    // ?WindowProc@WINEventHandler@@EAEJPAUHWND__@@IIJ@Z
    ARTS_EXPORT LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;

    void OnKeyPress(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    void OnCharPress(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    void OnMouse(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    // 0 = GetKeyboardState
    // 1 = geinputGetKeyboard
    // 3 = geinputGetMouse
    u32 input_method_ {0};
};

check_size(WINEventHandler, 0x16C);

// ?DeallocateEventQueue@@YAXXZ
ARTS_EXPORT void DeallocateEventQueue();

// ?InitEventQueue@@YAXXZ
ARTS_EXPORT void InitEventQueue();

// ?ActiveFlag@@3HA
// 0x1 | Focused/Active
ARTS_IMPORT extern i32 ActiveFlag;

// ?CloseCallback@@3P6AXXZA
ARTS_IMPORT extern void (*CloseCallback)(void);

// ?InitialCursorState@@3HA
ARTS_IMPORT extern i32 InitialCursorState;

// ?eqRestoreFlag@@3HA
ARTS_IMPORT extern i32 eqRestoreFlag;

// TODO: Move this somewhere else
inline bool IsAppActive()
{
    return ActiveFlag & 0x1;
}
