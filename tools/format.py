import glob
import os
import subprocess
from pathlib import Path

paths = ['code']
exts = ['cpp', 'h']

OUR_DIR = Path(__file__).resolve().parent


ROOT_DIR = OUR_DIR.parent

files = []

for path in paths:
    for ext in exts:
        files.extend(glob.glob(os.path.join(ROOT_DIR, path, '**', f'*.{ext}'), recursive = True))

print(f'Processing {len(files)} files')

def chunks(l, n):
    """Yield successive n-sized chunks from l."""
    for i in range(0, len(l), n):
        yield l[i:i + n]
        
clang_format = str(OUR_DIR / 'clang-format.exe')

for chunk in chunks(files, 128):
    subprocess.run([
        clang_format,
        '-i',
        *chunk
    ])
