# Contents
* [Versions](#versions)
* [Debug Symbols](#debug-symbols-linker-map)
* [Disassembly](#disassembly)
* [IDA](#ida)

# Versions
| Build | Build Date | Name | Details |
| --- | --- | --- | --- |
| `1427` | `Mar  1 1999 18:23:06` | midtown.exe | Beta, Symbols, Debug |
| `1549` | `Mar 31 1999 17:02:43` | midtown.exe | Beta, Executable Only, SafeDisc |
| `1560` | `Apr  2 1999 19:09:02` | midtown.exe | Beta, Symbols |
| `1560` | `Apr  2 1999 19:10:27` | test1560.exe | Beta, Sybmols, Debug |
| `1588` | `Apr 14 1999 15:07:10` | midtown.exe | Retail, Symbols, SafeDisc |
| `1532 / NET DEMO` | `Jul 26 1999 18:50:44` | midtrial.exe | Trial |
| `1532 / VW DEMO`  | `Jul 29 1999 15:03:55` | midvwtrial.exe | Trial |
| `1589` | `Sep 16 1999 11:00:21` | midtown.exe | Retail, SafeDisc + Clean |

## 1427
Earliest known build. Probably the one seen in GDC, March 1999.

## 1549
Found in an old .icd alongside the 1560 builds. Needs a custom mmlang.dll to run.

## 1560
Sneak Preview CD. Contained Debug and Release builds (plus an old 1549 build).\
Available at https://archive.org/details/midtown-madness-sneak-preview-beta-and-sales-avi.

## 1588
Retail release.

## 1532
Released as NET DEMO (Trial) and VW DEMO.\
Very similar to 1589, despite the lower build number (contains EditMode, hardcoded tuning, etc).

## 1589
Released 3 times. Commonly known as XP Patch or MS Zone Patch.\
Has a few interesting changes, but not good for modding (no debug symbols, no exception handling, hardcoded localization, hardcoded tuning).

## Vehicle Creation Kit
Compiled in debug mode (with optimisations disabled), though no debug symbols. Good for research.

# Debug Symbols (Linker Map)
There are 4 known linker maps: 1427, 1560 Debug, 1560 Release, 1588 Release, 1589 Debug Trial.\
Comparisons can be found [here](https://github.com/0x1F9F1/Open1560/issues/46#issuecomment-697062680).

# Disassembly
The game has been fully disassembled into `game.asm`, making it much easier to replace symbols and patch functions.

After replacing any symbols, you should run `tools/asm.py`. This analyzes both the C++ and ASM code, performing tasks such as:
* Ensuring any ARTS_IMPORT symbols exist in the ASM.
* Removing any ASM symbols which exist as ARTS_EXPORT in C++, or converting them to EXTERN declarations if they are still referenced.
* Warning of any ARTS_EXPORT symbols which are not used by the ASM.
* Check for PATCH comments when removing dead code.

# ARTS_IMPORT
Currently does nothing, apart from signaling that a function is not yet implemented.

# ARTS_EXPORT
Marks the function as dllexport, to force the compiler to generate a definition for it.

`Open1560.exp` (generated from an empty .def file) is used to disable actually exporting any functions from the exe.

If replacing a global variable which was not trivially constructible and destructible, make sure to also remove the original static initializer.

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
    | Protection | Release Date | Name | Extra |
    | --- | --- | --- | --- |
    | SafeDisc | `03 November 1999 00:32:10` | mmpat.exe | Contains symbols for an unknown trial debug build dated `Aug 10 11:52:15 1999` |
    | Clean | `10 May 2000 22:47:12` | midtown1_patch_aspac.exe |
    | Clean | `16 January 2002 18:42:16` | mm1xppat.exe | Contains a 2 byte NOP patch for ComputeCpuSpeed |

# Retail Releases

## Gold
| Name | Hash | Length |
| --- | --- | --- |
| `midtown.exe` | `2E4DAB549C8B789DF30BF1AA4DE4DC74234E0BA0` | 1972736 |

## English
| Name | Hash | Length |
| --- | --- | --- |
| `audio.ar` | `4754F78BD6E537C822E533526882C9360AFA453F` | 54821984 |
| `core.ar` | `4058AC179CA888B0BC86F0A0394C70E99FDF56C2` | 91404016 |
| `mmlang.dll` | `471D7137DAC14AC12DAB89E0784FCB6CCFDE9C55` | 49152 |
| `ui.ar` | `B7CC8EA982C643635CA1D842BD16D740D2678314` | 19891168 |

## German
Name | Hash | Length
--- | --- | ---
`audio.ar` | `3B2A3DFFD6079C88FA003B138D044BA22CEEA0E3` | 64175024
`core.ar` | `4058AC179CA888B0BC86F0A0394C70E99FDF56C2` | 91404016
`mmlang.dll` | `F0058F3C63B03B6F76A3F6A1622C2010028C3012` | 52224
`ui.ar` | `6687A23D1FD0867DE532AB3309E9A9AF621AA889` | 21073168

## Japanese
| Name | Hash | Length |
| --- | --- | --- |
| `audio.ar` | `5D8AE0E580058401BF644A993CE93B627113AEF8` | 50076688 |
| `core.ar` | `4058AC179CA888B0BC86F0A0394C70E99FDF56C2` | 91404016 |
| `mmlang.dll` | `DE26AA2405BB5339985C6AC1881D4A51C6146C1D` | 49152 |
| `ui.ar` | `1165F55DCCE3466A28CEEF44DF3CBCCDBAF22E4E` | 17365728 |

## Russian
| Name | Hash | Length |
| --- | --- | --- |
| `audio.ar` | `573DABF7E72DE213C6E9E597ACA2ACD292C3027C` | 54821984 |
| `core.ar` | `4058AC179CA888B0BC86F0A0394C70E99FDF56C2` | 91404016 |
| `mmlang.dll` | `42C1DAE1EEC3DA83AFEC6639B4768F8DF4915003` | 48128 |
| `ui.ar` | `8496EE9D8CD2589DEB7714B5080117074337496D` | 19891168 |

# Other Releases

| Name | Hash | Length |
| --- | --- | --- |
| `midtown.pdf` | `5F0539663FFDDD454D1B270BCAD9CFEB6EC8F6FB` | 764584 |
| `midtown1_patch_aspac.exe` | `B4B6AAAD9A4663C70B76EB954BF7DE052E149AD2` | 1290960 |
| `mm1xppat.exe` | `5676A24B9D43731D6C145E5B69D766EAEC0FEA8C` | 825432 |
| `mmdemo.exe` | `1A562B21BCD8E395422F313F73D187539A944476` | 27104528 |
| `mmpat.exe` | `A9FA68B14D05108C8DB784D5009A033A43CE3856` | 2499568 |
| `mmvwdemo.exe` | `450669FAB7B965DA740DB45B9D480E3A70A580A0` | 24231936 |

## mmdemo.exe
| Name | Hash | Length |
| --- | --- | --- |
| `midtrial.ar` | `83D17588F78DC7A645DF5FC734E078A27E211874` | 85285616 |
| `midtrial.exe` | `8AC67A1035B2736C079B1B545DA77B2833EF5AD5` | 1990656 |

## mmvwdemo.exe
| Name | Hash | Length |
| --- | --- | --- |
| `midvwtrial.ar` | `F265DD7597A0C9D3189016474C0819BD8D519638` | 77003488 |
| `midvwtrial.exe` | `975F7EB948A2CC7B5D755211C0246733BCB784C1` | 1991168 |

## mmpat.exe
| Name | Hash | Length |
| --- | --- | --- |
| `midtown.exe` | `12EF71BCF9A81E7E30576DED5859E2CC6B9727CF` | 239863 |
| `midtown.icd` | `E1EF98215090A1517EF8527CB51E1A0AA71A618A` | 2005549 |

## midtown1_patch_aspac.exe
| Name | Hash | Length |
| --- | --- | --- |
| `midtown.exe` | `6A5356090489C3E715FB8A29334BB971B409D058` | 2005504 |

## mm1xppat.exe
| Name | Hash | Length |
| --- | --- | --- |
| `midtown.exe` | `F9CFDDF30257DCE4C588C5F4F924FF6E7F9179EC` | 2005504 |

## 1560 / Sneak Preview Beta
| Name | Hash | Length |
| --- | --- | --- |
| `audio.ar` | `7F38D809B6FEE8EB38020EF7A73AAB69EB89336D` | 55054704 |
| `core.ar` | `73C76EC9D1A3660CE437382E7D127F2244F4A4FA` | 89388112 |
| `midtown.exe` | `179F87605C61FE233064331E01854194F9BE91D9` | 1967616 |
| `midtown.icd` | `7A3D8C524EE5176A06EF5FEA49AA92C73A18A0F8` | 1964544 |
| `mmlang.dll` | `BEFFEC30E72AE63EC2FD07DAC6374C719499DB76` | 49152 |
| `racetrack2.ar` | `C58A094CBE789C08E52120099AB14240E2E309C3` | 1033584 |
| `test1560.exe` | `755C24140088FD479BAB040A216038A88A55DBAB` | 2782208 |
| `ui.ar` | `A7B682DC63C869AA997B0D427B8AFE432A7D9727` | 18844304 |
| `vpdisco.ar` | `63FCCF9EC7871E6C32098FE53195A1845AE2D6D9` | 177776 |

## 1427 Beta
| Name | Hash | Length |
| --- | --- | --- |
| `midtown.ar` | `302403895A39FB31FDED5CEBD798A9FCA0A4B1AA` | 156897280 |
| `midtown.exe` | `D7FE4C77FB4707C5F302D778B2AB64849AEBEEF0` | 2655744 |

## Script for dumping file info
```ps
Get-ChildItem | Foreach-Object { New-Object PSObject -Property @{ Name=$_.Name.ToLower(); Length=$_.Length; Hash=(Get-FileHash -Algorithm SHA1 $_.FullName).Hash } } | Format-Table -Auto
```

# Old/Useful Links (Use Wayback Machine)
* http://www.microsoft.com/games/midtown/downloads.htm
* http://download.microsoft.com/download/midtownmad/Trial/1/W9X/EN-US/MMDemo.exe
* http://www1.vw-online.de/shop/programme/games/mad/mmvwdemo.exe
* ftp://ftp.microsoft.com/deskapps/games/public/midtown/patch/mmpat.exe
* http://download.microsoft.com/download/midtownmad/Patch/1.2/W9XNT4/EN-US/midtown1_patch_aspac.exe
* http://download.microsoft.com/download/midtownmad/Update/1.2.1/W9X2KMeXP/EN-US/mm1xppat.EXE
* http://download.microsoft.com/download/midtownmad/Update/1.2.1/WXP/EN-US/mm1xppat.EXE
* https://www.sdbj.com/news/2000/feb/01/software-industry-takes-hard-stand-against-piracy/
* https://github.com/jeffpar/kbarchive/search?l=Markdown&p=3&q=kbMidtownMadness
