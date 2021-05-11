# Setup
In most cases, Open1560 should run optimally straight away.
You do not need to install the XP patch, or use dgVoodoo.
However, there are certain things you may wish to change:
* If you have a laptop, ensure you are using the correct GPU.
* If you have low performance:
    * Try using the `-legacygl` argument.
    * Consider disabling cloud shadows, the rear view mirror, or lowering the far clip distance.
* To enable anti-aliasing, use the `-msaa <LEVEL>` argument (possible levels are 1, 2, 4 or 8). This may not be available on certain older/integrated GPUs.
* If running through wine, download [wine1560.sh](https://raw.githubusercontent.com/0x1F9F1/Open1560/master/extra/wine1560.sh), or manually set the WINEDLLOVERRIDES to prefer native dinput

# Common Issues
* The application was unable to start correctly (0xc0000022)
    * Activate DirectPlay

# Command Line Arguments
Open1560 uses command line arguments to configure certain aspects of the game.<br/>
For a tutorial on how to use command line arguments, see https://www.bleepingcomputer.com/tutorials/understanding-command-line-arguments-and-how-to-use-them/

## Examples
| Value      | Description |
| ---------- | --- |
| -window    | Sets window to true (1) |
| -nowindow  | Sets window to false (0) |
| -msaa 4    | Sets msaa to 4 |

## Game
| Name       | Value | Description |
| ---------- | ----- | --- |
| allcars    | false | Unlocks All Cars |
| allrace    | false | Unlocks All Races |
| maxcops    | 3     | Max cops chasing you at once |
| nodamage   | false | Disables Damage |

## Basic
| Name       | Value | Description |
| ---------- | ----- | --- |
| affinity   | 0     | Sets the process affinity |
| afilter    | 16    | Anisotropic filtering level |
| border     | true  | Enables a border when in windowed mode |
| cdid       | false | Enables CD music in the menu when using a virtual CD |
| config     | false | Forces redetection of graphics modes |
| console    | false | Enables console logging |
| d3d        | false | Use the D3D renderer |
| fovfix     | true  | Enables FOV scaling based on resolution |
| heapsize   | 64    | The size in MB of the game heap |
| legacygl   | false | Uses a legacy OpenGL context (enabled by default on Intel iGPUs) |
| maxaspect  |       | Maximum aspect ratio of available resolutions |
| maxfps     | 0     | Limits the max fps |
| minaspect  |       | Minimum aspect ratio of available resolutions |
| msaa       | 0     | Sets the anti-aliasing level (does not work with legacy OpenGL) |
| nativeres  | true  | Enables rendering internally at the native window resolution (enabled when using -msaa or -legacygl) |
| opengl     | true  | Use the OpenGL renderer |
| prio       | 2     | Sets the process priority |
| scaling    | 0     | Sets the scaling mode. 0 = Stretched (Keep Aspect), 1 = Stretched, 2 = Centered |
| smoothstep | true  | Smoothes out the time between frames to avoid stutter |
| speedrun   | false | Enables speedrunning conditions (currently -nosmoothstep -maxfps=60 -speedycops) |
| speedycops | false | Enables the vanilla cop speed boost (fps dependant) |
| vsync      | true  | Enables vertical sync |
| window     | false | Puts the game in a window |
| windowmenu | false | Puts the game in a borderless window when in the menu |

## Advanced
| Name        | Value | Description |
| ----------- | ----- | --- |
| agiverbose  | false | Enables AGI (graphics) logging |
| cleandir    | true  | Deletes various debug files from the games directory |
| fontscale   |       | Sets the debug font scale |
| gldebug     | -1    | Sets the OpenGL debug output level |
| gllinewidth |       | Sets the width of lines (sparks) |
| glstream    |       | Sets the mode for streaming data to the GPU |
| sync        | true  | Disables multi-threading |
| thinfont    | true  | Makes the debug font slightly thinner |

## DirectDraw
| Name       | Value | Description |
| ---------- | ---   | --- |
| reshack    | true  | Enables resolutions above 2048x2048 when using MS ddraw |
| voodooaa   | false | Fixes text rendering when using dgVodooo's anti aliasing |

# Dev/Debug Functions
Beta 1560 contains many debug functions/hotkeys. To enter debug mode, press CTRL+ALT+SHIFT+F4.
For a list of hotkeys, see https://github.com/0x1F9F1/Open1560/blob/master/extra/keys.txt
