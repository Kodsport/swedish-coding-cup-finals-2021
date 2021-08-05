#!/usr/bin/env python3
ans = 0

def find(i, update=False):
    global ans
    while parent[i] != i:
        i = parent[i]
        if update:
            ans += 1
    return i

def union(i, j):
    i = find(i, True)
    j = find(j, True)
    global size
    global parent
    if size[i] < size[j]:
        (i, j) = (j, i)
    size[i] += size[j]
    parent[j] = i

def depth(i):
    res = 0
    while parent[i] != i:
        i = parent[i]
        res += 1
    return res


(n, m) = list(map(int, input().split()))
size = [1] * n
parent = list(range(n))
seen = set()
edges = []

nxt = 1
prev_size = 1

EDGE_LIM = 250

while True:
    nxt2 = nxt
    done = False
    for i in range(nxt+1, n):
        for j in range(nxt, i):
            siz = size[find(nxt, False)]
            siz2 = size[find(0, False)]
            if siz >= siz2:
                done = True
                break
            nxt2 = i
            union(j, i)
            edges.append((j, i))
            seen.add((j, i))
        if done:
            break
    p = find(nxt, False)
    prev_size = nxt2 + 1 - nxt
    union(0, p)
    edges.append((0, p))
    seen.add((0, p))
    nxt = nxt2+1
    if n-nxt+1 < prev_size or len(edges) > EDGE_LIM:
        break

ind = []
for i in range(n):
    for j in range(i+1, n):
        ind.append((i, j))

ind.sort(key=lambda p: -depth(p[0])-depth(p[1]))

for (a, b) in ind:
    if a > b:
        (a, b) = (b, a)
    if (a, b) not in seen:
        edges.append((a, b))
        seen.add((a, b))
        union(a, b)
    if len(edges) == m:
        break

for (u, v) in edges:
    print(u+1, v+1)

