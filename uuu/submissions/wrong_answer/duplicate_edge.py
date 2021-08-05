#!/usr/bin/env python3

import random

(n, m) = list(map(int, input().split()))
seen = set()
edges = []

while len(edges) < m:
    i = random.randrange(0, n)
    j = random.randrange(0, n)
    if i > j:
        (i, j) = (j, i)
    if i != j:
        seen.add((i, j))
        edges.append((i, j))

for (u, v) in edges:
    print(u+1, v+1)
