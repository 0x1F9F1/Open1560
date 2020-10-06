# Debug Symbols (Linker Map)
There are 4 known linker maps: 1560 Debug, 1560 Release, 1588 Release, 1589 Debug Trial.
Comparisons between them can be found [here](https://github.com/0x1F9F1/Open1560/issues/46#issuecomment-697062680).

# 1549
Only executable + 2 days older than 1560. Not much of interest.

# 1560
* TODO

# 1588
* TODO

# 1532 (Trial)
* TODO

# 1589
Also known as XP Patch. Has a few interesting changes but not good for modding (no debug symbols, no exception handling, hardcoded localization, hardcoded tuning).

# VCK
Debug executables with optimisation disabled. Good for research.

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
