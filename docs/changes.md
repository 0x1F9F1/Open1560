# Changes

This is a list of notable changes made by Open1560. Many other smaller tweaks are not included.

## Added

* FreeType font renderer
* OpenGL hardware renderer
* SDL2 software renderer
* SDL2 window/input handler

## Fixed

* 9th position icon (was CnR dollar sign)
* Broken trailer physics
* Crash launching game
* Crash loading a missing vehicle
* Crash opening hotkey popup (F1) too many times (Heap overrun)
* Dashboard flicker when pausing
* Enabled showcase for addon vehicles
* FOV scaling on wide screens
* Incorrect audio device mapping (Debug Assertion Failed, no sound, useless volume slider)
* Incorrect particle and spark animation speed at higher FPS
* Incorrect texture quality shown in options
* Key presses sometimes not registering
* Menu/popup scaling on wide screens
* Missing/white shadows in software renderer
* Props disappearing/moving when paused
* Rendering artifacts when drawing pedestrians
* Stuttering, audio/input lag (process pinned to 1 core)
* Switching menus mid frame
* Washed out textures in software mode

## Modified

* Improved debug functionality
* Improved loading speed
* Improved thread safety
* Increased heap size
* Increased vertex limits
