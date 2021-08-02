#!/usr/bin/env pypy
#First placing one of each type, then randomizing the rest.

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
d = int(cmdlinearg('d'))
a = random.randint(0,n-k)
v = ["0" for i in range(n)]

for i in range(a,a+k):
    v[i] = "1"

print(n,d)
print(" ".join(v))
