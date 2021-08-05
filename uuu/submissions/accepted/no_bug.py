#!/usr/bin/env python3
ans = 0

def find(i):
    global ans
    while parent[i] != i:
        i = parent[i]
        ans += 1
    return i

def union(i, j):
    i = find(i)
    j = find(j)
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

t = 2
while True:
    found = False
    for i in range(1, n):
        if i%t != 0 and i%(t // 2) == 0:
            edges.append((i-1, i))
            seen.add((i-1, i))
            union(i-1, i)
            found = True
    t *= 2
    if not found:
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

#print(ans)
for (u, v) in edges:
    print(u+1, v+1)


