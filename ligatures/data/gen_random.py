from util import *
import random
import string

n = int(cmdlinearg('n', 10**6))
q = int(cmdlinearg('q', 10**5))
k = int(cmdlinearg('k'))

alphabet = string.ascii_lowercase

print(n, q, k)
print(''.join(random.choice(alphabet) for _ in range(n)))
for _ in range(q):
    seen = set()
    s = ''
    while len(seen) < k:
        pair = random.choice(alphabet) + random.choice(alphabet)
        if pair not in seen:
            seen.add(pair)
            s += pair
    print(s)
