#!/usr/bin/env python3

(n, m) = list(map(int, input().split()))
for i in range(0, n):
    for j in range(i+1, n):
        if m > 0:
            print(i+1, j+1)
            m -= 1
