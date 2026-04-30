import glob
import os
import subprocess
import sys
from pathlib import Path

paths = ['code']
exts = ['cpp', 'h']

OUR_DIR = Path(__file__).resolve().parent

ROOT_DIR = OUR_DIR.parent

files = []

for path in paths:
    for ext in exts:
        files.extend(glob.glob(os.path.join(ROOT_DIR, path, '**', f'*.{ext}'), recursive = True))

print(f'\nProcessing {len(files)} files')

def chunks(l, n):
    """Yield successive n-sized chunks from l."""
    for i in range(0, len(l), n):
        yield l[i:i + n]
        
format_args = [str(OUR_DIR / 'clang-format.exe'), '-i', '-Werror']

if '--dry' in sys.argv[1:]:
    format_args.append('--dry-run')

errors = False

for chunk in chunks(files, 128):
    if subprocess.run(format_args + chunk).returncode != 0:
        errors = True

if errors:
    exit(1)

print(f'Successfully formatted {len(files)} files!\n')