#!/usr/bin/env pypy
# Contiguous ones.

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

a = random.randint(0,n-k)
for i in range(a,a+k):
    v[i] = "1"

print(n)
print(" ".join(v))
