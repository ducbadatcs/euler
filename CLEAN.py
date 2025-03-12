import glob
import os
import pathlib
for file in glob.glob("*"):
    if file[0].isnumeric() or "_" in str(file) or file[1] == "_" or file[0].islower():
        os.remove(file)