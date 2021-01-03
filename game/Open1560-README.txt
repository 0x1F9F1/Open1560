# Open1560
Open1560 is an open source re-implementation of Midtown Madness 1 beta 1560.
To run, extract the files in the zip directly into your Midtown Madness 1 directory and then run Open1560.exe.

# Setup
Open1560 uses command line parameters to configure certain aspects of the game:

# Game
-nodamage   | false | Disables Damage
-allrace    | false | Unlocks All Races
-allcars    | false | Unlocks All Cars

# Basic
-affinity   | 0     | Sets the process affinity
-aspect     | true  | Enables black bars to avoid stretching
-cdid       | false | Enables CD music in the menu when using a virtual CD
-config     | false | Forces redetection of graphics modes
-fovfix     | true  | Enables FOV scaling based on resolution
-integrated | false | Prefer using laptop iGPU
-legacygl   | false | Uses a legacy OpenGL context (enabled by default on Intel iGPUs)
-maxaspect  | 2.4   | Maximum resolution aspect ratio
-minaspect  | 1.6   | Minimum resolution aspect ratio
-msaa       | 0     | Sets the anti-aliasing level (does not work with legacy OpenGL)
-nativeres  | true  | Enables rendering internally at the native window resolution (enabled when using -msaa or -legacygl)
-prio       | 2     | Sets the process priority
-vsync      | true  | Enables vertical sync

# Advanced
-agiverbose | false | Enables AGI (graphics) logging
-fontscale  |       | Sets the debug font scale
-gldebug    | false | Enables OpenGL debug output
-sync       | true  | Disables multi-threading
-thinfont   | true  | Enables the debug font slightly thinner

# DirectDraw (disabled)
-afilter    | 16    | Anisotropic filtering level
-reshack    | true  | Enables resolutions above 2048x2048 when using MS ddraw
-voodooaa   | false | Fixes text rendering when using dgVodooo's anti aliasing
