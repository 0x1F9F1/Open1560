# Open1560

[![Build status](https://ci.appveyor.com/api/projects/status/qiyykgn9vb6kk9mj/branch/master?svg=true)](https://ci.appveyor.com/project/0x1F9F1/Open1560/branch/master)
[![Chat On Discord](https://img.shields.io/discord/239900961731117059?color=7289DA&logo=discord)](https://discord.gg/ykT7PT4)

Open1560 is an open source re-implementation of Midtown Madness 1 beta 1560.

This project is a bottom-up rewrite of Midtown Madness 1, using the original binary to provide functions that have not been implemented yet.<br/>
The intention is to allow the fixing of bugs, implementation of new features and porting to platforms unsupported by the original.<br/>

## Installation
1. Download and install the [Visual C++ 2019 Redistributable](https://aka.ms/vs/16/release/vc_redist.x86.exe).
2. Download the [Latest Version](https://ci.appveyor.com/api/projects/0x1F9F1/Open1560/artifacts/build/Open1560.zip?branch=master) and extract the files directly into your MM1 directory.

# History

## Versions
Build | Build Date | Name | Details
--- | --- | --- | ---
`1549` | `Mar 31 1999 17:02:43` | midtown.exe | Beta, Executable Only, SafeDisc
`1560` | `Apr  2 1999 19:09:02` | midtown.exe | Beta, Symbols
`1560` | `Apr  2 1999 19:10:27` | test1560.exe | Beta, Sybmols, Debug
`1588` | `Apr 14 1999 15:07:10` | midtown.exe | Retail, Symbols, SafeDisc
`1532 / NET DEMO` | `Jul 26 1999 18:50:44` | midtrial.exe | Trial
`1532 / VW DEMO`  | `Jul 29 1999 15:03:55` | midvwtrial.exe | Trial
`1589` | `Sep 16 1999 11:00:21` | midtown.exe | Retail, SafeDisc + Clean

## Notes/Trivia
* 1532 builds contain a mix of changes from older and newer versions:
    * Progress bar in same position as 1549
    * Newer cursor texture (differs from 1549)
    * Includes certain cheats not found in 1549/1560
* 1549 was found in an unused .icd alongside the 1560 builds. It requires a custom mmlang.dll to run.
* 1560 setup.exe references an unknown `vpbus.ar`.
* 1589 was released three times:
    Protection | Release Date | Name | Extra
    --- | --- | --- | ---
    SafeDisc | `03 ‎November ‎1999 00:32:10` | mmpat.exe | Contains symbols for an unknown trial debug build dated `Aug 10 11:52:15 1999`
    Clean | `10 ‎May ‎2000 22:47:12` | midtown1_patch_aspac.exe |
    Clean | `16 ‎January ‎2002 18:42:16` | mm1xppat.exe | Contains a 2 byte NOP patch for ComputeCpuSpeed

## Old Links (Use Wayback Machine)
* http://www.microsoft.com/games/midtown/downloads.htm
* http://download.microsoft.com/download/midtownmad/Trial/1/W9X/EN-US/MMDemo.exe
* http://www1.vw-online.de/shop/programme/games/mad/mmvwdemo.exe
* ftp://ftp.microsoft.com/deskapps/games/public/midtown/patch/mmpat.exe
* http://download.microsoft.com/download/midtownmad/Patch/1.2/W9XNT4/EN-US/midtown1_patch_aspac.exe
* http://download.microsoft.com/download/midtownmad/Update/1.2.1/W9X2KMeXP/EN-US/mm1xppat.EXE
* http://download.microsoft.com/download/midtownmad/Update/1.2.1/WXP/EN-US/mm1xppat.EXE
