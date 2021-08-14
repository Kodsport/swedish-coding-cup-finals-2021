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

def deepest(i):
    p = find(i, False)
    best = -1
    res = -1
    for j in range(n):
        if find(j, False) == p:
            f = depth(j)
            if f > best:
                best = f
                res = j
    return res


def get_spanning_tree(ind):
    if len(ind) == 1:
        return []
    h = len(ind) // 2
    return get_spanning_tree(ind[:h]) + get_spanning_tree(ind[h:]) + [(ind[h-1], ind[h])]


(n, m) = list(map(int, input().split()))
size = [1] * n
parent = list(range(n))
seen = set()
edges = []

nxt = 1
prev_size = 1

EDGE_LIM = 250

while True:
    done = False

    length = 1
    while prev_size > 2 ** (((length-2) * (length-1)) // 2):
        length += 1
    nxt2 = nxt + length
    if nxt2 > n:
        break
    
    for edge in get_spanning_tree(list(range(nxt, nxt2))):
        a = deepest(edge[0])
        b = deepest(edge[1])
        union(a, b)
        edges.append((a, b))
        seen.add((a, b))
        seen.add((b, a))
    rem = []
    for i in range(nxt, nxt2):
        for j in range(i+1, nxt2):
            if (i, j) not in seen and (j, i) not in seen:
                rem.append((i, j))
    rem.sort(key=lambda p: -depth(p[0])-depth(p[1]))
    for (a, b) in rem:
        if size[find(nxt, False)] >= prev_size:
            break
        union(a, b)
        edges.append((a, b))
        seen.add((a, b))
        seen.add((b, a))
    
        
    a = deepest(0)
    b = deepest(nxt)
    union(b, a)
    edges.append((b, a))
    seen.add((a, b))
    nxt = nxt2
    prev_size = size[find(0, False)]
    if len(edges) > EDGE_LIM:
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

#print(ans)

