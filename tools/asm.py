from pathlib import Path

import re
import json
import glob
import os

ROOT_DIR = Path(__file__).resolve().parent.parent
GAME_DIR = ROOT_DIR / 'code' / 'midtown'
game_asm = GAME_DIR / 'game.asm'

with open(game_asm, 'r') as f:
    data = f.read()

lines = data.splitlines()

sym_regex = re.compile(r'[a-zA-Z0-9_?@$]+')

current_sym = None
prev_sym = None
current_start = 0

all_syms = {}
public_syms = set()
end_of_branch = None

extern_syms = {}
renames = {}
proc_syms = {}

# Replace possibly overlapping matches
def replace_all(value, old, new):
    while True:
        replaced = value.replace(old, new)
        if replaced == value:
            return replaced
        value = replaced

def is_directive(value):
    return value.startswith('ALIGN')

def set_sym(value, line):
    global current_sym
    global current_start
    global prev_sym

    if value == current_sym:
        return

    while line > current_start and is_directive(lines[line - 1]):
        line -= 1

    if current_sym:
        assert current_sym not in all_syms
        all_syms[current_sym] = (current_start, line, set())

    prev_sym = current_sym
    if value:
        assert sym_regex.fullmatch(value), current_sym

    current_sym = value
    current_start = line

def get_code_syms():
    paths = ['code']
    exts = ['cpp', 'h']

    files = []

    for path in paths:
        for ext in exts:
            files.extend(glob.glob(os.path.join(ROOT_DIR, path, '**', f'*.{ext}'), recursive = True))

    import_syms = set()
    export_syms = set()

    for file in files:
        with open(file, 'r', encoding='utf-8') as f:
            data = f.read()

        for match in re.finditer(r'// (\S+).*\n.*ARTS_(IMPORT|EXPORT)', data):
            name = match[1]
            if match[2] == 'IMPORT':
                import_syms.add(name)
            else:
                export_syms.add(name)

    return import_syms, export_syms

for i, line in enumerate(lines):
    if not line:
        continue
    if is_directive(line):
        continue
    if line.startswith(' '):
        end_of_branch = line.startswith('    ret') or line.startswith('    jmp')
        continue
    if line.startswith('.') or line.startswith('INCLUDELIB') or line.startswith('END'):
        set_sym(None, i)
    elif line.startswith('PUBLIC '):
        sym = line[7:]
        set_sym(sym, i)
        public_syms.add(sym)
    elif line.endswith(':'):
        sym = line.rstrip(':')
        set_sym(sym, i)
        if sym.startswith('sym_'):
            renames[sym] = 'loc_' + sym[4:]
        elif not any(sym.startswith(x) for x in [ '?', 'sub_', 'loc_', 'locret_', '_$E' ]):
            print('Strange symbol', sym)
        if prev_sym and not end_of_branch:
            _, _, refs = all_syms[prev_sym]
            refs.add(sym)
    elif line.startswith('EXTERN '):
        sym = line[7:line.index(':')]
        extern_syms[sym] = line
        set_sym(sym, i)
        set_sym(f'dead_code_{i}', i)
    else:
        parts = line.split(' ')

        if parts[1] == 'PROC':
            assert len(parts) == 3
            sym = parts[0]
            set_sym(sym, i)
            access = parts[2]
            assert access in ['PUBLIC', 'PRIVATE']
            if access == 'PUBLIC':
                public_syms.add(sym)
            assert sym not in proc_syms
            proc_syms[sym] = (i, None)
        elif parts[1] == 'ENDP':
            assert len(parts) == 2
            sym = parts[0]
            start, end = proc_syms[sym]
            assert end is None
            set_sym(None, i)
            proc_syms[sym] = (start, i)
        elif len(parts) >= 3:
            sym = parts[0]
            set_sym(sym, i)

    end_of_branch = None

set_sym(None, len(lines))

import_syms, export_syms = get_code_syms()

for sym in import_syms - public_syms:
    raise Exception(f'Missing {sym}')

public_syms = public_syms & import_syms

print('Public Syms', len(public_syms))

for sym_name, (start, end, sym_refs) in all_syms.items():
    done_directives = False
    for line in lines[start:end]:
        # Check for directives in the middle
        if is_directive(line):
            assert not done_directives, (line, sym_name)
        else:
            done_directives = True

        for name in sym_regex.findall(line):
            if name in all_syms:
                sym_refs.add(name)

visited = set()
to_check = list(public_syms)
dead_syms = set(all_syms.keys() & export_syms)

while to_check:
    name = to_check.pop()
    visited.add(name)
    if name in dead_syms:
        continue
    _, _, refs = all_syms[name]
    for ref in refs:
        if ref not in visited:
            to_check.append(ref)

dead_syms.update(all_syms.keys() - visited)

for sym in export_syms:
    if sym not in all_syms:
        continue
    if sym not in visited:
        continue
    dead_syms.add(sym)
    if sym not in extern_syms:
        sym_type = 'PROC' if sym in proc_syms else 'BYTE'
        extern_syms[sym] = f'EXTERN {sym}:{sym_type}'

bad_lines = set()

for sym in dead_syms:
    start, end, _ = all_syms[sym]
    if start != end:
        if not sym.startswith('dead_code_'):
            print(sym, start, end)
        bad_lines.update(range(start, end))
    if sym in proc_syms:
        start, end = proc_syms[sym]
        bad_lines.add(start)
        bad_lines.add(end)

for i in bad_lines:
    line = lines[i]
    if 'PATCH' in line:
        raise Exception(f'Line {i + 1}, Removed patch: {line.strip()}')

lines = [ v for i, v in enumerate(lines) if i not in bad_lines ]

assert lines.pop() == 'END'

for sym, line in sorted(extern_syms.items()):
    if sym in visited:
        lines.append(line)

lines.append('END')

output = '\n'.join(lines)

if renames:
    pat = r'\b{}\b'.format('|'.join(re.escape(x) for x in renames.keys()))
    output = re.sub(pat, lambda match: renames[match.group(0)], output)

output = replace_all(output, '\n\n\n', '\n\n')

with open(game_asm, 'w') as f:
    f.write(output)