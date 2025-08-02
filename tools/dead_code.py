from pathlib import Path
import re

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
        sym = line = line.rstrip(':')
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
    elif line.endswith(' ENDP'):
        set_sym(None, i + 1)
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
        elif len(parts) >= 3:
            sym = parts[0]
            set_sym(sym, i)

    end_of_branch = None

set_sym(None, len(lines))

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

while to_check:
    name = to_check.pop()
    visited.add(name)
    _, _, refs = all_syms[name]
    for ref in refs:
        if ref not in visited:
            to_check.append(ref)

dead_syms = all_syms.keys() - visited

bad_lines = set()

for sym in dead_syms:
    start, end, _ = all_syms[sym]
    if start != end:
        if not sym.startswith('dead_code_'):
            print(sym, start, end)
        bad_lines.update(range(start, end))

for i in bad_lines:
    line = lines[i]
    assert 'PATCH' not in line, f'Removed patch: {line}'

lines = [ v for i, v in enumerate(lines) if i not in bad_lines ]

assert lines.pop() == 'END'

for sym, line in sorted(extern_syms.items()):
    if sym not in dead_syms:
        lines.append(line)

lines.append('END')

output = '\n'.join(lines)

if renames:
    pat = r'\b{}\b'.format('|'.join(re.escape(x) for x in renames.keys()))
    output = re.sub(pat, lambda match: renames[match.group(0)], output)

output = output.replace('\n\n\n', '\n\n')

with open(game_asm, 'w') as f:
    f.write(output)