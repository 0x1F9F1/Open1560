import re
import json

# dumpbin /RELOCATIONS test1560.exe

reloc_block_re = re.compile(r'([0-9A-F]+) RVA')
reloc_entry_re = re.compile(r'([0-9A-F]+)\s*HIGHLOW\s*([0-9A-F]+)')

current_rva = 0

relocs = []

with open('relocations.txt', 'r') as f:
    for line in f.readlines():
        match = reloc_block_re.search(line)
        if match:
            current_rva = int(match[1], 16)
            continue

        match = reloc_entry_re.search(line)
        if match:
            relocs.append((0x400000 + current_rva + int(match[1], 16), int(match[2], 16)))
            continue

relocs.sort()

with open('relocs.json', 'w') as f:
    json.dump(relocs, f, indent = 4, sort_keys = True)
