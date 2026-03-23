import shutil
import os
import sys

build_dir = "../build" if os.path.exists("../build") else "../buildDir"

src = "ExampleMod/"
dest = os.path.join(build_dir, "Minecraft.Client", "mods", "ExampleMod")

if os.path.exists(dest):
    if os.path.isdir(dest):
        shutil.rmtree(dest)
    else:
        sys.exit(1)

os.makedirs(os.path.dirname(dest), exist_ok=True)

try:
    shutil.copytree(src, dest)
    print("Copied ExampleMod successfully")
except Exception as e:
    sys.exit(1)