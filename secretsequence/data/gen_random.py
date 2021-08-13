#!/usr/bin/env pypy
# Random ones.

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))

v = ["0" for i in range(n)]

for i in random.sample(range(n), k):
    v[i] = "1"

print(n)
print(" ".join(v))
