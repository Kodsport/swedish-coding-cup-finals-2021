#!/usr/bin/env python3
import sys
import random
import string

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

N = int(cmdlinearg('N'))
M = int(cmdlinearg('M'))

goals = []
starts = []

left = 500
for _ in range(M):
    x = max(0, min(left, int(random.expovariate(M / left))))
    starts.append(x)
    left -= x

at = 0
canSkip = M - N
starts = sorted(starts)
for i in range(N):
    left = N - i
    while True:
        if random.random() < (M - N - at) / left:
            at += 1
        else:
            break
    rem = min(starts[at], int(random.expovariate(2 / starts[at]))) if starts[at] else 0
    goals.append(starts[at] - rem)
    at += 1

#print(goals)
#print(starts)

random.shuffle(goals)
random.shuffle(starts)
print(N, M)
for i in range(N):
    print(goals[i], *range(goals[i]))

for i in range(M):
    print(starts[i], *range(starts[i]))
