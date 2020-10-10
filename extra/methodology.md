# Versions
Build | Build Date | Name | Details
--- | --- | --- | ---
`1549` | `Mar 31 1999 17:02:43` | midtown.exe | Beta, Executable Only, SafeDisc
`1560` | `Apr  2 1999 19:09:02` | midtown.exe | Beta, Symbols
`1560` | `Apr  2 1999 19:10:27` | test1560.exe | Beta, Sybmols, Debug
`1588` | `Apr 14 1999 15:07:10` | midtown.exe | Retail, Symbols, SafeDisc
`1532 / NET DEMO` | `Jul 26 1999 18:50:44` | midtrial.exe | Trial
`1532 / VW DEMO`  | `Jul 29 1999 15:03:55` | midvwtrial.exe | Trial
`1589` | `Sep 16 1999 11:00:21` | midtown.exe | Retail, SafeDisc + Clean

## 1549
Found in an old .icd alongside the 1560 builds. Needs a custom mmlang.dll to run.

## 1560
Sneak Preview CD. Contained Debug and Release builds (plus an old 1549 build).

## 1588
Retail release.

## 1532
Released as NET DEMO (Trial) and VW DEMO.\
Very similar to 1589, despite the lower build number (contains EditMode, hardcoded tuning, etc).

## 1589
Release 3 times. Commonly known as XP Patch or MS Zone Patch.\
Has a few interesting changes, but not good for modding (no debug symbols, no exception handling, hardcoded localization, hardcoded tuning).

## VCK
Debug executables with optimisation disabled. Good for research.

# Debug Symbols (Linker Map)
There are 4 known linker maps: 1560 Debug, 1560 Release, 1588 Release, 1589 Debug Trial.\
Comparisons can be found [here](https://github.com/0x1F9F1/Open1560/issues/46#issuecomment-697062680).

# Imports
"Fake" imports are used to reference game symbols. Allows almost seamless interop between game and hook.

# Exports
Exports are used to hook game functions. Avoids problems introduced by C++ address-of semantics.

# IDA
## Offset (user-defined) - Ctrl+R
Fix incorrect global offsets

## Offset (struct) - T
Fix virtual call types

## Offset (struct) - Select + T
Fix incorrect struct offsets

# Notes/Trivia
* 1532 builds contain a mix of changes from older and newer versions:
    * Progress bar in same position as 1549
    * Newer cursor texture (differs from 1549)
    * Includes certain cheats not found in 1549/1560
* 1560 setup.exe references an unknown `vpbus.ar`.
* 1589 was released three times:
    Protection | Release Date | Name | Extra
    --- | --- | --- | ---
    SafeDisc | `03 ‎November ‎1999 00:32:10` | mmpat.exe | Contains symbols for an unknown trial debug build dated `Aug 10 11:52:15 1999`
    Clean | `10 ‎May ‎2000 22:47:12` | midtown1_patch_aspac.exe |
    Clean | `16 ‎January ‎2002 18:42:16` | mm1xppat.exe | Contains a 2 byte NOP patch for ComputeCpuSpeed

# Old Links (Use Wayback Machine)
* http://www.microsoft.com/games/midtown/downloads.htm
* http://download.microsoft.com/download/midtownmad/Trial/1/W9X/EN-US/MMDemo.exe
* http://www1.vw-online.de/shop/programme/games/mad/mmvwdemo.exe
* ftp://ftp.microsoft.com/deskapps/games/public/midtown/patch/mmpat.exe
* http://download.microsoft.com/download/midtownmad/Patch/1.2/W9XNT4/EN-US/midtown1_patch_aspac.exe
* http://download.microsoft.com/download/midtownmad/Update/1.2.1/W9X2KMeXP/EN-US/mm1xppat.EXE
* http://download.microsoft.com/download/midtownmad/Update/1.2.1/WXP/EN-US/mm1xppat.EXE
