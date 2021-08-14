#!/usr/bin/env python3
import sys
import random
import string

from common import random_uniform, complete

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

par = complete(maxdeg=3)
hascut = set()
remap = {0: 0}
newtree = []

for i, x in enumerate(par):
    if random.randint(0, 10) == 0 or x in hascut:
        hascut.add(i + 1)
    else:
        remap[i + 1] = len(newtree) + 1
        newtree.append(remap[par[i]])


print(1, 1)
print(len(newtree), *newtree)
print(len(par), *par)
