#!/usr/bin/env python3
import sys
import random
import string

from common import random_uniform

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
N = int(cmdlinearg("N"))
M = int(cmdlinearg("M"))


left = 700
starts = []
for i in range(M):
    starts.append(random_uniform(B=random.randint(0, left // (M - i))))

goals = []
for par in random.sample(starts, N):
    hascut = set()
    remap = {0: 0}
    newtree = []
    for i, x in enumerate(par):
        if random.randint(0, 10) == 0 or x in hascut:
            hascut.add(i + 1)
        else:
            remap[i + 1] = len(newtree) + 1
            newtree.append(remap[par[i]])
    goals.append(newtree)

print(N, M)
for t in goals:
    print(len(t), *t)
for t in starts:
    print(len(t), *t)
