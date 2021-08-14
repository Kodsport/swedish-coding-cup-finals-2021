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

par = random_uniform(maxdeg=2)

print(1, 1)
print(len(par), *par)
print(len(par), *par)
