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

#include "sdlevent.h"

#include "keys.h"
#include "mmaudio/manager.h"
#include "pcwindis/dxinit.h"
#include "winevent.h"

#include <SDL_events.h>
#include <SDL_hints.h>
#include <SDL_video.h>

void DeallocateEventQueue()
{
    delete eqEventHandler::SuperQ;

    eqEventHandler::SuperQ = nullptr;
}

void InitEventQueue()
{
    if (eqEventHandler::SuperQ)
        return;

    if (g_MainWindow && !(SDL_GetWindowFlags(g_MainWindow) & SDL_WINDOW_FOREIGN))
        eqEventHandler::SuperQ = new SDLEventHandler();
    else
        eqEventHandler::SuperQ = new WINEventHandler();
}

static mem::cmd_param PARAM_mousemode {"mousemode"};

i32 SDLEventHandler::BeginGfx(i32 width, i32 height, b32 fullscreen)
{
    center_x_ = width / 2.0f;
    center_y_ = height / 2.0f;

    scale_x_ = 1.0f / center_x_;
    scale_y_ = 1.0f / center_y_;

    mouse_x_ = width / 2;
    mouse_y_ = height / 2;

    mouse_virtual_x_ = 0;
    mouse_virtual_y_ = 0;

    mouse_width_ = width;
    mouse_height_ = height;

    tracking_x_ = 0;
    tracking_y_ = 0;
    tracked_events_ = 0x0;

    SDL_RaiseWindow(g_MainWindow);
    SDL_SetWindowGrab(g_MainWindow, SDL_TRUE);

    i32 mouse_mode = PARAM_mousemode.get_or(fullscreen ? 0 : 2);
    SDL_SetHint(SDL_HINT_MOUSE_RELATIVE_MODE_WARP, (mouse_mode == 1) ? "1" : "0");

    if ((SDL_SetRelativeMouseMode((mouse_mode != 2) ? SDL_TRUE : SDL_FALSE) < 0) || (mouse_mode == 2))
    {
        SDL_WarpMouseInWindow(g_MainWindow, mouse_x_, mouse_y_);
        tracked_events_ |= 0x1;
    }

    return 0;
}

void SDLEventHandler::EndGfx()
{
    SDL_SetRelativeMouseMode(SDL_FALSE);
    SDL_SetWindowGrab(g_MainWindow, SDL_FALSE);
}

#define EQ_SEND(NAME, ...)                               \
    for (eqEventMonitor * monitor : monitors_)           \
    {                                                    \
        if (monitor && (monitor->channels_ & channels_)) \
            monitor->NAME(__VA_ARGS__);                  \
    }

void SDLEventHandler::Update(i32)
{
    if (ActiveFlag)
    {
        SDL_Event events[32];
        SDL_PumpEvents();

        i32 count = 0;
        while ((count = SDL_PeepEvents(events, ARTS_SSIZE32(events), SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT)) != 0)
        {
            for (i32 i = 0; i < count; ++i)
                HandleEvent(events[i]);
        }
    }
    else
    {
        SDL_Event event;

        while (ActiveFlag == 0)
        {
            if (SDL_WaitEvent(&event))
                HandleEvent(event);
        }
    }

    if (mouse_moved_)
    {
        EQ_SEND(Mouse, 0, 0, 0, buttons_, mouse_x_, mouse_y_, 0, 0);

        mouse_moved_ = false;
    }
}

void SDLEventHandler::BeginTracking()
{}

void SDLEventHandler::EndTracking()
{}

const char* SDLEventHandler::GKeyName(i32 /*key*/)
{
    return "[Unknown]";
}

static void TranslateScancode(SDL_Scancode scan, i32& vkey, u8& vsc);

void SDLEventHandler::HandleEvent(const SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_WINDOWEVENT: HandleWindowEvent(event.window); break;

        case SDL_MOUSEMOTION: {
            i32 old_x = mouse_x_;
            i32 old_y = mouse_y_;

            mouse_virtual_x_ += event.motion.xrel;
            mouse_virtual_y_ += event.motion.yrel;

            if (tracked_events_ & 0x1)
            {
                mouse_x_ = std::clamp(event.motion.x - tracking_x_, 0, mouse_width_);
                mouse_y_ = std::clamp(event.motion.y - tracking_y_, 0, mouse_height_);

                tracking_x_ = event.motion.x - mouse_x_;
                tracking_y_ = event.motion.y - mouse_y_;
            }
            else
            {
                mouse_x_ = std::clamp(mouse_x_ + event.motion.xrel, 0, mouse_width_);
                mouse_y_ = std::clamp(mouse_y_ + event.motion.yrel, 0, mouse_height_);
            }

            // Avoid redudant events, and only send a maximum of one per frame
            if (mouse_x_ != old_x || mouse_y_ != old_y)
                mouse_moved_ = true;

            break;
        }

        case SDL_KEYDOWN:
        case SDL_KEYUP: {
            u32 modifiers = 0;

            if (event.key.state == SDL_PRESSED)
                modifiers |= EQ_KMOD_DOWN;
            if (event.key.repeat)
                modifiers |= EQ_KMOD_REPEAT;
            if (event.key.keysym.mod & KMOD_CTRL)
                modifiers |= EQ_KMOD_CTRL;
            if (event.key.keysym.mod & KMOD_ALT)
                modifiers |= EQ_KMOD_ALT;
            if (event.key.keysym.mod & KMOD_SHIFT)
                modifiers |= EQ_KMOD_SHIFT;

            i32 vkey = 0;
            u8 vsc = 0;
            TranslateScancode(event.key.keysym.scancode, vkey, vsc);

            if (vsc)
                key_states_[vsc] = !!(modifiers & EQ_KMOD_DOWN);

            i32 lparam = 0x1 | ((vsc & 0x7F) << 16) | ((vsc & 0x80) << 17);

            if (modifiers & EQ_KMOD_REPEAT)
                lparam |= (0x1 << 30);

            if (!(modifiers & EQ_KMOD_DOWN))
                lparam |= (0x1 << 30) | (0x1 << 31);

            if (vkey)
                EQ_SEND(Keyboard, (void*) event.key.windowID, modifiers, vkey, 0, lparam);

            break;
        }

        case SDL_TEXTINPUT: {
            for (const char* text = event.text.text; *text; ++text)
            {
                u8 value = *text;

                EQ_SEND(Keyboard, (void*) event.text.windowID, EQ_KMOD_DOWN, 0, value, 0);
            }

            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: {
            u32 button = 0;

            switch (event.button.button)
            {
                case SDL_BUTTON_LEFT: button = EQ_BUTTON_LEFT; break;
                case SDL_BUTTON_RIGHT: button = EQ_BUTTON_RIGHT; break;
                case SDL_BUTTON_MIDDLE: button = EQ_BUTTON_MIDDLE; break;
            }

            if (event.button.state == SDL_PRESSED)
                buttons_ |= button;
            else
                buttons_ &= ~button;

            u32 changed_buttons = buttons_ ^ prev_buttons_;
            u32 new_buttons = buttons_ & changed_buttons;

            EQ_SEND(
                Mouse, (void*) event.button.windowID, new_buttons, changed_buttons, buttons_, mouse_x_, mouse_y_, 0, 0);

            prev_buttons_ = buttons_;

            break;
        }
    }
}

void SDLEventHandler::HandleWindowEvent(const SDL_WindowEvent& event)
{
    switch (event.event)
    {
        case SDL_WINDOWEVENT_FOCUS_GAINED:
        case SDL_WINDOWEVENT_FOCUS_LOST: {
            bool focused = event.event == SDL_WINDOWEVENT_FOCUS_GAINED;

            if (focused)
            {
                if (!(ActiveFlag & 1))
                {
                    RestoreApplication();
                    ActiveFlag |= 1;
                }
            }
            else
            {
                if ((ActiveFlag & 1) && PARAM_pause.get_or(true))
                {
                    DeactivateApplication();
                    ActiveFlag &= ~1;
                }
            }

            EQ_SEND(Refocus, (void*) event.windowID, focused);

            break;
        }

        case SDL_WINDOWEVENT_CLOSE: {
            Displayf("Close requested.");

            if (CloseCallback)
                CloseCallback();

            ActiveFlag = 1;
            break;
        }
    }
}

static void TranslateScancode(SDL_Scancode scan, i32& vkey, u8& vsc)
{
    vkey = 0;
    vsc = 0;

    switch (scan)
    {
        case SDL_SCANCODE_A:
            vkey = EQ_VK_A;
            vsc = EQ_KEY_A;
            break;
        case SDL_SCANCODE_B:
            vkey = EQ_VK_B;
            vsc = EQ_KEY_B;
            break;
        case SDL_SCANCODE_C:
            vkey = EQ_VK_C;
            vsc = EQ_KEY_C;
            break;
        case SDL_SCANCODE_D:
            vkey = EQ_VK_D;
            vsc = EQ_KEY_D;
            break;
        case SDL_SCANCODE_E:
            vkey = EQ_VK_E;
            vsc = EQ_KEY_E;
            break;
        case SDL_SCANCODE_F:
            vkey = EQ_VK_F;
            vsc = EQ_KEY_F;
            break;
        case SDL_SCANCODE_G:
            vkey = EQ_VK_G;
            vsc = EQ_KEY_G;
            break;
        case SDL_SCANCODE_H:
            vkey = EQ_VK_H;
            vsc = EQ_KEY_H;
            break;
        case SDL_SCANCODE_I:
            vkey = EQ_VK_I;
            vsc = EQ_KEY_I;
            break;
        case SDL_SCANCODE_J:
            vkey = EQ_VK_J;
            vsc = EQ_KEY_J;
            break;
        case SDL_SCANCODE_K:
            vkey = EQ_VK_K;
            vsc = EQ_KEY_K;
            break;
        case SDL_SCANCODE_L:
            vkey = EQ_VK_L;
            vsc = EQ_KEY_L;
            break;
        case SDL_SCANCODE_M:
            vkey = EQ_VK_M;
            vsc = EQ_KEY_M;
            break;
        case SDL_SCANCODE_N:
            vkey = EQ_VK_N;
            vsc = EQ_KEY_N;
            break;
        case SDL_SCANCODE_O:
            vkey = EQ_VK_O;
            vsc = EQ_KEY_O;
            break;
        case SDL_SCANCODE_P:
            vkey = EQ_VK_P;
            vsc = EQ_KEY_P;
            break;
        case SDL_SCANCODE_Q:
            vkey = EQ_VK_Q;
            vsc = EQ_KEY_Q;
            break;
        case SDL_SCANCODE_R:
            vkey = EQ_VK_R;
            vsc = EQ_KEY_R;
            break;
        case SDL_SCANCODE_S:
            vkey = EQ_VK_S;
            vsc = EQ_KEY_S;
            break;
        case SDL_SCANCODE_T:
            vkey = EQ_VK_T;
            vsc = EQ_KEY_T;
            break;
        case SDL_SCANCODE_U:
            vkey = EQ_VK_U;
            vsc = EQ_KEY_U;
            break;
        case SDL_SCANCODE_V:
            vkey = EQ_VK_V;
            vsc = EQ_KEY_V;
            break;
        case SDL_SCANCODE_W:
            vkey = EQ_VK_W;
            vsc = EQ_KEY_W;
            break;
        case SDL_SCANCODE_X:
            vkey = EQ_VK_X;
            vsc = EQ_KEY_X;
            break;
        case SDL_SCANCODE_Y:
            vkey = EQ_VK_Y;
            vsc = EQ_KEY_Y;
            break;
        case SDL_SCANCODE_Z:
            vkey = EQ_VK_Z;
            vsc = EQ_KEY_Z;
            break;
        case SDL_SCANCODE_1:
            vkey = EQ_VK_1;
            vsc = EQ_KEY_1;
            break;
        case SDL_SCANCODE_2:
            vkey = EQ_VK_2;
            vsc = EQ_KEY_2;
            break;
        case SDL_SCANCODE_3:
            vkey = EQ_VK_3;
            vsc = EQ_KEY_3;
            break;
        case SDL_SCANCODE_4:
            vkey = EQ_VK_4;
            vsc = EQ_KEY_4;
            break;
        case SDL_SCANCODE_5:
            vkey = EQ_VK_5;
            vsc = EQ_KEY_5;
            break;
        case SDL_SCANCODE_6:
            vkey = EQ_VK_6;
            vsc = EQ_KEY_6;
            break;
        case SDL_SCANCODE_7:
            vkey = EQ_VK_7;
            vsc = EQ_KEY_7;
            break;
        case SDL_SCANCODE_8:
            vkey = EQ_VK_8;
            vsc = EQ_KEY_8;
            break;
        case SDL_SCANCODE_9:
            vkey = EQ_VK_9;
            vsc = EQ_KEY_9;
            break;
        case SDL_SCANCODE_0:
            vkey = EQ_VK_0;
            vsc = EQ_KEY_0;
            break;
        case SDL_SCANCODE_RETURN:
            vkey = EQ_VK_RETURN;
            vsc = EQ_KEY_RETURN;
            break;
        case SDL_SCANCODE_ESCAPE:
            vkey = EQ_VK_ESCAPE;
            vsc = EQ_KEY_ESCAPE;
            break;
        case SDL_SCANCODE_BACKSPACE:
            vkey = EQ_VK_BACK;
            vsc = EQ_KEY_BACK;
            break;
        case SDL_SCANCODE_TAB:
            vkey = EQ_VK_TAB;
            vsc = EQ_KEY_TAB;
            break;
        case SDL_SCANCODE_SPACE:
            vkey = EQ_VK_SPACE;
            vsc = EQ_KEY_SPACE;
            break;
        case SDL_SCANCODE_MINUS:
            vkey = EQ_VK_OEM_MINUS;
            vsc = EQ_KEY_MINUS;
            break;
        case SDL_SCANCODE_EQUALS: vsc = EQ_KEY_EQUALS; break;
        case SDL_SCANCODE_LEFTBRACKET: vsc = EQ_KEY_LBRACKET; break;
        case SDL_SCANCODE_RIGHTBRACKET: vsc = EQ_KEY_RBRACKET; break;
        case SDL_SCANCODE_BACKSLASH: vsc = EQ_KEY_BACKSLASH; break;
        case SDL_SCANCODE_NONUSHASH: vsc = EQ_KEY_BACKSLASH; break;
        case SDL_SCANCODE_SEMICOLON: vsc = EQ_KEY_SEMICOLON; break;
        case SDL_SCANCODE_APOSTROPHE: vsc = EQ_KEY_APOSTROPHE; break;
        case SDL_SCANCODE_GRAVE: vsc = EQ_KEY_GRAVE; break;
        case SDL_SCANCODE_COMMA:
            vkey = EQ_VK_OEM_COMMA;
            vsc = EQ_KEY_COMMA;
            break;
        case SDL_SCANCODE_PERIOD:
            vkey = EQ_VK_OEM_PERIOD;
            vsc = EQ_KEY_PERIOD;
            break;
        case SDL_SCANCODE_SLASH: vsc = EQ_KEY_SLASH; break;
        case SDL_SCANCODE_CAPSLOCK:
            vkey = EQ_VK_CAPITAL;
            vsc = EQ_KEY_CAPITAL;
            break;
        case SDL_SCANCODE_F1:
            vkey = EQ_VK_F1;
            vsc = EQ_KEY_F1;
            break;
        case SDL_SCANCODE_F2:
            vkey = EQ_VK_F2;
            vsc = EQ_KEY_F2;
            break;
        case SDL_SCANCODE_F3:
            vkey = EQ_VK_F3;
            vsc = EQ_KEY_F3;
            break;
        case SDL_SCANCODE_F4:
            vkey = EQ_VK_F4;
            vsc = EQ_KEY_F4;
            break;
        case SDL_SCANCODE_F5:
            vkey = EQ_VK_F5;
            vsc = EQ_KEY_F5;
            break;
        case SDL_SCANCODE_F6:
            vkey = EQ_VK_F6;
            vsc = EQ_KEY_F6;
            break;
        case SDL_SCANCODE_F7:
            vkey = EQ_VK_F7;
            vsc = EQ_KEY_F7;
            break;
        case SDL_SCANCODE_F8:
            vkey = EQ_VK_F8;
            vsc = EQ_KEY_F8;
            break;
        case SDL_SCANCODE_F9:
            vkey = EQ_VK_F9;
            vsc = EQ_KEY_F9;
            break;
        case SDL_SCANCODE_F10:
            vkey = EQ_VK_F10;
            vsc = EQ_KEY_F10;
            break;
        case SDL_SCANCODE_F11:
            vkey = EQ_VK_F11;
            vsc = EQ_KEY_F11;
            break;
        case SDL_SCANCODE_F12:
            vkey = EQ_VK_F12;
            vsc = EQ_KEY_F12;
            break;
        case SDL_SCANCODE_PRINTSCREEN: vkey = EQ_VK_SNAPSHOT; break;
        case SDL_SCANCODE_SCROLLLOCK:
            vkey = EQ_VK_SCROLL;
            vsc = EQ_KEY_SCROLL;
            break;
        case SDL_SCANCODE_PAUSE:
            vkey = EQ_VK_PAUSE;
            vsc = EQ_KEY_PAUSE;
            break;
        case SDL_SCANCODE_INSERT:
            vkey = EQ_VK_INSERT;
            vsc = EQ_KEY_INSERT;
            break;
        case SDL_SCANCODE_HOME:
            vkey = EQ_VK_HOME;
            vsc = EQ_KEY_HOME;
            break;
        case SDL_SCANCODE_PAGEUP:
            vkey = EQ_VK_PRIOR;
            vsc = EQ_KEY_PRIOR;
            break;
        case SDL_SCANCODE_DELETE:
            vkey = EQ_VK_DELETE;
            vsc = EQ_KEY_DELETE;
            break;
        case SDL_SCANCODE_END:
            vkey = EQ_VK_END;
            vsc = EQ_KEY_END;
            break;
        case SDL_SCANCODE_PAGEDOWN:
            vkey = EQ_VK_NEXT;
            vsc = EQ_KEY_NEXT;
            break;
        case SDL_SCANCODE_RIGHT:
            vkey = EQ_VK_RIGHT;
            vsc = EQ_KEY_RIGHT;
            break;
        case SDL_SCANCODE_LEFT:
            vkey = EQ_VK_LEFT;
            vsc = EQ_KEY_LEFT;
            break;
        case SDL_SCANCODE_DOWN:
            vkey = EQ_VK_DOWN;
            vsc = EQ_KEY_DOWN;
            break;
        case SDL_SCANCODE_UP:
            vkey = EQ_VK_UP;
            vsc = EQ_KEY_UP;
            break;
        case SDL_SCANCODE_NUMLOCKCLEAR:
            vkey = EQ_VK_NUMLOCK;
            vsc = EQ_KEY_NUMLOCK;
            break;
        case SDL_SCANCODE_KP_DIVIDE:
            vkey = EQ_VK_DIVIDE;
            vsc = EQ_KEY_DIVIDE;
            break;
        case SDL_SCANCODE_KP_MULTIPLY:
            vkey = EQ_VK_MULTIPLY;
            vsc = EQ_KEY_MULTIPLY;
            break;
        case SDL_SCANCODE_KP_MINUS:
            vkey = EQ_VK_SUBTRACT;
            vsc = EQ_KEY_SUBTRACT;
            break;
        case SDL_SCANCODE_KP_PLUS:
            vkey = EQ_VK_ADD;
            vsc = EQ_KEY_ADD;
            break;
        case SDL_SCANCODE_KP_ENTER:
            vkey = EQ_VK_RETURN;
            vsc = EQ_KEY_NUMPADENTER;
            break;
        case SDL_SCANCODE_KP_1:
            vkey = EQ_VK_NUMPAD1;
            vsc = EQ_KEY_NUMPAD1;
            break;
        case SDL_SCANCODE_KP_2:
            vkey = EQ_VK_NUMPAD2;
            vsc = EQ_KEY_NUMPAD2;
            break;
        case SDL_SCANCODE_KP_3:
            vkey = EQ_VK_NUMPAD3;
            vsc = EQ_KEY_NUMPAD3;
            break;
        case SDL_SCANCODE_KP_4:
            vkey = EQ_VK_NUMPAD4;
            vsc = EQ_KEY_NUMPAD4;
            break;
        case SDL_SCANCODE_KP_5:
            vkey = EQ_VK_NUMPAD5;
            vsc = EQ_KEY_NUMPAD5;
            break;
        case SDL_SCANCODE_KP_6:
            vkey = EQ_VK_NUMPAD6;
            vsc = EQ_KEY_NUMPAD6;
            break;
        case SDL_SCANCODE_KP_7:
            vkey = EQ_VK_NUMPAD7;
            vsc = EQ_KEY_NUMPAD7;
            break;
        case SDL_SCANCODE_KP_8:
            vkey = EQ_VK_NUMPAD8;
            vsc = EQ_KEY_NUMPAD8;
            break;
        case SDL_SCANCODE_KP_9:
            vkey = EQ_VK_NUMPAD9;
            vsc = EQ_KEY_NUMPAD9;
            break;
        case SDL_SCANCODE_KP_0:
            vkey = EQ_VK_NUMPAD0;
            vsc = EQ_KEY_NUMPAD0;
            break;
        case SDL_SCANCODE_KP_PERIOD:
            vkey = EQ_VK_DECIMAL;
            vsc = EQ_KEY_DECIMAL;
            break;
        case SDL_SCANCODE_NONUSBACKSLASH:
            vkey = EQ_VK_OEM_102;
            vsc = EQ_KEY_OEM_102;
            break;
        case SDL_SCANCODE_APPLICATION:
            vkey = EQ_VK_APPS;
            vsc = EQ_KEY_APPS;
            break;
        case SDL_SCANCODE_POWER: vsc = EQ_KEY_POWER; break;
        case SDL_SCANCODE_KP_EQUALS:
            vkey = EQ_VK_OEM_NEC_EQUAL;
            vsc = EQ_KEY_NUMPADEQUALS;
            break;
        case SDL_SCANCODE_F13:
            vkey = EQ_VK_F13;
            vsc = EQ_KEY_F13;
            break;
        case SDL_SCANCODE_F14:
            vkey = EQ_VK_F14;
            vsc = EQ_KEY_F14;
            break;
        case SDL_SCANCODE_F15:
            vkey = EQ_VK_F15;
            vsc = EQ_KEY_F15;
            break;
        case SDL_SCANCODE_F16:
            vkey = EQ_VK_F16;
            vsc = EQ_KEY_F16;
            break;
        case SDL_SCANCODE_F17:
            vkey = EQ_VK_F17;
            vsc = EQ_KEY_F17;
            break;
        case SDL_SCANCODE_F18:
            vkey = EQ_VK_F18;
            vsc = EQ_KEY_F18;
            break;
        case SDL_SCANCODE_F19:
            vkey = EQ_VK_F19;
            vsc = EQ_KEY_F19;
            break;
        case SDL_SCANCODE_F20: vkey = EQ_VK_F20; break;
        case SDL_SCANCODE_F21: vkey = EQ_VK_F21; break;
        case SDL_SCANCODE_F22: vkey = EQ_VK_F22; break;
        case SDL_SCANCODE_F23: vkey = EQ_VK_F23; break;
        case SDL_SCANCODE_F24: vkey = EQ_VK_F24; break;
        case SDL_SCANCODE_EXECUTE: vkey = EQ_VK_EXECUTE; break;
        case SDL_SCANCODE_HELP: vkey = EQ_VK_HELP; break;
        case SDL_SCANCODE_MENU: vkey = EQ_VK_MENU; break;
        case SDL_SCANCODE_SELECT: vkey = EQ_VK_SELECT; break;
        case SDL_SCANCODE_STOP: vsc = EQ_KEY_STOP; break;
        // case SDL_SCANCODE_AGAIN: break;
        // case SDL_SCANCODE_UNDO: break;
        // case SDL_SCANCODE_CUT: break;
        // case SDL_SCANCODE_COPY: break;
        // case SDL_SCANCODE_PASTE: break;
        // case SDL_SCANCODE_FIND: break;
        case SDL_SCANCODE_MUTE: vsc = EQ_KEY_MUTE; break;
        case SDL_SCANCODE_VOLUMEUP:
            vkey = EQ_VK_VOLUME_UP;
            vsc = EQ_KEY_VOLUMEUP;
            break;
        case SDL_SCANCODE_VOLUMEDOWN:
            vkey = EQ_VK_VOLUME_DOWN;
            vsc = EQ_KEY_VOLUMEDOWN;
            break;
        // case SDL_SCANCODE_KP_COMMA: break;
        // case SDL_SCANCODE_KP_EQUALSAS400: break;
        case SDL_SCANCODE_INTERNATIONAL1: vsc = EQ_KEY_ABNT_C1; break;
        case SDL_SCANCODE_INTERNATIONAL2: vsc = EQ_KEY_KANA; break;
        case SDL_SCANCODE_INTERNATIONAL3: vsc = EQ_KEY_YEN; break;
        case SDL_SCANCODE_INTERNATIONAL4: vsc = EQ_KEY_CONVERT; break;
        case SDL_SCANCODE_INTERNATIONAL5: vsc = EQ_KEY_NOCONVERT; break;
        // case SDL_SCANCODE_INTERNATIONAL6: break;
        // case SDL_SCANCODE_INTERNATIONAL7: break;
        // case SDL_SCANCODE_INTERNATIONAL8: break;
        // case SDL_SCANCODE_INTERNATIONAL9: break;
        // case SDL_SCANCODE_LANG1: break;
        // case SDL_SCANCODE_LANG2: break;
        // case SDL_SCANCODE_LANG3: break;
        // case SDL_SCANCODE_LANG4: break;
        // case SDL_SCANCODE_LANG5: break;
        // case SDL_SCANCODE_LANG6: break;
        // case SDL_SCANCODE_LANG7: break;
        // case SDL_SCANCODE_LANG8: break;
        // case SDL_SCANCODE_LANG9: break;
        // case SDL_SCANCODE_ALTERASE: break;
        case SDL_SCANCODE_SYSREQ: vkey = EQ_VK_ATTN; break;
        case SDL_SCANCODE_CANCEL: vkey = EQ_VK_CANCEL; break;
        case SDL_SCANCODE_CLEAR: vkey = EQ_VK_CLEAR; break;
        case SDL_SCANCODE_PRIOR:
            vkey = EQ_VK_PRIOR;
            vsc = EQ_KEY_PRIOR;
            break;
        // case SDL_SCANCODE_RETURN2: break;
        case SDL_SCANCODE_SEPARATOR: vkey = EQ_VK_SEPARATOR; break;
        // case SDL_SCANCODE_OUT: break;
        // case SDL_SCANCODE_OPER: break;
        // case SDL_SCANCODE_CLEARAGAIN: break;
        case SDL_SCANCODE_CRSEL: vkey = EQ_VK_CRSEL; break;
        case SDL_SCANCODE_EXSEL: vkey = EQ_VK_EXSEL; break;
        // case SDL_SCANCODE_KP_00: break;
        // case SDL_SCANCODE_KP_000: break;
        // case SDL_SCANCODE_THOUSANDSSEPARATOR: break;
        // case SDL_SCANCODE_DECIMALSEPARATOR: break;
        // case SDL_SCANCODE_CURRENCYUNIT: break;
        // case SDL_SCANCODE_CURRENCYSUBUNIT: break;
        // case SDL_SCANCODE_KP_LEFTPAREN: break;
        // case SDL_SCANCODE_KP_RIGHTPAREN: break;
        // case SDL_SCANCODE_KP_LEFTBRACE: break;
        // case SDL_SCANCODE_KP_RIGHTBRACE: break;
        case SDL_SCANCODE_KP_TAB: vkey = EQ_VK_TAB; break;
        case SDL_SCANCODE_KP_BACKSPACE: vkey = EQ_VK_BACK; break;
        case SDL_SCANCODE_KP_A: vkey = EQ_VK_A; break;
        case SDL_SCANCODE_KP_B: vkey = EQ_VK_B; break;
        case SDL_SCANCODE_KP_C: vkey = EQ_VK_C; break;
        case SDL_SCANCODE_KP_D: vkey = EQ_VK_D; break;
        case SDL_SCANCODE_KP_E: vkey = EQ_VK_E; break;
        case SDL_SCANCODE_KP_F: vkey = EQ_VK_F; break;
        // case SDL_SCANCODE_KP_XOR: break;
        // case SDL_SCANCODE_KP_POWER: break;
        // case SDL_SCANCODE_KP_PERCENT: break;
        // case SDL_SCANCODE_KP_LESS: break;
        // case SDL_SCANCODE_KP_GREATER: break;
        // case SDL_SCANCODE_KP_AMPERSAND: break;
        // case SDL_SCANCODE_KP_DBLAMPERSAND: break;
        // case SDL_SCANCODE_KP_VERTICALBAR: break;
        // case SDL_SCANCODE_KP_DBLVERTICALBAR: break;
        // case SDL_SCANCODE_KP_COLON: break;
        // case SDL_SCANCODE_KP_HASH: break;
        case SDL_SCANCODE_KP_SPACE:
            vkey = EQ_VK_SPACE;
            vsc = EQ_KEY_SPACE;
            break;
        // case SDL_SCANCODE_KP_AT: break;
        // case SDL_SCANCODE_KP_EXCLAM: break;
        // case SDL_SCANCODE_KP_MEMSTORE: break;
        // case SDL_SCANCODE_KP_MEMRECALL: break;
        // case SDL_SCANCODE_KP_MEMCLEAR: break;
        // case SDL_SCANCODE_KP_MEMADD: break;
        // case SDL_SCANCODE_KP_MEMSUBTRACT: break;
        // case SDL_SCANCODE_KP_MEMMULTIPLY: break;
        // case SDL_SCANCODE_KP_MEMDIVIDE: break;
        // case SDL_SCANCODE_KP_PLUSMINUS: break;
        case SDL_SCANCODE_KP_CLEAR: vkey = EQ_VK_CLEAR; break;
        // case SDL_SCANCODE_KP_CLEARENTRY: break;
        // case SDL_SCANCODE_KP_BINARY: break;
        // case SDL_SCANCODE_KP_OCTAL: break;
        case SDL_SCANCODE_KP_DECIMAL: vkey = EQ_VK_DECIMAL; break;
        // case SDL_SCANCODE_KP_HEXADECIMAL: break;
        case SDL_SCANCODE_LCTRL:
            vkey = EQ_VK_LCONTROL;
            vsc = EQ_KEY_LCONTROL;
            break;
        case SDL_SCANCODE_LSHIFT:
            vkey = EQ_VK_LSHIFT;
            vsc = EQ_KEY_LSHIFT;
            break;
        case SDL_SCANCODE_LALT:
            vkey = EQ_VK_LMENU;
            vsc = EQ_KEY_LMENU;
            break;
        case SDL_SCANCODE_LGUI:
            vkey = EQ_VK_LWIN;
            vsc = EQ_KEY_LWIN;
            break;
        case SDL_SCANCODE_RCTRL:
            vkey = EQ_VK_RCONTROL;
            vsc = EQ_KEY_RCONTROL;
            break;
        case SDL_SCANCODE_RSHIFT:
            vkey = EQ_VK_RSHIFT;
            vsc = EQ_KEY_RSHIFT;
            break;
        case SDL_SCANCODE_RALT:
            vkey = EQ_VK_RMENU;
            vsc = EQ_KEY_RMENU;
            break;
        case SDL_SCANCODE_RGUI:
            vkey = EQ_VK_RWIN;
            vsc = EQ_KEY_RWIN;
            break;
        case SDL_SCANCODE_MODE: vkey = EQ_VK_MODECHANGE; break;
        case SDL_SCANCODE_AUDIONEXT:
            vkey = EQ_VK_MEDIA_NEXT_TRACK;
            vsc = EQ_KEY_NEXTTRACK;
            break;
        case SDL_SCANCODE_AUDIOPREV:
            vkey = EQ_VK_MEDIA_PREV_TRACK;
            vsc = EQ_KEY_PREVTRACK;
            break;
        case SDL_SCANCODE_AUDIOSTOP:
            vkey = EQ_VK_MEDIA_STOP;
            vsc = EQ_KEY_MEDIASTOP;
            break;
        case SDL_SCANCODE_AUDIOPLAY:
            vkey = EQ_VK_MEDIA_PLAY_PAUSE;
            vsc = EQ_KEY_PLAYPAUSE;
            break;
        case SDL_SCANCODE_AUDIOMUTE:
            vkey = EQ_VK_VOLUME_MUTE;
            vsc = EQ_KEY_MUTE;
            break;
        case SDL_SCANCODE_MEDIASELECT:
            vkey = EQ_VK_LAUNCH_MEDIA_SELECT;
            vsc = EQ_KEY_MEDIASELECT;
            break;
        // case SDL_SCANCODE_WWW: break;
        case SDL_SCANCODE_MAIL:
            vkey = EQ_VK_LAUNCH_MAIL;
            vsc = EQ_KEY_MAIL;
            break;
        case SDL_SCANCODE_CALCULATOR: vsc = EQ_KEY_CALCULATOR; break;
        // case SDL_SCANCODE_COMPUTER: break;
        case SDL_SCANCODE_AC_SEARCH:
            vkey = EQ_VK_BROWSER_SEARCH;
            vsc = EQ_KEY_WEBSEARCH;
            break;
        case SDL_SCANCODE_AC_HOME:
            vkey = EQ_VK_BROWSER_HOME;
            vsc = EQ_KEY_WEBFAVORITES;
            break;
        case SDL_SCANCODE_AC_BACK:
            vkey = EQ_VK_BROWSER_BACK;
            vsc = EQ_KEY_WEBBACK;
            break;
        case SDL_SCANCODE_AC_FORWARD:
            vkey = EQ_VK_BROWSER_FORWARD;
            vsc = EQ_KEY_WEBFORWARD;
            break;
        case SDL_SCANCODE_AC_STOP:
            vkey = EQ_VK_BROWSER_STOP;
            vsc = EQ_KEY_WEBSTOP;
            break;
        case SDL_SCANCODE_AC_REFRESH: vkey = EQ_VK_BROWSER_REFRESH; break;
        case SDL_SCANCODE_AC_BOOKMARKS: vkey = EQ_VK_BROWSER_FAVORITES; break;
        // case SDL_SCANCODE_BRIGHTNESSDOWN: break;
        // case SDL_SCANCODE_BRIGHTNESSUP: break;
        // case SDL_SCANCODE_DISPLAYSWITCH: break;
        // case SDL_SCANCODE_KBDILLUMTOGGLE: break;
        // case SDL_SCANCODE_KBDILLUMDOWN: break;
        // case SDL_SCANCODE_KBDILLUMUP: break;
        // case SDL_SCANCODE_EJECT: break;
        case SDL_SCANCODE_SLEEP:
            vkey = EQ_VK_SLEEP;
            vsc = EQ_KEY_SLEEP;
            break;
        case SDL_SCANCODE_APP1: vkey = EQ_VK_LAUNCH_APP1; break;
        case SDL_SCANCODE_APP2: vkey = EQ_VK_LAUNCH_APP2; break;
        // case SDL_SCANCODE_AUDIOREWIND: break;
        // case SDL_SCANCODE_AUDIOFASTFORWARD: break;
        default: return;
    }

    if (vkey && vsc == 0)
        vsc = MapVirtualKeyA(vkey, MAPVK_VK_TO_VSC) & 0xFF;

    if (vsc && vkey == 0)
        vkey = MapVirtualKeyA(vsc, MAPVK_VSC_TO_VK);
}
