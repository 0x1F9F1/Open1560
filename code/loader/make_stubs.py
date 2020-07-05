import glob
import subprocess
import os

def chunks(l, n):
    """Yield successive n-sized chunks from l."""
    for i in range(0, len(l), n):
        yield l[i:i + n]

os.chdir('stubs')

if True:
    asm_files = glob.glob('*.asm')

    for chunk in chunks(asm_files, 128):
        with open('ml_cmd.txt', 'w') as f:
            for file in chunk:
                f.write('/c ')
                f.write(file)
                f.write('\n')

        subprocess.call([ "ml", "/nologo", "/Brepro", "/safeseh", "/coff", "@ml_cmd.txt" ])

    for file in asm_files:
        os.remove(file)

    os.remove('ml_cmd.txt')

if True:
    obj_files = glob.glob('*.obj')
    count = 0

    with open('lib_cmd.txt', 'w') as f:
        for file in obj_files:
            f.write(file)
            f.write('\n')

    subprocess.call([ "lib", "/nologo", "/Brepro", "/out:../Open1560_stubs.lib", "@lib_cmd.txt" ])

    for file in obj_files:
        os.remove(file)

    os.remove('lib_cmd.txt')
