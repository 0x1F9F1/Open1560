# Open1560
Open1560 is an open source re-implementation of Midtown Madness 1 beta 1560.
To run, extract the files in the zip directly into your Midtown Madness 1 directory and then run Open1560.exe.

# Setup
In most cases, Open1560 should run optimally straight away. However, there are certain things you may wish to change:
* If you have a laptop, ensure you are using the correct GPU.
* If you still have low performance, consider disabling Cloud Shadows.
* Enable anti-aliasing with the `-msaa <LEVEL>` argument (possible levels are 1, 2, 4 or 8). Note, this may not be available on certain older/integrated GPUs.

# Command Line Arguments
Open1560 uses command line arguments to configure certain aspects of the game.
For a tutorial on how to use command line arguments, see https://www.bleepingcomputer.com/tutorials/understanding-command-line-arguments-and-how-to-use-them/

## Examples
-window     | Sets window to true (1)
-nowindow   | Sets window to false (0)
-msaa 4     | Sets msaa to 4

## Game
Name        | Value | Description
-nodamage   | false | Disables Damage
-allrace    | false | Unlocks All Races
-allcars    | false | Unlocks All Cars

## Basic
Name        | Value | Description
-affinity   | 0     | Sets the process affinity
-border     | true  | Enables a border when in windowed mode
-cdid       | false | Enables CD music in the menu when using a virtual CD
-config     | false | Forces redetection of graphics modes
-fovfix     | true  | Enables FOV scaling based on resolution
-legacygl   | false | Uses a legacy OpenGL context (enabled by default on Intel iGPUs)
-maxaspect  |       | Maximum aspect ratio of available resolutions
-minaspect  |       | Minimum aspect ratio of available resolutions
-msaa       | 0     | Sets the anti-aliasing level (does not work with legacy OpenGL)
-nativeres  | true  | Enables rendering internally at the native window resolution (enabled when using -msaa or -legacygl)
-prio       | 2     | Sets the process priority
-scaling    | 0     | Sets the scaling mode. 0 = Stretched (Keep Aspect), 1 = Stretched, 2 = Centered
-smoothstep | true  | Smoothes out the time between frames to avoid stutter
-vsync      | true  | Enables vertical sync
-window     | false | Puts the game in a window
-windowmenu | false | Puts the game in a borderless window when in the menu

## Advanced
Name        | Value | Description
-agiverbose | false | Enables AGI (graphics) logging
-fontscale  |       | Sets the debug font scale
-gldebug    |       | Sets the OpenGL debug output level
-sync       | true  | Disables multi-threading
-thinfont   | true  | Enables the debug font slightly thinner

## DirectDraw (disabled)
Name        | Value | Description
-afilter    | 16    | Anisotropic filtering level
-reshack    | true  | Enables resolutions above 2048x2048 when using MS ddraw
-voodooaa   | false | Fixes text rendering when using dgVodooo's anti aliasing

# Dev/Debug Functions
Beta 1560 contains many debug functions/hotkeys. To enter debug mode, press CTRL+ALT+SHIFT+F4.
For a llist of hotkeys, see https://github.com/0x1F9F1/Open1560/blob/master/extra/keys.txt
